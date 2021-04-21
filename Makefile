##
## EPITECH PROJECT, 2020
## cpp_rush3
## File description:
## Makefile
##

UT_DIR	=	./tests/

UT_SRC	=	$(UT_DIR)test.cpp\

UT	=	units

SRC_DIR	=	./SFML_src/

SRC	=	$(SRC_DIR)Basic.cpp\
	        $(SRC_DIR)Main_display.cpp\
		./Ncurse_src/User.cpp\
		./Ncurse_src/Ncurse.cpp\
		./Ncurse_src/main.cpp\
		./Ncurse_src/Cpu.cpp\
		./Ncurse_src/Memory.cpp\
		./Ncurse_src/Network.cpp\

SRC	=		$(SRC_DIR)Basic.cpp\
			$(SRC_DIR)Main_display.cpp\
			$(SRC_DIR)Top/Top.cpp\
			$(SRC_DIR)Right/Right.cpp\
			$(SRC_DIR)Left/Left.cpp\
			$(SRC_DIR)Mid/Mid.cpp\
        		./Ncurse_src/Cpu.cpp\
			./Ncurse_src/Network.cpp\
        		./Ncurse_src/User.cpp\
        		./Ncurse_src/Memory.cpp\
        		./Ncurse_src/Ncurse.cpp\
        		./Ncurse_src/main.cpp\

MAIN	=	$(SRC_DIR)MainSfml.cpp

CFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lncurses

LDFLAGS	=	-lcriterion -lgcov -coverage

OBJ	=	$(SRC:.cpp=.o) $(MAIN:.cpp=.o)

NAME	=	MyGKrellm

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)
	rm -f $(OBJ)

gdb:
	g++ -o $(NAME) $(SRC) $(MAIN) $(CFLAGS) -g3

tests_run:
	g++ -o $(UT) $(UT_SRC) $(SRC) $(CFLAGS) $(LDFLAGS)
	./$(UT)

bonus:	$(BONUS_OBJ)
	g++ $(BONUS_NAME) $(BONUS_OBJ)

clean:
	rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)
		rm -f $(OBJ)
		rm -f $(UT)
		rm -f $(UT_DIR)*.gcno
		rm -f $(UT_DIR)*.gcda
		rm -f $(UT_DIR)*~
		rm -f $(SRC_DIR)*.gcno
	    rm -f $(SRC_DIR)*.gcda
	    rm -f $(SRC_DIR)*~
	    rm -f *.gcno
	    rm -f *.gcda
	    rm -f *~

re: 	fclean all
