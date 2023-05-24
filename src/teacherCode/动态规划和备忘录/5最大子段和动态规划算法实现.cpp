#include<stdio.h>
# define N 1000
int n=6;
int a[N]={-2,11,-4,13,-5,-2};
//6个元素的序列，
//求所有子段中，和值最大的子段的和 
int dp[N];//dp[i]记录以a[i]结尾的所有子段中的和值最大子段的和。
int maxdpindex;
int begin[N];//begin[i]记录以a[i]结尾的值最大子段起始元素的下标 
void solvedp(){	
	
	dp[0] = a[0];//dp[i]记录以a[i]结尾的所有子段中的和值最大子段的和。 
	begin[0]=0;
	if(dp[0]>=0) {		
		maxdpindex = 0;		
	}else {	
	    maxdpindex = -1;
	}
	
	for(int i=1;i<n;i++){
		if(dp[i-1]<=0) {		
		   dp[i] =a[i];
		   begin[i]=i;
		}
		else {		
		   dp[i] = dp[i-1]+a[i];
		   begin[i] = begin[i-1];
		}  
		if(dp[i]>=0 && maxdpindex==-1 || dp[i]>dp[maxdpindex]) {
	    	maxdpindex = i;
	    	//printf("%d",i); 
		}
	}

} 
int main(){
	solvedp();
	printf("%d\n",dp[maxdpindex]);
	printf("a%d --a%d之间的和值达到最大\n",begin[maxdpindex],maxdpindex); // 
}
