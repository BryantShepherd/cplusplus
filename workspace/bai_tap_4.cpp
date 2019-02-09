#include <iostream>
#include <string>
using namespace std;
int main() {
    // //co 2 cach lam cai nay, mot la cho string phep tinh day du luon, 2 la nhap tung so va operator vao giong trong calculator
    // float num_operand;
    // char num_operator;
    // float ket_qua = 0;
    // bool first_operand = true;
    // do {
    //     cin >> num_operand;
    //     cout << "Display: " << ket_qua << endl;
    //     cin >> num_operator;
    //     if (num_operator == '+' || num_operator == '-') {
    //         if (num_operator == '+') ket_qua += num_operand;
    //         else if (num_operator == '+') ket_qua -= num_operand;
    //     }
    //     else if (num_operator == 'x' || num_operator == '/') {
    //         break;
    //     }
    //     first_operand = false;
    // } while (num_operator != '=');
    // cout << "The result: " << ket_qua << endl;
    char prev_operand = '+'; //coi nhu phep tinh la ket_qua = 0 + ...
    char current_operand; //kiem tra xem co dung phep nhan/chia hay khong
    float num_operator;
    float ket_qua = 0;
    do {
        cin >> num_operator;
        cout << "Display: " << ket_qua << endl;
        cin >> current_operand;

        if (current_operand == 'x' || current_operand == '/') {
            char tmp_operand = current_operand;
            float tmp_operator;
            float tmp_ket_qua = num_operator;
            do {
                cin >> tmp_operator;
                if (tmp_operand == 'x') tmp_ket_qua *= tmp_operator;
                else tmp_ket_qua /= tmp_operator;
                cin >> tmp_operand;
            } while (tmp_operand == 'x' || tmp_operand == '/'); //neu tmp_operand la cong hoac tru

            if (prev_operand == '+' || prev_operand == '-') {
                if (prev_operand == '+') ket_qua += tmp_ket_qua;
                else ket_qua -= tmp_ket_qua;
            }           
            prev_operand = tmp_operand;
            continue;
        }

        if (prev_operand == '+' || prev_operand == '-') {
            if (prev_operand == '+') ket_qua += num_operator;
            else ket_qua -= num_operator;
        }
        prev_operand = current_operand;
    } while (current_operand != '=');
    cout << "The result: " << ket_qua << endl;

}