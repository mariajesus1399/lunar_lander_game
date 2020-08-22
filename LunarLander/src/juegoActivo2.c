#include "juegoActivo.h"

void juego_activo2(ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, int * onEmpezar, ALLEGRO_BITMAP ** nave, ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_KEYBOARD_STATE * keystate, int * fuel, int * score)
{
    ALLEGRO_TIMER * gametime;
    ALLEGRO_FONT * displayFuel;
    ALLEGRO_FONT * displayVelocity;
    ALLEGRO_BITMAP * plataforma2 = NULL;
    ALLEGRO_FONT * displayPausa;

    displayFuel = al_load_font("resources/fonts/AbyssinicaSIL-R.ttf", 12, 0);
    displayPausa = al_load_font("resources/fonts/AbyssinicaSIL-R.ttf", 12, 0);
    displayVelocity = al_load_font("resources/fonts/AbyssinicaSIL-R.ttf", 12, 0);

    plataforma2 = al_load_bitmap("resources/background/plataforma2.png");


    gametime = al_create_timer(1.0 / 60.0);


    *onEmpezar = 1;
    float x = 10.0;
    float y = 30.0;
    float v = 0;
    float cont = 0.0;
    float cont2 = 0.0;

    al_start_timer(gametime);
    while(*onEmpezar == 1){
        al_wait_for_event(*queue, event);
        al_get_keyboard_state(keystate);
        al_draw_bitmap(*empezarbackground, 0 , 0, 0);

        if(al_key_down(keystate, ALLEGRO_KEY_RIGHT)){
            x += 0.8;
            *fuel -= 2;
        }
        if(al_key_down(keystate, ALLEGRO_KEY_LEFT)){
            x -= 0.8;
            *fuel -= 2;
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
            *fuel -= 6;
        }

        if(al_key_down(keystate, ALLEGRO_KEY_P)){
            *onEmpezar = pausa(&*empezarbackground, &*queue, &*event, &*keystate);
        }

        if(*fuel < 0){
            *onEmpezar = 0;
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }

        if(event->type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            *onEmpezar = 0;
        }

        if (y > 427 && x < 19 && x > 0){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 354 && x > 19 && x < 71) {
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 354 && x > 117 && x < 127) {
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 464 && x > 127 && x < 171){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 374 && x > 171 && x < 248){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 441 && x > 248 && x < 260){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 380 && x > 304 && x < 346){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 414 && x > 346 && x < 365){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 388 && x > 365 && x < 409){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 388 && x > 459 && x < 464){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > (0.827*x)+20.0 && x > 464 && x < 540){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 393 && x > 540 && x < 635){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 457 && x > 635 && x < 709){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 457 && x > 757 && x < 800){
            *onEmpezar = 0;/*PIERDE*/
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        /*GANADOREEEEEES*/
        if (y > 350 && x > 71 && x < 117 && v < 0.6){
            *score = *score + 100;
	        *onEmpezar = 0;/*GANA*/
            juego_activo3(&*queue, &*event, &*onEmpezar, &*nave, &*empezarbackground, &*keystate, &*fuel, &*score);
	    
        }
        if (y > 440 && x > 260 && x < 304 && v < 0.6){
            *score = *score + 400;
	        *onEmpezar = 0;/*GANA*/
            juego_activo3(&*queue, &*event, &*onEmpezar, &*nave, &*empezarbackground, &*keystate, &*fuel, &*score);
        }
        if (y > 389 && x > 409 && x < 459 && v < 0.6){
            *score = *score + 200;
	        *onEmpezar = 0;/*GANA*/
            juego_activo3(&*queue, &*event, &*onEmpezar, &*nave, &*empezarbackground, &*keystate, &*fuel, &*score);
	    
        }
        if (y > 456 && x > 709 && x < 757 && v < 0.6){
            *score = *score + 300;
	        *onEmpezar = 0;/*GANA*/
            juego_activo3(&*queue, &*event, &*onEmpezar, &*nave, &*empezarbackground, &*keystate, &*fuel, &*score);
        }

        //------------Contrario a ganar---------------------------------------------------

        if (y > 350 && x > 71 && x < 117 && v >= 0.6){
	        *onEmpezar = 0;
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 440 && x > 260 && x < 304 && v >= 0.6){
	        *onEmpezar = 0;
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 389 && x > 409 && x < 459 && v >= 0.6){
	        *onEmpezar = 0;
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }
        if (y > 456 && x > 709 && x < 757 && v >= 0.6){
	        *onEmpezar = 0;
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }

        //si sale de pantalla de juego
        if(x < 0 || x > 765){
            *onEmpezar = 0;
            perder(&*empezarbackground, &*queue, &*event, &*keystate);
        }

        if(event->type == ALLEGRO_EVENT_TIMER){
            al_draw_text(displayFuel, al_map_rgb(255,255,255), 80, 355, 0, "100");
            al_draw_text(displayFuel, al_map_rgb(255,255,255), 410, 394, 0, "200");
            al_draw_text(displayFuel, al_map_rgb(255,255,255), 720, 461, 0, "300");
            al_draw_text(displayFuel, al_map_rgb(255,255,255), 270, 445, 0, "400");
            al_draw_textf(displayFuel, al_map_rgb(255, 255, 225), 20, 20, 0, "Combustible: %d", *fuel);
            al_draw_textf(displayVelocity, al_map_rgb(255, 255, 225), 20, 30, 0, "Velocidad: %.2f", v);
            al_draw_textf(displayPausa, al_map_rgb(255,255,255), 780, 20, ALLEGRO_ALIGN_RIGHT, "Presione P para pausa");
            al_draw_bitmap(plataforma2, 0, 333, 0); /*PLATAFORMA 2*/
            al_draw_bitmap(*nave, x , y, 0);
            al_flip_display();
        }
    }

    al_destroy_timer(gametime);
    al_destroy_font(displayFuel);
    al_destroy_font(displayVelocity);
    al_destroy_font(displayPausa);
    al_destroy_bitmap(plataforma2);
}