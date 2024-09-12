#include<iostream>
#include<string.h>
#include<climits>
#include<fstream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<Windows.h>
using namespace std;
//#define INF 999
#include <iostream>
#include <vector>
#include <limits>
#include <string>

#define INF std::numeric_limits<int>::max()

class Graph {
private:
    std::vector<std::vector<int>> adjacencyMatrix;
    std::vector<std::string> stationNames;

public:
    
    Graph(int numVertices) : adjacencyMatrix(numVertices, std::vector<int>(numVertices, INF)), stationNames(numVertices) {}

    // Add an edge between vertices u and v with weight w
    void addEdge(int u, int v, float w) {
        adjacencyMatrix[u][v] = w;
        adjacencyMatrix[v][u] = w; // Assuming an undirected graph
    }

    // Get the weight of the edge between vertices u and v
    float getEdgeWeight(int u, int v) const {
        return adjacencyMatrix[u][v];
    }

    // Get the name of a station
    std::string getStationName(int vertex) const {
        return stationNames[vertex];
    }

    // Set the name of a station
    void setStationName(int vertex, const std::string& name) {
        stationNames[vertex] = name;
    }

    // Get the number of vertices in the graph
    int getNumVertices() const {
        return adjacencyMatrix.size();
    }
};

// Function to find the shortest distance using Dijkstra's algorithm

void dijkstra(const Graph& graph,int source,unordered_map<string,int>&m)
{
    int V = graph.getNumVertices();
	vector<pair<float,int>> distance(V,{INT_MAX,INT_MAX});
    vector<int> vis(V,0);
    priority_queue<pair<float,int>,vector<pair<float,int>>,greater<pair<float,int>>>q;
    q.push({0,source});
    distance[source].first=0;
    distance[source].second=source;
    while(!q.empty())
    {
        float d=q.top().first;
        int node=q.top().second;
        q.pop();
        
        vis[node]=1;
        
        for(int i=0;i<V;i++)
        {
            float w= graph.getEdgeWeight(node, i);
            if(w!=INF && !vis[i] && d!=INT_MAX && d+w<distance[i].first)
            {
               
                  distance[i].first=d+w;
                  distance[i].second=node;
                  q.push({d+w,i});
            }
        }
        
        }
    

	cout<<"\n\nMinimum Number of Stations from "<<"["<<graph.getStationName(source)<<"]"<<" To every station\n\n\n"<<endl;
	for(int k=0;k<V;k++){
	
	cout<<"Enter"<<" "<<k<<" "<<"To Cheak Distance Between "<<graph.getStationName(source)<<" To "<<"["<<graph.getStationName(k)<<"]"<<" "<<"Station"<<endl;
	}
int n;
cout<<"Enter Station to cheak distance to Each other:"<<endl;
cin>>n;
		cout<<"Total Distance from "<<"["<<graph.getStationName(source)<<"]"<<" To "<<graph.getStationName(n)<<"  are  "<<"["<<distance[n].first<<"]"<<"KM"<<endl;
			for(int k=source;k<=n;k++){
	
	cout<<graph.getStationName(source)<<" -> "<<graph.getStationName(k)<<" "<<"Station"<<"["<<distance[k].first<<"]"<<"KM"<<" "<<"from"<<" "<<graph.getStationName(distance[k].second)<<endl;
	}
    string t=graph.getStationName(distance[n].second);
    string path="";
    cout<<endl<<"Here is the shortest path between Source and Destination:"<<endl;
    path+=graph.getStationName(n);
    string dis="";
    dis+=to_string(distance[n].first);
    while(t!=graph.getStationName(source))
    {
       
        path=t+" -> "+path;
        
        int x=m[t];
        dis=to_string(distance[x].first)+" -> "+dis;
        t=graph.getStationName(distance[x].second);

    }
    path=t+" -> "+path;
    dis=to_string(distance[m[t]].first)+" -> "+dis;
    dis+=" km";
    cout<<path<<endl;
    cout<<dis<<endl;
}

int login()
{
    char dum,u_name[30],name[30],g_pwd[30],pwd[30];
    int flag=0,s=1;
 cout<<"\n\n\n\n\n\n\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"<<endl;
    cout<<"\t\t\t\t\t\t*WELLCOME TO LOGIN*"<<endl;
    cout<<"\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb "<<endl;
    if(s==1){

cout<<"Enter your USER NAME  : "<<endl;
          string phrase = "Enter your USER NAME And PASSWORD: ";
        string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
        system(charCommand);
    cin>>name;
}

        cout<< "Enter the PASSWORD   : "<<endl;
//        string command = "espeak \"" + phrase + "\"";
//    const char *charCommand = command.c_str();
//        system(charCommand);
    cin>>pwd;
    fstream f;
    f.open("user_logins.txt",ios::in);
    f.seekg(0);
    while(f)
    {
        f.get(dum);
        f.get(u_name,30);
        f.get(dum);
        f.get(g_pwd,30);
        if(strcmp(u_name,name)==0&&strcmp(pwd,g_pwd)==0)
        {
            flag=1;
             string phrase = "\n\t\t\tYou have Successfully LOGGED IN ";
        string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
        system(charCommand);
            break;
        }
        else if(strcmp(u_name,name)==0&&strcmp(pwd,g_pwd)!=0)
        {
            do
            {
                 string phrase = "\t\t\t----INCORRECT PASSWORD!!!----";
        string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
        system(charCommand);
                
               
                           cout<<"Re-Enter the PASSWORD : "<<endl;
       
                cin>>pwd;
            }while(strcmp(pwd,g_pwd)!=0);
            
        string phrase = "\n\t\t\tYou have Successfully LOGGED IN";
        string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
        system(charCommand);
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"\n\t\t\tSORRY!!! USER NAME and PASSWORD does not Exist"<<endl;
    system("CLS");
    f.close();
    return flag;
}

void signup()
{
 cout<<"\n\n\n\n\n\n\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb "<<endl;
    cout<<"\t\t\t\t\t\t*WELLCOME TO SIGNUP*"<<endl;
    cout<<"\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb "<<endl;
    char name[30],pwd[30],check_pwd[30];
    fstream f;
    f.open("user_logins.txt",ios::in);
    char g_name[30],g_pwd[30],dum;
    int flag;
    cout<<"Enter the USER NAME : ";
     string phrase = "Enter your USER NAME And PASSWORD: ";
        string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
        system(charCommand);
    cin>>name;
    do
    {
        f.seekg(0);
        while(f)
        {
            flag=1;
            f.get(dum);
            f.get(g_name,30);
            f.get(dum);
            f.get(g_pwd,30);
            if(strcmp(g_name,name)==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"\n\t\t\t----SORRY! USER-NAME ALREADY EXIST----"<<endl;
            cout<<"Enter the USER NAME : ";
            cin>>name;
        }
    }while(flag==0);
    f.close();
    f.open("user_logins.txt",ios::out|ios::app);
    cout<<"Enter your PASSWORD : ";
    cin>>pwd;
    cout<<"Re-Enter your PASSWORD : ";
    cin>>check_pwd;
    while(strcmp(pwd,check_pwd)!=0)
    {
        cout<<"\t\t\t----INCORRECT PASSWORD!!!----"<<endl;
        cout<<"Enter your PASSWORD : ";
        cin>>pwd;
        cout<<"Re-Enter your PASSWORD : ";
        cin>>check_pwd;
    }
    f<<endl<<name<<endl<<pwd;
 cout<<"\n\t\t\t\t\t  YOUR NEW ID IS CREATING PLEASE WAIT";
	for(int i=0;i<6;i++)
	{
		cout<<".";
		Sleep(500);
    }
	cout<<"\n\n\t\t\t\t\t\aCONGRATULATION!!!YOUR ID CREATED SUCCESSFULL....Please wait";
	Sleep(5000);
	system("CLS");
    f.close();
}
int main()
{
	int numVertices, numEdges;
    std::cout << "Enter the number of vertices: ";
    std::cin >> numVertices;
    std::cout << "Enter the number of edges: ";
    std::cin >> numEdges;

    Graph graph(numVertices);//numvertices=20 and edges=30
    string stations[numVertices]={"Miyapur","JNTU","KPHB","Kukatpally","bal nagar","Moosapet","bharat nagar"
	,"sr nagar ","Ammerpet","begumpet","lb nagar","prakash nagar","khairatabad",
	"secundrabad","dilshuknagar","MGBS ","JBS parade ground ","narayanaguda ","Uppal ","Charminar"};
    unordered_map<string,int> m;
    for(int i=0;i<20;i++)
    {
        m[stations[i]]=i;
    }


    std::cout << "Enter the names of the stations:\n";
    for (int i = 0; i < numVertices; i++) {
        std::string name;
        
        graph.setStationName(i, stations[i]);
    }

    std::cout << "Enter the edges and their weights:\n";
   /* for (int i = 0; i < numEdges; i++) {
        int u, v;
        float w;
        std::cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }*/
    graph.addEdge(0, 1, 6.9);
    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 1);
    graph.addEdge(3, 4, 3);
    graph.addEdge(4, 5, 1);
    graph.addEdge(5, 6, 1);
    graph.addEdge(6, 7, 4);
    graph.addEdge(7, 8, 1.7);
    graph.addEdge(7, 9, 2.1);
    graph.addEdge(7, 10, 18.3);
    graph.addEdge(8, 9, 2.2);
    graph.addEdge(8, 10, 18.4);
    graph.addEdge(8, 12, 4);
    graph.addEdge(8, 14, 16);
    graph.addEdge(8, 15, 10);
    graph.addEdge(8, 16, 7.6);
    graph.addEdge(9, 10, 20.3);
    graph.addEdge(9, 11, 0.13);
    graph.addEdge(9, 13, 6.5);
    graph.addEdge(10, 13, 15.7);
    graph.addEdge(10, 14, 23);
    graph.addEdge(13, 15, 9.5);
    graph.addEdge(13, 16, 1);
    graph.addEdge(13, 17, 6);
    graph.addEdge(15, 16, 10.5);
    graph.addEdge(15, 17, 3);
    graph.addEdge(15, 19, 3.6);
    graph.addEdge(16, 18, 9);
	int source;
	int n,W,ch,flag;
    char s;
    cout<<"\t\t\t\t\t\t----------------------------------------WELCOME TO Orange Line Metro Distance Counter----------------------------------------\n\n";
    do
    {
        cout<<endl;
        cout<<"\t\t\t\t\t\t\t \t\t\t\t\t_____________________\n";
        cout<<"\t\t\t\t\t\t\t \t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb_____________\xdb\xdb\xdb\xdb\xdb\xdb \n";
        cout<<"\t\t\t\t\t\t\t \t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb 1) LOGIN    \xdb\xdb\xdb\xdb\xdb\xdb\n";
        cout<<"\t\t\t\t\t\t\t \t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb 2) REGISTER \xdb\xdb\xdb\xdb\xdb\xdb\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb 3) EXIT     \xdb\xdb\xdb\xdb\xdb\xdb\n";
         cout<<"\t\t\t\t\t\t\t \t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb_____________\xdb\xdb\xdb\xdb\xdb\xdb\n";
        cout<<"\t\t\t\t\t\t\t \t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb_____________\xdb\xdb\xdb\xdb\xdb\xdb\n";
        cout<<"Enter your Choice : ";
        cin>>ch;
        system("cls");
        switch(ch)
        {
            case 1:
                flag=login();
                break;
            case 2:
                signup();
                cout<<"Do you want to LOGIN (Y/N)? : ";
                cin>>s;
                if(s=='y'||s=='Y')
                    flag=login();
                else
                {
                    cout<<"\t\t\t\t\t\t\t \t\t\t\t\t ___________ \n";
                    cout<<"\t\t\t\t\t\t\t \t\t\t\t\t| THANK YOU |\n";
                    cout<<"\t\t\t\t\t\t\t \t\t\t\t\t|___________|\n";
                    exit(1);
                }
                break;
            case 3:
                cout<<"\t\t\t\t\t\t\t \t\t\t\t\t ___________ \n";
                cout<<"\t\t\t\t\t\t\t \t\t\t\t\t| THANK YOU |\n";
                cout<<"\t\t\t\t\t\t\t \t\t\t\t\t|___________|\n";
                exit(0);
                break;
            default:
                cout<<"\t\t\t----INCORRECT CHOICE!!!----"<<endl;
                break;
        }
    }while(flag!=1);
    if(flag==1)
    {
	
	 char x;
	      cout<<"\n\n\n\n\n\n\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb "<<endl;
    cout<<"\t\t\t\t\t\t*WELLCOME TO Orange Line Metro Distance Counter*"<<endl;
    cout<<"\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb "<<endl;
             string phrase = "WELLCOME TO Orange Line Metro Distance Counter";
        string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
        system(charCommand);
    do
    {
    		for(int i=0;i<20;i++)
	{
		cout<<"Enter "<<" "<<i<<" "<<" for "<<stations[i]<<endl;
	}
    	cout<<"Enter the source station"<<endl;
    	cin>>source;
    	system("cls");
	dijkstra(graph,source,m);



 cout<<"Do you want to continue (Y/N)? : ";

                cin>>x;
                	system("cls");
	}while(x=='y'||x=='Y');
	return 0;
}
}
