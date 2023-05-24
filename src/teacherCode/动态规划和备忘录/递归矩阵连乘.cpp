/*������ĸ��ֽ����������� 
     0111 1111 1111 1111 1111 1111 1111 1111 
   0x7fffffffʮ�����Ʊ�ʾ 
*/


#include<stdio.h>
const int inf = 0x7fffffff;
const int N =4;
int p[N+1]={30,35,15,5,10};

int mk[N+1][N+1];
int dp(int i,int j){//�Լ����ӱ��� 
	
	if(i==j) return 0;
	if(i+1==j) return p[i-1]*p[i]*p[i+1];
	int min=inf;
	
	for(int k=i;k<=j-1;k++){	
	   int d1 = dp(i,k);//�ݹ���� 
	   int d2 =  dp(k+1,j);//�ݹ���� 
	   int d = d1+d2+p[i-1]*p[k]*p[j];
	   if(d<min) min=d;
	}
	return min;
	
}

int main(){
	
	printf("%d\n",dp(1,N));//dp(1,4) 
} 
