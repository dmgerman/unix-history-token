begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- EscapeEnumerator.h --------------------------------------*- C++ -*-===//
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
comment|// Defines a helper class that enumerates all possible exits from a function,
end_comment

begin_comment
comment|// including exception handling.
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
name|LLVM_TRANSFORMS_UTILS_ESCAPEENUMERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_ESCAPEENUMERATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// EscapeEnumerator - This is a little algorithm to find all escape points
comment|/// from a function so that "finally"-style code can be inserted. In addition
comment|/// to finding the existing return and unwind instructions, it also (if
comment|/// necessary) transforms any call instructions into invokes and sends them to
comment|/// a landing pad.
name|class
name|EscapeEnumerator
block|{
name|Function
modifier|&
name|F
decl_stmt|;
specifier|const
name|char
modifier|*
name|CleanupBBName
decl_stmt|;
name|Function
operator|::
name|iterator
name|StateBB
operator|,
name|StateE
expr_stmt|;
name|IRBuilder
operator|<
operator|>
name|Builder
expr_stmt|;
name|bool
name|Done
decl_stmt|;
name|bool
name|HandleExceptions
decl_stmt|;
name|public
label|:
name|EscapeEnumerator
argument_list|(
argument|Function&F
argument_list|,
argument|const char *N =
literal|"cleanup"
argument_list|,
argument|bool HandleExceptions = true
argument_list|)
block|:
name|F
argument_list|(
name|F
argument_list|)
operator|,
name|CleanupBBName
argument_list|(
name|N
argument_list|)
operator|,
name|StateBB
argument_list|(
name|F
operator|.
name|begin
argument_list|()
argument_list|)
operator|,
name|StateE
argument_list|(
name|F
operator|.
name|end
argument_list|()
argument_list|)
operator|,
name|Builder
argument_list|(
name|F
operator|.
name|getContext
argument_list|()
argument_list|)
operator|,
name|Done
argument_list|(
name|false
argument_list|)
operator|,
name|HandleExceptions
argument_list|(
argument|HandleExceptions
argument_list|)
block|{}
name|IRBuilder
operator|<
operator|>
operator|*
name|Next
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_UTILS_ESCAPEENUMERATOR_H
end_comment

end_unit

