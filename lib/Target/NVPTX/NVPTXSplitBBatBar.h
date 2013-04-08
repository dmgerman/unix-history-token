begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/lib/Target/NVPTX/NVPTXSplitBBatBar.h ---------------*- C++ -*-===//
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
comment|// This file contains the declaration of the NVIDIA specific declarations
end_comment

begin_comment
comment|// for splitting basic blocks at barrier instructions.
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
name|NVPTX_SPLIT_BB_AT_BAR_H
end_ifndef

begin_define
define|#
directive|define
name|NVPTX_SPLIT_BB_AT_BAR_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionAnalysis.h"
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
comment|// actual analysis class, which is a functionpass
name|struct
name|NVPTXSplitBBatBar
range|:
name|public
name|FunctionPass
block|{
specifier|static
name|char
name|ID
block|;
name|NVPTXSplitBBatBar
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
block|{
name|AU
operator|.
name|addPreserved
operator|<
name|MachineFunctionAnalysis
operator|>
operator|(
operator|)
block|;   }
name|virtual
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"Split basic blocks at barrier"
return|;
block|}
expr|}
block|;
specifier|extern
name|FunctionPass
operator|*
name|createSplitBBatBarPass
argument_list|()
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//NVPTX_SPLIT_BB_AT_BAR_H
end_comment

end_unit

