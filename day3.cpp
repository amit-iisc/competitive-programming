#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define mp make_pair
#define pb push_back
#define ft first
#define sd second

int a[100][100];

    int GetWaterLevel(int input1,int input2,int input3_size,int* input3)
    {
        int i,j,w,h;
        if(input1<=2)return 0;
        if(input2<=2)return 0;
    	f(i,input1)
        {
            f(j,input2)
            {
                a[i][j]=input3[i*input2+j];
            }
        }
        w=input1;
        h=input2;
        map<int,vector<pair<int,int> > > m;
        for(i=1;i<w-1;++i)
        {
            m[a[i][0]].pb(mp(i,0));
            m[a[i][h-1]].pb(mp(i,h-1));
            a[i][0]=a[i][h-1]=0;
        }
        for(i=1;i+1<h;++i)
        {
            m[a[0][i]].pb(mp(0,i));
            m[a[w-1][i]].pb(mp(w-1,i));
            a[0][i]=a[w-1][i]=0;
        }
        
        a[0][0]=a[0][h-1]=a[w-1][0]=a[w-1][h-1]=0;
        
        int ret = 0;
        map<int,vector<pair<int,int> > >::iterator b;
        vector<pair<int,int> > v;
        pair<int,int> p;
        int height;
        pair<int,int> nodes[4];
        while(!m.empty()) 
        {
            b=m.begin();
            height=b->ft;
            v=b->sd;
            f(i,v.size()) 
            {
                p=v[i];
                f(j,4) 
                nodes[j]=p;
                --nodes[0].ft;
                ++nodes[1].ft;
                --nodes[2].sd;
                ++nodes[3].sd;
                f(j,4) 
                {
                    p=nodes[j];
                    if(!a[p.ft][p.sd]||p.ft<0||p.sd<0||p.ft>=w||p.sd>=h) 
                    continue;
                    ret+=max(0,height-a[p.ft][p.sd]);
                    a[p.ft][p.sd]=max(a[p.ft][p.sd],height);
                    if(a[p.ft][p.sd]==height)
                    v.pb(p);
                    else 
                    m[a[p.ft][p.sd]].pb(p);
                    a[p.ft][p.sd] = 0; 
                }
            }
            m.erase(b);
        }
        return ret;    
    }
Sample Problem with Solution
