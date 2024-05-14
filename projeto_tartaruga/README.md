# Série de Taylor - Operação Tartaruga


## Compilar e executar o programa:
- O código fonte se chama tartaruga.c
- Compilar <code>gcc tartaruga.c -o a.out </code>
- Executar <code>./a.out </code>
## Primeira versão do programa(Serial)

### "Números pequenos"
<p>Pra esse primeira versão eu fiz um programa serial que funciona para números fatoriais "pequenos"
- Para essa solução utilizei o tipo primitvo  <code>float</code> ,o que me permitiu gerar até o 9! sem complicações.
- Por enquanto fiz apenas a versão serial,pois tenho que resolver o fato do programa ter que lidar com números maiores.

### Aproximação gerada para série com 9 etapas:
- <img src ="https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/projeto_tartaruga/imagens/1_versaoTurtle.jpg" alt="primeira Versão do projeto">

### "Resolvendo números grandes"
<p>Para resolver o problema de armazenamento dos números em C,eu pensei em utilizar um vetor para armazenar cada numero,sendo assim 120 seria representado como <code>[1][2][0]</code>
<p>Eu consegui realizar essa lógica para criar a função fatorial
   <img src ="https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/projeto_tartaruga/imagens/Fatorial.png">
   - Código disponível em :https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/tree/main/projeto_tartaruga/testes> -> fatGrande.c 
</p>
<p><br>Porém me encontrei travado em como fazer uma operação de divisão onde o dividendo seria menor que o divisor...após muitas tentativas,desisti de pensar dessa forma<P>

## Segunda Versão do programa(Serial)
<p>Para a segunda versão eu utilizei a biblioteca <code>gmp.h</code></p>
<p>A biblioteca gmp nos permite manusear números com uma taxa de bits determinada</p>
<p>Para armazener o fatorial,o resultado da divsao e a soma eu utilizei 14000 bits</p>
<p>Sendo assim eu consegui uma aproximação muito boa para 1800 passos do algoritmo de euler</p>

- <img src ="https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/projeto_tartaruga/imagens/Euler.png">

## Terceira Versão do programa(Paralelo)



## Resultado e considerações Finais
