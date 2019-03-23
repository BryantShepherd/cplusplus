#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <limits>
#include <fstream>

using namespace std;

const char SAVE = '1';
const char DISPLAY = '2';
const char REMOVE = '3';
const char FIND = '4';
const char EDIT ='5';
const char LOAD ='6';
const char STORE ='7';
const char GROUP ='8';

struct Person{
    long long id = 0;
    string name;
    string phone_number;

//    long long id_upper(List& listContact){
//        id = listContact.size()+1;
//        return id;
//    }
};



typedef vector <Person> List;




void print_contact(Person person){
    cout << person.name << endl;
    cout << person.phone_number << endl;
    return ;
}

void find_by_name(List& listContact){
    string name_to_find;
    cout << "Moi nhap ten lien he: " << endl;
    cin.ignore();
    getline(cin, name_to_find);
    for(int i=0; i<listContact.size(); i++){
        if(listContact[i].name.find(name_to_find) != string::npos){
            cout << "ID cua lien he:" << i+1 << endl;
            print_contact(listContact[i]);
        }
    }
    }
void find_by_phone_number(List& listContact){
    string phone_number_to_find;
    cout << "Moi nhap so dien thoai: " << endl;
    cin.ignore();
    getline(cin, phone_number_to_find);
    for(int i=0; i<listContact.size(); i++){
        if(listContact[i].phone_number.find(phone_number_to_find) != string::npos){
            cout << "ID cua lien he:" << i+1 << endl;
            print_contact(listContact[i]);
    }
}}

void add(List& listContact){
    Person tmp;
    int dem = 0;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Moi nhap ten lien he: " << endl;
    getline(cin, tmp.name);
    cout << "Moi nhap so dien thoai: " << endl;
    getline(cin, tmp.phone_number);
    for(int i=0; i<listContact.size(); i++){
        if(tmp.phone_number == listContact[i].phone_number){
            cout << "So dien thoai da ton tai!" << endl;
            dem++;
            break;
        }}
    if(dem == 0){
        tmp.id = listContact.size() + 1;
        listContact.push_back(tmp);
        cout << "ID cua lien he: " << tmp.id << endl;
        cout << "Lien he da duoc luu thanh cong!" << endl;
    }
    return ;
}

void print(List& listContact){
    for(const auto& person: listContact)
    {
        cout << "ID: ";
        cout << person.id << endl;
        cout << person.name << endl;
        cout << person.phone_number << endl;
    }

    return ;
}

void deleteContact(List& listContact){
    print(listContact);
    long long id_to_delete = 0;
    cout << "Nhap ID can xoa: " << endl;
    cin >> id_to_delete;
    listContact.erase(listContact.begin() + id_to_delete-1);
}




int main()
{
    List listContact(0);
    char flag;
    bool notQuit = true;

    while(notQuit){
        cin >> flag;
        switch(flag){
            case SAVE:
                cout << "NHAP" << endl;
                add(listContact);
                break;

            case DISPLAY:
                cout << "IN" << endl;
                print(listContact);
                break;

            case REMOVE:
                cout << "XOA" << endl;
                deleteContact(listContact);
                break;
            case FIND:
                cout << "TIM" << endl;
                int selection;
                cin >> selection;
                switch(selection){
                    case 1:
                        find_by_name(listContact);
                        break;
                    case 2:
                        find_by_phone_number(listContact);
                        break;
                    default:
                        break;}
            default :
                break;
        }}
    return 0;
}
