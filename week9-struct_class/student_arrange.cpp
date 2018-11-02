#include <iostream>
#include <string>
using namespace std;
class Student {
    string name;
    unsigned int id;
    int gradDate;

    public:
        void setName(string nameIn) {
            nameIn = name;
        }
        void setID(int idIn) {
            idIn = id;
        }
        void setGradDate(int gradDateIn) {
            gradDateIn = gradDate;
        }
        string getName() {
            return name;
        }
        int getID() {
            return id;
        }
        int getGradDate() {
            return gradDate;
        }
        void print() {
            cout << name << " " << id << " " << gradDate;
        }
};

int main() {
    Student s;
    s.setName("bryant");
}