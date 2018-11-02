#include <iostream>
#include <string>
using namespace std;
class Student {
    //private: class se auto de la private nen khong can ghi.
    //bien la private nen khong the khai bao nhu struct(Student{"name",  id, gradDate}), ma phai dung ham de gan gia tri cho bien
    string name; 
    unsigned int id;
    int gradDate;

    public:
        void setName(string nameIn) {
            name = nameIn;
        }
        void setID(int idIn) {
            id = idIn;
        }
        void setGradDate(int gradDateIn) {
            gradDate = gradDateIn;
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

//co the prototype define ham o trong class va sau do dinh nghia ham o ben ngoai
// void Student:: setName(string nameIn) { --> can co them Student::
//     name = nameIn;
// }
int main() {
    // Student s{"Bryant", 14, 2017};
    s.setName("bryant");
    cout << s.getName() << endl;
}