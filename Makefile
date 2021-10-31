TARGET = philo
SRCS =	main.c \
		philo.c \
		utils.c
OBJS =	$(SRCS:.c=.o)
CC =	gcc
CF =	-Wall -Wextra -Werror -Iincludes -pthread 

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CF) $^ -o $@

%.o : %.c
	$(CC) $(CF) $< -c

clean :
	rm -f *.o

fclean : clean
	rm -f $(TARGET)

re : fclean all

bonus : all

.PHONY = all clean fclean re bonus
