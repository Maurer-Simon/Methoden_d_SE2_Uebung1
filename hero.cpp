#include <random>
#include <iostream>
#include "hero.h"

// Diese Funktion initialisiert die Heldin mit dem übergebenen Namen, Lebenspunkten und Goldbetrag.
// Zudem wird das Attribut isValid für alle Inventar- und Ausrüstungsgegenstände auf false gesetzt.
void initHero(Hero_t* hero, std::string name, int health, int gold)
{
	hero->name = name; // Setze den Namen der Heldin
	hero->health = health; // Setze die Lebenspunkte der Heldin
	hero->gold = gold; // Setze den Goldbetrag der Heldin

	// Setze isValid für alle Inventargegenstände auf false
	for (auto & item : hero->items)
	{
		item.isValid = false;
	}

	// Setze isValid für alle Ausrüstungsgegenstände auf false
	for (auto & equip : hero->equip)
	{
		equip.isValid = false;
	}
}

// Die Heldin greift einen spezifizierten Gegner an und fügt diesem einen zufälligen Schaden zwischen 15 und 25 Lebenspunkten zu.
void attack(Hero_t* hero, Character_t* enemy)
{
	std::random_device rd; // Erzeuge ein Random-Seed-Objekt
	std::mt19937 gen(rd()); // Initialisiere den Mersenne Twister Zufallszahlengenerator mit dem Seed

	// Definiere den Bereich für den Schaden
	std::uniform_int_distribution<> dis(15, 25);

	// Generiere eine zufällige Schadenszahl im definierten Bereich
	int damage = dis(gen);

	// Verringere die Lebenspunkte des Gegners um den erzeugten Schaden
	enemy->health -= damage;

	// Gib aus, dass die Heldin den Gegner getroffen hat und wie viel Schaden verursacht wurde
	std::cout << hero->name << " trifft " << enemy->name << " fuer " << damage << " Lebenspunkte! " << std::endl;
}