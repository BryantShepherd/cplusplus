#include <iostream>
#include <string>
using namespace std;
int main() {
    //Chuc nang: AC de reset ket_qua; M+. M-; ham luong giac, ham mu, so pi...
    char prev_operand = '+'; //coi nhu phep tinh la ket_qua = 0 + ...
    char current_operand; //kiem tra xem co dung phep nhan/chia hay khong
    float num_operator;
    float ket_qua = 0;
    do {
        cin >> num_operator;
        
        cin >> current_operand;

        if (current_operand == 'x' || current_operand == '/') { //neu gap phep nhan/chia, tinh ket qua cua phep nhan/chia roi cong/tru vao ket qua chinh.
            char tmp_operand = current_operand;
            float tmp_operator;
            float tmp_ket_qua = num_operator;
            do {
                cin >> tmp_operator;
                if (tmp_operand == 'x') tmp_ket_qua *= tmp_operator;
                else tmp_ket_qua /= tmp_operator;
                cin >> tmp_operand;
            } while (tmp_operand == 'x' || tmp_operand == '/'); //neu tmp_operand la cong hoac tru.

            if (prev_operand == '+' || prev_operand == '-') {
                if (prev_operand == '+') ket_qua += tmp_ket_qua;
                else ket_qua -= tmp_ket_qua;
            }

            if (tmp_operand == '=') break;
            prev_operand = tmp_operand;
            continue;
        }

        if (prev_operand == '+' || prev_operand == '-') {
            if (prev_operand == '+') ket_qua += num_operator;
            else ket_qua -= num_operator;
        }
        cout << "prev: " << prev_operand << ", current: " << current_operand << endl;
        prev_operand = current_operand;
        cout << "Display: " << ket_qua << endl;
    } while (current_operand != '=');
    cout << "The result: " << ket_qua << endl;

}