#include <allegro.h>
#include <stdio.h>
#include <iostream>
struct Nota
{
    float notas[5];
    int duracion[5];
};
int main ()
{
    BITMAP *buffer,*bmp,*bmp2,*notas;
    float x;
    struct Nota c1;
    int i=0;
    for(i=0;i<5;i++){
    printf("\nIngresar frecuencia: ");
    scanf("%f",&c1.notas[i]);
    printf("\nIngresar frecuencia: ");
    scanf("%d",&c1.duracion[i]);
    }
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1000, 530, 0, 0);
        if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }
    set_volume(70, 70);
    buffer = create_bitmap(1000, 550);
    bmp = load_bitmap("fondo3.bmp",NULL);
    bmp2 = load_bitmap("fondo.bmp",NULL);
    notas = load_bitmap("notas.bmp",NULL);
    clear_to_color(buffer, 0x999999);
    blit(bmp,buffer,0,0,0,0,1000,667);
    blit(bmp2,buffer,-25,-70,0,0,500,375);
    for(i=0;i<5;i++){
    if(c1.notas[i]>=261.62 && c1.notas[i]<293.664){
    blit(notas,buffer,0,0,100,170,21,43);
    }
    }
    blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
    readkey();
    destroy_bitmap(buffer);
    return 0;
}
END_OF_MAIN ()


