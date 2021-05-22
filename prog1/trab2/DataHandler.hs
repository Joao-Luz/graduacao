module DataHandler
(
  Dataset
, readCsv
, trainTest
, kFold
, Scaler
, StandardScaler (StandardScaler)
, fit
, scale
, testTargets
) where

import Data.List (transpose)
import Utils (mean, rmdups, splitList, std, uniqueRandomList)

-- | Um tipo que representa um dataset, com valores de caracteristicas e
-- classes correspondentes
type Dataset = ([[Double]], [String])

-- | Le um arquivo '.csv' separado por ',' e retorna um 'Dataset' e uma lista
-- de 'String' que representa as classes do problema
readCsv :: String -> IO ((Dataset, [String]))
readCsv file = do
  content <- readFile file
  return (featClass $ map (splitList (== ',')) $ lines content)
  where
    featClass x = ((feats, targets), classes) -- Separando o conteudo do arquivo em caracteristicas e classes
      where
        feats = map (init . map read) x
        targets = map last x
        classes = rmdups targets

-- | Separa um 'Dataset' em dois 'Dataset's de treino e de teste. Os testes tem
-- possuem 'p' elementos, um valor percentual da quantidade de dados totais do 'Dataset'
trainTest :: Dataset -> Double -> Int -> IO (Dataset, Dataset)
trainTest (feats, targets) p s = do
  let total = truncate ((p / 100) * (fromIntegral (length feats)))
  let test_idx = uniqueRandomList 0 (length feats - 1) total s
  let train_idx = [t | t <- [0 .. (length feats - 1)], all (/= t) test_idx] -- Preenchendo os dados de treino com os que nao foram
  let train = (select feats train_idx, select targets train_idx) -- selecionados para teste
  let test = (select feats test_idx, select targets test_idx)
  return (train, test)

-- | Separa um dataset em k folds de treino e teste. Caso os dados nao possam ser divididos igualmete
-- em k folds, os r primeiros folds serao preenchidos com os dados que restaram da divisao. Se dividirmos
-- [9, 3, 2, 4, 1, 5, 7, 10, 6, 8] em 4 folds, teremos [[9, 3, 6], [2, 4, 8], [1, 5], [7, 10]] como indices de teste.
kFold :: Dataset -> Int -> Int -> [(Dataset, Dataset)]
kFold (feats, targets) k s =
  map (\i -> trainTest' i) $ kFoldIdx k remainder idx size
  where
    idx = reverse $ uniqueRandomList 0 (length feats - 1) (length feats) s -- Criando uma lista de indices aleatoria
    size = (length feats) `div` k
    remainder = (length feats) `mod` k

    kFoldIdx :: Int -> Int -> [a] -> Int -> [[a]] -- Gerando os indices de teste para cada fold
    kFoldIdx n r idx sz
      | n == 0 = []
      | r == 0 = [take sz idx] ++ (kFoldIdx (n -1) 0 (drop sz idx) sz)
      | otherwise = [(take sz idx) ++ [idx !! (length idx - r)]] ++ (kFoldIdx (n -1) (r -1) (drop sz idx) sz)

    trainTest' i = (train, test)
      where
        train = (select feats train_idx, select targets train_idx)
        test = (select feats i, select targets i)
        train_idx = [t | t <- [0 .. (length feats - 1)], all (/= t) i]

select :: [a] -> [Int] -> [a]
select _ [] = []
select [] _ = []
select xs idx = [xs !! i | i <- idx]

-- | A classe 'Scaler' define um padronizador de dados. Uma instância deve implementar uma função 'fit' que ajusta os parâmetros do
-- padronizador aos dados fornecidos e uma função 'scale' que aplica a padronização à um conjunto de dados
class Scaler s where
  fit :: s -> [[Double]] -> s
  scale :: s -> [[Double]] -> [[Double]]

-- | O 'StandardScaler' é uma instância de 'Scaler'. É ferramenta utilizada para realizar a padronizacao de dados. Contruido com duas
-- listas de 'Double', a primeira sendo as medias de cada caracteristica e a segunda o desvio padrao das mesmas
data StandardScaler = StandardScaler | StandardScalerFit [Double] [Double]

instance Scaler StandardScaler where
  fit (StandardScaler) xs = (StandardScalerFit u s)
    where
      u = map mean (transpose xs)
      s = map std (transpose xs)
  
  scale (StandardScalerFit u s) xss = map (\xs -> map (\(x, i) -> (x - (u !! i)) / (s !! i)) $ zip xs [0 .. ]) xss

-- | Extrai as classificacoes dos folds de teste de um conjunto de folds e concatena essas classes. Util para gerar uma matriz
-- de confusao levando em consideracao as classificacoes preditas de cada fold
testTargets :: [(Dataset, Dataset)] -> [String]
testTargets = foldl (\l (_, (_, t)) -> l ++ t) []

