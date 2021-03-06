FROM ubuntu:18.04

RUN apt-get update && apt-get install -y wget git cmake pybind11-dev && \
    apt-get install -y libcurl4-openssl-dev libblkid-dev e2fslibs-dev  && \
    apt-get install -y libboost-all-dev libaudit-dev software-properties-common

RUN mkdir /cppKin
COPY CMakeLists.txt /cppKin
COPY IDL/ /cppKin/IDL/
COPY LICENSE /cppKin
COPY MANIFEST.in /cppKin
COPY README.md /cppKin
COPY Third_Party/ /cppKin/Third_Party
COPY external/ /cppKin/external
COPY appveyor.yml /cppKin
COPY bench/ /cppKin/bench
COPY cmake/ /cppKin/cmake
COPY cppkin/ /cppKin/cppkin
COPY cppkin.bat /cppKin
COPY cppkin.sh /cppKin
COPY docs/ /cppKin/docs
COPY examples/ /cppKin/examples
COPY scripts/ /scripts
COPY setup.py /cppKin
COPY src/ /cppKin/src
COPY tests/ /cppKin/tests

RUN cd cppKin && mkdir build && cd build && ../cppkin.sh config --output_dir=/usr/local --3rd_loc_prefix=/usr/local && make && make install
