#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void pretoin(char *str, int n){
    char stack[20][100];
    int top = -1;
    for(int i = n-1; i >=0; i--){
        if(str[i] >= 'a' && str[i] <= 'z'){
            stack[++top][0] = str[i];
            stack[top][1] = '\0';
        }else{
            char a[100],b[100];
            strcpy(b,stack[top--]);
            strcpy(a,stack[top--]);

            char newExpr[100];
            newExpr[0] = '(';
            newExpr[1] = '\0';
            strcat(newExpr, b);
            strncat(newExpr, &str[i], 1);
            strcat(newExpr, a);
            strcat(newExpr, ")");
            
            strcpy(stack[++top], newExpr);
        }
    }
    printf("%s",stack[0]);
}

int main(){
    char str[100] = "*-a/bc-/akl";
    int n = 11;
    pretoin(str, n);
}