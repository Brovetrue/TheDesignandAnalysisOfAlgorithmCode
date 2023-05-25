#include<stdio.h>
#define N 100
int n=3;
int w[N]={0,1,2,3};
int v[N]={0,6,10,12};
int C =5;
int choose[N];//选择的标记 
int bestchoose[N];
int bestV=0;
//子集问题的算法框架2 
void backtrack2(int i){//已经对前i-1个元素做了选择，现在对第i个元素做选择 
    
	if(i==n+1){ //递归出口，节点i是递归树中的叶子节点
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
	
	choose[i]=0;//不选第i个元素 
	backtrack2(i+1);	
	
	choose[i]=1;//选第i个元素 
	backtrack2(i+1);
	
		
} 

int main(){
    //sub(); 只能处理三个元素的子集 
	backtrack2(1);
	printf("%d",bestV);
}
