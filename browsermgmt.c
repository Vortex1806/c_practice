#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char str[1000];
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;
}Stack;

void initstack(Stack *st){
    st->top = NULL;
}
void viewing(Stack *st){
    // printf("printing\n");
    Node *temp = st->top;
    while(temp){
        printf("%s -> ",temp->str);
        temp = temp->next;
    }
    printf("NULL\n");
}
void push(Stack *st, char url[]){
    // printf("pushing\n");
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    strcpy(newNode->str,url);
    if(st->top == NULL){
        st->top = newNode;
    }else{
        newNode->next = st->top;
        st->top = newNode;
    }
    // viewing(st);
}

void pop(Stack *st){
    // printf("popping\n");
    if(st->top == NULL){
        return;
    }
    Node *temp = st->top;
    st->top = st->top->next;
    free(temp);
}

void edit(Stack *st, char url[],char newurl[]){
    // printf("editing\n");
    Node *temp = st->top;
    while (temp)
    {
        if(strcmp(temp->str,url) == 0){
            strcpy(temp->str,newurl);
            return;
        }
        temp = temp->next;
    }
    
}




int main(){
    Stack *st = (Stack*)malloc(sizeof(Stack));
    initstack(st);
    char url[100];
    char newurl[100];
    char str[] = "{push(www.google.com)}|{push(www.github.com)}|{push(www.openai.com)}|{view()}|{edit(www.github.com,www.microsoft.com)}|{view()}|{pop()}|{view()}|{push(www.reddit.com)}|{push(www.stackoverflow.com)}|{push(www.wikipedia.org)}|{view()}|{pop()}|{pop()}|{pop()}|{pop()}|{pop()}|{pop()}|{view()}|{edit(www.reddit.com,www.quora.com)}|{push(www.netflix.com)}|{view()}|{pop()}|{pop()}|{pop()}|{view()}";
    
    char *ptr = str;
    char *token = strtok(ptr,"{|}");
    while(token != NULL){
        // printf("%s\n",token);
        if(strncmp(token,"push",4) == 0){
            sscanf(token, " push(%[^)])",url);
            push(st,url);
        }else if(strncmp(token,"view",4) == 0){
            viewing(st);
        }else if(strncmp(token,"pop",3) == 0){
            pop(st);
        }else if(strncmp(token,"edit",4) == 0){
            sscanf(token, " edit(%[^,],%[^)])",url,newurl);
            edit(st, url, newurl);
        }
        token = strtok(NULL,"|}{");
    }



    // int ch;
    // while(1){
    //     printf("Browser Stack management\n");
    //     printf("1. Add website\n");
    //     printf("2. View history\n");
    //     printf("3. Edit url\n");
    //     printf("4. Remove recent\n");
    //     printf("5. Clear history\n");
    //     printf("6. Peek\n");
    //     printf("7. exit\n");
    //     printf("Enter the choice:");
    //     scanf("%d",&ch);
    //     switch(ch){
    //         case 1:
    //         printf("Enter the url: ");
    //             scanf("%s",url);
    //             push(st,url);
    //             break;
    //         case 2:
    //             printhistory(st);
    //             break;
    //         case 3:
    //             printf("Enter the url to be edited: ");
    //             scanf("%s",url);
    //             printf("Enter the new url: ");
    //             scanf("%s",newurl);
    //             editurl(st, url, newurl);
    //             break;
    //         case 4:
    //             pop(st);
    //             break;
    //         case 5:
    //             st->top = NULL;
    //             break;
    //         case 6:
    //             if(st->top == NULL){
    //                 printf("Empty\n");
    //             }else{
    //                 printf("%s\n",st->top->str);
    //             }
    //             break;
    //         case 7:
    //             return 0;
    //         default:
    //             printf("Invalid\n");
    //             break;

    //     }
    // }
    return 0;
}