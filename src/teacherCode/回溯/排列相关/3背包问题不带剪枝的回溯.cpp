#include<stdio.h>
#define N 100
int n=3;
int w[N]={0,1,2,3};
int v[N]={0,6,10,12};
int C =5;
int choose[N];//ѡ��ı�� 
int bestchoose[N];
int bestV=0;
//�Ӽ�������㷨���2 
void backtrack2(int i){//�Ѿ���ǰi-1��Ԫ������ѡ�����ڶԵ�i��Ԫ����ѡ�� 
    
	if(i==n+1){ //�ݹ���ڣ��ڵ�i�ǵݹ����е�Ҷ�ӽڵ�
    	//printsub();
    	int sumW=0;
    	int sumV=0;
    	for(int i=1;i<=n;i++){
    		if(choose[i]==1){
    			sumW += w[i];
    			sumV+=v[i];
			}
		}
		if(sumW<=C){
			if(sumV >bestV){
				bestV =sumV;
			    //copy(bestchoose,choose);
			    for(int i=1;i<=n;i++){
			    	bestchoose[i]=choose[i];
				} 
			}
		}
    	return ;
	}
	
	choose[i]=0;//��ѡ��i��Ԫ�� 
	backtrack2(i+1);	
	
	choose[i]=1;//ѡ��i��Ԫ�� 
	backtrack2(i+1);
	
		
} 

int main(){
    //sub(); ֻ�ܴ�������Ԫ�ص��Ӽ� 
	backtrack2(1);
	printf("%d",bestV);
}
