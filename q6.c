#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[100] = "08:30-22.5F, 12:15-25.0C, 15:45-24.8F";
    char *ptr = str;
    char ch;
    char converted;
    float conval;
    char time[10];
    float val;
    char *token = strtok(ptr,", ");
    while(token != NULL){
        // printf("%s\n",token);
        if(sscanf(token,"%[^-]-%f%c",time,&val,&ch) != 3){
            return 0;
        }
        if(ch == 'F'){
            converted = 'C';
            conval = (float)(val-32)*(5.0/9.0);
        }else{
            converted = 'F';
            conval = (val * (9.0 / 5.0)) + 32;

        }
        printf("%s - Original:%.1f*%c, Converted: %.1f*%c\n",time,val,ch,conval,converted);
        token = strtok(NULL,", ");
    }
    return 0;
}