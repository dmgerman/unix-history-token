begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2008 Google Inc.
end_comment

begin_comment
comment|// All Rights Reserved.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Redistribution and use in source and binary forms, with or without
end_comment

begin_comment
comment|// modification, are permitted provided that the following conditions are
end_comment

begin_comment
comment|// met:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     * Redistributions of source code must retain the above copyright
end_comment

begin_comment
comment|// notice, this list of conditions and the following disclaimer.
end_comment

begin_comment
comment|//     * Redistributions in binary form must reproduce the above
end_comment

begin_comment
comment|// copyright notice, this list of conditions and the following disclaimer
end_comment

begin_comment
comment|// in the documentation and/or other materials provided with the
end_comment

begin_comment
comment|// distribution.
end_comment

begin_comment
comment|//     * Neither the name of Google Inc. nor the names of its
end_comment

begin_comment
comment|// contributors may be used to endorse or promote products derived from
end_comment

begin_comment
comment|// this software without specific prior written permission.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
end_comment

begin_comment
comment|// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
end_comment

begin_comment
comment|// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
end_comment

begin_comment
comment|// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
end_comment

begin_comment
comment|// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
end_comment

begin_comment
comment|// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
end_comment

begin_comment
comment|// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
end_comment

begin_comment
comment|// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
end_comment

begin_comment
comment|// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Author: wan@google.com (Zhanyong Wan)
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_GTEST_TYPED_TEST_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_GTEST_TYPED_TEST_H_
end_define

begin_comment
comment|// This header implements typed tests and type-parameterized tests.
end_comment

begin_comment
comment|// Typed (aka type-driven) tests repeat the same test for types in a
end_comment

begin_comment
comment|// list.  You must know which types you want to test with when writing
end_comment

begin_comment
comment|// typed tests. Here's how you do it:
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|// First, define a fixture class template.  It should be parameterized
end_comment

begin_comment
comment|// by a type.  Remember to derive it from testing::Test.
end_comment

begin_comment
unit|template<typename T> class FooTest : public testing::Test {  public:   ...   typedef std::list<T> List;   static T shared_;   T value_; };
comment|// Next, associate a list of types with the test case, which will be
end_comment

begin_comment
comment|// repeated for each type in the list.  The typedef is necessary for
end_comment

begin_comment
comment|// the macro to parse correctly.
end_comment

begin_comment
unit|typedef testing::Types<char, int, unsigned int> MyTypes; TYPED_TEST_CASE(FooTest, MyTypes);
comment|// If the type list contains only one type, you can write that type
end_comment

begin_comment
comment|// directly without Types<...>:
end_comment

begin_comment
comment|//   TYPED_TEST_CASE(FooTest, int);
end_comment

begin_comment
comment|// Then, use TYPED_TEST() instead of TEST_F() to define as many typed
end_comment

begin_comment
comment|// tests for this test case as you want.
end_comment

begin_comment
unit|TYPED_TEST(FooTest, DoesBlah) {
comment|// Inside a test, refer to TypeParam to get the type parameter.
end_comment

begin_comment
comment|// Since we are inside a derived class template, C++ requires use to
end_comment

begin_comment
comment|// visit the members of FooTest via 'this'.
end_comment

begin_comment
unit|TypeParam n = this->value_;
comment|// To visit static members of the fixture, add the TestFixture::
end_comment

begin_comment
comment|// prefix.
end_comment

begin_comment
unit|n += TestFixture::shared_;
comment|// To refer to typedefs in the fixture, add the "typename
end_comment

begin_comment
comment|// TestFixture::" prefix.
end_comment

begin_endif
unit|typename TestFixture::List values;   values.push_back(n);   ... }  TYPED_TEST(FooTest, HasPropertyA) { ... }
endif|#
directive|endif
end_endif

begin_comment
comment|// 0
end_comment

begin_comment
comment|// Type-parameterized tests are abstract test patterns parameterized
end_comment

begin_comment
comment|// by a type.  Compared with typed tests, type-parameterized tests
end_comment

begin_comment
comment|// allow you to define the test pattern without knowing what the type
end_comment

begin_comment
comment|// parameters are.  The defined pattern can be instantiated with
end_comment

begin_comment
comment|// different types any number of times, in any number of translation
end_comment

begin_comment
comment|// units.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If you are designing an interface or concept, you can define a
end_comment

begin_comment
comment|// suite of type-parameterized tests to verify properties that any
end_comment

begin_comment
comment|// valid implementation of the interface/concept should have.  Then,
end_comment

begin_comment
comment|// each implementation can easily instantiate the test suite to verify
end_comment

begin_comment
comment|// that it conforms to the requirements, without having to write
end_comment

begin_comment
comment|// similar tests repeatedly.  Here's an example:
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|// First, define a fixture class template.  It should be parameterized
end_comment

begin_comment
comment|// by a type.  Remember to derive it from testing::Test.
end_comment

begin_comment
unit|template<typename T> class FooTest : public testing::Test {   ... };
comment|// Next, declare that you will define a type-parameterized test case
end_comment

begin_comment
comment|// (the _P suffix is for "parameterized" or "pattern", whichever you
end_comment

begin_comment
comment|// prefer):
end_comment

begin_comment
unit|TYPED_TEST_CASE_P(FooTest);
comment|// Then, use TYPED_TEST_P() to define as many type-parameterized tests
end_comment

begin_comment
comment|// for this type-parameterized test case as you want.
end_comment

begin_comment
unit|TYPED_TEST_P(FooTest, DoesBlah) {
comment|// Inside a test, refer to TypeParam to get the type parameter.
end_comment

begin_comment
unit|TypeParam n = 0;   ... }  TYPED_TEST_P(FooTest, HasPropertyA) { ... }
comment|// Now the tricky part: you need to register all test patterns before
end_comment

begin_comment
comment|// you can instantiate them.  The first argument of the macro is the
end_comment

begin_comment
comment|// test case name; the rest are the names of the tests in this test
end_comment

begin_comment
comment|// case.
end_comment

begin_comment
unit|REGISTER_TYPED_TEST_CASE_P(FooTest,                            DoesBlah, HasPropertyA);
comment|// Finally, you are free to instantiate the pattern with the types you
end_comment

begin_comment
comment|// want.  If you put the above code in a header file, you can #include
end_comment

begin_comment
comment|// it in multiple C++ source files and instantiate it multiple times.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To distinguish different instances of the pattern, the first
end_comment

begin_comment
comment|// argument to the INSTANTIATE_* macro is a prefix that will be added
end_comment

begin_comment
comment|// to the actual test case name.  Remember to pick unique prefixes for
end_comment

begin_comment
comment|// different instances.
end_comment

begin_comment
unit|typedef testing::Types<char, int, unsigned int> MyTypes; INSTANTIATE_TYPED_TEST_CASE_P(My, FooTest, MyTypes);
comment|// If the type list contains only one type, you can write that type
end_comment

begin_comment
comment|// directly without Types<...>:
end_comment

begin_comment
comment|//   INSTANTIATE_TYPED_TEST_CASE_P(My, FooTest, int);
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// 0
end_comment

begin_include
include|#
directive|include
file|"gtest/internal/gtest-port.h"
end_include

begin_include
include|#
directive|include
file|"gtest/internal/gtest-type-util.h"
end_include

begin_comment
comment|// Implements typed tests.
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_TYPED_TEST
end_if

begin_comment
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN USER CODE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Expands to the name of the typedef for the type parameters of the
end_comment

begin_comment
comment|// given test case.
end_comment

begin_define
define|#
directive|define
name|GTEST_TYPE_PARAMS_
parameter_list|(
name|TestCaseName
parameter_list|)
value|gtest_type_params_##TestCaseName##_
end_define

begin_comment
comment|// The 'Types' template argument below must have spaces around it
end_comment

begin_comment
comment|// since some compilers may choke on '>>' when passing a template
end_comment

begin_comment
comment|// instance (e.g. Types<int>)
end_comment

begin_define
define|#
directive|define
name|TYPED_TEST_CASE
parameter_list|(
name|CaseName
parameter_list|,
name|Types
parameter_list|)
define|\
value|typedef ::testing::internal::TypeList< Types>::type \       GTEST_TYPE_PARAMS_(CaseName)
end_define

begin_define
define|#
directive|define
name|TYPED_TEST
parameter_list|(
name|CaseName
parameter_list|,
name|TestName
parameter_list|)
define|\
value|template<typename gtest_TypeParam_> \   class GTEST_TEST_CLASS_NAME_(CaseName, TestName) \       : public CaseName<gtest_TypeParam_> { \    private: \     typedef CaseName<gtest_TypeParam_> TestFixture; \     typedef gtest_TypeParam_ TypeParam; \     virtual void TestBody(); \   }; \   bool gtest_##CaseName##_##TestName##_registered_ GTEST_ATTRIBUTE_UNUSED_ = \       ::testing::internal::TypeParameterizedTest< \           CaseName, \           ::testing::internal::TemplateSel< \               GTEST_TEST_CLASS_NAME_(CaseName, TestName)>, \           GTEST_TYPE_PARAMS_(CaseName)>::Register(\               "", #CaseName, #TestName, 0); \   template<typename gtest_TypeParam_> \   void GTEST_TEST_CLASS_NAME_(CaseName, TestName)<gtest_TypeParam_>::TestBody()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_TYPED_TEST
end_comment

begin_comment
comment|// Implements type-parameterized tests.
end_comment

begin_if
if|#
directive|if
name|GTEST_HAS_TYPED_TEST_P
end_if

begin_comment
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN USER CODE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Expands to the namespace name that the type-parameterized tests for
end_comment

begin_comment
comment|// the given type-parameterized test case are defined in.  The exact
end_comment

begin_comment
comment|// name of the namespace is subject to change without notice.
end_comment

begin_define
define|#
directive|define
name|GTEST_CASE_NAMESPACE_
parameter_list|(
name|TestCaseName
parameter_list|)
define|\
value|gtest_case_##TestCaseName##_
end_define

begin_comment
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN USER CODE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Expands to the name of the variable used to remember the names of
end_comment

begin_comment
comment|// the defined tests in the given test case.
end_comment

begin_define
define|#
directive|define
name|GTEST_TYPED_TEST_CASE_P_STATE_
parameter_list|(
name|TestCaseName
parameter_list|)
define|\
value|gtest_typed_test_case_p_state_##TestCaseName##_
end_define

begin_comment
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN USER CODE DIRECTLY.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Expands to the name of the variable used to remember the names of
end_comment

begin_comment
comment|// the registered tests in the given test case.
end_comment

begin_define
define|#
directive|define
name|GTEST_REGISTERED_TEST_NAMES_
parameter_list|(
name|TestCaseName
parameter_list|)
define|\
value|gtest_registered_test_names_##TestCaseName##_
end_define

begin_comment
comment|// The variables defined in the type-parameterized test macros are
end_comment

begin_comment
comment|// static as typically these macros are used in a .h file that can be
end_comment

begin_comment
comment|// #included in multiple translation units linked together.
end_comment

begin_define
define|#
directive|define
name|TYPED_TEST_CASE_P
parameter_list|(
name|CaseName
parameter_list|)
define|\
value|static ::testing::internal::TypedTestCasePState \       GTEST_TYPED_TEST_CASE_P_STATE_(CaseName)
end_define

begin_define
define|#
directive|define
name|TYPED_TEST_P
parameter_list|(
name|CaseName
parameter_list|,
name|TestName
parameter_list|)
define|\
value|namespace GTEST_CASE_NAMESPACE_(CaseName) { \   template<typename gtest_TypeParam_> \   class TestName : public CaseName<gtest_TypeParam_> { \    private: \     typedef CaseName<gtest_TypeParam_> TestFixture; \     typedef gtest_TypeParam_ TypeParam; \     virtual void TestBody(); \   }; \   static bool gtest_##TestName##_defined_ GTEST_ATTRIBUTE_UNUSED_ = \       GTEST_TYPED_TEST_CASE_P_STATE_(CaseName).AddTestName(\           __FILE__, __LINE__, #CaseName, #TestName); \   } \   template<typename gtest_TypeParam_> \   void GTEST_CASE_NAMESPACE_(CaseName)::TestName<gtest_TypeParam_>::TestBody()
end_define

begin_comment
comment|// Silencing C99 build warnings
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|REGISTER_TYPED_TEST_CASE_P
parameter_list|(
name|CaseName
parameter_list|,
modifier|...
parameter_list|)
define|\
value|namespace GTEST_CASE_NAMESPACE_(CaseName) { \   typedef ::testing::internal::Templates<__VA_ARGS__>::type gtest_AllTests_; \   } \   static const char* const GTEST_REGISTERED_TEST_NAMES_(CaseName) = \       GTEST_TYPED_TEST_CASE_P_STATE_(CaseName).VerifyRegisteredTestNames(\           __FILE__, __LINE__, #__VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// The 'Types' template argument below must have spaces around it
end_comment

begin_comment
comment|// since some compilers may choke on '>>' when passing a template
end_comment

begin_comment
comment|// instance (e.g. Types<int>)
end_comment

begin_define
define|#
directive|define
name|INSTANTIATE_TYPED_TEST_CASE_P
parameter_list|(
name|Prefix
parameter_list|,
name|CaseName
parameter_list|,
name|Types
parameter_list|)
define|\
value|bool gtest_##Prefix##_##CaseName GTEST_ATTRIBUTE_UNUSED_ = \       ::testing::internal::TypeParameterizedTestCase<CaseName, \           GTEST_CASE_NAMESPACE_(CaseName)::gtest_AllTests_, \           ::testing::internal::TypeList< Types>::type>::Register(\               #Prefix, #CaseName, GTEST_REGISTERED_TEST_NAMES_(CaseName))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_TYPED_TEST_P
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_INCLUDE_GTEST_GTEST_TYPED_TEST_H_
end_comment

end_unit

