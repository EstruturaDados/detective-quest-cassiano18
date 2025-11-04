#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===========================================
// Estrutura que representa uma sala da mansão
// ===========================================
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// ===========================================
// Função: criarSala
// Cria uma sala dinamicamente com um nome
// ===========================================
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memória para a sala.\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// ===========================================
// Função: explorarSalas
// Permite a navegação do jogador pela mansão
// ===========================================
void explorarSalas(Sala *atual) {
    char escolha;

    while (atual != NULL) {
        printf("\nVocê está na %s.\n", atual->nome);

        // Caso a sala não tenha caminhos
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Esta sala não possui mais caminhos. Fim da exploração!\n");
            break;
        }

        printf("Escolha um caminho:\n");
        if (atual->esquerda != NULL)
            printf("  (e) Ir para a esquerda → %s\n", atual->esquerda->nome);
        if (atual->direita != NULL)
            printf("  (d) Ir para a direita  → %s\n", atual->direita->nome);
        printf("  (s) Sair da exploração\n");
        printf("Opção: ");
        scanf(" %c", &escolha);

        if (escolha == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } else if (escolha == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        } else if (escolha == 's') {
            printf("Exploração encerrada pelo jogador.\n");
            break;
        } else {
            printf("Caminho inválido! Tente novamente.\n");
        }
    }
}

// ===========================================
// Função principal: monta o mapa da mansão
// ===========================================
int main() {
    // Criação automática das salas (árvore binária fixa)
    Sala *hall = criarSala("Hall de Entrada");
    hall->esquerda = criarSala("Sala de Estar");
    hall->direita = criarSala("Biblioteca");

    hall->esquerda->esquerda = criarSala("Cozinha");
    hall->esquerda->direita = criarSala("Sala de Jantar");

    hall->direita->esquerda = criarSala("Escritório");
    hall->direita->direita = criarSala("Jardim Interno");

    // Inicia a exploração
    printf("=== Detective Quest: A Mansão Misteriosa ===\n");
    printf("Explore a mansão e descubra seus segredos!\n");

    explorarSalas(hall);

    // Liberação de memória (opcional para este exercício)
    // ... poderia implementar uma função recursiva para liberar todas as salas.

    return 0;
}
