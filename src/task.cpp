#include "../include/task.h"

void add_task()
{
    std::cout << "\t\t\t_________________________MY TODO LIST_______________________________\n\n\n";
    std::fstream TodoList;
    std::string task;
    std::cout << "\n Enter the task: ";
    std::getline(std::cin, task);
    TodoList.open("todo.txt", std::ios::app);
    if (TodoList.is_open())
    {
        TodoList << task << std::endl;
        TodoList.close();
    }
}
void delete_task()
{
    std::fstream TodoList;
    std::fstream tempTodo;
    std::string deleteValue;
    std::cout << "\n Enter the num of the task you want to delete: ";
    std::getline(std::cin, deleteValue);

    TodoList.open("todo.txt", std::ios::in);
    tempTodo.open("tempTodo.txt", std::ios::app);
    if (TodoList.is_open() && tempTodo.is_open())
    {
        std::string temTask;
        int i = 1;
        while (getline(TodoList, temTask))
        {
            if (stoi(deleteValue) != i)
            {
                tempTodo << temTask << std::endl;
            }
            i++;
        }
    }
    TodoList.close();
    tempTodo.close();
    remove("todo.txt");
    rename("tempTodo.txt", "todo.txt");
}
void show_task()
{
    std::cout << "\t\t\t_________________________MY TODO LIST_______________________________\n\n\n";
    std::fstream TodoList;
    std::cout << "\nHere are your tasks :- \n";
    TodoList.open("todo.txt", std::ios::in);
    if (TodoList.is_open())
    {
        std::string showTask;
        int i = 1;
        while (getline(TodoList, showTask))
        {
            std::cout << i << " : " << showTask << std::endl;
            i++;
        }
        std::cout << std::endl;
        TodoList.close();
    }
}
