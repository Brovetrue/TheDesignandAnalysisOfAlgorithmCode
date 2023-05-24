#include<stdio.h>
const int inf = 0x7fffff;
const int N = 100;
int n =6;
char vername[N][10]={"v1","v2","v3","v4","v5","v6"}; 
int w[N][N]={{0,6,1,5,inf,inf},
	          {6,0,5,inf,3,inf}, 
              {1,5,0,5,6,4},
              {1,inf,5,0,inf,2},
              {inf,3,6,inf,0,6},
              { inf ,inf,4,2,6,0}
            };
int v0 = 0;//记录源点的索引 
int cost[N];//cost[i] vi在V-S中，记录跨在两个集合之间的边的最小哪一条 
int pre[N];//pre[i] 记录vi的路径的前一个节点的编号 

int tag[N];//tag[i]表示结点i是否在S中，还是再V-S中
int selectMin() {
	int min=inf;
	int u;
	for(int i=0;i<n;i++) 
      if(tag[i] == 0){
      	 if(min>cost[i]){
      	     min=cost[i];
			   u = i;
         }
	  }
	return u;
}
void tiaozheng(int u){  //u是刚加入S的顶点  
	for(int i=0;i<n;i++) 
      if(tag[i] == 0){
      	 if(cost[i] >  w[u][i]){		   
      	     cost[i]=w[u][i];
      	     pre[i] = u;
		 }
	  }
}
void prim(int v0){
   //初始化S和V-S   
   for(int i=0;i<n;i++) 
     tag[i] = 0;
   tag[v0]=1;
   //初始化dist，记录V-S中所有结点的最短特殊路径
   for(int i=0;i<n;i++){    
       cost[i] =w[v0][i];
       pre[i] = v0;
   }
   for(int i=1;i<=n-1;i++){
   	  // 从V-S中的cost[u]选出最小的u 
   	   int u = selectMin();
   	   printf("v%d->v%d:%d\n",pre[u]+1,u+1,cost[u]);//输出我们所选的边 
   	   //将u加入S中
   	   tag[u]=1;
	   //调整新的V-S中的结点的dist值 
	   tiaozheng(u);//根据刚加入的顶点u调整其他的顶点 
   }	
}           
int main() {
	prim(v0);
	//print(); 
}
