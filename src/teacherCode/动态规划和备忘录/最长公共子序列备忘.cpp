#include<stdio.h>
#include<string.h>
const int N = 1001;
char X[N];
char Y[N] ;//最多处理1000的序列 
int n,m;//记录X 和Y中序列的长度 
int memory[N+1][N+1];//全部初始化成-1
int dp(int i,int j){//dp(6,7)
    if(memory[i][j]!=-1) return memory[i][j];
	if(i==0||j==0) return memory[i][j]=0;
	if(X[i-1]==Y[j-1])  return memory[i][j]=dp(i-1,j-1)+1;
	else {
	  int d1 =dp(i-1,j);
	  int d2= dp(i,j-1)	
	  memory[i][j]= d1>=d2?d1:d2
	  return memory[i][j]= d1>=d2?d1:d2;	//会不会出现重复计算 
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
