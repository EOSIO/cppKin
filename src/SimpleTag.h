#pragma once

#include <string>
#include <cinttypes>
#include "boost/variant.hpp"
#include "Export.h"
#include "ValueTypes.h"

namespace cppkin
{

    class SimpleTag
    {
    public:
        SimpleTag(const char* key, bool value);
        SimpleTag(const char* key, const char* value);
        SimpleTag(const char* key, std::string value);
        SimpleTag(const char* key, int value);
        SimpleTag(const char* key, float value);
        SimpleTag(const SimpleTag& object);
        
        ~SimpleTag() {}
        ValueTypes GetValueType() const { return m_valueType; }
        const std::string& GetKey() const { return m_key; }
        
        void GetValue(bool& value) const;
        void GetValue(std::string& value) const;
        void GetValue(int& value) const;
        void GetValue(float& value) const;
        
    private:
        std::string m_key;
        ValueTypes m_valueType;
        boost::variant<bool, std::string, int, float> m_value;
    };
}

