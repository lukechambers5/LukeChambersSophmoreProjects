#include <iostream>
#include <string>
#include <list>
#include <ctime>

class ToDoItem{
    private:
        int id;
        std::string description;
        bool completed;
    
    public:
        ToDoItem(): id(0), description(""), completed(false){}
        ~ToDoItem() = default;

        bool create(std::string new_description){
            id = rand() % 100 + 1;
            description = new_description;
            return true;
        }

        int getId() {
            return id;
        }

        std::string getDescription() {
            return description;
        }

        bool isCompleted() {
            return completed;
        }

        void setCompleted(bool val){
            completed = val;
        }
};

int main()
{
    char input_op;
    int input_id;
    std::string input_desc;
    std::string version = "v0.2.0";
    std::list<ToDoItem> todoItems;
    std::list<ToDoItem>::iterator it;

    srand(time(NULL));

    todoItems.clear();

    while(1){
        system("cls");
        std::cout << "Todo List Maker - " << version << std::endl;
        std::cout << std::endl << std::endl;

        for(it = todoItems.begin(); it != todoItems.end(); it++){
            std::string completed = it->isCompleted() ? "done" : "not done";

            std::cout << it->getId() << " | " << it-> getDescription() << " | " << completed << std::endl;
        }

        if(todoItems.empty()){
            std::cout << "Add your first To Do Item!" << std::endl;
        }

        std::cout << std::endl << std::endl;

        std::cout << "[a]dd a new Todo" << std::endl;
        std::cout << "[c]omplete a Todo" << std::endl;
        std:: cout <<"[q]uit" << std::endl;

        std::cout << "Choice: ";
        std::cin >> input_op;

        if(input_op == 'q'){
            std::cout << "Ok bye" << std::endl;
            break;
        }else if(input_op == 'c'){
            std::cout << "Enter id to mark complete: ";
            std::cin >> input_id;

            for(it = todoItems.begin(); it != todoItems.end(); it++){
                if(input_id == it->getId()){
                    it->setCompleted(true);
                    break;
                }
            }
        }else if(input_op == 'a'){
            std::cout << "Add a new description: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, input_desc);

            ToDoItem newItem;
            newItem.create(input_desc);
            todoItems.push_back(newItem);
        }
       
    }

    return 0;
}