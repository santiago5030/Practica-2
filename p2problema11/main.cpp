/*El programa realiza reservaciones y cancelaciones de asientos de una sala de cine indicando  la fila y la
posicion del asiento.
*/

#include <iostream>
#include <string.h>

using namespace std;

void menu();
char mayus(char *);
void mostrarcine();
void reservacion(int);
void control(char*, int&);

char cine[15][20];
int main()
{
    for(int i=0; i< 15; i++){
        for(int j=0; j<20; j++){
            *(*(cine+i)+j)='-';
        }
    }
    mostrarcine();
    menu();
    return 0;
}
void reservacion(int opcion){
    char fila[10];
    int asiento, nfila;

    switch(opcion){
    case 1:
        cout<<"\nIngrese la fila que desea reservar A-O: "; cin>>fila;
        cout<<"\nIngrese el asiento que desea reservar 1-20: "; cin>>asiento;
        control(fila,asiento);
        nfila= *fila-65;
        asiento=asiento-1;
        if(*(*(cine+nfila)+asiento)== '+'){
            mostrarcine();
            cout<<"\nEl asiento "<<fila<<asiento+1<<" ya se encuentra reservado\n\n";
        }
        else{
        *(*(cine+nfila)+asiento)= '+';
        mostrarcine();
        cout<<"\nReservacion del asiento "<< fila<<asiento+1<<" realizado con exito!\n\n";
        }
        break;
    case 2:
        cout<<"\nIngrese la fila de la reserva que desea cancelar A-O: "; cin>>fila;
        cout<<"\nIngrese el asiento de la reserva que desea cancelar 1-20: "; cin>>asiento;
        control(fila,asiento);
        nfila= *fila-65;
        asiento=asiento-1;
        if(*(*(cine+nfila)+asiento)== '-'){
            mostrarcine();
            cout<<"\nEl asiento "<<fila<<asiento+1<<" no tiene reservacion\n\n";
        }
        else{
            *(*(cine+nfila)+asiento)= '-';
            mostrarcine();
            cout<<"\nCancelacion del asiento "<< fila<<asiento+1<<" realizado con exito!\n\n";
        }
        break;
    }

}
void control(char *fila, int &asiento){
    while(strlen(fila) != 1){
        cout<<"\nLa fila no existe ingresela de nuevo: "; cin>>fila;
    }
    mayus(fila);
    int nfila= *fila;
    while(nfila < 65 || nfila > 79){
        cout<<"\nLa fila no existe ingresela de nuevo: "; cin>>fila;
        while(strlen(fila) != 1){
            cout<<"\nLa fila no existe ingresela de nuevo: "; cin>>fila;
        }
        mayus(fila);
        nfila= *fila;
    }
    while(asiento < 1 || asiento > 20){
        cout<<"\nEl asiento no existe ingreselo de nuevo: "; cin>>asiento;
    }
}
void menu(){
    int opcion;
    cout<<"menu\n\n"<<"1. Realizar reserva\n\n"<<"2. Cancelar reserva\n\n"<<"3. salir\n\n";
    cout<<"ingrese opcion: "; cin>>opcion;

    while(opcion != 1 && opcion !=2 && opcion != 3){
        cout<<"\nLa opcion es invalida ingresela de nuevo: "; cin>>opcion;
    }
    while(opcion != 3){

    reservacion(opcion);

    cout<<"menu\n\n"<<"1. Realizar reserva\n\n"<<"2. Cancelar reserva\n\n"<<"3. salir\n\n";
    cout<<"ingrese opcion: "; cin>>opcion;

    while(opcion != 1 && opcion !=2 && opcion != 3){
        cout<<"\nLa opcion es invalida ingresela de nuevo: "; cin>>opcion;
    }
    }
}
void mostrarcine(){
    cout<<"\n\n+: reservados, -: disponibles\n\n";
    cout<<"  ";
    for(int c=1; c<=20; c++){
        cout<<c<<" ";
    }
    cout<<"\n\n";
    char l=65;
    for(int i=0; i<15; i++){
        cout<<l<<" ";
        for(int j=0; j<20; j++){
            if(j>=0 && j<9){
            cout<<*(*(cine+i)+j)<<" ";
        }
            else{
                cout<<*(*(cine+i)+j)<<"  ";
            }
         }
        cout<<"\n\n";
        l++;
    }
}
char mayus(char *letra){
    if(*letra <= 111 && *letra >=97){
        *letra=*letra-32;
        return *letra;
    }
    else{
        return *letra;
    }
}
