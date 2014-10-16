#include <iostream>
#include "cab5.h"

/*Autores: Valentina Espinosa y Jose Mansilla
Fecha: 10/10/2014
Descripcion: Tarea 5 con uso de LLS y Estructuras estaticas.*/

using namespace std;

int main(){
    NG_s E;
    E=Llenar_NG();
    Lista P; //Puntero tipo Lista para los partidos
    P=NULL;
    GenerarPartidos(P,E.N);
    int A[100],B[100];
    GenerarPuntos(A,E.N,P,B);
    int *p,G2=0;
    int suma=RepartijaPuntos(E.G,A,E.N,B,p,G2);
    cout<<endl<<"Puntos: "<<suma;
}
