# Série de Taylor - Operação Tartaruga


## Compilar e executar o programa:
- O código fonte se chama tartaruga.c
- Compilar <code>gcc tartaruga.c -o a.out </code>
- Executar <code>./a.out </code>
## Primeira versão do programa

### "Números pequenos"
<p>Pra esse primeira versão eu fiz um programa serial que funciona para números fatoriais "pequenos"
- Para essa solução utilizei o tipo primitvo  <code>float</code> ,o que me permitiu gerar até o 9! sem complicações.
- Por enquanto fiz apenas a versão serial,pois tenho que resolver o fato do programa ter que lidar com números maiores.

### Aproximação gerada para série com 9 etapas:
- <img src ="https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/projeto_tartaruga/imagens/1_versaoTurtle.jpg" alt="primeira Versão do projeto">

### "Números grandes"
<p>Estou fazendo uma segunda versão para corrigir o problema de números da primeira versão.
- Trocar o tipo primitivo para double não vai adiantar pois os números que estamos lidando são de grandezeas maiores do que as suportadas pelos tipos primitivos do C.
- Por enquanto consegui implementar o fatorial de qualquer número utilizando um vetor de digitos inteiros para armazenar as posições</p><br>
- Porém me encontro travado nos seguintes problemas:
<p> --> <strong>Divisão de numeros grandes utilizando um vetor</strong> </p>
<p> --> <strong>Soma das divisões para gerar a resposta.</strong> </p>
