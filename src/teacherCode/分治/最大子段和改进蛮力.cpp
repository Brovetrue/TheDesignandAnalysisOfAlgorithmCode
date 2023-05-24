#include<stdio.h>
int N = 8;
int a[65]={1,-3,7,8,-4,12,-10,6};
int maxsubsum(int a[],int n){
	int max = 0;
	for(int i=0;i<n;i++){	 
	  int s = 0;//求ai开头到子段 和 
	  for(int j=i;j<n;j++){
	    s =s + a[j];
	    if(max<s)max =s;		
	  }
    }
	return max;
}
int main(){
	int m=maxsubsum(a,N);
	printf("%d",m);
	
}


