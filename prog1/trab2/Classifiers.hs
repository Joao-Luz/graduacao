module Classifiers 
(
  Classifier
, train
, predict
, KNN (KNN)
, Centroid (Centroid)
) where

import Data.Function (on)
import Data.List (groupBy, sortBy)
import Data.Ord (comparing)
import DataHandler (Dataset)
import Utils

-- | Classe Classifier que representa um classificador qualquer. Deve implementar 'train' e 'test'
class Classifier c where
  -- | Treinar um classificador com um 'Dataset'
  train :: c -> Dataset -> c

  -- | Avalia um conjunto de dados utilizando o classificador treinado
  predict :: c -> [[Double]] -> [String]

-- | O classificador 'KNN'
data KNN = KNN Int | KNNTrained Int Dataset

-- | O classificador 'Centroid'
data Centroid = Centroid | CentroidTrained Dataset

instance Classifier KNN where
  -- Pontos de treino são passados para o 'KNN'
  train (KNN k) d = KNNTrained k d
  train (KNNTrained k _) d = KNNTrained k d

  predict (KNN _) _ = []
  predict (KNNTrained k d) feats = predictKNN (KNNTrained k d) feats

instance Classifier Centroid where
  -- Calcular os centroides e criar um 'CentroidTrained' com esses centroides
  train (Centroid) d = CentroidTrained $ unzip $ map (\(d, t) -> (multList (1 / fromIntegral (length d)) (addLists d), t)) $ groups $ zip (fst d) (snd d)
    where
      groups = map (\l -> (map fst l, snd . head $ l)) . groupBy ((==) `on` snd) . sortBy (comparing snd)

  predict (CentroidTrained c) feats = predictCentroid (CentroidTrained c) feats

-- | Funcao que realiza a predicao dos dados usando um classificador KNN
predictKNN :: KNN -> [[Double]] -> [String]
predictKNN (KNNTrained k (feats, targets)) test =
  map ( \t -> let g = groups t in (trd . head) g ) test
  where
    trd (_, _, c) = c
    -- Ordenar 'groups' em ordem de maior frequencia e menor distancia media
    tSort (a1, b1, _) (a2, b2, _)
      | a1 > a2 = GT
      | a1 < a2 = LT
      | a1 == a2 = compare b1 b2
    -- A frequencia e distancia media de cada classe entre os k mais proximos
    groups xs = (sortBy tSort . map (\l -> (length l, mean [fst x | x <- l], (snd . head) l)) . groupBy ((==) `on` snd) . sortBy (comparing snd)) $ kNearest xs
    -- Os k dados mais proximos e suas respectivas classes
    kNearest xs = (take k $ sortBy (comparing fst) $ distances xs)
    -- As distancias entre o elemento e os demais dados do problema
    distances xs = map (\(f, t) -> (distance f xs, t)) $ zip feats targets

-- | O classificador Centroide. Realiza uma predicao dos dados de test baseado
-- em dados de treino provenientes de um 'Dataset'
predictCentroid :: Centroid -> [[Double]] -> [String]
predictCentroid (CentroidTrained centroids) feats = map findCentroid feats
  where
    findCentroid xs =
      snd
        . nearest xs
        $ zip (fst centroids) (snd centroids)
    nearest xs =
      -- os classificadores, então uma função em comum pode sem implementada
      foldl
        ( \(d, c) (f, t) ->
            if (distance xs f) < d || d == -1 then (distance xs f, t) else (d, c)
        )
        firstDist
      where
        firstDist = (-1, "")
