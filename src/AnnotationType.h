#pragma once

#include "Enumeration.h"
#include "Export.h"

namespace cppkin
{
    class CPPKIN_EXPORT AnnotationType
    {
    public:
        enum Enumeration
        {
            Simple,
            Binary
        };
    ENUMERATION(AnnotationType)
    };
}
