#include<iostream>
#include<cmath>
#include<fstream>
#include<math.h>

/*Incluyo otro programa donde se usa matplotlib para graficar: vanderpolplt.cpp,
batallé para hacerlo funcionar en mi computadora y en el servidor */

/* Este programa genera tres archivos de datos que se pueden graficar en gnuplot haciendo:
> plot "vanderpol1.txt" using 1:2, "vanderpol1.txt" using 1:3
> plot "vanderpol2.txt" using 1:2, "vanderpol2.txt" using 1:3
> plot "vanderpol3.txt" using 1:2, "vanderpol3.txt" using 1:3
*/

//Utilizando el método de Stormer-Verlett
float F(float x, float v){
    return ((1-pow(x,2)*v)-x);
}

void vanderpol1(){
    std::ofstream file;
    file.open ("vanderpol1.txt");
    double v=2.16108;
    double q=0;
    double q2;
    float a=0;
    float b=10;
    float h=0.0002;
    while(a<b){
        file << a << "\t" << q << "\t" <<  v << "\n";
        q2=q+h*(v+(h/2)*F(q,v)); // Lo asignamos a q2 porque todavía necesitamos q
        v+=(h/2)*(F(q,v)+F(q2,v));
        q=q2; // Recorremos después de calcular v nuevo
        a+=h;
    }
    file.close();
    std::cout << "Se ha generado el archivo de datos vanderpol1.txt" << std::endl;
}

void vanderpol2(){
    std::ofstream file;
    file.open ("vanderpol2.txt");
    double v=0;
    double q=1;
    double q2;
    float a=0;
    float b=10;
    float h=0.0002;
    while(a<b){
        file << a << "\t" << q << "\t" <<  v << "\n";
        q2=q+h*(v+(h/2)*F(q,v)); // Lo asignamos a q2 porque todavía necesitamos q
        v+=(h/2)*(F(q,v)+F(q2,v));
        q=q2; // Recorremos después de
        a+=h;
    }
    file.close();
    std::cout << "Se ha generado el archivo de datos vanderpol2.txt" << std::endl;
}

void vanderpol3(){
    std::ofstream file;
    file.open ("vanderpol3.txt");
    double v=2.53;
    double q=-2.161;
    double q2;
    float a=0;
    float b=10;
    float h=0.0002;
    while(a<b){
        file << a << "\t" << q << "\t" <<  v << "\n";
        q2=q+h*(v+(h/2)*F(q,v)); // Lo asignamos a q2 porque todavía necesitamos q
        v+=(h/2)*(F(q,v)+F(q2,v));
        q=q2; // Recorremos después de
        a+=h;
    }
    file.close();
    std::cout << "Se ha generado el archivo de datos vanderpol3.txt" << std::endl;
}

int main(){//genera tres archivos de datos que se pueden graficar usando gnuplot
    vanderpol1();
    vanderpol2();
    vanderpol3();
}