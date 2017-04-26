begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- MipsCCState.h - CCState with Mips specific extensions -----------===//
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
name|MIPSCCSTATE_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSCCSTATE_H
end_define

begin_include
include|#
directive|include
file|"MipsISelLowering.h"
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
name|SDNode
decl_stmt|;
name|class
name|MipsSubtarget
decl_stmt|;
name|class
name|MipsCCState
range|:
name|public
name|CCState
block|{
name|public
operator|:
expr|enum
name|SpecialCallingConvType
block|{
name|Mips16RetHelperConv
block|,
name|NoSpecialCallingConv
block|}
block|;
comment|/// Determine the SpecialCallingConvType for the given callee
specifier|static
name|SpecialCallingConvType
name|getSpecialCallingConvForCallee
argument_list|(
specifier|const
name|SDNode
operator|*
name|Callee
argument_list|,
specifier|const
name|MipsSubtarget
operator|&
name|Subtarget
argument_list|)
block|;
name|private
operator|:
comment|/// Identify lowered values that originated from f128 arguments and record
comment|/// this for use by RetCC_MipsN.
name|void
name|PreAnalyzeCallResultForF128
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
argument_list|,
specifier|const
name|Type
operator|*
name|RetTy
argument_list|,
specifier|const
name|char
operator|*
name|Func
argument_list|)
block|;
comment|/// Identify lowered values that originated from f128 arguments and record
comment|/// this for use by RetCC_MipsN.
name|void
name|PreAnalyzeReturnForF128
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
comment|/// Identify lowered values that originated from f128 arguments and record
comment|/// this.
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
argument_list|,
name|std
operator|::
name|vector
operator|<
name|TargetLowering
operator|::
name|ArgListEntry
operator|>
operator|&
name|FuncArgs
argument_list|,
specifier|const
name|char
operator|*
name|Func
argument_list|)
block|;
comment|/// Identify lowered values that originated from f128 arguments and record
comment|/// this.
name|void
name|PreAnalyzeFormalArgumentsForF128
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
comment|/// Records whether the value has been lowered from an f128.
name|SmallVector
operator|<
name|bool
block|,
literal|4
operator|>
name|OriginalArgWasF128
block|;
comment|/// Records whether the value has been lowered from float.
name|SmallVector
operator|<
name|bool
block|,
literal|4
operator|>
name|OriginalArgWasFloat
block|;
comment|/// Records whether the value was a fixed argument.
comment|/// See ISD::OutputArg::IsFixed,
name|SmallVector
operator|<
name|bool
block|,
literal|4
operator|>
name|CallOperandIsFixed
block|;
comment|// Used to handle MIPS16-specific calling convention tweaks.
comment|// FIXME: This should probably be a fully fledged calling convention.
name|SpecialCallingConvType
name|SpecialCallingConv
block|;
name|public
operator|:
name|MipsCCState
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
argument_list|,
argument|SpecialCallingConvType SpecialCC = NoSpecialCallingConv
argument_list|)
operator|:
name|CCState
argument_list|(
name|CC
argument_list|,
name|isVarArg
argument_list|,
name|MF
argument_list|,
name|locs
argument_list|,
name|C
argument_list|)
block|,
name|SpecialCallingConv
argument_list|(
argument|SpecialCC
argument_list|)
block|{}
name|void
name|AnalyzeCallOperands
argument_list|(
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|CCAssignFn Fn
argument_list|,
argument|std::vector<TargetLowering::ArgListEntry>&FuncArgs
argument_list|,
argument|const char *Func
argument_list|)
block|{
name|PreAnalyzeCallOperands
argument_list|(
name|Outs
argument_list|,
name|FuncArgs
argument_list|,
name|Func
argument_list|)
block|;
name|CCState
operator|::
name|AnalyzeCallOperands
argument_list|(
name|Outs
argument_list|,
name|Fn
argument_list|)
block|;
name|OriginalArgWasF128
operator|.
name|clear
argument_list|()
block|;
name|OriginalArgWasFloat
operator|.
name|clear
argument_list|()
block|;
name|CallOperandIsFixed
operator|.
name|clear
argument_list|()
block|;   }
comment|// The AnalyzeCallOperands in the base class is not usable since we must
comment|// provide a means of accessing ArgListEntry::IsFixed. Delete them from this
comment|// class. This doesn't stop them being used via the base class though.
name|void
name|AnalyzeCallOperands
argument_list|(
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|CCAssignFn Fn
argument_list|)
operator|=
name|delete
block|;
name|void
name|AnalyzeCallOperands
argument_list|(
argument|const SmallVectorImpl<MVT>&Outs
argument_list|,
argument|SmallVectorImpl<ISD::ArgFlagsTy>&Flags
argument_list|,
argument|CCAssignFn Fn
argument_list|)
operator|=
name|delete
block|;
name|void
name|AnalyzeFormalArguments
argument_list|(
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|CCAssignFn Fn
argument_list|)
block|{
name|PreAnalyzeFormalArgumentsForF128
argument_list|(
name|Ins
argument_list|)
block|;
name|CCState
operator|::
name|AnalyzeFormalArguments
argument_list|(
name|Ins
argument_list|,
name|Fn
argument_list|)
block|;
name|OriginalArgWasFloat
operator|.
name|clear
argument_list|()
block|;
name|OriginalArgWasF128
operator|.
name|clear
argument_list|()
block|;   }
name|void
name|AnalyzeCallResult
argument_list|(
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|CCAssignFn Fn
argument_list|,
argument|const Type *RetTy
argument_list|,
argument|const char *Func
argument_list|)
block|{
name|PreAnalyzeCallResultForF128
argument_list|(
name|Ins
argument_list|,
name|RetTy
argument_list|,
name|Func
argument_list|)
block|;
name|CCState
operator|::
name|AnalyzeCallResult
argument_list|(
name|Ins
argument_list|,
name|Fn
argument_list|)
block|;
name|OriginalArgWasFloat
operator|.
name|clear
argument_list|()
block|;
name|OriginalArgWasF128
operator|.
name|clear
argument_list|()
block|;   }
name|void
name|AnalyzeReturn
argument_list|(
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|CCAssignFn Fn
argument_list|)
block|{
name|PreAnalyzeReturnForF128
argument_list|(
name|Outs
argument_list|)
block|;
name|CCState
operator|::
name|AnalyzeReturn
argument_list|(
name|Outs
argument_list|,
name|Fn
argument_list|)
block|;
name|OriginalArgWasFloat
operator|.
name|clear
argument_list|()
block|;
name|OriginalArgWasF128
operator|.
name|clear
argument_list|()
block|;   }
name|bool
name|CheckReturn
argument_list|(
argument|const SmallVectorImpl<ISD::OutputArg>&ArgsFlags
argument_list|,
argument|CCAssignFn Fn
argument_list|)
block|{
name|PreAnalyzeReturnForF128
argument_list|(
name|ArgsFlags
argument_list|)
block|;
name|bool
name|Return
operator|=
name|CCState
operator|::
name|CheckReturn
argument_list|(
name|ArgsFlags
argument_list|,
name|Fn
argument_list|)
block|;
name|OriginalArgWasFloat
operator|.
name|clear
argument_list|()
block|;
name|OriginalArgWasF128
operator|.
name|clear
argument_list|()
block|;
return|return
name|Return
return|;
block|}
name|bool
name|WasOriginalArgF128
argument_list|(
argument|unsigned ValNo
argument_list|)
block|{
return|return
name|OriginalArgWasF128
index|[
name|ValNo
index|]
return|;
block|}
name|bool
name|WasOriginalArgFloat
argument_list|(
argument|unsigned ValNo
argument_list|)
block|{
return|return
name|OriginalArgWasFloat
index|[
name|ValNo
index|]
return|;
block|}
name|bool
name|IsCallOperandFixed
argument_list|(
argument|unsigned ValNo
argument_list|)
block|{
return|return
name|CallOperandIsFixed
index|[
name|ValNo
index|]
return|;
block|}
name|SpecialCallingConvType
name|getSpecialCallingConv
argument_list|()
block|{
return|return
name|SpecialCallingConv
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

