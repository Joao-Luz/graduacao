## Roteiro 9

Usando pipes como mecanismo de comunicação entre processos, crie um programa que execute o seguinte procedimento:
- O processo pai, P0, lê do teclado um valor X inteiro entre 1-5.
- P0 cria dois filhos, P1 e P2.
- P0 envia para o filho P1, via pipe (primeiro pipe), o valor de X.
- P0 envia também para P1, pelo mesmo pipe, a seguinte mensagem (string): "Meu filho, crie e envie para o seu irmão um array de números inteiros com valores randômicos entre 1 e o valor enviado anteriormente. O tamanho do array também deve ser randômico, na faixa de 1 a 10".
- P1 recebe e imprime a mensagem enviada pelo pai.
- P1 cria o array de tamanho randômico, entre 1 e 10, preenchendo-o com valores randômicos, entre 1 e X, conforme solicitado pelo pai.
- P1 envia o array para o irmão P2, via pipe (segundo pipe).
- P2 recebe o array e faz a soma dos seus valores.
- P2 envia o resultado da soma para o processo pai (P0), via pipe (terceiro pipe).
- P0 imprime o resultado da soma.
