#include<stdio.h>
const int n =6;

int q(int n,int m){//��ҿ���һ�£����������еĻ��� 
	if(n==1 || m==1){
		return 1;
	}else if( n< m)
	    return q(n,n);
	else if(n==m){
		return 1+q(n,n-1);
	}else{
		return q(n,m-1) + q(n-m,m);//
	}
	
	
}


int main(){
   printf("%d",q(n,n));	
}
