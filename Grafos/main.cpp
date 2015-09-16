#include <iostream>
#include <list>

using namespace std;

class Nodo
{
public:
    int valor;
    list<Nodo*>adjacentes;
    bool recorrido;
    Nodo(int valor)
    {
        this->valor=valor;
        this->recorrido=false;
    }
};

class Grafo
{
public:
    Nodo* inicio;
    list<Nodo*>nodos;
    Grafo()
    {
        Nodo *n1=new Nodo(1);
        Nodo *n2=new Nodo(2);
        Nodo *n3=new Nodo(3);
        Nodo *n4=new Nodo(4);
        Nodo *n5=new Nodo(5);
        Nodo *n6=new Nodo(6);

        n1->adjacentes.push_back(n2);
        n1->adjacentes.push_back(n3);
        n1->adjacentes.push_back(n4);
        n4->adjacentes.push_back(n5);
        n4->adjacentes.push_back(n6);
        n6->adjacentes.push_back(n1);
        n2->adjacentes.push_back(n1);
        n4->adjacentes.push_back(n2);

        this->inicio=n1;

        nodos.push_back(n1);
        nodos.push_back(n2);
        nodos.push_back(n3);
        nodos.push_back(n4);
        nodos.push_back(n5);
    }

    void imprimir()
    {
        nodos.clear();
        imprimir(inicio);
        nodos.clear();
    }

    void imprimir(Nodo* actual)
    {
        for(list<Nodo*>::iterator i=nodos.begin();
            i!=nodos.end();
            i++)
            if(actual==*i)
                return;

        cout<<actual->valor<<endl;
        nodos.push_back(actual);
        for(list<Nodo*>::iterator i=actual->adjacentes.begin();
            i!=actual->adjacentes.end();
            i++)
            imprimir(*i);
    }
};

int main()
{
    Grafo g;
    cout<<"---Imprimir---"<<endl;
    g.imprimir();
    cout<<"---Imprimir---"<<endl;
    g.imprimir();
    return 0;
}
