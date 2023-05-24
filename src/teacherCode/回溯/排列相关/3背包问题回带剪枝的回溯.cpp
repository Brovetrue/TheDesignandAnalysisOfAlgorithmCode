#include<stdio.h>
const int N =100;
int n=3;
int w[N]={0,1,2,3};
int v[N]={0,6,10,12}; 
int C = 5;
int bestV;
int choose[N];//choose[i] =1 表示第i个元素在子集中， choose[i] =0表示第i个元素不在子集中 
int bestchoose[N];
int curW=0;
int curV=0;
void trackBack(int i,int ub){//蛮力：回溯 1 - i-1个已经做了选择，现在对第i个做选择 
	if(i==n+1){//4
		//判断当前的解是否是可行解，如果是可行再判断是否是目前的最优
		//if(curV>bestV){
		bestV = curV;
		
		for(int i=1;i<=n;i++){
	       bestchoose[i]= choose[i];
        }	    
        //加return 后面可以不加else 
	}else{		
		
		if(curW + w[i]<=C){	//剪枝:	约束 
		    choose[i]=1;
			curW += w[i];//进去前加	
			curV += v[i];		
			trackBack(i+1,ub);	
			curW -= w[i];//回来的时候要减掉 
			curV -= v[i];
		}
			
		choose[i]=0;
		if(ub-v[i]>bestV){	//剪枝: 界（上）						
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
