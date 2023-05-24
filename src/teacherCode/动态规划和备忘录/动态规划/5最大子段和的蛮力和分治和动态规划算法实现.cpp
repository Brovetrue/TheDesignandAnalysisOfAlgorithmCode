#include<stdio.h>
# define N 1000
int n=6;
int a[N]={-2,11,-4,13,-5,-2};
//6个元素的序列，
//求所有子段中，和值最大的子段的和 

 
int dp[N];//dp[i]记录以a[i]结尾的所有子段中的和值最大子段的和。

int maxsubsum1(int a[],int n){
	int max =0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int s=0;
			for(int k=i;k<=j;k++)
			  s+=a[k];
			if(s>max) max =s;
			
		}
	}
	return max;
}
int maxsubsum2(int a[],int n){
	int max =0;
	for(int i=0;i<n;i++){
	    int s=0;
		for(int j=i;j<n;j++){		
		    s+=a[j];
			if(s>max) max =s;			
		}
	}
	return max;
}
int maxsubsum3(int a[],int L,int R){
	if(L==R) {
		 if(a[L]<0) return 0;
		 else return a[L];
	}
	int mid = (L+R)/2;
	int m1=maxsubsum3(a,L,mid);
	int m2=maxsubsum3(a,mid+1,R);
	
	int s1=0;
	int left=0; 
	for(int i=mid;i>=L;i--) {
	   left+=a[i];
	   if(left>s1) s1=left;
	}
	   
	int s2 =0;//记录中间往后的最大
	int right=0;
	for(int i=mid+1;i<=R;i++){
	   right+=a[i];
	   if(right>s2) s2=right;
	}
	int m3 = s1+s2;
	int m=m1;
	if(m2>m) m=m2;
	if(m3>m) m=m3;
	return m;//max(m1,m2,m3);
}


int dp_maxsubsum(int a[],int n){
	int m;
	dp[0] = a[0];//dp[i]记录以a[i]结尾的所有子段中的和值最大子段的和。 
	if(dp[0]>0) m=dp[0];else m=0;
	for(int i=1;i<n;i++){
		if(dp[i-1]<=0) dp[i] =a[i];
		else dp[i] = dp[i-1]+a[i];
		if(dp[i]>m) m=dp[i];
	}
	return m;
} 
int main(){

	
	printf("%d\n",maxsubsum1(a,n));
	printf("%d\n",maxsubsum2(a,n));
	printf("%d\n",maxsubsum3(a,0,n-1));
	printf("%d\n",dp_maxsubsum(a,n));//哪一段呢？自行考虑实现 
}
