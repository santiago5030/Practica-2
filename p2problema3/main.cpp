/* El programa crea una funcion que compara dos cadenas de caracteres y devulve true en caso de que sean iguales
 y false en caso de que sean diferentes.
*/
#include <iostream>
#include <string.h>

using namespace std;

bool comparacion(char *cad1, char *cad2, int l1, int l2); // declarandofuncion

int main()
{
    char pal1[30], pal2[30];// definicion de cadenas
    int l1,l2;// longitudes de las cadenas
    bool iguales=false;// Estado de comparacion

    cout<<"ingrese una palabra: "; cin.getline(pal1,30);//  pidiendo palabras al usuario
    cout<<"\ningrese una palabra: "; cin.getline(pal2,30);

    l1=strlen(pal1);// asignando las longitudes
    l2=strlen(pal2);

    iguales = comparacion(pal1, pal2, l1, l2);// llamando a la funcion

    if(iguales){
        cout<<"\nlas palabras son iguales"<<endl;
    }
    else{
        cout<<"\nlas palabras son diferentes"<<endl;
    }
    return 0;
}
bool comparacion(char *cad1, char *cad2, int l1, int l2){ // definiendo funcion
    if(l1 != l2){ // comparando longitudes de las cadenas
        return false;
    }
    int c=0;
    while(c < l1){ // ciclo para recorrer todas las cadenas
        if(*(cad1+c) == *(cad2 +c)){ // comparacion de las posiciones
            c++;
        }
        else{
            return false;
        }
    }
    return true;
}

