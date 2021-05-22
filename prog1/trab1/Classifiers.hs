module Classifiers (predictCentroid, predictNN) where

import Data.Function (on)
import Data.List (groupBy, sortBy)
import Data.Ord (comparing)
import DataHandler (Dataset)
import Utils (addLists, distance, multList)

-- | O classificador Nearest Neighbor (Vizinho mais proximo). Realiza uma predicao
-- dos dados de test baseado em dados de treino provenientes de um 'Dataset'
predictNN :: Dataset -> [[Double]] -> [String]
predictNN (feats, targets) test = map findNN test
  where
    findNN xs =
      snd
        . _nearest xs
        $ zip feats targets

-- | O classificador Centroide. Realiza uma predicao dos dados de test baseado 
-- em dados de treino provenientes de um 'Dataset'
predictCentroid :: Dataset -> [[Double]] -> [String]
predictCentroid train test = map findCentroid test
  where
    findCentroid xs =
      snd
        . _nearest xs
        $ centroids
      where
        centroids = map (\(d, t) -> (multList (1 / fromIntegral (length d)) (addLists d), t)) $ groups $ zip (fst train) (snd train)
          where
            groups = map (\l -> (map fst l, snd . head $ l)) . groupBy ((==) `on` snd) . sortBy (comparing snd)

_nearest :: Foldable t => [Double] -> t ([Double], [Char]) -> (Double, [Char]) -- Queremos encontrar um valor mínimo em uma lista para ambos os 
_nearest xs =                                                                  -- os classificadores, então uma função em comum pode sem implementada
  foldl
    ( \(d, c) (f, t) ->
        if (distance xs f) < d || d == -1 then (distance xs f, t) else (d, c)
    )
    firstDist
  where
    firstDist = (-1, "")