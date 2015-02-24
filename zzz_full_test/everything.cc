// This file is auto-generated by KnowSheet/scripts/full-test.sh.
// It is updated by running `make run` in the top-level Bricks directory, along with the documentation.
// And it is checked in, much like the documentation, so that non-*nix systems can run all the tests.

#include "port.h" // To have for in Visual studio, need port.h before STL headers.

#include "dflags/dflags.h"
#include "3party/gtest/gtest-main-with-dflags.h"

#include "./dflags/test.cc"
#include "./time/test.cc"
#include "./graph/test.cc"
#include "./util/test.cc"
#include "./mq/inmemory/test.cc"
#include "./net/api/docu/client/docu_02httpclient_02_test.cc"
#include "./net/api/docu/client/docu_02httpclient_01_test.cc"
#include "./net/api/docu/server/docu_03httpserver_03_test.cc"
#include "./net/api/docu/server/docu_03httpserver_02_test.cc"
#include "./net/api/docu/server/docu_03httpserver_04_test.cc"
#include "./net/api/docu/server/docu_03httpserver_01_test.cc"
#include "./net/api/docu/server/docu_03httpserver_05_test.cc"
#include "./net/api/test.cc"
#include "./net/url/test.cc"
#include "./net/http/test.cc"
#include "./net/tcp/test.cc"
#include "./rtti/docu/docu_06rtti_01_test.cc"
#include "./rtti/test.cc"
#include "./file/test.cc"
#include "./cerealize/docu/docu_01cerealize_04_test.cc"
#include "./cerealize/docu/docu_01cerealize_01_test.cc"
#include "./cerealize/docu/docu_01cerealize_03_test.cc"
#include "./cerealize/docu/docu_01cerealize_02_test.cc"
#include "./cerealize/test.cc"
#include "./strings/test.cc"
