#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

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
        out.write(puntajes[i]->jugador.c_str(),10);
        out.write((char*)&puntajes[i]->puntaje,4);
    }
    out.close();
}

void imprimir(string archivo)
{
    ifstream in(archivo.c_str());
    char jugador[10];
    int puntaje;

    in.seekg(0,ios::end);
    int registros = in.tellg()/14;
    in.seekg(0,ios::beg);

    for(int i=0;i<registros;i++)
    {
        in.read(jugador,10);
        in.read((char*)&puntaje,4);
        cout<<jugador<<":"<<puntaje<<endl;
    }

    in.close();
}

void editar(string archivo, string jugador_editado, int nuevo_puntaje)
{
    ifstream in(archivo.c_str());
    in.seekg(0,ios::end);
    int tamano = in.tellg()/14;
    in.seekg(0,ios::beg);

    int pos_a_cambiar;
    for(int i=0;i<tamano;i++)
    {
        char personaje[10];
        int puntaje;
        in.read(personaje,10);
        in.read((char*)&puntaje,4);
        if(strcmp(personaje,jugador_editado.c_str())==0)
        {
            pos_a_cambiar=i;
        }
    }
    in.close();

    ofstream out(archivo.c_str(),ios::in);
    out.seekp(pos_a_cambiar*14+10);
    out.write((char*)&nuevo_puntaje,4);
    out.close();
}

int main()
{
    vector<Puntaje*>puntajes;
    puntajes.push_back(new Puntaje("lolo",10));
    puntajes.push_back(new Puntaje("lola",20));
    puntajes.push_back(new Puntaje("roro",8));

    escribir("archivo",puntajes);
    //agregar("archivo",Puntaje("rora",12));
    editar("archivo","lolo",22);
    //borrar("archivo","lola");
    imprimir("archivo");

    return 0;
}
