OUTPUT_PATH = out/production/practice/
SOURCE_PATH = src/

CCMD = gcc

all:
	@echo Compiling ...
	$(CCMD) -o $(OUTPUT_PATH)binarytree $(SOURCE_PATH)binarytree.c
	$(CCMD) -o $(OUTPUT_PATH)linkedlist $(SOURCE_PATH)linkedlist.c

clean:
	rm -f $(OUTPUT_PATH)binarytree
	rm -f $(OUTPUT_PATH)linkedlist

rebuild: clean all
#rebuild is not entirely correct
