begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemZCallingConv.h - Calling conventions for SystemZ --*- C++ -*-===//
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
name|LLVM_LIB_TARGET_SYSTEMZ_SYSTEMZCALLINGCONV_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_SYSTEMZ_SYSTEMZCALLINGCONV_H
end_define

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
name|namespace
name|SystemZ
block|{
specifier|const
name|unsigned
name|NumArgGPRs
init|=
literal|5
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|ArgGPRs
index|[
name|NumArgGPRs
index|]
decl_stmt|;
specifier|const
name|unsigned
name|NumArgFPRs
init|=
literal|4
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|ArgFPRs
index|[
name|NumArgFPRs
index|]
decl_stmt|;
block|}
comment|// end namespace SystemZ
name|class
name|SystemZCCState
range|:
name|public
name|CCState
block|{
name|private
operator|:
comment|/// Records whether the value was a fixed argument.
comment|/// See ISD::OutputArg::IsFixed.
name|SmallVector
operator|<
name|bool
block|,
literal|4
operator|>
name|ArgIsFixed
block|;
comment|/// Records whether the value was widened from a short vector type.
name|SmallVector
operator|<
name|bool
block|,
literal|4
operator|>
name|ArgIsShortVector
block|;
comment|// Check whether ArgVT is a short vector type.
name|bool
name|IsShortVectorType
argument_list|(
argument|EVT ArgVT
argument_list|)
block|{
return|return
name|ArgVT
operator|.
name|isVector
argument_list|()
operator|&&
name|ArgVT
operator|.
name|getStoreSize
argument_list|()
operator|<=
literal|8
return|;
block|}
name|public
operator|:
name|SystemZCCState
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
name|void
name|AnalyzeFormalArguments
argument_list|(
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|CCAssignFn Fn
argument_list|)
block|{
comment|// Formal arguments are always fixed.
name|ArgIsFixed
operator|.
name|clear
argument_list|()
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|Ins
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|ArgIsFixed
operator|.
name|push_back
argument_list|(
name|true
argument_list|)
expr_stmt|;
comment|// Record whether the call operand was a short vector.
name|ArgIsShortVector
operator|.
name|clear
argument_list|()
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|Ins
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|ArgIsShortVector
operator|.
name|push_back
argument_list|(
name|IsShortVectorType
argument_list|(
name|Ins
index|[
name|i
index|]
operator|.
name|ArgVT
argument_list|)
argument_list|)
expr_stmt|;
name|CCState
operator|::
name|AnalyzeFormalArguments
argument_list|(
name|Ins
argument_list|,
name|Fn
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|AnalyzeCallOperands
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
argument_list|,
name|CCAssignFn
name|Fn
argument_list|)
block|{
comment|// Record whether the call operand was a fixed argument.
name|ArgIsFixed
operator|.
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|Outs
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|ArgIsFixed
operator|.
name|push_back
argument_list|(
name|Outs
index|[
name|i
index|]
operator|.
name|IsFixed
argument_list|)
expr_stmt|;
comment|// Record whether the call operand was a short vector.
name|ArgIsShortVector
operator|.
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|Outs
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|ArgIsShortVector
operator|.
name|push_back
argument_list|(
name|IsShortVectorType
argument_list|(
name|Outs
index|[
name|i
index|]
operator|.
name|ArgVT
argument_list|)
argument_list|)
expr_stmt|;
name|CCState
operator|::
name|AnalyzeCallOperands
argument_list|(
name|Outs
argument_list|,
name|Fn
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// This version of AnalyzeCallOperands in the base class is not usable
end_comment

begin_comment
comment|// since we must provide a means of accessing ISD::OutputArg::IsFixed.
end_comment

begin_decl_stmt
name|void
name|AnalyzeCallOperands
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|MVT
operator|>
operator|&
name|Outs
argument_list|,
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|ArgFlagsTy
operator|>
operator|&
name|Flags
argument_list|,
name|CCAssignFn
name|Fn
argument_list|)
init|=
name|delete
decl_stmt|;
end_decl_stmt

begin_function
name|bool
name|IsFixed
parameter_list|(
name|unsigned
name|ValNo
parameter_list|)
block|{
return|return
name|ArgIsFixed
index|[
name|ValNo
index|]
return|;
block|}
end_function

begin_function
name|bool
name|IsShortVector
parameter_list|(
name|unsigned
name|ValNo
parameter_list|)
block|{
return|return
name|ArgIsShortVector
index|[
name|ValNo
index|]
return|;
block|}
end_function

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

