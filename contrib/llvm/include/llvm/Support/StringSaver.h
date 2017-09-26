begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/StringSaver.h -------------------------------*- C++ -*-===//
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
name|LLVM_SUPPORT_STRINGSAVER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_STRINGSAVER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Saves strings in the inheritor's stable storage and returns a
comment|/// StringRef with a stable character pointer.
name|class
name|StringSaver
name|final
block|{
name|BumpPtrAllocator
modifier|&
name|Alloc
decl_stmt|;
name|public
label|:
name|StringSaver
argument_list|(
name|BumpPtrAllocator
operator|&
name|Alloc
argument_list|)
operator|:
name|Alloc
argument_list|(
argument|Alloc
argument_list|)
block|{}
name|StringRef
name|save
argument_list|(
argument|const char *S
argument_list|)
block|{
return|return
name|save
argument_list|(
name|StringRef
argument_list|(
name|S
argument_list|)
argument_list|)
return|;
block|}
name|StringRef
name|save
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
name|StringRef
name|save
parameter_list|(
specifier|const
name|Twine
modifier|&
name|S
parameter_list|)
block|{
return|return
name|save
argument_list|(
name|StringRef
argument_list|(
name|S
operator|.
name|str
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
name|StringRef
name|save
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|S
argument_list|)
block|{
return|return
name|save
argument_list|(
name|StringRef
argument_list|(
name|S
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

end_unit

