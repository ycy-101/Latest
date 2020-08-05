#include <stdio.h>
#include <stdlib.h>
 
typedef struct node {
	int num;
	struct node *next;
}KeyNode;
 
void bucket_sort(int a[],int size,int bucket_size) {
	int i,j;
    //这是一个结构体指针的数组，数组内都是指针，还要分配内存，为结构体指针数组分配大小为bucket_size的内存空间
	//使用二维指针表示二维数组，动态分配内存空间
	KeyNode **bucket_num = (KeyNode **)malloc(bucket_size * sizeof(KeyNode*));    //分配行所用的空间
	for(i = 0;i < bucket_size;i++) {
		bucket_num[i] = (KeyNode*)malloc(sizeof(KeyNode));      //为每个桶分配内存空间，分配列所用的空间
		bucket_num[i]->num = 0;   //记录当前桶中的数量，初始化桶中数量为0
		bucket_num[i]->next = NULL;   //为结构体中的结构体指针变量初始化为空
	}
	for(j = 0;j < size;j++) {
		KeyNode *node = (KeyNode *)malloc(sizeof(KeyNode));     //定义一个结构体变量的指针
		node->num = a[j];    
		node->next = NULL;
		int index = a[j]/100;  //映射函数计算桶号
		KeyNode *p = bucket_num[index];   //初始化P成为桶中数据链条的头指针
        //该桶中还没有数据
		if(p->num == 0) 
        {
			bucket_num[index]->next = node;
			(bucket_num[index]->num)++;
		}else
        {
            //链表结构的插入排序
			while(p->next != NULL && p->next->num <= node->num)
			{
				p = p->next;
			}	
			node->next = p->next;
			p->next = node;
			(bucket_num[index]->num)++;
		}
	}
	//打印结果
	KeyNode * k = NULL;  //定义一个空的结构体指针用于储存输出结果
	for(i = 0;i < bucket_size;i++)
    {
        for(k = bucket_num[i]->next;k!=NULL;k=k->next)
        {
            printf("%d ",k->num);
        }			
    }		
	printf("\n");
}
 
 
int main()
{
	int a[]= {491,381,615,917,716,13,217,419,19,138,61,917,176,113,27,419,419,38,615,917,16,113,217,419};
	int size = sizeof(a)/sizeof(int);    //计算数组长度
	bucket_sort(a,size,10);
    system("pause");   //防止控制台闪退
}