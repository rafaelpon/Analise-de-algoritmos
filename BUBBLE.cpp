#include <stdio.h>
#include <sys/time.h>

void trocar(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                trocar(&arr[j], &arr[j+1]);
            }
        }
    }
}

void imprimirArray(int arr[], int size) {
    for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

long long getCurrentTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)(tv.tv_sec) * 1000 + (long long)(tv.tv_usec) / 1000;
}

int main() {
    int arr[] = {4641, 680, 6493};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < 10; i++) {
        long long inicio = getCurrentTime();
        
        bubbleSort(arr, n);
        
        long long fim = getCurrentTime();
        double tempo_execucao = (fim - inicio);

        printf("Array ordenado na iteração %d: \n", i + 1);
        imprimirArray(arr, n);

        printf("\nTempo de execução: %f milissegundos\n\n", tempo_execucao);
    }

    printf("Quantidade de numeros no array: %d\n", n);

    return 0;
}

