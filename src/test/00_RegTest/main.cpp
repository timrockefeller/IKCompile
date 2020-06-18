#include <iostream>
// #include <string>
// #include <cmath>
// #include <vector>
// #include <stdio.h>
#include <regex>
using namespace std;
int main() {
    char *a = "VAR ABC";
    string str = "VAR ABV";
    cmatch rerResult;
    std::regex e ("^(VAR)");
    bool bValid = regex_search("VAR ABV", rerResult, e);
    if (bValid) {
        cout << rerResult.position();
    }
    return 0;
}
