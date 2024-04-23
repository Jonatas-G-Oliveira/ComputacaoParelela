Nome:Jônatas Garcia de Oliveira TIA:4218232
# Lab03 - OpenMP
  Para este lab optei por deixar os parametros definidos no programa por questão de comodidade
### Instruções de execução
<p>
  Para este lab foram duas versões,ambas utilizam a biblioteca <math.h>,portanto é necessário inclui-la no momento de compilação utilizando o parametro -lm
  Versão Serial -> gcc  nome_serial.c -lm -o saida.out 
  Versã Paralela -> gcc nome_paralelo.c -lm -o saida.out -fopenmp
</p>

### Executando:
  ./saida.out

## Informação sobre o processador
   Para esse exercicio eu utilizei uma VM que utiliza UBUNTU 22 e um processador com 6 núcleos fisicos.
    Antigamente eu emulava mais 2 nucleos lógicos,porém após conversas com o professor percebi que não fazia tanto sentido

## Métricas
  Para verifacar o tempo de execução foi utilziado o comando time ./nomeDOprograma
  Foram feitas 5 execuções de cada caso.



## Gráfico feito a partir das médias de execução



## Diretiva Critical
  Sem essa diretiva o programa tem execuções além do esperado,resultando em números inconstantes
  [Inserir Imagem]

## SpeedUp



# Obrigado



