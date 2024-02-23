#ifndef ITEM_H
#define ITEM_H

#include <string>

// Item_t: Repräsentiert einen Gegenstand mit Bezeichnung, Wert und einem Flag, das angibt, ob der Gegenstand gültig ist.
struct Item_t
{
	std::string name; // Bezeichnung des Gegenstands
	int worth; // Wert des Gegenstands
	bool isValid; // Flag, das angibt, ob der Gegenstand gültig ist
};

struct Hero_t; // Vorwärtsdeklaration der Struktur Hero_t

// Initialisiert einen Gegenstand mit dem angegebenen Namen und Wert und setzt isValid auf true.
void initItem(Item_t* ITEM, std::string, int gold);

// Setzt das Attribut isValid des übergebenen Gegenstands auf false.
void initItem(Item_t* gegenstand);

// Verkauft den Gegenstand an der angegebenen Indexposition im Inventar des Helden und erhöht sein Gold um den Wert des Gegenstands.
void sellItem(Hero_t* hero, int index);

#endif // ITEM_H