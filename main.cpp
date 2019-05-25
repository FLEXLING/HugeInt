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
#include<string>
#include<stdlib.h>
#define NUM_LENGTH 8

using namespace std;

class HugeInt{
public:
    //构造函数
    HugeInt(){}
    HugeInt(string num);
    HugeInt(long long int);

    const vector<int> &getNums();

    int getIsMinus();

    //重载运算符函数
    HugeInt& operator=(long long int);
    HugeInt& operator=(string);
    friend istream &operator>>(istream &,HugeInt &);
    friend ostream &operator<<(ostream &,HugeInt &);
    //巨型整数op巨型整数
    HugeInt operator+(HugeInt);
    HugeInt operator-(HugeInt);
    HugeInt operator*(HugeInt);
    HugeInt operator/(HugeInt);
    HugeInt operator%(HugeInt);
    bool operator>(HugeInt);
    bool operator>=(HugeInt);
    bool operator<(HugeInt);
    bool operator<=(HugeInt);
    bool operator!=(HugeInt);
    bool operator==(HugeInt);
    //巨型整数op长整型数
    HugeInt operator+(long long int);
    HugeInt operator-(long long int);
    HugeInt operator*(long long int);
    HugeInt operator/(long long int);
    HugeInt operator%(long long int);
    bool operator>(long long int);
    bool operator>=(long long int);
    bool operator<(long long int);
    bool operator<=(long long int);
    bool operator!=(long long int);
    bool operator==(long long int);
    //巨型整数op字符串
    HugeInt operator+(string);
    HugeInt operator-(string);
    HugeInt operator*(string);
    HugeInt operator/(string);
    HugeInt operator%(string);
    bool operator>(string);
    bool operator>=(string);
    bool operator<(string);
    bool operator<=(string);
    bool operator!=(string);
    bool operator==(string);
    //长整型数op巨型整数
    friend HugeInt operator+(HugeInt &caller,long long int);
    friend HugeInt operator-(HugeInt &caller,long long int);
    friend HugeInt operator*(HugeInt &caller,long long int);
    friend HugeInt operator/(HugeInt &caller,long long int);
    friend HugeInt operator%(HugeInt &caller,long long int);
    friend bool operator>(HugeInt &caller,long long int);
    friend bool operator>=(HugeInt &caller,long long int);
    friend bool operator<(HugeInt &caller,long long int);
    friend bool operator<=(HugeInt &caller,long long int);
    friend bool operator!=(HugeInt &caller,long long int);
    friend bool operator==(HugeInt &caller,long long int);
    //字符串op巨型整数
    friend HugeInt operator+(HugeInt &caller,string);
    friend HugeInt operator-(HugeInt &caller,string);
    friend HugeInt operator*(HugeInt &caller,string);
    friend HugeInt operator/(HugeInt &caller,string);
    friend HugeInt operator%(HugeInt &caller,string);
    friend bool operator>(HugeInt &caller,string);
    friend bool operator>=(HugeInt &caller,string);
    friend bool operator<(HugeInt &caller,string);
    friend bool operator<=(HugeInt &caller,string);
    friend bool operator!=(HugeInt &caller,string);
    friend bool operator==(HugeInt &caller,string);

private:
    vector<int> nums;
    int isMinus=0;
};

HugeInt::HugeInt(string num){
    int isMinus=0;
    int isWrong=0;
    int type=0;//默认为0；1代表八进制；2代表十六进制
    if(num[0]=='-'){
        num=num.substr(1,num.size()-1);//去掉特殊符号
        isMinus=1;
    }
    if(num.substr(0,1)=="0"){
        type=1;
        num=num.substr(1,num.size()-1);//去掉特殊符号
    }else if(num.substr(0,2)=="0X"||num.substr(0,2)=="0x"){
        type=2;
        num=num.substr(1,num.size()-1);//去掉特殊符号
    }
    for(int i=0;i<num.size();i++){
        if(!isdigit(num[i])){
            isWrong=1;
        }
    }

    if(isWrong==0){
        int end=num.length();
        if(type==0){
            while(1){
                if(end-8<=0){
                    int temp;
                    sscanf(num.substr(0,end).c_str(),"%d",&temp);
                    nums.push_back(temp);
                    break;
                }
                int temp;
                sscanf(num.substr(end-8,8).c_str(),"%d",&temp);
                nums.push_back(temp);
                end-=8;
            }
        }else if(type==1){
            while(1){
                if(end-8<=0){
                    int temp;
                    sscanf(num.substr(0,end).c_str(),"%o",&temp);
                    nums.push_back(temp);
                    break;
                }
                int temp;
                sscanf(num.substr(end-8,8).c_str(),"%o",&temp);
                nums.push_back(temp);
                end-=8;
            }
        }else if(type==2){
            while(1){
                if(end-8<=0){
                    int temp;
                    sscanf(num.substr(0,end).c_str(),"%x",&temp);
                    nums.push_back(temp);
                    break;
                }
                int temp;
                sscanf(num.substr(end-8,8).c_str(),"%x",&temp);
                nums.push_back(temp);
                end-=8;
            }
        }
        if(isMinus==1){
            this->isMinus=1;
        }
    }else{
        HugeInt();
    }
}

HugeInt::HugeInt(long long int num){
    if(num<0){
        num*=-1;
        this->isMinus=1;
    }
    while(num>0){
        this->nums.push_back(num%NUM_LENGTH);
        num/=NUM_LENGTH;
    }
}

const vector<int> &HugeInt::getNums(){
    return nums;
}

int HugeInt::getIsMinus(){
    return isMinus;
}

HugeInt& HugeInt::operator=(long long int num){
    this->nums.clear();
    while(num>0){
        this->nums.push_back(num%NUM_LENGTH);
        num/=NUM_LENGTH;
    }
    return *this;
}

HugeInt& HugeInt::operator=(string num){
    this->nums.clear();
    HugeInt temp(num);
    if(temp.nums.size()!=0){
        this->nums=temp.nums;
        this->isMinus=temp.isMinus;
    }
    return *this;
}



istream &operator>>(istream &in,HugeInt &item){
    string str="0";
    in>>str;
    item=str;
    return in;
}

ostream &operator<<(ostream &out,HugeInt &item){
    int i=item.getNums().size()-1;
    if(item.isMinus){
        out<<'-';
    }
    while(i>=0){
        out<<item.getNums()[i];
        i--;
    }
    return out;
}

//重载运算符函数
//巨型整数op巨型整数
HugeInt HugeInt::operator+(HugeInt item){
    if(item.isMinus){
        item.isMinus=0;
        return *this-item;
    }else if(this->isMinus){
        HugeInt temp;
        HugeInt temp1=*this;
        temp1.isMinus=0;
        temp=item-temp1;
        temp.isMinus*=-1;
        return temp;
    }else if(this->isMinus&&item.isMinus){
        HugeInt temp1=*this;
        HugeInt temp;
        temp1.isMinus=0;
        item.isMinus=0;
        temp=item+temp1;
        temp.isMinus=1;
        return temp;
    }

    HugeInt temp;
    int size1=this->nums.size();
    int size2=item.nums.size();
    int i=0;
    int carryNum=0;
    while(i<size1&&i<size2){
        temp.nums.push_back((this->nums[i]+item.nums[i])%100000000);
        temp.nums[i]+=carryNum;
        carryNum=(this->nums[i]+item.nums[i])/100000000;
        i++;
    }
    if(i<max(size1,size2)){
        if(max(size1,size2)==size1){
            while(i!=size1){
                temp.nums.push_back(this->nums[i]+carryNum);
                carryNum=0;
                i++;
            }
        }else if(max(size1,size2)==size2){
            while(i!=size2){
                temp.nums.push_back(item.nums[i]+carryNum);
                carryNum=0;
                i++;
            }
        }
    }
    return temp;
}

HugeInt HugeInt::operator-(HugeInt item){
    if(item.isMinus){
        item.isMinus=0;
        return *this+item;
    }else if(this->isMinus){
        HugeInt temp;
        HugeInt temp1=*this;
        temp1.isMinus=0;
        temp=item+temp1;
        temp.isMinus*=-1;
        return temp;
    }else if(this->isMinus&&item.isMinus){
        HugeInt temp1=*this;
        HugeInt temp;
        temp1.isMinus=0;
        item.isMinus=0;
        temp=item-temp1;
        temp.isMinus=1;
        return temp;
    }
    HugeInt temp;
    int size1=this->nums.size();
    int size2=item.nums.size();
    int i=0;
    int carryNum=0;
    while(i<size1&&i<size2){
        if(this->nums[i]-item.nums[i]>0){
            temp.nums.push_back(this->nums[i]-item.nums[i]-carryNum);
            carryNum=0;
        }else{
            temp.nums.push_back((1000000000-(this->nums[i]-item.nums[i])-carryNum)%100000000);
            carryNum=1;
        }
        i++;
    }
    if(i<max(size1,size2)){
        if(max(size1,size2)==size1){
            while(i!=size1){
                temp.nums.push_back(this->nums[i]-carryNum);
                carryNum=0;
                i++;
            }
        }else if(max(size1,size2)==size2){
            while(i!=size2){
                temp.nums.push_back(item.nums[i]);
                i++;
                temp.isMinus=1;
            }
        }
    }
    return temp;
}

HugeInt HugeInt::operator*(HugeInt item){
    HugeInt temp;
    int size1=this->nums.size();
    int size2=item.nums.size();
    int i=0;
    int carryNum=0;
    while(i<size1&&i<size2){
        temp.nums.push_back((this->nums[i]*item.nums[i])%100000000);
        temp.nums[i]+=carryNum;
        carryNum=(this->nums[i]*item.nums[i])/100000000;
        i++;
    }
    if(i<max(size1,size2)){
        if(max(size1,size2)==size1){
            while(i!=size1){
                temp.nums.push_back(this->nums[i]+carryNum);
                carryNum=0;
                i++;
            }
        }else if(max(size1,size2)==size2){
            while(i!=size2){
                temp.nums.push_back(item.nums[i]+carryNum);
                carryNum=0;
                i++;
            }
        }
    }
    temp.isMinus=(this->isMinus+item.isMinus)%2;
    return temp;
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
    HugeInt a;
    a="1234567891234567";
    HugeInt b("-123456789");
    cout<<a<<endl;
    cout<<b<<endl;
    a=a-b;
    cout<<a<<endl;
    return 0;
}