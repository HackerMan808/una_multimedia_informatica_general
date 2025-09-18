#include "Luz.h"
#include <cstdlib>

Luz::Luz(int ID, int iX, int iY, int sizeX, int sizeY){
    id=ID;
    x=iX;
    y=iY;
    size_x=sizeX;
    size_y=sizeY;
    encendida = true;
}

void Luz::draw(){

}

void Luz::update(){
    int aux = rand()%4;
    if(!encendida){
        delay-=0.01;
        if(delay<=0){
            encendida=true;
            delay=delay_luz+aux;
        }
    }else{
        delay-=0.01;
        if(delay<=0){
            delay=delay_luz/2+aux;
            encendida=false;
        }
    }
}

void Luz::mover(int dir){

}

///////////////////////////////
int Luz::getId(){return id;}
void Luz::setX(int iX){x=iX;}
void Luz::setY(int iY){y=iY;}
int Luz::getX(){return x;}
int Luz::getY(){return y;}
void Luz::setSizeX(int sizeX){size_x=sizeX;}
void Luz::setSizeY(int sizeY){size_y=sizeY;}
int Luz::getSizeX(){return size_x;}
int Luz::getSizeY(){return size_y;}
void Luz::setEncendida(bool estado){encendida=estado;}
bool Luz::getEncendida(){return encendida;}