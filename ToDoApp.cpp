#include <iostream>
#include <string>
#include <list>
#include <ctime>
<<<<<<< HEAD
#include <limits>

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif
=======
>>>>>>> 78cd6459343acc4b6988bb0b250309fa2e038afc

class ToDoItem{
    private:
        int id;
        std::string description;
        bool completed;
    
    public:
        ToDoItem(): id(0), description(""), completed(false){}
        ~ToDoItem() = default;

<<<<<<< HEAD
        bool create(const std::string& new_description){
=======
        bool create(std::string new_description){
>>>>>>> 78cd6459343acc4b6988bb0b250309fa2e038afc
            id = rand() % 100 + 1;
            description = new_description;
            return true;
        }

<<<<<<< HEAD
        int getId() const {
            return id;
        }

        std::string getDescription() const {
            return description;
        }

        bool isCompleted() const {
=======
        int getId() {
            return id;
        }

        std::string getDescription() {
            return description;
        }

        bool isCompleted() {
>>>>>>> 78cd6459343acc4b6988bb0b250309fa2e038afc
            return completed;
        }

        void setCompleted(bool val){
            completed = val;
        }
};

<<<<<<< HEAD
void display(const ToDoItem &item){
    std::string completed = item.isCompleted() ? "\033[32mdone\033[0m" : "\033[33mnot done\033[0m";
    std::cout << item.getId() << " | " << item.getDescription() << " | " << completed << std::endl;
}

=======
>>>>>>> 78cd6459343acc4b6988bb0b250309fa2e038afc
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
<<<<<<< HEAD
        system(CLEAR_COMMAND);  // Platform-independent clearing
        std::cout << "Todo List Maker - " << version << std::endl;
        std::cout << std::endl << std::endl;

        if (todoItems.empty()) {
            std::cout << "\033[31mAdd your first To Do Item!\033[0m" << std::endl;  // Red for empty state
        } else {
            for (it = todoItems.begin(); it != todoItems.end(); it++) {
                display(*it);
            }
        }

        std::cout << "\n\nOptions: [a]dd, [c]omplete, [e]dit, [d]elete, [q]uit\n";
=======
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

>>>>>>> 78cd6459343acc4b6988bb0b250309fa2e038afc
        std::cout << "Choice: ";
        std::cin >> input_op;

        if(input_op == 'q'){
            std::cout << "Ok bye" << std::endl;
            break;
<<<<<<< HEAD
        } else if(input_op == 'c'){
=======
        }else if(input_op == 'c'){
>>>>>>> 78cd6459343acc4b6988bb0b250309fa2e038afc
            std::cout << "Enter id to mark complete: ";
            std::cin >> input_id;

            for(it = todoItems.begin(); it != todoItems.end(); it++){
                if(input_id == it->getId()){
                    it->setCompleted(true);
                    break;
                }
            }
<<<<<<< HEAD
        } else if(input_op == 'a'){
            std::cout << "Add a new description: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
=======
        }else if(input_op == 'a'){
            std::cout << "Add a new description: ";
            std::cin.clear();
            std::cin.ignore();
>>>>>>> 78cd6459343acc4b6988bb0b250309fa2e038afc
            std::getline(std::cin, input_desc);

            ToDoItem newItem;
            newItem.create(input_desc);
            todoItems.push_back(newItem);
        }
<<<<<<< HEAD
    }

    return 0;
}
=======
       
    }

    return 0;
}
>>>>>>> 78cd6459343acc4b6988bb0b250309fa2e038afc
