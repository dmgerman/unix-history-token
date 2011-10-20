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
comment|// Google Test - The Google C++ Testing Framework
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file implements a universal value printer that can print a
end_comment

begin_comment
comment|// value of any type T:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   void ::testing::internal::UniversalPrinter<T>::Print(value, ostream_ptr);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A user can teach this function how to print a class type T by
end_comment

begin_comment
comment|// defining either operator<<() or PrintTo() in the namespace that
end_comment

begin_comment
comment|// defines T.  More specifically, the FIRST defined function in the
end_comment

begin_comment
comment|// following list will be used (assuming T is defined in namespace
end_comment

begin_comment
comment|// foo):
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   1. foo::PrintTo(const T&, ostream*)
end_comment

begin_comment
comment|//   2. operator<<(ostream&, const T&) defined in either foo or the
end_comment

begin_comment
comment|//      global namespace.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If none of the above is defined, it will print the debug string of
end_comment

begin_comment
comment|// the value if it is a protocol buffer, or print the raw bytes in the
end_comment

begin_comment
comment|// value otherwise.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To aid debugging: when T is a reference type, the address of the
end_comment

begin_comment
comment|// value is also printed; when T is a (const) char pointer, both the
end_comment

begin_comment
comment|// pointer value and the NUL-terminated string it points to are
end_comment

begin_comment
comment|// printed.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// We also provide some convenient wrappers:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // Prints a value to a string.  For a (const or not) char
end_comment

begin_comment
comment|//   // pointer, the NUL-terminated string (but not the pointer) is
end_comment

begin_comment
comment|//   // printed.
end_comment

begin_comment
comment|//   std::string ::testing::PrintToString(const T& value);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // Prints a value tersely: for a reference type, the referenced
end_comment

begin_comment
comment|//   // value (but not the address) is printed; for a (const or not) char
end_comment

begin_comment
comment|//   // pointer, the NUL-terminated string (but not the pointer) is
end_comment

begin_comment
comment|//   // printed.
end_comment

begin_comment
comment|//   void ::testing::internal::UniversalTersePrint(const T& value, ostream*);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // Prints value using the type inferred by the compiler.  The difference
end_comment

begin_comment
comment|//   // from UniversalTersePrint() is that this function prints both the
end_comment

begin_comment
comment|//   // pointer and the NUL-terminated string for a (const or not) char pointer.
end_comment

begin_comment
comment|//   void ::testing::internal::UniversalPrint(const T& value, ostream*);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // Prints the fields of a tuple tersely to a string vector, one
end_comment

begin_comment
comment|//   // element for each field. Tuple support must be enabled in
end_comment

begin_comment
comment|//   // gtest-port.h.
end_comment

begin_comment
comment|//   std::vector<string> UniversalTersePrintTupleFieldsToStrings(
end_comment

begin_comment
comment|//       const Tuple& value);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Known limitation:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The print primitives print the elements of an STL-style container
end_comment

begin_comment
comment|// using the compiler-inferred type of *iter where iter is a
end_comment

begin_comment
comment|// const_iterator of the container.  When const_iterator is an input
end_comment

begin_comment
comment|// iterator but not a forward iterator, this inferred type may not
end_comment

begin_comment
comment|// match value_type, and the print output may be incorrect.  In
end_comment

begin_comment
comment|// practice, this is rarely a problem as for most containers
end_comment

begin_comment
comment|// const_iterator is a forward iterator.  We'll fix this if there's an
end_comment

begin_comment
comment|// actual need for it.  Note that this fix cannot rely on value_type
end_comment

begin_comment
comment|// being defined as many user-defined container types don't have
end_comment

begin_comment
comment|// value_type.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_GTEST_PRINTERS_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_GTEST_PRINTERS_H_
end_define

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
file|<sstream>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"gtest/internal/gtest-port.h"
end_include

begin_include
include|#
directive|include
file|"gtest/internal/gtest-internal.h"
end_include

begin_decl_stmt
name|namespace
name|testing
block|{
comment|// Definitions in the 'internal' and 'internal2' name spaces are
comment|// subject to change without notice.  DO NOT USE THEM IN USER CODE!
name|namespace
name|internal2
block|{
comment|// Prints the given number of bytes in the given object to the given
comment|// ostream.
name|GTEST_API_
name|void
name|PrintBytesInObjectTo
argument_list|(
specifier|const
name|unsigned
name|char
operator|*
name|obj_bytes
argument_list|,
name|size_t
name|count
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl_stmt|;
comment|// For selecting which printer to use when a given type has neither<<
comment|// nor PrintTo().
enum|enum
name|TypeKind
block|{
name|kProtobuf
block|,
comment|// a protobuf type
name|kConvertibleToInteger
block|,
comment|// a type implicitly convertible to BiggestInt
comment|// (e.g. a named or unnamed enum type)
name|kOtherType
comment|// anything else
block|}
enum|;
comment|// TypeWithoutFormatter<T, kTypeKind>::PrintValue(value, os) is called
comment|// by the universal printer to print a value of type T when neither
comment|// operator<< nor PrintTo() is defined for T, where kTypeKind is the
comment|// "kind" of T as defined by enum TypeKind.
name|template
operator|<
name|typename
name|T
operator|,
name|TypeKind
name|kTypeKind
operator|>
name|class
name|TypeWithoutFormatter
block|{
name|public
operator|:
comment|// This default version is called when kTypeKind is kOtherType.
specifier|static
name|void
name|PrintValue
argument_list|(
argument|const T& value
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|PrintBytesInObjectTo
argument_list|(
argument|reinterpret_cast<const unsigned char*>(&value)
argument_list|,
argument|sizeof(value)
argument_list|,
argument|os
argument_list|)
block|;   }
block|}
expr_stmt|;
comment|// We print a protobuf using its ShortDebugString() when the string
comment|// doesn't exceed this many characters; otherwise we print it using
comment|// DebugString() for better readability.
specifier|const
name|size_t
name|kProtobufOneLinerMaxLength
init|=
literal|50
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|TypeWithoutFormatter
operator|<
name|T
operator|,
name|kProtobuf
operator|>
block|{
name|public
operator|:
specifier|static
name|void
name|PrintValue
argument_list|(
argument|const T& value
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
specifier|const
operator|::
name|testing
operator|::
name|internal
operator|::
name|string
name|short_str
operator|=
name|value
operator|.
name|ShortDebugString
argument_list|()
block|;
specifier|const
operator|::
name|testing
operator|::
name|internal
operator|::
name|string
name|pretty_str
operator|=
name|short_str
operator|.
name|length
argument_list|()
operator|<=
name|kProtobufOneLinerMaxLength
condition|?
name|short_str
else|:
operator|(
literal|"\n"
operator|+
name|value
operator|.
name|DebugString
argument_list|()
operator|)
block|;
operator|*
name|os
operator|<<
operator|(
literal|"<"
operator|+
name|pretty_str
operator|+
literal|">"
operator|)
block|;   }
block|}
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|TypeWithoutFormatter
operator|<
name|T
operator|,
name|kConvertibleToInteger
operator|>
block|{
name|public
operator|:
comment|// Since T has no<< operator or PrintTo() but can be implicitly
comment|// converted to BiggestInt, we print it as a BiggestInt.
comment|//
comment|// Most likely T is an enum type (either named or unnamed), in which
comment|// case printing it as an integer is the desired behavior.  In case
comment|// T is not an enum, printing it as an integer is the best we can do
comment|// given that it has no user-defined printer.
specifier|static
name|void
name|PrintValue
argument_list|(
argument|const T& value
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
specifier|const
name|internal
operator|::
name|BiggestInt
name|kBigInt
operator|=
name|value
block|;
operator|*
name|os
operator|<<
name|kBigInt
block|;   }
block|}
expr_stmt|;
comment|// Prints the given value to the given ostream.  If the value is a
comment|// protocol message, its debug string is printed; if it's an enum or
comment|// of a type implicitly convertible to BiggestInt, it's printed as an
comment|// integer; otherwise the bytes in the value are printed.  This is
comment|// what UniversalPrinter<T>::Print() does when it knows nothing about
comment|// type T and T has neither<< operator nor PrintTo().
comment|//
comment|// A user can override this behavior for a class type Foo by defining
comment|// a<< operator in the namespace where Foo is defined.
comment|//
comment|// We put this operator in namespace 'internal2' instead of 'internal'
comment|// to simplify the implementation, as much code in 'internal' needs to
comment|// use<< in STL, which would conflict with our own<< were it defined
comment|// in 'internal'.
comment|//
comment|// Note that this operator<< takes a generic std::basic_ostream<Char,
comment|// CharTraits> type instead of the more restricted std::ostream.  If
comment|// we define it to take an std::ostream instead, we'll get an
comment|// "ambiguous overloads" compiler error when trying to print a type
comment|// Foo that supports streaming to std::basic_ostream<Char,
comment|// CharTraits>, as the compiler cannot tell whether
comment|// operator<<(std::ostream&, const T&) or
comment|// operator<<(std::basic_stream<Char, CharTraits>, const Foo&) is more
comment|// specific.
name|template
operator|<
name|typename
name|Char
operator|,
name|typename
name|CharTraits
operator|,
name|typename
name|T
operator|>
operator|::
name|std
operator|::
name|basic_ostream
operator|<
name|Char
operator|,
name|CharTraits
operator|>
operator|&
name|operator
operator|<<
operator|(
operator|::
name|std
operator|::
name|basic_ostream
operator|<
name|Char
operator|,
name|CharTraits
operator|>
operator|&
name|os
operator|,
specifier|const
name|T
operator|&
name|x
operator|)
block|{
name|TypeWithoutFormatter
operator|<
name|T
block|,
operator|(
name|internal
operator|::
name|IsAProtocolMessage
operator|<
name|T
operator|>
operator|::
name|value
operator|?
name|kProtobuf
operator|:
name|internal
operator|::
name|ImplicitlyConvertible
operator|<
specifier|const
name|T
operator|&
operator|,
name|internal
operator|::
name|BiggestInt
operator|>
operator|::
name|value
operator|?
name|kConvertibleToInteger
operator|:
name|kOtherType
operator|)
operator|>
operator|::
name|PrintValue
argument_list|(
name|x
argument_list|,
operator|&
name|os
argument_list|)
block|;
return|return
name|os
return|;
block|}
block|}
comment|// namespace internal2
block|}
end_decl_stmt

begin_comment
comment|// namespace testing
end_comment

begin_comment
comment|// This namespace MUST NOT BE NESTED IN ::testing, or the name look-up
end_comment

begin_comment
comment|// magic needed for implementing UniversalPrinter won't work.
end_comment

begin_decl_stmt
name|namespace
name|testing_internal
block|{
comment|// Used to print a value that is not an STL-style container when the
comment|// user doesn't define PrintTo() for it.
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|DefaultPrintNonContainerTo
argument_list|(
argument|const T& value
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
comment|// With the following statement, during unqualified name lookup,
comment|// testing::internal2::operator<< appears as if it was declared in
comment|// the nearest enclosing namespace that contains both
comment|// ::testing_internal and ::testing::internal2, i.e. the global
comment|// namespace.  For more details, refer to the C++ Standard section
comment|// 7.3.4-1 [namespace.udir].  This allows us to fall back onto
comment|// testing::internal2::operator<< in case T doesn't come with a<<
comment|// operator.
comment|//
comment|// We cannot write 'using ::testing::internal2::operator<<;', which
comment|// gcc 3.3 fails to compile due to a compiler bug.
name|using
name|namespace
operator|::
name|testing
operator|::
name|internal2
block|;
comment|// NOLINT
comment|// Assuming T is defined in namespace foo, in the next statement,
comment|// the compiler will consider all of:
comment|//
comment|//   1. foo::operator<< (thanks to Koenig look-up),
comment|//   2. ::operator<< (as the current namespace is enclosed in ::),
comment|//   3. testing::internal2::operator<< (thanks to the using statement above).
comment|//
comment|// The operator<< whose type matches T best will be picked.
comment|//
comment|// We deliberately allow #2 to be a candidate, as sometimes it's
comment|// impossible to define #1 (e.g. when foo is ::std, defining
comment|// anything in it is undefined behavior unless you are a compiler
comment|// vendor.).
operator|*
name|os
operator|<<
name|value
block|; }
block|}
end_decl_stmt

begin_comment
comment|// namespace testing_internal
end_comment

begin_decl_stmt
name|namespace
name|testing
block|{
name|namespace
name|internal
block|{
comment|// UniversalPrinter<T>::Print(value, ostream_ptr) prints the given
comment|// value to the given ostream.  The caller must ensure that
comment|// 'ostream_ptr' is not NULL, or the behavior is undefined.
comment|//
comment|// We define UniversalPrinter as a class template (as opposed to a
comment|// function template), as we need to partially specialize it for
comment|// reference types, which cannot be done with function templates.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|UniversalPrinter
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|UniversalPrint
argument_list|(
specifier|const
name|T
operator|&
name|value
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
expr_stmt|;
comment|// Used to print an STL-style container when the user doesn't define
comment|// a PrintTo() for it.
name|template
operator|<
name|typename
name|C
operator|>
name|void
name|DefaultPrintTo
argument_list|(
argument|IsContainer
comment|/* dummy */
argument_list|,
argument|false_type
comment|/* is not a pointer */
argument_list|,
argument|const C& container
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
specifier|const
name|size_t
name|kMaxCount
operator|=
literal|32
block|;
comment|// The maximum number of elements to print.
operator|*
name|os
operator|<<
literal|'{'
block|;
name|size_t
name|count
operator|=
literal|0
block|;
for|for
control|(
name|typename
name|C
operator|::
name|const_iterator
name|it
operator|=
name|container
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|container
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
operator|,
operator|++
name|count
control|)
block|{
if|if
condition|(
name|count
operator|>
literal|0
condition|)
block|{
operator|*
name|os
operator|<<
literal|','
expr_stmt|;
if|if
condition|(
name|count
operator|==
name|kMaxCount
condition|)
block|{
comment|// Enough has been printed.
operator|*
name|os
operator|<<
literal|" ..."
expr_stmt|;
break|break;
block|}
block|}
operator|*
name|os
operator|<<
literal|' '
expr_stmt|;
comment|// We cannot call PrintTo(*it, os) here as PrintTo() doesn't
comment|// handle *it being a native array.
name|internal
operator|::
name|UniversalPrint
argument_list|(
operator|*
name|it
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|count
operator|>
literal|0
condition|)
block|{
operator|*
name|os
operator|<<
literal|' '
expr_stmt|;
block|}
operator|*
name|os
operator|<<
literal|'}'
expr_stmt|;
block|}
comment|// Used to print a pointer that is neither a char pointer nor a member
comment|// pointer, when the user doesn't define PrintTo() for it.  (A member
comment|// variable pointer or member function pointer doesn't really point to
comment|// a location in the address space.  Their representation is
comment|// implementation-defined.  Therefore they will be printed as raw
comment|// bytes.)
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|DefaultPrintTo
argument_list|(
argument|IsNotContainer
comment|/* dummy */
argument_list|,
argument|true_type
comment|/* is a pointer */
argument_list|,
argument|T* p
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
block|{
operator|*
name|os
operator|<<
literal|"NULL"
expr_stmt|;
block|}
else|else
block|{
comment|// C++ doesn't allow casting from a function pointer to any object
comment|// pointer.
comment|//
comment|// IsTrue() silences warnings: "Condition is always true",
comment|// "unreachable code".
if|if
condition|(
name|IsTrue
argument_list|(
name|ImplicitlyConvertible
operator|<
name|T
operator|*
argument_list|,
specifier|const
name|void
operator|*
operator|>
operator|::
name|value
argument_list|)
condition|)
block|{
comment|// T is not a function type.  We just call<< to print p,
comment|// relying on ADL to pick up user-defined<< for their pointer
comment|// types, if any.
operator|*
name|os
operator|<<
name|p
expr_stmt|;
block|}
else|else
block|{
comment|// T is a function type, so '*os<< p' doesn't do what we want
comment|// (it just prints p as bool).  We want to print p as a const
comment|// void*.  However, we cannot cast it to const void* directly,
comment|// even using reinterpret_cast, as earlier versions of gcc
comment|// (e.g. 3.4.5) cannot compile the cast when p is a function
comment|// pointer.  Casting to UInt64 first solves the problem.
operator|*
name|os
operator|<<
name|reinterpret_cast
operator|<
specifier|const
name|void
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
name|internal
operator|::
name|UInt64
operator|>
operator|(
name|p
operator|)
operator|)
expr_stmt|;
block|}
block|}
block|}
comment|// Used to print a non-container, non-pointer value when the user
comment|// doesn't define PrintTo() for it.
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|DefaultPrintTo
argument_list|(
argument|IsNotContainer
comment|/* dummy */
argument_list|,
argument|false_type
comment|/* is not a pointer */
argument_list|,
argument|const T& value
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
operator|::
name|testing_internal
operator|::
name|DefaultPrintNonContainerTo
argument_list|(
name|value
argument_list|,
name|os
argument_list|)
block|; }
comment|// Prints the given value using the<< operator if it has one;
comment|// otherwise prints the bytes in it.  This is what
comment|// UniversalPrinter<T>::Print() does when PrintTo() is not specialized
comment|// or overloaded for type T.
comment|//
comment|// A user can override this behavior for a class type Foo by defining
comment|// an overload of PrintTo() in the namespace where Foo is defined.  We
comment|// give the user this option as sometimes defining a<< operator for
comment|// Foo is not desirable (e.g. the coding style may prevent doing it,
comment|// or there is already a<< operator but it doesn't do what the user
comment|// wants).
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|PrintTo
argument_list|(
argument|const T& value
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
comment|// DefaultPrintTo() is overloaded.  The type of its first two
comment|// arguments determine which version will be picked.  If T is an
comment|// STL-style container, the version for container will be called; if
comment|// T is a pointer, the pointer version will be called; otherwise the
comment|// generic version will be called.
comment|//
comment|// Note that we check for container types here, prior to we check
comment|// for protocol message types in our operator<<.  The rationale is:
comment|//
comment|// For protocol messages, we want to give people a chance to
comment|// override Google Mock's format by defining a PrintTo() or
comment|// operator<<.  For STL containers, other formats can be
comment|// incompatible with Google Mock's format for the container
comment|// elements; therefore we check for container types here to ensure
comment|// that our format is used.
comment|//
comment|// The second argument of DefaultPrintTo() is needed to bypass a bug
comment|// in Symbian's C++ compiler that prevents it from picking the right
comment|// overload between:
comment|//
comment|//   PrintTo(const T& x, ...);
comment|//   PrintTo(T* x, ...);
name|DefaultPrintTo
argument_list|(
name|IsContainerTest
operator|<
name|T
operator|>
operator|(
literal|0
operator|)
argument_list|,
name|is_pointer
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|,
name|value
argument_list|,
name|os
argument_list|)
block|; }
comment|// The following list of PrintTo() overloads tells
comment|// UniversalPrinter<T>::Print() how to print standard types (built-in
comment|// types, strings, plain arrays, and pointers).
comment|// Overloads for various char types.
name|GTEST_API_
name|void
name|PrintTo
argument_list|(
argument|unsigned char c
argument_list|,
argument|::std::ostream* os
argument_list|)
expr_stmt|;
name|GTEST_API_
name|void
name|PrintTo
argument_list|(
name|signed
name|char
name|c
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl_stmt|;
specifier|inline
name|void
name|PrintTo
argument_list|(
name|char
name|c
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
block|{
comment|// When printing a plain char, we always treat it as unsigned.  This
comment|// way, the output won't be affected by whether the compiler thinks
comment|// char is signed or not.
name|PrintTo
argument_list|(
argument|static_cast<unsigned char>(c)
argument_list|,
argument|os
argument_list|)
empty_stmt|;
block|}
comment|// Overloads for other simple built-in types.
specifier|inline
name|void
name|PrintTo
argument_list|(
name|bool
name|x
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
block|{
operator|*
name|os
operator|<<
operator|(
name|x
condition|?
literal|"true"
else|:
literal|"false"
operator|)
expr_stmt|;
block|}
comment|// Overload for wchar_t type.
comment|// Prints a wchar_t as a symbol if it is printable or as its internal
comment|// code otherwise and also as its decimal code (except for L'\0').
comment|// The L'\0' char is printed as "L'\\0'". The decimal code is printed
comment|// as signed integer when wchar_t is implemented by the compiler
comment|// as a signed type and is printed as an unsigned integer when wchar_t
comment|// is implemented as an unsigned type.
name|GTEST_API_
name|void
name|PrintTo
argument_list|(
name|wchar_t
name|wc
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl_stmt|;
comment|// Overloads for C strings.
name|GTEST_API_
name|void
name|PrintTo
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl_stmt|;
specifier|inline
name|void
name|PrintTo
argument_list|(
name|char
operator|*
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
block|{
name|PrintTo
argument_list|(
name|ImplicitCast_
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|s
operator|)
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
comment|// signed/unsigned char is often used for representing binary data, so
comment|// we print pointers to it as void* to be safe.
specifier|inline
name|void
name|PrintTo
argument_list|(
specifier|const
name|signed
name|char
operator|*
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
block|{
name|PrintTo
argument_list|(
name|ImplicitCast_
operator|<
specifier|const
name|void
operator|*
operator|>
operator|(
name|s
operator|)
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|PrintTo
argument_list|(
name|signed
name|char
operator|*
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
block|{
name|PrintTo
argument_list|(
name|ImplicitCast_
operator|<
specifier|const
name|void
operator|*
operator|>
operator|(
name|s
operator|)
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|PrintTo
argument_list|(
specifier|const
name|unsigned
name|char
operator|*
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
block|{
name|PrintTo
argument_list|(
name|ImplicitCast_
operator|<
specifier|const
name|void
operator|*
operator|>
operator|(
name|s
operator|)
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|PrintTo
argument_list|(
name|unsigned
name|char
operator|*
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
block|{
name|PrintTo
argument_list|(
name|ImplicitCast_
operator|<
specifier|const
name|void
operator|*
operator|>
operator|(
name|s
operator|)
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
comment|// MSVC can be configured to define wchar_t as a typedef of unsigned
comment|// short.  It defines _NATIVE_WCHAR_T_DEFINED when wchar_t is a native
comment|// type.  When wchar_t is a typedef, defining an overload for const
comment|// wchar_t* would cause unsigned short* be printed as a wide string,
comment|// possibly causing invalid memory accesses.
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|_NATIVE_WCHAR_T_DEFINED
argument_list|)
comment|// Overloads for wide C strings
name|GTEST_API_
name|void
name|PrintTo
argument_list|(
specifier|const
name|wchar_t
operator|*
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl_stmt|;
specifier|inline
name|void
name|PrintTo
argument_list|(
name|wchar_t
operator|*
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
block|{
name|PrintTo
argument_list|(
name|ImplicitCast_
operator|<
specifier|const
name|wchar_t
operator|*
operator|>
operator|(
name|s
operator|)
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// Overload for C arrays.  Multi-dimensional arrays are printed
comment|// properly.
comment|// Prints the given number of elements in an array, without printing
comment|// the curly braces.
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|PrintRawArrayTo
argument_list|(
argument|const T a[]
argument_list|,
argument|size_t count
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|UniversalPrint
argument_list|(
name|a
index|[
literal|0
index|]
argument_list|,
name|os
argument_list|)
block|;
for|for
control|(
name|size_t
name|i
init|=
literal|1
init|;
name|i
operator|!=
name|count
condition|;
name|i
operator|++
control|)
block|{
operator|*
name|os
operator|<<
literal|", "
expr_stmt|;
name|UniversalPrint
argument_list|(
name|a
index|[
name|i
index|]
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Overloads for ::string and ::std::string.
if|#
directive|if
name|GTEST_HAS_GLOBAL_STRING
name|GTEST_API_
name|void
name|PrintStringTo
argument_list|(
specifier|const
operator|::
name|string
operator|&
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
expr_stmt|;
specifier|inline
name|void
name|PrintTo
argument_list|(
specifier|const
operator|::
name|string
operator|&
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
block|{
name|PrintStringTo
argument_list|(
name|s
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// GTEST_HAS_GLOBAL_STRING
name|GTEST_API_
name|void
name|PrintStringTo
argument_list|(
specifier|const
operator|::
name|std
operator|::
name|string
operator|&
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl_stmt|;
specifier|inline
name|void
name|PrintTo
argument_list|(
specifier|const
operator|::
name|std
operator|::
name|string
operator|&
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
block|{
name|PrintStringTo
argument_list|(
name|s
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
comment|// Overloads for ::wstring and ::std::wstring.
if|#
directive|if
name|GTEST_HAS_GLOBAL_WSTRING
name|GTEST_API_
name|void
name|PrintWideStringTo
argument_list|(
specifier|const
operator|::
name|wstring
operator|&
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl_stmt|;
specifier|inline
name|void
name|PrintTo
argument_list|(
specifier|const
operator|::
name|wstring
operator|&
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
block|{
name|PrintWideStringTo
argument_list|(
name|s
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// GTEST_HAS_GLOBAL_WSTRING
if|#
directive|if
name|GTEST_HAS_STD_WSTRING
name|GTEST_API_
name|void
name|PrintWideStringTo
argument_list|(
specifier|const
operator|::
name|std
operator|::
name|wstring
operator|&
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl_stmt|;
specifier|inline
name|void
name|PrintTo
argument_list|(
specifier|const
operator|::
name|std
operator|::
name|wstring
operator|&
name|s
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
block|{
name|PrintWideStringTo
argument_list|(
name|s
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// GTEST_HAS_STD_WSTRING
if|#
directive|if
name|GTEST_HAS_TR1_TUPLE
comment|// Overload for ::std::tr1::tuple.  Needed for printing function arguments,
comment|// which are packed as tuples.
comment|// Helper function for printing a tuple.  T must be instantiated with
comment|// a tuple type.
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|PrintTupleTo
argument_list|(
specifier|const
name|T
operator|&
name|t
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
expr_stmt|;
comment|// Overloaded PrintTo() for tuples of various arities.  We support
comment|// tuples of up-to 10 fields.  The following implementation works
comment|// regardless of whether tr1::tuple is implemented using the
comment|// non-standard variadic template feature or not.
specifier|inline
name|void
name|PrintTo
argument_list|(
specifier|const
operator|::
name|std
operator|::
name|tr1
operator|::
name|tuple
operator|<
operator|>
operator|&
name|t
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
block|{
name|PrintTupleTo
argument_list|(
name|t
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
name|template
operator|<
name|typename
name|T1
operator|>
name|void
name|PrintTo
argument_list|(
argument|const ::std::tr1::tuple<T1>& t
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|PrintTupleTo
argument_list|(
name|t
argument_list|,
name|os
argument_list|)
block|; }
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|void
name|PrintTo
argument_list|(
argument|const ::std::tr1::tuple<T1
argument_list|,
argument|T2>& t
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|PrintTupleTo
argument_list|(
name|t
argument_list|,
name|os
argument_list|)
block|; }
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|>
name|void
name|PrintTo
argument_list|(
argument|const ::std::tr1::tuple<T1
argument_list|,
argument|T2
argument_list|,
argument|T3>& t
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|PrintTupleTo
argument_list|(
name|t
argument_list|,
name|os
argument_list|)
block|; }
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|>
name|void
name|PrintTo
argument_list|(
argument|const ::std::tr1::tuple<T1
argument_list|,
argument|T2
argument_list|,
argument|T3
argument_list|,
argument|T4>& t
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|PrintTupleTo
argument_list|(
name|t
argument_list|,
name|os
argument_list|)
block|; }
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|>
name|void
name|PrintTo
argument_list|(
argument|const ::std::tr1::tuple<T1
argument_list|,
argument|T2
argument_list|,
argument|T3
argument_list|,
argument|T4
argument_list|,
argument|T5>& t
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|PrintTupleTo
argument_list|(
name|t
argument_list|,
name|os
argument_list|)
block|; }
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|,
name|typename
name|T6
operator|>
name|void
name|PrintTo
argument_list|(
argument|const ::std::tr1::tuple<T1
argument_list|,
argument|T2
argument_list|,
argument|T3
argument_list|,
argument|T4
argument_list|,
argument|T5
argument_list|,
argument|T6>& t
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|PrintTupleTo
argument_list|(
name|t
argument_list|,
name|os
argument_list|)
block|; }
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|,
name|typename
name|T6
operator|,
name|typename
name|T7
operator|>
name|void
name|PrintTo
argument_list|(
argument|const ::std::tr1::tuple<T1
argument_list|,
argument|T2
argument_list|,
argument|T3
argument_list|,
argument|T4
argument_list|,
argument|T5
argument_list|,
argument|T6
argument_list|,
argument|T7>& t
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|PrintTupleTo
argument_list|(
name|t
argument_list|,
name|os
argument_list|)
block|; }
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|,
name|typename
name|T6
operator|,
name|typename
name|T7
operator|,
name|typename
name|T8
operator|>
name|void
name|PrintTo
argument_list|(
argument|const ::std::tr1::tuple<T1
argument_list|,
argument|T2
argument_list|,
argument|T3
argument_list|,
argument|T4
argument_list|,
argument|T5
argument_list|,
argument|T6
argument_list|,
argument|T7
argument_list|,
argument|T8>& t
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|PrintTupleTo
argument_list|(
name|t
argument_list|,
name|os
argument_list|)
block|; }
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|,
name|typename
name|T6
operator|,
name|typename
name|T7
operator|,
name|typename
name|T8
operator|,
name|typename
name|T9
operator|>
name|void
name|PrintTo
argument_list|(
argument|const ::std::tr1::tuple<T1
argument_list|,
argument|T2
argument_list|,
argument|T3
argument_list|,
argument|T4
argument_list|,
argument|T5
argument_list|,
argument|T6
argument_list|,
argument|T7
argument_list|,
argument|T8
argument_list|,
argument|T9>& t
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|PrintTupleTo
argument_list|(
name|t
argument_list|,
name|os
argument_list|)
block|; }
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|,
name|typename
name|T4
operator|,
name|typename
name|T5
operator|,
name|typename
name|T6
operator|,
name|typename
name|T7
operator|,
name|typename
name|T8
operator|,
name|typename
name|T9
operator|,
name|typename
name|T10
operator|>
name|void
name|PrintTo
argument_list|(
argument|const ::std::tr1::tuple<T1
argument_list|,
argument|T2
argument_list|,
argument|T3
argument_list|,
argument|T4
argument_list|,
argument|T5
argument_list|,
argument|T6
argument_list|,
argument|T7
argument_list|,
argument|T8
argument_list|,
argument|T9
argument_list|,
argument|T10>& t
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|PrintTupleTo
argument_list|(
name|t
argument_list|,
name|os
argument_list|)
block|; }
endif|#
directive|endif
comment|// GTEST_HAS_TR1_TUPLE
comment|// Overload for std::pair.
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|void
name|PrintTo
argument_list|(
argument|const ::std::pair<T1
argument_list|,
argument|T2>& value
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
operator|*
name|os
operator|<<
literal|'('
block|;
comment|// We cannot use UniversalPrint(value.first, os) here, as T1 may be
comment|// a reference type.  The same for printing value.second.
name|UniversalPrinter
operator|<
name|T1
operator|>
operator|::
name|Print
argument_list|(
name|value
operator|.
name|first
argument_list|,
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|", "
block|;
name|UniversalPrinter
operator|<
name|T2
operator|>
operator|::
name|Print
argument_list|(
name|value
operator|.
name|second
argument_list|,
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|')'
block|; }
comment|// Implements printing a non-reference type T by letting the compiler
comment|// pick the right overload of PrintTo() for T.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|UniversalPrinter
block|{
name|public
operator|:
comment|// MSVC warns about adding const to a function type, so we want to
comment|// disable the warning.
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
name|4180
name|)
comment|// Temporarily disables warning 4180.
endif|#
directive|endif
comment|// _MSC_VER
comment|// Note: we deliberately don't call this PrintTo(), as that name
comment|// conflicts with ::testing::internal::PrintTo in the body of the
comment|// function.
specifier|static
name|void
name|Print
argument_list|(
argument|const T& value
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
comment|// By default, ::testing::internal::PrintTo() is used for printing
comment|// the value.
comment|//
comment|// Thanks to Koenig look-up, if T is a class and has its own
comment|// PrintTo() function defined in its namespace, that function will
comment|// be visible here.  Since it is more specific than the generic ones
comment|// in ::testing::internal, it will be picked by the compiler in the
comment|// following statement - exactly what we want.
name|PrintTo
argument_list|(
name|value
argument_list|,
name|os
argument_list|)
block|;   }
ifdef|#
directive|ifdef
name|_MSC_VER
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
comment|// Restores the warning state.
endif|#
directive|endif
comment|// _MSC_VER
block|}
expr_stmt|;
comment|// UniversalPrintArray(begin, len, os) prints an array of 'len'
comment|// elements, starting at address 'begin'.
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|UniversalPrintArray
argument_list|(
argument|const T* begin
argument_list|,
argument|size_t len
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
if|if
condition|(
name|len
operator|==
literal|0
condition|)
block|{
operator|*
name|os
operator|<<
literal|"{}"
expr_stmt|;
block|}
else|else
block|{
operator|*
name|os
operator|<<
literal|"{ "
expr_stmt|;
specifier|const
name|size_t
name|kThreshold
init|=
literal|18
decl_stmt|;
specifier|const
name|size_t
name|kChunkSize
init|=
literal|8
decl_stmt|;
comment|// If the array has more than kThreshold elements, we'll have to
comment|// omit some details by printing only the first and the last
comment|// kChunkSize elements.
comment|// TODO(wan@google.com): let the user control the threshold using a flag.
if|if
condition|(
name|len
operator|<=
name|kThreshold
condition|)
block|{
name|PrintRawArrayTo
argument_list|(
name|begin
argument_list|,
name|len
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|PrintRawArrayTo
argument_list|(
name|begin
argument_list|,
name|kChunkSize
argument_list|,
name|os
argument_list|)
expr_stmt|;
operator|*
name|os
operator|<<
literal|", ..., "
expr_stmt|;
name|PrintRawArrayTo
argument_list|(
name|begin
operator|+
name|len
operator|-
name|kChunkSize
argument_list|,
name|kChunkSize
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
operator|*
name|os
operator|<<
literal|" }"
expr_stmt|;
block|}
block|}
comment|// This overload prints a (const) char array compactly.
name|GTEST_API_
name|void
name|UniversalPrintArray
argument_list|(
argument|const char* begin
argument_list|,
argument|size_t len
argument_list|,
argument|::std::ostream* os
argument_list|)
expr_stmt|;
comment|// Implements printing an array type T[N].
name|template
operator|<
name|typename
name|T
operator|,
name|size_t
name|N
operator|>
name|class
name|UniversalPrinter
operator|<
name|T
index|[
name|N
index|]
operator|>
block|{
name|public
operator|:
comment|// Prints the given array, omitting some elements when there are too
comment|// many.
specifier|static
name|void
name|Print
argument_list|(
argument|const T (&a)[N]
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|UniversalPrintArray
argument_list|(
name|a
argument_list|,
name|N
argument_list|,
name|os
argument_list|)
block|;   }
block|}
expr_stmt|;
comment|// Implements printing a reference type T&.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|UniversalPrinter
operator|<
name|T
operator|&
operator|>
block|{
name|public
operator|:
comment|// MSVC warns about adding const to a function type, so we want to
comment|// disable the warning.
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
name|4180
name|)
comment|// Temporarily disables warning 4180.
endif|#
directive|endif
comment|// _MSC_VER
specifier|static
name|void
name|Print
argument_list|(
argument|const T& value
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
comment|// Prints the address of the value.  We use reinterpret_cast here
comment|// as static_cast doesn't compile when T is a function type.
operator|*
name|os
operator|<<
literal|"@"
operator|<<
name|reinterpret_cast
operator|<
specifier|const
name|void
operator|*
operator|>
operator|(
operator|&
name|value
operator|)
operator|<<
literal|" "
block|;
comment|// Then prints the value itself.
name|UniversalPrint
argument_list|(
name|value
argument_list|,
name|os
argument_list|)
block|;   }
ifdef|#
directive|ifdef
name|_MSC_VER
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
comment|// Restores the warning state.
endif|#
directive|endif
comment|// _MSC_VER
block|}
expr_stmt|;
comment|// Prints a value tersely: for a reference type, the referenced value
comment|// (but not the address) is printed; for a (const) char pointer, the
comment|// NUL-terminated string (but not the pointer) is printed.
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|UniversalTersePrint
argument_list|(
argument|const T& value
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|UniversalPrint
argument_list|(
name|value
argument_list|,
name|os
argument_list|)
block|; }
specifier|inline
name|void
name|UniversalTersePrint
argument_list|(
argument|const char* str
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
if|if
condition|(
name|str
operator|==
name|NULL
condition|)
block|{
operator|*
name|os
operator|<<
literal|"NULL"
expr_stmt|;
block|}
else|else
block|{
name|UniversalPrint
argument_list|(
name|string
argument_list|(
name|str
argument_list|)
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
block|}
specifier|inline
name|void
name|UniversalTersePrint
argument_list|(
argument|char* str
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|UniversalTersePrint
argument_list|(
name|static_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
name|str
operator|)
argument_list|,
name|os
argument_list|)
block|; }
comment|// Prints a value using the type inferred by the compiler.  The
comment|// difference between this and UniversalTersePrint() is that for a
comment|// (const) char pointer, this prints both the pointer and the
comment|// NUL-terminated string.
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|UniversalPrint
argument_list|(
argument|const T& value
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|UniversalPrinter
operator|<
name|T
operator|>
operator|::
name|Print
argument_list|(
name|value
argument_list|,
name|os
argument_list|)
block|; }
if|#
directive|if
name|GTEST_HAS_TR1_TUPLE
typedef|typedef
operator|::
name|std
operator|::
name|vector
operator|<
name|string
operator|>
name|Strings
expr_stmt|;
comment|// This helper template allows PrintTo() for tuples and
comment|// UniversalTersePrintTupleFieldsToStrings() to be defined by
comment|// induction on the number of tuple fields.  The idea is that
comment|// TuplePrefixPrinter<N>::PrintPrefixTo(t, os) prints the first N
comment|// fields in tuple t, and can be defined in terms of
comment|// TuplePrefixPrinter<N - 1>.
comment|// The inductive case.
name|template
operator|<
name|size_t
name|N
operator|>
expr|struct
name|TuplePrefixPrinter
block|{
comment|// Prints the first N fields of a tuple.
name|template
operator|<
name|typename
name|Tuple
operator|>
specifier|static
name|void
name|PrintPrefixTo
argument_list|(
argument|const Tuple& t
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|TuplePrefixPrinter
operator|<
name|N
operator|-
literal|1
operator|>
operator|::
name|PrintPrefixTo
argument_list|(
name|t
argument_list|,
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|", "
block|;
name|UniversalPrinter
operator|<
name|typename
operator|::
name|std
operator|::
name|tr1
operator|::
name|tuple_element
operator|<
name|N
operator|-
literal|1
block|,
name|Tuple
operator|>
operator|::
name|type
operator|>
operator|::
name|Print
argument_list|(
operator|::
name|std
operator|::
name|tr1
operator|::
name|get
operator|<
name|N
operator|-
literal|1
operator|>
operator|(
name|t
operator|)
argument_list|,
name|os
argument_list|)
block|;   }
comment|// Tersely prints the first N fields of a tuple to a string vector,
comment|// one element for each field.
name|template
operator|<
name|typename
name|Tuple
operator|>
specifier|static
name|void
name|TersePrintPrefixToStrings
argument_list|(
argument|const Tuple& t
argument_list|,
argument|Strings* strings
argument_list|)
block|{
name|TuplePrefixPrinter
operator|<
name|N
operator|-
literal|1
operator|>
operator|::
name|TersePrintPrefixToStrings
argument_list|(
name|t
argument_list|,
name|strings
argument_list|)
block|;
operator|::
name|std
operator|::
name|stringstream
name|ss
block|;
name|UniversalTersePrint
argument_list|(
operator|::
name|std
operator|::
name|tr1
operator|::
name|get
operator|<
name|N
operator|-
literal|1
operator|>
operator|(
name|t
operator|)
argument_list|,
operator|&
name|ss
argument_list|)
block|;
name|strings
operator|->
name|push_back
argument_list|(
name|ss
operator|.
name|str
argument_list|()
argument_list|)
block|;   }
block|}
expr_stmt|;
comment|// Base cases.
name|template
operator|<
operator|>
expr|struct
name|TuplePrefixPrinter
operator|<
literal|0
operator|>
block|{
name|template
operator|<
name|typename
name|Tuple
operator|>
specifier|static
name|void
name|PrintPrefixTo
argument_list|(
argument|const Tuple&
argument_list|,
argument|::std::ostream*
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Tuple
operator|>
specifier|static
name|void
name|TersePrintPrefixToStrings
argument_list|(
argument|const Tuple&
argument_list|,
argument|Strings*
argument_list|)
block|{}
block|}
expr_stmt|;
comment|// We have to specialize the entire TuplePrefixPrinter<> class
comment|// template here, even though the definition of
comment|// TersePrintPrefixToStrings() is the same as the generic version, as
comment|// Embarcadero (formerly CodeGear, formerly Borland) C++ doesn't
comment|// support specializing a method template of a class template.
name|template
operator|<
operator|>
expr|struct
name|TuplePrefixPrinter
operator|<
literal|1
operator|>
block|{
name|template
operator|<
name|typename
name|Tuple
operator|>
specifier|static
name|void
name|PrintPrefixTo
argument_list|(
argument|const Tuple& t
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|UniversalPrinter
operator|<
name|typename
operator|::
name|std
operator|::
name|tr1
operator|::
name|tuple_element
operator|<
literal|0
block|,
name|Tuple
operator|>
operator|::
name|type
operator|>
operator|::
name|Print
argument_list|(
operator|::
name|std
operator|::
name|tr1
operator|::
name|get
operator|<
literal|0
operator|>
operator|(
name|t
operator|)
argument_list|,
name|os
argument_list|)
block|;   }
name|template
operator|<
name|typename
name|Tuple
operator|>
specifier|static
name|void
name|TersePrintPrefixToStrings
argument_list|(
argument|const Tuple& t
argument_list|,
argument|Strings* strings
argument_list|)
block|{
operator|::
name|std
operator|::
name|stringstream
name|ss
block|;
name|UniversalTersePrint
argument_list|(
operator|::
name|std
operator|::
name|tr1
operator|::
name|get
operator|<
literal|0
operator|>
operator|(
name|t
operator|)
argument_list|,
operator|&
name|ss
argument_list|)
block|;
name|strings
operator|->
name|push_back
argument_list|(
name|ss
operator|.
name|str
argument_list|()
argument_list|)
block|;   }
block|}
expr_stmt|;
comment|// Helper function for printing a tuple.  T must be instantiated with
comment|// a tuple type.
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|PrintTupleTo
argument_list|(
argument|const T& t
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
operator|*
name|os
operator|<<
literal|"("
block|;
name|TuplePrefixPrinter
operator|<
operator|::
name|std
operator|::
name|tr1
operator|::
name|tuple_size
operator|<
name|T
operator|>
operator|::
name|value
operator|>
operator|::
name|PrintPrefixTo
argument_list|(
name|t
argument_list|,
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|")"
block|; }
comment|// Prints the fields of a tuple tersely to a string vector, one
comment|// element for each field.  See the comment before
comment|// UniversalTersePrint() for how we define "tersely".
name|template
operator|<
name|typename
name|Tuple
operator|>
name|Strings
name|UniversalTersePrintTupleFieldsToStrings
argument_list|(
argument|const Tuple& value
argument_list|)
block|{
name|Strings
name|result
block|;
name|TuplePrefixPrinter
operator|<
operator|::
name|std
operator|::
name|tr1
operator|::
name|tuple_size
operator|<
name|Tuple
operator|>
operator|::
name|value
operator|>
operator|::
name|TersePrintPrefixToStrings
argument_list|(
name|value
argument_list|,
operator|&
name|result
argument_list|)
block|;
return|return
name|result
return|;
block|}
endif|#
directive|endif
comment|// GTEST_HAS_TR1_TUPLE
block|}
comment|// namespace internal
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
argument|const T& value
argument_list|)
block|{
operator|::
name|std
operator|::
name|stringstream
name|ss
block|;
name|internal
operator|::
name|UniversalTersePrint
argument_list|(
name|value
argument_list|,
operator|&
name|ss
argument_list|)
block|;
return|return
name|ss
operator|.
name|str
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace testing
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_INCLUDE_GTEST_GTEST_PRINTERS_H_
end_comment

end_unit

