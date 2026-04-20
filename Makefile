# ++++++++++++++++++++++++++++++++++++++ MAKEFILE ++++++++++++++++++++++++++++++++++++++

# +++++ commands +++++

createlib: ./ttt_lib/libtttcore.a ./ttt_lib/libtttio.a ./ttt_lib/libtttutils.a clean

first_prototype: ./play/prototype \
	./ttt_lib/libtttcore.a ./ttt_lib/libtttio.a ./ttt_lib/libtttutils.a \
	clean

second_prototype: ./play/prototype_two \
	./ttt_lib/libtttcore.a ./ttt_lib/libtttio.a ./ttt_lib/libtttutils.a \
	clean

clean:
	rm -f ./srcs/core_field_manipulation.o ./srcs/core_read_field.o \
	./srcs/core_is_won.o ./srcs/core_won_diagonal.o \
	./srcs/core_won_row_col.o ./srcs/core_validation.o \
	./srcs/core_setup_field_values.o ./srcs/core_setup_player_values.o \
	./srcs/core_setup_base_values.o ./srcs/core_utils.o  \
	./srcs/io_user_input.o ./srcs/io_convert_str_int.o \
	./srcs/io_integrate_str_in_str.o ./srcs/io_terminal_output.o \
	./srcs/io_terminal_output_utils.o ./srcs/io_string_array.o \
	./srcs/io_utils.o ./srcs/null_utils.o

# +++++ programms +++++

./play/prototype : ./playable_prototype/first_prototype.c \
	./ui/cli/print_field.c ./ui/cli/print_error_messages.c \
	./ui/cli/print_game_messages.c
	mkdir -p play
	cc -Wall -Wextra -Werror ./playable_prototype/first_prototype.c \
	./ui/cli/print_field.c ./ui/cli/print_error_messages.c \
	./ui/cli/print_game_messages.c \
	-L ./ttt_lib/ -l tttcore -l tttio -l tttutils -o ./play/prototype

./play/prototype_two : ./playable_prototype/second_prototype.c \
	./engine/terminal_game_core.c ./engine/correct_object_stats.c \
	./game/cli/terminal_menu_layer_zero.c \
	./game/cli/terminal_menu_layer_first.c ./game/cli/terminal_menu_layer_sec.c \
	./game/cli/terminal_menu_layer_third.c ./game/cli/terminal_set_predefined_field.c \
	./ui/cli/print_field.c ./ui/cli/print_error_messages.c \
	./ui/cli/print_game_messages.c ./ui/cli/print_stats.c \
	./ui/cli/get_options.c
	mkdir -p play
	cc -Wall -Wextra -Werror -g ./playable_prototype/second_prototype.c \
	./engine/terminal_game_core.c ./engine/correct_object_stats.c \
	./game/cli/terminal_menu_layer_zero.c \
	./game/cli/terminal_menu_layer_first.c ./game/cli/terminal_menu_layer_sec.c \
	./game/cli/terminal_menu_layer_third.c \
	./game/cli/terminal_set_predefined_field.c \
	./ui/cli/print_field.c \
	./ui/cli/print_error_messages.c ./ui/cli/print_game_messages.c \
	./ui/cli/print_stats.c ./ui/cli/get_options.c \
	./incls/terminal_menu.h \
	-L ./ttt_lib/ -l tttcore -l tttio -l tttutils -o ./play/prototype_two

# +++++ libraries +++++

./ttt_lib/libtttcore.a : ./srcs/core_field_manipulation.o ./srcs/core_read_field.o \
	./srcs/core_is_won.o ./srcs/core_won_diagonal.o ./srcs/core_won_row_col.o \
	./srcs/core_validation.o ./srcs/core_setup_field_values.o \
	./srcs/core_setup_player_values.o ./srcs/core_setup_base_values.o \
	./srcs/core_utils.o
	mkdir -p ttt_lib
	ar rcs ./ttt_lib/libtttcore.a ./srcs/core_field_manipulation.o \
	./srcs/core_read_field.o ./srcs/core_is_won.o ./srcs/core_won_diagonal.o \
	./srcs/core_won_row_col.o ./srcs/core_validation.o \
	./srcs/core_setup_field_values.o ./srcs/core_setup_player_values.o \
	./srcs/core_setup_base_values.o ./srcs/core_utils.o

./ttt_lib/libtttio.a : ./srcs/io_user_input.o ./srcs/io_convert_str_int.o \
	./srcs/io_integrate_str_in_str.o ./srcs/io_terminal_output.o \
	./srcs/io_terminal_output_utils.o ./srcs/io_string_array.o \
	./srcs/io_utils.o
	mkdir -p ttt_lib
	ar rcs ./ttt_lib/libtttio.a ./srcs/io_user_input.o ./srcs/io_convert_str_int.o \
	./srcs/io_integrate_str_in_str.o ./srcs/io_terminal_output.o \
	./srcs/io_terminal_output_utils.o ./srcs/io_string_array.o \
	./srcs/io_utils.o

./ttt_lib/libtttutils.a : ./srcs/core_utils.o ./srcs/io_utils.o ./srcs/null_utils.o
	mkdir -p ttt_lib
	ar rcs ./ttt_lib/libtttutils.a \
	./srcs/core_utils.o ./srcs/io_utils.o ./srcs/null_utils.o

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

./srcs/core_setup_field_values.o : ./srcs/core_setup_field_values.c \
	./incls/field.h ./incls/player.h ./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_setup_field_values.c -I ./incls/ \
	-o ./srcs/core_setup_field_values.o

./srcs/core_setup_player_values.o : ./srcs/core_setup_player_values.c \
	./incls/field.h ./incls/player.h ./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_setup_player_values.c -I ./incls/ \
	-o ./srcs/core_setup_player_values.o

./srcs/core_setup_base_values.o : ./srcs/core_setup_base_values.c \
	./incls/field.h ./incls/player.h ./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_setup_base_values.c -I ./incls/ \
	-o ./srcs/core_setup_base_values.o

./srcs/core_utils.o : ./srcs/core_utils.c ./incls/field.h \
	./incls/tttcore.h ./incls/tttutils.h
	cc -Wall -Wextra -Werror -c ./srcs/core_utils.c -I ./incls/ \
	-o ./srcs/core_utils.o

./srcs/io_user_input.o : ./srcs/io_user_input.c \
	./incls/tttio.h
	cc -Wall -Wextra -Werror -c ./srcs/io_user_input.c -I ./incls/ \
	-o ./srcs/io_user_input.o

./srcs/io_convert_str_int.o : ./srcs/io_convert_str_int.c \
	./incls/tttio.h
	cc -Wall -Wextra -Werror -c ./srcs/io_convert_str_int.c -I ./incls/ \
	-o ./srcs/io_convert_str_int.o

./srcs/io_integrate_str_in_str.o : ./srcs/io_integrate_str_in_str.c \
	./incls/tttio.h
	cc -Wall -Wextra -Werror -c ./srcs/io_integrate_str_in_str.c -I ./incls/ \
	-o ./srcs/io_integrate_str_in_str.o

./srcs/io_string_array.o : ./srcs/io_string_array.c \
	./incls/tttio.h
	cc -Wall -Wextra -Werror -c ./srcs/io_string_array.c -I ./incls/ \
	-o ./srcs/io_string_array.o

./srcs/io_terminal_output.o : ./srcs/io_terminal_output.c \
	./incls/tttio.h
	cc -Wall -Wextra -Werror -c ./srcs/io_terminal_output.c -I ./incls/ \
	-o ./srcs/io_terminal_output.o

./srcs/io_terminal_output_utils.o : ./srcs/io_terminal_output_utils.c \
	./incls/tttio.h
	cc -Wall -Wextra -Werror -c ./srcs/io_terminal_output_utils.c -I ./incls/ \
	-o ./srcs/io_terminal_output_utils.o

./srcs/io_utils.o : ./srcs/io_utils.c \
	./incls/tttcore.h ./incls/tttutils.h
	cc -Wall -Wextra -Werror -c ./srcs/io_utils.c -I ./incls/ \
	-o ./srcs/io_utils.o

./srcs/null_utils.o : ./srcs/null_utils.c ./incls/tttutils.h
	cc -Wall -Wextra -Werror -c ./srcs/null_utils.c -I ./incls/ \
	-o ./srcs/null_utils.o

.PHONY: clean createlib first_prototype second_prototype

