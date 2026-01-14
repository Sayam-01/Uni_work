//insertion sort in C
//algo = take an element, and place it in correct pos
//Average and Worst case is O(n^2)
//Best case is O(n) [when the array is already sorted]
#include <stdio.h>
#include <stdlib.h>


//insertion sort funciton
void insertion_sort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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

    insertion_sort(arr, n);
    
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