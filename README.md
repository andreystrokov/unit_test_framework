# unit_test_framework
1) Include `test_runner.h` in your code;  
2) Write tests, using macro ASSERT_EQUAL like:
```
void TestSum() {
   int i = 4;
   ASSERT_EQUAL (i,sum(2,3));
}
  ```
3) When u wrote tests, write function `TestAll`, create object `TestRunner` and add your test function (using `RUN_TEST` macro)
  ```
void TestAll {
      TestRunner tr;
      RUN_TEST(tr,<TestFunc1>);
      RUN_TEST(tr,<TestFunc2>);
    ..
}
```
 4) input `TestAll` func in main file code;   
    
