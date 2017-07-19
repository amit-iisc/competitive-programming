
//
//  Created by Amit 
//  Copyright © 2017 Amit. All rights reserved.
//


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <valarray>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>

using namespace std;



#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)

#define M 1000005

class segTreeNode{

public: 
	int val;
	segTreeNode *left;
	segTreeNode *right;

	segTreeNode(){}

	segTreeNode(segTreeNode *l,segTreeNode *r, int v){
		this->left = l;
		this->right = r;
		this->val = v;
	}

	void updateValue(segTreeNode *prev,int low, int high, int idx, int newval){

		if(idx < low || idx > high || low > high){
			return;
		}

		//cout << "Inside";
		if(prev == NULL){
			if(low == high){
				this->val = newval;
				return;
			}

			int mid = (low + high) / 2;

			if(idx <= mid){
				this->left = new segTreeNode(NULL,NULL,0);
				this->right = NULL;
				this->left->updateValue(NULL,low,mid,idx,newval);
				
			}
			else{
				this->right = new segTreeNode(NULL,NULL,0);
				this->left = NULL;
				this->right->updateValue(NULL,mid+1,high,idx,newval);
			}

			this->val = newval;
		}
		else{
			if(low == high){
				this->val = prev->val + newval;
				return;
			}

			int mid = (low + high) / 2;
			

			if(idx <= mid){
				this->left = new segTreeNode(NULL,NULL,0);
				this->right = prev->right;
				this->left->updateValue(prev->left,low,mid,idx,newval);

			}
			else{
				this->right = new segTreeNode(NULL,NULL,0);
				this->left = prev->left;
				this->right->updateValue(prev->right,mid+1,high,idx,newval);
			}

			int p1 = 0,p2 = 0;
			if(this->left != NULL){
				p1 = this->left->val;
			}

			if(this->right != NULL){
				p2 = this->right->val;
			}
	
			this->val = p1 + p2; 
		}

	}

	int query(int low,int high,int l,int r){
		if(r < low || l > high){
			return 0;
		}

		if(l <= low && r >= high){
			return this->val;
		}

		int mid = (low + high) / 2;

		int p1 = 0,p2 = 0;

		if(this->left != NULL){
			p1 = this->left->query(low,mid,l,r);
		}
		if(this->right != NULL){
			p2 =  this->right->query(mid+1,high,l,r);
		}

		//cout << low << " " << high<<" " << p1 << " " << p2 << "\n";
		return p1 + p2;
	}

};


void primeFactors(int *arr, int idx, vector <pair <int ,int> > *factorList)
{
    // Print the number of 2s that divide n
    int count = 0;
    int n = arr[idx];
    while (n%2 == 0)
    {
        count++;
        n = n/2;
    }
 	
 	if(count){
	 	factorList[idx].push_back(make_pair(2,count));
	 }
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        count = 0;
        while (n%i == 0)
        {
            count++;
            n = n/i;
        }
        if(count){
        	factorList[idx].push_back(make_pair(i,count));
        }
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
        factorList[idx].push_back(make_pair(n,1));
}


int main(){

	// fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("B-small-attempt0.in","rt",stdin);
	// freopen("B.out","wt",stdout);

	int n,q;

	cin >> n;

	int arr[n];

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	vector <pair<int ,int> > factorList[n];

	for(int i = 0; i < n; i++){
		primeFactors(arr,i,factorList);
	}

    segTreeNode *version[n+1];

    version[0] = new segTreeNode(NULL,NULL,0);

    for(int i = 1; i <= n; i++){

    	segTreeNode *temp = version[i-1];

	    for(int j = 0; j < factorList[i-1].size();j++){
	    	version[i] = new segTreeNode(NULL,NULL,0);
	    	version[i]->updateValue(temp,1,M,factorList[i-1][j].first, factorList[i-1][j].second);
	    	temp = version[i];
	    	//cout << version[i]->val << " inserted " <<factorList[i-1][j].second << " at " << factorList[i-1][j].first << "\n";
	    }
	    //delete(temp);
    }

    // for(int i = 0; i < n; i++){

    // 	For(it,factorList[i]){
    // 		cout << (*it).first<< " "<< (*it).second << "     ";
    // 	}
    // 	cout << "\n";
    // }

    int nq,x,y,l,r;

    cin >> nq;

    while(nq--){
    	cin >> l >> r >> x >> y;

    	int p = version[r]->query(1,M,x,y);
    	int q = version[l-1]->query(1,M,x,y);

    	cout << p - q  << "\n";
    }
  

	return 0;
	
}




