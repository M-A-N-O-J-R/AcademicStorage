#include <stdio.h>
#include <stdlib.h>
void seq(int files[])
{
    int len = 0, count = 0, startblk, i, j;
    printf("\n---Sequential File Allocation---\n");
    printf("Enter the file size: ");
    scanf("%d", &len);
    printf("Enter the starting block: ");
    scanf("%d", &startblk);
    for (i = startblk; i < (startblk + len); i++)
    {
        if (files[i] == 0)
        {
            count++;
        }
    }
    if (count == len)
    {
        for (j = startblk; j < (startblk + len); j++)
        {
            files[j] = 1;
            printf("%d\t%d\n", j, files[j]);
        }
        if (j != (startblk + len - 1))
        {
            printf("The file is allocated in the block\n\n");
        }
    }
    else
    {
        printf("The file is not allocated in the block\n\n");
    }
}

void indexed(int files[])
{
    int ind, count, index[50], len;
    int i, j, k;
    printf("\n---Indexed File Allocation---\n");
x:
    printf("Enter the index block: ");
    scanf("%d", &ind);
    if (files[ind] != 1)
    {
        printf("Enter the file size: ");
        scanf("%d", &len);
    }
    else
    {
        printf("%d index is already allocated\n", ind);
        goto x;
    }
y:
    count = 0;
    printf("Enter no of files for index %d on the disk:\n", len);
    for (i = 0; i < len; i++)
    {
        scanf("%d", &index[i]);
        if (files[index[i]] == 0)
        {
            count++;
        }
    }
    if (count == len)
    {
        for (j = 0; j < len; j++)
        {
            files[index[j]] = 1;
        }
        printf("File is Allocated in the given index\n");
        printf("File\tIndex\n");
        for (k = 0; k < len; k++)
        {
            printf(" %d----->%d:%d\n", ind, index[k], files[index[k]]);
        }
    }
    else
    {
        printf("Block in the index is already allocated\n");
        printf("Enter Another block index for file\n");
        goto y;
    }
    printf("\n");
}
int main()
{
    int files[50], i;
    for (i = 0; i < 50; i++)
    {
        files[i] = 0;
    }
    seq(files);
    indexed(files);
    return 0;
}
