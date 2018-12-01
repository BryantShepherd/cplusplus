#include <iostream>
int main()
{
    std::cout << "Enter number of elements: " ;
    int len;
    std::cin >> len;
    
    // Cấp bộ nhớ động len phần tử để tạo mảng mới
    // Chú ý rằng len không cần phải là const!
    int *array = new int[len];
    
    // Khởi tạo các giá trị của mảng
    for(int i = 0; i < len; i++){
        array[i] = i+1;
    }
    
    //in ra màn hình
    for(int i = 0; i < len; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
    
    // Giải phóng bộ nhớ
    std::cout << "Array[1] truoc khi delele: " << array[1] << std::endl;
    std::cout << "Deleting..." << std::endl;
    delete[] array; 
    std::cout << "Array[1] sau khi delele: " <<  array[1];
    return 0;
}