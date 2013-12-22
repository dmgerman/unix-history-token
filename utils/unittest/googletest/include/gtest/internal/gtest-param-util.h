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
comment|// Author: vladl@google.com (Vlad Losev)
end_comment

begin_comment
comment|// Type and function utilities for implementing parameterized tests.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_PARAM_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_PARAM_UTIL_H_
end_define

begin_include
include|#
directive|include
file|<iterator>
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

begin_comment
comment|// scripts/fuse_gtest.py depends on gtest's own header being #included
end_comment

begin_comment
comment|// *unconditionally*.  Therefore these #includes cannot be moved
end_comment

begin_comment
comment|// inside #if GTEST_HAS_PARAM_TEST.
end_comment

begin_include
include|#
directive|include
file|"gtest/internal/gtest-internal.h"
end_include

begin_include
include|#
directive|include
file|"gtest/internal/gtest-linked_ptr.h"
end_include

begin_include
include|#
directive|include
file|"gtest/internal/gtest-port.h"
end_include

begin_include
include|#
directive|include
file|"gtest/gtest-printers.h"
end_include

begin_if
if|#
directive|if
name|GTEST_HAS_PARAM_TEST
end_if

begin_decl_stmt
name|namespace
name|testing
block|{
name|namespace
name|internal
block|{
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN USER CODE.
comment|//
comment|// Outputs a message explaining invalid registration of different
comment|// fixture class for the same test case. This may happen when
comment|// TEST_P macro is used to define two tests with the same name
comment|// but in different namespaces.
name|GTEST_API_
name|void
name|ReportInvalidTestCaseType
parameter_list|(
specifier|const
name|char
modifier|*
name|test_case_name
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
operator|>
name|class
name|ParamGeneratorInterface
expr_stmt|;
name|template
operator|<
name|typename
operator|>
name|class
name|ParamGenerator
expr_stmt|;
comment|// Interface for iterating over elements provided by an implementation
comment|// of ParamGeneratorInterface<T>.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ParamIteratorInterface
block|{
name|public
operator|:
name|virtual
operator|~
name|ParamIteratorInterface
argument_list|()
block|{}
comment|// A pointer to the base generator instance.
comment|// Used only for the purposes of iterator comparison
comment|// to make sure that two iterators belong to the same generator.
name|virtual
specifier|const
name|ParamGeneratorInterface
operator|<
name|T
operator|>
operator|*
name|BaseGenerator
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|// Advances iterator to point to the next element
comment|// provided by the generator. The caller is responsible
comment|// for not calling Advance() on an iterator equal to
comment|// BaseGenerator()->End().
name|virtual
name|void
name|Advance
argument_list|()
operator|=
literal|0
block|;
comment|// Clones the iterator object. Used for implementing copy semantics
comment|// of ParamIterator<T>.
name|virtual
name|ParamIteratorInterface
operator|*
name|Clone
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|// Dereferences the current iterator and provides (read-only) access
comment|// to the pointed value. It is the caller's responsibility not to call
comment|// Current() on an iterator equal to BaseGenerator()->End().
comment|// Used for implementing ParamGenerator<T>::operator*().
name|virtual
specifier|const
name|T
operator|*
name|Current
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|// Determines whether the given iterator and other point to the same
comment|// element in the sequence generated by the generator.
comment|// Used for implementing ParamGenerator<T>::operator==().
name|virtual
name|bool
name|Equals
argument_list|(
argument|const ParamIteratorInterface& other
argument_list|)
specifier|const
operator|=
literal|0
block|; }
expr_stmt|;
comment|// Class iterating over elements provided by an implementation of
comment|// ParamGeneratorInterface<T>. It wraps ParamIteratorInterface<T>
comment|// and implements the const forward iterator concept.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ParamIterator
block|{
name|public
operator|:
typedef|typedef
name|T
name|value_type
typedef|;
typedef|typedef
specifier|const
name|T
modifier|&
name|reference
typedef|;
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
comment|// ParamIterator assumes ownership of the impl_ pointer.
name|ParamIterator
argument_list|(
specifier|const
name|ParamIterator
operator|&
name|other
argument_list|)
operator|:
name|impl_
argument_list|(
argument|other.impl_->Clone()
argument_list|)
block|{}
name|ParamIterator
operator|&
name|operator
operator|=
operator|(
specifier|const
name|ParamIterator
operator|&
name|other
operator|)
block|{
if|if
condition|(
name|this
operator|!=
operator|&
name|other
condition|)
name|impl_
operator|.
name|reset
argument_list|(
name|other
operator|.
name|impl_
operator|->
name|Clone
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
specifier|const
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|impl_
operator|->
name|Current
argument_list|()
return|;
block|}
specifier|const
name|T
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|impl_
operator|->
name|Current
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|// Prefix version of operator++.
end_comment

begin_expr_stmt
name|ParamIterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|impl_
operator|->
name|Advance
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|// Postfix version of operator++.
end_comment

begin_expr_stmt
name|ParamIterator
name|operator
operator|++
operator|(
name|int
comment|/*unused*/
operator|)
block|{
name|ParamIteratorInterface
operator|<
name|T
operator|>
operator|*
name|clone
operator|=
name|impl_
operator|->
name|Clone
argument_list|()
block|;
name|impl_
operator|->
name|Advance
argument_list|()
block|;
return|return
name|ParamIterator
argument_list|(
name|clone
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ParamIterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|impl_
operator|.
name|get
argument_list|()
operator|==
name|other
operator|.
name|impl_
operator|.
name|get
argument_list|()
operator|||
name|impl_
operator|->
name|Equals
argument_list|(
operator|*
name|other
operator|.
name|impl_
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ParamIterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|friend
name|class
name|ParamGenerator
operator|<
name|T
operator|>
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|explicit
name|ParamIterator
argument_list|(
name|ParamIteratorInterface
operator|<
name|T
operator|>
operator|*
name|impl
argument_list|)
range|:
name|impl_
argument_list|(
argument|impl
argument_list|)
block|{}
name|scoped_ptr
operator|<
name|ParamIteratorInterface
operator|<
name|T
operator|>
expr|>
name|impl_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// ParamGeneratorInterface<T> is the binary interface to access generators
end_comment

begin_comment
comment|// defined in other translation units.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ParamGeneratorInterface
block|{
name|public
operator|:
typedef|typedef
name|T
name|ParamType
typedef|;
name|virtual
operator|~
name|ParamGeneratorInterface
argument_list|()
block|{}
comment|// Generator interface definition
name|virtual
name|ParamIteratorInterface
operator|<
name|T
operator|>
operator|*
name|Begin
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
name|ParamIteratorInterface
operator|<
name|T
operator|>
operator|*
name|End
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Wraps ParamGeneratorInterface<T> and provides general generator syntax
end_comment

begin_comment
comment|// compatible with the STL Container concept.
end_comment

begin_comment
comment|// This class implements copy initialization semantics and the contained
end_comment

begin_comment
comment|// ParamGeneratorInterface<T> instance is shared among all copies
end_comment

begin_comment
comment|// of the original object. This is possible because that instance is immutable.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ParamGenerator
block|{
name|public
operator|:
typedef|typedef
name|ParamIterator
operator|<
name|T
operator|>
name|iterator
expr_stmt|;
name|explicit
name|ParamGenerator
argument_list|(
name|ParamGeneratorInterface
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
name|ParamGenerator
argument_list|(
specifier|const
name|ParamGenerator
operator|&
name|other
argument_list|)
operator|:
name|impl_
argument_list|(
argument|other.impl_
argument_list|)
block|{}
name|ParamGenerator
operator|&
name|operator
operator|=
operator|(
specifier|const
name|ParamGenerator
operator|&
name|other
operator|)
block|{
name|impl_
operator|=
name|other
operator|.
name|impl_
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|(
name|impl_
operator|->
name|Begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|(
name|impl_
operator|->
name|End
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|linked_ptr
operator|<
specifier|const
name|ParamGeneratorInterface
operator|<
name|T
operator|>
expr|>
name|impl_
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Generates values from a range of two comparable values. Can be used to
end_comment

begin_comment
comment|// generate sequences of user-defined types that implement operator+() and
end_comment

begin_comment
comment|// operator<().
end_comment

begin_comment
comment|// This class is used in the Range() function.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|IncrementT
operator|>
name|class
name|RangeGenerator
operator|:
name|public
name|ParamGeneratorInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|RangeGenerator
argument_list|(
argument|T begin
argument_list|,
argument|T end
argument_list|,
argument|IncrementT step
argument_list|)
operator|:
name|begin_
argument_list|(
name|begin
argument_list|)
block|,
name|end_
argument_list|(
name|end
argument_list|)
block|,
name|step_
argument_list|(
name|step
argument_list|)
block|,
name|end_index_
argument_list|(
argument|CalculateEndIndex(begin, end, step)
argument_list|)
block|{}
name|virtual
operator|~
name|RangeGenerator
argument_list|()
block|{}
name|virtual
name|ParamIteratorInterface
operator|<
name|T
operator|>
operator|*
name|Begin
argument_list|()
specifier|const
block|{
return|return
name|new
name|Iterator
argument_list|(
name|this
argument_list|,
name|begin_
argument_list|,
literal|0
argument_list|,
name|step_
argument_list|)
return|;
block|}
name|virtual
name|ParamIteratorInterface
operator|<
name|T
operator|>
operator|*
name|End
argument_list|()
specifier|const
block|{
return|return
name|new
name|Iterator
argument_list|(
name|this
argument_list|,
name|end_
argument_list|,
name|end_index_
argument_list|,
name|step_
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|class
name|Iterator
range|:
name|public
name|ParamIteratorInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|Iterator
argument_list|(
argument|const ParamGeneratorInterface<T>* base
argument_list|,
argument|T value
argument_list|,
argument|int index
argument_list|,
argument|IncrementT step
argument_list|)
operator|:
name|base_
argument_list|(
name|base
argument_list|)
block|,
name|value_
argument_list|(
name|value
argument_list|)
block|,
name|index_
argument_list|(
name|index
argument_list|)
block|,
name|step_
argument_list|(
argument|step
argument_list|)
block|{}
name|virtual
operator|~
name|Iterator
argument_list|()
block|{}
name|virtual
specifier|const
name|ParamGeneratorInterface
operator|<
name|T
operator|>
operator|*
name|BaseGenerator
argument_list|()
specifier|const
block|{
return|return
name|base_
return|;
block|}
name|virtual
name|void
name|Advance
argument_list|()
block|{
name|value_
operator|=
name|value_
operator|+
name|step_
block|;
name|index_
operator|++
block|;     }
name|virtual
name|ParamIteratorInterface
operator|<
name|T
operator|>
operator|*
name|Clone
argument_list|()
specifier|const
block|{
return|return
name|new
name|Iterator
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
name|virtual
specifier|const
name|T
operator|*
name|Current
argument_list|()
specifier|const
block|{
return|return
operator|&
name|value_
return|;
block|}
name|virtual
name|bool
name|Equals
argument_list|(
argument|const ParamIteratorInterface<T>& other
argument_list|)
specifier|const
block|{
comment|// Having the same base generator guarantees that the other
comment|// iterator is of the same type and we can downcast.
name|GTEST_CHECK_
argument_list|(
name|BaseGenerator
argument_list|()
operator|==
name|other
operator|.
name|BaseGenerator
argument_list|()
argument_list|)
operator|<<
literal|"The program attempted to compare iterators "
operator|<<
literal|"from different generators."
operator|<<
name|std
operator|::
name|endl
block|;
specifier|const
name|int
name|other_index
operator|=
name|CheckedDowncastToActualType
operator|<
specifier|const
name|Iterator
operator|>
operator|(
operator|&
name|other
operator|)
operator|->
name|index_
block|;
return|return
name|index_
operator|==
name|other_index
return|;
block|}
name|private
operator|:
name|Iterator
argument_list|(
specifier|const
name|Iterator
operator|&
name|other
argument_list|)
operator|:
name|ParamIteratorInterface
operator|<
name|T
operator|>
operator|(
operator|)
block|,
name|base_
argument_list|(
name|other
operator|.
name|base_
argument_list|)
block|,
name|value_
argument_list|(
name|other
operator|.
name|value_
argument_list|)
block|,
name|index_
argument_list|(
name|other
operator|.
name|index_
argument_list|)
block|,
name|step_
argument_list|(
argument|other.step_
argument_list|)
block|{}
comment|// No implementation - assignment is unsupported.
name|void
name|operator
operator|=
operator|(
specifier|const
name|Iterator
operator|&
name|other
operator|)
block|;
specifier|const
name|ParamGeneratorInterface
operator|<
name|T
operator|>
operator|*
specifier|const
name|base_
block|;
name|T
name|value_
block|;
name|int
name|index_
block|;
specifier|const
name|IncrementT
name|step_
block|;   }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// class RangeGenerator::Iterator
end_comment

begin_function
specifier|static
name|int
name|CalculateEndIndex
parameter_list|(
specifier|const
name|T
modifier|&
name|begin
parameter_list|,
specifier|const
name|T
modifier|&
name|end
parameter_list|,
specifier|const
name|IncrementT
modifier|&
name|step
parameter_list|)
block|{
name|int
name|end_index
init|=
literal|0
decl_stmt|;
for|for
control|(
name|T
name|i
init|=
name|begin
init|;
name|i
operator|<
name|end
condition|;
name|i
operator|=
name|i
operator|+
name|step
control|)
name|end_index
operator|++
expr_stmt|;
return|return
name|end_index
return|;
block|}
end_function

begin_comment
comment|// No implementation - assignment is unsupported.
end_comment

begin_decl_stmt
name|void
name|operator
init|=
operator|(
specifier|const
name|RangeGenerator
operator|&
name|other
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|T
name|begin_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|T
name|end_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|IncrementT
name|step_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The index for the end() iterator. All the elements in the generated
end_comment

begin_comment
comment|// sequence are indexed (0-based) to aid iterator comparison.
end_comment

begin_decl_stmt
specifier|const
name|int
name|end_index_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// class RangeGenerator
end_comment

begin_comment
comment|// Generates values from a pair of STL-style iterators. Used in the
end_comment

begin_comment
comment|// ValuesIn() function. The elements are copied from the source range
end_comment

begin_comment
comment|// since the source can be located on the stack, and the generator
end_comment

begin_comment
comment|// is likely to persist beyond that stack frame.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ValuesInIteratorRangeGenerator
operator|:
name|public
name|ParamGeneratorInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|template
operator|<
name|typename
name|ForwardIterator
operator|>
name|ValuesInIteratorRangeGenerator
argument_list|(
argument|ForwardIterator begin
argument_list|,
argument|ForwardIterator end
argument_list|)
operator|:
name|container_
argument_list|(
argument|begin
argument_list|,
argument|end
argument_list|)
block|{}
name|virtual
operator|~
name|ValuesInIteratorRangeGenerator
argument_list|()
block|{}
name|virtual
name|ParamIteratorInterface
operator|<
name|T
operator|>
operator|*
name|Begin
argument_list|()
specifier|const
block|{
return|return
name|new
name|Iterator
argument_list|(
name|this
argument_list|,
name|container_
operator|.
name|begin
argument_list|()
argument_list|)
return|;
block|}
name|virtual
name|ParamIteratorInterface
operator|<
name|T
operator|>
operator|*
name|End
argument_list|()
specifier|const
block|{
return|return
name|new
name|Iterator
argument_list|(
name|this
argument_list|,
name|container_
operator|.
name|end
argument_list|()
argument_list|)
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
operator|::
name|std
operator|::
name|vector
operator|<
name|T
operator|>
name|ContainerType
expr_stmt|;
end_typedef

begin_decl_stmt
name|class
name|Iterator
range|:
name|public
name|ParamIteratorInterface
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|Iterator
argument_list|(
argument|const ParamGeneratorInterface<T>* base
argument_list|,
argument|typename ContainerType::const_iterator iterator
argument_list|)
operator|:
name|base_
argument_list|(
name|base
argument_list|)
block|,
name|iterator_
argument_list|(
argument|iterator
argument_list|)
block|{}
name|virtual
operator|~
name|Iterator
argument_list|()
block|{}
name|virtual
specifier|const
name|ParamGeneratorInterface
operator|<
name|T
operator|>
operator|*
name|BaseGenerator
argument_list|()
specifier|const
block|{
return|return
name|base_
return|;
block|}
name|virtual
name|void
name|Advance
argument_list|()
block|{
operator|++
name|iterator_
block|;
name|value_
operator|.
name|reset
argument_list|()
block|;     }
name|virtual
name|ParamIteratorInterface
operator|<
name|T
operator|>
operator|*
name|Clone
argument_list|()
specifier|const
block|{
return|return
name|new
name|Iterator
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
comment|// We need to use cached value referenced by iterator_ because *iterator_
comment|// can return a temporary object (and of type other then T), so just
comment|// having "return&*iterator_;" doesn't work.
comment|// value_ is updated here and not in Advance() because Advance()
comment|// can advance iterator_ beyond the end of the range, and we cannot
comment|// detect that fact. The client code, on the other hand, is
comment|// responsible for not calling Current() on an out-of-range iterator.
name|virtual
specifier|const
name|T
operator|*
name|Current
argument_list|()
specifier|const
block|{
if|if
condition|(
name|value_
operator|.
name|get
argument_list|()
operator|==
name|NULL
condition|)
name|value_
operator|.
name|reset
argument_list|(
argument|new T(*iterator_)
argument_list|)
expr_stmt|;
return|return
name|value_
operator|.
name|get
argument_list|()
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|virtual
name|bool
name|Equals
argument_list|(
specifier|const
name|ParamIteratorInterface
operator|<
name|T
operator|>
operator|&
name|other
argument_list|)
decl|const
block|{
comment|// Having the same base generator guarantees that the other
comment|// iterator is of the same type and we can downcast.
name|GTEST_CHECK_
argument_list|(
name|BaseGenerator
argument_list|()
operator|==
name|other
operator|.
name|BaseGenerator
argument_list|()
argument_list|)
operator|<<
literal|"The program attempted to compare iterators "
operator|<<
literal|"from different generators."
operator|<<
name|std
operator|::
name|endl
expr_stmt|;
return|return
name|iterator_
operator|==
name|CheckedDowncastToActualType
operator|<
specifier|const
name|Iterator
operator|>
operator|(
operator|&
name|other
operator|)
operator|->
name|iterator_
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|Iterator
argument_list|(
specifier|const
name|Iterator
operator|&
name|other
argument_list|)
comment|// The explicit constructor call suppresses a false warning
comment|// emitted by gcc when supplied with the -Wextra option.
operator|:
name|ParamIteratorInterface
operator|<
name|T
operator|>
operator|(
operator|)
operator|,
name|base_
argument_list|(
name|other
operator|.
name|base_
argument_list|)
operator|,
name|iterator_
argument_list|(
argument|other.iterator_
argument_list|)
block|{}
specifier|const
name|ParamGeneratorInterface
operator|<
name|T
operator|>
operator|*
specifier|const
name|base_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|typename
name|ContainerType
operator|::
name|const_iterator
name|iterator_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// A cached value of *iterator_. We keep it here to allow access by
end_comment

begin_comment
comment|// pointer in the wrapping iterator's operator->().
end_comment

begin_comment
comment|// value_ needs to be mutable to be accessed in Current().
end_comment

begin_comment
comment|// Use of scoped_ptr helps manage cached value's lifetime,
end_comment

begin_comment
comment|// which is bound by the lifespan of the iterator itself.
end_comment

begin_expr_stmt
name|mutable
name|scoped_ptr
operator|<
specifier|const
name|T
operator|>
name|value_
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// class ValuesInIteratorRangeGenerator::Iterator
end_comment

begin_comment
comment|// No implementation - assignment is unsupported.
end_comment

begin_decl_stmt
name|void
name|operator
init|=
operator|(
specifier|const
name|ValuesInIteratorRangeGenerator
operator|&
name|other
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|ContainerType
name|container_
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// class ValuesInIteratorRangeGenerator
end_comment

begin_comment
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN USER CODE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Stores a parameter value and later creates tests parameterized with that
end_comment

begin_comment
comment|// value.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|TestClass
operator|>
name|class
name|ParameterizedTestFactory
operator|:
name|public
name|TestFactoryBase
block|{
name|public
operator|:
typedef|typedef
name|typename
name|TestClass
operator|::
name|ParamType
name|ParamType
expr_stmt|;
name|explicit
name|ParameterizedTestFactory
argument_list|(
argument|ParamType parameter
argument_list|)
operator|:
name|parameter_
argument_list|(
argument|parameter
argument_list|)
block|{}
name|virtual
name|Test
operator|*
name|CreateTest
argument_list|()
block|{
name|TestClass
operator|::
name|SetParam
argument_list|(
operator|&
name|parameter_
argument_list|)
block|;
return|return
name|new
name|TestClass
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
name|ParamType
name|parameter_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ParameterizedTestFactory
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN USER CODE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TestMetaFactoryBase is a base class for meta-factories that create
end_comment

begin_comment
comment|// test factories for passing into MakeAndRegisterTestInfo function.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ParamType
operator|>
name|class
name|TestMetaFactoryBase
block|{
name|public
operator|:
name|virtual
operator|~
name|TestMetaFactoryBase
argument_list|()
block|{}
name|virtual
name|TestFactoryBase
operator|*
name|CreateTestFactory
argument_list|(
argument|ParamType parameter
argument_list|)
operator|=
literal|0
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN USER CODE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TestMetaFactory creates test factories for passing into
end_comment

begin_comment
comment|// MakeAndRegisterTestInfo function. Since MakeAndRegisterTestInfo receives
end_comment

begin_comment
comment|// ownership of test factory pointer, same factory object cannot be passed
end_comment

begin_comment
comment|// into that method twice. But ParameterizedTestCaseInfo is going to call
end_comment

begin_comment
comment|// it for each Test/Parameter value combination. Thus it needs meta factory
end_comment

begin_comment
comment|// creator class.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|TestCase
operator|>
name|class
name|TestMetaFactory
operator|:
name|public
name|TestMetaFactoryBase
operator|<
name|typename
name|TestCase
operator|::
name|ParamType
operator|>
block|{
name|public
operator|:
typedef|typedef
name|typename
name|TestCase
operator|::
name|ParamType
name|ParamType
expr_stmt|;
name|TestMetaFactory
argument_list|()
block|{}
name|virtual
name|TestFactoryBase
operator|*
name|CreateTestFactory
argument_list|(
argument|ParamType parameter
argument_list|)
block|{
return|return
name|new
name|ParameterizedTestFactory
operator|<
name|TestCase
operator|>
operator|(
name|parameter
operator|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|TestMetaFactory
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN USER CODE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ParameterizedTestCaseInfoBase is a generic interface
end_comment

begin_comment
comment|// to ParameterizedTestCaseInfo classes. ParameterizedTestCaseInfoBase
end_comment

begin_comment
comment|// accumulates test information provided by TEST_P macro invocations
end_comment

begin_comment
comment|// and generators provided by INSTANTIATE_TEST_CASE_P macro invocations
end_comment

begin_comment
comment|// and uses that information to register all resulting test instances
end_comment

begin_comment
comment|// in RegisterTests method. The ParameterizeTestCaseRegistry class holds
end_comment

begin_comment
comment|// a collection of pointers to the ParameterizedTestCaseInfo objects
end_comment

begin_comment
comment|// and calls RegisterTests() on each of them when asked.
end_comment

begin_decl_stmt
name|class
name|ParameterizedTestCaseInfoBase
block|{
name|public
label|:
name|virtual
operator|~
name|ParameterizedTestCaseInfoBase
argument_list|()
expr_stmt|;
comment|// Base part of test case name for display purposes.
name|virtual
specifier|const
name|string
operator|&
name|GetTestCaseName
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Test case id to verify identity.
name|virtual
name|TypeId
name|GetTestCaseTypeId
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// UnitTest class invokes this method to register tests in this
comment|// test case right before running them in RUN_ALL_TESTS macro.
comment|// This method should not be called more then once on any single
comment|// instance of a ParameterizedTestCaseInfoBase derived class.
name|virtual
name|void
name|RegisterTests
parameter_list|()
init|=
literal|0
function_decl|;
name|protected
label|:
name|ParameterizedTestCaseInfoBase
argument_list|()
block|{}
name|private
label|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ParameterizedTestCaseInfoBase
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN USER CODE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ParameterizedTestCaseInfo accumulates tests obtained from TEST_P
end_comment

begin_comment
comment|// macro invocations for a particular test case and generators
end_comment

begin_comment
comment|// obtained from INSTANTIATE_TEST_CASE_P macro invocations for that
end_comment

begin_comment
comment|// test case. It registers tests with all values generated by all
end_comment

begin_comment
comment|// generators when asked.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|TestCase
operator|>
name|class
name|ParameterizedTestCaseInfo
operator|:
name|public
name|ParameterizedTestCaseInfoBase
block|{
name|public
operator|:
comment|// ParamType and GeneratorCreationFunc are private types but are required
comment|// for declarations of public methods AddTestPattern() and
comment|// AddTestCaseInstantiation().
typedef|typedef
name|typename
name|TestCase
operator|::
name|ParamType
name|ParamType
expr_stmt|;
end_expr_stmt

begin_comment
comment|// A function that returns an instance of appropriate generator type.
end_comment

begin_typedef
typedef|typedef
name|ParamGenerator
operator|<
name|ParamType
operator|>
call|(
name|GeneratorCreationFunc
call|)
argument_list|()
expr_stmt|;
end_typedef

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|ParameterizedTestCaseInfo
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
operator|:
name|test_case_name_
argument_list|(
argument|name
argument_list|)
block|{}
comment|// Test case base name for display purposes.
name|virtual
specifier|const
name|string
operator|&
name|GetTestCaseName
argument_list|()
specifier|const
block|{
return|return
name|test_case_name_
return|;
block|}
end_expr_stmt

begin_comment
comment|// Test case id to verify identity.
end_comment

begin_expr_stmt
name|virtual
name|TypeId
name|GetTestCaseTypeId
argument_list|()
specifier|const
block|{
return|return
name|GetTypeId
operator|<
name|TestCase
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// TEST_P macro uses AddTestPattern() to record information
end_comment

begin_comment
comment|// about a single test in a LocalTestInfo structure.
end_comment

begin_comment
comment|// test_case_name is the base name of the test case (without invocation
end_comment

begin_comment
comment|// prefix). test_base_name is the name of an individual test without
end_comment

begin_comment
comment|// parameter index. For the test SequenceA/FooTest.DoBar/1 FooTest is
end_comment

begin_comment
comment|// test case base name and DoBar is test base name.
end_comment

begin_decl_stmt
name|void
name|AddTestPattern
argument_list|(
specifier|const
name|char
operator|*
name|test_case_name
argument_list|,
specifier|const
name|char
operator|*
name|test_base_name
argument_list|,
name|TestMetaFactoryBase
operator|<
name|ParamType
operator|>
operator|*
name|meta_factory
argument_list|)
block|{
name|tests_
operator|.
name|push_back
argument_list|(
name|linked_ptr
operator|<
name|TestInfo
operator|>
operator|(
name|new
name|TestInfo
argument_list|(
name|test_case_name
argument_list|,
name|test_base_name
argument_list|,
name|meta_factory
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// INSTANTIATE_TEST_CASE_P macro uses AddGenerator() to record information
end_comment

begin_comment
comment|// about a generator.
end_comment

begin_function
name|int
name|AddTestCaseInstantiation
parameter_list|(
specifier|const
name|string
modifier|&
name|instantiation_name
parameter_list|,
name|GeneratorCreationFunc
modifier|*
name|func
parameter_list|,
specifier|const
name|char
modifier|*
comment|/* file */
parameter_list|,
name|int
comment|/* line */
parameter_list|)
block|{
name|instantiations_
operator|.
name|push_back
argument_list|(
operator|::
name|std
operator|::
name|make_pair
argument_list|(
name|instantiation_name
argument_list|,
name|func
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|// Return value used only to run this method in namespace scope.
block|}
end_function

begin_comment
comment|// UnitTest class invokes this method to register tests in this test case
end_comment

begin_comment
comment|// test cases right before running tests in RUN_ALL_TESTS macro.
end_comment

begin_comment
comment|// This method should not be called more then once on any single
end_comment

begin_comment
comment|// instance of a ParameterizedTestCaseInfoBase derived class.
end_comment

begin_comment
comment|// UnitTest has a guard to prevent from calling this method more then once.
end_comment

begin_function
name|virtual
name|void
name|RegisterTests
parameter_list|()
block|{
for|for
control|(
name|typename
name|TestInfoContainer
operator|::
name|iterator
name|test_it
operator|=
name|tests_
operator|.
name|begin
argument_list|()
init|;
name|test_it
operator|!=
name|tests_
operator|.
name|end
argument_list|()
condition|;
operator|++
name|test_it
control|)
block|{
name|linked_ptr
operator|<
name|TestInfo
operator|>
name|test_info
operator|=
operator|*
name|test_it
expr_stmt|;
for|for
control|(
name|typename
name|InstantiationContainer
operator|::
name|iterator
name|gen_it
operator|=
name|instantiations_
operator|.
name|begin
argument_list|()
init|;
name|gen_it
operator|!=
name|instantiations_
operator|.
name|end
argument_list|()
condition|;
operator|++
name|gen_it
control|)
block|{
specifier|const
name|string
modifier|&
name|instantiation_name
init|=
name|gen_it
operator|->
name|first
decl_stmt|;
name|ParamGenerator
operator|<
name|ParamType
operator|>
name|generator
argument_list|(
call|(
modifier|*
name|gen_it
operator|->
name|second
call|)
argument_list|()
argument_list|)
expr_stmt|;
name|Message
name|test_case_name_stream
decl_stmt|;
if|if
condition|(
operator|!
name|instantiation_name
operator|.
name|empty
argument_list|()
condition|)
name|test_case_name_stream
operator|<<
name|instantiation_name
operator|<<
literal|"/"
expr_stmt|;
name|test_case_name_stream
operator|<<
name|test_info
operator|->
name|test_case_base_name
expr_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
for|for
control|(
name|typename
name|ParamGenerator
operator|<
name|ParamType
operator|>
operator|::
name|iterator
name|param_it
operator|=
name|generator
operator|.
name|begin
argument_list|()
init|;
name|param_it
operator|!=
name|generator
operator|.
name|end
argument_list|()
condition|;
operator|++
name|param_it
operator|,
operator|++
name|i
control|)
block|{
name|Message
name|test_name_stream
decl_stmt|;
name|test_name_stream
operator|<<
name|test_info
operator|->
name|test_base_name
operator|<<
literal|"/"
operator|<<
name|i
expr_stmt|;
name|MakeAndRegisterTestInfo
argument_list|(
name|test_case_name_stream
operator|.
name|GetString
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|,
name|test_name_stream
operator|.
name|GetString
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|,
name|NULL
argument_list|,
comment|// No type parameter.
name|PrintToString
argument_list|(
operator|*
name|param_it
argument_list|)
operator|.
name|c_str
argument_list|()
argument_list|,
name|GetTestCaseTypeId
argument_list|()
argument_list|,
name|TestCase
operator|::
name|SetUpTestCase
argument_list|,
name|TestCase
operator|::
name|TearDownTestCase
argument_list|,
name|test_info
operator|->
name|test_meta_factory
operator|->
name|CreateTestFactory
argument_list|(
operator|*
name|param_it
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// for param_it
block|}
comment|// for gen_it
block|}
comment|// for test_it
block|}
end_function

begin_comment
comment|// RegisterTests
end_comment

begin_label
name|private
label|:
end_label

begin_comment
comment|// LocalTestInfo structure keeps information about a single test registered
end_comment

begin_comment
comment|// with TEST_P macro.
end_comment

begin_struct
struct|struct
name|TestInfo
block|{
name|TestInfo
argument_list|(
specifier|const
name|char
operator|*
name|a_test_case_base_name
argument_list|,
specifier|const
name|char
operator|*
name|a_test_base_name
argument_list|,
name|TestMetaFactoryBase
operator|<
name|ParamType
operator|>
operator|*
name|a_test_meta_factory
argument_list|)
operator|:
name|test_case_base_name
argument_list|(
name|a_test_case_base_name
argument_list|)
operator|,
name|test_base_name
argument_list|(
name|a_test_base_name
argument_list|)
operator|,
name|test_meta_factory
argument_list|(
argument|a_test_meta_factory
argument_list|)
block|{}
specifier|const
name|string
name|test_case_base_name
expr_stmt|;
specifier|const
name|string
name|test_base_name
decl_stmt|;
specifier|const
name|scoped_ptr
operator|<
name|TestMetaFactoryBase
operator|<
name|ParamType
operator|>
expr|>
name|test_meta_factory
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
operator|::
name|std
operator|::
name|vector
operator|<
name|linked_ptr
operator|<
name|TestInfo
operator|>
expr|>
name|TestInfoContainer
expr_stmt|;
end_typedef

begin_comment
comment|// Keeps pairs of<Instantiation name, Sequence generator creation function>
end_comment

begin_comment
comment|// received from INSTANTIATE_TEST_CASE_P macros.
end_comment

begin_typedef
typedef|typedef
operator|::
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|string
operator|,
name|GeneratorCreationFunc
operator|*
operator|>
expr|>
name|InstantiationContainer
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|const
name|string
name|test_case_name_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TestInfoContainer
name|tests_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|InstantiationContainer
name|instantiations_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ParameterizedTestCaseInfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// class ParameterizedTestCaseInfo
end_comment

begin_comment
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN USER CODE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ParameterizedTestCaseRegistry contains a map of ParameterizedTestCaseInfoBase
end_comment

begin_comment
comment|// classes accessed by test case names. TEST_P and INSTANTIATE_TEST_CASE_P
end_comment

begin_comment
comment|// macros use it to locate their corresponding ParameterizedTestCaseInfo
end_comment

begin_comment
comment|// descriptors.
end_comment

begin_decl_stmt
name|class
name|ParameterizedTestCaseRegistry
block|{
name|public
label|:
name|ParameterizedTestCaseRegistry
argument_list|()
block|{}
operator|~
name|ParameterizedTestCaseRegistry
argument_list|()
block|{
for|for
control|(
name|TestCaseInfoContainer
operator|::
name|iterator
name|it
operator|=
name|test_case_infos_
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|test_case_infos_
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|delete
modifier|*
name|it
decl_stmt|;
block|}
block|}
comment|// Looks up or creates and returns a structure containing information about
comment|// tests and instantiations of a particular test case.
name|template
operator|<
name|class
name|TestCase
operator|>
name|ParameterizedTestCaseInfo
operator|<
name|TestCase
operator|>
operator|*
name|GetTestCasePatternHolder
argument_list|(
argument|const char* test_case_name
argument_list|,
argument|const char* file
argument_list|,
argument|int line
argument_list|)
block|{
name|ParameterizedTestCaseInfo
operator|<
name|TestCase
operator|>
operator|*
name|typed_test_info
operator|=
name|NULL
block|;
for|for
control|(
name|TestCaseInfoContainer
operator|::
name|iterator
name|it
operator|=
name|test_case_infos_
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|test_case_infos_
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
operator|(
operator|*
name|it
operator|)
operator|->
name|GetTestCaseName
argument_list|()
operator|==
name|test_case_name
condition|)
block|{
if|if
condition|(
operator|(
operator|*
name|it
operator|)
operator|->
name|GetTestCaseTypeId
argument_list|()
operator|!=
name|GetTypeId
operator|<
name|TestCase
operator|>
operator|(
operator|)
condition|)
block|{
comment|// Complain about incorrect usage of Google Test facilities
comment|// and terminate the program since we cannot guaranty correct
comment|// test case setup and tear-down in this case.
name|ReportInvalidTestCaseType
argument_list|(
name|test_case_name
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|posix
operator|::
name|Abort
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|// At this point we are sure that the object we found is of the same
comment|// type we are looking for, so we downcast it to that type
comment|// without further checks.
name|typed_test_info
operator|=
name|CheckedDowncastToActualType
operator|<
name|ParameterizedTestCaseInfo
operator|<
name|TestCase
operator|>
expr|>
operator|(
operator|*
name|it
operator|)
expr_stmt|;
block|}
break|break;
block|}
block|}
if|if
condition|(
name|typed_test_info
operator|==
name|NULL
condition|)
block|{
name|typed_test_info
operator|=
name|new
name|ParameterizedTestCaseInfo
operator|<
name|TestCase
operator|>
operator|(
name|test_case_name
operator|)
expr_stmt|;
name|test_case_infos_
operator|.
name|push_back
argument_list|(
name|typed_test_info
argument_list|)
expr_stmt|;
block|}
return|return
name|typed_test_info
return|;
block|}
name|void
name|RegisterTests
parameter_list|()
block|{
for|for
control|(
name|TestCaseInfoContainer
operator|::
name|iterator
name|it
operator|=
name|test_case_infos_
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|test_case_infos_
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
operator|(
operator|*
name|it
operator|)
operator|->
name|RegisterTests
argument_list|()
expr_stmt|;
block|}
block|}
name|private
label|:
typedef|typedef
operator|::
name|std
operator|::
name|vector
operator|<
name|ParameterizedTestCaseInfoBase
operator|*
operator|>
name|TestCaseInfoContainer
expr_stmt|;
name|TestCaseInfoContainer
name|test_case_infos_
decl_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ParameterizedTestCaseRegistry
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
comment|//  GTEST_HAS_PARAM_TEST
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_INCLUDE_GTEST_INTERNAL_GTEST_PARAM_UTIL_H_
end_comment

end_unit

