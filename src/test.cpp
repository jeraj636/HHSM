#include <iostream>
#include "Render/Render.h"
#include "Scena/Scena.h"
#include "Scena/TestScena.h"
#include "Matematika/Matematika.h"
#include "Scene/Glavna.h"
#include "ostalo/ostalo.h"
int main()
{
    Render rend;
    rend.Init("HHSM");

    Glavna glavna;
    rend.DodajSceno(glavna.Naslov(), "Glavna");
    rend.AktivirajSceno("Glavna");
    while (!rend.AliSeMoramZapreti())
    {
        rend.OkvirZac();
        rend.Zanka();

        rend.OkvirKon();
    }
}