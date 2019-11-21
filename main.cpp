#include <allegro.h>
#include <stdio.h>
#include <winalleg.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct Nota
{
    float notas[8][3];
    int duracion[8][2];
};
int main ()
{
    BITMAP *buffer,*bmp,*bmp2,*notas,*boton, *cursor, *blanca,*redonda,*corchea,*bmp3;
    bool botoon=false;
    ofstream file;
    vector <Nota> NotaI;
    vector <Nota> NotaO;
    char n,f;
    int i=0,j=0,x=350, numero,duracion, k=0,numero1,numero2,numero3,numero4,numero5,numero6,numero7,
    duracion1,duracion2,duracion3,duracion4,duracion5,duracion6,duracion7,duracionnew=500;
    struct Nota c1,NotaU;
    float n0,n1,n2,n3,n4,n5,n6,n7;
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
    buffer = create_bitmap(1000, 530);
    bmp = load_bitmap("fondo3.bmp",NULL);
    bmp2 = load_bitmap("pentagrama.bmp",NULL);
    bmp3 = load_bitmap("1234.bmp",NULL);
    notas = load_bitmap("notas.bmp",NULL);
    boton = load_bitmap("boton.bmp",NULL);
    blanca = load_bitmap("blanca.bmp",NULL);
    cursor = load_bitmap("cursor.bmp",NULL);
    redonda = load_bitmap("redonda.bmp",NULL);
    corchea = load_bitmap("corchea.bmp",NULL);

    while(!key[KEY_ESC])
    {
        blit(bmp3,buffer,0,0,0,0,1000,667);
        textout_centre_ex(buffer, font, "A.- Introducir notas manualmente", 530/2, 100, 0xFFFFFF, 0x333333);
        textout_centre_ex(buffer, font, "B.- Introducir notas por un archivo", 530/2, 110, 0xFFFFFF, 0x333333);
        blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
        readkey();
        if(key[KEY_A])
        {
            blit(bmp,buffer,0,0,0,0,1000,667);
            blit(bmp2,buffer,0,0,200,150,640,194);
            blit(boton,buffer,0,0,180,400,100,93);


            for(i=0; i<=7; i++)
            {
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
                        c1.notas[i][j]=8;
                    }
                    else if(n=='9')
                    {
                        c1.notas[i][j]=9;
                    }
                }
                for(k=0; k<=1; k++)
                {
                    f=readkey()&0xff;
                    if(f=='0')
                    {
                        c1.duracion[i][k]=0;
                    }
                    else if(f=='1')
                    {
                        c1.duracion[i][k]=1;
                    }
                    else if(f=='2')
                    {
                        c1.duracion[i][k]=2;
                    }
                    else if(f=='3')
                    {
                        c1.duracion[i][k]=3;
                    }
                    else if(f=='4')
                    {
                        c1.duracion[i][k]=4;
                    }
                    else if(f=='5')
                    {
                        c1.duracion[i][k]=5;
                    }
                    else if(f=='6')
                    {
                        c1.duracion[i][k]=6;
                    }
                    else if(f=='7')
                    {
                        c1.duracion[i][k]=7;
                    }
                    else if(f=='8')
                    {
                        c1.duracion[i][k]=8;
                    }
                    else if(n=='9')
                    {
                        c1.duracion[i][k]=9;
                    }
                }
                numero=c1.notas[i][0]*100+c1.notas[i][1]*10+c1.notas[i][2];
                duracion=c1.duracion[i][0]*10+c1.duracion[i][1];
                cout<<numero<<endl;
                cout<<duracion<<endl;
                if(numero>=261.6 && numero<293.6)   //do
                {
                    if(duracion==10)
                    {
                        blit(notas,buffer,0,0,x,270,21,43);
                        x=x+30;
                    }
                    else if(duracion==20)
                    {
                        blit(blanca,buffer,0,0,x,270,21,44);
                        x=x+30;
                    }
                    else if(duracion==40)
                    {
                        blit(redonda,buffer,0,0,x,275,21,43);
                        x=x+30;
                    }
                    else if(duracion==50)
                    {
                        blit(corchea,buffer,0,0,x,270,30,43);
                        x=x+30;
                    }
                }
                else if(numero>=293.6 && numero<329.6)      //re
                {
                    if(duracion==10)
                    {
                        blit(notas,buffer,0,0,x,260,21,43);
                        x=x+30;
                    }
                    else if(duracion==20)
                    {
                        blit(blanca,buffer,0,0,x,260,21,44);
                        x=x+30;
                    }
                    else if(duracion==40)
                    {
                        blit(redonda,buffer,0,0,x,270,21,43);
                        x=x+30;
                    }
                    else if(duracion==50)
                    {
                        blit(corchea,buffer,0,0,x,260,30,43);
                        x=x+30;
                    }
                }
                else if(numero>=329.6 && numero<349.2)      //mi
                {
                    if(duracion==10)
                    {
                        blit(notas,buffer,0,0,x,250,21,43);
                        x=x+30;
                    }
                    else if(duracion==20)
                    {
                        blit(blanca,buffer,0,0,x,250,21,44);
                        x=x+30;
                    }
                    else if(duracion==40)
                    {
                        blit(redonda,buffer,0,0,x,265,21,43);
                        x=x+30;
                    }
                    else if(duracion==50)
                    {
                        blit(corchea,buffer,0,0,x,250,30,43);
                        x=x+30;
                    }
                }
                else if(numero>=349.2 && numero<391.9)      //fa
                {
                    if(duracion==10)
                    {
                        blit(notas,buffer,0,0,x,240,21,43);
                        x=x+30;
                    }
                    else if(duracion==20)
                    {
                        blit(blanca,buffer,0,0,x,240,21,44);
                        x=x+30;
                    }
                    else if(duracion==40)
                    {
                        blit(redonda,buffer,0,0,x,255,21,43);
                        x=x+30;
                    }
                    else if(duracion==50)
                    {
                        blit(corchea,buffer,0,0,x,240,30,43);
                        x=x+30;
                    }
                }
                else if(numero>=391.9 && numero<440)        //sol
                {
                    if(duracion==10)
                    {
                        blit(notas,buffer,0,0,x,230,21,43);
                        x=x+30;
                    }
                    else if(duracion==20)
                    {
                        blit(blanca,buffer,0,0,x,230,21,44);
                        x=x+30;
                    }
                    else if(duracion==40)
                    {
                        blit(redonda,buffer,0,0,x,245,21,43);
                        x=x+30;
                    }
                    else if(duracion==50)
                    {
                        blit(corchea,buffer,0,0,x,230,30,43);
                        x=x+30;
                    }
                }
                else if(numero>=440 && numero<493.8)        //la
                {
                    if(duracion==10)
                    {
                        blit(notas,buffer,0,0,x,220,21,43);
                        x=x+30;
                    }
                    else if(duracion==20)
                    {
                        blit(blanca,buffer,0,0,x,220,21,44);
                        x=x+30;
                    }
                    else if(duracion==40)
                    {
                        blit(redonda,buffer,0,0,x,235,21,43);
                        x=x+30;
                    }
                    else if(duracion==50)
                    {
                        blit(corchea,buffer,0,0,x,220,30,43);
                        x=x+30;
                    }
                }
                else if(numero>=493.8 && numero<523.2)      //si
                {
                    if(duracion==10)
                    {
                        blit(notas,buffer,0,0,x,210,21,43);
                        x=x+30;
                    }
                    else if(duracion==20)
                    {
                        blit(blanca,buffer,0,0,x,210,21,44);
                        x=x+30;
                    }
                    else if(duracion==40)
                    {
                        blit(redonda,buffer,0,0,x,225,21,43);
                        x=x+30;
                    }
                    else if(duracion==50)
                    {
                        blit(corchea,buffer,0,0,x,210,30,43);
                        x=x+30;
                    }
                }
                else if(numero>=523.2)                  //do
                {
                    if(duracion==10)
                    {
                        blit(notas,buffer,0,0,x,200,21,43);
                        x=x+30;
                    }
                    else if(duracion==20)
                    {
                        blit(blanca,buffer,0,0,x,200,21,44);
                        x=x+30;
                    }
                    else if(duracion==40)
                    {
                        blit(redonda,buffer,0,0,x,215,21,43);
                        x=x+30;
                    }
                    else if(duracion==50)
                    {
                        blit(corchea,buffer,0,0,x,200,30,43);
                        x=x+30;
                    }
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
                        x=350;
                        numero=c1.notas[0][0]*100+c1.notas[0][1]*10+c1.notas[0][2];
                        duracion=(c1.duracion[0][0]*10+c1.duracion[0][1])*100;
                        numero1=c1.notas[1][0]*100+c1.notas[1][1]*10+c1.notas[1][2];
                        duracion1=(c1.duracion[1][0]*10+c1.duracion[1][1])*100;
                        numero2=c1.notas[2][0]*100+c1.notas[2][1]*10+c1.notas[2][2];
                        duracion2=(c1.duracion[2][0]*10+c1.duracion[2][1])*100;
                        numero3=c1.notas[3][0]*100+c1.notas[3][1]*10+c1.notas[3][2];
                        duracion3=(c1.duracion[3][0]*10+c1.duracion[3][1])*100;
                        numero4=c1.notas[4][0]*100+c1.notas[4][1]*10+c1.notas[4][2];
                        duracion4=(c1.duracion[4][0]*10+c1.duracion[4][1])*100;
                        numero5=c1.notas[5][0]*100+c1.notas[5][1]*10+c1.notas[5][2];
                        duracion5=(c1.duracion[5][0]*10+c1.duracion[5][1])*100;
                        numero6=c1.notas[6][0]*100+c1.notas[6][1]*10+c1.notas[6][2];
                        duracion6=(c1.duracion[6][0]*10+c1.duracion[6][1])*100;
                        numero7=c1.notas[7][0]*100+c1.notas[7][1]*10+c1.notas[7][2];
                        duracion7=(c1.duracion[7][0]*10+c1.duracion[7][1])*100;
                        if(numero>=261.6 && numero<293.6){      //do
                            n0=261.625565;
                            if(duracion==1000){
                            blit(notas,buffer,0,0,x,270,21,43);
                            blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==2000){
                            blit(blanca,buffer,0,0,x,270,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==4000){
                            blit(redonda,buffer,0,0,x,275,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==5000){
                            blit(corchea,buffer,0,0,x,270,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracionnew);
                            x=x+30;
                            }
                        }else if(numero>=293.6 && numero<329.6){    //re
                            n0=293.664768;
                            if(duracion==1000){
                            blit(notas,buffer,0,0,x,260,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==2000){
                            blit(blanca,buffer,0,0,x,260,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==4000){
                            blit(redonda,buffer,0,0,x,270,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==5000){
                            blit(corchea,buffer,0,0,x,260,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracionnew);
                            x=x+30;
                            }
                        }else if(numero>=329.6 && numero<349.2){    //mi
                            n0=329.627557;
                            if(duracion==1000){
                            blit(notas,buffer,0,0,x,250,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==2000){
                            blit(blanca,buffer,0,0,x,250,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==4000){
                            blit(redonda,buffer,0,0,x,265,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==5000){
                            blit(corchea,buffer,0,0,x,250,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracionnew);
                            x=x+30;
                            }
                        }else if(numero>=349.2 && numero<391.9){       //fa
                            n0=349.228231;
                            if(duracion==1000){
                            blit(notas,buffer,0,0,x,240,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==2000){
                            blit(blanca,buffer,0,0,x,240,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==4000){
                            blit(redonda,buffer,0,0,x,255,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==5000){
                            blit(corchea,buffer,0,0,x,240,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracionnew);
                            x=x+30;
                            }
                        }else if(numero>=391.9 && numero<440){          //sol
                            n0=391.995436;
                            if(duracion==1000){
                            blit(notas,buffer,0,0,x,230,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==2000){
                            blit(blanca,buffer,0,0,x,230,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==4000){
                            blit(redonda,buffer,0,0,x,245,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==5000){
                            blit(corchea,buffer,0,0,x,230,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracionnew);
                            x=x+30;
                            }
                        }else if(numero>=440 && numero<493.8){          //la
                            n0=440;
                            if(duracion==1000){
                            blit(notas,buffer,0,0,x,220,21,43);
                            blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==2000){
                            blit(blanca,buffer,0,0,x,220,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==4000){
                            blit(redonda,buffer,0,0,x,235,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==5000){
                            blit(corchea,buffer,0,0,x,220,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracionnew);
                            x=x+30;
                            }
                        }else if(numero>=493.8 && numero<523.2){        //si
                            n0=493.883301;
                            if(duracion==1000){
                            blit(notas,buffer,0,0,x,210,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==2000){
                            blit(blanca,buffer,0,0,x,210,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==4000){
                            blit(redonda,buffer,0,0,x,225,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==5000){
                            blit(corchea,buffer,0,0,x,210,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracionnew);
                            x=x+30;
                            }
                        }else if(numero>=523.2){            //do
                            n0=523.252131;
                            if(duracion==1000){
                            blit(notas,buffer,0,0,x,200,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==2000){
                            blit(blanca,buffer,0,0,x,200,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==4000){
                            blit(redonda,buffer,0,0,x,215,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracion);
                            x=x+30;
                            }else if(duracion==5000){
                            blit(corchea,buffer,0,0,x,200,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n0,duracionnew);
                            x=x+30;
                            }
                        }
                        if(numero1>=261.6 && numero1<293.6){      //do
                            n1=261.625565;
                            if(duracion1==1000){
                            blit(notas,buffer,0,0,x,270,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==2000){
                            blit(blanca,buffer,0,0,x,270,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==4000){
                            blit(redonda,buffer,0,0,x,275,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==5000){
                            blit(corchea,buffer,0,0,x,270,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracionnew);
                            x=x+30;
                            }
                        }else if(numero1>=293.6 && numero1<329.6){    //re
                            n1=293.664768;
                            if(duracion1==1000){
                            blit(notas,buffer,0,0,x,260,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==2000){
                            blit(blanca,buffer,0,0,x,260,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==4000){
                            blit(redonda,buffer,0,0,x,270,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==5000){
                            blit(corchea,buffer,0,0,x,260,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracionnew);
                            x=x+30;
                            }
                        }else if(numero1>=329.6 && numero1<349.2){    //mi
                            n1=329.627557;
                            if(duracion1==1000){
                            blit(notas,buffer,0,0,x,250,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==2000){
                            blit(blanca,buffer,0,0,x,250,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==4000){
                            blit(redonda,buffer,0,0,x,265,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==5000){
                            blit(corchea,buffer,0,0,x,250,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracionnew);
                            x=x+30;
                            }
                        }else if(numero1>=349.2 && numero1<391.9){       //fa
                            n1=349.228231;
                            if(duracion1==1000){
                            blit(notas,buffer,0,0,x,240,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==2000){
                            blit(blanca,buffer,0,0,x,240,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==4000){
                            blit(redonda,buffer,0,0,x,255,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==5000){
                            blit(corchea,buffer,0,0,x,240,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracionnew);
                            x=x+30;
                            }
                        }else if(numero1>=391.9 && numero1<440){          //sol
                            n1=391.995436;
                            if(duracion1==1000){
                            blit(notas,buffer,0,0,x,230,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==2000){
                            blit(blanca,buffer,0,0,x,230,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==4000){
                            blit(redonda,buffer,0,0,x,245,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==5000){
                            blit(corchea,buffer,0,0,x,230,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracionnew);
                            x=x+30;
                            }
                        }else if(numero1>=440 && numero1<493.8){          //la
                            n1=440;
                            if(duracion1==1000){
                            blit(notas,buffer,0,0,x,220,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==2000){
                            blit(blanca,buffer,0,0,x,220,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==4000){
                            blit(redonda,buffer,0,0,x,235,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==5000){
                            blit(corchea,buffer,0,0,x,220,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracionnew);
                            x=x+30;
                            }
                        }else if(numero1>=493.8 && numero1<523.2){        //si
                            n1=493.883301;
                            if(duracion1==1000){
                            blit(notas,buffer,0,0,x,210,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==2000){
                            blit(blanca,buffer,0,0,x,210,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==4000){
                            blit(redonda,buffer,0,0,x,225,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==5000){
                            blit(corchea,buffer,0,0,x,210,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracionnew);
                            x=x+30;
                            }
                        }else if(numero1>=523.2){            //do
                            n1=523.252131;
                            if(duracion1==1000){
                            blit(notas,buffer,0,0,x,200,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==2000){
                            blit(blanca,buffer,0,0,x,200,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==4000){
                            blit(redonda,buffer,0,0,x,215,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracion1);
                            x=x+30;
                            }else if(duracion1==5000){
                            blit(corchea,buffer,0,0,x,200,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n1,duracionnew);
                            x=x+30;
                            }
                        }
                        if(numero2>=261.6 && numero2<293.6){      //do
                            n2=261.625565;
                            if(duracion2==1000){
                            blit(notas,buffer,0,0,x,270,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==2000){
                            blit(blanca,buffer,0,0,x,270,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==4000){
                            blit(redonda,buffer,0,0,x,275,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==5000){
                            blit(corchea,buffer,0,0,x,270,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracionnew);
                            x=x+30;
                            }
                        }else if(numero2>=293.6 && numero2<329.6){    //re
                            n2=293.664768;
                            if(duracion2==1000){
                            blit(notas,buffer,0,0,x,260,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==2000){
                            blit(blanca,buffer,0,0,x,260,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==4000){
                            blit(redonda,buffer,0,0,x,270,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==5000){
                            blit(corchea,buffer,0,0,x,260,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracionnew);
                            x=x+30;
                            }
                        }else if(numero2>=329.6 && numero2<349.2){    //mi
                            n2=329.627557;
                            if(duracion2==1000){
                            blit(notas,buffer,0,0,x,250,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==2000){
                            blit(blanca,buffer,0,0,x,250,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==4000){
                            blit(redonda,buffer,0,0,x,265,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==5000){
                            blit(corchea,buffer,0,0,x,250,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracionnew);
                            x=x+30;
                            }
                        }else if(numero2>=349.2 && numero2<391.9){       //fa
                            n2=349.228231;
                            if(duracion2==1000){
                            blit(notas,buffer,0,0,x,240,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==2000){
                            blit(blanca,buffer,0,0,x,240,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==4000){
                            blit(redonda,buffer,0,0,x,255,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==5000){
                            blit(corchea,buffer,0,0,x,240,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracionnew);
                            x=x+30;
                            }
                        }else if(numero2>=391.9 && numero2<440){          //sol
                            n2=391.995436;
                            if(duracion2==1000){
                            blit(notas,buffer,0,0,x,230,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==2000){
                            blit(blanca,buffer,0,0,x,230,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==4000){
                            blit(redonda,buffer,0,0,x,245,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==5000){
                            blit(corchea,buffer,0,0,x,230,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracionnew);
                            x=x+30;
                            }
                        }else if(numero2>=440 && numero2<493.8){          //la
                            n2=440;
                            if(duracion2==1000){
                            blit(notas,buffer,0,0,x,220,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==2000){
                            blit(blanca,buffer,0,0,x,220,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==4000){
                            blit(redonda,buffer,0,0,x,235,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==5000){
                            blit(corchea,buffer,0,0,x,220,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracionnew);
                            x=x+30;
                            }
                        }else if(numero2>=493.8 && numero2<523.2){        //si
                            n2=493.883301;
                            if(duracion2==1000){
                            blit(notas,buffer,0,0,x,210,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==2000){
                            blit(blanca,buffer,0,0,x,210,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==4000){
                            blit(redonda,buffer,0,0,x,225,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==5000){
                            blit(corchea,buffer,0,0,x,210,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracionnew);
                            x=x+30;
                            }
                        }else if(numero2>=523.2){            //do
                            n2=523.252131;
                            if(duracion2==1000){
                            blit(notas,buffer,0,0,x,200,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==2000){
                            blit(blanca,buffer,0,0,x,200,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==4000){
                            blit(redonda,buffer,0,0,x,215,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracion2);
                            x=x+30;
                            }else if(duracion2==5000){
                            blit(corchea,buffer,0,0,x,200,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n2,duracionnew);
                            x=x+30;
                            }
                        }
                        if(numero3>=261.6 && numero3<293.6){      //do
                            n3=261.625565;
                            if(duracion3==1000){
                            blit(notas,buffer,0,0,x,270,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==2000){
                            blit(blanca,buffer,0,0,x,270,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==4000){
                            blit(redonda,buffer,0,0,x,275,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==5000){
                            blit(corchea,buffer,0,0,x,270,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracionnew);
                            x=x+30;
                            }
                        }else if(numero3>=293.6 && numero3<329.6){    //re
                            n3=293.664768;
                            if(duracion3==1000){
                            blit(notas,buffer,0,0,x,260,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==2000){
                            blit(blanca,buffer,0,0,x,260,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==4000){
                            blit(redonda,buffer,0,0,x,270,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==5000){
                            blit(corchea,buffer,0,0,x,260,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracionnew);
                            x=x+30;
                            }
                        }else if(numero3>=329.6 && numero3<349.2){    //mi
                            n3=329.627557;
                            if(duracion3==1000){
                            blit(notas,buffer,0,0,x,250,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==2000){
                            blit(blanca,buffer,0,0,x,250,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==4000){
                            blit(redonda,buffer,0,0,x,265,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==5000){
                            blit(corchea,buffer,0,0,x,250,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracionnew);
                            x=x+30;
                            }
                        }else if(numero3>=349.2 && numero3<391.9){       //fa
                            n3=349.228231;
                            if(duracion3==1000){
                            blit(notas,buffer,0,0,x,240,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==2000){
                            blit(blanca,buffer,0,0,x,240,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==4000){
                            blit(redonda,buffer,0,0,x,255,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==5000){
                            blit(corchea,buffer,0,0,x,240,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracionnew);
                            x=x+30;
                            }
                        }else if(numero3>=391.9 && numero3<440){          //sol
                            n3=391.995436;
                            if(duracion3==1000){
                            blit(notas,buffer,0,0,x,230,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==2000){
                            blit(blanca,buffer,0,0,x,230,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==4000){
                            blit(redonda,buffer,0,0,x,245,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==5000){
                            blit(corchea,buffer,0,0,x,230,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracionnew);
                            x=x+30;
                            }
                        }else if(numero3>=440 && numero3<493.8){          //la
                            n3=440;
                            if(duracion3==1000){
                            blit(notas,buffer,0,0,x,220,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==2000){
                            blit(blanca,buffer,0,0,x,220,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==4000){
                            blit(redonda,buffer,0,0,x,235,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==5000){
                            blit(corchea,buffer,0,0,x,220,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracionnew);
                            x=x+30;
                            }
                        }else if(numero3>=493.8 && numero3<523.2){        //si
                            n3=493.883301;
                            if(duracion3==1000){
                            blit(notas,buffer,0,0,x,210,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==2000){
                            blit(blanca,buffer,0,0,x,210,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==4000){
                            blit(redonda,buffer,0,0,x,225,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==5000){
                            blit(corchea,buffer,0,0,x,210,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracionnew);
                            x=x+30;
                            }
                        }else if(numero3>=523.2){            //do
                            n3=523.252131;
                            if(duracion3==1000){
                            blit(notas,buffer,0,0,x,200,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==2000){
                            blit(blanca,buffer,0,0,x,200,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==4000){
                            blit(redonda,buffer,0,0,x,215,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracion3);
                            x=x+30;
                            }else if(duracion3==5000){
                            blit(corchea,buffer,0,0,x,200,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n3,duracionnew);
                            x=x+30;
                            }
                        }
                            if(numero4>=261.6 && numero4<293.6){      //do
                            n4=261.625565;
                            if(duracion4==1000){
                            blit(notas,buffer,0,0,x,270,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==2000){
                            blit(blanca,buffer,0,0,x,270,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==4000){
                            blit(redonda,buffer,0,0,x,275,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==5000){
                            blit(corchea,buffer,0,0,x,270,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracionnew);
                            x=x+30;
                            }
                        }else if(numero4>=293.6 && numero4<329.6){    //re
                            n4=293.664768;
                            if(duracion4==1000){
                            blit(notas,buffer,0,0,x,260,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==2000){
                            blit(blanca,buffer,0,0,x,260,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==4000){
                            blit(redonda,buffer,0,0,x,270,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==5000){
                            blit(corchea,buffer,0,0,x,260,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracionnew);
                            x=x+30;
                            }
                        }else if(numero4>=329.6 && numero4<349.2){    //mi
                            n4=329.627557;
                            if(duracion4==1000){
                            blit(notas,buffer,0,0,x,250,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==2000){
                            blit(blanca,buffer,0,0,x,250,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==4000){
                            blit(redonda,buffer,0,0,x,265,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==5000){
                            blit(corchea,buffer,0,0,x,250,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracionnew);
                            x=x+30;
                            }
                        }else if(numero4>=349.2 && numero4<391.9){       //fa
                            n4=349.228231;
                            if(duracion4==1000){
                            blit(notas,buffer,0,0,x,240,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==2000){
                            blit(blanca,buffer,0,0,x,240,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==4000){
                            blit(redonda,buffer,0,0,x,255,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==5000){
                            blit(corchea,buffer,0,0,x,240,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracionnew);
                            x=x+30;
                            }
                        }else if(numero4>=391.9 && numero4<440){          //sol
                            n4=391.995436;
                            if(duracion4==1000){
                            blit(notas,buffer,0,0,x,230,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==2000){
                            blit(blanca,buffer,0,0,x,230,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==4000){
                            blit(redonda,buffer,0,0,x,245,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==5000){
                            blit(corchea,buffer,0,0,x,230,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracionnew);
                            x=x+30;
                            }
                        }else if(numero4>=440 && numero4<493.8){          //la
                            n4=440;
                            if(duracion4==1000){
                            blit(notas,buffer,0,0,x,220,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==2000){
                            blit(blanca,buffer,0,0,x,220,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==4000){
                            blit(redonda,buffer,0,0,x,235,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==5000){
                            blit(corchea,buffer,0,0,x,220,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracionnew);
                            x=x+30;
                            }
                        }else if(numero4>=493.8 && numero4<523.2){        //si
                            n4=493.883301;
                            if(duracion4==1000){
                            blit(notas,buffer,0,0,x,210,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==2000){
                            blit(blanca,buffer,0,0,x,210,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==4000){
                            blit(redonda,buffer,0,0,x,255,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==5000){
                            blit(corchea,buffer,0,0,x,210,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracionnew);
                            x=x+30;
                            }
                        }else if(numero4>=523.2){            //do
                            n4=523.252131;
                            if(duracion4==1000){
                            blit(notas,buffer,0,0,x,200,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==2000){
                            blit(blanca,buffer,0,0,x,200,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==4000){
                            blit(redonda,buffer,0,0,x,215,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracion4);
                            x=x+30;
                            }else if(duracion4==5000){
                            blit(corchea,buffer,0,0,x,200,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n4,duracionnew);
                            x=x+30;
                            }
                        }
                        if(numero5>=261.6 && numero5<293.6){      //do
                            n5=261.625565;
                            if(duracion5==1000){
                            blit(notas,buffer,0,0,x,270,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==2000){
                            blit(blanca,buffer,0,0,x,270,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==4000){
                            blit(redonda,buffer,0,0,x,275,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==5000){
                            blit(corchea,buffer,0,0,x,270,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracionnew);
                            x=x+30;
                            }
                        }else if(numero5>=293.6 && numero5<329.6){    //re
                            n5=293.664768;
                            if(duracion5==1000){
                            blit(notas,buffer,0,0,x,260,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==2000){
                            blit(blanca,buffer,0,0,x,260,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==4000){
                            blit(redonda,buffer,0,0,x,270,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==5000){
                            blit(corchea,buffer,0,0,x,260,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracionnew);
                            x=x+30;
                            }
                        }else if(numero5>=329.6 && numero5<349.2){    //mi
                            n5=329.627557;
                            if(duracion5==1000){
                            blit(notas,buffer,0,0,x,250,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==2000){
                            blit(blanca,buffer,0,0,x,250,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==4000){
                            blit(redonda,buffer,0,0,x,265,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==5000){
                            blit(corchea,buffer,0,0,x,250,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracionnew);
                            x=x+30;
                            }
                        }else if(numero5>=349.2 && numero5<391.9){       //fa
                            n5=349.228231;
                            if(duracion5==1000){
                            blit(notas,buffer,0,0,x,240,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==2000){
                            blit(blanca,buffer,0,0,x,240,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==4000){
                            blit(redonda,buffer,0,0,x,255,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==5000){
                            blit(corchea,buffer,0,0,x,240,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracionnew);
                            x=x+30;
                            }
                        }else if(numero5>=391.9 && numero5<440){          //sol
                            n5=391.995436;
                            if(duracion5==1000){
                            blit(notas,buffer,0,0,x,230,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==2000){
                            blit(blanca,buffer,0,0,x,230,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==4000){
                            blit(redonda,buffer,0,0,x,245,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==5000){
                            blit(corchea,buffer,0,0,x,230,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracionnew);
                            x=x+30;
                            }
                        }else if(numero5>=440 && numero5<493.8){          //la
                            n5=440;
                            if(duracion5==1000){
                            blit(notas,buffer,0,0,x,220,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==2000){
                            blit(blanca,buffer,0,0,x,220,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==4000){
                            blit(redonda,buffer,0,0,x,235,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==5000){
                            blit(corchea,buffer,0,0,x,220,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracionnew);
                            x=x+30;
                            }
                        }else if(numero5>=493.8 && numero5<523.2){        //si
                            n5=493.883301;
                            if(duracion5==1000){
                            blit(notas,buffer,0,0,x,210,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==2000){
                            blit(blanca,buffer,0,0,x,210,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==4000){
                            blit(redonda,buffer,0,0,x,225,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==5000){
                            blit(corchea,buffer,0,0,x,210,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracionnew);
                            x=x+30;
                            }
                        }else if(numero5>=523.2){            //do
                            n5=523.252131;
                            if(duracion5==1000){
                            blit(notas,buffer,0,0,x,200,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==2000){
                            blit(blanca,buffer,0,0,x,200,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==4000){
                            blit(redonda,buffer,0,0,x,215,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracion5);
                            x=x+30;
                            }else if(duracion5==5000){
                            blit(corchea,buffer,0,0,x,200,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n5,duracionnew);
                            x=x+30;
                            }
                        }
                            if(numero6>=261.6 && numero6<293.6){      //do
                            n6=261.625565;
                            if(duracion6==1000){
                            blit(notas,buffer,0,0,x,270,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==2000){
                            blit(blanca,buffer,0,0,x,270,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==4000){
                            blit(redonda,buffer,0,0,x,275,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==5000){
                            blit(corchea,buffer,0,0,x,270,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracionnew);
                            x=x+30;
                            }
                        }else if(numero6>=293.6 && numero6<329.6){    //re
                            n6=293.664768;
                            if(duracion6==1000){
                            blit(notas,buffer,0,0,x,260,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==2000){
                            blit(blanca,buffer,0,0,x,260,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==4000){
                            blit(redonda,buffer,0,0,x,270,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==5000){
                            blit(corchea,buffer,0,0,x,260,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracionnew);
                            x=x+30;
                            }
                        }else if(numero6>=329.6 && numero6<349.2){    //mi
                            n6=329.627557;
                            if(duracion6==1000){
                            blit(notas,buffer,0,0,x,250,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==2000){
                            blit(blanca,buffer,0,0,x,250,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==4000){
                            blit(redonda,buffer,0,0,x,265,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==5000){
                            blit(corchea,buffer,0,0,x,250,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracionnew);
                            x=x+30;
                            }
                        }else if(numero6>=349.2 && numero6<391.9){       //fa
                            n6=349.228231;
                            if(duracion6==1000){
                            blit(notas,buffer,0,0,x,240,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==2000){
                            blit(blanca,buffer,0,0,x,240,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==4000){
                            blit(redonda,buffer,0,0,x,255,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==5000){
                            blit(corchea,buffer,0,0,x,240,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracionnew);
                            x=x+30;
                            }
                        }else if(numero6>=391.9 && numero6<440){          //sol
                            n6=391.995436;
                            if(duracion6==1000){
                            blit(notas,buffer,0,0,x,230,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==2000){
                            blit(blanca,buffer,0,0,x,230,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==4000){
                            blit(redonda,buffer,0,0,x,245,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==5000){
                            blit(corchea,buffer,0,0,x,230,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracionnew);
                            x=x+30;
                            }
                        }else if(numero6>=440 && numero6<493.8){          //la
                            n6=440;
                            if(duracion6==1000){
                            blit(notas,buffer,0,0,x,220,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==2000){
                            blit(blanca,buffer,0,0,x,220,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==4000){
                            blit(redonda,buffer,0,0,x,235,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==5000){
                            blit(corchea,buffer,0,0,x,220,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracionnew);
                            x=x+30;
                            }
                        }else if(numero6>=493.8 && numero6<523.2){        //si
                            n6=493.883301;
                            if(duracion6==1000){
                            blit(notas,buffer,0,0,x,210,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==2000){
                            blit(blanca,buffer,0,0,x,210,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==4000){
                            blit(redonda,buffer,0,0,x,225,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==5000){
                            blit(corchea,buffer,0,0,x,210,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracionnew);
                            x=x+30;
                            }
                        }else if(numero6>=523.2){            //do
                            n6=523.252131;
                            if(duracion6==1000){
                            blit(notas,buffer,0,0,x,200,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==2000){
                            blit(blanca,buffer,0,0,x,200,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==4000){
                            blit(redonda,buffer,0,0,x,215,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracion6);
                            x=x+30;
                            }else if(duracion6==5000){
                            blit(corchea,buffer,0,0,x,200,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n6,duracionnew);
                            x=x+30;
                            }
                        }
                        if(numero7>=261.6 && numero7<293.6){      //do
                            n7=261.625565;
                            if(duracion7==1000){
                            blit(notas,buffer,0,0,x,270,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==2000){
                            blit(blanca,buffer,0,0,x,270,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==4000){
                            blit(redonda,buffer,0,0,x,275,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==5000){
                            blit(corchea,buffer,0,0,x,270,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracionnew);
                            x=x+30;
                            }
                        }else if(numero7>=293.6 && numero7<329.6){    //re
                            n7=293.664768;
                            if(duracion7==1000){
                            blit(notas,buffer,0,0,x,260,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==2000){
                            blit(blanca,buffer,0,0,x,260,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==4000){
                            blit(redonda,buffer,0,0,x,270,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==5000){
                            blit(corchea,buffer,0,0,x,260,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracionnew);
                            x=x+30;
                            }
                        }else if(numero7>=329.6 && numero7<349.2){    //mi
                            n7=329.627557;
                            if(duracion7==1000){
                            blit(notas,buffer,0,0,x,250,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==2000){
                            blit(blanca,buffer,0,0,x,250,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==4000){
                            blit(redonda,buffer,0,0,x,265,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==5000){
                            blit(corchea,buffer,0,0,x,250,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracionnew);
                            x=x+30;
                            }
                        }else if(numero7>=349.2 && numero7<391.9){       //fa
                            n7=349.228231;
                            if(duracion7==1000){
                            blit(notas,buffer,0,0,x,240,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==2000){
                            blit(blanca,buffer,0,0,x,240,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==4000){
                            blit(redonda,buffer,0,0,x,255,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==5000){
                            blit(corchea,buffer,0,0,x,240,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracionnew);
                            x=x+30;
                            }
                        }else if(numero7>=391.9 && numero7<440){          //sol
                            n7=391.995436;
                            if(duracion7==1000){
                            blit(notas,buffer,0,0,x,230,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==2000){
                            blit(blanca,buffer,0,0,x,230,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==4000){
                            blit(redonda,buffer,0,0,x,245,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==5000){
                            blit(corchea,buffer,0,0,x,230,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracionnew);
                            x=x+30;
                            }
                        }else if(numero7>=440 && numero7<493.8){          //la
                            n7=440;
                            if(duracion7==1000){
                            blit(notas,buffer,0,0,x,220,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==2000){
                            blit(blanca,buffer,0,0,x,220,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==4000){
                            blit(redonda,buffer,0,0,x,235,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==5000){
                            blit(corchea,buffer,0,0,x,220,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracionnew);
                            x=x+30;
                            }
                        }else if(numero7>=493.8 && numero7<523.2){        //si
                            n7=493.883301;
                            if(duracion7==1000){
                            blit(notas,buffer,0,0,x,210,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==2000){
                            blit(blanca,buffer,0,0,x,210,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==4000){
                            blit(redonda,buffer,0,0,x,225,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==5000){
                            blit(corchea,buffer,0,0,x,210,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracionnew);
                            x=x+30;
                            }
                        }else if(numero7>=523.2){            //do
                            n7=523.252131;
                            if(duracion7==1000){
                            blit(notas,buffer,0,0,x,200,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==2000){
                            blit(blanca,buffer,0,0,x,200,21,44);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==4000){
                            blit(redonda,buffer,0,0,x,215,21,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracion7);
                            x=x+30;
                            }else if(duracion7==5000){
                            blit(corchea,buffer,0,0,x,200,30,43);
                             blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
                            Beep(n7,duracionnew);
                            x=x+30;
                            }
                        }
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
        }
        else if(key[KEY_B])
        {
            blit(bmp,buffer,0,0,0,0,1000,667);
            blit(bmp2,buffer,0,0,200,150,640,194);
            blit(boton,buffer,0,0,180,400,100,93);
            char cadena[128];
   ifstream fe("frecuencias.txt");

   while(!fe.eof()) {
      fe >> cadena;
      cout << cadena << endl;
   }

/*            if(cadena>=261.6 && cadena<293.6)   //do
        {
            blit(notas,buffer,0,0,x,270,21,43);
            x=x+30;
        }
        else if(cadena>=293.6 && cadena<329.6)
        {
            blit(notas,buffer,0,0,x,260,21,43);
            x=x+30;
        }
        else if(cadena>=329.6 && cadena<349.2)
        {
            blit(notas,buffer,0,0,x,250,21,43);
            x=x+30;
        }
        else if(cadena>=349.2 && cadena<391.9)
        {
            blit(notas,buffer,0,0,x,240,21,43);
            x=x+30;
        }
        else if(cadena>=391.9 && cadena<440)
        {
            blit(notas,buffer,0,0,x,230,21,43);
            x=x+30;
        }
        else if(cadena>=440 && cadena<493.8)
        {
            blit(notas,buffer,0,0,x,220,21,43);
            x=x+30;
        }
        else if(cadena>=493.8 && cadena<523.2)
        {
            blit(notas,buffer,0,0,x,210,21,43);
            x=x+30;
        }
        else if(cadena>=523.2)
        {
            blit(notas,buffer,0,0,x,200,21,43);
            x=x+30;
        } */
        blit(buffer, screen, 0, 0, 0, 0, 1000, 530);
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
            }
            fe.close();

    }

        }
    return 0;
}
END_OF_MAIN ()
