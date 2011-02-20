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
name|class
name|APInt
decl_stmt|;
comment|/// ArrayRef - Represent a constant reference to an array (0 or more elements
comment|/// consecutively in memory), i.e. a start pointer and a length.  It allows
comment|/// various APIs to take consecutive elements easily and conveniently.
comment|///
comment|/// This class does not own the underlying data, it is expected to be used in
comment|/// situations where the data resides in some other buffer, whose lifetime
comment|/// extends past that of the StringRef. For this reason, it is not in general
comment|/// safe to store a ArrayRef.
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
name|private
label|:
comment|/// The start of the array, in an external buffer.
specifier|const
name|T
modifier|*
name|Data
decl_stmt|;
comment|/// The number of elements.
name|size_t
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
comment|/// Construct an ArrayRef from a SmallVector.
comment|/*implicit*/
name|ArrayRef
argument_list|(
specifier|const
name|SmallVectorImpl
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
name|data
argument_list|()
argument_list|)
operator|,
name|Length
argument_list|(
argument|Vec.size()
argument_list|)
block|{}
comment|/// Construct an ArrayRef from a std::vector.
comment|/*implicit*/
name|ArrayRef
argument_list|(
specifier|const
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
comment|// TODO: C arrays.
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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

