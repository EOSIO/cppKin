#include "cppkin.h"
#include "Environment.h"
#include "Logger.h"
#include "ConfigParams.h"
#include "TransportManager.h"
#include "SpanContainer.h"

using namespace core;

namespace cppkin
{
    void Init(const GeneralParams& params){
        Environment::Instance().Init();
        Logger::Instance().Start(TraceSeverity::Info);
        ConfigParams::Instance().Load(params);
    }

    void Stop()
    {
        TransportManager::Instance().Stop();
        Logger::Instance().Terminate();
    }

    void PushSpan(Span& span)
    {
        SpanContainer::Instance().PushSpan(span);
    }
    
    Span& TopSpan()
    {
        return SpanContainer::Instance().TopSpan();
    }

    void PopSpan()
    {
        SpanContainer::Instance().PopSpan();
    }
    
    bool IsContainerEmpty()
    {
        return SpanContainer::Instance().IsEmpty();
    }
}
