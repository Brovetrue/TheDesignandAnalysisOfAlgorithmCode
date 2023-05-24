#include<stdio.h>
struct edge{
	int u,v,w;
};
struct edge  earr[100]={
     {1,4,12},{2,3,17},{0,5,19},{2,5,25},
	 {3,5,25},{4,5,26},{0,1,34},{3,45,38},{0,2,46}};//输入 
int e=9;//输入 
int n=6;//输入 
int father[100];//father[i]代表编号是i的顶点它的父亲结点的编号 :父亲表示法 
int findroot(int v){
	int k=v;
	while(father[k]!=-1){
		k = father[k];
	}	
	return k;
}
void kruskal(){	
    //paixu();  升序 
	for(int i=0;i<n;i++) 
	    father[i]=-1;//开始是n个连通分支 
	int choose =0;//选出边的条数 
	int i=0;//用来扫描边数组：边数组按权值升序已经排列好，即从小边开始选择 
	while(choose<n-1 && i<e){
		int r1 = findroot(earr[i].u) ; 
		int r2 =findroot(earr[i].v);
		if(r1!=r2){//判断两个端点是否在同一颗树上，根一样就是同一颗树 
			printf("v%d v%d  %d\n",earr[i].u,earr[i].v,earr[i].w);
			choose++;
			father[r2]=r1;//根r2作为另一颗树的根r1的孩子 
		}
		i++;
	}
	if(choose<n-1){
		printf("原图不连通，没有最小生成树\n");
	}
	 
}
int main(){
	//input();
	kruskal();
}
