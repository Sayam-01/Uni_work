#include <stdio.h>
#define MAX 1000

int binary_search(int arr[], int size, int value){
    int low = 0;
    int high = size - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == value){
            return mid;
        }
        else if(arr[mid] < value){
            low = mid + 1;
        }
        else{
            high = mid - 1; 
        }
    }
    return -1;
}

int main(){
    int arr[MAX], value, size;

    printf("Enter array size: ");
    scanf("%i", &size);

    if(size > MAX || size <= 0){
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter array elements (sorted):\n");
    for(int i = 0; i < size; i++){
        printf("Element %i: ", i + 1);
        scanf("%i", &arr[i]);
    }

    printf("Enter value to be searched: ");
    scanf("%i", &value);

    int result = binary_search(arr, size, value);
    if(result == -1){
        printf("Element not in the array.\n");
    }
    else{
        printf("%i found at index %i.\n", value, result);
    }

    printf("\n----By Sayam Shrestha-----\n");
    return 0;
}
