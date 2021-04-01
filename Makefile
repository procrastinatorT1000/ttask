all:
ifeq ($(OS),Windows_NT)
	
else
	gcc task1.cpp -lstdc++ -o task1.o
endif

clean:
ifneq ($(OS),Windows_NT)
	-rm task1.o
endif

