#include <PL0/ASTBuild.h>
#include <Utils/File.h>

#include <iostream>
using namespace std;
using namespace IKCL;
using namespace KTKR;
int main() {
    File file = File("test.PL0", File::READ);
    auto rc = ASTBuild::Tokenizer(file.ReadAll());
    for(auto t : rc){
        cout << t;
    }
    return 0;
}
