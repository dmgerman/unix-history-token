begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2007, Google Inc.
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
comment|// Author: wan@google.com (Zhanyong Wan)
end_comment

begin_comment
comment|// Google Mock - a framework for writing C++ mock classes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines some utilities useful for implementing Google
end_comment

begin_comment
comment|// Mock.  They are subject to change without notice, so please DO NOT
end_comment

begin_comment
comment|// USE THEM IN USER CODE.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_INTERNAL_UTILS_H_
end_ifndef

begin_define
define|#
directive|define
name|GMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_INTERNAL_UTILS_H_
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ostream>
end_include

begin_comment
comment|// NOLINT
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"gmock/internal/gmock-generated-internal-utils.h"
end_include

begin_include
include|#
directive|include
file|"gmock/internal/gmock-port.h"
end_include

begin_include
include|#
directive|include
file|"gtest/gtest.h"
end_include

begin_decl_stmt
name|namespace
name|testing
block|{
name|namespace
name|internal
block|{
comment|// Converts an identifier name to a space-separated list of lower-case
comment|// words.  Each maximum substring of the form [A-Za-z][a-z]*|\d+ is
comment|// treated as one word.  For example, both "FooBar123" and
comment|// "foo_bar_123" are converted to "foo bar 123".
name|GTEST_API_
name|string
name|ConvertIdentifierNameToWords
parameter_list|(
specifier|const
name|char
modifier|*
name|id_name
parameter_list|)
function_decl|;
comment|// PointeeOf<Pointer>::type is the type of a value pointed to by a
comment|// Pointer, which can be either a smart pointer or a raw pointer.  The
comment|// following default implementation is for the case where Pointer is a
comment|// smart pointer.
name|template
operator|<
name|typename
name|Pointer
operator|>
expr|struct
name|PointeeOf
block|{
comment|// Smart pointer classes define type element_type as the type of
comment|// their pointees.
typedef|typedef
name|typename
name|Pointer
operator|::
name|element_type
name|type
expr_stmt|;
block|}
empty_stmt|;
comment|// This specialization is for the raw pointer case.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|PointeeOf
operator|<
name|T
operator|*
operator|>
block|{
typedef|typedef
name|T
name|type
typedef|;
block|}
empty_stmt|;
comment|// NOLINT
comment|// GetRawPointer(p) returns the raw pointer underlying p when p is a
comment|// smart pointer, or returns p itself when p is already a raw pointer.
comment|// The following default implementation is for the smart pointer case.
name|template
operator|<
name|typename
name|Pointer
operator|>
specifier|inline
specifier|const
name|typename
name|Pointer
operator|::
name|element_type
operator|*
name|GetRawPointer
argument_list|(
argument|const Pointer& p
argument_list|)
block|{
return|return
name|p
operator|.
name|get
argument_list|()
return|;
block|}
comment|// This overloaded version is for the raw pointer case.
name|template
operator|<
name|typename
name|Element
operator|>
specifier|inline
name|Element
operator|*
name|GetRawPointer
argument_list|(
argument|Element* p
argument_list|)
block|{
return|return
name|p
return|;
block|}
comment|// This comparator allows linked_ptr to be stored in sets.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|LinkedPtrLessThan
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
operator|::
name|testing
operator|::
name|internal
operator|::
name|linked_ptr
operator|<
name|T
operator|>
operator|&
name|lhs
operator|,
specifier|const
operator|::
name|testing
operator|::
name|internal
operator|::
name|linked_ptr
operator|<
name|T
operator|>
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|lhs
operator|.
name|get
argument_list|()
operator|<
name|rhs
operator|.
name|get
argument_list|()
return|;
block|}
expr|}
block|;
comment|// Symbian compilation can be done with wchar_t being either a native
comment|// type or a typedef.  Using Google Mock with OpenC without wchar_t
comment|// should require the definition of _STLP_NO_WCHAR_T.
comment|//
comment|// MSVC treats wchar_t as a native type usually, but treats it as the
comment|// same as unsigned short when the compiler option /Zc:wchar_t- is
comment|// specified.  It defines _NATIVE_WCHAR_T_DEFINED symbol when wchar_t
comment|// is a native type.
if|#
directive|if
operator|(
name|GTEST_OS_SYMBIAN
operator|&&
name|defined
argument_list|(
name|_STLP_NO_WCHAR_T
argument_list|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_NATIVE_WCHAR_T_DEFINED
argument_list|)
operator|)
comment|// wchar_t is a typedef.
else|#
directive|else
define|#
directive|define
name|GMOCK_WCHAR_T_IS_NATIVE_
value|1
endif|#
directive|endif
comment|// signed wchar_t and unsigned wchar_t are NOT in the C++ standard.
comment|// Using them is a bad practice and not portable.  So DON'T use them.
comment|//
comment|// Still, Google Mock is designed to work even if the user uses signed
comment|// wchar_t or unsigned wchar_t (obviously, assuming the compiler
comment|// supports them).
comment|//
comment|// To gcc,
comment|//   wchar_t == signed wchar_t != unsigned wchar_t == unsigned int
ifdef|#
directive|ifdef
name|__GNUC__
comment|// signed/unsigned wchar_t are valid types.
define|#
directive|define
name|GMOCK_HAS_SIGNED_WCHAR_T_
value|1
endif|#
directive|endif
comment|// In what follows, we use the term "kind" to indicate whether a type
comment|// is bool, an integer type (excluding bool), a floating-point type,
comment|// or none of them.  This categorization is useful for determining
comment|// when a matcher argument type can be safely converted to another
comment|// type in the implementation of SafeMatcherCast.
block|enum
name|TypeKind
block|{
name|kBool
block|,
name|kInteger
block|,
name|kFloatingPoint
block|,
name|kOther
block|}
block|;
comment|// KindOf<T>::value is the kind of type T.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|KindOf
block|{   enum
block|{
name|value
operator|=
name|kOther
block|}
block|;
comment|// The default kind.
block|}
block|;
comment|// This macro declares that the kind of 'type' is 'kind'.
define|#
directive|define
name|GMOCK_DECLARE_KIND_
parameter_list|(
name|type
parameter_list|,
name|kind
parameter_list|)
define|\
value|template<> struct KindOf<type> { enum { value = kind }; }
name|GMOCK_DECLARE_KIND_
argument_list|(
name|bool
argument_list|,
name|kBool
argument_list|)
block|;
comment|// All standard integer types.
name|GMOCK_DECLARE_KIND_
argument_list|(
name|char
argument_list|,
name|kInteger
argument_list|)
block|;
name|GMOCK_DECLARE_KIND_
argument_list|(
argument|signed char
argument_list|,
argument|kInteger
argument_list|)
block|;
name|GMOCK_DECLARE_KIND_
argument_list|(
argument|unsigned char
argument_list|,
argument|kInteger
argument_list|)
block|;
name|GMOCK_DECLARE_KIND_
argument_list|(
name|short
argument_list|,
name|kInteger
argument_list|)
block|;
comment|// NOLINT
name|GMOCK_DECLARE_KIND_
argument_list|(
argument|unsigned short
argument_list|,
argument|kInteger
argument_list|)
block|;
comment|// NOLINT
name|GMOCK_DECLARE_KIND_
argument_list|(
name|int
argument_list|,
name|kInteger
argument_list|)
block|;
name|GMOCK_DECLARE_KIND_
argument_list|(
argument|unsigned int
argument_list|,
argument|kInteger
argument_list|)
block|;
name|GMOCK_DECLARE_KIND_
argument_list|(
name|long
argument_list|,
name|kInteger
argument_list|)
block|;
comment|// NOLINT
name|GMOCK_DECLARE_KIND_
argument_list|(
argument|unsigned long
argument_list|,
argument|kInteger
argument_list|)
block|;
comment|// NOLINT
if|#
directive|if
name|GMOCK_WCHAR_T_IS_NATIVE_
name|GMOCK_DECLARE_KIND_
argument_list|(
name|wchar_t
argument_list|,
name|kInteger
argument_list|)
block|;
endif|#
directive|endif
comment|// Non-standard integer types.
name|GMOCK_DECLARE_KIND_
argument_list|(
name|Int64
argument_list|,
name|kInteger
argument_list|)
block|;
name|GMOCK_DECLARE_KIND_
argument_list|(
name|UInt64
argument_list|,
name|kInteger
argument_list|)
block|;
comment|// All standard floating-point types.
name|GMOCK_DECLARE_KIND_
argument_list|(
name|float
argument_list|,
name|kFloatingPoint
argument_list|)
block|;
name|GMOCK_DECLARE_KIND_
argument_list|(
name|double
argument_list|,
name|kFloatingPoint
argument_list|)
block|;
name|GMOCK_DECLARE_KIND_
argument_list|(
argument|long double
argument_list|,
argument|kFloatingPoint
argument_list|)
block|;
undef|#
directive|undef
name|GMOCK_DECLARE_KIND_
comment|// Evaluates to the kind of 'type'.
define|#
directive|define
name|GMOCK_KIND_OF_
parameter_list|(
name|type
parameter_list|)
define|\
value|static_cast< ::testing::internal::TypeKind>( \       ::testing::internal::KindOf<type>::value)
comment|// Evaluates to true iff integer type T is signed.
define|#
directive|define
name|GMOCK_IS_SIGNED_
parameter_list|(
name|T
parameter_list|)
value|(static_cast<T>(-1)< 0)
comment|// LosslessArithmeticConvertibleImpl<kFromKind, From, kToKind, To>::value
comment|// is true iff arithmetic type From can be losslessly converted to
comment|// arithmetic type To.
comment|//
comment|// It's the user's responsibility to ensure that both From and To are
comment|// raw (i.e. has no CV modifier, is not a pointer, and is not a
comment|// reference) built-in arithmetic types, kFromKind is the kind of
comment|// From, and kToKind is the kind of To; the value is
comment|// implementation-defined when the above pre-condition is violated.
name|template
operator|<
name|TypeKind
name|kFromKind
block|,
name|typename
name|From
block|,
name|TypeKind
name|kToKind
block|,
name|typename
name|To
operator|>
expr|struct
name|LosslessArithmeticConvertibleImpl
operator|:
name|public
name|false_type
block|{}
block|;
comment|// Converting bool to bool is lossless.
name|template
operator|<
operator|>
expr|struct
name|LosslessArithmeticConvertibleImpl
operator|<
name|kBool
block|,
name|bool
block|,
name|kBool
block|,
name|bool
operator|>
operator|:
name|public
name|true_type
block|{}
block|;
comment|// NOLINT
comment|// Converting bool to any integer type is lossless.
name|template
operator|<
name|typename
name|To
operator|>
expr|struct
name|LosslessArithmeticConvertibleImpl
operator|<
name|kBool
block|,
name|bool
block|,
name|kInteger
block|,
name|To
operator|>
operator|:
name|public
name|true_type
block|{}
block|;
comment|// NOLINT
comment|// Converting bool to any floating-point type is lossless.
name|template
operator|<
name|typename
name|To
operator|>
expr|struct
name|LosslessArithmeticConvertibleImpl
operator|<
name|kBool
block|,
name|bool
block|,
name|kFloatingPoint
block|,
name|To
operator|>
operator|:
name|public
name|true_type
block|{}
block|;
comment|// NOLINT
comment|// Converting an integer to bool is lossy.
name|template
operator|<
name|typename
name|From
operator|>
expr|struct
name|LosslessArithmeticConvertibleImpl
operator|<
name|kInteger
block|,
name|From
block|,
name|kBool
block|,
name|bool
operator|>
operator|:
name|public
name|false_type
block|{}
block|;
comment|// NOLINT
comment|// Converting an integer to another non-bool integer is lossless iff
comment|// the target type's range encloses the source type's range.
name|template
operator|<
name|typename
name|From
block|,
name|typename
name|To
operator|>
expr|struct
name|LosslessArithmeticConvertibleImpl
operator|<
name|kInteger
block|,
name|From
block|,
name|kInteger
block|,
name|To
operator|>
operator|:
name|public
name|bool_constant
operator|<
comment|// When converting from a smaller size to a larger size, we are
comment|// fine as long as we are not converting from signed to unsigned.
operator|(
operator|(
sizeof|sizeof
argument_list|(
name|From
argument_list|)
operator|<
sizeof|sizeof
argument_list|(
name|To
argument_list|)
operator|)
operator|&&
operator|(
operator|!
name|GMOCK_IS_SIGNED_
argument_list|(
name|From
argument_list|)
operator|||
name|GMOCK_IS_SIGNED_
argument_list|(
name|To
argument_list|)
operator|)
operator|)
operator|||
comment|// When converting between the same size, the signedness must match.
operator|(
operator|(
sizeof|sizeof
argument_list|(
name|From
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|To
argument_list|)
operator|)
operator|&&
operator|(
name|GMOCK_IS_SIGNED_
argument_list|(
name|From
argument_list|)
operator|==
name|GMOCK_IS_SIGNED_
argument_list|(
name|To
argument_list|)
operator|)
operator|)
operator|>
block|{}
block|;
comment|// NOLINT
undef|#
directive|undef
name|GMOCK_IS_SIGNED_
comment|// Converting an integer to a floating-point type may be lossy, since
comment|// the format of a floating-point number is implementation-defined.
name|template
operator|<
name|typename
name|From
block|,
name|typename
name|To
operator|>
expr|struct
name|LosslessArithmeticConvertibleImpl
operator|<
name|kInteger
block|,
name|From
block|,
name|kFloatingPoint
block|,
name|To
operator|>
operator|:
name|public
name|false_type
block|{}
block|;
comment|// NOLINT
comment|// Converting a floating-point to bool is lossy.
name|template
operator|<
name|typename
name|From
operator|>
expr|struct
name|LosslessArithmeticConvertibleImpl
operator|<
name|kFloatingPoint
block|,
name|From
block|,
name|kBool
block|,
name|bool
operator|>
operator|:
name|public
name|false_type
block|{}
block|;
comment|// NOLINT
comment|// Converting a floating-point to an integer is lossy.
name|template
operator|<
name|typename
name|From
block|,
name|typename
name|To
operator|>
expr|struct
name|LosslessArithmeticConvertibleImpl
operator|<
name|kFloatingPoint
block|,
name|From
block|,
name|kInteger
block|,
name|To
operator|>
operator|:
name|public
name|false_type
block|{}
block|;
comment|// NOLINT
comment|// Converting a floating-point to another floating-point is lossless
comment|// iff the target type is at least as big as the source type.
name|template
operator|<
name|typename
name|From
block|,
name|typename
name|To
operator|>
expr|struct
name|LosslessArithmeticConvertibleImpl
operator|<
name|kFloatingPoint
block|,
name|From
block|,
name|kFloatingPoint
block|,
name|To
operator|>
operator|:
name|public
name|bool_constant
operator|<
sizeof|sizeof
argument_list|(
name|From
argument_list|)
operator|<=
sizeof|sizeof
argument_list|(
name|To
argument_list|)
operator|>
block|{}
block|;
comment|// NOLINT
comment|// LosslessArithmeticConvertible<From, To>::value is true iff arithmetic
comment|// type From can be losslessly converted to arithmetic type To.
comment|//
comment|// It's the user's responsibility to ensure that both From and To are
comment|// raw (i.e. has no CV modifier, is not a pointer, and is not a
comment|// reference) built-in arithmetic types; the value is
comment|// implementation-defined when the above pre-condition is violated.
name|template
operator|<
name|typename
name|From
block|,
name|typename
name|To
operator|>
expr|struct
name|LosslessArithmeticConvertible
operator|:
name|public
name|LosslessArithmeticConvertibleImpl
operator|<
name|GMOCK_KIND_OF_
argument_list|(
name|From
argument_list|)
block|,
name|From
block|,
name|GMOCK_KIND_OF_
argument_list|(
name|To
argument_list|)
block|,
name|To
operator|>
block|{}
block|;
comment|// NOLINT
comment|// This interface knows how to report a Google Mock failure (either
comment|// non-fatal or fatal).
name|class
name|FailureReporterInterface
block|{
name|public
operator|:
comment|// The type of a failure (either non-fatal or fatal).
expr|enum
name|FailureType
block|{
name|kNonfatal
block|,
name|kFatal
block|}
block|;
name|virtual
operator|~
name|FailureReporterInterface
argument_list|()
block|{}
comment|// Reports a failure that occurred at the given source file location.
name|virtual
name|void
name|ReportFailure
argument_list|(
argument|FailureType type
argument_list|,
argument|const char* file
argument_list|,
argument|int line
argument_list|,
argument|const string& message
argument_list|)
operator|=
literal|0
block|; }
block|;
comment|// Returns the failure reporter used by Google Mock.
name|GTEST_API_
name|FailureReporterInterface
operator|*
name|GetFailureReporter
argument_list|()
block|;
comment|// Asserts that condition is true; aborts the process with the given
comment|// message if condition is false.  We cannot use LOG(FATAL) or CHECK()
comment|// as Google Mock might be used to mock the log sink itself.  We
comment|// inline this function to prevent it from showing up in the stack
comment|// trace.
specifier|inline
name|void
name|Assert
argument_list|(
argument|bool condition
argument_list|,
argument|const char* file
argument_list|,
argument|int line
argument_list|,
argument|const string& msg
argument_list|)
block|{
if|if
condition|(
operator|!
name|condition
condition|)
block|{
name|GetFailureReporter
argument_list|()
operator|->
name|ReportFailure
argument_list|(
name|FailureReporterInterface
operator|::
name|kFatal
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
block|}
specifier|inline
name|void
name|Assert
argument_list|(
argument|bool condition
argument_list|,
argument|const char* file
argument_list|,
argument|int line
argument_list|)
block|{
name|Assert
argument_list|(
name|condition
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
literal|"Assertion failed."
argument_list|)
block|; }
comment|// Verifies that condition is true; generates a non-fatal failure if
comment|// condition is false.
specifier|inline
name|void
name|Expect
argument_list|(
argument|bool condition
argument_list|,
argument|const char* file
argument_list|,
argument|int line
argument_list|,
argument|const string& msg
argument_list|)
block|{
if|if
condition|(
operator|!
name|condition
condition|)
block|{
name|GetFailureReporter
argument_list|()
operator|->
name|ReportFailure
argument_list|(
name|FailureReporterInterface
operator|::
name|kNonfatal
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
block|}
specifier|inline
name|void
name|Expect
argument_list|(
argument|bool condition
argument_list|,
argument|const char* file
argument_list|,
argument|int line
argument_list|)
block|{
name|Expect
argument_list|(
name|condition
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
literal|"Expectation failed."
argument_list|)
block|; }
comment|// Severity level of a log.
expr|enum
name|LogSeverity
block|{
name|kInfo
operator|=
literal|0
block|,
name|kWarning
operator|=
literal|1
block|}
block|;
comment|// Valid values for the --gmock_verbose flag.
comment|// All logs (informational and warnings) are printed.
specifier|const
name|char
name|kInfoVerbosity
index|[]
operator|=
literal|"info"
block|;
comment|// Only warnings are printed.
specifier|const
name|char
name|kWarningVerbosity
index|[]
operator|=
literal|"warning"
block|;
comment|// No logs are printed.
specifier|const
name|char
name|kErrorVerbosity
index|[]
operator|=
literal|"error"
block|;
comment|// Returns true iff a log with the given severity is visible according
comment|// to the --gmock_verbose flag.
name|GTEST_API_
name|bool
name|LogIsVisible
argument_list|(
argument|LogSeverity severity
argument_list|)
block|;
comment|// Prints the given message to stdout iff 'severity'>= the level
comment|// specified by the --gmock_verbose flag.  If stack_frames_to_skip>=
comment|// 0, also prints the stack trace excluding the top
comment|// stack_frames_to_skip frames.  In opt mode, any positive
comment|// stack_frames_to_skip is treated as 0, since we don't know which
comment|// function calls will be inlined by the compiler and need to be
comment|// conservative.
name|GTEST_API_
name|void
name|Log
argument_list|(
argument|LogSeverity severity
argument_list|,
argument|const string& message
argument_list|,
argument|int stack_frames_to_skip
argument_list|)
block|;
comment|// TODO(wan@google.com): group all type utilities together.
comment|// Type traits.
comment|// is_reference<T>::value is non-zero iff T is a reference type.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_reference
operator|:
name|public
name|false_type
block|{}
block|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_reference
operator|<
name|T
operator|&
operator|>
operator|:
name|public
name|true_type
block|{}
block|;
comment|// type_equals<T1, T2>::value is non-zero iff T1 and T2 are the same type.
name|template
operator|<
name|typename
name|T1
block|,
name|typename
name|T2
operator|>
expr|struct
name|type_equals
operator|:
name|public
name|false_type
block|{}
block|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|type_equals
operator|<
name|T
block|,
name|T
operator|>
operator|:
name|public
name|true_type
block|{}
block|;
comment|// remove_reference<T>::type removes the reference from type T, if any.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_reference
block|{
typedef|typedef
name|T
name|type
typedef|;
block|}
block|;
comment|// NOLINT
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|remove_reference
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
block|;
comment|// NOLINT
comment|// DecayArray<T>::type turns an array type U[N] to const U* and preserves
comment|// other types.  Useful for saving a copy of a function argument.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|DecayArray
block|{
typedef|typedef
name|T
name|type
typedef|;
block|}
block|;
comment|// NOLINT
name|template
operator|<
name|typename
name|T
block|,
name|size_t
name|N
operator|>
expr|struct
name|DecayArray
operator|<
name|T
index|[
name|N
index|]
operator|>
block|{
typedef|typedef
specifier|const
name|T
modifier|*
name|type
typedef|;
block|}
block|;
comment|// Sometimes people use arrays whose size is not available at the use site
comment|// (e.g. extern const char kNamePrefix[]).  This specialization covers that
comment|// case.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|DecayArray
operator|<
name|T
index|[]
operator|>
block|{
typedef|typedef
specifier|const
name|T
modifier|*
name|type
typedef|;
block|}
block|;
comment|// Disable MSVC warnings for infinite recursion, since in this case the
comment|// the recursion is unreachable.
ifdef|#
directive|ifdef
name|_MSC_VER
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4717
name|)
endif|#
directive|endif
comment|// Invalid<T>() is usable as an expression of type T, but will terminate
comment|// the program with an assertion failure if actually run.  This is useful
comment|// when a value of type T is needed for compilation, but the statement
comment|// will not really be executed (or we don't care if the statement
comment|// crashes).
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|Invalid
argument_list|()
block|{
name|Assert
argument_list|(
name|false
argument_list|,
literal|""
argument_list|,
operator|-
literal|1
argument_list|,
literal|"Internal error: attempt to return invalid value"
argument_list|)
block|;
comment|// This statement is unreachable, and would never terminate even if it
comment|// could be reached. It is provided only to placate compiler warnings
comment|// about missing return statements.
return|return
name|Invalid
operator|<
name|T
operator|>
operator|(
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|_MSC_VER
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
endif|#
directive|endif
comment|// Given a raw type (i.e. having no top-level reference or const
comment|// modifier) RawContainer that's either an STL-style container or a
comment|// native array, class StlContainerView<RawContainer> has the
comment|// following members:
comment|//
comment|//   - type is a type that provides an STL-style container view to
comment|//     (i.e. implements the STL container concept for) RawContainer;
comment|//   - const_reference is a type that provides a reference to a const
comment|//     RawContainer;
comment|//   - ConstReference(raw_container) returns a const reference to an STL-style
comment|//     container view to raw_container, which is a RawContainer.
comment|//   - Copy(raw_container) returns an STL-style container view of a
comment|//     copy of raw_container, which is a RawContainer.
comment|//
comment|// This generic version is used when RawContainer itself is already an
comment|// STL-style container.
name|template
operator|<
name|class
name|RawContainer
operator|>
name|class
name|StlContainerView
block|{
name|public
operator|:
typedef|typedef
name|RawContainer
name|type
typedef|;
typedef|typedef
specifier|const
name|type
modifier|&
name|const_reference
typedef|;
specifier|static
name|const_reference
name|ConstReference
argument_list|(
argument|const RawContainer& container
argument_list|)
block|{
comment|// Ensures that RawContainer is not a const type.
name|testing
operator|::
name|StaticAssertTypeEq
operator|<
name|RawContainer
block|,
name|GTEST_REMOVE_CONST_
argument_list|(
name|RawContainer
argument_list|)
operator|>
operator|(
operator|)
block|;
return|return
name|container
return|;
block|}
specifier|static
name|type
name|Copy
argument_list|(
argument|const RawContainer& container
argument_list|)
block|{
return|return
name|container
return|;
block|}
block|}
empty_stmt|;
comment|// This specialization is used when RawContainer is a native array type.
name|template
operator|<
name|typename
name|Element
operator|,
name|size_t
name|N
operator|>
name|class
name|StlContainerView
operator|<
name|Element
index|[
name|N
index|]
operator|>
block|{
name|public
operator|:
typedef|typedef
name|GTEST_REMOVE_CONST_
argument_list|(
argument|Element
argument_list|)
name|RawElement
expr_stmt|;
typedef|typedef
name|internal
operator|::
name|NativeArray
operator|<
name|RawElement
operator|>
name|type
expr_stmt|;
comment|// NativeArray<T> can represent a native array either by value or by
comment|// reference (selected by a constructor argument), so 'const type'
comment|// can be used to reference a const native array.  We cannot
comment|// 'typedef const type& const_reference' here, as that would mean
comment|// ConstReference() has to return a reference to a local variable.
typedef|typedef
specifier|const
name|type
name|const_reference
typedef|;
specifier|static
name|const_reference
name|ConstReference
argument_list|(
specifier|const
name|Element
argument_list|(
operator|&
name|array
argument_list|)
index|[
name|N
index|]
argument_list|)
block|{
comment|// Ensures that Element is not a const type.
name|testing
operator|::
name|StaticAssertTypeEq
operator|<
name|Element
operator|,
name|RawElement
operator|>
operator|(
operator|)
expr_stmt|;
if|#
directive|if
name|GTEST_OS_SYMBIAN
comment|// The Nokia Symbian compiler confuses itself in template instantiation
comment|// for this call without the cast to Element*:
comment|// function call '[testing::internal::NativeArray<char *>].NativeArray(
comment|//     {lval} const char *[4], long, testing::internal::RelationToSource)'
comment|//     does not match
comment|// 'testing::internal::NativeArray<char *>::NativeArray(
comment|//     char *const *, unsigned int, testing::internal::RelationToSource)'
comment|// (instantiating: 'testing::internal::ContainsMatcherImpl
comment|//<const char * (&)[4]>::Matches(const char * (&)[4]) const')
comment|// (instantiating: 'testing::internal::StlContainerView<char *[4]>::
comment|//     ConstReference(const char * (&)[4])')
comment|// (and though the N parameter type is mismatched in the above explicit
comment|// conversion of it doesn't help - only the conversion of the array).
return|return
name|type
argument_list|(
name|const_cast
operator|<
name|Element
operator|*
operator|>
operator|(
operator|&
name|array
index|[
literal|0
index|]
operator|)
argument_list|,
name|N
argument_list|,
name|RelationToSourceReference
argument_list|()
argument_list|)
return|;
else|#
directive|else
return|return
name|type
argument_list|(
name|array
argument_list|,
name|N
argument_list|,
name|RelationToSourceReference
argument_list|()
argument_list|)
return|;
endif|#
directive|endif
comment|// GTEST_OS_SYMBIAN
block|}
specifier|static
name|type
name|Copy
argument_list|(
specifier|const
name|Element
argument_list|(
operator|&
name|array
argument_list|)
index|[
name|N
index|]
argument_list|)
block|{
if|#
directive|if
name|GTEST_OS_SYMBIAN
return|return
name|type
argument_list|(
name|const_cast
operator|<
name|Element
operator|*
operator|>
operator|(
operator|&
name|array
index|[
literal|0
index|]
operator|)
argument_list|,
name|N
argument_list|,
name|RelationToSourceCopy
argument_list|()
argument_list|)
return|;
else|#
directive|else
return|return
name|type
argument_list|(
name|array
argument_list|,
name|N
argument_list|,
name|RelationToSourceCopy
argument_list|()
argument_list|)
return|;
endif|#
directive|endif
comment|// GTEST_OS_SYMBIAN
block|}
block|}
empty_stmt|;
comment|// This specialization is used when RawContainer is a native array
comment|// represented as a (pointer, size) tuple.
name|template
operator|<
name|typename
name|ElementPointer
operator|,
name|typename
name|Size
operator|>
name|class
name|StlContainerView
operator|<
operator|::
name|testing
operator|::
name|tuple
operator|<
name|ElementPointer
operator|,
name|Size
operator|>
expr|>
block|{
name|public
operator|:
typedef|typedef
name|GTEST_REMOVE_CONST_
argument_list|(
argument|typename internal::PointeeOf<ElementPointer>::type
argument_list|)
name|RawElement
expr_stmt|;
typedef|typedef
name|internal
operator|::
name|NativeArray
operator|<
name|RawElement
operator|>
name|type
expr_stmt|;
typedef|typedef
specifier|const
name|type
name|const_reference
typedef|;
specifier|static
name|const_reference
name|ConstReference
argument_list|(
specifier|const
operator|::
name|testing
operator|::
name|tuple
operator|<
name|ElementPointer
argument_list|,
name|Size
operator|>
operator|&
name|array
argument_list|)
block|{
return|return
name|type
argument_list|(
name|get
operator|<
literal|0
operator|>
operator|(
name|array
operator|)
argument_list|,
name|get
operator|<
literal|1
operator|>
operator|(
name|array
operator|)
argument_list|,
name|RelationToSourceReference
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|type
name|Copy
argument_list|(
specifier|const
operator|::
name|testing
operator|::
name|tuple
operator|<
name|ElementPointer
argument_list|,
name|Size
operator|>
operator|&
name|array
argument_list|)
block|{
return|return
name|type
argument_list|(
name|get
operator|<
literal|0
operator|>
operator|(
name|array
operator|)
argument_list|,
name|get
operator|<
literal|1
operator|>
operator|(
name|array
operator|)
argument_list|,
name|RelationToSourceCopy
argument_list|()
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// The following specialization prevents the user from instantiating
end_comment

begin_comment
comment|// StlContainer with a reference type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|StlContainerView
operator|<
name|T
operator|&
operator|>
expr_stmt|;
end_expr_stmt

begin_comment
comment|// A type transform to remove constness from the first part of a pair.
end_comment

begin_comment
comment|// Pairs like that are used as the value_type of associative containers,
end_comment

begin_comment
comment|// and this transform produces a similar but assignable pair.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|RemoveConstFromKey
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
comment|// Partially specialized to remove constness from std::pair<const K, V>.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|K
operator|,
name|typename
name|V
operator|>
expr|struct
name|RemoveConstFromKey
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|K
operator|,
name|V
operator|>
expr|>
block|{
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|K
operator|,
name|V
operator|>
name|type
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Mapping from booleans to types. Similar to boost::bool_<kValue> and
end_comment

begin_comment
comment|// std::integral_constant<bool, kValue>.
end_comment

begin_expr_stmt
name|template
operator|<
name|bool
name|kValue
operator|>
expr|struct
name|BooleanConstant
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// namespace internal
end_comment

begin_comment
unit|}
comment|// namespace testing
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GMOCK_INCLUDE_GMOCK_INTERNAL_GMOCK_INTERNAL_UTILS_H_
end_comment

end_unit

