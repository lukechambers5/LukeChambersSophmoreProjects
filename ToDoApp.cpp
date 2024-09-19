#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <limits>

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

class ToDoItem {
private:
    int id;
    std::string description;
    bool completed;

public:
    ToDoItem() : id(0), description(""), completed(false) {}
    ~ToDoItem() = default;

    bool create(const std::string& new_description) {
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }

    int getId() const {
        return id;
    }

    std::string getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }

    void setCompleted(bool val) {
        completed = val;
    }
};

void display(const ToDoItem &item) {
    std::string completed = item.isCompleted() ? "\033[32mdone\033[0m" : "\033[33mnot done\033[0m";
    std::cout << item.getId() << " | " << item.getDescription() << " | " << completed << std::endl;
}

int main() {
    char input_op;
    int input_id;
    std::string input_desc;
    std::string version = "v0.2.0";
    std::list<ToDoItem> todoItems;
    std::list<ToDoItem>::iterator it;

    srand(time(NULL));

    while (true) {
        system(CLEAR_COMMAND);  // Platform-independent clearing
        std::cout << "Todo List Maker - " << version << std::endl;
        std::cout << std::endl;

        if (todoItems.empty()) {
            std::cout << "\033[31mAdd your first To Do Item!\033[0m" << std::endl;  // Red for empty state
        } else {
            for (it = todoItems.begin(); it != todoItems.end(); ++it) {
                display(*it);
            }
        }

        std::cout << "\nOptions: [a]dd, [c]omplete, [q]uit\n";
        std::cout << "Choice: ";
        std::cin >> input_op;

        if (input_op == 'q') {
            std::cout << "Ok bye" << std::endl;
            break;
        } else if (input_op == 'c') {
            std::cout << "Enter id to mark complete: ";
            std::cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); ++it) {
                if (input_id == it->getId()) {
                    it->setCompleted(true);
                    break;
                }
            }
        } else if (input_op == 'a') {
            std::cout << "Add a new description: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, input_desc);

            ToDoItem newItem;
            newItem.create(input_desc);
            todoItems.push_back(newItem);
        }
    }

    return 0;
}
