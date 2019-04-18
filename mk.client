#簡略式makfefile for msys64 

TAR = client.exe

OBJS = \
	obj/client.o \

LIBS = \
	 -lgdi32

FLGS = \
	-g \
	-c \
	-m64 \
	-std=c++17 \
	-Wall \
	-Werror \
	-Wno-unused-variable \

#	-O3 \
	-Wno-unknown-pragmas \
	-Wno-unused-function \

#CC	= clang++
CC	= g++

$(TAR)	:	obj $(OBJS) $(SHDR)
	$(CC) -o $(TAR) $(OBJS) $(LIBS)

obj/%.o:%.cpp
	$(CC)  $(FLGS) $< -o $@

obj:
	mkdir obj

g:
	gdb -q $(TAR)
clean:
	rm -f *.exe
	rm -rf obj


