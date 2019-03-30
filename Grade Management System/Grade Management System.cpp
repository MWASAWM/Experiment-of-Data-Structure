#pragma GCC diagnostic error "-std=c++11"//support the c++11 standard
#include<bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////////////////////////////
#define all(v) v.begin(),v.end()//all of a container,simplify the coding
#define p(c) puts(#c);//simplify the "puts" function
#define fi(i,a,b) for(int i=a;i<b;i++)//simplify the for loop
////////////////////////////////////////////////////////////////////////////
struct student{string id,name,gender;double score[3],total_score;};//the data structure of a student
vector<student>table;//use vector to store the information of students
void line(){p(-------------------------------------------------------------------------------------------------------)}//for beauty
void start_interface()//output the start interface,which is menu
{
    p(---------------MENU---------------)
    p(1 Add students information)
    p(2 Display students information)
    p(3 Search student)
    p(4 Insert a student)
    p(5 Delete a student)
    p(6 Calculate)
    p(7 Sort)
    p(0 Exit)
    p(----------------------------------)
}
void fun_1()//Add students information
{
    p(Input Student Number:)
    int n;cin>>n;
    line();
    p(Please input ID Name Gender and 3 Courses Grades)
    fi(i,0,n)//input the fundamental information of some students and calculate their average score automatically
    {
        student a;
        cin>>a.id>>a.name>>a.gender;fi(i,0,3)cin>>a.score[i];
        a.total_score=accumulate(a.score,a.score+3,0.0);
        table.push_back(a);//store to the table
    }
    line();
    p(Input Successfully.)//feedback
    line();
}
void fun_2()//Display all of the students information
{
    cout<<setw(10)<<"ID"<<" "<<setw(15)<<"Name"<<" "<<setw(15)<<"Gender"<<" ";
    cout<<setw(15)<<"Course A"<<setw(15)<<"Course B"<<setw(15)<<"Course C"<<setw(15)<<"Total"<<endl;
    auto it=table.begin();
    while(it!=table.end())//traverse and output the table which stores the information of students
    {
        cout<<fixed<<setw(10)<<setprecision(0)<<(*it).id<<" "<<setw(15)<<(*it).name<<" "<<setw(15)<<(*it).gender<<" ";
        fi(i,0,3)cout<<setw(15)<<(*it).score[i];
        cout<<setw(15)<<accumulate((*it).score,(*it).score+3,0.0)<<endl;
        it++;
    }
    line();

}
void fun_3()//Search a student
{
    p(You can input ID or name to search)
    string search_key;cin>>search_key;
    line();
    int k=-1;
    auto it=table.begin();
    while(it!=table.end())//look for the student and store the location of the student if found
    {
        if(search_key==(*it).id||search_key==(*it).name){k=it-table.begin();break;}it++;
    }
    if(k==-1){p(Not Found!!!)line();}
    else//if found,print the information of the student
    {
        cout<<setw(10)<<"ID"<<" "<<setw(15)<<"Name"<<" "<<setw(15)<<"Gender"<<" ";
        cout<<setw(15)<<"Course A"<<setw(15)<<"Course B"<<setw(15)<<"Course C"<<setw(15)<<"Total"<<endl;
        cout<<fixed<<setw(10)<<setprecision(0)<<(*it).id<<" "<<setw(15)<<(*it).name<<" "<<setw(15)<<(*it).gender<<" ";
        fi(i,0,3)cout<<setw(15)<<(*it).score[i];
        cout<<setw(15)<<(*it).total_score<<endl;
        line();
    }
}
void fun_4()//Insert a student
{
    p(Please Input ID Name Gender and 3 Courses Grades)
    student a;cin>>a.id>>a.name>>a.gender;fi(i,0,3)cin>>a.score[i];a.total_score=accumulate(a.score,a.score+3,0.0);
    //input the fundamental information of the student and calculate his average score automatically
    table.push_back(a);//store to the table
    line();
    p(Insert Completely.)
    line();
}
void fun_5()//Delete a student
{
    p(You can input ID or name to delete)
    string delete_key;cin>>delete_key;
    line();
    int k=-1;
    auto it=table.begin();
    while(it!=table.end())//search the matching student and remain the location for further operation
    {
        if(delete_key==(*it).id||delete_key==(*it).name){k=it-table.begin();break;}
        it++;
    }
    if(k==-1)p(Not Found!!!)
    else table.erase(table.begin()+k),p(Delete Completely.)//erase his information from table if find
    line();
}
void fun_6()//Calculate
{
    double ave[4];
    fi(i,0,3)
    {
        ave[i]=0;
        auto it=table.begin();
        while(it!=table.end())ave[i]+=(*it).score[i],it++;
        ave[i]/=table.size();
    }
    auto it=table.begin();
    while(it!=table.end())ave[3]+=(*it).total_score,it++;
    ave[3]/=table.size();
    cout<<setw(15)<<"Course A"<<setw(15)<<"Course B"<<setw(15)<<"Course C"<<setw(15)<<"Total"<<endl;
    fi(i,0,4)cout<<fixed<<setw(15)<<setprecision(2)<<ave[i];
    p()line();
}
void fun_7()//Sort
{
    p(Please Choose the Sort Rule:)
    p(1 ID)
    p(2 Total Score)
    p(3 Course A)
    p(4 Course B)
    p(5 Course C)
    int k;cin>>k;//choose the sort rule
    switch(k)
    {
        case 1:sort(all(table),[](student a,student b){return a.id<b.id;});break;//sort by id
        case 2:sort(all(table),[](student a,student b){return a.total_score>b.total_score;});break;//sort by total score
        case 3:sort(all(table),[](student a,student b){return a.score[0]>b.score[0];});break;//sort by the score of course A
        case 4:sort(all(table),[](student a,student b){return a.score[1]>b.score[1];});break;//sort by the score of course B
        case 5:sort(all(table),[](student a,student b){return a.score[2]>b.score[2];});break;//sort by the score of course C
    }
    line();
    p(Sort Compelely.)
    line();
}
int main()
{
    start_interface();
    cout.setf(ios::left);
    while(1)
    {
        p(Input your choice:)
        int key;cin>>key;line();//choose the function
        if(key==0)break;
        switch(key)
        {
            case 1:fun_1();break;//Add students information
            case 2:fun_2();break;//Display students information
            case 3:fun_3();break;//Search student
            case 4:fun_4();break;//Insert a student
            case 5:fun_5();break;//Delete a student
            case 6:fun_6();break;//Calculate
            case 7:fun_7();break;//Sort
        }
    }
    return 0;
}
