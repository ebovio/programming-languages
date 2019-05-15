#include <iostream>
#include <limits> 
using namespace std;

int main()
{
    cout << "Size of char: " << sizeof(char) << " byte" << endl;
    cout << "Minimum value for char: " << std::numeric_limits<char>::min() << '\n';
    cout << "Maximum value for char: " << std::numeric_limits<char>::max() << '\n';
    cout << "Size of unsigned char: " << sizeof(unsigned char) << " byte" << endl;
    cout << "Minimum value for unsigned char: " << std::numeric_limits<unsigned char>::min() << '\n';
    cout << "Maximum value for unsigned char: " << std::numeric_limits<unsigned char>::max() << '\n';
    cout << "Size of boolean: " << sizeof(bool) << " byte" << endl;
    cout << "Minimum value for boolean: " << std::numeric_limits<bool>::min() << '\n';
    cout << "Maximum value for boolean: " << std::numeric_limits<bool>::max() << '\n';
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Minimum value for int: " << std::numeric_limits<int>::min() << '\n';
    cout << "Maximum value for int: " << std::numeric_limits<int>::max() << '\n';
    cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes" << endl;
    cout << "Minimum value for unsigned int: " << std::numeric_limits<unsigned int>::min() << '\n';
    cout << "Maximum value for unsigned int: " << std::numeric_limits<unsigned int>::max() << '\n';
    cout << "Size of short: " << sizeof(short) << " bytes" << endl;
    cout << "Minimum value for short: " << std::numeric_limits<short>::min() << '\n';
    cout << "Maximum value for short: " << std::numeric_limits<short>::max() << '\n';
    cout << "Size of unsigned short: " << sizeof(unsigned short) << " bytes" << endl;
    cout << "Minimum value for unsigned short: " << std::numeric_limits<unsigned short>::min() << '\n';
    cout << "Maximum value for unsigned short: " << std::numeric_limits<unsigned short>::max() << '\n';
    cout << "Size of long: " << sizeof(long) << " bytes" << endl;
    cout << "Minimum value for long: " << std::numeric_limits<long>::min() << '\n';
    cout << "Maximum value for long: " << std::numeric_limits<long>::max() << '\n';
    cout << "Size of unsigned long: " << sizeof(unsigned long) << " bytes" << endl;
    cout << "Minimum value for unsigned long: " << std::numeric_limits<unsigned long>::min() << '\n';
    cout << "Maximum value for unsigned long: " << std::numeric_limits<unsigned long>::max() << '\n';
    cout << "Size of long long: " << sizeof(long long) << " bytes" << endl;
    cout << "Minimum value for long long: " << std::numeric_limits<long long>::min() << '\n';
    cout << "Maximum value for long long: " << std::numeric_limits<long long>::max() << '\n';
    cout << "Size of unsigned long long: " << sizeof(unsigned long long) << " bytes" << endl;
    cout << "Minimum value for unsigned long long: " << std::numeric_limits<unsigned long long>::min() << '\n';
    cout << "Maximum value for unsigned long long: " << std::numeric_limits<unsigned long long>::max() << '\n';
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Minimum value for float: " << std::numeric_limits<float>::min() << '\n';
    cout << "Maximum value for float: " << std::numeric_limits<float>::max() << '\n';
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Minimum value for double: " << std::numeric_limits<double>::min() << '\n';
    cout << "Maximum value for double: " << std::numeric_limits<double>::max() << '\n';
    cout << "Size of long double: " << sizeof(long double) << " bytes" << endl;
    cout << "Minimum value for long double: " << std::numeric_limits<long double>::min() << '\n';
    cout << "Maximum value for long double: " << std::numeric_limits<long double>::max() << '\n';

    return 0;
}