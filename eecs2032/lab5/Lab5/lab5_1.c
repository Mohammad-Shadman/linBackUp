#include <stdio.h>

int main(){
    int l,m;
    printf("Enter left margin and row count seperated by a space: ");
    scanf("%d %d", &l, &m);

    int maxm = m;

    while (m>0){
        for (int i = 0; i < l; i++) {
            printf(" ");
        }
        l--;
        for (int i = 0; i<maxm-(m-1); i++) {
            printf("*");
        }
        m--;
        printf("\n");
    }
    return 0;
}