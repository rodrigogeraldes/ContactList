#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "listaContatos.h"


/** ROTINAS DE ESTRUTURA*/
struct lista{
    informacoes dados;
    struct lista *prox;
};

typedef struct lista ORDEM;
/********************************************************************************/

/** ROTINAS DE ARQUIVO*/

//Fun��o feita para salvar os dados em um arquivo
void arquivo_save(Lista *lista){
    informacoes *vet = (informacoes*) calloc(tamanho_lista(lista), sizeof(informacoes));

    ORDEM *no = *lista;
    int i=0;

    arquivo = fopen("arquivo.txt", "wb");
    while(no != NULL){
        vet[i] = no->dados;
        fwrite(&vet[i], sizeof(informacoes), 1, arquivo);
        no = no->prox;
        i++;
    }
    fclose(arquivo);
}

//Fun��o feita para ler os dados j� existentes e inserir novos
int arquivo_read(Lista *lista){
    informacoes rec;

    arquivo = fopen("arquivo.txt", "rb");
    if (arquivo ==  NULL){
        return (0);
    }
    while(1){
        fread(&rec, sizeof(informacoes), 1, arquivo);
        if(feof(arquivo)){
            break;
        }
        insercao(lista, rec);
    }
    fclose(arquivo);
    return (0);
}

/********************************************************************************/

/** ROTINAS DE PERSONALIZA��O*/
//Finalizar� o programa :)
void finalizacao(){
    system("cls");
    printf("\n");
    printf("       \\|/ ____ \\|/    OBRIGADO POR UTILIZAR              \n");
    printf("        @~/ ,. \\~@     NOSSO PROGRAMA                     \n");
    printf("       /_( \\__/ )_\\                                      \n");
    printf("          \\__U_/       AUGUSTO ARAUJO && RODRIGO GERALDES \n");
}

//Fun��o menu
int menu(Lista *lista){
    int opc;
    system("cls");
    printf("****************************************");
    printf("\n*                                      *");
    printf("\n*          LISTA DE CONTATOS           *");
    printf("\n*                                      *");
    printf("\n****************************************");
    printf("\n* Digite a op��o escolhida:            *");
    printf("\n*                                      *");
    printf("\n* 1- Inserir um novo contato.          *");
    printf("\n* 2- Gerar e exibir relat�rio total.   *");
    printf("\n* 3- Buscar contato por identificador. *");
    printf("\n* 4- Buscar contato por nome.          *");
    printf("\n* 5- Editar dados do contato.          *");
    printf("\n* 6- Remover contato.                  *");
    printf("\n* 7- Sair e encerrar programa.         *");
    printf("\n*                                      *");
    printf("\n****************************************");
    printf("\nOp��o: ");
    scanf("%d",&opc);
    return opc;
}
/********************************************************************************/


/** ROTINAS DE INSER��O*/
//Ir� inserir o dado do funcionario de maneira ordenada
int insercao(Lista *lista, informacoes val){
    ORDEM *no = (ORDEM*) calloc(1, sizeof(ORDEM));

    if(lista == NULL || no == NULL){
        return 0;
    }
    no->dados = val;

    if(lista_vazia(lista)){
        no->prox = *lista;
        *lista = no;
    }else{
        ORDEM *ant, *atual = *lista;
        while(atual != NULL && atual->dados.codigo < val.codigo){
            ant = atual;
            atual = atual->prox;
        }

        if(atual == *lista){
            no->prox = *lista;
            *lista = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
    }
    return 1;
}

//�rea onde o usu�rio ir� inserir os dados do cliente
informacoes preenchimento(){
    setlocale(LC_ALL,"Portuguese");
    informacoes funcionario;

    printf("Nome: ");
    getchar();
    fgets(funcionario.nome, 59, stdin);
    funcionario.nome[strlen(funcionario.nome)-1] = '\0';
    printf("C�digo: ");
    scanf("%d", &funcionario.codigo);
    getchar();
    printf("Empresa: ");
    fgets(funcionario.empresa, 59, stdin);
    funcionario.empresa[strlen(funcionario.empresa)-1] = '\0';
    printf("Departamento: ");
    fgets(funcionario.departamento, 59, stdin);
    funcionario.departamento[strlen(funcionario.departamento)-1] = '\0';
    printf("Telefone: ");
    fgets(funcionario.telefone, 19, stdin);
    funcionario.telefone[strlen(funcionario.telefone)-1] = '\0';
    printf("Celular: ");
    fgets(funcionario.celular, 19, stdin);
    funcionario.celular[strlen(funcionario.celular)-1] = '\0';
    printf("E-mail: ");
    fgets(funcionario.email, 59, stdin);
    funcionario.email[strlen(funcionario.email)-1] = '\0';

    return funcionario;
}

//�rea onde o usu�rio ir� alterar os dados de um funcion�rio j� existente
informacoes preenchimento_alteracao(int codigo){
    setlocale(LC_ALL,"Portuguese");
    informacoes funcionario;

    funcionario.codigo = codigo;
    printf("Nome: ");
    getchar();
    fgets(funcionario.nome, 59, stdin);
    funcionario.nome[strlen(funcionario.nome)-1] = '\0';
    printf("Empresa: ");
    fgets(funcionario.empresa, 59, stdin);
    funcionario.empresa[strlen(funcionario.empresa)-1] = '\0';
    printf("Departamento: ");
    fgets(funcionario.departamento, 59, stdin);
    funcionario.departamento[strlen(funcionario.departamento)-1] = '\0';
    printf("Telefone: ");
    fgets(funcionario.telefone, 19, stdin);
    funcionario.telefone[strlen(funcionario.telefone)-1] = '\0';
    printf("Celular: ");
    fgets(funcionario.celular, 19, stdin);
    funcionario.celular[strlen(funcionario.celular)-1] = '\0';
    printf("E-mail: ");
    fgets(funcionario.email, 59, stdin);
    funcionario.email[strlen(funcionario.email)-1] = '\0';

    return funcionario;
}
/********************************************************************************/

/** ROTINAS DE TAMANHO*/
//Mostrar� o tamanho da lista
int tamanho_lista(Lista *lista){
    if(lista == NULL){
        return 0;
    }
    int qtd = 0;
    ORDEM *no = *lista;
    while(no != NULL){
        qtd++;
        no = no->prox;
    }
    return qtd;
}

//Informar� se a lista est� vazia
int lista_vazia(Lista *lista){
    if(lista == NULL || *lista == NULL){
        return 1;
    }
    return 0;
}
/********************************************************************************/

/** ROTINAS DE CRIA��O E DESTRUI��O*/
//Criar� a lista
Lista *cria_lista(){
    Lista *lista = (Lista*) calloc(1, sizeof(Lista));
    if(lista != NULL){
        *lista = NULL;
    }
    return lista;
}

//Liberar� a mem�ria
void destroi_lista(Lista *lista){
    if(lista != NULL){
        ORDEM *no;
        while(*lista != NULL){
            no = *lista;
            *lista = (*lista)->prox;
            free(no);
        }
        free(lista);
    }
}
/********************************************************************************/

/** ROTINAS DE REMO��O E EDI��O*/
//Ir� inserir novamente o funcion�rio rec�m editado, de maneira ordenada
int alterar_dados(Lista *lista, int cod, informacoes dados){
    if(lista == NULL || *lista == NULL){
        return 0;
    }

    ORDEM *ant, *atual = *lista;
    while(atual != NULL && atual->dados.codigo != cod){
        ant = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        return 0;
    }

    ORDEM *no = (ORDEM*) calloc(1, sizeof(ORDEM));

    no->dados = dados;

    if(atual == *lista){
        *lista = no;
    }else{
        ant->prox = no;
        no->prox = atual->prox;
    }
    free(atual);
    return 1;
}

//Remove o funcion�rio da lista de funcion�rios cadastrados
int remover_funcionario(Lista *lista, int cod){
    if(lista == NULL || *lista == NULL){
        return 0;
    }

    ORDEM *ant, *no = *lista;
    while(no != NULL && no->dados.codigo != cod){
        ant = no;
        no = no->prox;
    }

    if(no == NULL){
        return 0;
    }

    if(no == *lista){
        *lista = no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}
/********************************************************************************/

/** ROTINAS DE CONSULTA*/
//Gera um relat�rio total de todos os funcion�rios cadastrados
informacoes *relatorio(Lista *lista){
    informacoes *aux = (informacoes*) calloc(tamanho_lista(lista), sizeof(informacoes));
    if(lista == NULL || lista_vazia(lista) || aux == NULL){
        return 0;
    }

    ORDEM *no = *lista;
    int i=0;

    while(no != NULL){
        aux[i] = no->dados;
        no = no->prox;
        i++;
    }
    return aux;
}

//Busca o funcion�rio pelo c�digo dele
int buscar_codigo(Lista *lista, int cod, informacoes *aux){
    if(lista == NULL || lista_vazia(lista) || aux == NULL){
        return 0;
    }

    ORDEM *no = *lista;

    while(no != NULL && no->dados.codigo != cod){
        no = no->prox;
    }

    if(no == NULL){
        return 0;
    }

    *aux = no->dados;
    return 1;
}

//Buscar� o funcion�rio pelo nome do mesmo, independente de quantas letras for�m inseridas para servir de busca
informacoes *buscar_nome(Lista *lista, char *nome, int *i){
    char aux_nome[60];
    informacoes *aux = (informacoes*) calloc(tamanho_lista(lista), sizeof(informacoes));
    if(lista == NULL || lista_vazia(lista) || aux == NULL){
        return 0;
    }

    ORDEM *no = *lista;
    while(no != NULL){
        strcpy(aux_nome, no->dados.nome);
        if(strncmp(lower(nome), lower(aux_nome), strlen(nome)) == 0){
            aux[*i] = no->dados;
            *i = *i + 1;
        }
        no = no->prox;
    }

    return aux;
}
/********************************************************************************/


/** ROTINAS DE MANIPULA��O DE STRING*/
//Colocar� todos os dados em letra min�scula
char *lower(char *string){
    int i;
    for(i=0; i<strlen(string); i++){
        string[i] = tolower(string[i]);
    }
    return string;
}


