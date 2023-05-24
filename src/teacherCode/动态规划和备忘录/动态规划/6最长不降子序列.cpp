#include<stdio.h>
const int n=8;
int a[n+1]={0,1,3,4,2,7,9,6,8};
int b[n+1];
int maxlen=1;
void solveb(){
	
	b[1] =1;
	for(int i=2;i<=n;i++){
		//b[i]=?;
		int m=0;
		for(int j=0;j<=i-1;j++){//到a[i]的前面找比a[i]小的或者跟a[i]相等 
			if(a[j]<=a[i]){
				if(b[j]>m)m=b[j];
			}
		}
		b[i] = m+1;
		if(b[i]>maxlen) maxlen=b[i];
	}
} 

int main(){
	solveb();
	printf("%d\n",maxlen) ;
	
}

 
