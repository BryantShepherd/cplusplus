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
        // void setName(string nameIn) {
        //     name = nameIn;
        // }
        // void setID(int idIn) {
        //     id = idIn;
        // }
        // void setGradDate(int gradDateIn) {
        //     gradDate = gradDateIn;
        // }
        void setData(string nameIn, int idIn, int gradDateIn) {
            name = nameIn;
            id = idIn;
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
    // Student s{"Bryant", 14, 2017}; chi dung cai nay khi bien duoc de public
    // s.setName("bryant");
    Student s;
    s.setData("Bryant", 2518, 18); //khai bao tat ca gia tri cung mot luc
    cout << s.getName() << endl;
    s.print();
    cout << endl;
    Student classA[10];
    for (int i = 0; i < 10; i++) {
        classA[i].setData("Name", i + 100, i + 1000);
        classA[i].print();
        cout << endl;
    }
}