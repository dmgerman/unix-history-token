begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StripDeadPrototypes.h - Remove unused function declarations -------===//
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
comment|// This pass loops over all of the functions in the input module, looking for
end_comment

begin_comment
comment|// dead declarations and removes them. Dead declarations are declarations of
end_comment

begin_comment
comment|// functions for which no implementation is available (i.e., declarations for
end_comment

begin_comment
comment|// unused library functions).
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
name|LLVM_TRANSFORMS_IPO_STRIPDEADPROTOTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_STRIPDEADPROTOTYPES_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Pass to remove unused function declarations.
name|class
name|StripDeadPrototypesPass
block|{
name|public
label|:
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"StripDeadPrototypesPass"
return|;
block|}
name|PreservedAnalyses
name|run
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_IPO_STRIPDEADPROTOTYPES_H
end_comment

end_unit

