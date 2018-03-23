/*El progama recibe una palabra y el programa muestra la palabra sin letras repetidas.
Ej: si se ingresa restriccion el programa muestra resticon.
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void removeletters(char *,int);// funcion que elimina las palabra repetidas

int main()
{
   char word[20];// arreglo de la palabra
   int l;
   cout<<"ingrese una palabra: "; cin.getline(word,20);

   l=strlen(word);
   removeletters(word,l);

    return 0;
}
void removeletters(char *word,int l){
    char *neword;
    int l2=1;
    neword= new char[l];//asignacion dinamica de memoria

    *neword= *word;
    for(int i=1; i < l; i++){// ciclo que recorre toda la palabra
        int c=0;
        while(c < l2){// ciclo que recorre la nueva palabra
            if(*(word + i) == *(neword +c)){//busca de letras iguales
                break;
            }
            c++;
        }
        if(c== l2){
            *(neword + l2)= *(word + i);//asignando letras no repetidas a la nueva palabra
            l2++;
        }
    }
    cout<<"Original: "<<word<<" Sin repetidos: "<<neword<<endl;
    delete[] neword;
}
