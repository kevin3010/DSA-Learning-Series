// range querry for minimum in an array

void bulidTree(int idx,int left,int right)
{
	if(left==right)
		{seg[idx] = arr[right]; return;}


	int mid = (left+right)/2;
	bulidTree(2*idx,left,mid);
	bulidTree(2*idx+1,mid+1,right);

	seg[idx] = min(seg[2*idx],seg[2*idx+1]);
} 

int queryTree(int idx ,int ss,int se,int qs,int qe)
{
	cout<<"("<<ss<<" "<<se<<" "<<qs<<" "<<qe<<')'<<endl;
	if(qs==ss && qe==se) {cout<<"# "; return seg[idx];}
	if(qs>se || qe<ss) {cout<<"* "; return INT_MAX; }

	int mid = (ss+se)/2;
	int l=queryTree(idx*2, ss, mid, qs, min(mid,qe));
	int r=queryTree(idx*2+1, mid+1,se, max(mid+1,qs), qe);

	return min(l,r);
}

void update(int idx, int ss,int se, int qi)
{
	if(ss==se){
		seg[idx] = arr[qi];
		return;
	}
		
	int mid = (ss+se)/2;
	if(qi<mid+1)
		update(idx*2,ss,mid,qi);
	else
		update(idx*2+1, mid+1,se, qi);

	seg[idx] = min(seg[idx*2] , seg[idx*2+1]);
}
