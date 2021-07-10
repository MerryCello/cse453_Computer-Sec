###############################################################
# Program:
# Author:
# Summary:
###############################################################

OBJDIR = ./.makefileObjects

##############################################################
# The main rule
##############################################################
accessControl.exe: mkObjDir ${OBJDIR}/control.o ${OBJDIR}/message.o \
                            ${OBJDIR}/messages.o ${OBJDIR}/interact.o \
                            ${OBJDIR}/lab12.o
	g++ -o ${OBJDIR}/*.o -g -std=c++11

##############################################################
# any file that pertains to the program
##############################################################
${OBJDIR}/control.o: control.cpp control.h
	g++ -c control.cpp -g -std=c++11 -o $@

${OBJDIR}/message.o: message.cpp message.h control.h
	g++ -c message.cpp -g -std=c++11 -o $@

${OBJDIR}/messages.o: messages.cpp message.h messages.h control.h
	g++ -c messages.cpp -g -std=c++11 -o $@

${OBJDIR}/interact.o: interact.cpp interact.h messages.h control.h
	g++ -c interact.cpp -g -std=c++11 -o $@

${OBJDIR}/lab12.o: lab12.cpp messages.h interact.h
	g++ -c lab12.cpp -g -std=c++11 -o $@


###############################################################
# TOOLS
###############################################################
clean:
	@rm ${OBJDIR}/*
	@rm a.exe a.out *.o

# Make OBJDIR if needs be
mkObjDir:
	@mkdir -p ${OBJDIR}
