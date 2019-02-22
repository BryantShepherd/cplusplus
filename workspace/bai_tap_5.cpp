//mo app ra -> in ra 0
//su dung ham trong main(tong, hieu, ...) de luyen ve ham
//muon tinh ham sin, cos, nhap f de vao function mode de tinh duoc sin, cos. Arithmetic mode de tinh phep tinh thuong. Memory Mode de su dung m+, m-, ...
//const COSINE = 'c'. const CLEAR = 'c'
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;
int main() {
    const char ADD  = '+';
    const char MINUS = '-';
    const char MULTIPLY = '*';
    const char DIVIDE = '/';
    const char POWER = '^';
    const char EQUAL = '=';
    const char A_MODE = 'a';
    const char F_MODE = 'f';
    const char M_MODE = 'm';
    const char QUIT = 'q';
    const char CLEAR = 'c';
    const char COSINE = 'c';
    const char SINE = 's';
    const char TANGENT = 't';
    const double PI = 3.14159265358979323846; //co san trong c++, ve nha tim 
    //khi nguoi dung nhap p thi gia tri p se thay bang pi?
    //define != const. define la no se tim tat ca su xuat hien cua pi va thay bang 3.14, const thi giong bien.

    char op = '+', tmp_op, cal_mode = 'a', f_trig;
    float num;
    float result = 0;
    float memory = 0;
    bool notQuit = true;
    bool luot_dau = false;

    cout << "   =" << result << endl;
    while(notQuit) {
        if (cal_mode == 'a') {
            // if (luot_dau == false) {
            //     luot_dau == true;
            // }
            // else cin >> op;
            cout << "Mode: A" << endl;
            cin >> op;
            switch(op) {
                //Math Operation
                case ADD:
                    cin >> num;
                    //xu ly loi: neu nhap nham num se =0 lien tuc
                    result += num;
                    cout << "   =" << result << endl;
                    break;
                
                case MINUS:
                    cin >> num;
                    result -= num;
                    cout << "   =" << result << endl;
                    break;
                
                case MULTIPLY:
                    cin >> num;
                    result *= num;
                    cout << "   =" << result << endl;
                    break;

                case DIVIDE:
                    cin >> num;
                    if (num == 0) {
                        cout << "error: divided by zero" << endl;
                        return 0;
                    }
                    else result /= num;
                    cout << "   =" << result << endl;
                    break;

                case POWER:
                    cin >> num;
                    result = pow(result, num);
                    cout << "   =" << result << endl;
                    break;
                
                //System
                case QUIT:
                    return 0;
                
                case CLEAR: 
                    system("cls");
                    result = 0;
                    cout << "   =" << result << endl;
                    break;

                //Change Mode
                case A_MODE:
                    cal_mode = 'a';
                    break;

                case F_MODE:
                    cal_mode = 'f';
                    break;

                case M_MODE:
                    cal_mode = 'm';
                    break;

                default:
                    cout << "error: unidentified operator" << endl;
                    break;
            }
        }

        else if (cal_mode == 'f') {
            cout << "Mode: F" << endl;
            cin >> op;
            switch(op) {
                //Math Operation
                case ADD:
                    cin >> f_trig;
                    cin >> num;
                    num = num*PI/180;
                    switch(f_trig){
                        case SINE:
                            num = sin(num);
                            break;
                        case COSINE:
                            num = cos(num);
                            break;
                        
                        case TANGENT:
                            if (cos(num) == 0) {
                                cout << "error: divided by zero" << endl;
                                return 0;
                            } 
                            num = sin(num)/cos(num);
       
                    }
                    //xu ly loi: neu nhap nham num se =0 lien tuc
                    result += num;
                    // cout.precision(2); t180 khong in ra 0 ma in ra so gan 0
                    cout << "   =" << result << endl;
                    break;
                
                case MINUS:
                    cin >> f_trig;
                    cin >> num;
                    num = num * PI / 180; 
                    switch(f_trig){
                        case SINE:
                            num = sin(num);
                            break;

                        case COSINE:
                            num = cos(num);
                            break;
                        
                        case TANGENT:
                            if (cos(num) == 0) {
                                cout << "error: divided by zero" << endl;
                                return 0;
                            } 
                            num = sin(num)/cos(num);
       
                    }

                    result -= num;
                    cout << "   =" << result << endl;
                    break;
                
                case MULTIPLY:
                    cin >> f_trig;
                    cin >> num;
                    num = num*PI/180;
                    switch(f_trig){
                        case SINE:
                            num = sin(num);
                            break;

                        case COSINE:
                            num = cos(num);
                            break;
                        
                        case TANGENT:
                            if (cos(num) == 0) {
                                cout << "error: divided by zero" << endl;
                                return 0;
                            } 
                            num = sin(num)/cos(num);
       
                    }

                    result *= num;
                    cout << "   =" << result << endl;
                    break;

                case DIVIDE:
                    cin >> f_trig;
                    cin >> num;
                    num = num*PI/180;
                    switch(f_trig){
                        case SINE:
                            num = sin(num);
                            break;

                        case COSINE:
                            num = cos(num);
                            break;
                        
                        case TANGENT:
                            if (cos(num) == 0) {
                                cout << "error: divided by zero" << endl;
                                return 0;
                            } 
                            num = sin(num)/cos(num);
                    }

                    if (num == 0) {
                        cout << "error: divided by zero" << endl;
                        return 0;
                    }
                    else result /= num;
                    cout << "   =" << result << endl;
                    break;

                case POWER:
                    cin >> f_trig;
                    cin >> num;
                    num = num*PI/180;
                    switch(f_trig){
                        case SINE:
                            num = sin(num);
                            break;

                        case COSINE:
                            num = cos(num);
                            break;
                        
                        case TANGENT:
                            if (cos(num) == 0) {
                                cout << "error: divided by zero" << endl;
                                return 0;
                            } 
                            num = sin(num)/cos(num);
       
                    }
                    //xu ly loi: result khong ra ket qua
                    result = pow(result, num);
                    cout << "   =" << result << endl;
                    break;
                
                //System
                case QUIT:
                    return 0;

                case CLEAR: 
                    system("cls");
                    result = 0;
                    cout << "   =" << result << endl;
                    break;

                //Change Mode
                case A_MODE:
                    cal_mode = 'a';
                    break;

                case F_MODE:
                    cal_mode = 'f';
                    break;

                case M_MODE:
                    cal_mode = 'm';
                    break;
                    
                default:
                    cout << "error: unidentified operator" << endl;
                    break;
            }
            
        }

        else if (cal_mode == 'm') {
            cout << "Mode: M" << endl;
            cin >> op;
            // switch(op) {

            // }
        }
    }
}


