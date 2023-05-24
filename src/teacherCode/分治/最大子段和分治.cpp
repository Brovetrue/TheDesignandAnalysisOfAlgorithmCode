#include<stdio.h>
int N = 8;
int a[65]={1,-3,7,8,-4,12,-10,6};
int maxsubsum(int a[],int left,int right){
	//T(n) =2 T(n/2) + n  //
	if(left==right){
		if(a[left]>0)
	       return a[left];
	    else return 0;	
	}
	
	int mid =(left+right)/2;
    int leftmax=	maxsubsum(a,left,mid);
    int rightmax =maxsubsum(a,mid+1,right);
    int s1=0;
    int m1 =0;
    for(int i=mid;i>=left;i--) {
    	s1+=a[i];
    	if(m1<s1) m1 =s1;
	}
	int s2=0;
    int m2 =0;
    for(int i=mid+1;i<=right;i++) {
    	s2+=a[i];
    	if(m2<s2) m2 =s2;
	}
	int midmax = m1+m2;
	int m= leftmax;
	if(rightmax>m) m =rightmax;
	if(midmax>m) m =midmax;
	return m;
}
int main(){
	int m=maxsubsum(a,0,N-1);
	printf("%d",m);
	
}


