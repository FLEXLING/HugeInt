/*
 * ������������
 * ѧ�ţ�221801201
 * �༶��2018���������2��
 * �����ʼ���782870819@qq.com
 *
 * �㷨��
 * ���ݽṹ��
 *
 * ����������Clion 2019.1
 * ���л�����windows10 1803
 * */
#include<iostream>
#include<vector>
#define NUM_LENGTH 8

using namespace std;

class HugeInt{
public:
    //���캯��
    HugeInt(){
        nums.push_back(0);
    }

    HugeInt(string num);

    HugeInt(long long int);
    //�������������
    //��������op��������
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



    //��������op��������
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

    //��������op�ַ���
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

    //��������op��������
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

    //�ַ���op��������
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

//�������������
//��������op��������
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



//��������op��������
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

//��������op�ַ���
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

//��������op��������
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

//�ַ���op��������
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