// Multiply matrices using pointers

#include <stdio.h>
#include <stdlib.h>

void display_matrix(int** matrix, int m, int n){
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d\t", *(*(matrix+i)+j));
        }
        printf("\n");
    }
    printf("\n");
}

int** create_2d_array(int m, int n) {
    int** C = (int**)malloc(m * sizeof(int*));
    if (C == NULL) return NULL;

    for (int i = 0; i < m; i++) {
        *(C+i) = (int*)malloc(n * sizeof(int));
        if (*(C+i) == NULL) {
            for (int j = 0; j < i; j++) {
                free(*(C+j));
            }
            free(C);
            return NULL;
        }
    }

    return C;
}

int** multiply_matrices(int** A, int** B, int m, int n, int p, int q){
	if (n != p){
		printf("Invalid array dimensions.");
		return NULL;
	}

	int** C = create_2d_array(m, q);

	for (int i = 0; i < m; i++){
		for(int j = 0; j < q; j++){
			*(*(C+i)+j) = 0;
			for(int k = 0; k < n; k++){
				*(*(C+i)+j) += (*(*(A+i)+k)* *(*(B+k)+j));
			}
		}
	}

	return C;
}

int main(void){
	int m, n, p, q;
	printf("Enter dimensions of first matrix: ");
	scanf("%dx%d", &m, &n);

	int** A = create_2d_array(m, n);

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("Enter element %d-%d: ", i+1, j+1);
			scanf("%d", (*(A+i)+j));
		}
	}

	printf("Enter dimensions of second matrix: ");
	scanf("%dx%d", &p, &q);

	int** B = create_2d_array(p, q);

	for(int i = 0; i < p; i++){
		for(int j = 0; j < q; j++){
			printf("Enter element %d-%d: ", i+1, j+1);
			scanf("%d", (*(B+i)+j));
		}
	}

	printf("Matrix A: \n");
	display_matrix(A, m, n);

	printf("Matrix B: \n");
	display_matrix(B, p, q);

	int** C = multiply_matrices(A, B, m, n, p, q);
	printf("Multiplied matrices A & B. \n");

	printf("Matrix C: \n");
	display_matrix(C, m, q);
}