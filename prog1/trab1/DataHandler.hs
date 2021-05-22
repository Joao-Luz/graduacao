module DataHandler where

import Utils (rmdups, splitList, uniqueRandomList)

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
  let train = (select feats train_idx, select targets train_idx)            -- selecionados para teste
  let test = (select feats test_idx, select targets test_idx)
  return (train, test)
  where
    select _ [] = []
    select [] _ = []
    select xs idx = [xs !! i | i <- idx]
