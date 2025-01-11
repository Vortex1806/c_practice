#include <stdio.h>
#include <stdlib.h>
#define STRMAX 50
#define MAX 100000

struct Company
{
    char name[STRMAX];
    int *revenue;
    int total;
};

int getMaxRev(struct Company companies[], int n)
{
    int maxrev = 0;
    for (int i = 0; i < n; i++)
    {
        if (companies[i].total > maxrev)
        {
            maxrev = companies[i].total;
        }
    }
    return maxrev;
}

int main()
{
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    struct Company *companies = (struct Company *)malloc(n * sizeof(struct Company));
    for (int i = 0; i < n; i++)
    {
        scanf("%s", companies[i].name);
        int total = 0;
        companies[i].revenue = (int *)malloc(m * sizeof(int *));
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &companies[i].revenue[j]);
            total += companies[i].revenue[j];
        }
        companies[i].total = total;
    }
    int maxrev = getMaxRev(companies, n);

    for (int i = 0; i < n; i++)
    {
        if (maxrev == companies[i].total)
        {
            printf("%s\n", companies[i].name);
        }
    }
}