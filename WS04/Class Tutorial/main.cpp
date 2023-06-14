#include <iostream>
#include <string>

// Validate Age

// Read about `trailing return`!!

auto get(std::istream& is) -> std::istream& {
    bool done = false;

    do {
        if (is >> value) {
            done = validate(value, errMsg);
        }
        else {
            errMsg = "Invalid Int";
            is.clear();
            done = false;
        }
        is.ignore(1000, '\n');
    } while (!done && cout << errMsg);
}

bool validate(int val, std::string errMsg) {
    return true;
}

class Int {
    int value;
    std::string errMsg;
public:
    bool (*validate) (int, std::string); // Pointer to `validate()`
};

int main(void) {

    Int(int v, auto (*validate) (int, std::string&) -> bool);

    void setValidation(auto (*v) (int, std::string&) -> bool);

    bool (* funcPtr) (int, std::string);

    funcPtr = validate; // Must be the same signature

    return 9;
}

