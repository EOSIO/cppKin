# pragma once

#include <string>
#include "Export.h"
#include "TransportType.h"
#include "EncodingTypes.h"
#if defined(WIN32)
#pragma warning( push )
#pragma warning (disable : 4251)
#endif

namespace core
{
    class GeneralParams;
}

namespace cppkin
{
    class CPPKIN_EXPORT ConfigParams
    {
    public:
        static ConfigParams& Instance();
        ~ConfigParams() {}
        void Load(const core::GeneralParams& configParams);
        //Accessors
        const std::string& GetHostAddress() const { return m_hostAddress; }
        int GetPort() const { return m_port; }
        TransportType GetTransportType() const { return m_transportType; }
        const std::string& GetServiceName() const { return m_serviceName;}
        bool GetDebug() const { return m_debug; }
        int GetSampleCount() const { return m_sampleCount; }
        EncodingType GetEncodingType() const { return m_encodingType; }
        int GetBatchSize() const { return m_batchSize; }
        const std::string& GetApiKey() const { return m_apiKey; }
        const std::string& GetDataFormat() const { return m_dataFormat; }
        int GetDataFormatVersion() const { return m_dataFormatVersion; }

    private:
        ConfigParams();

    private:
        std::string m_hostAddress;
        int m_port;
        std::string m_serviceName;

        TransportType m_transportType;
        bool m_debug;
        int m_sampleCount;
        EncodingType m_encodingType;
        int m_batchSize;
        std::string m_apiKey;
        std::string m_dataFormat;
        int m_dataFormatVersion;
    };
}
#if defined(WIN32)
#pragma warning( pop )
#endif
