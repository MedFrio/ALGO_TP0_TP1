#include <stdio.h>
#include <string.h>

// 1. La somme de n éléments d’un tableau
// Approche itérative
int sumIterative(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
    // Complexité temporelle : O(n)
}

// Approche récursive
int sumRecursive(int arr[], int n) {
    if (n <= 0) return 0;
    return arr[n - 1] + sumRecursive(arr, n - 1);
    // Complexité temporelle : O(n)
}

// 2. Factorial
// Approche itérative
int factorialIterative(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
    // Complexité temporelle : O(n)
}

// Approche récursive
int factorialRecursive(int n) {
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1);
    // Complexité temporelle : O(n)
}

// 3. Algorithmes de recherche
// i. Recherche linéaire
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
    // Complexité temporelle : O(n)
}

// ii. Recherche dichotomique (binaire) - approche itérative
int binarySearchIterative(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
    // Complexité temporelle : O(log n)
}

// ii. Recherche dichotomique (binaire) - approche récursive
int binarySearchRecursive(int arr[], int left, int right, int x) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearchRecursive(arr, left, mid - 1, x);
        return binarySearchRecursive(arr, mid + 1, right, x);
    }
    return -1;
    // Complexité temporelle : O(log n)
}

// 4. Renverser les éléments du tableau
void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    // Complexité temporelle : O(n)
}

// 5. Séquence de Fibonacci (nième élément)
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
    // Complexité temporelle : O(2^n) pour récursive sans optimisation
}

// 6. Renverser un string et vérifier s'il est un palindrome
void reverseString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int isPalindrome(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) return 0;
    }
    return 1;
    // Complexité temporelle : O(n)
}

// 7. Trouver une sous-chaîne dans une chaîne
int findSubstring(char str[], char substr[]) {
    int n = strlen(str), m = strlen(substr);
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (str[i + j] != substr[j]) break;
        }
        if (j == m) return i;
    }
    return -1;
    // Complexité temporelle : O(n * m)
}

// Fonction principale
int main() {
    // Variables pour exemples
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    char str[] = "kayak";
    char substr[] = "yak";
    
    // 1. Somme des éléments
    printf("Somme itérative : %d\n", sumIterative(arr, n));
    printf("Somme récursive : %d\n", sumRecursive(arr, n));
    
    // 2. Factorial
    printf("Factorial itératif (5) : %d\n", factorialIterative(5));
    printf("Factorial récursif (5) : %d\n", factorialRecursive(5));
    
    // 3. Recherche
    printf("Recherche linéaire (5) : %d\n", linearSearch(arr, n, 5));
    printf("Recherche dichotomique itérative (5) : %d\n", binarySearchIterative(arr, n, 5));
    printf("Recherche dichotomique récursive (5) : %d\n", binarySearchRecursive(arr, 0, n - 1, 5));
    
    // 4. Renverser le tableau
    printf("Tableau avant inversion : ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    reverseArray(arr, n);
    printf("Tableau après inversion : ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    // 5. Fibonacci
    printf("7ème élément de Fibonacci : %d\n", fibonacci(7));
    
    // 6. Palindrome
    reverseString(str);
    printf("Renversement de la chaîne : %s\n", str);
    if (isPalindrome(str)) printf("C'est un palindrome\n");
    else printf("Pas un palindrome\n");
    
    // 7. Trouver une sous-chaîne
    int index = findSubstring("Iamhers", substr);
    if (index != -1) printf("Sous-chaîne trouvée à l'index : %d\n", index);
    else printf("Sous-chaîne non trouvée\n");
    
    return 0;
}
