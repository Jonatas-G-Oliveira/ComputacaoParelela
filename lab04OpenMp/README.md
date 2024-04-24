Nome:Jônatas Garcia de Oliveira TIA:4218232
# Lab03 - OpenMP
  Para este lab optei por deixar os parametros a,b,n e threads definidos no códigos por questão de comodidade
### Instruções de execução
<p>
   Para este lab foram feitas duas versões,ambas utilizam a biblioteca <math.h>,portanto é necessário inclui-la no momento de compilação utilizando o parâmetro -lm<br>
   Versão Serial -> <code> gcc  lab04_serial.c -lm -o saida.out </code> <br>
   Versão Paralela -> <code> gcc lab04.threads.c -lm -o saida.out -fopenmp </code>
</p>

### Executando:
  ./saida.out

## Informação sobre o processador
   <p>Para esse exercício eu utilizei uma VM que utiliza UBUNTU 22 e um processador com 6 núcleos fisicos.<br>
   Eu emulei mais 2 núcleos lógicos porém sei que não é uma boa práticas,fiz apenas para fins de estudo.</p>
   <img src ="https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/lab03Threads/imagens/info_cpu.png">
   

## Métricas
  <p>
      Para verificar o tempo de execução foi utilizado o comando time ./nomeDOprograma<br>
      Foram feitas 5 execuções de cada caso.
  </p>
  <img src ="https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/lab04OpenMp/imagens/execucao.jpg">
  <p>A partir das média das execuções eu fiz um gráfico de tempo de execução que demonstra melhora na execução até a 6º Thread</p>
  <img src ="https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/lab04OpenMp/imagens/tempo_threads.jpg">
  <p>Foi feito um gráfico de speedUp evidenciando a melhora de execução utilizando 6 threads</p>
  <img src ="https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/lab04OpenMp/imagens/speedUp.jpg">


## Diretiva Critical
  <p>Para os testes anteriores eu já estava utilizando essa diretiva para garantir a integridade do programa porém...</p>
  <p>ao destivar essa diretiva o programa rodou quase que instantaneamente mesmo com uma entrada grande como a de 1.000.000 de trapézios<p><br>
  <p>Utilizei as mesma metodologias para fazer os gráficos</p><br>
  <strong>Gráficos: </strong><br>
  <img src = "https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/lab04OpenMp/imagens/execucao_diretiva.jpg">
  <img src = "https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/lab04OpenMp/imagens/tempo_threads_diretiva.jpg">
  <img src = "https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/lab04OpenMp/imagens/speedUp_diretivas.jpg">
  
### Obrigado ;_;/



