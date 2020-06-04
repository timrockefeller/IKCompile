#pragma once
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
//定义文法类，保存文法个数和记录所有文法
const unsigned int N = 100;
namespace IKC {

class Grammar {
   public:
    //保存所有文法
    std::unordered_map<int, std::vector<std::vector<int>>> grammarTable;
    //保存终结字符
    char terminalChar[N];
    //保存终结字符的个数
    int terNum;
    //保存每行的产生式的个数
    int countEachRow[N];
    //定义文法数量
    int count;
    Grammar() {
        terNum = 0;
    }
};

//保存每个非终结符的FIRST集合
class FIRST {
   public:
    //保存每个非终结符的FIRST集合
    std::set<char> First[N];
    //保存非终结符
    char nonTerminal[N];
    //保存是否计算出相应的FIRST集
    bool flag[N] = {0};
    //保存已计算FIRST集的个数
    int calCount;

    FIRST() {
        calCount = 0;
    }
};
class Position {
   public:
    int x;
    int y;
    Position() {
        x = -1;
        y = -1;
    }
};
//保存每个非终结符的FOLLOW集合
class FOLLOW {
   public:
    //保存每个非终结符的FOLLOW集合
    std::set<char> Follow[N];
    //保存非终结符
    char nonTerminal[N];
    //保存是否计算出相应的FOLLOW集
    bool flag[N] = {0};
    //保存已计算Follow集的个数
    int calCount;
    //保存产生式的索引
    std::vector<Position> position[N];

    FOLLOW() {
        calCount = 0;
    }
};

//定义预测分析表
using AnalyseTable = std::string[N][N];
//检测一个字符是否为非终结字符
bool isNonTerminal(char var);
//检测一个字符是否为空字
bool isEmpty(char var);
//检测一个字符是否为终结字符
bool isTerminal(char var);
//从控制台读取文法并保存
void readGrammar();
//判断一个产生式是否能求出FIRST集，能返回true，否则false
bool canCalFIRST(int i);
//计算能够计算FIRST集的产生式
void calFIRST();
//获取其非终结字符所在的索引
int getNonTerminalIndex(char var);
//检测第i个FIRST集是否有空字
bool hasEmpty(int i);
//判断是否能计算FIRST集(首字符含非终结符)
bool adjustFIRST(int i);
//计算两个集合的并集，即set(i) = set(i) ∪ set(j)
void calSetUnion(int i, int j);
//更新calCount
int reloadCalCount();
//计算FIRST集
void calFIRSTSet();
//输出first集
void printFIRST();
//获取索引（每一个非终结符在产生式的索引，索引保存在容器中）
void getPosition();
//将FIRST集去空加入FOLLOW集，i代表FOLLOW,i代表FIRST集
void calFollowAndFirstUnion(int i, int j);
//计算两个FOLLOW集的并集,即set(i) = set(i) ∪ set(j)
void calFollowAndFollowUnion(int i, int j);
//更新FOLLOW集的calCount
int reloadFOLLOWCalCount();
//计算FOLLOW集
void calFOLLOWSet();
//获取每一个非终结符的FOLLOW集
void getFollowSet();
//打印FOLLOW集
void printFOLLOW();
//获取终结符在Grammar.terminal[]中的索引
int getTerminalIndex(char var);
//构建单个产生式的First集,i,j为相应产生式的索引
std::set<char> buildFirstForOne(int i, int j);
//将产生式字符转为字符串,i,j为相应产生式的索引
std::string charToString(int i, int j);
//构建预测分析表
void bulidAnalyseTable();
//打印预测分析表
void printAnalyseTable();
//将vector中的字符转化为字符串
std::string veToString(std::vector<char>& vec);
//将字符数组有选择的转化为字符串
std::string toString(char buf[], int start, int end);
//核心函数，对语法进行分析
void analyseGrammar();

}  // namespace IKC
