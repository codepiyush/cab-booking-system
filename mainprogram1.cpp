#include <fstream>
#include <iostream>
#include <limits>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
T get_input(const string &strQuery);
void login();
void register_user();
void main_menu();

void login()
{
    string line = " ";
    ifstream readFile("credentials.txt");
    string UserName ,Password, _UserName,_Password;
    cout << "Enter UserName: ";
    cin >> UserName;
    cout << "Enter Password: ";
    cin >> Password;
    bool found = false;

    while (getline(readFile,line))
    {
        stringstream iss(line);
        iss >> _UserName >> _Password;
        if (UserName == _UserName && Password == _Password)
        {   cout << "Login Successful!"<< endl;
            found = true;
            break;
        }
    }

    if (found==false)
    {
        cout << "Invalid Username And Password"<< endl;
        cout<<"To Register 1 and for Logging again press 2"<<endl;
        int choice;
        A:
        cin>>choice;
        switch(choice)
        {
            case 1:
                register_user();
                break;
            case 2:
                login();
                break;
            default:
            cout<<"Wrong input.\n> ";
            goto A;
        }
    }

}
void main_menu()
{
    int choice;
    cin>>choice;
    B:
    switch (choice)
    {
        case 1:
            login();
            break;
        case 2:
            register_user();
            cout<<"\t\t\t\t\t\t";
            for(int i=0;i<5;i++)
            {
                cout<<".";
                Sleep(100);
            }
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout <<"\t\t\t\t\tRegistered Successfully!"<< endl;
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<"Wrong input. Please enter your choice again.\n> ";
            cin>>choice;
            goto B;
    }
}
void save(const string &username, const string &password)
{
    ofstream myfile;
    myfile.open ("credentials.txt",ios::app);
    myfile << username<< " "<< password;
    myfile<<'\n';
    myfile.close();
}
void register_user()
{
    string username;
    cin>>username;
    string password;
    cin>>password;
    save(username, password);
}


class Pair
{
    public:
        string destination;
        float dist;
        int condition;
        Pair(string dest, float weight,int cond=1)
        {
            destination=dest;
            dist=weight;
            condition=cond;
        }
};

class myComparator
{
    public:
        int operator() (Pair p1, Pair p2)
        {
            return p1.dist > p2.dist;
        }
};
class Graph
{
    int V;
    map<string, list< Pair > > adjList;
    public:
        Graph(int v)
        {
            V=v;
        }
        void addEdge(string src, string dest,float wt,int condition)
        {
            Pair p (dest,wt,condition);
            Pair k (src,wt,condition);
            adjList[src].push_back(p);
            adjList[dest].push_back(k);
        }
        void print();

        for(auto it=adjList.begin();it!=adjList.end();it++)
            {
                cout<<"\t\t\t"<<(it)->first<<"-->\t\t";
                for(auto lit=((it)->second).begin();lit!=((it)->second).end();lit++)
                {
                   cout<<(lit)->destination<<", ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        void printAllPathsUtil(string u, string d, map<string,bool> &visited, string path[], int &path_index,int cond,float wt,int rate)
        {
            visited[u] = true;
            path[path_index] = u;
            path_index++;
            if (u.compare(d)==0)
            {
                cout<<"\t\t\t";
                int i;
                for (i = 0; i<path_index-1; i++)
                    cout << path[i] << "-->";
                cout << path[i];
                cout<< "\t\t\tThe distance for the route being "<< wt<<" KM"<<endl;
                cout << endl;
                cout<<"\t\t\tThe cost of Travel Inclusive of Taxes : Rs "<<wt*rate<<endl;
                cout << endl;
            }
            else
            {
                for (auto i = adjList[u].begin(); i != adjList[u].end(); ++i)
                    if (!visited[i->destination])
                        printAllPathsUtil(i->destination,d, visited, path, path_index,cond+i->condition,wt+i->dist,rate);
            }
            path_index--;
            visited[u] = false;
        }
        void Validate_input(string &src,string &des)
        {
            if(( adjList.find(src) == adjList.end() ))
            {
                cout<<"\t\t\t\tSource Could Not be Found, Renter\n";
                string src1;
                cin>>src1;
                src=src1;
            }
            if(( adjList.find(des) == adjList.end() ))
            {
                cout<<"\t\t\t\tDestination Could Not be Found, Renter\n";
                string des1;
                cin>>des1;
                des=des1;
            }
        }
        void printAllPaths(string s, string d,int rate)
        {
            map<string,bool> visited;
            for(auto it=adjList.begin();it!=adjList.end();it++)
            {
                visited[it->first]=false;
            }
            string *path = new string[V];
            int path_index = 0;
            printAllPathsUtil(s, d, visited, path, path_index,0,0,rate);
        }
        void Dijkstras(string src,string des,int rate)
        {
            /*to print the path having the shortest distance*/
            map<string ,float > distance;
            map<string, int> conditions;
            map<string,string> parent;
            for(auto it=adjList.begin();it!=adjList.end();it++)
            {
                distance[it->first]=INT_MAX;
            }
            distance[src]=0;
            conditions[src]=0;
            priority_queue<Pair,vector<Pair>, myComparator> Q;
            Pair P(src,distance[src],conditions[src]);
            Q.push(P);
            string last;
            while(!Q.empty())
            {
                Pair Temp=Q.top();
                Q.pop();
                string u=Temp.destination;last=Temp.destination;
                for(auto it=adjList[u].begin();it!=adjList[u].end();it++)
                {
                    Pair f = *it;
                    string v = f.destination;
                    float w = f.dist;
                    int cond=f.condition;
                    if(distance[u]+w<distance[v])
                    {
                        parent[v]=u;
                        distance[v]=distance[u]+w;
                        conditions[v]=conditions[u]+cond;
                        Pair L(v,distance[v],conditions[v]);
                        Q.push(L);
                    }
                }
            }
            if(distance[des]==INT_MAX)
            {
                cout<<"No Path";
                exit(0);
            }
           
            cout<<"\t\t\tThe shortest distance between "<<src<<" and "<<des<< " is : "<<distance[des]<<" KM"<<endl;
           
            cout<<"\t\t\tThe cost of Travel : Rs "<<distance[des]*rate<<endl;
            
            cout<<"\t\t\tThe path Of the Shortest Route is: "<<endl;
            
            cout<<"\t\t\t";
            string k=des;
            cout<<k<<"<--";
            while(parent[k].compare(src)!=0)
            {
                cout<<parent[k]<<" <--";
                k=parent[k];
            }
            cout<<src;
};


int main()
{
    Graph g(75);
    main_menu();
    Sleep(2000);
    system("cls");
    string line = " ";

    string source,destination,distance,condition;
    ifstream readFile("Distance-From-City.txt");
    while (getline(readFile,line))
    {
        stringstream iss(line);
        iss >> source >> destination >> distance >> condition;
        float D= strtof((distance).c_str(),0);
        int C= atoi((condition).c_str());
        g.addEdge(source,destination,D,C);
    }
    cout<<"CITIES";
    Sleep(1000);
    g.print();
    cout<<"\t\t\tEnter the City from the list above:\t";
    string src;
    cin>>src;
    cin.ignore();
    cout<<"\t\t\tEnter Your Destination:\t";
    string dest;
    cin>>dest;
    if(src.compare(dest)==0)
    {
        return 0;
    }
    g.Validate_input(src,dest);
            g.Dijkstras(src, dest, 8);
            cout<<"\n\nALL ROUTES FROM SOURCE TO DESTINATION"<<endl;
            g.printAllPaths(src,dest,8);
            break;
    return 0;
}
