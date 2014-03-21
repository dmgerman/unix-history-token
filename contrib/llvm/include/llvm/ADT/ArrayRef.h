begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ArrayRef.h - Array Reference Wrapper -------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ADT_ARRAYREF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_ARRAYREF_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/None.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// ArrayRef - Represent a constant reference to an array (0 or more elements
comment|/// consecutively in memory), i.e. a start pointer and a length.  It allows
comment|/// various APIs to take consecutive elements easily and conveniently.
comment|///
comment|/// This class does not own the underlying data, it is expected to be used in
comment|/// situations where the data resides in some other buffer, whose lifetime
comment|/// extends past that of the ArrayRef. For this reason, it is not in general
comment|/// safe to store an ArrayRef.
comment|///
comment|/// This is intended to be trivially copyable, so it should be passed by
comment|/// value.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
block|{
name|public
operator|:
typedef|typedef
specifier|const
name|T
modifier|*
name|iterator
typedef|;
typedef|typedef
specifier|const
name|T
modifier|*
name|const_iterator
typedef|;
typedef|typedef
name|size_t
name|size_type
typedef|;
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|iterator
operator|>
name|reverse_iterator
expr_stmt|;
name|private
label|:
comment|/// The start of the array, in an external buffer.
specifier|const
name|T
modifier|*
name|Data
decl_stmt|;
comment|/// The number of elements.
name|size_type
name|Length
decl_stmt|;
name|public
label|:
comment|/// @name Constructors
comment|/// @{
comment|/// Construct an empty ArrayRef.
comment|/*implicit*/
name|ArrayRef
argument_list|()
operator|:
name|Data
argument_list|(
literal|0
argument_list|)
operator|,
name|Length
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Construct an empty ArrayRef from None.
comment|/*implicit*/
name|ArrayRef
argument_list|(
name|NoneType
argument_list|)
operator|:
name|Data
argument_list|(
literal|0
argument_list|)
operator|,
name|Length
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Construct an ArrayRef from a single element.
comment|/*implicit*/
name|ArrayRef
argument_list|(
specifier|const
name|T
operator|&
name|OneElt
argument_list|)
operator|:
name|Data
argument_list|(
operator|&
name|OneElt
argument_list|)
operator|,
name|Length
argument_list|(
literal|1
argument_list|)
block|{}
comment|/// Construct an ArrayRef from a pointer and length.
comment|/*implicit*/
name|ArrayRef
argument_list|(
argument|const T *data
argument_list|,
argument|size_t length
argument_list|)
operator|:
name|Data
argument_list|(
name|data
argument_list|)
operator|,
name|Length
argument_list|(
argument|length
argument_list|)
block|{}
comment|/// Construct an ArrayRef from a range.
name|ArrayRef
argument_list|(
specifier|const
name|T
operator|*
name|begin
argument_list|,
specifier|const
name|T
operator|*
name|end
argument_list|)
operator|:
name|Data
argument_list|(
name|begin
argument_list|)
operator|,
name|Length
argument_list|(
argument|end - begin
argument_list|)
block|{}
comment|/// Construct an ArrayRef from a SmallVector. This is templated in order to
comment|/// avoid instantiating SmallVectorTemplateCommon<T> whenever we
comment|/// copy-construct an ArrayRef.
name|template
operator|<
name|typename
name|U
operator|>
comment|/*implicit*/
name|ArrayRef
argument_list|(
specifier|const
name|SmallVectorTemplateCommon
operator|<
name|T
argument_list|,
name|U
operator|>
operator|&
name|Vec
argument_list|)
operator|:
name|Data
argument_list|(
name|Vec
operator|.
name|data
argument_list|()
argument_list|)
operator|,
name|Length
argument_list|(
argument|Vec.size()
argument_list|)
block|{     }
comment|/// Construct an ArrayRef from a std::vector.
name|template
operator|<
name|typename
name|A
operator|>
comment|/*implicit*/
name|ArrayRef
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|T
argument_list|,
name|A
operator|>
operator|&
name|Vec
argument_list|)
operator|:
name|Data
argument_list|(
name|Vec
operator|.
name|empty
argument_list|()
operator|?
operator|(
name|T
operator|*
operator|)
literal|0
operator|:
operator|&
name|Vec
index|[
literal|0
index|]
argument_list|)
operator|,
name|Length
argument_list|(
argument|Vec.size()
argument_list|)
block|{}
comment|/// Construct an ArrayRef from a C array.
name|template
operator|<
name|size_t
name|N
operator|>
comment|/*implicit*/
name|LLVM_CONSTEXPR
name|ArrayRef
argument_list|(
specifier|const
name|T
argument_list|(
operator|&
name|Arr
argument_list|)
index|[
name|N
index|]
argument_list|)
operator|:
name|Data
argument_list|(
name|Arr
argument_list|)
operator|,
name|Length
argument_list|(
argument|N
argument_list|)
block|{}
if|#
directive|if
name|LLVM_HAS_INITIALIZER_LISTS
comment|/// Construct an ArrayRef from a std::initializer_list.
comment|/*implicit*/
name|ArrayRef
argument_list|(
specifier|const
name|std
operator|::
name|initializer_list
operator|<
name|T
operator|>
operator|&
name|Vec
argument_list|)
operator|:
name|Data
argument_list|(
name|Vec
operator|.
name|begin
argument_list|()
operator|==
name|Vec
operator|.
name|end
argument_list|()
operator|?
operator|(
name|T
operator|*
operator|)
literal|0
operator|:
name|Vec
operator|.
name|begin
argument_list|()
argument_list|)
operator|,
name|Length
argument_list|(
argument|Vec.size()
argument_list|)
block|{}
endif|#
directive|endif
comment|/// @}
comment|/// @name Simple Operations
comment|/// @{
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Data
operator|+
name|Length
return|;
block|}
name|reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|reverse_iterator
argument_list|(
name|end
argument_list|()
argument_list|)
return|;
block|}
name|reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|reverse_iterator
argument_list|(
name|begin
argument_list|()
argument_list|)
return|;
block|}
comment|/// empty - Check if the array is empty.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Length
operator|==
literal|0
return|;
block|}
specifier|const
name|T
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
comment|/// size - Get the array size.
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Length
return|;
block|}
comment|/// front - Get the first element.
specifier|const
name|T
operator|&
name|front
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
argument_list|)
block|;
return|return
name|Data
index|[
literal|0
index|]
return|;
block|}
comment|/// back - Get the last element.
specifier|const
name|T
operator|&
name|back
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
argument_list|)
block|;
return|return
name|Data
index|[
name|Length
operator|-
literal|1
index|]
return|;
block|}
comment|/// equals - Check for element-wise equality.
name|bool
name|equals
argument_list|(
name|ArrayRef
name|RHS
argument_list|)
decl|const
block|{
if|if
condition|(
name|Length
operator|!=
name|RHS
operator|.
name|Length
condition|)
return|return
name|false
return|;
for|for
control|(
name|size_type
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|Length
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|Data
index|[
name|i
index|]
operator|!=
name|RHS
operator|.
name|Data
index|[
name|i
index|]
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
comment|/// slice(n) - Chop off the first N elements of the array.
name|ArrayRef
operator|<
name|T
operator|>
name|slice
argument_list|(
argument|unsigned N
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|N
operator|<=
name|size
argument_list|()
operator|&&
literal|"Invalid specifier"
argument_list|)
block|;
return|return
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|data
argument_list|()
operator|+
name|N
operator|,
name|size
argument_list|()
operator|-
name|N
operator|)
return|;
block|}
comment|/// slice(n, m) - Chop off the first N elements of the array, and keep M
comment|/// elements in the array.
name|ArrayRef
operator|<
name|T
operator|>
name|slice
argument_list|(
argument|unsigned N
argument_list|,
argument|unsigned M
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|N
operator|+
name|M
operator|<=
name|size
argument_list|()
operator|&&
literal|"Invalid specifier"
argument_list|)
block|;
return|return
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|data
argument_list|()
operator|+
name|N
operator|,
name|M
operator|)
return|;
block|}
comment|/// @}
comment|/// @name Operator Overloads
comment|/// @{
specifier|const
name|T
modifier|&
name|operator
index|[]
argument_list|(
name|size_t
name|Index
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Index
operator|<
name|Length
operator|&&
literal|"Invalid index!"
argument_list|)
expr_stmt|;
return|return
name|Data
index|[
name|Index
index|]
return|;
block|}
comment|/// @}
comment|/// @name Expensive Operations
comment|/// @{
name|std
operator|::
name|vector
operator|<
name|T
operator|>
name|vec
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|vector
operator|<
name|T
operator|>
operator|(
name|Data
operator|,
name|Data
operator|+
name|Length
operator|)
return|;
block|}
comment|/// @}
comment|/// @name Conversion operators
comment|/// @{
name|operator
name|std
operator|::
name|vector
operator|<
name|T
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|std
operator|::
name|vector
operator|<
name|T
operator|>
operator|(
name|Data
operator|,
name|Data
operator|+
name|Length
operator|)
return|;
block|}
comment|/// @}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// MutableArrayRef - Represent a mutable reference to an array (0 or more
end_comment

begin_comment
comment|/// elements consecutively in memory), i.e. a start pointer and a length.  It
end_comment

begin_comment
comment|/// allows various APIs to take and modify consecutive elements easily and
end_comment

begin_comment
comment|/// conveniently.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class does not own the underlying data, it is expected to be used in
end_comment

begin_comment
comment|/// situations where the data resides in some other buffer, whose lifetime
end_comment

begin_comment
comment|/// extends past that of the MutableArrayRef. For this reason, it is not in
end_comment

begin_comment
comment|/// general safe to store a MutableArrayRef.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is intended to be trivially copyable, so it should be passed by
end_comment

begin_comment
comment|/// value.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|MutableArrayRef
operator|:
name|public
name|ArrayRef
operator|<
name|T
operator|>
block|{
name|public
operator|:
typedef|typedef
name|T
modifier|*
name|iterator
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|iterator
operator|>
name|reverse_iterator
expr_stmt|;
end_typedef

begin_comment
comment|/// Construct an empty MutableArrayRef.
end_comment

begin_comment
comment|/*implicit*/
end_comment

begin_expr_stmt
name|MutableArrayRef
argument_list|()
operator|:
name|ArrayRef
operator|<
name|T
operator|>
operator|(
operator|)
block|{}
comment|/// Construct an empty MutableArrayRef from None.
comment|/*implicit*/
name|MutableArrayRef
argument_list|(
name|NoneType
argument_list|)
operator|:
name|ArrayRef
operator|<
name|T
operator|>
operator|(
operator|)
block|{}
comment|/// Construct an MutableArrayRef from a single element.
comment|/*implicit*/
name|MutableArrayRef
argument_list|(
name|T
operator|&
name|OneElt
argument_list|)
operator|:
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|OneElt
operator|)
block|{}
comment|/// Construct an MutableArrayRef from a pointer and length.
comment|/*implicit*/
name|MutableArrayRef
argument_list|(
argument|T *data
argument_list|,
argument|size_t length
argument_list|)
operator|:
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|data
operator|,
name|length
operator|)
block|{}
comment|/// Construct an MutableArrayRef from a range.
name|MutableArrayRef
argument_list|(
name|T
operator|*
name|begin
argument_list|,
name|T
operator|*
name|end
argument_list|)
operator|:
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|begin
operator|,
name|end
operator|)
block|{}
comment|/// Construct an MutableArrayRef from a SmallVector.
comment|/*implicit*/
name|MutableArrayRef
argument_list|(
name|SmallVectorImpl
operator|<
name|T
operator|>
operator|&
name|Vec
argument_list|)
operator|:
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|Vec
operator|)
block|{}
comment|/// Construct a MutableArrayRef from a std::vector.
comment|/*implicit*/
name|MutableArrayRef
argument_list|(
name|std
operator|::
name|vector
operator|<
name|T
operator|>
operator|&
name|Vec
argument_list|)
operator|:
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|Vec
operator|)
block|{}
comment|/// Construct an MutableArrayRef from a C array.
name|template
operator|<
name|size_t
name|N
operator|>
comment|/*implicit*/
name|MutableArrayRef
argument_list|(
name|T
argument_list|(
operator|&
name|Arr
argument_list|)
index|[
name|N
index|]
argument_list|)
operator|:
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|Arr
operator|)
block|{}
name|T
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|ArrayRef
operator|<
name|T
operator|>
operator|::
name|data
argument_list|()
operator|)
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
name|data
argument_list|()
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
name|data
argument_list|()
operator|+
name|this
operator|->
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|reverse_iterator
argument_list|(
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|reverse_iterator
argument_list|(
name|begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// front - Get the first element.
end_comment

begin_expr_stmt
name|T
operator|&
name|front
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|this
operator|->
name|empty
argument_list|()
argument_list|)
block|;
return|return
name|data
argument_list|()
index|[
literal|0
index|]
return|;
block|}
end_expr_stmt

begin_comment
comment|/// back - Get the last element.
end_comment

begin_expr_stmt
name|T
operator|&
name|back
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|this
operator|->
name|empty
argument_list|()
argument_list|)
block|;
return|return
name|data
argument_list|()
index|[
name|this
operator|->
name|size
argument_list|()
operator|-
literal|1
index|]
return|;
block|}
end_expr_stmt

begin_comment
comment|/// slice(n) - Chop off the first N elements of the array.
end_comment

begin_expr_stmt
name|MutableArrayRef
operator|<
name|T
operator|>
name|slice
argument_list|(
argument|unsigned N
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|N
operator|<=
name|this
operator|->
name|size
argument_list|()
operator|&&
literal|"Invalid specifier"
argument_list|)
block|;
return|return
name|MutableArrayRef
operator|<
name|T
operator|>
operator|(
name|data
argument_list|()
operator|+
name|N
operator|,
name|this
operator|->
name|size
argument_list|()
operator|-
name|N
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// slice(n, m) - Chop off the first N elements of the array, and keep M
end_comment

begin_comment
comment|/// elements in the array.
end_comment

begin_expr_stmt
name|MutableArrayRef
operator|<
name|T
operator|>
name|slice
argument_list|(
argument|unsigned N
argument_list|,
argument|unsigned M
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|N
operator|+
name|M
operator|<=
name|this
operator|->
name|size
argument_list|()
operator|&&
literal|"Invalid specifier"
argument_list|)
block|;
return|return
name|MutableArrayRef
operator|<
name|T
operator|>
operator|(
name|data
argument_list|()
operator|+
name|N
operator|,
name|M
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Operator Overloads
end_comment

begin_comment
comment|/// @{
end_comment

begin_decl_stmt
name|T
modifier|&
name|operator
index|[]
argument_list|(
name|size_t
name|Index
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Index
operator|<
name|this
operator|->
name|size
argument_list|()
operator|&&
literal|"Invalid index!"
argument_list|)
expr_stmt|;
return|return
name|data
argument_list|()
index|[
name|Index
index|]
return|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|/// @name ArrayRef Convenience constructors
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// Construct an ArrayRef from a single element.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|ArrayRef
operator|<
name|T
operator|>
name|makeArrayRef
argument_list|(
argument|const T&OneElt
argument_list|)
block|{
return|return
name|OneElt
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Construct an ArrayRef from a pointer and length.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|ArrayRef
operator|<
name|T
operator|>
name|makeArrayRef
argument_list|(
argument|const T *data
argument_list|,
argument|size_t length
argument_list|)
block|{
return|return
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|data
operator|,
name|length
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Construct an ArrayRef from a range.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|ArrayRef
operator|<
name|T
operator|>
name|makeArrayRef
argument_list|(
argument|const T *begin
argument_list|,
argument|const T *end
argument_list|)
block|{
return|return
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|begin
operator|,
name|end
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Construct an ArrayRef from a SmallVector.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|ArrayRef
operator|<
name|T
operator|>
name|makeArrayRef
argument_list|(
argument|const SmallVectorImpl<T>&Vec
argument_list|)
block|{
return|return
name|Vec
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Construct an ArrayRef from a SmallVector.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|unsigned
name|N
operator|>
name|ArrayRef
operator|<
name|T
operator|>
name|makeArrayRef
argument_list|(
argument|const SmallVector<T
argument_list|,
argument|N>&Vec
argument_list|)
block|{
return|return
name|Vec
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Construct an ArrayRef from a std::vector.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|ArrayRef
operator|<
name|T
operator|>
name|makeArrayRef
argument_list|(
argument|const std::vector<T>&Vec
argument_list|)
block|{
return|return
name|Vec
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Construct an ArrayRef from a C array.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|size_t
name|N
operator|>
name|ArrayRef
operator|<
name|T
operator|>
name|makeArrayRef
argument_list|(
argument|const T (&Arr)[N]
argument_list|)
block|{
return|return
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|Arr
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name ArrayRef Comparison Operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|ArrayRef
operator|<
name|T
operator|>
name|LHS
operator|,
name|ArrayRef
operator|<
name|T
operator|>
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|equals
argument_list|(
name|RHS
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|ArrayRef
operator|<
name|T
operator|>
name|LHS
operator|,
name|ArrayRef
operator|<
name|T
operator|>
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|// ArrayRefs can be treated like a POD type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|isPodLike
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|isPodLike
operator|<
name|ArrayRef
operator|<
name|T
operator|>
expr|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|;   }
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

