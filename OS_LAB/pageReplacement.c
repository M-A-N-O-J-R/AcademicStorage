#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int capacity;

int fifo(int pages[], int n)
{
    int i, j, p_f = 0, flag = 0;
    int page_table[10];

    for (i = 0; i < capacity; i++)
    {
        page_table[i] = -1;
    }

    printf("\nFIFO:");
    printf("\n-----\n");
    for (i = 0; i < n; i++)
    {
        flag = 1;
        if (i < capacity)
        {
            page_table[i] = pages[i];
            p_f++;
        }

        else
        {
            for (j = 0; j < capacity; j++)
            {
                if (pages[i] == page_table[j])
                {
                    flag = 0;
                    break;
                }
            }
            if (j == capacity)
            {
                int x = (p_f) % capacity;

                page_table[x] = pages[i];
                p_f++;
            }
        }

        int d;
        if (flag)
        {
            printf("\n");
            for (d = 0; d < capacity; d++)
            {
                printf("%d ", page_table[d]);
            }
            printf(" Page fault\n");
        }

        else
        {
            printf("\n");
            for (d = 0; d < capacity; d++)
            {
                printf("%d ", page_table[d]);
            }
            printf(" No page fault\n");
        }
    }

    return p_f;
}

struct p_t
{
    int x;
    int y;
};

int least_recently_used(int pages[], int n)
{
    int i, j, p_f = 0, flag = 0;
    struct p_t page_table[10];
    int temp = 0;

    for (i = 0; i < capacity; i++)
    {
        page_table[i].x = -1;
    }

    printf("\nLRU:");
    printf("\n----\n");
    for (i = 0; i < n; i++)
    {
        flag = 1;
        if (i < capacity)
        {
            page_table[i].x = pages[i];
            page_table[i].y = temp++;
            p_f++;
        }

        else
        {
            for (j = 0; j < capacity; j++)
            {
                if (pages[i] == page_table[j].x)
                {
                    page_table[j].y = temp++;
                    flag = 0;
                    break;
                }
            }
            if (j == capacity)
            {
                int k, min = INT_MAX, m_i = 0;
                for (k = 0; k < capacity; k++)
                {
                    if (page_table[k].y < min)
                    {
                        min = page_table[k].y;
                        m_i = k;
                    }
                }

                page_table[m_i].x = pages[i];
                page_table[m_i].y = temp++;
                p_f++;
            }
        }
        int d;
        if (flag)
        {
            printf("\n");
            for (d = 0; d < capacity; d++)
            {
                printf("%d ", page_table[d].x);
            }
            printf(" Page fault\n");
        }
        else
        {
            printf("\n");
            for (d = 0; d < capacity; d++)
            {
                printf("%d ", page_table[d].x);
            }
            printf(" No page fault\n");
        }
    }

    return p_f;
}

int optimise(int pages[], int n)
{
    int i, j, p_f = 0, flag = 0;
    int size = 0;
    struct p_t table[50], page_table[capacity];

    for (i = 0; i < capacity; i++)
    {
        page_table[i].x = -1;
    }

    printf("\nOPTIMAL:");
    printf("\n--------\n");
    for (i = 0; i < n; i++)
    {
        if (i < capacity)
        {
            table[size].x = pages[i];
            table[size].y = 1;
            size++;
        }

        else
        {
            for (j = 0; j < size; j++)
            {
                if (table[j].x == pages[i])
                {
                    (table[j].y)++;
                    break;
                }
            }

            if (j == size)
            {
                table[size].x = pages[i];
                table[size].y = 1;
                size++;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        flag = 1;
        if (i < capacity)
        {
            page_table[i].x = table[i].x;
            page_table[i].y = table[i].y - 1;
            table[i].y = table[i].y - 1;
            p_f++;
        }

        else
        {
            for (j = 0; j < capacity; j++)
            {
                if (page_table[j].x == pages[i])
                {
                    page_table[j].y = page_table[j].y - 1;
                    flag = 0;
                    break;
                }
            }

            if (j == capacity)
            {
                int k, min = INT_MAX, m_i = 0;
                for (k = 0; k < capacity; k++)
                {
                    if (page_table[k].y < min)
                    {
                        min = page_table[k].y;
                        m_i = k;
                    }
                }

                for (k = 0; k < size; k++)
                {
                    if (pages[i] == table[k].x)
                    {
                        page_table[m_i].x = pages[i];
                        page_table[m_i].y = table[k].y - 1;
                        break;
                    }
                }
                p_f++;
            }
        }

        int d;
        if (flag)
        {
            printf("\n");
            for (d = 0; d < capacity; d++)
            {
                printf("%d ", page_table[d].x);
            }
            printf(" Page fault\n");
        }

        else
        {
            printf("\n");
            for (d = 0; d < capacity; d++)
            {
                printf("%d ", page_table[d].x);
            }
            printf(" No page fault\n");
        }
    }

    return p_f;
}

int main()
{
    int page_faults[3] = {0, 0, 0};
    int pages[25], n;

    printf("Enter capacity : ");
    scanf("%d", &capacity);
    printf("Enter number of pages : ");
    scanf("%d", &n);
    int i;
    printf("Enter the sequence : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    page_faults[0] = fifo(pages, n);
    page_faults[1] = least_recently_used(pages, n);
    page_faults[2] = optimise(pages, n);

    printf("\nFIFO:\nPage faults:%d\n\nLRU:\nPage faults:%d\n\nOPTIMAL:\nPage_faults:%d\n", page_faults[0], page_faults[1], page_faults[2]);

    return 0;
}
