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
            // for (Token<PL0Pattern> t : rc) {
            //     cout << t;
            // }
            PL0AST p = ASTBuild::Parser(rc);
        } catch (string e) {
            std::cout << "[!!] Unexpected Token at :" << e << '\n';
        }
    } else {
        cout << "cant open file" << endl;
    }
    return 0;
}
