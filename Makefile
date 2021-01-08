TARGET = c2048
SRC := $(wildcard src/*.c)

.PHONY: all clean

all: ${TARGET}

clean:
ifeq ($(OS),Windows_NT)
	del /f ${TARGET}.exe
else
	rm -f ${TARGET}
endif

${TARGET}: ${SRC}
	gcc $^ -Iinclude -o $@
