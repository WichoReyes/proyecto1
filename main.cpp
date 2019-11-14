#include <allegro.h>
#include <stdio.h>
#include <iostream>
using namespace std;
struct Nota
{
    float notas[8][3];
    int duracion[8];
};
int main ()
{
    BITMAP *buffer,*bmp,*bmp2,*notas,*boton, *cursor;
    bool botoon=false;
    char n;
    int i=0,j=0,x=350, numero;
    struct Nota c1;
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1000, 530, 0, 0);
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0)
    {
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


        for(i=0; i<=7; i++){
            for(j=0; j<=2; j++)
        {
        n=readkey()&0xff;
        if(n=='0')
        {
            c1.notas[i][j]=0;
        }
        else if(n=='1')
        {
            c1.notas[i][j]=1;
        }
        else if(n=='2')
        {
            c1.notas[i][j]=2;
        }
        else if(n=='3')
        {
            c1.notas[i][j]=3;
        }
        else if(n=='4')
        {
            c1.notas[i][j]=4;
        }
        else if(n=='5')
        {
            c1.notas[i][j]=5;
        }
        else if(n=='6')
        {
            c1.notas[i][j]=6;
        }
        else if(n=='7')
        {
            c1.notas[i][j]=7;
        }
        else if(n=='8')
        {
            c1.notas[i][j]=2;
        }
        else if(n=='9')
        {
            c1.notas[i][j]=9;
        }
    }
    numero=c1.notas[i][0]*100+c1.notas[i][1]*10+c1.notas[i][2];
    cout<<numero;
    if(numero>=261.6 && numero<293.6)   //do
    {
        blit(notas,buffer,0,0,x,270,21,43);
        x=x+30;
    }
    else if(numero>=293.6 && numero<329.6)
    {
        blit(notas,buffer,0,0,x,260,21,43);
        x=x+30;
    }
    else if(numero>=329.6 && numero<349.2)
    {
        blit(notas,buffer,0,0,x,250,21,43);
        x=x+30;
    }
    else if(numero>=349.2 && numero<391.9)
    {
        blit(notas,buffer,0,0,x,240,21,43);
        x=x+30;
    }
    else if(numero>=391.9 && numero<440)
    {
        blit(notas,buffer,0,0,x,230,21,43);
        x=x+30;
    }
    else if(numero>=440 && numero<493.8)
    {
        blit(notas,buffer,0,0,x,220,21,43);
        x=x+30;
    }
    else if(numero>=493.8 && numero<523.2)
    {
        blit(notas,buffer,0,0,x,210,21,43);
        x=x+30;
    }
    else if(numero>=523.2)
    {
        blit(notas,buffer,0,0,x,200,21,43);
        x=x+30;
    }
        blit(buffer, screen, 0, 0, 0, 0, 1000, 530);

        }
    while(!botoon)
    {
        if(mouse_x > 178 && mouse_x < 280 && mouse_y > 400 && mouse_y < 500)
        {
            if(mouse_b & 1)
            {
                botoon=true;
                return 0;
            }
        }
        else
        {
            blit(bmp,buffer,0,0,0,0,1000,667);
            blit(bmp2,buffer,0,0,200,150,640,194);
            blit(boton,buffer,0,0,180,400,100,93);
            masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,20,26);
            blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
        }
    }
    readkey();
    destroy_bitmap(buffer);
    return 0;
}
END_OF_MAIN ()
