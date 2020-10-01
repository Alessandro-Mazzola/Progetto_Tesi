#ifndef CMPFUNCTIONALITY_H
#define CMPFUNCTIONALITY_H

#include <string>

class CmpFunctionality {
  public:
    CmpFunctionality() {}
    ~CmpFunctionality() {}

    std::string to_string() {
        std::string str("[");
        str.append(std::to_string(id));
        str.append("] A:");
        str.append(std::to_string(id_activity));
        str.append(" I:");
        str.append(std::to_string(id_plugin_int));
        str.append(" ");
        str.append(name);

        return str;
    }

    int id;
    int id_activity;
    int id_plugin_int;
    std::string name;
    std::string info="Functionality";
};

#endif // CMPFUNCTIONALITY_H
