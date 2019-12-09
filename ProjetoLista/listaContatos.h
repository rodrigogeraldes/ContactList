
/** ESTRUTURAS */
typedef struct lista* Lista;

typedef struct{
    int codigo;
    char nome[60];
    char empresa[60];
    char departamento[60];
    char telefone[20];
    char celular[20];
    char email[60];
}informacoes;


/** ROTINAS DE ARQUIVO*/
FILE *arquivo;
void arquivo_save(Lista *lista);
int arquivo_read(Lista *lista);


/** ROTINAS DE CRIA��O E DESTRUI��O */
Lista *cria_lista();
void destroi_lista(Lista *lista);

/** ROTINAS DE TAMANHO */
int tamanho_lista(Lista *lista);
int lista_vazia(Lista *lista);


/** ROTINAS DE INSER��O*/
int insercao(Lista *lista, informacoes val);
informacoes preenchimento();
informacoes preenchimento_alteracao(int codigo);


/** ROTINAS DE CONSULTA*/
informacoes *relatorio(Lista *lista);
int buscar_codigo(Lista *lista, int cod, informacoes *busca);
informacoes *buscar_nome(Lista *lista, char *nome, int *i);


/** ROTINAS DE EDI��O E REMO��O*/
int alterar_dados(Lista *lista, int cod, informacoes dados);
int remover_funcionario(Lista *lista, int cod);


/** ROTINAS DE MANIPULA��O DE STRING*/
char *lower(char *nome);

/** ROTINAS DE  PERSONALIZA��O*/
int menu(Lista *lista);
void finalizacao();

