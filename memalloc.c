#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
int n, np;
struct hole
{
    int size;
    bool visited;
} h[40];
struct pro
{
    int size;
    int index;
} p[40];
void in()
{
    int i;
    for (i = 0; i < np; i++)
    {
        p[i].index = -1;
    }
    for (i = 1; i <= n; i++)
    {
        h[i].visited = false;
    }
}
void display()
{
    for (int i = 0; i < np; i++)
    {
        if (p[i].index != -1)
        {
            printf("\n P%i - H%i", i, p[i].index);
        }
        else
        {
            printf("\n P%i - Cannot be allocated", i);
        }
    }
    printf("\n");
}
void ff()
{
    int i, j;
    in();
    for (i = 0; i < np; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (h[j].visited == false && h[j].size >= p[i].size)
            {
                h[j].visited = true;
                p[i].index = j;
                break;
            }
        }
    }
    display();
}
void bf()
{
    int i, j;
    in();
    int t, s, si;
    for (i = 0; i < np; i++)
    {
        s = INT_MAX;
        si = -1;
        for (j = 1; j <= n; j++)
        {
            if (h[j].visited == false && h[j].size >= p[i].size)
            {
                if (h[j].size < s)
                {
                    s = h[j].size;
                    si = j;
                }
            }
        }
        if (si != -1)
        {
            p[i].index = si;
            h[si].visited = true;
        }
    }
    display();
}
void wf()
{
    int i, j;
    in();
    int t, s, si;
    for (i = 0; i < np; i++)
    {
        s = INT_MIN;
        si = -1;
        for (j = 1; j <= n; j++)
        {
            if (h[j].visited == false && h[j].size >= p[i].size)
            {
                if (h[j].size > s)
                {
                    s = h[j].size;
                    si = j;
                }
            }
        }
        if (si != -1)
        {
            p[i].index = si;
            h[si].visited = true;
        }
    }
    display();
}
int main()
{
    int c;
    printf("Enter the number of holes\n");
    scanf("%i", &n);
    printf("Enter the sizes of holes\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%i", &h[i].size);
    }
    printf("Enter the number of processes\n");
    scanf("%i", &np);
    printf("Enter the sizes of processes\n");
    for (int i = 0; i < np; i++)
    {
        scanf("%i", &p[i].size);
    }
    while (1)
    {
        printf("\n1.First Fit\n");
        printf("2.Best Fit\n");
        printf("3.Worst Fit\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");
        scanf("%i", &c);
        switch (c)
        {
        case 1:
            ff();
            break;
        case 2:
            bf();
            break;
        case 3:
            wf();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter correct option\n");
        }
    }
}
