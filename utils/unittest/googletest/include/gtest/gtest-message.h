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
comment|// Author: wan@google.com (Zhanyong Wan)
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
comment|// This header file defines the Message class.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IMPORTANT NOTE: Due to limitation of the C++ language, we have to
end_comment

begin_comment
comment|// leave some internal implementation details in this header file.
end_comment

begin_comment
comment|// They are clearly marked by comments like this:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Such code is NOT meant to be used by a user directly, and is subject
end_comment

begin_comment
comment|// to CHANGE WITHOUT NOTICE.  Therefore DO NOT DEPEND ON IT in a user
end_comment

begin_comment
comment|// program!
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_GTEST_MESSAGE_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_GTEST_MESSAGE_H_
end_define

begin_include
include|#
directive|include
file|<gtest/internal/gtest-string.h>
end_include

begin_include
include|#
directive|include
file|<gtest/internal/gtest-internal.h>
end_include

begin_decl_stmt
name|namespace
name|testing
block|{
comment|// The Message class works like an ostream repeater.
comment|//
comment|// Typical usage:
comment|//
comment|//   1. You stream a bunch of values to a Message object.
comment|//      It will remember the text in a StrStream.
comment|//   2. Then you stream the Message object to an ostream.
comment|//      This causes the text in the Message to be streamed
comment|//      to the ostream.
comment|//
comment|// For example;
comment|//
comment|//   testing::Message foo;
comment|//   foo<< 1<< " != "<< 2;
comment|//   std::cout<< foo;
comment|//
comment|// will print "1 != 2".
comment|//
comment|// Message is not intended to be inherited from.  In particular, its
comment|// destructor is not virtual.
comment|//
comment|// Note that StrStream behaves differently in gcc and in MSVC.  You
comment|// can stream a NULL char pointer to it in the former, but not in the
comment|// latter (it causes an access violation if you do).  The Message
comment|// class hides this difference by treating a NULL char pointer as
comment|// "(null)".
name|class
name|Message
block|{
name|private
label|:
comment|// The type of basic IO manipulators (endl, ends, and flush) for
comment|// narrow streams.
typedef|typedef
name|std
operator|::
name|ostream
operator|&
call|(
modifier|*
name|BasicNarrowIoManip
call|)
argument_list|(
name|std
operator|::
name|ostream
operator|&
argument_list|)
expr_stmt|;
name|public
label|:
comment|// Constructs an empty Message.
comment|// We allocate the StrStream separately because it otherwise each use of
comment|// ASSERT/EXPECT in a procedure adds over 200 bytes to the procedure's
comment|// stack frame leading to huge stack frames in some cases; gcc does not reuse
comment|// the stack space.
name|Message
argument_list|()
operator|:
name|ss_
argument_list|(
argument|new internal::StrStream
argument_list|)
block|{}
comment|// Copy constructor.
name|Message
argument_list|(
specifier|const
name|Message
operator|&
name|msg
argument_list|)
operator|:
name|ss_
argument_list|(
argument|new internal::StrStream
argument_list|)
block|{
comment|// NOLINT
operator|*
name|ss_
operator|<<
name|msg
operator|.
name|GetString
argument_list|()
block|;   }
comment|// Constructs a Message from a C-string.
name|explicit
name|Message
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
operator|:
name|ss_
argument_list|(
argument|new internal::StrStream
argument_list|)
block|{
operator|*
name|ss_
operator|<<
name|str
block|;   }
operator|~
name|Message
argument_list|()
block|{
name|delete
name|ss_
block|; }
ifdef|#
directive|ifdef
name|GTEST_OS_SYMBIAN
comment|// Streams a value (either a pointer or not) to this object.
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|Message
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|T
operator|&
name|value
operator|)
block|{
name|StreamHelper
argument_list|(
argument|typename internal::is_pointer<T>::type()
argument_list|,
argument|value
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
else|#
directive|else
comment|// Streams a non-pointer value to this object.
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|Message
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|T
operator|&
name|val
operator|)
block|{
operator|::
name|GTestStreamToHelper
argument_list|(
name|ss_
argument_list|,
name|val
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|// Streams a pointer value to this object.
comment|//
comment|// This function is an overload of the previous one.  When you
comment|// stream a pointer to a Message, this definition will be used as it
comment|// is more specialized.  (The C++ Standard, section
comment|// [temp.func.order].)  If you stream a non-pointer, then the
comment|// previous definition will be used.
comment|//
comment|// The reason for this overload is that streaming a NULL pointer to
comment|// ostream is undefined behavior.  Depending on the compiler, you
comment|// may get "0", "(nil)", "(null)", or an access violation.  To
comment|// ensure consistent result across compilers, we always treat NULL
comment|// as "(null)".
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|Message
operator|&
name|operator
operator|<<
operator|(
name|T
operator|*
specifier|const
operator|&
name|pointer
operator|)
block|{
comment|// NOLINT
if|if
condition|(
name|pointer
operator|==
name|NULL
condition|)
block|{
operator|*
name|ss_
operator|<<
literal|"(null)"
expr_stmt|;
block|}
else|else
block|{
operator|::
name|GTestStreamToHelper
argument_list|(
name|ss_
argument_list|,
name|pointer
argument_list|)
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
comment|// GTEST_OS_SYMBIAN
comment|// Since the basic IO manipulators are overloaded for both narrow
comment|// and wide streams, we have to provide this specialized definition
comment|// of operator<<, even though its body is the same as the
comment|// templatized version above.  Without this definition, streaming
comment|// endl or other basic IO manipulators to Message will confuse the
comment|// compiler.
name|Message
operator|&
name|operator
operator|<<
operator|(
name|BasicNarrowIoManip
name|val
operator|)
block|{
operator|*
name|ss_
operator|<<
name|val
block|;
return|return
operator|*
name|this
return|;
block|}
comment|// Instead of 1/0, we want to see true/false for bool values.
name|Message
operator|&
name|operator
operator|<<
operator|(
name|bool
name|b
operator|)
block|{
return|return
operator|*
name|this
operator|<<
operator|(
name|b
operator|?
literal|"true"
operator|:
literal|"false"
operator|)
return|;
block|}
comment|// These two overloads allow streaming a wide C string to a Message
comment|// using the UTF-8 encoding.
name|Message
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|wchar_t
operator|*
name|wide_c_str
operator|)
block|{
return|return
operator|*
name|this
operator|<<
name|internal
operator|::
name|String
operator|::
name|ShowWideCString
argument_list|(
name|wide_c_str
argument_list|)
return|;
block|}
name|Message
operator|&
name|operator
operator|<<
operator|(
name|wchar_t
operator|*
name|wide_c_str
operator|)
block|{
return|return
operator|*
name|this
operator|<<
name|internal
operator|::
name|String
operator|::
name|ShowWideCString
argument_list|(
name|wide_c_str
argument_list|)
return|;
block|}
if|#
directive|if
name|GTEST_HAS_STD_WSTRING
comment|// Converts the given wide string to a narrow string using the UTF-8
comment|// encoding, and streams the result to this Message object.
name|Message
operator|&
name|operator
operator|<<
operator|(
specifier|const
operator|::
name|std
operator|::
name|wstring
operator|&
name|wstr
operator|)
expr_stmt|;
endif|#
directive|endif
comment|// GTEST_HAS_STD_WSTRING
if|#
directive|if
name|GTEST_HAS_GLOBAL_WSTRING
comment|// Converts the given wide string to a narrow string using the UTF-8
comment|// encoding, and streams the result to this Message object.
name|Message
operator|&
name|operator
operator|<<
operator|(
specifier|const
operator|::
name|wstring
operator|&
name|wstr
operator|)
expr_stmt|;
endif|#
directive|endif
comment|// GTEST_HAS_GLOBAL_WSTRING
comment|// Gets the text streamed to this object so far as a String.
comment|// Each '\0' character in the buffer is replaced with "\\0".
comment|//
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
name|internal
operator|::
name|String
name|GetString
argument_list|()
specifier|const
block|{
return|return
name|internal
operator|::
name|StrStreamToString
argument_list|(
name|ss_
argument_list|)
return|;
block|}
name|private
label|:
ifdef|#
directive|ifdef
name|GTEST_OS_SYMBIAN
comment|// These are needed as the Nokia Symbian Compiler cannot decide between
comment|// const T& and const T* in a function template. The Nokia compiler _can_
comment|// decide between class template specializations for T and T*, so a
comment|// tr1::type_traits-like is_pointer works, and we can overload on that.
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|StreamHelper
argument_list|(
argument|internal::true_type dummy
argument_list|,
argument|T* pointer
argument_list|)
block|{
if|if
condition|(
name|pointer
operator|==
name|NULL
condition|)
block|{
operator|*
name|ss_
operator|<<
literal|"(null)"
expr_stmt|;
block|}
else|else
block|{
operator|::
name|GTestStreamToHelper
argument_list|(
name|ss_
argument_list|,
name|pointer
argument_list|)
expr_stmt|;
block|}
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|StreamHelper
argument_list|(
argument|internal::false_type dummy
argument_list|,
argument|const T& value
argument_list|)
block|{
operator|::
name|GTestStreamToHelper
argument_list|(
name|ss_
argument_list|,
name|value
argument_list|)
block|;   }
endif|#
directive|endif
comment|// GTEST_OS_SYMBIAN
comment|// We'll hold the text streamed to this object here.
name|internal
operator|::
name|StrStream
operator|*
specifier|const
name|ss_
expr_stmt|;
comment|// We declare (but don't implement) this to prevent the compiler
comment|// from implementing the assignment operator.
name|void
name|operator
init|=
operator|(
specifier|const
name|Message
operator|&
operator|)
decl_stmt|;
block|}
empty_stmt|;
comment|// Streams a Message to an ostream.
specifier|inline
name|std
operator|::
name|ostream
operator|&
name|operator
operator|<<
operator|(
name|std
operator|::
name|ostream
operator|&
name|os
operator|,
specifier|const
name|Message
operator|&
name|sb
operator|)
block|{
return|return
name|os
operator|<<
name|sb
operator|.
name|GetString
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
comment|// GTEST_INCLUDE_GTEST_GTEST_MESSAGE_H_
end_comment

end_unit

