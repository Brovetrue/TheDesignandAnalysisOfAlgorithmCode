#include<stdio.h>
#include<string.h>
const int N = 1001;
char X[N];
char Y[N] ;//��ദ��1000������ 
int n,m;//��¼X ��Y�����еĳ��� 
int memory[N+1][N+1];//ȫ����ʼ����-1
int dp(int i,int j){//dp(6,7)
    if(memory[i][j]!=-1) return memory[i][j];
	if(i==0||j==0) return memory[i][j]=0;
	if(X[i-1]==Y[j-1])  return memory[i][j]=dp(i-1,j-1)+1;
	else {
	  int d1 =dp(i-1,j);
	  int d2= dp(i,j-1)	
	  memory[i][j]= d1>=d2?d1:d2
	  return memory[i][j]= d1>=d2?d1:d2;	//�᲻������ظ����� 
	}
}
int main(){
   scanf("%s%s",X,Y);
   //BDCABA   
   //ABCBDAB
   n = strlen(X);m = strlen(Y);
   //solvedp();	
   printf("%d\n",dp(n,m));
   MLsubStr();
}
