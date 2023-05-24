#include<stdio.h>
#include<queue>
using namespace std;
#define n  5
#define inf  100000
int w[n]={10,8,16,13,4};


struct node{
	int index; 
	int weight;
	int parent;
	int lchild;
	int rchild;
	friend bool operator<(node n1,node n2){
		return n1.weight > n2.weight; 
	}
};
struct node huffmanTree[n+n-1];
void createHuffman(){
    //初始化
    priority_queue<node> q;
	for(int i=0;i<2*n-1;i++){
		huffmanTree[i].parent =huffmanTree[i].lchild =huffmanTree[i].rchild=-1;
	    huffmanTree[i].index = i; 
	} 
    for(int i=0;i<n;i++){    	
		huffmanTree[i]. weight =w[i];
		q.push(huffmanTree[i]);
	}
	int p=n;//记录合并得到节点存放的下标 
	for(int times=1;times<=n-1;times++){ 
	   int i1,i2;
	   //
	   node nod = q.top();q.pop();
	   i1 =nod.index;
	   
	   nod = q.top();q.pop();
	   i2 =nod.index;
	   
	   huffmanTree[p]. weight= huffmanTree[i1]. weight+huffmanTree[i2].weight;
	   huffmanTree[p].lchild = i1;
	   huffmanTree[p].rchild  =i2;	   
	   huffmanTree[i1].parent =  p;
	   huffmanTree[i2].parent =  p;//? 	   
	   q.push(huffmanTree[p]);
	   
	   p++;
	} 

}
void print(){
	for(int i=0;i<2*n-1;i++) //00
	 printf("%3d%3d%3d%3d%3d\n",i,huffmanTree[i].weight,
	       huffmanTree[i].parent,//
		   huffmanTree[i].lchild,
		   huffmanTree[i].rchild
	 );
}

int main(){
	createHuffman();
	print();
	
	//printWPL();
}
