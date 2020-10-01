#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component {
  public:
    Component() {}
    Component(std::string package, std::string type) {
            this->package = package;
            this->type = type;
        }
    Component(std::string category, std::string package, std::string type, int id) {
            this->category = category;
            this->package = package;
            this->type = type;
            this->id = id;
        }
    ~Component() {}

    std::string to_string() {
        std::string str("[");
        str.append(std::to_string(id));
        str.append("]  ");
        str.append(category);
        str.append("  ");
        str.append(package);
        str.append("::");
        str.append(type);
        return str;
    }

    int id;
    std::string category;
    std::string package;
    std::string type;
    std::string info="Component";
};

#endif // COMPONENT_H
