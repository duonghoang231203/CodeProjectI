#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::unordered_set<std::string> database;//dung de luu tru cac khoa
    
    // Read the initial key sequence
    std::string key;
    while (std::cin >> key) {
        if (key == "*") {
            break;
        }
        database.insert(key);//dung de chen vao 'database' bang cach su  dung insert cua 'unordered_set'
    }
    
    std::string cmd, k;
    while (std::cin >> cmd >> k) {//doc hai chuoi la 'cmd'(lenh hanh dong) va 'k'(khoa)
        if (cmd == "find") {
            if (database.find(k) != database.end()) {//kiem tra xem khoa k co ton tai trong database hay ko, co in 1, ko co in 0
                std::cout << "1" << std::endl;
            } else {
                std::cout << "0" << std::endl;
            }
        } else if (cmd == "insert") {
            if (database.find(k) != database.end()) {//nghia la k da dc tim thay trong database, kiem tra xem khoa k co ton tai trong database hay ko, co in 0, ko co in 1
                std::cout << "0" << std::endl;
            } else {
                database.insert(k);
                std::cout << "1" << std::endl;
            }
        } else if (cmd == "***") {
            break;
        }
    }
    
    return 0;
}
//database.end() chi su ket thuc cua tap hop
//coi database.find(k) la 1, database.end() la 0
