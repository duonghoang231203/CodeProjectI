#include <bits/stdc++.h> 
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    if (s.length() == 8 && s[2] == ':' && s[5] == ':') {
        int hh, mm, ss;
        
        std::stringstream ss_stream(s);// de phan tach chuoi 's' thanh ba phan
        char colon;// luu ky tu dau hai cham

        if (ss_stream >> hh >> colon >> mm >> colon >> ss) {
            if (0 <= hh && hh <= 23 && 0 <= mm && mm <= 59 && 0 <= ss && ss <= 59) {
                int total_seconds = hh * 3600 + mm * 60 + ss;
                std::cout << total_seconds << std::endl;
            } else {
                std::cout << "INCORRECT" << std::endl;
            }
        } else {
            std::cout << "INCORRECT" << std::endl;
        }
    } else {
        std::cout << "INCORRECT" << std::endl;
    }

    return 0;
}

