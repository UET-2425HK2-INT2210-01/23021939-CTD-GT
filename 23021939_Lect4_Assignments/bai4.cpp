#include <iostream>
using namespace std;
struct Student {
    int id;
    string name;
    string className;
    Student* next;
};
Student* head = nullptr;
void insertStudent(int id, string name, string className) {
    Student* newStudent = new Student{id, name, className, head};
    head = newStudent;
}
void deleteStudent(int id) {
    Student* current = head;
    Student* prev = nullptr;
    while (current != nullptr && current->id != id) {
        prev = current;
        current = current->next;
    }
    if (current != nullptr) {
        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
    }
}
void inforStudent(int id) {
    cout << "----------" << endl;
    Student* current = head;
    while (current != nullptr) {
        if (current->id == id) {
            cout << current->name << "," << current->className << endl;
            return;
        }
        current = current->next;
    }
    cout << "NA,NA" << endl;
}

void processCommand(string command) {
    if (command.substr(0, 6) == "Insert") {
        int id;
        string name, className;
        char c;
        size_t pos1 = command.find('(') + 1;
        size_t pos2 = command.find(',', pos1);
        id = stoi(command.substr(pos1, pos2 - pos1));
        pos1 = pos2 + 1;
        pos2 = command.find(',', pos1);
        name = command.substr(pos1, pos2 - pos1);
        pos1 = pos2 + 1;
        pos2 = command.find(')', pos1);
        className = command.substr(pos1, pos2 - pos1);
        insertStudent(id, name, className);
    } else if (command.substr(0, 6) == "Delete") {
        int id = stoi(command.substr(7));
        deleteStudent(id);
    } else if (command.substr(0, 5) == "Infor") {
        int id = stoi(command.substr(6));
        inforStudent(id);
    }
}
int main() {
    string command;
    while (getline(cin, command)) {
        processCommand(command);
    }
    return 0;
}
