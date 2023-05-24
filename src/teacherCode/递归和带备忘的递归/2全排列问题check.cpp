#include<stdio.h>
int n=3;
int a[100];//a[i] 记录安排的第i个数 
void output(){
	for(int i=1;i<=n;i++)
	  printf("%3d",a[i]);
	printf("\n");  
}
int check(int i){
	for(int j=1;j<=i-1;j++)
	  if(a[i]==a[j]) return 0;
	return 1;
}
void pailie(int i){	//前面的i-1个元素已经排好了，排第i个 
    if(i==n+1){
    	//已经排了n个了，输出结果 
    	output();
    	return ;
	}
	for(a[i]=1;a[i]<=n;a[i]++ ){
	    if(check(i)){	        
		   pailie(i+1); 		   	
		}		
	}	
			
	
}
int main(){
	pailie(1);	
	return 0;
} 
