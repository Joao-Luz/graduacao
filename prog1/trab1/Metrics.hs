module Metrics where

-- | Retora a acuracia entre duas listas. A acuracia é calculada como o numero de acertos
-- entre as duas listas dividido pelo tamanho delas
--
-- >>> accuracy [1, 0, 1, 0] [1, 1, 1, 1]
-- 0.5
accuracy :: (Eq a) => [a] -> [a] -> Double
accuracy xs ys = sum [if x == y then 1 else 0 | (x, y) <- (zip xs ys)] / (fromIntegral $ length xs)

-- | Retorna uma matriz de confusao entre duas listas, levando em consideracao uma terceira
-- lista de classes do problema.
--
-- >>> confusionMat [1, 0, 1, 0] [1, 1, 1, 1] [0, 1]
-- [[0,2],[0,2]]
confusionMat :: Eq a => [a] -> [a] -> [a] -> [[Int]]
confusionMat preds targets classes = map (\r -> map (\c -> (eqs c r)) classes) classes
  where
    eqs c r = length $ filter (== (c, r)) (zip targets preds)