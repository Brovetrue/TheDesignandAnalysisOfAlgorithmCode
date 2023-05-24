#include<stdio.h>
#include<stdlib.h>
const int N =10;
int a[N] ={9,6,2,3,5,4,8,0,1,7};
merge(int a[],int L1,int R1,int L2,int R2){//L1 0  L2 1
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
void mergeSort(int a[], int left, int right)//T(n) = 2T(n/2)+O(n) 
   {
      if (left<right) {//至少有2个元素
            int mid=(left+right)/2;  //取中点,分 
            mergeSort(a, left, mid);//治 
            mergeSort(a, mid+1, right);//治
            merge(a, left, mid,mid+1 ,right);  //合并
      }
}
int main(){
	mergeSort(a,0,N-1);
	for(int i=0;i<N;i++){
		printf("%d ",a[i]);
	}
}


