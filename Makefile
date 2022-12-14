PROGRAM	= Main
APPNAME = FanAnimation
TARGET	= $(shell echo $(PROGRAM) | tr "[:upper:]" "[:lower:]")
INSTDIR	= $(APPNAME).app/Contents/Resources/C/
ARCHIVE	= $(shell basename `pwd`)
CC	= hgcc
CCFLAGS	= $(shell \
	XcodeMajorVersion=`xcodebuild -version | head -n 1 | cut -d " " -f 2 | cut -d "." -f 1`; \
	if [ $${XcodeMajorVersion} -lt "12" ] ; \
	then \
		echo '-Weverything -Werror -save-temps' ; \
	else \
		echo '-Weverything -Werror -Wno-poison-system-directories -save-temps' ; \
	fi)
CCTEMPS	= *.o *.s *.i *.bc
REPORTS	= ClangStaticAnalyzerReports
CHECKER	= scan-build --use-analyzer=`which $(CC)` --view -o $(REPORTS)
SOUNDSFILE = ./Sounds
IMAGESFILE = ./images
MODULES	= \
	$(PROGRAM) \
	Model \
	View \
	Controller \
	Fan \
	Bell

SOURCES	= $(shell for each in `echo $(MODULES)` ; do echo $${each}.c ; done)
OBJECTS	= $(shell for each in `echo $(MODULES)` ; do echo $${each}.o ; done)

HEADERS	= Definition.h

all: $(TARGET)
	@:

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

$(SOURCES): $(HEADERS)
	@:

%.o: %.c
	$(CC) -c $< -o $@

clean:
	@for each in `ls $(TARGET) $(CCTEMPS) 2> /dev/null` ; do echo "rm -f $${each}" ; rm -f $${each} ; done
	@if [ -e $(INSTDIR) ] ; then echo "rm -f -r $(INSTDIR)" ; rm -f -r $(INSTDIR) ; fi

test: $(TARGET)
	open ${HOME}/../../Applications/HgDisplayer.app;
	sleep 3;
	./$(TARGET)

install: $(TARGET)
	@if [ ! -e $(INSTDIR) ] ; then echo "mkdir $(INSTDIR)" ; mkdir $(INSTDIR) ; fi
	cp -p $(TARGET) $(INSTDIR);
	cp -r $(SOUNDSFILE) $(INSTDIR);
	cp -r $(IMAGESFILE) $(INSTDIR)

open: install
	open $(PROGRAM).app

zip: clean wipe
	(cd ../ ; zip -r ./$(ARCHIVE).zip ./$(ARCHIVE)/)

lint: clean
	$(CHECKER) make

wipe:
	@if [ -e $(REPORTS) ] ; then echo "rm -f -r $(REPORTS)" ; rm -f -r $(REPORTS) ; fi

format:
	@for each in $(HEADERS) $(SOURCES) ; do echo "/*** $${each} ***/" ; clang-format -style=file $${each} ; echo ; done