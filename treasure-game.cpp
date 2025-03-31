#include<iostream>
#include<vector>
#include<conio.h>
#include<ctime>
#include<cstdlib>
using namespace std;
class game{
    public:
    int row;
    int col;
    int t;
    int tr;
    int p_r;
    int p_c;
    vector<vector<char>>v;
    game(int a,int b):row(a),col(b),v(a,vector<char>(b,'*')),p_r(0),p_c(0){}
    void mod();
    void dis();
    void treasure();
    void trap();
    void key();
    void easy(int arr[],vector<string>e) 
    {
      t=arr[0];
      tr=arr[1];
    }
    void m(int arr[],vector<string>e)
    {
      t=arr[0];
      tr=arr[1];
    }
    void h(int arr[],vector<string>e)
    {
      t=arr[0];
      tr=arr[2];
    }
};
void game::mod()
{
    int arr[3]={4,6,5};
    vector<string>e={"Easy","Medium","Hard"};
    for(int i=0;i<e.size();i++)
    {
        cout<<i+1<<") "<<e[i]<<endl;
    }
    int ch;
    cout<<":::enter your choice:::"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:
        easy(arr,e);
        break;
        case 2:
        m(arr,e);
        break;
        case 3:
        h(arr,e);
        break;
        default:
        cout<<"you are not entering correct::"<<endl;
    }
}
void game::dis()
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            v[i][j] = '*';
        }
    }
    v[p_r][p_c] = 'P';  
    treasure();  
    trap();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
void game::treasure()
{
    int e=0;
    while(e<t)
    {
     int g=rand()%row;
     int x=rand()%col;
     if(v[g][x]=='*'&&v[g][x]!='X'&&v[g][x]!='P')
     {
        v[g][x]='T';
        e++;
    }
}

    }
    void game::trap()
    {
        int tra_c=0;
    while(tra_c<tr)
    {
     int g=rand()%row;
     int x=rand()%col;
     if(v[g][x]=='*'&&v[g][x]!='T'&&v[g][x]!='P')
     {
        v[g][x]='X';
        tra_c++;
     }
    }
    
}
void game::key()
{
    char se;
    cout<<"Enter the position you want to move ::::w|up:::s|down:::a|left:::d|right:::"<<endl;
    cin>>se;
    v[p_r][p_c]='*';
    switch(se)
    {
        case 'w':
        if(p_r>0)p_r--;
        break;
        case 's':
        if(p_r<row-1)p_r++;
        break;
        case 'a':
        if(p_c>0)p_c--;
        break;
        case 'd':
        if(p_c<col-1)p_c++;
        break;
        default:
        cout<<"you are not entering the right command:::"<<endl;
    }
    v[p_r][p_c] ='P';
}
int main()
{
    srand(time(0));
    int r;
    int c;
    cout<<"enter how many large you want the grid map::"<<endl;
    cout<<"first enter the row limit 5-10::"<<endl;
    cin>>r;
    if(r>10)
    {
        cout<<"not in limit enter again::"<<endl;
        cin>>r;
    }
    cout<<"now enter the column limit 5-10::"<<endl;
    cin>>c;
    if(c>10)
    {
        cout<<"not in limit enter again::"<<endl;
        cin>>c;
    }
 vector<game>g1;
 g1.push_back(game(r,c));
 cout<<"now choose the game Mod::"<<endl;
 g1[0].mod();
 cout<<"Press Enter to start of the game::"<<endl;
 getch();
g1[0].dis();
while (true) {
    g1[0].key();
    g1[0].dis();
}
}