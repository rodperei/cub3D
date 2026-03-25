## Variável: `char *map`

Esta variável armazena o endereço de memória base do mapa alocado dinamicamente. Embora o mapa seja logicamente uma matriz bidimensional, ele é tratado como um bloco de **memória contígua** no programa.

### Acesso e Estrutura (Row-Major Order)

Para simular uma matriz $M(i, j)$ num array linear, utilizamos a convenção **row-major ordering**. O cálculo do índice (_offset_) para aceder a uma célula específica é feito através da fórmula:

$$index = (i \times \text{total\_colunas}) + j$$

Onde:

- **$i$**: Índice da linha atual.
    
- **$j$**: Índice da coluna atual.
    
- **$\text{total\_colunas}$**: A largura total da matriz.
    

---

### Legenda de Valores do Mapa

Os caracteres armazenados no `map` definem a lógica do cenário:

| **Valor**      | **Descrição**                                                                            |
| -------------- | ---------------------------------------------------------------------------------------- |
| **-1**         | **Área Inválida:** Útil para definir limites em mapas não retangulares.                  |
| **0**          | **Espaço Vazio:** Área navegável para o jogador.                                         |
| **1**          | **Parede/Obstáculo:** Bloqueia a passagem do jogador.                                    |
| **N, S, E, W** | **Ponto de Partida:** Define a posição e a orientação inicial (Norte, Sul, Este, Oeste). |

> **Recursos Adicionais:** > * Para entender melhor a alocação de matrizes em C, consulta este tópico no [StackOverflow](https://stackoverflow.com/questions/2128728/allocate-matrix-in-c).
> 
> - Sobre a organização de memória, consulta o artigo da Wikipedia sobre [Row- and Column-major order](https://en.wikipedia.org/wiki/Row-_and_column-major_order).
>