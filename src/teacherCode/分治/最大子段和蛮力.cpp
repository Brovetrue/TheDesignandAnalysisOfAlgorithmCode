#include<stdio.h>
int N = 8;
int a[65]={1,-3,7,8,-4,12,-10,6};
int maxsubsum(int a[],int n){
	int max = 0;
	for(int i=0;i<n;i++){	 
	  for(int j=i;j<n;j++){
	    int s =0;
	    for(int k=i;k<=j;k++){//[i,j]µ½ºÍÖµ
	       s+=a[k];
		} 
		if(max<s)max =s;
	}
	return max;
}
int main(){
	int m=maxsubsum(a,N);
	printf("%d",m);
	
}


