#include <iostream>
#include <sstream>

using namespace std;

const int TABLE_SIZE = 10007;

struct Student {
    int ID;
    string Name;
    string Class;
    Student* next;

    Student(int id, string name, string class_name) 
        : ID(id), Name(name), Class(class_name), next(nullptr) {}
};

class StudentManager {
private:
    Student* studentTable[TABLE_SIZE];

    int hashFunction(int ID) {
        return ID % TABLE_SIZE;
    }

public:
    StudentManager() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            studentTable[i] = nullptr;
        }
    }

    void insert(int ID, const string& Name, const string& Class) {
        int index = hashFunction(ID);
        Student* newStudent = new Student(ID, Name, Class);

        if (!studentTable[index]) {
            studentTable[index] = newStudent;
            return;
        }

        Student* current = studentTable[index];
        while (current) {
            if (current->ID == ID) {
                current->Name = Name;
                current->Class = Class;
                delete newStudent;
                return;
            }
            if (!current->next) break;
            current = current->next;
        }
        current->next = newStudent;
    }

    void remove(int ID) {
        int index = hashFunction(ID);
        Student* current = studentTable[index];
        Student* prev = nullptr;

        while (current) {
            if (current->ID == ID) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    studentTable[index] = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    string infor(int ID) {
        int index = hashFunction(ID);
        Student* current = studentTable[index];

        while (current) {
            if (current->ID == ID) {
                return current->Name + "," + current->Class;
            }
            current = current->next;
        }
        return "NA,NA";
    }
};

int main() {
    StudentManager manager;
    string line;

    while (getline(cin, line)) {
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "Insert") {
            int ID;
            string Name, Class;
            ss >> ID;
            ss.ignore();
            getline(ss, Name, ' ');
            getline(ss, Class);
            manager.insert(ID, Name, Class);
        } 
        else if (command == "Delete") {
            int ID;
            ss >> ID;
            manager.remove(ID);
        } 
        else if (command == "Infor") {
            int ID;
            ss >> ID;
            cout << manager.infor(ID) << endl;
        }
    }

    return 0;
}
