#include<iostream>
using namespace std;
int main()
 {   int s1,s2,s3,s4;
     cin>>s1;
     cin>>s2;
     cin>>s3;
     
    // input size
    // create array
    int a[s1];
    int b[s2];
    int c[s3];
    for(int i=0;i<s1;i++)
       {
           cin>>a[i];
       }
    for(int i=0;i<s2;i++)
       {
           cin>>b[i];
       }
    for(int i=0;i<s3;i++)
       {
           cin>>c[i];
       }
       //print array
       for(int i=0;i<s1;i++)
       {
           cout<<a[i]<<" ";
       }
       cout<<endl;
    for(int i=0;i<s2;i++)
       {
           cout<<b[i]<<" ";
       }
       cout<<endl;
    for(int i=0;i<s3;i++)
       {
           cout<<c[i]<<" ";
       }
       cout<<endl;
    ///
    
    //merge first two
    s4=s1+s2;
    int j=0;
    int k=0;
    int d[s4];
    for(int i=0;i<s4;i++)
       {
           if((a[j]<=b[k])&&j<s1)
             {  
                d[i]=a[j];
                j++;
                 
             }
             else{
                 d[i]=b[k];
                 k++;
                  }
       }
       //
       for(int l=0;l<s4;l++)
          {
              cout<<d[l]<<" ";
          }
       
       
       //
      cout<<endl;
    
    //merge last two
     int fin=s1+s2+s3;
       int arr[fin];
        int j2=0;
        int  k2=0;
        for(int i=0;i<fin;i++)
       {
           if((c[j2]<=d[k2])||k2==s4)
             {  
              arr[i]=c[j2];
              j2++;
                 
             }
             else
             {
                 arr[i]=d[k2];
                 k2++;
             }
       }
       
    for(int m=0;m<fin;m++)
       {
          cout<<arr[m]<<" ";
       }
    //search in array
    //arr[fin]
    cout<<endl;
    
    cout<<"print"<<endl;
    int temp;
    temp=arr[0];
    for(int n=0;n<fin;n++)
       {
           if(arr[n]==arr[n+1])
              {
                  cout<<arr[n]<<" ";
                  while(arr[n]==arr[n+1])
                    {
                        n++;
                    }
              }
       }
    
    
    
    return 0;
}