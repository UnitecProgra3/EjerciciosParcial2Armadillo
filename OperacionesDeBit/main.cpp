#include <iostream>
#include <math.h>

using namespace std;

bool estaEncendido(char byte, int pos)
{
    char mascara = 1;
    mascara = mascara << pos;
    return byte&mascara;
}

char encenderBit(char byte, int pos)
{
    char mascara = 1;
    mascara = mascara << pos;
    return byte|mascara;
}

char apagarBit(char byte, int pos)
{
    if(estaEncendido(byte,pos))
    {
        char matador = pow(2,pos);
        return byte-matador;
    }
    return byte;
}

int main()
{
    char c = apagarBit(5,1);

    for(int i=7;i>=0;i--)
        cout<<estaEncendido(c,i);

    cout<<endl;

    for(int i=7;i>=0;i--)
        cout<<estaEncendido(5,i);

    cout<<endl;

    for(int i=7;i>=0;i--)
        cout<<estaEncendido(9,i);

    return 0;
}
