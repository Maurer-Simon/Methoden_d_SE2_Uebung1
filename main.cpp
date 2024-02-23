#include <iostream>
#include "character.h"
#include "hero.h"

#define cout std::cout
#define endl std::endl

// Simuliert einen Kampf zwischen der Heldin und einem Feind, der aus mehreren Runden besteht.
// In jeder Runde wird abwechselnd die attack()-Funktion der Heldin und des Feindes aufgerufen,
// bis eine der beiden Parteien keine Lebenspunkte mehr hat.
// Gibt true zurück, wenn die Heldin gewinnt, sonst false.
bool fight(Hero_t* hero, Character_t* enemy)
{
	while (hero->health > 0 && enemy->health > 0) {
		attack(hero, enemy);
		if (enemy->health <= 0) {
			// Ausgabe, wenn der Feind besiegt wurde
			cout << enemy->name << " wurde besiegt! " << hero->name << " hat noch " << hero->health
				 << " Lebenspunkte uebrig!" << endl;
			return true;
		}

		attack(enemy, hero);
		if (hero->health <= 0) {
			// Ausgabe, wenn die Heldin besiegt wurde
			cout << hero->name << " wurde besiegt! " << enemy->name << " hat noch " << enemy->health
				 << " Lebenspunkte uebrig!" << endl;
			return false;
		}
	}
	return false;
}


int main() {
	// Deklaration der Variablen für die Heldin und zwei Angreifer
	Hero_t Heldin;
	Character_t Angreifer1, Angreifer2;

	// Initialisierung der Charaktere mit Namen, Lebenspunkten und Angriffswerten
	initHero(&Heldin, "Annina", 100, 10);
	initCharacter(&Angreifer1, "Matthias", 100, 5);
	initCharacter(&Angreifer2, "Pascal", 100, 5);

	// Kampf zwischen der Heldin und Angreifer1
	if (fight(&Heldin, &Angreifer1))
	{
		// Wenn die Heldin gewinnt, wird ein Gegenstand zum Inventar hinzugefügt
		initItem(&Heldin.items[0], "Zaubertrank", 25);
		cout << "Gegenstand " << Heldin.items[0].name << " wurde zum Inventar der Heldin hinzugefuegt." << endl;
	}

	// Kampf zwischen der Heldin und Angreifer2
	if (fight(&Heldin, &Angreifer2))
	{
		// Wenn die Heldin gewinnt, wird ein Gegenstand zum Inventar hinzugefügt
		initItem(&Heldin.items[1], "Axt", 35);
		cout << "Gegenstand " << Heldin.items[0].name << " wurde zum Inventar der Heldin hinzugefuegt." << endl;
	}

	// Verkaufe alle gültigen Gegenstände im Inventar der Heldin
	for (int i = 0; i < sizeof(Heldin.items)/sizeof(*Heldin.items); i++)
	{
		if (Heldin.items[i].isValid)
		{
			sellItem(&Heldin, i);
		}
	}
	return 0;
}