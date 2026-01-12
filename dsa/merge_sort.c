//merge sort in C
//algo = divide, sort, and merge
// TC is O(n logn)
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high);
void merge_sort(int arr[], int low, int  high);

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

    merge_sort(arr, 0, n-1);
    
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

void merge(int arr[], int low, int mid, int high){
    int left = low;
    int right = mid+1;
    int k = 0;
    int temp[high - low +1];

    while(left <= mid && right <= high){
        if (arr[left] <= arr[right]){
            temp[k] = arr[left];
            left++;
            k++;
        }
        else {
            temp[k]= arr[right];
            right++;
            k++;
        }
    }

    while(left <= mid){
        temp[k] = arr[left];
        left++;
        k++;
    }

    while(right <= high){
        temp[k] = arr[right];
        right++;
        k++;
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}

void merge_sort(int arr[], int low, int high){
    if(low >= high) return;

    int mid = (low+high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
}