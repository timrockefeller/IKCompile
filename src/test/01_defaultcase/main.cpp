#include <PL0/ASTBuild.h>
#include <Utils/File.h>

#include <iostream>
using namespace std;
using namespace IKCL;
using namespace KTKR;
int main() {
    File file = File("asset/test.PL0", File::READ);
    if (file.IsValid()) {
        try {
            PL0Tokens rc = ASTBuild::Tokenizer(file.ReadAll(), true);
            for (Token<PL0Pattern> t : rc) {
                cout << t;
            }
        } catch (const std::exception& e) {
            std::cerr << "[!!] Unexpected Token at :" << e.what() << '\n';
        }
    } else {
        cout << "cant open file" << endl;
    }
    return 0;
}
