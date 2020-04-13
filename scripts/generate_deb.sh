#!/bin/bash

# This assumes that you installed cppkin via:
# cppkin.sh config --output_dir=/usr/local --3rd_loc_prefix=/usr/local

set -u

cd /

PACKAGE="cppkin"
VERSION=$1
UBUNTU_VERSION=$2

mkdir -p /${PACKAGE}/DEBIAN
mkdir -p /${PACKAGE}/usr/local/lib
mkdir -p /${PACKAGE}/usr/local/include

cp /usr/local/lib/libCore.so /${PACKAGE}/usr/local/lib
cp /usr/local/lib/libcppkin.so /${PACKAGE}/usr/local/lib

cp /usr/local/include/Annotation.h /${PACKAGE}/usr/local/include
cp /usr/local/include/AnnotationType.h /${PACKAGE}/usr/local/include
cp /usr/local/include/BinaryAnnotation.h /${PACKAGE}/usr/local/include
cp /usr/local/include/ValueTypes.h /${PACKAGE}/usr/local/include
cp /usr/local/include/ConfigParams.h /${PACKAGE}/usr/local/include
cp /usr/local/include/ConfigTags.h /${PACKAGE}/usr/local/include
cp /usr/local/include/Encoder.h /${PACKAGE}/usr/local/include
cp /usr/local/include/EncodingContext.h /${PACKAGE}/usr/local/include
cp /usr/local/include/EncodingTypes.h /${PACKAGE}/usr/local/include
cp /usr/local/include/Export.h /${PACKAGE}/usr/local/include
cp /usr/local/include/HttpTransport.h /${PACKAGE}/usr/local/include
cp /usr/local/include/JsonEncoder.h /${PACKAGE}/usr/local/include
cp /usr/local/include/Sampler.h /${PACKAGE}/usr/local/include
cp /usr/local/include/ScribeTransport.h /${PACKAGE}/usr/local/include
cp /usr/local/include/SimpleAnnotation.h /${PACKAGE}/usr/local/include
cp /usr/local/include/Span.h /${PACKAGE}/usr/local/include
cp /usr/local/include/StubTransport.h /${PACKAGE}/usr/local/include
cp /usr/local/include/ThriftEncoder.h /${PACKAGE}/usr/local/include
cp /usr/local/include/Trace.h /${PACKAGE}/usr/local/include
cp /usr/local/include/Transport.h /${PACKAGE}/usr/local/include
cp /usr/local/include/TransportFactory.h /${PACKAGE}/usr/local/include
cp /usr/local/include/TransportManager.h /${PACKAGE}/usr/local/include
cp /usr/local/include/TransportType.h /${PACKAGE}/usr/local/include
cp /usr/local/include/cppkin.h /${PACKAGE}/usr/local/include
cp /usr/local/include/span_impl.h /${PACKAGE}/usr/local/include

cp -r /usr/local/include/core /${PACKAGE}/usr/local/include
cp -r /usr/local/include/spdlog /${PACKAGE}/usr/local/include

echo "Package: ${PACKAGE}
Version: ${VERSION}
Section: devel
Priority: optional
Architecture: amd64
Homepage: https://github.com/EOSIO/cppkin
Maintainer: support@block.one
Description: C++ integration for zipkin tracing" &> /${PACKAGE}/DEBIAN/control

echo "#!/bin/bash
echo 'Running ldconfig'
ldconfig" &> /${PACKAGE}/DEBIAN/postinst
chmod +x /${PACKAGE}/DEBIAN/postinst

dpkg-deb --build ${PACKAGE}

mv /${PACKAGE}.deb /${PACKAGE}_${VERSION}-ubuntu-${UBUNTU_VERSION}_amd64.deb
