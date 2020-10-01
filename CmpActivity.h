#ifndef CMPACTIVITY_H
#define CMPACTIVITY_H

#include <string>

class CmpActivity {
  public:
    CmpActivity() {}
    CmpActivity (std::string name, std::string package, std::string type, int id,int id_component) {
            this->name = name;
            this->package = package;
            this->type = type;
            this->id = id;
            this->id_component = id_component;
        }
    ~CmpActivity() {}

    std::string to_string() {
        std::string str("[");
        str.append(std::to_string(id));
        str.append("]  (");
        str.append(std::to_string(id_component));
        str.append(") ");
        str.append(package);
        str.append("::");
        str.append(type);
        str.append(":");
        str.append(name);
        str.append(" {");
        if(periodic)
            str.append("Periodic");
        else
            str.append("Aperiodic");
        str.append("}");

        return str;
    }

    int id;
    int id_component;
    std::string name;
    std::string type;
    std::string package;
    bool periodic;
    std::string info="Activity";
};

#endif // CMPACTIVITY_H
