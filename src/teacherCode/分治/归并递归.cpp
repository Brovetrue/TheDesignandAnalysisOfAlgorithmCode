#include<stdio.h>
#include<stdlib.h>
const int N =10;
int a[N] ={9,6,2,3,5,4,8,0,1,7};
merge(int a[],int L1,int R1,int L2,int R2){//L1 0  L2 1
	int i = L1;//�±ָ꣬�룬����ɨ���һ������ 
	int j = L2;//�±ָ꣬�룬����ɨ��ڶ������� 
	int k=L1;
	int *temp =	(int*)malloc(sizeof(int)*N);
	while(i<=R1&&j<=R2){//�������䶼û��ɨ���� 
		if(a[i]<=a[j]){//��С���temp������ 
			temp[k]=a[i];i++;
		}else{
			temp[k]=a[j];j++;
		}
		k++;
	}
	while(i<=R1){//��1������û��ɨ���꣬����2������һ��ɨ������		
		temp[k]=a[i];i++;		
		k++;
	}
	while(j<=R2){	//��2������û��ɨ���꣬����1������һ��ɨ������		
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
      if (left<right) {//������2��Ԫ��
            int mid=(left+right)/2;  //ȡ�е�,�� 
            mergeSort(a, left, mid);//�� 
            mergeSort(a, mid+1, right);//��
            merge(a, left, mid,mid+1 ,right);  //�ϲ�
      }
}
int main(){
	mergeSort(a,0,N-1);
	for(int i=0;i<N;i++){
		printf("%d ",a[i]);
	}
}


