#include<stdio.h>
const int n=3;
int w[n+1]={0,14,15,15}; 
int upbound[n+1]= {44,30,15,0}; 
//upbound[i]:�����i+1����Ʒ����n����Ʒ�ܵ����� ,
//��ʣ���ȫ�����봬1,
//��ѡ�Ļ���curP+upbound[i]��Ϊ�Ͻ� 
int C1 =30;
int C2=35; 
int choose[n+1];//choose[i]=1�����Ӽ��к���a[i],=0���벻��a[i]
int bestchoose[n+1];
int maxW=0;
int curW = 0; 
void dfs(int i){
	if(i==n+1){
		if(curW>maxW){
			maxW = curW;
			
		   // bestchoose<=choose ��¼���ŵ�װ�ط��� 
		}
		return;	
	}	
	choose[i]=1;
	
	if(curW+w[i]<=C1){//Լ����������֦
	   curW+=w[i];
	   dfs(i+1); 
	   curW-=w[i];
    }      
	

		
	choose[i]=0;
	if(curW+upbound[i] > maxW) //�޽���������curP+upbound[i]<= maxP ,��Ϊ�Ͻ磬��֦��
	     dfs(i+1);
}
int main(){
	//enumA() ; 
	dfs(1);//���ݷ��ĵݹ�ʵ�֣�backtrack 
	
	if(upbound[0]-maxW<=C2) {
		printf("��һ��װ��%d\n",maxW);
		printf("�ڶ���װ��%d\n",upbound[0]-maxW);
	}
	else{
		printf("no SOLVE\n");
	} 
	
} 
