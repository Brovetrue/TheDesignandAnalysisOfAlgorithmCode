#include<stdio.h>
# define N 1000
int n=6;
int a[N]={-2,11,-4,13,-5,-2};
//6��Ԫ�ص����У�
//�������Ӷ��У���ֵ�����Ӷεĺ� 
int dp[N];//dp[i]��¼��a[i]��β�������Ӷ��еĺ�ֵ����Ӷεĺ͡�
int maxdpindex;
int begin[N];//begin[i]��¼��a[i]��β��ֵ����Ӷ���ʼԪ�ص��±� 
void solvedp(){	
	
	dp[0] = a[0];//dp[i]��¼��a[i]��β�������Ӷ��еĺ�ֵ����Ӷεĺ͡� 
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
	printf("a%d --a%d֮��ĺ�ֵ�ﵽ���\n",begin[maxdpindex],maxdpindex); // 
}
