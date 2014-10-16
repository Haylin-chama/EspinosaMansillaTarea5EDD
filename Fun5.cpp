#include <iostream>
#include <ctype.h>
#include <string.h>
#include "cab5.h"

using namespace std;

int Validar(){
    bool a=false;
    int x;
    while (a!=true){
        cin>>x;
        if (x>=0 and x<=100){
            a=true;
            return x;
        }
        else
            cout<<"Intente con un numero entre 0 y 100"<<endl<<"Valor: ";
    }
}

NG Llenar_NG(){
    cout<<"INGRESE"<<endl;
    NG_s nuevo_NG;
    cout<<"Partidos jugados: ";
    nuevo_NG.N=Validar();
    cout<<"Goles Comprados: ";
    nuevo_NG.G=Validar();
    return nuevo_NG;
}

void GenerarPartidos(Lista &Puntero, int Contador){
    Lista p;
    while(Contador!=0){
        p=new Partidos;
        cout<<endl<<endl<<"Partidos por ingresar: "<<Contador;
        cout<<endl<<"Goles Hechos> ";
        p->S=Validar();
        cout<<"Goles Recibidos> ";
        p->R=Validar();
        p->sig=Puntero;
        Puntero=p;
        Contador--;
    }
}

void GenerarPuntos(int Puntos[], int Largo, Lista Puntero, int Diferencia[]){
    for(int i=0;i<Largo;i++){
        int a=Puntero->S,b=Puntero->R;
        if (a>b)
            Puntos[i]=3;
        if (a=b)
            Puntos[i]=1;
        if (a<b){
            Puntos[i]=0;
            Diferencia[i]=b - a;
        }
        cout<<endl<<Puntos[i]<" "<<Diferencia[i];
        Puntero=Puntero->sig;
    }
    cout<<endl;
}

int SumaFinal(int Puntos[], int Largo){
    if (Largo==0)
        return Puntos[0];
    else
        return Puntos[Largo]+SumaFinal(Puntos,Largo-1);
}

int RepartijaPuntos(int Goles, int Puntos[], int Largo, int Diferencia[], int Puntero, int G2){
    if (Goles==0){
        return SumaFinal(Puntos,Largo);
    }
    else{
        Puntero=Puntos[Largo];
        while (Puntero!=NULL and Goles!=0){//While para los empates
            if (*Puntero==1){
                return RepartijaPuntos(int Goles-1, int Puntos[], int Largo, int Diferencia[], int Puntero+1, int G2+3);
            }
        }

    }
}
