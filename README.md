Simulador de Batalha Naval em C

Este projeto apresenta uma sequência de versões de um jogo simplificado de Batalha Naval, desenvolvido em linguagem C. O objetivo é demonstrar o uso de matrizes bidimensionais, estruturas de repetição, validação de posições, e formas geométricas em grade, por meio de três níveis de dificuldade: Iniciante, Médio e Avançado.
🧩 Nível Iniciante
Descrição

Nesta versão inicial, o jogador insere dois navios simples de tamanho fixo (3 espaços):

    Um posicionado horizontalmente

    Outro posicionado verticalmente

Ambos são inseridos em um tabuleiro de 10x10, representado por uma matriz int[10][10].
Conceitos abordados

    Inicialização de matrizes

    Estruturas de repetição for

    Validação de espaço disponível antes da inserção

    Impressão de matrizes em formato de tabuleiro

Exemplo de saída

0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 3 3 3 0 0 0
...

🧠 Nível Intermediário
Descrição

Nesta versão intermediária, são adicionados dois novos tipos de navios:

    Um na diagonal principal (↘)

    Outro na diagonal inversa (↙)

Antes de inserir esses navios, o programa valida se há espaço disponível e se não existe sobreposição com outros navios.
Conceitos abordados

    Validação de limites em diagonais

    Prevenção de sobreposição

    Incremento de complexidade no posicionamento

    Uso de operadores lógicos com estruturas if

Novas habilidades

    Análise de colisões

    Uso de diagonais em matrizes

🧠💡 Nível Avançado
Descrição

A versão mais avançada insere navios com formatos geométricos customizados no tabuleiro, incluindo:

    Cone

    Cruz

    Octaedro

Cada forma é representada por uma máscara 5x5, onde 1 indica parte do navio e 0 espaço vazio. As máscaras são sobrepostas no tabuleiro principal, respeitando os limites e verificando se há colisões com outros navios.
Conceitos abordados

    Máscaras bidimensionais para formas complexas

    Aplicação de operações com deslocamento de coordenadas (i - 2, j - 2)

    Macro para validação de intervalo (#define ENTRE(x, lo, hi))

    Inserção condicional de formas

    Reutilização de código com laços aninhados

Exemplo visual

cone[5][5] =
  {0, 0, 1, 0, 0},
  {0, 1, 1, 1, 0},
  {1, 1, 1, 1, 1},
  {0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0}

Resultado no tabuleiro

Números diferentes indicam diferentes tipos de navios (por exemplo, 3 para navios lineares e 5 para navios geométricos).
