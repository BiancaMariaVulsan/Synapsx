#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

int A[N][N], sizeArray=0, sizeGroup=0;

void readArray()
{
    FILE* pf = fopen("in.txt", "r");
    if(pf == NULL)
    {
        printf("Input file does not exists!");
        exit(1);
    }
    char ch;
    fscanf(pf, "%c", &ch);
    int i=0, j=0;
    while(fscanf(pf, "%c", &ch)!=EOF)
    {
        if(ch == '[')
        {
            j=0;
            fscanf(pf, "%d", &A[i][j++]);
        }
        else if(ch == ']')
        {
            i++; fscanf(pf, "%c", &ch);
        }
        else if(ch == ',')
            fscanf(pf, "%d", &A[i][j++]);
    }
    fclose(pf);
    sizeArray = --i;
    sizeGroup = sqrt(i);
}

int check()
{
    int v[N];
    // lines
    for(int i=0; i<sizeArray; i++)
    {
        for(int j=0; j<sizeArray; v[j] = 0, j++);
        for(int j=0; j<sizeArray; j++)
            if(v[A[i][j]]++ == 1)
                return 0;
    }
    // columns
    for(int i=0; i<sizeArray; i++)
    {
        for(int j=0; j<sizeArray; v[j] = 0, j++);
        for(int j=0; j<sizeArray; j++)
            if(v[A[j][i]]++ == 1)
                return 0;
    }
    // groups
    int l=0, k=0;
    while(l!=sizeArray && k!=sizeArray)
    {
        for(int j=0; j<sizeArray; v[j] = 0, j++);
        for(int i=l; i<sizeGroup+l; i++)
        for(int j=k; j<sizeGroup+k; j++)
            if(v[A[i][j]]++ == 1)
                return 0;
        k += sizeGroup;
        if(k>=sizeArray)
        {
            k=0;
            l+= sizeGroup;
        }
    }
    return 1;
}

int main()
{
    readArray();
    if(check())
        printf("Valid Sudoku!");
    else
        printf("Invalid Sudoku!");
    return 0;
}
