#include <iostream>
#include <fstream>
#include <vector>
#include<SDL2/SDL.h>
using namespace std;

class Puntaje
{
public:
    string jugador;
    int puntaje;
    Puntaje(string jugador, int puntaje)
    {
        this->jugador = jugador;
        this->puntaje = puntaje;
    }
};

void escribir(string archivo,vector<Puntaje*>puntajes)
{
    ofstream out(archivo.c_str());
    for(int i=0;i<puntajes.size();i++)
    {
        out<<puntajes[i]->jugador<<" "<<puntajes[i]->puntaje<<endl;
    }
    out.close();
}

void imprimir(string archivo)
{
    ifstream in(archivo.c_str());
    string jugador;
    while(in>>jugador)
    {
        string puntaje;
        in>>puntaje;
        cout<<jugador<<": "<<puntaje<<endl;
    }
    in.close();
}

void agregar(string archivo, Puntaje p)
{
    ofstream out(archivo.c_str(), ios::app);
    out<<p.jugador<<" "<<p.puntaje<<endl;
    out.close();
}

vector<Puntaje*> leer(string archivo)
{
    vector<Puntaje*>puntajes;
    ifstream in(archivo.c_str());
    string jugador;
    while(in>>jugador)
    {
        string puntaje;
        in>>puntaje;
        puntajes.push_back(new Puntaje(jugador,atoi(puntaje.c_str())));
    }
    in.close();
    return puntajes;
}

void editar(string archivo, string jugador_editado, int nuevo_puntaje)
{
    vector<Puntaje*>puntajes=leer("archivo");

    for(int i=0;i<puntajes.size();i++)
    {
        if(puntajes[i]->jugador==jugador_editado)
        {
            puntajes[i]->puntaje=nuevo_puntaje;
        }
    }

    escribir("archivo",puntajes);
}

void borrar(string archivo,string jugador_borrado)
{
    vector<Puntaje*>puntajes=leer("archivo");

    vector<Puntaje*>puntajes_nuevo;
    for(int i=0;i<puntajes.size();i++)
    {
        if(puntajes[i]->jugador!=jugador_borrado)
        {
            puntajes_nuevo.push_back(puntajes[i]);
        }
    }

    escribir("archivo",puntajes_nuevo);
}

int main()
{
    vector<Puntaje*>puntajes;
    puntajes.push_back(new Puntaje("lolo",10));
    puntajes.push_back(new Puntaje("lola",20));
    puntajes.push_back(new Puntaje("roro",8));

    escribir("archivo",puntajes);
    agregar("archivo",Puntaje("rora",12));
    editar("archivo","lolo",22);
    borrar("archivo","lola");
    imprimir("archivo");


    return 0;
}
