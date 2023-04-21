#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <iostream>
int main(){
srand(time(NULL));
int d=0;
int r=0;
double T;
//T=3.0;
T=1.0;
int N = 10;
int nrandom;
int matriz[N][N];
for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
         nrandom = rand() % 2; // generar número aleatorio entre 0 y 1
         if (nrandom==0)
         {
            nrandom=-1;
         }
      matriz[i][j] = nrandom;
      //matriz[i][j]=1;
         printf("%d\t",matriz[i][j]);
      }
        printf("\n"); 
   }
while(r<pow(N,5)){

int f = rand() % N; // Generar un núm aleatorio entre 0 y N-1 para la fila de la matriz
int c = rand() % N; // Generar un núm aleatorio entre 0 y N-1 para la columna de la matriz
int elemento = matriz[f][c]; // Obtener el elemento aleatorio de la matriz 
double p;
double varE;
if (f==N-1 and c!=N-1 and c!=0){
   varE=2* matriz[f][c]*(matriz[0][c]+matriz[f-1][c]+matriz[f][c+1]+matriz[f][c-1]); //definimos la variación de energía 
}
if(f==N-1 and c==0){
   varE=2* matriz[f][c]*(matriz[0][c]+matriz[f-1][c]+matriz[f][c+1]+matriz[f][N-1]);}

if(c==N-1 and f!=N-1 and f!=0){
   varE=2* matriz[f][c]*(matriz[f+1][c]+matriz[f-1][c]+matriz[f][0]+matriz[f][c-1]);  
}
if(c==N-1 and f==0){
   varE=2* matriz[f][c]*(matriz[f+1][c]+matriz[N-1][c]+matriz[f][0]+matriz[f][c-1]);
}

if(c==N-1 and f==N-1){
   varE=2* matriz[f][c]*(matriz[0][c]+matriz[f-1][c]+matriz[f][0]+matriz[f][c-1]);
}
if(c!=N-1 and f!=N-1 and f!=0 and c!=0){
   varE=2* matriz[f][c]*(matriz[f+1][c]+matriz[f-1][c]+matriz[f][c+1]+matriz[f][c-1]);
}
if(f==0 and c==0){
   varE=2* matriz[f][c]*(matriz[f+1][c]+matriz[N-1][c]+matriz[f][c+1]+matriz[f][N-1]);
}
if(c!=N-1 and f==0 and c!=0){
   varE=2* matriz[f][c]*(matriz[f+1][c]+matriz[N-1][c]+matriz[f][c+1]+matriz[f][c-1]);
}
if(f!=N-1 and f!=0 and c==0){
   varE=2.0* matriz[f][c]*(matriz[f+1][c]+matriz[f-1][c]+matriz[f][c+1]+matriz[f][N-1]);
}
printf("%d\t",varE);
if (1<exp(-varE*1.0/T)){
   p=1.0;
} 
   else{
      p=exp(-varE*1.0/T);
   }

double epsilon = (double) rand() / RAND_MAX;
if (epsilon<p){
   matriz[f][c]=-matriz[f][c];
}
//printf("%d\t",p);
//printf("%d\t", epsilon);
if (d==pow(N,2)){
 // Guardarmos la matriz en un archivo
    FILE* archivo = fopen("espinTbaja.txt", "a");
    //FILE*archivo= fopen("espinTalta.txt","a");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(j!=N-1){
            fprintf(archivo, "%d,", matriz[i][j]);
        }
            else{
            fprintf(archivo, "%d\t", matriz[i][j]);  
            }
        }
        fprintf(archivo, "\n"); 
    }
    fprintf(archivo, "\n");
    fclose(archivo);
d=0;
}
else{
   d=d+1;
}
r=r+1;
}
    return 0;
}