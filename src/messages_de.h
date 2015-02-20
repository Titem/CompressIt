/**
 * @file messages_de.h
 * 
 * Dieses Modul enthält alle Text-Meldungen in deutscher Sprache, die von der
 * Anwendung CompressIt auf dem Bildschirm ausgegeben werden.
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz 
 */

#ifndef MESSAGES_DE_H
#define	MESSAGES_DE_H




/* ======================================================================== *
 * Symbolische-Konstanten                                                                   *
 * ======================================================================== */

#define MSG_CANT_ALLOCATE_MEMORY \
        Es konnte kein Speicher allociert werden! 

#define MSG_NO_INPUT_FILENAME \
        Es wurde keine Quell-Datei angegeben! \
        fuer Hilfe: huffman.exe -h

#define MSG_TO_FEW_ARGUMENTS \
        Es wurden notwendige Parameter nicht angegeben! \
        fuer Hilfe: huffman.exe -h
        
#define MSG_WRONG_ARGUMENTS \
        Es wurden ungueltige Parameter angegeben! \
        fuer Hilfe: huffman.exe -h

#define MSG_FILENAMES_ARE_EQUAL \
        Der Dateiname der Ziel-Datei ist gleich dem Dateinamen der Quell-Datei!

#define MSG_CANT_OPEN_INPUT_FILE(X, Y, Z) \
        Die Quell-Datei X konnte nicht geoeffnet werden!\n \
        Fehlernummer: Y \n \
        Beschreibung: Z
                
#define MSG_CANT_OPEN_OUTPUT_FILE(X, Y, Z) \
        Die Ziel-Datei X konnte nicht erstellt werden!\n \
        Fehlernummer: Y \n \
        Beschreibung: Z

#define MSG_UNKNOWN_ERROR \
        Ein unbekannter Fehler ist aufgetreten! 

        
#endif	/* MESSAGES_DE_H */

