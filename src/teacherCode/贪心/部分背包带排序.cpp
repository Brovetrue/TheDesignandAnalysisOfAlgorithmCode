struct wupin{
	int w;
	int v;
	friend bool operator<(wupin a,wupin b){//2 ָ������ʽ 
	    return a.v/(float)a.w > b.v/(float)b.w;
	}
};
wupin arr[N];
int n;

#include<stdio.h>
int main(){
    input();//arr n �������� 
    sort(arr,arr+n);
    zhuang(); 
  return 0;
}

