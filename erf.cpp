
#include<iostream>
#include<cmath>
#include<fstream>
#include<math.h>

//funcion e^(-t^2)
float func(float x){
    return exp(-pow(x,2));
}
// SimpsonINT
float simpson(float a, float b){
    return (b-a)*(func(a)+4*func(0.5*(a+b))+func(b))/6; 
}

float erf(float a, float h){
    float integral=0;
    if(a>0){
        float x=-a;
        float b=x+h;
        while (x<a){
            integral+=simpson(x,b);
            x=b;
            b+=h;
        }
        return (1/sqrt(M_PI))*integral;
    }
    else{
        float x=-a;
        float b=x-h;
        while (x>a){
            integral+=simpson(x,b);
            x=b;
            b-=h;
        }
        return (1/sqrt(M_PI))*integral;
    }
}

float erf2(float b, float h){ //Solución de la ec.diferencial con método de Gauss
    double y=0;
    double a=0;
    double v=2/sqrt(M_PI);
    if(b>0){
        while(a<b){
            v=(1-2*a*h)*v;
            y+=h*v;
            a=a+h;
        }
    }
    if(b<0){
        while(a>b){
            v=(1+2*a*h)*v;
            y-=h*v;
            a=a-h;     
        }
    }
    return y;
}

int main(){
    std::cout << "Llevando a cabo la inegración" << std::endl;
    for(int i =-3; i<4;i++){
        std::cout << erf(i,0.001) << ",";
    }
    std::cout << std::endl;
    std::cout << "Solucionando la ecuación diferencial" << std::endl;
    for(int i =-3; i<4;i++){
        std::cout << erf2(i,0.001) << ",";
    }
    std::cout << std::endl;
}
