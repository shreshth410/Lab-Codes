#include <stdio.h>

int linearSearch(int array[], int n, int search){
    for (int i = 0; i < n; i++){
        if (array[i] == search){
            return i;
        }
    }
    return -1;
}

int main(void){
    int n = 7;
    int array[] = {23, 42, 53, 12, 65, 45, 34};
    int search = 34;

    printf("Position: %i", linearSearch(array, n, search));
}