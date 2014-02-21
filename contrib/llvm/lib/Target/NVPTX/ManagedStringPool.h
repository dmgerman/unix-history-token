begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ManagedStringPool.h - Managed String Pool ---------------*- C++ -*-===//
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
comment|// The strings allocated from a managed string pool are owned by the string
end_comment

begin_comment
comment|// pool and will be deleted together with the managed string pool.
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
name|LLVM_SUPPORT_MANAGED_STRING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_MANAGED_STRING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// ManagedStringPool - The strings allocated from a managed string pool are
comment|/// owned by the string pool and will be deleted together with the managed
comment|/// string pool.
name|class
name|ManagedStringPool
block|{
name|SmallVector
operator|<
name|std
operator|::
name|string
operator|*
operator|,
literal|8
operator|>
name|Pool
expr_stmt|;
name|public
label|:
name|ManagedStringPool
argument_list|()
block|{}
operator|~
name|ManagedStringPool
argument_list|()
block|{
name|SmallVectorImpl
operator|<
name|std
operator|::
name|string
operator|*
operator|>
operator|::
name|iterator
name|Current
operator|=
name|Pool
operator|.
name|begin
argument_list|()
block|;
while|while
condition|(
name|Current
operator|!=
name|Pool
operator|.
name|end
argument_list|()
condition|)
block|{
name|delete
modifier|*
name|Current
decl_stmt|;
name|Current
operator|++
expr_stmt|;
block|}
block|}
name|std
operator|::
name|string
operator|*
name|getManagedString
argument_list|(
argument|const char *S
argument_list|)
block|{
name|std
operator|::
name|string
operator|*
name|Str
operator|=
name|new
name|std
operator|::
name|string
argument_list|(
name|S
argument_list|)
block|;
name|Pool
operator|.
name|push_back
argument_list|(
name|Str
argument_list|)
block|;
return|return
name|Str
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

