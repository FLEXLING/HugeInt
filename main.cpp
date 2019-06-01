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
#include<cmath>
#include<iomanip>

#define NUM_LENGTH 100000000

using namespace std;

class HugeInt{
public:
    //构造函数
    HugeInt(){}
    HugeInt(string num);
    HugeInt(long int);
    HugeInt(const HugeInt &);

    vector<int> &getNums();

    int getIsMinus();

    //重载运算符函数
    HugeInt& operator=(long int);
    HugeInt& operator=(string);
    friend istream &operator>>(istream &,HugeInt &);
    friend ostream &operator<<(ostream &,HugeInt &);
    HugeInt operator++(int);
    HugeInt &operator++();
    HugeInt operator--(int);
    HugeInt &operator--();
    HugeInt operator+=(HugeInt);
    HugeInt operator-=(HugeInt);
    HugeInt operator*=(HugeInt);
    HugeInt operator/=(HugeInt);
    HugeInt operator%=(HugeInt);
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
    HugeInt operator+(long int);
    HugeInt operator-(long int);
    HugeInt operator*(long int);
    HugeInt operator/(long int);
    HugeInt operator%(long int);
    bool operator>(long int);
    bool operator>=(long int);
    bool operator<(long int);
    bool operator<=(long int);
    bool operator!=(long int);
    bool operator==(long int);
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
    friend HugeInt operator+(long int,HugeInt &caller);
    friend HugeInt operator-(long int,HugeInt &caller);
    friend HugeInt operator*(long int,HugeInt &caller);
    friend HugeInt operator/(long int,HugeInt &caller);
    friend HugeInt operator%(long int,HugeInt &caller);
    friend bool operator>(long int,HugeInt &caller);
    friend bool operator>=(long int,HugeInt &caller);
    friend bool operator<(long int,HugeInt &caller);
    friend bool operator<=(long int,HugeInt &caller);
    friend bool operator!=(long int,HugeInt &caller);
    friend bool operator==(long int,HugeInt &caller);
    //字符串op巨型整数
    friend HugeInt operator+(string,HugeInt &caller);
    friend HugeInt operator-(string,HugeInt &caller);
    friend HugeInt operator*(string,HugeInt &caller);
    friend HugeInt operator/(string,HugeInt &caller);
    friend HugeInt operator%(string,HugeInt &caller);
    friend bool operator>(string,HugeInt &caller);
    friend bool operator>=(string,HugeInt &caller);
    friend bool operator<(string,HugeInt &caller);
    friend bool operator<=(string,HugeInt &caller);
    friend bool operator!=(string,HugeInt &caller);
    friend bool operator==(string,HugeInt &caller);

private:
    vector<int> nums;
    int isMinus=0;
};

int cntDig(HugeInt);
string mulStr(int);
HugeInt calRemainder(int,HugeInt,HugeInt);

HugeInt::HugeInt(string num){
    int isMinus=0;
    int isWrong=0;
    int type=0;//默认为0；1代表八进制；2代表十六进制
    if(num[0]=='-'){
        num=num.substr(1,num.size()-1);//去掉特殊符号
        isMinus=1;
    }else if(num[0]=='+'){
        num=num.substr(1,num.size()-1);//去掉特殊符号
    }
    if(num.substr(0,2)=="0X"||num.substr(0,2)=="0x"){
        type=2;
        num=num.substr(2,num.size()-2);//去掉特殊符号
    }else if(num.substr(0,1)=="0"){
        type=1;
        num=num.substr(1,num.size()-1);//去掉特殊符号
    }
    if(num[num.size()-1]=='L'){
        num=num.substr(0,num.size()-1);
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

HugeInt::HugeInt(long int num){
    if(num==0){
        this->nums.push_back(0);
    }
    if(num<0){
        num*=-1;
        this->isMinus=1;
    }
    while(num>0){
        this->nums.push_back(num%NUM_LENGTH);
        num/=NUM_LENGTH;
    }
}

HugeInt::HugeInt(const HugeInt &item){
    for(int i=0;i<item.nums.size();i++){
        this->nums.push_back(item.nums[i]);
    }
    this->isMinus=item.isMinus;
}

vector<int> &HugeInt::getNums(){
    return nums;
}

int HugeInt::getIsMinus(){
    return isMinus;
}

HugeInt& HugeInt::operator=(long int num){
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
        if(i==item.getNums().size()-1){
            out<<item.getNums()[i];
        }else{
            out<<setw(8)<<setfill('0')<<item.getNums()[i];
        }
        i--;
    }

    return out;
}

HugeInt HugeInt::operator++(int){
    HugeInt temp=*this;
    int i=0;
    this->nums[0]+=1;
    while(this->nums[i]/1000000000!=0){
        this->nums[i]%=1000000000;
        this->nums[i+1]+=1;
        i++;
    }
    return temp;
}

HugeInt &HugeInt::operator++(){
    int i=0;
    this->nums[0]+=1;
    while(this->nums[i]/1000000000!=0){
        this->nums[i]%=1000000000;
        this->nums[i+1]+=1;
        i++;
    }
    return *this;
}

HugeInt HugeInt::operator--(int){
    HugeInt temp=*this;
    if(this->nums[0]==0&&this->nums.size()==1){
        this->nums[0]=1;
        this->isMinus=1;
    }else{
        if(this->nums[0]==0){
            this->nums[0]=99999999;
            for(int i=1;i<this->nums.size();i++){
                if(this->nums[i]==0){
                    this->nums[i]=99999999;
                }else{
                    this->nums[i]--;
                }
                if(this->nums[i]!=0){
                    this->nums[i+1]--;
                }
            }
        }else{
            this->nums[0]--;
        }
    }
    int i=this->nums.size()-1;
    while(this->nums[i]==0&&i!=0){
        this->nums.pop_back();
        i--;
    }
    return temp;
}

HugeInt &HugeInt::operator--(){
    if(this->nums[0]==0&&this->nums.size()==1){
        this->nums[0]=1;
        this->isMinus=1;
    }else{
        if(this->nums[0]==0){
            this->nums[0]=99999999;
            for(int i=0;i<this->nums.size();i++){
                if(this->nums[i]==0){
                    this->nums[i]=99999999;
                }else{
                    this->nums[i]--;
                }
                if(this->nums[i]!=0){
                    this->nums[i+1]--;
                }
            }
        }else{
            this->nums[0]--;
        }
    }
    int i=this->nums.size()-1;
    while(this->nums[i]==0&&i!=0){
        this->nums.pop_back();
        i--;
    }
    return *this;
}

HugeInt HugeInt::operator+=(HugeInt item){
    HugeInt temp=*this+std::move(item);
    this->nums=temp.nums;
    this->isMinus=temp.isMinus;
    return temp;
}

HugeInt HugeInt::operator-=(HugeInt item){
    HugeInt temp=*this-item;
    this->nums=temp.nums;
    this->isMinus=temp.isMinus;
    return temp;
}

HugeInt HugeInt::operator*=(HugeInt item){
    HugeInt temp=*this*item;
    this->nums=temp.nums;
    this->isMinus=temp.isMinus;
    return temp;
}

HugeInt HugeInt::operator/=(HugeInt item){
    HugeInt temp=*this/item;
    this->nums=temp.nums;
    this->isMinus=temp.isMinus;
    return temp;
}

HugeInt HugeInt::operator%=(HugeInt item){
    HugeInt temp=*this%item;
    this->nums=temp.nums;
    this->isMinus=temp.isMinus;
    return temp;
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
    int reverse=0;
    HugeInt temp1;
    HugeInt temp2;
    HugeInt temp;
    if(item>*this){
        temp1=item;
        temp2=*this;
        reverse=1;
    }else{
        temp1=*this;
        temp2=item;
    }
    int size1=temp1.nums.size();
    int size2=temp2.nums.size();
    int i=0;
    int carryNum=0;
    while(i<size2){
        if(temp1.nums[i]-temp2.nums[i]>=0){
            temp.nums.push_back(temp1.nums[i]-temp2.nums[i]-carryNum);
            carryNum=0;
        }else{
            temp.nums.push_back((1000000000+(temp1.nums[i]-temp2.nums[i])-carryNum)%100000000);
            carryNum=1;
        }
        i++;
    }
    while(i!=size1){
        if(temp1.nums[i]-carryNum>=0){
            temp.nums.push_back(temp1.nums[i]-carryNum);
            carryNum=0;
        }else{
            temp.nums.push_back((1000000000+(temp1.nums[i]-carryNum))%100000000);
            carryNum=1;
        }
        i++;
    }
    i=temp.nums.size()-1;
    while(temp.nums[i]==0&&i!=0){
        temp.nums.pop_back();
        i--;
    }
    if(reverse){
        temp.isMinus=1;
    }
    return temp;
}

HugeInt HugeInt::operator*(HugeInt item){
    HugeInt temp;
    int size1=this->nums.size();
    int size2=item.nums.size();
    int carryNum=0;
    for(int i=0;i<=size1*size2;i++){
        temp.nums.push_back(0);
    }
    int num1,num2,num3,num4,sum1,sum2;
    for(int i=0;i<size1;i++){
        for(int k=0;k<size2;k++){
            num1=this->nums[i]/10000;
            num2=this->nums[i]%10000;
            num3=item.nums[k]/10000;
            num4=item.nums[k]%10000;
            sum2=num2*num4%10000;
            sum1=(num1*num4%10000+num2*num3%10000+num2*num4/10000)%10000;
            carryNum=num1*num4/10000+num2*num3/10000+num1*num3;
            temp.nums[i+k+1]+=carryNum;
            temp.nums[i+k]+=sum1*10000+sum2;
        }
    }
    int i=temp.nums.size()-1;
    while(temp.nums[i]==0&&i!=0){
        temp.nums.pop_back();
        i--;
    }
    temp.isMinus=(this->isMinus+item.isMinus)%2;
    return temp;
}

HugeInt HugeInt::operator/(HugeInt item){
    HugeInt result=0;
    HugeInt temp=0;
    if(*this<item||item==0){
        return result;
    }
    int multiple=cntDig(*this)-cntDig(item);
    if(multiple==0){
        return 1;
    }
    int cnt;
    HugeInt remainder(0);
    HugeInt gapMultiple;
    gapMultiple=mulStr(multiple);
    while(gapMultiple!=0){
        temp=temp+item*gapMultiple*10;
        result=result+gapMultiple*10;
        cnt=10;

        while(temp>*this){
            temp=temp-item*gapMultiple;
            result=result-gapMultiple;
            cnt--;
        }

        int k=gapMultiple.nums.size()-1;
        if(gapMultiple.nums[k]==1&&k==0){
            gapMultiple.nums[k]=0;
        }else if(gapMultiple.nums[k]==1&&k!=0){
            gapMultiple.nums[k-1]=10000000;
            gapMultiple.nums.pop_back();
        }else{
            gapMultiple.nums[k]/=10;
        }

//        remainder=calRemainder(cnt,item,*this);
    }
    return result;
}

HugeInt HugeInt::operator%(HugeInt item){
    HugeInt temp=0;
    if(*this<item){
        return *this;
    }else{
        temp=*this-(*this/item)*item;
        return temp;
    }
}

bool HugeInt::operator>(HugeInt item){
    bool is=0;
    int i=this->nums.size()-1;
    if(this->nums.size()>item.nums.size()){
        is=1;
    }else if(this->nums.size()==item.nums.size()){
        while(i>=0){
            if(this->nums[i]>item.nums[i]){
                is=1;
                break;
            }else if(this->nums[i]==item.nums[i]){
                i--;
            }else{
                is=0;
                break;
            }
        }
    }
    return is;
}

bool HugeInt::operator>=(HugeInt item){
    return *this>item||*this==item;
}

bool HugeInt::operator<(HugeInt item){
    bool is=0;
    int i=this->nums.size()-1;
    if(this->nums.size()<item.nums.size()){
        is=1;
    }else if(this->nums.size()==item.nums.size()){
        while(i>=0){
            if(this->nums[i]>item.nums[i]){
                is=0;
                break;
            }else if(this->nums[i]==item.nums[i]){
                i--;
            }else{
                is=1;
                break;
            }
        }
    }
    return is;
}

bool HugeInt::operator<=(HugeInt item){
    return *this<item||*this==item;
}

bool HugeInt::operator==(HugeInt item){
    bool is=true;
    for(int i=0;i<this->nums.size();i++){
        if(this->nums[i]!=item.nums[i]){
            is=false;
            break;
        }
    }
    return is;
}

bool HugeInt::operator!=(HugeInt item){
    bool is=false;
    for(int i=0;i<this->nums.size();i++){
        if(this->nums[i]!=item.nums[i]){
            is=true;
            break;
        }
    }
    return is;
}

//巨型整数op长整型数
HugeInt HugeInt::operator+(long int item){
    HugeInt cover(item);
    return *this+cover;
}

HugeInt HugeInt::operator-(long int item){
    HugeInt cover(item);
    return *this-cover;
}

HugeInt HugeInt::operator*(long int item){
    HugeInt cover(item);
    return *this*cover;
}

HugeInt HugeInt::operator/(long int item){
    HugeInt cover(item);
    return *this/cover;
}

HugeInt HugeInt::operator%(long int item){
    HugeInt cover(item);
    return *this%cover;
}

bool HugeInt::operator>(long int item){
    HugeInt cover(item);
    return *this>cover;
}

bool HugeInt::operator>=(long int item){
    HugeInt cover(item);
    return *this>=cover;
}

bool HugeInt::operator<(long int item){
    HugeInt cover(item);
    return *this<=cover;
}

bool HugeInt::operator<=(long int item){
    HugeInt cover(item);
    return *this<=cover;
}

bool HugeInt::operator!=(long int item){
    HugeInt cover(item);
    return *this!=cover;
}

bool HugeInt::operator==(long int item){
    HugeInt cover(item);
    return *this==cover;
}

//巨型整数op字符串
HugeInt HugeInt::operator+(string item){
    HugeInt cover(item);
    return *this+cover;
}

HugeInt HugeInt::operator-(string item){
    HugeInt cover(item);
    return *this-cover;
}

HugeInt HugeInt::operator*(string item){
    HugeInt cover(item);
    return *this*cover;
}

HugeInt HugeInt::operator/(string item){
    HugeInt cover(item);
    return *this/cover;
}

HugeInt HugeInt::operator%(string item){
    HugeInt cover(item);
    return *this%cover;
}

bool HugeInt::operator>(string item){
    HugeInt cover(item);
    return *this>cover;
}

bool HugeInt::operator>=(string item){
    HugeInt cover(item);
    return *this>=cover;
}

bool HugeInt::operator<(string item){
    HugeInt cover(item);
    return *this<cover;
}

bool HugeInt::operator<=(string item){
    HugeInt cover(item);
    return *this<=cover;
}

bool HugeInt::operator!=(string item){
    HugeInt cover(item);
    return *this!=cover;
}

bool HugeInt::operator==(string item){
    HugeInt cover(item);
    return *this==cover;
}

//长整型数op巨型整数
HugeInt operator+(long int item,HugeInt &caller){
    HugeInt cover(item);
    return caller+cover;
}

HugeInt operator-(long int item,HugeInt &caller){
    HugeInt cover(item);
    return caller-cover;
}

HugeInt operator*(long int item,HugeInt &caller){
    HugeInt cover(item);
    return caller*cover;
}

HugeInt operator/(long int item,HugeInt &caller){
    HugeInt cover(item);
    return caller/cover;
}

HugeInt operator%(long int item,HugeInt &caller){
    HugeInt cover(item);
    return caller%cover;
}

bool operator>(long int item,HugeInt &caller){
    HugeInt cover(item);
    return caller>cover;
}

bool operator>=(long int item,HugeInt &caller){
    HugeInt cover(item);
    return caller>=cover;
}

bool operator<(long int item,HugeInt &caller){
    HugeInt cover(item);
    return caller<cover;
}

bool operator<=(long int item,HugeInt &caller){
    HugeInt cover(item);
    return caller<=cover;
}

bool operator!=(long int item,HugeInt &caller){
    HugeInt cover(item);
    return caller!=cover;
}

bool operator==(long int item,HugeInt &caller){
    HugeInt cover(item);
    return caller==cover;
}

//字符串op巨型整数
HugeInt operator+(string item,HugeInt &caller){
    HugeInt cover(item);
    return caller+cover;
}

HugeInt operator-(string item,HugeInt &caller){
    HugeInt cover(item);
    return caller-cover;
}

HugeInt operator*(string item,HugeInt &caller){
    HugeInt cover(item);
    return caller*cover;
}

HugeInt operator/(string item,HugeInt &caller){
    HugeInt cover(item);
    return caller/cover;
}

HugeInt operator%(string item,HugeInt &caller){
    HugeInt cover(item);
    return caller%cover;
}

bool operator>(string item,HugeInt &caller){
    HugeInt cover(item);
    return caller>cover;
}

bool operator>=(string item,HugeInt &caller){
    HugeInt cover(item);
    return caller>=cover;
}

bool operator<(string item,HugeInt &caller){
    HugeInt cover(item);
    return caller<cover;
}

bool operator<=(string item,HugeInt &caller){
    HugeInt cover(item);
    return caller<=cover;
}

bool operator!=(string item,HugeInt &caller){
    HugeInt cover(item);
    return caller!=cover;
}

bool operator==(string item,HugeInt &caller){
    HugeInt cover(item);
    return caller==cover;
}
int cntDig(HugeInt item){
    int cnt=0;
    if(item.getNums().size()==0){
        return 0;
    }
    int topNums=item.getNums().back();
    while(topNums!=0){
        topNums/=10;
        cnt++;
    }
    cnt+=(item.getNums().size()-1)*8;
    return cnt;
}

string mulStr(int multiple){
    string result="1";
    for(int i=0;i<multiple;i++){
        result+="0";
    }
    return result;
}

HugeInt calRemainder(int cnt,HugeInt item,HugeInt caller){
    HugeInt temp;
    int end=caller.getNums().size()-1;
    for(int i=0;i<=cntDig(caller)-cntDig(item);i++){
        for(int j=0;j<end;j++){
            caller.getNums()[j]=caller.getNums()[j]/10+caller.getNums()[j+1]%10*10000000;
        }
    }

    temp=caller-item*cnt;
    return temp;
}

int main(){
    HugeInt a("44556677223388993212646546846");
    HugeInt b("12");
    cout<<a<<endl;
    cout<<b<<endl;
    a=a/b;
    cout<<a<<endl;
    return 0;
}