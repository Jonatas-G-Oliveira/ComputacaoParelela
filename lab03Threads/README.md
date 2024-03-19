###  Nome:Jônatas Garcia de Oliveira RA:10396490

## Multiplicação matriz-vetor
- Notas do programador:
- O erro do lab anterior foi corrigido,agora o programa pode dividir qualquer quantidade de linhas para serem executadas por qualquer quantidade de threads
- Além da melhoria,para esse lab foi desenvolvida um solução serial para o problema.
  
## Instruções para execução:
- Para esse lab foram feitas duas versões do programa.

###  Compilando o  arquivo:
- gcc mult_matriz_serial.c -o a.out
- gcc mult_matriz.c -o b.out

###  Executando:
- ./a.out
- ./b.out

### Comprovando os resultados
- Para esse exercicio eu utilizei uma VM que utiliza UBUNTU 22 e um processador com 6 núcleos fisicos,porém como eu precisava de mais 2
- núcleos eu emulei 2 núcleos lógicos na VM.
  ### Informações do processador
 <p align = "center">
     <img src = https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/lab03Threads/imagens/info_cpu.png>
  </p>
 
### Foram feitas 5 execuções para cada caso:
- Cada execução foi feita para uma matriz de tamanho 6000 L x 40000 C
 <p align = "center">
     <img src = https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/lab03Threads/imagens/Tabela_Execu%C3%A7%C3%B5es.png>
  </p>

### Gráfico feito a partir das médias de execução
 <p align = "center">
     <img src = https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/lab03Threads/imagens/Gr%C3%A1fico.png>
  </p>

### Discussão sobre o SpeedUP
  - Podemos observar uma boa diferença de 0.6s entre 1 e 4 threads,porém a partir desse ponto a diferença começa a diminuir conforme adicionamos mais threads
  - Para melhorar o desempenho do algoritmo poderiamos nos beneficiar da memória cache do processador na forma como acessamos as matrizes,porém ainda não consegui implementar essa versão

- Muito Obrigado ´_´/
