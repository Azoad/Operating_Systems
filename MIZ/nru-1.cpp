#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
int check_ref_mod(int refbit,int modibit)
{
    if (refbit==0 && modibit==0)
    {
        return 1;
    }
    if (refbit==0 && modibit==1)
    {
        return 2;
    }
    if (refbit==1 && modibit==0)
    {
        return 3;
    }
    if (refbit==1 && modibit==1)
    {
        return 4;
    }
}
int sum(vector<int>temp)
{
    int sum=0;
    for (int i=0; i<temp.size(); i++)
    {
        sum+=temp[i];
    }
    if(sum==0 || sum==temp.size())
        return 1;
    else
    {
        return 2;
    }
}
void not_recently_use()
{
    int total=0;
    int page_no;
    cout<<"Page no: ";
    cin>>page_no;
    int page_array[page_no];
    cout<<"Pages :"<<endl;
    for(int i=0; i<page_no; i++)
    {
        cin>>page_array[i];
    }
    int count=0;
    int frame;
    cout<<"Frame no :"<<endl;
    cin>>frame;
    int refbit[frame];
    int modbit[frame];
    vector<int>insert_page;
    vector<int>temp;
    //cout<<insert_page.size();
    for(int i=0; i<page_no; i++)
    {
        cout<<endl<<"FOR page "<<page_array[i]<<" "<<endl;
        if(insert_page.size()<frame)
        {
            int flag=0;
            for (int j=0; j<insert_page.size(); j++)
            {
                if (insert_page[j]==page_array[i])
                {
                    flag=1;
                    cout<<"No page fault";
                    cout<<endl<<"Page condition "<<endl;
                    for(int k=0; k<insert_page.size(); k++)
                    {
                        cout<<"Frame => "<<k<<" page => "<<insert_page[k]<<" "<<endl;
                    }
                    cout<<endl;
                    break;

                }
                else
                {
                    flag=0;
                }
            }
            if (flag==0)
            {
                insert_page.push_back(page_array[i]);
                cout<<"page fault";
                total++;
                cout<<endl<<"Page condition "<<endl;
                for(int k=0; k<insert_page.size(); k++)
                {
                    cout<<"Frame => "<<k<<" page => "<<insert_page[k]<<" "<<endl;
                }
                cout<<endl;
            }


        }
        else if (insert_page.size()==frame)
        {
            int flag=0;
            for (int j=0; j<insert_page.size(); j++)
            {
                if (insert_page[j]==page_array[i])
                {
                    flag=1;
                    cout<<"No page fault";
                    cout<<endl<<"Page condition "<<endl;
                    for(int k=0; k<insert_page.size(); k++)
                    {
                        cout<<"Frame => "<<k<<" page => "<<insert_page[k]<<" "<<endl;
                    }
                    cout<<endl;
                    break;

                }
                else
                {
                    flag=0;
                }
            }
            if (flag==0)
            {
                cout<<"Input the reference and modification bit"<<endl;
                for (int l=0; l<frame; l++)
                {
                    cout<<endl<<"Reference bit of "<<insert_page[l]<<" "<<endl;
                    cin>>refbit[l];
                    cout<<endl<<"Modification bit of "<<insert_page[l]<<" "<<endl;
                    cin>>modbit[l];
                }
                temp=insert_page;
                int t1,t2;
                int rs;
                t2=5;
                for(int l=0; l<frame; l++)
                {
                    t1=check_ref_mod(refbit[l],modbit[l]);
                    if(t1==1)
                        temp.push_back(0);
                    if(t1==4)
                        temp.push_back(1);
                    if(t2>t1)
                    {
                        rs=l;
                        t2=t1;
                    }
                }
                if(sum(temp)==1)
                {
                    insert_page[0]=page_array[i];
                    cout<<"Page fault";
                    total++;
                    cout<<endl<<"Page condition "<<endl;
                    for(int k=0; k<insert_page.size(); k++)
                    {
                        cout<<"Frame => "<<k<<" page => "<<insert_page[k]<<" "<<endl;
                    }
                    cout<<endl;
                }
                else
                {
                    insert_page[rs] = page_array[i];
                    cout<<"Page fault";
                    total++;
                    cout<<endl<<"Page condition "<<endl;
                    for(int k=0; k<insert_page.size(); k++)
                    {
                        cout<<"Frame => "<<k<<" page => "<<insert_page[k]<<" "<<endl;
                    }
                    cout<<endl;
                }


            }
        }
    }

    cout<<endl<<"Total page fault = "<<total<<endl;

}
void fifo()
{
    int total=0;
    int page_no;
    cout<<"Page no: ";
    cin>>page_no;
    int page_array[page_no];
    cout<<"Pages :"<<endl;
    for(int i=0; i<page_no; i++)
    {
        cin>>page_array[i];
    }
    int count=0;
    int frame;
    cout<<"Frame no :"<<endl;
    cin>>frame;

    vector<int>insert_page;
    vector<int>temp;
    for (int i=0; i<page_no; i++)
    {
        cout<<endl<<"FOR page "<<page_array[i]<<" "<<endl;
        if(insert_page.size()<frame)
        {
            int flag=0;
            for (int j=0; j<insert_page.size(); j++)
            {
                if (insert_page[j]==page_array[i])
                {
                    flag=1;
                    cout<<"No page fault";
                    cout<<endl<<"Page condition "<<endl;
                    for(int k=0; k<insert_page.size(); k++)
                    {
                        cout<<insert_page[k]<<" ";
                    }
                    cout<<endl;
                    break;

                }
                else
                {
                    flag=0;
                }
            }
            if (flag==0)
            {
                insert_page.push_back(page_array[i]);
                cout<<"page fault";
                total++;
                cout<<endl<<"Page condition "<<endl;
                for(int k=0; k<insert_page.size(); k++)
                {
                    cout<<insert_page[k]<<" ";
                }
                cout<<endl;
            }
        }
        else if (insert_page.size()==frame)
        {
            int flag=0;
            for (int j=0; j<insert_page.size(); j++)
            {
                if (insert_page[j]==page_array[i])
                {
                    flag=1;
                    cout<<"No page fault";
                    cout<<endl<<"Page condition "<<endl;
                    for(int k=0; k<insert_page.size(); k++)
                    {
                        cout<<insert_page[k]<<" ";
                    }
                    cout<<endl;
                    break;

                }
                else
                {
                    flag=0;

                }
            }
            if (flag == 0)
            {
                for (int j=1; j<insert_page.size(); j++)
                {
                    insert_page[j-1]=insert_page[j];
                }
                insert_page[insert_page.size()-1]=page_array[i];
                cout<<"page fault";
                total++;
                cout<<endl<<"Page condition "<<endl;
                for(int k=0; k<insert_page.size(); k++)
                {
                    cout<<insert_page[k]<<" ";
                }
                cout<<endl;
            }

        }
    }
    cout<<"Total page fault : "<<total<<endl;
}
void fifo2()
{
    int total=0;
    int page_no;
    cout<<"Page no: ";
    cin>>page_no;
    int page_array[page_no];
    cout<<"Pages :"<<endl;
    for(int i=0; i<page_no; i++)
    {
        cin>>page_array[i];
    }
    int count=0;
    int frame;
    cout<<"Frame no :"<<endl;
    cin>>frame;

    int insert_page[frame];

    int remain;
    for(int i=0; i<frame; i++)
    {
        insert_page[i]= -1 ;
    }
    int j = 0;
    for (int i = 0; i<page_no; i++)
    {
        cout<<endl<<"FOR page "<<page_array[i]<<" "<<endl;
        remain=0;
        for(int k=0; k<frame; k++)
        {
            if(insert_page[k]==page_array[i])
                remain=1;
        }

        if(remain==0)
        {
            insert_page[j]=page_array[i];
            j=(j+1)%frame;
            count++;
            cout<<"page fault";
            cout<<endl<<"Page condition "<<endl;
            for(int k=0; k<frame; k++)
            {
                cout<<"Frame => "<<k<<" page => "<<insert_page[k]<<endl;
            }
        }
        else
        {
            cout<<"NO page fault";
            cout<<endl<<"Page condition "<<endl;
            for(int k=0; k<frame; k++)
            {
                cout<<"Frame => "<<k<<" page => "<<insert_page[k]<<endl;
            }
        }
        printf("\n");
    }
    cout<<endl<<"Total page fault : "<<count<<endl;
}
void second_chance()
{
    int total=0;
    int page_no;
    cout<<"Page no: ";
    cin>>page_no;
    int page_array[page_no];
    cout<<"Pages :"<<endl;
    for(int i=0; i<page_no; i++)
    {
        cin>>page_array[i];
    }
    int count=0;
    int frame;
    cout<<"Frame no :"<<endl;
    cin>>frame;
    int refbit[frame];
    vector<int>insert_page;
    vector<int>temp;
    for (int i = 0; i<page_no; i++)
    {
        cout<<endl<<"FOR page "<<page_array[i]<<" "<<endl;
        if(insert_page.size()<frame)
        {
            int flag=0;
            for (int j=0; j<insert_page.size(); j++)
            {
                if (insert_page[j]==page_array[i])
                {
                    flag=1;
                    cout<<"No page fault";
                    cout<<endl<<"Page condition "<<endl;
                    for(int k=0; k<insert_page.size(); k++)
                    {
                        cout<<"Frame => "<<k<<" page => "<<insert_page[k]<<" "<<endl;
                    }
                    cout<<endl;
                    break;

                }
                else
                {
                    flag=0;
                }
            }
            if (flag==0)
            {
                insert_page.push_back(page_array[i]);
                cout<<"page fault";
                total++;
                cout<<endl<<"Page condition "<<endl;
                for(int k=0; k<insert_page.size(); k++)
                {
                    cout<<"Frame => "<<k<<" page => "<<insert_page[k]<<" "<<endl;
                }
                cout<<endl;
            }
        }
        else if (insert_page.size()==frame)
        {
            int flag=0;
            for (int j=0; j<insert_page.size(); j++)
            {
                if (insert_page[j]==page_array[i])
                {
                    flag=1;
                    cout<<"No page fault";
                    cout<<endl<<"Page condition "<<endl;
                    for(int k=0; k<insert_page.size(); k++)
                    {
                        cout<<"Frame => "<<k<<" page => "<<insert_page[k]<<" "<<endl;
                    }
                    cout<<endl;
                    break;

                }
                else
                {
                    flag=0;
                }
            }
            if (flag==0)
            {

                int rs=0;
                cout<<"Input the reference bit"<<endl;
                for (int l=0; l<frame; l++)
                {
                    cout<<endl<<"Reference bit of "<<insert_page[l]<<" "<<endl;
                    cin>>refbit[l];
                    if (refbit[l]!=1)
                    {
                        rs=1;
                    }

                }

                int t1=2;
                if (rs == 1)
                {
                    int t2;
                    for (int l=0; l<frame; l++)
                    {
                        if (t1>refbit[l])
                        {
                            t1=refbit[l];
                            t2=l;
                        }
                    }
                    insert_page[t2] = page_array[i];
                    cout<<"Page fault";
                    total++;
                    cout<<endl<<"Page condition "<<endl;
                    for(int k=0; k<insert_page.size(); k++)
                    {
                        cout<<"Frame => "<<k<<" page => "<<insert_page[k]<<" "<<endl;
                    }
                    cout<<endl;


                }
                else if (rs == 0)
                {
                    insert_page[0] = page_array[i];
                    cout<<"Page fault";
                    total++;
                    cout<<endl<<"Page condition "<<endl;
                    for(int k=0; k<insert_page.size(); k++)
                    {
                        cout<<"Frame => "<<k<<" page => "<<insert_page[k]<<" "<<endl;
                    }
                    cout<<endl;
                }
            }

        }
    }

    cout<<"Total page fault : "<<total<<endl;
}

void fifo1()
{
    int i,j,k,page[10000],frame[10000],page_no,frame_no,avail,count=0,hit=0;
    printf("\n Enter the number of pages:\n");
    scanf("%d",&page_no);
    printf("\nEnter the page number:\n");
    for(i=0; i<page_no; i++)
    {
        scanf("%d",&page[i]);
    }
    printf("\nEnter the number of frames:\n");
    scanf("%d",&frame_no);
    for(i=0; i<frame_no; i++)
    {
        frame[i]=-1;
    }
    j=0;
    //printf("\t \t page_frames\n");
    // printf("****************************************\n");
    for(i=0; i<page_no; i++)
    {
        printf("For page:%d\n",page[i]);
        avail=0;
        for(k=0; k<frame_no; k++)
        {
            if(frame[k]==page[i])
                avail=1;
        }

        if(avail==0)
        {
            frame[j]=page[i];
            j=(j+1)%frame_no;
            count++;
            printf("\nThe elements in the frame are\n");
            for(k=0; k<frame_no; k++)
            {
                printf("%d\n",frame[k]);
            }
        }
        else
        {
            printf("\nThe elements in the frame are\n");
            for(k=0; k<frame_no; k++)
            {
                printf("%d\n",frame[k]);
            }
        }
        printf("\n");
    }
}
int main()
{
    int p;
    while(1)
    {
        cout<<"Press 1 for FIFO\nPress 2 for Second chance\nPress 3 for NRU\nPress 4 for exit\n";
        cin>>p;
        if (p==1)
        {
            fifo2();
        }
        else if (p==2)
        {
            second_chance();
        }
        else if (p==3)
        {
            not_recently_use();
        }
        else if (p==4)
        {
            return 0;
        }
        else
        {
            cout<<"Choose proper option"<<endl;
        }
    }

}
