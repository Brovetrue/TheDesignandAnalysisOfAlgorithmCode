#include<stdio.h>
const int n=4;
//int adj[n+1][n+1]={{0},{0,0,1,1,0},{0,1,0,1,1},{0,1,1,0,1},{0,1,1,1,0}}; //四个顶点的完全图 
int adj[n+1][n+1]={{0},{0,0,1,1,0},{0,1,0,1,0},{0,1,1,0,1},{0,0,0,1,0}};// 
int choose[n+1];//
int max = 1; //记录最大团含的顶点数 
void outputSub();
void dfs(int i);
int main(){	 
	dfs(1);
	printf("max=%d",max); 
} 
int isTuan(){
  for(int i=1;i<=n;i++)	
    if(choose[i]==1){	
	    for(int j=1;j<=i-1;j++){
	    	if(choose[j]==1 && adj[i][j]==0) 
			         return 0;//adj[i][j]==0，vi,vj两个顶点之间没有边，不是团 
		} 
	}
  return 1;//是团 
}
int daxiao(){
  int s=0;
  for(int i=1;i<=n;i++)	
    if(choose[i]==1){	
	    s++;
	}
  return s;
}
void dfs(int i){//大家可以改进该算法，使用剪枝函数 
	if(i==n+1){
		if(isTuan()==1){//当前的子集是团吗？ 
		    int s = daxiao();//统计当前团的大小，即子集元素个数 
			if(s>max) max=s; 
	    }
		return;	
	}	
	//if(isTuan(i))//顶点i加入后跟前面能否构成团，不能就剪枝 
	choose[i]=1;
	dfs(i+1);
	choose[i]=0;
	dfs(i+1);
}
