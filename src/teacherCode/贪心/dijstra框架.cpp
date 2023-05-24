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
void dijstra(v0){
   //初始化S和V-S   
   //初始化dist，记录V-S中所有结点的最短特殊路径
   for(int i=1;i<=n-1;i++){
   	   从V-S中的dist[u]选出最小的u 
   	   将u加入S中
	   调整新的V-S中的结点的dist值 
   }	
}           
int main() {
	dijstra(v0);
}
