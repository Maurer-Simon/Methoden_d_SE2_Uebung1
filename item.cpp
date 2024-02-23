#include <iostream>
#include "item.h"
#include "hero.h"

// Diese Funktion initialisiert einen Gegenstand mit dem übergebenen Namen und Wert und setzt isValid auf true.
void initItem(Item_t* ITEM, std::string name, int gold)
{
	ITEM->name = name; // Setze den Namen des Gegenstands
	ITEM->worth = gold; // Setze den Wert des Gegenstands
	ITEM->isValid = true; // Setze isValid auf true, um den Gegenstand als gültig zu markieren
}

// Diese Funktion setzt das Attribut isValid des übergebenen Gegenstands auf false.
void initItem(Item_t* item)
{
	item->isValid = false; // Setze isValid auf false, um den Gegenstand als ungültig zu markieren
}

// Verkauft einen Gegenstand an der spezifizierten Indexposition im Inventar der Heldin und erhöht ihr Gold um den Wert des Gegenstands.
void sellItem(Hero_t* hero, int index)
{
	// Überprüfe, ob der Index innerhalb des gültigen Bereichs liegt und ob sich an dieser Stelle ein gültiger Gegenstand befindet
	if (index >= 0 && index < 10 && hero->items[index].isValid) {
		// Füge den Wert des Gegenstands zum Gold der Heldin hinzu
		hero->gold += hero->items[index].worth;

		// Markiere den Gegenstand als ungültig, um ihn aus dem Inventar zu entfernen
		hero->items[index].isValid = false;

		// Initialisiere den Gegenstand erneut, um ihn zurückzusetzen
		initItem(&hero->items[index]);

		// Gib eine Nachricht aus, dass der Gegenstand verkauft wurde und wie viel Gold die Heldin nun besitzt
		std::cout << "Gegenstand " << hero->items[index].name << " wurde verkauft. " << hero->name << " besitzt nun "
				  << hero->gold << " Gold."<< std::endl;
	}
}