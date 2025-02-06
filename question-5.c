#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
A user enters a list of timestamps in the format "hh:mm am/pm" separated by commas (e.g., "10:30 am, 2:45 pm, 6:10 am").
Extracts the hour and minute from each timestamp and Converts it into 24-hour format.

INPUT : 
"10:30 am, 2:45 pm, 6:10 am, 12:00 am, 12:30 pm"

OUTPUT: 
10:30 am → 10:30
2:45 pm → 14:45
6:10 am → 06:10
12:00 am → 00:00
12:30 pm → 12:30
*/

int main(){
    char str[1000];
    int hrs;
    int min;
    scanf("%[^\n]",str);
    char t[5];
    char *ptr = str;
    char *token = strtok(ptr,",");
    while(token != NULL){
        while(*token == ' '){
            token++;
        }
        // printf("%s\n",token);
        if(sscanf(token," %d :%d %s",&hrs, &min, t) != 3){
            printf("invalid format");
            return 0;
        }
        // printf("%d, %d, %s\n",hrs, min, t);
        if(hrs > 12){
            printf("12 hr clock cannot have hrs greater than 12");
            return 0;
        }
        if(strcmp(t,"pm") == 0){
            hrs += 12;
            if(hrs >= 24){
                hrs = 12;
            }
            
        }
        if(strcmp(t,"am") == 0 && hrs == 12){
            hrs = 0;
        }
        // if(hrs ==0 && min == 0){
        //     printf("%s -> 00:00\n",token);
        // }else
        // if(hrs == 0){
        //     printf("%s -> 00:%d\n",token, min);
        // }else
        // if(min == 0){
        //     printf("%s -> %d:00\n",token, hrs);
        // }else{
        //     printf("%s -> %d:%d\n",token, hrs, min);
        // }
        printf("%s -> %02d:%02d\n",token, hrs, min);
        token = strtok(NULL,",");
    }
    return 0;
}