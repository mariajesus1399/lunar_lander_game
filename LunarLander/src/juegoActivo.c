#include "juegoActivo.h"


float velocidad(float * v_ini, float * t, float g)
{
    float velocidad;
    velocidad = (0.8)*(*v_ini + g * (*t));
    return velocidad;
}

float gravedad(float g, float * v_ini, float * cont)
{
    float caida; //es una posición y
    caida = (*v_ini) * (*cont) + (g * ((*cont)*(*cont)));
    return caida;
}

void juego_activo(ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, int * onEmpezar, ALLEGRO_BITMAP ** nave, ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_KEYBOARD_STATE * keystate)
{
    
    ALLEGRO_TIMER * gametime;
    ALLEGRO_FONT * displayFuel;
    ALLEGRO_FONT * displayVelocity;
    ALLEGRO_BITMAP * plataforma1 = NULL;

    displayFuel = al_load_font("resources/fonts/AbyssinicaSIL-R.ttf", 12, 0);
    displayVelocity = al_load_font("resources/fonts/AbyssinicaSIL-R.ttf", 12, 0);

    plataforma1 = al_load_bitmap("resources/background/plataforma1.png");

    gametime = al_create_timer(1.0 / 60.0);


    *onEmpezar = 1;
    float x = 10.0;
    int fuel = 8000;
    float y = 30.0;
    float v = 0;
    float cont = 0.0;
    float cont2 = 0.0;
    int score = 0;

    al_start_timer(gametime);
    while(*onEmpezar == 1){
        al_wait_for_event(*queue, event);
        al_get_keyboard_state(keystate);
        al_draw_bitmap(*empezarbackground, 0 , 0, 0);

        if(al_key_down(keystate, ALLEGRO_KEY_RIGHT)){
            x += 0.8;
            fuel -= 2.0;
        }
        if(al_key_down(keystate, ALLEGRO_KEY_LEFT)){
            x -= 0.8;
            fuel -= 2.0;
        }

        if(!(al_key_down(keystate, ALLEGRO_KEY_SPACE))){
            cont = cont + (1.0/60.0);
            v = velocidad(&v, &cont, 0.2);
            y = y + gravedad(0.1, &v, &cont);
            cont2 = (0.4)*cont;
        }else if((al_key_down(keystate, ALLEGRO_KEY_SPACE))){
            cont2 = cont2 + (1.0/60.0);
            v = velocidad(&v, &cont2, -0.3);
            y = y + gravedad(-0.15, &v, &cont2);
            cont = (0.4)*cont2;
            fuel -= 6;
        }

        if(fuel < 0){
            *onEmpezar = 0;
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }

        if(event->type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            *onEmpezar = 0;
        }

        if(al_key_down(keystate, ALLEGRO_KEY_P)){
            *onEmpezar = pausa(&*empezarbackground, &*queue, &*event, &*keystate);
        }
    
        if (y > 305 && x < 93 && x > 0){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 407 && x > 93 && x < 112) {
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 407 && x > 173 && x < 184) {
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 495 && x > 184 && x < 233){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 241 && x > 233 && x < 279){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 241 && x > 337 && x < 353){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > (2.2232*x)-530 && x > 353 && x < 468){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 494 && x > 468 && x < 498){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 397 && x > 498 && x < 543){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 313 && x > 597 && x < 678){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 503 && x > 678 && x < 714){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 503 && x > 774 && x < 800){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }

        if (y > 402 && x > 112 && x < 173 && v < 0.6){
            score= score + 100;
            *onEmpezar = 0;/*GANA*/
            juego_activo2(&*queue, &*event, &*onEmpezar, &*nave, &*empezarbackground, &*keystate, &fuel, &score);
        }
        if (y > 238 && x > 279 && x < 337 && v < 0.6){
            score= score + 200;
            *onEmpezar = 0;/*GANA*/
            juego_activo2(&*queue, &*event, &*onEmpezar, &*nave, &*empezarbackground, &*keystate, &fuel, &score);
        }
        if (y > 392 && x > 543 && x < 597 && v < 0.6){
            score= score + 300;
            *onEmpezar = 0;/*GANA*/
            juego_activo2(&*queue, &*event, &*onEmpezar, &*nave, &*empezarbackground, &*keystate, &fuel, &score);

        }
        if (y > 495 && x > 714 && x < 774 && v < 0.6){
            score= score + 400;
            *onEmpezar = 0;/*GANA*/
            juego_activo2(&*queue, &*event, &*onEmpezar, &*nave, &*empezarbackground, &*keystate, &fuel, &score);
        }

        //------------Contrario a ganar------------------------------------

        if (y > 402 && x > 112 && x < 173 && v >= 0.6){
            *onEmpezar = 0;
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 238 && x > 279 && x < 337 && v >= 0.6){
            *onEmpezar = 0;
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 392 && x > 543 && x < 597 && v >= 0.6){
            *onEmpezar = 0;
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 495 && x > 714 && x < 774 && v >= 0.6){
            *onEmpezar = 0;
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }

        //si sale de pantalla de juego
        if(x < 0 || x > 765){
            *onEmpezar = 0;
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }


        if(event->type == ALLEGRO_EVENT_TIMER){
            al_draw_text(displayFuel, al_map_rgb(255,255,255), 120, 407, 0, "100");
            al_draw_text(displayFuel, al_map_rgb(255,255,255), 290, 243, 0, "200");
            al_draw_text(displayFuel, al_map_rgb(255,255,255), 555, 397, 0, "300");
            al_draw_text(displayFuel, al_map_rgb(255,255,255), 722, 500, 0, "400");
            al_draw_textf(displayFuel, al_map_rgb(255, 255, 225), 20, 20, 0, "Combustible: %d", fuel);
            al_draw_textf(displayVelocity, al_map_rgb(255, 255, 225), 20, 30, 0, "Velocidad: %.2f", v);
            al_draw_textf(displayFuel, al_map_rgb(255,255,255), 780, 20, ALLEGRO_ALIGN_RIGHT, "Presione P para pausa");
            al_draw_bitmap(plataforma1, 0, 240, 0); /*PLATAFORMA 1*/
            al_draw_bitmap(*nave, x , y, 0);
            al_flip_display();
        }
    }

    al_destroy_timer(gametime);
    al_destroy_font(displayFuel);
    al_destroy_font(displayVelocity);
    al_destroy_bitmap(plataforma1);

}
