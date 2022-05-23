/*
    Dynamic Memory Allocation sample.
*/

#include <stdio.h>
#include <stdlib.h>

void memory_malloc();
void memory_calloc();
void memory_free();
void memory_realloc();
void memory_realloc2();

int main() {
    memory_malloc();
    memory_calloc();
    memory_free();
    memory_realloc();
    memory_realloc2();
    return 0;
}

void memory_malloc() {
    int* ptr;
    int n, i;

    printf("Insert the numbers of elements: ");
    scanf("%d", &n);

    ptr = (int*)malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {
        printf("Memory successfully allocated!\n");
 
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }
}

void memory_calloc() {
    int* ptr;
    int n, i;
 
    n = 5;
    printf("Enter number of elements: %d\n", n);
 
    ptr = (int*)calloc(n, sizeof(int));
 
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {
 
        printf("Memory successfully allocated using calloc.\n");
 
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }
}

void memory_free() {
    int *ptr, *ptr1;
    int n, i;
    n = 5;

    printf("Enter number of elements: %d\n", n);
    ptr = (int*)malloc(n * sizeof(int));
    ptr1 = (int*)calloc(n, sizeof(int));

    if (ptr == NULL || ptr1 == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {
        printf("Memory successfully allocated using malloc.\n");

        free(ptr);
        printf("Malloc Memory successfully freed.\n");
 
        printf("\nMemory successfully allocated using calloc.\n");
 
        free(ptr1);
        printf("Calloc Memory successfully freed.\n");
    }
}

void memory_realloc() {
    int* ptr;
    int n, i;
    n = 5;

    printf("Enter number of elements: %d\n", n);
    ptr = (int*)calloc(n, sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {

        printf("Memory successfully allocated using calloc.\n");
 
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
 
        n = 10;
        printf("\n\nEnter the new size of the array: %d\n", n);
 
        ptr = realloc(ptr, n * sizeof(int));
 
        printf("Memory successfully re-allocated using realloc.\n");
 
        for (i = 5; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
 
        free(ptr);
    }
}

void memory_realloc2() {
    int index = 0, i = 0, n,
    *marks;

    int ans;
    marks = (int*)malloc(sizeof(int));

    if (marks == NULL) {
        printf("Memory cannot be allocated");
    } else {
        printf("Memory has been successfully allocated!\n");
        printf("\n marks = %pc\n",
               marks);
        do {
            printf("\n Enter Marks\n");
            scanf("%d", &marks[index]);
            printf("would you like to add more(1/0): ");
            scanf("%d", &ans);
 
            if (ans == 1) {
                index++;
                marks = (int*)realloc(marks, (index + 1) * sizeof(int));

                if (marks == NULL) {
                    printf("Memory cannot be allocated");
                } else {
                    printf("Memory has been successfully reallocated:\n");
                    printf("\n base address of marks are:%pc", marks);
                }
            }
        } while (ans == 1);
        for (i = 0; i <= index; i++) {
            printf("marks of persons %d are: %d\n ", i, marks[i]);
        }
        free(marks);
    }
}