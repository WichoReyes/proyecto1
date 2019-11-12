#include <allegro.h>
#include <stdio.h>
#include <iostream>
using namespace std;
struct Nota
{
    float notas[3][3];
    int duracion[8];
};
int main ()
{
    BITMAP *buffer,*bmp,*bmp2,*notas;
    //int readkey();
    struct Nota c1;
    int i=0,j=100, numero;

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

    blit(bmp,buffer,0,0,0,0,1000,667);
    blit(bmp2,buffer,-25,-70,0,0,500,375);
    blit(buffer, screen, 0, 0, 0, 0, 1000, 530);

    for(i=0; i<=1; i++){
        for(j=0; j<=2; j++){
            if((readkey()&0xff)=='0'){
            c1.notas[i][j]=0;
            }
            else if((readkey()&0xff)=='1'){
            c1.notas[i][j]=1;
            }
            else if((readkey()&0xff)=='2'){
            c1.notas[i][j]=2;
            }
            else if((readkey()&0xff)=='3'){
            c1.notas[i][j]=3;
            }
            else if((readkey()&0xff)=='4'){
            c1.notas[i][j]=4;
            }
            else if((readkey()&0xff)=='5'){
            c1.notas[i][j]=5;
            }
            else if((readkey()&0xff)=='6'){
            c1.notas[i][j]=6;
            }
            else if((readkey()&0xff)=='7'){
            c1.notas[i][j]=7;
            }
            else if((readkey()&0xff)=='8'){
            c1.notas[i][j]=8;
            }
            else if((readkey()&0xff)=='9'){
            c1.notas[i][j]=9;
            }
        }
        numero=c1.notas[i][0]*100+c1.notas[i][1]*10+c1.notas[i][2];
        cout<<numero;

        if(numero>=261.6 && numero<293.6){  //do
        blit(notas,buffer,0,0,j,170,21,43);
        j=j+30;
        }
        else if(numero>=293.6 && numero<329.6){  //re
        blit(notas,buffer,0,0,j,165,21,43);
        j=j+30;
        }
        else if(numero>=329.6 && numero<349.2){  //mi
        blit(notas,buffer,0,0,j,160,21,43);
        j=j+30;
        }
        else if(numero>=349.2 && numero<391.9){  //fa
        blit(notas,buffer,0,0,j,150,21,43);
        j=j+30;
        }
        else if(numero>=391.9 && numero<440){  //sol
        blit(notas,buffer,0,0,j,140,21,43);
        j=j+30;
        }
        else if(numero>=440 && numero<493.8){  //la
        blit(notas,buffer,0,0,j,130,21,43);
        j=j+30;
        }
        else if(numero>=493.8 && numero<523.2){  //si
        blit(notas,buffer,0,0,j,125,21,43);
        j=j+30;
        }
        else if(numero>=523.2){  //do
        blit(notas,buffer,0,0,j,115,21,43);
        j=j+30;
        }
        blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
        //readkey();
        //destroy_bitmap(buffer);

    }

    //readkey();
    //destroy_bitmap(buffer);

    for(i=0;i<3;i++){
    numero=c1.notas[i][0]*100+c1.notas[i][1]*10+c1.notas[i][2];
    /*printf("\nIngresar frecuencia: ");
    scanf("%f",&c1.notas[i]);
    printf("\nIngresar duracion: ");
    scanf("%d",&c1.duracion[i]);*/

    if(numero>=261.6 && numero<293.6){  //do
    blit(notas,buffer,0,0,j,170,21,43);
    j=j+30;
    }
    else if(numero>=293.6 && numero<329.6){  //re
    blit(notas,buffer,0,0,j,165,21,43);
    j=j+30;
    }
    else if(numero>=329.6 && numero<349.2){  //mi
    blit(notas,buffer,0,0,j,160,21,43);
    j=j+30;
    }
    else if(numero>=349.2 && numero<391.9){  //fa
    blit(notas,buffer,0,0,j,150,21,43);
    j=j+30;
    }
    else if(numero>=391.9 && numero<440){  //sol
    blit(notas,buffer,0,0,j,140,21,43);
    j=j+30;
    }
    else if(numero>=440 && numero<493.8){  //la
    blit(notas,buffer,0,0,j,130,21,43);
    j=j+30;
    }
    else if(numero>=493.8 && numero<523.2){  //si
    blit(notas,buffer,0,0,j,125,21,43);
    j=j+30;
    }
    else if(numero>=523.2){  //do
    blit(notas,buffer,0,0,j,115,21,43);
    j=j+30;
    }
    blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
    readkey();
    destroy_bitmap(buffer);
    }
    return 0;
}
END_OF_MAIN ()


