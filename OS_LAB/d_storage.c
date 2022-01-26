#include <stdio.h>
void bestfit(int no_mem, int no_pro, int mem[], int pro[])
{
    void sort(int mem[], int no_mem)
    {
        int a;
        for (int i = 0; i < no_mem; i++)
        {
            for (int j = i + 1; j < no_mem; j++)
            {
                if (mem[j] < mem[i])
                {
                    a = mem[i];
                    mem[i] = mem[j];
                    mem[j] = a;
                }
            }
        }
    }
    int i, j, temp_mem[20], dup_mem[20];
    for (i = 0; i < no_mem; i++)
    {
        dup_mem[i] = mem[i];
    }
    sort(dup_mem, no_mem);
    for (int i = 0; i < no_pro; i++)
    {
        for (int j = 0; j < no_mem; j++)
        {
            if (dup_mem[j] > pro[i])
            {
                temp_mem[j] = dup_mem[j];
                dup_mem[j] = dup_mem[j] - pro[i];
printf("\n%d KB process is put in %dKB\n",pro[i],temp_mem[j]); 
printf("Size of Hole after assigning process:%dKB\n",dup_mem[j]); 
break;
            }
            if (j == no_mem - 1)
            {
                printf("\n%dKB must wait\n", pro[i]);
            }
        }
    }
}
void firstfit(int n_m, int n_p, int memory[], int process[])
{
    int memory_left[20];
    for (int i = 0; i < n_m; i++)
    {
        memory_left[i] = memory[i];
    }
    for (int i = 0; i < n_p; i++)
    {
        int j, flag = 0;
        for (j = 0; j < n_m; j++)
        {
            if (memory_left[j] >= process[i])
            {
                printf("%dKB process assigned to memory %dKB\n", process[i], memory_left[j]);
                memory_left[j] -= process[i];
                printf("Size of Hole after assigning the process:%dKB\n", memory_left[j]);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("\n%dKB should wait\n", process[i]);
    }
}
void worstfit(int b, int p, int blocks[], int process[])
{
    int max_sort(int blocks[], int b)
    {
        int temp;
        for (int i = 0; i < b; i++)
        {
            for (int j = i + 1; j < b; j++)
            {
                if (blocks[i] < blocks[j])
                {
                    temp = blocks[i];
                    blocks[i] = blocks[j];
                    blocks[j] = temp;
                }
            }
        }
    }
    int flag, i, j, temp_blocks[30];
    for (i = 0; i < b; i++)
    {
        temp_blocks[i] = blocks[i];
    }
    printf("\nWorst Fit:\n");
    for (int i = 0; i < p; i++)
    {
        max_sort(temp_blocks, b);
        flag = -1;
        for (int j = 0; j < b; j++)
        {
            if (temp_blocks[j] >= process[i])
            {
                if (flag == -1)
                {
                    flag = j;
                }
            }
        }
        if (flag != -1)
        {
            printf("\nThe process of size %dKB has been assigned to block %dKB\n", process[i], temp_blocks[flag]);
            temp_blocks[flag] -= process[i];
            printf("Size Of hole after assigning the process: %dKB\n", temp_blocks[flag]);
        }
        else
        {
            printf("\nThe process of size %dKB is in wait state\n", process[i]);
        }
    }
}
int main()
{
    int choice, b, p, blocks[30], processes[30];
    printf("\nEnter the number of blocks:");
    scanf("%d", &b);
    for (int i = 0; i < b; i++)
    {
        printf("\n\tEnter the value of block %d in KB:", i + 1);
        scanf("%d", &blocks[i]);
    }
    printf("\nEnter the number of processes:");
    scanf("%d", &p);
    for (int i = 0; i < p; i++)
    {
        printf("\n\tEnter value of process %d in KB:", i + 1);
        scanf("%d", &processes[i]);
    }
    printf("\nChoose an algorithm:");
    printf("\n1.Best fit\n2.First Fit\n3.Worst Fit\n4.Exit");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        printf("\n");
        if (choice == 1)
        {
            bestfit(b, p, blocks, processes);
        }
        if (choice == 2)
        {
            firstfit(b, p, blocks, processes);
        }
        if (choice == 3)
        {
            worstfit(b, p, blocks, processes);
        }
    } while (choice <= 3);
    return 0;
}
