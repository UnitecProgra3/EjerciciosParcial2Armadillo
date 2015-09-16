#include <iostream>

using namespace std;

bool existeUnCamino(char tablero[5][5],
                    int x_actual,int y_actual,
                    int x_destino, int y_destino)
{
    cout<<"Llamada recursiva: "<<tablero[x_actual][y_actual]<<endl;

    if(x_actual<0 || x_actual>4
       || y_actual<0 || y_actual>4
       || x_destino<0 || x_destino>4
       || y_destino<0 || y_destino>4
       )
        return false;

    if(tablero[x_actual][y_actual]=='*')
        return false;

    if(x_actual == x_destino
       && y_actual == y_destino)
       return true;

    tablero[x_actual][y_actual]='*';

    bool existe_izq = existeUnCamino(tablero,
                                     x_actual-1,y_actual,
                                     x_destino,y_destino);

    bool existe_der = existeUnCamino(tablero,
                                     x_actual+1,y_actual,
                                     x_destino,y_destino);

    bool existe_arriba = existeUnCamino(tablero,
                                     x_actual,y_actual-1,
                                     x_destino,y_destino);

    bool existe_abajo = existeUnCamino(tablero,
                                     x_actual,y_actual+1,
                                     x_destino,y_destino);

    tablero[x_actual][y_actual]=' ';

    return existe_izq || existe_der || existe_arriba || existe_abajo;
}

void imprimir(char tablero[5][5])
{
    for(int y=0;y<5;y++)
    {
        for(int x=0;x<5;x++)
            cout<<tablero[y][x]<<' ';
        cout<<endl;
    }
}

int main()
{
    char tablero[5][5]={  {' ','*',' ',' ',' '},
                          {' ','*',' ','*',' '},
                          {' ',' ',' ','*',' '},
                          {' ','*','*','*',' '},
                          {' ',' ',' ','*','D'}
                        };
    imprimir(tablero);
    cout<<existeUnCamino(tablero,
                        0,0,
                        4,4)<<endl;
    imprimir(tablero);
    return 0;
}
