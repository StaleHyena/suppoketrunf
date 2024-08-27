# Super Poké-Trunfo

Programa desenvolvido para a cadeira de Algoritmos e Estruturas de Dados.
Um jogo similar ao Super Trunfo da Grow, adaptado para cartas de Pokémon.

## Compilar
Clone o repositório e execute `$ make` na sua pasta raíz.
Também existe a possibilidade de compilar no modo debug:
`$ make debug`

A saída é um único executável chamado `pokemon`.

## Jogar
Rode o comando `$ ./pokemon`. Caso reclame que o arquivo não existe, compile
o projeto novamente (`$ make clean && make`) e tente outra vez.

O programa inicia apresentando a escolha entre o jogo de fato (o padrão) ou
a pesquisa por nome na Pokedéx.

Selecionar o jogo traz um menu de configurações
que permite determinar o número de jogadores, o número de cartas (aleatórias)
por jogador, e quais jogadores são reais e quais são controlados por computador.
Caso não escolhas um valor válido para determinado item, um valor predefinido
é utilizado. O valor padrão para jogadores é o controlado por computador!

Selecionar a pesquisa por nome na Pokedéx te coloca em um ambiente onde toda
linha que é inserida no terminal é considerada um prefixo de busca sobre
todos os nomes, exceto a palavra especial "quit". Já que a pesquisa é por
prefixo, é provável que apareça mais de um resultado de busca. Os resultados
são impressos um por linha, contendo o nome e os atributos dos pokémons.

### Regras
 - Cada jogador possuí uma pilha de cartas embaralhadas do mesmo tamanho que os
demais jogadores, na qual somente a carta do topo é exposta ao mesmo.
 - O objetivo é ganhar todas as cartas do jogo.
 - Em cada rodada:
   - Se for a vez do jogador, ele escolhe um atributo da sua carta.
   - O atributo escolhido é usado para comparar as cartas dos jogadores, vencendo a carta com o maior valor dentre elas.
   - O vencedor recebe todas as cartas jogadas nessa rodada (inclusive a sua), para colocar na base da sua pilha.
   - Caso especial: pokémons lendários sempre vencem pokémons convencionais na comparação por atributo. Lendários contra lendários é resolvido como no caso convencional contra convencional.
   - Em caso de empate, uma rodada restrita aos empatados é realizada (rodada-desempate); o vencedor da rodada-desempate recebe todas as cartas dessa rodada e as das subsequentes rodadas-desempate. Podem ocorrer rodadas-desempate aninhadas.
 - Vence o jogador que atinge o objetivo de ter todas as cartas do jogo.

### Exemplo de rodada
