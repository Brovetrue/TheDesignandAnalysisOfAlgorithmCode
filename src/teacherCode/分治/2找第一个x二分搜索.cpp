int  findfirst(int L,int R,int x){
	if(L>R) return -1;
	if(L==R && a[L]==x) return L;
	if(L==R && a[L]!=x) -1;	
	int mid = (L+R)/2;
	if(a[mid]==x) 
	   return findfirst(L,mid,x);
	else if(a[mid] >x) 
	    return findfirst(L,mid-1,x);
	else return findfirst(mid+1,R,x);
} 
