import Classifiers
import DataHandler
import Metrics
import Text.Printf (printf)
import Utils

main :: IO ()
main = do
  input <- prompt "Forneça o nome do arquivo de entrada: "
  output <- prompt "Forneca o nome do arquivo de saida: "
  f <- asInt $ prompt "Forneca o número de folds: "
  k <- asInt $ prompt "Forneca o número de vizinhos: "
  randomSeed <- asInt $ prompt "Forneca o valor da semente para geracao randomizada: "

  ((feats, targets), classes) <- readCsv input
  if classes == [] -- Caso o arquivo de entrada seja vazio
    then do
      putStrLn "ERRO: Não foi possível obter nenhum dado do arquivo."
      return ()
    else do
      let folds = kFold (feats, targets) f randomSeed
      -- Testando cada classificador
      let nn = KNN 1 -- Nearest neighbor é simplesmente o KNN com k = 1
      let (nnScores, nnPreds) = scaledCrossVal nn StandardScaler folds
      printf "Acuracia(vizinho): %.2f%%\nDesvio-Padrao(vizinho): %.2f%%\n" (100 * mean nnScores) (100 * std nnScores)
      let matNN = showMat $ confusionMat (concat nnPreds) (testTargets folds) classes

      let centroid = Centroid
      let (centroidScores, centroidPreds) = scaledCrossVal centroid StandardScaler folds
      printf "Acuracia(centroide): %.2f%%\nDesvio-Padrao(centroide): %.2f%%\n" (100 * mean centroidScores) (100 * std centroidScores)
      let matCentroid = showMat $ confusionMat (concat centroidPreds) (testTargets folds) classes

      let knn = KNN k
      let (knnScores, knnPreds) = scaledCrossVal knn StandardScaler folds
      printf "Acuracia(k-vizinhos): %.2f%%\nDesvio-Padrao(k-vizinhos): %.2f%%\n" (100 * mean knnScores) (100 * std knnScores)
      let matKNN = showMat $ confusionMat (concat knnPreds) (testTargets folds) classes

      -- Gerando o arquivo de saida com as matrizes de confusao
      writeFile output $ "vizinho mais próximo:\n" ++ matNN ++ "\ncentroides:\n" ++ matCentroid ++ "\nk-vizinhos mais próximos:\n" ++ matKNN
      return ()