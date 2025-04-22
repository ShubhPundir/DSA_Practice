//author : bhupathi07
//problem Link : https://atcoder.jp/contests/abc103/tasks/abc103_d
#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int,int> &a , const pair<int,int> &b)
{
	return a.second < b.second;
}
int main()
{
	int n = 9, m = 5;
	//number of islands and number of requests
	// cin >> n >> m;
	vector<pair<int,int>> requests = {{1,8}, {2,7}, {3,5}, {4,6}, {7,9}};
	//storing all requests as a pairs in vector of pairs
	
    // for(int i = 0 ; i < m ; i++)
	// {
	// 	int a, b;
	// 	cin >> a >> b;
	// 	requests.push_back(make_pair(a,b));
	// }
	
    // sort the request on the basis of right end point
	sort(requests.begin(),requests.end(),comp);

    for(auto p: requests)
        cout << p.first << "-" << p.second << endl;

	int ans = 0;
	int lastbridge = -1;
	//interating over the reuqests to know that if that
	//request demands that the bridge need to be added to answer
    cout << "--------------------------" << endl;
	for(auto request : requests)
	{
		// if the current request  is already handled by previous solution  that we have
		// the continue by ignoring this request (this is done by using lastbridge )
		if(lastbridge > request.first)
			continue;
		else
		{
			//rightmost bridge of request which is not handled by our lastbridge
			lastbridge = request.second;
            cout << "lastbridge pair: " << request.first << "-" << request.second << endl;
			ans++;
		}
	}
	cout<< ans << endl;
 	return 0;
}