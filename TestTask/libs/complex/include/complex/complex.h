#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <cmath>


#define PI 3.141592653589793

template <class T>

struct complex {

 complex(T Re= 0, T Im = 0) : RE(Re), IM(Im) { }


T const& Re() //для чтения
 {
 return RE;
}

T & Re(T re)//для записи
 {
 this->RE=re;
return RE;
}


T const & Im()
{
return IM;
}

T& Im(T im) 
{
     this->IM=im;
return IM;
}



T Abs()
{
T ABS = sqrt(pow(IM, 2) + pow(RE, 2));
return ABS;
}
 T Abs2()
{
T ABS = pow(IM, 2) + pow(RE, 2);
return ABS;
}


T Arg() 
{
T ARG;
if (IM==0 && RE==0) {ARG=0;}

else
  {
T abs=Abs();
ARG = (atan((IM/=abs) / (RE/=abs)));

if ((IM<=0)&&(RE>=0) ||(IM>=0)&&(RE<=0)) 
{ARG +=PI;}

if (ARG > 2 * PI) 
{ARG -= 2 * PI;}
  }
return ARG;
}

T ArgDeg() 
{
T ARGDeg = 180 * Arg() / PI;
return ARGDeg;
}

 void conj(){
          this->IM=-IM;
         return ;//меняет значение в изначальной структуре, нужно быть внимательным,как сделать, чтобы не меняла структруру, но возвращала измененную структуру?
}


struct Factory {

static complex CreateComplexFromPhaseDeg(float phi)
{ return{float(cos(phi)),float(sin(phi))};}

static complex CreateComplexFromPhase(float phi)
{ phi=phi*PI/180;
return {float(cos(phi)),float(sin(phi))};}
};


private:
 T RE;
 T IM;
};

template <class T>
std::istream& operator >>(std::istream &is, complex<T> &p){//для удобного ввода, вывода
is>>p.Re()>>p.Im();
return is;
}
template <class T>
std::ostream& operator <<(std::ostream &os, complex<T> &p){
os<<p.Re()<<' '<<p.Im()<<"i";
return os;
}

#endif
