#include<stdio.h>
struct edge{
	int u,v,w;
};
struct edge  earr[100]={
     {1,4,12},{2,3,17},{0,5,19},{2,5,25},
	 {3,5,25},{4,5,26},{0,1,34},{3,45,38},{0,2,46}};//���� 
int e=9;//���� 
int n=6;//���� 
int father[100];//father[i]��������i�Ķ������ĸ��׽��ı�� :���ױ�ʾ�� 
int findroot(int v){
	int k=v;
	while(father[k]!=-1){
		k = father[k];
	}	
	return k;
}
void kruskal(){	
    //paixu();  ���� 
	for(int i=0;i<n;i++) 
	    father[i]=-1;//��ʼ��n����ͨ��֧ 
	int choose =0;//ѡ���ߵ����� 
	int i=0;//����ɨ������飺�����鰴Ȩֵ�����Ѿ����кã�����С�߿�ʼѡ�� 
	while(choose<n-1 && i<e){
		int r1 = findroot(earr[i].u) ; 
		int r2 =findroot(earr[i].v);
		if(r1!=r2){//�ж������˵��Ƿ���ͬһ�����ϣ���һ������ͬһ���� 
			printf("v%d v%d  %d\n",earr[i].u,earr[i].v,earr[i].w);
			choose++;
			father[r2]=r1;//��r2��Ϊ��һ�����ĸ�r1�ĺ��� 
		}
		i++;
	}
	if(choose<n-1){
		printf("ԭͼ����ͨ��û����С������\n");
	}
	 
}
int main(){
	//input();
	kruskal();
}
