#include<bits/stdc++.h> //not optimised
using namespace std;
#define size 100000

int merge(int arr[],int beg,int mid,int end){

    int i=beg,j=mid+1,index=beg,temp[size];
    while((i<=mid)&&(j<=end)){
            if(arr[i]<arr[j]){
                    temp[index]=arr[i];
                    i++;

            }else{
                temp[index]=arr[j];
                j++;
            }index++;

    }
    if(i>mid){
        while(j<=end){
            temp[index]=arr[j];
            j++;
            index++;
        }
    }else{
        while(i<=mid){
            temp[index]=arr[i];
            i++;
            index++;
        }
    }
    for(int k=beg;k<index;k++){
        arr[k]=temp[k];
    }
}
int merge_sort(int arr[],int beg,int end){
int mid;
if(beg<end){
        mid=(beg+end)/2;

        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,beg,mid,end);

}}
int main(){
    int t,arr[100000],n,k,ta[100];
cin>>t;
int test_case=t;
int j=0;
while(t--){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1);
    cin>>k;
     ta[j]=arr[k-1];
     j++;




}
for(int i=0;i<test_case;i++ ){
    cout<<ta[i];
    cout<<endl;
}

return 0;}


