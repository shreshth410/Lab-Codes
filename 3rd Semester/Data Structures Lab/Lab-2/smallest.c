// Find the smallest element in array using pointer
#include <stdio.h>
#include <stdlib.h>

int smallest_element(int* arr, int n){
	int* ptr = arr;
	int smallest = *ptr;

	while (*(ptr+1) != '\0'){
		if (*(ptr+1) < smallest){
			smallest = *(ptr+1);
		}

		ptr += 1;
	}

	return smallest;
}

int main(void){
	int n;

	printf("Enter size of array: ");
	scanf("%d", &n);

	int* arr = (int*)malloc(n*sizeof(int));
	if(arr == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

	for(int i = 0; i < n; i++){
		printf("Enter element: ");
		scanf("%d", (arr+i));
	}

	printf("Smalest element in array: %d", smallest_element(arr, n));
    printf("\n");

    free(arr);
    return 0;
}