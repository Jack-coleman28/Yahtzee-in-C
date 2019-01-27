#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

//DECLARATIONS 
#define NUMOFPLAYERS 2
#define NUMOFCATEGORIES 13
#define NUMOFDICEROLLS NUMOFPLAYERS*NUMOFCATEGORIES

#define dieRow1 "---------"
#define dieRow2 "|       |"
#define dieRow3 "|   *   |"
#define dieRow4 "| *   * |"
#define dieSpace "   "
#define useColor 0

enum colors { black, red, green, yellow, blue, purple, cyan, white, gray };

int roll_index = 0, loop_counter = 1, keep_going = 1; 
int scorecard[NUMOFPLAYERS][NUMOFCATEGORIES + 1];
int dice[5][2]; 
char player_names[NUMOFPLAYERS][50];

void start_player_turn_print_name(void);
void play_game(void);
void reset_scorecard();
void reset_dice();
void reset_player_names();
void get_player_names(char player_names[2][50]);
void key_when_ready();
int roll_again_yn();
int select_score_category(int scorecard[]);
void game_menu(void);
void text_color(i);
void back_color(i);
void print_dice(int d[5][2]);
int get_value_count(int d[5][2], int i);
int get_total_dice_vals(int d[5][2]);
void score_dice(int d[5][2], int category, int l4_scorecard[NUMOFPLAYERS][NUMOFCATEGORIES + 1]);
int get_score_card_total(int l3_scorecard[NUMOFPLAYERS][NUMOFCATEGORIES + 1], int l_player_index);
void print_category(int l2_scorecard[NUMOFPLAYERS][NUMOFCATEGORIES + 1]);
void prompt_which_dice_keep(int d[5][2]);
void roll_dice(int d[5][2]);
void determine_winning_player(int l5_scorecard[NUMOFPLAYERS][NUMOFCATEGORIES + 1]);

#endif
