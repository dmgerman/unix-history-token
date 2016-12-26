begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- PPCCCState.h - CCState with PowerPC specific extensions -----------===//
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
name|PPCCCSTATE_H
end_ifndef

begin_define
define|#
directive|define
name|PPCCCSTATE_H
end_define

begin_include
include|#
directive|include
file|"PPCISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/CallingConvLower.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PPCCCState
range|:
name|public
name|CCState
block|{
name|public
operator|:
name|void
name|PreAnalyzeCallOperands
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
name|Outs
argument_list|)
block|;
name|void
name|PreAnalyzeFormalArguments
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|)
block|;
name|private
operator|:
comment|// Records whether the value has been lowered from an ppcf128.
name|SmallVector
operator|<
name|bool
block|,
literal|4
operator|>
name|OriginalArgWasPPCF128
block|;
name|public
operator|:
name|PPCCCState
argument_list|(
argument|CallingConv::ID CC
argument_list|,
argument|bool isVarArg
argument_list|,
argument|MachineFunction&MF
argument_list|,
argument|SmallVectorImpl<CCValAssign>&locs
argument_list|,
argument|LLVMContext&C
argument_list|)
operator|:
name|CCState
argument_list|(
argument|CC
argument_list|,
argument|isVarArg
argument_list|,
argument|MF
argument_list|,
argument|locs
argument_list|,
argument|C
argument_list|)
block|{}
name|bool
name|WasOriginalArgPPCF128
argument_list|(
argument|unsigned ValNo
argument_list|)
block|{
return|return
name|OriginalArgWasPPCF128
index|[
name|ValNo
index|]
return|;
block|}
name|void
name|clearWasPPCF128
argument_list|()
block|{
name|OriginalArgWasPPCF128
operator|.
name|clear
argument_list|()
block|; }
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

