#include <iostream>
#include "Render/Render.h"
#include "Scena/Scena.h"
#include "Scena/TestScena.h"
#include "Matematika/Matematika.h"
#include "Scene/Zacetna.h"
#include "ostalo/ostalo.h"
int main()
{
    Render rend;
    rend.Init("HenigmaEngine");

    // TestScena test;
    // rend.DodajSceno(test.Naslov(), "test");
    // rend.AktivirajSceno("test");

    Zacetna zacetna;
    rend.DodajSceno(zacetna.Naslov(), "zacetna");
    rend.AktivirajSceno("zacetna");
    while (!rend.AliSeMoramZapreti())
    {
        rend.OkvirZac();
        rend.Zanka();

        rend.OkvirKon();
    }
}