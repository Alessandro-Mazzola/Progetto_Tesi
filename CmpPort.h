#ifndef CMPPORT_H
#define CMPPORT_H

#include <string>

#define PORT_PUBLISHER	"PUBLISHER"
#define PORT_SUBSCRIBER	"SUBSCRIBER"

class CmpPort {
  public:
    CmpPort() {}
    CmpPort (std::string name, std::string role, std::string topic_type, int id,int id_activity) {
            this->name = name;
            this->role = role;
            this->topic_type = topic_type;
            this->id = id;
            this->id_activity = id_activity;
        }
    ~CmpPort() {}

    std::string to_string() {
        std::string str("[");
        str.append(std::to_string(id));
        str.append("] A:");
        str.append(std::to_string(id_activity));
        str.append(" T:");
        str.append(std::to_string(id_topic));
        str.append(" ");
        str.append(name);
        str.append(" {");
        str.append(role);
        str.append("}");

        return str;
    }

    int id;
    int id_activity;
    int id_topic;
    std::string name;
    std::string role;
    std::string topic_type;
    std::string info = "Port";
};

#endif // CMPPORT_H
