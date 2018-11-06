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
<<<<<<< HEAD
    // Student s{"Bryant", 14, 2017};
    s.setName("bryant");
=======
    // Student s{"Bryant", 14, 2017}; chi dung cai nay khi bien duoc de public
    // s.setName("bryant");
    Student s;
    s.setData("Bryant", 2518, 18); //khai bao tat ca gia tri cung mot luc
>>>>>>> 4b14f3b9861686129e6fa637493b0b9dfcc7034c
    cout << s.getName() << endl;
    s.print();
}