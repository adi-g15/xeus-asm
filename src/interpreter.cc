/**
 * SPDX-License-Identifier: Apache-2.0
 *
 * @file    interpreter.cc
 * @brief   contains implementation for interpreter function
 */

#include "xasm/interpreter.hpp"

string Register::toString() const{
  stringstream ss;
  ss << "Registers\nA\t" << A << "\nBC\t" << B << "\t" << C << "\nDE\t" << D
     << "\t" << E << "\nHL\t" << H << "\t" << L << "\nPC\t" << PC << "\n";
  ss << "Flags\nS\tZ\tAC\tP\tAC\n" << S << "\t" << Z << "\t" << AC << "\t"
      << P << "\t" << C << "\n";
  return ss.str();
}

Interpreter::Interpreter() {

  for (int i = 0; i < 7; i++)
    registers[i] = "NULL";
  for (int i = 0; i < 8; i++)
    flag[i] = false;

  start = "";
  pc = "";
}

Register Interpreter::getRegister() {
  Register resister = {registers[0], registers[1], registers[2], registers[3],
                       registers[4], registers[5], registers[6], pc,
                       flag[7],      flag[6],      flag[4],      flag[2],
                       flag[0]};
  return resister;
}

void Interpreter::set_address(string start ) {
  pc = start;
}


// store in Memory
// store hlt too
// execute the line
// check error
// return flag
bool Interpreter::execute(const string &line) {
  Memory[pc] = line;
  pc = executionCode(Memory[pc], registers, flag, Memory, pc, last_error);
  if (last_error != "") {
    return false;
  }
  return true;
}

/*
// @note @mergeconflict sarita singh's commit; @adig solve later
void Interpreter::multiLine() {
  cin.ignore();
  cout << "\nEnter the code:\n";
  while (1) {
    cout << ">> " << pc << " ";
    string line;
    getline(cin, line);
    Memory[pc] = line;
    cout<<line<<"\n";
    sequence.push_back(pc);
    if (line == "HLT") {
      break;
    }
    pc = updatedAddress(pc, Memory);
}
*/

string Interpreter::get_error() { return last_error; }
