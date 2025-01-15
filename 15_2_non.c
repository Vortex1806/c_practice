#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char word[20];
    int count;
    int firstIndex;
} WordInfo;

int main()
{
    char str[1000];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    WordInfo words[100];
    int wordssize = 0;
    char *token = strtok(str, " ");
    while (token)
    {
        int found = 0;

        for (int i = 0; i < wordssize; i++)
        {
            if (strcmp(words[i].word, token) == 0)
            {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            strcpy(words[wordssize].word, token);
            words[wordssize].count = 1;
            words[wordssize].firstIndex = wordssize;
            wordssize++;
        }
        token = strtok(NULL, " ");
    }
    for (int i = 0; i < wordssize; i++)
    {
        if (words[i].count == 1)
        {
            printf("%s", words[i].word);
            break;
        }
    }
    return 0;
}