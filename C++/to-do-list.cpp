#include <iostream>
#include <string>
#include <vector>

class task
{
    private:
    std::vector<std::string> task_m{};

    public:
    void add_task()
    {
        std::string task_new{};
        std::cout << "\nEnter the new task to add: ";
        std::cin.ignore();
        std::getline(std::cin, task_new);
        task_m.push_back(task_new);
    }

    ~task()
    {
        std::cout << "\ntasks cleared" << std::endl;
    }

    void delete_task()
    {
        int position{};
        std::cout << "\nEnter the task number to delete: ";
        std::cin >> position;
        if(position > 0 && position <= static_cast<int>(task_m.size())){
        task_m.erase(task_m.begin() + (position - 1));
        }
        else{
            std::cout << "Invalid task number." << std::endl;
        }
    }
    
    void print_all()
    {
    if (task_m.empty()) {
            std::cout << "\nNo tasks to display." << std::endl;
            return;
        }
        std::cout << "\nTask list: " << std::endl;
        for (size_t i = 0; i < task_m.size(); ++i) {
            std::cout << i + 1 << ") " << task_m[i] << std::endl;
        }
    }

    void menu()
    {
        int input{};
        std::cout << "1=Add, 2=Delete, 3=View tasks, Any other number to Quit."<< std::endl;
        std::cin >> input;
        switch (input)
        {
        case 1:
            add_task();
            break;

        case 2:
            delete_task();
            break;

        case 3:
            print_all();
            break;
        
        default:
            std::cout << "Exiting program." << std::endl;
            exit(0);
        }

    }
};

int main(){

    task task_one{};
    std::cout << "To do list app." << std::endl;
    while(true){
    task_one.menu();
    }

    return 0;

}