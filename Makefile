##############################################################################
#  Programmer:  Camaro Walker and Katie Isbell
#  File:        makefile.txt
#  Assignment:  Semester Project and Programming Option
#  Due Date:    12/6/2013
#  Course:      CS301
#  Purpose:     This is the makefile used for the Semester Programming Project
##############################################################################

# Creates the "driver" exe
default: all
all: driver

# Dependencies
driver:      driver.o
								g++ driver.o -o driver

driver.o:    driver.cpp matrix.h matrix.hpp vector.h vector.hpp divisionByZeroError.h \
             subscriptRangeError.h sizeMismatchError.h database.h database.hpp

								g++ -c driver.cpp

# Removes the driver exe, object files, and core dumps
clean:
	-@rm -f core > /dev/null 2>&1
	-@rm -f driver > /dev/null 2>&1
	-@rm *.o > /dev/null 2>&1

