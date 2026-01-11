// selection sort in C
// algo = select minimum and swap
//TC for selection sort is O(n^2)
#include <stdio.h>
#include <stdlib.h>

//function for swapping 
void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

//selection sort funciton
void selection_sort(int arr[], int n){
    for (int i = 0; i< n - 1; i++){
        int min = i;
        for (int j = i+1 ; j < n; j++){
            if (arr[j] < arr[min]) min = j;
        }
        if (min != i) swap(&arr[min], &arr[i]);   
    }
}

int main(){
    int n;

    printf("Enter the array size: ");
    scanf("%i", &n);

    //allocate array size dynamically
    int *arr = malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Error allocating array size!!\n");
        return 1;
    }
    
    //take user input for array elements
    for(int i = 0; i < n; i++){
        printf("Enter the element %i: ", (i+1));
        scanf("%i", &arr[i]);
    }

    selection_sort(arr, n);
    
    //display sorted array
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }

    //free array after using it
    free(arr);
    return 0;
}