#include "Array.h"

std::string ArrayException::getMessage() {
    return messageText;
}

std::string nonExistentIndex::getMessage() {
    return ArrayException::getMessage();
}