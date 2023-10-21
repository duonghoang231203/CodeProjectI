#include <iostream>
#include <stack>
#include <string>

bool isCorrectExpression(const std::string& s) {//const dai dien cho mot tham chieu khong thay doi. Viec su dung tham chieu (string&) giup truyen chuoi vao ham ma khong can sao chep du lieu
    std::stack<char> bracketStack;

    for (std::size_t i = 0; i < s.length(); ++i) {//kieu size_t la kieu du lieu khong am dung de bieu dien chuoi, mang, vector,... 
        char c = s[i];//dung de lay ki tu i trong chuoi gan cho c
        
        if (c == '(' || c == '{' || c == '[') {
            bracketStack.push(c);//neu la dau ngoac mo, day vao stack
        } else if (c == ')' || c == '}' || c == ']') {
            if (bracketStack.empty()) {
                return false;//kiem tra stack co rong hay khong, neu rong tuc la khong co dau mo tuong ung, false
            }

            char top = bracketStack.top();
            bracketStack.pop();//pop top ra khoi stack, duoc dat truoc if de dam bao dau ngoac mo tuong ung da duoc loai khoi stack. Viec nay nham dam bao stack chi chua cac dau ngoac mo chua duoc dong

            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return bracketStack.empty();
}

int main() {
    std::string expression;
    std::getline(std::cin, expression);

    bool result = isCorrectExpression(expression);
    std::cout << (result ? 1 : 0) << std::endl;

    return 0;
}
