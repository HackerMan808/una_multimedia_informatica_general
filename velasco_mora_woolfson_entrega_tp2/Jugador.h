#pragma once
#include <ncurses.h>
#include "Cuarto.h"

#define texto_x 25
#define texto_y 15
#define texto_max 6

#define arriba 1
#define abajo 2
#define izq 3
#define der 4

class Jugador
{
public:
  Jugador(int x, int y, Cuarto *c);

  void setup();
  void draw();
  int update();

  void mover(int dir);

  void resistir();

  void setX(int x);
  void setY(int y);

  int getX();
  int getY();

  void setEnergia(float energia);
  float getEnergia();

  void set_cuarto(Cuarto *cuarto);
  Cuarto *get_cuarto();


private:
  int m_x, m_y, inicioX, inicioY;
  float m_energia, max_energia;
  int cambiar_cuarto;
  bool m_explotar, en_luz, mostrar_texto=false;
  Cuarto *cuarto;
  vector<string> buffer_texto;

  bool colision(int x, int y, int xOffset, int yOffset);
  void detectar_luz();
};
