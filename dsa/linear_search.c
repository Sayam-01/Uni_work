#include <stdio.h>
#define MAX 1000

int linear_search(int arr[], int size, int value){
    for(int i = 0; i < size; i++){
        if(arr[i]==value) return i;
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
    
    printf("Enter array elements: \n");
    for(int i = 0; i < size; i++){
        printf("Element %i: ", i+1);
        scanf("%i", &arr[i]);
    }

    printf("Enter value to be searched: ");
    scanf("%i", &value);

    int result = linear_search(arr, size, value);
    if(result == -1){
        printf("Element not in the arrar.\n");
        return 0;
    }
    printf("%i found at index %i.\n", value, result);
    printf("\n----By Sayam Shrestha-----\n");
    return 0;
}