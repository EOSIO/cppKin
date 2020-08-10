#include "SimpleTag.h"
#include "core/Exception.h"
#include "boost/variant/get.hpp"

namespace cppkin
{
    
    SimpleTag::SimpleTag(const char* key, bool value) :
        m_key(key), m_valueType(ValueTypes::Boolean), m_value(value)
    {
    }

    SimpleTag::SimpleTag(const char* key, const char* value) :
        m_key(key), m_valueType(ValueTypes::String), m_value(std::string(value))
    {
    }

    SimpleTag::SimpleTag(const char* key, std::string value) :
        m_key(key), m_valueType(ValueTypes::String), m_value(std::move(value))
    {
    }


    SimpleTag::SimpleTag(const char* key, int value) :
        m_key(key), m_valueType(ValueTypes::Int), m_value(value)
    {
    }

    SimpleTag::SimpleTag(const char* key, float value) :
        m_key(key), m_valueType(ValueTypes::Float), m_value(value)
    {
    }
    
    SimpleTag::SimpleTag(const SimpleTag& object) :
        m_key(object.m_key), m_valueType(object.m_valueType), m_value(object.m_value)
    {
    }
    
    void SimpleTag::GetValue(bool& value) const
    {
        if(m_valueType != ValueTypes::Boolean)
            throw core::Exception(__CORE_SOURCE, "Requested type doesn't match the stored instance type");
        value = boost::get<bool>(m_value);
    }
    void SimpleTag::GetValue(std::string& value) const
    {
        if(m_valueType != ValueTypes::String)
            throw core::Exception(__CORE_SOURCE, "Requested type doesn't match the stored instance type");
        value = boost::get<std::string>(m_value);
    }
    void SimpleTag::GetValue(int& value) const
    {
        if(m_valueType != ValueTypes::Int)
            throw core::Exception(__CORE_SOURCE, "Requested type doesn't match the stored instance type");
        value = boost::get<int>(m_value);
    }
    void SimpleTag::GetValue(float& value) const
    {
        if(m_valueType != ValueTypes::Float)
            throw core::Exception(__CORE_SOURCE, "Requested type doesn't match the stored instance type");
        value = boost::get<float>(m_value);
    }
}
