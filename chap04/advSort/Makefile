CPP = g++
CFLAGS = -Wall -Werror -Wextra

TARGET = advsort

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: $(TARGET)

$(TARGET):
	$(CPP) $(CFLAGS) -o $(TARGET) $(SRCS)

.PHONY: clean
clean:
	rm -rf $(OBJS)

.PHONY: fclean
fclean: clean
	rm -rf $(TARGET)

.PHONY: re
re: fclean all