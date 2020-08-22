#include "juegoActivo.h"

int pausa(ALLEGRO_BITMAP ** empezarbackground, ALLEGRO_EVENT_QUEUE ** queue, ALLEGRO_EVENT * event, ALLEGRO_KEYBOARD_STATE* keystate)
{
    int onPausa = 2;
    ALLEGRO_FONT * menu;
    ALLEGRO_FONT * reanudar;

    menu = al_load_font("resources/fonts/AbyssinicaSIL-R.ttf", 36, 0);
    reanudar = al_load_font("resources/fonts/AbyssinicaSIL-R.ttf", 36, 0);
 
    while(onPausa == 2){
        al_wait_for_event(*queue, event);
        al_get_keyboard_state(keystate);
        al_draw_bitmap(*empezarbackground, 0 , 0, 0);
        
        if(event->type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            onPausa = 1;
        }

        if(al_key_down(keystate, ALLEGRO_KEY_SPACE)){
            onPausa = 1;
        }

        if(al_key_down(keystate, ALLEGRO_KEY_ENTER)){
            onPausa = 0;
        }

        if(event->type == ALLEGRO_EVENT_TIMER){
            al_draw_text(menu, al_map_rgb(255,255,255), 400, 295, ALLEGRO_ALIGN_CENTER, "Presione ENTER para ir al menú principal");
            al_draw_text(reanudar, al_map_rgb(255,255,255), 400, 235, ALLEGRO_ALIGN_CENTER, "Presione SPACE para reanudar");
            al_flip_display();
        }

    }

    al_destroy_font(menu);
    al_destroy_font(reanudar);

    return onPausa;
}