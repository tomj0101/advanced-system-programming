all: dbconn

include $(ORACLE_HOME)/precomp/lib/env_precomp.mk
CC=gcc -g
CFLAGS=$((CFLAGS)) -I. -I$(ORACLE_HOME)/precomp/public -L$(ORACLE_HOME)/lib
#PROCFLAGS=$((PROCFLAGS))
PROC=proc 

dbconn: dbconn.mk
	$(CC) $(CFLAGS) dbconn.c -o dbconn

dbconn.c: dbconn.pc
#	$(PROC) $(PROCFLAGS) iname=dbconn.pc oname=dbconn.c
	proc iname=dbconn.pc oname=dbconn.c

clean: 
	rm -f dbconn.c \
	dbconn.lis \
	dbconn.o \
	dbconn
