// #include<iostream>
// #include<vector>
// #include<map>

// using namespace std;

// int n;
// map<int, int> record;

// int main() {
//     int t;
//     cin >> t;
//     while(t--) {
//         cin >> n;
//         vector<int> nums(n);
//         for (int i = 0; i < n; i++)
//             cin >> nums[i];
//         for (int i = 0;i)
// }

#include<iostream>
#include<vector>

using namespace std;
const int maxn=3e5+100;
typedef long long LL;
const LL inf=1e18;
LL ans[maxn]; 
vector<LL>v[maxn];
int main(void)
{
  LL t;cin>>t;
  while(t--)
  {
  	LL n;cin>>n;
  	for(LL i=0;i<=n+10;i++) ans[i]=inf,v[i].clear();
  	for(LL i=1;i<=n;i++){
  		LL x;cin>>x;v[x].push_back(i);	
	}
	for(LL i=1;i<=n;i++)
	{
		if(!v[i].empty())
		{
			LL mx=0;
			for(LL j=1;j<v[i].size();j++)
			{
				mx=max(mx,v[i][j]-v[i][j-1]);
			}
			mx=max(mx,v[i].front());
			mx=max(mx,n-v[i].back()+1);
			ans[mx]=min(ans[mx],i);
		}
	}
	for(LL i=2;i<=n;i++) ans[i]=min(ans[i],ans[i-1]);
	for(LL i=1;i<=n;i++){
		if(ans[i]<inf) cout<<ans[i]<<" ";
		else cout<<"-1"<<" ";
	} 
	cout<<endl;
  }
return 0;
}