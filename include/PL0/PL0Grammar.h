#pragma once
#include <Compiler/ASTNode.h>

#include <unordered_map>
namespace IKCL {

enum PL0ASTType {
    Odd,
    Expression,
    Assignment,
    Call,
    Write,
    CompoundStatement,
    IfThen,
    While,
    Block,
    Procedure,
    Program,
    Symbol
};
// definations
class ProgramNode;
class BlockNode;
class ProcedureNode;
class AssignmentNode;
class SymbolNode;
class ExpressionNode;
class CallNode;
class WriteNode;
class CompoundStatementNode;
class IfThenNode;
class WhileNode;
// implements

class BlockNode : public ASTNode<PL0ASTType> {
   public:
    BlockNode()
        : ASTNode(Block) {
        symbol = std::unordered_map<std::string, SymbolNode>();
        procedure = std::vector<ProcedureNode>();
        }
    ASTNode statement;
    std::unordered_map<std::string, SymbolNode> symbol;
    std::vector<ProcedureNode> procedure;
};
class ProcedureNode : public ASTNode<PL0ASTType> {
   public:
    ProcedureNode()
        : ASTNode(Procedure) {}
    std::string name;
    BlockNode block;
};

class SymbolNode : public ASTNode<PL0ASTType> {
   public:
    SymbolNode()
        : ASTNode(Symbol) {}
    bool isConst;
    float val;
};
class ExpressionNode : public ASTNode<PL0ASTType> {
   public:
    ExpressionNode()
        : ASTNode(Expression) {}
};
class AssignmentNode : public ASTNode<PL0ASTType> {
   public:
    AssignmentNode()
        : ASTNode(Assignment) {}
    std::string identifier;
    ExpressionNode expression;
};
class CallNode : public ASTNode<PL0ASTType> {
   public:
    CallNode()
        : ASTNode(Call) {}
        
    std::string identifier;
};
class WriteNode : public ASTNode<PL0ASTType> {
   public:
    WriteNode()
        : ASTNode(Write) {}
        
    std::string identifier;
};
class CompoundStatementNode : public ASTNode<PL0ASTType> {
   public:
    CompoundStatementNode()
        : ASTNode(CompoundStatement) {
        statements = std::vector<ASTNode>();
        }
    std::vector<ASTNode> statements;
};
class IfThenNode :public ASTNode<PL0ASTType> {
   public:
    IfThenNode()
        : ASTNode(IfThen) {}
    ASTNode condition;
    ASTNode statement;
};
class WhileNode :public ASTNode<PL0ASTType> {
   public:
    WhileNode()
        : ASTNode(While) {}
    ASTNode condition;
    ASTNode statement;
};
class ProgramNode : public ASTNode<PL0ASTType> {
   public:
    ProgramNode()
        : ASTNode(Program) {}
    BlockNode block;
};
}  // namespace IKCL
