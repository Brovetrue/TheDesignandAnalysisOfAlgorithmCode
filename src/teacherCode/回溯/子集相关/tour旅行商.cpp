#include<stdio.h>
int n=8;//
int adj[N][N];//��ͼ 
int a[100] = {0,2};// 
void output(){
	for(int i=1;i<=n;i++)
	  printf("%3d",a[i]);
	printf("\n");  
}
int count=0; 
int  check(int i){
     //1  a[i] ��Ӧ�Ķ����Ƿ���ֹ���  
	 //2   a[i]  a[i-1] ֮���Ƿ��б� 
}
void trackBackQueue(int i){	//���������ݣ�//pailie(1)    1 - i-1���Ѿ��ź��ˣ������ŵ�i�� 
	if(i==n+1){
		//��ǰ������·�ĳ��ȣ����Ƿ���Ŀǰ�����· 
		return ;
	}	
	for(a[i] = 1;a[i]<=n;a[i]++){	
	    if(check(i)){	
		    //��֦����:		
			trackBackQueue(i+1)	;
		}	
    }
	return ; 
}
int main(){
	trackBackQueue(2);	
	printf("%d",count);	
	return 0;
} 
