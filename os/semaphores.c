#include <stdio.h>

int main(){
    int buffer[10], bufsize, produce, consume,
    choice = 0, in = 0, out=0,bufsie=10;

    while(choice != 3){
        printf("\n1.Produce\t2.Consume\t3.Exit\n");
        printf("Enter your choice: ");
        scanf("%i", &choice);
        
        switch(choice){
            case 1:
                if((in + 1) % bufsize == out){
                    printf("\nBuffer size is full.\n");
                    break;
                }
                else {
                    printf("Enter the value: ");
                    scanf("%i", &produce);
                    buffer[in] = produce;
                    in = (in+1)%bufsize;
                    break;
                }
                case 2:
                    if(in == out){
                        printf("\nBuffer is empty.\n");
                        
                    }
                    else{
                        consume = buffer[out];
                        printf("The consumed value is: %i\n", consume);
                        out = (out+1)%bufsize;
                    }
                    break;
                
        }
    }

    printf("\n----By Sayam Shrestha----\n");
    return 0;
}