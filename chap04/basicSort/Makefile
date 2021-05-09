CPP = g++

CFLAGS = -Wall -Werror -Wextra

TARGET = basicsort

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

.PHONY: all
all : $(TARGET)

$(TARGET) :
	$(CPP) $(CFLAGS) -o $(TARGET) $(SRC)

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -rf $(TARGET)

.PHONY: re
re: fclean all
