begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- StringSet.h - The LLVM Compiler Driver -----------------*- C++ -*-===//
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
comment|// This file is distributed under the University of Illinois Open
end_comment

begin_comment
comment|// Source License. See LICENSE.TXT for details.
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
comment|//  StringSet - A set-like wrapper for the StringMap.
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
name|LLVM_ADT_STRINGSET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_STRINGSET_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// StringSet - A wrapper for StringMap that provides set-like functionality.
name|template
operator|<
name|class
name|AllocatorTy
operator|=
name|llvm
operator|::
name|MallocAllocator
operator|>
name|class
name|StringSet
operator|:
name|public
name|llvm
operator|::
name|StringMap
operator|<
name|char
operator|,
name|AllocatorTy
operator|>
block|{
typedef|typedef
name|llvm
operator|::
name|StringMap
operator|<
name|char
operator|,
name|AllocatorTy
operator|>
name|base
expr_stmt|;
name|public
operator|:
name|std
operator|::
name|pair
operator|<
name|typename
name|base
operator|::
name|iterator
operator|,
name|bool
operator|>
name|insert
argument_list|(
argument|StringRef Key
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|Key
operator|.
name|empty
argument_list|()
argument_list|)
block|;
return|return
name|base
operator|::
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Key
argument_list|,
literal|'\0'
argument_list|)
argument_list|)
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

begin_comment
comment|// LLVM_ADT_STRINGSET_H
end_comment

end_unit

