#ifndef HERO_H
#define HERO_H

#include <string>
#include "item.h"
#include "character.h"

// Hero_t: Repräsentiert die Heldin und enthält ihren Namen, ihre Lebenspunkte, ihr Gold sowie Inventar- und Ausrüstungsgegenstände.
struct Hero_t
{
	std::string name; // Der Name der Heldin
	int health; // Die Lebenspunkte der Heldin
	int gold; // Der Goldbetrag der Heldin
	Item_t items[10]; // Das Inventar der Heldin (maximal 10 Gegenstände)
	Item_t equip[10]; // Die Ausrüstung der Heldin (maximal 2 Gegenstände)
};

// Initialisiert eine Heldin mit dem übergebenen Namen, Lebenspunkten und Goldbetrag.
void initHero(Hero_t*, std::string, int, int);

// Die Heldin greift einen spezifizierten Gegner an.
void attack(Hero_t* hero, Character_t* enemy);

// Eine Überladung von attack(), die es einem Gegner ermöglicht, die Heldin anzugreifen.
void attack(Character_t* enemy, Hero_t* hero);

#endif // HERO_H