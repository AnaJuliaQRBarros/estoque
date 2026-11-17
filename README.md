Uma pequena empresa deseja informatizar o controle de seu estoque. O sistema deverá permitir o
cadastro, a consulta, a atualização e a remoção de produtos, além da emissão de uma listagem organizada.
Neste projeto, você desenvolverá uma aplicação em linguagem C que utiliza duas estruturas de dados
simultaneamente:

• Tabela hash com encadeamento separado: utilizada para localizar produtos pelo código.

• Árvore binária de busca (ABB): utilizada para localizar produtos pelo nome e gerar uma listagem
em ordem alfabética.

As duas estruturas deverão armazenar referências para os mesmos registros de produtos. Portanto, cada
produto será alocado uma única vez na memória.
