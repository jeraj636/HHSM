#pragma once
#include "../HenigmaEngine/src/Scena/Scena.h"
#include <stdint.h>
#include "../HenigmaEngine/src/Matematika/Matematika.h"
#include "../HenigmaEngine/src/ostalo/ostalo.h"
#include "Objekt/Objekt.h"
#include <string>
#include "../HenigmaEngine/src/Render/Render.h"
enum class TerminalStvari
{
    terminal,
    debug,
    error
};
class Glavna : public Scena
{
public:
    void Konec() override;
    void Zanka() override;
    void Zacetek(Render *Ren) override;
    Glavna() = default;

private:
    void PreberiKonfiguracijo();
    Objekt topBar;
    Objekt levMeni;
    Objekt levTopBar;
    Objekt seperator;
    Objekt terminal;
    Objekt terminalTopBar;
    Objekt imeDatotekeBar;

    Objekt ikonaTerminalTerminal;
    TerminalStvari aktivnaStvarVTerminalu = TerminalStvari::terminal;

    uint32_t belaTek;
    Font font;
    int fontVelikost;
    std::string potDoFonta;

private:
    void Terminal();
    void Initer();
};