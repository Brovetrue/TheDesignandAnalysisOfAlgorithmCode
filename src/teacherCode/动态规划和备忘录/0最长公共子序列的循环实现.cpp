#include<stdio.h>
#include<string.h>
const int N = 10001;
// BDCABA  ABCBDAB
char X[N];
char Y[N]; 
int n,m;
int dp[N+1][N+1];
void solvedp(){
	for(int i=1;i<=m;i++)
	   dp[0][i] = 0;
	for(int i=1;i<=n;i++)  
	   dp[i][0] = 0;
	for(int i=1;i<=n;i++){//o(N*M)
		for(int j=1;j<=m;j++){
			if(X[i-1]==Y[j-1])
			    dp[i][j] = dp[i-1][j-1]+1;
			    
			else{
				int m;
				if(dp[i-1][j]>=dp[i][j-1]){
					m=dp[i-1][j];
				}else{
					m=dp[i][j-1];
				}
				dp[i][j] = m;
				
			} 
		}
	}
	
}
void output(int a[][N+1]){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++)
		   printf("%3d",a[i][j]);
		printf("\n");
	}
}
void LCSoutput(){
	int i = n,j = m;
	while(dp[i][j]!=0){
		if(X[i-1]==Y[j-1]){
			printf("%c",X[i-1]);
			i = i-1;
			j = j-1;
		}else {
			if(dp[i-1][j]>=dp[i][j-1]){
				i = i-1;
				//j = j;
			}
			else {
				//i = i;
				j = j-1;
			}
		}
	}
}
int main(){
	scanf("%s%s",X,Y);
	n = strlen(X);
	m =strlen(Y);
	solvedp();
	printf("%d\n",dp[n][m]);
	output(dp); 
	printf("\n最长公共子序列的逆序：");
	
    LCSoutput(); 
}
