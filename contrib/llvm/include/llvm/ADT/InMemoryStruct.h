begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InMemoryStruct.h - Indirect Struct Access Smart Pointer --*- C++ -*-===//
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
name|LLVM_ADT_INMEMORYSTRUCT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_INMEMORYSTRUCT_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Helper object for abstracting access to an in-memory structure which
comment|/// may require some kind of temporary storage.
comment|///
comment|/// This class is designed to be used for accessing file data structures which
comment|/// in the common case can be accessed from a direct pointer to a memory mapped
comment|/// object, but which in some cases may require indirect access to a temporary
comment|/// structure (which, for example, may have undergone endianness translation).
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|InMemoryStruct
block|{
typedef|typedef
name|T
name|value_type
typedef|;
typedef|typedef
name|value_type
modifier|&
name|reference
typedef|;
typedef|typedef
name|value_type
modifier|*
name|pointer
typedef|;
typedef|typedef
specifier|const
name|value_type
modifier|&
name|const_reference
typedef|;
typedef|typedef
specifier|const
name|value_type
modifier|*
name|const_pointer
typedef|;
comment|/// \brief The smart pointer target.
name|value_type
modifier|*
name|Target
decl_stmt|;
comment|/// \brief A temporary object which can be used as a target of the smart
comment|/// pointer.
name|value_type
name|Contents
decl_stmt|;
name|private
label|:
name|public
label|:
name|InMemoryStruct
argument_list|()
operator|:
name|Target
argument_list|(
literal|0
argument_list|)
block|{}
name|InMemoryStruct
argument_list|(
argument|reference Value
argument_list|)
operator|:
name|Target
argument_list|(
operator|&
name|Contents
argument_list|)
operator|,
name|Contents
argument_list|(
argument|Value
argument_list|)
block|{}
name|InMemoryStruct
argument_list|(
argument|pointer Value
argument_list|)
operator|:
name|Target
argument_list|(
argument|Value
argument_list|)
block|{}
name|InMemoryStruct
argument_list|(
argument|const InMemoryStruct<T>&Value
argument_list|)
block|{
operator|*
name|this
operator|=
name|Value
block|; }
name|void
name|operator
operator|=
operator|(
specifier|const
name|InMemoryStruct
operator|<
name|T
operator|>
operator|&
name|Value
operator|)
block|{
if|if
condition|(
name|Value
operator|.
name|Target
operator|!=
operator|&
name|Value
operator|.
name|Contents
condition|)
block|{
name|Target
operator|=
name|Value
operator|.
name|Target
expr_stmt|;
block|}
else|else
block|{
name|Target
operator|=
operator|&
name|Contents
expr_stmt|;
name|Contents
operator|=
name|Value
operator|.
name|Contents
expr_stmt|;
block|}
block|}
name|const_reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Target
operator|&&
literal|"Cannot dereference null pointer"
argument_list|)
block|;
return|return
operator|*
name|Target
return|;
block|}
name|reference
name|operator
modifier|*
parameter_list|()
block|{
name|assert
argument_list|(
name|Target
operator|&&
literal|"Cannot dereference null pointer"
argument_list|)
expr_stmt|;
return|return
operator|*
name|Target
return|;
block|}
name|const_pointer
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|Target
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|pointer
name|operator
operator|->
expr|(
end_expr_stmt

begin_block
unit|)
block|{
return|return
name|Target
return|;
block|}
end_block

begin_expr_stmt
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Target
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_endif
unit|};  }
endif|#
directive|endif
end_endif

end_unit

