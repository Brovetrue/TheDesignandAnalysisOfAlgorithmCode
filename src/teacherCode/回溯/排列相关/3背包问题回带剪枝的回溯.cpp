#include<stdio.h>
const int N =100;
int n=3;
int w[N]={0,1,2,3};
int v[N]={0,6,10,12}; 
int C = 5;
int bestV;
int choose[N];//choose[i] =1 ��ʾ��i��Ԫ�����Ӽ��У� choose[i] =0��ʾ��i��Ԫ�ز����Ӽ��� 
int bestchoose[N];
int curW=0;
int curV=0;
void trackBack(int i,int ub){//���������� 1 - i-1���Ѿ�����ѡ�����ڶԵ�i����ѡ�� 
	if(i==n+1){//4
		//�жϵ�ǰ�Ľ��Ƿ��ǿ��н⣬����ǿ������ж��Ƿ���Ŀǰ������
		//if(curV>bestV){
		bestV = curV;
		
		for(int i=1;i<=n;i++){
	       bestchoose[i]= choose[i];
        }	    
        //��return ������Բ���else 
	}else{		
		
		if(curW + w[i]<=C){	//��֦:	Լ�� 
		    choose[i]=1;
			curW += w[i];//��ȥǰ��	
			curV += v[i];		
			trackBack(i+1,ub);	
			curW -= w[i];//������ʱ��Ҫ���� 
			curV -= v[i];
		}
			
		choose[i]=0;
		if(ub-v[i]>bestV){	//��֦: �磨�ϣ�						
			trackBack(i+1,ub-v[i]);	
		}
			
		
	} 
}
main(){
	//scanf("%d",&n); //4
	int sumV =28;
	trackBack(1,sumV);
	printf("%d\n",bestV);
	for(int i=1;i<=n;i++)
	  printf("%d",bestchoose[i]);
	//dfs(1);
} 
