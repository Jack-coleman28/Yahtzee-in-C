//////////////////////////////////////////////////////////////////////////////////
// Company: WSU CPTS 121
// Programmer: Jack    
// 
// Create Date: 10/12/2018 
// Design Name: Programming Assignment 05
// Project Name: PA05_
// Description: 
// Revision: Revised to clean up. 
// Additional Comments: 6th version. 					
//////////////////////////////////////////////////////////////////////////////////

enum game_statuses { READY, RULES, PLAYGAME, EXIT };

int main(void)
{
	srand((unsigned int)time(0));
	int main_loop_status = READY;
	while (main_loop_status < EXIT)
	{

		//call DoMainMenu()
		game_menu();//Print Options	
		//system("cls");//Clear Screen
		main_loop_status = get_selection_option();//Get Input Choice(1, 2, 3), set mainLoopStatus
		system("cls");
		switch (main_loop_status)//SWITCH thru Input Choice
		{
		case RULES://RULES
			print_rules();//call PrintRules()
			break;
		case PLAYGAME://PLAYGAME
			play_game();//call PlayGame()
			system("cls");//check 
			break;
		case EXIT:
			printf("\n               Thanks for playing!\n\n");
			//main_loop_status = EXIT;
			break;
		}	
	}
	return 0; 
}
