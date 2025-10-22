#include <stdio.h>
#include "mylib.h"
#include "arraylib.h"

int main()
{
    int choice, num;
    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Check Armstrong Number\n");
        printf("2. Check Adams Number\n");
        printf("3. Check Prime Palindrome Number\n");
        printf("4. Array operations\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5){
            printf("Exiting Program. Goodbye!\n");
            break;
        }

        if(choice>=1 && choice<=3){
            printf("Enter a number: ");
            scanf("%d", &num);
        }

        switch(choice){
            case 1:
                if (isArmstrong(num)){
                    printf("%d is an Armstrong number.\n", num);
                }else{
                    printf("%d is NOT an Armstrong number.\n", num);
                }
                break;
            case 2:
                if (isAdams(num)){
                    printf("%d is an Adams number.\n", num);
                }else{
                    printf("%d is NOT an Adams number.\n", num);
                }
                break;
            case 3:
                if (isPrimePalindrome(num)){
                    printf("%d is a Prime Palindrome number.\n", num);
                }else{
                    printf("%d is NOT a Prime Palindrome number.\n", num);
                }
                break;
            case 4:
            {
                int  size, val;
        	    printf("Enter array size: ");
                scanf("%d", &size);

                int arr[size], dup[size];
                printf("Enter %d elements: ", size);
                for (int i=0; i<size; i++){
                    scanf("%d",&arr[i]);
                }
                for(int i=0; i<size; i++){
                    dup[i] = arr[i];
                }


            
                printf("\nOriginal ");
                displayarray(arr, size);
                printf("Average=%.2f\n", findaverage(arr,size));
                printf("Max at index %d, Min at index %d\n", findmaxindex(arr,size), findminindex(arr, size));
            
                reversearray(arr,size);
                printf("Reversed");
                displayarray(arr,size);
            
                sortarray(arr,size);
                printf("sorted");
                displayarray(arr, size);

                printf("Enter value to search");
                scanf("%d", &val);
                int pos = linearsearch(dup , size, val);
                if (pos != -1){
                    printf("%d found at index %d\n", val, pos);
                }else{
                    printf("%d not found in array\n", val);
                    break;
                }
            }
            default:
                printf("Invalid Choice! Please select between 1-4.\n");

        }
    }while (choice != 5);

    return 0;
}
