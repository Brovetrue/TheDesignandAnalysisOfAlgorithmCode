#include<stdio.h>
#include<algorithm>
using namespace std;

const int N = 100;
int n =11;//
struct node{
	int start;
	int end;
	friend bool operator<(node a,node b){
           return    a.end  < b.end ;
    }

	
	
};
node jiemu[N]={{0,6},{3,5},{1,4},{5,7},{3,8},{5,9},{6,10},
               {8,11},{8,12},{2,13},{12,14}};
int arrange(){
	int i=0;
	int m=0;
	int end = 0;
	while(i<n){
		if(jiemu[i].start>=end){
		   m++;
		   end  = jiemu[i].end;
		   printf("%d --%d\n",jiemu[i].start,jiemu[i].end);
		   //end  ��¼�Ѿ����ŵ����һ����Ŀ�Ľ���ʱ�� 
		}		
		i++;
	}
	return m ; 
}


int main(){//O(n*log(n))
	//input(); //�Խ�Ŀ���ͽ�Ŀ��ʼ����ʱ��������룬
	
	//����Ŀ�Ľ���ʱ�������������
	
	 
	sort(jiemu,jiemu+n);//O(n*log(n)) 
	for(int i=0;i<n;i++){
		printf("%d,%d\n",jiemu[i].start,jiemu[i].end);
	}
	
	//int m= arrange();//O(n) 
	
	//printf("%d",m);
	
}
