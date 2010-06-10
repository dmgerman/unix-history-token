begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/IndexedMap.h - An index map implementation ------*- C++ -*-===//
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
comment|// This file implements an indexed map. The index map template takes two
end_comment

begin_comment
comment|// types. The first is the mapped type and the second is a functor
end_comment

begin_comment
comment|// that maps its argument to a size_t. On instantiation a "null" value
end_comment

begin_comment
comment|// can be provided to be used as a "does not exist" indicator in the
end_comment

begin_comment
comment|// map. A member function grow() is provided that given the value of
end_comment

begin_comment
comment|// the maximally indexed key (the argument of the functor) makes sure
end_comment

begin_comment
comment|// the map has enough space for it.
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
name|LLVM_ADT_INDEXEDMAP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_INDEXEDMAP_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<functional>
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
name|struct
name|IdentityFunctor
range|:
name|public
name|std
operator|::
name|unary_function
operator|<
name|unsigned
decl_stmt|,
name|unsigned
decl|>
block|{
name|unsigned
name|operator
argument_list|()
operator|(
name|unsigned
name|Index
operator|)
specifier|const
block|{
return|return
name|Index
return|;
block|}
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|ToIndexT
operator|=
name|IdentityFunctor
operator|>
name|class
name|IndexedMap
block|{
typedef|typedef
name|typename
name|ToIndexT
operator|::
name|argument_type
name|IndexT
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|T
operator|>
name|StorageT
expr_stmt|;
name|StorageT
name|storage_
decl_stmt|;
name|T
name|nullVal_
decl_stmt|;
name|ToIndexT
name|toIndex_
decl_stmt|;
name|public
label|:
name|IndexedMap
argument_list|()
operator|:
name|nullVal_
argument_list|(
argument|T()
argument_list|)
block|{ }
name|explicit
name|IndexedMap
argument_list|(
specifier|const
name|T
operator|&
name|val
argument_list|)
operator|:
name|nullVal_
argument_list|(
argument|val
argument_list|)
block|{ }
name|typename
name|StorageT
operator|::
name|reference
name|operator
index|[]
operator|(
name|IndexT
name|n
operator|)
block|{
name|assert
argument_list|(
name|toIndex_
argument_list|(
name|n
argument_list|)
operator|<
name|storage_
operator|.
name|size
argument_list|()
operator|&&
literal|"index out of bounds!"
argument_list|)
block|;
return|return
name|storage_
index|[
name|toIndex_
argument_list|(
name|n
argument_list|)
index|]
return|;
block|}
name|typename
name|StorageT
operator|::
name|const_reference
name|operator
index|[]
operator|(
name|IndexT
name|n
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|toIndex_
argument_list|(
name|n
argument_list|)
operator|<
name|storage_
operator|.
name|size
argument_list|()
operator|&&
literal|"index out of bounds!"
argument_list|)
block|;
return|return
name|storage_
index|[
name|toIndex_
argument_list|(
name|n
argument_list|)
index|]
return|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|storage_
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|void
name|grow
parameter_list|(
name|IndexT
name|n
parameter_list|)
block|{
name|unsigned
name|NewSize
init|=
name|toIndex_
argument_list|(
name|n
argument_list|)
operator|+
literal|1
decl_stmt|;
if|if
condition|(
name|NewSize
operator|>
name|storage_
operator|.
name|size
argument_list|()
condition|)
name|storage_
operator|.
name|resize
argument_list|(
name|NewSize
argument_list|,
name|nullVal_
argument_list|)
expr_stmt|;
block|}
name|typename
name|StorageT
operator|::
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|storage_
operator|.
name|size
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

