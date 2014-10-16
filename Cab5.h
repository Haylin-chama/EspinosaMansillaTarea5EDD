#ifndef CAB5_H_INCLUDED
#define CAB5_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct NG{
    int N; //Cantidad de partidos jugadis
    int G; //Cantidad de goles comprados
}NG_s;

typedef struct Partidos{
    int S; //Cantidad de goles hechos
    int R; //Cantidad de goles recibidos
    struct Partidos * sig; //Sig de siguiente
};
typedef Partidos * Lista; //Se define Lista

//Operaciones
NG Llenar_NG();
void GenerarPartidos(Lista &, int);
void GenerarPuntos(int[],int,Lista,int[]);
int RepartijaPuntos(int,int[],int,int[],int,int);

#endif // CAB5_H_INCLUDED
