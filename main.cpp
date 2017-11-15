
#include<iostream>
#include <assert.h>
#include <sstream>

using namespace std;

//define the datestruct
template <typename E> class Stack {
private:
    void operator =(const Stack&){}
    Stack(const Stack&){}

public:
    Stack(){}
    virtual ~Stack(){}
    virtual void clear() = 0;
    virtual void push(const E& it) = 0;
    virtual E pop() = 0;
    virtual const E& topValue() const = 0;
    virtual int length() const = 0;
};

template <typename E> class AStack : public Stack<E>{
private:
    int maxSize;
    int top;
    E *listArray;

public:
    AStack(int size = 10){
        maxSize = size; top = 0; listArray = new E[size];
    }//Constructor

    ~AStack(){
        delete [] listArray;
    }//Destructor

    void clear(){
        top = 0;
    }//Reinitialize

    void push(const E& it){
        assert(top != maxSize);
        listArray[top++] = it;
    }//Push "it" to Stack

    E pop(){
        assert (top != 0 );
        return listArray[--top];
    }//Pop top element

    const E& topValue() const{
        assert(top != 0);
        return listArray[top-1];
    }//Return top element

    int length() const { return top;}//Return length
};

int prior (char a){
    int priority ;
    switch (a){
        case '+':
        {
            priority = 1;
            break;
        }
        case '-':
        {
            priority = 1;
            break;
        }
        case '*':
        {
            priority = 2;
            break;
        }
        case '/':{
            priority = 2;
            break;
        }
        case '(':{
            priority = 3;
            break;
        }
        case '#':{
            priority = 4;
            break;
        }
    }

    return priority;
}

//得到结果
double getResult(string sourse){
    string buff;
    int len = sourse.length();
    int i = 0;
    int j = 0;
    double result = 0;
    double temp[2];
    AStack<double> num(len);
    stringstream ss(sourse);
    while (ss >> buff) {
        if (buff == "+") {
            temp[1] = num.pop();
            temp[0] = num.pop();
            result = temp[0] + temp[1];
            num.push(result);
        } else if (buff == "-") {
            temp[1] = num.pop();
            temp[0] = num.pop();
            result = temp[0] - temp[1];
            num.push(result);
        } else if (buff == "*") {
            temp[1] = num.pop();
            temp[0] = num.pop();
            result = temp[0] * temp[1];
            num.push(result);
        } else if (buff == "/") {
            temp[1] = num.pop();
            temp[0] = num.pop();
            result = temp[0] / temp[1];
            num.push(result);
        } else if (buff == "/") {
            temp[1] = num.pop();
            temp[0] = num.pop();
            result = temp[0] / temp[1];
            num.push(result);
        } else if (buff == "#") {
            result = (-1) * num.pop();
            num.push(result);
        } else {
            result = atof(buff.data());
            num.push(result);
        }
    }
    result = num.pop();
    return result;
}

//输入检测
bool isOK(string s){
    bool isExp = 1;
    int len = s.length();
    int result = 0;
    //括号匹配
    for (int i = 0; i < len; ++i) {
        if(s[i] =='('){
            result++;
            //括号内容检测
            if(i<len-1&&s[i+1]==')'){
                isExp=0;
                cout<<"There is nothing in the ()"<<endl;
            }
        }else if (s[i] == ')'){
            result--;
            if(result < 0){//括号顺序检测
                cout<<"Lack of ("<<endl;
               return isExp = 0;
            }
            if(i<len-1) {
                switch (s[i + 1]) {
                       case '#':
                       case '0':
                       case '1':
                       case '2':
                       case '3':
                       case '4':
                       case '5':
                       case '6':
                       case '7':
                       case '8':
                       case '9':
                       case '.':
                           cout << "Lacking operator after ')'" << endl;
                            isExp = 0;
                }
            }
        }
        //字符内容判断
        switch (s[i]){
            //连续操作符判断
            case '+':
            case '-':
            case '*':
            case '/':{
                if(i<len-1){
                    switch (s[i+1]) {
                        case '+':
                        case '-':
                        case '*':
                        case '/':
                        case '.':
                            cout<<"There have double operation together"<<endl;
                            isExp = 0;//(3+2*5)/3
                    }
                }
            }
            case '(':
            case ')':
            case '#':
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '.':
                break;
            default:{
                cout<<"Wrong expression!"<<endl;
                isExp = 0;
               return isExp ;
            }
        }
//test
        if(s[i] == '.'){
            int j =i+1 ;
            while(j<len){
                if (s[j] =='+'||s[j] =='/'||s[j] =='-'||s[j] =='*'){
                     break;
                }else if(s[j] =='.'){
                    cout<<"This is a wrong expression with two '.' together"<<endl;
                    isExp = 0;
                }
                j++;
            }
        }
    }
    //首尾检测
    switch (s[0]){
        case '+':
        case '-':
        case '*':
        case '/':
        case '.':
            cout<<"Wrong expression at the first"<<endl;
            isExp = 0;
    }
    switch (s[len-1]){
        case '.':
        case '+':
        case '-':
        case '*':
        case '/':
            cout<<"Wrong expression at the Last"<<endl;
            isExp = 0;
    }
    if(result > 0){
        cout<<"Lack of )"<<endl;
        isExp = 0;
    }
    return isExp;
}
//转后缀
void expget(string str){
    //转换及拼写检查
    int len=str.length();
    string temp;
    int i=0,j=0;
    while(i<len){
        if(str[i]==' '){
            i++;
            continue;
        }
        temp += str[i++];
    }
    if(!isOK(temp)){
        cout<<"This is not a expression !"<<endl;
        return;
    }
    //中缀向后缀处理
    j=0;
    len=temp.length();
    string buff;
    string String;//2-3.0/1+(12/3)
    AStack <char> buffer1(len);
    while(j<len){
        switch(temp[j]){
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
            case ')':
            case '#':
            {
                if(buffer1.length() == 0|| temp[j] == '('){
                    buffer1.push(temp[j]);
                }else{
                    if(prior(buffer1.topValue()) < prior(temp[j])||buffer1.topValue() == '('){
                        buffer1.push(temp[j]);
                    }else{
                        if(temp[j] == ')'){
                            while(buffer1.topValue() != '('){
                                String += buffer1.pop();
                                String += ' ';
                            }
                            buffer1.pop();
                         //   buffer1.pop();
                        }else{
                            while(prior(buffer1.topValue()) >= prior(temp[j])){
                                String += buffer1.pop();
                                String += ' ';
                                if(buffer1.length() == 0){
                                    break;
                                }
                            }
                            buffer1.push(temp[j]);
//                            String += temp[j];
//                            String += ' ';
                        }
                   }
                }
                j++;
                break;
            }

            default:
            {
                buff.clear();
                while(isdigit(temp[j])||temp[j]=='.'){
                    buff += temp[j++];
                }
                String += buff;
                String += ' ';
                break;
            }
        }

    }
    while (buffer1.length() != 0){
        String += buffer1.pop();
        String += ' ';
    }
    cout<<"The suffix is "<<String<<endl;
    double result = getResult(String);
    cout<<"The result is "<<result<<endl;
    return;
}
//业务逻辑代码
void todo(){

    cout<<"Please print your expression:"<<endl;
    string will,exp;
    cin>>exp;
    expget(exp);
    cout<<"Do you want to exist? Yes=1,No=0"<<endl;
    cin>>will;
    if(will == "1")
        exit(0);
    else
        todo();
    return;
}

int main(){
    todo();
    return 0;
}