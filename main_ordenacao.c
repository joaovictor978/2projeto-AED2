#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
	int i;
	int j;
 	for ( i = 0; i < n-1; i++) {
 		for ( j = 0; j < n-i-1; j++) {
 			if (arr[j] > arr[j+1]) {
 				// Trocar os elementos
 				int temp = arr[j];
 				arr[j] = arr[j+1];
 				arr[j+1] = temp;
 			}
 		}
 	}
}
void insertionSort(int arr[], int n) {
 int i, key, j;
 for (i = 1; i < n; i++) {
 	key = arr[i];
 	j = i - 1;
 
 	// Mover os elementos do arr[0..i-1], que são maiores que key
 	while (j >= 0 && arr[j] > key) {
 		arr[j+1] = arr[j];
 		j = j - 1;
 		}
 		arr[j+1] = key;
	}
}
void merge(int arr[], int left, int mid, int right) {
 int n1 = mid - left + 1;
 int n2 = right - mid;
 int i = 0;
 int j = 0;
 int k = left;
 int L[n1], R[n2];
 
 // Copiar dados para os arrays temporários L[] e R[]
 for ( i = 0; i < n1; i++)
 	L[i] = arr[left + i];
 for ( j = 0; j < n2; j++)
 	R[j] = arr[mid + 1 + j];
 
  // Mesclar os arrays temporários de volta para o arr[]
 
 while (i < n1 && j < n2) {
 	if (L[i] <= R[j]) {
 		arr[k] = L[i];
 		i++;
 	} else {
 		arr[k] = R[j];
 		j++;
 	}
 	k++;
 }
 
 // Copiar os elementos restantes de L[], se houver
 while (i < n1) {
 	arr[k] = L[i];
 	i++;
 	k++;
 }
 
 // Copiar os elementos restantes de R[], se houver
 while (j < n2) {
 	arr[k] = R[j];
 	j++;
 	k++;
 }
}
void mergeSort(int arr[], int left, int right) {
	int j;
 if (left < right) {
 	int mid = left + (right - left) / 2;

 	mergeSort(arr, left, mid);
 	mergeSort(arr, mid + 1, right);
 
 	merge(arr, left, mid, right);
 }
}
int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);
	int j;
 
	for ( j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
 			i++;
 			// Trocar arr[i] e arr[j]
 			int temp = arr[i];
 			arr[i] = arr[j];
 			arr[j] = temp;
 		}
 	}
 
 	// Trocar arr[i+1] e arr[high] (pivot)
 	int temp = arr[i + 1];
 	arr[i + 1] = arr[high];
 	arr[high] = temp;
 
 	return (i + 1);
}
void quickSort(int arr[], int low, int high) {
	if (low < high) {
 		int pi = partition(arr, low, high);
 
 		quickSort(arr, low, pi - 1);
 		quickSort(arr, pi + 1, high);
 	}
}
void printArray(int arr[], int n) {
	int i;
 	for (i = 0; i < n; i++) {
 	printf("%d ", arr[i]);
 	}
 printf("\n");
}
int main() {
 // Arrays de exemplo
 int arr1[] = {64, 25, 12, 22, 11};
 int arr2[] = {64, 34, 25, 12, 22, 11};
 int arr3[] = {12, 11, 13, 5, 6, 7};
 int arr4[] = {10, 7, 8, 9, 1, 5};
 int n1 = sizeof(arr1) / sizeof(arr1[0]);
 int n2 = sizeof(arr2) / sizeof(arr2[0]);
 int n3 = sizeof(arr3) / sizeof(arr3[0]);
 int n4 = sizeof(arr4) / sizeof(arr4[0]);
 // Bubble Sort
 printf("Array antes de ordenar (Bubble Sort):\n");
 printArray(arr1, n1);
 bubbleSort(arr1, n1);
 printf("Array apos ordenar (Bubble Sort):\n");
 printArray(arr1, n1);
 // Insertion Sort
 printf("\nArray antes de ordenar (Insertion Sort):\n");
 printArray(arr2, n2);
 insertionSort(arr2, n2);
 printf("Array apos ordenar (Insertion Sort):\n");
 printArray(arr2, n2);
 // Merge Sort
 printf("\nArray antes de ordenar (Merge Sort):\n");
 printArray(arr3, n3);
 mergeSort(arr3, 0, n3 - 1);
 printf("Array apos ordenar (Merge Sort):\n");
 printArray(arr3, n3);
 // Quick Sort
 printf("\nArray antes de ordenar (Quick Sort):\n");
 printArray(arr4, n4);
 quickSort(arr4, 0, n4 - 1);
 printf("Array apos ordenar (Quick Sort):\n");
 printArray(arr4, n4);
 return 0;
}
