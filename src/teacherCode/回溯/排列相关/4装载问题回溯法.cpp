#include<stdio.h>
const int n=3;
int w[n+1]={0,14,15,15}; 
int upbound[n+1]= {44,30,15,0}; 
//upbound[i]:代表第i+1种物品到第n种物品总的重量 ,
//即剩余的全部放入船1,
//不选的话，curP+upbound[i]作为上界 
int C1 =30;
int C2=35; 
int choose[n+1];//choose[i]=1代表子集中含有a[i],=0代码不含a[i]
int bestchoose[n+1];
int maxW=0;
int curW = 0; 
void dfs(int i){
	if(i==n+1){
		if(curW>maxW){
			maxW = curW;
			
		   // bestchoose<=choose 记录最优的装载方案 
		}
		return;	
	}	
	choose[i]=1;
	
	if(curW+w[i]<=C1){//约束条件：剪枝
	   curW+=w[i];
	   dfs(i+1); 
	   curW-=w[i];
    }      
	

		
	choose[i]=0;
	if(curW+upbound[i] > maxW) //限界条件：（curP+upbound[i]<= maxP ,作为上界，剪枝）
	     dfs(i+1);
}
int main(){
	//enumA() ; 
	dfs(1);//回溯法的递归实现，backtrack 
	
	if(upbound[0]-maxW<=C2) {
		printf("第一艘装：%d\n",maxW);
		printf("第二艘装：%d\n",upbound[0]-maxW);
	}
	else{
		printf("no SOLVE\n");
	} 
	
} 
