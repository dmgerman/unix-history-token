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
file|"llvm/ADT/Hashing.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/None.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<array>
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
name|LLVM_NODISCARD
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
name|nullptr
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
name|nullptr
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
name|data
argument_list|()
argument_list|)
operator|,
name|Length
argument_list|(
argument|Vec.size()
argument_list|)
block|{}
comment|/// Construct an ArrayRef from a std::array
name|template
operator|<
name|size_t
name|N
operator|>
comment|/*implicit*/
name|constexpr
name|ArrayRef
argument_list|(
specifier|const
name|std
operator|::
name|array
operator|<
name|T
argument_list|,
name|N
operator|>
operator|&
name|Arr
argument_list|)
operator|:
name|Data
argument_list|(
name|Arr
operator|.
name|data
argument_list|()
argument_list|)
operator|,
name|Length
argument_list|(
argument|N
argument_list|)
block|{}
comment|/// Construct an ArrayRef from a C array.
name|template
operator|<
name|size_t
name|N
operator|>
comment|/*implicit*/
name|constexpr
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
name|nullptr
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
comment|/// Construct an ArrayRef<const T*> from ArrayRef<T*>. This uses SFINAE to
comment|/// ensure that only ArrayRefs of pointers can be converted.
name|template
operator|<
name|typename
name|U
operator|>
name|ArrayRef
argument_list|(
argument|const ArrayRef<U *>&A
argument_list|,
argument|typename std::enable_if<            std::is_convertible<U *const *
argument_list|,
argument|T const *>::value>::type * = nullptr
argument_list|)
operator|:
name|Data
argument_list|(
name|A
operator|.
name|data
argument_list|()
argument_list|)
operator|,
name|Length
argument_list|(
argument|A.size()
argument_list|)
block|{}
comment|/// Construct an ArrayRef<const T*> from a SmallVector<T*>. This is
comment|/// templated in order to avoid instantiating SmallVectorTemplateCommon<T>
comment|/// whenever we copy-construct an ArrayRef.
name|template
operator|<
name|typename
name|U
operator|,
name|typename
name|DummyT
operator|>
comment|/*implicit*/
name|ArrayRef
argument_list|(
argument|const SmallVectorTemplateCommon<U *
argument_list|,
argument|DummyT>&Vec
argument_list|,
argument|typename std::enable_if<           std::is_convertible<U *const *
argument_list|,
argument|T const *>::value>::type * = nullptr
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
comment|/// Construct an ArrayRef<const T*> from std::vector<T*>. This uses SFINAE
comment|/// to ensure that only vectors of pointers can be converted.
name|template
operator|<
name|typename
name|U
operator|,
name|typename
name|A
operator|>
name|ArrayRef
argument_list|(
argument|const std::vector<U *
argument_list|,
argument|A>&Vec
argument_list|,
argument|typename std::enable_if<                  std::is_convertible<U *const *
argument_list|,
argument|T const *>::value>::type* =
literal|0
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
block|{}
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
comment|// copy - Allocate copy in Allocator and return ArrayRef<T> to it.
name|template
operator|<
name|typename
name|Allocator
operator|>
name|ArrayRef
operator|<
name|T
operator|>
name|copy
argument_list|(
argument|Allocator&A
argument_list|)
block|{
name|T
operator|*
name|Buff
operator|=
name|A
operator|.
name|template
name|Allocate
operator|<
name|T
operator|>
operator|(
name|Length
operator|)
block|;
name|std
operator|::
name|uninitialized_copy
argument_list|(
name|begin
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|,
name|Buff
argument_list|)
block|;
return|return
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|Buff
operator|,
name|Length
operator|)
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
return|return
name|std
operator|::
name|equal
argument_list|(
name|begin
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|,
name|RHS
operator|.
name|begin
argument_list|()
argument_list|)
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
argument|size_t N
argument_list|,
argument|size_t M
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
comment|/// slice(n) - Chop off the first N elements of the array.
name|ArrayRef
operator|<
name|T
operator|>
name|slice
argument_list|(
argument|size_t N
argument_list|)
specifier|const
block|{
return|return
name|slice
argument_list|(
name|N
argument_list|,
name|size
argument_list|()
operator|-
name|N
argument_list|)
return|;
block|}
comment|/// \brief Drop the first \p N elements of the array.
name|ArrayRef
operator|<
name|T
operator|>
name|drop_front
argument_list|(
argument|size_t N =
literal|1
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|size
argument_list|()
operator|>=
name|N
operator|&&
literal|"Dropping more elements than exist"
argument_list|)
block|;
return|return
name|slice
argument_list|(
name|N
argument_list|,
name|size
argument_list|()
operator|-
name|N
argument_list|)
return|;
block|}
comment|/// \brief Drop the last \p N elements of the array.
name|ArrayRef
operator|<
name|T
operator|>
name|drop_back
argument_list|(
argument|size_t N =
literal|1
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|size
argument_list|()
operator|>=
name|N
operator|&&
literal|"Dropping more elements than exist"
argument_list|)
block|;
return|return
name|slice
argument_list|(
literal|0
argument_list|,
name|size
argument_list|()
operator|-
name|N
argument_list|)
return|;
block|}
comment|/// \brief Return a copy of *this with the first N elements satisfying the
comment|/// given predicate removed.
name|template
operator|<
name|class
name|PredicateT
operator|>
name|ArrayRef
operator|<
name|T
operator|>
name|drop_while
argument_list|(
argument|PredicateT Pred
argument_list|)
specifier|const
block|{
return|return
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|find_if_not
argument_list|(
operator|*
name|this
argument_list|,
name|Pred
argument_list|)
operator|,
name|end
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Return a copy of *this with the first N elements not satisfying
comment|/// the given predicate removed.
name|template
operator|<
name|class
name|PredicateT
operator|>
name|ArrayRef
operator|<
name|T
operator|>
name|drop_until
argument_list|(
argument|PredicateT Pred
argument_list|)
specifier|const
block|{
return|return
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|find_if
argument_list|(
operator|*
name|this
argument_list|,
name|Pred
argument_list|)
operator|,
name|end
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Return a copy of *this with only the first \p N elements.
name|ArrayRef
operator|<
name|T
operator|>
name|take_front
argument_list|(
argument|size_t N =
literal|1
argument_list|)
specifier|const
block|{
if|if
condition|(
name|N
operator|>=
name|size
argument_list|()
condition|)
return|return
operator|*
name|this
return|;
return|return
name|drop_back
argument_list|(
name|size
argument_list|()
operator|-
name|N
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Return a copy of *this with only the last \p N elements.
end_comment

begin_expr_stmt
name|ArrayRef
operator|<
name|T
operator|>
name|take_back
argument_list|(
argument|size_t N =
literal|1
argument_list|)
specifier|const
block|{
if|if
condition|(
name|N
operator|>=
name|size
argument_list|()
condition|)
return|return
operator|*
name|this
return|;
end_expr_stmt

begin_return
return|return
name|drop_front
argument_list|(
name|size
argument_list|()
operator|-
name|N
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Return the first N elements of this Array that satisfy the given
end_comment

begin_comment
comment|/// predicate.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|PredicateT
operator|>
name|ArrayRef
operator|<
name|T
operator|>
name|take_while
argument_list|(
argument|PredicateT Pred
argument_list|)
specifier|const
block|{
return|return
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|begin
argument_list|()
operator|,
name|find_if_not
argument_list|(
operator|*
name|this
argument_list|,
name|Pred
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the first N elements of this Array that don't satisfy the
end_comment

begin_comment
comment|/// given predicate.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|PredicateT
operator|>
name|ArrayRef
operator|<
name|T
operator|>
name|take_until
argument_list|(
argument|PredicateT Pred
argument_list|)
specifier|const
block|{
return|return
name|ArrayRef
operator|<
name|T
operator|>
operator|(
name|begin
argument_list|()
operator|,
name|find_if
argument_list|(
operator|*
name|this
argument_list|,
name|Pred
argument_list|)
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
end_decl_stmt

begin_comment
comment|/// Disallow accidental assignment from a temporary.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The declaration here is extra complicated so that "arrayRef = {}"
end_comment

begin_comment
comment|/// continues to select the move assignment operator.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|U
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|is_same
operator|<
name|U
operator|,
name|T
operator|>
operator|::
name|value
operator|,
name|ArrayRef
operator|<
name|T
operator|>>
operator|::
name|type
operator|&
name|operator
operator|=
operator|(
name|U
operator|&&
name|Temporary
operator|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Disallow accidental assignment from a temporary.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The declaration here is extra complicated so that "arrayRef = {}"
end_comment

begin_comment
comment|/// continues to select the move assignment operator.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|U
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|is_same
operator|<
name|U
operator|,
name|T
operator|>
operator|::
name|value
operator|,
name|ArrayRef
operator|<
name|T
operator|>>
operator|::
name|type
operator|&
name|operator
operator|=
operator|(
name|std
operator|::
name|initializer_list
operator|<
name|U
operator|>
operator|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Expensive Operations
end_comment

begin_comment
comment|/// @{
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Conversion operators
end_comment

begin_comment
comment|/// @{
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
unit|};
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
name|LLVM_NODISCARD
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
comment|/// Construct an ArrayRef from a std::array
name|template
operator|<
name|size_t
name|N
operator|>
comment|/*implicit*/
name|constexpr
name|MutableArrayRef
argument_list|(
name|std
operator|::
name|array
operator|<
name|T
argument_list|,
name|N
operator|>
operator|&
name|Arr
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
comment|/// Construct an MutableArrayRef from a C array.
name|template
operator|<
name|size_t
name|N
operator|>
comment|/*implicit*/
name|constexpr
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
argument|size_t N
argument_list|,
argument|size_t M
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
name|this
operator|->
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
comment|/// slice(n) - Chop off the first N elements of the array.
end_comment

begin_expr_stmt
name|MutableArrayRef
operator|<
name|T
operator|>
name|slice
argument_list|(
argument|size_t N
argument_list|)
specifier|const
block|{
return|return
name|slice
argument_list|(
name|N
argument_list|,
name|this
operator|->
name|size
argument_list|()
operator|-
name|N
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Drop the first \p N elements of the array.
end_comment

begin_expr_stmt
name|MutableArrayRef
operator|<
name|T
operator|>
name|drop_front
argument_list|(
argument|size_t N =
literal|1
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|this
operator|->
name|size
argument_list|()
operator|>=
name|N
operator|&&
literal|"Dropping more elements than exist"
argument_list|)
block|;
return|return
name|slice
argument_list|(
name|N
argument_list|,
name|this
operator|->
name|size
argument_list|()
operator|-
name|N
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|MutableArrayRef
operator|<
name|T
operator|>
name|drop_back
argument_list|(
argument|size_t N =
literal|1
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|this
operator|->
name|size
argument_list|()
operator|>=
name|N
operator|&&
literal|"Dropping more elements than exist"
argument_list|)
block|;
return|return
name|slice
argument_list|(
literal|0
argument_list|,
name|this
operator|->
name|size
argument_list|()
operator|-
name|N
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return a copy of *this with the first N elements satisfying the
end_comment

begin_comment
comment|/// given predicate removed.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|PredicateT
operator|>
name|MutableArrayRef
operator|<
name|T
operator|>
name|drop_while
argument_list|(
argument|PredicateT Pred
argument_list|)
specifier|const
block|{
return|return
name|MutableArrayRef
operator|<
name|T
operator|>
operator|(
name|find_if_not
argument_list|(
operator|*
name|this
argument_list|,
name|Pred
argument_list|)
operator|,
name|end
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return a copy of *this with the first N elements not satisfying
end_comment

begin_comment
comment|/// the given predicate removed.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|PredicateT
operator|>
name|MutableArrayRef
operator|<
name|T
operator|>
name|drop_until
argument_list|(
argument|PredicateT Pred
argument_list|)
specifier|const
block|{
return|return
name|MutableArrayRef
operator|<
name|T
operator|>
operator|(
name|find_if
argument_list|(
operator|*
name|this
argument_list|,
name|Pred
argument_list|)
operator|,
name|end
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return a copy of *this with only the first \p N elements.
end_comment

begin_expr_stmt
name|MutableArrayRef
operator|<
name|T
operator|>
name|take_front
argument_list|(
argument|size_t N =
literal|1
argument_list|)
specifier|const
block|{
if|if
condition|(
name|N
operator|>=
name|this
operator|->
name|size
argument_list|()
condition|)
return|return
operator|*
name|this
return|;
end_expr_stmt

begin_return
return|return
name|drop_back
argument_list|(
name|this
operator|->
name|size
argument_list|()
operator|-
name|N
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Return a copy of *this with only the last \p N elements.
end_comment

begin_expr_stmt
unit|MutableArrayRef
operator|<
name|T
operator|>
name|take_back
argument_list|(
argument|size_t N =
literal|1
argument_list|)
specifier|const
block|{
if|if
condition|(
name|N
operator|>=
name|this
operator|->
name|size
argument_list|()
condition|)
return|return
operator|*
name|this
return|;
end_expr_stmt

begin_return
return|return
name|drop_front
argument_list|(
name|this
operator|->
name|size
argument_list|()
operator|-
name|N
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Return the first N elements of this Array that satisfy the given
end_comment

begin_comment
comment|/// predicate.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|PredicateT
operator|>
name|MutableArrayRef
operator|<
name|T
operator|>
name|take_while
argument_list|(
argument|PredicateT Pred
argument_list|)
specifier|const
block|{
return|return
name|MutableArrayRef
operator|<
name|T
operator|>
operator|(
name|begin
argument_list|()
operator|,
name|find_if_not
argument_list|(
operator|*
name|this
argument_list|,
name|Pred
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the first N elements of this Array that don't satisfy the
end_comment

begin_comment
comment|/// given predicate.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|PredicateT
operator|>
name|MutableArrayRef
operator|<
name|T
operator|>
name|take_until
argument_list|(
argument|PredicateT Pred
argument_list|)
specifier|const
block|{
return|return
name|MutableArrayRef
operator|<
name|T
operator|>
operator|(
name|begin
argument_list|()
operator|,
name|find_if
argument_list|(
operator|*
name|this
argument_list|,
name|Pred
argument_list|)
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
comment|/// This is a MutableArrayRef that owns its array.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|OwningArrayRef
operator|:
name|public
name|MutableArrayRef
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|OwningArrayRef
argument_list|()
block|{}
name|OwningArrayRef
argument_list|(
argument|size_t Size
argument_list|)
operator|:
name|MutableArrayRef
operator|<
name|T
operator|>
operator|(
name|new
name|T
index|[
name|Size
index|]
operator|,
name|Size
operator|)
block|{}
name|OwningArrayRef
argument_list|(
name|ArrayRef
operator|<
name|T
operator|>
name|Data
argument_list|)
operator|:
name|MutableArrayRef
operator|<
name|T
operator|>
operator|(
name|new
name|T
index|[
name|Data
operator|.
name|size
argument_list|()
index|]
operator|,
name|Data
operator|.
name|size
argument_list|()
operator|)
block|{
name|std
operator|::
name|copy
argument_list|(
name|Data
operator|.
name|begin
argument_list|()
argument_list|,
name|Data
operator|.
name|end
argument_list|()
argument_list|,
name|this
operator|->
name|begin
argument_list|()
argument_list|)
block|;     }
name|OwningArrayRef
argument_list|(
argument|OwningArrayRef&&Other
argument_list|)
block|{
operator|*
name|this
operator|=
name|Other
block|; }
name|OwningArrayRef
operator|&
name|operator
operator|=
operator|(
name|OwningArrayRef
operator|&&
name|Other
operator|)
block|{
name|delete
index|[]
name|this
operator|->
name|data
argument_list|()
block|;
name|this
operator|->
name|MutableArrayRef
operator|<
name|T
operator|>
operator|::
name|operator
operator|=
operator|(
name|Other
operator|)
block|;
name|Other
operator|.
name|MutableArrayRef
operator|<
name|T
operator|>
operator|::
name|operator
operator|=
operator|(
name|MutableArrayRef
operator|<
name|T
operator|>
operator|(
operator|)
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
operator|~
name|OwningArrayRef
argument_list|()
block|{
name|delete
index|[]
name|this
operator|->
name|data
argument_list|()
block|; }
end_expr_stmt

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
comment|/// Construct an ArrayRef from an ArrayRef (no-op) (const)
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
argument|const ArrayRef<T>&Vec
argument_list|)
block|{
return|return
name|Vec
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Construct an ArrayRef from an ArrayRef (no-op)
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
operator|&
name|makeArrayRef
argument_list|(
argument|ArrayRef<T>&Vec
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
comment|/// Construct a MutableArrayRef from a single element.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|MutableArrayRef
operator|<
name|T
operator|>
name|makeMutableArrayRef
argument_list|(
argument|T&OneElt
argument_list|)
block|{
return|return
name|OneElt
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Construct a MutableArrayRef from a pointer and length.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|MutableArrayRef
operator|<
name|T
operator|>
name|makeMutableArrayRef
argument_list|(
argument|T *data
argument_list|,
argument|size_t length
argument_list|)
block|{
return|return
name|MutableArrayRef
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

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|hash_code
name|hash_value
argument_list|(
argument|ArrayRef<T> S
argument_list|)
block|{
return|return
name|hash_combine_range
argument_list|(
name|S
operator|.
name|begin
argument_list|()
argument_list|,
name|S
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
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
comment|// LLVM_ADT_ARRAYREF_H
end_comment

end_unit

