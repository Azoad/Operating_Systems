#include<iostream>
using namespace std;

int main()
{
    int s, fs, i, j, k=0, fault=0, m;
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
            else if(data[i] == frame[j])
                break;
        }
        if(j == fs)
        {
            for(k=0; k<fs-1; k++)
            {
                frame[k] = frame[k+1];
            }
            frame[fs-1] = data[i];
            fault++;
        }
        cout<<"\nCurrent Page Status: ";
        for(m=0; m<fs; m++)
        {
            cout<<frame[m]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nTotal Page Fault: "<<fault<<endl;
}
