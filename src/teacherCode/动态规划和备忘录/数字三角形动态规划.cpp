#include<stdio.h>
const int N = 64;
int n = 5;
/*
9
12  15
10  6   8
2   18  9   5
19  7   10  4   16
*/ 
int data[N+1][N+1];
int dp[N+1][N+1];
void input(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
		   scanf("%d",&data[i][j]);
	}
}
void solvedp(){
	for(int i=1;i<=n;i++)
	   dp[n][i] = data[n][i];
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=i;j++){
			int m ;
			if(dp[i+1][j]>=dp[i+1][j+1]){
				m =dp[i+1][j];
			}
			else {
				m =dp[i+1][j+1];
			}
			dp[i][j] = data[i][j]+m;
		}
	}
	
}
void output(int a[][N+1]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
		   printf("%3d",a[i][j]);
		printf("\n");
	}
}
void path(){
	int i=1,j=1;
	printf("path:%3d",data[i][j]);
	while(i<n){
		if(dp[i+1][j]>=dp[i+1][j+1])
		  j=j;
		else j = j+1;
		i=i+1;
		printf("%3d",data[i][j]);
	}
}
int main(){
	input();//data‘ÿ»Î 
	solvedp();
	printf("%d\n",dp[1][1]);
	output(dp); 
	printf("\n");
	output(data);
	path(); 
}
