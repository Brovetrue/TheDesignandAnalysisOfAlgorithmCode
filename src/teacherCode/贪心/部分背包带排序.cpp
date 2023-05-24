struct wupin{
	int w;
	int v;
	friend bool operator<(wupin a,wupin b){//2 指定排序方式 
	    return a.v/(float)a.w > b.v/(float)b.w;
	}
};
wupin arr[N];
int n;

#include<stdio.h>
int main(){
    input();//arr n 进行输入 
    sort(arr,arr+n);
    zhuang(); 
  return 0;
}

