#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/*
Q: Decode a String Encoded with Run-Length Encoding
Given a compressed string like "3[a]2[bc]", expand it to "aaabcbc".
Example: 
Input: "3[a2[c]]"
Output: "accaccacc"
*/



// void recursiveParsing(char *str){
//     char res[200] = "";
//     char st[20][50];
//     int numstack[20];
//     int numtop = -1;
//     int top = -1;
//     int n = strlen(str);
//     int i = 0;
//     while(str[i] != '\0'){
//         while(str[i] != ']'){
//             if(str[i] >= '0' && str[i] <= '9'){
//                 numstack[++numtop]= (str[i] - '0');
//             }else{
//                 st[++top][0] = str[i];
//                 st[top][1] = '\0';
//             }
//             i++;
//         }
//         char check[50] = "";
//         i--;
//         while(top > -1 && st[top--][0] != '['){
//             strncat(check,st[top],strlen(st[top]));
            
//         }
//         top--;
//         int multiplier = numstack[numtop--];
//         char stackpushing[50] = "";
//         for(int i = 0; i < multiplier; i++){
//             strncat(stackpushing,check, strlen(check));
//         }
//         strcpy(st[++top],stackpushing);
        

//     }
//     printf("%s",st[top]);
    // return st[top]; 

    // int i = 0;
    // while(!isdigit(str[i])){
    //     strcat(res,str[i]);
    //     i++;
    // }
    // for(; i < strlen(str); i++){
    //     char check[100];
    //     int k = 0;
    //     if(str[i] >= '0' && str[i]<='9'){
    //         int num = str[i]-'0';
    //         i++;
    //         i++;
    //         while(str[i] != ']'){
    //             check[k++] = str[i++];
    //         }
    //         char *ans = recursiveParsing(check);
    //         for(int j = 0; j<num;j++){
    //             strncat(res,check,strlen(check));
    //         }
    //     }
    // }
    // return res;
    

// }

// int main(){
//     //first testcase passed
//     char str[100] = "3[a]2[bc]";
//     char res[100];

    // for(int i = 0 ; i < strlen(str); i++){
    //     char check[100];
    //     int k = 0;
    //     if(str[i] >= '0' && str[i]<='9'){
    //         int num = str[i]-'0';
    //         i++;
    //         i++;
    //         while(str[i] != ']'){
    //             check[k++] = str[i++];
    //         }
    //         for(int j = 0; j<num;j++){
    //             strncat(res,check,strlen(check));
    //         }
    //     }
    // }
    // return 0;

// }


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100 
void decodeString(char *s, char *result) {
    char stack[MAX_LEN][MAX_LEN]; 
    int numStack[MAX_LEN]; 
    int top = -1, numTop = -1;

    char current[MAX_LEN] = ""; 
    int num = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            strcpy(stack[++top], current);
            numStack[++numTop] = num;
            num = 0;
            current[0] = '\0';
        } else if (s[i] == ']') {
            int times = numStack[numTop--];
            char temp[MAX_LEN] = "";
            for (int j = 0; j < times; j++) {
                strcat(temp, current);
            }
            strcpy(current, stack[top--]);
            strcat(current, temp);
        } else {
            
            int len = strlen(current);
            current[len] = s[i];
            current[len + 1] = '\0';
        }
    }

    strcpy(result, current);

}

int main() {
    char str[] = "3[a2[bc]]"; 
    char result[MAX_LEN];
    
    decodeString(str, result);
    printf("%s\n", result); 
    return 0;
}


