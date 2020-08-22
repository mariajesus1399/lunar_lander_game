/* Main.c
El Main del juego
Autores:
Leonardo Agüero Villagra
-
-
*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include "juegoActivo.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main(int argc, char **argv)
{

    al_init_font_addon();
    al_init_ttf_addon();
    int running;

    ALLEGRO_DISPLAY * display;
    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_EVENT_QUEUE * queue;
    ALLEGRO_TIMER * timer;

    //para imagenes
    ALLEGRO_BITMAP * menuBackground = NULL;
    ALLEGRO_BITMAP * onClickEmpezar = NULL;
    ALLEGRO_BITMAP * onClickSalir = NULL; 
    ALLEGRO_BITMAP * empezarbackground = NULL;
    ALLEGRO_BITMAP * nave = NULL;

    al_init();

    if(!al_init()){
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }
    if(!al_install_audio()){
        fprintf(stderr, "failed to initialize audio!\n");
        return -1;
    }

    if(!al_init_acodec_addon()){
        fprintf(stderr, "failed to initialize audio codecs!\n");
        return -1;
    }

    if (!al_reserve_samples(1)){
        fprintf(stderr, "failed to reserve samples!\n");
        return -1;
    }

    sample = al_load_sample("resources/sound/musica.ogg");

    if (!sample){
        printf( "Audio clip sample not loaded!\n" );
        return -1;
    }

    display = al_create_display(800, 530);

    if(!display){
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }
 
    queue = al_create_event_queue();
    timer = al_create_timer(1.0 / 60.0);

    al_init_image_addon();
    al_install_keyboard();
    
    //para el mouse
    al_install_mouse();
    ALLEGRO_MOUSE_STATE mousepos;
    al_get_mouse_state(&mousepos);


    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    menuBackground = al_load_bitmap("resources/background/menuBackground.png");
    onClickEmpezar = al_load_bitmap("resources/background/onClickEmpezar.png");
    onClickSalir = al_load_bitmap("resources/background/onClickSalir.png");
    empezarbackground = al_load_bitmap("resources/background/empezarbackground.png");
    nave = al_load_bitmap("resources/background/nave.png");
    

    running = 1;
    float mouseposx = 0;
    float mouseposy = 0;
    al_start_timer(timer);

    while(running == 1) {
        ALLEGRO_EVENT event;
        ALLEGRO_KEYBOARD_STATE keystate;
        al_wait_for_event(queue, &event);

        //si se toca la x de salida sale
        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            running = 0;
        }

        //sale del juego si se toca boton salir
        if((event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) && (mouseposx > 127 && mouseposx < 670 && mouseposy > 290 && mouseposy < 380) ){
            running = 0;
        }

        //empieza el juego
        if((event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) && (mouseposx > 127 && mouseposx < 670 && mouseposy > 175 && mouseposy < 264)){
            int onEmpezar;
            juego_activo(&queue, &event, &onEmpezar, &nave, &empezarbackground, &keystate);
        }

        //posición del mouse
        if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
            mouseposx = event.mouse.x;
            mouseposy = event.mouse.y;
        }

        //Pone la música.
        al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);

        if(event.type == ALLEGRO_EVENT_TIMER){

            if(mouseposx > 127 && mouseposx < 670 && mouseposy > 175 && mouseposy < 264){
                al_draw_bitmap(onClickEmpezar, 0, 0, 0);
            }else if(mouseposx > 127 && mouseposx < 670 && mouseposy > 290 && mouseposy < 380){
                al_draw_bitmap(onClickSalir, 0, 0, 0);                
            }else{
                al_draw_bitmap(menuBackground, 0, 0, 0);
            }

            al_flip_display();

        }
    }

    //Libera memorias
    al_destroy_display(display);
    al_destroy_sample(sample);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_bitmap(menuBackground);
    al_destroy_bitmap(onClickEmpezar);
    al_destroy_bitmap(onClickSalir);
    al_destroy_bitmap(empezarbackground);
    al_destroy_bitmap(nave);
    al_uninstall_keyboard();
    al_uninstall_mouse();

    return 0;
}