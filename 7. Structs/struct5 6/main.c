#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* ==========================================================
   Constantes
   - Quadrante vai de 0 a 8   -> 9 valores possiveis
   - Setor vai de 'A' a 'L'   -> 12 valores possiveis
   ========================================================== */
   
#define MAXPLANETAS    20
#define MAXNAVES_FED   16
#define MAXNAVES_ROM   12
#define MAXNAVES       (MAXNAVES_FED + MAXNAVES_ROM)
#define MAXQUADRANTE   9
#define MAXSETOR       12
#define MAXCONFRONTO   20   /* nº máximo de naves de uma mesma classe num mesmo local */

/* ==========================================================
   7.5 - struct planeta
   ========================================================== */
struct planeta {
    char nome[30];
    double raio;        /* km  */
    double massa;       /* kg  */
    int satelites;
    int habitantes;
    int quadrante;       /* 0 a 8   */
    char setor;          /* 'A' a 'L' */
};

/* ==========================================================
   7.7 - struct nave
   ========================================================== */
struct nave {
    char nome[30];
    char classe[30];
    int tamanho;          /* toneladas */
    int tripulantes;
    int naves_auxiliares;
    char origem[30];
    char destino[30];
    int quadrante;
    char setor;
};

/* ---------- utilitários de entrada ---------- */
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void removerNovaLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';
}

/* ---------- impressão ---------- */
void printPlaneta(struct planeta p) {
    printf("Planeta %s\n", p.nome);
    printf("  raio: %.0f km\n", p.raio);
    printf("  massa: %.3e kg\n", p.massa);
    printf("  satelites: %d\n", p.satelites);
    printf("  habitantes: %d\n", p.habitantes);
    printf("  quadrante: %d\n", p.quadrante);
    printf("  setor: %c\n", p.setor);
}

void printNave(struct nave n) {
    printf("Nave %s\n", n.nome);
    printf("  classe: %s\n", n.classe);
    printf("  tamanho: %d toneladas\n", n.tamanho);
    printf("  tripulantes: %d\n", n.tripulantes);
    printf("  naves auxiliares: %d\n", n.naves_auxiliares);
    printf("  origem: %s\n", n.origem);
    printf("  destino: %s\n", n.destino);
    printf("  quadrante: %d\n", n.quadrante);
    printf("  setor: %c\n", n.setor);
}

/* ==========================================================
   7.6 (a) habitantes no quadrante Gamma (código 6)
   ========================================================== */
void habitantesNoQuadrante(struct planeta *planetas[], int n, int quad) {
    long long pop = 0;
    for (int i = 0; i < n; i++) {
        if (planetas[i]->quadrante == quad) {
            pop += planetas[i]->habitantes;
        }
    }
    printf("Total de habitantes no quadrante %d = %lld\n", quad, pop);
}

/* ==========================================================
   7.6 (b) setor mais populoso
   ========================================================== */
void setorMaisPopuloso(struct planeta *planetas[], int n) {
    long long setores[MAXSETOR] = {0};

    for (int i = 0; i < n; i++) {
        int idx = planetas[i]->setor - 'A';
        if (idx >= 0 && idx < MAXSETOR) setores[idx] += planetas[i]->habitantes;
    }

    long long hab = -1;
    char set = '?';
    for (int i = 0; i < MAXSETOR; i++) {
        if (setores[i] > hab) {
            hab = setores[i];
            set = (char)(i + 'A');
        }
    }
    printf("O setor mais populoso é %c, com %lld habitantes\n", set, hab);
}

/* ==========================================================
   7.6 (c) maior planeta de cada quadrante
   ========================================================== */
void maiorPlanetaPorQuadrante(struct planeta *planetas[], int n) {
    int maiorIdx[MAXQUADRANTE];
    double maiorRaio[MAXQUADRANTE];

    for (int i = 0; i < MAXQUADRANTE; i++) {
        maiorIdx[i] = -1;
        maiorRaio[i] = -1.0;
    }

    for (int i = 0; i < n; i++) {
        int q = planetas[i]->quadrante;
        if (q < 0 || q >= MAXQUADRANTE) continue;
        if (planetas[i]->raio > maiorRaio[q]) {
            maiorRaio[q] = planetas[i]->raio;
            maiorIdx[q] = i;
        }
    }

    for (int i = 0; i < MAXQUADRANTE; i++) {
        if (maiorIdx[i] == -1)
            printf("Sem planetas no quadrante %d\n", i);
        else
            printf("O maior planeta do quadrante %d é %s (raio %.0f km)\n",
                   i, planetas[maiorIdx[i]]->nome, planetas[maiorIdx[i]]->raio);
    }
}

/* ==========================================================
   Criação interativa (usada caso o usuário queira cadastrar
   naves/planetas digitando os dados)
   ========================================================== */
struct nave *criarNave(void) {
    struct nave *novaNave = malloc(sizeof(struct nave));
    printf("---INICIANDO PROCESSO DE FABRICACAO---\n");
    printf("Nome- ");             fgets(novaNave->nome, sizeof(novaNave->nome), stdin);
    removerNovaLinha(novaNave->nome);
    printf("Classe- ");           fgets(novaNave->classe, sizeof(novaNave->classe), stdin);
    removerNovaLinha(novaNave->classe);
    printf("Tamanho- ");          scanf("%d", &novaNave->tamanho);          limparBuffer();
    printf("Tripulantes- ");      scanf("%d", &novaNave->tripulantes);      limparBuffer();
    printf("Naves auxiliares- "); scanf("%d", &novaNave->naves_auxiliares); limparBuffer();
    printf("Origem- ");           fgets(novaNave->origem, sizeof(novaNave->origem), stdin);
    removerNovaLinha(novaNave->origem);
    printf("Destino- ");          fgets(novaNave->destino, sizeof(novaNave->destino), stdin);
    removerNovaLinha(novaNave->destino);
    printf("Quadrante (0-8)- ");  scanf("%d", &novaNave->quadrante);        limparBuffer();
    printf("Setor (A-L)- ");      scanf(" %c", &novaNave->setor);           limparBuffer();
    return novaNave;
}

struct planeta *criarPlaneta(void) {
    struct planeta *novoPlaneta = malloc(sizeof(struct planeta));
    printf("---CATALOGANDO NOVO PLANETA---\n");
    printf("Nome- ");            fgets(novoPlaneta->nome, sizeof(novoPlaneta->nome), stdin);
    removerNovaLinha(novoPlaneta->nome);
    printf("Raio (km)- ");       scanf("%lf", &novoPlaneta->raio);      limparBuffer();
    printf("Massa (kg)- ");      scanf("%lf", &novoPlaneta->massa);     limparBuffer();
    printf("Satelites- ");       scanf("%d", &novoPlaneta->satelites);  limparBuffer();
    printf("Habitantes- ");      scanf("%d", &novoPlaneta->habitantes); limparBuffer();
    printf("Quadrante (0-8)- "); scanf("%d", &novoPlaneta->quadrante);  limparBuffer();
    printf("Setor (A-L)- ");     scanf(" %c", &novoPlaneta->setor);     limparBuffer();
    return novoPlaneta;
}

void catalogarNovosPlanetas(int qtd, struct planeta *sistema[]) {
    for (int i = 0; i < qtd; i++) sistema[i] = criarPlaneta();
}

void catalogarNovasNaves(int qtd, struct nave *frota[]) {
    for (int i = 0; i < qtd; i++) frota[i] = criarNave();
}

/* ==========================================================
   7.8 - relatório de um quadrante/setor específico
   ========================================================== */
void relatorioLocal(int quadrante, char setor,
                     int nPlanetas, struct planeta *sistema[],
                     int nNaves, struct nave *frota[]) {
    int achou = 0;

    printf("\n=== Relatorio do Quadrante %d, Setor %c ===\n", quadrante, setor);

    for (int i = 0; i < nPlanetas; i++) {
        if (sistema[i]->quadrante == quadrante && sistema[i]->setor == setor) {
            printPlaneta(*sistema[i]);
            achou = 1;
        }
    }
    if (!achou) printf("Nenhum planeta neste local.\n");

    achou = 0;
    for (int i = 0; i < nNaves; i++) {
        if (frota[i]->quadrante == quadrante && frota[i]->setor == setor) {
            printNave(*frota[i]);
            achou = 1;
        }
    }
    if (!achou) printf("Nenhuma nave neste local.\n");
}

/* ==========================================================
   7.9 - Confronto Federação x Romulanos
   Duas naves "se encontram" quando estao no mesmo quadrante
   E no mesmo setor. Se houver naves de ambas as facções no
   mesmo local, uma batalha ocorre e apenas um lado sobrevive.
   ========================================================== */
struct nave **destruirNaves(struct nave *frota[], int *numNaves) {
    int totalPos = MAXQUADRANTE * MAXSETOR;

    static struct nave *fed[MAXQUADRANTE * MAXSETOR][MAXCONFRONTO];
    static struct nave *rom[MAXQUADRANTE * MAXSETOR][MAXCONFRONTO];
    int qtdFed[MAXQUADRANTE * MAXSETOR];
    int qtdRom[MAXQUADRANTE * MAXSETOR];

    for (int i = 0; i < totalPos; i++) { qtdFed[i] = 0; qtdRom[i] = 0; }

    for (int i = 0; i < *numNaves; i++) {
        int q = frota[i]->quadrante;
        int s = frota[i]->setor - 'A';
        if (q < 0 || q >= MAXQUADRANTE || s < 0 || s >= MAXSETOR) continue;
        int pos = q * MAXSETOR + s;

        if (strcmp(frota[i]->classe, "Romulana") == 0) {
            if (qtdRom[pos] < MAXCONFRONTO) rom[pos][qtdRom[pos]++] = frota[i];
        } else {
            if (qtdFed[pos] < MAXCONFRONTO) fed[pos][qtdFed[pos]++] = frota[i];
        }
    }

    struct nave **remanescentes = malloc((*numNaves) * sizeof(struct nave *));
    int idx = 0;

    for (int pos = 0; pos < totalPos; pos++) {
        int q = pos / MAXSETOR;
        char s = (char)(pos % MAXSETOR + 'A');

        if (qtdFed[pos] > 0 && qtdRom[pos] > 0) {
            /* houve encontro: relatar e decidir a batalha */
            printf("\n*** ENCONTRO no Quadrante %d, Setor %c! ***\n", q, s);
            printf("Naves da Federacao presentes:\n");
            for (int j = 0; j < qtdFed[pos]; j++) printf("  - %s\n", fed[pos][j]->nome);
            printf("Naves Romulanas presentes:\n");
            for (int j = 0; j < qtdRom[pos]; j++) printf("  - %s\n", rom[pos][j]->nome);

            int venceFederacao = rand() % 2;
            if (venceFederacao) {
                printf("Resultado: a Federacao venceu! As naves romulanas foram destruidas.\n");
                for (int j = 0; j < qtdFed[pos]; j++) remanescentes[idx++] = fed[pos][j];
            } else {
                printf("Resultado: os Romulanos venceram! As naves da Federacao foram destruidas.\n");
                for (int j = 0; j < qtdRom[pos]; j++) remanescentes[idx++] = rom[pos][j];
            }
        } else {
            /* sem confronto: todas as naves do local sobrevivem */
            for (int j = 0; j < qtdFed[pos]; j++) remanescentes[idx++] = fed[pos][j];
            for (int j = 0; j < qtdRom[pos]; j++) remanescentes[idx++] = rom[pos][j];
        }
    }

    *numNaves = idx;
    return remanescentes;
}

/* ==========================================================
   7.10 - Redirecionar uma nave para um planeta
   ========================================================== */
void redirecionarNave(const char *nomeNave, const char *nomePlaneta,
                       struct nave *frota[], int *numNaves,
                       struct planeta *sistema[], int nPlanetas) {
    int posPlaneta = -1;
    for (int i = 0; i < nPlanetas; i++) {
        if (strcmp(nomePlaneta, sistema[i]->nome) == 0) { posPlaneta = i; break; }
    }
    if (posPlaneta == -1) {
        printf("\nERRO - Planeta '%s' nao encontrado!\n\n", nomePlaneta);
        return;
    }

    int posNave = -1;
    for (int i = 0; i < *numNaves; i++) {
        if (strcmp(nomeNave, frota[i]->nome) == 0) { posNave = i; break; }
    }
    if (posNave == -1) {
        printf("\nERRO - Nave '%s' nao encontrada!\n\n", nomeNave);
        return;
    }

    frota[posNave]->quadrante = sistema[posPlaneta]->quadrante;
    frota[posNave]->setor = sistema[posPlaneta]->setor;
    strcpy(frota[posNave]->destino, sistema[posPlaneta]->nome);

    printf("\nNave '%s' redirecionada para '%s' (Quadrante %d, Setor %c)\n",
           frota[posNave]->nome, sistema[posPlaneta]->nome,
           frota[posNave]->quadrante, frota[posNave]->setor);

    printf("Verificando presenca romulana no novo local...\n");
    struct nave **sobreviventes = destruirNaves(frota, numNaves);
    for (int i = 0; i < *numNaves; i++) frota[i] = sobreviventes[i];
    free(sobreviventes);
}

void redirecionar(struct nave *frota[], int *numNaves,
                   struct planeta *sistema[], int nPlanetas) {
    char nomeNave[30], nomePlaneta[30];
    printf("Qual nave redirecionar? - ");
    fgets(nomeNave, sizeof(nomeNave), stdin);   removerNovaLinha(nomeNave);
    printf("Para qual planeta? - ");
    fgets(nomePlaneta, sizeof(nomePlaneta), stdin); removerNovaLinha(nomePlaneta);
    redirecionarNave(nomeNave, nomePlaneta, frota, numNaves, sistema, nPlanetas);
}

/* ==========================================================
   MAIN - popula planetas e naves de teste e exercita todas
   as funções pedidas nos exercícios 7.5 a 7.10
   ========================================================== */
int main(void) {
    srand((unsigned int)time(NULL));

    struct planeta *sistema[MAXPLANETAS];
    struct nave *frota[MAXNAVES];

    /* ---------- 20 planetas de teste ---------- */
    const char *nomesPlanetas[MAXPLANETAS] = {
        "Vulcano", "Romulus", "Qo'noS", "Bajor", "Cardassia", "Ferenginar",
        "Betazed", "Andoria", "Trill", "Risa", "Tellar", "Deneva", "Rigel",
        "Talos IV", "Organia", "Nimbus III", "Delta Vega", "Wolf 359",
        "Khitomer", "Shermans Planet"
    };
    for (int i = 0; i < MAXPLANETAS; i++) {
        sistema[i] = malloc(sizeof(struct planeta));
        strcpy(sistema[i]->nome, nomesPlanetas[i]);
        sistema[i]->raio = 3000 + rand() % 12000;
        sistema[i]->massa = (1.0 + (rand() % 900) / 100.0) * 1e24;
        sistema[i]->satelites = rand() % 5;
        sistema[i]->habitantes = rand() % 2000000000;
        sistema[i]->quadrante = rand() % MAXQUADRANTE;
        sistema[i]->setor = (char)('A' + rand() % MAXSETOR);
    }

    /* ---------- 16 naves da Federacao ---------- */
    const char *nomesNaves[MAXNAVES_FED] = {
        "Enterprise", "Voyager", "Defiant", "Excelsior", "Reliant",
        "Farragut", "Yamato", "Hood", "Lakota", "Sutherland", "Bozeman",
        "Stargazer", "Cochrane", "Prometheus", "Titan", "Discovery"
    };
    const char *classesFed[] = { "Constitution", "Galaxy", "Defiant",
                                  "Excelsior", "Intrepid", "Sovereign" };
    for (int i = 0; i < MAXNAVES_FED; i++) {
        frota[i] = malloc(sizeof(struct nave));
        strcpy(frota[i]->nome, nomesNaves[i]);
        strcpy(frota[i]->classe, classesFed[rand() % 6]);
        frota[i]->tamanho = 500 + rand() % 4000;
        frota[i]->tripulantes = 50 + rand() % 900;
        frota[i]->naves_auxiliares = rand() % 5;
        strcpy(frota[i]->origem, sistema[rand() % MAXPLANETAS]->nome);
        strcpy(frota[i]->destino, sistema[rand() % MAXPLANETAS]->nome);
        frota[i]->quadrante = rand() % MAXQUADRANTE;
        frota[i]->setor = (char)('A' + rand() % MAXSETOR);
    }

    /* ---------- 12 naves romulanas ---------- */
    const char *nomesRomulanos[MAXNAVES_ROM] = {
        "Khazara", "D'deridex", "Terix", "Devoras", "Haakona", "Tomalak",
        "Valdore", "Scimitar", "Shrike", "Praetor", "Icarus", "Nequencia"
    };
    for (int i = 0; i < MAXNAVES_ROM; i++) {
        int idx = MAXNAVES_FED + i;
        frota[idx] = malloc(sizeof(struct nave));
        strcpy(frota[idx]->nome, nomesRomulanos[i]);
        strcpy(frota[idx]->classe, "Romulana");
        frota[idx]->tamanho = 400 + rand() % 3000;
        frota[idx]->tripulantes = 40 + rand() % 600;
        frota[idx]->naves_auxiliares = rand() % 3;
        strcpy(frota[idx]->origem, "Romulus");
        strcpy(frota[idx]->destino, sistema[rand() % MAXPLANETAS]->nome);
        frota[idx]->quadrante = rand() % MAXQUADRANTE;
        frota[idx]->setor = (char)('A' + rand() % MAXSETOR);
    }

    /* garante pelo menos um encontro Federacao x Romulanos para teste */
    frota[MAXNAVES_FED]->quadrante = frota[0]->quadrante;
    frota[MAXNAVES_FED]->setor = frota[0]->setor;

    int numNaves = MAXNAVES;

    printf("############ 7.6 - RELATORIOS DE PLANETAS ############\n");
    habitantesNoQuadrante(sistema, MAXPLANETAS, 6); /* Gamma = 6 */
    setorMaisPopuloso(sistema, MAXPLANETAS);
    maiorPlanetaPorQuadrante(sistema, MAXPLANETAS);

    printf("\n############ 7.8 - RELATORIO DE UM LOCAL ############\n");
    relatorioLocal(frota[0]->quadrante, frota[0]->setor,
                   MAXPLANETAS, sistema, numNaves, frota);

    printf("\n############ 7.9 - BATALHA ROMULANA ############\n");
    struct nave **sobreviventes = destruirNaves(frota, &numNaves);
    for (int i = 0; i < numNaves; i++) frota[i] = sobreviventes[i];
    free(sobreviventes);

    printf("\nNaves sobreviventes apos a batalha: %d\n", numNaves);
    for (int i = 0; i < numNaves; i++) printNave(*frota[i]);

    printf("\n############ 7.10 - REDIRECIONAMENTO ############\n");
    if (numNaves > 0) {
        redirecionarNave(frota[0]->nome, sistema[0]->nome,
                          frota, &numNaves, sistema, MAXPLANETAS);
    }
    /* teste de nave/planeta inexistente */
    redirecionarNave("Nave Fantasma", "Planeta Fantasma",
                      frota, &numNaves, sistema, MAXPLANETAS);

    /* ---------- limpeza de memoria ---------- */
    for (int i = 0; i < MAXPLANETAS; i++) free(sistema[i]);
    for (int i = 0; i < numNaves; i++) free(frota[i]);

    return 0;
}