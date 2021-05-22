import Classifiers (predictCentroid, predictNN)
import DataHandler (readCsv, trainTest)
import Metrics (accuracy, confusionMat)
import Text.Printf (printf)
import Utils (asDouble, asInt, prompt, showMat)

main :: IO ()
main = do
  input <- prompt "Forneça o nome do arquivo de entrada: "
  output <- prompt "Forneca o nome do arquivo de saida: "
  pTest <- asDouble $ prompt "Forneca o percentual de exemplos de teste: "
  randomSeed <- asInt $ prompt "Forneca o valor da semente para geracao randomizada: "

  ((feats, targets), classes) <- readCsv input
  if classes == [] -- Caso o arquivo de entrada seja vazio
    then do
      putStrLn "ERRO: Não foi possível obter nenhum dado do arquivo."
      return ()
    else do
      (train, test) <- trainTest (feats, targets) pTest randomSeed

      -- Realizando a predicao dos Vizinhos mais Proximos
      let predNN = predictNN train (fst test)
      let accNN = accuracy (snd test) predNN
      printf "Acuracia(vizinho): %.2f%%\n" $ accNN * 100

      -- Realizando a predicao dos Centroides
      let predCentroid = predictCentroid train (fst test)
      let accCentroid = accuracy (snd test) predCentroid
      printf "Acuracia(centroide): %.2f%%\n" $ accCentroid * 100

      -- Gerando as matrizes de confusao e escrevendo no arquivo de saida
      let matNN = showMat $ confusionMat predNN (snd test) classes
      let matCentroid = showMat $ confusionMat predCentroid (snd test) classes
      writeFile output $ "vizinho mais próximo:\n" ++ matNN ++ "\ncentroides:\n" ++ matCentroid
      return ()