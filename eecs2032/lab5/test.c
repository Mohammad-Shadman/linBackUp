#include <stdio.h>

int trim(char s[]){
    char * c = s;
}


int main(){
    int a = 2, b = 3, c = 5, d = 7, e = 11, f = 3;
    a+= b+=c+=1+2;


    int arr[20];

    int *p1 = &arr[0], *p2 = &arr[4];
    printf("%i\n", (long)((long)p2-(long)p1));
    // 13  11  8
    for (int i = 0; i<20; i++) {
        printf("%d ",arr[i]);
    }
    switch(a){
        case 'a':
        break;

    }
    printf("\na %d , b %d , c %d\n",a,b,c);

    return 0;

}