#include <stdio.h>

// Fonctions pour les différents tris

// Tri à bulles
// Complexité temporelle : O(n^2)

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Tri par sélection
// Complexité temporelle : O(n^2)

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Tri à fusion (fonctions merge et mergeSort)
// Complexité temporelle : O(n log n)

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Tri rapide (fonctions partition et quickSort)
// Complexité temporelle : O(n^2) dans le pire cas, O(n log n) en moyenne

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fonction pour afficher le tableau
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Fonction principale
int main() {
    int arr[] = {1, 3, 5, 7, 8, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice;

    printf("Tableau d'origine : ");
    printArray(arr, n);

    printf("\nChoisissez le type de tri :\n");
    printf("1. Tri à bulles\n");
    printf("2. Tri par sélection\n");
    printf("3. Tri à fusion\n");
    printf("4. Tri rapide\n");
    printf("Votre choix : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            printf("Tableau trié avec Tri à bulles : ");
            break;
        case 2:
            selectionSort(arr, n);
            printf("Tableau trié avec Tri par sélection : ");
            break;
        case 3:
            mergeSort(arr, 0, n - 1);
            printf("Tableau trié avec Tri à fusion : ");
            break;
        case 4:
            quickSort(arr, 0, n - 1);
            printf("Tableau trié avec Tri rapide : ");
            break;
        default:
            printf("Choix invalide.\n");
            return 1;
    }

    printArray(arr, n);
    return 0;
}
