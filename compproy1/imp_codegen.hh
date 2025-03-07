#ifndef IMP_CODEGEN
#define IMP_CODEGEN

#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <fstream>

#include "imp.hh"
#include "imp_visitor.hh"
#include "environment.hh"
#include "imp_typechecker.hh"

class ImpCodeGen : public ImpVisitor {
public:
  ImpCodeGen();
  ImpCodeGen(ImpTypeChecker checker);
  void codegen(Program*, string outfname);
  int visit(Program*);
  int visit(Body*);
  int visit(VarDecList*);
  int visit(VarDec*);
  int visit(StatementList*);
  int visit(AssignStatement*);
  int visit(PrintStatement*);
  int visit(IfStatement*);
  int visit(WhileStatement*);
  int visit(DoWhileStatement*);

  
  int visit(BinaryExp* e);
  int visit(UnaryExp* e);
  int visit(NumberExp* e);
  int visit(IdExp* e);
  int visit(ParenthExp* e);
  int visit(CondExp* e);
  int visit(BoolExp* e);

private:
  std::ostringstream code;
  string nolabel;
  int current_label;
  ImpTypeChecker checker;
  Environment<int> direcciones;
  int siguiente_direccion, mem_locals;
  void codegen(string label, string instr);
  void codegen(string label, string instr, int arg);
  void codegen(string label, string instr, string jmplabel);
  string next_label();
};


#endif

