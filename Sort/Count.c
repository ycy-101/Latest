#include <stdio.h>
#include <stdlib.h>

//计数排序
int CountSort(int* pData, int nLen)
{
    int* pCout = NULL;            //保存记数数据的指针
    pCout = (int*)malloc(sizeof(int) * nLen);    //申请空间
    //初始化记数为0
    for (int i = 0; i < nLen; ++i)
    {
        pCout[i] = 0;
    }

    //记录排序记数。在排序的值相应记数加1。
    for (int i = 0; i < nLen; ++i)
    {
        ++pCout[pData[i]];        //增
    }

    //确定不比该位置大的数据个数。
    for (int i = 1; i < nLen; ++i)
    {
        pCout[i] += pCout[i - 1];    //不比他大的数据个数为他的个数加上前一个的记数。
    }

    int* pSort = NULL;            //保存排序结果的指针
    pSort = (int*)malloc(sizeof(int) * nLen);    //申请空间

    for (int i = 0; i < nLen; ++i)
    {
        //把数据放在指定位置。因为pCout[pData[i]]的值就是不比他大数据的个数。
        //为什么要先减一，因为pCout[pData[i]]保存的是不比他大数据的个数中包括了
        //他自己，我的下标是从零开始的!所以要先减一。
        --pCout[pData[i]];    //因为有相同数据的可能，所以要把该位置数据个数减一。
        pSort[pCout[pData[i]]] = pData[i];        
        
    }

    //排序结束，复制到原来数组中。
    for (int i = 0; i < nLen; ++i)
    {
        pData[i] = pSort[i];
    }

    //最后要注意释放申请的空间。
    free(pCout);
    free(pSort);

    return 1;
}

int main()
{
    int nData[10] = {8,6,3,6,5,8,3,5,1,4};
    CountSort(nData, 10);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", nData[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}