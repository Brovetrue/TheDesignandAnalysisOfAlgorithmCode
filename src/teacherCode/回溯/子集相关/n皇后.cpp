#include<stdio.h>
int n=8;//4�ʺ����� 
int a[100];//a[i] ��¼���ŵĵ�i���ʺ���ڵ�i�е�a[i]�� 
void output(){
	for(int i=1;i<=n;i++)
	  printf("%3d",a[i]);
	printf("\n");  
}
int count=0; 
int  check(int i){
 //���Ե�i���ʺ��λ�ã�i,a[i]�� ��
 //ǰ���i-1���ʺ��λ�� ��1,a[1]�� ....... ��i-1,a[i-1]���Ƿ��ͻ�� 
 //��ͬ�У���ͬ���Խǣ���ͬ���Խ� 
    for(int j=1;j<=i-1;j++){
    	// ��i,a[i]��  ��j,a[j]�� 
    	if(a[i]==a[j]||i-a[i]==j-a[j]|| i+a[i]==j+a[j])return 0;
    	
	} 
	return 1;
}
void trackBackQueue(int i){	//���������ݣ�//pailie(1)    1 - i-1���Ѿ��ź��ˣ������ŵ�i�� 
	if(i==n+1){
		count++;
		return ;
	}	
	for(a[i] = 1;a[i]<=n;a[i]++){	
	    if(check(i)){	
		    //��֦����:Լ������	,�ٶ��£���Ƿ���		
			trackBackQueue(i+1)	;
		}	
    }
	return ; 
}
int main(){
	trackBackQueue(1);	
	printf("%d",count);	
	return 0;
} 
