//mo app ra -> in ra 0
//su dung ham trong main(tong, hieu, ...) de luyen ve ham
//muon tinh ham sin, cos, nhap f de vao function mode de tinh duoc sin, cos. Arithmetic mode de tinh phep tinh thuong. Memory Mode de su dung m+, m-, ...
//const COSINE = 'c'. const CLEAR = 'c'
#include <iostream>
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

    char op = '+', tmp_op, prev_op;
    float num, prev_num;
    float result = 0;
    float memory = 0;
    do {
        prev_num = num;
        if(op != 'm') cin >> num;
        switch(op) {
            case ADD:{
                result+=num;
                break;
            }
            case MINUS:{
                result-=num;
                break;
            }
            case MULTIPLY:{
                result*=num;
                break;
            }
            case DIVIDE:{
                result/=num;
                break;
            }
            case POWER:{
                result = pow(result, num);
                break;
            }
            // case EQUAL:{
            //     break;
            // }
//            case 'm': {
//                char tmp_op;
//                cin >> tmp_op;
//                if (tmp_op == '+') memory+=num;
//                else if (tmp_op == '-') memory-=num;
//            }

        }
        cout << "=" << result << endl;
        prev_op = op;
        cin >> op;
        // if (op == 'm') {
        //     cin >> tmp_op;
        //     if (tmp_op == '+') memory+=result;
        //     else if (tmp_op == '-') memory-=result;
        // }

    } while (op != 'q');
}


