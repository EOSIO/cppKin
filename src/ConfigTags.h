#pragma once

#include "Export.h"

namespace  cppkin {
    class CPPKIN_EXPORT ConfigTags
    {
    public:
        static const char *ENDPOINT;
        static const char *PORT;
        static const char *DEBUG;
        static const char *TRANSPORT_TYPE;
        static const char *SERVICE_NAME;
        static const char *SAMPLE_COUNT;
        static const char *ENCODING_TYPE;
        static const char *BATCH_SIZE;
        static const char *API_KEY;
        static const char *DATA_FORMAT;
        static const char *DATA_FORMAT_VERSION;
    private:
        ConfigTags();
    };
}
