#ifndef TERMINAL_MENU_H
# define TERMINAL_MENU_H

//include
# include <stddef.h>

// layer NULL
# define PATH_MAIN "\npath: main/\n"
// layer first
# define PATH_PRED "\npath: main/ predefined tables/\n"
# define PATH_TSET "\npath: main/ table settings/\n"
# define PATH_SHOW "\npath: main/ show table settings/\n"
# define PATH_PLAY "\npath: main/ start/\n"
# define PATH_INFO "\npath: main/ info/\n"
// layer second
# define PATH_FIELD "\npath: main/ table settings/ field/\n"
# define PATH_PLAYER "\npath: main/ table settings/ player/\n"
# define PATH_BASE "\npath: main/ table settings/ base/\n"

// layer NULL
# define HEAD_MAIN "\nsniggle\n"
// layer first
# define HEAD_PRED "\nReady to play?\n\nfollowing settings:\n\n"
# define HEAD_TSET "\nReady to play?\n\nfollowing settings:\n\n"
# define HEAD_SHOW "\nReady to play?\n\nfollowing settings:\n\n"
# define HEAD_PLAY "\nReady to play?\n\nfollowing settings:\n\n"
# define HEAD_INFO "\nReady to play?\n\nfollowing settings:\n\n"
// layer second
# define HEAD_FIELD "\nPlease select a field measurements:\n\n"
# define HEAD_PLAYER "\nPlease select:\n\n"
# define HEAD_BASE "--- NULL ---"

// layer NULL
# define MENU_MAIN "Menu:\n\n\t[1] play predefined table\n\t[2] table settings\n\t[3] show settings\n\t[4] start\n\t[5] info\n\t[X] exit\n\n"
// layer first
# define MENU_PRED "Options:\n\n\t[1] classic TicTacToe\n\t[2] Four in a row\n\t[3] Four in a row wide\n\t[4] four in a row huge\n\t[5] four in a row wide hex\n\t[X] back\n\n"
# define MENU_TSET "Options:\n\n\t[1] set field\n\t[2] set player\n\t[3] set base\n\t[X] back\n\n"
# define MENU_SHOW "Options:\t[X] back\n"
# define MENU_PLAY "Options:\n\n\t[1] player name\n\t[2] play\n\t[X] back\n\n"
# define MENU_INFO "Options:\t[X] back\n"
// layer second
# define MENU_FIELD "Options:\n\n\t[1] 3 x 3 field\n\t[2] 4 x 5 field\n\t[3] 7 x 7 field\n\t[4] custom field\n\t[X] back"
# define MENU_PLAYER "Menu:\n\n\t[1] number of players\n\t[2] edit player\n\t[X] back"

// layer NULL
# define OPT_MAIN ((char *[]){"X", "1", "2", "3", "4", "5", NULL})
// layer first
# define OPT_PRED ((char *[]){"X", "1", "2", "3", "4", "5", NULL})
# define OPT_TSET ((char *[]){"X", "1", "2", "3", NULL})
# define OPT_SHOW ((char *[]){"X", NULL})
# define OPT_PLAY ((char *[]){"X", "1", "2", NULL})
# define OPT_INFO ((char *[]){"X", NULL})
// layer second
# define OPT_FIELD ((char *[]){"X", "1", "2", "3", "4", NULL})
# define OPT_PLAYER ((char *[]){"X", "1", "2", NULL})
# define OPT_BASE ((char *[]){NULL})

#endif
