# Environment
OBJPATH = build
EXEPATH = dist
EXE = huffman.exe

# Compiler-Optionen
GCC_OPTION = -c -g -DDEBUG -std=c89 -Wall -pedantic-errors

# Konfiguration fuer Doxygen
DOXYGEN_PATH = doxygen
DOXYGEN_FILE = $(DOXYGEN_PATH)/html/index.html
DOXYGEN_CFG = res/ppr_doxygen.cfg

# Konfiguration fuer Splint
SPLINT_LOG = ./splint.log

OBJS = $(OBJPATH)/error.o $(OBJPATH)/codetab_element.o $(OBJPATH)/properties.o \
$(OBJPATH)/compressor.o $(OBJPATH)/content_coder.o $(OBJPATH)/codetab.o \
$(OBJPATH)/htree.o $(OBJPATH)/freqtab_element.o $(OBJPATH)/freqtab.o \
$(OBJPATH)/pqueue.o $(OBJPATH)/htree_element.o $(OBJPATH)/htree_node.o \
$(OBJPATH)/htree_leaf.o $(OBJPATH)/main.o

# Es wird bei jedem normalen Build eine exe erzeugt und dann eine statische
# Codepruefung durchgefuehrt.
build : $(EXEPATH)/$(EXE)

# Regel zum Ausfuehren des aktuellen Programms
run : build
	./$(EXEPATH)/$(EXE)

# Build zusammen mit Doxygen, falls es zu einem Splint Fehler kommt wird
# abgebrochen .
build_release : $(SPLINT_LOG) $(EXEPATH)/$(EXE)  $(DOXYGEN_FILE)

clean_and_build : clean build

# ----------------------------------------------------------------------------
#Regel zum expliziten Erzeugung der Projektdokumentation
doxygen : $(DOXYGEN_FILE)

# ----------------------------------------------------------------------------
#Regel zum expliziten Erzeugung der Splintpruefung
splint : $(SPLINT_LOG)

# ----------------------------------------------------------------------------
# Aufruf des Linkers: erzeugt exe-Datei aus .o-Dateien
$(EXEPATH)/$(EXE) : $(OBJS)
	@echo ========================================================
	@echo Erzeuge $(EXEPATH)/$(EXE) $(OBJS)
	@echo --------------------------------------------------------
	mkdir -p $(EXEPATH)
	gcc -g $(OBJS) -o $(EXEPATH)/$(EXE)

# ----------------------------------------------------------------------------
# Aufruf des Linkers: erzeugt exe-Datei aus .o-Dateien fuer gdb
Debug : $(OBJS)
	@echo ========================================================
	@echo Erzeuge Debug $(EXEPATH)/$(EXE) $(OBJS)
	@echo --------------------------------------------------------
	mkdir -p $(EXEPATH)
	gcc -g $(OBJS) -o $(EXEPATH)/$(EXE)


$(OBJPATH)/error.o : src/error.c src/error.h
	@echo ========================================================
	@echo Erzeuge $(OBJPATH)/error.o
	@echo --------------------------------------------------------
	mkdir -p $(OBJPATH)
	gcc  $(GCC_OPTION) -o $(OBJPATH)/error.o src/error.c

$(OBJPATH)/freqtab_element.o : src/freqtab_element.c src/freqtab_element.h
	@echo ========================================================
	@echo Erzeuge $(OBJPATH)/freqtab_element.o
	@echo --------------------------------------------------------
	mkdir -p $(OBJPATH)
	gcc $(GCC_OPTION) -o $(OBJPATH)/freqtab_element.o src/freqtab_element.c


$(OBJPATH)/freqtab.o : src/freqtab.c src/freqtab.h src/freqtab_element.h src/error.h
	@echo ========================================================
	@echo Erzeuge $(OBJPATH)/freqtab.o
	@echo --------------------------------------------------------
	mkdir -p $(OBJPATH)
	gcc $(GCC_OPTION) -o $(OBJPATH)/freqtab.o src/freqtab.c


$(OBJPATH)/htree_element.o : src/htree_element.c src/htree_element.h src/htree_element.h
	@echo ========================================================
	@echo Erzeuge $(OBJPATH)/htree_element.o
	@echo --------------------------------------------------------
	mkdir -p $(OBJPATH)
	gcc $(GCC_OPTION) -o $(OBJPATH)/htree_element.o src/htree_element.c


$(OBJPATH)/pqueue.o : src/pqueue.c src/pqueue.h src/htree_element.h
	@echo ========================================================
	@echo Erzeuge $(OBJPATH)/pqueue.o
	@echo --------------------------------------------------------
	mkdir -p $(OBJPATH)
	gcc $(GCC_OPTION) -o $(OBJPATH)/pqueue.o src/pqueue.c


$(OBJPATH)/codetab_element.o : src/codetab_element.c
	@echo ========================================================
	@echo Erzeuge $(OBJPATH)/htree_element.o
	@echo --------------------------------------------------------
	mkdir -p $(OBJPATH)
	gcc $(GCC_OPTION) -o $(OBJPATH)/codetab_element.o src/codetab_element.c


$(OBJPATH)/htree.o : src/htree.c src/htree.h src/codetab_element.h src/htree_element.h src/pqueue.h src/freqtab.h src/freqtab_element.h
	@echo ========================================================
	@echo Erzeuge $(OBJPATH)/htree.o
	@echo --------------------------------------------------------
	mkdir -p $(OBJPATH)
	gcc $(GCC_OPTION) -o $(OBJPATH)/htree.o src/htree.c

$(OBJPATH)/htree_leaf.o : src/htree_leaf.c src/htree_leaf.h
	@echo ========================================================
	@echo Erzeuge $(OBJPATH)/htree.o
	@echo --------------------------------------------------------
	mkdir -p $(OBJPATH)
	gcc $(GCC_OPTION) -o $(OBJPATH)/htree_leaf.o src/htree_leaf.c

$(OBJPATH)/htree_node.o : src/htree_node.c src/htree_node.h
	@echo ========================================================
	@echo Erzeuge $(OBJPATH)/htree.o
	@echo --------------------------------------------------------
	mkdir -p $(OBJPATH)
	gcc $(GCC_OPTION) -o $(OBJPATH)/htree_node.o src/htree_node.c


$(OBJPATH)/properties.o : src/properties.c src/properties.h src/error.h
	@echo ========================================================
	@echo Erzeuge $(OBJPATH)/properties.o
	@echo --------------------------------------------------------
	mkdir -p $(OBJPATH)
	gcc $(GCC_OPTION) -o $(OBJPATH)/properties.o src/properties.c


$(OBJPATH)/codetab.o : src/codetab.c src/codetab.h src/codetab_element.h
	@echo ========================================================
	@echo Erzeuge $(OBJPATH)/codetab.o
	@echo --------------------------------------------------------
	mkdir -p $(OBJPATH)
	gcc $(GCC_OPTION) -o $(OBJPATH)/codetab.o src/codetab.c


$(OBJPATH)/content_coder.o : src/content_coder.c src/content_coder.h src/codetab.h
	@echo ========================================================
	@echo Erzeuge $(OBJPATH)/content_coder.o
	@echo --------------------------------------------------------
	mkdir -p $(OBJPATH)
	gcc $(GCC_OPTION) -o $(OBJPATH)/content_coder.o src/content_coder.c


$(OBJPATH)/compressor.o : src/compressor.c src/compressor.h src/freqtab.h src/htree.h src/codetab.h src/content_coder.h
	@echo ========================================================
	@echo Erzeuge $(OBJPATH)/compressor.o
	@echo --------------------------------------------------------
	mkdir -p $(OBJPATH)
	gcc $(GCC_OPTION) -o $(OBJPATH)/compressor.o src/compressor.c


$(OBJPATH)/main.o : src/main.c src/properties.h src/compressor.h src/error.h src/freqtab.h
	@echo ========================================================
	@echo Erzeuge $(OBJPATH)/main.o
	@echo --------------------------------------------------------
	mkdir -p $(OBJPATH)
	gcc $(GCC_OPTION) -o $(OBJPATH)/main.o src/main.c


# ----------------------------------------------------------------------------
# Regel zum Erzeugen der Splint Prüfung
$(SPLINT_LOG) : src/*.c src/*.h
	@echo ========================================================
	@echo Fuehre statische Codepruefung durch
	@echo --------------------------------------------------------
	splint -weak \
           -booltype BOOL -boolfalse FALSE -booltrue TRUE \
           +predboolint +noret +usedef +infloops +casebreak \
           -initallelements -incompletetype -fixedformalarray \
           +posix-lib src/*.c

# ----------------------------------------------------------------------------
# Regel zum Erzeugen der Projektdokumentation
$(DOXYGEN_FILE) : src/*.c src/*.h
	@echo ========================================================
	@echo Erzeuge Doxygen-Dokumentation
	@echo --------------------------------------------------------
	doxygen $(DOXYGEN_CFG)



# ----------------------------------------------------------------------------
# Regel zum Loeschen aller erzeugten Dateien
clean :
	@echo ========================================================
	@echo Loesche $(EXEPATH)/$(EXE), $(OBJS)
	@echo --------------------------------------------------------
	rm -f -r $(EXEPATH)
	rm -f -r $(OBJPATH)
	rm -f -r $(DOXYGEN_PATH)
	rm -f $(SPLINT_LOG)


#-----------------------------------------------------------------------------
# Automatisches Testen
test1 : build
	@echo Test:
	./$(EXEPATH)/$(EXE) -c ./res/bibel.txt
	./$(EXEPATH)/$(EXE) -d ./res/bibel.txt.hc ./res/bibel.txt.dc
	#diff -s ./res/bibel.txt ./res/bibel.txt.dc
	@echo Test durchgefuehrt

