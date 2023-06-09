#pragma once
#include "../HenigmaEngine/src/Scena/Scena.h"
#include <stdint.h>
#include "../HenigmaEngine/src/Matematika/Matematika.h"
#include "../HenigmaEngine/src/ostalo/ostalo.h"
#include "Objekt/Objekt.h"

class Glavna : public Scena
{
public:
    void Konec() override;
    void Zanka() override;
    void Zacetek(Render *Ren) override;
    Glavna() = default;

private:
    Objekt topBar;
    Objekt levMeni;
    Objekt levTopBar;
    Objekt seperator;
    Objekt terminal;
    // Objekt terminalTopBar;
    uint32_t belaTek;
};