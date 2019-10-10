#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Operation {
private:
    char marker;
public:
    Operation(char marker) {
        this->marker = marker;
    }

    double process(double a, double b) {
        switch (marker) {
            case '+': {
                return a + b;
            }
            case '-': {
                return a - b;
            }
            case '*': {
                return a * b;
            }
            case '/': {
                return a / b;
            }
            default: {
                return a + b;
            }
        }
    }
};

class Parser {
private:
    string expression;
    stack<double> st;

    bool isDigit(char c) {
        return (47 < c && c < 58);
    }

    bool isDelimiter(char c) {
        return c == ':';
    }

public:
    Parser(const string &expression) {
        this->expression = expression;
    }

    double calculate() {
        string s = "";
        for (int i = 0; i < expression.length(); ++i) {
            char c = expression[i];
            if (isDigit(c) || c == '.') {
                s += c;
                continue;
            }
            if (isDelimiter(c)) {
                st.push(stod(s));
                s = "";
                continue;
            }
            if (s.length()>0){
                st.push(stod(s));
            }
            s = "";
            Operation operation(c);
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            double value = operation.process(a, b);
            st.push(value);
        }
        return st.top();
    }
};


int main() {
    Parser p("2:3+10*10:10/+25.5:1/*");
    cout << p.calculate();
    return 0;
}



