#include<iostream>
using namespace std;

int main()
{
    int s, fs, i, j, k=0, fault=0, l, temp=0, m;
    cout<<"Enter the no. of page: ";
    cin>>s;
    cout<<"Enter frame size: ";
    cin>>fs;
    int data[s], frame[fs];

    for(i=0; i<fs; i++)
    {
        frame[i] = 9999;
    }

    for(i=0; i<s; i++)
    {
        cin>>data[i];
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
            else if(data[i] == frame[j])
            {
                if(j<fs-1)
                {
                    for(l=j; l<fs-1; l++)
                        frame[l] = frame[l+1];
                }
                frame[fs-1] = data[i];
                break;
            }
        }
       // cout<<fault<<endl;
        if(j == fs)
        {
            for(k=0; k<fs-1; k++)
            {
                frame[k] = frame[k+1];
            }
            frame[fs-1] = data[i];
            fault += 1;
        }
        for(m=0; m<fs; m++)
        {
            cout<<frame[m]<<" ";
        }
        cout<<endl;
    }
    cout<<fault;
}
