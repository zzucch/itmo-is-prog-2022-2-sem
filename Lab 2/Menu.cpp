#include "Menu.h"

Menu::Menu() {
  invalid_size_message_ = "Error. Provided invalid subset size\n";
  out_of_range_message_ = "Error. Provided argument is out of range\n";
  not_enough_args_ = "Error. 2 or more subsets are required.\n";
  invalid_command_message_ = "Error. Command not found\n";
  vector_ = std::vector<Subset>();

  std::cout << "MENU: Integer subsets\n\n";
  std::cout << "First subset creation:\n";
  CreateNewSubset();
  GetCommands();
}

void Menu::GetCommands() {
  std::string command;
  std::cout << "\nEnter 'help' for a list of available commands\n";

  while (std::cin >> command) {
    if (command == "help") {
      PrintHelp();
    } else if (command == "create") {
      CreateNewSubset();
    } else if (command == "add") {
      AddValue();
    } else if (command == "remove") {
      RemoveValue();
    } else if (command == "plus") {
      PlusOperator();
    } else if (command == "minus") {
      MinusOperator();
    } else if (command == "multi") {
      MultiplyOperator();
    } else if (command == "print") {
      PrintData();
    } else if (command == "quit") {
      return;
    } else {
      std::cout << invalid_command_message_;
    }
  }
}

void Menu::PrintHelp() {
  std::cout << "List of all available commands:\n";
  std::cout << "help\tLists all available commands\n";
  std::cout << "print\tPrints subset's data\n";
  std::cout << "create\tCreates new subset\n";
  std::cout << "add\tAdds new value to the subset\n";
  std::cout << "remove\tRemoves value from the subset\n";
  std::cout << "plus\tSummarizes two subsets\n";
  std::cout << "minus\tSubtracts second subset from first one\n";
  std::cout << "multi\tMultiplies two subsets\n";
  std::cout << "quit\tQuits the menu\n";
}

void Menu::CreateNewSubset() {
  std::string command;

  std::cout << "Would you like to use default values? (Y/n)\n";
  std::cin >> command;

  if (command[0] == 'N' || command[0] == 'n') {
    int size = -1;
    std::cout << "Enter the subset's max size:\n";
    GetSize(size);

    vector_.emplace_back(size);

    std::cout << "New subset is created.\n";
  } else {
    vector_.emplace_back();

    std::cout << "New default subset is created.\n";
  }

  std::cout << "This subset's ID is " << vector_.size() - 1 << ".\n";
}

void Menu::AddValue() {
  int id1 = 0;
  int val;
  HandleOneId(id1, val);

  vector_[id1].AddValue(val);
  std::cout << "Success.\n";
}

void Menu::RemoveValue() {
  int id1 = 0;
  int val;
  HandleOneId(id1, val);

  vector_[id1].RemoveValue(val);
  std::cout << "Success.\n";
}

void Menu::PlusOperator() {
  int id1, id2, res;
  if (!HandleThreeIds(id1, id2, res)) {
    return;
  }

  vector_[res] = vector_[id1] + vector_[id2];
  std::cout << "Success.\n";
}

void Menu::MinusOperator() {
  int id1, id2, res;
  if (!HandleThreeIds(id1, id2, res)) {
    return;
  }

  vector_[res] = vector_[id1] - vector_[id2];
  std::cout << "Success.\n";
}

void Menu::MultiplyOperator() {
  int id1, id2, res;
  if (!HandleThreeIds(id1, id2, res)) {
    return;
  }

  vector_[res] = vector_[id1] * vector_[id2];
  std::cout << "Success.\n";
}

void Menu::PrintData() {
  int subset_id = 0;
  if (vector_.size() > 1) {
    std::cout << "What subset to print?\n";
    HandleOutOfRange(subset_id);
  }

  std::cout << vector_[subset_id];
}

void Menu::HandleOneId(int &id1, int &val) {
  if (vector_.size() > 1) {
    std::cout << "What subset to change?\n";
    HandleOutOfRange(id1);
  }

  std::cout << "What value?\n";
  std::cin >> val;
}

bool Menu::HandleThreeIds(int &id1, int &id2, int &res) {
  if (vector_.size() < 2) {
    std::cout << not_enough_args_;
    return false;
  }

  std::cout << "Enter first subset's ID:\n";
  HandleOutOfRange(id1);

  std::cout << "Enter second subset's ID:\n";
  HandleOutOfRange(id2);

  std::cout << "Enter where the result will be:\n";
  HandleOutOfRange(res);

  return true;
}

void Menu::HandleOutOfRange(int &arg) {
  arg = -1;
  while (arg >= vector_.size() || arg < 0) {
    std::string buffer;
    std::cin >> buffer;

    if (!std::isdigit(buffer[0])) {
      std::cout << invalid_data_message_;
      std::cout << "Try again.\n";
      continue;
    } else if (arg >= vector_.size() || arg < 0) {
      std::cout << out_of_range_message_;
      std::cout << "Try again.\n";
      continue;
    }

    arg = std::stoi(buffer);
  }
}

void Menu::GetSize(int &size) {
  while (size < 1) {
    std::string buffer;
    std::cin >> buffer;

    if (!isdigit(buffer[0])) {
      std::cout << invalid_size_message_;
      std::cout << "Try again.\n";
      continue;
    }

    size = std::stoi(buffer);
  }
}
