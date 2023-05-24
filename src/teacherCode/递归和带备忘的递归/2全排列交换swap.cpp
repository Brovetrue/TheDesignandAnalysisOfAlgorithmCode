#include<stdio.h>
const int n=3;
int a[n+1]={0,1,2,3} ;
void output(){
	for(int i=1;i<=n;i++){
		printf("%d",a[i]);
		
	}printf("\n");
}
void pailie(int k){//n
        //   k 
	if(k==n){output();return ;}
	for(int j=k;j<=n;j++){
		 int t=a[k];a[k]=a[j];a[j]=t;//交换
		 pailie(k+1);
		 t=a[k];a[k]=a[j];a[j]=t;
		 //大家把这句交换删了看什么情况 
		 //交换 :回溯 
	}
}
int main(){ 
    pailie(1);  //T(n)= nT(n-1) T(n)=n*n!
	            // T(1)=n  
				//=>T(n)=n*n!
		
}
