#include "game.h"

void play_game()
{	
	//INITIALIZATIONS
	reset_scorecard(scorecard[NUMOFPLAYERS][NUMOFCATEGORIES + 1]);
	reset_dice(dice[5][2]);
	reset_player_names(player_names[NUMOFPLAYERS][50]);
	get_player_names(player_names);

	for (roll_index = 0; roll_index < NUMOFDICEROLLS; roll_index++)
	{
		start_player_turn_print_name();

		loop_counter = 1;
		keep_going = 1;
		
		key_when_ready(); 		
		reset_dice(dice[5][2]);

		while (loop_counter <= 3 && keep_going == 1)
		{
			roll_dice(dice);

			if (loop_counter < 3 && (keep_going = roll_again_yn()) == 1)
				prompt_which_dice_keep(dice);
			else				
				score_dice(dice, select_score_category(scorecard), scorecard); 			
			loop_counter++;
		} //End dice roll Loop
	} //End roll index for loop
	determine_winning_player(scorecard);
}

void determine_winning_player(int l5_scorecard[NUMOFPLAYERS][NUMOFCATEGORIES + 1])
{
	printf("%s score: %d\n", player_names[0], get_score_card_total(l5_scorecard, 0));  
	printf("%s score: %d\n", player_names[1], get_score_card_total(l5_scorecard, 1));  
	if (get_score_card_total(l5_scorecard, 0) > get_score_card_total(l5_scorecard, 1))
		printf("%s is the winner!", player_names[0]); 
	else if (get_score_card_total(l5_scorecard, 0) < get_score_card_total(l5_scorecard, 1))
		printf("%s is the winner!", player_names[1]); 
	else if (get_score_card_total(l5_scorecard, 0) == get_score_card_total(l5_scorecard, 1))
		printf("Its a tie!");
	Sleep(5000);
	return; 
}

void roll_dice(int d[5][2])
{	
	for (int animate = 0; animate < 3; animate++)
		for (int r = 0; r < 5; r++)
		{
			if (d[r][1] == 0)
			{
				d[r][0] = (rand() % 6) + 1;
			}
			print_dice(d);
			Sleep(70);
		}
	return;
}

void start_player_turn_print_name()
{	
	system("cls");
	printf("Hi %s, it is now your turn. \n", player_names[(roll_index % 2)]);
	return; 
}

void reset_scorecard(int l_scorecard[NUMOFPLAYERS][NUMOFCATEGORIES + 1]) //memory fix
{
	for (int i = 0; i < NUMOFPLAYERS; i++)
	{
		for (int j = 0; j < NUMOFCATEGORIES + 1; j++)
		{
			scorecard[i][j] = -1; // -1 means unused category 
		}
	}
	return; 
}//INITIALIZATION

void reset_dice(int l_d[5][2]) //memory fix
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			dice[i][j] = 0;
		}
	}
	return;
}//INITIALIZATION

void reset_player_names(int l_player_names[NUMOFPLAYERS][50]) //memory fix
{
	player_names[1][0] = " ";
	player_names[2][0] = " ";
	return;
}//INITIALIZATION

void get_player_names(char player_names[2][50])
{
	printf("\nInput player 1 name: ");
	scanf("%s", ((char*)player_names[0]));
	printf("\nInput player 2 name: ");
	scanf("%s", ((char*)player_names[1]));
}

void key_when_ready()
{
	int exit = 0;
	printf("\nPress ( 1 ) to roll.\n");
scanf("%d", &exit);
return;
}

int roll_again_yn()
{
	int i = 0;

	while (i < 1 || i > 2)
	{
		printf("Do you want to roll again (1: YES / 2: NO) ?    ");
		scanf("%d", &i);
	}
	return (i == 2) ? (0) : (1);
}

void prompt_which_dice_keep(int d[5][2])
{
	int num = 0, tens = 10000;
		
	for (int k = 0; k < 5; k++)
		dice[k][1] = 0;

	printf("\nWhich Dice To Keep: ");
	scanf("%ld", &num);

	for (int m = 1; m < 6; m++)
	{
		if (((num / tens) <= 5) || ((num / tens) >= 1))
			d[(num / tens) - 1][1] = 1;
		num = num - (tens * (num / tens));
		tens = tens / 10;
	}
	return;
}

int select_score_category(int l_scorecard[NUMOFPLAYERS][NUMOFCATEGORIES + 1])
{
	int category_select = 0;

	while (category_select == 0)
	{
		system("cls");
		print_dice(dice);
		print_category(l_scorecard); 
		printf("\n Choose a category, between 1 and 13: "); 
		scanf("%d", &category_select);
		if (category_select < 1 || category_select > 13)
			category_select = 0; 
		if (l_scorecard[roll_index % 2][category_select - 1] != -1) 
			category_select = 0;
	}
	return category_select;
}

void game_menu(void)
{
	printf(" *****************************************************************************************************************\n");
	printf(" *                                            Welcome to Yahtzee                                                 *\n");
	printf(" *                                             A game of dice!                                                   *\n");
	printf(" *                                                                                                               *\n");
	printf(" *                       Select your option below                                                                *\n");
	printf(" *                                                                                                               *\n");
	printf(" *                       1: Rules of the game                                                                    *\n");
	printf(" *                       2: Start game                                                                           *\n");
	printf(" *                       3: Exit game                                                                            *\n");
	printf(" *                                                                                                               *\n");
	printf(" *****************************************************************************************************************\n");
}

void print_category(int l2_scorecard[NUMOFPLAYERS][NUMOFCATEGORIES + 1])
{
	for (int i = 0; i < NUMOFCATEGORIES + 1; i++)
	{
		switch (i + 1) {
		case 1:		printf(" 1. Sum of 1's:      ");  break;
		case 2:		printf(" 2. Sum of 2's:      ");  break;
		case 3:		printf(" 3. Sum of 3's:      ");  break;
		case 4:		printf(" 4. Sum of 4's:      ");  break;
		case 5:		printf(" 5. Sum of 5's:      ");  break;
		case 6:		printf(" 6. Sum of 6's:      ");  break;
		case 7:		printf(" 7. Three-of-a-kind: ");  break;
		case 8:		printf(" 8. Four-of-a-kind:  ");  break;
		case 9:		printf(" 9. Full House:      ");  break;
		case 10:	printf("10. Small straight:  ");  break;
		case 11:	printf("11. Large straight:  ");  break;
		case 12:	printf("12. Yahtzee:         ");  break;
		case 13:	printf("13. Chance:          ");  break;
		case 14:	printf("Dice (1 - 6) Bonus   ");  break;
		}
		(l2_scorecard[roll_index % 2][i] == -1) ?
			printf("Score =\n") : printf("Score = %d\n", (l2_scorecard[roll_index % 2][i])); //scoring print fix
	}
	printf("Scorecard Total = %d\n", get_score_card_total(l2_scorecard, (roll_index % 2)));
	return;

}

int get_score_card_total(int l3_scorecard[NUMOFPLAYERS][NUMOFCATEGORIES + 1], int l_player_index)
{
	int l_num = 0; 

	for (int i = 0; i < 15; i++)
	{
		l_num = l_num + ((l3_scorecard[l_player_index][i] == -1) ? (0) : (l3_scorecard[l_player_index][i]));
	}
	return l_num; 
}

void text_color(i)
{
	printf("%c[%dm", 0x1B, i + 30);
}

void back_color(i)
{
	printf("%c[%dm", 0x1B, i + 40);
}

void print_dice(int d[5][2])
{
	system("cls");

	/*printf("\n");
	text_color(black);
	back_color(white);*/

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (useColor)
			{
				text_color(black);
				back_color(white);
			}
			switch (i)
			{
			case 0:
			case 4:
				printf("%s", dieRow1);
				break;
			case 1:
			case 3:
				switch (d[j][0])
				{
				case 1: printf("%s", dieRow2);  break;
				case 2:
				case 3: printf("%s", dieRow3);  break;
				case 4:
				case 5:
				case 6: printf("%s", dieRow4);  break;
				default: printf(" ");
				}
				break;
			case 2:
				switch (d[j][0])
				{
				case 1:
				case 3:
				case 5: printf("%s", dieRow3);  break;
				case 2:
				case 4: printf("%s", dieRow2);  break;
				case 6: printf("%s", dieRow4);  break;
				default: printf(" ");
				}
				break;
			default:
				printf("WHOOPS");
			} //Switch mark
			if (useColor)
				back_color(black);
			printf("%s", dieSpace);
		}  //Die loop
		printf("\n"); //Back to the first column
		if (useColor)
			back_color(black);
	}  //Row loop
	if (useColor)
		text_color(white);
	
	/*printf("\n");
	text_color(white);
	back_color(black);*/

	printf("    1           2           3           4           5\n");

	return;
}

int get_value_count(int d[5][2], int i)
{
	int count = 0;
	for (int a = 0; a < 5; a++)
		if (d[a][0] == i)
			count++;
	return count;
}

int get_total_dice_vals(int d[5][2])
{
	int total = 0;
	for (int b = 0; b < 5; b++)
		total = total + d[b][0];
	return total;
}

void score_dice(int d[5][2], int category, int l4_scorecard[NUMOFPLAYERS][NUMOFCATEGORIES + 1])
{
	int x = category, score = 0;

	switch (x)	//Category
	{
	case 13:  //Chance
		score = get_total_dice_vals(d);
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		score = (x * get_value_count(d, x));
		if ((scorecard[roll_index % 2][0] + scorecard[roll_index % 2][1] + 
			scorecard[roll_index % 2][2] + scorecard[roll_index % 2][3] + 
			scorecard[roll_index % 2][4] + scorecard[roll_index % 2][5]) >= 63)
		{
			scorecard[roll_index % 2][13] = 35;//Bonus assignment
		}
		break;
	case 7:  //Three of a kind
	case 8:  //Four of a kind
	case 12: //Yahtzee 
		for (int y= 1; y < 7; y++)
			if ((x == 7 && get_value_count(d, y) > 2) //Three of a kind
				|| (x == 8 && get_value_count(d, y) > 3) //Four of a kind
				|| (x == 12 && get_value_count(d, y) > 4)) //Five of a kind
			{
				score = (x == 12) ? (50) : (get_total_dice_vals(d));
				y = 7;  //Force to leave early
			}
		break;
	case 9:  //Full house
		for (int y = 1; y < 7; y++)
			if (get_value_count(d, y) > 2) //Three of a kind
				for (int z = 1; z < 7; z++)
					if ((y != z) && (get_value_count(d, z) > 1))
					{
						score = 25;
						z = 7;  //Force to leave early
					}
		break;
	case 10:  //Small staight
		if (((get_value_count(d, 1) > 0)
			&& (get_value_count(d, 2) > 0)
			&& (get_value_count(d, 3) > 0)
			&& (get_value_count(d, 4) > 0)
			)
			||
			((get_value_count(d, 2) > 0)
			&& (get_value_count(d, 3) > 0)
			&& (get_value_count(d, 4) > 0)
			&& (get_value_count(d, 5) > 0)
			)
			||
			((get_value_count(d, 3) > 0)
			&& (get_value_count(d, 4) > 0)
			&& (get_value_count(d, 5) > 0)
			&& (get_value_count(d, 6) > 0)
			))
			score = 30;
		break;
	case 11:  //Large straight
		if (((get_value_count(d, 1) > 0)
			&& (get_value_count(d, 2) > 0)
			&& (get_value_count(d, 3) > 0)
			&& (get_value_count(d, 4) > 0)
			&& (get_value_count(d, 5) > 0)
			)
			||
			((get_value_count(d, 2) > 0)
			&& (get_value_count(d, 3) > 0)
			&& (get_value_count(d, 4) > 0)
			&& (get_value_count(d, 5) > 0)
			&& (get_value_count(d, 6) > 0)
			))
			score = 40;
		break;
	default:
		score = -1;
		break;
	} //Switch mark
	l4_scorecard[roll_index % 2][x - 1] = score;
	return;
}

void print_rules(void)
{
	int exit = 0;

	printf("*******************************************************************************************************************************\n\n");
	printf(" > Rules to Yahtzee                                                                                                           *\n");
	printf(" - The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section.                           *\n");
	printf(" - A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.                               *\n");
	printf(" - The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.        *\n");
	printf(" - If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.                       *\n");
	printf(" - Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. *\n");
	printf(" - If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are                      *\n");
	printf("   added to the players overall score as a bonus.                                                                             *\n");
	printf(" - The lower section contains a number of poker like combinations.                                                            *\n\n");
	printf("*******************************************************************************************************************************\n\n");

	printf(" Think you got it? (Press 1)\n", exit);
	scanf("%d", &exit);

	system("cls");

	return;
}

int get_selection_option()
{
	int selection = 0;

	scanf("%d", &selection);

	return selection;
}
