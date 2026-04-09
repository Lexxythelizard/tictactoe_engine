# ++++++++++++++++++++++++++++++++++++++ MAKEFILE ++++++++++++++++++++++++++++++++++++++

# +++++ commands +++++

createlib: ./ttt_lib/libtttcore.a ./ttt_lib/libtttio.a ./ttt_lib/libtttutils.a clean

first_prototype: ./playable_prototype/first_prototype \
	./ttt_lib/libtttcore.a ./ttt_lib/libtttio.a ./ttt_lib/libtttutils.a \
	clean

clean:
	rm -f ./srcs/core_field_manipulation.o ./srcs/core_read_field.o \
	./srcs/core_is_won.o ./srcs/core_won_diagonal.o \
	./srcs/core_won_row_col.o ./srcs/core_validation.o \
	./srcs/core_setup_values.o ./srcs/core_utils.o  \
	./srcs/io_user_input.o ./srcs/io_convert_str_int.o \
	./srcs/io_integrate_str_in_str.o ./srcs/io_terminal_output.o \
	./srcs/io_utils.o

# +++++ programms +++++

./playable_prototype/first_prototype : ./playable_prototype/first_prototype.c \
	./ui/cli/print_field.c ./ui/cli/print_error_messages.c \
	./ui/cli/print_game_messages.c
	mkdir -p play
	cc -Wall -Wextra -Werror ./playable_prototype/first_prototype.c \
	./ui/cli/print_field.c ./ui/cli/print_error_messages.c \
	./ui/cli/print_game_messages.c \
	-L ./ttt_lib/ -l tttcore -l tttio -l tttutils -o ./play/prototype

# +++++ libraries +++++

./ttt_lib/libtttcore.a : ./srcs/core_field_manipulation.o ./srcs/core_read_field.o \
	./srcs/core_is_won.o ./srcs/core_won_diagonal.o ./srcs/core_won_row_col.o \
	./srcs/core_validation.o ./srcs/core_setup_values.o ./srcs/core_utils.o
	mkdir -p ttt_lib
	ar rcs ./ttt_lib/libtttcore.a ./srcs/core_field_manipulation.o \
	./srcs/core_read_field.o ./srcs/core_is_won.o ./srcs/core_won_diagonal.o \
	./srcs/core_won_row_col.o ./srcs/core_validation.o \
	./srcs/core_setup_values.o ./srcs/core_utils.o

./ttt_lib/libtttio.a : ./srcs/io_user_input.o ./srcs/io_convert_str_int.o \
	./srcs/io_integrate_str_in_str.o ./srcs/io_terminal_output.o ./srcs/io_utils.o
	mkdir -p ttt_lib
	ar rcs ./ttt_lib/libtttio.a ./srcs/io_user_input.o ./srcs/io_convert_str_int.o \
	./srcs/io_integrate_str_in_str.o ./srcs/io_terminal_output.o ./srcs/io_utils.o

./ttt_lib/libtttutils.a : ./srcs/core_utils.o ./srcs/io_utils.o
	mkdir -p ttt_lib
	ar rcs ./ttt_lib/libtttutils.a ./srcs/core_utils.o ./srcs/io_utils.o

# +++++ Objectfiles +++++

./srcs/core_field_manipulation.o : ./srcs/core_field_manipulation.c ./incls/field.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_field_manipulation.c -I ./incls/ \
	-o ./srcs/core_field_manipulation.o

./srcs/core_read_field.o : ./srcs/core_read_field.c ./incls/field.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_read_field.c -I ./incls/ \
	-o ./srcs/core_read_field.o

./srcs/core_is_won.o : ./srcs/core_is_won.c ./incls/field.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_is_won.c -I ./incls/ \
	-o ./srcs/core_is_won.o

./srcs/core_won_diagonal.o : ./srcs/core_won_diagonal.c ./incls/field.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_won_diagonal.c -I ./incls/ \
	-o ./srcs/core_won_diagonal.o

./srcs/core_won_row_col.o : ./srcs/core_won_row_col.c ./incls/field.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_won_row_col.c -I ./incls/ \
	-o ./srcs/core_won_row_col.o

./srcs/core_validation.o : ./srcs/core_validation.c ./incls/field.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_validation.c -I ./incls/ \
	-o ./srcs/core_validation.o

./srcs/core_setup_values.o : ./srcs/core_setup_values.c ./incls/field.h ./incls/player.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_setup_values.c -I ./incls/ \
	-o ./srcs/core_setup_values.o

./srcs/core_utils.o : ./srcs/core_utils.c ./incls/field.h \
	./incls/tttcore.h ./incls/tttutils.h
	cc -Wall -Wextra -Werror -c ./srcs/core_utils.c -I ./incls/ \
	-o ./srcs/core_utils.o

./srcs/io_user_input.o : ./srcs/io_user_input.c \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/io_user_input.c -I ./incls/ \
	-o ./srcs/io_user_input.o

./srcs/io_convert_str_int.o : ./srcs/io_convert_str_int.c \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/io_convert_str_int.c -I ./incls/ \
	-o ./srcs/io_convert_str_int.o

./srcs/io_integrate_str_in_str.o : ./srcs/io_integrate_str_in_str.c \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/io_integrate_str_in_str.c -I ./incls/ \
	-o ./srcs/io_integrate_str_in_str.o

./srcs/io_terminal_output.o : ./srcs/io_terminal_output.c \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/io_terminal_output.c -I ./incls/ \
	-o ./srcs/io_terminal_output.o

./srcs/io_utils.o : ./srcs/io_utils.c \
	./incls/tttcore.h ./incls/tttutils.h
	cc -Wall -Wextra -Werror -c ./srcs/io_utils.c -I ./incls/ \
	-o ./srcs/io_utils.o

.PHONY: clean createlib first_prototype

