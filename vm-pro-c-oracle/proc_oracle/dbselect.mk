all: dbselect

include $(ORACLE_HOME)/precomp/lib/env_precomp.mk
CC=gcc -g
CFLAGS=$((CFLAGS)) -I. -I$(ORACLE_HOME)/precomp/public -L$(ORACLE_HOME)/lib
#PROCFLAGS=$((PROCFLAGS))
PROC=proc 

dbselect: dbselect.mk
	$(CC) $(CFLAGS) dbselect.c -o dbselect

dbselect.c: dbselect.pc
	proc iname=dbselect.pc oname=dbselect.c

clean: 
	rm -f dbselect.c \
	dbselect.lis \
	dbselect.o \
	dbselect
