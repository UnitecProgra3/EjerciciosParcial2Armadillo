#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

void funcionQueue()
{
    cout<<"---Queue---"<<endl;
    queue<int> mi_cola;
    mi_cola.push(10);
    mi_cola.push(20);
    mi_cola.push(30);
    while(!mi_cola.empty())
    {
        cout<<mi_cola.front()<<endl;
        mi_cola.pop();
    }
}

void funcionStack()
{
    cout<<"---Stack---"<<endl;
    stack<int> mi_stack;
    mi_stack.push(10);
    mi_stack.push(20);
    mi_stack.push(30);
    while(!mi_stack.empty())
    {
        cout<<mi_stack.top()<<endl;
        mi_stack.pop();
    }
}

void funcionMultimap()
{
    cout<<"---Multimap---"<<endl;
    multimap<string,int>mi_mapa;
    mi_mapa.insert(pair<string,int>("A",10));
    mi_mapa.insert(pair<string,int>("B",20));
    mi_mapa.insert(pair<string,int>("C",30));
    mi_mapa.insert(pair<string,int>("D",40));

    for(multimap<string,int>::iterator i = mi_mapa.begin();
        i!=mi_mapa.end();
        i++)
    {
        cout<<(*i).first<<","<<(*i).second<<endl;
    }
}

void funcionMap()
{
    cout<<"---Map---"<<endl;
    map<string,int>mi_mapa;
    mi_mapa["A"]=10;
    mi_mapa["B"]=20;
    mi_mapa["B"]=25;
    mi_mapa["C"]=30;
    mi_mapa.insert(pair<string,int>("D",40));

    cout<<mi_mapa["A"]<<endl;
    cout<<mi_mapa["B"]<<endl;
    cout<<mi_mapa["C"]<<endl;
    cout<<mi_mapa["D"]<<endl;
    for(map<string,int>::iterator i = mi_mapa.begin();
        i!=mi_mapa.end();
        i++)
    {
        cout<<(*i).first<<","<<(*i).second<<endl;
    }
}

void funcionSet()
{
    cout<<"---Set---"<<endl;
    set<int>mi_set;
    mi_set.insert(20);
    mi_set.insert(10);
    mi_set.insert(30);
    mi_set.insert(20);

    for(set<int>::iterator i=mi_set.begin();
        i!=mi_set.end();
        i++)
        cout<<*i<<endl;
}

void funcionMultiset()
{
    cout<<"---Multiset---"<<endl;
    multiset<int>mi_set;
    mi_set.insert(20);
    mi_set.insert(10);
    mi_set.insert(30);
    mi_set.insert(20);
    //mi_set.erase(30);

    for(multiset<int>::iterator i=mi_set.begin();//find(20);
        i!=mi_set.end();
        i++)
        cout<<*i<<endl;
}

int main()
{
//    funcionQueue();
//    funcionStack();
//    funcionMap();
//    funcionMultimap();
    funcionSet();
    funcionMultiset();

    return 0;
}
