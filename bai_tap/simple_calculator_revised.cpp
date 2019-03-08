//mo app ra -> in ra 0
//su dung ham trong main(tong, hieu, ...) de luyen ve ham
//muon tinh ham sin, cos, nhap f de vao function mode de tinh duoc sin, cos. Arithmetic mode de tinh phep tinh thuong. Memory Mode de su dung m+, m-, ...
//const COSINE = 'c'. const CLEAR = 'c'
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

void add(double &num, double &result);
void subtract(double &num, double &result);
void multiply(double &num, double &result);
void divide(double &num, double &result);
void power(double &num, double &result);
bool checkIfInteger(double num);
// void checkInputValid(double num);
void funcCalculate(double &num, char f_trig);

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
    const char CLEAR_MEMORY = 'c';
    const char SINE = 's';
    const char TANGENT = 't';
    const char REVOKE_MEMORY = 'r';
    const double PI = 3.14159265358979323846; //co san trong c++, ve nha tim 
    //khi nguoi dung nhap p thi gia tri p se thay bang pi?
    //define != const. define la no se tim tat ca su xuat hien cua pi va thay bang 3.14, const thi giong bien.

    char op = '+', tmp_op, cal_mode = 'a', f_trig, prev_op;
    double num;
    double result = 0;
    double memory = 0;
    bool notQuit = true;

    cout << "   =" << result << endl;
    while(notQuit) {
        if (op == A_MODE || op == M_MODE || op == F_MODE) cal_mode = op;
        
        if (cal_mode == 'a') {
            cout << "Mode: A" << endl;
            if (op != '=') prev_op = op;
            cin >> op;
            switch(op) {
                //Math Operation
                case ADD:
                    // cin >> num;
                    // //xu ly loi: neu nhap nham num se =0 lien tuc
                    // result += num;
                    // cout << "   =" << result << endl;
                    add(num, result);
                    break;
                
                case MINUS:
                    subtract(num, result);
                    break;
                
                case MULTIPLY:
                    multiply(num, result);
                    break;

                case DIVIDE:
                    divide(num, result);
                    break;

                case POWER:
                    power(num, result);
                    break;

                case EQUAL:
                    switch(prev_op){
                        case ADD:
                            result += num;
                            break;
                        case MINUS:
                            result -= num;
                            break;
                        case MULTIPLY:
                            result *= num;
                            break;
                        case DIVIDE:
                            result /= num;
                            break;
                        case POWER:
                            result = pow(result, num);
                            break;
                        default:
                            break;
                    }
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

                // //Change Mode
                // case A_MODE:
                //     cal_mode = 'a';
                //     break;

                // case F_MODE:
                //     cal_mode = 'f';
                //     break;

                // case M_MODE:
                //     cal_mode = 'm';
                //     break;

                default:
                    cin.clear();
                    cin.ignore(256, '\n');
                    // cout << "error: unidentified operator" << endl;
                    // exit(EXIT_FAILURE);
                    break;
            }
        }

        else if (cal_mode == 'f') {
            cout << "Mode: F" << endl;
            if (op != '=') prev_op = op; //for EQUAL operator
            cin >> op;
            switch(op) {
                //Math Operation: 1. cho tat ca case vao funcAdd, funcSubtract,... 2. Them if vao ham add, subtract 3. Them phan switch(f_trig) vao funcCheck
                case ADD:
                    cin >> f_trig;
                    cin >> num;
                    if (!cin) {
                        cout << "error: invalid number" << endl;
                        exit(EXIT_FAILURE);
                    }

                    num = num*PI/180;
                    funcCalculate(num, f_trig);
                    result += num;
                    //cout.precision(2); //t180 khong in ra 0 ma in ra so gan 0
                    cout << "   =" << result << endl;
                    break;
                
                case MINUS:
                    cin >> f_trig;
                    cin >> num;
                    if (!cin) {
                        cout << "error: invalid number" << endl;
                        exit(EXIT_FAILURE);
                    }

                    num = num * PI / 180; 
                    funcCalculate(num, f_trig);

                    result -= num;
                    cout << "   =" << result << endl;
                    break;
                
                case MULTIPLY:
                    cin >> f_trig;
                    cin >> num;
                    if (!cin) {
                        cout << "error: invalid number" << endl;
                        exit(EXIT_FAILURE);
                    }

                    num = num*PI/180;
                    funcCalculate(num, f_trig);

                    result *= num;
                    cout << "   =" << result << endl;
                    break;

                case DIVIDE:
                    cin >> f_trig;
                    cin >> num;
                    if (!cin) {
                        cout << "error: invalid number" << endl;
                        exit(EXIT_FAILURE);
                    }

                    num = num*PI/180;
                    funcCalculate(num, f_trig);
                    if (num == 0) {
                        cout << "error: divided by zero" << endl;
                        return 0;
                    }
                    else result /= num;
                    cout << "   =" << result << endl;
                    break;

                case POWER: //chuyen POWER vao f_mode?
                    cin >> f_trig;
                    cin >> num;
                    if (!cin) {
                        cout << "error: invalid number" << endl;
                        exit(EXIT_FAILURE);
                    }

                    num = num*PI/180;
                    funcCalculate(num, f_trig);

                    if ((result == 0 && num <= 0) || (result < 0 && !checkIfInteger(num))){
                        cout << "error: MATH error" << endl;
                        exit(EXIT_FAILURE);
                    }
                    result = pow(result, num);
                    cout << "   =" << result << endl;
                    break;

                case EQUAL:
                    switch(prev_op){
                        case ADD:
                            result += num;
                            break;
                        case MINUS:
                            result -= num;
                            break;
                        case MULTIPLY:
                            result *= num;
                            break;
                        case DIVIDE:
                            result /= num;
                            break;
                        case POWER:
                            result = pow(result, num);
                            break;
                        default:
                            break;
                    }
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
                    
                default:
                    cin.ignore(256, '\n');
                    break;
            }
            
        }

        else if (cal_mode == 'm') {
            cout << "Mode: M" << endl;
            cin >> op;
            switch(op) {
                case ADD:
                    memory += result;
                    cout << "   =" << memory << endl;
                    // cal_mode = 'a';
                    break;
                
                case MINUS:
                    memory -= result;
                    cout << "   =" << memory << endl;
                    break;

                case REVOKE_MEMORY:
                    result = memory;
                    cout << "   =" << result << endl;
                    break;

                case CLEAR_MEMORY:
                    memory = 0;
                    cout << "   =" << memory << endl;
                    break;

                //System
                case QUIT:
                    return 0;
                    
                default:
                    cin.ignore(256, '\n');
                    break;
            }
        }
    }
}

void add(double &num, double &result){
    cin >> num;
    if (!cin) {
        cout << "error: invalid number" << endl;
        exit(EXIT_FAILURE);
    }
    result += num;
    cout << "   =" << result << endl;
}

void subtract(double &num, double &result){
    cin >> num;
    if (!cin) {
        cout << "error: invalid number" << endl;
        exit(EXIT_FAILURE);
    }
    result -= num;
    cout << "   =" << result << endl;
}

void multiply(double &num, double &result){
    cin >> num;
    if (!cin) {
        cout << "error: invalid number" << endl;
        exit(EXIT_FAILURE);
    }
    result *= num;
    cout << "   =" << result << endl;
}

void divide(double &num, double &result){
    cin >> num;
    if (!cin) {
        cout << "error: invalid number" << endl;
        exit(EXIT_FAILURE);
    }
    if (num == 0) {
        cout << "error: divided by zero" << endl;
        exit(EXIT_FAILURE);
    }
    result /= num;
    cout << "   =" << result << endl;
}

void power(double &num, double &result){
    cin >> num;
    if (!cin) {
        cout << "error: invalid number" << endl;
        exit(EXIT_FAILURE);
    }
    if ((result == 0 && num <= 0) || (result < 0 && !checkIfInteger(num))){
        cout << "error: MATH error" << endl;
        exit(EXIT_FAILURE);
    }
    result = pow(result, num);
    cout << "   =" << result << endl;
}

bool checkIfInteger(double num) {
    if (floor(num) == ceil(num)) return true;
    else return false;
}

void funcCalculate(double &num, char f_trig) {
    const char COSINE = 'c';
    const char SINE = 's';
    const char TANGENT = 't';
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
                exit(EXIT_FAILURE);
            } 
            num = sin(num)/cos(num);
            break;

        default: 
            cout << "error: unidentified operator" << endl;
            exit(EXIT_FAILURE);
    }
}
