/*
 * 姓名：凌铧钦
 * 学号：221801201
 * 班级：2018级软件工程2班
 * 电子邮件：782870819@qq.com
 *
 * 算法：
 * 数据结构：
 *
 * 开发环境：Clion 2019.1
 * 运行环境：windows10 1803
 * */
#include<iostream>
#include<vector>
#define NUM_LENGTH 8

using namespace std;

class HugeInt{
public:
    //构造函数
    HugeInt(){
        nums.push_back(0);
    }

    HugeInt(string num);

    HugeInt(long long int);
    //重载运算符函数
    //巨型整数op巨型整数
    HugeInt operator+(HugeInt item);

    HugeInt operator-(HugeInt item);

    HugeInt operator*(HugeInt item);

    HugeInt operator/(HugeInt item);

    HugeInt operator%(HugeInt item);

    bool operator>(HugeInt item);

    bool operator>=(HugeInt item);

    bool operator<(HugeInt item);

    bool operator<=(HugeInt item);

    bool operator!=(HugeInt item);

    bool operator==(HugeInt item);



    //巨型整数op长整型数
    HugeInt operator+(long long int item);

    HugeInt operator-(long long int item);

    HugeInt operator*(long long int item);

    HugeInt operator/(long long int item);

    HugeInt operator%(long long int item);

    bool operator>(long long int item);

    bool operator>=(long long int item);

    bool operator<(long long int item);

    bool operator<=(long long int item);

    bool operator!=(long long int item);

    bool operator==(long long int item);

    //巨型整数op字符串
    HugeInt operator+(string item);

    HugeInt operator-(string item);

    HugeInt operator*(string item);

    HugeInt operator/(string item);

    HugeInt operator%(string item);

    bool operator>(string item);

    bool operator>=(string item);

    bool operator<(string item);

    bool operator<=(string item);

    bool operator!=(string item);

    bool operator==(string item);

    //长整型数op巨型整数
    friend HugeInt operator+(HugeInt &caller,long long int item);

    friend HugeInt operator-(HugeInt &caller,long long int item);

    friend HugeInt operator*(HugeInt &caller,long long int item);

    friend HugeInt operator/(HugeInt &caller,long long int item);

    friend HugeInt operator%(HugeInt &caller,long long int item);

    friend bool operator>(HugeInt &caller,long long int item);

    friend bool operator>=(HugeInt &caller,long long int item);

    friend bool operator<(HugeInt &caller,long long int item);

    friend bool operator<=(HugeInt &caller,long long int item);

    friend bool operator!=(HugeInt &caller,long long int item);

    friend bool operator==(HugeInt &caller,long long int item);

    //字符串op巨型整数
    friend HugeInt operator+(HugeInt &caller,string item);

    friend HugeInt operator-(HugeInt &caller,string item);

    friend HugeInt operator*(HugeInt &caller,string item);

    friend HugeInt operator/(HugeInt &caller,string item);

    friend HugeInt operator%(HugeInt &caller,string item);

    friend bool operator>(HugeInt &caller,string item);

    friend bool operator>=(HugeInt &caller,string item);

    friend bool operator<(HugeInt &caller,string item);

    friend bool operator<=(HugeInt &caller,string item);

    friend bool operator!=(HugeInt &caller,string item);

    friend bool operator==(HugeInt &caller,string item);

private:
    vector<int> nums;
};

HugeInt::HugeInt(string num){

}

HugeInt::HugeInt(long long int){

}

//重载运算符函数
//巨型整数op巨型整数
HugeInt HugeInt::operator+(HugeInt item){

}

HugeInt HugeInt::operator-(HugeInt item){

}

HugeInt HugeInt::operator*(HugeInt item){

}

HugeInt HugeInt::operator/(HugeInt item){

}

HugeInt HugeInt::operator%(HugeInt item){

}

bool HugeInt::operator>(HugeInt item){

}

bool HugeInt::operator>=(HugeInt item){

}

bool HugeInt::operator<(HugeInt item){

}

bool HugeInt::operator<=(HugeInt item){

}

bool HugeInt::operator!=(HugeInt item){

}

bool HugeInt::operator==(HugeInt item){

}



//巨型整数op长整型数
HugeInt HugeInt::operator+(long long int item){

}

HugeInt HugeInt::operator-(long long int item){

}

HugeInt HugeInt::operator*(long long int item){

}

HugeInt HugeInt::operator/(long long int item){

}

HugeInt HugeInt::operator%(long long int item){

}

bool HugeInt::operator>(long long int item){

}

bool HugeInt::operator>=(long long int item){

}

bool HugeInt::operator<(long long int item){

}

bool HugeInt::operator<=(long long int item){

}

bool HugeInt::operator!=(long long int item){

}

bool HugeInt::operator==(long long int item){

}

//巨型整数op字符串
HugeInt HugeInt::operator+(string item){

}

HugeInt HugeInt::operator-(string item){

}

HugeInt HugeInt::operator*(string item){

}

HugeInt HugeInt::operator/(string item){

}

HugeInt HugeInt::operator%(string item){

}

bool HugeInt::operator>(string item){

}

bool HugeInt::operator>=(string item){

}

bool HugeInt::operator<(string item){

}

bool HugeInt::operator<=(string item){

}

bool HugeInt::operator!=(string item){

}

bool HugeInt::operator==(string item){

}

//长整型数op巨型整数
HugeInt operator+(HugeInt &caller,long long int item){

}

HugeInt operator-(HugeInt &caller,long long int item){

}

HugeInt operator*(HugeInt &caller,long long int item){

}

HugeInt operator/(HugeInt &caller,long long int item){

}

HugeInt operator%(HugeInt &caller,long long int item){

}

bool operator>(HugeInt &caller,long long int item){

}

bool operator>=(HugeInt &caller,long long int item){

}

bool operator<(HugeInt &caller,long long int item){

}

bool operator<=(HugeInt &caller,long long int item){

}

bool operator!=(HugeInt &caller,long long int item){

}

bool operator==(HugeInt &caller,long long int item){

}

//字符串op巨型整数
HugeInt operator+(HugeInt &caller,string item){

}

HugeInt operator-(HugeInt &caller,string item){

}

HugeInt operator*(HugeInt &caller,string item){

}

HugeInt operator/(HugeInt &caller,string item){

}

HugeInt operator%(HugeInt &caller,string item){

}

bool operator>(HugeInt &caller,string item){

}

bool operator>=(HugeInt &caller,string item){

}

bool operator<(HugeInt &caller,string item){

}

bool operator<=(HugeInt &caller,string item){

}

bool operator!=(HugeInt &caller,string item){

}

bool operator==(HugeInt &caller,string item){

}

int main(){
    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}