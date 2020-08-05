#include <stdio.h>
#include <stdlib.h>

//对单个组排序
int SortGroup(int* pnData, int nLen, int nBegin,int nStep)
{
    for (int i = nBegin + nStep; i < nLen; i += nStep)
    {
        //寻找i元素的位置，
        for (int j = nBegin; j < i; j+= nStep)
        {
            //如果比他小，则这里就是他的位置了
            if (pnData[i] < pnData[j])
            {
                int nTemp = pnData[i];
                for (int k = i; k > j; k -= nStep)
                {
                    pnData[k] = pnData[k - nStep];
                }
                pnData[j] = nTemp;
            }
        }
    }
    return 1;
}
//希尔排序, pnData要排序的数据， nLen数据的个数
int ShellSort(int* pnData, int nLen)
{
    //以nStep分组，nStep每次减为原来的一半。
    for (int nStep = nLen / 2; nStep > 0; nStep /= 2)
    {
        //对每个组进行排序
        for (int i = 0 ;i < nStep; ++i)
        {
            SortGroup(pnData, nLen, i, nStep);
        }
    }

    return 1;
}

int main()
{
    int nData[10] = {4,1,9,8,7,6,5,4,3,2};    //创建10个数据，测试
    ShellSort(nData, 10);        //调用希尔排序

    for (int i = 0; i < 10; ++i)        
    {
        printf("%d ", nData[i]);
    }

    printf("\n");
    system("pause");
    return 0;
}