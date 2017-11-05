#include<iostream>

using namespace std;

int main()
{
    int n,nf,k,c=0;
    int p[100],pf[100];
    bool hit;

    cout<<"Enter the number of pages :";
    cin>>n;

    cout<<"Enter the page sequence :";
    for(int i=0;i<n;i++){
        cin>>p[i];
    }

    cout<<"Enter the size of page frame :";
    cin>>nf;

    for(int i=0;i<nf;i++){
        pf[i]=-1;
    }

    for(int i=0;i<n;i++){
        cout<<"For "<<p[i]<<": ";
        hit=false;
        for(int j=0;j<nf;j++){
            if(p[i]==pf[j]){
                hit=true;
                break;
            }
        }

        if(hit){
            cout<<"No page fault"<<endl;
        }
        else
        {
            for(k=0;k<nf-1;k++){
                pf[k]=pf[k+1];
            }
            pf[k]=p[i];
            c++;

            for(k=0;k<nf;k++){
                if(pf[k]!=-1){
                    cout<<pf[k]<<" ";
                }
            }
            cout<<endl;
        }
    }
    cout<<endl<<"Page fault :"<<c<<endl;
}
