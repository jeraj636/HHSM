#pragma once
#include "../HenigmaEngine/src/Scena/Scena.h"
#include <stdint.h>
class Zacetna : public Scena
{
public:
    void Konec() override;
    void Zanka() override;
    void Zacetek(Render *Ren) override;

private:
    uint32_t tek;
};