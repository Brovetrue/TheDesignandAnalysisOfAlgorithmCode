#include<stdio.h>
#include<string.h>
const int N = 10001;
// BDCABA  ABCBDAB
char X[N];
char Y[N]; 
int n,m;
int memory[N+1][N+1];// -1  
int dp(int i,int j){
	
	if(memory[i][j]!=0)return memory[i][j];
	
	if(i==0||j==0) return memory[i][j]=0;
	if(X[i-1]==Y[j-1]){
		return memory[i][j]= dp(i-1,j-1)+1;
	}else{
		int d1 =dp(i-1,j);
		int d2 =dp(i,j-1);
		int m = d1>=d2?d1:d2;
		return memory[i][j]=m;
	}
}
void LCSoutput(int i,int j){
    
       
       if(memory[i][j]==0) return;
       if(X[i-1]==Y[j-1]){
       	   LCSoutput(i-1,j-1);
       	   printf("%c",X[i-1]);
	   }else {
	   	   if(dp[i-1][j]>=dp[i][j-1]){
	   	   	  LCSoutput(i-1,j);
		   }
		   else{
		   	  LCSoutput(i,j-1);
		   }
	   }




}
int main(){
	scanf("%s%s",X,Y);
	n = strlen(X);
	m =strlen(Y);
	//solvedp();
	printf("%d\n",dp(n,m));	
	
    LCSoutput(n,m);; 
}
