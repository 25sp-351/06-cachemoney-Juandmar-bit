CC = clang
CFLANGS = -Wall -Wextra -g
EXEC = money_to_string
SRC = money_to_string.c memoize.c conversion.c

all: $(EXEC)

$(EXEC): $(SRC)
		$(CC) $(CFLANGS) -o $(EXEC) $(SRC)

rebuild: clean all

run: $(EXEC)
		@echo "Running ..."
		./$(EXEC)

clean: 
		rm -f $(EXEC)