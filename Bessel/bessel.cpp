#include<iostream>
#include<cmath>
#include<fstream>
#include<math.h>
#include<vector>

float func(int n, float t, float x){
    return cos(n*t-x*sin(t));
}
// Simpson como método de cuadratura
float simpson(float a, float b, int n, float x){
    return (b-a)*(func(n,a,x)+4*func(n,0.5*(a+b),x)+func(n,b,x))/6; 
}

//Calculando Jn(x)
float Jn(int n, double x){
    double I = 0;
    float a = 0;
    float h=0.0001;
    float b=a+h;
    while (a<M_PI){
        I+=simpson(a,b,n,x);
        a=b;
        b+=h;
    }
    return 1/M_PI*I;
}

//Horrible función donde se calculan las 4 raíces del J(n) (tarda un buen)
//Intervalos y valores iniciales diferentes para cada función
void raices(int n){
    double nf = n;
    if (n==0){
        std::cout << "Raíces para J0(x):";
        std::vector<double> a= {1,4,7,11};
        std::vector<double> b= {3,6,9,13};
        std::vector<double> x= {2.5,6.0,8.8,11.7};
        for(int i=0; i<4;i++){
        double a_1=a[i];
        double b_1=b[i];
        double x_1=x[i];
        int j=1;
        while(j<100){
            if(Jn(n,x_1)==0){
            break;
            }
            if(Jn(n,x_1)*Jn(n,a_1)<0){
                b_1=x_1;
            }
            if(Jn(n,x_1)*Jn(n,b_1)<0){
                a_1=x_1;
            }
            x_1=(a_1+b_1)/2;
            j++;
        }
        std::cout << x_1 << ", ";   
    }
    std::cout << std::endl;

    }
     if (n==1){
        std::cout << "Raíces para J1(x):";
        std::vector<double> a= {3,6,9,12};
        std::vector<double> b= {5,8,11,14};
        std::vector<double> x= {4,7,10,13.5};
        for(int i=0; i<4;i++){
        double a_1=a[i];
        double b_1=b[i];
        double x_1=x[i];
        int j=1;
        while(j<100){
            if(Jn(n,x_1)==0){
            break;
            }
            if(Jn(n,x_1)*Jn(n,a_1)<0){
                b_1=x_1;
            }
            if(Jn(n,x_1)*Jn(n,b_1)<0){
                a_1=x_1;
            }
            x_1=(a_1+b_1)/2;
            j++;
        }
        std::cout << x_1 << ", ";  
    }
    std::cout << std::endl;
    }
     if (n==2){
        std::cout << "Raíces para J2(x):";
        std::vector<double> a= {4,7,11,14};
        std::vector<double> b= {6,9,13,16};
        std::vector<double> x= {5,8.7,11.5,15};
        for(int i=0; i<4;i++){
        double a_1=a[i];
        double b_1=b[i];
        double x_1=x[i];
        int j=1;
        while(j<100){
            if(Jn(n,x_1)==0){
            break;
            }
            if(Jn(n,x_1)*Jn(n,a_1)<0){
                b_1=x_1;
            }
            if(Jn(n,x_1)*Jn(n,b_1)<0){
                a_1=x_1;
            }
            x_1=(a_1+b_1)/2;
            j++;
        }
        std::cout << x_1 << ", ";  
    }
    std::cout << std::endl;

    }
    if (n==3){
        std::cout << "Raíces para J3(x):";
        std::vector<double> a= {6,9,12,15};
        std::vector<double> b= {7,11,14,17};
        std::vector<double> x= {6.5,9.9,13,16.1};
        for(int i=0; i<4;i++){
        double a_1=a[i];
        double b_1=b[i];
        double x_1=x[i];
        int j=1;
        while(j<100){
            if(Jn(n,x_1)==0){
            break;
            }
            if(Jn(n,x_1)*Jn(n,a_1)<0){
                b_1=x_1;
            }
            if(Jn(n,x_1)*Jn(n,b_1)<0){
                a_1=x_1;
            }
            x_1=(a_1+b_1)/2;
            j++;
        }
        std::cout << x_1 << ", ";  
    }
    std::cout << std::endl;

    }
    if (n==4){
        std::cout << "Raíces para J4(x):";
        std::vector<double> a= {6,10,14,17};
        std::vector<double> b= {8,12,15,18};
        std::vector<double> x= {7.7,11.1,14.5,17.6};
        for(int i=0; i<4;i++){
        double a_1=a[i];
        double b_1=b[i];
        double x_1=x[i];
        int j=1;
        while(j<100){
            if(Jn(n,x_1)==0){
            break;
            }
            if(Jn(n,x_1)*Jn(n,a_1)<0){
                b_1=x_1;
            }
            if(Jn(n,x_1)*Jn(n,b_1)<0){
                a_1=x_1;
            }
            x_1=(a_1+b_1)/2;
            j++;
        }
        std::cout << x_1 << ", ";  
    }
    std::cout << std::endl;
    }
}

int main(){ 
    for(int i=0; i<5;i++){
        raices(i);
    }
}
//Incluyo una imagen (bessel.png) donde se muestran J0(x)-J4(x) para "ver" sus raices