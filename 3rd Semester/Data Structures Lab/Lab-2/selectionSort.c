//Selection sort using recursion and pointers

#include <stdio.h>
#include <stdlib.h>

int* smallest_element(int* arr, int n){
	int* ptr = arr;
	int *smallest = ptr;

	while (*(ptr+1) != '\0'){
		if (*(ptr+1) < *smallest){
			smallest = (ptr+1);
		}

		ptr += 1;
	}

	return smallest;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* selection_sort(int* arr, int n){
    if (n == 1) return arr;

    else{
        int* smallest = smallest_element(arr, n);
        swap(smallest, arr);

        return selection_sort(arr+1, n-1), arr;
    }
}

int main(void){
    int n, *arr;
    printf("Enter size of array: ");
    scanf("%d", &n);

    arr = (int*)malloc(n*sizeof(int));

    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        printf("Enter element: ");
        scanf("%d", (arr+i));
    }

    printf("Before sorting:\n");
    for(int i = 0; i < n; i++){
        printf("%d\t", *(arr+i));
    }
    printf("\n");

    printf("After sorting:\n");
    int* sorted_arr = selection_sort(arr, n);
    for(int i = 0; i < n; i++){
        printf("%d\t", *(sorted_arr+i));
    }

    free(arr);
}