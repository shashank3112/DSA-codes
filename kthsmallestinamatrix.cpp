#include <bits/stdc++.h>
using namespace std;

int mat[303][303],k,n;

int func(int x){
    int cnt = 0;
    for(int i = 0; i<n ; i++){
        int l=0,h=n-1,m;
        
        if(mat[i][n-1] <=x ){
            cnt = cnt + n ;
            continue;
        }
        if(mat[i][0] > x) continue;
        
        while(l<=h){
            m = (l+h)/2;
            if(mat[i][m]<x) l = m+1;
            else{
                if(mat[i][m]>x){
                	if(mat[i][m-1]<=x){
                		cnt = cnt + m;break;
					}
					else h = m-1;
				}
                else{
                	 cnt+=m+1;break;
				}
            }
        }
        
    }
    return cnt;
}

int main() {
    
    int i,j,k,l=INT_MAX,m,h=INT_MIN,cnt,cnt1;
    cin>>n;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++) cin>>mat[i][j];
    cin>>k;
    for(i=0;i<n;i++) l = min(l,mat[i][0]);
    for(i=0;i<n;i++) h = max(h,mat[i][n-1]);
    
    while(l<=h){
        m = (l+h)/2;
        cnt = func(m);a
        //cout<<"m and cnt = "<<m<<" "<<cnt<<"\n";
        if(cnt<k) l = m+1;
        else{
            cnt1 = func(m-1);
            //cout<<"m and cnt1 = "<<m<<" "<<cnt1<<"\n";
            if(cnt1<k){
            	cout<<m;return 0;
			}
			else h = m-1;
        }
    }
    
    return 0;
}
