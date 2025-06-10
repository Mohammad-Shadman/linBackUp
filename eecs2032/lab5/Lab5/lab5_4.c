#include <stdio.h>

int main(){
    int rows, colums;
    printf("Enter rows followed by columns: ");
    scanf("%d %d", &rows, &colums);
    int arr[50*50];
    printf("Enter array of %dx%d\n", rows,colums);

    for(int i = 0; i < rows*colums; i++){
        scanf("%d",arr+i);
    }
    int validRow;
    for (int i = 0; i<rows; i++) {
        validRow = 1;
        for(int j = 1; j<colums; j++){
            if(*(arr+i*colums+j-1) >*(arr + i*colums+j)){
                validRow = 0;
            }
        }
        if (validRow){
            printf("%d\n", i+1);
        }
    }

    return 0;
}