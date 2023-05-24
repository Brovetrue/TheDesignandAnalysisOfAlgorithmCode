#include<stdio.h>
const int N = 1000;
int n = 8;
int a[N]={};
int dp[N];
int max =0;
void solvedp(){	
	dp[0] =a[0];
	if(max<dp[0]){
		max =dp[0];
	}
	for(int i=1;i<n;i++){	
		if(dp[i-1]>0)
		   dp[i]  = dp[i-1]+a[i];
		else dp[i] =a[i];
		
		if(max<dp[i]){
			max = dp[i];
		}
	}
}

int main(){
	inputn();
	inputa();
	solvedp();
	printf("最大子段和：%d",max);
}
