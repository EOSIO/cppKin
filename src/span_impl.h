#pragma once

#include <string>
#include <cinttypes>
#include <vector>
#include <memory>
#include "core/Assert.h"
#include "core/Environment.h"
#include "Annotation.h"
#include "BinaryAnnotation.h"
#include "SimpleTag.h"
#include "ConfigParams.h"
#include "Export.h"
#if defined(WIN32)
#pragma warning( push )
#pragma warning (disable : 4251)
#endif

namespace cppkin
{
    class Trace;
    class EncoderContextThrift;

    class span_impl
    {
    public:
        typedef std::vector<std::unique_ptr<Annotation>> Annotations;
        typedef std::vector<std::unique_ptr<SimpleTag>> Tags;
        struct CPPKIN_EXPORT SpanHeader
        {
        public:
            SpanHeader(const std::string& name, uint_fast64_t traceID, uint_fast64_t parentID, uint_fast64_t id, bool sampled);
            SpanHeader(const std::string& name, uint_fast64_t traceID, uint_fast64_t id, bool sampled);
            SpanHeader() = default;
        public:
            std::string Name;
            uint_fast64_t ID = 0;
            uint_fast64_t ParentID = 0;
            uint_fast64_t TraceID = 0;
            bool Sampled = false;
            bool ParentIdSet = false;
        };
        struct CPPKIN_EXPORT LocalEndpoint
        {
            std::string ServiceName;
            std::string Host;
            int_fast16_t Port;
        };

    public:
        ~span_impl() = default;
        span_impl(const span_impl& obj);
        span_impl& operator=(const span_impl&) = delete;
        const SpanHeader& GetHeader() const;
        const Annotations& GetAnnotations() const;
        const Tags& GetTags() const;
        const LocalEndpoint& GetLocalEndpoint() const;
        void CreateSimpleAnnotation(const std::string& event);
        void CreateSimpleAnnotation(const std::string& event, int_fast64_t timeStamp);
        void CreateBinaryAnnotation(const char* key, bool value);
        void CreateBinaryAnnotation(const char* key, const char* value);
        void CreateSimpleTag(const char* key, bool value);
        void CreateSimpleTag(const char* key, const char* value);
        void CreateSimpleTag(const char* key, int value);
        void CreateSimpleTag(const char* key, float value);
        void AddLocalEndpoint();
        int_fast64_t GetTimeStamp() const;
        int_fast64_t GetDuration() const;
        void SetEndTime();

    private:
        friend class Trace;
        friend class Span;

        span_impl(const std::string& name, uint_fast64_t traceID, uint_fast64_t parentID, uint_fast64_t id, bool sampled);
        span_impl(const std::string& name, uint_fast64_t traceID, bool sampled);
        explicit span_impl(const char* b3format);
        static uint_fast64_t GenerateID();
        int_fast64_t GetCurrentTime();
        std::string GetHeaderB3Format() const;

    private:
        SpanHeader m_header;
        Annotations m_events;
        Tags m_tags;
        LocalEndpoint m_localEndpoint;
        int_fast64_t m_timeStamp = 0;
        int_fast64_t m_duration = 0;
    };
}
#if defined(WIN32)
#pragma warning( pop )
#endif
