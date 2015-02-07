# Environment 
OBJPATH = build
EXEPATH = dist
EXE = huffman.exe

CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build
# Compiler-Optionen
GCC_OPTION = -c -g -DDEBUG -std=c99 -pedantic-errors

# Konfiguration fuer Doxygen
DOXYGEN_PATH = doxygen
DOXYGEN_FILE = $(DOXYGEN_PATH)/html/index.html
DOXYGEN_CFG = res/ppr_doxygen.cfg

# Konfiguration fuer Splint
SPLINT_LOG = ./splint.log

OBJS = $(OBJPATH)/error.o $(OBJPATH)/codetab_element.o $(OBJPATH)/properties.o $(OBJPATH)/compressor.o \
$(OBJPATH)/content_coder.o $(OBJPATH)/codetab.o $(OBJPATH)/htree.o $(OBJPATH)/freqtab_element.o \
$(OBJPATH)/freqtab.o $(OBJPATH)/pqueue.o \
$(OBJPATH)/htree_element.o $(OBJPATH)/main.o

# Standardziel
build : $(EXEPATH)/$(EXE)

# Regel zum Ausfuehren des aktuellen Programms
run : build
	./$(EXEPATH)/$(EXE)

build_all : $(SPLINT_LOG) $(EXEPATH)/$(EXE) $(DOXYGEN_FILE) 
clean_and_build : clean build

# Aufruf des Linkers: erzeugt exe-Datei aus .o-Dateien
$(EXEPATH)/$(EXE) : $(OBJS)
	@echo ========================================================
	@echo Erzeuge $(EXEPATH)/$(EXE) $(OBJS)
	@echo --------------------------------------------------------
	mkdir -p $(EXEPATH)
	gcc $(OBJS) -o $(EXEPATH)/$(EXE) 

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


$(OBJPATH)/htree.o : src/htree.c src/htree.h src/codetab_element.h src/htree_element.h src/pqueue.h src/freqtab.h
	@echo ========================================================
	@echo Erzeuge $(OBJPATH)/htree.o
	@echo --------------------------------------------------------
	mkdir -p $(OBJPATH)
	gcc $(GCC_OPTION) -o $(OBJPATH)/htree.o src/htree.c
	
	
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
	splint -weak -I $(STACK_PATH) \
           -booltype BOOL -boolfalse FALSE -booltrue TRUE \
           +predboolint +noret +usedef +infloops +casebreak \
           -initallelements -incompletetype -fixedformalarray \
           *.c > $(SPLINT_LOG)

# ----------------------------------------------------------------------------
# Regel zum Erzeugen der Projektdokumentation
$(DOXYGEN_FILE) : *.c *.h
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
# Netbeans Makefile	


#-----------------------------------------------------------------------------
# Automatisches Testen
test1 : 
	@echo Test:
	./$(EXEPATH)/$(EXE) -c ./res/bibel.txt
	@echo Test durchgeführt


