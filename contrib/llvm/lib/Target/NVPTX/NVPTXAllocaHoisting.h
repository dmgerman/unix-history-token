begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AllocaHoisting.h - Hosist allocas to the entry block ----*- C++ -*-===//
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
comment|// Hoist the alloca instructions in the non-entry blocks to the entry blocks.
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
name|NVPTX_ALLOCA_HOISTING_H_
end_ifndef

begin_define
define|#
directive|define
name|NVPTX_ALLOCA_HOISTING_H_
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionPass
decl_stmt|;
name|class
name|Function
decl_stmt|;
comment|// Hoisting the alloca instructions in the non-entry blocks to the entry
comment|// block.
name|class
name|NVPTXAllocaHoisting
range|:
name|public
name|FunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass ID
name|NVPTXAllocaHoisting
argument_list|()
operator|:
name|FunctionPass
argument_list|(
argument|ID
argument_list|)
block|{}
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|{
name|AU
operator|.
name|addRequired
operator|<
name|DataLayoutPass
operator|>
operator|(
operator|)
block|;
name|AU
operator|.
name|addPreserved
argument_list|(
literal|"stack-protector"
argument_list|)
block|;
name|AU
operator|.
name|addPreserved
operator|<
name|MachineFunctionAnalysis
operator|>
operator|(
operator|)
block|;   }
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"NVPTX specific alloca hoisting"
return|;
block|}
name|bool
name|runOnFunction
argument_list|(
argument|Function&function
argument_list|)
name|override
block|; }
decl_stmt|;
specifier|extern
name|FunctionPass
modifier|*
name|createAllocaHoisting
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// NVPTX_ALLOCA_HOISTING_H_
end_comment

end_unit

