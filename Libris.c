#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 50
#define MAX_EMPRESTIMOS 100

// Definições das estruturas
typedef struct {
    char titulo[100];
    char autor[100];
    char anoDePublicacao[10];
    char ISBN[20];
    char status[20];
} Livro;

typedef struct {
    int ID;
    char nome[100];
    char endereco[200];
    char contato[50];
} Usuario;

typedef struct {
    int livroID;
    int usuarioID;
    char dataEmprestimo[20];
    char dataDevolucao[20];
} Emprestimo;

// Vetores de dados
Livro livros[MAX_LIVROS];
Usuario usuarios[MAX_USUARIOS];
Emprestimo emprestimos[MAX_EMPRESTIMOS];

int numLivros = 0;
int numUsuarios = 0;
int numEmprestimos = 0;

// Funções de validação de entrada
int validaEntrada() {
    int escolha;
    scanf("%d", &escolha);
    return escolha;
}

// Funções de gerenciamento de livros
void listarLivrosDisponiveis() {
    printf("Lista de Livros Disponíveis:\n");
    for (int i = 0; i < numLivros; i++) {
        if (strcmp(livros[i].status, "disponivel") == 0) {
            printf("%d - %s\n", i+1, livros[i].titulo);
        }
    }
}

void listarLivrosEmprestados() {
    printf("Lista de Livros Emprestados:\n");
    for (int i = 0; i < numEmprestimos; i++) {
        int livroID = emprestimos[i].livroID;
        if (livros[livroID].status[0] == 'e') {
            printf("%d - %s\n", livroID+1, livros[livroID].titulo);
        }
    }
}

// Funções de gerenciamento de usuários
void listarUsuarios() {
    printf("Lista de Usuários:\n");
    for (int i = 0; i < numUsuarios; i++) {
        printf("%d - %s\n", usuarios[i].ID, usuarios[i].nome);
    }
}

// Função de gerenciamento de empréstimos
void realizarEmprestimo() {
    int livroID, usuarioID;
    printf("Digite o ID do livro para emprestar: ");
    scanf("%d", &livroID);
    printf("Digite o ID do usuário: ");
    scanf("%d", &usuarioID);

    if (livroID < 1 || livroID > numLivros || usuarioID < 1 || usuarioID > numUsuarios) {
        printf("ID inválido.\n");
        return;
    }

    livroID--; usuarioID--;
    
    if (strcmp(livros[livroID].status, "disponivel") == 0) {
        emprestimos[numEmprestimos].livroID = livroID;
        emprestimos[numEmprestimos].usuarioID = usuarioID;
        printf("Digite a data de empréstimo (DD/MM/AAAA): ");
        scanf("%s", emprestimos[numEmprestimos].dataEmprestimo);
        printf("Digite a data de devolução (DD/MM/AAAA): ");
        scanf("%s", emprestimos[numEmprestimos].dataDevolucao);

        strcpy(livros[livroID].status, "emprestado");
        numEmprestimos++;
        printf("Empréstimo realizado com sucesso!\n");
    } else {
        printf("Este livro já foi emprestado.\n");
    }
}

// Funções do menu principal
void menuLivros() {
    int escolha;
    do {
        printf("\n--- Menu Livros ---\n");
        printf("1. Listar Livros Disponíveis\n");
        printf("2. Listar Livros Emprestados\n");
        printf("Escolha uma opção: ");
        escolha = validaEntrada();

        switch (escolha) {
            case 1: listarLivrosDisponiveis(); break;
            case 2: listarLivrosEmprestados(); break;
            default: printf("Opção inválida!\n"); break;
        }
    } while (escolha != 0);
}

void menuUsuarios() {
    int escolha;
    do {
        printf("\n--- Menu Usuários ---\n");
        printf("1. Listar Usuários\n");
        printf("Escolha uma opção: ");
        escolha = validaEntrada();

        switch (escolha) {
            case 1: listarUsuarios(); break;
            default: printf("Opção inválida!\n"); break;
        }
    } while (escolha != 0);
}

void menuEmprestimos() {
    int escolha;
    do {
        printf("\n--- Menu Empréstimos ---\n");
        printf("1. Realizar Empréstimo\n");
        printf("Escolha uma opção: ");
        escolha = validaEntrada();

        switch (escolha) {
            case 1: realizarEmprestimo(); break;
            default: printf("Opção inválida!\n"); break;
        }
    } while (escolha != 0);
}

void menuOutrasFuncoes() {
    int escolha;
    do {
        printf("\n--- Outras Funções ---\n");
        printf("1. Listar Livros Disponíveis\n");
        printf("2. Listar Livros Emprestados\n");
        printf("Escolha uma opção: ");
        escolha = validaEntrada();

        switch (escolha) {
            case 1: listarLivrosDisponiveis(); break;
            case 2: listarLivrosEmprestados(); break;
            default: printf("Opção inválida!\n"); break;
        }
    } while (escolha != 0);
}

int main() {
    int escolhaOpcao;

    // Exibindo o menu principal
    printf(" ▄█        ▄█  ▀█████████▄     ▄████████  ▄█     ▄████████ \n");
    printf("███       ███    ███    ███   ███    ███ ███    ███    ███ \n");
    printf("███       ███▌   ███    ███   ███    ███ ███▌   ███    █▀  \n");
    printf("███       ███▌  ▄███▄▄▄██▀   ▄███▄▄▄▄██▀ ███▌   ███        \n");
    printf("███       ███▌ ▀▀███▀▀▀██▄  ▀▀███▀▀▀▀▀   ███▌ ▀███████████ \n");
    printf("███       ███    ███    ██▄ ▀███████████ ███           ███ \n");
    printf("███▌    ▄ ███    ███    ███   ███    ███ ███     ▄█    ███ \n");
    printf("█████▄▄██ █▀   ▄█████████▀    ███    ███ █▀    ▄████████▀  \n");
    printf("▀                             ███    ███                   \n");
    printf("\n---- 𝕲𝖊𝖗𝖊𝖓𝖈𝖎𝖆𝖒𝖊𝖓𝖙𝖔 𝖉𝖊 𝕷𝖎𝖛𝖗𝖔𝖘, 𝖀𝖘𝖚𝖆́𝖗𝖎𝖔𝖘 𝖊 𝕰𝖒𝖕𝖗𝖊́𝖘𝖙𝖎𝖒𝖔𝖘 ----\n");
    printf("1. Gerenciamento de Livros\n");
    printf("2. Gerenciamento de Usuários\n");
    printf("3. Gerenciamento de Empréstimos\n");
    printf("4. Outras Funções\n");
    printf("Escolha uma opção: ");
    escolhaOpcao = validaEntrada();

    switch (escolhaOpcao) {
        case 1: menuLivros(); break;
        case 2: menuUsuarios(); break;
        case 3: menuEmprestimos(); break;
        case 4: menuOutrasFuncoes(); break;
        default: printf("Opção inválida! Tente novamente.\n");
    }

    return 0;
}
