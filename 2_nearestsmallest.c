#include<stdio.h>
#include<stdlib.h>

void getsmallestarr(int *arr, int n){
    int smallest = arr[0];
    int sarr[n];
    sarr[0] = -1;
    for(int i = 1; i < n; i++){
        if(arr[i] > smallest){
            sarr[i] = smallest;
        }else{
            sarr[i] = -1;
            smallest = arr[i];
        }
    }
    for(int i = 0; i < n; i++){
        printf(" %d ",sarr[i]);
    }
}

int main(){
    int arr[5] = {4,5,2,10,8};
    int n = 5;
    getsmallestarr(arr, n);
    
    return 0;
}