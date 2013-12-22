begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2005, Google Inc.
end_comment

begin_comment
comment|// All rights reserved.
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
comment|// Authors: wan@google.com (Zhanyong Wan), eefacm@gmail.com (Sean Mcafee)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The Google C++ Testing Framework (Google Test)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This header file declares functions and macros used internally by
end_comment

begin_comment
comment|// Google Test.  They are subject to change without notice.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_INTERNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_INTERNAL_H_
end_define

begin_include
include|#
directive|include
file|"gtest/internal/gtest-port.h"
end_include

begin_if
if|#
directive|if
name|GTEST_OS_LINUX
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_OS_LINUX
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<iomanip>
end_include

begin_include
include|#
directive|include
file|<limits>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|"gtest/internal/gtest-string.h"
end_include

begin_include
include|#
directive|include
file|"gtest/internal/gtest-filepath.h"
end_include

begin_include
include|#
directive|include
file|"gtest/internal/gtest-type-util.h"
end_include

begin_if
if|#
directive|if
operator|!
name|GTEST_NO_LLVM_RAW_OSTREAM
end_if

begin_include
include|#
directive|include
file|"llvm/Support/raw_os_ostream.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Due to C++ preprocessor weirdness, we need double indirection to
end_comment

begin_comment
comment|// concatenate two tokens when one of them is __LINE__.  Writing
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   foo ## __LINE__
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// will result in the token foo__LINE__, instead of foo followed by
end_comment

begin_comment
comment|// the current line number.  For more details, see
end_comment

begin_comment
comment|// http://www.parashift.com/c++-faq-lite/misc-technical-issues.html#faq-39.6
end_comment

begin_define
define|#
directive|define
name|GTEST_CONCAT_TOKEN_
parameter_list|(
name|foo
parameter_list|,
name|bar
parameter_list|)
value|GTEST_CONCAT_TOKEN_IMPL_(foo, bar)
end_define

begin_define
define|#
directive|define
name|GTEST_CONCAT_TOKEN_IMPL_
parameter_list|(
name|foo
parameter_list|,
name|bar
parameter_list|)
value|foo ## bar
end_define

begin_comment
comment|// Google Test defines the testing::Message class to allow construction of
end_comment

begin_comment
comment|// test messages via the<< operator.  The idea is that anything
end_comment

begin_comment
comment|// streamable to std::ostream can be streamed to a testing::Message.
end_comment

begin_comment
comment|// This allows a user to use his own types in Google Test assertions by
end_comment

begin_comment
comment|// overloading the<< operator.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// util/gtl/stl_logging-inl.h overloads<< for STL containers.  These
end_comment

begin_comment
comment|// overloads cannot be defined in the std namespace, as that will be
end_comment

begin_comment
comment|// undefined behavior.  Therefore, they are defined in the global
end_comment

begin_comment
comment|// namespace instead.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// C++'s symbol lookup rule (i.e. Koenig lookup) says that these
end_comment

begin_comment
comment|// overloads are visible in either the std namespace or the global
end_comment

begin_comment
comment|// namespace, but not other namespaces, including the testing
end_comment

begin_comment
comment|// namespace which Google Test's Message class is in.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To allow STL containers (and other types that has a<< operator
end_comment

begin_comment
comment|// defined in the global namespace) to be used in Google Test assertions,
end_comment

begin_comment
comment|// testing::Message must access the custom<< operator from the global
end_comment

begin_comment
comment|// namespace.  Hence this helper function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note: Jeffrey Yasskin suggested an alternative fix by "using
end_comment

begin_comment
comment|// ::operator<<;" in the definition of Message's operator<<.  That fix
end_comment

begin_comment
comment|// doesn't require a helper function, but unfortunately doesn't
end_comment

begin_comment
comment|// compile with MSVC.
end_comment

begin_comment
comment|// LLVM INTERNAL CHANGE: To allow operator<< to work with both
end_comment

begin_comment
comment|// std::ostreams and LLVM's raw_ostreams, we define a special
end_comment

begin_comment
comment|// std::ostream with an implicit conversion to raw_ostream& and stream
end_comment

begin_comment
comment|// to that.  This causes the compiler to prefer std::ostream overloads
end_comment

begin_comment
comment|// but still find raw_ostream& overloads.
end_comment

begin_if
if|#
directive|if
operator|!
name|GTEST_NO_LLVM_RAW_OSTREAM
end_if

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|convertible_fwd_ostream
range|:
name|public
name|std
operator|::
name|ostream
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|raw_os_ostream
name|ros_
block|;
name|public
operator|:
name|convertible_fwd_ostream
argument_list|(
name|std
operator|::
name|ostream
operator|&
name|os
argument_list|)
operator|:
name|std
operator|::
name|ostream
argument_list|(
name|os
operator|.
name|rdbuf
argument_list|()
argument_list|)
block|,
name|ros_
argument_list|(
argument|*this
argument_list|)
block|{}
name|operator
name|raw_ostream
operator|&
operator|(
operator|)
block|{
return|return
name|ros_
return|;
block|}
expr|}
block|; }
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|GTestStreamToHelper
argument_list|(
argument|std::ostream* os
argument_list|,
argument|const T& val
argument_list|)
block|{
name|llvm
operator|::
name|convertible_fwd_ostream
name|cos
argument_list|(
operator|*
name|os
argument_list|)
block|;
name|cos
operator|<<
name|val
block|; }
else|#
directive|else
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|GTestStreamToHelper
argument_list|(
argument|std::ostream* os
argument_list|,
argument|const T& val
argument_list|)
block|{
operator|*
name|os
operator|<<
name|val
block|; }
endif|#
directive|endif
name|class
name|ProtocolMessage
decl_stmt|;
name|namespace
name|proto2
block|{
name|class
name|Message
decl_stmt|;
block|}
name|namespace
name|testing
block|{
comment|// Forward declarations.
name|class
name|AssertionResult
decl_stmt|;
comment|// Result of an assertion.
name|class
name|Message
decl_stmt|;
comment|// Represents a failure message.
name|class
name|Test
decl_stmt|;
comment|// Represents a test.
name|class
name|TestInfo
decl_stmt|;
comment|// Information about a test.
name|class
name|TestPartResult
decl_stmt|;
comment|// Result of a test part.
name|class
name|UnitTest
decl_stmt|;
comment|// A collection of test cases.
name|template
operator|<
name|typename
name|T
operator|>
operator|::
name|std
operator|::
name|string
name|PrintToString
argument_list|(
specifier|const
name|T
operator|&
name|value
argument_list|)
expr_stmt|;
name|namespace
name|internal
block|{
struct_decl|struct
name|TraceInfo
struct_decl|;
comment|// Information about a trace point.
name|class
name|ScopedTrace
decl_stmt|;
comment|// Implements scoped trace.
name|class
name|TestInfoImpl
decl_stmt|;
comment|// Opaque implementation of TestInfo
name|class
name|UnitTestImpl
decl_stmt|;
comment|// Opaque implementation of UnitTest
comment|// How many times InitGoogleTest() has been called.
specifier|extern
name|int
name|g_init_gtest_count
decl_stmt|;
comment|// The text used in failure messages to indicate the start of the
comment|// stack trace.
name|GTEST_API_
specifier|extern
specifier|const
name|char
name|kStackTraceMarker
index|[]
decl_stmt|;
comment|// A secret type that Google Test users don't know about.  It has no
comment|// definition on purpose.  Therefore it's impossible to create a
comment|// Secret object, which is what we want.
name|class
name|Secret
decl_stmt|;
comment|// Two overloaded helpers for checking at compile time whether an
comment|// expression is a null pointer literal (i.e. NULL or any 0-valued
comment|// compile-time integral constant).  Their return values have
comment|// different sizes, so we can use sizeof() to test which version is
comment|// picked by the compiler.  These helpers have no implementations, as
comment|// we only need their signatures.
comment|//
comment|// Given IsNullLiteralHelper(x), the compiler will pick the first
comment|// version if x can be implicitly converted to Secret*, and pick the
comment|// second version otherwise.  Since Secret is a secret and incomplete
comment|// type, the only expression a user can write that has type Secret* is
comment|// a null pointer literal.  Therefore, we know that x is a null
comment|// pointer literal if and only if the first version is picked by the
comment|// compiler.
name|char
name|IsNullLiteralHelper
parameter_list|(
name|Secret
modifier|*
name|p
parameter_list|)
function_decl|;
name|char
argument_list|(
operator|&
name|IsNullLiteralHelper
argument_list|(
operator|...
argument_list|)
argument_list|)
index|[
literal|2
index|]
expr_stmt|;
comment|// NOLINT
comment|// A compile-time bool constant that is true if and only if x is a
comment|// null pointer literal (i.e. NULL or any 0-valued compile-time
comment|// integral constant).
ifdef|#
directive|ifdef
name|GTEST_ELLIPSIS_NEEDS_POD_
comment|// We lose support for NULL detection where the compiler doesn't like
comment|// passing non-POD classes through ellipsis (...).
define|#
directive|define
name|GTEST_IS_NULL_LITERAL_
parameter_list|(
name|x
parameter_list|)
value|false
else|#
directive|else
define|#
directive|define
name|GTEST_IS_NULL_LITERAL_
parameter_list|(
name|x
parameter_list|)
define|\
value|(sizeof(::testing::internal::IsNullLiteralHelper(x)) == 1)
endif|#
directive|endif
comment|// GTEST_ELLIPSIS_NEEDS_POD_
comment|// Appends the user-supplied message to the Google-Test-generated message.
name|GTEST_API_
name|String
name|AppendUserMessage
parameter_list|(
specifier|const
name|String
modifier|&
name|gtest_msg
parameter_list|,
specifier|const
name|Message
modifier|&
name|user_msg
parameter_list|)
function_decl|;
comment|// A helper class for creating scoped traces in user programs.
name|class
name|GTEST_API_
name|ScopedTrace
block|{
name|public
label|:
comment|// The c'tor pushes the given source file location and message onto
comment|// a trace stack maintained by Google Test.
name|ScopedTrace
argument_list|(
argument|const char* file
argument_list|,
argument|int line
argument_list|,
argument|const Message& message
argument_list|)
empty_stmt|;
comment|// The d'tor pops the info pushed by the c'tor.
comment|//
comment|// Note that the d'tor is not virtual in order to be efficient.
comment|// Don't inherit from ScopedTrace!
operator|~
name|ScopedTrace
argument_list|()
expr_stmt|;
name|private
label|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ScopedTrace
argument_list|)
expr_stmt|;
block|}
name|GTEST_ATTRIBUTE_UNUSED_
expr_stmt|;
comment|// A ScopedTrace object does its job in its
comment|// c'tor and d'tor.  Therefore it doesn't
comment|// need to be used otherwise.
comment|// Converts a streamable value to a String.  A NULL pointer is
comment|// converted to "(null)".  When the input value is a ::string,
comment|// ::std::string, ::wstring, or ::std::wstring object, each NUL
comment|// character in it is replaced with "\\0".
comment|// Declared here but defined in gtest.h, so that it has access
comment|// to the definition of the Message class, required by the ARM
comment|// compiler.
name|template
operator|<
name|typename
name|T
operator|>
name|String
name|StreamableToString
argument_list|(
specifier|const
name|T
operator|&
name|streamable
argument_list|)
expr_stmt|;
comment|// The Symbian compiler has a bug that prevents it from selecting the
comment|// correct overload of FormatForComparisonFailureMessage (see below)
comment|// unless we pass the first argument by reference.  If we do that,
comment|// however, Visual Age C++ 10.1 generates a compiler error.  Therefore
comment|// we only apply the work-around for Symbian.
if|#
directive|if
name|defined
argument_list|(
name|__SYMBIAN32__
argument_list|)
define|#
directive|define
name|GTEST_CREF_WORKAROUND_
value|const&
else|#
directive|else
define|#
directive|define
name|GTEST_CREF_WORKAROUND_
endif|#
directive|endif
comment|// When this operand is a const char* or char*, if the other operand
comment|// is a ::std::string or ::string, we print this operand as a C string
comment|// rather than a pointer (we do the same for wide strings); otherwise
comment|// we print it as a pointer to be safe.
comment|// This internal macro is used to avoid duplicated code.
define|#
directive|define
name|GTEST_FORMAT_IMPL_
parameter_list|(
name|operand2_type
parameter_list|,
name|operand1_printer
parameter_list|)
define|\
value|inline String FormatForComparisonFailureMessage(\     operand2_type::value_type* GTEST_CREF_WORKAROUND_ str, \     const operand2_type&
comment|/*operand2*/
value|) {\   return operand1_printer(str);\ }\ inline String FormatForComparisonFailureMessage(\     const operand2_type::value_type* GTEST_CREF_WORKAROUND_ str, \     const operand2_type&
comment|/*operand2*/
value|) {\   return operand1_printer(str);\ }
name|GTEST_FORMAT_IMPL_
argument_list|(
argument|::std::string
argument_list|,
argument|String::ShowCStringQuoted
argument_list|)
if|#
directive|if
name|GTEST_HAS_STD_WSTRING
name|GTEST_FORMAT_IMPL_
argument_list|(
argument|::std::wstring
argument_list|,
argument|String::ShowWideCStringQuoted
argument_list|)
endif|#
directive|endif
comment|// GTEST_HAS_STD_WSTRING
if|#
directive|if
name|GTEST_HAS_GLOBAL_STRING
name|GTEST_FORMAT_IMPL_
argument_list|(
argument|::string
argument_list|,
argument|String::ShowCStringQuoted
argument_list|)
endif|#
directive|endif
comment|// GTEST_HAS_GLOBAL_STRING
if|#
directive|if
name|GTEST_HAS_GLOBAL_WSTRING
name|GTEST_FORMAT_IMPL_
argument_list|(
argument|::wstring
argument_list|,
argument|String::ShowWideCStringQuoted
argument_list|)
endif|#
directive|endif
comment|// GTEST_HAS_GLOBAL_WSTRING
undef|#
directive|undef
name|GTEST_FORMAT_IMPL_
comment|// The next four overloads handle the case where the operand being
comment|// printed is a char/wchar_t pointer and the other operand is not a
comment|// string/wstring object.  In such cases, we just print the operand as
comment|// a pointer to be safe.
define|#
directive|define
name|GTEST_FORMAT_CHAR_PTR_IMPL_
parameter_list|(
name|CharType
parameter_list|)
define|\
value|template<typename T>                                             \   String FormatForComparisonFailureMessage(CharType* GTEST_CREF_WORKAROUND_ p, \                                            const T&) { \     return PrintToString(static_cast<const void*>(p));              \   }
name|GTEST_FORMAT_CHAR_PTR_IMPL_
argument_list|(
argument|char
argument_list|)
name|GTEST_FORMAT_CHAR_PTR_IMPL_
argument_list|(
argument|const char
argument_list|)
name|GTEST_FORMAT_CHAR_PTR_IMPL_
argument_list|(
argument|wchar_t
argument_list|)
name|GTEST_FORMAT_CHAR_PTR_IMPL_
argument_list|(
argument|const wchar_t
argument_list|)
undef|#
directive|undef
name|GTEST_FORMAT_CHAR_PTR_IMPL_
comment|// Constructs and returns the message for an equality assertion
comment|// (e.g. ASSERT_EQ, EXPECT_STREQ, etc) failure.
comment|//
comment|// The first four parameters are the expressions used in the assertion
comment|// and their values, as strings.  For example, for ASSERT_EQ(foo, bar)
comment|// where foo is 5 and bar is 6, we have:
comment|//
comment|//   expected_expression: "foo"
comment|//   actual_expression:   "bar"
comment|//   expected_value:      "5"
comment|//   actual_value:        "6"
comment|//
comment|// The ignoring_case parameter is true iff the assertion is a
comment|// *_STRCASEEQ*.  When it's true, the string " (ignoring case)" will
comment|// be inserted into the message.
name|GTEST_API_
name|AssertionResult
name|EqFailure
parameter_list|(
specifier|const
name|char
modifier|*
name|expected_expression
parameter_list|,
specifier|const
name|char
modifier|*
name|actual_expression
parameter_list|,
specifier|const
name|String
modifier|&
name|expected_value
parameter_list|,
specifier|const
name|String
modifier|&
name|actual_value
parameter_list|,
name|bool
name|ignoring_case
parameter_list|)
function_decl|;
comment|// Constructs a failure message for Boolean assertions such as EXPECT_TRUE.
name|GTEST_API_
name|String
name|GetBoolAssertionFailureMessage
parameter_list|(
specifier|const
name|AssertionResult
modifier|&
name|assertion_result
parameter_list|,
specifier|const
name|char
modifier|*
name|expression_text
parameter_list|,
specifier|const
name|char
modifier|*
name|actual_predicate_value
parameter_list|,
specifier|const
name|char
modifier|*
name|expected_predicate_value
parameter_list|)
function_decl|;
comment|// This template class represents an IEEE floating-point number
comment|// (either single-precision or double-precision, depending on the
comment|// template parameters).
comment|//
comment|// The purpose of this class is to do more sophisticated number
comment|// comparison.  (Due to round-off error, etc, it's very unlikely that
comment|// two floating-points will be equal exactly.  Hence a naive
comment|// comparison by the == operation often doesn't work.)
comment|//
comment|// Format of IEEE floating-point:
comment|//
comment|//   The most-significant bit being the leftmost, an IEEE
comment|//   floating-point looks like
comment|//
comment|//     sign_bit exponent_bits fraction_bits
comment|//
comment|//   Here, sign_bit is a single bit that designates the sign of the
comment|//   number.
comment|//
comment|//   For float, there are 8 exponent bits and 23 fraction bits.
comment|//
comment|//   For double, there are 11 exponent bits and 52 fraction bits.
comment|//
comment|//   More details can be found at
comment|//   http://en.wikipedia.org/wiki/IEEE_floating-point_standard.
comment|//
comment|// Template parameter:
comment|//
comment|//   RawType: the raw floating-point type (either float or double)
name|template
operator|<
name|typename
name|RawType
operator|>
name|class
name|FloatingPoint
block|{
name|public
operator|:
comment|// Defines the unsigned integer type that has the same size as the
comment|// floating point number.
typedef|typedef
name|typename
name|TypeWithSize
operator|<
sizeof|sizeof
argument_list|(
name|RawType
argument_list|)
operator|>
operator|::
name|UInt
name|Bits
expr_stmt|;
comment|// Constants.
comment|// # of bits in a number.
specifier|static
specifier|const
name|size_t
name|kBitCount
operator|=
literal|8
operator|*
sizeof|sizeof
argument_list|(
name|RawType
argument_list|)
expr_stmt|;
comment|// # of fraction bits in a number.
specifier|static
specifier|const
name|size_t
name|kFractionBitCount
init|=
name|std
operator|::
name|numeric_limits
operator|<
name|RawType
operator|>
operator|::
name|digits
operator|-
literal|1
decl_stmt|;
comment|// # of exponent bits in a number.
specifier|static
specifier|const
name|size_t
name|kExponentBitCount
init|=
name|kBitCount
operator|-
literal|1
operator|-
name|kFractionBitCount
decl_stmt|;
comment|// The mask for the sign bit.
specifier|static
specifier|const
name|Bits
name|kSignBitMask
init|=
name|static_cast
operator|<
name|Bits
operator|>
operator|(
literal|1
operator|)
operator|<<
operator|(
name|kBitCount
operator|-
literal|1
operator|)
decl_stmt|;
comment|// The mask for the fraction bits.
specifier|static
specifier|const
name|Bits
name|kFractionBitMask
init|=
operator|~
name|static_cast
operator|<
name|Bits
operator|>
operator|(
literal|0
operator|)
operator|>>
operator|(
name|kExponentBitCount
operator|+
literal|1
operator|)
decl_stmt|;
comment|// The mask for the exponent bits.
specifier|static
specifier|const
name|Bits
name|kExponentBitMask
init|=
operator|~
operator|(
name|kSignBitMask
operator||
name|kFractionBitMask
operator|)
decl_stmt|;
comment|// How many ULP's (Units in the Last Place) we want to tolerate when
comment|// comparing two numbers.  The larger the value, the more error we
comment|// allow.  A 0 value means that two numbers must be exactly the same
comment|// to be considered equal.
comment|//
comment|// The maximum error of a single floating-point operation is 0.5
comment|// units in the last place.  On Intel CPU's, all floating-point
comment|// calculations are done with 80-bit precision, while double has 64
comment|// bits.  Therefore, 4 should be enough for ordinary use.
comment|//
comment|// See the following article for more details on ULP:
comment|// http://www.cygnus-software.com/papers/comparingfloats/comparingfloats.htm.
specifier|static
specifier|const
name|size_t
name|kMaxUlps
init|=
literal|4
decl_stmt|;
comment|// Constructs a FloatingPoint from a raw floating-point number.
comment|//
comment|// On an Intel CPU, passing a non-normalized NAN (Not a Number)
comment|// around may change its bits, although the new value is guaranteed
comment|// to be also a NAN.  Therefore, don't expect this constructor to
comment|// preserve the bits in x when x is a NAN.
name|explicit
name|FloatingPoint
parameter_list|(
specifier|const
name|RawType
modifier|&
name|x
parameter_list|)
block|{
name|u_
operator|.
name|value_
operator|=
name|x
expr_stmt|;
block|}
comment|// Static methods
comment|// Reinterprets a bit pattern as a floating-point number.
comment|//
comment|// This function is needed to test the AlmostEquals() method.
specifier|static
name|RawType
name|ReinterpretBits
parameter_list|(
specifier|const
name|Bits
name|bits
parameter_list|)
block|{
name|FloatingPoint
name|fp
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|fp
operator|.
name|u_
operator|.
name|bits_
operator|=
name|bits
expr_stmt|;
return|return
name|fp
operator|.
name|u_
operator|.
name|value_
return|;
block|}
comment|// Returns the floating-point number that represent positive infinity.
specifier|static
name|RawType
name|Infinity
parameter_list|()
block|{
return|return
name|ReinterpretBits
argument_list|(
name|kExponentBitMask
argument_list|)
return|;
block|}
comment|// Non-static methods
comment|// Returns the bits that represents this number.
specifier|const
name|Bits
operator|&
name|bits
argument_list|()
specifier|const
block|{
return|return
name|u_
operator|.
name|bits_
return|;
block|}
comment|// Returns the exponent bits of this number.
name|Bits
name|exponent_bits
argument_list|()
specifier|const
block|{
return|return
name|kExponentBitMask
operator|&
name|u_
operator|.
name|bits_
return|;
block|}
comment|// Returns the fraction bits of this number.
name|Bits
name|fraction_bits
argument_list|()
specifier|const
block|{
return|return
name|kFractionBitMask
operator|&
name|u_
operator|.
name|bits_
return|;
block|}
comment|// Returns the sign bit of this number.
name|Bits
name|sign_bit
argument_list|()
specifier|const
block|{
return|return
name|kSignBitMask
operator|&
name|u_
operator|.
name|bits_
return|;
block|}
comment|// Returns true iff this is NAN (not a number).
name|bool
name|is_nan
argument_list|()
specifier|const
block|{
comment|// It's a NAN if the exponent bits are all ones and the fraction
comment|// bits are not entirely zeros.
return|return
operator|(
name|exponent_bits
argument_list|()
operator|==
name|kExponentBitMask
operator|)
operator|&&
operator|(
name|fraction_bits
argument_list|()
operator|!=
literal|0
operator|)
return|;
block|}
comment|// Returns true iff this number is at most kMaxUlps ULP's away from
comment|// rhs.  In particular, this function:
comment|//
comment|//   - returns false if either number is (or both are) NAN.
comment|//   - treats really large numbers as almost equal to infinity.
comment|//   - thinks +0.0 and -0.0 are 0 DLP's apart.
name|bool
name|AlmostEquals
argument_list|(
specifier|const
name|FloatingPoint
operator|&
name|rhs
argument_list|)
decl|const
block|{
comment|// The IEEE standard says that any comparison operation involving
comment|// a NAN must return false.
if|if
condition|(
name|is_nan
argument_list|()
operator|||
name|rhs
operator|.
name|is_nan
argument_list|()
condition|)
return|return
name|false
return|;
return|return
name|DistanceBetweenSignAndMagnitudeNumbers
argument_list|(
name|u_
operator|.
name|bits_
argument_list|,
name|rhs
operator|.
name|u_
operator|.
name|bits_
argument_list|)
operator|<=
name|kMaxUlps
return|;
block|}
name|private
label|:
comment|// The data type used to store the actual floating-point number.
union|union
name|FloatingPointUnion
block|{
name|RawType
name|value_
decl_stmt|;
comment|// The raw floating-point number.
name|Bits
name|bits_
decl_stmt|;
comment|// The bits that represent the number.
block|}
union|;
comment|// Converts an integer from the sign-and-magnitude representation to
comment|// the biased representation.  More precisely, let N be 2 to the
comment|// power of (kBitCount - 1), an integer x is represented by the
comment|// unsigned number x + N.
comment|//
comment|// For instance,
comment|//
comment|//   -N + 1 (the most negative number representable using
comment|//          sign-and-magnitude) is represented by 1;
comment|//   0      is represented by N; and
comment|//   N - 1  (the biggest number representable using
comment|//          sign-and-magnitude) is represented by 2N - 1.
comment|//
comment|// Read http://en.wikipedia.org/wiki/Signed_number_representations
comment|// for more details on signed number representations.
specifier|static
name|Bits
name|SignAndMagnitudeToBiased
parameter_list|(
specifier|const
name|Bits
modifier|&
name|sam
parameter_list|)
block|{
if|if
condition|(
name|kSignBitMask
operator|&
name|sam
condition|)
block|{
comment|// sam represents a negative number.
return|return
operator|~
name|sam
operator|+
literal|1
return|;
block|}
else|else
block|{
comment|// sam represents a positive number.
return|return
name|kSignBitMask
operator||
name|sam
return|;
block|}
block|}
comment|// Given two numbers in the sign-and-magnitude representation,
comment|// returns the distance between them as an unsigned number.
specifier|static
name|Bits
name|DistanceBetweenSignAndMagnitudeNumbers
parameter_list|(
specifier|const
name|Bits
modifier|&
name|sam1
parameter_list|,
specifier|const
name|Bits
modifier|&
name|sam2
parameter_list|)
block|{
specifier|const
name|Bits
name|biased1
init|=
name|SignAndMagnitudeToBiased
argument_list|(
name|sam1
argument_list|)
decl_stmt|;
specifier|const
name|Bits
name|biased2
init|=
name|SignAndMagnitudeToBiased
argument_list|(
name|sam2
argument_list|)
decl_stmt|;
return|return
operator|(
name|biased1
operator|>=
name|biased2
operator|)
condition|?
operator|(
name|biased1
operator|-
name|biased2
operator|)
else|:
operator|(
name|biased2
operator|-
name|biased1
operator|)
return|;
block|}
name|FloatingPointUnion
name|u_
decl_stmt|;
block|}
empty_stmt|;
comment|// Typedefs the instances of the FloatingPoint template class that we
comment|// care to use.
typedef|typedef
name|FloatingPoint
operator|<
name|float
operator|>
name|Float
expr_stmt|;
typedef|typedef
name|FloatingPoint
operator|<
name|double
operator|>
name|Double
expr_stmt|;
comment|// In order to catch the mistake of putting tests that use different
comment|// test fixture classes in the same test case, we need to assign
comment|// unique IDs to fixture classes and compare them.  The TypeId type is
comment|// used to hold such IDs.  The user should treat TypeId as an opaque
comment|// type: the only operation allowed on TypeId values is to compare
comment|// them for equality using the == operator.
typedef|typedef
specifier|const
name|void
modifier|*
name|TypeId
typedef|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|TypeIdHelper
block|{
name|public
operator|:
comment|// dummy_ must not have a const type.  Otherwise an overly eager
comment|// compiler (e.g. MSVC 7.1& 8.0) may try to merge
comment|// TypeIdHelper<T>::dummy_ for different Ts as an "optimization".
specifier|static
name|bool
name|dummy_
block|; }
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|TypeIdHelper
operator|<
name|T
operator|>
operator|::
name|dummy_
operator|=
name|false
expr_stmt|;
comment|// GetTypeId<T>() returns the ID of type T.  Different values will be
comment|// returned for different types.  Calling the function twice with the
comment|// same type argument is guaranteed to return the same ID.
name|template
operator|<
name|typename
name|T
operator|>
name|TypeId
name|GetTypeId
argument_list|()
block|{
comment|// The compiler is required to allocate a different
comment|// TypeIdHelper<T>::dummy_ variable for each T used to instantiate
comment|// the template.  Therefore, the address of dummy_ is guaranteed to
comment|// be unique.
return|return
operator|&
operator|(
name|TypeIdHelper
operator|<
name|T
operator|>
operator|::
name|dummy_
operator|)
return|;
block|}
comment|// Returns the type ID of ::testing::Test.  Always call this instead
comment|// of GetTypeId< ::testing::Test>() to get the type ID of
comment|// ::testing::Test, as the latter may give the wrong result due to a
comment|// suspected linker bug when compiling Google Test as a Mac OS X
comment|// framework.
name|GTEST_API_
name|TypeId
name|GetTestTypeId
parameter_list|()
function_decl|;
comment|// Defines the abstract factory interface that creates instances
comment|// of a Test object.
name|class
name|TestFactoryBase
block|{
name|public
label|:
name|virtual
operator|~
name|TestFactoryBase
argument_list|()
expr_stmt|;
comment|// Creates a test instance to run. The instance is both created and destroyed
comment|// within TestInfoImpl::Run()
name|virtual
name|Test
modifier|*
name|CreateTest
parameter_list|()
init|=
literal|0
function_decl|;
name|protected
label|:
name|TestFactoryBase
argument_list|()
block|{}
name|private
label|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|TestFactoryBase
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|// This class provides implementation of TeastFactoryBase interface.
comment|// It is used in TEST and TEST_F macros.
name|template
operator|<
name|class
name|TestClass
operator|>
name|class
name|TestFactoryImpl
operator|:
name|public
name|TestFactoryBase
block|{
name|public
operator|:
name|virtual
name|Test
operator|*
name|CreateTest
argument_list|()
block|{
return|return
name|new
name|TestClass
return|;
block|}
expr|}
block|;
if|#
directive|if
name|GTEST_OS_WINDOWS
comment|// Predicate-formatters for implementing the HRESULT checking macros
comment|// {ASSERT|EXPECT}_HRESULT_{SUCCEEDED|FAILED}
comment|// We pass a long instead of HRESULT to avoid causing an
comment|// include dependency for the HRESULT type.
name|GTEST_API_
name|AssertionResult
name|IsHRESULTSuccess
argument_list|(
argument|const char* expr
argument_list|,
argument|long hr
argument_list|)
block|;
comment|// NOLINT
name|GTEST_API_
name|AssertionResult
name|IsHRESULTFailure
argument_list|(
argument|const char* expr
argument_list|,
argument|long hr
argument_list|)
block|;
comment|// NOLINT
endif|#
directive|endif
comment|// GTEST_OS_WINDOWS
comment|// Types of SetUpTestCase() and TearDownTestCase() functions.
typedef|typedef
name|void
function_decl|(
modifier|*
name|SetUpTestCaseFunc
function_decl|)
parameter_list|()
function_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|TearDownTestCaseFunc
function_decl|)
parameter_list|()
function_decl|;
comment|// Creates a new TestInfo object and registers it with Google Test;
comment|// returns the created object.
comment|//
comment|// Arguments:
comment|//
comment|//   test_case_name:   name of the test case
comment|//   name:             name of the test
comment|//   type_param        the name of the test's type parameter, or NULL if
comment|//                     this is not  a typed or a type-parameterized test.
comment|//   value_param       text representation of the test's value parameter,
comment|//                     or NULL if this is not a type-parameterized test.
comment|//   fixture_class_id: ID of the test fixture class
comment|//   set_up_tc:        pointer to the function that sets up the test case
comment|//   tear_down_tc:     pointer to the function that tears down the test case
comment|//   factory:          pointer to the factory that creates a test object.
comment|//                     The newly created TestInfo instance will assume
comment|//                     ownership of the factory object.
name|GTEST_API_
name|TestInfo
modifier|*
name|MakeAndRegisterTestInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|test_case_name
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|type_param
parameter_list|,
specifier|const
name|char
modifier|*
name|value_param
parameter_list|,
name|TypeId
name|fixture_class_id
parameter_list|,
name|SetUpTestCaseFunc
name|set_up_tc
parameter_list|,
name|TearDownTestCaseFunc
name|tear_down_tc
parameter_list|,
name|TestFactoryBase
modifier|*
name|factory
parameter_list|)
function_decl|;
comment|// If *pstr starts with the given prefix, modifies *pstr to be right
comment|// past the prefix and returns true; otherwise leaves *pstr unchanged
comment|// and returns false.  None of pstr, *pstr, and prefix can be NULL.
name|GTEST_API_
name|bool
name|SkipPrefix
parameter_list|(
specifier|const
name|char
modifier|*
name|prefix
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|pstr
parameter_list|)
function_decl|;
if|#
directive|if
name|GTEST_HAS_TYPED_TEST
operator|||
name|GTEST_HAS_TYPED_TEST_P
comment|// State of the definition of a type-parameterized test case.
name|class
name|GTEST_API_
name|TypedTestCasePState
block|{
name|public
label|:
name|TypedTestCasePState
argument_list|()
operator|:
name|registered_
argument_list|(
argument|false
argument_list|)
block|{}
comment|// Adds the given test name to defined_test_names_ and return true
comment|// if the test case hasn't been registered; otherwise aborts the
comment|// program.
name|bool
name|AddTestName
argument_list|(
argument|const char* file
argument_list|,
argument|int line
argument_list|,
argument|const char* case_name
argument_list|,
argument|const char* test_name
argument_list|)
block|{
if|if
condition|(
name|registered_
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s Test %s must be defined before "
literal|"REGISTER_TYPED_TEST_CASE_P(%s, ...).\n"
argument_list|,
name|FormatFileLocation
argument_list|(
name|file
argument_list|,
name|line
argument_list|)
operator|.
name|c_str
argument_list|()
argument_list|,
name|test_name
argument_list|,
name|case_name
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|posix
operator|::
name|Abort
argument_list|()
expr_stmt|;
block|}
name|defined_test_names_
operator|.
name|insert
argument_list|(
name|test_name
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
comment|// Verifies that registered_tests match the test names in
comment|// defined_test_names_; returns registered_tests if successful, or
comment|// aborts the program otherwise.
specifier|const
name|char
modifier|*
name|VerifyRegisteredTestNames
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|registered_tests
parameter_list|)
function_decl|;
name|private
label|:
name|bool
name|registered_
decl_stmt|;
operator|::
name|std
operator|::
name|set
operator|<
specifier|const
name|char
operator|*
operator|>
name|defined_test_names_
expr_stmt|;
block|}
empty_stmt|;
comment|// Skips to the first non-space char after the first comma in 'str';
comment|// returns NULL if no comma is found in 'str'.
specifier|inline
specifier|const
name|char
modifier|*
name|SkipComma
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|comma
init|=
name|strchr
argument_list|(
name|str
argument_list|,
literal|','
argument_list|)
decl_stmt|;
if|if
condition|(
name|comma
operator|==
name|NULL
condition|)
block|{
return|return
name|NULL
return|;
block|}
while|while
condition|(
name|IsSpace
argument_list|(
operator|*
operator|(
operator|++
name|comma
operator|)
argument_list|)
condition|)
block|{}
return|return
name|comma
return|;
block|}
comment|// Returns the prefix of 'str' before the first comma in it; returns
comment|// the entire string if it contains no comma.
specifier|inline
name|String
name|GetPrefixUntilComma
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|comma
init|=
name|strchr
argument_list|(
name|str
argument_list|,
literal|','
argument_list|)
decl_stmt|;
return|return
name|comma
operator|==
name|NULL
condition|?
name|String
argument_list|(
name|str
argument_list|)
else|:
name|String
argument_list|(
name|str
argument_list|,
name|comma
operator|-
name|str
argument_list|)
return|;
block|}
comment|// TypeParameterizedTest<Fixture, TestSel, Types>::Register()
comment|// registers a list of type-parameterized tests with Google Test.  The
comment|// return value is insignificant - we just need to return something
comment|// such that we can call this function in a namespace scope.
comment|//
comment|// Implementation note: The GTEST_TEMPLATE_ macro declares a template
comment|// template parameter.  It's defined in gtest-type-util.h.
name|template
operator|<
name|GTEST_TEMPLATE_
name|Fixture
operator|,
name|class
name|TestSel
operator|,
name|typename
name|Types
operator|>
name|class
name|TypeParameterizedTest
block|{
name|public
operator|:
comment|// 'index' is the index of the test in the type list 'Types'
comment|// specified in INSTANTIATE_TYPED_TEST_CASE_P(Prefix, TestCase,
comment|// Types).  Valid values for 'index' are [0, N - 1] where N is the
comment|// length of Types.
specifier|static
name|bool
name|Register
argument_list|(
argument|const char* prefix
argument_list|,
argument|const char* case_name
argument_list|,
argument|const char* test_names
argument_list|,
argument|int index
argument_list|)
block|{
typedef|typedef
name|typename
name|Types
operator|::
name|Head
name|Type
expr_stmt|;
typedef|typedef
name|Fixture
operator|<
name|Type
operator|>
name|FixtureClass
expr_stmt|;
typedef|typedef
name|typename
name|GTEST_BIND_
argument_list|(
name|TestSel
argument_list|,
name|Type
argument_list|)
name|TestClass
typedef|;
comment|// First, registers the first type-parameterized test in the type
comment|// list.
name|MakeAndRegisterTestInfo
argument_list|(
argument|String::Format(
literal|"%s%s%s/%d"
argument|, prefix, prefix[
literal|0
argument|] ==
literal|'\0'
argument|?
literal|""
argument|:
literal|"/"
argument|,                        case_name, index).c_str()
argument_list|,
argument|GetPrefixUntilComma(test_names).c_str()
argument_list|,
argument|GetTypeName<Type>().c_str()
argument_list|,
argument|NULL
argument_list|,
comment|// No value parameter.
argument|GetTypeId<FixtureClass>()
argument_list|,
argument|TestClass::SetUpTestCase
argument_list|,
argument|TestClass::TearDownTestCase
argument_list|,
argument|new TestFactoryImpl<TestClass>
argument_list|)
empty_stmt|;
comment|// Next, recurses (at compile time) with the tail of the type list.
return|return
name|TypeParameterizedTest
operator|<
name|Fixture
operator|,
name|TestSel
operator|,
name|typename
name|Types
operator|::
name|Tail
operator|>
operator|::
name|Register
argument_list|(
name|prefix
argument_list|,
name|case_name
argument_list|,
name|test_names
argument_list|,
name|index
operator|+
literal|1
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|// The base case for the compile time recursion.
end_comment

begin_expr_stmt
name|template
operator|<
name|GTEST_TEMPLATE_
name|Fixture
operator|,
name|class
name|TestSel
operator|>
name|class
name|TypeParameterizedTest
operator|<
name|Fixture
operator|,
name|TestSel
operator|,
name|Types0
operator|>
block|{
name|public
operator|:
specifier|static
name|bool
name|Register
argument_list|(
argument|const char*
comment|/*prefix*/
argument_list|,
argument|const char*
comment|/*case_name*/
argument_list|,
argument|const char*
comment|/*test_names*/
argument_list|,
argument|int
comment|/*index*/
argument_list|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// TypeParameterizedTestCase<Fixture, Tests, Types>::Register()
end_comment

begin_comment
comment|// registers *all combinations* of 'Tests' and 'Types' with Google
end_comment

begin_comment
comment|// Test.  The return value is insignificant - we just need to return
end_comment

begin_comment
comment|// something such that we can call this function in a namespace scope.
end_comment

begin_expr_stmt
name|template
operator|<
name|GTEST_TEMPLATE_
name|Fixture
operator|,
name|typename
name|Tests
operator|,
name|typename
name|Types
operator|>
name|class
name|TypeParameterizedTestCase
block|{
name|public
operator|:
specifier|static
name|bool
name|Register
argument_list|(
argument|const char* prefix
argument_list|,
argument|const char* case_name
argument_list|,
argument|const char* test_names
argument_list|)
block|{
typedef|typedef
name|typename
name|Tests
operator|::
name|Head
name|Head
expr_stmt|;
comment|// First, register the first test in 'Test' for each type in 'Types'.
name|TypeParameterizedTest
operator|<
name|Fixture
operator|,
name|Head
operator|,
name|Types
operator|>
operator|::
name|Register
argument_list|(
name|prefix
argument_list|,
name|case_name
argument_list|,
name|test_names
argument_list|,
literal|0
argument_list|)
block|;
comment|// Next, recurses (at compile time) with the tail of the test list.
return|return
name|TypeParameterizedTestCase
operator|<
name|Fixture
operator|,
name|typename
name|Tests
operator|::
name|Tail
operator|,
name|Types
operator|>
operator|::
name|Register
argument_list|(
name|prefix
argument_list|,
name|case_name
argument_list|,
name|SkipComma
argument_list|(
name|test_names
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// The base case for the compile time recursion.
end_comment

begin_expr_stmt
name|template
operator|<
name|GTEST_TEMPLATE_
name|Fixture
operator|,
name|typename
name|Types
operator|>
name|class
name|TypeParameterizedTestCase
operator|<
name|Fixture
operator|,
name|Templates0
operator|,
name|Types
operator|>
block|{
name|public
operator|:
specifier|static
name|bool
name|Register
argument_list|(
argument|const char*
comment|/*prefix*/
argument_list|,
argument|const char*
comment|/*case_name*/
argument_list|,
argument|const char*
comment|/*test_names*/
argument_list|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_TYPED_TEST || GTEST_HAS_TYPED_TEST_P
end_comment

begin_comment
comment|// Returns the current OS stack trace as a String.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The maximum number of stack frames to be included is specified by
end_comment

begin_comment
comment|// the gtest_stack_trace_depth flag.  The skip_count parameter
end_comment

begin_comment
comment|// specifies the number of top frames to be skipped, which doesn't
end_comment

begin_comment
comment|// count against the number of frames to be included.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For example, if Foo() calls Bar(), which in turn calls
end_comment

begin_comment
comment|// GetCurrentOsStackTraceExceptTop(..., 1), Foo() will be included in
end_comment

begin_comment
comment|// the trace but Bar() and GetCurrentOsStackTraceExceptTop() won't.
end_comment

begin_function_decl
name|GTEST_API_
name|String
name|GetCurrentOsStackTraceExceptTop
parameter_list|(
name|UnitTest
modifier|*
name|unit_test
parameter_list|,
name|int
name|skip_count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Helpers for suppressing warnings on unreachable code or constant
end_comment

begin_comment
comment|// condition.
end_comment

begin_comment
comment|// Always returns true.
end_comment

begin_function_decl
name|GTEST_API_
name|bool
name|AlwaysTrue
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Always returns false.
end_comment

begin_function
specifier|inline
name|bool
name|AlwaysFalse
parameter_list|()
block|{
return|return
operator|!
name|AlwaysTrue
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// Helper for suppressing false warning from Clang on a const char*
end_comment

begin_comment
comment|// variable declared in a conditional expression always being NULL in
end_comment

begin_comment
comment|// the else branch.
end_comment

begin_struct
struct|struct
name|GTEST_API_
name|ConstCharPtr
block|{
name|ConstCharPtr
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
operator|:
name|value
argument_list|(
argument|str
argument_list|)
block|{}
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
specifier|const
name|char
modifier|*
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// A simple Linear Congruential Generator for generating random
end_comment

begin_comment
comment|// numbers with a uniform distribution.  Unlike rand() and srand(), it
end_comment

begin_comment
comment|// doesn't use global state (and therefore can't interfere with user
end_comment

begin_comment
comment|// code).  Unlike rand_r(), it's portable.  An LCG isn't very random,
end_comment

begin_comment
comment|// but it's good enough for our purposes.
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
name|Random
block|{
name|public
label|:
specifier|static
specifier|const
name|UInt32
name|kMaxRange
init|=
literal|1u
operator|<<
literal|31
decl_stmt|;
name|explicit
name|Random
argument_list|(
argument|UInt32 seed
argument_list|)
block|:
name|state_
argument_list|(
argument|seed
argument_list|)
block|{}
name|void
name|Reseed
parameter_list|(
name|UInt32
name|seed
parameter_list|)
block|{
name|state_
operator|=
name|seed
expr_stmt|;
block|}
comment|// Generates a random number from [0, range).  Crashes if 'range' is
comment|// 0 or greater than kMaxRange.
name|UInt32
name|Generate
parameter_list|(
name|UInt32
name|range
parameter_list|)
function_decl|;
name|private
label|:
name|UInt32
name|state_
decl_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|Random
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Defining a variable of type CompileAssertTypesEqual<T1, T2> will cause a
end_comment

begin_comment
comment|// compiler error iff T1 and T2 are different types.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
expr|struct
name|CompileAssertTypesEqual
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|CompileAssertTypesEqual
operator|<
name|T
operator|,
name|T
operator|>
block|{ }
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Removes the reference from a type if it is a reference type,
end_comment

begin_comment
comment|// otherwise leaves it unchanged.  This is the same as
end_comment

begin_comment
comment|// tr1::remove_reference, which is not widely available yet.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|RemoveReference
block|{
typedef|typedef
name|T
name|type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// NOLINT
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|RemoveReference
operator|<
name|T
operator|&
operator|>
block|{
typedef|typedef
name|T
name|type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// NOLINT
end_comment

begin_comment
comment|// A handy wrapper around RemoveReference that works when the argument
end_comment

begin_comment
comment|// T depends on template parameters.
end_comment

begin_define
define|#
directive|define
name|GTEST_REMOVE_REFERENCE_
parameter_list|(
name|T
parameter_list|)
define|\
value|typename ::testing::internal::RemoveReference<T>::type
end_define

begin_comment
comment|// Removes const from a type if it is a const type, otherwise leaves
end_comment

begin_comment
comment|// it unchanged.  This is the same as tr1::remove_const, which is not
end_comment

begin_comment
comment|// widely available yet.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|RemoveConst
block|{
typedef|typedef
name|T
name|type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// NOLINT
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|RemoveConst
operator|<
specifier|const
name|T
operator|>
block|{
typedef|typedef
name|T
name|type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// NOLINT
end_comment

begin_comment
comment|// MSVC 8.0, Sun C++, and IBM XL C++ have a bug which causes the above
end_comment

begin_comment
comment|// definition to fail to remove the const in 'const int[3]' and 'const
end_comment

begin_comment
comment|// char[3][4]'.  The following specialization works around the bug.
end_comment

begin_comment
comment|// However, it causes trouble with GCC and thus needs to be
end_comment

begin_comment
comment|// conditionally compiled.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|__SUNPRO_CC
argument_list|)
operator|||
name|defined
argument_list|(
name|__IBMCPP__
argument_list|)
end_if

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|size_t
name|N
operator|>
expr|struct
name|RemoveConst
operator|<
specifier|const
name|T
index|[
name|N
index|]
operator|>
block|{
typedef|typedef
name|typename
name|RemoveConst
operator|<
name|T
operator|>
operator|::
name|type
name|type
index|[
name|N
index|]
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// A handy wrapper around RemoveConst that works when the argument
end_comment

begin_comment
comment|// T depends on template parameters.
end_comment

begin_define
define|#
directive|define
name|GTEST_REMOVE_CONST_
parameter_list|(
name|T
parameter_list|)
define|\
value|typename ::testing::internal::RemoveConst<T>::type
end_define

begin_comment
comment|// Turns const U&, U&, const U, and U all into U.
end_comment

begin_define
define|#
directive|define
name|GTEST_REMOVE_REFERENCE_AND_CONST_
parameter_list|(
name|T
parameter_list|)
define|\
value|GTEST_REMOVE_CONST_(GTEST_REMOVE_REFERENCE_(T))
end_define

begin_comment
comment|// Adds reference to a type if it is not a reference type,
end_comment

begin_comment
comment|// otherwise leaves it unchanged.  This is the same as
end_comment

begin_comment
comment|// tr1::add_reference, which is not widely available yet.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|AddReference
block|{
typedef|typedef
name|T
modifier|&
name|type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// NOLINT
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|AddReference
operator|<
name|T
operator|&
operator|>
block|{
typedef|typedef
name|T
modifier|&
name|type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// NOLINT
end_comment

begin_comment
comment|// A handy wrapper around AddReference that works when the argument T
end_comment

begin_comment
comment|// depends on template parameters.
end_comment

begin_define
define|#
directive|define
name|GTEST_ADD_REFERENCE_
parameter_list|(
name|T
parameter_list|)
define|\
value|typename ::testing::internal::AddReference<T>::type
end_define

begin_comment
comment|// Adds a reference to const on top of T as necessary.  For example,
end_comment

begin_comment
comment|// it transforms
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   char         ==> const char&
end_comment

begin_comment
comment|//   const char   ==> const char&
end_comment

begin_comment
comment|//   char&        ==> const char&
end_comment

begin_comment
comment|//   const char&  ==> const char&
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The argument T must depend on some template parameters.
end_comment

begin_define
define|#
directive|define
name|GTEST_REFERENCE_TO_CONST_
parameter_list|(
name|T
parameter_list|)
define|\
value|GTEST_ADD_REFERENCE_(const GTEST_REMOVE_REFERENCE_(T))
end_define

begin_comment
comment|// ImplicitlyConvertible<From, To>::value is a compile-time bool
end_comment

begin_comment
comment|// constant that's true iff type From can be implicitly converted to
end_comment

begin_comment
comment|// type To.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|From
operator|,
name|typename
name|To
operator|>
name|class
name|ImplicitlyConvertible
block|{
name|private
operator|:
comment|// We need the following helper functions only for their types.
comment|// They have no implementations.
comment|// MakeFrom() is an expression whose type is From.  We cannot simply
comment|// use From(), as the type From may not have a public default
comment|// constructor.
specifier|static
name|From
name|MakeFrom
argument_list|()
block|;
comment|// These two functions are overloaded.  Given an expression
comment|// Helper(x), the compiler will pick the first version if x can be
comment|// implicitly converted to type To; otherwise it will pick the
comment|// second version.
comment|//
comment|// The first version returns a value of size 1, and the second
comment|// version returns a value of size 2.  Therefore, by checking the
comment|// size of Helper(x), which can be done at compile time, we can tell
comment|// which version of Helper() is used, and hence whether x can be
comment|// implicitly converted to type To.
specifier|static
name|char
name|Helper
argument_list|(
name|To
argument_list|)
block|;
specifier|static
name|char
argument_list|(
operator|&
name|Helper
argument_list|(
operator|...
argument_list|)
argument_list|)
index|[
literal|2
index|]
block|;
comment|// NOLINT
comment|// We have to put the 'public' section after the 'private' section,
comment|// or MSVC refuses to compile the code.
name|public
operator|:
comment|// MSVC warns about implicitly converting from double to int for
comment|// possible loss of data, so we need to temporarily disable the
comment|// warning.
ifdef|#
directive|ifdef
name|_MSC_VER
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
comment|// Saves the current warning state.
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4244
name|)
comment|// Temporarily disables warning 4244.
specifier|static
specifier|const
name|bool
name|value
operator|=
sizeof|sizeof
argument_list|(
name|Helper
argument_list|(
name|ImplicitlyConvertible
operator|::
name|MakeFrom
argument_list|()
argument_list|)
argument_list|)
operator|==
literal|1
block|;
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
comment|// Restores the warning state.
elif|#
directive|elif
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
comment|// C++Builder cannot use member overload resolution during template
comment|// instantiation.  The simplest workaround is to use its C++0x type traits
comment|// functions (C++Builder 2009 and above only).
specifier|static
specifier|const
name|bool
name|value
operator|=
name|__is_convertible
argument_list|(
name|From
argument_list|,
name|To
argument_list|)
block|;
else|#
directive|else
specifier|static
specifier|const
name|bool
name|value
operator|=
sizeof|sizeof
argument_list|(
name|Helper
argument_list|(
name|ImplicitlyConvertible
operator|::
name|MakeFrom
argument_list|()
argument_list|)
argument_list|)
operator|==
literal|1
block|;
endif|#
directive|endif
comment|// _MSV_VER
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|From
operator|,
name|typename
name|To
operator|>
specifier|const
name|bool
name|ImplicitlyConvertible
operator|<
name|From
operator|,
name|To
operator|>
operator|::
name|value
expr_stmt|;
end_expr_stmt

begin_comment
comment|// IsAProtocolMessage<T>::value is a compile-time bool constant that's
end_comment

begin_comment
comment|// true iff T is type ProtocolMessage, proto2::Message, or a subclass
end_comment

begin_comment
comment|// of those.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|IsAProtocolMessage
operator|:
name|public
name|bool_constant
operator|<
name|ImplicitlyConvertible
operator|<
specifier|const
name|T
operator|*
operator|,
specifier|const
operator|::
name|ProtocolMessage
operator|*
operator|>
operator|::
name|value
operator|||
name|ImplicitlyConvertible
operator|<
specifier|const
name|T
operator|*
operator|,
specifier|const
operator|::
name|proto2
operator|::
name|Message
operator|*
operator|>
operator|::
name|value
operator|>
block|{ }
expr_stmt|;
end_expr_stmt

begin_comment
comment|// When the compiler sees expression IsContainerTest<C>(0), if C is an
end_comment

begin_comment
comment|// STL-style container class, the first overload of IsContainerTest
end_comment

begin_comment
comment|// will be viable (since both C::iterator* and C::const_iterator* are
end_comment

begin_comment
comment|// valid types and NULL can be implicitly converted to them).  It will
end_comment

begin_comment
comment|// be picked over the second overload as 'int' is a perfect match for
end_comment

begin_comment
comment|// the type of argument 0.  If C::iterator or C::const_iterator is not
end_comment

begin_comment
comment|// a valid type, the first overload is not viable, and the second
end_comment

begin_comment
comment|// overload will be picked.  Therefore, we can determine whether C is
end_comment

begin_comment
comment|// a container class by checking the type of IsContainerTest<C>(0).
end_comment

begin_comment
comment|// The value of the expression is insignificant.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that we look for both C::iterator and C::const_iterator.  The
end_comment

begin_comment
comment|// reason is that C++ injects the name of a class as a member of the
end_comment

begin_comment
comment|// class itself (e.g. you can refer to class iterator as either
end_comment

begin_comment
comment|// 'iterator' or 'iterator::iterator').  If we look for C::iterator
end_comment

begin_comment
comment|// only, for example, we would mistakenly think that a class named
end_comment

begin_comment
comment|// iterator is an STL container.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Also note that the simpler approach of overloading
end_comment

begin_comment
comment|// IsContainerTest(typename C::const_iterator*) and
end_comment

begin_comment
comment|// IsContainerTest(...) doesn't work with Visual Age C++ and Sun C++.
end_comment

begin_typedef
typedef|typedef
name|int
name|IsContainer
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|class
name|C
operator|>
name|IsContainer
name|IsContainerTest
argument_list|(
argument|int
comment|/* dummy */
argument_list|,
argument|typename C::iterator*
comment|/* it */
argument|= NULL
argument_list|,
argument|typename C::const_iterator*
comment|/* const_it */
argument|= NULL
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|char
name|IsNotContainer
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|class
name|C
operator|>
name|IsNotContainer
name|IsContainerTest
argument_list|(
argument|long
comment|/* dummy */
argument_list|)
block|{
return|return
literal|'\0'
return|;
block|}
end_expr_stmt

begin_comment
comment|// EnableIf<condition>::type is void when 'Cond' is true, and
end_comment

begin_comment
comment|// undefined when 'Cond' is false.  To use SFINAE to make a function
end_comment

begin_comment
comment|// overload only apply when a particular expression is true, add
end_comment

begin_comment
comment|// "typename EnableIf<expression>::type* = 0" as the last parameter.
end_comment

begin_expr_stmt
name|template
operator|<
name|bool
operator|>
expr|struct
name|EnableIf
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|EnableIf
operator|<
name|true
operator|>
block|{
typedef|typedef
name|void
name|type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// NOLINT
end_comment

begin_comment
comment|// Utilities for native arrays.
end_comment

begin_comment
comment|// ArrayEq() compares two k-dimensional native arrays using the
end_comment

begin_comment
comment|// elements' operator==, where k can be any integer>= 0.  When k is
end_comment

begin_comment
comment|// 0, ArrayEq() degenerates into comparing a single pair of values.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|bool
name|ArrayEq
argument_list|(
argument|const T* lhs
argument_list|,
argument|size_t size
argument_list|,
argument|const U* rhs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// This generic version is used when k is 0.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
specifier|inline
name|bool
name|ArrayEq
argument_list|(
argument|const T& lhs
argument_list|,
argument|const U& rhs
argument_list|)
block|{
return|return
name|lhs
operator|==
name|rhs
return|;
block|}
end_expr_stmt

begin_comment
comment|// This overload is used when k>= 1.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|,
name|size_t
name|N
operator|>
specifier|inline
name|bool
name|ArrayEq
argument_list|(
argument|const T(&lhs)[N]
argument_list|,
argument|const U(&rhs)[N]
argument_list|)
block|{
return|return
name|internal
operator|::
name|ArrayEq
argument_list|(
name|lhs
argument_list|,
name|N
argument_list|,
name|rhs
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// This helper reduces code bloat.  If we instead put its logic inside
end_comment

begin_comment
comment|// the previous ArrayEq() function, arrays with different sizes would
end_comment

begin_comment
comment|// lead to different copies of the template code.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|bool
name|ArrayEq
argument_list|(
argument|const T* lhs
argument_list|,
argument|size_t size
argument_list|,
argument|const U* rhs
argument_list|)
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|size
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|!
name|internal
operator|::
name|ArrayEq
argument_list|(
name|lhs
index|[
name|i
index|]
argument_list|,
name|rhs
index|[
name|i
index|]
argument_list|)
condition|)
return|return
name|false
return|;
block|}
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_comment
unit|}
comment|// Finds the first element in the iterator range [begin, end) that
end_comment

begin_comment
comment|// equals elem.  Element may be a native array type itself.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Iter
operator|,
name|typename
name|Element
operator|>
name|Iter
name|ArrayAwareFind
argument_list|(
argument|Iter begin
argument_list|,
argument|Iter end
argument_list|,
argument|const Element& elem
argument_list|)
block|{
for|for
control|(
name|Iter
name|it
init|=
name|begin
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
name|internal
operator|::
name|ArrayEq
argument_list|(
operator|*
name|it
argument_list|,
name|elem
argument_list|)
condition|)
return|return
name|it
return|;
block|}
end_expr_stmt

begin_return
return|return
name|end
return|;
end_return

begin_comment
unit|}
comment|// CopyArray() copies a k-dimensional native array using the elements'
end_comment

begin_comment
comment|// operator=, where k can be any integer>= 0.  When k is 0,
end_comment

begin_comment
comment|// CopyArray() degenerates into copying a single value.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|void
name|CopyArray
argument_list|(
argument|const T* from
argument_list|,
argument|size_t size
argument_list|,
argument|U* to
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// This generic version is used when k is 0.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
specifier|inline
name|void
name|CopyArray
argument_list|(
argument|const T& from
argument_list|,
argument|U* to
argument_list|)
block|{
operator|*
name|to
operator|=
name|from
block|; }
comment|// This overload is used when k>= 1.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|,
name|size_t
name|N
operator|>
specifier|inline
name|void
name|CopyArray
argument_list|(
argument|const T(&from)[N]
argument_list|,
argument|U(*to)[N]
argument_list|)
block|{
name|internal
operator|::
name|CopyArray
argument_list|(
name|from
argument_list|,
name|N
argument_list|,
operator|*
name|to
argument_list|)
block|; }
comment|// This helper reduces code bloat.  If we instead put its logic inside
comment|// the previous CopyArray() function, arrays with different sizes
comment|// would lead to different copies of the template code.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|void
name|CopyArray
argument_list|(
argument|const T* from
argument_list|,
argument|size_t size
argument_list|,
argument|U* to
argument_list|)
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|size
condition|;
name|i
operator|++
control|)
block|{
name|internal
operator|::
name|CopyArray
argument_list|(
name|from
index|[
name|i
index|]
argument_list|,
name|to
operator|+
name|i
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// The relation between an NativeArray object (see below) and the
end_comment

begin_comment
comment|// native array it represents.
end_comment

begin_macro
unit|enum
name|RelationToSource
end_macro

begin_block
block|{
name|kReference
operator|,
comment|// The NativeArray references the native array.
name|kCopy
comment|// The NativeArray makes a copy of the native array and
comment|// owns the copy.
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Adapts a native array to a read-only STL-style container.  Instead
end_comment

begin_comment
comment|// of the complete STL container concept, this adaptor only implements
end_comment

begin_comment
comment|// members useful for Google Mock's container matchers.  New members
end_comment

begin_comment
comment|// should be added as needed.  To simplify the implementation, we only
end_comment

begin_comment
comment|// support Element being a raw type (i.e. having no top-level const or
end_comment

begin_comment
comment|// reference modifier).  It's the client's responsibility to satisfy
end_comment

begin_comment
comment|// this requirement.  Element can be an array type itself (hence
end_comment

begin_comment
comment|// multi-dimensional arrays are supported).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Element
operator|>
name|class
name|NativeArray
block|{
name|public
operator|:
comment|// STL-style container typedefs.
typedef|typedef
name|Element
name|value_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|Element
modifier|*
name|iterator
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|Element
modifier|*
name|const_iterator
typedef|;
end_typedef

begin_comment
comment|// Constructs from a native array.
end_comment

begin_macro
name|NativeArray
argument_list|(
argument|const Element* array
argument_list|,
argument|size_t count
argument_list|,
argument|RelationToSource relation
argument_list|)
end_macro

begin_block
block|{
name|Init
argument_list|(
name|array
argument_list|,
name|count
argument_list|,
name|relation
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|// Copy constructor.
end_comment

begin_macro
name|NativeArray
argument_list|(
argument|const NativeArray& rhs
argument_list|)
end_macro

begin_block
block|{
name|Init
argument_list|(
name|rhs
operator|.
name|array_
argument_list|,
name|rhs
operator|.
name|size_
argument_list|,
name|rhs
operator|.
name|relation_to_source_
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
operator|~
name|NativeArray
argument_list|()
block|{
comment|// Ensures that the user doesn't instantiate NativeArray with a
comment|// const or reference type.
name|static_cast
operator|<
name|void
operator|>
operator|(
name|StaticAssertTypeEqHelper
operator|<
name|Element
operator|,
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
name|Element
argument_list|)
operator|>
operator|(
operator|)
operator|)
block|;
if|if
condition|(
name|relation_to_source_
operator|==
name|kCopy
condition|)
name|delete
index|[]
name|array_
decl_stmt|;
block|}
end_expr_stmt

begin_comment
comment|// STL-style container methods.
end_comment

begin_expr_stmt
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|size_
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|array_
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|array_
operator|+
name|size_
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|NativeArray
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|size
argument_list|()
operator|==
name|rhs
operator|.
name|size
argument_list|()
operator|&&
name|ArrayEq
argument_list|(
name|begin
argument_list|()
argument_list|,
name|size
argument_list|()
argument_list|,
name|rhs
operator|.
name|begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// Initializes this object; makes a copy of the input array if
end_comment

begin_comment
comment|// 'relation' is kCopy.
end_comment

begin_function
name|void
name|Init
parameter_list|(
specifier|const
name|Element
modifier|*
name|array
parameter_list|,
name|size_t
name|a_size
parameter_list|,
name|RelationToSource
name|relation
parameter_list|)
block|{
if|if
condition|(
name|relation
operator|==
name|kReference
condition|)
block|{
name|array_
operator|=
name|array
expr_stmt|;
block|}
else|else
block|{
name|Element
modifier|*
specifier|const
name|copy
init|=
name|new
name|Element
index|[
name|a_size
index|]
decl_stmt|;
name|CopyArray
argument_list|(
name|array
argument_list|,
name|a_size
argument_list|,
name|copy
argument_list|)
expr_stmt|;
name|array_
operator|=
name|copy
expr_stmt|;
block|}
name|size_
operator|=
name|a_size
expr_stmt|;
name|relation_to_source_
operator|=
name|relation
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|const
name|Element
modifier|*
name|array_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|size_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RelationToSource
name|relation_to_source_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|NativeArray
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// namespace internal
end_comment

begin_comment
unit|}
comment|// namespace testing
end_comment

begin_define
define|#
directive|define
name|GTEST_MESSAGE_AT_
parameter_list|(
name|file
parameter_list|,
name|line
parameter_list|,
name|message
parameter_list|,
name|result_type
parameter_list|)
define|\
value|::testing::internal::AssertHelper(result_type, file, line, message) \     = ::testing::Message()
end_define

begin_define
define|#
directive|define
name|GTEST_MESSAGE_
parameter_list|(
name|message
parameter_list|,
name|result_type
parameter_list|)
define|\
value|GTEST_MESSAGE_AT_(__FILE__, __LINE__, message, result_type)
end_define

begin_define
define|#
directive|define
name|GTEST_FATAL_FAILURE_
parameter_list|(
name|message
parameter_list|)
define|\
value|return GTEST_MESSAGE_(message, ::testing::TestPartResult::kFatalFailure)
end_define

begin_define
define|#
directive|define
name|GTEST_NONFATAL_FAILURE_
parameter_list|(
name|message
parameter_list|)
define|\
value|GTEST_MESSAGE_(message, ::testing::TestPartResult::kNonFatalFailure)
end_define

begin_define
define|#
directive|define
name|GTEST_SUCCESS_
parameter_list|(
name|message
parameter_list|)
define|\
value|GTEST_MESSAGE_(message, ::testing::TestPartResult::kSuccess)
end_define

begin_comment
comment|// Suppresses MSVC warnings 4072 (unreachable code) for the code following
end_comment

begin_comment
comment|// statement if it returns or throws (or doesn't return or throw in some
end_comment

begin_comment
comment|// situations).
end_comment

begin_define
define|#
directive|define
name|GTEST_SUPPRESS_UNREACHABLE_CODE_WARNING_BELOW_
parameter_list|(
name|statement
parameter_list|)
define|\
value|if (::testing::internal::AlwaysTrue()) { statement; }
end_define

begin_define
define|#
directive|define
name|GTEST_TEST_THROW_
parameter_list|(
name|statement
parameter_list|,
name|expected_exception
parameter_list|,
name|fail
parameter_list|)
define|\
value|GTEST_AMBIGUOUS_ELSE_BLOCKER_ \   if (::testing::internal::ConstCharPtr gtest_msg = "") { \     bool gtest_caught_expected = false; \     try { \       GTEST_SUPPRESS_UNREACHABLE_CODE_WARNING_BELOW_(statement); \     } \     catch (expected_exception const&) { \       gtest_caught_expected = true; \     } \     catch (...) { \       gtest_msg.value = \           "Expected: " #statement " throws an exception of type " \           #expected_exception ".\n  Actual: it throws a different type."; \       goto GTEST_CONCAT_TOKEN_(gtest_label_testthrow_, __LINE__); \     } \     if (!gtest_caught_expected) { \       gtest_msg.value = \           "Expected: " #statement " throws an exception of type " \           #expected_exception ".\n  Actual: it throws nothing."; \       goto GTEST_CONCAT_TOKEN_(gtest_label_testthrow_, __LINE__); \     } \   } else \     GTEST_CONCAT_TOKEN_(gtest_label_testthrow_, __LINE__): \       fail(gtest_msg.value)
end_define

begin_define
define|#
directive|define
name|GTEST_TEST_NO_THROW_
parameter_list|(
name|statement
parameter_list|,
name|fail
parameter_list|)
define|\
value|GTEST_AMBIGUOUS_ELSE_BLOCKER_ \   if (::testing::internal::AlwaysTrue()) { \     try { \       GTEST_SUPPRESS_UNREACHABLE_CODE_WARNING_BELOW_(statement); \     } \     catch (...) { \       goto GTEST_CONCAT_TOKEN_(gtest_label_testnothrow_, __LINE__); \     } \   } else \     GTEST_CONCAT_TOKEN_(gtest_label_testnothrow_, __LINE__): \       fail("Expected: " #statement " doesn't throw an exception.\n" \            "  Actual: it throws.")
end_define

begin_define
define|#
directive|define
name|GTEST_TEST_ANY_THROW_
parameter_list|(
name|statement
parameter_list|,
name|fail
parameter_list|)
define|\
value|GTEST_AMBIGUOUS_ELSE_BLOCKER_ \   if (::testing::internal::AlwaysTrue()) { \     bool gtest_caught_any = false; \     try { \       GTEST_SUPPRESS_UNREACHABLE_CODE_WARNING_BELOW_(statement); \     } \     catch (...) { \       gtest_caught_any = true; \     } \     if (!gtest_caught_any) { \       goto GTEST_CONCAT_TOKEN_(gtest_label_testanythrow_, __LINE__); \     } \   } else \     GTEST_CONCAT_TOKEN_(gtest_label_testanythrow_, __LINE__): \       fail("Expected: " #statement " throws an exception.\n" \            "  Actual: it doesn't.")
end_define

begin_comment
comment|// Implements Boolean test assertions such as EXPECT_TRUE. expression can be
end_comment

begin_comment
comment|// either a boolean expression or an AssertionResult. text is a textual
end_comment

begin_comment
comment|// represenation of expression as it was passed into the EXPECT_TRUE.
end_comment

begin_define
define|#
directive|define
name|GTEST_TEST_BOOLEAN_
parameter_list|(
name|expression
parameter_list|,
name|text
parameter_list|,
name|actual
parameter_list|,
name|expected
parameter_list|,
name|fail
parameter_list|)
define|\
value|GTEST_AMBIGUOUS_ELSE_BLOCKER_ \   if (const ::testing::AssertionResult gtest_ar_ = \       ::testing::AssertionResult(expression)) \     ; \   else \     fail(::testing::internal::GetBoolAssertionFailureMessage(\         gtest_ar_, text, #actual, #expected).c_str())
end_define

begin_define
define|#
directive|define
name|GTEST_TEST_NO_FATAL_FAILURE_
parameter_list|(
name|statement
parameter_list|,
name|fail
parameter_list|)
define|\
value|GTEST_AMBIGUOUS_ELSE_BLOCKER_ \   if (::testing::internal::AlwaysTrue()) { \     ::testing::internal::HasNewFatalFailureHelper gtest_fatal_failure_checker; \     GTEST_SUPPRESS_UNREACHABLE_CODE_WARNING_BELOW_(statement); \     if (gtest_fatal_failure_checker.has_new_fatal_failure()) { \       goto GTEST_CONCAT_TOKEN_(gtest_label_testnofatal_, __LINE__); \     } \   } else \     GTEST_CONCAT_TOKEN_(gtest_label_testnofatal_, __LINE__): \       fail("Expected: " #statement " doesn't generate new fatal " \            "failures in the current thread.\n" \            "  Actual: it does.")
end_define

begin_comment
comment|// Expands to the name of the class that implements the given test.
end_comment

begin_define
define|#
directive|define
name|GTEST_TEST_CLASS_NAME_
parameter_list|(
name|test_case_name
parameter_list|,
name|test_name
parameter_list|)
define|\
value|test_case_name##_##test_name##_Test
end_define

begin_comment
comment|// Helper macro for defining tests.
end_comment

begin_define
define|#
directive|define
name|GTEST_TEST_
parameter_list|(
name|test_case_name
parameter_list|,
name|test_name
parameter_list|,
name|parent_class
parameter_list|,
name|parent_id
parameter_list|)
define|\
value|class GTEST_TEST_CLASS_NAME_(test_case_name, test_name) : public parent_class {\  public:\   GTEST_TEST_CLASS_NAME_(test_case_name, test_name)() {}\  private:\   virtual void TestBody();\   static ::testing::TestInfo* const test_info_ GTEST_ATTRIBUTE_UNUSED_;\   GTEST_DISALLOW_COPY_AND_ASSIGN_(\       GTEST_TEST_CLASS_NAME_(test_case_name, test_name));\ };\ \ ::testing::TestInfo* const GTEST_TEST_CLASS_NAME_(test_case_name, test_name)\   ::test_info_ =\     ::testing::internal::MakeAndRegisterTestInfo(\         #test_case_name, #test_name, NULL, NULL, \         (parent_id), \         parent_class::SetUpTestCase, \         parent_class::TearDownTestCase, \         new ::testing::internal::TestFactoryImpl<\             GTEST_TEST_CLASS_NAME_(test_case_name, test_name)>);\ void GTEST_TEST_CLASS_NAME_(test_case_name, test_name)::TestBody()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_INCLUDE_GTEST_INTERNAL_GTEST_INTERNAL_H_
end_comment

end_unit

