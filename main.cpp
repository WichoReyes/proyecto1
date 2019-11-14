#include <allegro.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
class Nota
{
    public:
    int notas[8][3];
    int duracion[8];
};

int main (){
    ofstream file;
    vector <Nota> notaI;
    vector <Nota> notaO;
    BITMAP *buffer,*bmp,*bmp2,*notas;
    char n;
    int i=0,j=0,x=100, numero;

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

    for(i=0; i<=3; i++){
        Nota notaU;
        for(j=0; j<=2; j++){
            n=readkey()&0xff;
            if(n=='0'){
            notaU.notas[i][j]=0;
            }
            else if(n=='1'){
            notaU.notas[i][j]=1;
            }
            else if(n=='2'){
            notaU.notas[i][j]=2;
            }
            else if(n=='3'){
            notaU.notas[i][j]=3;
            }
            else if(n=='4'){
            notaU.notas[i][j]=4;
            }
            else if(n=='5'){
            notaU.notas[i][j]=5;
            }
            else if(n=='6'){
            notaU.notas[i][j]=6;
            }
            else if(n=='7'){
            notaU.notas[i][j]=7;
            }
            else if(n=='8'){
            notaU.notas[i][j]=8;
            }
            else if(n=='9'){
            notaU.notas[i][j]=9;
            }
        }
        printf("\n%i %i %i \n",notaU.notas[i][0],notaU.notas[i][1],notaU.notas[i][2]);
        notaI.push_back(notaU);
            printf("\n%i%i%i \n",notaI[i].notas[i][0],notaI[i].notas[i][1],notaI[i].notas[i][2]);
        file.open("C:\\Users\\lufer\\Downloads\\proyecto1-master\\notas.vict", ios::out | ios::binary);
        file.write(reinterpret_cast<char * >(&notaI), sizeof(Nota));
        file.close();

        numero=notaI[i].notas[i][0]*100+notaI[i].notas[i][1]*10+notaI[i].notas[i][2];
        cout<<numero<<endl;

        if(numero>=261.6 && numero<293.6){  //do
        blit(notas,buffer,0,0,x,170,21,43);
        x=x+30;
        }
        else if(numero>=293.6 && numero<329.6){  //re
        blit(notas,buffer,0,0,x,165,21,43);
        x=x+30;
        }
        else if(numero>=329.6 && numero<349.2){  //mi
        blit(notas,buffer,0,0,x,160,21,43);
        x=x+30;
        }
        else if(numero>=349.2 && numero<391.9){  //fa
        blit(notas,buffer,0,0,x,150,21,43);
        x=x+30;
        }
        else if(numero>=391.9 && numero<440){  //sol
        blit(notas,buffer,0,0,x,140,21,43);
        x=x+30;
        }
        else if(numero>=440 && numero<493.8){  //la
        blit(notas,buffer,0,0,x,130,21,43);
        x=x+30;
        }
        else if(numero>=493.8 && numero<523.2){  //si
        blit(notas,buffer,0,0,x,125,21,43);
        x=x+30;
        }
        else if(numero>=523.2){  //do
        blit(notas,buffer,0,0,x,115,21,43);
        x=x+30;
        }
        blit(buffer, screen, 0, 0, 0, 0, 1000, 530);

    }

    readkey();

    ifstream entrada;
    entrada.open("C:\\Users\\lufer\\Downloads\\proyecto1-master\\notas.vict", ios::in | ios::binary);
    entrada.read(reinterpret_cast<char * >(&notaO), sizeof(Nota));

    for(i=0; i<=3; i++){
        numero=notaO[i].notas[i][0]*100+notaO[i].notas[i][1]*10+notaO[i].notas[i][2];
        cout<<numero<<endl;

        if(numero>=261.6 && numero<293.6){  //do
        blit(notas,buffer,0,0,x,190,21,43);
        x=x+30;
        }
        else if(numero>=293.6 && numero<329.6){  //re
        blit(notas,buffer,0,0,x,185,21,43);
        x=x+30;
        }
        else if(numero>=329.6 && numero<349.2){  //mi
        blit(notas,buffer,0,0,x,180,21,43);
        x=x+30;
        }
        else if(numero>=349.2 && numero<391.9){  //fa
        blit(notas,buffer,0,0,x,170,21,43);
        x=x+30;
        }
        else if(numero>=391.9 && numero<440){  //sol
        blit(notas,buffer,0,0,x,160,21,43);
        x=x+30;
        }
        else if(numero>=440 && numero<493.8){  //la
        blit(notas,buffer,0,0,x,150,21,43);
        x=x+30;
        }
        else if(numero>=493.8 && numero<523.2){  //si
        blit(notas,buffer,0,0,x,145,21,43);
        x=x+30;
        }
        else if(numero>=523.2){  //do
        blit(notas,buffer,0,0,x,135,21,43);
        x=x+30;
        }
        blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
    }
    entrada.close();
    readkey();
    destroy_bitmap(buffer);
    return 0;
}
END_OF_MAIN ()


