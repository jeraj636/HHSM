#include "Objekt.h"
#include "../../HenigmaEngine/src/Render/Render.h"
void Objekt::Narisi()
{
    ren->Narisi(tek, poz, rot, vel, Bobj, Bozd);
}
Objekt::Objekt()
    : Bobj(0xffffffff), Bozd(0xffffffff)
{
}
void Objekt::Init(Render *t_ren)
{
    ren = t_ren;
}