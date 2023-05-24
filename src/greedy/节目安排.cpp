#include <iostream>
#include <algorithm>
using namespace std;

struct Activity{
    int num,start,end,mark;
};

bool comp(Activity a,Activity b){
    if(a.end==b.end) return a.start<b.start;
    return a.end<b.end;
}

void Select(Activity act[],int n){
    int begin = act[1].start;
    for(int i=1;i<=n;i++) {
        if (act[i].start >= begin) {
            begin = act[i].end;
            act[i].mark = 1;
        }
    }
}
int main() {
   int n;
   cin>>n;
   Activity activity[n+1];
   for(int i=1;i<=n;i++){
       cin>>activity[i].start>>activity[i].end;
       activity[i].num = i;
       activity[i].mark = 0;
   }
    sort(activity+1,activity+n+1,comp);
    Select(activity,n);
    int count;
    for(int i=1;i<=n;i++){
        if(activity[i].mark==1) {
            cout << activity[i].num << " ";
            count++;
        }
    }
    cout<<endl;
    cout<<count;
}
