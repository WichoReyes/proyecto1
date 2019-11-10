#include <allegro.h>
#include <stdio.h>

int main ()
{
    /* *** Con estas lineas de codigo preparamos el entorno para graficos y sonidos *** */
    allegro_init();
    BITMAP *bmp,*buffer,*bmp2;
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1000, 530, 0, 0);
        if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }
    set_volume(70, 70);
    /* ******************************************************************************** */

    buffer = create_bitmap(1000, 550);
    bmp = load_bitmap("fondo3.bmp",NULL);
    bmp2 = load_bitmap("fondo.bmp",NULL);
    clear_to_color(buffer, 0x999999);
   // textout_centre_ex(bmp, font, "Traduccion de notas musicales", 300, 25, 0xFFFFFF, 0x999999);
    blit(bmp,buffer,0,0,0,0,1000,667);
    blit(bmp2,buffer,-25,-70,0,0,500,375);
    blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
    readkey();
    destroy_bitmap(buffer);
    return 0;
}
END_OF_MAIN ()

