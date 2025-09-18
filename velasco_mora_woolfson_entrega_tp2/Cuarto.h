#pragma once
#include <ncurses.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include "Luz.h"

#define obj_nulo -1
#define obj_normal 0
#define obj_puerta 1
#define obj_texto 2
#define obj_llave 3
#define obj_muerte 4

#define iluminado 1
#define oscuro 2
#define rojo 3
#define ladrillo 4
#define sol 5

#define xPos 0
#define yPos 1

using namespace std;

struct Objeto {
    int idObj;
    int tipo;
    int pos[2];
    vector<string> layout;
    vector<string> texto;
    int id_cuarto;
};

class Cuarto
{
public:
    Cuarto(int id);

    void connect(char puerta, Cuarto* destino);
    void draw();
    void update();
    void borrarObjeto(int id);
    
    ////////////////////////
    void set_idCuarto(int id);
    int get_idCuarto();
    void add_puerta(int x, int y, int id, vector<string> l);
    void set_puerta(int i, int x, int y, int id, vector<string> l);
    Objeto get_puerta(int i);
    void add_objeto(int x, int y, bool colision, vector<string> l);
    void set_objeto(int i, int x, int y, vector<string> l);
    vector<Objeto> get_objetos();
    void add_texto(int id, int x, int y, vector<string> l, vector<string>texto);
    void add_luz(int id, int x, int y, int sizeX, int sizeY);
    Luz *get_luz(int id);
    vector<Luz> get_luces();

private:
    vector<Objeto> objetos;
    vector<Luz> luces;

    int id_cuarto;
};
