#include <allegro.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    BITMAP *buffer,*bmp,*bmp2,*notas,*boton, *cursor;
    bool botoon=false;
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1000, 530, 0, 0);
        if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }
    buffer = create_bitmap(1000, 550);
    bmp = load_bitmap("fondo3.bmp",NULL);
    bmp2 = load_bitmap("pentagrama.bmp",NULL);
    notas = load_bitmap("notas.bmp",NULL);
    boton = load_bitmap("boton.bmp",NULL);
    cursor = load_bitmap("cursor.bmp",NULL);
    blit(bmp,buffer,0,0,0,0,1000,667);
    blit(bmp2,buffer,0,0,200,150,640,194);
    blit(boton,buffer,0,0,180,400,100,93);
    while(!botoon){
    if(mouse_x > 178 && mouse_x < 280 && mouse_y > 535 && mouse_y < 630){
         if(mouse_b & 1){
            botoon=true;
            }
        }else{
        blit(bmp,buffer,0,0,0,0,1000,667);
        blit(bmp2,buffer,0,0,200,150,640,194);
        blit(boton,buffer,0,0,180,400,100,93);
        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,20,26);
        blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
    }
    }
    destroy_bitmap(buffer);
    return 0;
}
END_OF_MAIN ()
