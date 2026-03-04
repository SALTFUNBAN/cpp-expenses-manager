# Expenses Manager (C++17)

Konsolenanwendung zur Verwaltung monatlicher Ausgaben.

## Funktionen

- Ausgaben hinzufügen
- Löschen nach ID
- Filter nach Kategorie
- Monatliche Gesamtsumme
- Speicherung in Textdatei
- Automatisches Laden beim Start

## Technologien

- C++17
- STL
- CMake
- Dateiverarbeitung (fstream)

## Build

```bash
mkdir build
cd build
cmake ..
cmake --build .

## Dateiformat

id|title|category|date|price|amount

## Weiterentwicklung (geplant)

Statistiken pro Kategorie
Validierung des Datumsformats
Verbesserte Benutzeroberfläche