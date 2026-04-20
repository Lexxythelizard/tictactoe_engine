#ifndef TERMINAL_MENU_H
# define TERMINAL_MENU_H

//include
# include <stddef.h>

// NULL
# define SECTION_SEP "\n+++++++++++++++++++++++++++++++++++++++++++++++++\n"
// layer NULL
# define PATH_MAIN "path: main/\n\n"
// layer first
# define PATH_PRED "path: main/ predefined tables/\n\n"
# define PATH_TSET "path: main/ table settings/\n\n"
# define PATH_SHOW "path: main/ show table settings/\n\n"
# define PATH_PLAY "path: main/ start/\n\n"
# define PATH_INFO "path: main/ info/\n\n"
// layer second
# define PATH_FIELD "path: main/ table settings/ field/\n\n"
# define PATH_PLAYER "path: main/ table settings/ player/\n\n"
# define PATH_BASE "path: main/ table settings/ base/\n\n"
// layer third
# define PATH_PLAYER_N "path: main/ table settings/ player/ number\n\n"
# define PATH_PLAYER_M "path: main/ table settings/ player/ name\n\n"
# define PATH_CUSFIELD "path: main/ table settings/ field/ customize\n\n"

// layer NULL
# define HEAD_MAIN "-->**TicTacToe engine**<--\n\n"
// layer first
# define HEAD_PRED "**Predefined tables**\n\n"
# define HEAD_TSET "**set tables**\n\n"
# define HEAD_SHOW "**Settings**\n\n"
# define HEAD_PLAY "**Run game**\n\n"
# define HEAD_INFO "**Infos/About**\n\n"
// layer second
# define HEAD_FIELD "**Set field**\n\n"
# define HEAD_PLAYER "**Set player**\n\n"
# define HEAD_BASE "**Set base\n\n"
// layer third
# define HEAD_PLAYER_N "\t...under construction...\n\n"
# define HEAD_PLAYER_M "\t...under construction...\n\n"
# define HEAD_CUSFIELD "**Customize field**\n\n"

// layer NULL
# define MENU_MAIN "Menu:\n\n\t[1] play predefined table\n\t[2] table settings\n\t[3] show settings\n\t[4] start\n\t[5] info\n\t[X] exit\n\n"
// layer first
# define MENU_PRED "Options:\n\n\t[1] classic TicTacToe\n\t[2] Four in a row\n\t[3] Four in a row wide\n\t[4] four in a row huge\n\t[5] four in a row wide hex\n\t[X] back\n\n"
# define MENU_TSET "Options:\n\n\t[1] set field\n\t[2] set player\n\t[3] set base\n\t[X] back\n\n"
# define MENU_SHOW "Options:\n\n\t[X] back\n\n"
# define MENU_PLAY "Options:\n\n\t[1] player name\n\t[2] play\n\t[X] back\n\n"
# define MENU_INFO "Options:\n\n\t[X] back\n\n"
// layer second
# define MENU_FIELD "Options:\n\n\t[1] 3 x 3 field\n\t[2] 4 x 5 field\n\t[3] 7 x 7 field\n\t[4] custom field\n\t[X] back\n\n"
# define MENU_PLAYER "Menu:\n\n\t[1] number of players\n\t[2] edit player\n\t[X] back\n\n"
# define MENU_BASE "Options:\n\t[2] Binary Base\n\t[8] Octal Base\n\t[10] Decimal Base\n\t[12] Duodecimal Base\n\t[16] Hexadecimal Base\n\t[X] back\n\n"
// layer third
# define MENU_PLAYER_N "Options:\n\n\t[X] back\n\n"
# define MENU_PLAYER_M "Options:\n\n\t[X] back\n\n"
# define MENU_CUSFIELD "Options:\n\n\t\n\t[1] set lengths (rows)\n\t[2] set width (cols)\n\t[3] set win length\n\t[4] show settings\n\t[X] back\n\n"

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
# define OPT_BASE ((char *[]){"X", NULL})
// layer third
# define OPT_PLAYER_N ((char *[]){"X", NULL})
# define OPT_PLAYER_M ((char *[]){"X", NULL})
# define OPT_CUSFIELD ((char *[]){"X", "1", "2", "3", "4", NULL})

#endif
