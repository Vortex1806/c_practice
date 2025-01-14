// sorting characters by frequency
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 52

struct CharacterFrequency
{
    char ch;
    int freq;
};

int getlength(char *num)
{
    int size = 0;
    while (*num != '\0')
    {
        size++;
        num++;
    }
    return size;
}

char *frequencySort(char *s)
{
    int n = getlength(s);
    char *result = (char *)malloc(n + 1);
    int maxfreq = 0;
    struct CharacterFrequency freq[MAX_CHARS] = {0};
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            freq[s[i] - 'a'].ch = s[i];
            freq[s[i] - 'a'].freq++;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            freq[s[i] - 'A' + 26].ch = s[i];
            freq[s[i] - 'A' + 26].freq++;
        }
    }

    for (int i = 0; i < MAX_CHARS; i++)
    {
        if (freq[i].freq > maxfreq)
        {
            maxfreq = freq[i].freq;
        }
    }

    int end = 0;
    for (int i = maxfreq; i > 0; i--)
    {
        for (int j = 0; j < MAX_CHARS; j++)
        {
            if (freq[j].freq == i)
            {
                for (int k = 0; k < i; k++)
                {
                    result[end++] = freq[j].ch;
                }
            }
        }
    }
    result[end] = '\0';
    return result;
}

int main()
{
    char str[6];
    printf("Enter the string: ");
    scanf("%s", str);
    char *sorted = frequencySort(str);
    printf("\n%s\n", sorted);
    free(sorted);
}