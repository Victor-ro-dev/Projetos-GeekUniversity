#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct{
    int codigo;
    char nome[30];
    float preco;
}Produto;

typedef struct{
    Produto produto;
    int quantidade;
}Carrinho;

void infoProduto(Produto prod);
void menu();
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
Produto pegarProdutoPorCodigo(int codigo);
int * temNoCarrinho(int codigo);
void fecharPedido();

static int contador_produto = 0;
static int contador_carrinho = 0;
static Carrinho carrinho[50];
static Produto produtos[50];



int main(){
    menu();
    return 0;
}

void infoProduto(Produto prod){
    printf("Codigo: %d \nNome: %s \nPreco: %2.f\n", prod.codigo, strtok(prod.nome, "\n"), prod.preco);
}

void cadastrarProduto(){
    printf("Cadastro de Produto\n");
    printf("===================\n");

    printf("Informe o nome do Produto: \n");
    fgets(produtos[contador_produto].nome, 30, stdin);

    printf("Informe o Preco do produto: \n");
    scanf("%f", &produtos[contador_produto].preco);

    printf("Produto cadastrado com sucesso!\n", strtok(produtos[contador_produto].nome, "\n"));

    produtos[contador_produto].codigo = (contador_produto +1);
    contador_produto++;

    Sleep(2);
    menu();
}

void listarProdutos(){
    if(contador_produto > 0){
        printf("Listagem de Produto(s)\n");
        printf("======================\n");
        for(int i = 0; i < contador_produto; i++){
            infoProduto(produtos[i]);
            printf("Quantidade: %d\n", carrinho[i].quantidade);
            printf("--------------------\n");
            Sleep(1);
            menu();
        }

    }else{
        printf("Nao ha produtos cadastrados!\n");
        Sleep(2);
        menu();
    }
}

void menu(){
    printf("===================================================\n");
    printf("==================== Bem-vindo(a)==================\n");
    printf("==================== Loja do Vitao ================\n");
    printf("===================================================\n");

    printf("Selecione uma opcao abaixo: \n");
    printf("1 - Cadastrar Prodtuo\n" );
    printf("2 - Lista Prodtuo\n" );
    printf("3 - Comprar Prodtuo\n" );
    printf("4 - Vizualizar Carrinho\n" );
    printf("5 - Fechar Produto\n" );
    printf("6 - Sair do Sistema\n" );

    int opcao;
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
        case 1:
            cadastrarProduto();
            break;
        case 2:
            listarProdutos();
            break;
        case 3:
            comprarProduto();
            break;
        case 4:
            visualizarCarrinho();
            break;
        case 5:
            fecharPedido();
            break;
        case 6:
            printf("Obrigado por usar o nosso sistema!\n");
            Sleep(2);
            exit(0);              
        default:
        printf("Opcao Inválida!");
        Sleep(2);
        menu();
            break;    
    }
}

void visualizarCarrinho(){
    if(contador_carrinho > 0){
        printf("Produto(s) dos Carrinho\n");
        printf("======================\n");
        for(int i = 0; i < contador_carrinho; i++){
            infoProduto(carrinho[i].produto);
            printf("Quantidade: %d\n", carrinho[i].quantidade);
            printf("--------------------\n");
            Sleep(1);
        }
        Sleep(2);
        menu();
    }else{
        printf("Nao ha produtos no carrinho!\n");
        Sleep(2);
        menu();
    }
}

void comprarProduto(){
    if(contador_produto>0){
        printf("Informe o codigo do produto.\n");

        printf("===========Produtos disponiveis==============\n");
        for(int i = 0; i < contador_produto; i++){
            infoProduto(produtos[i]);
        printf("-------------------------------------------------\n");
        Sleep(1);    
        }
        int codigo;
        scanf("%d", &codigo);
        getchar();

        int tem_mercado = 0;
        for(int i = 0; i < contador_produto; i++){
            if(produtos[i].codigo == codigo){
                tem_mercado = 1;

                if(contador_carrinho>0){
                    int * retorno = temNoCarrinho(codigo);

                    if(retorno[0]==1){
                        carrinho[retorno[1]].quantidade++;
                        printf("Foi aumentada a quantidade do produto ja existente mo carrinho\n", strtok(carrinho[retorno[1]].produto.nome, "\n"));
                        Sleep(2);
                        menu();
                    }
                    else{
                        Produto p = pegarProdutoPorCodigo(codigo);
                        carrinho[contador_carrinho].produto = p;
                        carrinho[contador_carrinho].quantidade = 1;
                        contador_carrinho++;
                        printf("O Produto %s foi adicionado ao carrinho\n", strtok(p.nome, "\n"));
                        Sleep(2);
                        menu();
                    }
                }else{
                        Produto p =pegarProdutoPorCodigo(codigo);
                        carrinho[contador_carrinho].produto = p;
                        carrinho[contador_carrinho].quantidade = 1;
                        contador_carrinho++;
                        printf("O Produto %s foi adicionado ao carrinho\n", strtok(p.nome, "\n"));
                        Sleep(2);
                        menu();
                }
        }
        }
        if(tem_mercado < 1){
            printf("Nao foi encontrado o produto com o codigo %d\n", codigo);
            Sleep(2);
            menu();
        }
    }else{
        printf("Ainda não existe produtos\n");
        Sleep(2);
        menu();
    }
}

Produto pegarProdutoPorCodigo(int codigo){
    Produto p;
    for(int i=0; i < contador_produto; i++){
        if(produtos[i].codigo == codigo){
            p = produtos[i];
        }
    }
    return p;
}

int * temNoCarrinho(int codigo){
    int static retorno[] = {0,0};
    for(int i =0; i < contador_carrinho; i++){
        if(carrinho[i].produto.codigo == codigo){
            retorno[0] = 1;
            retorno[1] = i; 
        }
    }
    return retorno;
}

void fecharPedido(){
    if(contador_carrinho > 0){
        float valorTotal = 0.0;
        printf("Produtos do Carrinho\n");
        printf("--------------------\n");
        for(int i =0; i < contador_carrinho; i++){
            Produto p = carrinho[i].produto;
            int quantidade = carrinho[i].quantidade;
            valorTotal += p.preco *quantidade;
            infoProduto(p);
            printf("Quantidade: %d\n", quantidade);
            printf("----------------\n");
            Sleep(1);
        }
        printf("Sua fatura e R$ %2.f\n", valorTotal);

        contador_carrinho = 0;
        printf("Obrigado pela preferencia!\n");
        Sleep(5);
        menu();
    }else{
        printf("Voce não tem produto no carrinho!\n");
        Sleep(3);
        menu();
  }

}