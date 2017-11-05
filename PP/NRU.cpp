#include<iostream>
#include<algorithm>

using namespace std;

int val(int r,int m)
{
    if(r==0&&m==0)
    {
        return 0;
    }
    else if(r==0&&m==1)
    {
        return 1;
    }
    else if(r==1&&m==0)
    {
        return 2;
    }
    else if(r==1&&m==1)
    {
        return 3;
    }
}

int main()
{
    int n,nf,k,minVal,index,cf=0,c=0;
    int p[100],pf[100],rf[100],m[100],value[100],tmpvalue[100];
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
        m[i]=0;
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
            for(k=0;k<nf;k++){

            //cout<<pf[k]<<"("<<rf[k]<<")"<<"("<<m[k]<<")"<<" ";

            }
            cout<<"No page fault"<<endl;
        }
        else
        {
            for(k=0; k<nf; k++)
            {
                value[k]=val(rf[k],m[k]);
                tmpvalue[k]=val(rf[k],m[k]);
            }
            sort(tmpvalue,tmpvalue+nf);
            minVal=tmpvalue[0];
            for(k=0; k<nf; k++)
            {
                if(value[k]==minVal)
                {
                    break;
                }
            }
            index=k;
            if(pf[index]==-1){
                if(cf<nf){
                cf++;
                }
            }
            pf[index]=p[i];
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
            for(k=0;k<cf;k++){
                cin>>rf[k];
            }
            cout<<"Enter the modification bits :";
            for(k=0;k<cf;k++){
                cin>>m[k];
            }
        }
        }
    }
    cout<<endl<<"Page fault :"<<c<<endl;
}

