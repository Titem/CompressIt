/**
 * @file messages_de.h
 *
 * Dieses Modul enthält alle Text-Meldungen in deutscher Sprache, die von der
 * Anwendung CompressIt auf dem Bildschirm ausgegeben werden.
 *
 * @author Tim Buschmann <br>
 *         Artur Leinweber <br>
 *         Alexander Schmitz
 */

#ifndef MESSAGES_DE_H
#define	MESSAGES_DE_H




/* ======================================================================== *
 * Makros                                                                   *
 * ======================================================================== */

#define MSG_CANT_ALLOCATE_MEMORY \
        "Es konnte kein Speicher allociert werden!"

#define MSG_NO_INPUT_FILENAME \
        "Es wurde keine Quell-Datei angegeben! \n" \
        "fuer Hilfe: huffman.exe -h"

#define MSG_TO_FEW_ARGUMENTS \
        "Es wurden notwendige Parameter nicht angegeben! \n" \
        "fuer Hilfe: huffman.exe -h"

#define MSG_WRONG_ARGUMENTS \
        "Es wurden ungueltige Parameter angegeben! \n" \
        "fuer Hilfe: huffman.exe -h"

#define MSG_FILENAMES_ARE_EQUAL \
        "Der Dateiname der Ziel-Datei ist gleich dem Dateinamen \n" \
        "der Quell-Datei!"

#define MSG_CANT_OPEN_INPUT_FILE(X, Y, Z) \
        "Die Quell-Datei " X " konnte nicht geoeffnet werden! \n" \
        "Fehlernummer: " Y " \n" \
        "Beschreibung: " Z

#define MSG_CANT_OPEN_OUTPUT_FILE(X, Y, Z) \
        "Die Ziel-Datei " X " konnte nicht erstellt werden! \n" \
        "Fehlernummer: " Y " \n" \
        "Beschreibung: " Z

#define MSG_UNKNOWN_ERROR \
        "Ein unbekannter Fehler ist aufgetreten!"

#define MSG_INVALID_FILE_CONTENT_INVALID(X, Y) \
        "Bei der Quell-Datei " X " handelt es sich entweder um keine \n" \
        "gueltige Datei, die mit dieser Anwendung komprimiert wurde, \n" \
        "oder die Datei ist beschaedigt! \n\n" \
        "Beim Dekomprimieren ist aufgefallen, dass der Inhalt der \n" \
        "Quell-Datei " Y " eine ungueltige Codierung enthaelt!"

#define MSG_INVALID_FILE_CONTENT_TO_SHORT(X, Y) \
        "Bei der Quell-Datei " X " handelt es sich entweder um keine \n" \
        "gueltige Datei, die mit dieser Anwendung komprimiert wurde, \n" \
        "oder die Datei ist beschaedigt! \n\n" \
        "Beim Dekomprimieren ist aufgefallen, dass der Inhalt der \n" \
        "Quell-Datei " Y " unvollstaendig ist!"

#define MSG_INVALID_FILE_CONTENT_TO_LONG(X, Y) \
        "Bei der Quell-Datei " X " handelt es sich entweder um keine \n" \
        "gueltige Datei, die mit dieser Anwendung komprimiert wurde, \n" \
        "oder die Datei ist beschaedigt! \n\n" \
        "Beim Dekomprimieren ist aufgefallen, dass der Inhalt der \n" \
        "Quell-Datei " Y " laenger ist als erwartet!"

#define MSG_INVALID_FILE_CODETAB_INVALID(X, Y) \
        "Bei der Quell-Datei " X " handelt es sich entweder um keine \n" \
        "gueltige Datei, die mit dieser Anwendung komprimiert wurde, \n" \
        "oder die Datei ist beschaedigt! \n\n" \
        "Beim Dekomprimieren ist aufgefallen, dass die Code-Tabelle der \n" \
        "Quell-Datei " Y " einen ungueltigen Eintrag enthaelt!"

#define MSG_INVALID_FILE_CODETAB_TO_SHORT(X, Y) \
        "Bei der Quell-Datei " X " handelt es sich entweder um keine \n" \
        "gueltige Datei, die mit dieser Anwendung komprimiert wurde, \n" \
        "oder die Datei ist beschaedigt! \n\n" \
        "Beim Dekomprimieren ist aufgefallen, dass die Code-Tabelle der \n" \
        "Quell-Datei " Y " unvollstaendig ist!"

#define MSG_INVALID_FILE_CONTENTLENGTH_UNREADABLE(X, Y) \
        "Bei der Quell-Datei " X " handelt es sich entweder um keine \n" \
        "gueltige Datei, die mit dieser Anwendung komprimiert wurde, \n" \
        "oder die Datei ist beschaedigt! \n\n" \
        "Beim Dekomprimieren ist aufgefallen, dass die Laenge des Inhalts \n" \
        "nicht aus der Quell-Datei " Y " gelesen werden konnte!"

#define MSG_INVALID_FILE_CODETABLENGTH_UNREADABLE(X, Y) \
        "Bei der Quell-Datei " X " handelt es sich entweder um keine \n" \
        "gueltige Datei, die mit dieser Anwendung komprimiert wurde, \n" \
        "oder die Datei ist beschaedigt! \n\n" \
        "Beim Dekomprimieren ist aufgefallen, dass die Laenge der \n" \
        "Code-Tabelle nicht aus der Quell-Datei " Y " gelesen werden konnte!"

#define MSG_CANT_WRITE_CONTENTLENGTH \
        "Ein unbekannter Fehler ist aufgetreten, der verhindert, dass die \n" \
        "Laenge des Inhaltes in der Ziel-Datei gespeichert werden kann!"

#define MSG_CANT_WRITE_CODETABLENGTH \
        "Ein unbekannter Fehler ist aufgetreten, der verhindert, dass die \n" \
        "Laenge der Code-Tabelle in der Ziel-Datei gespeichert werden kann!"

#define MSG_MANPAGE \
        "Usage: \n" \
        "\t Compress:    " \
        " huffman.exe -c <in_file> [<out_file> (default: <in_file>.hc)] \n" \
        "\t Decompress:  " \
        " huffman.exe -d <in_file> [<out_file> (default: <in_file>.hd)] \n" \
        "\t Help:        " \
        " huffman.exe -h \n\n" 

#endif	/* MESSAGES_DE_H */

