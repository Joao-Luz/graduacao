module Utils where

import Data.List (intercalate, transpose)
import System.Random (Random (randomR), mkStdGen)
import System.IO ( stdout, hFlush )

-- | Imprime uma mensagem em stdout e le e retorna um input de stdin
prompt :: String -> IO (String)
prompt msg = do
  putStr msg
  hFlush stdout
  getLine

-- | Converte uma String de input em um Double
asDouble :: IO (String) -> IO (Double)
asDouble s = do
  num <- s
  return (read num :: Double)

-- | Converte uma String de input em um Int
asInt :: IO (String) -> IO (Int)
asInt s = do
  num <- s
  return (read num :: Int)

-- | Gera uma lista numeros aleatorios unicos entre 'lo' e 'hi' e de tamanho de tamanho 'sz'
-- usando uma semente de aleatorios 's'
-- 
-- >>> uniqueRandomList 0 10 5 23
-- [9,3,2,8,0]
uniqueRandomList :: Int -> Int -> Int -> Int -> [Int]
uniqueRandomList lo hi sz s = uniqueRandomList' lo hi sz g []
  where
    g = (mkStdGen s)
    uniqueRandomList' lo hi sz gn xs
      | length xs >= sz = xs
      | any (== num) xs = uniqueRandomList' lo hi sz ng xs
      | otherwise = uniqueRandomList' lo hi sz ng (num : xs)
      where
        (num, ng) = randomR (lo, hi) gn

-- | Quebra uma String em uma lista de String
--
-- >>> splitList (==',') "Pao,Leite,Frutas,Haskell"
-- ["Pao","Leite","Frutas","Haskell"]
splitList :: (Char -> Bool) -> String -> [String]
splitList p s = case dropWhile p s of
  "" -> []
  s' -> w : splitList p s''
    where
      (w, s'') = break p s'

-- | Soma varias listas de 'Num's elemento a elemento, resultando em uma unica
-- lista de 'Num's
--
-- >>> addLists [[1, 1, 1], [2, 2, 3], [4, 5, 1]]
-- [7,8,5]
--
-- >>> addLists [[0.1, 1.2, 12.9], [3.9, 2.8, 9.1]]
-- [4.0,4.0,22.0]
addLists :: Num a => [[a]] -> [a]
addLists xss = map sum . transpose $ xss

-- | Multiplica uma lista de 'Num's por um valor escalar, elemento por elemento
--
-- >>> multList 2 [1.0, 2.0, 3.5]
-- [2.0,4.0,7.0]
multList :: Num b => b -> [b] -> [b]
multList x xs = map (x *) xs

-- | Calcula a distancia euclidiana entre dois pontos com coordenadas representadas
-- por listas de 'Double'
--
-- >>> distance [0, 0] [0, 1]
-- 1.0
distance :: [Double] -> [Double] -> Double
distance xs ys = (sqrt . sum) [(x1 - x2) ^ 2 | (x1, x2) <- zip xs ys]

-- | Remove valores duplicados de uma lista
--
-- >>> rmdups [1, 1, 2, 3, 3, 2, 4, 5, 5]
-- [1,2,3,4,5]
rmdups :: Eq a => [a] -> [a]
rmdups =
  foldl
    ( \seen x ->
        if x `elem` seen
          then seen
          else seen ++ [x]
    )
    []

-- | Transforma uma matriz de inteiros em uma 'String' formatada
--
-- >>> showMat [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
-- "  1,  0,  0\n  0,  1,  0\n  0,  0,  1\n"
showMat :: [[Int]] -> String -- Poderiamos utilizar da funcao printf, mas foi optado criar uma funcao para gerar uma string a fim de manter a pureza
showMat xss = unlines $ map (\xs -> intercalate "," (map (\x -> replicate (3 - (length . show) x) ' ' ++ (show x)) xs)) xss
