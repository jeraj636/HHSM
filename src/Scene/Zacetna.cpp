#include "Zacetna.h"
#include "../HenigmaEngine/src/Render/Render.h"
void Zacetna::Konec()
{
}
void Zacetna::Zanka()
{
}
void Zacetna::Zacetek(Render *Ren)
{
    rend = Ren;
    tek = rend->NaloziTeksturo("Materiali/Slike/logo260.png");
};
