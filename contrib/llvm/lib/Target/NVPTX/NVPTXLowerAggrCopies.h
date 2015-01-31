begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/lib/Target/NVPTX/NVPTXLowerAggrCopies.h ------------*- C++ -*-===//
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
comment|// This file contains the declaration of the NVIDIA specific lowering of
end_comment

begin_comment
comment|// aggregate copies
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
name|LLVM_LIB_TARGET_NVPTX_NVPTXLOWERAGGRCOPIES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_NVPTX_NVPTXLOWERAGGRCOPIES_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/StackProtector.h"
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
comment|// actual analysis class, which is a functionpass
name|struct
name|NVPTXLowerAggrCopies
range|:
name|public
name|FunctionPass
block|{
specifier|static
name|char
name|ID
block|;
name|NVPTXLowerAggrCopies
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
operator|<
name|MachineFunctionAnalysis
operator|>
operator|(
operator|)
block|;
name|AU
operator|.
name|addPreserved
operator|<
name|StackProtector
operator|>
operator|(
operator|)
block|;   }
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|;
specifier|static
specifier|const
name|unsigned
name|MaxAggrCopySize
operator|=
literal|128
block|;
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"Lower aggregate copies/intrinsics into loops"
return|;
block|}
expr|}
block|;
specifier|extern
name|FunctionPass
operator|*
name|createLowerAggrCopies
argument_list|()
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

