// bubble sort in C
// algo = compare adjacent elements and swap if necessary
//TC for bubble sort is O(n^2) in average
//the best case is O(n) when no swaps occur
#include <stdio.h>
#include <stdlib.h>


//bubble sort funciton
void bubble_sort(int arr[], int n){
    for (int i = 0; i < n -1; i++){
        //using a flag for optimization
        int swapped = 0;
        for (int j = 0; j < n - i -1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= temp;
                swapped = 1;
            }
            
        }
        if (!swapped) break;
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

    bubble_sort(arr, n);
    
    //display sorted array
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }

    printf("\n----By Sayam Shrestha-----\n");

    
    //free array after using it
    free(arr);
    return 0;
}