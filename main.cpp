#include <iostream>

using namespace std;

#include <ctime>
#include <cstdlib>

#include <iomanip>

using std::setw;

void array_test();

void swap(int &x, int &y);

// 要生成和返回随机数的函数
int *getRandom() {
    static int r[10];

    // 设置种子
    srand((unsigned) time(NULL));
    for (int i = 0; i < 10; ++i) {
        r[i] = rand();
        cout << r[i] << endl;
    }

    return r;
}

//引用
void test_reference() {
    int i;
    double d;

    // 声明引用变量
    int &r = i;
    double &s = d;

    i = 5;
    cout << "value of i :" << i << endl;
    cout << "value of i reference :" << r << endl;

    d = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s << endl;
}


double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

double& setValues( int i )
{
    return vals[i];   // 返回第 i 个元素的引用
}

int main11() {
    cout << "Hello, World!" << endl;

//    test_reference();
    int a = 100, b = 200;
    swap(a, b);
    cout << "交换后，a 的值：" << a << endl;
    cout << "交换后，b 的值：" << b << endl;

    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "time:" << now << endl;
    cout << "date time str :" << dt << endl;

    // 把 now 转换为 tm 结构
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC 日期和时间："<< dt << endl;
//    array_test();

    return 0;
}



void swap(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
    return;
}


void array_test() {
    for (int j = 0; j < 10; ++j) {
        int i;
        i = rand();
        cout << "随机数：" << i << endl;
    }

    int n[10];

    for (int k = 0; k < 10; ++k) {
        n[k] = k + 100;
    }
    cout << "Element" << setw(13) << "value" << endl;

    for (int l = 0; l < 10; ++l) {
        cout << setw(7) << l << setw(13) << n[l] << endl;
    }

    // 带有 5 个元素的双精度浮点型数组
    double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    double *p;

    p = balance;

    // 输出数组中每个元素的值
    cout << "使用指针的数组值 " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "*(p + " << i << ") : ";
        cout << *(p + i) << endl;
    }

    cout << "使用 balance 作为地址的数组值 " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "*(balance + " << i << ") : ";
        cout << *(balance + i) << endl;
    }

    int *p2;

    p2 = getRandom();
    for (int i = 0; i < 10; i++) {
        cout << "*(p2 + " << i << ") : ";
        cout << *(p2 + i) << endl;
    }

}
