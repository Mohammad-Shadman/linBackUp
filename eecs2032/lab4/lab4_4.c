#include <stdio.h>
#include <string.h>
#include <assert.h>

#define N 4
int main(){
    assert(N > 0);
    int arr[N];
    memset(arr,0,N*sizeof(int));
    int count = 0;
    int j;
    double avr = 0;
    int sum =0;
    for (int i = 0; i < 10; i++) {
        sum = 0;
        printf("Enter reading %d: ",i+1);
        scanf("%d",&j);
        count = count < N ? count+1 : N;
        arr[i%N] = j;
        for (int i = 0; i<N; i++) {
            sum+=arr[i];
        }
        avr = (double)(sum)/(double)count;
        printf("Average: %.2f\n",avr);

    }

    return 0;
}