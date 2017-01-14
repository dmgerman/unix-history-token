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
comment|// This file implements some commonly used cardinalities.  More
end_comment

begin_comment
comment|// cardinalities can be defined by the user implementing the
end_comment

begin_comment
comment|// CardinalityInterface interface if necessary.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GMOCK_INCLUDE_GMOCK_GMOCK_CARDINALITIES_H_
end_ifndef

begin_define
define|#
directive|define
name|GMOCK_INCLUDE_GMOCK_GMOCK_CARDINALITIES_H_
end_define

begin_include
include|#
directive|include
file|<limits.h>
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
comment|// To implement a cardinality Foo, define:
comment|//   1. a class FooCardinality that implements the
comment|//      CardinalityInterface interface, and
comment|//   2. a factory function that creates a Cardinality object from a
comment|//      const FooCardinality*.
comment|//
comment|// The two-level delegation design follows that of Matcher, providing
comment|// consistency for extension developers.  It also eases ownership
comment|// management as Cardinality objects can now be copied like plain values.
comment|// The implementation of a cardinality.
name|class
name|CardinalityInterface
block|{
name|public
label|:
name|virtual
operator|~
name|CardinalityInterface
argument_list|()
block|{}
comment|// Conservative estimate on the lower/upper bound of the number of
comment|// calls allowed.
name|virtual
name|int
name|ConservativeLowerBound
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|int
name|ConservativeUpperBound
argument_list|()
specifier|const
block|{
return|return
name|INT_MAX
return|;
block|}
comment|// Returns true iff call_count calls will satisfy this cardinality.
name|virtual
name|bool
name|IsSatisfiedByCallCount
argument_list|(
name|int
name|call_count
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// Returns true iff call_count calls will saturate this cardinality.
name|virtual
name|bool
name|IsSaturatedByCallCount
argument_list|(
name|int
name|call_count
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// Describes self to an ostream.
name|virtual
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
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|// A Cardinality is a copyable and IMMUTABLE (except by assignment)
comment|// object that specifies how many times a mock function is expected to
comment|// be called.  The implementation of Cardinality is just a linked_ptr
comment|// to const CardinalityInterface, so copying is fairly cheap.
comment|// Don't inherit from Cardinality!
name|class
name|GTEST_API_
name|Cardinality
block|{
name|public
label|:
comment|// Constructs a null cardinality.  Needed for storing Cardinality
comment|// objects in STL containers.
name|Cardinality
argument_list|()
block|{}
comment|// Constructs a Cardinality from its implementation.
name|explicit
name|Cardinality
argument_list|(
specifier|const
name|CardinalityInterface
operator|*
name|impl
argument_list|)
operator|:
name|impl_
argument_list|(
argument|impl
argument_list|)
block|{}
comment|// Conservative estimate on the lower/upper bound of the number of
comment|// calls allowed.
name|int
name|ConservativeLowerBound
argument_list|()
specifier|const
block|{
return|return
name|impl_
operator|->
name|ConservativeLowerBound
argument_list|()
return|;
block|}
name|int
name|ConservativeUpperBound
argument_list|()
specifier|const
block|{
return|return
name|impl_
operator|->
name|ConservativeUpperBound
argument_list|()
return|;
block|}
comment|// Returns true iff call_count calls will satisfy this cardinality.
name|bool
name|IsSatisfiedByCallCount
argument_list|(
name|int
name|call_count
argument_list|)
decl|const
block|{
return|return
name|impl_
operator|->
name|IsSatisfiedByCallCount
argument_list|(
name|call_count
argument_list|)
return|;
block|}
comment|// Returns true iff call_count calls will saturate this cardinality.
name|bool
name|IsSaturatedByCallCount
argument_list|(
name|int
name|call_count
argument_list|)
decl|const
block|{
return|return
name|impl_
operator|->
name|IsSaturatedByCallCount
argument_list|(
name|call_count
argument_list|)
return|;
block|}
comment|// Returns true iff call_count calls will over-saturate this
comment|// cardinality, i.e. exceed the maximum number of allowed calls.
name|bool
name|IsOverSaturatedByCallCount
argument_list|(
name|int
name|call_count
argument_list|)
decl|const
block|{
return|return
name|impl_
operator|->
name|IsSaturatedByCallCount
argument_list|(
name|call_count
argument_list|)
operator|&&
operator|!
name|impl_
operator|->
name|IsSatisfiedByCallCount
argument_list|(
name|call_count
argument_list|)
return|;
block|}
comment|// Describes self to an ostream
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
name|impl_
operator|->
name|DescribeTo
argument_list|(
name|os
argument_list|)
expr_stmt|;
block|}
comment|// Describes the given actual call count to an ostream.
specifier|static
name|void
name|DescribeActualCallCountTo
argument_list|(
name|int
name|actual_call_count
argument_list|,
operator|::
name|std
operator|::
name|ostream
operator|*
name|os
argument_list|)
decl_stmt|;
name|private
label|:
name|internal
operator|::
name|linked_ptr
operator|<
specifier|const
name|CardinalityInterface
operator|>
name|impl_
expr_stmt|;
block|}
empty_stmt|;
comment|// Creates a cardinality that allows at least n calls.
name|GTEST_API_
name|Cardinality
name|AtLeast
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
comment|// Creates a cardinality that allows at most n calls.
name|GTEST_API_
name|Cardinality
name|AtMost
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
comment|// Creates a cardinality that allows any number of calls.
name|GTEST_API_
name|Cardinality
name|AnyNumber
parameter_list|()
function_decl|;
comment|// Creates a cardinality that allows between min and max calls.
name|GTEST_API_
name|Cardinality
name|Between
parameter_list|(
name|int
name|min
parameter_list|,
name|int
name|max
parameter_list|)
function_decl|;
comment|// Creates a cardinality that allows exactly n calls.
name|GTEST_API_
name|Cardinality
name|Exactly
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
comment|// Creates a cardinality from its implementation.
specifier|inline
name|Cardinality
name|MakeCardinality
parameter_list|(
specifier|const
name|CardinalityInterface
modifier|*
name|c
parameter_list|)
block|{
return|return
name|Cardinality
argument_list|(
name|c
argument_list|)
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
comment|// GMOCK_INCLUDE_GMOCK_GMOCK_CARDINALITIES_H_
end_comment

end_unit

