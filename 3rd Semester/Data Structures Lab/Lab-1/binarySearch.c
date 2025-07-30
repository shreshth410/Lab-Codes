#include <stdio.h>
#include <stdlib.h>

int binarySearch(int array[], int n, int search){
    int low = 0, high = n-1, mid = (low+high)/2;

    while (low < high){
        if (search == array[mid]){
            return mid;
        }

        else if (search < array[mid]){
            high = mid - 1;
            mid = (low+high)/2;
        }

        else{
            low = mid + 1;
            mid = (low+high)/2;
        }
    }
    return -1;
}

int main()
{
    int array[] = {23, 34, 42, 54, 62, 91, 102, 127};
    int n = 7;
    int search = 344;
    printf("Position: %i", binarySearch(array, n, search));
}