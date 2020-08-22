#ifndef JUEGOACTIVO
#define JUEGOACTIVO

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>

    ALLEGRO_EVENT_QUEUE * queue2;
    ALLEGRO_TIMER * timer2;

    float velocidad(float * v_ini, float * t, float g);
    float gravedad(float g, float * v_ini, float * cont);
    void juego_activo(ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, int * onEmpezar, ALLEGRO_BITMAP ** nave, ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_KEYBOARD_STATE * keystate);
    void juego_activo2(ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, int * onEmpezar, ALLEGRO_BITMAP ** nave, ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_KEYBOARD_STATE * keystate, int * fuel, int * score);
    void juego_activo3(ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, int * onEmpezar, ALLEGRO_BITMAP ** nave, ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_KEYBOARD_STATE * keystate, int * fuel, int * score);
    int pausa(ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, ALLEGRO_KEYBOARD_STATE* keystate);
    void perder(ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, ALLEGRO_KEYBOARD_STATE* keystate);
    void ganar(ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, ALLEGRO_KEYBOARD_STATE* keystate, int * fuel, int * score);

#endif