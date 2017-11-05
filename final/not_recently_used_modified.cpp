#include<iostream>
using namespace std;

int ref_bit[50], mod_bit[50];

void set_ref(int i, int fs)
{
    int m;
    cout<<"\nEnter reference bit: ";
    for(m=0; m < fs; m++)
    {
        cin>>ref_bit[m];
        if(m==fs-1)
            break;
    }

    cout<<"\nEnter modification bit: ";
    for(m=0; m < fs; m++)
    {
        cin>>mod_bit[m];
        if(m==fs-1)
            break;
    }
}

int least(int ref[], int mod[])
{
    int length = sizeof(ref);
    int index[length], ind, small;
    for(int i=0; i<length-1; i++)
    {
        if(ref[i]==0 && mod[i]==0)
            index[i] = 0;
        else if(ref[i]==0 && mod[i]==1)
            index[i] = 1;
        else if(ref[i]==1 && mod[i]==0)
            index[i] = 2;
        else
            index[i] = 3;
    }
    small = index[0];
    ind = 0;
    for(int i=1; i<length-1; i++)
    {
        if(index[i] < small)
        {
            small = index[i];
            ind = i;
        }
    }
    return ind;
}

int main()
{
    int s, fs, i, j, k=0, fault=0, m, temp=0;
    cout<<"Enter the number of page: ";
    cin>>s;
    int data[s], hit=0;
    cout<<"Enter pages: ";
    for(i=0; i<s; i++)
    {
        cin>>data[i];
    }
    cout<<"Enter frame size: ";
    cin>>fs;
     int frame[fs];

    for(i=0; i<fs; i++)
    {
        frame[i] = 9999;
    }

    for(i=0; i<s; i++)
    {
        for(j=0; j<fs; j++)
        {
            if(frame[j] == 9999)
            {
                frame[j] = data[i];
                fault += 1;
                break;
            }
            else if(frame[j]==data[i])
                break;
        }
        if(j==fs)
        {
            if(i>0)
                set_ref(i, fs);

            int r = least(ref_bit, mod_bit);
            frame[r] = data[i];
            fault += 1;
        }

        cout<<"\nCurrent Page Status: ";
        for(m=0; m<fs; m++)
        {
            if(frame[m]!=9999)
            cout<<frame[m]<<" ";
            else
                cout<<" ";
        }
        cout<<endl;
    }
    cout<<"\nTotal Page Fault: "<<fault<<endl;
}
