#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int SelectSort(char *pData,int num)
{//选择排序，pData是待排序数组，num是数组的长度
 
	for (int i=0;i<num-1;i++)//控制循环次数 num-1次循环即可得到有序序列
	{
		int index=i;//初始化最小元素的下标
		for(int j=i+1;j<num;j++)//从i+1个位置开始
		{
			if(pData[j]<pData[index])//如果有比当前最小值更小的元素，更新指向最小元素的索引
				index=j;
		}//循环结束后，index指向的是无序区最小元素的索引
		if(index!=i)//如果第i个元素不是当前循环最小元素，则交换
		{
			int temp=pData[i];
			pData[i]=pData[index];
			pData[index]=temp;
		}
	}
	for(int i=0;i<num;i++){
	printf("%c",pData[i]);
	}
	return 1;
}
int main(){
	char pData[]="8493650";
	int num=strlen(pData);
	SelectSort(pData,num);
	return 0;
	
}
