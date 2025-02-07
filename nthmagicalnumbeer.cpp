#include <bits/stdc++.h>
using namespace std;
long long a,b;
#define MOD 1000000007
long long gcd(long long x,long long y){
    long long mini=min(x,y);
    long long maxi=max(x,y);
    
    if(mini==1 || maxi==1) return 1;
    
    long long rem = maxi%mini;
    while(rem!=0){
         maxi = mini;
         mini = rem;
         rem = maxi%mini;
    }
    return mini;
}
long long func(long long x ,long long lcm){
    return (x/a + x/b - x/lcm);
}
int main() {
    long long t,n,i,j,k,cnt,cnt1,lcm;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        lcm = (a*b)/gcd(a,b);
        long long l = min(a,b), h = n*max(a,b),m;
        
        while(l<=h){
            m  = (l + h)/2;
            
            cnt = func(m,lcm);
           // cout<<"m cnt = "<<m<<" "<<cnt<<"\n";
            if(cnt<n) l = m +1;
            else if(cnt>n) h = m-1;
            else{
                if(m%a==0 || m%b==0){
                    cout<<m%MOD<<"\n";
                    break;
                }
                else h = m-1;
            }
        }
    }
    return 0;
}
