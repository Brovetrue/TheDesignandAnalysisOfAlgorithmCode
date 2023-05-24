#include<stdio.h>

const int inf = 0x7fff;
const int N = 100;//最多节点数 
int n =5;
char vername[N][10]={"v0","v1","v2","v3","v4"}; 
int w[N][N]={{0,10,inf,30,inf},
	          {inf,0,50,inf,inf}, 
              {inf,inf,0,inf,10},
              {inf,inf,20,0,60},
              {inf,inf,inf,inf,0}
            };//邻接矩阵 
int v0 = 0;//记录源点的索引
//初始数据

 
 
int dist[N];//从源点到其他各个顶点的最短路径值。
int pre[N];//pre[i]  vi的顶点的最短的特殊路径中
                   //的vi的前一个节点 
int tag[N];//tag[i] =1 顶点vi在S中，
              //tag[i] =0 顶点vi在V-S中，
//标识数据 
//用于记录过程和展现结果的数据
int selectMinDist(){//从V-S中的dist[u]选出最小的u
    int min=inf;
    int u;
	for(int i=0;i<n;i++){
    	if(tag[i]==0){
    		if(dist[i]<min){
    			min = dist[i];
    			u = i;
			}
		}
	} 

    return u;

}
void tiaozheng(int u){
	//调整新的V-S中的结点的dist值
	for(int i=0;i<n;i++){
    	if(tag[i]==0){
    		if(dist[i]>dist[u]+w[u][i]){
    			dist[i]=dist[u]+w[u][i];
    			pre[i]=u;
			}
		}
	} 
	
}
void dijstra(int v0){
   //初始化S和V-S 
   for(int i=0;i<n;i++) 
      tag[i]=0;
   tag[v0] =1; 
   //初始化dist，记录V-S中所有结点的最短特殊路径
   for(int i=0;i<n;i++) {   
      dist[i] =w[v0][i];//开始s中只有一个v0所有最短
	  pre[i]=v0; 
   }
   for(int i=1;i<=n-1;i++){
   	   //从V-S中的dist[u]选出最小的u 
   	   int u =selectMinDist();
	   //将u加入S中
   	   tag[u]=1;
	   //调整新的V-S中的结点的dist值
	   tiaozheng(u); 
   }	
}  
void print(){
		//调整新的V-S中的结点的dist值
    printf("%6s%6s%6s%12s\n","源点","pre","终点","最短路径值");
	for(int i=0;i<n;i++){
    	printf("%6s%6s%6s%12d\n",vername[v0],vername[pre[i]],vername[i],dist[i]);
	} 
	

}  
void input(){
	int e;
	scanf("%d",&n);
	//w 矩阵全部初始化成 inf 
	for(int i=0;i<n;i++){ 
	  scanf("%s",vername[i]);
	  w[i][i]=0; 
	} 
	scanf("%d",&e);
	
	for(int i=0;i<e;i++){
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		w[a][b]=k;
		//w[a][b]=w[b][a]=k;
	}
}      
int main() {
	input();//对初始数据进行输入 
	dijstra(v0);
	print();//输出结果
	//printpath(); 
}
