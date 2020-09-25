#include <bits/stdc++.h>
#define sp(n) fixed << setprecision(n)

using namespace std;
const long double pi = acos(-1);
// Функция определения машинного нуля
template<typename T>
T get_machine_zero(T E_k) {
    while (E_k / 2 > 0) E_k /= 2;
    return E_k;
}

// Функция определения машинного эпсилон
template<typename T>
T get_machine_eps(T E_k) {
    while (E_k + 1 > 1) E_k /= 2;
    return E_k;
}

// Функция вычисления значения e^x разложением в ряд Маклорена
long double my_exp(int x) {
    bool is_negative = x < 0;
    if (is_negative) x = -x;
    int k = 1;
    long double ans = 1, tmp = 1;
    while (tmp > 0){
        tmp = tmp * x / k;
        k++;
        ans += tmp;
    }
    return is_negative ? 1 / ans : ans;
}

// Приведение аргумента к промежутку [0; 2pi]
long double normalize(long double x) {
    while (x < 0) x += 2 * pi;
    while (x - 2 * pi > 0) x -= 2 * pi;
    return x;
}

// Функция вычисления синуса в ряд Маклорена
long double my_sin(long double x) {
    long double ans = x, tmp = x;
    int k = 2;
    while (abs(tmp) > 0) {
        tmp = -tmp / (k * k + k) * x * x;
        k += 2;
        ans += tmp;
    }
    return ans;
}

// Функция вычисления косинуса в ряд Маклорена
long double my_cos(long double x) {
    long double ans = x, tmp = 1;
    int k = 1;
    while (abs(tmp) > 0) {
        tmp = -1 * tmp * x * x / k / (k + 1);
        k += 2;
        ans += tmp;
    }
    return ans;
}

int main() {
    system("chcp 65001"); //кодировка

    cout << "ЗАДАНИЕ 1.1\n";
    cout << "Машинный ноль для float: " << get_machine_zero((float) 1) << endl;
    cout << "Машинный ноль для double: " << get_machine_zero((double) 1) << endl;
    cout << "Машинный ноль для long double: " << get_machine_zero((long double) 1) << endl;
    cout << "-------------------------------------------\n";

    cout << "ЗАДАНИЕ 1.2\n";
    cout << "Машинный эпсилон для float: " << get_machine_eps((float) 1) << endl;
    cout << "Машинный эпсилон для double: " << get_machine_eps((double) 1) << endl;
    cout << "Машинный эпсилон для long double: " << get_machine_eps((long double) 1) << endl;
    cout << "-------------------------------------------\n";

    cout << "ЗАДАНИЕ 2.1\n";
    for (int i = 0; i <= 50; i += 10) {
        cout << sp(12) << "my_exp(x)  при  x = " << i << ": " << my_exp(i) << endl;
        cout << sp(12) << "std_exp(x) при  x = " << i << ": " << exp(i) << endl;
        cout << sp(12) << "Погрешность при x = " << i << ": " << abs(my_exp(i) - exp(i)) << endl;
        cout << "-------------------------------------------\n";
    }

    cout << "ЗАДАНИЕ 2.2 \n";
    for (int i = 0; i <= 50; i += 10) {
        cout << sp(40) << "my_exp(x)  при  x = " << -i << ": " << my_exp(-i) << endl;
        cout << sp(40) << "std_exp(x) при  x = " << -i << ": " << exp(-i) << endl;
        cout << sp(40) << "Погрешность при x = " << -i << ": " << abs(my_exp(-i) - exp(-i)) << endl;
        cout << "-------------------------------------------\n";
    }

    cout << "ЗАДАНИЕ 2.3 \n";
    for (int i = 0; i <= 50; i += 5) {
        long double x = i;//normalize(i);
        cout << sp(12) << "my_sin(x)  при  x = " << i << ": " << my_sin(i) << endl;
        cout << sp(12) << "std_sin(x) при  x = " << i << ": " << sin(i) << endl;
        cout << sp(12) << "Погрешность при x = " << i << ": " << abs(my_sin(i) - sin(i)) << endl;
        cout << "-------------------------------------------\n";
        cout << sp(12) << "my_cos(x)  при  x = " << i << ": " << my_cos(i) << endl;
        cout << sp(12) << "std_cos(x) при  x = " << i << ": " << cos(i) << endl;
        cout << sp(12) << "Погрешность при x = " << i << ": " << abs(my_cos(i) - cos(i)) << endl;
        cout << "-------------------------------------------\n";
    }
    return 0;
}
