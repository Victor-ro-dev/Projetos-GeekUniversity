# Projetos em C - Geek University

Este repositório contém diversos projetos desenvolvidos em linguagem C, originados do curso da Geek University. Os projetos têm como objetivo fornecer uma compreensão prática da programação em C, abordando conceitos como estruturas de dados, controle de fluxo, manipulação de arquivos, e muito mais.

## Projetos Incluídos

### 1. Jogo de Matemática

Este projeto é um jogo de matemática onde o usuário deve resolver operações simples (adição, subtração e multiplicação) com base em um nível de dificuldade selecionado. A cada resposta correta, o usuário ganha um ponto. O jogo continua até que o usuário decida sair.

**Principais Funcionalidades:**
- Escolha de nível de dificuldade (1 a 4).
- Geração aleatória de operações matemáticas.
- Contador de pontos do jogador.

### 2. Sistema de Vendas

Este projeto simula um sistema de vendas onde o usuário pode cadastrar produtos, listar produtos disponíveis, e adicionar produtos a um carrinho de compras. O sistema permite visualizar o carrinho e fechar um pedido.

**Principais Funcionalidades:**
- Cadastro de produtos com nome e preço.
- Listagem de produtos cadastrados.
- Adição de produtos ao carrinho de compras.
- Cálculo do valor total do carrinho ao fechar o pedido.

### 3. Sistema Bancário

Este projeto simula um sistema bancário onde o usuário pode criar contas, efetuar saques, depósitos e transferências. Ele também permite listar as contas existentes.

**Principais Funcionalidades:**
- Criação de contas bancárias para clientes.
- Efetuação de saques e depósitos.
- Transferência de valores entre contas.
- Listagem das contas e seus saldos.

## Instruções de Uso

1. **Compilar os projetos:**
   Utilize um compilador C, como `gcc`, para compilar os arquivos fonte.
   ```bash
   gcc -o jogo jogo.c
   gcc -o sistema_vendas sistema_vendas.c
   gcc -o sistema_bancario sistema_bancario.c
