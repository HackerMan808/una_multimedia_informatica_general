#include <iostream>
#include <string>
#include <limits>

#define saludTotal 3;
#define saludLobo 5;

using namespace std;

// Acciones posibles
enum Accion { norte, sur, este, oeste, ver, tomar, usar, invalida };

// Lugares posibles
enum Lugar { ventana, escritorio, cama, armario, escaleras, cima, puertaVestibulo, vestibulo,
            estatua, comedor, espada, escudo, lobo, puertaPasillo, pasillo, exterior  };

enum FaseLobo { vulnerable, defendiendo, atacando};

int main() {
    bool salirDelJuego = false;
    while(!salirDelJuego){
    Lugar lugarActual = ventana;
    FaseLobo faseActual = defendiendo;
    bool continuar = true;
    bool camaTendida = false, armarioBloqueado=true, ropaMovida=false;
    bool llaveEquipada = false, vestibuloBloqueado = true;
    bool espadaEquipada=false, escudoEquipado=false, espadaEstatua=false, escudoEstatua=false, loboVivo=true;
    bool espadaTirada = true, escudoTirado = true, loboDormido = true, incendio = false;

    string codigoArmario = "937";
    string strAccion, strNulo;
    Accion accion;
    
    int saludActual = saludTotal;
    int saludActualLobo = saludLobo;
    float precisionPelea;


    int op = 0;


    cout << "********* ESCAPE DE LA TORRE *********" << endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░╬░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░▄░░░░░░░░░░░░┼░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░┼░░░░░░░░░"<< endl;
    cout << "░░░░░░░░┼░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░═══░░═══░│═══░░░░░░░░┼░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░║░║──║░║──║░║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░░░░░░░░░░░░░░░║░░░░░░░░░░░║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░╬░░░░░░░░░░░░░░░░░░░░░║░█░░░█░░░█░║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░█░░░█░░░█░║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░╬░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░║░░░░░░░░░░░║░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░╬░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░░░░░░░░░░░░░║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░┼░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░█░░█░░░█░░█░║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░▄░░░░░░░░░░░░░░░░░░║░░░░░░░░░░░░░║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░░░░░░░░░░░║░░█░░░█░░░█░░║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░░░░░░░░░░░░░░░║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░█░░░░░█░░░░░█░║░░░░░░░┼░░░░░░░░░░░░░░┼░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░█░░░░░█░░░░░█░║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░█░░░░░█░░░░░█░║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░░░░░░░░░░░░░░░║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░║░░█░░░░░░░░░█░░║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░░░░░█████░░░░░║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░░░░░░░░░░░░░░░░║║░░░░███████░░░░║║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║░░░░░███████░░░░░║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░───────────────────░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;
    cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"<< endl;


    cout << "=== Controles del juego ===" << endl;
    cout << "n = norte | s = sur | e = este | o = oeste" << endl;
    cout << "v = ver   | t = tomar | q = salir" << endl;
    cout << "===========================\n";

    cout << "\nPresiona 1 para jugar, 0 para salir: ";
    cin >> op;

    if (op == 0) {
        cout << "Gracias por jugar.\n";
        salirDelJuego = true;
    }

    // Introducción
    cout << "\n--- Historia ---" << endl;
    cout << "Una princesa debe escapar de una torre en la que está encerrada." << endl;
    cout << "Tendrá que buscar los elementos necesarios para poder escapar.\n";
    cout << "Es de noche. Frente al ventanal observa el bosque que rodea el lugar," << endl;
    cout << "mientras escucha el viento que sopla entre los árboles." << endl;
    cout << "Sabe que debe escapar y decide explorar la habitación...\n";

    // Bucle principal del juego
    while (continuar && !salirDelJuego) {
        cout << "\nEstás en: ";
        switch (lugarActual) {

            //Fase 1
            case ventana:
                cout << "una ventana con barrotes.\n";
                cout << "Podés:\n";
                cout << "- Ir al norte (escritorio)\n";
                cout << "- Ir al oeste (cama)\n";
                cout << "- Ir al este (armario)\n";
                cout << "- Ver por la ventana\n";
                break;

            case escritorio:
                cout << "un escritorio antiguo con un microscopio.\n";
                cout << "Podés:\n";
                cout << "- Ir al sur (ventana)\n";
                cout << "- Ir al este (armario)\n";
                cout << "- Ir al oeste (cama)\n";
                cout << "- Ver por el microscopio\n";
                cout << "- Tomar una nota escondida\n";
            break;

            case cama:
                cout << "una cama vieja y destendida.\n";
                cout << "Podés:\n";
                cout << "- Ir al sur (ventana)\n";
                cout << "- Ir al este (armario)\n";
                cout << "- Ir al norte (escritorio)\n";
                if(!camaTendida)
                    cout << "- Tender la cama (u)\n";
                else
                    cout << "- Ver nota\n";
            break;

            case armario:
                cout << "un armario antiguo, tiene mucha ropa abultada.\n";
                cout << "Podés:\n";
                cout << "- Ir al sur (ventana)\n";
                cout << "- Ir al norte (escritorio)\n";
                cout << "- Ir al oeste (cama)\n";
                if(!ropaMovida)
                    cout << "- Buscar en el armario (u)\n";
                if(ropaMovida && armarioBloqueado)
                    cout << "- Usar el candado (u)\n";
                else if (!armarioBloqueado)
                    cout << "- Ir al este (escaleras)\n";
            break;

            //Fase 2
            case escaleras:
                cout << "unas escaleras de caracol, estás justo a la mitad.\n";
                cout << "Podés:\n";
                cout << "- Ir arriba (n)\n";
                cout << "- Ir abajo (s)\n";
            break;

            case cima:
                cout << "una cúpula con figuras macabras pintadas en el techo.\n Hay un cadaver apoyado a la pared...\n";
                cout << "Podés:\n";
                cout << "- Ir abajo (s)\n";
                cout << "- Ver la nota del cadaver\n";
                if(!llaveEquipada)
                    cout << "- Tomar la llave del cadaver\n";
            break;

            case puertaVestibulo:
                cout << "una puera de madera tallada, tiene un candado.\n";
                cout << "Podés:\n";
                cout << "- Ir arriba (n)\n";
                if(vestibuloBloqueado)
                    cout << "- Usar el candado\n";
                else
                    cout << "- Ir al sur (vestíbulo)\n";
            break;


            //fase 3
            case vestibulo:
                cout << "un vestíbulo del castillo...\n";
                cout << "Podés:\n";
                cout << "- Ir al sur (lobo)\n";
                cout << "- Ir al oeste (comedor)\n";
                cout << "- Ir al este (estatua)\n";
            break;

            case comedor:
                cout << "un comedor del castillo...\n";
                cout << "Podés:\n";
                cout << "- Ir al sur (fondo de la sala)\n";
                cout << "- Ir al este (vestíbulo)\n";
            break;

            case estatua:
                cout << "una gran estatua, rayos de luna caen sobre esta...\n";
                cout << "Podés:\n";
                cout << "- Ir al sur (fondo de la sala)\n";
                cout << "- Ir al oeste (vestíbulo)\n";
                cout << "- Ver la estatua\n";
                cout << "- Colocar algo en la estatua (u)\n";
                cout << "- Tomar algo de la estatua\n";
            break;

            case escudo:
                cout << "el fondo derecho del castillo...\n";
                if(escudoTirado) cout<<"hay un escudo tirado\n";
                cout << "Podés:\n";
                cout << "- Ir al norte (estatua)\n";
                cout << "- Ir al oeste (lobo)\n";
                if(escudoTirado)
                    cout << "- Tomar el escudo\n";
            break;

            case espada:
                cout << "el fondo izquierdo del castillo...\n";
                if(espadaTirada) cout<<"hay una espada tirada\n";
                cout << "Podés:\n";
                cout << "- Ir al norte (comedor)\n";
                cout << "- Ir al este (lobo)\n";
                if(espadaTirada)
                    cout << "- Tomar la espada\n";
            break;

            case lobo:
                if(loboVivo){
                    cout << "Frente a una bestia letal...\n";
                    cout << "Podés:\n";
                    cout << "- Atacar (u)\n";
                    cout << "- Cubrirte (t)\n";
                    cout << "- Analizar al lobo (v)\n";
                }else{
                    cout << "Frente al cadaver de un imponente lobo, y una puerta detrás...\n";
                    cout << "Podés:\n";
                    cout << "- Ir al norte (vestíbulo)\n";
                    cout << "- Ir al sur (pasillo)\n";
                    cout << "- Ir al oeste (fondo izquierda de la sala)\n";
                    cout << "- Ir al este (fondo derecho de la sala)\n";
                }
            break;

            case pasillo:
                cout << "un pasillo, el camino a la libertad...\n";
                cout << "Podés:\n";
                cout << "- Ir al sur (exterior)\n";
                cout << "- Incendiar el castillo (u)\n";
            break;

            case exterior:
                cout<<"Las afueras del castillo, el viento mueve tu pelo y sientes una gran calma\n";
                if(incendio){
                    cout<<"\nDetrás tuyo, el castillo en llamas...\n\nA lo lejos escuchas los gritos de tu captor, quemándose...\n";
                }
                precisionPelea = (saludActual/3.0f)*100;
                cout<<"\nFIN\n";
                cout<<"\nPrecisión de la pelea: "<<precisionPelea<<"%\n";
                continuar = false;
            break;
        }

        // Pedir acción
        cout << "\n¿Qué querés hacer? (n/s/e/o/v/t/q): ";
        cin >> strAccion;

        // Traducir a acción
        if (strAccion == "n") accion = norte;
        else if (strAccion == "s") accion = sur;
        else if (strAccion == "e") accion = este;
        else if (strAccion == "o") accion = oeste;
        else if (strAccion == "v") accion = ver;
        else if (strAccion == "t") accion = tomar;
        else if (strAccion == "u") accion = usar;
        else if (strAccion == "q") {
            continuar = false;
            break;
        } else accion = invalida;

        // Procesar acción
        cout << "\n--- Resultado de la acción ---\n";

        switch (lugarActual) {

            //Fase 1
            case ventana:
                if (accion == norte) {
                    lugarActual = escritorio;
                    cout << "Caminás hacia el escritorio.\n";
                } else if (accion == oeste) {
                    lugarActual = cama;
                    cout << "Te acercás a la cama...\n";
                } else if (accion == este) {
                    lugarActual = armario;
                    cout << "Te acercás al armario...\n";
                } else if (accion == ver) {
                    cout << "Ves el bosque... y tallado en el marco un número: 7\n";
                } else {
                    cout << "Esa acción no tiene sentido aquí.\n";
                }
                break;

            case escritorio:
                if (accion == sur) {
                    lugarActual = ventana;
                    cout << "Volvés a la ventana.\n";
                } else if (accion == este) {
                    lugarActual = armario;
                    cout << "Te acercás al armario...\n";
                } else if (accion == oeste) {
                    lugarActual = cama;
                    cout << "Vas hacia la cama...\n";
                } else if (accion == ver) {
                    cout << "Te acercas al microscopio y ves el número 3 grabado en la lente.\n";
                    
                } else if (accion == tomar) {
                    cout << "Tomás una nota que estaba debajo del microscopio.\n";
                    cout << "Se lee...\nEspero sepas organizar tus ideas en tu confinamiento\n, primero deberías hacer la cama\n";
                    cout << "Seguido de sentarte aquí y matar el aburrimiento con el microscopio\n por último puedes soñar al ver el mundo por la ventana\n";
                    cout << "Tal vez los ropajes del armario sean una salida de tus penas...\n";
                    cout << "Vuelves a dejar la nota en su lugar\n";
                } else {
                    cout << "Esa acción no tiene sentido aquí.\n";
                }
            break;
                    
            case cama:
                if (accion == sur) {
                    lugarActual = ventana;
                    cout << "Te acercás a la ventana.\n";
                } else if (accion == este) {
                    lugarActual = armario;
                    cout << "Te acercás al armario...\n";
                }else if(accion == norte){
                    lugarActual = escritorio;
                    cout << "Te acercás al escritorio...\n";
                }
                else if (accion == ver && camaTendida) {
                    cout << "Te acercás a la nota y ves el número 9 escrito.\n";  
                } else if (accion == usar && !camaTendida) {
                    cout << "Estirás las sábanas y acomodás las almohadas.\n";
                    cout << "Una nota se encontraba entre las sábanas\n";
                    camaTendida = true;
                } else {
                    cout << "Esa acción no tiene sentido aquí.\n";
                }
            break;

            case armario:
                if (accion == sur) {
                    lugarActual = ventana;
                    cout << "Te acercás a la ventana.\n";
                } else if (accion == oeste) {
                    lugarActual = cama;
                    cout << "Te acercás a la cama...\n";
                }else if(accion == norte){
                    lugarActual = escritorio;
                    cout << "Te acercás al escritorio...\n";
                }else if (accion == usar && !ropaMovida) {
                    cout << "Mueves la ropa hacia los lados.\n";
                    cout << "Una puerta yace al fondo del armario, tiene un candado numérico\n";
                    ropaMovida = true;
                }else if (accion == usar && armarioBloqueado && ropaMovida) {
                    string codigoIngresado;
                    cout << "Ingresa el código:\n";
                    cin >> codigoIngresado;
                    if(codigoIngresado == codigoArmario){
                        cout << "El candado cae al piso...\n";
                        armarioBloqueado = false;
                    }else
                        cout << "No pasa nada...\n";
                }else if (accion==este && !armarioBloqueado){
                    lugarActual = escaleras;
                    cout << "Atraviesas la puerta, te encuentras un unas escaleras de caracol...\n";
                } 
                else {
                    cout << "Esa acción no tiene sentido aquí.\n";
                }
            break;


            //Fase 2
            case escaleras:
                if (accion == norte) {
                    lugarActual = cima;
                    cout << "Subes las escaleras hasta la cima...\n";
                } else if (accion == sur) {
                    lugarActual = puertaVestibulo;
                    cout << "Bajas las escaleras...\n";
                }else {
                    cout << "Esa acción no tiene sentido aquí.\n";
                }
            break;

            case cima:
                if (accion == sur) {
                    lugarActual = escaleras;
                    cout << "Bajas las escaleras, el olor a moho y humo inunda el lugar...\n";
                }else if(accion == ver){
                    cout << "Agarras la carta del cadáver\n.";
                    cout << "...La salida estaba tan cerca, pero ese maldito lobo...\n";
                    cout << "De verdad lo intenté, quise luchar pero me ganó el miedo\n";
                    cout << "...Ahora voy a morir aquí, espero al menos ser de ayuda si ese monstruo rapta alguien más\n";
                    cout << "\nLa puerta se cerró cuando le quité el equipo a la estatua\n para salir abrá que ponerlo en su lugar\n";
                    cout << "\nOtra cosa, ese lobo duerme como una piedra, solo se despertó cuando intenté pasar\n";
                    cout << "Mucha suerte, seas quien seas...\n";
                }else if (accion==tomar && !llaveEquipada){
                    cout << "agarras la llave de la mano del cadaver\n";
                    llaveEquipada = true;
                }
                else {
                    cout << "Esa acción no tiene sentido aquí.\n";
                }
            break;

            case puertaVestibulo:
                if (accion == norte) {
                    lugarActual = escaleras;
                    cout << "subes las escaleras, el olor a moho y humo inunda el lugar...\n";
                }else if (accion==usar && vestibuloBloqueado){
                    if(llaveEquipada){
                        cout << "El candado se abre y cae al piso\n";
                        vestibuloBloqueado = false;
                    }else
                        cout << "No tengo la llave...\n";
                }
                else if(accion==sur && !vestibuloBloqueado){
                    lugarActual = vestibulo;
                    cout << "Sales a un gran vestíbulo, parece la parte principal del castillo\n";
                    cout << "En la puerta de salida hay un lobo blanco dormido...\n";
                }
                else {
                    cout << "Esa acción no tiene sentido aquí.\n";
                }
            break;


            //fase 3
            case vestibulo:
                if (accion == sur) {
                    lugarActual = lobo;
                    cout << "Te acercas al lobo...\n";
                }else if(accion == este){
                    lugarActual = estatua;
                    cout << "Te acercas a la estatua...\n";
                }else if (accion==oeste){
                    lugarActual = comedor;
                    cout << "Te acercas al comedor...\n";
                }
                else {
                    cout << "Esa acción no tiene sentido aquí.\n";
                }
            break;

            case comedor:
                if (accion == sur) {
                    lugarActual = espada;
                    cout << "Te acercas hacia el fondo izquierdo de la sala...\n";
                }else if(accion == este){
                    lugarActual = vestibulo;
                    cout << "Te acercas al centro de la sala...\n";
                }
                else {
                    cout << "Esa acción no tiene sentido aquí.\n";
                }
            break;

            case estatua:
                if (accion == sur) {
                    lugarActual = escudo;
                    cout << "Te acercas al fondo derecho de la sala...\n";
                }else if (accion==oeste){
                    lugarActual = vestibulo;
                    cout << "Te acercas al centro de la sala...\n";
                }else if (accion == ver){
                    cout << "Una estatua de un caballero resplandece en el lugar, sus manos pueden sostener cosas\n";
                }
                else if (accion == usar){
                    if(espadaEquipada){
                        espadaEquipada = false;
                        espadaEstatua = true;
                        cout << "Colocas la espada en la mano derecha de la estatua\n";
                    }
                    if(escudoEquipado){
                        escudoEquipado = false;
                        escudoEstatua = true;
                        cout << "Colocas el escudo en la mano izquierda de la estatua\n";
                    }
                    cout << "Das un paso atrás\n";
                }else if (accion == tomar){
                    if(espadaEstatua){
                        espadaEquipada = true;
                        espadaEstatua = false;
                        cout << "Agarras la espada de la mano derecha de la estatua\n";
                    }
                    if(escudoEstatua){
                        escudoEquipado = true;
                        escudoEstatua = false;
                        cout << "Agarras el escudo de la mano izquierda de la estatua\n";
                    }
                    cout << "Das un paso atrás\n";
                }
                else {
                    cout << "Esa acción no tiene sentido aquí.\n";
                }
            break;

            case escudo:
                if (accion == oeste) {
                    lugarActual = lobo;
                    cout << "Te acercas al lobo...\n";
                }else if(accion == norte){
                    lugarActual = estatua;
                    cout << "Te acercas a la estatua...\n";
                }else if(accion == tomar && escudoTirado){
                    escudoTirado = false;
                    escudoEquipado = true;
                    cout << "Tomas el escudo...\n";
                }
                else {
                    cout << "Esa acción no tiene sentido aquí.\n";
                }
            break;

            case espada:
                if (accion == este) {
                    lugarActual = lobo;
                    cout << "Te acercas al lobo...\n";
                }else if(accion == norte){
                    lugarActual = comedor;
                    cout << "Te acercas al comedor...\n";
                }else if(accion == tomar && espadaTirada){
                    espadaTirada = false;
                    espadaEquipada = true;
                    cout << "Tomas la espada...\n";
                }
                else {
                    cout << "Esa acción no tiene sentido aquí.\n";
                }
            break;

            case lobo:
                if(loboVivo){
                    if(loboDormido){
                        cout << "El lobo se despierta al sentir tu presencia...\n";
                        cout << "Ves que su rostro se torna en intensa furia\n";
                        loboDormido=false;
                    }
                    if(saludActual>0|| saludActualLobo>0){
                        switch (faseActual)
                        {
                        case vulnerable:
                            if(accion == usar){
                                if(espadaEquipada){
                                    saludActualLobo--;
                                    cout<<"La espada hiere al lobo, sangre brota de su herida\n";
                                }else cout<<"No tienes nada para atacar\n";
                                faseActual = atacando;
                            }
                            else if(accion == tomar){
                                if(escudoEquipado){
                                cout<< "Te cubres con el escudo\n";
                                }else cout<<"No tienes nada para cubrirte\n";
                                faseActual = atacando;
                            }
                            else if(accion==ver){
                                cout<<"Buscas una vulnerabilidad, sin embargo el lobo ya estaba vulnerable\n";
                                faseActual = atacando;
                            }
                        break;

                        case defendiendo:
                            if(accion == usar){
                                if(espadaEquipada) cout<<"El lobo logra esquivar, la espada falla\n";
                                else cout<<"No tienes nada para atacar\n";
                                faseActual = atacando;
                            }
                            else if(accion == tomar){
                                if(escudoEquipado) cout<< "Te cubres con el escudo\n";
                                else cout<<"No tienes nada para cubrirte\n";
                                faseActual = atacando;
                            }
                            else if(accion==ver){
                                cout<<"Buscas una vulnerabilidad, y la encuentras\n";
                                faseActual = vulnerable;
                            }
                        break;

                        case atacando:
                            if(accion == usar){
                                saludActual--;
                                cout<<"El lobo salta hacia ti al ver tu imprudencia\n Te abre una herida y sangras\n";
                                faseActual = defendiendo;
                            }
                            else if(accion == tomar){
                                if(escudoEquipado) cout<<"El lobo salta hacia ti\nTe cubres con el escudo\n";
                                else{
                                    cout<<"No tienes nada para cubrirte, el lobo salta hacia y te hiere\n";
                                    saludActual--;
                                }
                                faseActual = defendiendo;
                            }
                            else if(accion==ver){
                                cout<<"Buscas una vulnerabilidad pero el lobo salta hacia ti\n Te provoca una gran herida\n";
                                saludActual-=2;
                                faseActual = atacando;
                            }
                        break;
                    }
                    if(saludActual<=0){
                        cout << "Has muerto...\n";
                        continuar = false;
                    }else if(saludActualLobo<=0){
                        cout << "El lobo ha muerto\n";
                        loboVivo=false;
                    }
                }
            }
                else{
                    if (accion == norte) {
                        lugarActual = vestibulo;
                        cout << "Te acercas al centro de la sala...\n";
                    }else if(accion == este){
                        lugarActual = escudo;
                        cout << "Te acercas al fondo derecho de la sala...\n";
                    }else if (accion==oeste){
                        lugarActual = espada;
                        cout << "Te acercas al lado izquiero de la sala\n";
                    }
                    else if(espadaEstatua&&escudoEstatua&&accion==sur){
                        lugarActual = pasillo;
                        cout << "Empujas la puerta y sales a un pasillo iluminado por antorchas\nVes una tenue luz al final\n";
                    }else if((!espadaEstatua||!escudoEstatua)&&accion==sur){
                        cout<<"Empujas la puerta pero no se mueve\n";
                    }
                    else {
                        cout << "Esa acción no tiene sentido aquí.\n";
                    }
                }
            break;

            case pasillo:
                if(accion==sur){
                    lugarActual = exterior;
                    cout<<"Caminas hacia el exterior del castillo...\n";
                }else if(accion==usar){
                    incendio = true;
                    cout<<"Agarras la antorcha y la tiras hacia un montón de heno\n";
                }
                else {
                    cout << "Esa acción no tiene sentido aquí.\n";
                }
            break;
        }

        //Pausa
        cout << "\nPresioná ENTER para continuar...\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    }
    cout << "\nGracias por jugar.\n";
    return 0;
}
