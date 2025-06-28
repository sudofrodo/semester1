#include <iostream>

void card_art() {
    std::cout << "//                      _     " << std::endl;
    std::cout << "//                     | |    " << std::endl;
    std::cout << "//     ___ __ _ _ __ __| |___ " << std::endl;
    std::cout << "//    / __/ _` | '__/ _` / __|" << std::endl;
    std::cout << "//   | (_| (_| | | | (_| \\__ \\" << std::endl; // Note the escaped backslash
    std::cout << "//    \\__\\__,_|_|  \\__,_|___/" << std::endl; // Note the escaped backslash
    std::cout << "//                            " << std::endl;
    std::cout << "//                            " << std::endl;
}
int main() {
    card_art();
}
