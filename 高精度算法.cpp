#include <cstdio>
#include <cstring>
#include<iostream>
using namespace std;
void add(char*a1,char *b1) {
    int a[5005], b[5005], c[5005]; //c[i] 用来储存每位相加的结果
    int len_a, len_b, len_c = 1, x, i;
    memset(a, 0, sizeof(a));//长度不够用0来算，防止访问垃圾数据
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    len_a = strlen(a1);
    len_b = strlen(b1);
    for(i=0; i<len_a; i++) a[len_a - i] = a1[i] - '0'; // 将加数放进a数组
    for(i=0; i<len_b; i++) b[len_b - i] = b1[i] - '0'; // 将另一个加数放进b数组
    x = 0; // x为进位
    while(len_c <= len_a || len_c <= len_b) {
        c[len_c] = a[len_c] + b[len_c] + x; // 两数相加，再加上前两个数进位的
        x = c[len_c] / 10; // 刷新进位
        c[len_c] %= 10; // 进位后剩下的
        len_c++; //位数加1
    }
    c[len_c] = x;//最高位的进位在此赋值
    if(c[len_c] == 0&&len_c>1) { //判断首位是否为0
        len_c--; // 不输出此位
    }
    for(int i=len_c; i>=1; i--) 
        printf("%d", c[i]); //输出每一位的数
}
void subtraction(char *n1,char *n2) {
    if(n1>n2)
    {
        cout<<"-";
        char tem[1000];
        strcpy(tem,n1);
        strcpy(n1,n2);
        strcpy(n2,tem);
    }
    int a[5005], b[5005], c[5005];
    int lena, lenb, lenc, i;
    std::memset(a, 0, sizeof(a));
    std::memset(b, 0, sizeof(b));
    std::memset(c, 0, sizeof(c));
    lena = std::strlen(n1);
    lenb = std::strlen(n2);
    for(i=0; i<lena; i++) a[lena - i] = (int)n1[i] - '0';
    for(i=0; i<lenb; i++) b[lenb - i] = (int)n2[i] - '0'; //逆序存放排列
    i = 1;
    while(i <= lena || i <= lenb) {
        if(a[i] < b[i]) {
            c[i] = a[i] + 10 - b[i];
            a[i+1]--; //借位处理
        }
        else {
            c[i] = a[i] - b[i]; 
        }
        i++;
    }
 
    lenc = i;
    while(c[lenc] == 0 && lenc > 1) { //如果最后一位是0，是需要输出的
        lenc--;   // 不输出首位0
    }
 
    for(i=lenc; i>=1; i--) std::cout << c[i];
}
void multiplication(char *n1,char *n2){
    int a[105], b[105], c[10005];
    int lena, lenb, lenc, j, i, x;
    std::memset(a, 0, sizeof(a));
    std::memset(b, 0, sizeof(b));
    std::memset(c, 0, sizeof(c));
    lena = std::strlen(n1);
    lenb = std::strlen(n2);
    for(i=0; i<=lena-1; i++) a[lena - i] = n1[i] - 48; 
    for(i=0; i<=lenb-1; i++) b[lenb - i] = n2[i] - 48; // 倒序储存
    for(i=1; i<=lena; i++) {
        x = 0;
        for(j=1; j<=lenb; j++) {
            c[i + j - 1] = c[i + j - 1] + x + a[i] * b[j];
            x = c[i + j - 1] / 10; // 进位
            c[i + j - 1] %= 10; // 剩余
        }
        c[i + lenb] = x; // 进位的数
    }
    lenc = lena + lenb;
    while(c[lenc] == 0 && lenc > 1) {
        lenc--; // 删除前导0
    }
    for(i=lenc; i>=1; i--) {
        std::cout << c[i];
    }  // 输出每一位
    std::cout << std::endl;
} 
int main(){
    char s1[1000]="0";
    char s2[1000]="0";
    multiplication(s1,s2);
    return 0;
}