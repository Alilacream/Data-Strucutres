# L-moteu (Compiler)
CC = gcc

# L-qwanen (Warnings and Debugging)
# -Wall: goul l-ia ay khata' sghir
# -g: khli l-ia l-forsa ndir 'debug' ila t'bloka l-programe
CFLAGS = -Wall -Wextra -g 

# Smia d-l-executable (L-kharij l-niha'i)
TARGET = main

# Jma' ga' l-fichiyat .c li 'ndek f l-dossier
SRC = $(wildcard *.c)

# Beddel smiat .c b .o (Object files)
OBJS = $(SRC:.c=.o)

# Fin kaynin l-fichiyat .h (Headers)
# FIX: Beddelt ')' b '=' bach tkhdem
INCLUDES = -I./Headers

# L-hedaf l-asasi: kheddem 'main'
all: $(TARGET)

# Bach n'siybo l-kharij (Target), khsena n'jm'o ga' l-object files (.o)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Had l-qa'ida kat'akhd ay .c w t'rejdou .o
# $<: l-fichi .c (l-madat l-kham)
# $@: l-fichi .o (l-natija)
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Ila briti t'mse7 l-rwina (ga' l-.o w l-main) bach tbda mn jdid
clean:
	rm -f *.o $(TARGET)

# Compile w kheddem l-programe f deqqa wehda
run: all
	./$(TARGET)
