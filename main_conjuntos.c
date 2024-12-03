#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

// Estruturas para armazenar o representante e o tamanho dos conjuntos
int parent[MAX_N]; // Armazena o representante de cada conjunto
int size[MAX_N]; // Armazena o tamanho dos conjuntos (usado para uni�o por tamanho)

// Fun��o para inicializar os conjuntos disjuntos
void initialize(int n) {
	int i;
    for ( i = 0; i < n; i++) {
        parent[i] = i; // Cada elemento � seu pr�prio representante inicialmente
        size[i] = 1; // Cada conjunto tem tamanho 1 no in�cio
    }
}

// Fun��o de Find com compress�o de caminho
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Compress�o de caminho
    }
    return parent[x];
}

// Fun��o de Union por tamanho
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        // Uni�o por tamanho
        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
}

// Fun��o para compara��o de inteiros (necess�ria para qsort)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Fun��o para ordenar um subconjunto de elementos (por exemplo, usando QuickSort)
void sortSubset(int subset[], int n) {
    qsort(subset, n, sizeof(int), compare);
}

// Fun��o para imprimir o conjunto de um determinado representante
void printSet(int n) {
    int* set = (int*)malloc(sizeof(int) * n);
    int setSize = 0;
    int i;
    for ( i = 0; i < n; i++) {
        if (find(i) == find(0)) { // Substitua 0 por qualquer �ndice que voc� queira verificar
            set[setSize++] = i + 1; // Armazena os elementos do conjunto
        }
    }
    sortSubset(set, setSize);
    printf("Conjunto: ");
    for ( i = 0; i < setSize; i++) {
        printf("%d ", set[i]);
    }
    printf("\n");
    free(set); // Libere a mem�ria alocada
}

// Fun��o para ler a entrada do arquivo
void readInput(const char* filename, int *n, int partition[MAX_N][MAX_N], int *k) {
    FILE *file = fopen(filename, "r");
    int i, j;
    if (file == NULL) {
        perror("Erro ao abrir o arquivo.");
        exit(1);
    }
    fscanf(file, "%d %d", n, k);
    for ( i = 0; i < *k; i++) {
        int size;
        fscanf(file, "%d", &size);
        for ( j = 0; j < size; j++) {
            fscanf(file, "%d", &partition[i][j]);
        }
    }
    fclose(file);
}

// Fun��o principal
int main() {
    int n, k, i, j, l, m;
    int partition[MAX_N][MAX_N];

    // Leitura dos dados de entrada
    readInput("input.txt", &n, partition, &k);

    // Inicializa os conjuntos disjuntos
    initialize(n);

    // Para cada subconjunto na parti��o, unir os elementos
    for ( i = 0; i < k; i++) {
        for ( j = 0; j < k; j++) {
            if (i != j) { // N�o faz sentido unir o pr�prio conjunto consigo mesmo
                for ( m = 0; m < k; m++) {
                    for ( l = 0; l < k; l++) {
                        unionSets(partition[i][m], partition[l][m]);
                    }
                }
            }
        }
    }
    
    // Imprime o conjunto disjunto
    printf("Conjunto disjunto: ");
    printSet(n);
}

