begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/SmallSet.h - 'Normally small' sets --------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines the SmallSet class.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ADT_SMALLSET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_SMALLSET_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/None.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// SmallSet - This maintains a set of unique values, optimizing for the case
comment|/// when the set is small (less than N).  In this case, the set can be
comment|/// maintained with no mallocs.  If the set gets large, we expand to using an
comment|/// std::set to maintain reasonable lookup times.
comment|///
comment|/// Note that this set does not provide a way to iterate over members in the
comment|/// set.
name|template
operator|<
name|typename
name|T
operator|,
name|unsigned
name|N
operator|,
name|typename
name|C
operator|=
name|std
operator|::
name|less
operator|<
name|T
operator|>>
name|class
name|SmallSet
block|{
comment|/// Use a SmallVector to hold the elements here (even though it will never
comment|/// reach its 'large' stage) to avoid calling the default ctors of elements
comment|/// we will never use.
name|SmallVector
operator|<
name|T
block|,
name|N
operator|>
name|Vector
block|;
name|std
operator|::
name|set
operator|<
name|T
block|,
name|C
operator|>
name|Set
block|;
name|using
name|VIterator
operator|=
name|typename
name|SmallVector
operator|<
name|T
block|,
name|N
operator|>
operator|::
name|const_iterator
block|;
name|using
name|mutable_iterator
operator|=
name|typename
name|SmallVector
operator|<
name|T
block|,
name|N
operator|>
operator|::
name|iterator
block|;
comment|// In small mode SmallPtrSet uses linear search for the elements, so it is
comment|// not a good idea to choose this value too high. You may consider using a
comment|// DenseSet<> instead if you expect many elements in the set.
name|static_assert
argument_list|(
name|N
operator|<=
literal|32
argument_list|,
literal|"N should be small"
argument_list|)
block|;
name|public
operator|:
name|using
name|size_type
operator|=
name|size_t
block|;
name|SmallSet
argument_list|()
operator|=
expr|default
block|;
name|LLVM_NODISCARD
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Vector
operator|.
name|empty
argument_list|()
operator|&&
name|Set
operator|.
name|empty
argument_list|()
return|;
block|}
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|isSmall
argument_list|()
operator|?
name|Vector
operator|.
name|size
argument_list|()
operator|:
name|Set
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// count - Return 1 if the element is in the set, 0 otherwise.
name|size_type
name|count
argument_list|(
argument|const T&V
argument_list|)
specifier|const
block|{
if|if
condition|(
name|isSmall
argument_list|()
condition|)
block|{
comment|// Since the collection is small, just do a linear search.
return|return
name|vfind
argument_list|(
name|V
argument_list|)
operator|==
name|Vector
operator|.
name|end
argument_list|()
condition|?
literal|0
else|:
literal|1
return|;
block|}
else|else
block|{
return|return
name|Set
operator|.
name|count
argument_list|(
name|V
argument_list|)
return|;
block|}
block|}
comment|/// insert - Insert an element into the set if it isn't already there.
comment|/// Returns true if the element is inserted (it was not in the set before).
comment|/// The first value of the returned pair is unused and provided for
comment|/// partial compatibility with the standard library self-associative container
comment|/// concept.
comment|// FIXME: Add iterators that abstract over the small and large form, and then
comment|// return those here.
name|std
operator|::
name|pair
operator|<
name|NoneType
block|,
name|bool
operator|>
name|insert
argument_list|(
argument|const T&V
argument_list|)
block|{
if|if
condition|(
operator|!
name|isSmall
argument_list|()
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|None
argument_list|,
name|Set
operator|.
name|insert
argument_list|(
name|V
argument_list|)
operator|.
name|second
argument_list|)
return|;
name|VIterator
name|I
operator|=
name|vfind
argument_list|(
name|V
argument_list|)
block|;
if|if
condition|(
name|I
operator|!=
name|Vector
operator|.
name|end
argument_list|()
condition|)
comment|// Don't reinsert if it already exists.
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|None
argument_list|,
name|false
argument_list|)
return|;
if|if
condition|(
name|Vector
operator|.
name|size
argument_list|()
operator|<
name|N
condition|)
block|{
name|Vector
operator|.
name|push_back
argument_list|(
name|V
argument_list|)
expr_stmt|;
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|None
argument_list|,
name|true
argument_list|)
return|;
block|}
comment|// Otherwise, grow from vector to set.
while|while
condition|(
operator|!
name|Vector
operator|.
name|empty
argument_list|()
condition|)
block|{
name|Set
operator|.
name|insert
argument_list|(
name|Vector
operator|.
name|back
argument_list|()
argument_list|)
expr_stmt|;
name|Vector
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
name|Set
operator|.
name|insert
argument_list|(
name|V
argument_list|)
expr_stmt|;
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|None
argument_list|,
name|true
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|IterT
operator|>
name|void
name|insert
argument_list|(
argument|IterT I
argument_list|,
argument|IterT E
argument_list|)
block|{
for|for
control|(
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
name|insert
argument_list|(
operator|*
name|I
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_function
name|bool
name|erase
parameter_list|(
specifier|const
name|T
modifier|&
name|V
parameter_list|)
block|{
if|if
condition|(
operator|!
name|isSmall
argument_list|()
condition|)
return|return
name|Set
operator|.
name|erase
argument_list|(
name|V
argument_list|)
return|;
for|for
control|(
name|mutable_iterator
name|I
init|=
name|Vector
operator|.
name|begin
argument_list|()
init|,
name|E
init|=
name|Vector
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
if|if
condition|(
operator|*
name|I
operator|==
name|V
condition|)
block|{
name|Vector
operator|.
name|erase
argument_list|(
name|I
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_function

begin_function
name|void
name|clear
parameter_list|()
block|{
name|Vector
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Set
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|bool
name|isSmall
argument_list|()
specifier|const
block|{
return|return
name|Set
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|VIterator
name|vfind
argument_list|(
specifier|const
name|T
operator|&
name|V
argument_list|)
decl|const
block|{
for|for
control|(
name|VIterator
name|I
init|=
name|Vector
operator|.
name|begin
argument_list|()
init|,
name|E
init|=
name|Vector
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
if|if
condition|(
operator|*
name|I
operator|==
name|V
condition|)
return|return
name|I
return|;
return|return
name|Vector
operator|.
name|end
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|/// If this set is of pointer values, transparently switch over to using
end_comment

begin_comment
comment|/// SmallPtrSet for performance.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|PointeeType
operator|,
name|unsigned
name|N
operator|>
name|class
name|SmallSet
operator|<
name|PointeeType
operator|*
operator|,
name|N
operator|>
operator|:
name|public
name|SmallPtrSet
operator|<
name|PointeeType
operator|*
operator|,
name|N
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_SMALLSET_H
end_comment

end_unit

