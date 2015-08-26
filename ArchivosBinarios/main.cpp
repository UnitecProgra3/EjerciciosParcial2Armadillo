#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream out("archivo");
    int num = 10;
    out.write((char*)&num,4);
    out.close();

    ifstream in("archivo");
    int numero_leido;
    in.read((char*)&numero_leido,4);
    in.close();

    cout<<"Numero leido: "<<numero_leido<<endl;

    return 0;
}
