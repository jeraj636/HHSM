#include "Objekt.h"
#include "../../HenigmaEngine/src/Render/Render.h"
#include <iostream>
void Objekt::Narisi()
{
    ren->Narisi(tek, poz, rot, vel, Bobj, Bozd);
}
Objekt::Objekt()
    : Bobj(0xffffffff), Bozd(0xffffffff)
{
    vel = 0;
    rot = 0;
    poz = 0;
    nastavekZaVel = 0;
}
void Objekt::Init(Render *t_ren)
{
    ren = t_ren;
}
bool Objekt::AliSemOznacen()
{
    spl::vec2 A(poz.x - vel.x / 2, poz.y - vel.y / 2);
    spl::vec2 C(poz.x + vel.x / 2, poz.y + vel.y / 2);
    spl::vec2 kaz(ren->kazalec.x, ren->kazalec.y);

    if (kaz.x > A.x && kaz.x < C.x && kaz.y > A.y && kaz.y < C.y)
    {
        Bobj.a = 0.5f;
        return true;
    }
    Bobj.a = 1;
    return false;
}
bool Objekt::AliSemKliknjen()
{
    bool a = AliSemOznacen();
    // if (ren->aktivenGumb == Gumb::leviKlik && a)
    // return 1;
    return 0;
}
