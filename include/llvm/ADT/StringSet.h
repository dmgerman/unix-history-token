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

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// StringSet - A wrapper for StringMap that provides set-like
comment|/// functionality.  Only insert() and count() methods are used by my
comment|/// code.
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
name|bool
name|insert
argument_list|(
argument|const std::string& InLang
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|InLang
operator|.
name|empty
argument_list|()
argument_list|)
block|;
specifier|const
name|char
operator|*
name|KeyStart
operator|=
operator|&
name|InLang
index|[
literal|0
index|]
block|;
specifier|const
name|char
operator|*
name|KeyEnd
operator|=
name|KeyStart
operator|+
name|InLang
operator|.
name|size
argument_list|()
block|;
return|return
name|base
operator|::
name|insert
argument_list|(
name|llvm
operator|::
name|StringMapEntry
operator|<
name|char
operator|>
operator|::
name|Create
argument_list|(
name|KeyStart
argument_list|,
name|KeyEnd
argument_list|,
name|base
operator|::
name|getAllocator
argument_list|()
argument_list|,
literal|'+'
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

