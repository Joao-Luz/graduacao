module Metrics where

import Classifiers
import DataHandler

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

-- | Realiza a validacao cruzada com um classificador e os folds. Cada fold deve ser padronizado por um 'Scaler' utilizando os dados de treino
scaledCrossVal :: (Classifier c, Scaler s) => c -> s -> [(Dataset, Dataset)] -> ([Double], [[String]])
scaledCrossVal c s folds = unzip $ map accPred folds
  where
    accPred ((f, t), (feats, targets)) = (accuracy targets predictions, predictions)
      where
        predictions = 
          let scaler = fit s f in 
            predict (train c (scale scaler f, t)) (scale scaler feats)

-- | Realiza a validacao cruzada com um classificador e os folds
crossVal :: (Classifier c) => c -> [(Dataset, Dataset)] -> ([Double], [[String]])
crossVal c folds = unzip $ map accPred folds
  where
    accPred ((f, t), (feats, targets)) = (accuracy targets predictions, predictions)
      where
        predictions = predict (train c (f, t)) feats