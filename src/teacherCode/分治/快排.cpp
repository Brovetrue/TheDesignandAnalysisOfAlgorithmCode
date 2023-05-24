#include<stdio.h>
#include<stdlib.h>
const int N =10;
int a[N] ={9,6,2,3,5,4,8,0,1,7};
int partition(int a[],int left,int right){//L1 0  L2 1

	int zou = a[left];//选区间的第一个元素作为轴元素 
	int i=left+1;
	int j=right;
	while(i<=j){
		while(i<=j &&  a[i]<=zou)i++;//在前面找大的 
		while(i<=j &&  a[j]>=zou)j--;//在后面找小的 
		if(i<j){		
			int t=a[i];
			a[i]=a[j]; //让小的放前面去，让大的放后面去 
			a[j]=t;
		}
	}
	
	a[left]=a[j];
	a[j]=zou;//让轴元素站到中间 
	return j;
	
} 
void quickSort(int a[], int left, int right){//
   //最好的情况T(n) = 2T(n/2)+O(n) 
   //最坏的情况T(n) = T(n-1)+O(n)
      if (left<right) {//至少有2个元素
            int q = partition(a,left,right);
            quickSort(a, left, q-1);//治 
            quickSort(a, q+1, right);//治
            
      }
}

int main(){
	quickSort(a,0,N-1);
	for(int i=0;i<N;i++){
		printf("%d ",a[i]);
	}
}


