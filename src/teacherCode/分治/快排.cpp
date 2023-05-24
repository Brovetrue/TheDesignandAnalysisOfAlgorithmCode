#include<stdio.h>
#include<stdlib.h>
const int N =10;
int a[N] ={9,6,2,3,5,4,8,0,1,7};
int partition(int a[],int left,int right){//L1 0  L2 1

	int zou = a[left];//ѡ����ĵ�һ��Ԫ����Ϊ��Ԫ�� 
	int i=left+1;
	int j=right;
	while(i<=j){
		while(i<=j &&  a[i]<=zou)i++;//��ǰ���Ҵ�� 
		while(i<=j &&  a[j]>=zou)j--;//�ں�����С�� 
		if(i<j){		
			int t=a[i];
			a[i]=a[j]; //��С�ķ�ǰ��ȥ���ô�ķź���ȥ 
			a[j]=t;
		}
	}
	
	a[left]=a[j];
	a[j]=zou;//����Ԫ��վ���м� 
	return j;
	
} 
void quickSort(int a[], int left, int right){//
   //��õ����T(n) = 2T(n/2)+O(n) 
   //������T(n) = T(n-1)+O(n)
      if (left<right) {//������2��Ԫ��
            int q = partition(a,left,right);
            quickSort(a, left, q-1);//�� 
            quickSort(a, q+1, right);//��
            
      }
}

int main(){
	quickSort(a,0,N-1);
	for(int i=0;i<N;i++){
		printf("%d ",a[i]);
	}
}


