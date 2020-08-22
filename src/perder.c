#include "juegoActivo.h"

void perder(ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, ALLEGRO_KEYBOARD_STATE* keystate)
{
    int onPerder = 2;
    ALLEGRO_FONT * menu;

    menu = al_load_font("resources/fonts/AbyssinicaSIL-R.ttf", 36, 0);

    while(onPerder == 2){
        al_wait_for_event(*queue, event);
        al_get_keyboard_state(keystate);
        al_draw_bitmap(*empezarbackground, 0 , 0, 0);
        
        if(event->type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            onPerder = 1;
        }

        if(al_key_down(keystate, ALLEGRO_KEY_ENTER)){
            onPerder = 0;
        }

        if(event->type == ALLEGRO_EVENT_TIMER){
            al_draw_text(menu, al_map_rgb(255,255,255), 400, 215, ALLEGRO_ALIGN_CENTER, "Has perdido");
            al_draw_text(menu, al_map_rgb(255,255,255), 400, 265, ALLEGRO_ALIGN_CENTER, "Presiona ENTER para ir al menú principal");
            al_flip_display();
        }

    }
    al_destroy_font(menu);
}