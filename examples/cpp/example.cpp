#if defined(WIN32)
#include <windows.h>
#endif
#include <string>
#include <memory>
#include <functional>
#include <boost/program_options.hpp>
#include "src/cppkin.h"

using namespace std;
using namespace core;
using namespace boost::program_options;

static void portable_sleep(int duration)
{
#if defined(WIN32)
    ::Sleep(duration);
#else
    ::sleep(duration);
#endif
}

static void boo(const char* b3format)
{
    cppkin::Span span_2;
    span_2.Join(b3format);
    auto span_3 = span_2.CreateSpan("B3ChildSpan");
    portable_sleep(5);
    span_3.Submit();
}

static void foo()
{
    typedef std::unique_ptr<const char, std::function<void(const char*)>> char_ptr;
    cppkin::Span& span_1 = cppkin::TopSpan();
    auto span_2 = span_1.CreateSpan("Span2");
    portable_sleep(1);
    char const * b3header;
    span_2.GetHeaderB3Format(b3header);
    char_ptr guard(b3header, [](char const * ptr){free(const_cast<char*>(ptr));});
    boo(b3header);
    span_2.Submit();
}

int main( int argc, const char *argv[] )
{
    options_description desc{"Options"};
        desc.add_options()
          ("help,h", "Help screen")
          ("endpoint", value<string>()->default_value("127.0.0.1"), "Endpoint" )
          ("service", value<string>()->default_value("example_service"), "Service")
          ("api-key", value<string>()->default_value(""), "API Key")
          ("data-format", value<string>()->default_value("zipkin"), "Data Format")
          ("data-format-version", value<int>()->default_value(2), "Data Format Version");
    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help")) {
        std::cout << desc << '\n';
        return 0;
    }

    int port = -1;
    auto transportType = cppkin::TransportType::Http;
    auto encodingType = cppkin::EncodingType::Json;

    cppkin::CppkinParams cppkinParams;
    cppkinParams.AddParam(cppkin::ConfigTags::ENDPOINT, vm["endpoint"].as<string>());
    cppkinParams.AddParam(cppkin::ConfigTags::SERVICE_NAME, vm["service"].as<string>());
    cppkinParams.AddParam(cppkin::ConfigTags::PORT, port);
    cppkinParams.AddParam(cppkin::ConfigTags::SAMPLE_COUNT, 1);
    cppkinParams.AddParam(cppkin::ConfigTags::TRANSPORT_TYPE, cppkin::TransportType(transportType).ToString());
    cppkinParams.AddParam(cppkin::ConfigTags::ENCODING_TYPE, cppkin::EncodingType(encodingType).ToString());
    cppkinParams.AddParam(cppkin::ConfigTags::API_KEY, vm["api-key"].as<string>());
    cppkinParams.AddParam(cppkin::ConfigTags::DATA_FORMAT, vm["data-format"].as<string>());
    cppkinParams.AddParam(cppkin::ConfigTags::DATA_FORMAT_VERSION, vm["data-format-version"].as<int>());

    cppkin::Init(cppkinParams);

    cppkin::Trace trace("TestTrace");
    portable_sleep(1);
    trace.AddAnnotation("TraceEvent");

    auto span_1 = trace.CreateSpan("Span1");
    portable_sleep(1);
    span_1.AddAnnotation("Span1Event");
    span_1.AddTag("str value", "some value");
    //Lets use the span container in order to reach a certain stack frame.
    cppkin::PushSpan(span_1);
    foo();
    cppkin::PopSpan();

    span_1.Submit();
    portable_sleep(1);
    trace.Submit();

#if defined(WIN32)
    portable_sleep(100);
#else
    portable_sleep(2);
#endif
    cppkin::Stop();
    return 0;
}
