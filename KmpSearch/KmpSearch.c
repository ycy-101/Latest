#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>  

//pattern是现有的模式串，prefix是要求的初代前缀表，n是串的长度
void  prefix_table(char  pattern[],int  prefix[],int  n){
	prefix[0]=0;
	int  len  =0;//len，是用来比较的长度
	int  i=1;//用来标是当前所求的位置下标
	while(i<n){
		if(pattern[i]==pattern[len]){
			//len就是上一次求完之后的公共串长度，判断pattern[len]和现在位置是否相同
			len++;//长度加1
			prefix[i]=len;//当前的前缀表数据就是加1之后的len
			i++;//往后移动一位
									}
		else  {
		//这里就是我们发现两个不相同时的情况。
		//为了防止出现我们求prefix[1]的时候访问到pattern[-1]
		if(len>0){
			len  =  prefix[len-1];//正常情况错位更新len
					}
		else  {
			prefix[i]=len;//这里len就是0
			i++;
				}
				}
			}
	//现在实现移位  
	for(i=n-1;i>0;i--){
		prefix[i]=prefix[i-1];
						}
		prefix[0]=-1;
}
int  kmp_search(char  text[],char  pattern[]){
	//主串text，模式串pattern  
	int  n=strlen(pattern);
	int  m=strlen(text);
	int  *prefix=(int  *)malloc(sizeof(int)*n);//建立一个前缀表数组，也即是next数组  
	prefix_table(pattern,prefix,n);//调用建立前缀表数组函数  
	int  i=0,j=0,flag=0;  
	while(i<m){
		if(j==n-1&&text[i]==pattern[j])  {
			printf("We  find  it  in  %d\n",i-j);//输出模式串在主串中的位置  
			flag=1;  
			j=prefix[j];//匹配成功  ,我们可以直接退出，当然有些主串和模式串并不只在一个地方包含  
										}
		if(text[i]==pattern[j]){//正常匹配，往后+就行  
						i++;
						j++;
				}
		else  {//匹配失败，失配位和前缀表中数据所指的项对齐  
		j=prefix[j];
		if(j==-1){
			//这就是我们访问到了那个开头的-1，这个时候，我们当然是让模式串往后移动一格，并且和主串的下一个元素匹配  
			i++;
			j++;
				}
			}
			}
		if(flag==1){
			return  1;
		}
	}
int  main()
{
	FILE  *fp=fopen("Android.log","r");
	if(fp==NULL)
	{
		printf("错误");
		return  0;
	}

	char  text[1024];
	while(fgets(text,sizeof(text),fp))
	{
		char  pattern[]="CameraService::connect";
		int  n=0;
		n=kmp_search(text,pattern);
	if(n==1)
	{
		printf("%s  \n",text);
	}
	}
		fclose(fp);
		return  0;
	}