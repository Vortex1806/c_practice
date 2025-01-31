#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char *str;
    int **arr;
}MyStruct;

void initStruct(MyStruct *ms){
    ms->str = (char*)malloc(sizeof(char)*100);
    ms->arr = (int**)malloc(sizeof(int*)*10);
    for(int i = 0; i < 10; i++){
        ms->arr[i] = (int*)malloc(sizeof(int)*10);
    }
}

void destroy(MyStruct *ms){
    free(ms->str);
}

int main(){
    MyStruct *ms = (MyStruct*)malloc(sizeof(MyStruct));

    initStruct(&ms);
    printf("Put String: ");
    scanf("%s",ms.str);
    printf("%s",ms.str);
    printf("\n\nEnter matrix 2x2\n");
    for(int i = 0; i < 2;i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &ms.arr[i][j]);
        }
    }
    printf("\n");
    for(int i = 0; i < 2;i++){
        for(int j = 0; j < 2; j++){
            printf("%d ", ms.arr[i][j]);
        }
        printf("\n");
    }
}