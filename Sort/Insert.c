#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  insert_sort(char array[],int length){
   int temp;
   for(int i=0;i<length-1;i++){
       for(int j=i+1;j>0;j--){
           if(array[j] < array[j-1]){
               temp = array[j-1];
               array[j-1] = array[j];
               array[j] = temp;
           }else{         //不需要交换
               break;
           }
       }
   }
}
int main(){
	char array[]="34934678";
	int length=strlen(array);
	insert_sort(array,length);
	for(int i=0;i<length;i++){
		printf("%c",array[i]);
	}
	return 0;	
}