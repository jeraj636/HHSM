#include "../../HenigmaEngine/src/Matematika/Matematika.h"
#include <stdint.h>
#include "../../HenigmaEngine/src/ostalo/ostalo.h"
class Render;
class Objekt
{
public:
    spl::vec3 vel;
    float rot;
    spl::vec3 poz;
    Barva Bobj;
    Barva Bozd;
    uint32_t tek;
    void Narisi();
    void Init(Render *t_ren);
    Objekt();

private:
    Render *ren;
};