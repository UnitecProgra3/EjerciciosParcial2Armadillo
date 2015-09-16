// queue::push/pop

#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Celular.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;

//Escribe los datos del objeto celular (dado) en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varios celulares en un solo archivo
void escribir(string nombre_archivo, Celular*celular, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in);
    out.seekp(posicion*22);
    out.write(celular->nombre.c_str(),10);
    out.write((char*)&celular->modelo,4);
    out.write((char*)&celular->precio,8);
    out.close();
}

//Devuelve un celular previamente escrito (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varios celulares de un solo archivo
Celular* leer(string nombre_archivo, int posicion)
{
    Celular *c = new Celular("",0,0.0);

    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*22);

    char nombre[10];
    in.read(nombre,10);
    c->nombre = nombre;

    in.read((char*)&c->modelo,4);
    in.read((char*)&c->precio,8);

    in.close();

    return c;
}

//Devuelve el precio del celular en la ultima posicion del archivo con nombre dado
double getUltimoPrecio(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(-8,ios::end);
    double precio;
    in.read((char*)&precio,8);
    return precio;
}

//Convierte la cola (dada) en una pila los datos deben de quedar en el mismo orden
//Nota: El tope de la pila debe de ser el frente de la cola
stack<char> convertirAPila(queue<char> mi_cola)
{
    stack<char> resultado;

    vector<char>temp;
    while(!mi_cola.empty())
    {
        temp.push_back(mi_cola.front());
        mi_cola.pop();
    }

    for(int i=temp.size()-1;i>=0;i--)
        resultado.push(temp[i]);

    return resultado;
}

//Devuelve true si el set esta ordenado, de lo contrario devuelve false
bool estaOrdenado(set<int> mi_set)
{
    return true;
}

//Devuelve las tablas de los numeros del 1 al 10
//La llave es el numero de la tabla, el valor asociado es un vector que contiene la tabla de dicho numero
map<int,vector<int> > getTablas()
{
    map<int,vector<int> > mi_mapa;

    for(int i=1;i<=10;i++)
    {
        vector<int>tabla;
        for(int j=1;j<=10;j++)
            tabla.push_back(j*i);
        mi_mapa[i]=tabla;
    }

    return mi_mapa;
}

//Devuelve la suma de todos los valores almacenados en el arbol con raiz dada
int getSuma(NodoBinario* raiz)
{
    if(raiz==NULL)
        return 0;

    int suma_izq = getSuma(raiz->hijo_izq);
    int suma_der = getSuma(raiz->hijo_der);

    return raiz->valor + suma_izq + suma_der;
}

//Devuelve true si todos los valores de los nodos son primos, de lo contrario devuelve false
bool esPrimo(int num)
{
    for(int i=2;i<num;i++)
        if(num%i==0)
            return false;
    return true;
}
bool sonPrimos(NodoBinario* raiz)
{
    if(raiz==NULL)
        return true;

    bool primo_izq = sonPrimos(raiz->hijo_izq);
    bool primo_der = sonPrimos(raiz->hijo_der);
    bool primo_raiz = esPrimo(raiz->valor);

    return primo_izq && primo_der && primo_raiz;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

