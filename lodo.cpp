#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;
class lodo{
    public:
    string name;
    string color;
    lodo(string n,string c):name(n),color(c){
        
    }
};
class game{
public:
    vector<lodo>play;
    game(){
    play.push_back(lodo("player 1","red"));
    play.push_back(lodo("player 2","green"));
    play.push_back(lodo("player 3","blue"));
    play.push_back(lodo("player 4","yellow"));
}
};
class token{
    public:
    int p=0;
    bool h=false;
    void dic(int pl){
        cout<<"press enter to dice roll "<<"player "<<pl<<endl;
        cin.ignore();
        int x=rand()% 6 + 1;
        cout<<"player: "<<pl<<" dice rolls to: "<<x<<" and at the position "<<"("<<p+x<<")"<<endl;
        data(x,p);
    } 
    void data(int x,int &p)
        {
            p+=x;
            if(p>=50)
            {
                p=50;
                h=true;
            }
        }
        bool win()
        {
            return h;
        }
};
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    vector<token>t(4);
    game g1;  
    bool w=false;
    cout<<"welcome to the lodo game:"<<endl;
    cout<<"press enter to start the game:"<<endl;
    cin.ignore(); 
    while(!w){
    for(int i=0;i<4;i++)
    {
        cout<<"now the turn of the player is:"<<g1.play[i].name<<endl;
        t[i].dic(i+1);
        if (t[i].win()) {
            cout << "Player " << i + 1 << " (" << g1.play[i].name << ") wins!" << endl;
            w =true;
            break;  
        }
    
    }
    }
}