PRE_MAKE_CXX_FLAGS=gcc -std=c++11 -Wno-literal-suffix -L ${ORACLE_HOME}/lib/ -I ${ORACLE_HOME}/rdbms/public/
POST_MAKE_CXX_FLAGS=-locci -lclntsh

all:executable
executable:main.o login.o employee.o generalmanager.o manager.o validation.o regionalmanager.o branchmanager.o bankemployee.o 
	$(PRE_MAKE_CXX_FLAGS) main.o login.o employee.o generalmanager.o manager.o validation.o regionalmanager.o branchmanager.o bankemployee.o $(POST_MAKE_CXX_FLAGS) -o executable
main.o:main.cpp
	$(PRE_MAKE_CXX_FLAGS) -c main.cpp $(POST_MAKE_CXX_FLAGS) -o main.o
login.o:login.cpp
	$(PRE_MAKE_CXX_FLAGS) -c login.cpp $(POST_MAKE_CXX_FLAGS) -o login.o
employee.o:employee.cpp
	$(PRE_MAKE_CXX_FLAGS) -c employee.cpp $(POST_MAKE_CXX_FLAGS) -o employee.o
generalmanager.o:generalmanager.cpp
	$(PRE_MAKE_CXX_FLAGS) -c generalmanager.cpp $(POST_MAKE_CXX_FLAGS) -o generalmanager.o
manager.o:manager.cpp
	$(PRE_MAKE_CXX_FLAGS) -c manager.cpp $(POST_MAKE_CXX_FLAGS) -o manager.o
validation.o:validation.cpp
	$(PRE_MAKE_CXX_FLAGS) -c validation.cpp $(POST_MAKE_CXX_FLAGS) -o validation.o
regionalmanager.o:regionalmanager.cpp
	$(PRE_MAKE_CXX_FLAGS) -c regionalmanager.cpp $(POST_MAKE_CXX_FLAGS) -o regionalmanager.o
branchmanager.o:branchmanager.cpp
	$(PRE_MAKE_CXX_FLAGS) -c branchmanager.cpp $(POST_MAKE_CXX_FLAGS) -o branchmanager.o
bankemployee.o:bankemployee.cpp
	$(PRE_MAKE_CXX_FLAGS) -c bankemployee.cpp $(POST_MAKE_CXX_FLAGS) -o bankemployee.o


clean:
	rm -rf *o executable
