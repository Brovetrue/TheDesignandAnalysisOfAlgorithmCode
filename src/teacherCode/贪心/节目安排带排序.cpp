#include<stdio.h>
#include<algorithm>//1 �������ͷ 
using namespace std;//1 �������ͷ
const int N = 100;
int n =11;
struct jiemu{
	int start;
	int end;
	friend bool operator<(jiemu a,jiemu b){//2 ָ������ʽ 
	    return a.end<b.end;
	}
}; 
jiemu arr[N]={{5,7},{3,8},{5,9},{6,10},{8,11},
			  {8,12},{2,13},{12,14},{1,4},{3,5},{0,6}};
int Count=0;
void arrange(){
   printf("%d - %d\n",arr[0].start,arr[0].end)	;
   Count ++;
   int j =0;//��¼�ոձ����ŵĽ�Ŀ��� 
   for(int i=1;i<n;i++){
   	   if(arr[i].start >= arr[j].end ){
   	   	     printf("%d - %d\n",arr[i].start,arr[i].end)	;
   	   	     Count++;
			 j =i; 
		}
   }
   printf("count==%d\n",Count);
}
int main(){
   sort(arr,arr+n);//3 �������� 
   arrange();

    return 0;
}

