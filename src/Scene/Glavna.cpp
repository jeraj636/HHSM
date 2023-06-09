#include "Glavna.h"
#include "../HenigmaEngine/src/Render/Render.h"
#include "../HenigmaEngine/src/ostalo/ostalo.h"
#include <iostream>
#include <fstream>
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

    terminal.vel = vec3(rend->okno.dolzina - levMeni.vel.x - seperator.vel.x, rend->okno.visina * 20 / 100, 0);
    terminal.poz = vec3(terminal.vel.x / 2 + levMeni.vel.x + seperator.vel.x, rend->okno.visina - terminal.vel.y / 2, 0);
    terminal.Narisi();

    terminalTopBar.vel = vec3(terminal.vel.x, 32, 0);
    terminalTopBar.poz = vec3(terminal.poz.x, rend->okno.visina - terminal.vel.y + terminalTopBar.vel.y / 2, 0);
    terminalTopBar.Narisi();
}
void Glavna::Zacetek(Render *Ren)
{

    rend = Ren;
    belaTek = rend->NaloziTeksturo("Materiali/Slike/Bela.png");

    rend->Odzadje = Barva(0x333333ff);

    topBar.Init(rend);

    topBar.rot = 0;
    topBar.tek = belaTek;

    levMeni.Init(rend);
    levMeni.tek = belaTek;

    levTopBar.Init(rend);
    levTopBar.tek = belaTek;

    seperator.Init(rend);
    seperator.tek = belaTek;

    terminal.Init(rend);
    terminal.tek = belaTek;

    terminalTopBar.Init(rend);

    /*
        levMeni.Bobj = Barva(0x707070ff);
        levTopBar.Bobj = Barva(0xa9a9a9ff);
        seperator.Bobj = Barva(0x222222ff);
        terminal.Bobj = Barva(0xffffffff);
        terminalTopBar.Bobj = levTopBar.Bobj;
        topBar.Bobj = Barva(0x707070ff);
        */

    PreberiKonfiguracijo();
}
void Glavna::PreberiKonfiguracijo()
{
    std::ifstream konfiguracija;
    konfiguracija.open("../Datoteke/hhsm.conf");
    if (!konfiguracija)
        io::err("NE NAJDEM KONFIGURACIJSKE DATOTEKE");
    io::msg("KONFIGURACIJA ODPRTA");

    std::string vrstica;
    bool barvaOdzadja = 0;

    while (std::getline(konfiguracija, vrstica))
    {
        std::string pomozna;
        std::string vrednost;
        if (vrstica[0] == '[')
        {
            int i = 1;
            for (; vrstica[i] != ']' && i < vrstica.size(); i++)
            {
                pomozna.push_back(vrstica[i]);
            }
            if (pomozna == "colors")
                barvaOdzadja = 1;
        }
        if (vrstica[0] == '#' || vrstica[0] == '[' || vrstica[0] == '\0' || vrstica[0] == ' ')
            continue;

        int i = 0;
        for (; vrstica[i] != '=' && i < vrstica.size(); i++)
            pomozna.push_back(vrstica[i]);
        for (; vrstica[i] != '\'' && i < vrstica.size(); i++)
            ;

        for (i++; vrstica[i] != '\'' && i < vrstica.size(); i++)
            vrednost.push_back(vrstica[i]);
        if (barvaOdzadja)
        {
            if (pomozna == "topBar")
            {
                topBar.Bobj = Barva(vrednost);
                // std::cout << vrednost << "\n";
            }
            else if (pomozna == "leftMenu")
            {
                levMeni.Bobj = Barva(vrednost);
                // std::cout << vrednost << "\n";
            }
            else if (pomozna == "leftMenuTopBar")
            {
                levTopBar.Bobj = Barva(vrednost);
                // std::cout << vrednost << "\n";
            }
            else if (pomozna == "seperator")
            {
                seperator.Bobj = Barva(vrednost);
                // std::cout << vrednost << "\n";
            }
            else if (pomozna == "terminal")
            {
                terminal.Bobj = Barva(vrednost);
                // std::cout << vrednost << "\n";
            }
            else if (pomozna == "terminalTopBar")
            {
                terminalTopBar.Bobj = Barva(vrednost);
                // std::cout << vrednost << "\n";
            }
        }
    }
}