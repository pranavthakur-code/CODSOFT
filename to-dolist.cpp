#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool iscompleted;
};

vector<Task> Tasklist;

void addTask(){
    Task newTask;
    cout << "Enter task: ";
    cin.ignore(); // To ignore any leftover newline character in the input buffer
    getline(cin, newTask.description);
    newTask.iscompleted = false;
    Tasklist.push_back(newTask);
    cout << "Task added successfully!\n";
}

void viewTasks(){
    if(Tasklist.empty()){
        cout << "No tasks found.\n";
        return;
    }
    cout << "Your Tasks:\n";
    for(size_t i = 0; i < Tasklist.size(); ++i){
        cout << i + 1 << ". " << Tasklist[i].description;
        if(Tasklist[i].iscompleted)
            cout << " [Completed]\n";
        else
            cout << " [Pending]\n";
        }   
              
    }

void markTaskCompleted(){
    int taskNumber;
    viewTasks();


    cout << "Enter task number to mark as completed: ";
    cin >> taskNumber;

    if(taskNumber < 1 || taskNumber >Tasklist.size()){
        cout << "Invalid task number!\n";
        return;
    }

    Tasklist[taskNumber - 1].iscompleted = true;
    cout << "Task marked as completed!\n";
}
void deleteTask(){
    int taskNumber;
    viewTasks();

    cout << "Enter task number to delete: ";
    cin >> taskNumber;

    if(taskNumber < 1 || taskNumber > Tasklist.size()){
        cout << "Invalid task number!\n";
        return;
    }

    Tasklist.erase(Tasklist.begin() + taskNumber - 1);
    cout << "Task deleted successfully!\n";
}
int main(){
    int choice;
    do{
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }while(choice != 5);

    return 0;
}
