//Velasco Mateo
//Mora Sofía
//Woolfson Carla

#include <iostream>
#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Cuarto.h"
#include "Jugador.h"

#define DELAY 20
#define ALTO 40
#define ANCHO 120


Cuarto piso1(1);

Cuarto piso2(2);

Cuarto *cuartoActual=&piso1;

Jugador jugador(52,37,cuartoActual);
bool game_over;

void setup();
void input();
void update();
void draw();
void menu();

int main() {
    setup();

    setlocale(LC_ALL, "");
    initscr();
	noecho();
	start_color();
	curs_set(FALSE);
	init_pair(oscuro, COLOR_WHITE, COLOR_BLACK);
    init_pair(iluminado, COLOR_BLACK, COLOR_WHITE);
	init_pair(rojo, COLOR_RED,COLOR_BLACK);
	init_pair(ladrillo, COLOR_YELLOW, COLOR_BLACK);
	init_pair(sol, COLOR_RED, COLOR_YELLOW);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	menu();

    while (!game_over)
    {
        input();
	    update();
	    draw();
    }

    endwin();

	cout << endl;

    return 0;
}

void setup()
{
	//Piso 1
	Cuarto room1(1);
	//Baño principal
	room1.add_objeto(1,1,true,{
    "|------------------------------------|"
	});
	room1.add_objeto(44,1,true,{
		"|-------------------------------------------------------------------------|"
	});
	room1.add_objeto(1,2,true,{
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||"
	});
	room1.add_objeto(4,12,true,{
		"|__",
		"|_/",
		"| \\"
	});
	room1.add_objeto(18,8,true,{
		"  -\\  ",
		"    : ",
		"    : ",
		"    : ",
		"    : ",
		"    --",
		"\\_-_-_"
	});
	room1.add_objeto(24,7,true,{
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||"
	});
	room1.add_objeto(24,2,true,{
		"||",
		"||"
	});
	room1.add_objeto(3,15,true,{
		"|||||||||||||||||||||",
		"|||||||||||||||||||||"
	});

	//Comedor
	room1.add_objeto(37,9,true,{
		" __________ ",     
		"|     _    |",     
		"|O   (_)  O|",     
		"|__________|",
		" ||      || "
	});
	room1.add_objeto(31,12,true,{
		"   __ ",
		"__|__ "
	});
	room1.add_objeto(49,12,true,{
		"  __|",
		" |  |"
	});
	room1.add_objeto(1,17,true,{
		"|",
		"|",
		"|",
		"|",
		"|",
		"|"
	});
	room1.add_objeto(118,17,true,{
		"|",
		"|",
		"|",
		"|",
		"|",
		"|"
	});
	room1.add_objeto(1,38,true,{
		"|--------------------------------------------||           ||--------------------------------------------------------||"
	});

	//Habitacion y baño
	room1.add_objeto(63,2,true,{
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||"
	});
	room1.add_objeto(63,15,true,{
		"||||||||||||||||||||",
		"||||||||||||||||||||"
	});
	room1.add_objeto(66,11,true,{
		"_/-           ",
		"|_____________",
		" \\           /",
		"  \\_________/ "
	});
	room1.add_objeto(81,7,true,{
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||"
	});
	room1.add_objeto(81,2,true,{
		"||",
		"||"
	});
	room1.add_objeto(95,5,true,{
		" _________________ ",
		"|   ___     ___   |",
		"|--|___|---|___|--|",
		"|                 |",
		"|                 |",
		"|                 |",
		"|                 |",
		"|                 |",
		"|_________________|"
	});
	room1.add_objeto(90,15,true,{
		"|||||||||||||||||||||||||||",
		"|||||||||||||||||||||||||||"
	});
	room1.add_objeto(117,2,true,{
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||"
	});

	//habitacion peq
	room1.add_objeto(1,25,true,{
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||"
	});
	room1.add_objeto(1,23,true,{
		"|||||||||||||||||||||||",
		"|||||||||||||||||||||||"
	});
	room1.add_objeto(29,23,true,{
		"|||||||||||||||||||",
		"|||||||||||||||||||"
	});
	room1.add_objeto(46,25,true,{
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||"
	});
	room1.add_objeto(11,35,true,{
		"|--_________ ",
		"------------\\",
		"|           |"
	});
	room1.add_objeto(36,35,true,{
		"|   ------",
		"|__  |    ",
		"|  | |    "
	});

	//cocina
	room1.add_objeto(59,25,true,{
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||"
	});
	room1.add_objeto(117,25,true,{
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||"
	});
	room1.add_objeto(59,23,true,{
		"|||||||||||||||||||||||||||||||||||||",
		"|||||||||||||||||||||||||||||||||||||"
	});
	room1.add_objeto(106,23,true,{
		"|||||||||||||",
		"|||||||||||||"
	});
	room1.add_objeto(61,33,true,{
		"   _._   ",
		"|  \\_/   ",
		"|---""-- ",
		"||||||| /",
		"|||||||/ "
	});
	room1.add_puerta(39,1,2, {
		"     "
	});
	/*room1.add_texto(25,25, {
		"               "
	},{
		"Inti: Está anocheciendo , debería entrar a casa rápido...",
		"no quisiera quedarme en la oscuridad…",
		"no quisiera que aparezca...",
		"NO no , mejor ni pensarlo..."
	});*/
	room1.add_texto(1,48,31, {
		"           "
	},{
		"INTI: Todo está oscuro...",
		"Hola?...",
		"¿Hay alguien aqui?",
		"¿O algo...?"
	});

	room1.add_texto(2,26,16, {
		"                                     "
	},{
		"INTI: Necesito buscar más luz, no me gusta esta oscuridad."
	});

	room1.add_texto(3,26,4, {
		"                                     "
	},{
		"ENTIDAD: de mí no puedes esconderte...",
		"..."
	});

	//carta 1
	room1.add_texto(4,42,15,{
		"#"
	},{
		"Inti 10/9/1945:",
		"Todo se siente más pesado en la oscuridad…",
		"El aire no se mueve, pero algo me mira.",
		"El silencio es peor que cualquier ruido.",
		"Si no encuentro algo de luz pronto,",
		"sé que mi mente comenzará a quebrarse."
	});

	//carta 2
	room1.add_texto(5,43,34,{
		"#"
	},{
		"Inti 11/9/1945:"
		"La luz mantiene mi respiración estable.",
		"Cada resplandor me recuerda que sigo aquí.",
		"Cuando pulso, pulso, pulso rápido...",
		"es como sujetar un hilo que me ata a la cordura.",
		"Sin ese ritmo, la sombra me devora lentamente."
	});

	//carta 3
	room1.add_texto(6,66,9,{
		"#"
	},{
		"Inti 14/9/1945:"
		"Subir, siempre subir... arriba hay resguardo.",
		"Pero la voz me sigue, se desliza entre las paredes.",
		"‘No puedes esconderte’, me susurra.",
		"Cada chispa de luz la hace retroceder,",
		"pero el eco… sigue detrás de mí."
	});

	//carta 4
	room1.add_texto(7,62,25,{
		"#"
	},{
		"Inti 15/9/1945:"
		"Respiro fuerte.",
		"No escucho nada… no escucho nada...",
		"¡Si dejo de apretar, dejo de existir!",
		"La luz tiembla, mi mente grita.",
		"¿Y si ya estoy hablando con la sombra?"
	});

	//entrada
	room1.add_luz(0,48,30,11,9);
	room1.get_luz(0)->setEncendida(true);
	//comedor
	room1.add_luz(1,26,7,37,10);
	room1.get_luz(1)->setEncendida(false);
	//hab peq
	room1.add_luz(2,3,25,43,13);
	room1.get_luz(2)->setEncendida(false);
	//baño
	room1.add_luz(3,3,2,21,13);
	room1.get_luz(3)->setEncendida(false);
	//baño hab
	room1.add_luz(4,65,2,16,13);
	room1.get_luz(4)->setEncendida(false);
	//hab p
	room1.add_luz(5,83,2,34,13);
	room1.get_luz(5)->setEncendida(false);
	//cocina
	room1.add_luz(6,61,25,56,13);
	room1.get_luz(6)->setEncendida(false);

	piso1=room1;



	//piso 2
	Cuarto room2(2);
	room2.add_objeto(1,1,true,{
    "|------------------------------------|"
	});
	room2.add_objeto(44,1,true,{
		"|-------------------------------------------------------------------------|"
	});
	room2.add_objeto(1,38,true,{
		"|--------------------------------------------------------------------------------------------------------------------|"
	});

	room2.add_objeto(1,2,true,{
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|"
	});
	room2.add_objeto(118,2,true,{
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|"
	});

	//hab
	room2.add_objeto(33,2,true,{
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||"
	});

	room2.add_objeto(33,15,true,{
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||"
	});
	//hab 1
	room2.add_objeto(2,24,true,{
    "|||||||||||||||||||||||||||||||",
	"|||||||||||||||||||||||||||||||"
	});

	room2.add_objeto(33,34,true,{
		"||",
		"||",
		"||",
		"||"
	});

	//hab 3
	room2.add_objeto(50,2,true,{
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||"
	});

	room2.add_objeto(50,14,true,{
		"|||||||||||||||||||||||||||",
		"|||||||||||||||||||||||||||"
	});

	room2.add_objeto(75,2,true,{
		"||",
		"||",
		"||",
		"||",
		"||"
	});

	room2.add_objeto(75,10,true,{
		"||",
		"||",
		"||",
		"||"
	});
	//hab 4
	room2.add_objeto(89,2,true,{
		"||",
		"||",
		"||",
		"||",
		"||",
		"||"
	});

	room2.add_objeto(89,11,true,{
		"||",
		"||",
		"||"
	});

	room2.add_objeto(89,14,true,{
		"|||||||||||||||||||||||||||||",
		"|||||||||||||||||||||||||||||"
	});

	//baño

	room2.add_objeto(42,23,true,{
		"|||||||||||||||||||||||||||||||||||",
		"|||||||||||||||||||||||||||||||||||"
	});

	room2.add_objeto(84,23,true,{
		"||||||||||||||||||||||||||||||||||",
		"||||||||||||||||||||||||||||||||||"
	});
	room2.add_objeto(42,25,true,{
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||",
		"||"
	});

	room2.add_objeto(44,28,true,{
		"   /",
		"  / ",
		"_/  "
	});

	room2.add_objeto(48,34,true,{
		" _ ",
		"/o\\",
		"\\_/"
	});

	room2.add_objeto(53,30,true,{
		"___"
	});
	room2.add_objeto(57,28,true,{
		"   /",
		"  / ",
		"_/  "
	});

	room2.add_objeto(56,31,true,{
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|"
	});

	room2.add_objeto(61,34,true,{
		" _ ",
		"/o\\",
		"\\_/"
	});

	room2.add_objeto(66,30,true,{
		"___"
	});
	room2.add_objeto(70,28,true,{
		"   /",
		"  / ",
		"_/  "
	});

	room2.add_objeto(69,31,true,{
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|"
	});

	room2.add_objeto(74,34,true,{
		" _ ",
		"/o\\",
		"\\_/"
	});

	room2.add_objeto(79,30,true,{
		"___"
	});
	room2.add_objeto(83,28,true,{
		"   /",
		"  / ",
		"_/  "
	});

	room2.add_objeto(82,31,true,{
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|"
	});

	room2.add_objeto(87,34,true,{
		" _ ",
		"/o\\",
		"\\_/"
	});

	room2.add_objeto(91,30,true,{
		"___"
	});
	room2.add_objeto(95,28,true,{
		"   /",
		"  / ",
		"_/  "
	});

	room2.add_objeto(94,31,true,{
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|"
	});

	room2.add_objeto(99,34,true,{
		" _ ",
		"/o\\",
		"\\_/"
	});

	room2.add_objeto(104,30,true,{
		"___"
	});

	room2.add_objeto(107,31,true,{
		"|",
		"|",
		"|",
		"|",
		"|",
		"|",
		"|"
	});

	room2.add_objeto(107,30,true,{
		"___________",
		"|          ",
		"|          ",
		"|          ",
		"|          ",
		"|          ",
		"|          ",
		"|          "
	});

	room2.add_texto(1,35,6,{
		"               "
	},{
		"INTI: por fin logre llegar arriba. Capaz acá pueda estar a salvo.",
   		"*aún siente mucho temor, el cuarto es muy oscuro, sigue sintiéndose observada*"
	});

	room2.add_texto(2,33,10,{
		"  ",
		"  ",
		"  ",
		"  ",
		"  "		
	},{
		"ENTIDAD: ..jaJaj...AJA..jA..JAA...Ja",
		"...",
		"INTI: YA DEJAME EN PAZ!!!",
		"creo que me estoy volviendo loca...",
		"esto debe ser un sueño, una pesadilla." 
	});

	room2.add_texto(3,62,16,{
		"  ",
		"  ",
		"  ",
		"  ",
		"  ",
		"  ",
		"  "
	},{
		"*desde la oscuridad, casi imperceptible se oye algo*",
        "ENTIDAD: tu crees, en serio,  niñita de luz, que si te atrapo, no será tu fin?",
        "INTI:....",
        "INTI:*entre sollozos* Ya déjame en paz por favor. "

	});

	//carta 5
	room2.add_texto(4,15,21,{
		"#"
	},{
		"Inti 20/9/1945:"
		"Un sonido... algo cayó.",
		"No veo nada, pero está demasiado cerca.",
		"La oscuridad no es solo ausencia,",
		"es un hambre que me muerde la piel.",
		"Tengo que mantener la luz conmigo... o perderé todo."
	});

	//carta 6
	room2.add_texto(5,54,11,{
		"#"
	},{
		"Inti 21/9/1945:"
		"Hay un murmullo bajo mis pasos.",
		"Como si la oscuridad me hablara en un idioma roto.",
		"Al apretar rápido, logro silenciarlo...",
		"pero apenas me detengo, vuelve más fuerte,",
		"como un coro enterrado en mis huesos."
	});

	//carta 7
	room2.add_texto(6,66,37,{
		"#"
	},{
		"Inti 23/9/1945:"
		"Vi mi reflejo en un charco oscuro.",
		"No era yo… era algo que sonreía con mi cara.",
		"La luz lo hizo desaparecer,",
		"pero su risa quedó atrapada en mi garganta.",
		"Quizás nunca estuve sola en este cuerpo."
	});
	//carta 8
	room2.add_texto(7,13,26,{
		"#"
	},{
		"Inti 23/9/1945:"
		"Siento que me observan desde un rincón.",
		"La luz nunca llega ahí, siempre se queda corta.",
		"Cada vez que parpadeo, la figura cambia de sitio.",
		"No sé si la persigo o si me está guiando."
	});

	//hab 1
	room2.add_luz(1,2,2,31,22);
	room2.get_luz(1)->setEncendida(false);
	//hab 2
	room2.add_luz(2,52,2,23,12);
	room2.get_luz(2)->setEncendida(false);
	//hab 3
	room2.add_luz(3,91,2,27,12);
	room2.get_luz(3)->setEncendida(false);
	//cuchitril
	room2.add_luz(4,2,26,31,12);
	room2.get_luz(4)->setEncendida(false);
	//baños
	room2.add_luz(5,44,25,74,13);
	room2.get_luz(5)->setEncendida(false);

	room2.add_puerta(39,1,1, {
		"     "
	});

	piso2=room2;
	cuartoActual=&piso1;
	Jugador jug(52,37,cuartoActual);
	jugador=jug;
    jugador.setup();
}

void input()
{
	int tecla = getch();

	switch (tecla)
	{
	case KEY_UP:
		jugador.mover(arriba);
		break;
	case KEY_DOWN:
		jugador.mover(abajo);
		break;
	case KEY_LEFT:
		jugador.mover(izq);
		break;
	case KEY_RIGHT:
		jugador.mover(der);
		break;
	case 27:
		game_over = TRUE;
		break;
	case ' ':
		jugador.resistir();
		break;
	default:
		break;
	}
}

void update()
{
	int auxCuarto=jugador.update();
	if(cuartoActual->get_idCuarto()!=auxCuarto){
		switch(auxCuarto)
    	{
			case 1:
			cuartoActual=&piso1;
			jugador.set_cuarto(cuartoActual);
    	    break;
		
    	case 2:
			cuartoActual=&piso2;
			jugador.set_cuarto(cuartoActual);
    	    break;

    	default:
    	    break;
    	}
	}

	cuartoActual->update();

	//Win
	bool win=true;
	for(int i=0;i<piso1.get_objetos().size();i++){
		if(piso1.get_objetos()[i].tipo==obj_texto) win=false;
	}
	for(int i=0;i<piso2.get_objetos().size();i++){
		if(piso1.get_objetos()[i].tipo==obj_texto) win=false;
	}
	if(win){
		clear();
		mvaddstr(15,25,"El sol partió la noche en pedazos.");
		mvaddstr(16,25,"Las sombras se disolvieron como humo,");
		mvaddstr(17,25,"y la risa quedó atrapada en el silencio.");
		mvaddstr(18,25,"La luz me cubre, cálida, real.");
		mvaddstr(19,25,"Por fin respiro… y sigo siendo yo.");
		int ch = 0;
		while (ch!='e')
      	{
      	  ch=getch();
      	}

		attron(COLOR_PAIR(sol));
mvaddstr(5,0,"             	              	                                                                                         ");  
mvaddstr(6,0,"                                                                                                                       ");
mvaddstr(7,0,"                                                                                                                       ");
mvaddstr(8,0,"                                                                                                                       ");
mvaddstr(9,0,"                                                                                                                       ");
mvaddstr(10,0,"                                                                                                                       ");
mvaddstr(11,0,"                                                                                                                       ");
mvaddstr(12,0,"                                                                                                                       ");
mvaddstr(13,0,"                                                                                                                       ");
mvaddstr(14,0,"                                                                                                                       ");
mvaddstr(15,0,"                                                                                                                       ");
mvaddstr(16,0,"                                                                                                                       ");
mvaddstr(17,0,"                                                                                                                       ");
mvaddstr(18,0,"                                                                                                                       ");
mvaddstr(19,0,"                                                                                                                       ");
mvaddstr(20,0,"                                                                                                                       ");
mvaddstr(21,0,"                                                                                                                       ");
mvaddstr(22,0,"                                                                                                                       ");
mvaddstr(23,0,"                                                 *******************                                                   ");
mvaddstr(24,0,"                                             ***************************                                               ");
mvaddstr(25,0,"                                         *********************************                                             ");
mvaddstr(26,0,"                                       *************************************                                           ");
mvaddstr(27,0,"                                     ****************************************                                          ");
mvaddstr(28,0,"                                   ********************************************                                        ");
mvaddstr(29,0,"                                  ***********************************************                                      ");
mvaddstr(30,0,"                                 *************************************************                                     ");
mvaddstr(31,0,"                                ***************************************************                                    ");
mvaddstr(32,0,"                               *****************************************************                                   ");
mvaddstr(33,0,"                               ******************************************************                                  ");
mvaddstr(34,0,"                              ********************************************************                                 ");
		attroff(COLOR_PAIR(sol));
		ch = 0;
		while (ch!='e')
      	{
      	  ch=getch();
      	}
		setup();
		menu();
	}

	//Game Over
	if(jugador.getEnergia()<=0){
		clear();
		mvaddstr(15,25,"Tu reflejo se quebró en la penumbra.");
		mvaddstr(16,25,"La sombra tomó tu rostro y lo hizo suyo.");
		mvaddstr(17,25,"La luz no alcanzó a protegerte...");
		mvaddstr(18,25,"ahora caminas vacío, con una sonrisa que no es tuya.");
		mvaddstr(20,23,"-Presiona e para empezar de nuevo");
		int ch = 0;
		while (ch!='e')
      	{
      	  ch=getch();
      	}
		setup();
		menu();
	}
}

void draw()
{
	erase();

	if(has_colors){
    switch (cuartoActual->get_idCuarto())
    {
    case 1:
        piso1.draw();
        break;
    
    case 2:
        piso2.draw();
        break;

    default:
        break;
    }
	jugador.draw();

	mvprintw(0, 80, "[ ENERGIA:       ]");
	for (int i = 0; i < ceil(jugador.getEnergia()); i++)
	{
		mvaddch(0, 91 + i, ACS_CKBOARD);
	}

	}else{
		return;
	}
	refresh();
	delay_output(DELAY);
}


void menu(){
	clear();
	attron(COLOR_PAIR(ladrillo));
	mvaddstr(20,65,"        ___________________________  "        );        
    mvaddstr(21,65,"       /                           \\"        );    
    mvaddstr(22,65,"     /                                \\"     ); 
    mvaddstr(23,65,"   /                                    \\"   );
    mvaddstr(24,65," /________________________________________\\");
    mvaddstr(25,65," |__|__|__|__|__|__|__|__| |__|__|__|__ |   |");
    mvaddstr(26,65," |__|__|__|__|__|__|___|__|__|__|__|__|_|   |");
    mvaddstr(27,65," |___|___|__|__|__|__|__|__|___|__|__ |_|   |");
    mvaddstr(28,65," |___|___|__|__|__|__|__|__|__|__|__|_|_|   |");
    mvaddstr(29,65," |__|__||                         |__|__|   |");
    mvaddstr(30,65," |__|__||                         |__|__|   |");
    mvaddstr(31,65," |__|__||                         |__|__|   |");
    mvaddstr(32,65," |___|__|__|__|__|__|__|__|__|__|___|_|_|   |");
    mvaddstr(33,65," |__|__|      /|__|     |__|     /|__|_ |   |");
    mvaddstr(34,65," |__|__|      /|__|     |__|     /|__|__|   |");
    mvaddstr(35,65," |__|__|      /|__|     |__|     /|__|__|   |");
    mvaddstr(36,65," |__|__|_____ /|__|     |__|_____/| __|_|   /");
    mvaddstr(37,65," |__|__|__|___|___|     |__|__|__|__|___|  /"); 
    mvaddstr(38,65," |__|__|___|___|__|_____|__|__|__|__|__|_ /"  ); 
	attroff(COLOR_PAIR(ladrillo));

	attron(COLOR_PAIR(rojo));
	mvaddstr(2 ,1," .     .                                            _                                       ");
	mvaddstr(3 ,1," /     / , __     ___         ____   __.  , _ , _   \\ ___  .___    ___                      ");
	mvaddstr(4 ,1," |     | |'  `.  /   `       (     .'   \\ |' `|' `. |/   \\ /   \\  /   `                     ");
	mvaddstr(5 ,1," |     | |    | |    |       `--.  |    | |   |   | |    ` |   ' |    |                     ");
	mvaddstr(6 ,1,"  `._.'  /    | `.__/|      \\___.'  `._.' /   '   / `___,' /     `.__/|                     ");
	mvaddstr(7 ,1,"                                                                                            ");
	mvaddstr(8,1," __  __        _         .                                 __  __                           ");
	mvaddstr(9,1," |   |    ___  \\ ___  ` _/_     ___       , _ , _   `      |   |    __.    ___.   ___  .___ ");
	mvaddstr(10,1," |___|   /   ` |/   \\ |  |     /   `      |' `|' `. |      |___|  .'   \\ .'   `  /   ` /   \\");
	mvaddstr(11,1," |   |  |    | |    ` |  |    |    |      |   |   | |      |   |  |    | |    | |    | |   '");
	mvaddstr(12,1," /   /  `.__/| `___,' /  \\__/ `.__/|      /   '   / /      /   /   `._.'  `---| `.__/| /    ");
	mvaddstr(13,1,"                                                                          \\___/             ");
	attroff(COLOR_PAIR(rojo));

	mvaddstr(20,3,"CONTROLES:");
	mvaddstr(21,2,"-Flechas para mover");
	mvaddstr(22,2,"-Espacio para resistir la oscuridad");
	mvaddstr(23,2,"-e para continuar");
	mvaddstr(24,2,"-esc para salir");

	mvaddstr(35,2,"Creado por:");
	mvaddstr(36,2,"Mateo Velasco");
	mvaddstr(37,2,"Mora Sofía");
	mvaddstr(38,2,"Carla Woolfson");

	int ch=0;
	while (ch!='e')
    {
      ch=getch();
	  if(ch==27){
		game_over=true;
		ch='e';
	  };
    }
	clear();
	mvaddstr(15,3,"Inti es una chica nada complicada, un poco ansiosa, ");
	mvaddstr(16,3,"a veces se siente paranoica, un poco inquieta, sobre todo en las noches.");
	mvaddstr(17,3,"Ella se siente perseguida, a veces siente como miradas en las sombras. ");
	mvaddstr(18,3,"Desde chiquita, ha estado hipnotizada por la luz ..."); 
	mvaddstr(19,3, "encantada por el brillo y su seguridad…con las sombras también, pero por otras razones.");
	mvaddstr(20,3,"En ellas no se siente segura, en ellas siempre percibe algo... malo... ");
	mvaddstr(21,3, "algo que la acecha en la oscuridad y la quiere matar. ");

	ch = 0;
	while (ch!='e')
    {
      ch=getch();
	  if(ch==27){
		game_over=true;
		ch='e';
	  };
    }

	clear();
	mvaddstr(15, 3, "Son las 8pm. Inti está llegando a su casa, la oscuridad a su alrededor cada vez más presente.");  
	mvaddstr(16,3, "La seguridad cada vez más lejana. debe seguir en la luz.");
	mvaddstr(18,3, "Instrucciones: Sigue la luz .. o  trata de quedarte en ella."); 
	mvaddstr(20,3,	"Llega a la puerta para pasar al siguiente piso. ");
	mvaddstr(20,3,	"A veces debes comprometerte con la oscuridad. ");
	mvaddstr(20,3,	"Recolecta las piezas de tu diario para que llegue el amanecer.");

	ch = 0;
	while (ch!='e')
    {
      ch=getch();
	  if(ch==27){
		game_over=true;
		ch='e';
	  };
    }
} 
