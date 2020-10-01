#ifndef CMPPROPERTY_H
#define CMPPROPERTY_H

#include <string>

#define OWNER_ACTIVITY 		"OWNER_ACTIVITY"
#define OWNER_PLUGIN 		"OWNER_PLUGIN"

class CmpProperty {
  public:
    CmpProperty() {}
    ~CmpProperty() {}

    std::string to_string() {
        std::string str("[");
        str.append(std::to_string(id));
        str.append("]  (");
        str.append(std::to_string(id_owner));
        str.append(") ");
        str.append(owner);
        str.append("::");
        str.append(type);
        str.append(":");
        str.append(name);
        str.append(" {");
        str.append(domain);
        str.append("}");

        return str;
    }

    int id;
    int id_owner;
    std::string owner;
    std::string name;
    std::string type;
    std::string domain;
    std::string info="Property";
};
#endif // CMPPROPERTY_H
