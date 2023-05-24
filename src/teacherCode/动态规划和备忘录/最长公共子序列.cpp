#include<stdio.h>
const int N = 1000;
int n = 8;
int a[N]={1,7,2,8,3,6,4,5};
int dp[N];
int pre[N];
int maxdpindex;
void solvedp(){	
	dp[0] = 1;
	pre[0]=-1;
	maxdpindex=0;
	for(int i=1;i<n;i++){	 
		int max =0;
		int w =-1;//dp[i]=?;
		for(int j=i-1;j>=0;j--){	
			if(a[j]<=a[i]) {
				if(dp[j]>max) {
				   max  = dp[j]; 
				   w = j;
				} 
			}
		}	
		dp[i] =  max + 1;
		pre[i] = w;
		if(dp[i] > dp[maxdpindex]){
			maxdpindex = i;
		}
	}	
}
void track(int i){
	if(pre[i]==-1){
		printf("%d ",a[i]);
		return ;
	}
	track(pre[i]);
	printf("%d ",a[i]);
}
int main(){
	//inputn();
	//inputa();
	solvedp();
	printf("最长递增子序列的长度：%d\n",dp[maxdpindex]);// 
	
	track(maxdpindex);// 
}
