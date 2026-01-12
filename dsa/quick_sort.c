//quick sort in C
//algo = chose pivot, partition, and repeat
// TC is O(n logn) and SC is O(log n) due to recursion stack
// TC at worst case is O(n^2) when the array is sorted orignially
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);


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

    quick_sort(arr, 0, n-1);
    
    //display sorted array
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }

    printf("\nBY SAYAM SHRESTHA\n");

    //free array after using it
    free(arr);
    return 0;
}

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

int partition(int arr[], int low, int high){
    int i = low;
    int j = high;
    int pivot = arr[low];

    while(i < j){
        while(arr[i]<=pivot && i <= high -1) i++;
        while(arr[j]>pivot && j >= low + 1) j--;

        if(i < j) swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]);
    return j;//partition index
}

void quick_sort(int arr[], int low, int high){
    if (low < high){
        int partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index -1);
        quick_sort(arr, partition_index + 1, high);
    }
}

