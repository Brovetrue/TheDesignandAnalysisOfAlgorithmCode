#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
const int N =10;
int a[N] ={9,6,2,3,5,4,8,0,1,7};
void merge(int a[],int L1,int R1,int L2,int R2){//L1 0  L2 1
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
void mergeSort(int a[],int n){	
   int len=1;
   while(len<n){   
		//���鲢����ĳ��� 
		int L1=0;
		int L2=L1+len;
		while(L2<=n-1){//��֤���������ڵ����� 
			if(L2+len-1 <= n-1) {//�ڶ������䳤��Ҳ��len		
			   merge(a,L1,L2-1,L2,L2+len-1);
			}else if(L2 <= n-1) {//�ڶ������䳤�� < len
			    merge(a,L1,L2-1,L2,n-1);
			    break; 
		    }
		    else{
		    	break;
			}
			L1 = L1+2*len;//��һ�������������ʼ 
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
