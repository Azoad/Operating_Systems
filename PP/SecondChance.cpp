#include<iostream>

using namespace std;

int main()
{
    int n,nf,k,m,cf=0,c=0;
    int p[100],pf[100],rf[100];
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
        rf[i]=0;
    }

    for(int i=0;i<n;i++){
        cout<<"For "<<p[i]<<": ";
        hit=false;
        for(int j=0;j<nf;j++){
            if(p[i]==pf[j]){
                hit=true;
                rf[j]=1;
                break;
            }
        }

        if(hit){
            cout<<"No page fault"<<endl;
        }
        else
        {
            again:
            for(k=0;k<nf-1;k++){
                if(rf[k]==0){
                    pf[k]=pf[k+1];
                    rf[k]=rf[k+1];
                    rf[k+1]=0;
                }else
                {
                    rf[k]=0;
                    int temp=pf[k];
                    for(m=k;m<nf-1;m++){
                        pf[m]=pf[m+1];
                        rf[m]=rf[m+1];
                        rf[m+1]=0;
                    }
                    pf[m]=temp;
                    k=0;
                    goto again;
                }
            }

            pf[k]=p[i];

            if(cf<nf){
                cf++;
            }
            c++;
            for(k=0;k<nf;k++){
                     if(pf[k]!=-1){
                        cout<<pf[k]<<" ";
                     }

            }
            cout<<endl;
        }
        if(!hit){
        if(c==nf){
            cout<<"Enter the reference bits :";
            for(k=0;k<nf;k++){
                cin>>rf[k];
            }
        }
        }
    }
    cout<<endl<<"Page fault :"<<c<<endl;
}
