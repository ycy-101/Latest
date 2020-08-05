#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int BubbleSort(char *pData,int len)
{//冒泡排序，pData 是待排序的数组，len是数组的长度
	bool isOk=false;//这是一个优化，标志数组是否有序
	for(int i=0;i<len-1&&!isOk;i++)//外层循环控制起泡循环的次数
	{
		isOk=true;//初始化为有序的
		for(int j=len-1;j>i;j--)//从最后一个元素开始,一次循环的结果是使第i小的元素出现在第i个位置上
		{
			if(pData[j]<pData[j-1])//如果第j-1个元素比第j个元素小，则交换.
			{
				int temp=pData[j];
				pData[j]=pData[j-1];
				pData[j-1]=temp;
				isOk =false;//有交换发生，说明数组是无序的，即排序没有完成.
			}
		}
	}
	printf("%d\n",isOk);
	for(int i=0;i<len;i++){
	printf("%c",pData[i]);
	}
	return 1;
}
int main(){
	char pData[]="8495";
	int len=strlen(pData);
	BubbleSort(pData,len);
	return 0;
	
}