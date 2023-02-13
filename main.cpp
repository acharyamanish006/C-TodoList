#include "./include/task.h"

int main()
{
	int current_selection = 0;
	std::vector<std::string> options = {"Add Task", "Show Task", "Delete Task", "Exit"};

	while (true)
	{
		system("cls");
		std::cout << "\t\t\t_________________________MY TODO LIST_______________________________\n\n\n";
		for (int i = 0; i < options.size(); i++)
		{
			if (i == current_selection)
			{
				std::cout << " --> ";
			}
			else
			{
				std::cout << "   ";
			}
			std::cout << options[i] << std::endl;
		}
		int key = getch();

		switch (key)
		{
		case ARROW_UP:
			if (current_selection > 0)
			{
				current_selection--;
			}
			break;
		case ARROW_DOWN:
			if (current_selection < (options.size() - 1))
			{
				current_selection++;
			}
			break;
		case ENTER:
			int choice = current_selection;
			switch (choice)
			{
			case 0:
				system("cls");

				add_task();
				break;
			case 1:
				system("cls");
				show_task();
				system("pause");
				break;
			case 2:
				system("cls");
				show_task();
				delete_task();
				break;
			case 3:
				return 0;
				break;

			default:
				break;
			}
		};
	}

	// std::string choice;
	// std::cout << "\n\n what is your choice: ";
	// std::getline(std::cin, choice);

	return 0;
}
