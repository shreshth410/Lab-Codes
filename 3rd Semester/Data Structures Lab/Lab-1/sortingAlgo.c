#include <stdio.h>
#include <stdlib.h>

//BUBBLE SORT
void bubbleSort(int array[], int n){
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%i\n", array[i]);
    }
}

//SELECTION SORT
void selectionSort(int array[], int n){
    for(int i = 0; i < n; i++){
        int s = array[i], l = i;
        for(int j = i; j < n; j++){
            if (array[j] < s){
                s = array[j];
                l = j;
            }
        }
        int temp = array[i];
        array[i] = array[l];
        array[l] = temp;
    }

    for(int i = 0; i < n; i++){
        printf("%i\n", array[i]);
    }
}

//INSERTION SORT
void insertionSort(int arr[], int N) {

    // Starting from the second element
    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are
      	// greater than key, to one position to
      	// the right of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Move the key to its correct position
        arr[j + 1] = key;
    }
}

int main()
{
    int array[] = {23, 42, 53, 12, 65, 85, 0 ,72, 34, 44};
    int n = 10;
    printf("Bubble sort:\n");
    bubbleSort(array, n);

    int array2[] = {23, 42, 53, 12, 65, 85, 34, 0, 72, 44};
    printf("Selection Sort: \n");
    selectionSort(array2, n);

    int array3[] = {23, 42, 53, 12, 65, 85, 34, 0, 72, 44};
    printf("Insertion Sort: \n");
    insertionSort(array3, 10);

    return 0;
}