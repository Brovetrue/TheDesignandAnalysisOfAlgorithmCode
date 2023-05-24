#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
const int N =10;
int a[N] ={9,6,2,3,5,4,8,0,1,7};
void merge(int a[],int L1,int R1,int L2,int R2){//L1 0  L2 1
	int i = L1;//下标，指针，用来扫描第一个区间 
	int j = L2;//下标，指针，用来扫描第二个区间 
	int k=L1;
	int *temp =	(int*)malloc(sizeof(int)*N);
	while(i<=R1&&j<=R2){//两个区间都没有扫描完 
		if(a[i]<=a[j]){//把小的填到temp数组中 
			temp[k]=a[i];i++;
		}else{
			temp[k]=a[j];j++;
		}
		k++;
	}
	while(i<=R1){//第1个区间没有扫描完，但第2个区间一定扫描完了		
		temp[k]=a[i];i++;		
		k++;
	}
	while(j<=R2){	//第2个区间没有扫描完，但第1个区间一定扫描完了		
		temp[k]=a[j];j++;		
		k++;
	}
	//temp->a
	for(int i=L1;i<=R2;i++){
		a[i]= temp[i];
	}
	free(temp);
} 
void mergeSort(int a[],int n){	
   int len=1;
   while(len<n){   
		//待归并区间的长度 
		int L1=0;
		int L2=L1+len;
		while(L2<=n-1){//保证有两个相邻的区间 
			if(L2+len-1 <= n-1) {//第二个区间长度也是len		
			   merge(a,L1,L2-1,L2,L2+len-1);
			}else if(L2 <= n-1) {//第二个区间长度 < len
			    merge(a,L1,L2-1,L2,n-1);
			    break; 
		    }
		    else{
		    	break;
			}
			L1 = L1+2*len;//下一个相邻区间的起始 
			L2 = L1+len;
		}
		len = len*2;//1  2  4   8   
	}	
	
} 
int main(){
	mergeSort(a,N);
	for(int i=0;i<N;i++){
		printf("%d ",a[i]);
	}
}
