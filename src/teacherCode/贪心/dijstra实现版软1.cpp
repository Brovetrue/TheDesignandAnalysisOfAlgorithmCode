#include<stdio.h>
const int inf = 0x7fffff;
const int N = 100;
int n =5;
char vername[N][10]={"v0","v1","v2","v3","v4"}; 
int w[N][N]={{0,10,inf,30,inf},
	          {inf,0,50,inf,inf}, 
              {inf,inf,0,inf,10},
              {inf,inf,20,0,60},
              {inf,inf,inf,inf,0}
            };
int v0 = 0;//记录源点的索引 
int dist[N];
int pre[N];//pre[i] 记录vi的路径的前一个节点的编号 

int tag[N];//tag[i]表示结点i是否在S中，还是再V-S中
int selectMin() {
	int min=inf;
	int u;
	for(int i=0;i<n;i++) 
      if(tag[i] == 0){
      	 if(min>dist[i]){
      	     min=dist[i];
			   u = i;
         }
	  }
	return u;
}
void tiaozheng(int u){  //u是刚加入S的顶点  
	for(int i=0;i<n;i++) 
      if(tag[i] == 0){
      	 if(dist[i] > dist[u]+w[u][i]){		   
      	     dist[i]=dist[u]+w[u][i];
      	     pre[i] = u;
		 }
	  }
}
void dijstra(int v0){
   //初始化S和V-S   
   for(int i=0;i<n;i++) 
     tag[i] = 0;
   tag[v0]=1;
   //初始化dist，记录V-S中所有结点的最短特殊路径
   for(int i=0;i<n;i++){    
       dist[i] =w[v0][i];
       pre[i] = v0;
   }
   for(int i=1;i<=n-1;i++){
   	  // 从V-S中的dist[u]选出最小的u 
   	   int u = selectMin();
   	   //将u加入S中
   	   tag[u]=1;
	   //调整新的V-S中的结点的dist值 
	   tiaozheng(u);//根据刚加入的顶点u调整其他的顶点 
   }	
} 
void print(){
	printf("  源点    终点     终点的前一个    最短路的值\n");
	for(int i=0;i<n;i++) 
       printf("%6d %6d    %8d           %d\n",v0,i,pre[i],dist[i]);
}          
int main() {
	dijstra(v0);
	print(); 
}
