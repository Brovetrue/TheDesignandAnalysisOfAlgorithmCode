#include<stdio.h>
#define n  5
#define inf  100000
int w[n]={10,8,16,13,4};


struct node{
	int weight;
	int parent;
	int lchild;
	int rchild;
};
struct node huffmanTree[n+n-1];
void  select(int k,int *pi1,int *pi2){
   int min1 = inf;
   int min2 = inf;
   for(int i=0;i<=k;i++){
   	  if(huffmanTree[i].parent==-1 && min1> huffmanTree[i].weight){  	  	
   	  	    min2 = min1;
   	  	    *pi2 = *pi1;
   	  	    min1 =huffmanTree[i].weight;
		    *pi1 = i;
		}else if(huffmanTree[i].parent==-1 && min2 > huffmanTree[i].weight){
			min2 =huffmanTree[i].weight;
		    *pi2 = i;
		}
   }
   


   //*pi1   i1 ��¼��С
   //*pi2   i2  ��¼��Сλ�� 

} 
void createHuffman(){
    //��ʼ��
	for(int i=0;i<2*n-1;i++){
		huffmanTree[i].parent =huffmanTree[i].lchild =huffmanTree[i].rchild=-1;
	} 
    for(int i=0;i<n;i++){
		huffmanTree[i]. weight =w[i];
	}
	int p=n;//��¼�ϲ��õ��ڵ��ŵ��±� 
	for(int times=1;times<=n-1;times++){ 
	   int i1,i2;
	   select(p-1,&i1,&i2);//[0,k]ѡ����С�ĺϲ� 
	   huffmanTree[p]. weight= huffmanTree[i1]. weight+huffmanTree[i2].weight;
	   huffmanTree[p].lchild = i1;
	   huffmanTree[p].rchild  =i2;
	   huffmanTree[i1].parent =  p;
	   huffmanTree[i2].parent =  p;//? 
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
}
