#include <random>
#include <iostream>
#include "character.h"
#include "hero.h"

// Diese Funktion initialisiert einen Charakter mit dem übergebenen Namen, Lebenspunkten und Goldbetrag.
// Zudem wird das Attribut isValid für alle Inventargegenstände auf false gesetzt.
void initCharacter(Character_t* character, std::string name, int health, int gold)
{
	character->name = name; // Setze den Namen des Charakters
	character->health = health; // Setze die Lebenspunkte des Charakters
	character->gold = gold; // Setze den Goldbetrag des Charakters

	// Setze isValid für alle Inventargegenstände auf false, um sie als ungültig zu markieren
	for (auto & item : character->items)
	{
		item.isValid = false;
	}
}

// Der Charakter greift die spezifizierte Heldin an und fügt ihr einen zufälligen Schaden zwischen 5 und 15 Lebenspunkten zu.
void attack(Character_t* enemy, Hero_t* hero)
{
	std::random_device rd; // Erzeuge ein Random-Seed-Objekt
	std::mt19937 gen(rd()); // Initialisiere den Mersenne Twister Zufallszahlengenerator mit dem Seed

	// Definiere den Bereich für den Schaden
	std::uniform_int_distribution<> dis(5, 15);

	// Generiere eine zufällige Schadenszahl im definierten Bereich
	int damage = dis(gen);

	// Verringere die Lebenspunkte der Heldin um den erzeugten Schaden
	hero->health -= damage;

	// Gib aus, dass der Charakter die Heldin getroffen hat und wie viel Schaden verursacht wurde
	std::cout << enemy->name << " trifft " << hero->name << " fuer " << damage << " Lebenspunkte! " << std::endl;
}