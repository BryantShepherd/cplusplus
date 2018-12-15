#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main ()
{
   char str1[15];
   char str2[15];
   int ret;


   strcpy(str1, "AbCdef"); //so sanh tung ki tu tu trai sang phai, neu giong nhau thi bo qua, neu khac nhau thi ki tu nao lon hon thi xau chua ki tu do lon hon
   strcpy(str2, "ABCDEF");

   ret = strcmp(str1, str2);

   cout << ret << endl;
   
   return(0);
}