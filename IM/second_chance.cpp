#include<iostream>
using namespace std;

int main()
{
    int s, fs, i, j, k=0, fault=0, m, temp=0;
    cout<<"Enter the no. of page: ";
    cin>>s;
    cout<<"Enter frame size: ";
    cin>>fs;
    int data[s], frame[fs], ref_bit[fs];

    for(i=0; i<fs; i++)
    {
        frame[i] = 9999;
        ref_bit[i] = 0;
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
                ref_bit[j] = 1;
                break;
            }
        }
        if(j == fs)
        {
            for(k=0; ; )
            {
                if(ref_bit[0] == 1)
                {
                    temp = frame[0];
                    for(m=0; m<fs-1; m++)
                    {
                        frame[m] = frame[m+1];
                        ref_bit[m] = ref_bit[m+1];
                    }
                    frame[fs-1] = temp;
                    ref_bit[fs-1] = 0;
                    continue;
                }
                else
                {
                    for(m=0; m<fs-1; m++)
                    {
                        frame[m] = frame[m+1];
                        ref_bit[m] = ref_bit[m+1];
                    }
                    break;
                }
            }
            frame[fs-1] = data[i];
            fault++;
        }
        for(m=0; m<fs; m++)
        {
            cout<<frame[m]<<" ";
        }
        cout<<endl;
        for(m=0; m<fs; m++)
        {
            cout<<ref_bit[m]<<" ";
        }
        cout<<endl;

    }
    cout<<fault;
}
