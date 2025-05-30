#include <stdio.h>



int mlog(int x){
    int count =0;
    while(x!=0){
        count+=1;
        x/=10;
    }
    return count-1;
}
int mpow(int x, int y){
    int prod = 1;
    for (int i = 0; i < y; i++) {
        prod *=x;
    }
    return prod;
}

//compile with gcc lab4_3.c -lm
int main (int argc, char** argv){
    
    int x,i,j;
    printf("Input Number: ");
    scanf("%d",&x);

    printf("Input ranger (i j): ");
    scanf("%d %d",&i,&j);
    int digits = mlog(x);
    if(digits<j || i<0 || i>j || digits<i || j<0){
        printf("invalid i or j\n");
        return -1;
    }
    x = x%(int)mpow(10, j+1);
    x = x/(int)mpow(10,i);
    printf("%d\n", x);
    return 0;
}