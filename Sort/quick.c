#include <stdio.h>
#include <stdlib.h>

//化分区间,找到最后元素的排序位置。并返回分隔的点（即最后一数据排序的位置）。
//划分的区间是[nBegin, nEnd). pData是保存数据的指针
int Partition(int* pData, int nBeging, int nEnd)
{
    int i = nBeging - 1;    //分隔符号，最后nD保存在这里
    --nEnd;
    int nD = pData[nEnd]; //比较的数据。
    int nTemp; // 交换用的临时数据

    //遍历数据比较，找到nD的位置，这里注意，比较结果是,
    //如果i的左边是小于等于nD的，i的右边是大于nD的
    for (int j = nBeging; j < nEnd; ++j)
    {
        if (pData[j] <= nD)        //如果数据比要比较的小，则在该数据的左边，与i+1交换
        {
            ++i;                //小于nD的数据多一个，所以要加1，i的左边数据都比nD小
            nTemp = pData[i];    //交换数据
            pData[i] = pData[j];
            pData[j] = nTemp;
        }
    }

    //最后不要忘了吧nD和i+1交换，因为这里就是nD的位置咯。
    ++i;
    pData[nEnd] = pData[i];
    pData[i] = nD;

    return i;   //返回nD的位置，就是分割的位置。
}

//排序的递归调用。
int QuickSortRecursion(int* pData, int nBeging, int nEnd)
{
    if (nBeging >= nEnd -1)        //如果区域不存在或只有一个数据则不递归排序
    {
        return 1;
    }

    //这里因为分割的时候，分割点处的数据就是排序中他的位置。
    //也就是说他的左边的数据都小于等于他，他右边的数据都大于他。
    //所以他不在递归调用的数据中。
    int i = Partition(pData, nBeging, nEnd);        //找到分割点
    QuickSortRecursion(pData, nBeging, i);            //递归左边的排序
    QuickSortRecursion(pData, i + 1, nEnd);            //递归右边的排序
    return 1;
}

//快速排序
int QuickSort(int* pData, int nLen)
{
    //递归调用，快速排序。
    QuickSortRecursion(pData, 0, nLen);
    return 1;
}
int main()
{
    int nData[11] = {5,9,3,2,1,6,20,45,88,75,10};        //测试数据
    QuickSort(nData, 11);            //调用快速排序
	printf("排序后：");
    for (int i = 0; i < 11; ++i)        //输出结果
    {	
        printf("%d ", nData[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}