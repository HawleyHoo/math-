//
// Created by 胡杨 on 2018/3/21.
//

#include <stdio.h>

//题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
void test_math001() {
    __uint32_t i, j, k;
    for (i = 1; i < 5; i++) {
        for (j = 1; j < 5; j++) {
            if (j == i) {
                continue;
            }
            for (k = 1; k < 5; k++) {
                if (k == j || k == i) {
                    continue;
                }
                printf("%u%u%u", i, j, k);
            }
        }

    }
}

//交换两个数的值
void test_math002() {
    int a = 10;
    int b = 20;
    a = a + b;
    b = a - b;
    a = a - b;

//    采用按位异或运算的方式：任意一个数与任意一个给定的值连续异或两次，值不变！
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
//    采用移位的方法：
    a = a << 16;
    a = a | b;
    b = a >> 16;
    a = a & 0xffff;
}

// 题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
void test_math003() {
    int x;
    for (int m = 0; m < 168 / 2 + 1; m++) {
        for (int n = 0; n < m; ++n) {
            if ((m * m - n * n) == 168) {
                x = n * n - 100;
                printf("%d + 100 = %d * %d \n", x, n, n);
                printf("%d + 268 = %d * %d \n", x, m, m);
            }
        }
    }
}

/*
 * 程序分析：
假设该数为 x。
1、则：x + 100 = n2, x + 100 + 168 = m2
2、计算等式：m2 - n2 = (m + n)(m - n) = 168
3、设置： m + n = i，m - n = j，i * j =168，i 和 j 至少一个是偶数
4、可得： m = (i + j) / 2， n = (i - j) / 2，i 和 j 要么都是偶数，要么都是奇数。
5、从 3 和 4 推导可知道，i 与 j 均是大于等于 2 的偶数。
6、由于 i * j = 168， j>=2，则 1 < i < 168 / 2 + 1。
7、接下来将 i 的所有数字循环计算即可。
 */
void test_math0032() {
    int i, j, m, n, x;
    for (i = 1; i < 168 / 2 + 1; i++) {
        if (168 % i == 0) {
            j = 168 / i;
            if (i > j && (i + j) % 2 == 0 && (i - j) % 2 == 0) {
                m = (i + j) / 2;
                n = (i - j) / 2;
                x = n * n - 100;
                printf("%d + 100 = %d * %d\n", x, n, n);
                printf("%d + 268 = %d * %d\n", x, m, m);
            }
        }
    }
}

/*
题目：输入某年某月某日，判断这一天是这一年的第几天？
程序分析：以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天，特殊情况，闰年且输入月份大于3时需考虑多加一天。
 */
void test_math004() {
    int year, month, day, sumday = 0;
    int monthdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("请输入年、月、日，格式为：年,月,日（2015,12,10）\n");
    scanf("%d,%d,%d", &year, &month, &day);
//    printf("%d年%d月%d日是%d年的第%d天",year, month, day, year, sumday);
//    return;
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
        monthdays[1] = 29;
    }

    for (int i = 0; i < month - 1; ++i) {
        sumday += monthdays[i];
    }

    sumday += day;
    printf("%d年%d月%d日是%d年的第%d天", year, month, day, year, sumday);
}

#include <math.h>

bool is_prinme(int m) {
    if (m % 2 == 0) {
        return false;
    }

    for (int i = 3; i * i <= m; ++i) {
        if (m % i == 0) {
            return false;
        }
    }
    return true;
}

//判断101到200之间的素数。
void test_math012() {
    for (int i = 101; i < 201; ++i) {
        if (is_prinme(i)) {
            printf("素数：%d\n", i);
        }
    }
}

/* 将一个正整数分解质因数
程序分析：对n进行分解质因数，应先找到一个最小的质数k，然后按下述步骤完成：
(1)如果这个质数恰等于（小于的时候，继续执行循环）n，则说明分解质因数的过程已经结束，另外 打印出即可。
(2)但n能被k整除，则应打印出k的值，并用n除以k的商,作为新的正整数n.重复执行第二步。
(3)如果n不能被k整除，则用k+1作为k的值,重复执行第一步。
 */
void test_math014(int n) {
    for (int i = 2; i <= n; ++i) {
        while (n % i == 0) {
            printf("因数为：%d\n", i);
            n /= i;
        }
    }
}

/*
 * 输入两个正整数m和n，求其最大公约数和最小公倍数。
 * 程序分析：
（1）最小公倍数=输入的两个数之积除于它们的最大公约数，关键是求出最大公约数；
（2）求最大公约数用辗转相除法（又名欧几里德算法）
1）证明：设c是a和b的最大公约数，记为c=gcd(a,b),a>=b,
令r=a mod b
设a=kc，b=jc，则k，j互素，否则c不是最大公约数
据上，r=a-mb=kc-mjc=(k-mj)c
可知r也是c的倍数，且k-mj与j互素，否则与前述k，j互素矛盾,
由此可知，b与r的最大公约数也是c，即gcd(a,b)=gcd(b,a mod b)，得证。
2）算法描述：
第一步：a ÷ b，令r为所得余数（0≤r 第二步：互换：置 a←b，b←r，并返回第一步。
 * */
void test_math016(int m, int n) {
    int a, b;
    if (m < n) {
        a = n;
        b = m;
    } else {
        a = m;
        b = n;
    }

    // a <= b
    int r = a % b;
    int d = a * b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    printf("%d, %d的最大公约数是%d，最小公倍数是%d\n", m, n, b, d / b);
}

//输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
void test_math017() {
    char c;
    int letters = 0, spaces = 0, digits = 0, others = 0;
    printf("请输入一些字母：\n");
    while ((c = getchar()) != '\n') {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            letters++;
        else if (c >= '0' && c <= '9')
            digits++;
        else if (c == ' ')
            spaces++;
        else
            others++;
    }
    printf("字母=%d,数字=%d,空格=%d,其他=%d\n", letters, digits, spaces, others);
}

/* 求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。
 * 例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。
 * */
void test_math018(int n, int a) {
    int sum = 0;

    int t = 0;
    for (int i = 1; i <= n; ++i) {
        t = t * 10 + a;
        sum += t;
    }

    printf("a+aa+...=%d\n", sum);
}

/*猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不瘾，又多吃了一个 第二天早上又将剩下的桃子吃掉一半，又多吃了一个。
 * 以后每天早上都吃了前一天剩下 的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。
 * 求第一天共摘了多少。*/
void test_math021() {
    int sum = 1;
    for (int i = 1; i < 10; ++i) {
        sum = (sum + 1) * 2;
    }
    printf("原来一共%d个桃子\n", sum);
}

/*有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。*/
void test_math024() {
    float sum = 0;
    float a = 2, b = 1;
    for (int i = 0; i < 20; ++i) {
        sum += a / b;
        a = a + b;
        b = a - b;
    }
    printf("%9.6f\n", sum);
}
/*
 * 删除一个字符串中的指定字母，如：字符串 "aca"，删除其中的 a 字母。
 */
#include <string.h>

char *test_math032(char *str, char *strSet) {
    int hash[256];
    if (NULL == strSet)
        return str;

    for (int i = 0; i < 256; ++i) {
        hash[i] = 0;
    }

    for (int j = 0; j < strlen(strSet); ++j) {
        hash[strSet[j]] = 1;
    }

    int currentIndex = 0;
    for (int k = 0; k < strlen(str); ++k) {
        if (!hash[str[k]])
            str[currentIndex++] = str[k];
    }
    str[currentIndex] = '\0';
    return str;


}

/*
 * 判断一个数字是否为质数。
 * 一个大于1的自然数，除了1和它本身外，不能被其他自然数整除。
 */
bool hoo_is_prinme(int m, int *sieve_arr) {
//    if (m < 2) return false;
//    if (m == 2) return true;

    for (int i = 0; sieve_arr[i] * sieve_arr[i] <= m ; ++i) {
        if (m % sieve_arr[i] == 0) return false;
    }
    return true;
}
bool test_math033(int n) {
    //[0,n]之间有 n +1 个整数，0 和 1不是素数，因此剩下 n-1 个数。偶数一定不是素数，因此我们大致将数组大小定义为 (n-1)/2 +1
    int *primes = new int[(n - 1) / 2 + 1];
    int count = 0;
    if (n >= 2) {
        primes[count++] = 2;
    }

    for (int i = 2; i <= n; ++i) {
        if (hoo_is_prinme(i, primes)) {//如果 i为素数
            primes[count++] = i;//则将 i存储到数组中
        }
    }
    printf("[2,n]之间的素数的个数 :%d\n", count);
    for (int j = 0; j < count; ++j) {
        printf("小于%d的素数为：%d\n", n, primes[j]);
    }
    delete[] primes;
}

/*
 * 字符串反转reverse，如将字符串 "www.runoob.com" 反转为 "moc.boonur.www"。
 */
void test_math035(char *str) {
    int len = 0;
    char temp;
    char *begin, *end;
    len = strlen(str);
    begin = str;
    end = str + len - 1;

    while (begin < end) {
        temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }
}


#include <time.h>
#include <iostream>

int main() {
    clock_t start = clock();

//    char string[]="www.runoob.com";
    char string[]="123456";
    test_math035(string);
    puts(string);

    clock_t end = clock();

    std::cout<<"耗时："<< (double(end - start)) / CLOCKS_PER_SEC * 1000<< "毫秒"<<std::endl;
//     int i = 1;
//    int b = i++;
//    printf("%d===== %d", (i++), i);
//    char test[12] = "asfdasga";
//    char test2[3] = "af";
//    printf("%s\n", test_math032(test, test2));
//    for (int i = 0; i <= 18;) {
//        test[i] = i + 2;
//        printf("%d---%d----%d\n", i, test[i], test2[i]);
//
//        ++i;
//    }
    printf("%d", int(2.9999));

    return 0;
}