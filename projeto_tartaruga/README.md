# Série de Taylor - Operação Tartaruga


## Compilar e executar o programa serial:
- O código fonte se chama tartarugaGMP.c 
- Compilar <code>gcc tartarugaGMP.c -o a.out -lgmp </code>
- Executar <code>./a.out </code>

## Compilar e executar o programa paralelo:
- O código fonte se chama tartarugaParalela.c 
- Compilar <code>gcc tartarugaParalela.c -o a.out -lgmp -fopenmp </code>
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
<p>A biblioteca gmp nos permite manusear números grandes com uma taxa de bit determinada</p>
### Como funciona?
<p>Para armazener o fatorial,o resultado da divsao e a soma eu utilizei 14000 bits</p>
<p>Sendo assim eu consegui uma aproximação muito boa para 1800 passos do algoritmo de euler</p>

- <img src ="https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/projeto_tartaruga/imagens/Euler.png">
- Consegui um resultado de +8000 bits de precisão.
- <img src ="https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/projeto_tartaruga/imagens/Resultado.png">
## Terceira Versão do programa(Paralelo)
<br> Para a versão paralela do programa eu utilizei a biblioteca <code>gmp.h</code> para lidar com números grandes 
<br> Utilizei a biblioteca <code>openmp.h</code> para fazer a paralelização
<br> Para a paralização eu dividi o numero de tarefas igualmente para cada thread,porém a ultima thread irá trabalhar caso sobre tarefas nessas divisões.
<br> As versões possuem resultados iguais se voce definir a mesma configuração para ambas.

## Resultado e considerações Finais
<p>
    Executei 5 testes para cada caso para obter o resultado de +20000 casas decimais
   <img src ="https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/projeto_tartaruga/imagens/Tabela_Execu%C3%A7%C3%B5es.jpg"><br>
</p>
<p>
   Após tirar as médias eu fiz um gráfico demonstrando o tempo de execução.
   <img src ="https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/projeto_tartaruga/imagens/Thread_Tempo.jpg"><br>
</p>
   Podemos perceber como a paralelização foi benéfica para o programa através do gráfico de speedUp.
   <img src ="https://github.com/Jonatas-G-Oliveira/ComputacaoParelela/blob/main/projeto_tartaruga/imagens/SpeedUp.jpg"><br>
</p>

<p>
   Muito obrigado pela atenção -_-/
</p>
