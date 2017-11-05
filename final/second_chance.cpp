#include<iostream>
using namespace std;

int ref_bit[50];

void set_ref(int i, int fs)
{
    cout<<"\nEnter references :";
    for(int m=0; m < i; m++)
    {
        cin>>ref_bit[m];
        if(m==fs-1)
            break;
    }
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
            else if(data[i] == frame[j])
            {
                break;
            }
        }
        if(j == fs)
        {
            if(i>0)
                set_ref(i, fs);
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

        cout<<"\nCurrent Page Status: ";
        for(m=0; m<fs; m++)
        {
            if(frame[m]!=9999)
            cout<<frame[m]<<" ";
            else
                cout<<" ";
        }
        cout<<endl;

        if(j==fs)
        {
            cout<<"\nCurrent references: ";
        for(m=0; m<fs; m++)
        {
            cout<<ref_bit[m]<<" ";
        }
        cout<<endl;
        }
    }
    cout<<"\nTotal Page Fault: "<<fault<<endl;
}
