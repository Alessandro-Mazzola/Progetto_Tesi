#ifndef CMPPLUGIN_H
#define CMPPLUGIN_H

#include <string>

class CmpPluginInt {
  public:
    CmpPluginInt() {}
    ~CmpPluginInt() {}

    std::string to_string() {
        std::string str("[");
        str.append(std::to_string(id));
        str.append("]  ");
        str.append(package);
        str.append("::");
        str.append(type);
        return str;
    }

    int id;
    std::string type;
    std::string package;
    std::string info="Plugin";
};

#endif // CMPPLUGIN_H
