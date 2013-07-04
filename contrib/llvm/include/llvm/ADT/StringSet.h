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
comment|/// insert - Insert the specified key into the set.  If the key already
comment|/// exists in the set, return false and ignore the request, otherwise insert
comment|/// it and return true.
name|bool
name|insert
argument_list|(
argument|StringRef Key
argument_list|)
block|{
comment|// Get or create the map entry for the key; if it doesn't exist the value
comment|// type will be default constructed which we use to detect insert.
comment|//
comment|// We use '+' as the sentinel value in the map.
name|assert
argument_list|(
operator|!
name|Key
operator|.
name|empty
argument_list|()
argument_list|)
block|;
name|StringMapEntry
operator|<
name|char
operator|>
operator|&
name|Entry
operator|=
name|this
operator|->
name|GetOrCreateValue
argument_list|(
name|Key
argument_list|)
block|;
if|if
condition|(
name|Entry
operator|.
name|getValue
argument_list|()
operator|==
literal|'+'
condition|)
return|return
name|false
return|;
name|Entry
operator|.
name|setValue
argument_list|(
literal|'+'
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_decl_stmt

begin_endif
unit|}; }
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_STRINGSET_H
end_comment

end_unit

