#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MWORD_LENGTH 100
#define MAX_WORDS 10

int my_strcspn(char *str, char ch)
{
    char *ptr = str;
    while (*ptr != '\0')
    {
        if (*ptr == ch)
        {
            return ptr - str;
        }
        ptr++;
    }
    return ptr - str;
}

void reverseWords(char *str)
{
    char **words = (char **)malloc(MAX_WORDS * sizeof(char *));
    int wordCount = 0;
    char *word = NULL;
    char *start = str;
    while (*start != '\0')
    {
        while (*start == ' ')
            start++;
        if (*start == '\0')
            break;

        char *end = start;
        while (*end != ' ' && *end != '\0')
            end++;

        int wordLen = end - start;
        word = (char *)malloc((wordLen + 1) * sizeof(char));
        strncpy(word, start, wordLen);
        word[wordLen] = '\0';
        words[wordCount++] = word;
        start = end;
    }
    printf("Reversed words:\n");
    for (int i = wordCount - 1; i >= 0; i--)
    {
        printf("%s ", words[i]);
        free(words[i]);
    }

    free(words);
    printf("\n");
}

int main()
{
    char str[MWORD_LENGTH * 10];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[my_strcspn(str, '\n')] = '\0';
    reverseWords(str);
    return 0;
}