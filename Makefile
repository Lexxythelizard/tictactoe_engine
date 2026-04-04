createlib: ./ttt_lib/libtttcore.a ./ttt_lib/libtttio.a ./ttt_lib/libtttutils.a clean

clean:
	rm -f ./srcs/core_field_manipulation.o ./srcs/core_read_field.o \
	./srcs/core_is_won.o ./srcs/core_won_diagonal.o \
	./srcs/core_won_row_col.o ./srcs/core_validation.o \
	./srcs/core_setup_values.o ./srcs/core_utils.o  \
	./srcs/io_user_input.o ./srcs/io_convert_str_int.o \
	./srcs/io_integrate_str_in_str.o ./srcs/io_utils.o

# +++++ libraries +++++

./ttt_lib/libtttcore.a : ./srcs/core_field_manipulation.o ./srcs/core_read_field.o \
	./srcs/core_is_won.o ./srcs/core_won_diagonal.o ./srcs/core_won_row_col.o \
	./srcs/core_validation.o ./srcs/core_setup_values.o ./srcs/core_utils.o
	ar rcs ./ttt_lib/libtttcore.a ./srcs/core_field_manipulation.o \
	./srcs/core_read_field.o ./srcs/core_is_won.o ./srcs/core_won_diagonal.o \
	./srcs/core_won_row_col.o ./srcs/core_validation.o \
	./srcs/core_setup_values.o ./srcs/core_utils.o

./ttt_lib/libtttio.a : ./srcs/io_user_input.o ./srcs/io_convert_str_int.o \
	./srcs/io_integrate_str_in_str.o ./srcs/io_utils.o
	ar rcs ./ttt_lib/libtttio.a ./srcs/io_user_input.o ./srcs/io_convert_str_int.o \
	./srcs/io_integrate_str_in_str.o ./srcs/io_utils.o

./ttt_lib/libtttutils.a : ./srcs/core_utils.o ./srcs/io_utils.o
	ar rcs ./ttt_lib/libtttutils.a ./srcs/core_utils.o ./srcs/io_utils.o

# +++++ Objectfiles +++++

./srcs/core_field_manipulation.o : ./srcs/core_field_manipulation.c ./incls/meta.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_field_manipulation.c -I ./incls/ \
	-o ./srcs/core_field_manipulation.o

./srcs/core_read_field.o : ./srcs/core_read_field.c ./incls/meta.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_read_field.c -I ./incls/ \
	-o ./srcs/core_read_field.o

./srcs/core_is_won.o : ./srcs/core_is_won.c ./incls/meta.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_is_won.c -I ./incls/ \
	-o ./srcs/core_is_won.o

./srcs/core_won_diagonal.o : ./srcs/core_won_diagonal.c ./incls/meta.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_won_diagonal.c -I ./incls/ \
	-o ./srcs/core_won_diagonal.o

./srcs/core_won_row_col.o : ./srcs/core_won_row_col.c ./incls/meta.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_won_row_col.c -I ./incls/ \
	-o ./srcs/core_won_row_col.o

./srcs/core_validation.o : ./srcs/core_validation.c ./incls/meta.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_validation.c -I ./incls/ \
	-o ./srcs/core_validation.o

./srcs/core_setup_values.o : ./srcs/core_setup_values.c ./incls/meta.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/core_setup_values.c -I ./incls/ \
	-o ./srcs/core_setup_values.o

./srcs/core_utils.o : ./srcs/core_utils.c ./incls/meta.h \
	./incls/tttcore.h ./incls/tttutils.h
	cc -Wall -Wextra -Werror -c ./srcs/core_utils.c -I ./incls/ \
	-o ./srcs/core_utils.o

./srcs/io_user_input.o : ./srcs/io_user_input.c ./incls/meta.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/io_user_input.c -I ./incls/ \
	-o ./srcs/io_user_input.o

./srcs/io_convert_str_int.o : ./srcs/io_convert_str_int.c ./incls/meta.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/io_convert_str_int.c -I ./incls/ \
	-o ./srcs/io_convert_str_int.o

./srcs/io_integrate_str_in_str.o : ./srcs/io_integrate_str_in_str.c ./incls/meta.h \
	./incls/tttcore.h
	cc -Wall -Wextra -Werror -c ./srcs/io_integrate_str_in_str.c -I ./incls/ \
	-o ./srcs/io_integrate_str_in_str.o

./srcs/io_utils.o : ./srcs/io_utils.c ./incls/meta.h \
	./incls/tttcore.h ./incls/tttutils.h
	cc -Wall -Wextra -Werror -c ./srcs/io_utils.c -I ./incls/ \
	-o ./srcs/io_utils.o

.PHONY: clean createlib

