#pragma once
#ifndef UNTITLED22_TEST_RUNNER_H
#define UNTITLED22_TEST_RUNNER_H

#endif //UNTITLED22_TEST_RUNNER_H
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;
inline void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}
template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}
template<class T>
ostream& operator<< (ostream& ostream1,const vector <T> v){
    bool b = true;
    char t = ',';
    for (auto i : v){
        if (!b) {
            ostream1 << t;
        }
            b = false;
            ostream1 << i;
    }
    return ostream1;
    }

    void Assert(bool b, const string& hint);

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner();

private:
    int fail_count = 0;
};

TestRunner::~TestRunner() {
    if (fail_count > 0) {
        cerr << fail_count << " unit tests failed. Terminate" << endl;
        exit(1);
    }
}
#include "test_runner.h"
#define ASSERT_EQUAL(x,y) {         \
 ostringstream os;                  \
os << #x << " != " << #y << endl << \
__FILE__ << " : " << "line: " <<  __LINE__;   \
AssertEqual(x,y,os.str());          \
} 
#define ASSERT(x) {                     \
  ostringstream os;                     \
  os << #x << " is false, "             \
    << __FILE__ << ":" << __LINE__;     \
  Assert(x, os.str());                  \
}
#define RUN_TEST(tr,func) \
    tr.RunTest(func, #func)
