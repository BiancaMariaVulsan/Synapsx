#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void read(char str[MAX_SIZE])
{
    FILE* pf = fopen("in.txt", "r");
    if(pf == NULL)
    {
        printf("Input file does not exists!");
        exit(1);
    }
    char ch;
    int i=0;
    while(fscanf(pf, "%c", &ch)!=EOF)
    {
        str[i++] = ch;
    }
    fclose(pf);
}

char* solution(char str[MAX_SIZE], char commMark[10])
{
    static char strCpy[100];
    int delim = 0, k=0, j;
    for(int i=0; i<strlen(str); i++)
    {
        for(j=0; j<strlen(commMark) && delim == 0; j++)
            if(str[i] == commMark[j])
                delim = 1;
        if(str[i] == '\n')
            {
                delim = 0;
                j = k-1;
                while(i>0 && strCpy[j--] == ' ')
                    k--;
            }
        if(delim == 0)
        {
            strCpy[k++] = str[i];
        }
    }
    strCpy[k] = '\0';
    return strCpy;
}

void printResult(char rezStr[MAX_SIZE])
{
    FILE* outf = fopen("out.txt", "w");
    if(outf == NULL)
    {
        printf("Output file does not exists!");
        exit(1);
    }
    fprintf(outf, "%s", rezStr);
    fclose(outf);
}

int main()
{
    char str[MAX_SIZE];
    char commMark[10] = {'#', '!', '\0'};
    char result[MAX_SIZE];
    read(str);
    strcpy(result, solution(str, commMark));
    printResult(result);
    return 0;
}
