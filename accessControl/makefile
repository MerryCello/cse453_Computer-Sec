###############################################################
# Program:
# Author:
# Summary:
###############################################################

##############################################################
# The main rule
##############################################################
a.exe: lab12.o interact.o control.o messages.o message.o
	g++ -o lab12.o interact.o control.o messages.o message.o -g -std=c++11

##############################################################
# any file that pertains to the program
##############################################################
control.o: control.cpp control.h
	g++ -c control.cpp -g -std=c++11

message.o: message.cpp messages.h control.h
	g++ -c message.cpp -g -std=c++11

messages.o: messages.cpp control.h message.h messages.h
	g++ -c messages.cpp -g -std=c++11

interact.o: interact.cpp interact.h messages.h control.h
	g++ -c interact.cpp -g -std=c++11

lab12.o: lab12.cpp messages.h interact.h
	g++ -c lab12.cpp -g -std=c++11


###############################################################
# TOOLS
###############################################################
clean:
	rm *.o
