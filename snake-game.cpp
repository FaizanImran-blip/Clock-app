#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<ctime>
#include<cstdlib>
using namespace std;
enum direct{st=0,left,right,up,down};
direct d;
int h=20;
int w=20;
int fx,fy;
int tx,ty;
int s;
int tail_x[100],tail_y[100];
int t_len;
bool g;
void set();
void logic();
void input();
void draw();
int main()
{
cout<<"|--------------------------------|"<<endl;
cout<<"::::::::::::SNAKE GAME::::::::::::"<<endl;
cout<<"|--------------------------------|"<<endl;
cout<<"--Press enter to Start the game--"<<endl;
getch();
set();
while(!g)
{
    draw();
    input();
    logic();
    Sleep(30);
    g=true;
}
}
void set()
{
    d=st;
    g=false;
    tx=w/2;
    ty=h/2;
    fx=rand()%w;
    fy=rand()%h;
    s=0;
}
void draw()
{
    system("cls");
    cout<<"\t\t";
    for(int i=0;i<w-8;i++)
    {
        cout<<"||";
    }
    cout<<endl;
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
            if(j==0)
            {
                cout<<"\t\t||";
            }
            else if(i==tx&&j==ty)
            {
                cout<<"O";
            }
            else if(i==fx&&j==fy)
            {
                cout<<"*";
            }
            else{
                bool p=false;
                for(int k=0;k<t_len;k++)
                {
                    if(tail_x[k]==j&&tail_y[k]==i)
                    {
                        cout<<"O";
                        p=true;
                    }
            
                }
                if (!p)
                {
                    cout<<" ";
                } 
            }
            if(j==w-1)
             {
              cout<<" ||";
             }
        }
        cout<<endl;
    }
    cout<<"\t\t";
    for(int i=0;i<w-8;i++)
    {
        cout<<"||";
    }
    cout<<endl;
    cout<<endl;
    cout<<"\t\t\tScore:"<<"["<<s<<"]"<<endl;
}
void input()
{
//pending..
}
void logic()
{
//pending..
}
