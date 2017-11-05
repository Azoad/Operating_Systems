#include<iostream>

using namespace std;

int main()
{
    int n,nf,k,cf=0;
    int l=0;
    int p[200];
    int pf[100];
    int r[100];
    int rf[100];
    bool hit;
    int count=0;

    cout<<"Enter the length of page sequence: ";
    cin>>n;
    cout<<"Enter the pages: ";
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }

    cout<<"Enter the size of page frame: ";
    cin>>nf;

    //Initialize page frame
    //Initialize reference bit
    for(int i=0; i<nf; i++)
    {
        pf[i]=99999;
        rf[i]=0;
    }
    cout<<endl;

    //Check for each page
    for(int i=0; i<n; i++)
    {
        hit=false;
        cout<<"For "<<p[i]<<": ";

        //Check if hit or miss
        for(int j=0; j<nf; j++)
        {
            if(p[i]==pf[j])
            {
                hit=true;
                r[j]=1;
                break;
            }
        }

        //When page hit occurs
        if(hit)
        {

            for(k=0; k<nf; k++)
            {
                if(pf[k]!=99999)
                {
                    //cout<<pf[k]<<"("<<r[k]<<")"<<"("<<l<<")"<<" ";
                }
            }
            //cout<<endl;
            cout<<"No page fault"<<endl;
        }

        //When page fault occurs
        else
        {
            for(k=l; k<nf; k++)
            {
                if(rf[k]==0)
                {
                    break;
                }
                else
                {
                    rf[k]=0;
                    continue;
                }

            }
            if(k>nf-1){
                k=0;
            }
            if(l>0&&rf[k]!=0)
            {
                for(k=0; k<l; k++)
                {
                    if(rf[k]==0)
                    {
                        break;
                    }
                    else
                    {
                        rf[k]=0;
                        continue;
                    }
                }
            }
            pf[k]=p[i];
//            r[k]=rf[i];
            if(k<nf-1){
                l=k+1;
            }else
            {
                l=0;
            }

            //Display page frame on each iteration
            for(k=0; k<nf; k++)
            {
                if(pf[k]!=99999)
                {
                    cout<<pf[k]<<" ";
                    //cout<<pf[k]<<"("<<r[k]<<")"<<"("<<l<<")"<<" ";
                }
            }
            cout<<endl;
            count++;
            if(cf<nf){
                cf++;
            }
        }
        if(!hit){
        if(i<n-1){
            cout<<"Enter the reference bits :";
            for(k=0;k<cf;k++){
                cin>>rf[k];
            }
        }
        }
    }
    cout<<endl<<"Page fault: "<<count<<endl;
}

