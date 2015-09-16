#include <iostream>

using namespace std;

class Nodo
{
public:
    int valor;
    Nodo *hijo_izq, *hijo_der;
    Nodo(int valor)
    {
        this->valor=valor;
        this->hijo_der=NULL;
        this->hijo_izq=NULL;
    }
};

class Arbol
{
public:
    Nodo* raiz;
    Arbol()
    {
        //Ver el arbol:
        //http://visualgo.net/bst.html
        Nodo*n15=new Nodo(15);
        Nodo*n6=new Nodo(6);
        Nodo*n4=new Nodo(4);
        Nodo*n5=new Nodo(5);
        Nodo*n7=new Nodo(7);
        Nodo*n23=new Nodo(23);
        Nodo*n71=new Nodo(71);
        Nodo*n50=new Nodo(50);

        n15->hijo_izq=n6;
        n6->hijo_izq=n4;
        n6->hijo_der=n7;
        n4->hijo_der=n5;

        n15->hijo_der=n23;
        n23->hijo_der=n71;
        n71->hijo_izq=n50;

        raiz=n15;
    }

    void imprimirArbol()
    {
        imprimirArbol(raiz);
    }

    void imprimirArbol(Nodo*raiz)
    {
        if(raiz==NULL)
            return;

        cout<<raiz->valor<<endl;

        imprimirArbol(raiz->hijo_izq);
        imprimirArbol(raiz->hijo_der);
    }

    bool existe(Nodo* actual, int valor_buscado)
    {
        if(actual==NULL)
            return false;

        cout<<"Buscando backtracking"<<endl;

        if(actual->valor==valor_buscado)
            return true;

        if(existe(actual->hijo_izq,valor_buscado))
            return true;

        if(existe(actual->hijo_der,valor_buscado))
            return true;

        return false;
    }

    bool existeAVL(Nodo* actual, int valor_buscado)
    {
        if(actual==NULL)
            return false;

        cout<<"Buscando avl"<<endl;

        if(actual->valor == valor_buscado)
            return true;
        else if(actual->valor < valor_buscado)
            return existeAVL(actual->hijo_izq,valor_buscado);
        else
            return existeAVL(actual->hijo_der,valor_buscado);
    }

    void insertarAVL(Nodo*actual, int valor)
    {
        Nodo* nuevo = new Nodo(valor);

        if(raiz==NULL)
        {
            raiz = nuevo;
            return;
        }

        if(valor < actual->valor)
        {
            if(actual->hijo_izq!=NULL)
                insertarAVL(actual->hijo_izq,valor);
            else
                actual->hijo_izq=nuevo;
        }
        else
        {
            if(actual->hijo_der!=NULL)
                insertarAVL(actual->hijo_der,valor);
            else
                actual->hijo_der=nuevo;
        }
    }
};

int main()
{
    Arbol a;
    a.insertarAVL(a.raiz,8);
    a.imprimirArbol();
    cout<<a.existe(a.raiz,71)<<endl;
    cout<<a.existeAVL(a.raiz,71)<<endl;
//    cout<<a.existe(a.raiz,10)<<endl;
//    cout<<a.existe(a.raiz,0)<<endl;
//    cout<<a.existe(a.raiz,6)<<endl;

    return 0;
}
