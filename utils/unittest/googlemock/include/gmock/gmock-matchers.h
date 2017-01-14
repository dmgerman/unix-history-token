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
comment|// This file implements some commonly used argument matchers.  More
end_comment

begin_comment
comment|// matchers can be defined by the user implementing the
end_comment

begin_comment
comment|// MatcherInterface<T> interface if necessary.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GMOCK_INCLUDE_GMOCK_GMOCK_MATCHERS_H_
end_ifndef

begin_define
define|#
directive|define
name|GMOCK_INCLUDE_GMOCK_GMOCK_MATCHERS_H_
end_define

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<limits>
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
file|"gmock/internal/gmock-internal-utils.h"
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

begin_if
if|#
directive|if
name|GTEST_HAS_STD_INITIALIZER_LIST_
end_if

begin_include
include|#
directive|include
file|<initializer_list>
end_include

begin_comment
comment|// NOLINT -- must be after gtest.h
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|testing
block|{
comment|// To implement a matcher Foo for type T, define:
comment|//   1. a class FooMatcherImpl that implements the
comment|//      MatcherInterface<T> interface, and
comment|//   2. a factory function that creates a Matcher<T> object from a
comment|//      FooMatcherImpl*.
comment|//
comment|// The two-level delegation design makes it possible to allow a user
comment|// to write "v" instead of "Eq(v)" where a Matcher is expected, which
comment|// is impossible if we pass matchers by pointers.  It also eases
comment|// ownership management as Matcher objects can now be copied like
comment|// plain values.
comment|// MatchResultListener is an abstract class.  Its<< operator can be
comment|// used by a matcher to explain why a value matches or doesn't match.
comment|//
comment|// TODO(wan@google.com): add method
comment|//   bool InterestedInWhy(bool result) const;
comment|// to indicate whether the listener is interested in why the match
comment|// result is 'result'.
name|class
name|MatchResultListener
block|{
name|public
label|:
comment|// Creates a listener object with the given underlying ostream.  The
comment|// listener does not own the ostream, and does not dereference it
comment|// in the constructor or destructor.
name|explicit
name|MatchResultListener
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
range|:
name|stream_
argument_list|(
argument|os
argument_list|)
block|{}
name|virtual
operator|~
name|MatchResultListener
argument_list|()
operator|=
literal|0
decl_stmt|;
comment|// Makes this class abstract.
comment|// Streams x to the underlying ostream; does nothing if the ostream
comment|// is NULL.
name|template
operator|<
name|typename
name|T
operator|>
name|MatchResultListener
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|T
operator|&
name|x
operator|)
block|{
if|if
condition|(
name|stream_
operator|!=
name|NULL
condition|)
operator|*
name|stream_
operator|<<
name|x
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|// Returns the underlying ostream.
operator|::
name|std
operator|::
name|ostream
operator|*
name|stream
argument_list|()
block|{
return|return
name|stream_
return|;
block|}
comment|// Returns true iff the listener is interested in an explanation of
comment|// the match result.  A matcher's MatchAndExplain() method can use
comment|// this information to avoid generating the explanation when no one
comment|// intends to hear it.
name|bool
name|IsInterested
argument_list|()
specifier|const
block|{
return|return
name|stream_
operator|!=
name|NULL
return|;
block|}
name|private
label|:
operator|::
name|std
operator|::
name|ostream
operator|*
specifier|const
name|stream_
expr_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|MatchResultListener
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|MatchResultListener
operator|::
operator|~
name|MatchResultListener
argument_list|()
block|{ }
comment|// An instance of a subclass of this knows how to describe itself as a
comment|// matcher.
name|class
name|MatcherDescriberInterface
block|{
name|public
operator|:
name|virtual
operator|~
name|MatcherDescriberInterface
argument_list|()
block|{}
comment|// Describes this matcher to an ostream.  The function should print
comment|// a verb phrase that describes the property a value matching this
comment|// matcher should have.  The subject of the verb phrase is the value
comment|// being matched.  For example, the DescribeTo() method of the Gt(7)
comment|// matcher prints "is greater than 7".
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|// Describes the negation of this matcher to an ostream.  For
comment|// example, if the description of this matcher is "is greater than
comment|// 7", the negated description could be "is not greater than 7".
comment|// You are not required to override this when implementing
comment|// MatcherInterface, but it is highly advised so that your matcher
comment|// can produce good error messages.
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"not ("
block|;
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|")"
block|;   }
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The implementation of a matcher.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|MatcherInterface
operator|:
name|public
name|MatcherDescriberInterface
block|{
name|public
operator|:
comment|// Returns true iff the matcher matches x; also explains the match
comment|// result to 'listener' if necessary (see the next paragraph), in
comment|// the form of a non-restrictive relative clause ("which ...",
comment|// "whose ...", etc) that describes x.  For example, the
comment|// MatchAndExplain() method of the Pointee(...) matcher should
comment|// generate an explanation like "which points to ...".
comment|//
comment|// Implementations of MatchAndExplain() should add an explanation of
comment|// the match result *if and only if* they can provide additional
comment|// information that's not already present (or not obvious) in the
comment|// print-out of x and the matcher's description.  Whether the match
comment|// succeeds is not a factor in deciding whether an explanation is
comment|// needed, as sometimes the caller needs to print a failure message
comment|// when the match succeeds (e.g. when the matcher is used inside
comment|// Not()).
comment|//
comment|// For example, a "has at least 10 elements" matcher should explain
comment|// what the actual element count is, regardless of the match result,
comment|// as it is useful information to the reader; on the other hand, an
comment|// "is empty" matcher probably only needs to explain what the actual
comment|// size is when the match fails, as it's redundant to say that the
comment|// size is 0 when the value is already known to be empty.
comment|//
comment|// You should override this method when defining a new matcher.
comment|//
comment|// It's the responsibility of the caller (Google Mock) to guarantee
comment|// that 'listener' is not NULL.  This helps to simplify a matcher's
comment|// implementation when it doesn't care about the performance, as it
comment|// can talk to 'listener' without checking its validity first.
comment|// However, in order to implement dummy listeners efficiently,
comment|// listener->stream() may be NULL.
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|T x
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|// Inherits these methods from MatcherDescriberInterface:
comment|//   virtual void DescribeTo(::std::ostream* os) const = 0;
comment|//   virtual void DescribeNegationTo(::std::ostream* os) const;
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// A match result listener that stores the explanation in a string.
end_comment

begin_decl_stmt
name|class
name|StringMatchResultListener
range|:
name|public
name|MatchResultListener
block|{
name|public
operator|:
name|StringMatchResultListener
argument_list|()
operator|:
name|MatchResultListener
argument_list|(
argument|&ss_
argument_list|)
block|{}
comment|// Returns the explanation accumulated so far.
name|internal
operator|::
name|string
name|str
argument_list|()
specifier|const
block|{
return|return
name|ss_
operator|.
name|str
argument_list|()
return|;
block|}
comment|// Clears the explanation accumulated so far.
name|void
name|Clear
argument_list|()
block|{
name|ss_
operator|.
name|str
argument_list|(
literal|""
argument_list|)
block|; }
name|private
operator|:
operator|::
name|std
operator|::
name|stringstream
name|ss_
block|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|StringMatchResultListener
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|internal
block|{
struct|struct
name|AnyEq
block|{
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|A
operator|&
name|a
operator|,
specifier|const
name|B
operator|&
name|b
operator|)
specifier|const
block|{
return|return
name|a
operator|==
name|b
return|;
block|}
block|}
struct|;
struct|struct
name|AnyNe
block|{
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|A
operator|&
name|a
operator|,
specifier|const
name|B
operator|&
name|b
operator|)
specifier|const
block|{
return|return
name|a
operator|!=
name|b
return|;
block|}
block|}
struct|;
struct|struct
name|AnyLt
block|{
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|A
operator|&
name|a
operator|,
specifier|const
name|B
operator|&
name|b
operator|)
specifier|const
block|{
return|return
name|a
operator|<
name|b
return|;
block|}
block|}
struct|;
struct|struct
name|AnyGt
block|{
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|A
operator|&
name|a
operator|,
specifier|const
name|B
operator|&
name|b
operator|)
specifier|const
block|{
return|return
name|a
operator|>
name|b
return|;
block|}
block|}
struct|;
struct|struct
name|AnyLe
block|{
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|A
operator|&
name|a
operator|,
specifier|const
name|B
operator|&
name|b
operator|)
specifier|const
block|{
return|return
name|a
operator|<=
name|b
return|;
block|}
block|}
struct|;
struct|struct
name|AnyGe
block|{
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|A
operator|&
name|a
operator|,
specifier|const
name|B
operator|&
name|b
operator|)
specifier|const
block|{
return|return
name|a
operator|>=
name|b
return|;
block|}
block|}
struct|;
comment|// A match result listener that ignores the explanation.
name|class
name|DummyMatchResultListener
range|:
name|public
name|MatchResultListener
block|{
name|public
operator|:
name|DummyMatchResultListener
argument_list|()
operator|:
name|MatchResultListener
argument_list|(
argument|NULL
argument_list|)
block|{}
name|private
operator|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|DummyMatchResultListener
argument_list|)
block|; }
decl_stmt|;
comment|// A match result listener that forwards the explanation to a given
comment|// ostream.  The difference between this and MatchResultListener is
comment|// that the former is concrete.
name|class
name|StreamMatchResultListener
range|:
name|public
name|MatchResultListener
block|{
name|public
operator|:
name|explicit
name|StreamMatchResultListener
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
operator|:
name|MatchResultListener
argument_list|(
argument|os
argument_list|)
block|{}
name|private
operator|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|StreamMatchResultListener
argument_list|)
block|; }
decl_stmt|;
comment|// An internal class for implementing Matcher<T>, which will derive
comment|// from it.  We put functionalities common to all Matcher<T>
comment|// specializations here to avoid code duplication.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|MatcherBase
block|{
name|public
operator|:
comment|// Returns true iff the matcher matches x; also explains the match
comment|// result to 'listener'.
name|bool
name|MatchAndExplain
argument_list|(
argument|T x
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
return|return
name|impl_
operator|->
name|MatchAndExplain
argument_list|(
name|x
argument_list|,
name|listener
argument_list|)
return|;
block|}
comment|// Returns true iff this matcher matches x.
name|bool
name|Matches
argument_list|(
argument|T x
argument_list|)
specifier|const
block|{
name|DummyMatchResultListener
name|dummy
block|;
return|return
name|MatchAndExplain
argument_list|(
name|x
argument_list|,
operator|&
name|dummy
argument_list|)
return|;
block|}
comment|// Describes this matcher to an ostream.
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
name|impl_
operator|->
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|; }
comment|// Describes the negation of this matcher to an ostream.
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
name|impl_
operator|->
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;   }
comment|// Explains why x matches, or doesn't match, the matcher.
name|void
name|ExplainMatchResultTo
argument_list|(
argument|T x
argument_list|,
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
name|StreamMatchResultListener
name|listener
argument_list|(
name|os
argument_list|)
block|;
name|MatchAndExplain
argument_list|(
name|x
argument_list|,
operator|&
name|listener
argument_list|)
block|;   }
comment|// Returns the describer for this matcher object; retains ownership
comment|// of the describer, which is only guaranteed to be alive when
comment|// this matcher object is alive.
specifier|const
name|MatcherDescriberInterface
operator|*
name|GetDescriber
argument_list|()
specifier|const
block|{
return|return
name|impl_
operator|.
name|get
argument_list|()
return|;
block|}
name|protected
operator|:
name|MatcherBase
argument_list|()
block|{}
comment|// Constructs a matcher from its implementation.
name|explicit
name|MatcherBase
argument_list|(
specifier|const
name|MatcherInterface
operator|<
name|T
operator|>
operator|*
name|impl
argument_list|)
operator|:
name|impl_
argument_list|(
argument|impl
argument_list|)
block|{}
name|virtual
operator|~
name|MatcherBase
argument_list|()
block|{}
name|private
operator|:
comment|// shared_ptr (util/gtl/shared_ptr.h) and linked_ptr have similar
comment|// interfaces.  The former dynamically allocates a chunk of memory
comment|// to hold the reference count, while the latter tracks all
comment|// references using a circular linked list without allocating
comment|// memory.  It has been observed that linked_ptr performs better in
comment|// typical scenarios.  However, shared_ptr can out-perform
comment|// linked_ptr when there are many more uses of the copy constructor
comment|// than the default constructor.
comment|//
comment|// If performance becomes a problem, we should see if using
comment|// shared_ptr helps.
operator|::
name|testing
operator|::
name|internal
operator|::
name|linked_ptr
operator|<
specifier|const
name|MatcherInterface
operator|<
name|T
operator|>
expr|>
name|impl_
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace internal
end_comment

begin_comment
comment|// A Matcher<T> is a copyable and IMMUTABLE (except by assignment)
end_comment

begin_comment
comment|// object that can check whether a value of type T matches.  The
end_comment

begin_comment
comment|// implementation of Matcher<T> is just a linked_ptr to const
end_comment

begin_comment
comment|// MatcherInterface<T>, so copying is fairly cheap.  Don't inherit
end_comment

begin_comment
comment|// from Matcher!
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Matcher
operator|:
name|public
name|internal
operator|::
name|MatcherBase
operator|<
name|T
operator|>
block|{
name|public
operator|:
comment|// Constructs a null matcher.  Needed for storing Matcher objects in STL
comment|// containers.  A default-constructed matcher is not yet initialized.  You
comment|// cannot use it until a valid value has been assigned to it.
name|explicit
name|Matcher
argument_list|()
block|{}
comment|// NOLINT
comment|// Constructs a matcher from its implementation.
name|explicit
name|Matcher
argument_list|(
specifier|const
name|MatcherInterface
operator|<
name|T
operator|>
operator|*
name|impl
argument_list|)
operator|:
name|internal
operator|::
name|MatcherBase
operator|<
name|T
operator|>
operator|(
name|impl
operator|)
block|{}
comment|// Implicit constructor here allows people to write
comment|// EXPECT_CALL(foo, Bar(5)) instead of EXPECT_CALL(foo, Bar(Eq(5))) sometimes
name|Matcher
argument_list|(
argument|T value
argument_list|)
block|;
comment|// NOLINT
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The following two specializations allow the user to write str
end_comment

begin_comment
comment|// instead of Eq(str) and "foo" instead of Eq("foo") when a string
end_comment

begin_comment
comment|// matcher is expected.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|GTEST_API_
name|Matcher
operator|<
specifier|const
name|internal
operator|::
name|string
operator|&
operator|>
operator|:
name|public
name|internal
operator|::
name|MatcherBase
operator|<
specifier|const
name|internal
operator|::
name|string
operator|&
operator|>
block|{
name|public
operator|:
name|Matcher
argument_list|()
block|{}
name|explicit
name|Matcher
argument_list|(
specifier|const
name|MatcherInterface
operator|<
specifier|const
name|internal
operator|::
name|string
operator|&
operator|>
operator|*
name|impl
argument_list|)
operator|:
name|internal
operator|::
name|MatcherBase
operator|<
specifier|const
name|internal
operator|::
name|string
operator|&
operator|>
operator|(
name|impl
operator|)
block|{}
comment|// Allows the user to write str instead of Eq(str) sometimes, where
comment|// str is a string object.
name|Matcher
argument_list|(
specifier|const
name|internal
operator|::
name|string
operator|&
name|s
argument_list|)
block|;
comment|// NOLINT
comment|// Allows the user to write "foo" instead of Eq("foo") sometimes.
name|Matcher
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|)
block|;
comment|// NOLINT
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|GTEST_API_
name|Matcher
operator|<
name|internal
operator|::
name|string
operator|>
operator|:
name|public
name|internal
operator|::
name|MatcherBase
operator|<
name|internal
operator|::
name|string
operator|>
block|{
name|public
operator|:
name|Matcher
argument_list|()
block|{}
name|explicit
name|Matcher
argument_list|(
specifier|const
name|MatcherInterface
operator|<
name|internal
operator|::
name|string
operator|>
operator|*
name|impl
argument_list|)
operator|:
name|internal
operator|::
name|MatcherBase
operator|<
name|internal
operator|::
name|string
operator|>
operator|(
name|impl
operator|)
block|{}
comment|// Allows the user to write str instead of Eq(str) sometimes, where
comment|// str is a string object.
name|Matcher
argument_list|(
specifier|const
name|internal
operator|::
name|string
operator|&
name|s
argument_list|)
block|;
comment|// NOLINT
comment|// Allows the user to write "foo" instead of Eq("foo") sometimes.
name|Matcher
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|)
block|;
comment|// NOLINT
block|}
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|GTEST_HAS_STRING_PIECE_
end_if

begin_comment
comment|// The following two specializations allow the user to write str
end_comment

begin_comment
comment|// instead of Eq(str) and "foo" instead of Eq("foo") when a StringPiece
end_comment

begin_comment
comment|// matcher is expected.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|GTEST_API_
name|Matcher
operator|<
specifier|const
name|StringPiece
operator|&
operator|>
operator|:
name|public
name|internal
operator|::
name|MatcherBase
operator|<
specifier|const
name|StringPiece
operator|&
operator|>
block|{
name|public
operator|:
name|Matcher
argument_list|()
block|{}
name|explicit
name|Matcher
argument_list|(
specifier|const
name|MatcherInterface
operator|<
specifier|const
name|StringPiece
operator|&
operator|>
operator|*
name|impl
argument_list|)
operator|:
name|internal
operator|::
name|MatcherBase
operator|<
specifier|const
name|StringPiece
operator|&
operator|>
operator|(
name|impl
operator|)
block|{}
comment|// Allows the user to write str instead of Eq(str) sometimes, where
comment|// str is a string object.
name|Matcher
argument_list|(
specifier|const
name|internal
operator|::
name|string
operator|&
name|s
argument_list|)
block|;
comment|// NOLINT
comment|// Allows the user to write "foo" instead of Eq("foo") sometimes.
name|Matcher
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|)
block|;
comment|// NOLINT
comment|// Allows the user to pass StringPieces directly.
name|Matcher
argument_list|(
argument|StringPiece s
argument_list|)
block|;
comment|// NOLINT
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|GTEST_API_
name|Matcher
operator|<
name|StringPiece
operator|>
operator|:
name|public
name|internal
operator|::
name|MatcherBase
operator|<
name|StringPiece
operator|>
block|{
name|public
operator|:
name|Matcher
argument_list|()
block|{}
name|explicit
name|Matcher
argument_list|(
specifier|const
name|MatcherInterface
operator|<
name|StringPiece
operator|>
operator|*
name|impl
argument_list|)
operator|:
name|internal
operator|::
name|MatcherBase
operator|<
name|StringPiece
operator|>
operator|(
name|impl
operator|)
block|{}
comment|// Allows the user to write str instead of Eq(str) sometimes, where
comment|// str is a string object.
name|Matcher
argument_list|(
specifier|const
name|internal
operator|::
name|string
operator|&
name|s
argument_list|)
block|;
comment|// NOLINT
comment|// Allows the user to write "foo" instead of Eq("foo") sometimes.
name|Matcher
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|)
block|;
comment|// NOLINT
comment|// Allows the user to pass StringPieces directly.
name|Matcher
argument_list|(
argument|StringPiece s
argument_list|)
block|;
comment|// NOLINT
block|}
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_STRING_PIECE_
end_comment

begin_comment
comment|// The PolymorphicMatcher class template makes it easy to implement a
end_comment

begin_comment
comment|// polymorphic matcher (i.e. a matcher that can match values of more
end_comment

begin_comment
comment|// than one type, e.g. Eq(n) and NotNull()).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To define a polymorphic matcher, a user should provide an Impl
end_comment

begin_comment
comment|// class that has a DescribeTo() method and a DescribeNegationTo()
end_comment

begin_comment
comment|// method, and define a member function (or member function template)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   bool MatchAndExplain(const Value& value,
end_comment

begin_comment
comment|//                        MatchResultListener* listener) const;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// See the definition of NotNull() for a complete example.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Impl
operator|>
name|class
name|PolymorphicMatcher
block|{
name|public
operator|:
name|explicit
name|PolymorphicMatcher
argument_list|(
specifier|const
name|Impl
operator|&
name|an_impl
argument_list|)
operator|:
name|impl_
argument_list|(
argument|an_impl
argument_list|)
block|{}
comment|// Returns a mutable reference to the underlying matcher
comment|// implementation object.
name|Impl
operator|&
name|mutable_impl
argument_list|()
block|{
return|return
name|impl_
return|;
block|}
comment|// Returns an immutable reference to the underlying matcher
comment|// implementation object.
specifier|const
name|Impl
operator|&
name|impl
argument_list|()
specifier|const
block|{
return|return
name|impl_
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|operator
name|Matcher
operator|<
name|T
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|new
name|MonomorphicImpl
operator|<
name|T
operator|>
operator|(
name|impl_
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|MonomorphicImpl
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|explicit
name|MonomorphicImpl
argument_list|(
specifier|const
name|Impl
operator|&
name|impl
argument_list|)
operator|:
name|impl_
argument_list|(
argument|impl
argument_list|)
block|{}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
name|impl_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
name|impl_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|T x
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
return|return
name|impl_
operator|.
name|MatchAndExplain
argument_list|(
name|x
argument_list|,
name|listener
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|Impl
name|impl_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|MonomorphicImpl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
name|Impl
name|impl_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|PolymorphicMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Creates a matcher from its implementation.  This is easier to use
end_comment

begin_comment
comment|// than the Matcher<T> constructor as it doesn't require you to
end_comment

begin_comment
comment|// explicitly write the template argument, e.g.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   MakeMatcher(foo);
end_comment

begin_comment
comment|// vs
end_comment

begin_comment
comment|//   Matcher<const string&>(foo);
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|Matcher
operator|<
name|T
operator|>
name|MakeMatcher
argument_list|(
argument|const MatcherInterface<T>* impl
argument_list|)
block|{
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|impl
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic matcher from its implementation.  This is
end_comment

begin_comment
comment|// easier to use than the PolymorphicMatcher<Impl> constructor as it
end_comment

begin_comment
comment|// doesn't require you to explicitly write the template argument, e.g.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   MakePolymorphicMatcher(foo);
end_comment

begin_comment
comment|// vs
end_comment

begin_comment
comment|//   PolymorphicMatcher<TypeOfFoo>(foo);
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Impl
operator|>
specifier|inline
name|PolymorphicMatcher
operator|<
name|Impl
operator|>
name|MakePolymorphicMatcher
argument_list|(
argument|const Impl& impl
argument_list|)
block|{
return|return
name|PolymorphicMatcher
operator|<
name|Impl
operator|>
operator|(
name|impl
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Anything inside the 'internal' namespace IS INTERNAL IMPLEMENTATION
end_comment

begin_comment
comment|// and MUST NOT BE USED IN USER CODE!!!
end_comment

begin_decl_stmt
name|namespace
name|internal
block|{
comment|// The MatcherCastImpl class template is a helper for implementing
comment|// MatcherCast().  We need this helper in order to partially
comment|// specialize the implementation of MatcherCast() (C++ allows
comment|// class/struct templates to be partially specialized, but not
comment|// function templates.).
comment|// This general version is used when MatcherCast()'s argument is a
comment|// polymorphic matcher (i.e. something that can be converted to a
comment|// Matcher but is not one yet; for example, Eq(value)) or a value (for
comment|// example, "hello").
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|M
operator|>
name|class
name|MatcherCastImpl
block|{
name|public
operator|:
specifier|static
name|Matcher
operator|<
name|T
operator|>
name|Cast
argument_list|(
argument|const M& polymorphic_matcher_or_value
argument_list|)
block|{
comment|// M can be a polymorhic matcher, in which case we want to use
comment|// its conversion operator to create Matcher<T>.  Or it can be a value
comment|// that should be passed to the Matcher<T>'s constructor.
comment|//
comment|// We can't call Matcher<T>(polymorphic_matcher_or_value) when M is a
comment|// polymorphic matcher because it'll be ambiguous if T has an implicit
comment|// constructor from M (this usually happens when T has an implicit
comment|// constructor from any type).
comment|//
comment|// It won't work to unconditionally implict_cast
comment|// polymorphic_matcher_or_value to Matcher<T> because it won't trigger
comment|// a user-defined conversion from M to T if one exists (assuming M is
comment|// a value).
return|return
name|CastImpl
argument_list|(
name|polymorphic_matcher_or_value
argument_list|,
name|BooleanConstant
operator|<
name|internal
operator|::
name|ImplicitlyConvertible
operator|<
name|M
argument_list|,
name|Matcher
operator|<
name|T
operator|>
expr|>
operator|::
name|value
operator|>
operator|(
operator|)
argument_list|)
return|;
block|}
name|private
operator|:
specifier|static
name|Matcher
operator|<
name|T
operator|>
name|CastImpl
argument_list|(
argument|const M& value
argument_list|,
argument|BooleanConstant<false>
argument_list|)
block|{
comment|// M can't be implicitly converted to Matcher<T>, so M isn't a polymorphic
comment|// matcher.  It must be a value then.  Use direct initialization to create
comment|// a matcher.
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|ImplicitCast_
operator|<
name|T
operator|>
operator|(
name|value
operator|)
operator|)
return|;
block|}
specifier|static
name|Matcher
operator|<
name|T
operator|>
name|CastImpl
argument_list|(
argument|const M& polymorphic_matcher_or_value
argument_list|,
argument|BooleanConstant<true>
argument_list|)
block|{
comment|// M is implicitly convertible to Matcher<T>, which means that either
comment|// M is a polymorhpic matcher or Matcher<T> has an implicit constructor
comment|// from M.  In both cases using the implicit conversion will produce a
comment|// matcher.
comment|//
comment|// Even if T has an implicit constructor from M, it won't be called because
comment|// creating Matcher<T> would require a chain of two user-defined conversions
comment|// (first to create T from M and then to create Matcher<T> from T).
return|return
name|polymorphic_matcher_or_value
return|;
block|}
expr|}
block|;
comment|// This more specialized version is used when MatcherCast()'s argument
comment|// is already a Matcher.  This only compiles when type T can be
comment|// statically converted to type U.
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|U
operator|>
name|class
name|MatcherCastImpl
operator|<
name|T
block|,
name|Matcher
operator|<
name|U
operator|>
expr|>
block|{
name|public
operator|:
specifier|static
name|Matcher
operator|<
name|T
operator|>
name|Cast
argument_list|(
argument|const Matcher<U>& source_matcher
argument_list|)
block|{
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|new
name|Impl
argument_list|(
name|source_matcher
argument_list|)
operator|)
return|;
block|}
name|private
operator|:
name|class
name|Impl
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|explicit
name|Impl
argument_list|(
specifier|const
name|Matcher
operator|<
name|U
operator|>
operator|&
name|source_matcher
argument_list|)
operator|:
name|source_matcher_
argument_list|(
argument|source_matcher
argument_list|)
block|{}
comment|// We delegate the matching logic to the source matcher.
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|T x
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
return|return
name|source_matcher_
operator|.
name|MatchAndExplain
argument_list|(
name|static_cast
operator|<
name|U
operator|>
operator|(
name|x
operator|)
argument_list|,
name|listener
argument_list|)
return|;
block|}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
name|source_matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
name|source_matcher_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;     }
name|private
operator|:
specifier|const
name|Matcher
operator|<
name|U
operator|>
name|source_matcher_
block|;
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|Impl
argument_list|)
block|;   }
block|; }
block|;
comment|// This even more specialized version is used for efficiently casting
comment|// a matcher to its own type.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|MatcherCastImpl
operator|<
name|T
block|,
name|Matcher
operator|<
name|T
operator|>
expr|>
block|{
name|public
operator|:
specifier|static
name|Matcher
operator|<
name|T
operator|>
name|Cast
argument_list|(
argument|const Matcher<T>& matcher
argument_list|)
block|{
return|return
name|matcher
return|;
block|}
expr|}
block|;  }
comment|// namespace internal
comment|// In order to be safe and clear, casting between different matcher
comment|// types is done explicitly via MatcherCast<T>(m), which takes a
comment|// matcher m and returns a Matcher<T>.  It compiles only when T can be
comment|// statically converted to the argument type of m.
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|M
operator|>
specifier|inline
name|Matcher
operator|<
name|T
operator|>
name|MatcherCast
argument_list|(
argument|const M& matcher
argument_list|)
block|{
return|return
name|internal
operator|::
name|MatcherCastImpl
operator|<
name|T
operator|,
name|M
operator|>
operator|::
name|Cast
argument_list|(
name|matcher
argument_list|)
return|;
block|}
comment|// Implements SafeMatcherCast().
comment|//
comment|// We use an intermediate class to do the actual safe casting as Nokia's
comment|// Symbian compiler cannot decide between
comment|// template<T, M> ... (M) and
comment|// template<T, U> ... (const Matcher<U>&)
comment|// for function templates but can for member function templates.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SafeMatcherCastImpl
block|{
name|public
operator|:
comment|// This overload handles polymorphic matchers and values only since
comment|// monomorphic matchers are handled by the next one.
name|template
operator|<
name|typename
name|M
operator|>
specifier|static
specifier|inline
name|Matcher
operator|<
name|T
operator|>
name|Cast
argument_list|(
argument|const M& polymorphic_matcher_or_value
argument_list|)
block|{
return|return
name|internal
operator|::
name|MatcherCastImpl
operator|<
name|T
operator|,
name|M
operator|>
operator|::
name|Cast
argument_list|(
name|polymorphic_matcher_or_value
argument_list|)
return|;
block|}
comment|// This overload handles monomorphic matchers.
comment|//
comment|// In general, if type T can be implicitly converted to type U, we can
comment|// safely convert a Matcher<U> to a Matcher<T> (i.e. Matcher is
comment|// contravariant): just keep a copy of the original Matcher<U>, convert the
comment|// argument from type T to U, and then pass it to the underlying Matcher<U>.
comment|// The only exception is when U is a reference and T is not, as the
comment|// underlying Matcher<U> may be interested in the argument's address, which
comment|// is not preserved in the conversion from T to U.
name|template
operator|<
name|typename
name|U
operator|>
specifier|static
specifier|inline
name|Matcher
operator|<
name|T
operator|>
name|Cast
argument_list|(
argument|const Matcher<U>& matcher
argument_list|)
block|{
comment|// Enforce that T can be implicitly converted to U.
name|GTEST_COMPILE_ASSERT_
argument_list|(
operator|(
name|internal
operator|::
name|ImplicitlyConvertible
operator|<
name|T
operator|,
name|U
operator|>
operator|::
name|value
operator|)
argument_list|,
name|T_must_be_implicitly_convertible_to_U
argument_list|)
block|;
comment|// Enforce that we are not converting a non-reference type T to a reference
comment|// type U.
name|GTEST_COMPILE_ASSERT_
argument_list|(
name|internal
operator|::
name|is_reference
operator|<
name|T
operator|>
operator|::
name|value
operator|||
operator|!
name|internal
operator|::
name|is_reference
operator|<
name|U
operator|>
operator|::
name|value
argument_list|,
name|cannot_convert_non_referentce_arg_to_reference
argument_list|)
block|;
comment|// In case both T and U are arithmetic types, enforce that the
comment|// conversion is not lossy.
typedef|typedef
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
argument|T
argument_list|)
name|RawT
expr_stmt|;
typedef|typedef
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
argument|U
argument_list|)
name|RawU
expr_stmt|;
specifier|const
name|bool
name|kTIsOther
operator|=
name|GMOCK_KIND_OF_
argument_list|(
name|RawT
argument_list|)
operator|==
name|internal
operator|::
name|kOther
block|;
specifier|const
name|bool
name|kUIsOther
operator|=
name|GMOCK_KIND_OF_
argument_list|(
name|RawU
argument_list|)
operator|==
name|internal
operator|::
name|kOther
block|;
name|GTEST_COMPILE_ASSERT_
argument_list|(
name|kTIsOther
operator|||
name|kUIsOther
operator|||
operator|(
name|internal
operator|::
name|LosslessArithmeticConvertible
operator|<
name|RawT
operator|,
name|RawU
operator|>
operator|::
name|value
operator|)
argument_list|,
name|conversion_of_arithmetic_types_must_be_lossless
argument_list|)
block|;
return|return
name|MatcherCast
operator|<
name|T
operator|>
operator|(
name|matcher
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|M
operator|>
specifier|inline
name|Matcher
operator|<
name|T
operator|>
name|SafeMatcherCast
argument_list|(
argument|const M& polymorphic_matcher
argument_list|)
block|{
return|return
name|SafeMatcherCastImpl
operator|<
name|T
operator|>
operator|::
name|Cast
argument_list|(
name|polymorphic_matcher
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// A<T>() returns a matcher that matches any value of type T.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Matcher
operator|<
name|T
operator|>
name|A
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Anything inside the 'internal' namespace IS INTERNAL IMPLEMENTATION
end_comment

begin_comment
comment|// and MUST NOT BE USED IN USER CODE!!!
end_comment

begin_decl_stmt
name|namespace
name|internal
block|{
comment|// If the explanation is not empty, prints it to the ostream.
specifier|inline
name|void
name|PrintIfNotEmpty
argument_list|(
specifier|const
name|internal
operator|::
name|string
operator|&
name|explanation
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
block|{
if|if
condition|(
name|explanation
operator|!=
literal|""
operator|&&
name|os
operator|!=
name|NULL
condition|)
block|{
operator|*
name|os
operator|<<
literal|", "
operator|<<
name|explanation
expr_stmt|;
block|}
block|}
comment|// Returns true if the given type name is easy to read by a human.
comment|// This is used to decide whether printing the type of a value might
comment|// be helpful.
specifier|inline
name|bool
name|IsReadableTypeName
parameter_list|(
specifier|const
name|string
modifier|&
name|type_name
parameter_list|)
block|{
comment|// We consider a type name readable if it's short or doesn't contain
comment|// a template or function type.
return|return
operator|(
name|type_name
operator|.
name|length
argument_list|()
operator|<=
literal|20
operator|||
name|type_name
operator|.
name|find_first_of
argument_list|(
literal|"<("
argument_list|)
operator|==
name|string
operator|::
name|npos
operator|)
return|;
block|}
comment|// Matches the value against the given matcher, prints the value and explains
comment|// the match result to the listener. Returns the match result.
comment|// 'listener' must not be NULL.
comment|// Value cannot be passed by const reference, because some matchers take a
comment|// non-const argument.
name|template
operator|<
name|typename
name|Value
operator|,
name|typename
name|T
operator|>
name|bool
name|MatchPrintAndExplain
argument_list|(
argument|Value& value
argument_list|,
argument|const Matcher<T>& matcher
argument_list|,
argument|MatchResultListener* listener
argument_list|)
block|{
if|if
condition|(
operator|!
name|listener
operator|->
name|IsInterested
argument_list|()
condition|)
block|{
comment|// If the listener is not interested, we do not need to construct the
comment|// inner explanation.
return|return
name|matcher
operator|.
name|Matches
argument_list|(
name|value
argument_list|)
return|;
block|}
name|StringMatchResultListener
name|inner_listener
decl_stmt|;
specifier|const
name|bool
name|match
operator|=
name|matcher
operator|.
name|MatchAndExplain
argument_list|(
name|value
argument_list|,
operator|&
name|inner_listener
argument_list|)
expr_stmt|;
name|UniversalPrint
argument_list|(
name|value
argument_list|,
name|listener
operator|->
name|stream
argument_list|()
argument_list|)
expr_stmt|;
if|#
directive|if
name|GTEST_HAS_RTTI
specifier|const
name|string
modifier|&
name|type_name
init|=
name|GetTypeName
operator|<
name|Value
operator|>
operator|(
operator|)
decl_stmt|;
if|if
condition|(
name|IsReadableTypeName
argument_list|(
name|type_name
argument_list|)
condition|)
operator|*
name|listener
operator|->
name|stream
argument_list|()
operator|<<
literal|" (of type "
operator|<<
name|type_name
operator|<<
literal|")"
expr_stmt|;
endif|#
directive|endif
name|PrintIfNotEmpty
argument_list|(
name|inner_listener
operator|.
name|str
argument_list|()
argument_list|,
name|listener
operator|->
name|stream
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|match
return|;
block|}
end_decl_stmt

begin_comment
comment|// An internal helper class for doing compile-time loop on a tuple's
end_comment

begin_comment
comment|// fields.
end_comment

begin_expr_stmt
name|template
operator|<
name|size_t
name|N
operator|>
name|class
name|TuplePrefix
block|{
name|public
operator|:
comment|// TuplePrefix<N>::Matches(matcher_tuple, value_tuple) returns true
comment|// iff the first N fields of matcher_tuple matches the first N
comment|// fields of value_tuple, respectively.
name|template
operator|<
name|typename
name|MatcherTuple
block|,
name|typename
name|ValueTuple
operator|>
specifier|static
name|bool
name|Matches
argument_list|(
argument|const MatcherTuple& matcher_tuple
argument_list|,
argument|const ValueTuple& value_tuple
argument_list|)
block|{
return|return
name|TuplePrefix
operator|<
name|N
operator|-
literal|1
operator|>
operator|::
name|Matches
argument_list|(
name|matcher_tuple
argument_list|,
name|value_tuple
argument_list|)
operator|&&
name|get
operator|<
name|N
operator|-
literal|1
operator|>
operator|(
name|matcher_tuple
operator|)
operator|.
name|Matches
argument_list|(
name|get
operator|<
name|N
operator|-
literal|1
operator|>
operator|(
name|value_tuple
operator|)
argument_list|)
return|;
block|}
comment|// TuplePrefix<N>::ExplainMatchFailuresTo(matchers, values, os)
comment|// describes failures in matching the first N fields of matchers
comment|// against the first N fields of values.  If there is no failure,
comment|// nothing will be streamed to os.
name|template
operator|<
name|typename
name|MatcherTuple
operator|,
name|typename
name|ValueTuple
operator|>
specifier|static
name|void
name|ExplainMatchFailuresTo
argument_list|(
argument|const MatcherTuple& matchers
argument_list|,
argument|const ValueTuple& values
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
comment|// First, describes failures in the first N - 1 fields.
name|TuplePrefix
operator|<
name|N
operator|-
literal|1
operator|>
operator|::
name|ExplainMatchFailuresTo
argument_list|(
name|matchers
argument_list|,
name|values
argument_list|,
name|os
argument_list|)
block|;
comment|// Then describes the failure (if any) in the (N - 1)-th (0-based)
comment|// field.
name|typename
name|tuple_element
operator|<
name|N
operator|-
literal|1
block|,
name|MatcherTuple
operator|>
operator|::
name|type
name|matcher
operator|=
name|get
operator|<
name|N
operator|-
literal|1
operator|>
operator|(
name|matchers
operator|)
block|;
typedef|typedef
name|typename
name|tuple_element
operator|<
name|N
operator|-
literal|1
operator|,
name|ValueTuple
operator|>
operator|::
name|type
name|Value
expr_stmt|;
name|Value
name|value
operator|=
name|get
operator|<
name|N
operator|-
literal|1
operator|>
operator|(
name|values
operator|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|StringMatchResultListener
name|listener
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
operator|!
name|matcher
operator|.
name|MatchAndExplain
argument_list|(
name|value
argument_list|,
operator|&
name|listener
argument_list|)
condition|)
block|{
comment|// TODO(wan): include in the message the name of the parameter
comment|// as used in MOCK_METHOD*() when possible.
operator|*
name|os
operator|<<
literal|"  Expected arg #"
operator|<<
name|N
operator|-
literal|1
operator|<<
literal|": "
expr_stmt|;
name|get
operator|<
name|N
operator|-
literal|1
operator|>
operator|(
name|matchers
operator|)
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
expr_stmt|;
operator|*
name|os
operator|<<
literal|"\n           Actual: "
expr_stmt|;
comment|// We remove the reference in type Value to prevent the
comment|// universal printer from printing the address of value, which
comment|// isn't interesting to the user most of the time.  The
comment|// matcher's MatchAndExplain() method handles the case when
comment|// the address is interesting.
name|internal
operator|::
name|UniversalPrint
argument_list|(
name|value
argument_list|,
name|os
argument_list|)
expr_stmt|;
name|PrintIfNotEmpty
argument_list|(
name|listener
operator|.
name|str
argument_list|()
argument_list|,
name|os
argument_list|)
expr_stmt|;
operator|*
name|os
operator|<<
literal|"\n"
expr_stmt|;
block|}
end_if

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_comment
comment|// The base case.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|TuplePrefix
operator|<
literal|0
operator|>
block|{
name|public
operator|:
name|template
operator|<
name|typename
name|MatcherTuple
block|,
name|typename
name|ValueTuple
operator|>
specifier|static
name|bool
name|Matches
argument_list|(
argument|const MatcherTuple&
comment|/* matcher_tuple */
argument_list|,
argument|const ValueTuple&
comment|/* value_tuple */
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|template
operator|<
name|typename
name|MatcherTuple
operator|,
name|typename
name|ValueTuple
operator|>
specifier|static
name|void
name|ExplainMatchFailuresTo
argument_list|(
argument|const MatcherTuple&
comment|/* matchers */
argument_list|,
argument|const ValueTuple&
comment|/* values */
argument_list|,
argument|::std::ostream*
comment|/* os */
argument_list|)
block|{}
end_expr_stmt

begin_comment
unit|};
comment|// TupleMatches(matcher_tuple, value_tuple) returns true iff all
end_comment

begin_comment
comment|// matchers in matcher_tuple match the corresponding fields in
end_comment

begin_comment
comment|// value_tuple.  It is a compiler error if matcher_tuple and
end_comment

begin_comment
comment|// value_tuple have different number of fields or incompatible field
end_comment

begin_comment
comment|// types.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|MatcherTuple
operator|,
name|typename
name|ValueTuple
operator|>
name|bool
name|TupleMatches
argument_list|(
argument|const MatcherTuple& matcher_tuple
argument_list|,
argument|const ValueTuple& value_tuple
argument_list|)
block|{
comment|// Makes sure that matcher_tuple and value_tuple have the same
comment|// number of fields.
name|GTEST_COMPILE_ASSERT_
argument_list|(
name|tuple_size
operator|<
name|MatcherTuple
operator|>
operator|::
name|value
operator|==
name|tuple_size
operator|<
name|ValueTuple
operator|>
operator|::
name|value
argument_list|,
name|matcher_and_value_have_different_numbers_of_fields
argument_list|)
block|;
return|return
name|TuplePrefix
operator|<
name|tuple_size
operator|<
name|ValueTuple
operator|>
operator|::
name|value
operator|>
operator|::
name|Matches
argument_list|(
name|matcher_tuple
argument_list|,
name|value_tuple
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Describes failures in matching matchers against values.  If there
end_comment

begin_comment
comment|// is no failure, nothing will be streamed to os.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|MatcherTuple
operator|,
name|typename
name|ValueTuple
operator|>
name|void
name|ExplainMatchFailureTupleTo
argument_list|(
argument|const MatcherTuple& matchers
argument_list|,
argument|const ValueTuple& values
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|TuplePrefix
operator|<
name|tuple_size
operator|<
name|MatcherTuple
operator|>
operator|::
name|value
operator|>
operator|::
name|ExplainMatchFailuresTo
argument_list|(
name|matchers
argument_list|,
name|values
argument_list|,
name|os
argument_list|)
block|; }
comment|// TransformTupleValues and its helper.
comment|//
comment|// TransformTupleValuesHelper hides the internal machinery that
comment|// TransformTupleValues uses to implement a tuple traversal.
name|template
operator|<
name|typename
name|Tuple
operator|,
name|typename
name|Func
operator|,
name|typename
name|OutIter
operator|>
name|class
name|TransformTupleValuesHelper
block|{
name|private
operator|:
typedef|typedef
operator|::
name|testing
operator|::
name|tuple_size
operator|<
name|Tuple
operator|>
name|TupleSize
expr_stmt|;
name|public
operator|:
comment|// For each member of tuple 't', taken in order, evaluates '*out++ = f(t)'.
comment|// Returns the final value of 'out' in case the caller needs it.
specifier|static
name|OutIter
name|Run
argument_list|(
argument|Func f
argument_list|,
argument|const Tuple& t
argument_list|,
argument|OutIter out
argument_list|)
block|{
return|return
name|IterateOverTuple
operator|<
name|Tuple
operator|,
name|TupleSize
operator|::
name|value
operator|>
operator|(
operator|)
operator|(
name|f
operator|,
name|t
operator|,
name|out
operator|)
return|;
block|}
name|private
operator|:
name|template
operator|<
name|typename
name|Tup
operator|,
name|size_t
name|kRemainingSize
operator|>
block|struct
name|IterateOverTuple
block|{
name|OutIter
name|operator
argument_list|()
operator|(
name|Func
name|f
operator|,
specifier|const
name|Tup
operator|&
name|t
operator|,
name|OutIter
name|out
operator|)
specifier|const
block|{
operator|*
name|out
operator|++
operator|=
name|f
argument_list|(
operator|::
name|testing
operator|::
name|get
operator|<
name|TupleSize
operator|::
name|value
operator|-
name|kRemainingSize
operator|>
operator|(
name|t
operator|)
argument_list|)
block|;
return|return
name|IterateOverTuple
operator|<
name|Tup
operator|,
name|kRemainingSize
operator|-
literal|1
operator|>
operator|(
operator|)
operator|(
name|f
operator|,
name|t
operator|,
name|out
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|Tup
operator|>
expr|struct
name|IterateOverTuple
operator|<
name|Tup
operator|,
literal|0
operator|>
block|{
name|OutIter
name|operator
argument_list|()
operator|(
name|Func
comment|/* f */
operator|,
specifier|const
name|Tup
operator|&
comment|/* t */
operator|,
name|OutIter
name|out
operator|)
specifier|const
block|{
return|return
name|out
return|;
block|}
end_expr_stmt

begin_comment
unit|}; };
comment|// Successively invokes 'f(element)' on each element of the tuple 't',
end_comment

begin_comment
comment|// appending each result to the 'out' iterator. Returns the final value
end_comment

begin_comment
comment|// of 'out'.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Tuple
operator|,
name|typename
name|Func
operator|,
name|typename
name|OutIter
operator|>
name|OutIter
name|TransformTupleValues
argument_list|(
argument|Func f
argument_list|,
argument|const Tuple& t
argument_list|,
argument|OutIter out
argument_list|)
block|{
return|return
name|TransformTupleValuesHelper
operator|<
name|Tuple
operator|,
name|Func
operator|,
name|OutIter
operator|>
operator|::
name|Run
argument_list|(
name|f
argument_list|,
name|t
argument_list|,
name|out
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Implements A<T>().
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|AnyMatcherImpl
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|T
comment|/* x */
argument_list|,
argument|MatchResultListener*
comment|/* listener */
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"is anything"
block|; }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
comment|// This is mostly for completeness' safe, as it's not very useful
comment|// to write Not(A<bool>()).  However we cannot completely rule out
comment|// such a possibility, and it doesn't hurt to be prepared.
operator|*
name|os
operator|<<
literal|"never matches"
block|;   }
end_expr_stmt

begin_comment
unit|};
comment|// Implements _, a matcher that matches any value of any
end_comment

begin_comment
comment|// type.  This is a polymorphic matcher, so we need a template type
end_comment

begin_comment
comment|// conversion operator to make it appearing as a Matcher<T> for any
end_comment

begin_comment
comment|// type T.
end_comment

begin_decl_stmt
name|class
name|AnythingMatcher
block|{
name|public
label|:
name|template
operator|<
name|typename
name|T
operator|>
name|operator
name|Matcher
operator|<
name|T
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|A
operator|<
name|T
operator|>
operator|(
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Implements a matcher that compares a given value with a
end_comment

begin_comment
comment|// pre-supplied value using one of the ==,<=,<, etc, operators.  The
end_comment

begin_comment
comment|// two values being compared don't have to have the same type.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The matcher defined here is polymorphic (for example, Eq(5) can be
end_comment

begin_comment
comment|// used to match an int, a short, a double, etc).  Therefore we use
end_comment

begin_comment
comment|// a template type conversion operator in the implementation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The following template definition assumes that the Rhs parameter is
end_comment

begin_comment
comment|// a "bare" type (i.e. neither 'const T' nor 'T&').
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|D
operator|,
name|typename
name|Rhs
operator|,
name|typename
name|Op
operator|>
name|class
name|ComparisonBase
block|{
name|public
operator|:
name|explicit
name|ComparisonBase
argument_list|(
specifier|const
name|Rhs
operator|&
name|rhs
argument_list|)
operator|:
name|rhs_
argument_list|(
argument|rhs
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Lhs
operator|>
name|operator
name|Matcher
operator|<
name|Lhs
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new Impl<Lhs>(rhs_)
argument_list|)
return|;
block|}
name|private
operator|:
name|template
operator|<
name|typename
name|Lhs
operator|>
name|class
name|Impl
operator|:
name|public
name|MatcherInterface
operator|<
name|Lhs
operator|>
block|{
name|public
operator|:
name|explicit
name|Impl
argument_list|(
specifier|const
name|Rhs
operator|&
name|rhs
argument_list|)
operator|:
name|rhs_
argument_list|(
argument|rhs
argument_list|)
block|{}
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|Lhs lhs
argument_list|,
argument|MatchResultListener*
comment|/* listener */
argument_list|)
specifier|const
block|{
return|return
name|Op
argument_list|()
argument_list|(
name|lhs
argument_list|,
name|rhs_
argument_list|)
return|;
block|}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
name|D
operator|::
name|Desc
argument_list|()
operator|<<
literal|" "
block|;
name|UniversalPrint
argument_list|(
name|rhs_
argument_list|,
name|os
argument_list|)
block|;     }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
name|D
operator|::
name|NegatedDesc
argument_list|()
operator|<<
literal|" "
block|;
name|UniversalPrint
argument_list|(
name|rhs_
argument_list|,
name|os
argument_list|)
block|;     }
name|private
operator|:
name|Rhs
name|rhs_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
name|Rhs
name|rhs_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|ComparisonBase
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|Rhs
operator|>
name|class
name|EqMatcher
operator|:
name|public
name|ComparisonBase
operator|<
name|EqMatcher
operator|<
name|Rhs
operator|>
operator|,
name|Rhs
operator|,
name|AnyEq
operator|>
block|{
name|public
operator|:
name|explicit
name|EqMatcher
argument_list|(
specifier|const
name|Rhs
operator|&
name|rhs
argument_list|)
operator|:
name|ComparisonBase
operator|<
name|EqMatcher
operator|<
name|Rhs
operator|>
block|,
name|Rhs
block|,
name|AnyEq
operator|>
operator|(
name|rhs
operator|)
block|{ }
specifier|static
specifier|const
name|char
operator|*
name|Desc
argument_list|()
block|{
return|return
literal|"is equal to"
return|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|NegatedDesc
argument_list|()
block|{
return|return
literal|"isn't equal to"
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|Rhs
operator|>
name|class
name|NeMatcher
operator|:
name|public
name|ComparisonBase
operator|<
name|NeMatcher
operator|<
name|Rhs
operator|>
operator|,
name|Rhs
operator|,
name|AnyNe
operator|>
block|{
name|public
operator|:
name|explicit
name|NeMatcher
argument_list|(
specifier|const
name|Rhs
operator|&
name|rhs
argument_list|)
operator|:
name|ComparisonBase
operator|<
name|NeMatcher
operator|<
name|Rhs
operator|>
block|,
name|Rhs
block|,
name|AnyNe
operator|>
operator|(
name|rhs
operator|)
block|{ }
specifier|static
specifier|const
name|char
operator|*
name|Desc
argument_list|()
block|{
return|return
literal|"isn't equal to"
return|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|NegatedDesc
argument_list|()
block|{
return|return
literal|"is equal to"
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|Rhs
operator|>
name|class
name|LtMatcher
operator|:
name|public
name|ComparisonBase
operator|<
name|LtMatcher
operator|<
name|Rhs
operator|>
operator|,
name|Rhs
operator|,
name|AnyLt
operator|>
block|{
name|public
operator|:
name|explicit
name|LtMatcher
argument_list|(
specifier|const
name|Rhs
operator|&
name|rhs
argument_list|)
operator|:
name|ComparisonBase
operator|<
name|LtMatcher
operator|<
name|Rhs
operator|>
block|,
name|Rhs
block|,
name|AnyLt
operator|>
operator|(
name|rhs
operator|)
block|{ }
specifier|static
specifier|const
name|char
operator|*
name|Desc
argument_list|()
block|{
return|return
literal|"is<"
return|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|NegatedDesc
argument_list|()
block|{
return|return
literal|"isn't<"
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|Rhs
operator|>
name|class
name|GtMatcher
operator|:
name|public
name|ComparisonBase
operator|<
name|GtMatcher
operator|<
name|Rhs
operator|>
operator|,
name|Rhs
operator|,
name|AnyGt
operator|>
block|{
name|public
operator|:
name|explicit
name|GtMatcher
argument_list|(
specifier|const
name|Rhs
operator|&
name|rhs
argument_list|)
operator|:
name|ComparisonBase
operator|<
name|GtMatcher
operator|<
name|Rhs
operator|>
block|,
name|Rhs
block|,
name|AnyGt
operator|>
operator|(
name|rhs
operator|)
block|{ }
specifier|static
specifier|const
name|char
operator|*
name|Desc
argument_list|()
block|{
return|return
literal|"is>"
return|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|NegatedDesc
argument_list|()
block|{
return|return
literal|"isn't>"
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|Rhs
operator|>
name|class
name|LeMatcher
operator|:
name|public
name|ComparisonBase
operator|<
name|LeMatcher
operator|<
name|Rhs
operator|>
operator|,
name|Rhs
operator|,
name|AnyLe
operator|>
block|{
name|public
operator|:
name|explicit
name|LeMatcher
argument_list|(
specifier|const
name|Rhs
operator|&
name|rhs
argument_list|)
operator|:
name|ComparisonBase
operator|<
name|LeMatcher
operator|<
name|Rhs
operator|>
block|,
name|Rhs
block|,
name|AnyLe
operator|>
operator|(
name|rhs
operator|)
block|{ }
specifier|static
specifier|const
name|char
operator|*
name|Desc
argument_list|()
block|{
return|return
literal|"is<="
return|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|NegatedDesc
argument_list|()
block|{
return|return
literal|"isn't<="
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|Rhs
operator|>
name|class
name|GeMatcher
operator|:
name|public
name|ComparisonBase
operator|<
name|GeMatcher
operator|<
name|Rhs
operator|>
operator|,
name|Rhs
operator|,
name|AnyGe
operator|>
block|{
name|public
operator|:
name|explicit
name|GeMatcher
argument_list|(
specifier|const
name|Rhs
operator|&
name|rhs
argument_list|)
operator|:
name|ComparisonBase
operator|<
name|GeMatcher
operator|<
name|Rhs
operator|>
block|,
name|Rhs
block|,
name|AnyGe
operator|>
operator|(
name|rhs
operator|)
block|{ }
specifier|static
specifier|const
name|char
operator|*
name|Desc
argument_list|()
block|{
return|return
literal|"is>="
return|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|NegatedDesc
argument_list|()
block|{
return|return
literal|"isn't>="
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Implements the polymorphic IsNull() matcher, which matches any raw or smart
end_comment

begin_comment
comment|// pointer that is NULL.
end_comment

begin_decl_stmt
name|class
name|IsNullMatcher
block|{
name|public
label|:
name|template
operator|<
name|typename
name|Pointer
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|const Pointer& p
argument_list|,
argument|MatchResultListener*
comment|/* listener */
argument_list|)
specifier|const
block|{
if|#
directive|if
name|GTEST_LANG_CXX11
return|return
name|p
operator|==
name|nullptr
return|;
else|#
directive|else
comment|// GTEST_LANG_CXX11
return|return
name|GetRawPointer
argument_list|(
name|p
argument_list|)
operator|==
name|NULL
return|;
endif|#
directive|endif
comment|// GTEST_LANG_CXX11
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|DescribeTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
literal|"is NULL"
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|DescribeNegationTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
literal|"isn't NULL"
expr_stmt|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|// Implements the polymorphic NotNull() matcher, which matches any raw or smart
end_comment

begin_comment
comment|// pointer that is not NULL.
end_comment

begin_decl_stmt
name|class
name|NotNullMatcher
block|{
name|public
label|:
name|template
operator|<
name|typename
name|Pointer
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|const Pointer& p
argument_list|,
argument|MatchResultListener*
comment|/* listener */
argument_list|)
specifier|const
block|{
if|#
directive|if
name|GTEST_LANG_CXX11
return|return
name|p
operator|!=
name|nullptr
return|;
else|#
directive|else
comment|// GTEST_LANG_CXX11
return|return
name|GetRawPointer
argument_list|(
name|p
argument_list|)
operator|!=
name|NULL
return|;
endif|#
directive|endif
comment|// GTEST_LANG_CXX11
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|DescribeTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
literal|"isn't NULL"
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|DescribeNegationTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
literal|"is NULL"
expr_stmt|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|// Ref(variable) matches any argument that is a reference to
end_comment

begin_comment
comment|// 'variable'.  This matcher is polymorphic as it can match any
end_comment

begin_comment
comment|// super type of the type of 'variable'.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The RefMatcher template class implements Ref(variable).  It can
end_comment

begin_comment
comment|// only be instantiated with a reference type.  This prevents a user
end_comment

begin_comment
comment|// from mistakenly using Ref(x) to match a non-reference function
end_comment

begin_comment
comment|// argument.  For example, the following will righteously cause a
end_comment

begin_comment
comment|// compiler error:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   int n;
end_comment

begin_comment
comment|//   Matcher<int> m1 = Ref(n);   // This won't compile.
end_comment

begin_comment
comment|//   Matcher<int&> m2 = Ref(n);  // This will compile.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|RefMatcher
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|RefMatcher
operator|<
name|T
operator|&
operator|>
block|{
comment|// Google Mock is a generic framework and thus needs to support
comment|// mocking any function types, including those that take non-const
comment|// reference arguments.  Therefore the template parameter T (and
comment|// Super below) can be instantiated to either a const type or a
comment|// non-const type.
name|public
operator|:
comment|// RefMatcher() takes a T& instead of const T&, as we want the
comment|// compiler to catch using Ref(const_value) as a matcher for a
comment|// non-const reference.
name|explicit
name|RefMatcher
argument_list|(
name|T
operator|&
name|x
argument_list|)
operator|:
name|object_
argument_list|(
argument|x
argument_list|)
block|{}
comment|// NOLINT
name|template
operator|<
name|typename
name|Super
operator|>
name|operator
name|Matcher
operator|<
name|Super
operator|&
operator|>
operator|(
operator|)
specifier|const
block|{
comment|// By passing object_ (type T&) to Impl(), which expects a Super&,
comment|// we make sure that Super is a super type of T.  In particular,
comment|// this catches using Ref(const_value) as a matcher for a
comment|// non-const reference, as you cannot implicitly convert a const
comment|// reference to a non-const reference.
return|return
name|MakeMatcher
argument_list|(
argument|new Impl<Super>(object_)
argument_list|)
return|;
block|}
name|private
operator|:
name|template
operator|<
name|typename
name|Super
operator|>
name|class
name|Impl
operator|:
name|public
name|MatcherInterface
operator|<
name|Super
operator|&
operator|>
block|{
name|public
operator|:
name|explicit
name|Impl
argument_list|(
name|Super
operator|&
name|x
argument_list|)
operator|:
name|object_
argument_list|(
argument|x
argument_list|)
block|{}
comment|// NOLINT
comment|// MatchAndExplain() takes a Super& (as opposed to const Super&)
comment|// in order to match the interface MatcherInterface<Super&>.
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|Super& x
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
operator|*
name|listener
operator|<<
literal|"which is located @"
operator|<<
name|static_cast
operator|<
specifier|const
name|void
operator|*
operator|>
operator|(
operator|&
name|x
operator|)
block|;
return|return
operator|&
name|x
operator|==
operator|&
name|object_
return|;
block|}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"references the variable "
block|;
name|UniversalPrinter
operator|<
name|Super
operator|&
operator|>
operator|::
name|Print
argument_list|(
name|object_
argument_list|,
name|os
argument_list|)
block|;     }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"does not reference the variable "
block|;
name|UniversalPrinter
operator|<
name|Super
operator|&
operator|>
operator|::
name|Print
argument_list|(
name|object_
argument_list|,
name|os
argument_list|)
block|;     }
name|private
operator|:
specifier|const
name|Super
operator|&
name|object_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
name|T
modifier|&
name|object_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|RefMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Polymorphic helper functions for narrow and wide string matchers.
end_comment

begin_function
specifier|inline
name|bool
name|CaseInsensitiveCStringEquals
parameter_list|(
specifier|const
name|char
modifier|*
name|lhs
parameter_list|,
specifier|const
name|char
modifier|*
name|rhs
parameter_list|)
block|{
return|return
name|String
operator|::
name|CaseInsensitiveCStringEquals
argument_list|(
name|lhs
argument_list|,
name|rhs
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|bool
name|CaseInsensitiveCStringEquals
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|lhs
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|rhs
parameter_list|)
block|{
return|return
name|String
operator|::
name|CaseInsensitiveWideCStringEquals
argument_list|(
name|lhs
argument_list|,
name|rhs
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// String comparison for narrow or wide strings that can have embedded NUL
end_comment

begin_comment
comment|// characters.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|StringType
operator|>
name|bool
name|CaseInsensitiveStringEquals
argument_list|(
argument|const StringType& s1
argument_list|,
argument|const StringType& s2
argument_list|)
block|{
comment|// Are the heads equal?
if|if
condition|(
operator|!
name|CaseInsensitiveCStringEquals
argument_list|(
name|s1
operator|.
name|c_str
argument_list|()
argument_list|,
name|s2
operator|.
name|c_str
argument_list|()
argument_list|)
condition|)
block|{
return|return
name|false
return|;
block|}
comment|// Skip the equal heads.
specifier|const
name|typename
name|StringType
operator|::
name|value_type
name|nul
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|size_t
name|i1
init|=
name|s1
operator|.
name|find
argument_list|(
name|nul
argument_list|)
decl_stmt|,
name|i2
init|=
name|s2
operator|.
name|find
argument_list|(
name|nul
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Are we at the end of either s1 or s2?
end_comment

begin_if
if|if
condition|(
name|i1
operator|==
name|StringType
operator|::
name|npos
operator|||
name|i2
operator|==
name|StringType
operator|::
name|npos
condition|)
block|{
return|return
name|i1
operator|==
name|i2
return|;
block|}
end_if

begin_comment
comment|// Are the tails equal?
end_comment

begin_return
return|return
name|CaseInsensitiveStringEquals
argument_list|(
name|s1
operator|.
name|substr
argument_list|(
name|i1
operator|+
literal|1
argument_list|)
argument_list|,
name|s2
operator|.
name|substr
argument_list|(
name|i2
operator|+
literal|1
argument_list|)
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|// String matchers.
end_comment

begin_comment
comment|// Implements equality-based string matchers like StrEq, StrCaseNe, and etc.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|StringType
operator|>
name|class
name|StrEqualityMatcher
block|{
name|public
operator|:
name|StrEqualityMatcher
argument_list|(
argument|const StringType& str
argument_list|,
argument|bool expect_eq
argument_list|,
argument|bool case_sensitive
argument_list|)
operator|:
name|string_
argument_list|(
name|str
argument_list|)
block|,
name|expect_eq_
argument_list|(
name|expect_eq
argument_list|)
block|,
name|case_sensitive_
argument_list|(
argument|case_sensitive
argument_list|)
block|{}
comment|// Accepts pointer types, particularly:
comment|//   const char*
comment|//   char*
comment|//   const wchar_t*
comment|//   wchar_t*
name|template
operator|<
name|typename
name|CharType
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|CharType* s
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
block|{
return|return
operator|!
name|expect_eq_
return|;
block|}
return|return
name|MatchAndExplain
argument_list|(
name|StringType
argument_list|(
name|s
argument_list|)
argument_list|,
name|listener
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches anything that can convert to StringType.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is a template, not just a plain function with const StringType&,
end_comment

begin_comment
comment|// because StringPiece has some interfering non-explicit constructors.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|MatcheeStringType
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|const MatcheeStringType& s
argument_list|,
argument|MatchResultListener*
comment|/* listener */
argument_list|)
specifier|const
block|{
specifier|const
name|StringType
operator|&
name|s2
argument_list|(
name|s
argument_list|)
block|;
specifier|const
name|bool
name|eq
operator|=
name|case_sensitive_
condition|?
name|s2
operator|==
name|string_
else|:
name|CaseInsensitiveStringEquals
argument_list|(
name|s2
argument_list|,
name|string_
argument_list|)
block|;
return|return
name|expect_eq_
operator|==
name|eq
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|DescribeTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
name|DescribeToHelper
argument_list|(
name|expect_eq_
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|DescribeNegationTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
name|DescribeToHelper
argument_list|(
operator|!
name|expect_eq_
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|void
name|DescribeToHelper
argument_list|(
name|bool
name|expect_eq
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
operator|(
name|expect_eq
condition|?
literal|"is "
else|:
literal|"isn't "
operator|)
expr_stmt|;
operator|*
name|os
operator|<<
literal|"equal to "
expr_stmt|;
if|if
condition|(
operator|!
name|case_sensitive_
condition|)
block|{
operator|*
name|os
operator|<<
literal|"(ignoring case) "
expr_stmt|;
block|}
name|UniversalPrint
argument_list|(
name|string_
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|const
name|StringType
name|string_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bool
name|expect_eq_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bool
name|case_sensitive_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|StrEqualityMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements the polymorphic HasSubstr(substring) matcher, which
end_comment

begin_comment
comment|// can be used as a Matcher<T> as long as T can be converted to a
end_comment

begin_comment
comment|// string.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|StringType
operator|>
name|class
name|HasSubstrMatcher
block|{
name|public
operator|:
name|explicit
name|HasSubstrMatcher
argument_list|(
specifier|const
name|StringType
operator|&
name|substring
argument_list|)
operator|:
name|substring_
argument_list|(
argument|substring
argument_list|)
block|{}
comment|// Accepts pointer types, particularly:
comment|//   const char*
comment|//   char*
comment|//   const wchar_t*
comment|//   wchar_t*
name|template
operator|<
name|typename
name|CharType
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|CharType* s
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
return|return
name|s
operator|!=
name|NULL
operator|&&
name|MatchAndExplain
argument_list|(
name|StringType
argument_list|(
name|s
argument_list|)
argument_list|,
name|listener
argument_list|)
return|;
block|}
comment|// Matches anything that can convert to StringType.
comment|//
comment|// This is a template, not just a plain function with const StringType&,
comment|// because StringPiece has some interfering non-explicit constructors.
name|template
operator|<
name|typename
name|MatcheeStringType
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|const MatcheeStringType& s
argument_list|,
argument|MatchResultListener*
comment|/* listener */
argument_list|)
specifier|const
block|{
specifier|const
name|StringType
operator|&
name|s2
argument_list|(
name|s
argument_list|)
block|;
return|return
name|s2
operator|.
name|find
argument_list|(
name|substring_
argument_list|)
operator|!=
name|StringType
operator|::
name|npos
return|;
block|}
end_expr_stmt

begin_comment
comment|// Describes what this matcher matches.
end_comment

begin_decl_stmt
name|void
name|DescribeTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
literal|"has substring "
expr_stmt|;
name|UniversalPrint
argument_list|(
name|substring_
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|DescribeNegationTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
literal|"has no substring "
expr_stmt|;
name|UniversalPrint
argument_list|(
name|substring_
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|StringType
name|substring_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|HasSubstrMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements the polymorphic StartsWith(substring) matcher, which
end_comment

begin_comment
comment|// can be used as a Matcher<T> as long as T can be converted to a
end_comment

begin_comment
comment|// string.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|StringType
operator|>
name|class
name|StartsWithMatcher
block|{
name|public
operator|:
name|explicit
name|StartsWithMatcher
argument_list|(
specifier|const
name|StringType
operator|&
name|prefix
argument_list|)
operator|:
name|prefix_
argument_list|(
argument|prefix
argument_list|)
block|{   }
comment|// Accepts pointer types, particularly:
comment|//   const char*
comment|//   char*
comment|//   const wchar_t*
comment|//   wchar_t*
name|template
operator|<
name|typename
name|CharType
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|CharType* s
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
return|return
name|s
operator|!=
name|NULL
operator|&&
name|MatchAndExplain
argument_list|(
name|StringType
argument_list|(
name|s
argument_list|)
argument_list|,
name|listener
argument_list|)
return|;
block|}
comment|// Matches anything that can convert to StringType.
comment|//
comment|// This is a template, not just a plain function with const StringType&,
comment|// because StringPiece has some interfering non-explicit constructors.
name|template
operator|<
name|typename
name|MatcheeStringType
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|const MatcheeStringType& s
argument_list|,
argument|MatchResultListener*
comment|/* listener */
argument_list|)
specifier|const
block|{
specifier|const
name|StringType
operator|&
name|s2
argument_list|(
name|s
argument_list|)
block|;
return|return
name|s2
operator|.
name|length
argument_list|()
operator|>=
name|prefix_
operator|.
name|length
argument_list|()
operator|&&
name|s2
operator|.
name|substr
argument_list|(
literal|0
argument_list|,
name|prefix_
operator|.
name|length
argument_list|()
argument_list|)
operator|==
name|prefix_
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|DescribeTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
literal|"starts with "
expr_stmt|;
name|UniversalPrint
argument_list|(
name|prefix_
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|DescribeNegationTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
literal|"doesn't start with "
expr_stmt|;
name|UniversalPrint
argument_list|(
name|prefix_
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|StringType
name|prefix_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|StartsWithMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements the polymorphic EndsWith(substring) matcher, which
end_comment

begin_comment
comment|// can be used as a Matcher<T> as long as T can be converted to a
end_comment

begin_comment
comment|// string.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|StringType
operator|>
name|class
name|EndsWithMatcher
block|{
name|public
operator|:
name|explicit
name|EndsWithMatcher
argument_list|(
specifier|const
name|StringType
operator|&
name|suffix
argument_list|)
operator|:
name|suffix_
argument_list|(
argument|suffix
argument_list|)
block|{}
comment|// Accepts pointer types, particularly:
comment|//   const char*
comment|//   char*
comment|//   const wchar_t*
comment|//   wchar_t*
name|template
operator|<
name|typename
name|CharType
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|CharType* s
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
return|return
name|s
operator|!=
name|NULL
operator|&&
name|MatchAndExplain
argument_list|(
name|StringType
argument_list|(
name|s
argument_list|)
argument_list|,
name|listener
argument_list|)
return|;
block|}
comment|// Matches anything that can convert to StringType.
comment|//
comment|// This is a template, not just a plain function with const StringType&,
comment|// because StringPiece has some interfering non-explicit constructors.
name|template
operator|<
name|typename
name|MatcheeStringType
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|const MatcheeStringType& s
argument_list|,
argument|MatchResultListener*
comment|/* listener */
argument_list|)
specifier|const
block|{
specifier|const
name|StringType
operator|&
name|s2
argument_list|(
name|s
argument_list|)
block|;
return|return
name|s2
operator|.
name|length
argument_list|()
operator|>=
name|suffix_
operator|.
name|length
argument_list|()
operator|&&
name|s2
operator|.
name|substr
argument_list|(
name|s2
operator|.
name|length
argument_list|()
operator|-
name|suffix_
operator|.
name|length
argument_list|()
argument_list|)
operator|==
name|suffix_
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|DescribeTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
literal|"ends with "
expr_stmt|;
name|UniversalPrint
argument_list|(
name|suffix_
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|DescribeNegationTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
literal|"doesn't end with "
expr_stmt|;
name|UniversalPrint
argument_list|(
name|suffix_
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|StringType
name|suffix_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|EndsWithMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements polymorphic matchers MatchesRegex(regex) and
end_comment

begin_comment
comment|// ContainsRegex(regex), which can be used as a Matcher<T> as long as
end_comment

begin_comment
comment|// T can be converted to a string.
end_comment

begin_decl_stmt
name|class
name|MatchesRegexMatcher
block|{
name|public
label|:
name|MatchesRegexMatcher
argument_list|(
argument|const RE* regex
argument_list|,
argument|bool full_match
argument_list|)
block|:
name|regex_
argument_list|(
name|regex
argument_list|)
operator|,
name|full_match_
argument_list|(
argument|full_match
argument_list|)
block|{}
comment|// Accepts pointer types, particularly:
comment|//   const char*
comment|//   char*
comment|//   const wchar_t*
comment|//   wchar_t*
name|template
operator|<
name|typename
name|CharType
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|CharType* s
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
return|return
name|s
operator|!=
name|NULL
operator|&&
name|MatchAndExplain
argument_list|(
name|internal
operator|::
name|string
argument_list|(
name|s
argument_list|)
argument_list|,
name|listener
argument_list|)
return|;
block|}
comment|// Matches anything that can convert to internal::string.
comment|//
comment|// This is a template, not just a plain function with const internal::string&,
comment|// because StringPiece has some interfering non-explicit constructors.
name|template
operator|<
name|class
name|MatcheeStringType
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|const MatcheeStringType& s
argument_list|,
argument|MatchResultListener*
comment|/* listener */
argument_list|)
specifier|const
block|{
specifier|const
name|internal
operator|::
name|string
operator|&
name|s2
argument_list|(
name|s
argument_list|)
block|;
return|return
name|full_match_
condition|?
name|RE
operator|::
name|FullMatch
argument_list|(
name|s2
argument_list|,
operator|*
name|regex_
argument_list|)
else|:
name|RE
operator|::
name|PartialMatch
argument_list|(
name|s2
argument_list|,
operator|*
name|regex_
argument_list|)
return|;
block|}
name|void
name|DescribeTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
operator|(
name|full_match_
condition|?
literal|"matches"
else|:
literal|"contains"
operator|)
operator|<<
literal|" regular expression "
expr_stmt|;
name|UniversalPrinter
operator|<
name|internal
operator|::
name|string
operator|>
operator|::
name|Print
argument_list|(
name|regex_
operator|->
name|pattern
argument_list|()
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
name|void
name|DescribeNegationTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
literal|"doesn't "
operator|<<
operator|(
name|full_match_
condition|?
literal|"match"
else|:
literal|"contain"
operator|)
operator|<<
literal|" regular expression "
expr_stmt|;
name|UniversalPrinter
operator|<
name|internal
operator|::
name|string
operator|>
operator|::
name|Print
argument_list|(
name|regex_
operator|->
name|pattern
argument_list|()
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
name|private
label|:
specifier|const
name|internal
operator|::
name|linked_ptr
operator|<
specifier|const
name|RE
operator|>
name|regex_
expr_stmt|;
specifier|const
name|bool
name|full_match_
decl_stmt|;
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|MatchesRegexMatcher
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Implements a matcher that compares the two fields of a 2-tuple
end_comment

begin_comment
comment|// using one of the ==,<=,<, etc, operators.  The two fields being
end_comment

begin_comment
comment|// compared don't have to have the same type.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The matcher defined here is polymorphic (for example, Eq() can be
end_comment

begin_comment
comment|// used to match a tuple<int, short>, a tuple<const long&, double>,
end_comment

begin_comment
comment|// etc).  Therefore we use a template type conversion operator in the
end_comment

begin_comment
comment|// implementation.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|D
operator|,
name|typename
name|Op
operator|>
name|class
name|PairMatchBase
block|{
name|public
operator|:
name|template
operator|<
name|typename
name|T1
block|,
name|typename
name|T2
operator|>
name|operator
name|Matcher
operator|<
operator|::
name|testing
operator|::
name|tuple
operator|<
name|T1
block|,
name|T2
operator|>
expr|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new Impl< ::testing::tuple<T1
argument_list|,
argument|T2>>
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|operator
name|Matcher
operator|<
specifier|const
operator|::
name|testing
operator|::
name|tuple
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new Impl<const ::testing::tuple<T1
argument_list|,
argument|T2>&>
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|static
operator|::
name|std
operator|::
name|ostream
operator|&
name|GetDesc
argument_list|(
argument|::std::ostream& os
argument_list|)
block|{
comment|// NOLINT
return|return
name|os
operator|<<
name|D
operator|::
name|Desc
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|Tuple
operator|>
name|class
name|Impl
operator|:
name|public
name|MatcherInterface
operator|<
name|Tuple
operator|>
block|{
name|public
operator|:
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|Tuple args
argument_list|,
argument|MatchResultListener*
comment|/* listener */
argument_list|)
specifier|const
block|{
return|return
name|Op
argument_list|()
argument_list|(
operator|::
name|testing
operator|::
name|get
operator|<
literal|0
operator|>
operator|(
name|args
operator|)
argument_list|,
operator|::
name|testing
operator|::
name|get
operator|<
literal|1
operator|>
operator|(
name|args
operator|)
argument_list|)
return|;
block|}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"are "
operator|<<
name|GetDesc
block|;     }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"aren't "
operator|<<
name|GetDesc
block|;     }
end_expr_stmt

begin_decl_stmt
unit|}; };
name|class
name|Eq2Matcher
range|:
name|public
name|PairMatchBase
operator|<
name|Eq2Matcher
decl_stmt|,
name|AnyEq
decl|>
block|{
name|public
label|:
specifier|static
specifier|const
name|char
modifier|*
name|Desc
parameter_list|()
block|{
return|return
literal|"an equal pair"
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|Ne2Matcher
range|:
name|public
name|PairMatchBase
operator|<
name|Ne2Matcher
decl_stmt|,
name|AnyNe
decl|>
block|{
name|public
label|:
specifier|static
specifier|const
name|char
modifier|*
name|Desc
parameter_list|()
block|{
return|return
literal|"an unequal pair"
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|Lt2Matcher
range|:
name|public
name|PairMatchBase
operator|<
name|Lt2Matcher
decl_stmt|,
name|AnyLt
decl|>
block|{
name|public
label|:
specifier|static
specifier|const
name|char
modifier|*
name|Desc
parameter_list|()
block|{
return|return
literal|"a pair where the first< the second"
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|Gt2Matcher
range|:
name|public
name|PairMatchBase
operator|<
name|Gt2Matcher
decl_stmt|,
name|AnyGt
decl|>
block|{
name|public
label|:
specifier|static
specifier|const
name|char
modifier|*
name|Desc
parameter_list|()
block|{
return|return
literal|"a pair where the first> the second"
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|Le2Matcher
range|:
name|public
name|PairMatchBase
operator|<
name|Le2Matcher
decl_stmt|,
name|AnyLe
decl|>
block|{
name|public
label|:
specifier|static
specifier|const
name|char
modifier|*
name|Desc
parameter_list|()
block|{
return|return
literal|"a pair where the first<= the second"
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|Ge2Matcher
range|:
name|public
name|PairMatchBase
operator|<
name|Ge2Matcher
decl_stmt|,
name|AnyGe
decl|>
block|{
name|public
label|:
specifier|static
specifier|const
name|char
modifier|*
name|Desc
parameter_list|()
block|{
return|return
literal|"a pair where the first>= the second"
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Implements the Not(...) matcher for a particular argument type T.
end_comment

begin_comment
comment|// We do not nest it inside the NotMatcher class template, as that
end_comment

begin_comment
comment|// will prevent different instantiations of NotMatcher from sharing
end_comment

begin_comment
comment|// the same NotMatcherImpl<T> class.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|NotMatcherImpl
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|explicit
name|NotMatcherImpl
argument_list|(
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|matcher
argument_list|)
operator|:
name|matcher_
argument_list|(
argument|matcher
argument_list|)
block|{}
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|T x
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
return|return
operator|!
name|matcher_
operator|.
name|MatchAndExplain
argument_list|(
name|x
argument_list|,
name|listener
argument_list|)
return|;
block|}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
name|matcher_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;   }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
name|matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;   }
name|private
operator|:
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|NotMatcherImpl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements the Not(m) matcher, which matches a value that doesn't
end_comment

begin_comment
comment|// match matcher m.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|InnerMatcher
operator|>
name|class
name|NotMatcher
block|{
name|public
operator|:
name|explicit
name|NotMatcher
argument_list|(
argument|InnerMatcher matcher
argument_list|)
operator|:
name|matcher_
argument_list|(
argument|matcher
argument_list|)
block|{}
comment|// This template type conversion operator allows Not(m) to be used
comment|// to match any type m can match.
name|template
operator|<
name|typename
name|T
operator|>
name|operator
name|Matcher
operator|<
name|T
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|new
name|NotMatcherImpl
operator|<
name|T
operator|>
operator|(
name|SafeMatcherCast
operator|<
name|T
operator|>
operator|(
name|matcher_
operator|)
operator|)
operator|)
return|;
block|}
name|private
operator|:
name|InnerMatcher
name|matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|NotMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements the AllOf(m1, m2) matcher for a particular argument type
end_comment

begin_comment
comment|// T. We do not nest it inside the BothOfMatcher class template, as
end_comment

begin_comment
comment|// that will prevent different instantiations of BothOfMatcher from
end_comment

begin_comment
comment|// sharing the same BothOfMatcherImpl<T> class.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|BothOfMatcherImpl
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|BothOfMatcherImpl
argument_list|(
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|matcher1
argument_list|,
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|matcher2
argument_list|)
operator|:
name|matcher1_
argument_list|(
name|matcher1
argument_list|)
block|,
name|matcher2_
argument_list|(
argument|matcher2
argument_list|)
block|{}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"("
block|;
name|matcher1_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|") and ("
block|;
name|matcher2_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|")"
block|;   }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"("
block|;
name|matcher1_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|") or ("
block|;
name|matcher2_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|")"
block|;   }
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|T x
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
comment|// If either matcher1_ or matcher2_ doesn't match x, we only need
comment|// to explain why one of them fails.
name|StringMatchResultListener
name|listener1
block|;
if|if
condition|(
operator|!
name|matcher1_
operator|.
name|MatchAndExplain
argument_list|(
name|x
argument_list|,
operator|&
name|listener1
argument_list|)
condition|)
block|{
operator|*
name|listener
operator|<<
name|listener1
operator|.
name|str
argument_list|()
expr_stmt|;
return|return
name|false
return|;
block|}
name|StringMatchResultListener
name|listener2
block|;
if|if
condition|(
operator|!
name|matcher2_
operator|.
name|MatchAndExplain
argument_list|(
name|x
argument_list|,
operator|&
name|listener2
argument_list|)
condition|)
block|{
operator|*
name|listener
operator|<<
name|listener2
operator|.
name|str
argument_list|()
expr_stmt|;
return|return
name|false
return|;
block|}
comment|// Otherwise we need to explain why *both* of them match.
specifier|const
name|internal
operator|::
name|string
name|s1
operator|=
name|listener1
operator|.
name|str
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|internal
operator|::
name|string
name|s2
operator|=
name|listener2
operator|.
name|str
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|s1
operator|==
literal|""
condition|)
block|{
operator|*
name|listener
operator|<<
name|s2
expr_stmt|;
block|}
else|else
block|{
operator|*
name|listener
operator|<<
name|s1
expr_stmt|;
if|if
condition|(
name|s2
operator|!=
literal|""
condition|)
block|{
operator|*
name|listener
operator|<<
literal|", and "
operator|<<
name|s2
expr_stmt|;
block|}
block|}
end_if

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}   private:
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|matcher1_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|matcher2_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|BothOfMatcherImpl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
unit|};
if|#
directive|if
name|GTEST_LANG_CXX11
end_if

begin_comment
comment|// MatcherList provides mechanisms for storing a variable number of matchers in
end_comment

begin_comment
comment|// a list structure (ListType) and creating a combining matcher from such a
end_comment

begin_comment
comment|// list.
end_comment

begin_comment
comment|// The template is defined recursively using the following template paramters:
end_comment

begin_comment
comment|//   * kSize is the length of the MatcherList.
end_comment

begin_comment
comment|//   * Head is the type of the first matcher of the list.
end_comment

begin_comment
comment|//   * Tail denotes the types of the remaining matchers of the list.
end_comment

begin_expr_stmt
name|template
operator|<
name|int
name|kSize
operator|,
name|typename
name|Head
operator|,
name|typename
operator|...
name|Tail
operator|>
expr|struct
name|MatcherList
block|{
typedef|typedef
name|MatcherList
operator|<
name|kSize
operator|-
literal|1
operator|,
name|Tail
operator|...
operator|>
name|MatcherListTail
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
operator|::
name|std
operator|::
name|pair
operator|<
name|Head
operator|,
name|typename
name|MatcherListTail
operator|::
name|ListType
operator|>
name|ListType
expr_stmt|;
end_typedef

begin_comment
comment|// BuildList stores variadic type values in a nested pair structure.
end_comment

begin_comment
comment|// Example:
end_comment

begin_comment
comment|// MatcherList<3, int, string, float>::BuildList(5, "foo", 2.0) will return
end_comment

begin_comment
comment|// the corresponding result of type pair<int, pair<string, float>>.
end_comment

begin_function
specifier|static
name|ListType
name|BuildList
parameter_list|(
specifier|const
name|Head
modifier|&
name|matcher
parameter_list|,
specifier|const
name|Tail
modifier|&
modifier|...
name|tail
parameter_list|)
block|{
return|return
name|ListType
argument_list|(
name|matcher
argument_list|,
name|MatcherListTail
operator|::
name|BuildList
argument_list|(
name|tail
operator|...
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CreateMatcher<T> creates a Matcher<T> from a given list of matchers (built
end_comment

begin_comment
comment|// by BuildList()). CombiningMatcher<T> is used to combine the matchers of the
end_comment

begin_comment
comment|// list. CombiningMatcher<T> must implement MatcherInterface<T> and have a
end_comment

begin_comment
comment|// constructor taking two Matcher<T>s as input.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|template
operator|<
name|typename
comment|/* T */
operator|>
name|class
name|CombiningMatcher
operator|>
specifier|static
name|Matcher
operator|<
name|T
operator|>
name|CreateMatcher
argument_list|(
argument|const ListType& matchers
argument_list|)
block|{
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|new
name|CombiningMatcher
operator|<
name|T
operator|>
operator|(
name|SafeMatcherCast
operator|<
name|T
operator|>
operator|(
name|matchers
operator|.
name|first
operator|)
operator|,
name|MatcherListTail
operator|::
name|template
name|CreateMatcher
operator|<
name|T
operator|,
name|CombiningMatcher
operator|>
operator|(
name|matchers
operator|.
name|second
operator|)
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// The following defines the base case for the recursive definition of
end_comment

begin_comment
comment|// MatcherList.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Matcher1
operator|,
name|typename
name|Matcher2
operator|>
expr|struct
name|MatcherList
operator|<
literal|2
operator|,
name|Matcher1
operator|,
name|Matcher2
operator|>
block|{
typedef|typedef
operator|::
name|std
operator|::
name|pair
operator|<
name|Matcher1
operator|,
name|Matcher2
operator|>
name|ListType
expr_stmt|;
specifier|static
name|ListType
name|BuildList
argument_list|(
argument|const Matcher1& matcher1
argument_list|,
argument|const Matcher2& matcher2
argument_list|)
block|{
return|return
operator|::
name|std
operator|::
name|pair
operator|<
name|Matcher1
operator|,
name|Matcher2
operator|>
operator|(
name|matcher1
operator|,
name|matcher2
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|,
name|template
operator|<
name|typename
comment|/* T */
operator|>
name|class
name|CombiningMatcher
operator|>
specifier|static
name|Matcher
operator|<
name|T
operator|>
name|CreateMatcher
argument_list|(
argument|const ListType& matchers
argument_list|)
block|{
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|new
name|CombiningMatcher
operator|<
name|T
operator|>
operator|(
name|SafeMatcherCast
operator|<
name|T
operator|>
operator|(
name|matchers
operator|.
name|first
operator|)
operator|,
name|SafeMatcherCast
operator|<
name|T
operator|>
operator|(
name|matchers
operator|.
name|second
operator|)
operator|)
operator|)
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// VariadicMatcher is used for the variadic implementation of
end_comment

begin_comment
comment|// AllOf(m_1, m_2, ...) and AnyOf(m_1, m_2, ...).
end_comment

begin_comment
comment|// CombiningMatcher<T> is used to recursively combine the provided matchers
end_comment

begin_comment
comment|// (of type Args...).
end_comment

begin_expr_stmt
name|template
operator|<
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|CombiningMatcher
operator|,
name|typename
operator|...
name|Args
operator|>
name|class
name|VariadicMatcher
block|{
name|public
operator|:
name|VariadicMatcher
argument_list|(
specifier|const
name|Args
operator|&
operator|...
name|matchers
argument_list|)
comment|// NOLINT
operator|:
name|matchers_
argument_list|(
argument|MatcherListType::BuildList(matchers...)
argument_list|)
block|{}
comment|// This template type conversion operator allows an
comment|// VariadicMatcher<Matcher1, Matcher2...> object to match any type that
comment|// all of the provided matchers (Matcher1, Matcher2, ...) can match.
name|template
operator|<
name|typename
name|T
operator|>
name|operator
name|Matcher
operator|<
name|T
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MatcherListType
operator|::
name|template
name|CreateMatcher
operator|<
name|T
operator|,
name|CombiningMatcher
operator|>
operator|(
name|matchers_
operator|)
return|;
block|}
name|private
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|MatcherList
operator|<
sizeof|sizeof...
argument_list|(
name|Args
argument_list|)
operator|,
name|Args
operator|...
operator|>
name|MatcherListType
expr_stmt|;
end_typedef

begin_expr_stmt
specifier|const
name|typename
name|MatcherListType
operator|::
name|ListType
name|matchers_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|VariadicMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
operator|...
name|Args
operator|>
name|using
name|AllOfMatcher
operator|=
name|VariadicMatcher
operator|<
name|BothOfMatcherImpl
operator|,
name|Args
operator|...
operator|>
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_LANG_CXX11
end_comment

begin_comment
comment|// Used for implementing the AllOf(m_1, ..., m_n) matcher, which
end_comment

begin_comment
comment|// matches a value that matches all of the matchers m_1, ..., and m_n.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Matcher1
operator|,
name|typename
name|Matcher2
operator|>
name|class
name|BothOfMatcher
block|{
name|public
operator|:
name|BothOfMatcher
argument_list|(
argument|Matcher1 matcher1
argument_list|,
argument|Matcher2 matcher2
argument_list|)
operator|:
name|matcher1_
argument_list|(
name|matcher1
argument_list|)
block|,
name|matcher2_
argument_list|(
argument|matcher2
argument_list|)
block|{}
comment|// This template type conversion operator allows a
comment|// BothOfMatcher<Matcher1, Matcher2> object to match any type that
comment|// both Matcher1 and Matcher2 can match.
name|template
operator|<
name|typename
name|T
operator|>
name|operator
name|Matcher
operator|<
name|T
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|new
name|BothOfMatcherImpl
operator|<
name|T
operator|>
operator|(
name|SafeMatcherCast
operator|<
name|T
operator|>
operator|(
name|matcher1_
operator|)
operator|,
name|SafeMatcherCast
operator|<
name|T
operator|>
operator|(
name|matcher2_
operator|)
operator|)
operator|)
return|;
block|}
name|private
operator|:
name|Matcher1
name|matcher1_
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Matcher2
name|matcher2_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|BothOfMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements the AnyOf(m1, m2) matcher for a particular argument type
end_comment

begin_comment
comment|// T.  We do not nest it inside the AnyOfMatcher class template, as
end_comment

begin_comment
comment|// that will prevent different instantiations of AnyOfMatcher from
end_comment

begin_comment
comment|// sharing the same EitherOfMatcherImpl<T> class.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|EitherOfMatcherImpl
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|EitherOfMatcherImpl
argument_list|(
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|matcher1
argument_list|,
specifier|const
name|Matcher
operator|<
name|T
operator|>
operator|&
name|matcher2
argument_list|)
operator|:
name|matcher1_
argument_list|(
name|matcher1
argument_list|)
block|,
name|matcher2_
argument_list|(
argument|matcher2
argument_list|)
block|{}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"("
block|;
name|matcher1_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|") or ("
block|;
name|matcher2_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|")"
block|;   }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"("
block|;
name|matcher1_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|") and ("
block|;
name|matcher2_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|")"
block|;   }
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|T x
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
comment|// If either matcher1_ or matcher2_ matches x, we just need to
comment|// explain why *one* of them matches.
name|StringMatchResultListener
name|listener1
block|;
if|if
condition|(
name|matcher1_
operator|.
name|MatchAndExplain
argument_list|(
name|x
argument_list|,
operator|&
name|listener1
argument_list|)
condition|)
block|{
operator|*
name|listener
operator|<<
name|listener1
operator|.
name|str
argument_list|()
expr_stmt|;
return|return
name|true
return|;
block|}
name|StringMatchResultListener
name|listener2
block|;
if|if
condition|(
name|matcher2_
operator|.
name|MatchAndExplain
argument_list|(
name|x
argument_list|,
operator|&
name|listener2
argument_list|)
condition|)
block|{
operator|*
name|listener
operator|<<
name|listener2
operator|.
name|str
argument_list|()
expr_stmt|;
return|return
name|true
return|;
block|}
comment|// Otherwise we need to explain why *both* of them fail.
specifier|const
name|internal
operator|::
name|string
name|s1
operator|=
name|listener1
operator|.
name|str
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|internal
operator|::
name|string
name|s2
operator|=
name|listener2
operator|.
name|str
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|s1
operator|==
literal|""
condition|)
block|{
operator|*
name|listener
operator|<<
name|s2
expr_stmt|;
block|}
else|else
block|{
operator|*
name|listener
operator|<<
name|s1
expr_stmt|;
if|if
condition|(
name|s2
operator|!=
literal|""
condition|)
block|{
operator|*
name|listener
operator|<<
literal|", and "
operator|<<
name|s2
expr_stmt|;
block|}
block|}
end_if

begin_return
return|return
name|false
return|;
end_return

begin_expr_stmt
unit|}   private:
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|matcher1_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|Matcher
operator|<
name|T
operator|>
name|matcher2_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|EitherOfMatcherImpl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
unit|};
if|#
directive|if
name|GTEST_LANG_CXX11
end_if

begin_comment
comment|// AnyOfMatcher is used for the variadic implementation of AnyOf(m_1, m_2, ...).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Args
operator|>
name|using
name|AnyOfMatcher
operator|=
name|VariadicMatcher
operator|<
name|EitherOfMatcherImpl
operator|,
name|Args
operator|...
operator|>
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_LANG_CXX11
end_comment

begin_comment
comment|// Used for implementing the AnyOf(m_1, ..., m_n) matcher, which
end_comment

begin_comment
comment|// matches a value that matches at least one of the matchers m_1, ...,
end_comment

begin_comment
comment|// and m_n.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Matcher1
operator|,
name|typename
name|Matcher2
operator|>
name|class
name|EitherOfMatcher
block|{
name|public
operator|:
name|EitherOfMatcher
argument_list|(
argument|Matcher1 matcher1
argument_list|,
argument|Matcher2 matcher2
argument_list|)
operator|:
name|matcher1_
argument_list|(
name|matcher1
argument_list|)
block|,
name|matcher2_
argument_list|(
argument|matcher2
argument_list|)
block|{}
comment|// This template type conversion operator allows a
comment|// EitherOfMatcher<Matcher1, Matcher2> object to match any type that
comment|// both Matcher1 and Matcher2 can match.
name|template
operator|<
name|typename
name|T
operator|>
name|operator
name|Matcher
operator|<
name|T
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|new
name|EitherOfMatcherImpl
operator|<
name|T
operator|>
operator|(
name|SafeMatcherCast
operator|<
name|T
operator|>
operator|(
name|matcher1_
operator|)
operator|,
name|SafeMatcherCast
operator|<
name|T
operator|>
operator|(
name|matcher2_
operator|)
operator|)
operator|)
return|;
block|}
name|private
operator|:
name|Matcher1
name|matcher1_
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Matcher2
name|matcher2_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|EitherOfMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Used for implementing Truly(pred), which turns a predicate into a
end_comment

begin_comment
comment|// matcher.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Predicate
operator|>
name|class
name|TrulyMatcher
block|{
name|public
operator|:
name|explicit
name|TrulyMatcher
argument_list|(
argument|Predicate pred
argument_list|)
operator|:
name|predicate_
argument_list|(
argument|pred
argument_list|)
block|{}
comment|// This method template allows Truly(pred) to be used as a matcher
comment|// for type T where T is the argument type of predicate 'pred'.  The
comment|// argument is passed by reference as the predicate may be
comment|// interested in the address of the argument.
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|T& x
argument_list|,
comment|// NOLINT
argument|MatchResultListener*
comment|/* listener */
argument_list|)
specifier|const
block|{
comment|// Without the if-statement, MSVC sometimes warns about converting
comment|// a value to bool (warning 4800).
comment|//
comment|// We cannot write 'return !!predicate_(x);' as that doesn't work
comment|// when predicate_(x) returns a class convertible to bool but
comment|// having no operator!().
if|if
condition|(
name|predicate_
argument_list|(
name|x
argument_list|)
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|DescribeTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
literal|"satisfies the given predicate"
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|DescribeNegationTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
literal|"doesn't satisfy the given predicate"
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|Predicate
name|predicate_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|TrulyMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Used for implementing Matches(matcher), which turns a matcher into
end_comment

begin_comment
comment|// a predicate.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|M
operator|>
name|class
name|MatcherAsPredicate
block|{
name|public
operator|:
name|explicit
name|MatcherAsPredicate
argument_list|(
argument|M matcher
argument_list|)
operator|:
name|matcher_
argument_list|(
argument|matcher
argument_list|)
block|{}
comment|// This template operator() allows Matches(m) to be used as a
comment|// predicate on type T where m is a matcher on type T.
comment|//
comment|// The argument x is passed by reference instead of by value, as
comment|// some matcher may be interested in its address (e.g. as in
comment|// Matches(Ref(n))(x)).
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|T
operator|&
name|x
operator|)
specifier|const
block|{
comment|// We let matcher_ commit to a particular type here instead of
comment|// when the MatcherAsPredicate object was constructed.  This
comment|// allows us to write Matches(m) where m is a polymorphic matcher
comment|// (e.g. Eq(5)).
comment|//
comment|// If we write Matcher<T>(matcher_).Matches(x) here, it won't
comment|// compile when matcher_ has type Matcher<const T&>; if we write
comment|// Matcher<const T&>(matcher_).Matches(x) here, it won't compile
comment|// when matcher_ has type Matcher<T>; if we just write
comment|// matcher_.Matches(x), it won't compile when matcher_ is
comment|// polymorphic, e.g. Eq(5).
comment|//
comment|// MatcherCast<const T&>() is necessary for making the code work
comment|// in all of the above situations.
return|return
name|MatcherCast
operator|<
specifier|const
name|T
operator|&
operator|>
operator|(
name|matcher_
operator|)
operator|.
name|Matches
argument_list|(
name|x
argument_list|)
return|;
block|}
name|private
operator|:
name|M
name|matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|MatcherAsPredicate
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// For implementing ASSERT_THAT() and EXPECT_THAT().  The template
end_comment

begin_comment
comment|// argument M must be a type that can be converted to a matcher.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|M
operator|>
name|class
name|PredicateFormatterFromMatcher
block|{
name|public
operator|:
name|explicit
name|PredicateFormatterFromMatcher
argument_list|(
argument|M m
argument_list|)
operator|:
name|matcher_
argument_list|(
argument|internal::move(m)
argument_list|)
block|{}
comment|// This template () operator allows a PredicateFormatterFromMatcher
comment|// object to act as a predicate-formatter suitable for using with
comment|// Google Test's EXPECT_PRED_FORMAT1() macro.
name|template
operator|<
name|typename
name|T
operator|>
name|AssertionResult
name|operator
argument_list|()
operator|(
specifier|const
name|char
operator|*
name|value_text
operator|,
specifier|const
name|T
operator|&
name|x
operator|)
specifier|const
block|{
comment|// We convert matcher_ to a Matcher<const T&> *now* instead of
comment|// when the PredicateFormatterFromMatcher object was constructed,
comment|// as matcher_ may be polymorphic (e.g. NotNull()) and we won't
comment|// know which type to instantiate it to until we actually see the
comment|// type of x here.
comment|//
comment|// We write SafeMatcherCast<const T&>(matcher_) instead of
comment|// Matcher<const T&>(matcher_), as the latter won't compile when
comment|// matcher_ has type Matcher<T> (e.g. An<int>()).
comment|// We don't write MatcherCast<const T&> either, as that allows
comment|// potentially unsafe downcasting of the matcher argument.
specifier|const
name|Matcher
operator|<
specifier|const
name|T
operator|&
operator|>
name|matcher
operator|=
name|SafeMatcherCast
operator|<
specifier|const
name|T
operator|&
operator|>
operator|(
name|matcher_
operator|)
block|;
name|StringMatchResultListener
name|listener
block|;
if|if
condition|(
name|MatchPrintAndExplain
argument_list|(
name|x
argument_list|,
name|matcher
argument_list|,
operator|&
name|listener
argument_list|)
condition|)
return|return
name|AssertionSuccess
argument_list|()
return|;
operator|::
name|std
operator|::
name|stringstream
name|ss
block|;
name|ss
operator|<<
literal|"Value of: "
operator|<<
name|value_text
operator|<<
literal|"\n"
operator|<<
literal|"Expected: "
block|;
name|matcher
operator|.
name|DescribeTo
argument_list|(
operator|&
name|ss
argument_list|)
block|;
name|ss
operator|<<
literal|"\n  Actual: "
operator|<<
name|listener
operator|.
name|str
argument_list|()
block|;
return|return
name|AssertionFailure
argument_list|()
operator|<<
name|ss
operator|.
name|str
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|M
name|matcher_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|PredicateFormatterFromMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// A helper function for converting a matcher to a predicate-formatter
end_comment

begin_comment
comment|// without the user needing to explicitly write the type.  This is
end_comment

begin_comment
comment|// used for implementing ASSERT_THAT() and EXPECT_THAT().
end_comment

begin_comment
comment|// Implementation detail: 'matcher' is received by-value to force decaying.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|M
operator|>
specifier|inline
name|PredicateFormatterFromMatcher
operator|<
name|M
operator|>
name|MakePredicateFormatterFromMatcher
argument_list|(
argument|M matcher
argument_list|)
block|{
return|return
name|PredicateFormatterFromMatcher
operator|<
name|M
operator|>
operator|(
name|internal
operator|::
name|move
argument_list|(
name|matcher
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Implements the polymorphic floating point equality matcher, which matches
end_comment

begin_comment
comment|// two float values using ULP-based approximation or, optionally, a
end_comment

begin_comment
comment|// user-specified epsilon.  The template is meant to be instantiated with
end_comment

begin_comment
comment|// FloatType being either float or double.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|FloatType
operator|>
name|class
name|FloatingEqMatcher
block|{
name|public
operator|:
comment|// Constructor for FloatingEqMatcher.
comment|// The matcher's input will be compared with expected.  The matcher treats two
comment|// NANs as equal if nan_eq_nan is true.  Otherwise, under IEEE standards,
comment|// equality comparisons between NANs will always return false.  We specify a
comment|// negative max_abs_error_ term to indicate that ULP-based approximation will
comment|// be used for comparison.
name|FloatingEqMatcher
argument_list|(
argument|FloatType expected
argument_list|,
argument|bool nan_eq_nan
argument_list|)
operator|:
name|expected_
argument_list|(
name|expected
argument_list|)
block|,
name|nan_eq_nan_
argument_list|(
name|nan_eq_nan
argument_list|)
block|,
name|max_abs_error_
argument_list|(
argument|-
literal|1
argument_list|)
block|{   }
comment|// Constructor that supports a user-specified max_abs_error that will be used
comment|// for comparison instead of ULP-based approximation.  The max absolute
comment|// should be non-negative.
name|FloatingEqMatcher
argument_list|(
argument|FloatType expected
argument_list|,
argument|bool nan_eq_nan
argument_list|,
argument|FloatType max_abs_error
argument_list|)
operator|:
name|expected_
argument_list|(
name|expected
argument_list|)
block|,
name|nan_eq_nan_
argument_list|(
name|nan_eq_nan
argument_list|)
block|,
name|max_abs_error_
argument_list|(
argument|max_abs_error
argument_list|)
block|{
name|GTEST_CHECK_
argument_list|(
name|max_abs_error
operator|>=
literal|0
argument_list|)
operator|<<
literal|", where max_abs_error is"
operator|<<
name|max_abs_error
block|;   }
comment|// Implements floating point equality matcher as a Matcher<T>.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Impl
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|Impl
argument_list|(
argument|FloatType expected
argument_list|,
argument|bool nan_eq_nan
argument_list|,
argument|FloatType max_abs_error
argument_list|)
operator|:
name|expected_
argument_list|(
name|expected
argument_list|)
block|,
name|nan_eq_nan_
argument_list|(
name|nan_eq_nan
argument_list|)
block|,
name|max_abs_error_
argument_list|(
argument|max_abs_error
argument_list|)
block|{}
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|T value
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
specifier|const
name|FloatingPoint
operator|<
name|FloatType
operator|>
name|actual
argument_list|(
name|value
argument_list|)
block|,
name|expected
argument_list|(
name|expected_
argument_list|)
block|;
comment|// Compares NaNs first, if nan_eq_nan_ is true.
if|if
condition|(
name|actual
operator|.
name|is_nan
argument_list|()
operator|||
name|expected
operator|.
name|is_nan
argument_list|()
condition|)
block|{
if|if
condition|(
name|actual
operator|.
name|is_nan
argument_list|()
operator|&&
name|expected
operator|.
name|is_nan
argument_list|()
condition|)
block|{
return|return
name|nan_eq_nan_
return|;
block|}
comment|// One is nan; the other is not nan.
return|return
name|false
return|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|HasMaxAbsError
argument_list|()
condition|)
block|{
comment|// We perform an equality check so that inf will match inf, regardless
comment|// of error bounds.  If the result of value - expected_ would result in
comment|// overflow or if either value is inf, the default result is infinity,
comment|// which should only match if max_abs_error_ is also infinity.
if|if
condition|(
name|value
operator|==
name|expected_
condition|)
block|{
return|return
name|true
return|;
block|}
specifier|const
name|FloatType
name|diff
init|=
name|value
operator|-
name|expected_
decl_stmt|;
if|if
condition|(
name|fabs
argument_list|(
name|diff
argument_list|)
operator|<=
name|max_abs_error_
condition|)
block|{
return|return
name|true
return|;
block|}
if|if
condition|(
name|listener
operator|->
name|IsInterested
argument_list|()
condition|)
block|{
operator|*
name|listener
operator|<<
literal|"which is "
operator|<<
name|diff
operator|<<
literal|" from "
operator|<<
name|expected_
expr_stmt|;
block|}
return|return
name|false
return|;
block|}
else|else
block|{
return|return
name|actual
operator|.
name|AlmostEquals
argument_list|(
name|expected
argument_list|)
return|;
block|}
end_if

begin_decl_stmt
unit|}      virtual
name|void
name|DescribeTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
comment|// os->precision() returns the previously set precision, which we
comment|// store to restore the ostream to its original configuration
comment|// after outputting.
specifier|const
operator|::
name|std
operator|::
name|streamsize
name|old_precision
operator|=
name|os
operator|->
name|precision
argument_list|(
operator|::
name|std
operator|::
name|numeric_limits
operator|<
name|FloatType
operator|>
operator|::
name|digits10
operator|+
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|FloatingPoint
operator|<
name|FloatType
operator|>
operator|(
name|expected_
operator|)
operator|.
name|is_nan
argument_list|()
condition|)
block|{
if|if
condition|(
name|nan_eq_nan_
condition|)
block|{
operator|*
name|os
operator|<<
literal|"is NaN"
expr_stmt|;
block|}
else|else
block|{
operator|*
name|os
operator|<<
literal|"never matches"
expr_stmt|;
block|}
block|}
else|else
block|{
operator|*
name|os
operator|<<
literal|"is approximately "
operator|<<
name|expected_
expr_stmt|;
if|if
condition|(
name|HasMaxAbsError
argument_list|()
condition|)
block|{
operator|*
name|os
operator|<<
literal|" (absolute error<= "
operator|<<
name|max_abs_error_
operator|<<
literal|")"
expr_stmt|;
block|}
block|}
name|os
operator|->
name|precision
argument_list|(
name|old_precision
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
comment|// As before, get original precision.
specifier|const
operator|::
name|std
operator|::
name|streamsize
name|old_precision
operator|=
name|os
operator|->
name|precision
argument_list|(
operator|::
name|std
operator|::
name|numeric_limits
operator|<
name|FloatType
operator|>
operator|::
name|digits10
operator|+
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|FloatingPoint
operator|<
name|FloatType
operator|>
operator|(
name|expected_
operator|)
operator|.
name|is_nan
argument_list|()
condition|)
block|{
if|if
condition|(
name|nan_eq_nan_
condition|)
block|{
operator|*
name|os
operator|<<
literal|"isn't NaN"
expr_stmt|;
block|}
else|else
block|{
operator|*
name|os
operator|<<
literal|"is anything"
expr_stmt|;
block|}
block|}
else|else
block|{
operator|*
name|os
operator|<<
literal|"isn't approximately "
operator|<<
name|expected_
expr_stmt|;
if|if
condition|(
name|HasMaxAbsError
argument_list|()
condition|)
block|{
operator|*
name|os
operator|<<
literal|" (absolute error> "
operator|<<
name|max_abs_error_
operator|<<
literal|")"
expr_stmt|;
block|}
block|}
comment|// Restore original precision.
name|os
operator|->
name|precision
argument_list|(
name|old_precision
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|bool
name|HasMaxAbsError
argument_list|()
specifier|const
block|{
return|return
name|max_abs_error_
operator|>=
literal|0
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|const
name|FloatType
name|expected_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bool
name|nan_eq_nan_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// max_abs_error will be used for value comparison when>= 0.
end_comment

begin_decl_stmt
specifier|const
name|FloatType
name|max_abs_error_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// The following 3 type conversion operators allow FloatEq(expected) and
end_comment

begin_comment
comment|// NanSensitiveFloatEq(expected) to be used as a Matcher<float>, a
end_comment

begin_comment
comment|// Matcher<const float&>, or a Matcher<float&>, but nothing else.
end_comment

begin_comment
comment|// (While Google's C++ coding style doesn't allow arguments passed
end_comment

begin_comment
comment|// by non-const reference, we may see them in code not conforming to
end_comment

begin_comment
comment|// the style.  Therefore Google Mock needs to support them.)
end_comment

begin_expr_stmt
name|operator
name|Matcher
operator|<
name|FloatType
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new Impl<FloatType>(expected_, nan_eq_nan_, max_abs_error_)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|operator
name|Matcher
operator|<
specifier|const
name|FloatType
operator|&
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new Impl<const FloatType&>(expected_, nan_eq_nan_, max_abs_error_)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|operator
name|Matcher
operator|<
name|FloatType
operator|&
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new Impl<FloatType&>(expected_, nan_eq_nan_, max_abs_error_)
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|FloatType
name|expected_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bool
name|nan_eq_nan_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// max_abs_error will be used for value comparison when>= 0.
end_comment

begin_decl_stmt
specifier|const
name|FloatType
name|max_abs_error_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|FloatingEqMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements the Pointee(m) matcher for matching a pointer whose
end_comment

begin_comment
comment|// pointee matches matcher m.  The pointer can be either raw or smart.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|InnerMatcher
operator|>
name|class
name|PointeeMatcher
block|{
name|public
operator|:
name|explicit
name|PointeeMatcher
argument_list|(
specifier|const
name|InnerMatcher
operator|&
name|matcher
argument_list|)
operator|:
name|matcher_
argument_list|(
argument|matcher
argument_list|)
block|{}
comment|// This type conversion operator template allows Pointee(m) to be
comment|// used as a matcher for any pointer type whose pointee type is
comment|// compatible with the inner matcher, where type Pointer can be
comment|// either a raw pointer or a smart pointer.
comment|//
comment|// The reason we do this instead of relying on
comment|// MakePolymorphicMatcher() is that the latter is not flexible
comment|// enough for implementing the DescribeTo() method of Pointee().
name|template
operator|<
name|typename
name|Pointer
operator|>
name|operator
name|Matcher
operator|<
name|Pointer
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new Impl<Pointer>(matcher_)
argument_list|)
return|;
block|}
name|private
operator|:
comment|// The monomorphic implementation that works for a particular pointer type.
name|template
operator|<
name|typename
name|Pointer
operator|>
name|class
name|Impl
operator|:
name|public
name|MatcherInterface
operator|<
name|Pointer
operator|>
block|{
name|public
operator|:
typedef|typedef
name|typename
name|PointeeOf
operator|<
name|GTEST_REMOVE_CONST_
argument_list|(
comment|// NOLINT
name|GTEST_REMOVE_REFERENCE_
argument_list|(
name|Pointer
argument_list|)
argument_list|)
operator|>
operator|::
name|type
name|Pointee
expr_stmt|;
name|explicit
name|Impl
argument_list|(
specifier|const
name|InnerMatcher
operator|&
name|matcher
argument_list|)
operator|:
name|matcher_
argument_list|(
argument|MatcherCast<const Pointee&>(matcher)
argument_list|)
block|{}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"points to a value that "
block|;
name|matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"does not point to a value that "
block|;
name|matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|Pointer pointer
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
if|if
condition|(
name|GetRawPointer
argument_list|(
name|pointer
argument_list|)
operator|==
name|NULL
condition|)
return|return
name|false
return|;
operator|*
name|listener
operator|<<
literal|"which points to "
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|MatchPrintAndExplain
argument_list|(
operator|*
name|pointer
argument_list|,
name|matcher_
argument_list|,
name|listener
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}     private:
specifier|const
name|Matcher
operator|<
specifier|const
name|Pointee
operator|&
operator|>
name|matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
specifier|const
name|InnerMatcher
name|matcher_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|PointeeMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements the WhenDynamicCastTo<T>(m) matcher that matches a pointer or
end_comment

begin_comment
comment|// reference that matches inner_matcher when dynamic_cast<T> is applied.
end_comment

begin_comment
comment|// The result of dynamic_cast<To> is forwarded to the inner matcher.
end_comment

begin_comment
comment|// If To is a pointer and the cast fails, the inner matcher will receive NULL.
end_comment

begin_comment
comment|// If To is a reference and the cast fails, this matcher returns false
end_comment

begin_comment
comment|// immediately.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|To
operator|>
name|class
name|WhenDynamicCastToMatcherBase
block|{
name|public
operator|:
name|explicit
name|WhenDynamicCastToMatcherBase
argument_list|(
specifier|const
name|Matcher
operator|<
name|To
operator|>
operator|&
name|matcher
argument_list|)
operator|:
name|matcher_
argument_list|(
argument|matcher
argument_list|)
block|{}
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
name|GetCastTypeDescription
argument_list|(
name|os
argument_list|)
block|;
name|matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;   }
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
name|GetCastTypeDescription
argument_list|(
name|os
argument_list|)
block|;
name|matcher_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;   }
name|protected
operator|:
specifier|const
name|Matcher
operator|<
name|To
operator|>
name|matcher_
block|;
specifier|static
name|string
name|GetToName
argument_list|()
block|{
if|#
directive|if
name|GTEST_HAS_RTTI
return|return
name|GetTypeName
operator|<
name|To
operator|>
operator|(
operator|)
return|;
else|#
directive|else
comment|// GTEST_HAS_RTTI
return|return
literal|"the target type"
return|;
endif|#
directive|endif
comment|// GTEST_HAS_RTTI
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|static
name|void
name|GetCastTypeDescription
argument_list|(
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
literal|"when dynamic_cast to "
operator|<<
name|GetToName
argument_list|()
operator|<<
literal|", "
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|WhenDynamicCastToMatcherBase
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Primary template.
end_comment

begin_comment
comment|// To is a pointer. Cast and forward the result.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|To
operator|>
name|class
name|WhenDynamicCastToMatcher
operator|:
name|public
name|WhenDynamicCastToMatcherBase
operator|<
name|To
operator|>
block|{
name|public
operator|:
name|explicit
name|WhenDynamicCastToMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|To
operator|>
operator|&
name|matcher
argument_list|)
operator|:
name|WhenDynamicCastToMatcherBase
operator|<
name|To
operator|>
operator|(
name|matcher
operator|)
block|{}
name|template
operator|<
name|typename
name|From
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|From from
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
comment|// TODO(sbenza): Add more detail on failures. ie did the dyn_cast fail?
name|To
name|to
operator|=
name|dynamic_cast
operator|<
name|To
operator|>
operator|(
name|from
operator|)
block|;
return|return
name|MatchPrintAndExplain
argument_list|(
name|to
argument_list|,
name|this
operator|->
name|matcher_
argument_list|,
name|listener
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Specialize for references.
end_comment

begin_comment
comment|// In this case we return false if the dynamic_cast fails.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|To
operator|>
name|class
name|WhenDynamicCastToMatcher
operator|<
name|To
operator|&
operator|>
operator|:
name|public
name|WhenDynamicCastToMatcherBase
operator|<
name|To
operator|&
operator|>
block|{
name|public
operator|:
name|explicit
name|WhenDynamicCastToMatcher
argument_list|(
specifier|const
name|Matcher
operator|<
name|To
operator|&
operator|>
operator|&
name|matcher
argument_list|)
operator|:
name|WhenDynamicCastToMatcherBase
operator|<
name|To
operator|&
operator|>
operator|(
name|matcher
operator|)
block|{}
name|template
operator|<
name|typename
name|From
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|From& from
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
comment|// We don't want an std::bad_cast here, so do the cast with pointers.
name|To
operator|*
name|to
operator|=
name|dynamic_cast
operator|<
name|To
operator|*
operator|>
operator|(
operator|&
name|from
operator|)
block|;
if|if
condition|(
name|to
operator|==
name|NULL
condition|)
block|{
operator|*
name|listener
operator|<<
literal|"which cannot be dynamic_cast to "
operator|<<
name|this
operator|->
name|GetToName
argument_list|()
expr_stmt|;
return|return
name|false
return|;
block|}
return|return
name|MatchPrintAndExplain
argument_list|(
operator|*
name|to
argument_list|,
name|this
operator|->
name|matcher_
argument_list|,
name|listener
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Implements the Field() matcher for matching a field (i.e. member
end_comment

begin_comment
comment|// variable) of an object.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Class
operator|,
name|typename
name|FieldType
operator|>
name|class
name|FieldMatcher
block|{
name|public
operator|:
name|FieldMatcher
argument_list|(
argument|FieldType Class::*field
argument_list|,
argument|const Matcher<const FieldType&>& matcher
argument_list|)
operator|:
name|field_
argument_list|(
name|field
argument_list|)
block|,
name|matcher_
argument_list|(
argument|matcher
argument_list|)
block|{}
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"is an object whose given field "
block|;
name|matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;   }
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"is an object whose given field "
block|;
name|matcher_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;   }
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|const T& value
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
return|return
name|MatchAndExplainImpl
argument_list|(
name|typename
operator|::
name|testing
operator|::
name|internal
operator|::
name|is_pointer
operator|<
name|GTEST_REMOVE_CONST_
argument_list|(
name|T
argument_list|)
operator|>
operator|::
name|type
argument_list|()
argument_list|,
name|value
argument_list|,
name|listener
argument_list|)
return|;
block|}
name|private
operator|:
comment|// The first argument of MatchAndExplainImpl() is needed to help
comment|// Symbian's C++ compiler choose which overload to use.  Its type is
comment|// true_type iff the Field() matcher is used to match a pointer.
name|bool
name|MatchAndExplainImpl
argument_list|(
argument|false_type
comment|/* is_not_pointer */
argument_list|,
argument|const Class& obj
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
operator|*
name|listener
operator|<<
literal|"whose given field is "
block|;
return|return
name|MatchPrintAndExplain
argument_list|(
name|obj
operator|.*
name|field_
argument_list|,
name|matcher_
argument_list|,
name|listener
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|bool
name|MatchAndExplainImpl
argument_list|(
name|true_type
comment|/* is_pointer */
argument_list|,
specifier|const
name|Class
operator|*
name|p
argument_list|,
name|MatchResultListener
operator|*
name|listener
argument_list|)
decl|const
block|{
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
return|return
name|false
return|;
operator|*
name|listener
operator|<<
literal|"which points to an object "
expr_stmt|;
comment|// Since *p has a field, it must be a class/struct/union type and
comment|// thus cannot be a pointer.  Therefore we pass false_type() as
comment|// the first argument.
return|return
name|MatchAndExplainImpl
argument_list|(
name|false_type
argument_list|()
argument_list|,
operator|*
name|p
argument_list|,
name|listener
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|const
name|FieldType
name|Class
operator|::
operator|*
name|field_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|Matcher
operator|<
specifier|const
name|FieldType
operator|&
operator|>
name|matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|FieldMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements the Property() matcher for matching a property
end_comment

begin_comment
comment|// (i.e. return value of a getter method) of an object.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Class
operator|,
name|typename
name|PropertyType
operator|>
name|class
name|PropertyMatcher
block|{
name|public
operator|:
comment|// The property may have a reference type, so 'const PropertyType&'
comment|// may cause double references and fail to compile.  That's why we
comment|// need GTEST_REFERENCE_TO_CONST, which works regardless of
comment|// PropertyType being a reference or not.
typedef|typedef
name|GTEST_REFERENCE_TO_CONST_
argument_list|(
argument|PropertyType
argument_list|)
name|RefToConstProperty
expr_stmt|;
name|PropertyMatcher
argument_list|(
name|PropertyType
argument_list|(
argument|Class::*property
argument_list|)
operator|(
operator|)
specifier|const
argument_list|,
specifier|const
name|Matcher
operator|<
name|RefToConstProperty
operator|>
operator|&
name|matcher
argument_list|)
operator|:
name|property_
argument_list|(
name|property
argument_list|)
operator|,
name|matcher_
argument_list|(
argument|matcher
argument_list|)
block|{}
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"is an object whose given property "
block|;
name|matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;   }
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"is an object whose given property "
block|;
name|matcher_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;   }
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|const T&value
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
return|return
name|MatchAndExplainImpl
argument_list|(
name|typename
operator|::
name|testing
operator|::
name|internal
operator|::
name|is_pointer
operator|<
name|GTEST_REMOVE_CONST_
argument_list|(
name|T
argument_list|)
operator|>
operator|::
name|type
argument_list|()
argument_list|,
name|value
argument_list|,
name|listener
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// The first argument of MatchAndExplainImpl() is needed to help
end_comment

begin_comment
comment|// Symbian's C++ compiler choose which overload to use.  Its type is
end_comment

begin_comment
comment|// true_type iff the Property() matcher is used to match a pointer.
end_comment

begin_decl_stmt
name|bool
name|MatchAndExplainImpl
argument_list|(
name|false_type
comment|/* is_not_pointer */
argument_list|,
specifier|const
name|Class
operator|&
name|obj
argument_list|,
name|MatchResultListener
operator|*
name|listener
argument_list|)
decl|const
block|{
operator|*
name|listener
operator|<<
literal|"whose given property is "
expr_stmt|;
comment|// Cannot pass the return value (for example, int) to MatchPrintAndExplain,
comment|// which takes a non-const reference as argument.
if|#
directive|if
name|defined
argument_list|(
name|_PREFAST_
argument_list|)
operator|&&
name|_MSC_VER
operator|==
literal|1800
comment|// Workaround bug in VC++ 2013's /analyze parser.
comment|// https://connect.microsoft.com/VisualStudio/feedback/details/1106363/internal-compiler-error-with-analyze-due-to-failure-to-infer-move
name|posix
operator|::
name|Abort
argument_list|()
expr_stmt|;
comment|// To make sure it is never run.
return|return
name|false
return|;
else|#
directive|else
name|RefToConstProperty
name|result
init|=
operator|(
name|obj
operator|.*
name|property_
operator|)
operator|(
operator|)
decl_stmt|;
return|return
name|MatchPrintAndExplain
argument_list|(
name|result
argument_list|,
name|matcher_
argument_list|,
name|listener
argument_list|)
return|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_decl_stmt
name|bool
name|MatchAndExplainImpl
argument_list|(
name|true_type
comment|/* is_pointer */
argument_list|,
specifier|const
name|Class
operator|*
name|p
argument_list|,
name|MatchResultListener
operator|*
name|listener
argument_list|)
decl|const
block|{
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
return|return
name|false
return|;
operator|*
name|listener
operator|<<
literal|"which points to an object "
expr_stmt|;
comment|// Since *p has a property method, it must be a class/struct/union
comment|// type and thus cannot be a pointer.  Therefore we pass
comment|// false_type() as the first argument.
return|return
name|MatchAndExplainImpl
argument_list|(
name|false_type
argument_list|()
argument_list|,
operator|*
name|p
argument_list|,
name|listener
argument_list|)
return|;
block|}
end_decl_stmt

begin_macro
name|PropertyType
argument_list|(
argument|Class::*property_
argument_list|)
end_macro

begin_expr_stmt
operator|(
operator|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|Matcher
operator|<
name|RefToConstProperty
operator|>
name|matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|PropertyMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Type traits specifying various features of different functors for ResultOf.
end_comment

begin_comment
comment|// The default template specifies features for functor objects.
end_comment

begin_comment
comment|// Functor classes have to typedef argument_type and result_type
end_comment

begin_comment
comment|// to be compatible with ResultOf.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Functor
operator|>
expr|struct
name|CallableTraits
block|{
typedef|typedef
name|typename
name|Functor
operator|::
name|result_type
name|ResultType
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|Functor
name|StorageType
typedef|;
end_typedef

begin_function
specifier|static
name|void
name|CheckIsValid
parameter_list|(
name|Functor
comment|/* functor */
parameter_list|)
block|{}
end_function

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|ResultType
name|Invoke
argument_list|(
argument|Functor f
argument_list|,
argument|T arg
argument_list|)
block|{
return|return
name|f
argument_list|(
name|arg
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Specialization for function pointers.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ArgType
operator|,
name|typename
name|ResType
operator|>
expr|struct
name|CallableTraits
operator|<
name|ResType
argument_list|(
operator|*
argument_list|)
argument_list|(
name|ArgType
argument_list|)
operator|>
block|{
typedef|typedef
name|ResType
name|ResultType
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|ResType
function_decl|(
modifier|*
name|StorageType
function_decl|)
parameter_list|(
name|ArgType
parameter_list|)
function_decl|;
end_typedef

begin_function
specifier|static
name|void
name|CheckIsValid
parameter_list|(
name|ResType
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|ArgType
parameter_list|)
parameter_list|)
block|{
name|GTEST_CHECK_
argument_list|(
name|f
operator|!=
name|NULL
argument_list|)
operator|<<
literal|"NULL function pointer is passed into ResultOf()."
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|ResType
name|Invoke
argument_list|(
argument|ResType(*f)(ArgType)
argument_list|,
argument|T arg
argument_list|)
block|{
return|return
call|(
modifier|*
name|f
call|)
argument_list|(
name|arg
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Implements the ResultOf() matcher for matching a return value of a
end_comment

begin_comment
comment|// unary function of an object.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Callable
operator|>
name|class
name|ResultOfMatcher
block|{
name|public
operator|:
typedef|typedef
name|typename
name|CallableTraits
operator|<
name|Callable
operator|>
operator|::
name|ResultType
name|ResultType
expr_stmt|;
name|ResultOfMatcher
argument_list|(
argument|Callable callable
argument_list|,
argument|const Matcher<ResultType>& matcher
argument_list|)
operator|:
name|callable_
argument_list|(
name|callable
argument_list|)
operator|,
name|matcher_
argument_list|(
argument|matcher
argument_list|)
block|{
name|CallableTraits
operator|<
name|Callable
operator|>
operator|::
name|CheckIsValid
argument_list|(
name|callable_
argument_list|)
block|;   }
name|template
operator|<
name|typename
name|T
operator|>
name|operator
name|Matcher
operator|<
name|T
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|Matcher
operator|<
name|T
operator|>
operator|(
name|new
name|Impl
operator|<
name|T
operator|>
operator|(
name|callable_
operator|,
name|matcher_
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_typedef
typedef|typedef
name|typename
name|CallableTraits
operator|<
name|Callable
operator|>
operator|::
name|StorageType
name|CallableStorageType
expr_stmt|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Impl
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|Impl
argument_list|(
argument|CallableStorageType callable
argument_list|,
argument|const Matcher<ResultType>& matcher
argument_list|)
operator|:
name|callable_
argument_list|(
name|callable
argument_list|)
block|,
name|matcher_
argument_list|(
argument|matcher
argument_list|)
block|{}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"is mapped by the given callable to a value that "
block|;
name|matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"is mapped by the given callable to a value that "
block|;
name|matcher_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|T obj
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
operator|*
name|listener
operator|<<
literal|"which is mapped by the given callable to "
block|;
comment|// Cannot pass the return value (for example, int) to
comment|// MatchPrintAndExplain, which takes a non-const reference as argument.
name|ResultType
name|result
operator|=
name|CallableTraits
operator|<
name|Callable
operator|>
operator|::
name|template
name|Invoke
operator|<
name|T
operator|>
operator|(
name|callable_
operator|,
name|obj
operator|)
block|;
return|return
name|MatchPrintAndExplain
argument_list|(
name|result
argument_list|,
name|matcher_
argument_list|,
name|listener
argument_list|)
return|;
block|}
name|private
operator|:
comment|// Functors often define operator() as non-const method even though
comment|// they are actualy stateless. But we need to use them even when
comment|// 'this' is a const pointer. It's the user's responsibility not to
comment|// use stateful callables with ResultOf(), which does't guarantee
comment|// how many times the callable will be invoked.
name|mutable
name|CallableStorageType
name|callable_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|Matcher
operator|<
name|ResultType
operator|>
name|matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// class Impl
end_comment

begin_decl_stmt
specifier|const
name|CallableStorageType
name|callable_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|Matcher
operator|<
name|ResultType
operator|>
name|matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|ResultOfMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements a matcher that checks the size of an STL-style container.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|SizeMatcher
operator|>
name|class
name|SizeIsMatcher
block|{
name|public
operator|:
name|explicit
name|SizeIsMatcher
argument_list|(
specifier|const
name|SizeMatcher
operator|&
name|size_matcher
argument_list|)
operator|:
name|size_matcher_
argument_list|(
argument|size_matcher
argument_list|)
block|{   }
name|template
operator|<
name|typename
name|Container
operator|>
name|operator
name|Matcher
operator|<
name|Container
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new Impl<Container>(size_matcher_)
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|Container
operator|>
name|class
name|Impl
operator|:
name|public
name|MatcherInterface
operator|<
name|Container
operator|>
block|{
name|public
operator|:
typedef|typedef
name|internal
operator|::
name|StlContainerView
operator|<
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
name|Container
argument_list|)
operator|>
name|ContainerView
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|ContainerView
operator|::
name|type
operator|::
name|size_type
name|SizeType
expr_stmt|;
end_typedef

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|Impl
argument_list|(
specifier|const
name|SizeMatcher
operator|&
name|size_matcher
argument_list|)
operator|:
name|size_matcher_
argument_list|(
argument|MatcherCast<SizeType>(size_matcher)
argument_list|)
block|{}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"size "
block|;
name|size_matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"size "
block|;
name|size_matcher_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|Container container
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
name|SizeType
name|size
operator|=
name|container
operator|.
name|size
argument_list|()
block|;
name|StringMatchResultListener
name|size_listener
block|;
specifier|const
name|bool
name|result
operator|=
name|size_matcher_
operator|.
name|MatchAndExplain
argument_list|(
name|size
argument_list|,
operator|&
name|size_listener
argument_list|)
block|;
operator|*
name|listener
operator|<<
literal|"whose size "
operator|<<
name|size
operator|<<
operator|(
name|result
condition|?
literal|" matches"
else|:
literal|" doesn't match"
operator|)
block|;
name|PrintIfNotEmpty
argument_list|(
name|size_listener
operator|.
name|str
argument_list|()
argument_list|,
name|listener
operator|->
name|stream
argument_list|()
argument_list|)
block|;
return|return
name|result
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|Matcher
operator|<
name|SizeType
operator|>
name|size_matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
unit|};
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|SizeMatcher
name|size_matcher_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|SizeIsMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements a matcher that checks the begin()..end() distance of an STL-style
end_comment

begin_comment
comment|// container.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|DistanceMatcher
operator|>
name|class
name|BeginEndDistanceIsMatcher
block|{
name|public
operator|:
name|explicit
name|BeginEndDistanceIsMatcher
argument_list|(
specifier|const
name|DistanceMatcher
operator|&
name|distance_matcher
argument_list|)
operator|:
name|distance_matcher_
argument_list|(
argument|distance_matcher
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Container
operator|>
name|operator
name|Matcher
operator|<
name|Container
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new Impl<Container>(distance_matcher_)
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|Container
operator|>
name|class
name|Impl
operator|:
name|public
name|MatcherInterface
operator|<
name|Container
operator|>
block|{
name|public
operator|:
typedef|typedef
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
argument|Container
argument_list|)
name|RawContainer
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|internal
operator|::
name|StlContainerView
operator|<
name|RawContainer
operator|>
name|View
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|View
operator|::
name|type
name|StlContainer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|View
operator|::
name|const_reference
name|StlContainerReference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|decltype
argument_list|(
argument|std::begin(         std::declval<StlContainerReference>())
argument_list|)
name|StlContainerConstIterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|StlContainerConstIterator
operator|>
operator|::
name|difference_type
name|DistanceType
expr_stmt|;
end_typedef

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|Impl
argument_list|(
specifier|const
name|DistanceMatcher
operator|&
name|distance_matcher
argument_list|)
operator|:
name|distance_matcher_
argument_list|(
argument|MatcherCast<DistanceType>(distance_matcher)
argument_list|)
block|{}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"distance between begin() and end() "
block|;
name|distance_matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"distance between begin() and end() "
block|;
name|distance_matcher_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|Container container
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
if|#
directive|if
name|GTEST_HAS_STD_BEGIN_AND_END_
name|using
name|std
operator|::
name|begin
block|;
name|using
name|std
operator|::
name|end
block|;
name|DistanceType
name|distance
operator|=
name|std
operator|::
name|distance
argument_list|(
name|begin
argument_list|(
name|container
argument_list|)
argument_list|,
name|end
argument_list|(
name|container
argument_list|)
argument_list|)
block|;
else|#
directive|else
name|DistanceType
name|distance
operator|=
name|std
operator|::
name|distance
argument_list|(
name|container
operator|.
name|begin
argument_list|()
argument_list|,
name|container
operator|.
name|end
argument_list|()
argument_list|)
block|;
endif|#
directive|endif
name|StringMatchResultListener
name|distance_listener
block|;
specifier|const
name|bool
name|result
operator|=
name|distance_matcher_
operator|.
name|MatchAndExplain
argument_list|(
name|distance
argument_list|,
operator|&
name|distance_listener
argument_list|)
block|;
operator|*
name|listener
operator|<<
literal|"whose distance between begin() and end() "
operator|<<
name|distance
operator|<<
operator|(
name|result
condition|?
literal|" matches"
else|:
literal|" doesn't match"
operator|)
block|;
name|PrintIfNotEmpty
argument_list|(
name|distance_listener
operator|.
name|str
argument_list|()
argument_list|,
name|listener
operator|->
name|stream
argument_list|()
argument_list|)
block|;
return|return
name|result
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|Matcher
operator|<
name|DistanceType
operator|>
name|distance_matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
unit|};
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|DistanceMatcher
name|distance_matcher_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|BeginEndDistanceIsMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements an equality matcher for any STL-style container whose elements
end_comment

begin_comment
comment|// support ==. This matcher is like Eq(), but its failure explanations provide
end_comment

begin_comment
comment|// more detailed information that is useful when the container is used as a set.
end_comment

begin_comment
comment|// The failure message reports elements that are in one of the operands but not
end_comment

begin_comment
comment|// the other. The failure messages do not report duplicate or out-of-order
end_comment

begin_comment
comment|// elements in the containers (which don't properly matter to sets, but can
end_comment

begin_comment
comment|// occur if the containers are vectors or lists, for example).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Uses the container's const_iterator, value_type, operator ==,
end_comment

begin_comment
comment|// begin(), and end().
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Container
operator|>
name|class
name|ContainerEqMatcher
block|{
name|public
operator|:
typedef|typedef
name|internal
operator|::
name|StlContainerView
operator|<
name|Container
operator|>
name|View
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|View
operator|::
name|type
name|StlContainer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|View
operator|::
name|const_reference
name|StlContainerReference
expr_stmt|;
end_typedef

begin_comment
comment|// We make a copy of expected in case the elements in it are modified
end_comment

begin_comment
comment|// after this matcher is created.
end_comment

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|ContainerEqMatcher
argument_list|(
specifier|const
name|Container
operator|&
name|expected
argument_list|)
operator|:
name|expected_
argument_list|(
argument|View::Copy(expected)
argument_list|)
block|{
comment|// Makes sure the user doesn't instantiate this class template
comment|// with a const or reference type.
operator|(
name|void
operator|)
name|testing
operator|::
name|StaticAssertTypeEq
operator|<
name|Container
block|,
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
name|Container
argument_list|)
operator|>
operator|(
operator|)
block|;   }
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"equals "
block|;
name|UniversalPrint
argument_list|(
name|expected_
argument_list|,
name|os
argument_list|)
block|;   }
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"does not equal "
block|;
name|UniversalPrint
argument_list|(
name|expected_
argument_list|,
name|os
argument_list|)
block|;   }
name|template
operator|<
name|typename
name|LhsContainer
operator|>
name|bool
name|MatchAndExplain
argument_list|(
argument|const LhsContainer& lhs
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
comment|// GTEST_REMOVE_CONST_() is needed to work around an MSVC 8.0 bug
comment|// that causes LhsContainer to be a const type sometimes.
typedef|typedef
name|internal
operator|::
name|StlContainerView
operator|<
name|GTEST_REMOVE_CONST_
argument_list|(
name|LhsContainer
argument_list|)
operator|>
name|LhsView
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|LhsView
operator|::
name|type
name|LhsStlContainer
expr_stmt|;
end_typedef

begin_decl_stmt
name|StlContainerReference
name|lhs_stl_container
init|=
name|LhsView
operator|::
name|ConstReference
argument_list|(
name|lhs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|lhs_stl_container
operator|==
name|expected_
condition|)
return|return
name|true
return|;
end_if

begin_expr_stmt
operator|::
name|std
operator|::
name|ostream
operator|*
specifier|const
name|os
operator|=
name|listener
operator|->
name|stream
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|os
operator|!=
name|NULL
condition|)
block|{
comment|// Something is different. Check for extra values first.
name|bool
name|printed_header
init|=
name|false
decl_stmt|;
for|for
control|(
name|typename
name|LhsStlContainer
operator|::
name|const_iterator
name|it
operator|=
name|lhs_stl_container
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|lhs_stl_container
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
name|internal
operator|::
name|ArrayAwareFind
argument_list|(
name|expected_
operator|.
name|begin
argument_list|()
argument_list|,
name|expected_
operator|.
name|end
argument_list|()
argument_list|,
operator|*
name|it
argument_list|)
operator|==
name|expected_
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
name|printed_header
condition|)
block|{
operator|*
name|os
operator|<<
literal|", "
expr_stmt|;
block|}
else|else
block|{
operator|*
name|os
operator|<<
literal|"which has these unexpected elements: "
expr_stmt|;
name|printed_header
operator|=
name|true
expr_stmt|;
block|}
name|UniversalPrint
argument_list|(
operator|*
name|it
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Now check for missing values.
name|bool
name|printed_header2
init|=
name|false
decl_stmt|;
for|for
control|(
name|typename
name|StlContainer
operator|::
name|const_iterator
name|it
operator|=
name|expected_
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|expected_
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
name|internal
operator|::
name|ArrayAwareFind
argument_list|(
name|lhs_stl_container
operator|.
name|begin
argument_list|()
argument_list|,
name|lhs_stl_container
operator|.
name|end
argument_list|()
argument_list|,
operator|*
name|it
argument_list|)
operator|==
name|lhs_stl_container
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
name|printed_header2
condition|)
block|{
operator|*
name|os
operator|<<
literal|", "
expr_stmt|;
block|}
else|else
block|{
operator|*
name|os
operator|<<
operator|(
name|printed_header
condition|?
literal|",\nand"
else|:
literal|"which"
operator|)
operator|<<
literal|" doesn't have these expected elements: "
expr_stmt|;
name|printed_header2
operator|=
name|true
expr_stmt|;
block|}
name|UniversalPrint
argument_list|(
operator|*
name|it
argument_list|,
name|os
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_if

begin_return
return|return
name|false
return|;
end_return

begin_decl_stmt
unit|}   private:
specifier|const
name|StlContainer
name|expected_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|ContainerEqMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// A comparator functor that uses the< operator to compare two values.
end_comment

begin_struct
struct|struct
name|LessComparator
block|{
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|T
operator|&
name|lhs
operator|,
specifier|const
name|U
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|lhs
operator|<
name|rhs
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|// Implements WhenSortedBy(comparator, container_matcher).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Comparator
operator|,
name|typename
name|ContainerMatcher
operator|>
name|class
name|WhenSortedByMatcher
block|{
name|public
operator|:
name|WhenSortedByMatcher
argument_list|(
specifier|const
name|Comparator
operator|&
name|comparator
argument_list|,
specifier|const
name|ContainerMatcher
operator|&
name|matcher
argument_list|)
operator|:
name|comparator_
argument_list|(
name|comparator
argument_list|)
block|,
name|matcher_
argument_list|(
argument|matcher
argument_list|)
block|{}
name|template
operator|<
name|typename
name|LhsContainer
operator|>
name|operator
name|Matcher
operator|<
name|LhsContainer
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new Impl<LhsContainer>(comparator_, matcher_)
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|LhsContainer
operator|>
name|class
name|Impl
operator|:
name|public
name|MatcherInterface
operator|<
name|LhsContainer
operator|>
block|{
name|public
operator|:
typedef|typedef
name|internal
operator|::
name|StlContainerView
operator|<
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
name|LhsContainer
argument_list|)
operator|>
name|LhsView
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|LhsView
operator|::
name|type
name|LhsStlContainer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|LhsView
operator|::
name|const_reference
name|LhsStlContainerReference
expr_stmt|;
end_typedef

begin_comment
comment|// Transforms std::pair<const Key, Value> into std::pair<Key, Value>
end_comment

begin_comment
comment|// so that we can match associative containers.
end_comment

begin_typedef
typedef|typedef
name|typename
name|RemoveConstFromKey
operator|<
name|typename
name|LhsStlContainer
operator|::
name|value_type
operator|>
operator|::
name|type
name|LhsValue
expr_stmt|;
end_typedef

begin_expr_stmt
name|Impl
argument_list|(
specifier|const
name|Comparator
operator|&
name|comparator
argument_list|,
specifier|const
name|ContainerMatcher
operator|&
name|matcher
argument_list|)
operator|:
name|comparator_
argument_list|(
name|comparator
argument_list|)
operator|,
name|matcher_
argument_list|(
argument|matcher
argument_list|)
block|{}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"(when sorted) "
block|;
name|matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"(when sorted) "
block|;
name|matcher_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|LhsContainer lhs
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
name|LhsStlContainerReference
name|lhs_stl_container
operator|=
name|LhsView
operator|::
name|ConstReference
argument_list|(
name|lhs
argument_list|)
block|;
operator|::
name|std
operator|::
name|vector
operator|<
name|LhsValue
operator|>
name|sorted_container
argument_list|(
name|lhs_stl_container
operator|.
name|begin
argument_list|()
argument_list|,
name|lhs_stl_container
operator|.
name|end
argument_list|()
argument_list|)
block|;
operator|::
name|std
operator|::
name|sort
argument_list|(
name|sorted_container
operator|.
name|begin
argument_list|()
argument_list|,
name|sorted_container
operator|.
name|end
argument_list|()
argument_list|,
name|comparator_
argument_list|)
block|;
if|if
condition|(
operator|!
name|listener
operator|->
name|IsInterested
argument_list|()
condition|)
block|{
comment|// If the listener is not interested, we do not need to
comment|// construct the inner explanation.
return|return
name|matcher_
operator|.
name|Matches
argument_list|(
name|sorted_container
argument_list|)
return|;
block|}
operator|*
name|listener
operator|<<
literal|"which is "
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|UniversalPrint
argument_list|(
name|sorted_container
argument_list|,
name|listener
operator|->
name|stream
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|listener
operator|<<
literal|" when sorted"
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|StringMatchResultListener
name|inner_listener
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bool
name|match
init|=
name|matcher_
operator|.
name|MatchAndExplain
argument_list|(
name|sorted_container
argument_list|,
operator|&
name|inner_listener
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|PrintIfNotEmpty
argument_list|(
name|inner_listener
operator|.
name|str
argument_list|()
argument_list|,
name|listener
operator|->
name|stream
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|match
return|;
end_return

begin_decl_stmt
unit|}     private:
specifier|const
name|Comparator
name|comparator_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|Matcher
operator|<
specifier|const
operator|::
name|std
operator|::
name|vector
operator|<
name|LhsValue
operator|>
operator|&
operator|>
name|matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
unit|};
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|Comparator
name|comparator_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|ContainerMatcher
name|matcher_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|WhenSortedByMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements Pointwise(tuple_matcher, rhs_container).  tuple_matcher
end_comment

begin_comment
comment|// must be able to be safely cast to Matcher<tuple<const T1&, const
end_comment

begin_comment
comment|// T2&>>, where T1 and T2 are the types of elements in the LHS
end_comment

begin_comment
comment|// container and the RHS container respectively.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|TupleMatcher
operator|,
name|typename
name|RhsContainer
operator|>
name|class
name|PointwiseMatcher
block|{
name|public
operator|:
typedef|typedef
name|internal
operator|::
name|StlContainerView
operator|<
name|RhsContainer
operator|>
name|RhsView
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|RhsView
operator|::
name|type
name|RhsStlContainer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|RhsStlContainer
operator|::
name|value_type
name|RhsValue
expr_stmt|;
end_typedef

begin_comment
comment|// Like ContainerEq, we make a copy of rhs in case the elements in
end_comment

begin_comment
comment|// it are modified after this matcher is created.
end_comment

begin_expr_stmt
name|PointwiseMatcher
argument_list|(
specifier|const
name|TupleMatcher
operator|&
name|tuple_matcher
argument_list|,
specifier|const
name|RhsContainer
operator|&
name|rhs
argument_list|)
operator|:
name|tuple_matcher_
argument_list|(
name|tuple_matcher
argument_list|)
operator|,
name|rhs_
argument_list|(
argument|RhsView::Copy(rhs)
argument_list|)
block|{
comment|// Makes sure the user doesn't instantiate this class template
comment|// with a const or reference type.
operator|(
name|void
operator|)
name|testing
operator|::
name|StaticAssertTypeEq
operator|<
name|RhsContainer
block|,
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
name|RhsContainer
argument_list|)
operator|>
operator|(
operator|)
block|;   }
name|template
operator|<
name|typename
name|LhsContainer
operator|>
name|operator
name|Matcher
operator|<
name|LhsContainer
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new Impl<LhsContainer>(tuple_matcher_, rhs_)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|LhsContainer
operator|>
name|class
name|Impl
operator|:
name|public
name|MatcherInterface
operator|<
name|LhsContainer
operator|>
block|{
name|public
operator|:
typedef|typedef
name|internal
operator|::
name|StlContainerView
operator|<
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
name|LhsContainer
argument_list|)
operator|>
name|LhsView
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|LhsView
operator|::
name|type
name|LhsStlContainer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|LhsView
operator|::
name|const_reference
name|LhsStlContainerReference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|LhsStlContainer
operator|::
name|value_type
name|LhsValue
expr_stmt|;
end_typedef

begin_comment
comment|// We pass the LHS value and the RHS value to the inner matcher by
end_comment

begin_comment
comment|// reference, as they may be expensive to copy.  We must use tuple
end_comment

begin_comment
comment|// instead of pair here, as a pair cannot hold references (C++ 98,
end_comment

begin_comment
comment|// 20.2.2 [lib.pairs]).
end_comment

begin_typedef
typedef|typedef
operator|::
name|testing
operator|::
name|tuple
operator|<
specifier|const
name|LhsValue
operator|&
operator|,
specifier|const
name|RhsValue
operator|&
operator|>
name|InnerMatcherArg
expr_stmt|;
end_typedef

begin_expr_stmt
name|Impl
argument_list|(
specifier|const
name|TupleMatcher
operator|&
name|tuple_matcher
argument_list|,
specifier|const
name|RhsStlContainer
operator|&
name|rhs
argument_list|)
comment|// mono_tuple_matcher_ holds a monomorphic version of the tuple matcher.
operator|:
name|mono_tuple_matcher_
argument_list|(
name|SafeMatcherCast
operator|<
name|InnerMatcherArg
operator|>
operator|(
name|tuple_matcher
operator|)
argument_list|)
operator|,
name|rhs_
argument_list|(
argument|rhs
argument_list|)
block|{}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"contains "
operator|<<
name|rhs_
operator|.
name|size
argument_list|()
operator|<<
literal|" values, where each value and its corresponding value in "
block|;
name|UniversalPrinter
operator|<
name|RhsStlContainer
operator|>
operator|::
name|Print
argument_list|(
name|rhs_
argument_list|,
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|" "
block|;
name|mono_tuple_matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"doesn't contain exactly "
operator|<<
name|rhs_
operator|.
name|size
argument_list|()
operator|<<
literal|" values, or contains a value x at some index i"
operator|<<
literal|" where x and the i-th value of "
block|;
name|UniversalPrint
argument_list|(
name|rhs_
argument_list|,
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|" "
block|;
name|mono_tuple_matcher_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|LhsContainer lhs
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
name|LhsStlContainerReference
name|lhs_stl_container
operator|=
name|LhsView
operator|::
name|ConstReference
argument_list|(
name|lhs
argument_list|)
block|;
specifier|const
name|size_t
name|actual_size
operator|=
name|lhs_stl_container
operator|.
name|size
argument_list|()
block|;
if|if
condition|(
name|actual_size
operator|!=
name|rhs_
operator|.
name|size
argument_list|()
condition|)
block|{
operator|*
name|listener
operator|<<
literal|"which contains "
operator|<<
name|actual_size
operator|<<
literal|" values"
expr_stmt|;
return|return
name|false
return|;
block|}
name|typename
name|LhsStlContainer
operator|::
name|const_iterator
name|left
operator|=
name|lhs_stl_container
operator|.
name|begin
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|typename
name|RhsStlContainer
operator|::
name|const_iterator
name|right
operator|=
name|rhs_
operator|.
name|begin
argument_list|()
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|actual_size
condition|;
operator|++
name|i
operator|,
operator|++
name|left
operator|,
operator|++
name|right
control|)
block|{
specifier|const
name|InnerMatcherArg
name|value_pair
argument_list|(
operator|*
name|left
argument_list|,
operator|*
name|right
argument_list|)
decl_stmt|;
if|if
condition|(
name|listener
operator|->
name|IsInterested
argument_list|()
condition|)
block|{
name|StringMatchResultListener
name|inner_listener
decl_stmt|;
if|if
condition|(
operator|!
name|mono_tuple_matcher_
operator|.
name|MatchAndExplain
argument_list|(
name|value_pair
argument_list|,
operator|&
name|inner_listener
argument_list|)
condition|)
block|{
operator|*
name|listener
operator|<<
literal|"where the value pair ("
expr_stmt|;
name|UniversalPrint
argument_list|(
operator|*
name|left
argument_list|,
name|listener
operator|->
name|stream
argument_list|()
argument_list|)
expr_stmt|;
operator|*
name|listener
operator|<<
literal|", "
expr_stmt|;
name|UniversalPrint
argument_list|(
operator|*
name|right
argument_list|,
name|listener
operator|->
name|stream
argument_list|()
argument_list|)
expr_stmt|;
operator|*
name|listener
operator|<<
literal|") at index #"
operator|<<
name|i
operator|<<
literal|" don't match"
expr_stmt|;
name|PrintIfNotEmpty
argument_list|(
name|inner_listener
operator|.
name|str
argument_list|()
argument_list|,
name|listener
operator|->
name|stream
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
block|}
else|else
block|{
if|if
condition|(
operator|!
name|mono_tuple_matcher_
operator|.
name|Matches
argument_list|(
name|value_pair
argument_list|)
condition|)
return|return
name|false
return|;
block|}
block|}
end_for

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}     private:
specifier|const
name|Matcher
operator|<
name|InnerMatcherArg
operator|>
name|mono_tuple_matcher_
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|RhsStlContainer
name|rhs_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
unit|};
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|TupleMatcher
name|tuple_matcher_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|RhsStlContainer
name|rhs_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|PointwiseMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Holds the logic common to ContainsMatcherImpl and EachMatcherImpl.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Container
operator|>
name|class
name|QuantifierMatcherImpl
operator|:
name|public
name|MatcherInterface
operator|<
name|Container
operator|>
block|{
name|public
operator|:
typedef|typedef
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
argument|Container
argument_list|)
name|RawContainer
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|StlContainerView
operator|<
name|RawContainer
operator|>
name|View
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|View
operator|::
name|type
name|StlContainer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|View
operator|::
name|const_reference
name|StlContainerReference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|StlContainer
operator|::
name|value_type
name|Element
expr_stmt|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
name|InnerMatcher
operator|>
name|explicit
name|QuantifierMatcherImpl
argument_list|(
argument|InnerMatcher inner_matcher
argument_list|)
operator|:
name|inner_matcher_
argument_list|(
argument|testing::SafeMatcherCast<const Element&>(inner_matcher)
argument_list|)
block|{}
comment|// Checks whether:
comment|// * All elements in the container match, if all_elements_should_match.
comment|// * Any element in the container matches, if !all_elements_should_match.
name|bool
name|MatchAndExplainImpl
argument_list|(
argument|bool all_elements_should_match
argument_list|,
argument|Container container
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
name|StlContainerReference
name|stl_container
operator|=
name|View
operator|::
name|ConstReference
argument_list|(
name|container
argument_list|)
block|;
name|size_t
name|i
operator|=
literal|0
block|;
for|for
control|(
name|typename
name|StlContainer
operator|::
name|const_iterator
name|it
operator|=
name|stl_container
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|stl_container
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
operator|,
operator|++
name|i
control|)
block|{
name|StringMatchResultListener
name|inner_listener
decl_stmt|;
specifier|const
name|bool
name|matches
init|=
name|inner_matcher_
operator|.
name|MatchAndExplain
argument_list|(
operator|*
name|it
argument_list|,
operator|&
name|inner_listener
argument_list|)
decl_stmt|;
if|if
condition|(
name|matches
operator|!=
name|all_elements_should_match
condition|)
block|{
operator|*
name|listener
operator|<<
literal|"whose element #"
operator|<<
name|i
operator|<<
operator|(
name|matches
condition|?
literal|" matches"
else|:
literal|" doesn't match"
operator|)
expr_stmt|;
name|PrintIfNotEmpty
argument_list|(
name|inner_listener
operator|.
name|str
argument_list|()
argument_list|,
name|listener
operator|->
name|stream
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|!
name|all_elements_should_match
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}     return
name|all_elements_should_match
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}   protected:
specifier|const
name|Matcher
operator|<
specifier|const
name|Element
operator|&
operator|>
name|inner_matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|QuantifierMatcherImpl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements Contains(element_matcher) for the given argument type Container.
end_comment

begin_comment
comment|// Symmetric to EachMatcherImpl.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Container
operator|>
name|class
name|ContainsMatcherImpl
operator|:
name|public
name|QuantifierMatcherImpl
operator|<
name|Container
operator|>
block|{
name|public
operator|:
name|template
operator|<
name|typename
name|InnerMatcher
operator|>
name|explicit
name|ContainsMatcherImpl
argument_list|(
argument|InnerMatcher inner_matcher
argument_list|)
operator|:
name|QuantifierMatcherImpl
operator|<
name|Container
operator|>
operator|(
name|inner_matcher
operator|)
block|{}
comment|// Describes what this matcher does.
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"contains at least one element that "
block|;
name|this
operator|->
name|inner_matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;   }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"doesn't contain any element that "
block|;
name|this
operator|->
name|inner_matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;   }
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|Container container
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|MatchAndExplainImpl
argument_list|(
name|false
argument_list|,
name|container
argument_list|,
name|listener
argument_list|)
return|;
block|}
name|private
operator|:
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|ContainsMatcherImpl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements Each(element_matcher) for the given argument type Container.
end_comment

begin_comment
comment|// Symmetric to ContainsMatcherImpl.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Container
operator|>
name|class
name|EachMatcherImpl
operator|:
name|public
name|QuantifierMatcherImpl
operator|<
name|Container
operator|>
block|{
name|public
operator|:
name|template
operator|<
name|typename
name|InnerMatcher
operator|>
name|explicit
name|EachMatcherImpl
argument_list|(
argument|InnerMatcher inner_matcher
argument_list|)
operator|:
name|QuantifierMatcherImpl
operator|<
name|Container
operator|>
operator|(
name|inner_matcher
operator|)
block|{}
comment|// Describes what this matcher does.
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"only contains elements that "
block|;
name|this
operator|->
name|inner_matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;   }
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"contains some element that "
block|;
name|this
operator|->
name|inner_matcher_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;   }
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|Container container
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|MatchAndExplainImpl
argument_list|(
name|true
argument_list|,
name|container
argument_list|,
name|listener
argument_list|)
return|;
block|}
name|private
operator|:
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|EachMatcherImpl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements polymorphic Contains(element_matcher).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|M
operator|>
name|class
name|ContainsMatcher
block|{
name|public
operator|:
name|explicit
name|ContainsMatcher
argument_list|(
argument|M m
argument_list|)
operator|:
name|inner_matcher_
argument_list|(
argument|m
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Container
operator|>
name|operator
name|Matcher
operator|<
name|Container
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new ContainsMatcherImpl<Container>(inner_matcher_)
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|M
name|inner_matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|ContainsMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements polymorphic Each(element_matcher).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|M
operator|>
name|class
name|EachMatcher
block|{
name|public
operator|:
name|explicit
name|EachMatcher
argument_list|(
argument|M m
argument_list|)
operator|:
name|inner_matcher_
argument_list|(
argument|m
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Container
operator|>
name|operator
name|Matcher
operator|<
name|Container
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new EachMatcherImpl<Container>(inner_matcher_)
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|M
name|inner_matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|EachMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements Key(inner_matcher) for the given argument pair type.
end_comment

begin_comment
comment|// Key(inner_matcher) matches an std::pair whose 'first' field matches
end_comment

begin_comment
comment|// inner_matcher.  For example, Contains(Key(Ge(5))) can be used to match an
end_comment

begin_comment
comment|// std::map that contains at least one element whose key is>= 5.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|PairType
operator|>
name|class
name|KeyMatcherImpl
operator|:
name|public
name|MatcherInterface
operator|<
name|PairType
operator|>
block|{
name|public
operator|:
typedef|typedef
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
argument|PairType
argument_list|)
name|RawPairType
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|RawPairType
operator|::
name|first_type
name|KeyType
expr_stmt|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
name|InnerMatcher
operator|>
name|explicit
name|KeyMatcherImpl
argument_list|(
argument|InnerMatcher inner_matcher
argument_list|)
operator|:
name|inner_matcher_
argument_list|(
argument|testing::SafeMatcherCast<const KeyType&>(inner_matcher)
argument_list|)
block|{   }
comment|// Returns true iff 'key_value.first' (the key) matches the inner matcher.
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|PairType key_value
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
name|StringMatchResultListener
name|inner_listener
block|;
specifier|const
name|bool
name|match
operator|=
name|inner_matcher_
operator|.
name|MatchAndExplain
argument_list|(
name|key_value
operator|.
name|first
argument_list|,
operator|&
name|inner_listener
argument_list|)
block|;
specifier|const
name|internal
operator|::
name|string
name|explanation
operator|=
name|inner_listener
operator|.
name|str
argument_list|()
block|;
if|if
condition|(
name|explanation
operator|!=
literal|""
condition|)
block|{
operator|*
name|listener
operator|<<
literal|"whose first field is a value "
operator|<<
name|explanation
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|match
return|;
end_return

begin_comment
unit|}
comment|// Describes what this matcher does.
end_comment

begin_decl_stmt
unit|virtual
name|void
name|DescribeTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
literal|"has a key that "
expr_stmt|;
name|inner_matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Describes what the negation of this matcher does.
end_comment

begin_decl_stmt
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
operator|*
name|os
operator|<<
literal|"doesn't have a key that "
expr_stmt|;
name|inner_matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|Matcher
operator|<
specifier|const
name|KeyType
operator|&
operator|>
name|inner_matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|KeyMatcherImpl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements polymorphic Key(matcher_for_key).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|M
operator|>
name|class
name|KeyMatcher
block|{
name|public
operator|:
name|explicit
name|KeyMatcher
argument_list|(
argument|M m
argument_list|)
operator|:
name|matcher_for_key_
argument_list|(
argument|m
argument_list|)
block|{}
name|template
operator|<
name|typename
name|PairType
operator|>
name|operator
name|Matcher
operator|<
name|PairType
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new KeyMatcherImpl<PairType>(matcher_for_key_)
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|M
name|matcher_for_key_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|KeyMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements Pair(first_matcher, second_matcher) for the given argument pair
end_comment

begin_comment
comment|// type with its two matchers. See Pair() function below.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|PairType
operator|>
name|class
name|PairMatcherImpl
operator|:
name|public
name|MatcherInterface
operator|<
name|PairType
operator|>
block|{
name|public
operator|:
typedef|typedef
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
argument|PairType
argument_list|)
name|RawPairType
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|RawPairType
operator|::
name|first_type
name|FirstType
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|RawPairType
operator|::
name|second_type
name|SecondType
expr_stmt|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
name|FirstMatcher
operator|,
name|typename
name|SecondMatcher
operator|>
name|PairMatcherImpl
argument_list|(
argument|FirstMatcher first_matcher
argument_list|,
argument|SecondMatcher second_matcher
argument_list|)
operator|:
name|first_matcher_
argument_list|(
name|testing
operator|::
name|SafeMatcherCast
operator|<
specifier|const
name|FirstType
operator|&
operator|>
operator|(
name|first_matcher
operator|)
argument_list|)
operator|,
name|second_matcher_
argument_list|(
argument|testing::SafeMatcherCast<const SecondType&>(second_matcher)
argument_list|)
block|{   }
comment|// Describes what this matcher does.
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"has a first field that "
block|;
name|first_matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|", and has a second field that "
block|;
name|second_matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;   }
comment|// Describes what the negation of this matcher does.
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"has a first field that "
block|;
name|first_matcher_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|", or has a second field that "
block|;
name|second_matcher_
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
block|;   }
comment|// Returns true iff 'a_pair.first' matches first_matcher and 'a_pair.second'
comment|// matches second_matcher.
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|PairType a_pair
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|listener
operator|->
name|IsInterested
argument_list|()
condition|)
block|{
comment|// If the listener is not interested, we don't need to construct the
comment|// explanation.
return|return
name|first_matcher_
operator|.
name|Matches
argument_list|(
name|a_pair
operator|.
name|first
argument_list|)
operator|&&
name|second_matcher_
operator|.
name|Matches
argument_list|(
name|a_pair
operator|.
name|second
argument_list|)
return|;
block|}
name|StringMatchResultListener
name|first_inner_listener
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|first_matcher_
operator|.
name|MatchAndExplain
argument_list|(
name|a_pair
operator|.
name|first
argument_list|,
operator|&
name|first_inner_listener
argument_list|)
condition|)
block|{
operator|*
name|listener
operator|<<
literal|"whose first field does not match"
expr_stmt|;
name|PrintIfNotEmpty
argument_list|(
name|first_inner_listener
operator|.
name|str
argument_list|()
argument_list|,
name|listener
operator|->
name|stream
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
end_if

begin_decl_stmt
name|StringMatchResultListener
name|second_inner_listener
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
operator|!
name|second_matcher_
operator|.
name|MatchAndExplain
argument_list|(
name|a_pair
operator|.
name|second
argument_list|,
operator|&
name|second_inner_listener
argument_list|)
condition|)
block|{
operator|*
name|listener
operator|<<
literal|"whose second field does not match"
expr_stmt|;
name|PrintIfNotEmpty
argument_list|(
name|second_inner_listener
operator|.
name|str
argument_list|()
argument_list|,
name|listener
operator|->
name|stream
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
end_if

begin_expr_stmt
name|ExplainSuccess
argument_list|(
name|first_inner_listener
operator|.
name|str
argument_list|()
argument_list|,
name|second_inner_listener
operator|.
name|str
argument_list|()
argument_list|,
name|listener
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_decl_stmt
unit|}   private:
name|void
name|ExplainSuccess
argument_list|(
specifier|const
name|internal
operator|::
name|string
operator|&
name|first_explanation
argument_list|,
specifier|const
name|internal
operator|::
name|string
operator|&
name|second_explanation
argument_list|,
name|MatchResultListener
operator|*
name|listener
argument_list|)
decl|const
block|{
operator|*
name|listener
operator|<<
literal|"whose both fields match"
expr_stmt|;
if|if
condition|(
name|first_explanation
operator|!=
literal|""
condition|)
block|{
operator|*
name|listener
operator|<<
literal|", where the first field is a value "
operator|<<
name|first_explanation
expr_stmt|;
block|}
if|if
condition|(
name|second_explanation
operator|!=
literal|""
condition|)
block|{
operator|*
name|listener
operator|<<
literal|", "
expr_stmt|;
if|if
condition|(
name|first_explanation
operator|!=
literal|""
condition|)
block|{
operator|*
name|listener
operator|<<
literal|"and "
expr_stmt|;
block|}
else|else
block|{
operator|*
name|listener
operator|<<
literal|"where "
expr_stmt|;
block|}
operator|*
name|listener
operator|<<
literal|"the second field is a value "
operator|<<
name|second_explanation
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_expr_stmt
specifier|const
name|Matcher
operator|<
specifier|const
name|FirstType
operator|&
operator|>
name|first_matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|Matcher
operator|<
specifier|const
name|SecondType
operator|&
operator|>
name|second_matcher_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|PairMatcherImpl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements polymorphic Pair(first_matcher, second_matcher).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|FirstMatcher
operator|,
name|typename
name|SecondMatcher
operator|>
name|class
name|PairMatcher
block|{
name|public
operator|:
name|PairMatcher
argument_list|(
argument|FirstMatcher first_matcher
argument_list|,
argument|SecondMatcher second_matcher
argument_list|)
operator|:
name|first_matcher_
argument_list|(
name|first_matcher
argument_list|)
block|,
name|second_matcher_
argument_list|(
argument|second_matcher
argument_list|)
block|{}
name|template
operator|<
name|typename
name|PairType
operator|>
name|operator
name|Matcher
operator|<
name|PairType
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new PairMatcherImpl<PairType>(             first_matcher_, second_matcher_)
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
name|FirstMatcher
name|first_matcher_
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|SecondMatcher
name|second_matcher_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|PairMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements ElementsAre() and ElementsAreArray().
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Container
operator|>
name|class
name|ElementsAreMatcherImpl
operator|:
name|public
name|MatcherInterface
operator|<
name|Container
operator|>
block|{
name|public
operator|:
typedef|typedef
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
argument|Container
argument_list|)
name|RawContainer
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|internal
operator|::
name|StlContainerView
operator|<
name|RawContainer
operator|>
name|View
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|View
operator|::
name|type
name|StlContainer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|View
operator|::
name|const_reference
name|StlContainerReference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|decltype
argument_list|(
argument|std::begin(       std::declval<StlContainerReference>())
argument_list|)
name|StlContainerConstIterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|remove_reference
operator|<
name|decltype
argument_list|(
operator|*
name|std
operator|::
name|declval
operator|<
name|StlContainerConstIterator
operator|&
operator|>
operator|(
operator|)
argument_list|)
operator|>
operator|::
name|type
name|Element
expr_stmt|;
end_typedef

begin_comment
comment|// Constructs the matcher from a sequence of element values or
end_comment

begin_comment
comment|// element matchers.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|InputIter
operator|>
name|ElementsAreMatcherImpl
argument_list|(
argument|InputIter first
argument_list|,
argument|InputIter last
argument_list|)
block|{
while|while
condition|(
name|first
operator|!=
name|last
condition|)
block|{
name|matchers_
operator|.
name|push_back
argument_list|(
name|MatcherCast
operator|<
specifier|const
name|Element
operator|&
operator|>
operator|(
operator|*
name|first
operator|++
operator|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// Describes what this matcher does.
end_comment

begin_decl_stmt
unit|virtual
name|void
name|DescribeTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
if|if
condition|(
name|count
argument_list|()
operator|==
literal|0
condition|)
block|{
operator|*
name|os
operator|<<
literal|"is empty"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|count
argument_list|()
operator|==
literal|1
condition|)
block|{
operator|*
name|os
operator|<<
literal|"has 1 element that "
expr_stmt|;
name|matchers_
index|[
literal|0
index|]
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|*
name|os
operator|<<
literal|"has "
operator|<<
name|Elements
argument_list|(
name|count
argument_list|()
argument_list|)
operator|<<
literal|" where\n"
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
operator|*
name|os
operator|<<
literal|"element #"
operator|<<
name|i
operator|<<
literal|" "
expr_stmt|;
name|matchers_
index|[
name|i
index|]
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|+
literal|1
operator|<
name|count
argument_list|()
condition|)
block|{
operator|*
name|os
operator|<<
literal|",\n"
expr_stmt|;
block|}
block|}
block|}
block|}
end_decl_stmt

begin_comment
comment|// Describes what the negation of this matcher does.
end_comment

begin_decl_stmt
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
if|if
condition|(
name|count
argument_list|()
operator|==
literal|0
condition|)
block|{
operator|*
name|os
operator|<<
literal|"isn't empty"
expr_stmt|;
return|return;
block|}
operator|*
name|os
operator|<<
literal|"doesn't have "
operator|<<
name|Elements
argument_list|(
name|count
argument_list|()
argument_list|)
operator|<<
literal|", or\n"
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
operator|*
name|os
operator|<<
literal|"element #"
operator|<<
name|i
operator|<<
literal|" "
expr_stmt|;
name|matchers_
index|[
name|i
index|]
operator|.
name|DescribeNegationTo
argument_list|(
name|os
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|+
literal|1
operator|<
name|count
argument_list|()
condition|)
block|{
operator|*
name|os
operator|<<
literal|", or\n"
expr_stmt|;
block|}
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
name|Container
name|container
argument_list|,
name|MatchResultListener
operator|*
name|listener
argument_list|)
decl|const
block|{
comment|// To work with stream-like "containers", we must only walk
comment|// through the elements in one pass.
specifier|const
name|bool
name|listener_interested
init|=
name|listener
operator|->
name|IsInterested
argument_list|()
decl_stmt|;
comment|// explanations[i] is the explanation of the element at index i.
operator|::
name|std
operator|::
name|vector
operator|<
name|internal
operator|::
name|string
operator|>
name|explanations
argument_list|(
name|count
argument_list|()
argument_list|)
expr_stmt|;
name|StlContainerReference
name|stl_container
init|=
name|View
operator|::
name|ConstReference
argument_list|(
name|container
argument_list|)
decl_stmt|;
name|StlContainerConstIterator
name|it
init|=
name|stl_container
operator|.
name|begin
argument_list|()
decl_stmt|;
name|size_t
name|exam_pos
init|=
literal|0
decl_stmt|;
name|bool
name|mismatch_found
init|=
name|false
decl_stmt|;
comment|// Have we found a mismatched element yet?
comment|// Go through the elements and matchers in pairs, until we reach
comment|// the end of either the elements or the matchers, or until we find a
comment|// mismatch.
for|for
control|(
init|;
name|it
operator|!=
name|stl_container
operator|.
name|end
argument_list|()
operator|&&
name|exam_pos
operator|!=
name|count
argument_list|()
condition|;
operator|++
name|it
operator|,
operator|++
name|exam_pos
control|)
block|{
name|bool
name|match
decl_stmt|;
comment|// Does the current element match the current matcher?
if|if
condition|(
name|listener_interested
condition|)
block|{
name|StringMatchResultListener
name|s
decl_stmt|;
name|match
operator|=
name|matchers_
index|[
name|exam_pos
index|]
operator|.
name|MatchAndExplain
argument_list|(
operator|*
name|it
argument_list|,
operator|&
name|s
argument_list|)
expr_stmt|;
name|explanations
index|[
name|exam_pos
index|]
operator|=
name|s
operator|.
name|str
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|match
operator|=
name|matchers_
index|[
name|exam_pos
index|]
operator|.
name|Matches
argument_list|(
operator|*
name|it
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|match
condition|)
block|{
name|mismatch_found
operator|=
name|true
expr_stmt|;
break|break;
block|}
block|}
comment|// If mismatch_found is true, 'exam_pos' is the index of the mismatch.
comment|// Find how many elements the actual container has.  We avoid
comment|// calling size() s.t. this code works for stream-like "containers"
comment|// that don't define size().
name|size_t
name|actual_count
init|=
name|exam_pos
decl_stmt|;
for|for
control|(
init|;
name|it
operator|!=
name|stl_container
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
operator|++
name|actual_count
expr_stmt|;
block|}
if|if
condition|(
name|actual_count
operator|!=
name|count
argument_list|()
condition|)
block|{
comment|// The element count doesn't match.  If the container is empty,
comment|// there's no need to explain anything as Google Mock already
comment|// prints the empty container.  Otherwise we just need to show
comment|// how many elements there actually are.
if|if
condition|(
name|listener_interested
operator|&&
operator|(
name|actual_count
operator|!=
literal|0
operator|)
condition|)
block|{
operator|*
name|listener
operator|<<
literal|"which has "
operator|<<
name|Elements
argument_list|(
name|actual_count
argument_list|)
expr_stmt|;
block|}
return|return
name|false
return|;
block|}
if|if
condition|(
name|mismatch_found
condition|)
block|{
comment|// The element count matches, but the exam_pos-th element doesn't match.
if|if
condition|(
name|listener_interested
condition|)
block|{
operator|*
name|listener
operator|<<
literal|"whose element #"
operator|<<
name|exam_pos
operator|<<
literal|" doesn't match"
expr_stmt|;
name|PrintIfNotEmpty
argument_list|(
name|explanations
index|[
name|exam_pos
index|]
argument_list|,
name|listener
operator|->
name|stream
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|false
return|;
block|}
comment|// Every element matches its expectation.  We need to explain why
comment|// (the obvious ones can be skipped).
if|if
condition|(
name|listener_interested
condition|)
block|{
name|bool
name|reason_printed
init|=
name|false
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|internal
operator|::
name|string
operator|&
name|s
operator|=
name|explanations
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|s
operator|.
name|empty
argument_list|()
condition|)
block|{
if|if
condition|(
name|reason_printed
condition|)
block|{
operator|*
name|listener
operator|<<
literal|",\nand "
expr_stmt|;
block|}
operator|*
name|listener
operator|<<
literal|"whose element #"
operator|<<
name|i
operator|<<
literal|" matches, "
operator|<<
name|s
expr_stmt|;
name|reason_printed
operator|=
name|true
expr_stmt|;
block|}
block|}
block|}
return|return
name|true
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_function
specifier|static
name|Message
name|Elements
parameter_list|(
name|size_t
name|count
parameter_list|)
block|{
return|return
name|Message
argument_list|()
operator|<<
name|count
operator|<<
operator|(
name|count
operator|==
literal|1
condition|?
literal|" element"
else|:
literal|" elements"
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|size_t
name|count
argument_list|()
specifier|const
block|{
return|return
name|matchers_
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
operator|::
name|std
operator|::
name|vector
operator|<
name|Matcher
operator|<
specifier|const
name|Element
operator|&
operator|>
expr|>
name|matchers_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|ElementsAreMatcherImpl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Connectivity matrix of (elements X matchers), in element-major order.
end_comment

begin_comment
comment|// Initially, there are no edges.
end_comment

begin_comment
comment|// Use NextGraph() to iterate over all possible edge configurations.
end_comment

begin_comment
comment|// Use Randomize() to generate a random edge configuration.
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
name|MatchMatrix
block|{
name|public
label|:
name|MatchMatrix
argument_list|(
argument|size_t num_elements
argument_list|,
argument|size_t num_matchers
argument_list|)
block|:
name|num_elements_
argument_list|(
name|num_elements
argument_list|)
operator|,
name|num_matchers_
argument_list|(
name|num_matchers
argument_list|)
operator|,
name|matched_
argument_list|(
argument|num_elements_* num_matchers_
argument_list|,
literal|0
argument_list|)
block|{   }
name|size_t
name|LhsSize
argument_list|()
specifier|const
block|{
return|return
name|num_elements_
return|;
block|}
name|size_t
name|RhsSize
argument_list|()
specifier|const
block|{
return|return
name|num_matchers_
return|;
block|}
name|bool
name|HasEdge
argument_list|(
name|size_t
name|ilhs
argument_list|,
name|size_t
name|irhs
argument_list|)
decl|const
block|{
return|return
name|matched_
index|[
name|SpaceIndex
argument_list|(
name|ilhs
argument_list|,
name|irhs
argument_list|)
index|]
operator|==
literal|1
return|;
block|}
name|void
name|SetEdge
parameter_list|(
name|size_t
name|ilhs
parameter_list|,
name|size_t
name|irhs
parameter_list|,
name|bool
name|b
parameter_list|)
block|{
name|matched_
index|[
name|SpaceIndex
argument_list|(
name|ilhs
argument_list|,
name|irhs
argument_list|)
index|]
operator|=
name|b
condition|?
literal|1
else|:
literal|0
expr_stmt|;
block|}
comment|// Treating the connectivity matrix as a (LhsSize()*RhsSize())-bit number,
comment|// adds 1 to that number; returns false if incrementing the graph left it
comment|// empty.
name|bool
name|NextGraph
parameter_list|()
function_decl|;
name|void
name|Randomize
parameter_list|()
function_decl|;
name|string
name|DebugString
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|size_t
name|SpaceIndex
argument_list|(
name|size_t
name|ilhs
argument_list|,
name|size_t
name|irhs
argument_list|)
decl|const
block|{
return|return
name|ilhs
operator|*
name|num_matchers_
operator|+
name|irhs
return|;
block|}
name|size_t
name|num_elements_
decl_stmt|;
name|size_t
name|num_matchers_
decl_stmt|;
comment|// Each element is a char interpreted as bool. They are stored as a
comment|// flattened array in lhs-major order, use 'SpaceIndex()' to translate
comment|// a (ilhs, irhs) matrix coordinate into an offset.
operator|::
name|std
operator|::
name|vector
operator|<
name|char
operator|>
name|matched_
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
operator|::
name|std
operator|::
name|pair
operator|<
name|size_t
operator|,
name|size_t
operator|>
name|ElementMatcherPair
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
operator|::
name|std
operator|::
name|vector
operator|<
name|ElementMatcherPair
operator|>
name|ElementMatcherPairs
expr_stmt|;
end_typedef

begin_comment
comment|// Returns a maximum bipartite matching for the specified graph 'g'.
end_comment

begin_comment
comment|// The matching is represented as a vector of {element, matcher} pairs.
end_comment

begin_function_decl
name|GTEST_API_
name|ElementMatcherPairs
name|FindMaxBipartiteMatching
parameter_list|(
specifier|const
name|MatchMatrix
modifier|&
name|g
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GTEST_API_
name|bool
name|FindPairing
parameter_list|(
specifier|const
name|MatchMatrix
modifier|&
name|matrix
parameter_list|,
name|MatchResultListener
modifier|*
name|listener
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Untyped base class for implementing UnorderedElementsAre.  By
end_comment

begin_comment
comment|// putting logic that's not specific to the element type here, we
end_comment

begin_comment
comment|// reduce binary bloat and increase compilation speed.
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
name|UnorderedElementsAreMatcherImplBase
block|{
name|protected
label|:
comment|// A vector of matcher describers, one for each element matcher.
comment|// Does not own the describers (and thus can be used only when the
comment|// element matchers are alive).
typedef|typedef
operator|::
name|std
operator|::
name|vector
operator|<
specifier|const
name|MatcherDescriberInterface
operator|*
operator|>
name|MatcherDescriberVec
expr_stmt|;
comment|// Describes this UnorderedElementsAre matcher.
name|void
name|DescribeToImpl
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
decl_stmt|;
comment|// Describes the negation of this UnorderedElementsAre matcher.
name|void
name|DescribeNegationToImpl
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
decl_stmt|;
name|bool
name|VerifyAllElementsAndMatchersAreMatched
argument_list|(
specifier|const
operator|::
name|std
operator|::
name|vector
operator|<
name|string
operator|>
operator|&
name|element_printouts
argument_list|,
specifier|const
name|MatchMatrix
operator|&
name|matrix
argument_list|,
name|MatchResultListener
operator|*
name|listener
argument_list|)
decl|const
decl_stmt|;
name|MatcherDescriberVec
modifier|&
name|matcher_describers
parameter_list|()
block|{
return|return
name|matcher_describers_
return|;
block|}
specifier|static
name|Message
name|Elements
parameter_list|(
name|size_t
name|n
parameter_list|)
block|{
return|return
name|Message
argument_list|()
operator|<<
name|n
operator|<<
literal|" element"
operator|<<
operator|(
name|n
operator|==
literal|1
condition|?
literal|""
else|:
literal|"s"
operator|)
return|;
block|}
name|private
label|:
name|MatcherDescriberVec
name|matcher_describers_
decl_stmt|;
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|UnorderedElementsAreMatcherImplBase
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Implements unordered ElementsAre and unordered ElementsAreArray.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Container
operator|>
name|class
name|UnorderedElementsAreMatcherImpl
operator|:
name|public
name|MatcherInterface
operator|<
name|Container
operator|>
operator|,
name|public
name|UnorderedElementsAreMatcherImplBase
block|{
name|public
operator|:
typedef|typedef
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
argument|Container
argument_list|)
name|RawContainer
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|internal
operator|::
name|StlContainerView
operator|<
name|RawContainer
operator|>
name|View
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|View
operator|::
name|type
name|StlContainer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|View
operator|::
name|const_reference
name|StlContainerReference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|decltype
argument_list|(
argument|std::begin(       std::declval<StlContainerReference>())
argument_list|)
name|StlContainerConstIterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|remove_reference
operator|<
name|decltype
argument_list|(
operator|*
name|std
operator|::
name|declval
operator|<
name|StlContainerConstIterator
operator|&
operator|>
operator|(
operator|)
argument_list|)
operator|>
operator|::
name|type
name|Element
expr_stmt|;
end_typedef

begin_comment
comment|// Constructs the matcher from a sequence of element values or
end_comment

begin_comment
comment|// element matchers.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|InputIter
operator|>
name|UnorderedElementsAreMatcherImpl
argument_list|(
argument|InputIter first
argument_list|,
argument|InputIter last
argument_list|)
block|{
for|for
control|(
init|;
name|first
operator|!=
name|last
condition|;
operator|++
name|first
control|)
block|{
name|matchers_
operator|.
name|push_back
argument_list|(
name|MatcherCast
operator|<
specifier|const
name|Element
operator|&
operator|>
operator|(
operator|*
name|first
operator|)
argument_list|)
expr_stmt|;
name|matcher_describers
argument_list|()
operator|.
name|push_back
argument_list|(
name|matchers_
operator|.
name|back
argument_list|()
operator|.
name|GetDescriber
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// Describes what this matcher does.
end_comment

begin_decl_stmt
unit|virtual
name|void
name|DescribeTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
return|return
name|UnorderedElementsAreMatcherImplBase
operator|::
name|DescribeToImpl
argument_list|(
name|os
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Describes what the negation of this matcher does.
end_comment

begin_decl_stmt
name|virtual
name|void
name|DescribeNegationTo
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl|const
block|{
return|return
name|UnorderedElementsAreMatcherImplBase
operator|::
name|DescribeNegationToImpl
argument_list|(
name|os
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
name|Container
name|container
argument_list|,
name|MatchResultListener
operator|*
name|listener
argument_list|)
decl|const
block|{
name|StlContainerReference
name|stl_container
init|=
name|View
operator|::
name|ConstReference
argument_list|(
name|container
argument_list|)
decl_stmt|;
operator|::
name|std
operator|::
name|vector
operator|<
name|string
operator|>
name|element_printouts
expr_stmt|;
name|MatchMatrix
name|matrix
init|=
name|AnalyzeElements
argument_list|(
name|stl_container
operator|.
name|begin
argument_list|()
argument_list|,
name|stl_container
operator|.
name|end
argument_list|()
argument_list|,
operator|&
name|element_printouts
argument_list|,
name|listener
argument_list|)
decl_stmt|;
specifier|const
name|size_t
name|actual_count
init|=
name|matrix
operator|.
name|LhsSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|actual_count
operator|==
literal|0
operator|&&
name|matchers_
operator|.
name|empty
argument_list|()
condition|)
block|{
return|return
name|true
return|;
block|}
if|if
condition|(
name|actual_count
operator|!=
name|matchers_
operator|.
name|size
argument_list|()
condition|)
block|{
comment|// The element count doesn't match.  If the container is empty,
comment|// there's no need to explain anything as Google Mock already
comment|// prints the empty container. Otherwise we just need to show
comment|// how many elements there actually are.
if|if
condition|(
name|actual_count
operator|!=
literal|0
operator|&&
name|listener
operator|->
name|IsInterested
argument_list|()
condition|)
block|{
operator|*
name|listener
operator|<<
literal|"which has "
operator|<<
name|Elements
argument_list|(
name|actual_count
argument_list|)
expr_stmt|;
block|}
return|return
name|false
return|;
block|}
return|return
name|VerifyAllElementsAndMatchersAreMatched
argument_list|(
name|element_printouts
argument_list|,
name|matrix
argument_list|,
name|listener
argument_list|)
operator|&&
name|FindPairing
argument_list|(
name|matrix
argument_list|,
name|listener
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_typedef
typedef|typedef
operator|::
name|std
operator|::
name|vector
operator|<
name|Matcher
operator|<
specifier|const
name|Element
operator|&
operator|>
expr|>
name|MatcherVec
expr_stmt|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
name|ElementIter
operator|>
name|MatchMatrix
name|AnalyzeElements
argument_list|(
argument|ElementIter elem_first
argument_list|,
argument|ElementIter elem_last
argument_list|,
argument|::std::vector<string>* element_printouts
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
name|element_printouts
operator|->
name|clear
argument_list|()
block|;
operator|::
name|std
operator|::
name|vector
operator|<
name|char
operator|>
name|did_match
block|;
name|size_t
name|num_elements
operator|=
literal|0
block|;
for|for
control|(
init|;
name|elem_first
operator|!=
name|elem_last
condition|;
operator|++
name|num_elements
operator|,
operator|++
name|elem_first
control|)
block|{
if|if
condition|(
name|listener
operator|->
name|IsInterested
argument_list|()
condition|)
block|{
name|element_printouts
operator|->
name|push_back
argument_list|(
name|PrintToString
argument_list|(
operator|*
name|elem_first
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_for
for|for
control|(
name|size_t
name|irhs
init|=
literal|0
init|;
name|irhs
operator|!=
name|matchers_
operator|.
name|size
argument_list|()
condition|;
operator|++
name|irhs
control|)
block|{
name|did_match
operator|.
name|push_back
argument_list|(
name|Matches
argument_list|(
name|matchers_
index|[
name|irhs
index|]
argument_list|)
argument_list|(
operator|*
name|elem_first
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_expr_stmt
unit|}      MatchMatrix
name|matrix
argument_list|(
name|num_elements
argument_list|,
name|matchers_
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|::
name|std
operator|::
name|vector
operator|<
name|char
operator|>
operator|::
name|const_iterator
name|did_match_iter
operator|=
name|did_match
operator|.
name|begin
argument_list|()
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|size_t
name|ilhs
init|=
literal|0
init|;
name|ilhs
operator|!=
name|num_elements
condition|;
operator|++
name|ilhs
control|)
block|{
for|for
control|(
name|size_t
name|irhs
init|=
literal|0
init|;
name|irhs
operator|!=
name|matchers_
operator|.
name|size
argument_list|()
condition|;
operator|++
name|irhs
control|)
block|{
name|matrix
operator|.
name|SetEdge
argument_list|(
name|ilhs
argument_list|,
name|irhs
argument_list|,
operator|*
name|did_match_iter
operator|++
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_for

begin_return
return|return
name|matrix
return|;
end_return

begin_expr_stmt
unit|}    MatcherVec
name|matchers_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|UnorderedElementsAreMatcherImpl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Functor for use in TransformTuple.
end_comment

begin_comment
comment|// Performs MatcherCast<Target> on an input argument of any type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Target
operator|>
expr|struct
name|CastAndAppendTransform
block|{
name|template
operator|<
name|typename
name|Arg
operator|>
name|Matcher
operator|<
name|Target
operator|>
name|operator
argument_list|()
operator|(
specifier|const
name|Arg
operator|&
name|a
operator|)
specifier|const
block|{
return|return
name|MatcherCast
operator|<
name|Target
operator|>
operator|(
name|a
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Implements UnorderedElementsAre.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|MatcherTuple
operator|>
name|class
name|UnorderedElementsAreMatcher
block|{
name|public
operator|:
name|explicit
name|UnorderedElementsAreMatcher
argument_list|(
specifier|const
name|MatcherTuple
operator|&
name|args
argument_list|)
operator|:
name|matchers_
argument_list|(
argument|args
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Container
operator|>
name|operator
name|Matcher
operator|<
name|Container
operator|>
operator|(
operator|)
specifier|const
block|{
typedef|typedef
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
argument|Container
argument_list|)
name|RawContainer
expr_stmt|;
typedef|typedef
name|internal
operator|::
name|StlContainerView
operator|<
name|RawContainer
operator|>
name|View
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|View
operator|::
name|const_reference
name|StlContainerReference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|decltype
argument_list|(
argument|std::begin(         std::declval<StlContainerReference>())
argument_list|)
name|StlContainerConstIterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|remove_reference
operator|<
name|decltype
argument_list|(
operator|*
name|std
operator|::
name|declval
operator|<
name|StlContainerConstIterator
operator|&
operator|>
operator|(
operator|)
argument_list|)
operator|>
operator|::
name|type
name|Element
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
operator|::
name|std
operator|::
name|vector
operator|<
name|Matcher
operator|<
specifier|const
name|Element
operator|&
operator|>
expr|>
name|MatcherVec
expr_stmt|;
end_typedef

begin_decl_stmt
name|MatcherVec
name|matchers
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|matchers
operator|.
name|reserve
argument_list|(
operator|::
name|testing
operator|::
name|tuple_size
operator|<
name|MatcherTuple
operator|>
operator|::
name|value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TransformTupleValues
argument_list|(
name|CastAndAppendTransform
operator|<
specifier|const
name|Element
operator|&
operator|>
operator|(
operator|)
argument_list|,
name|matchers_
argument_list|,
operator|::
name|std
operator|::
name|back_inserter
argument_list|(
name|matchers
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|MakeMatcher
argument_list|(
argument|new UnorderedElementsAreMatcherImpl<Container>(                            matchers.begin(), matchers.end())
argument_list|)
return|;
end_return

begin_decl_stmt
unit|}   private:
specifier|const
name|MatcherTuple
name|matchers_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|UnorderedElementsAreMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements ElementsAre.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|MatcherTuple
operator|>
name|class
name|ElementsAreMatcher
block|{
name|public
operator|:
name|explicit
name|ElementsAreMatcher
argument_list|(
specifier|const
name|MatcherTuple
operator|&
name|args
argument_list|)
operator|:
name|matchers_
argument_list|(
argument|args
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Container
operator|>
name|operator
name|Matcher
operator|<
name|Container
operator|>
operator|(
operator|)
specifier|const
block|{
typedef|typedef
name|GTEST_REMOVE_REFERENCE_AND_CONST_
argument_list|(
argument|Container
argument_list|)
name|RawContainer
expr_stmt|;
typedef|typedef
name|internal
operator|::
name|StlContainerView
operator|<
name|RawContainer
operator|>
name|View
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|View
operator|::
name|const_reference
name|StlContainerReference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|decltype
argument_list|(
argument|std::begin(         std::declval<StlContainerReference>())
argument_list|)
name|StlContainerConstIterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|remove_reference
operator|<
name|decltype
argument_list|(
operator|*
name|std
operator|::
name|declval
operator|<
name|StlContainerConstIterator
operator|&
operator|>
operator|(
operator|)
argument_list|)
operator|>
operator|::
name|type
name|Element
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
operator|::
name|std
operator|::
name|vector
operator|<
name|Matcher
operator|<
specifier|const
name|Element
operator|&
operator|>
expr|>
name|MatcherVec
expr_stmt|;
end_typedef

begin_decl_stmt
name|MatcherVec
name|matchers
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|matchers
operator|.
name|reserve
argument_list|(
operator|::
name|testing
operator|::
name|tuple_size
operator|<
name|MatcherTuple
operator|>
operator|::
name|value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TransformTupleValues
argument_list|(
name|CastAndAppendTransform
operator|<
specifier|const
name|Element
operator|&
operator|>
operator|(
operator|)
argument_list|,
name|matchers_
argument_list|,
operator|::
name|std
operator|::
name|back_inserter
argument_list|(
name|matchers
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|MakeMatcher
argument_list|(
argument|new ElementsAreMatcherImpl<Container>(                            matchers.begin(), matchers.end())
argument_list|)
return|;
end_return

begin_decl_stmt
unit|}   private:
specifier|const
name|MatcherTuple
name|matchers_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|ElementsAreMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements UnorderedElementsAreArray().
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|UnorderedElementsAreArrayMatcher
block|{
name|public
operator|:
name|UnorderedElementsAreArrayMatcher
argument_list|()
block|{}
name|template
operator|<
name|typename
name|Iter
operator|>
name|UnorderedElementsAreArrayMatcher
argument_list|(
argument|Iter first
argument_list|,
argument|Iter last
argument_list|)
operator|:
name|matchers_
argument_list|(
argument|first
argument_list|,
argument|last
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Container
operator|>
name|operator
name|Matcher
operator|<
name|Container
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new UnorderedElementsAreMatcherImpl<Container>(matchers_.begin(),                                                        matchers_.end())
argument_list|)
return|;
block|}
name|private
operator|:
operator|::
name|std
operator|::
name|vector
operator|<
name|T
operator|>
name|matchers_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|UnorderedElementsAreArrayMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements ElementsAreArray().
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ElementsAreArrayMatcher
block|{
name|public
operator|:
name|template
operator|<
name|typename
name|Iter
operator|>
name|ElementsAreArrayMatcher
argument_list|(
argument|Iter first
argument_list|,
argument|Iter last
argument_list|)
operator|:
name|matchers_
argument_list|(
argument|first
argument_list|,
argument|last
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Container
operator|>
name|operator
name|Matcher
operator|<
name|Container
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new ElementsAreMatcherImpl<Container>(         matchers_.begin(), matchers_.end())
argument_list|)
return|;
block|}
name|private
operator|:
specifier|const
operator|::
name|std
operator|::
name|vector
operator|<
name|T
operator|>
name|matchers_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|ElementsAreArrayMatcher
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Given a 2-tuple matcher tm of type Tuple2Matcher and a value second
end_comment

begin_comment
comment|// of type Second, BoundSecondMatcher<Tuple2Matcher, Second>(tm,
end_comment

begin_comment
comment|// second) is a polymorphic matcher that matches a value x iff tm
end_comment

begin_comment
comment|// matches tuple (x, second).  Useful for implementing
end_comment

begin_comment
comment|// UnorderedPointwise() in terms of UnorderedElementsAreArray().
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BoundSecondMatcher is copyable and assignable, as we need to put
end_comment

begin_comment
comment|// instances of this class in a vector when implementing
end_comment

begin_comment
comment|// UnorderedPointwise().
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Tuple2Matcher
operator|,
name|typename
name|Second
operator|>
name|class
name|BoundSecondMatcher
block|{
name|public
operator|:
name|BoundSecondMatcher
argument_list|(
specifier|const
name|Tuple2Matcher
operator|&
name|tm
argument_list|,
specifier|const
name|Second
operator|&
name|second
argument_list|)
operator|:
name|tuple2_matcher_
argument_list|(
name|tm
argument_list|)
block|,
name|second_value_
argument_list|(
argument|second
argument_list|)
block|{}
name|template
operator|<
name|typename
name|T
operator|>
name|operator
name|Matcher
operator|<
name|T
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new Impl<T>(tuple2_matcher_, second_value_)
argument_list|)
return|;
block|}
comment|// We have to define this for UnorderedPointwise() to compile in
comment|// C++98 mode, as it puts BoundSecondMatcher instances in a vector,
comment|// which requires the elements to be assignable in C++98.  The
comment|// compiler cannot generate the operator= for us, as Tuple2Matcher
comment|// and Second may not be assignable.
comment|//
comment|// However, this should never be called, so the implementation just
comment|// need to assert.
name|void
name|operator
operator|=
operator|(
specifier|const
name|BoundSecondMatcher
operator|&
comment|/*rhs*/
operator|)
block|{
name|GTEST_LOG_
argument_list|(
name|FATAL
argument_list|)
operator|<<
literal|"BoundSecondMatcher should never be assigned."
block|;   }
name|private
operator|:
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Impl
operator|:
name|public
name|MatcherInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
typedef|typedef
operator|::
name|testing
operator|::
name|tuple
operator|<
name|T
operator|,
name|Second
operator|>
name|ArgTuple
expr_stmt|;
name|Impl
argument_list|(
specifier|const
name|Tuple2Matcher
operator|&
name|tm
argument_list|,
specifier|const
name|Second
operator|&
name|second
argument_list|)
operator|:
name|mono_tuple2_matcher_
argument_list|(
name|SafeMatcherCast
operator|<
specifier|const
name|ArgTuple
operator|&
operator|>
operator|(
name|tm
operator|)
argument_list|)
operator|,
name|second_value_
argument_list|(
argument|second
argument_list|)
block|{}
name|virtual
name|void
name|DescribeTo
argument_list|(
argument|::std::ostream* os
argument_list|)
specifier|const
block|{
operator|*
name|os
operator|<<
literal|"and "
block|;
name|UniversalPrint
argument_list|(
name|second_value_
argument_list|,
name|os
argument_list|)
block|;
operator|*
name|os
operator|<<
literal|" "
block|;
name|mono_tuple2_matcher_
operator|.
name|DescribeTo
argument_list|(
name|os
argument_list|)
block|;     }
name|virtual
name|bool
name|MatchAndExplain
argument_list|(
argument|T x
argument_list|,
argument|MatchResultListener* listener
argument_list|)
specifier|const
block|{
return|return
name|mono_tuple2_matcher_
operator|.
name|MatchAndExplain
argument_list|(
name|ArgTuple
argument_list|(
name|x
argument_list|,
name|second_value_
argument_list|)
argument_list|,
name|listener
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|Matcher
operator|<
specifier|const
name|ArgTuple
operator|&
operator|>
name|mono_tuple2_matcher_
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|Second
name|second_value_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
specifier|const
name|Tuple2Matcher
name|tuple2_matcher_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|Second
name|second_value_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// Given a 2-tuple matcher tm and a value second,
end_comment

begin_comment
comment|// MatcherBindSecond(tm, second) returns a matcher that matches a
end_comment

begin_comment
comment|// value x iff tm matches tuple (x, second).  Useful for implementing
end_comment

begin_comment
comment|// UnorderedPointwise() in terms of UnorderedElementsAreArray().
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Tuple2Matcher
operator|,
name|typename
name|Second
operator|>
name|BoundSecondMatcher
operator|<
name|Tuple2Matcher
operator|,
name|Second
operator|>
name|MatcherBindSecond
argument_list|(
argument|const Tuple2Matcher& tm
argument_list|,
argument|const Second& second
argument_list|)
block|{
return|return
name|BoundSecondMatcher
operator|<
name|Tuple2Matcher
operator|,
name|Second
operator|>
operator|(
name|tm
operator|,
name|second
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns the description for a matcher defined using the MATCHER*()
end_comment

begin_comment
comment|// macro where the user-supplied description string is "", if
end_comment

begin_comment
comment|// 'negation' is false; otherwise returns the description of the
end_comment

begin_comment
comment|// negation of the matcher.  'param_values' contains a list of strings
end_comment

begin_comment
comment|// that are the print-out of the matcher's parameters.
end_comment

begin_function_decl
name|GTEST_API_
name|string
name|FormatMatcherDescription
parameter_list|(
name|bool
name|negation
parameter_list|,
specifier|const
name|char
modifier|*
name|matcher_name
parameter_list|,
specifier|const
name|Strings
modifier|&
name|param_values
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|}
comment|// namespace internal
end_comment

begin_comment
comment|// ElementsAreArray(first, last)
end_comment

begin_comment
comment|// ElementsAreArray(pointer, count)
end_comment

begin_comment
comment|// ElementsAreArray(array)
end_comment

begin_comment
comment|// ElementsAreArray(container)
end_comment

begin_comment
comment|// ElementsAreArray({ e1, e2, ..., en })
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The ElementsAreArray() functions are like ElementsAre(...), except
end_comment

begin_comment
comment|// that they are given a homogeneous sequence rather than taking each
end_comment

begin_comment
comment|// element as a function argument. The sequence can be specified as an
end_comment

begin_comment
comment|// array, a pointer and count, a vector, an initializer list, or an
end_comment

begin_comment
comment|// STL iterator range. In each of these cases, the underlying sequence
end_comment

begin_comment
comment|// can be either a sequence of values or a sequence of matchers.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// All forms of ElementsAreArray() make a copy of the input matcher sequence.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Iter
operator|>
specifier|inline
name|internal
operator|::
name|ElementsAreArrayMatcher
operator|<
name|typename
operator|::
name|std
operator|::
name|iterator_traits
operator|<
name|Iter
operator|>
operator|::
name|value_type
operator|>
name|ElementsAreArray
argument_list|(
argument|Iter first
argument_list|,
argument|Iter last
argument_list|)
block|{
typedef|typedef
name|typename
operator|::
name|std
operator|::
name|iterator_traits
operator|<
name|Iter
operator|>
operator|::
name|value_type
name|T
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|internal
operator|::
name|ElementsAreArrayMatcher
operator|<
name|T
operator|>
operator|(
name|first
operator|,
name|last
operator|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|internal
operator|::
name|ElementsAreArrayMatcher
operator|<
name|T
operator|>
name|ElementsAreArray
argument_list|(
argument|const T* pointer
argument_list|,
argument|size_t count
argument_list|)
block|{
return|return
name|ElementsAreArray
argument_list|(
name|pointer
argument_list|,
name|pointer
operator|+
name|count
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|size_t
name|N
operator|>
specifier|inline
name|internal
operator|::
name|ElementsAreArrayMatcher
operator|<
name|T
operator|>
name|ElementsAreArray
argument_list|(
argument|const T (&array)[N]
argument_list|)
block|{
return|return
name|ElementsAreArray
argument_list|(
name|array
argument_list|,
name|N
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|Container
operator|>
specifier|inline
name|internal
operator|::
name|ElementsAreArrayMatcher
operator|<
name|typename
name|Container
operator|::
name|value_type
operator|>
name|ElementsAreArray
argument_list|(
argument|const Container& container
argument_list|)
block|{
return|return
name|ElementsAreArray
argument_list|(
name|container
operator|.
name|begin
argument_list|()
argument_list|,
name|container
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_if
if|#
directive|if
name|GTEST_HAS_STD_INITIALIZER_LIST_
end_if

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|internal
operator|::
name|ElementsAreArrayMatcher
operator|<
name|T
operator|>
name|ElementsAreArray
argument_list|(
argument|::std::initializer_list<T> xs
argument_list|)
block|{
return|return
name|ElementsAreArray
argument_list|(
name|xs
operator|.
name|begin
argument_list|()
argument_list|,
name|xs
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// UnorderedElementsAreArray(first, last)
end_comment

begin_comment
comment|// UnorderedElementsAreArray(pointer, count)
end_comment

begin_comment
comment|// UnorderedElementsAreArray(array)
end_comment

begin_comment
comment|// UnorderedElementsAreArray(container)
end_comment

begin_comment
comment|// UnorderedElementsAreArray({ e1, e2, ..., en })
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The UnorderedElementsAreArray() functions are like
end_comment

begin_comment
comment|// ElementsAreArray(...), but allow matching the elements in any order.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Iter
operator|>
specifier|inline
name|internal
operator|::
name|UnorderedElementsAreArrayMatcher
operator|<
name|typename
operator|::
name|std
operator|::
name|iterator_traits
operator|<
name|Iter
operator|>
operator|::
name|value_type
operator|>
name|UnorderedElementsAreArray
argument_list|(
argument|Iter first
argument_list|,
argument|Iter last
argument_list|)
block|{
typedef|typedef
name|typename
operator|::
name|std
operator|::
name|iterator_traits
operator|<
name|Iter
operator|>
operator|::
name|value_type
name|T
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|internal
operator|::
name|UnorderedElementsAreArrayMatcher
operator|<
name|T
operator|>
operator|(
name|first
operator|,
name|last
operator|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|internal
operator|::
name|UnorderedElementsAreArrayMatcher
operator|<
name|T
operator|>
name|UnorderedElementsAreArray
argument_list|(
argument|const T* pointer
argument_list|,
argument|size_t count
argument_list|)
block|{
return|return
name|UnorderedElementsAreArray
argument_list|(
name|pointer
argument_list|,
name|pointer
operator|+
name|count
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|size_t
name|N
operator|>
specifier|inline
name|internal
operator|::
name|UnorderedElementsAreArrayMatcher
operator|<
name|T
operator|>
name|UnorderedElementsAreArray
argument_list|(
argument|const T (&array)[N]
argument_list|)
block|{
return|return
name|UnorderedElementsAreArray
argument_list|(
name|array
argument_list|,
name|N
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|Container
operator|>
specifier|inline
name|internal
operator|::
name|UnorderedElementsAreArrayMatcher
operator|<
name|typename
name|Container
operator|::
name|value_type
operator|>
name|UnorderedElementsAreArray
argument_list|(
argument|const Container& container
argument_list|)
block|{
return|return
name|UnorderedElementsAreArray
argument_list|(
name|container
operator|.
name|begin
argument_list|()
argument_list|,
name|container
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_if
if|#
directive|if
name|GTEST_HAS_STD_INITIALIZER_LIST_
end_if

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|internal
operator|::
name|UnorderedElementsAreArrayMatcher
operator|<
name|T
operator|>
name|UnorderedElementsAreArray
argument_list|(
argument|::std::initializer_list<T> xs
argument_list|)
block|{
return|return
name|UnorderedElementsAreArray
argument_list|(
name|xs
operator|.
name|begin
argument_list|()
argument_list|,
name|xs
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _ is a matcher that matches anything of any type.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This definition is fine as:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   1. The C++ standard permits using the name _ in a namespace that
end_comment

begin_comment
comment|//      is not the global namespace or ::std.
end_comment

begin_comment
comment|//   2. The AnythingMatcher class has no data member or constructor,
end_comment

begin_comment
comment|//      so it's OK to create global variables of this type.
end_comment

begin_comment
comment|//   3. c-style has approved of using _ in this case.
end_comment

begin_expr_stmt
specifier|const
name|internal
operator|::
name|AnythingMatcher
name|_
operator|=
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches any value of the given type T.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|Matcher
operator|<
name|T
operator|>
name|A
argument_list|()
block|{
return|return
name|MakeMatcher
argument_list|(
argument|new internal::AnyMatcherImpl<T>()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches any value of the given type T.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|Matcher
operator|<
name|T
operator|>
name|An
argument_list|()
block|{
return|return
name|A
operator|<
name|T
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic matcher that matches anything equal to x.
end_comment

begin_comment
comment|// Note: if the parameter of Eq() were declared as const T&, Eq("foo")
end_comment

begin_comment
comment|// wouldn't compile.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|internal
operator|::
name|EqMatcher
operator|<
name|T
operator|>
name|Eq
argument_list|(
argument|T x
argument_list|)
block|{
return|return
name|internal
operator|::
name|EqMatcher
operator|<
name|T
operator|>
operator|(
name|x
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Constructs a Matcher<T> from a 'value' of type T.  The constructed
end_comment

begin_comment
comment|// matcher matches any value that's equal to 'value'.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Matcher
operator|<
name|T
operator|>
operator|::
name|Matcher
argument_list|(
argument|T value
argument_list|)
block|{
operator|*
name|this
operator|=
name|Eq
argument_list|(
name|value
argument_list|)
block|; }
comment|// Creates a monomorphic matcher that matches anything with type Lhs
comment|// and equal to rhs.  A user may need to use this instead of Eq(...)
comment|// in order to resolve an overloading ambiguity.
comment|//
comment|// TypedEq<T>(x) is just a convenient short-hand for Matcher<T>(Eq(x))
comment|// or Matcher<T>(x), but more readable than the latter.
comment|//
comment|// We could define similar monomorphic matchers for other comparison
comment|// operations (e.g. TypedLt, TypedGe, and etc), but decided not to do
comment|// it yet as those are used much less than Eq() in practice.  A user
comment|// can always write Matcher<T>(Lt(5)) to be explicit about the type,
comment|// for example.
name|template
operator|<
name|typename
name|Lhs
operator|,
name|typename
name|Rhs
operator|>
specifier|inline
name|Matcher
operator|<
name|Lhs
operator|>
name|TypedEq
argument_list|(
argument|const Rhs& rhs
argument_list|)
block|{
return|return
name|Eq
argument_list|(
name|rhs
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic matcher that matches anything>= x.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Rhs
operator|>
specifier|inline
name|internal
operator|::
name|GeMatcher
operator|<
name|Rhs
operator|>
name|Ge
argument_list|(
argument|Rhs x
argument_list|)
block|{
return|return
name|internal
operator|::
name|GeMatcher
operator|<
name|Rhs
operator|>
operator|(
name|x
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic matcher that matches anything> x.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Rhs
operator|>
specifier|inline
name|internal
operator|::
name|GtMatcher
operator|<
name|Rhs
operator|>
name|Gt
argument_list|(
argument|Rhs x
argument_list|)
block|{
return|return
name|internal
operator|::
name|GtMatcher
operator|<
name|Rhs
operator|>
operator|(
name|x
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic matcher that matches anything<= x.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Rhs
operator|>
specifier|inline
name|internal
operator|::
name|LeMatcher
operator|<
name|Rhs
operator|>
name|Le
argument_list|(
argument|Rhs x
argument_list|)
block|{
return|return
name|internal
operator|::
name|LeMatcher
operator|<
name|Rhs
operator|>
operator|(
name|x
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic matcher that matches anything< x.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Rhs
operator|>
specifier|inline
name|internal
operator|::
name|LtMatcher
operator|<
name|Rhs
operator|>
name|Lt
argument_list|(
argument|Rhs x
argument_list|)
block|{
return|return
name|internal
operator|::
name|LtMatcher
operator|<
name|Rhs
operator|>
operator|(
name|x
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic matcher that matches anything != x.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Rhs
operator|>
specifier|inline
name|internal
operator|::
name|NeMatcher
operator|<
name|Rhs
operator|>
name|Ne
argument_list|(
argument|Rhs x
argument_list|)
block|{
return|return
name|internal
operator|::
name|NeMatcher
operator|<
name|Rhs
operator|>
operator|(
name|x
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic matcher that matches any NULL pointer.
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|IsNullMatcher
operator|>
name|IsNull
argument_list|()
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|IsNullMatcher
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic matcher that matches any non-NULL pointer.
end_comment

begin_comment
comment|// This is convenient as Not(NULL) doesn't compile (the compiler
end_comment

begin_comment
comment|// thinks that that expression is comparing a pointer with an integer).
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|NotNullMatcher
operator|>
name|NotNull
argument_list|()
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|NotNullMatcher
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic matcher that matches any argument that
end_comment

begin_comment
comment|// references variable x.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|internal
operator|::
name|RefMatcher
operator|<
name|T
operator|&
operator|>
name|Ref
argument_list|(
argument|T& x
argument_list|)
block|{
comment|// NOLINT
return|return
name|internal
operator|::
name|RefMatcher
operator|<
name|T
operator|&
operator|>
operator|(
name|x
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches any double argument approximately
end_comment

begin_comment
comment|// equal to rhs, where two NANs are considered unequal.
end_comment

begin_expr_stmt
specifier|inline
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|double
operator|>
name|DoubleEq
argument_list|(
argument|double rhs
argument_list|)
block|{
return|return
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|double
operator|>
operator|(
name|rhs
operator|,
name|false
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches any double argument approximately
end_comment

begin_comment
comment|// equal to rhs, including NaN values when rhs is NaN.
end_comment

begin_expr_stmt
specifier|inline
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|double
operator|>
name|NanSensitiveDoubleEq
argument_list|(
argument|double rhs
argument_list|)
block|{
return|return
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|double
operator|>
operator|(
name|rhs
operator|,
name|true
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches any double argument approximately equal to
end_comment

begin_comment
comment|// rhs, up to the specified max absolute error bound, where two NANs are
end_comment

begin_comment
comment|// considered unequal.  The max absolute error bound must be non-negative.
end_comment

begin_expr_stmt
specifier|inline
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|double
operator|>
name|DoubleNear
argument_list|(
argument|double rhs
argument_list|,
argument|double max_abs_error
argument_list|)
block|{
return|return
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|double
operator|>
operator|(
name|rhs
operator|,
name|false
operator|,
name|max_abs_error
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches any double argument approximately equal to
end_comment

begin_comment
comment|// rhs, up to the specified max absolute error bound, including NaN values when
end_comment

begin_comment
comment|// rhs is NaN.  The max absolute error bound must be non-negative.
end_comment

begin_expr_stmt
specifier|inline
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|double
operator|>
name|NanSensitiveDoubleNear
argument_list|(
argument|double rhs
argument_list|,
argument|double max_abs_error
argument_list|)
block|{
return|return
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|double
operator|>
operator|(
name|rhs
operator|,
name|true
operator|,
name|max_abs_error
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches any float argument approximately
end_comment

begin_comment
comment|// equal to rhs, where two NANs are considered unequal.
end_comment

begin_expr_stmt
specifier|inline
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|float
operator|>
name|FloatEq
argument_list|(
argument|float rhs
argument_list|)
block|{
return|return
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|float
operator|>
operator|(
name|rhs
operator|,
name|false
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches any float argument approximately
end_comment

begin_comment
comment|// equal to rhs, including NaN values when rhs is NaN.
end_comment

begin_expr_stmt
specifier|inline
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|float
operator|>
name|NanSensitiveFloatEq
argument_list|(
argument|float rhs
argument_list|)
block|{
return|return
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|float
operator|>
operator|(
name|rhs
operator|,
name|true
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches any float argument approximately equal to
end_comment

begin_comment
comment|// rhs, up to the specified max absolute error bound, where two NANs are
end_comment

begin_comment
comment|// considered unequal.  The max absolute error bound must be non-negative.
end_comment

begin_expr_stmt
specifier|inline
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|float
operator|>
name|FloatNear
argument_list|(
argument|float rhs
argument_list|,
argument|float max_abs_error
argument_list|)
block|{
return|return
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|float
operator|>
operator|(
name|rhs
operator|,
name|false
operator|,
name|max_abs_error
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches any float argument approximately equal to
end_comment

begin_comment
comment|// rhs, up to the specified max absolute error bound, including NaN values when
end_comment

begin_comment
comment|// rhs is NaN.  The max absolute error bound must be non-negative.
end_comment

begin_expr_stmt
specifier|inline
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|float
operator|>
name|NanSensitiveFloatNear
argument_list|(
argument|float rhs
argument_list|,
argument|float max_abs_error
argument_list|)
block|{
return|return
name|internal
operator|::
name|FloatingEqMatcher
operator|<
name|float
operator|>
operator|(
name|rhs
operator|,
name|true
operator|,
name|max_abs_error
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches a pointer (raw or smart) that points
end_comment

begin_comment
comment|// to a value that matches inner_matcher.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|InnerMatcher
operator|>
specifier|inline
name|internal
operator|::
name|PointeeMatcher
operator|<
name|InnerMatcher
operator|>
name|Pointee
argument_list|(
argument|const InnerMatcher& inner_matcher
argument_list|)
block|{
return|return
name|internal
operator|::
name|PointeeMatcher
operator|<
name|InnerMatcher
operator|>
operator|(
name|inner_matcher
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches a pointer or reference that matches
end_comment

begin_comment
comment|// inner_matcher when dynamic_cast<To> is applied.
end_comment

begin_comment
comment|// The result of dynamic_cast<To> is forwarded to the inner matcher.
end_comment

begin_comment
comment|// If To is a pointer and the cast fails, the inner matcher will receive NULL.
end_comment

begin_comment
comment|// If To is a reference and the cast fails, this matcher returns false
end_comment

begin_comment
comment|// immediately.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|To
operator|>
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|WhenDynamicCastToMatcher
operator|<
name|To
operator|>
expr|>
name|WhenDynamicCastTo
argument_list|(
argument|const Matcher<To>& inner_matcher
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|WhenDynamicCastToMatcher
operator|<
name|To
operator|>
operator|(
name|inner_matcher
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches an object whose given field matches
end_comment

begin_comment
comment|// 'matcher'.  For example,
end_comment

begin_comment
comment|//   Field(&Foo::number, Ge(5))
end_comment

begin_comment
comment|// matches a Foo object x iff x.number>= 5.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Class
operator|,
name|typename
name|FieldType
operator|,
name|typename
name|FieldMatcher
operator|>
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|FieldMatcher
operator|<
name|Class
operator|,
name|FieldType
operator|>
expr|>
name|Field
argument_list|(
argument|FieldType Class::*field
argument_list|,
argument|const FieldMatcher& matcher
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|FieldMatcher
operator|<
name|Class
argument_list|,
name|FieldType
operator|>
operator|(
name|field
operator|,
name|MatcherCast
operator|<
specifier|const
name|FieldType
operator|&
operator|>
operator|(
name|matcher
operator|)
operator|)
argument_list|)
return|;
comment|// The call to MatcherCast() is required for supporting inner
comment|// matchers of compatible types.  For example, it allows
comment|//   Field(&Foo::bar, m)
comment|// to compile where bar is an int32 and m is a matcher for int64.
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches an object whose given property
end_comment

begin_comment
comment|// matches 'matcher'.  For example,
end_comment

begin_comment
comment|//   Property(&Foo::str, StartsWith("hi"))
end_comment

begin_comment
comment|// matches a Foo object x iff x.str() starts with "hi".
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Class
operator|,
name|typename
name|PropertyType
operator|,
name|typename
name|PropertyMatcher
operator|>
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|PropertyMatcher
operator|<
name|Class
operator|,
name|PropertyType
operator|>
expr|>
name|Property
argument_list|(
argument|PropertyType (Class::*property)() const
argument_list|,
argument|const PropertyMatcher& matcher
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|PropertyMatcher
operator|<
name|Class
argument_list|,
name|PropertyType
operator|>
operator|(
name|property
operator|,
name|MatcherCast
operator|<
name|GTEST_REFERENCE_TO_CONST_
argument_list|(
name|PropertyType
argument_list|)
operator|>
operator|(
name|matcher
operator|)
operator|)
argument_list|)
return|;
comment|// The call to MatcherCast() is required for supporting inner
comment|// matchers of compatible types.  For example, it allows
comment|//   Property(&Foo::bar, m)
comment|// to compile where bar() returns an int32 and m is a matcher for int64.
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches an object iff the result of applying
end_comment

begin_comment
comment|// a callable to x matches 'matcher'.
end_comment

begin_comment
comment|// For example,
end_comment

begin_comment
comment|//   ResultOf(f, StartsWith("hi"))
end_comment

begin_comment
comment|// matches a Foo object x iff f(x) starts with "hi".
end_comment

begin_comment
comment|// callable parameter can be a function, function pointer, or a functor.
end_comment

begin_comment
comment|// Callable has to satisfy the following conditions:
end_comment

begin_comment
comment|//   * It is required to keep no state affecting the results of
end_comment

begin_comment
comment|//     the calls on it and make no assumptions about how many calls
end_comment

begin_comment
comment|//     will be made. Any state it keeps must be protected from the
end_comment

begin_comment
comment|//     concurrent access.
end_comment

begin_comment
comment|//   * If it is a function object, it has to define type result_type.
end_comment

begin_comment
comment|//     We recommend deriving your functor classes from std::unary_function.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Callable
operator|,
name|typename
name|ResultOfMatcher
operator|>
name|internal
operator|::
name|ResultOfMatcher
operator|<
name|Callable
operator|>
name|ResultOf
argument_list|(
argument|Callable callable
argument_list|,
argument|const ResultOfMatcher& matcher
argument_list|)
block|{
return|return
name|internal
operator|::
name|ResultOfMatcher
operator|<
name|Callable
operator|>
operator|(
name|callable
operator|,
name|MatcherCast
operator|<
name|typename
name|internal
operator|::
name|CallableTraits
operator|<
name|Callable
operator|>
operator|::
name|ResultType
operator|>
operator|(
name|matcher
operator|)
operator|)
return|;
comment|// The call to MatcherCast() is required for supporting inner
comment|// matchers of compatible types.  For example, it allows
comment|//   ResultOf(Function, m)
comment|// to compile where Function() returns an int32 and m is a matcher for int64.
block|}
end_expr_stmt

begin_comment
comment|// String matchers.
end_comment

begin_comment
comment|// Matches a string equal to str.
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|string
operator|>
expr|>
name|StrEq
argument_list|(
argument|const internal::string& str
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|string
operator|>
operator|(
name|str
operator|,
name|true
operator|,
name|true
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches a string not equal to str.
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|string
operator|>
expr|>
name|StrNe
argument_list|(
argument|const internal::string& str
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|string
operator|>
operator|(
name|str
operator|,
name|false
operator|,
name|true
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches a string equal to str, ignoring case.
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|string
operator|>
expr|>
name|StrCaseEq
argument_list|(
argument|const internal::string& str
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|string
operator|>
operator|(
name|str
operator|,
name|true
operator|,
name|false
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches a string not equal to str, ignoring case.
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|string
operator|>
expr|>
name|StrCaseNe
argument_list|(
argument|const internal::string& str
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|string
operator|>
operator|(
name|str
operator|,
name|false
operator|,
name|false
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches any string, std::string, or C string
end_comment

begin_comment
comment|// that contains the given substring.
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|HasSubstrMatcher
operator|<
name|internal
operator|::
name|string
operator|>
expr|>
name|HasSubstr
argument_list|(
argument|const internal::string& substring
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|HasSubstrMatcher
operator|<
name|internal
operator|::
name|string
operator|>
operator|(
name|substring
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches a string that starts with 'prefix' (case-sensitive).
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|StartsWithMatcher
operator|<
name|internal
operator|::
name|string
operator|>
expr|>
name|StartsWith
argument_list|(
argument|const internal::string& prefix
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|StartsWithMatcher
operator|<
name|internal
operator|::
name|string
operator|>
operator|(
name|prefix
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches a string that ends with 'suffix' (case-sensitive).
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|EndsWithMatcher
operator|<
name|internal
operator|::
name|string
operator|>
expr|>
name|EndsWith
argument_list|(
argument|const internal::string& suffix
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|EndsWithMatcher
operator|<
name|internal
operator|::
name|string
operator|>
operator|(
name|suffix
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches a string that fully matches regular expression 'regex'.
end_comment

begin_comment
comment|// The matcher takes ownership of 'regex'.
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|MatchesRegexMatcher
operator|>
name|MatchesRegex
argument_list|(
argument|const internal::RE* regex
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|MatchesRegexMatcher
argument_list|(
name|regex
argument_list|,
name|true
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|MatchesRegexMatcher
operator|>
name|MatchesRegex
argument_list|(
argument|const internal::string& regex
argument_list|)
block|{
return|return
name|MatchesRegex
argument_list|(
argument|new internal::RE(regex)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches a string that contains regular expression 'regex'.
end_comment

begin_comment
comment|// The matcher takes ownership of 'regex'.
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|MatchesRegexMatcher
operator|>
name|ContainsRegex
argument_list|(
argument|const internal::RE* regex
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|MatchesRegexMatcher
argument_list|(
name|regex
argument_list|,
name|false
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|MatchesRegexMatcher
operator|>
name|ContainsRegex
argument_list|(
argument|const internal::string& regex
argument_list|)
block|{
return|return
name|ContainsRegex
argument_list|(
argument|new internal::RE(regex)
argument_list|)
return|;
block|}
end_expr_stmt

begin_if
if|#
directive|if
name|GTEST_HAS_GLOBAL_WSTRING
operator|||
name|GTEST_HAS_STD_WSTRING
end_if

begin_comment
comment|// Wide string matchers.
end_comment

begin_comment
comment|// Matches a string equal to str.
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|wstring
operator|>
expr|>
name|StrEq
argument_list|(
argument|const internal::wstring& str
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|wstring
operator|>
operator|(
name|str
operator|,
name|true
operator|,
name|true
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches a string not equal to str.
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|wstring
operator|>
expr|>
name|StrNe
argument_list|(
argument|const internal::wstring& str
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|wstring
operator|>
operator|(
name|str
operator|,
name|false
operator|,
name|true
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches a string equal to str, ignoring case.
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|wstring
operator|>
expr|>
name|StrCaseEq
argument_list|(
argument|const internal::wstring& str
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|wstring
operator|>
operator|(
name|str
operator|,
name|true
operator|,
name|false
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches a string not equal to str, ignoring case.
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|wstring
operator|>
expr|>
name|StrCaseNe
argument_list|(
argument|const internal::wstring& str
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|StrEqualityMatcher
operator|<
name|internal
operator|::
name|wstring
operator|>
operator|(
name|str
operator|,
name|false
operator|,
name|false
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches any wstring, std::wstring, or C wide string
end_comment

begin_comment
comment|// that contains the given substring.
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|HasSubstrMatcher
operator|<
name|internal
operator|::
name|wstring
operator|>
expr|>
name|HasSubstr
argument_list|(
argument|const internal::wstring& substring
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|HasSubstrMatcher
operator|<
name|internal
operator|::
name|wstring
operator|>
operator|(
name|substring
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches a string that starts with 'prefix' (case-sensitive).
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|StartsWithMatcher
operator|<
name|internal
operator|::
name|wstring
operator|>
expr|>
name|StartsWith
argument_list|(
argument|const internal::wstring& prefix
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|StartsWithMatcher
operator|<
name|internal
operator|::
name|wstring
operator|>
operator|(
name|prefix
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches a string that ends with 'suffix' (case-sensitive).
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|EndsWithMatcher
operator|<
name|internal
operator|::
name|wstring
operator|>
expr|>
name|EndsWith
argument_list|(
argument|const internal::wstring& suffix
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|EndsWithMatcher
operator|<
name|internal
operator|::
name|wstring
operator|>
operator|(
name|suffix
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_GLOBAL_WSTRING || GTEST_HAS_STD_WSTRING
end_comment

begin_comment
comment|// Creates a polymorphic matcher that matches a 2-tuple where the
end_comment

begin_comment
comment|// first field == the second field.
end_comment

begin_expr_stmt
specifier|inline
name|internal
operator|::
name|Eq2Matcher
name|Eq
argument_list|()
block|{
return|return
name|internal
operator|::
name|Eq2Matcher
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic matcher that matches a 2-tuple where the
end_comment

begin_comment
comment|// first field>= the second field.
end_comment

begin_expr_stmt
specifier|inline
name|internal
operator|::
name|Ge2Matcher
name|Ge
argument_list|()
block|{
return|return
name|internal
operator|::
name|Ge2Matcher
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic matcher that matches a 2-tuple where the
end_comment

begin_comment
comment|// first field> the second field.
end_comment

begin_expr_stmt
specifier|inline
name|internal
operator|::
name|Gt2Matcher
name|Gt
argument_list|()
block|{
return|return
name|internal
operator|::
name|Gt2Matcher
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic matcher that matches a 2-tuple where the
end_comment

begin_comment
comment|// first field<= the second field.
end_comment

begin_expr_stmt
specifier|inline
name|internal
operator|::
name|Le2Matcher
name|Le
argument_list|()
block|{
return|return
name|internal
operator|::
name|Le2Matcher
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic matcher that matches a 2-tuple where the
end_comment

begin_comment
comment|// first field< the second field.
end_comment

begin_expr_stmt
specifier|inline
name|internal
operator|::
name|Lt2Matcher
name|Lt
argument_list|()
block|{
return|return
name|internal
operator|::
name|Lt2Matcher
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic matcher that matches a 2-tuple where the
end_comment

begin_comment
comment|// first field != the second field.
end_comment

begin_expr_stmt
specifier|inline
name|internal
operator|::
name|Ne2Matcher
name|Ne
argument_list|()
block|{
return|return
name|internal
operator|::
name|Ne2Matcher
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a matcher that matches any value of type T that m doesn't
end_comment

begin_comment
comment|// match.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|InnerMatcher
operator|>
specifier|inline
name|internal
operator|::
name|NotMatcher
operator|<
name|InnerMatcher
operator|>
name|Not
argument_list|(
argument|InnerMatcher m
argument_list|)
block|{
return|return
name|internal
operator|::
name|NotMatcher
operator|<
name|InnerMatcher
operator|>
operator|(
name|m
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns a matcher that matches anything that satisfies the given
end_comment

begin_comment
comment|// predicate.  The predicate can be any unary function or functor
end_comment

begin_comment
comment|// whose return type can be implicitly converted to bool.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Predicate
operator|>
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|TrulyMatcher
operator|<
name|Predicate
operator|>
expr|>
name|Truly
argument_list|(
argument|Predicate pred
argument_list|)
block|{
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|TrulyMatcher
operator|<
name|Predicate
operator|>
operator|(
name|pred
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns a matcher that matches the container size. The container must
end_comment

begin_comment
comment|// support both size() and size_type which all STL-like containers provide.
end_comment

begin_comment
comment|// Note that the parameter 'size' can be a value of type size_type as well as
end_comment

begin_comment
comment|// matcher. For instance:
end_comment

begin_comment
comment|//   EXPECT_THAT(container, SizeIs(2));     // Checks container has 2 elements.
end_comment

begin_comment
comment|//   EXPECT_THAT(container, SizeIs(Le(2));  // Checks container has at most 2.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|SizeMatcher
operator|>
specifier|inline
name|internal
operator|::
name|SizeIsMatcher
operator|<
name|SizeMatcher
operator|>
name|SizeIs
argument_list|(
argument|const SizeMatcher& size_matcher
argument_list|)
block|{
return|return
name|internal
operator|::
name|SizeIsMatcher
operator|<
name|SizeMatcher
operator|>
operator|(
name|size_matcher
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns a matcher that matches the distance between the container's begin()
end_comment

begin_comment
comment|// iterator and its end() iterator, i.e. the size of the container. This matcher
end_comment

begin_comment
comment|// can be used instead of SizeIs with containers such as std::forward_list which
end_comment

begin_comment
comment|// do not implement size(). The container must provide const_iterator (with
end_comment

begin_comment
comment|// valid iterator_traits), begin() and end().
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|DistanceMatcher
operator|>
specifier|inline
name|internal
operator|::
name|BeginEndDistanceIsMatcher
operator|<
name|DistanceMatcher
operator|>
name|BeginEndDistanceIs
argument_list|(
argument|const DistanceMatcher& distance_matcher
argument_list|)
block|{
return|return
name|internal
operator|::
name|BeginEndDistanceIsMatcher
operator|<
name|DistanceMatcher
operator|>
operator|(
name|distance_matcher
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns a matcher that matches an equal container.
end_comment

begin_comment
comment|// This matcher behaves like Eq(), but in the event of mismatch lists the
end_comment

begin_comment
comment|// values that are included in one container but not the other. (Duplicate
end_comment

begin_comment
comment|// values and order differences are not explained.)
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Container
operator|>
specifier|inline
name|PolymorphicMatcher
operator|<
name|internal
operator|::
name|ContainerEqMatcher
operator|<
comment|// NOLINT
name|GTEST_REMOVE_CONST_
argument_list|(
name|Container
argument_list|)
operator|>
expr|>
name|ContainerEq
argument_list|(
argument|const Container& rhs
argument_list|)
block|{
comment|// This following line is for working around a bug in MSVC 8.0,
comment|// which causes Container to be a const type sometimes.
typedef|typedef
name|GTEST_REMOVE_CONST_
argument_list|(
argument|Container
argument_list|)
name|RawContainer
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|MakePolymorphicMatcher
argument_list|(
name|internal
operator|::
name|ContainerEqMatcher
operator|<
name|RawContainer
operator|>
operator|(
name|rhs
operator|)
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|// Returns a matcher that matches a container that, when sorted using
end_comment

begin_comment
comment|// the given comparator, matches container_matcher.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Comparator
operator|,
name|typename
name|ContainerMatcher
operator|>
specifier|inline
name|internal
operator|::
name|WhenSortedByMatcher
operator|<
name|Comparator
operator|,
name|ContainerMatcher
operator|>
name|WhenSortedBy
argument_list|(
argument|const Comparator& comparator
argument_list|,
argument|const ContainerMatcher& container_matcher
argument_list|)
block|{
return|return
name|internal
operator|::
name|WhenSortedByMatcher
operator|<
name|Comparator
operator|,
name|ContainerMatcher
operator|>
operator|(
name|comparator
operator|,
name|container_matcher
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns a matcher that matches a container that, when sorted using
end_comment

begin_comment
comment|// the< operator, matches container_matcher.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ContainerMatcher
operator|>
specifier|inline
name|internal
operator|::
name|WhenSortedByMatcher
operator|<
name|internal
operator|::
name|LessComparator
operator|,
name|ContainerMatcher
operator|>
name|WhenSorted
argument_list|(
argument|const ContainerMatcher& container_matcher
argument_list|)
block|{
return|return
name|internal
operator|::
name|WhenSortedByMatcher
operator|<
name|internal
operator|::
name|LessComparator
operator|,
name|ContainerMatcher
operator|>
operator|(
name|internal
operator|::
name|LessComparator
argument_list|()
operator|,
name|container_matcher
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches an STL-style container or a native array that contains the
end_comment

begin_comment
comment|// same number of elements as in rhs, where its i-th element and rhs's
end_comment

begin_comment
comment|// i-th element (as a pair) satisfy the given pair matcher, for all i.
end_comment

begin_comment
comment|// TupleMatcher must be able to be safely cast to Matcher<tuple<const
end_comment

begin_comment
comment|// T1&, const T2&>>, where T1 and T2 are the types of elements in the
end_comment

begin_comment
comment|// LHS container and the RHS container respectively.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|TupleMatcher
operator|,
name|typename
name|Container
operator|>
specifier|inline
name|internal
operator|::
name|PointwiseMatcher
operator|<
name|TupleMatcher
operator|,
name|GTEST_REMOVE_CONST_
argument_list|(
name|Container
argument_list|)
operator|>
name|Pointwise
argument_list|(
argument|const TupleMatcher& tuple_matcher
argument_list|,
argument|const Container& rhs
argument_list|)
block|{
comment|// This following line is for working around a bug in MSVC 8.0,
comment|// which causes Container to be a const type sometimes (e.g. when
comment|// rhs is a const int[])..
typedef|typedef
name|GTEST_REMOVE_CONST_
argument_list|(
argument|Container
argument_list|)
name|RawContainer
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|internal
operator|::
name|PointwiseMatcher
operator|<
name|TupleMatcher
operator|,
name|RawContainer
operator|>
operator|(
name|tuple_matcher
operator|,
name|rhs
operator|)
return|;
end_return

begin_if
unit|}
if|#
directive|if
name|GTEST_HAS_STD_INITIALIZER_LIST_
end_if

begin_comment
comment|// Supports the Pointwise(m, {a, b, c}) syntax.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|TupleMatcher
operator|,
name|typename
name|T
operator|>
specifier|inline
name|internal
operator|::
name|PointwiseMatcher
operator|<
name|TupleMatcher
operator|,
name|std
operator|::
name|vector
operator|<
name|T
operator|>
expr|>
name|Pointwise
argument_list|(
argument|const TupleMatcher& tuple_matcher
argument_list|,
argument|std::initializer_list<T> rhs
argument_list|)
block|{
return|return
name|Pointwise
argument_list|(
name|tuple_matcher
argument_list|,
name|std
operator|::
name|vector
operator|<
name|T
operator|>
operator|(
name|rhs
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_STD_INITIALIZER_LIST_
end_comment

begin_comment
comment|// UnorderedPointwise(pair_matcher, rhs) matches an STL-style
end_comment

begin_comment
comment|// container or a native array that contains the same number of
end_comment

begin_comment
comment|// elements as in rhs, where in some permutation of the container, its
end_comment

begin_comment
comment|// i-th element and rhs's i-th element (as a pair) satisfy the given
end_comment

begin_comment
comment|// pair matcher, for all i.  Tuple2Matcher must be able to be safely
end_comment

begin_comment
comment|// cast to Matcher<tuple<const T1&, const T2&>>, where T1 and T2 are
end_comment

begin_comment
comment|// the types of elements in the LHS container and the RHS container
end_comment

begin_comment
comment|// respectively.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is like Pointwise(pair_matcher, rhs), except that the element
end_comment

begin_comment
comment|// order doesn't matter.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Tuple2Matcher
operator|,
name|typename
name|RhsContainer
operator|>
specifier|inline
name|internal
operator|::
name|UnorderedElementsAreArrayMatcher
operator|<
name|typename
name|internal
operator|::
name|BoundSecondMatcher
operator|<
name|Tuple2Matcher
operator|,
name|typename
name|internal
operator|::
name|StlContainerView
operator|<
name|GTEST_REMOVE_CONST_
argument_list|(
name|RhsContainer
argument_list|)
operator|>
operator|::
name|type
operator|::
name|value_type
operator|>
expr|>
name|UnorderedPointwise
argument_list|(
argument|const Tuple2Matcher& tuple2_matcher
argument_list|,
argument|const RhsContainer& rhs_container
argument_list|)
block|{
comment|// This following line is for working around a bug in MSVC 8.0,
comment|// which causes RhsContainer to be a const type sometimes (e.g. when
comment|// rhs_container is a const int[]).
typedef|typedef
name|GTEST_REMOVE_CONST_
argument_list|(
argument|RhsContainer
argument_list|)
name|RawRhsContainer
expr_stmt|;
end_expr_stmt

begin_comment
comment|// RhsView allows the same code to handle RhsContainer being a
end_comment

begin_comment
comment|// STL-style container and it being a native C-style array.
end_comment

begin_typedef
typedef|typedef
name|typename
name|internal
operator|::
name|StlContainerView
operator|<
name|RawRhsContainer
operator|>
name|RhsView
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|RhsView
operator|::
name|type
name|RhsStlContainer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|RhsStlContainer
operator|::
name|value_type
name|Second
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|const
name|RhsStlContainer
modifier|&
name|rhs_stl_container
init|=
name|RhsView
operator|::
name|ConstReference
argument_list|(
name|rhs_container
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Create a matcher for each element in rhs_container.
end_comment

begin_expr_stmt
operator|::
name|std
operator|::
name|vector
operator|<
name|internal
operator|::
name|BoundSecondMatcher
operator|<
name|Tuple2Matcher
operator|,
name|Second
operator|>
expr|>
name|matchers
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|typename
name|RhsStlContainer
operator|::
name|const_iterator
name|it
operator|=
name|rhs_stl_container
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|rhs_stl_container
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|matchers
operator|.
name|push_back
argument_list|(
name|internal
operator|::
name|MatcherBindSecond
argument_list|(
name|tuple2_matcher
argument_list|,
operator|*
name|it
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_comment
comment|// Delegate the work to UnorderedElementsAreArray().
end_comment

begin_return
return|return
name|UnorderedElementsAreArray
argument_list|(
name|matchers
argument_list|)
return|;
end_return

begin_if
unit|}
if|#
directive|if
name|GTEST_HAS_STD_INITIALIZER_LIST_
end_if

begin_comment
comment|// Supports the UnorderedPointwise(m, {a, b, c}) syntax.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Tuple2Matcher
operator|,
name|typename
name|T
operator|>
specifier|inline
name|internal
operator|::
name|UnorderedElementsAreArrayMatcher
operator|<
name|typename
name|internal
operator|::
name|BoundSecondMatcher
operator|<
name|Tuple2Matcher
operator|,
name|T
operator|>
expr|>
name|UnorderedPointwise
argument_list|(
argument|const Tuple2Matcher& tuple2_matcher
argument_list|,
argument|std::initializer_list<T> rhs
argument_list|)
block|{
return|return
name|UnorderedPointwise
argument_list|(
name|tuple2_matcher
argument_list|,
name|std
operator|::
name|vector
operator|<
name|T
operator|>
operator|(
name|rhs
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_STD_INITIALIZER_LIST_
end_comment

begin_comment
comment|// Matches an STL-style container or a native array that contains at
end_comment

begin_comment
comment|// least one element matching the given value or matcher.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Examples:
end_comment

begin_comment
comment|//   ::std::set<int> page_ids;
end_comment

begin_comment
comment|//   page_ids.insert(3);
end_comment

begin_comment
comment|//   page_ids.insert(1);
end_comment

begin_comment
comment|//   EXPECT_THAT(page_ids, Contains(1));
end_comment

begin_comment
comment|//   EXPECT_THAT(page_ids, Contains(Gt(2)));
end_comment

begin_comment
comment|//   EXPECT_THAT(page_ids, Not(Contains(4)));
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   ::std::map<int, size_t> page_lengths;
end_comment

begin_comment
comment|//   page_lengths[1] = 100;
end_comment

begin_comment
comment|//   EXPECT_THAT(page_lengths,
end_comment

begin_comment
comment|//               Contains(::std::pair<const int, size_t>(1, 100)));
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   const char* user_ids[] = { "joe", "mike", "tom" };
end_comment

begin_comment
comment|//   EXPECT_THAT(user_ids, Contains(Eq(::std::string("tom"))));
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|M
operator|>
specifier|inline
name|internal
operator|::
name|ContainsMatcher
operator|<
name|M
operator|>
name|Contains
argument_list|(
argument|M matcher
argument_list|)
block|{
return|return
name|internal
operator|::
name|ContainsMatcher
operator|<
name|M
operator|>
operator|(
name|matcher
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches an STL-style container or a native array that contains only
end_comment

begin_comment
comment|// elements matching the given value or matcher.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Each(m) is semantically equivalent to Not(Contains(Not(m))). Only
end_comment

begin_comment
comment|// the messages are different.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Examples:
end_comment

begin_comment
comment|//   ::std::set<int> page_ids;
end_comment

begin_comment
comment|//   // Each(m) matches an empty container, regardless of what m is.
end_comment

begin_comment
comment|//   EXPECT_THAT(page_ids, Each(Eq(1)));
end_comment

begin_comment
comment|//   EXPECT_THAT(page_ids, Each(Eq(77)));
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   page_ids.insert(3);
end_comment

begin_comment
comment|//   EXPECT_THAT(page_ids, Each(Gt(0)));
end_comment

begin_comment
comment|//   EXPECT_THAT(page_ids, Not(Each(Gt(4))));
end_comment

begin_comment
comment|//   page_ids.insert(1);
end_comment

begin_comment
comment|//   EXPECT_THAT(page_ids, Not(Each(Lt(2))));
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   ::std::map<int, size_t> page_lengths;
end_comment

begin_comment
comment|//   page_lengths[1] = 100;
end_comment

begin_comment
comment|//   page_lengths[2] = 200;
end_comment

begin_comment
comment|//   page_lengths[3] = 300;
end_comment

begin_comment
comment|//   EXPECT_THAT(page_lengths, Not(Each(Pair(1, 100))));
end_comment

begin_comment
comment|//   EXPECT_THAT(page_lengths, Each(Key(Le(3))));
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   const char* user_ids[] = { "joe", "mike", "tom" };
end_comment

begin_comment
comment|//   EXPECT_THAT(user_ids, Not(Each(Eq(::std::string("tom")))));
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|M
operator|>
specifier|inline
name|internal
operator|::
name|EachMatcher
operator|<
name|M
operator|>
name|Each
argument_list|(
argument|M matcher
argument_list|)
block|{
return|return
name|internal
operator|::
name|EachMatcher
operator|<
name|M
operator|>
operator|(
name|matcher
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Key(inner_matcher) matches an std::pair whose 'first' field matches
end_comment

begin_comment
comment|// inner_matcher.  For example, Contains(Key(Ge(5))) can be used to match an
end_comment

begin_comment
comment|// std::map that contains at least one element whose key is>= 5.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|M
operator|>
specifier|inline
name|internal
operator|::
name|KeyMatcher
operator|<
name|M
operator|>
name|Key
argument_list|(
argument|M inner_matcher
argument_list|)
block|{
return|return
name|internal
operator|::
name|KeyMatcher
operator|<
name|M
operator|>
operator|(
name|inner_matcher
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Pair(first_matcher, second_matcher) matches a std::pair whose 'first' field
end_comment

begin_comment
comment|// matches first_matcher and whose 'second' field matches second_matcher.  For
end_comment

begin_comment
comment|// example, EXPECT_THAT(map_type, ElementsAre(Pair(Ge(5), "foo"))) can be used
end_comment

begin_comment
comment|// to match a std::map<int, string> that contains exactly one element whose key
end_comment

begin_comment
comment|// is>= 5 and whose value equals "foo".
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|FirstMatcher
operator|,
name|typename
name|SecondMatcher
operator|>
specifier|inline
name|internal
operator|::
name|PairMatcher
operator|<
name|FirstMatcher
operator|,
name|SecondMatcher
operator|>
name|Pair
argument_list|(
argument|FirstMatcher first_matcher
argument_list|,
argument|SecondMatcher second_matcher
argument_list|)
block|{
return|return
name|internal
operator|::
name|PairMatcher
operator|<
name|FirstMatcher
operator|,
name|SecondMatcher
operator|>
operator|(
name|first_matcher
operator|,
name|second_matcher
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns a predicate that is satisfied by anything that matches the
end_comment

begin_comment
comment|// given matcher.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|M
operator|>
specifier|inline
name|internal
operator|::
name|MatcherAsPredicate
operator|<
name|M
operator|>
name|Matches
argument_list|(
argument|M matcher
argument_list|)
block|{
return|return
name|internal
operator|::
name|MatcherAsPredicate
operator|<
name|M
operator|>
operator|(
name|matcher
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns true iff the value matches the matcher.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|M
operator|>
specifier|inline
name|bool
name|Value
argument_list|(
argument|const T& value
argument_list|,
argument|M matcher
argument_list|)
block|{
return|return
name|testing
operator|::
name|Matches
argument_list|(
name|matcher
argument_list|)
argument_list|(
name|value
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Matches the value against the given matcher and explains the match
end_comment

begin_comment
comment|// result to listener.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|M
operator|>
specifier|inline
name|bool
name|ExplainMatchResult
argument_list|(
argument|M matcher
argument_list|,
argument|const T& value
argument_list|,
argument|MatchResultListener* listener
argument_list|)
block|{
return|return
name|SafeMatcherCast
operator|<
specifier|const
name|T
operator|&
operator|>
operator|(
name|matcher
operator|)
operator|.
name|MatchAndExplain
argument_list|(
name|value
argument_list|,
name|listener
argument_list|)
return|;
block|}
end_expr_stmt

begin_if
if|#
directive|if
name|GTEST_LANG_CXX11
end_if

begin_comment
comment|// Define variadic matcher versions. They are overloaded in
end_comment

begin_comment
comment|// gmock-generated-matchers.h for the cases supported by pre C++11 compilers.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Args
operator|>
specifier|inline
name|internal
operator|::
name|AllOfMatcher
operator|<
name|Args
operator|...
operator|>
name|AllOf
argument_list|(
argument|const Args&... matchers
argument_list|)
block|{
return|return
name|internal
operator|::
name|AllOfMatcher
operator|<
name|Args
operator|...
operator|>
operator|(
name|matchers
operator|...
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Args
operator|>
specifier|inline
name|internal
operator|::
name|AnyOfMatcher
operator|<
name|Args
operator|...
operator|>
name|AnyOf
argument_list|(
argument|const Args&... matchers
argument_list|)
block|{
return|return
name|internal
operator|::
name|AnyOfMatcher
operator|<
name|Args
operator|...
operator|>
operator|(
name|matchers
operator|...
operator|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_LANG_CXX11
end_comment

begin_comment
comment|// AllArgs(m) is a synonym of m.  This is useful in
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   EXPECT_CALL(foo, Bar(_, _)).With(AllArgs(Eq()));
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// which is easier to read than
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   EXPECT_CALL(foo, Bar(_, _)).With(Eq());
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|InnerMatcher
operator|>
specifier|inline
name|InnerMatcher
name|AllArgs
argument_list|(
argument|const InnerMatcher& matcher
argument_list|)
block|{
return|return
name|matcher
return|;
block|}
end_expr_stmt

begin_comment
comment|// These macros allow using matchers to check values in Google Test
end_comment

begin_comment
comment|// tests.  ASSERT_THAT(value, matcher) and EXPECT_THAT(value, matcher)
end_comment

begin_comment
comment|// succeed iff the value matches the matcher.  If the assertion fails,
end_comment

begin_comment
comment|// the value and the description of the matcher will be printed.
end_comment

begin_define
define|#
directive|define
name|ASSERT_THAT
parameter_list|(
name|value
parameter_list|,
name|matcher
parameter_list|)
value|ASSERT_PRED_FORMAT1(\     ::testing::internal::MakePredicateFormatterFromMatcher(matcher), value)
end_define

begin_define
define|#
directive|define
name|EXPECT_THAT
parameter_list|(
name|value
parameter_list|,
name|matcher
parameter_list|)
value|EXPECT_PRED_FORMAT1(\     ::testing::internal::MakePredicateFormatterFromMatcher(matcher), value)
end_define

begin_comment
unit|}
comment|// namespace testing
end_comment

begin_comment
comment|// Include any custom callback matchers added by the local installation.
end_comment

begin_comment
comment|// We must include this header at the end to make sure it can use the
end_comment

begin_comment
comment|// declarations from this file.
end_comment

begin_include
include|#
directive|include
file|"gmock/internal/custom/gmock-matchers.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GMOCK_INCLUDE_GMOCK_GMOCK_MATCHERS_H_
end_comment

end_unit

