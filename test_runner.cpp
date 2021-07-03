//
// Created by ASUS on 29.04.2021.
//
#define RUN_TEST(tr,func) \
    tr.RunTest(func, #func)
#include "test_runner.h"
void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}
TestRunner::~TestRunner() {
    if (fail_count > 0) {
        cerr << fail_count << " unit tests failed. Terminate" << endl;
        exit(1);
    }
}
