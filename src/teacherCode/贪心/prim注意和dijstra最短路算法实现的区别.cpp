#include<stdio.h>
const int inf = 0x7fffff;
const int N = 100;
int n =6;
int w[N][N]={{0,6,1,5,inf,inf},
	          {6,0,5,inf,3,inf}, 
              {1,5,0,5,6,4},
              {5,inf,5,0,inf,2},
              {inf,3,6,inf,0,6},
              {inf,inf,4,2,6,0}
            };
int v0 = 0;//记录源点的索引 
int lowcost[N];
int pre[N]; 
int tag[N];//tag[i]表示结点i是否在S中，还是再V-S中
int selectMin() {
	int min=inf;
	int u;
	for(int i=0;i<n;i++) 
      if(tag[i] == 0){
      	 if(min>lowcost[i]){
      	     min=lowcost[i];
			   u = i;
         }
	  }
	return u;
}
void tiaozheng(int u){  //u是刚加入S的顶点  
	for(int i=0;i<n;i++) 
      if(tag[i] == 0){
      	 if(lowcost[i] > w[u][i]){      	 
      	     lowcost[i] = w[u][i];
      	     pre[i]=u;
		  }
	  }
	

}
void prim(int v0){
   //初始化S和V-S   
   for(int i=0;i<n;i++) 
     tag[i] = 0;
   tag[v0]=1;
   //初始化S ，V-S中所有结点的最小的边 
   for(int i=0;i<n;i++){    
      lowcost[i] =w[v0][i];
	 //lowcost记录跨在两个集合之间的（V-S）最小的边权 	 
	  pre[i]=v0;//v0 到 vi 
   }
   for(int i=1;i<=n-1;i++){
   	  // 从V-S中的lowcost[u]选出最小的u 
   	   int u = selectMin();
		  //选择边：(pre[u] , u）输出边 
	   printf("v%d--v%d\n",pre[u]+1,u+1);
   	   //将u加入S中
   	   tag[u]=1;
	   //调整新的V-S中的结点的lowcost值 
	   tiaozheng(u);//根据刚加入的顶点u调整其他的顶点 
   }	
}           
int main() {
	prim(v0);
	//print(); 
}
