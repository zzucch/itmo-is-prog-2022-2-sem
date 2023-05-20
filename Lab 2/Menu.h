#ifndef INC_2_MENU_H_
#define INC_2_MENU_H_

#include "Subset.h"
#include <iostream>
#include <vector>

class Menu {
 public:
  Menu();

  void GetCommands();
  static void PrintHelp();
  void AddValue();
  void CreateNewSubset();
  void RemoveValue();
  void PlusOperator();
  void MinusOperator();
  void MultiplyOperator();
  void PrintData();

  void HandleOneId(int &, int &);
  bool HandleThreeIds(int &, int &, int &);
  void HandleOutOfRange(int &);
  void GetSize(int &);

 private:
  std::string invalid_data_message_;
  std::string invalid_size_message_;
  std::string out_of_range_message_;
  std::string not_enough_args_;
  std::string invalid_command_message_;

  std::vector<Subset> vector_;
};

#endif //INC_2_MENU_H_
