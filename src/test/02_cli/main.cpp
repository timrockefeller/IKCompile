#include <PL0/ASTBuild.h>
#include <Utils/Utils.h>
#include <windows.h>

#include <iomanip>
#include <iostream>
using namespace std;
using namespace IKCL;
using namespace KTKR;
int main(int argc, char* argv[]) {
    View::getInstance()->Init();
    ArgHandle::getInstance()
        ->BindCommand("help", 0, [&](vector<string> args) {
            cout << "IKCL-PL0 client commands:" << endl
                 << endl;
            cout << "  tok   <file>                 --- List Tokens of the file." << endl;
            cout << "  par   <file>                 --- Parse the file." << endl;
            cout << "  bye                          --- Exit the client." << endl;
            cout << endl;
        })
        ->BindCommand("bye", 0, [&](vector<string> args) {
            cout << "Bye!" << endl;
            ArgHandle::getInstance()->Exit();
        })
        ->BindCommand("tok", 1, [&](vector<string> args) {
            File file = File(args[0], File::READ);
            if (file.IsValid()) {
                try {
                    PL0Tokens rc = ASTBuild::Tokenizer(file.ReadAll(), true);
                    int i = 0;
                    cout << setw(4) << "no"
                         << "|"
                         << setw(10) << "type"
                         << "|"
                         << "src" << endl;
                    cout << "----+----------+-----" << endl;
                    for (Token<PL0Pattern> t : rc) {
                        cout << setw(4) << i++
                             << "|"
                             << setw(10) << PL0Pattern_s[t.token]
                             << "|" << t << endl;
                    }
                } catch (string e) {
                    std::cout << e << '\n';
                }
            } else {
                cout << "cant open file" << endl;
            }
        })
        ->BindCommand("par", 1, [&](vector<string> args) {
            File file = File(args[0], File::READ);
            if (file.IsValid()) {
                try {
                    PL0Tokens rc = ASTBuild::Tokenizer(file.ReadAll(), true);
                    PL0AST p = ASTBuild::Parser(rc);
                    cout << "[v] parse completed" << endl;
                } catch (string e) {
                    std::cout << e << '\n';
                    std::cout << "on token " << ASTBuild::getCurIndex() << endl;
                    std::cout << "use \"tok\" command for more info." << endl;
                }
            } else {
                cout << "cant open file" << endl;
            }
        });
    if (argc <= 1) {
        cout << " use \"help\" command for more informations.\n"
             << endl;
    } else {
        ArgHandle::getInstance()->Parse(argc, argv);
    }

    return 0;
}
