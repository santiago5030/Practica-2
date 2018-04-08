#include <iostream>

using namespace std;

void rectangulos();
void mostrarectangulo(int*);
void Esquinas(int*,int*,int*,int*);
void contenencia(int*,int*,int*,int*);
void intersepcion(int*,int);

int rectangulo1[4], rectangulo2[4], rectangulo3[4];
int main()
{
    rectangulos();
    mostrarectangulo(rectangulo1);
    mostrarectangulo(rectangulo2);
    int cont=0;
    for(int i=0; i<4; i++){
        if(*(rectangulo1+i)==*(rectangulo2+i)){
            cont++;
        }
    }
    if(cont==4){
        cout<<"\n\nLos rectangulos son iguales\n"<<endl;
    }
    else{
        int E1[2],E2[2],E3[2],E4[2];
        Esquinas(E1,E2,E3,E4);
        contenencia(E1,E2,E3,E4);
    }
    return 0;
}
void rectangulos(){
    int numero;
    for(int i=0; i<4; i++){
        if(i==0){
            cout<<"ingrese la coordenada X del primer rectangulo: "; cin>>numero;
            *(rectangulo1 + i)=numero;
        }
        if(i==1){
            cout<<"\ningrese la coordenada en y del primer rectangulo: "; cin>>numero;
            *(rectangulo1+i)=numero;
        }
        if(i==2){
            cout<<"\ningrese el ancho del primer rectangulo: "; cin>>numero;
            *(rectangulo1+i)=numero;
        }
        if(i==3){
            cout<<"\ningrese la altura del primer rectangulo: ";cin>>numero;
            *(rectangulo1+i)=numero;
        }
    }
        for(int i=0; i<4; i++){
            if(i==0){
                cout<<"\n\ningrese la coordenada X del segundo rectangulo: "; cin>>numero;
                *(rectangulo2 + i)=numero;
            }
            if(i==1){
                cout<<"\ningrese la coordenada en y del segundo rectangulo: "; cin>>numero;
                *(rectangulo2+i)=numero;
            }
            if(i==2){
                cout<<"\ningrese el ancho del segundo rectangulo: "; cin>>numero;
                *(rectangulo2+i)=numero;
            }
            if(i==3){
                cout<<"\ningrese la altura del segundo rectangulo: ";cin>>numero;
                *(rectangulo2+i)=numero;
            }
    }
}

void mostrarectangulo(int *rectangulo){
    cout<<"{";
    for(int i=0; i<4;i++){
        if(i!=3){
        cout<<*(rectangulo+i)<<", ";
        }
        else{
            cout<<*(rectangulo+i)<<"} ";
        }
    }
}
void Esquinas(int *E1,int *E2, int *E3, int *E4){
    *E1=*rectangulo2;
    *(E1+1)=*(rectangulo2+1);
    *E2=*rectangulo2 + *(rectangulo2+2);
    *(E2+1)=*(rectangulo2+1);
    *E3=*E2;
    *(E3+1)=*(rectangulo2+1)- *(rectangulo2+3);
    *E4=*E1;
    *(E4+1)=*(E3+1);

    cout<<"\n\n{"<<*E1<<" ,"<<*(E1+1)<<"}  ";
    cout<<"{"<<*E2<<" ,"<<*(E2+1)<<"}  ";
    cout<<"{"<<*E3<<" ,"<<*(E3+1)<<"}  ";
    cout<<"{"<<*E4<<" ,"<<*(E4+1)<<"}"<<endl;
}
void contenencia(int *E1, int *E2, int *E3, int *E4){
    int cont=0, esqcontenida,aux1,aux2,aux3,aux4;
    aux1=*rectangulo1;
    aux3=*(rectangulo1+1);
    aux2=*rectangulo1 + *(rectangulo1+2);
    aux4=*(rectangulo1+1)- *(rectangulo1+3);

    if(*E1>=aux1 && *E1 < aux2 && *(E1+1)<= aux3 && *(E1+1)> aux4){
        cont++;
        esqcontenida=1;
        cout<<"\nEsquina "<<esqcontenida<<" contenida"<<endl;
    }
    if(*E2> aux1 && *E2 <= aux2 && *(E2+1)<= aux3 && *(E2+1)> aux4){
        cont++;
        esqcontenida=2;
        cout<<"\nEsquina "<<esqcontenida<<" contenida"<<endl;
    }
    if(*E3> aux1 && *E3 <= aux2 && *(E3+1)< aux3 && *(E3+1)>= aux4){
        cont++;
        esqcontenida=3;
        cout<<"\nEsquina "<<esqcontenida<<" contenida"<<endl;
    }
    if(*E4>= aux1 && *E4 < aux2 && *(E4+1)< aux3 && *(E4+1)>= aux4){
        cont++;
        esqcontenida=4;
        cout<<"\nEsquina "<<esqcontenida<<" contenida"<<endl;
    }
    if(cont== 4){
        cout<<"\nEl rectangulo esta contenido"<<endl;
    }
    if(cont==0 ||cont==2 || cont==3){
        cout<<"\nLos rectangulos no se interseptan para este caso"<<endl;
    }
    if(cont==1){
        if(esqcontenida==1){
            intersepcion(E1, esqcontenida);
        }
        if(esqcontenida==2){
            intersepcion(E2, esqcontenida);
        }
        if(esqcontenida==3){
            intersepcion(E3, esqcontenida);
        }
        if(esqcontenida==4){
            intersepcion(E4, esqcontenida);
        }
    }
}
void intersepcion(int *contenido,int esquina){
    if(esquina==1 || esquina==4){
        *(rectangulo3+2)=(*rectangulo1 + *(rectangulo1+2))- *contenido;
    }
    else{
        *(rectangulo3+2)= *contenido - (*rectangulo1);
    }
    if(esquina==1 || esquina==2){
        *(rectangulo3+3)=*(contenido+1) - (*(rectangulo1+1)- *(rectangulo1+3));
    }
    else{
        *(rectangulo3+3)=*(rectangulo1+1)- *(contenido+1);
    }

    if(esquina==1){
        *rectangulo3=*contenido;
        *(rectangulo3+1)=*(contenido+1);
    }
    if(esquina==2){
        *rectangulo3=*rectangulo1;
        *(rectangulo3+1)=*(contenido+1);
    }
    if(esquina==3){
        *rectangulo3=*rectangulo1;
        *(rectangulo3+1)=*(rectangulo1+1);
    }
    if(esquina==4){
        *rectangulo3=*contenido;
        *(rectangulo3+1)=*(rectangulo1+1);
    }
    cout<<"\nEl rectangulo intersepcion es: ";
    mostrarectangulo(rectangulo3);
    cout<<'\n';
}
