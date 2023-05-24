#include<stdio.h>
const int n=4;
int w[n+1] = {0,2,1,3,2};
int v[n+1]={0,12,10,20,15};
const int c =5;
int dp[n+1][c+1];

void solvedp(){
  for(int i=0;i<=n;i++)
     dp[i][0] = 0;   
  for(int j=0;j<=c;j++)
      dp[0][j]=0;
  for(int i=1;i<=n;i++){
  	for(int j=1;j<=c;j++) {
	   
	   // dp[i][j]=?
		if(w[i] >j	)dp[i][j]=dp[i-1][j];  
		else{
		  dp[i][j]=dp[i-1][j]>=dp[i-1][j-w[i]]+v[i]?dp[i-1][j]:dp[i-1][j-w[i]]+v[i];
		
		}
	}
  }
}
void trackPath(int i,int j){
	if(dp[i][j] == 0) return;
	
	if(dp[i][j]==dp[i-1][j]){
		//printf("物品%d不选\n",i);
		trackPath(i-1,j); 
	}else{
		printf("物品%d选\n",i);
		trackPath(i-1,j-w[i]); 
	}
	
}
int main(){
	solvedp();
	printf("%d\n",dp[n][c]) ;
	trackPath(n,c);
}
