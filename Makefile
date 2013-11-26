##############################################################################
#  Programmer:  Katie Isbell
#  File:        makefile.txt
#  Assignment:  Semester Project Programming Option
#  Due Date:    12/6/2013
#  Course:      CS301
#  Purpose:     This is the makefile used for the CS301 Semester Programming 
#               Project
##############################################################################

# Creates the "driver" exe
default: all
all: driver

# Dependencies
driver:      driver.o
								g++ driver.o -o driver

driver.o:    attribute.h attribute.hpp dataset.h dataset.hpp divisionByZeroError.h \
            driver.cpp fileNotExistError.h incorrectInputError.h matrix.h matrix.hpp \
            partition.h partition.hpp rico.h rico.hpp sizeMismatchError.h \
            subscriptRangeError.h vector.h vector.hpp

								g++ -c driver.cpp

# Removes the driver exe, object files, and core dumps
clean:
	-@rm -f core > /dev/null 2>&1
	-@rm -f driver > /dev/null 2>&1
	-@rm *.o > /dev/null 2>&1

