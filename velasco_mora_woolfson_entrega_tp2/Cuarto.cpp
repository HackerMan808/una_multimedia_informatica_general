#include "Cuarto.h"

Cuarto::Cuarto(int id){
    id_cuarto=id;
}

void Cuarto::draw() {
    clear();
    attron(COLOR_PAIR(oscuro));
    for(int i=0;i<objetos.size();i++){
        /*for (int y = 0; y < objetos[i].layout.size(); y++) {
            for (int x = 0; x < objetos[i].layout[y].size(); x++) {
                mvaddch(y+objetos[i].y, x+objetos[i].x, objetos[i].layout[y][x]);
                }
                }*/
        for (int y = 0; y < objetos[i].layout.size(); y++) {
            mvaddstr(y+objetos[i].pos[yPos], objetos[i].pos[xPos], objetos[i].layout[y].c_str());
        }
    }
    attron(COLOR_PAIR(oscuro));
//////////////////////////////////////////
    attron(COLOR_PAIR(iluminado));
    for(int i=0; i<luces.size();i++){
        if(luces[i].getEncendida()==true){
            for(int x=0;x<luces[i].getSizeX();x++){
                int newX = x+luces[i].getX();
                for(int y=0;y<luces[i].getSizeY();y++){
                    int newY = y+luces[i].getY();
                    chtype ch = mvinch(newY, newX);
                    char c = ch & A_CHARTEXT;
                    mvaddch(newY, newX, c);
                }
            }
        }
    }
    attroff(COLOR_PAIR(iluminado));
    
    box(stdscr, 0, 0);
    refresh();
}

void Cuarto::update(){
    for(int i=0;i<luces.size();i++){
        luces[i].update();
    }
}

void Cuarto::add_luz(int id, int x, int y, int sizeX, int sizeY){
    Luz luz(id,x,y,sizeX,sizeY);
    luces.push_back(luz);
}

Luz *Cuarto::get_luz(int id){
    for(int i=0; i<luces.size(); i++){
        if(luces[i].getId()==id) return &luces[i];
    }
    return nullptr;
}

void Cuarto::borrarObjeto(int id){
    for(int i=0;i<objetos.size();i++){
        if(id==objetos[i].idObj) objetos.erase(objetos.begin()+i);
    }
}

////////////////////////////////////////////////////////////////////////
int Cuarto::get_idCuarto(){
    return id_cuarto;
}

void Cuarto::set_idCuarto(int id){
    id_cuarto = id;
}

void Cuarto::add_puerta(int x, int y, int id, vector<string> l){
    Objeto aux;
    aux.pos[xPos]=x; aux.pos[yPos]=y;
    aux.tipo=obj_puerta;
    aux.id_cuarto=id;
    aux.layout=l;
    aux.idObj=-1;
    objetos.push_back(aux);
}


void Cuarto::set_puerta(int i, int x, int y, int id, vector<string> l){
    if(objetos.size()<=i){
        Objeto aux;
        aux.pos[xPos]=x; aux.pos[yPos]=y;
        aux.tipo=obj_puerta;
        aux.id_cuarto=id;
        aux.layout=l;
        objetos[i]=aux;
    }
}

Objeto Cuarto::get_puerta(int id){
    for(int i=0;i<objetos.size();i++){
        if(objetos[i].tipo==obj_puerta&&objetos[i].id_cuarto==id) return objetos[i];
    }
    Objeto aux;
    aux.tipo=obj_nulo;
    return aux;
}

void Cuarto::add_objeto(int x, int y, bool colision, vector<string> l){
    Objeto aux;
    aux.pos[xPos]=x; aux.pos[yPos]=y;
    if(colision) aux.tipo=obj_normal;
    else aux.tipo=obj_nulo;
    aux.layout=l;
    aux.idObj=-1;
    objetos.push_back(aux);
}


void Cuarto::set_objeto(int i, int x, int y, vector<string> l){
    if(objetos.size()<=i){
        objetos[i].pos[xPos]=x;
        objetos[i].pos[yPos]=y;
        objetos[i].layout=l;
    }
}

vector<Objeto> Cuarto::get_objetos(){
    return objetos;
}

void Cuarto::add_texto(int id, int x, int y, vector<string> l, vector<string>texto){
    Objeto aux;
    aux.idObj=id;
    aux.pos[xPos]=x; aux.pos[yPos]=y;
    aux.tipo=obj_texto;
    aux.layout=l;
    aux.texto=texto;
    objetos.push_back(aux);
}

vector<Luz> Cuarto::get_luces(){
    return luces;
}
/*int Cuarto::get_objeto(int id){
    for(int i=0;i<objetos.size();i++){
        if(objetos[i].id==id) return i;
    }
    return -1;
}*/

//amancay te amo <3
