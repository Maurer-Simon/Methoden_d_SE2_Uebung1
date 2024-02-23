#ifndef CHARACTER_H
#define CHARACTER_H

#include "item.h"

// Character_t: Repräsentiert andere Charaktere mit Namen, Lebenspunkten, Gold und einem Inventar aus Gegenständen (maximal 10).
struct Character_t
{
	std::string name; // Der Name des Charakters
	int health; // Die Lebenspunkte des Charakters
	int gold; // Der Goldbetrag des Charakters
	Item_t items[10]; // Das Inventar des Charakters (maximal 10 Gegenstände)
};

// Initialisiert einen Charakter mit dem angegebenen Namen, Lebenspunkten und Goldbetrag.
void initCharacter(Character_t* character, std::string name, int health, int gold);

// Der Charakter greift die spezifizierte Heldin an und fügt ihr Schaden zu.
void attack(Character_t* enemy, Hero_t* hero);

#endif // CHARACTER_H