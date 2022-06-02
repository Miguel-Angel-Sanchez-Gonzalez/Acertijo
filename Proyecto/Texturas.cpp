// Texturas.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include <windows.h>
#include <glut.h> 
#include <GL/glu.h>
#include "ImageLoader.h"
#include <time.h>
#include <math.h>
#include <iostream>
#include <sstream>

using namespace std;
static int lados = 0;
static double pi = 3.14159265358979323846;
static double x = 0.7, y = 0.0, z = -0.1;
static double tras = 0.1;
static double zz = 0, xx = 0;
int masx = 0;
int masz = 0;
int bandera1 = 0;

int bandera3 = 0;
int bandera4 = 0;
int bandera5 = 0;
int bandera6 = 0;
int bandera7 = 0;
int bandera8 = 0;
int bandera9 = 0;
int bandera10 = 0;
int bandera11 = 0;
int bandera12 = 0;
int flag = 0;
static int r = 0;
bool salir = false;
static char* texto = "LA CONSOLA TE DARA TU ACERTIJO";
static char* palabras[] = {
"Vuelo entre las flores, vivo en la colmena fabrico ahí la miel y tambien la cera",
"Tengo hojas, soy muy alto y en mis ramas duermen los pajaros",
"No es reloj pero hace tic tac, no usa pilas pero no para de andar",
"Tengo una melena y tambien soy muy veloz asusto a toda la gente con el ruido de mi voz",
"Es una planta con una flor, que gira y gira buscando el sol",
"¿quien sera el que de dia se acuesta y por la noche saldra?",
"Me gusta jugar y tambien ladrar protego la casa cuando mis amos no estan",
"Tiene escamas pero no es pez, tiene corona pero no es un rey",
"redondo como la luna, blanco como la cal, me hacen de leche pura y ya no te digo mas",
"Voy con mi casa al hombro, ando sin tener patas y voy marcando mi huella con un hilito de plata ¿quien soy?" };
static int angulo = 0;
static int direccion[] = { 0,30,60,90,120,150,180,210,240,270,300,330 };
static int random = 0;
static int bandera_random = 0;
static int contador_A = 0, contador_D = 0, contador_angulo = 0, contador_angulo_aux = 360;
static int bandera_signo_A = 1;
static int angulo_final = 0;
static int contador_X = 0, contador_Y = 0;
static int oportunidades = 3;
static int ganador = 0;
static int reloj = 1800 ;
static int bandera_reloj = 0;


//LOGICA
static int matriz[72][81] = {
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, };

//FISICA
static int cuadros[24][27] = {
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
static int posz = 34, posx = 41;
static int esferas[5][2];
using namespace std;
static int piezas[5] = { 0,0,0,0,0 };
static int contador = 0;


GLuint _pared, _cubito, _suelo, _cielo, _imagen, _luna, _abeja, _arbol, _arcoiris, _corazon, _girasol, _caracol, _leon, _perro, _piña, _queso;


GLuint loadTexture(Image* image) {
	GLuint idtextura;
	glGenTextures(1, &idtextura);
	glBindTexture(GL_TEXTURE_2D, idtextura);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return idtextura;
}


void initRendering() {
	Image* lado1 = loadBMP("3.bmp");
	Image* cbt = loadBMP("1.bmp");
	Image* suelo = loadBMP("suelo5.bmp");
	Image* sky = loadBMP("skya.bmp");
	Image* image = loadBMP("imagen.bmp");
	Image* luna = loadBMP("luna.bmp");
	Image* abeja = loadBMP("abeja.bmp");
	Image* arbol = loadBMP("arbol.bmp");
	Image* corazon = loadBMP("corazon.bmp");
	Image* girasol = loadBMP("girasol.bmp");
	Image* caracol = loadBMP("caracol.bmp");
	Image* leon = loadBMP("leon.bmp");
	Image* perro = loadBMP("perro.bmp");
	Image* piña = loadBMP("piña.bmp");
	Image* queso = loadBMP("queso.bmp");

	_pared = loadTexture(lado1);
	_cubito = loadTexture(cbt);
	_suelo = loadTexture(suelo);
	_cielo = loadTexture(sky);
	_imagen = loadTexture(image);
	_luna = loadTexture(luna);
	_abeja = loadTexture(abeja);
	_arbol = loadTexture(arbol);
	_corazon = loadTexture(corazon);
	_girasol = loadTexture(girasol);
	_caracol = loadTexture(caracol);
	_leon = loadTexture(leon);
	_perro = loadTexture(perro);
	_piña = loadTexture(piña);
	_queso = loadTexture(queso);
}


void cargarTextura(GLuint _textura) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textura);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void inline drawString(char* s)
{
	unsigned int i;
	for (i = 0; i < strlen(s); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
}

//CAJAS PERSONALIZADAS
void clavarImagen(int xmet, int zmet, GLuint mi_imagen) {
	//FRENTE
	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();


	//TECHO
	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glEnd();
	glPopMatrix();

	//PISO
	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	//TRASERA
	glPushMatrix();
	cargarTextura(mi_imagen);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glEnd();
	glPopMatrix();
}

//CAJAS PERSONALIZADAS TRASERAS 
void clavarImagen2(int xmet, int zmet, GLuint mi_imagen) {

	//IZQUIERDA
	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	//TECHO
	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glEnd();
	glPopMatrix();

	//TRASERA
	glPushMatrix();
	cargarTextura(mi_imagen);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	cargarTextura(_pared);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, -1.5);
	glEnd();
	glPopMatrix();
}


void clavarImagen3(int xmet, int zmet, GLuint mi_imagen) {
	//TRASERA
	glPushMatrix();
	cargarTextura(mi_imagen);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(-1.5, 1.5, -1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(-1.5, -1.5, -1.5);
	glEnd();
	glPopMatrix();
}


void clavarImagen4(int xmet, int zmet, GLuint mi_imagen) {

	//IZQUIERDA
	glPushMatrix();
	cargarTextura(mi_imagen);
	glRotated(r, 0, 1, 0);
	glTranslated(xx + xmet, 0.4, zz + zmet);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5, -1.5, 1.5);
	glTexCoord2f(3.0f, 0.0f);
	glVertex3f(-1.5, 1.5, 1.5);
	glTexCoord2f(3.0f, 3.0f);
	glVertex3f(1.5, 1.5, 1.5);
	glTexCoord2f(0.0f, 3.0f);
	glVertex3f(1.5, -1.5, 1.5);
	glEnd();
	glPopMatrix();
}

//PAREDES
void cajasPersonalizadas()
{
	int x = -70, z = -43, i, j, m;

	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 27; j++)
		{
			if (cuadros[i][j] == 1)
			{
				if (i == 23 && j == 1 && salir)
				{

				}
				else {

					//MURO FRENTE
					clavarImagen3(49, 28, _imagen);
					clavarImagen3(49, -40, _imagen);
					for (m = -40; m < 28; m++) {
						clavarImagen3(49, m, _imagen);
					}

					//MURO ABAJO
					clavarImagen3(-31, 28, _imagen);
					clavarImagen3(-31, -40, _imagen);

					for (m = -40; m < 28; m++) {
						clavarImagen3(-31, m, _imagen);
					}

					//MURO IZQUIERDA
					clavarImagen4(-31, 28, _imagen);
					clavarImagen4(46, 28, _imagen);

					for (m = -31; m < 46; m++) {
						clavarImagen4(m, 28, _imagen);
					}

					//MURO DERECHA
					clavarImagen4(-31, -43, _imagen);
					clavarImagen4(49, -43, _imagen);

					for (m = -31; m < 49; m++) {
						clavarImagen4(m, -43, _imagen);
					}

					//CAJASDE ACERTIJOS
					// DE FRENTE (DERECHA)
					clavarImagen(45, 26, _abeja);
					clavarImagen(45, 10, _arbol);
					clavarImagen(45, -6, _luna);
					clavarImagen(45, -22, _caracol);
					clavarImagen(45, -38, _corazon);

					//OPUESTAS (IZQUIERDA)
					clavarImagen2(-28, 26, _girasol);
					clavarImagen2(-28, 10, _leon);
					clavarImagen2(-28, -6, _perro);
					clavarImagen2(-28, -22, _piña);
					clavarImagen2(-28, -38, _queso);

					if (bandera_random == 1)
					{

					}
					else {
						bandera_random = 1;
						srand(time(NULL));
						random = rand() % 10;
						//ACERTIJO ALEATORIO
						cout << palabras[random] << endl;
					}
				}
			}
			x = x + 3;
		}
		z = z + 3;
		x = -35;
	}
}


// INICIALES
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




	if (bandera_reloj == 1)
	{

	}
	else {

		if (reloj == 0) {
			texto = "Se termino tu tiempo :(";
			bandera_reloj = 1;
		}
		else {
			reloj--;
			//cout << reloj << endl;
		}
	}




	//CAJAS PERSONALIZADAS-----------------
	glColor3d(195, 155, 211);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	cajasPersonalizadas();
	//PISO-------------------------------------------
	glColor3d(255, 0, 0);
	glPushMatrix();
	cargarTextura(_suelo);
	glRotated(r, 0, 1, 0);
	glTranslated(xx, 0.4, zz);

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-33, -1.6, -42);
	glTexCoord2f(100.0f, 0.0f);
	glVertex3f(48, -1.6, -42);
	glTexCoord2f(100.0f, 100.0f);
	glVertex3f(48, -1.6, 30);
	glTexCoord2f(0.0f, 100.0f);
	glVertex3f(-33, -1.6, 30);
	glEnd();
	glPopMatrix();

	//CIELO-----------------------------------------------
	glColor3d(0, 191, 255);
	glPushMatrix();
	cargarTextura(_cielo);
	glRotated(r, 0, 1, 0);
	glTranslated(xx, 15, zz);

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-43, -11.6, -52);
	glTexCoord2f(100.0f, 0.0f);
	glVertex3f(58, -11.6, -52);
	glTexCoord2f(100.0f, 100.0f);
	glVertex3f(58, -11.6, 40);
	glTexCoord2f(0.0f, 100.0f);
	glVertex3f(-43, -11.6, 40);
	glEnd();
	glPopMatrix();

	glRasterPos3f(-0.4, 0, -1);



	//ACERTIJO ALEATORIO
	drawString(texto);
	glutSwapBuffers();
}


void reshape(int width, int height) {
	const float ar = (float)width / (float)height;
	double aspect = height / width;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

static void idle(void)
{
	glutPostRedisplay();
}


static void validaGanador() {
	if (oportunidades == 2 || oportunidades == 1)
	{
		if (oportunidades == 2)
		{
			texto = "TIENES 2 OPORTUNIDADES";
		}

		if (oportunidades == 1)
		{
			texto = "¡TE QUEDA UNA ULTIMA OPORTUNIDAD!";
		}


	}
	else {
		if (oportunidades == 0 && ganador == 1)
		{
			texto = "GANASTE :)";
			
		}
		else {
			texto = "PERDISTE :(";

		}
		bandera_reloj = 1;

	}
}

static void key(unsigned char key, int x, int y)
{
	int esferasx = 0;
	int esferasz = 0;
	int bandera = 0;
	int bandera2 = 0;
	int banderaYO = 0;
	int comprobar = 0;
	int aux1 = 0;
	int aux2 = 0;

	if (oportunidades > 0 && reloj > 0)
	{
		switch (key)
		{
		case 'a':

			if (contador_A >= 0)
			{
				//AJUSTE DE ANGULO
				contador_angulo = contador_angulo + 30;
				angulo_final = contador_angulo;
			}
			else {
				contador_angulo_aux = contador_angulo_aux + 30;
				angulo_final = contador_angulo_aux;
			}

			//cout << "ANGULO FINAL" << endl;
			//cout << angulo_final << endl;

			//CONTADOR DE PULSOS A
			contador_A = contador_A + 1;
			contador_D = contador_D - 1;

			//SI YA DI 12 PULSOS (ORIGEN)
			if (contador_A == 12 || contador_A == -12)
			{
				contador_A = 0;
				contador_D = 0;
				contador_angulo = 0;
				contador_angulo_aux = 360;
			}

			//cout << "CUENTA DE A" << endl;
			//cout << contador_A << endl;

			//cout << "--------------------------" << endl;

			_asm {
				CMP key, 'a'
				JNE sa
				MOV EAX, angulo

				CMP EAX, 0
				JE igual

				DEC EAX
				MOV angulo, EAX
				JMP sa

				igual : MOV EAX, 11
				MOV angulo, EAX
				sa :
			}
			r = direccion[angulo];
			break;

		case 'd':

			//SI LOS PULSOS DE A > 0
			if (contador_A > 0)
			{
				//AJUSTE DE ANGULO
				contador_angulo = contador_angulo - 30;
				angulo_final = contador_angulo;
			}
			else {
				contador_angulo_aux = contador_angulo_aux - 30;
				angulo_final = contador_angulo_aux;
			}

			//cout << "ANGULO FINAL" << endl;
			//cout << angulo_final << endl;

			//CONTADOR DE PULSOS D
			contador_D = contador_D + 1;
			contador_A = contador_A - 1;

			//SI YA DI 12 PULSOS
			if (contador_D == 12 || contador_D == -12)
			{
				contador_A = 0;
				contador_D = 0;
				contador_angulo = 0;
				contador_angulo_aux = 360;
			}

			//cout << "CUENTA DE D " << endl;
			//cout << contador_D << endl;

			//cout << "--------------------------" << endl;

			_asm {
				CMP key, 'd'
				JNE sa2
				MOV EAX, angulo

				CMP EAX, 0
				JE cero
				CMP EAX, 11
				JE once

				INC EAX
				MOV angulo, EAX
				JMP sa2
				cero : MOV EAX, 1
				MOV angulo, EAX
				JMP sa2

				once : MOV EAX, 0
				MOV angulo, EAX
				sa2 :
			}
			r = direccion[angulo];
			break;


		case 'm':

			//QUESO
			if (contador_X <= 39 && contador_X >= 35)
			{
				if (contador_Y <= 28 && contador_Y >= 24)
				{
					oportunidades = oportunidades - 1;

					if (random == 8)
					{
						cout << "Respuesta correcta! QUESITO ENCONTRADO" << endl;
						ganador = 1;
						oportunidades = 0;
					}
					validaGanador();
				}
			}

			//PIÑA
			if (contador_X <= 24 && contador_X >= 20)
			{
				if (contador_Y <= 28 && contador_Y >= 24)
				{
					oportunidades = oportunidades - 1;

					if (random == 7)
					{
						cout << "Respuesta correcta! PINIA ENCONTRADA" << endl;
						ganador = 1;
						oportunidades = 0;
					}
					validaGanador();
				}
			}

			//CARACOL
			if (contador_X <= 22 && contador_X >= 18)
			{
				if (contador_Y <= -40 && contador_Y >= -44)
				{
					oportunidades = oportunidades - 1;

					if (random == 9)
					{
						cout << "Respuesta correcta! CARACOL ENCONTRADO" << endl;
						ganador = 1;
						oportunidades = 0;
					}
					validaGanador();
				}
			}

			//PERRO
			if (contador_X <= 8 && contador_X >= 4)
			{
				if (contador_Y <= 28 && contador_Y >= 24)
				{
					oportunidades = oportunidades - 1;

					if (random == 6)
					{
						cout << "Respuesta correcta! PERRO ENCONTRADO" << endl;
						ganador = 1;
						oportunidades = 0;
					}
					validaGanador();
				}
			}

			//LEON
			if (contador_X <= -8 && contador_X >= -12)
			{
				if (contador_Y <= 28 && contador_Y >= 24)
				{
					oportunidades = oportunidades - 1;
					if (random == 3)
					{
						cout << "Respuesta correcta! LEON ENCONTRADO" << endl;
						ganador = 1;
						oportunidades = 0;
					}
					validaGanador();
				}
			}

			//FLOR
			if (contador_X <= -24 && contador_X >= -28)
			{
				if (contador_Y <= 28 && contador_Y >= 24)
				{
					oportunidades = oportunidades - 1;
					if (random == 4)
					{
						cout << "Respuesta correcta! GIRASOL ENCONTRADO" << endl;
						ganador = 1;
						oportunidades = 0;
					}
					validaGanador();
				}
			}

			//CORAZON
			if (contador_X <= 39 && contador_X >= 35)
			{
				if (contador_Y <= -40 && contador_Y >= -44)
				{
					oportunidades = oportunidades - 1;
					if (random == 2)
					{
						cout << "Respuesta correcta! CORAZON ENCONTRADO" << endl;
						ganador = 1;
						oportunidades = 0;
					}
					validaGanador();
				}
			}

			//LUNA
			if (contador_X <= 7 && contador_X >= 3)
			{
				if (contador_Y <= -40 && contador_Y >= -44)
				{
					oportunidades = oportunidades - 1;
					if (random == 5)
					{
						cout << "Respuesta correcta! LUNA ENCONTRADA" << endl;
						ganador = 1;
						oportunidades = 0;
					}
					validaGanador();
				}
			}

			//ARBOL
			if (contador_X <= -8 && contador_X >= -12)
			{
				if (contador_Y <= -40 && contador_Y >= -44)
				{
					oportunidades = oportunidades - 1;
					if (random == 1)
					{
						cout << "Respuesta correcta! ARBOL ENCONTRADO" << endl;
						ganador = 1;
						oportunidades = 0;
					}
					validaGanador();
				}
			}

			//ABEJA
			if (contador_X <= -24 && contador_X >= -28)
			{
				if (contador_Y <= -40 && contador_Y >= -44)
				{
					oportunidades = oportunidades - 1;
					if (random == 0)
					{
						cout << "Respuesta correcta! ABEJA ENCONTRADA" << endl;
						ganador = 1;
						oportunidades = 0;
					}
					validaGanador();
				}
			}
			//cout << "OPORTUNIDADES:" << endl;
			//cout << oportunidades << endl;
			break;

		case 'w':

			texto = " ";


			//PRIMER CUADRANTE
			if (angulo_final >= 0 && angulo_final < 90)
			{
				if (contador_X > -27 && contador_X < 37)
				{
					//cout << "1ER CUADRANTE" << endl;

					if (angulo_final == 0)
					{
						contador_X = contador_X + 1;
					}

					if (angulo_final == 30)
					{
						contador_X = contador_X + 1;
					}

					if (angulo_final == 60)
					{
						contador_Y = contador_Y + 1;
					}
				}
			}

			//SEGUNDO CUADRANTE
			else if (angulo_final >= 90 && angulo_final < 180)
			{
				//cout << "2DO CUADRANTE" << endl;
				if (contador_Y > -43 && contador_Y < 26)
				{
					if (angulo_final == 90)
					{
						contador_Y = contador_Y + 1;
					}

					if (angulo_final == 120)
					{
						contador_Y = contador_Y + 1;
					}

					if (angulo_final == 150)
					{
						contador_X = contador_X - 1;
					}
				}
			}

			//TERCERO CUADRANTE
			else if (angulo_final >= 180 && angulo_final < 270)
			{
				//cout << "3RO CUADRANTE" << endl;

				if (contador_X > -26 && contador_X < 38)
				{
					if (angulo_final == 180)
					{
						contador_X = contador_X - 1;
					}

					if (angulo_final == 210)
					{
						contador_X = contador_X - 1;
					}

					if (angulo_final == 240)
					{
						contador_Y = contador_Y - 1;
					}
				}

			}

			//CUARTO CUADRANTE
			else if (angulo_final >= 270 && angulo_final < 360)
			{
				//cout << "4TO CUADRANTE" << endl;

				if (contador_Y > -42 && contador_Y < 27)
				{
					if (angulo_final == 270)
					{
						contador_Y = contador_Y - 1;
					}

					if (angulo_final == 300)
					{
						contador_Y = contador_Y - 1;
					}
					if (contador_X > -27 && contador_X < 37) {

						if (angulo_final == 330)
						{
							contador_X = contador_X + 1;
						}
					}
				}
			}

			//REINICIO DE CUADRANTE
			else if (angulo_final == 360)
			{
				if (contador_X > -27 && contador_X < 37) {
					//cout << "1ER CUADRANTE" << endl;
					//contador_X = contador_X + 1;
				}
			}

			//cout << "X: " << endl;
			///cout << contador_X << endl;
			//cout << "Y: " << endl;
			//cout << contador_Y << endl;
			//cout << "-----------------------------" << endl;

			_asm { CMP key, 'w'
			JNE fin

				sa3 : MOV EAX, r
				CMP EAX, 0
				JAE validar
				JMP nada
				validar : CMP EAX, 30
				JBE accion
				CMP EAX, 330
				JE accion
				JMP nada
				accion : MOV EDX, posx
				DEC EDX
				MOV masx, EDX
				MOV EDX, posz
				MOV masz, EDX
				MOV flag, 1
				fuera : MOV bandera1, 1
				JMP fin
				nada :
		fin:
			}

			if (flag == 1)
			{
				if (bandera1 == 1)
				{
					aux1 = matriz[masx][masz];
				}

				_asm {
					MOV EAX, aux1
					CMP EAX, 1
					JE sa4
					CMP EAX, 3
					JE sa4

					sig : MOV bandera2, 1
					JMP sa4
					sa4 :
				}

				//CONTROL DE PARTE DEL EJE X
				if (bandera2 == 1)
				{
					zz = zz + 1;
					posx = posx - 1;
				}

				_asm {
					MOV EAX, masx
					CMP EAX, 71
					JE two
					JMP nada2
					two : MOV EDX, masz
					CMP EDX, 3
					JE exito

					CMP EDX, 4
					JE exito

					CMP EDX, 5
					JE exito
					JMP nada2
					exito : MOV bandera3, 1
					nada2 :
				}
			}
			_asm {
				MOV EAX, r
				CMP EAX, 60
				JAE validar2
				JMP nada3
				validar2 : CMP EAX, 120
				JBE accion2
				JMP nada3
				accion2 : MOV EAX, posx
				MOV masx, EAX
				MOV EAX, posz
				INC EAX
				MOV masz, EAX
				MOV flag, 2
				MOV bandera4, 1
				nada3 :
			}
			if (flag == 2) {

				// CONTROL DE PARTE DE EJE Y
				if (matriz[masx][masz] != 1 && matriz[masx][masz] != 3)
				{
					xx = xx - 1;
					posz = posz + 1;
				}

				_asm {
					MOV EAX, masx
					CMP EAX, 71
					JE two2

					JMP nada5
					two2 : MOV EAX, masz
					CMP EAX, 3
					JE exito2

					CMP EAX, 4
					JE exito2

					CMP EAX, 5
					JE exito2
					JMP nada5
					exito2 : MOV bandera6, 1
					nada5 :
				}
			}
			_asm {
				MOV EAX, r
				CMP EAX, 150
				JAE validar6
				JMP nada6
				validar6 : CMP EAX, 210
				JBE accion6
				JMP nada6
				accion6 : MOV EAX, posx
				INC EAX
				MOV masx, EAX
				MOV EAX, posz
				MOV masz, EAX
				MOV flag, 3
				MOV bandera7, 1
				nada6 :
			}
			if (flag == 3) {

				//2DA PARTE DEL EJE X
				if (matriz[masx][masz] != 1 && matriz[masx][masz] != 3)
				{
					zz = zz - 1;
					posx = posx + 1;
				}

				_asm {
					MOV EAX, masx
					CMP EAX, 71
					JE two8

					JMP nada8
					two8 : MOV EAX, masz
					CMP EAX, 3
					JE exito8

					CMP EAX, 4
					JE exito8

					CMP EAX, 5
					JE exito8
					JMP nada8
					exito8 : MOV bandera9, 1
					nada8 :
				}
			}

			_asm {

				MOV EAX, r
				CMP EAX, 240
				JAE validar9
				JMP nada9
				validar9 : CMP EAX, 300
				JBE accion9
				JMP nada9
				accion9 : MOV EAX, posx
				MOV masx, EAX
				MOV EAX, posz
				DEC EAX
				MOV masz, EAX
				MOV flag, 4
				MOV bandera10, 1
				nada9 :
			}
			if (flag == 4) {

				//2DA PARTE DEL EJE Y
				if (matriz[masx][masz] != 1 && matriz[masx][masz] != 3)
				{
					xx = xx + 1;
					posz = posz - 1;
				}

				_asm {
					MOV EAX, masx
					CMP EAX, 71
					JE two11

					JMP nada11
					two11 : MOV EAX, masz
					CMP EAX, 3
					JE exito11

					CMP EAX, 4
					JE exito11

					CMP EAX, 5
					JE exito11
					JMP nada11
					exito11 : MOV bandera12, 1
					nada11 :
				}
			}
			break;
		}
	}

	glutPostRedisplay();
}

int main(int argc, char** argv) {
	(&argc, argv);
	glutInitWindowSize(1900, 5000);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("ACERTIJO By Miguel, Berenice, Estefania");
	glutSetCursor(GLUT_CURSOR_NONE);
	initRendering();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);
	glClearColor(0, 0, 0, 100);
	glutMainLoop();
}