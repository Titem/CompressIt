#
#  There exist several targets which are by default empty and which can be 
#  used for execution of your targets. These targets are usually executed 
#  before and after some main targets. They are: 
#
#     .build-pre:              called before 'build' target
#     .build-post:             called after 'build' target
#     .clean-pre:              called before 'clean' target
#     .clean-post:             called after 'clean' target
#     .clobber-pre:            called before 'clobber' target
#     .clobber-post:           called after 'clobber' target
#     .all-pre:                called before 'all' target
#     .all-post:               called after 'all' target
#     .help-pre:               called before 'help' target
#     .help-post:              called after 'help' target
#
#  Targets beginning with '.' are not intended to be called on their own.
#
#  Main targets can be executed directly, and they are:
#  
#     build                    build a specific configuration
#     clean                    remove built files from a configuration
#     clobber                  remove all built files
#     all                      build all configurations
#     help                     print help mesage
#  
#  Targets .build-impl, .clean-impl, .clobber-impl, .all-impl, and
#  .help-impl are implemented in nbproject/makefile-impl.mk.
#
#  Available make variables:
#
#     CND_BASEDIR                base directory for relative paths
#     CND_DISTDIR                default top distribution directory (build artifacts)
#     CND_BUILDDIR               default top build directory (object files, ...)
#     CONF                       name of current configuration
#     CND_PLATFORM_${CONF}       platform name (current configuration)
#     CND_ARTIFACT_DIR_${CONF}   directory of build artifact (current configuration)
#     CND_ARTIFACT_NAME_${CONF}  name of build artifact (current configuration)
#     CND_ARTIFACT_PATH_${CONF}  path to build artifact (current configuration)
#     CND_PACKAGE_DIR_${CONF}    directory of package (current configuration)
#     CND_PACKAGE_NAME_${CONF}   name of package (current configuration)
#     CND_PACKAGE_PATH_${CONF}   path to package (current configuration)
#
# NOCDDL


# Environment 
#MKDIR=mkdir
#CP=cp
#CCADMIN=CCadmin
OBJPATH = build
EXEPATH = dist
EXE = huffman.exe

# Compiler-Optionen
GCC_OPTION = -c -g -DDEBUG -std=c99 -pedantic-errors

# Konfiguration fuer Doxygen
DOXYGEN_PATH = doxygen
DOXYGEN_FILE = $(DOXYGEN_PATH)/html/index.html
DOXYGEN_CFG = ~/ppr_doxygen.cfg

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
	gcc $(GCC_OPTION) -o $(OBJPATH)/error.o src/error.c

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
$(SPLINT_LOG) : *.c *.h
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

