# cppkin

[![Join the chat at https://gitter.im/cppKin/Lobby](https://badges.gitter.im/cppKin/Lobby.svg)](https://gitter.im/cppKin/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge) [![Build Status](https://travis-ci.org/Dudi119/cppKin.svg?branch=master)](https://travis-ci.org/Dudi119/cppKin) [![Build status](https://ci.appveyor.com/api/projects/status/riaj54pn4h08xy40?svg=true)](https://ci.appveyor.com/project/Dudi119/cppKin)

`cppkin` is an instrumentation client library for `zipkin` available in **C++** and **Python**.

## Linux Requirements:
* c++11.
* Cmake version > 3.5.

## Windows Requirements:
* VC++ 12.0 (Visual Studio 2013 default toolset) or 14.0 (Visual Studio 2015 default toolset).
* Cmake version > 3.5.

## Getting Started:
cppkin is dependent upon -

| Package                 | Required   |  version  |
| ----------------------- | -----------| --------- |
| boost                   | mandatory  | >= 1.65.1 |
| curl                    | mandatory  | >= 7.54.1 |
| pybind11                | python or tests  | >= 2.2.4 |
| bottle                  | tests  |    >= 0.12.13 |
| google benchmark        | tests |     >= 1.3     |
| thrift                  | only for scribe transport | >= 0.10 |

### Linux Install:
All mandatory packages can be fetched directly:
```
apt-get install cmake pybind11-dev libcurl4-openssl-dev libblkid-dev e2fslibs-dev libboost-all-dev libaudit-dev
```

Use the help command to review the different configuration arguments:
```
. cppkin.sh --help
```

Build cppkin by using the shell script:
```
mkdir build && cd build
../cppkin.sh config #add arguments of choice
make
make install
```

### Windows Install:
Use the help command to review the different configuration arguments:
```
cppkin.bat --help
```

Build cppkin by using the batch script:
```
mkdir build && cd build
..\cppkin.bat install #add arguments of choice
```

### Python Install:
Only available in Linux as of now.
```
pip install cppkin
```

### Language:
- [cppkin - cpp variation](https://github.com/Dudi119/cppKin/blob/master/docs/cpp_client.md)
- [cppkin - python variation](https://github.com/Dudi119/cppKin/blob/master/docs/python_client.md)
