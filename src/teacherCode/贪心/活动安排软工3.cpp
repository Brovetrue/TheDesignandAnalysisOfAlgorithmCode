#include<iostream>
#include<algorithm>
using namespace std;
struct jiemu{
	int start;
	int end;
	friend  bool operator<(jiemu a,jiemu b){
           return    a.end<b.end; //升序
    }

};
const int N = 100;
int n =11;
jiemu a[N]={{0,6},{5,7},{3,8},{5,9},
{6,10},{8,11},{8,12},{2,13},{12,14},{1,4},{3,5},

};
void arrange(){
   printf("%d %d \n",a[0].start,a[0].end);
   int i=1;
   int front = 0;//最近被安排节目的下标 
   int count =1;//
   while(i<n){
   	  if( a[i].start >=a[front].end){
   	      	printf("%d %d \n",a[i].start,a[i].end);
   	      	front  = i;
   	      	count++;
	  }   	
   	
   	   i++;
   }
   printf("最多可以看%d\n",count);   	
}
int main(){
	//input();//对n 和n个节目进行输入 
	sort(a,a+n);
	for(int i=0;i<n;i++){
		cout<<a[i].start<<"   "<<a[i].end<<endl;//end of line
	}
	//arrange(); 
}

