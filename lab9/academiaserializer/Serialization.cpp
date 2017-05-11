//
// Created by Piotrek on 04.05.2017.
//

#include "Serialization.h"

namespace academia {
    std::string Room::TypeToString(Room::Type type) const {
        switch (type) {
            case Room::Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Room::Type::LECTURE_HALL:
                return "LECTURE_HALL";
            case Room::Type::CLASSROOM:
                return "CLASSROOM";
        }
    }

    void Room::Serialize(Serializer *serializer) const {
        serializer->Header("room");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->StringField("type", TypeToString(type_));
        serializer->Footer("room");
    }


    Room::Room(int id, std::string name, Room::Type type) {
        id_ = id;
        name_ = name;
        type_ = type;
    }


    Serializer::Serializer(std::ostream *out) {
        out_ = out;
    }

    void Building::Serialize(Serializer *serializer) const {
        serializer->Header("building");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->ArrayField("rooms", rooms_);
        serializer->Footer("building");
    }

    Building::Building(int id, const std::string &name, std::vector<std::reference_wrapper<const Serializable>> rooms) {
        id_ = id;
        name_ = name;
        rooms_ = rooms;
    }


    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }


    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {

    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {

    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_ << "<" << field_name << ">";
        for (const auto &n:value)
            n.get().Serialize(this);
        *out_ << "<\\" << field_name << ">";
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_ << "<" << object_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_ << "<\\" << object_name << ">";
    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        if (!needOpen)
            needOpen = true;
        else
            *out_ << ", ";
        *out_ << "\"" << field_name << "\": " << value << "";
    }


    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        if (!needOpen)
            needOpen = true;
        else
            *out_ << ", ";
        *out_ << "\"" << field_name << "\": \"" << value << "\"";
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {

    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {

    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {

    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        if (!needOpen)
            needOpen = true;
        else
            *out_ << ", ";
        *out_ << "\"" << field_name << "\": [";
        int i = 0;
        for (const auto &n:value) {
            needOpen = false;
            n.get().Serialize(this);
            i++;

            if (i < value.size()) {
                *out_ << ", ";
            }
        }
        *out_ << "]";
    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_ << "{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_ << "}";
    }
}