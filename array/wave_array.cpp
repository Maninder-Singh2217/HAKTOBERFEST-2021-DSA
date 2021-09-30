#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;         
                                      
}

void convertToWave(int *a,int n){
    int x=0;

    for(int i=0;i<n-1;i++){
        if(x%2==0){
            
        if(a[i]<a[i+1]){
              
              swap(&a[i],&a[i+1]);
              
              
        }}
        else{
            
        if(a[i]>a[i+1]){
            
            swap(&a[i],&a[i+1]);
            
            
        }}
        x++;
    }
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        convertToWave(a,n);
        for(int i=0;i<n;i++){
             cout<<a[i]<<" ";
        }

        cout<<endl;
    }
     return 0;

}