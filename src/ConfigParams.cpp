#include "ConfigParams.h"
#include "GeneralParams.h"
#include "ConfigTags.h"

using namespace std;
using namespace core;
namespace cppkin
{
    ConfigParams& ConfigParams::Instance()
    {
        static ConfigParams instance;
        return instance;
    }

    ConfigParams::ConfigParams():
            m_transportType(TransportType::Stub), m_debug(false), m_sampleCount(1000), m_encodingType(EncodingType::Json), m_batchSize(50), m_apiKey(""), m_dataFormat(""), m_dataFormatVersion(0)
    {}

    void ConfigParams::Load(const GeneralParams& configParams)
    {
        m_endpoint = configParams.Get<string>(ConfigTags::ENDPOINT);
        m_serviceName = configParams.Get<string>(ConfigTags::SERVICE_NAME);
        m_port = configParams.Get<int>(ConfigTags::PORT);

        if(configParams.Exists(ConfigTags::DEBUG))
            m_debug = configParams.Get<bool>(ConfigTags::DEBUG);
        if(configParams.Exists(ConfigTags::ENCODING_TYPE))
            m_encodingType = EncodingType::FromString(configParams.Get<string>(ConfigTags::ENCODING_TYPE));
        if(configParams.Exists(ConfigTags::TRANSPORT_TYPE))
            m_transportType = TransportType::FromString(configParams.Get<string>(ConfigTags::TRANSPORT_TYPE));
        if(configParams.Exists(ConfigTags::BATCH_SIZE))
            m_batchSize = configParams.Get<int>(ConfigTags::BATCH_SIZE);
        if(configParams.Exists(ConfigTags::SAMPLE_COUNT))
            m_sampleCount = configParams.Get<int>(ConfigTags::SAMPLE_COUNT);
        if(configParams.Exists(ConfigTags::API_KEY))
            m_apiKey = configParams.Get<string>(ConfigTags::API_KEY);
        if(configParams.Exists(ConfigTags::DATA_FORMAT))
            m_dataFormat = configParams.Get<string>(ConfigTags::DATA_FORMAT);
        if(configParams.Exists(ConfigTags::DATA_FORMAT_VERSION))
            m_dataFormatVersion = configParams.Get<int>(ConfigTags::DATA_FORMAT_VERSION);
    }
}
