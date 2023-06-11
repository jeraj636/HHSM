#include "Glavna.h"

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
    topBar.vel = vec3(rend->okno.dolzina, topBar.nastavekZaVel.y, 0);
    topBar.Narisi();

    levMeni.vel = vec3(rend->okno.dolzina * levMeni.nastavekZaVel.x / 100, rend->okno.visina - topBar.vel.y, 0);
    levMeni.poz = vec3(levMeni.vel.x / 2, topBar.vel.y + levMeni.vel.y / 2, 0);
    levMeni.Narisi();

    levTopBar.vel = vec3(levMeni.vel.x, levTopBar.nastavekZaVel.y, 0);
    levTopBar.poz = vec3(levMeni.poz.x, levTopBar.vel.y / 2 + topBar.vel.y, 0);
    levTopBar.Narisi();

    seperator.vel = vec3(rend->okno.dolzina * seperator.nastavekZaVel.x / 100, levMeni.vel.y, 0);
    seperator.poz = vec3(levMeni.vel.x + seperator.vel.x / 2, levMeni.poz.y, 0);
    seperator.Narisi();

    terminal.vel = vec3(rend->okno.dolzina - levMeni.vel.x - seperator.vel.x, rend->okno.visina * terminal.nastavekZaVel.y / 100, 0);
    terminal.poz = vec3(terminal.vel.x / 2 + levMeni.vel.x + seperator.vel.x, rend->okno.visina - terminal.vel.y / 2, 0);
    terminal.Narisi();

    terminalTopBar.vel = vec3(terminal.vel.x, terminalTopBar.nastavekZaVel.y, 0);
    terminalTopBar.poz = vec3(terminal.poz.x, rend->okno.visina - terminal.vel.y + terminalTopBar.vel.y / 2, 0);
    terminalTopBar.Narisi();

    imeDatotekeBar.vel = vec3(terminal.vel.x, levTopBar.vel.y, 0);
    imeDatotekeBar.poz = vec3(terminalTopBar.poz.x, levTopBar.poz.y, 0);
    imeDatotekeBar.Narisi();

    ikonaTerminalTerminal.vel = terminalTopBar.vel.y;
    ikonaTerminalTerminal.poz = vec3(terminalTopBar.poz.x - terminalTopBar.vel.x / 2 + ikonaTerminalTerminal.vel.x / 2, terminalTopBar.poz.y, 0);
    if (ikonaTerminalTerminal.AliSemKliknjen())
    {
        io::msg("klik");
        aktivnaStvarVTerminalu = TerminalStvari::terminal;
    }
    ikonaTerminalTerminal.Narisi();
    if (aktivnaStvarVTerminalu == TerminalStvari::terminal)
    {
        Terminal();
    }

    rend->NarisiNiz("Pozdravlje svet!", font, vec3(rend->okno.dolzina / 2, rend->okno.visina / 2, 0), 0, vec3(16, 16, 0), Barva(0xffffffff), Barva(0x00000000));
    // std::cout << rend->trenutenZnak << std::endl;
}
void Glavna::Zacetek(Render *Ren)
{

    rend = Ren;
    belaTek = rend->NaloziTeksturo("Materiali/Slike/Bela.png");
    Initer();

    PreberiKonfiguracijo();
    font.NaloziFont(potDoFonta, fontVelikost);
}

void Glavna::Initer()
{
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
    terminalTopBar.tek = belaTek;

    imeDatotekeBar.Init(rend);
    imeDatotekeBar.tek = belaTek;

    ikonaTerminalTerminal.Init(rend);
    ikonaTerminalTerminal.tek = rend->NaloziTeksturo("Materiali/Slike/code-alt-regular-72.png");
}
enum class KonfiguracijskiTipi
{
    colors,
    sizes,
    iconColors,
    font
};
void Glavna::PreberiKonfiguracijo()
{
    std::ifstream konfiguracija;
    konfiguracija.open("../Datoteke/hhsm.conf");
    if (!konfiguracija)
        io::err("NE NAJDEM KONFIGURACIJSKE DATOTEKE");
    io::msg("KONFIGURACIJA ODPRTA");

    std::string vrstica;
    // bool barvaOdzadja = 0;
    KonfiguracijskiTipi aktivenTip;
    while (std::getline(konfiguracija, vrstica))
    {
        std::string pomozna;
        std::string vrednost;
        if (vrstica[0] == '[')
        {

            if (vrstica == "[colors]")
                aktivenTip = KonfiguracijskiTipi::colors;
            else if (vrstica == "[sizes]")
                aktivenTip = KonfiguracijskiTipi::sizes;
            else if (vrstica == "[iconColors]")
                aktivenTip = KonfiguracijskiTipi::iconColors;
            else if (vrstica == "[font]")
                aktivenTip = KonfiguracijskiTipi::font;
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
        if (aktivenTip == KonfiguracijskiTipi::colors)
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
            else if (pomozna == "fileNameBar")
            {
                imeDatotekeBar.Bobj = Barva(vrednost);
            }
            else if (pomozna == "code")
            {
                rend->Odzadje = Barva(0x333333ff);
            }
        }
        else if (aktivenTip == KonfiguracijskiTipi::sizes)
        {
            if (pomozna == "topBar")
            {
                topBar.nastavekZaVel.y = atof(vrednost.c_str());
            }
            else if (pomozna == "leftMenuTopBar")
            {
                levTopBar.nastavekZaVel.y = atof(vrednost.c_str());
            }
            else if (pomozna == "terminalTopBar")
            {
                terminalTopBar.nastavekZaVel.y = atof(vrednost.c_str());
            }
            else if (pomozna == "seperator")
            {
                seperator.nastavekZaVel.x = atof(vrednost.c_str());
            }
            else if (pomozna == "levMeni")
            {
                levMeni.nastavekZaVel.x = atof(vrednost.c_str());
            }
            else if (pomozna == "terminal")
            {
                terminal.nastavekZaVel.y = atof(vrednost.c_str());
            }
        }
        else if (aktivenTip == KonfiguracijskiTipi::iconColors)
        {
            if (pomozna == "terminalTerminal")
                ikonaTerminalTerminal.Bobj = Barva(vrednost);
            ikonaTerminalTerminal.Bozd = Barva(0x00000000);
        }
        else if (aktivenTip == KonfiguracijskiTipi::font)
        {
            if (pomozna == "size")
            {
                fontVelikost = atoi(vrednost.c_str());
            }
            else if (pomozna == "path")
            {
                potDoFonta = vrednost;
            }
        }
    }
}
void Glavna::Terminal()
{
    //! tukaj sem ostal trenutno
    //! raziskujem kako nareditit terminale emulator
    //*nadaljuja
}