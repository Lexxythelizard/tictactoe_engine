createlib: ./ttt_lib/libtttengine.a ./ttt_lib/libtttutils.a clean

clean:
	rm -f ./srcs/field_manipulation.o ./srcs/read_field_0.o \
        ./srcs/read_field_1.o ./srcs/validation.o ./srcs/read_user_input.o \
        ./srcs/utilities_0.o ./srcs/utilities_1.o

# +++++ libaries +++++

./ttt_lib/libtttengine.a : ./srcs/field_manipulation.o ./srcs/read_field_0.o \
	./srcs/read_field_1.o ./srcs/validation.o ./srcs/read_user_input.o \
	./srcs/utilities_0.o ./srcs/utilities_1.o
	ar rcs ./ttt_lib/libtttengine.a ./srcs/field_manipulation.o ./srcs/read_field_0.o \
        ./srcs/read_field_1.o ./srcs/validation.o ./srcs/read_user_input.o \
        ./srcs/utilities_0.o ./srcs/utilities_1.o

./ttt_lib/libtttutils.a : ./srcs/utilities_0.o ./srcs/utilities_1.o
	ar rcs ./ttt_lib/libtttutils.a ./srcs/utilities_0.o ./srcs/utilities_1.o

# +++++ Objectfiles +++++

./srcs/field_manipulation.o : ./srcs/field_manipulation.c ./incls/meta.h \
	./incls/tttengine.h
	cc -Wall -Wextra -Werror -c ./srcs/field_manipulation.c -I ./incls/ \
	-o ./srcs/field_manipulation.o

./srcs/read_field_0.o : ./srcs/read_field_0.c ./incls/meta.h \
	./incls/tttengine.h
	cc -Wall -Wextra -Werror -c ./srcs/read_field_0.c -I ./incls/ \
	-o ./srcs/read_field_0.o

./srcs/read_field_1.o : ./srcs/read_field_1.c ./incls/meta.h \
	./incls/tttengine.h
	cc -Wall -Wextra -Werror -c ./srcs/read_field_1.c -I ./incls/ \
	-o ./srcs/read_field_1.o

./srcs/validation.o : ./srcs/validation.c ./incls/meta.h \
	./incls/tttengine.h
	cc -Wall -Wextra -Werror -c ./srcs/validation.c -I ./incls/ \
	-o ./srcs/validation.o

./srcs/read_user_input.o : ./srcs/read_user_input.c ./incls/meta.h \
	./incls/tttengine.h
	cc -Wall -Wextra -Werror -c ./srcs/read_user_input.c -I ./incls/ \
	-o ./srcs/read_user_input.o

./srcs/setup.o : ./srcs/setup.c ./incls/meta.h \
	./incls/tttengine.h
	cc -Wall -Wextra -Werror -c ./srcs/setup.c -I ./incls/ \
	-o ./srcs/setup.o

./srcs/utilities_0.o : ./srcs/utilities_0.c ./incls/meta.h \
	./incls/tttengine.h ./incls/tttutils.h
	cc -Wall -Wextra -Werror -c ./srcs/utilities_0.c -I ./incls/ \
	-o ./srcs/utilities_0.o

./srcs/utilities_1.o : ./srcs/utilities_1.c ./incls/meta.h \
	./incls/tttengine.h ./incls/tttutils.h
	cc -Wall -Wextra -Werror -c ./srcs/utilities_1.c -I ./incls/ \
	-o ./srcs/utilities_1.o

.PHONY: clean createlib

