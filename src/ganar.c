#include "juegoActivo.h"

void ganar(ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, ALLEGRO_KEYBOARD_STATE* keystate, int * fuel, int * score)
{
    int onGanar;
    ALLEGRO_FONT * menu;
    ALLEGRO_FONT * combustible;
    ALLEGRO_FONT * puntaje;

    menu = al_load_font("resources/fonts/AbyssinicaSIL-R.ttf", 36, 0);
    combustible = al_load_font("resources/fonts/AbyssinicaSIL-R.ttf", 36, 0);
    puntaje = al_load_font("resources/fonts/AbyssinicaSIL-R.ttf", 36, 0);

    *score = (*score) * (*fuel);
    onGanar = 2;

    while(onGanar == 2){
        al_wait_for_event(*queue, event);
        al_get_keyboard_state(keystate);
        al_draw_bitmap(*empezarbackground, 0 , 0, 0);
        
        if(event->type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            onGanar = 1;
        }

        if(al_key_down(keystate, ALLEGRO_KEY_ENTER)){
            onGanar = 0;
        }

        if(event->type == ALLEGRO_EVENT_TIMER){
            al_draw_text(menu, al_map_rgb(255,255,255), 400, 160, ALLEGRO_ALIGN_CENTER, "Has ganado el juego");
            al_draw_textf(combustible, al_map_rgb(255,255,255), 400, 210, ALLEGRO_ALIGN_CENTER, "Combustible final: %d", *fuel);
            al_draw_textf(puntaje, al_map_rgb(255,255,255), 400, 260, ALLEGRO_ALIGN_CENTER, "Puntaje: %d", *score);
            al_draw_text(menu, al_map_rgb(255,255,255), 400, 310, ALLEGRO_ALIGN_CENTER, "Presiona ENTER para ir al menú principal");
            al_flip_display();
        }
    }
    al_destroy_font(puntaje);
    al_destroy_font(combustible);
    al_destroy_font(menu);
}