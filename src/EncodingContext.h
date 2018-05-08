#pragma once

#include <string>
#include <memory>
#include <vector>
#include "EncodingTypes.h"

namespace cppkin
{
    class span_impl;
    class Encoder;

    class EncoderContext
    {

    public:

        class ContextElement {

        public:
            ContextElement(std::unique_ptr<span_impl>&& span, const Encoder& encoder);
            ContextElement(ContextElement&& obj);
            ContextElement(ContextElement&) = delete;
            ContextElement& operator=(ContextElement&) = delete;
            ContextElement& operator=(ContextElement&&) = delete;
            std::string ToString() const;
            const span_impl& operator*() const { return *m_span; }

        private:
            std::unique_ptr<span_impl> m_span;
            const Encoder&        m_encoder;
        };

        typedef std::vector<ContextElement> ContextElementVector;
        typedef ContextElementVector::iterator iterator;
        typedef ContextElementVector::const_iterator const_iterator;

        EncoderContext();
        EncoderContext(std::vector<std::unique_ptr<span_impl>>& spans);
        virtual ~EncoderContext();
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        std::string ToString() const;

    private:
        std::vector<ContextElement>    m_spans;
        const std::unique_ptr<Encoder> m_encoder;
    };
}
