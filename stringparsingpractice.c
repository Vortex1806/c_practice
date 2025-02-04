#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person
{
    char name[50];
    int age;
    char country[50];
} Person;

int main()
{
    char name[5];
    int age;
    char strp[] = "{{shubh:23},{shreyas:24},{vikas:34}}";
    Person people[10];
    int count = 0;
    // removed first and last from the code
    char *ptr = strp + 1;
    ptr[strlen(ptr) - 1] = '\0';

    char *token = strtok(ptr, "},{");
    while (token != NULL)
    {
        sscanf(token, "%[^:]:%d", people[count].name, &people[count].age);
        count++;
        token = strtok(NULL, "},{");
    }
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }
    return 0;
}

int main()
{
    char name[5];
    int age;
    char strp[] = "add(hello,23)|pop()|add(shubh,34)";
    Person people[10];
    int top = -1;
    int count = 0;
    // removed first and last from the code
    char *ptr = strp;

    char *token = strtok(ptr, "|");
    while (token != NULL)
    {
        if (strncmp(token, "add", 3) == 0)
        {
            printf("push");
            sscanf(token, "add(%[^,],%d)", people[count].name, &people[count].age);
            count++;
        }
        else if (strncmp(token, "pop", 3) == 0)
        {
            printf("pop");
            count--;
        }

        token = strtok(NULL, "|");
    }
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }
    return 0;
}

int main()
{
    char file[5];
    char strp[] = "['cd usr/','cd bin/','cd ../','cd local/']";
    // removed first and last from the code
    char *ptr = strp + 1;
    ptr[strlen(ptr) - 1] = '\0';
    char *token = strtok(ptr, "','");
    while (token != NULL)
    {
        sscanf(token, " cd %s", file);
        file[strlen(file) - 1] = '\0';
        printf("%s\n", file);
        token = strtok(NULL, "','");
    }

    return 0;
}

int main()
{
    Person p[10];
    int top = -1;
    char strp[] = "[('John', 25, 'USA'), ('Shubh', 23, 'India'), ('Vikas', 34, 'UK')]";
    // removed first and last from the code
    char *ptr = strp + 1;
    ptr[strlen(ptr) - 1] = '\0';
    char *token = strtok(ptr, ")(");
    while (token != NULL)
    {
        top++;
        // printf("%s\n", token);
        sscanf(token, "  '%[^']', %d, '%[^']'", p[top].name, &p[top].age, p[top].country);
        printf("%s | %d | %s\n", p[top].name, p[top].age, p[top].country);
        token = strtok(NULL, ")(");
        token = strtok(NULL, ")(");
    }

    return 0;
}

typedef struct Dictionary
{
    char key[50];
    char val[50];
} Dictionary;

int main()
{
    Dictionary d;
    int top = -1;
    char strp[] = "name=shubh&age=23&city=Bangalore&lang=C++|Python|Go";
    char *ptr = strp;
    char *token = strtok(ptr, "&");
    while (token != NULL)
    {
        top++;
        // printf("%s\n", token);
        sscanf(token, " %[^=]=%s", d.key, d.val);
        printf("%s----%s\n", d.key, d.val);
        token = strtok(NULL, "&");
    }

    return 0;
}

int main()
{
    Dictionary d;
    int top = -1;
    char strp[] = "<name>Shubh</name><age>23</age><city>Bangalore</city>";
    char *ptr = strp;
    int i = 0;
    char *token = strtok(ptr, "></");
    while (token != NULL)
    {
        i++;
        // printf("%s\n", token);
        if (i % 2 == 1)
            sscanf(token, "%s", d.key);
        else
            sscanf(token, "%s", d.val);
        if (i % 2 == 0)
            printf("%s----%s\n", d.key, d.val);
        token = strtok(NULL, "></");
        if (i % 2 == 0)
            token = strtok(NULL, "></");
    }

    return 0;
}
