#include "Glavna.h"
#include "../HenigmaEngine/src/Render/Render.h"
#include "../HenigmaEngine/src/ostalo/ostalo.h"
#include <iostream>
using namespace spl;
void Glavna::Konec()
{
}
void Glavna::Zanka()
{
    topBar.poz = vec3(rend->okno.dolzina / 2, 16, 0);
    topBar.vel = vec3(rend->okno.dolzina, 32, 0);
    topBar.Narisi();

    levMeni.vel = vec3(rend->okno.dolzina * 15 / 100, rend->okno.visina - topBar.vel.y, 0);
    levMeni.poz = vec3(levMeni.vel.x / 2, topBar.vel.y + levMeni.vel.y / 2, 0);
    levMeni.Narisi();

    levTopBar.vel = vec3(levMeni.vel.x, topBar.vel.y, 0);
    levTopBar.poz = vec3(levMeni.poz.x, levTopBar.vel.y / 2 + topBar.vel.y, 0);
    levTopBar.Narisi();

    seperator.vel = vec3(rend->okno.dolzina * 1 / 100, levMeni.vel.y, 0);
    seperator.poz = vec3(levMeni.vel.x + seperator.vel.x / 2, levMeni.poz.y, 0);
    seperator.Narisi();

    terminal.vel = vec3(rend->okno.dolzina - levMeni.vel.x - seperator.vel.x, rend->okno.visina * 10 / 100, 0);
    terminal.poz = vec3(terminal.vel.x / 2 + levMeni.vel.x + seperator.vel.x, rend->okno.visina - terminal.vel.y / 2, 0);
    terminal.Narisi();

    // terminalTopBar.Narisi();
}
void Glavna::Zacetek(Render *Ren)
{
    rend = Ren;
    belaTek = rend->NaloziTeksturo("Materiali/Slike/Bela.png");

    rend->Odzadje = Barva(0x333333ff);

    topBar.Init(rend);

    topBar.rot = 0;
    topBar.Bobj = Barva(0x707070ff);
    topBar.tek = belaTek;

    levMeni.Init(rend);
    levMeni.Bobj = Barva(0x707070ff);
    levMeni.tek = belaTek;

    levTopBar.Init(rend);
    levTopBar.Bobj = Barva(0xa9a9a9ff);
    levTopBar.tek = belaTek;

    seperator.Init(rend);
    seperator.Bobj = Barva(0x222222ff);
    seperator.tek = belaTek;

    terminal.Init(rend);
    terminal.Bobj = Barva(0xffffffff);
    terminal.tek = belaTek;

    terminalTopBar.Init(rend);
    terminalTopBar.Bobj = levTopBar.Bobj;
}
