#include<stdio.h>
#include<stdlib.h>
#include<time.h>
const int N =10;
int a[N] ={9,6,2,3,5,4,8,0,1,7};
int partition(int a[],int left,int right){//L1 0  L2 1
    srand(time(NULL));
    int w =rand()%(right-left+1)+left;//?[0,right-left] +left
                                  //[left,right] 
								  rand()%100  ;[0 99]
								  rand()%100 +100;  [100 199]  
    int t =a[left];a[left]=a[w];a[w]=t;
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
int mink_th(int a[], int left, int right,int k)//T(n) = 2T(n/2)+O(n) 
{
	        if(left==right) return a[left];
      
            int q = partition(a,left,right);
            if(q+1 == k)  return a[q];
            else if(q+1 < k) return mink_th(a, q+1, right,k);//�� 
            else return mink_th(a, left, q-1,k);
            
     
}
int main(){
	int mk = mink_th(a,0,N-1,4);
	
		printf("%d ",mk);
	
}


