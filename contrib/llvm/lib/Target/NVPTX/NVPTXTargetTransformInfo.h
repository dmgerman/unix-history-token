begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NVPTXTargetTransformInfo.h - NVPTX specific TTI ---------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// This file a TargetTransformInfo::Concept conforming object specific to the
end_comment

begin_comment
comment|/// NVPTX target machine. It uses the target's detailed information to
end_comment

begin_comment
comment|/// provide more precise answers to certain TTI queries, while letting the
end_comment

begin_comment
comment|/// target independent and default TTI implementations handle the rest.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_NVPTX_NVPTXTARGETTRANSFORMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_NVPTX_NVPTXTARGETTRANSFORMINFO_H
end_define

begin_include
include|#
directive|include
file|"NVPTX.h"
end_include

begin_include
include|#
directive|include
file|"NVPTXTargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetTransformInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/BasicTTIImpl.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|NVPTXTTIImpl
range|:
name|public
name|BasicTTIImplBase
operator|<
name|NVPTXTTIImpl
operator|>
block|{
typedef|typedef
name|BasicTTIImplBase
operator|<
name|NVPTXTTIImpl
operator|>
name|BaseT
expr_stmt|;
typedef|typedef
name|TargetTransformInfo
name|TTI
typedef|;
name|friend
name|BaseT
decl_stmt|;
specifier|const
name|NVPTXSubtarget
modifier|*
name|ST
decl_stmt|;
specifier|const
name|NVPTXTargetLowering
modifier|*
name|TLI
decl_stmt|;
specifier|const
name|NVPTXSubtarget
operator|*
name|getST
argument_list|()
specifier|const
block|{
return|return
name|ST
return|;
block|}
empty_stmt|;
specifier|const
name|NVPTXTargetLowering
operator|*
name|getTLI
argument_list|()
specifier|const
block|{
return|return
name|TLI
return|;
block|}
empty_stmt|;
name|public
label|:
name|explicit
name|NVPTXTTIImpl
argument_list|(
specifier|const
name|NVPTXTargetMachine
operator|*
name|TM
argument_list|,
specifier|const
name|Function
operator|&
name|F
argument_list|)
operator|:
name|BaseT
argument_list|(
name|TM
argument_list|,
name|F
operator|.
name|getParent
argument_list|()
operator|->
name|getDataLayout
argument_list|()
argument_list|)
operator|,
name|ST
argument_list|(
name|TM
operator|->
name|getSubtargetImpl
argument_list|()
argument_list|)
operator|,
name|TLI
argument_list|(
argument|ST->getTargetLowering()
argument_list|)
block|{}
name|bool
name|hasBranchDivergence
argument_list|()
block|{
return|return
name|true
return|;
block|}
name|bool
name|isSourceOfDivergence
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
name|unsigned
name|getFlatAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|AddressSpace
operator|::
name|ADDRESS_SPACE_GENERIC
return|;
block|}
comment|// Increase the inlining cost threshold by a factor of 5, reflecting that
comment|// calls are particularly expensive in NVPTX.
name|unsigned
name|getInliningThresholdMultiplier
parameter_list|()
block|{
return|return
literal|5
return|;
block|}
name|int
name|getArithmeticInstrCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
name|TTI
operator|::
name|OperandValueKind
name|Opd1Info
operator|=
name|TTI
operator|::
name|OK_AnyValue
argument_list|,
name|TTI
operator|::
name|OperandValueKind
name|Opd2Info
operator|=
name|TTI
operator|::
name|OK_AnyValue
argument_list|,
name|TTI
operator|::
name|OperandValueProperties
name|Opd1PropInfo
operator|=
name|TTI
operator|::
name|OP_None
argument_list|,
name|TTI
operator|::
name|OperandValueProperties
name|Opd2PropInfo
operator|=
name|TTI
operator|::
name|OP_None
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Value
operator|*
operator|>
name|Args
operator|=
name|ArrayRef
operator|<
specifier|const
name|Value
operator|*
operator|>
operator|(
operator|)
argument_list|)
decl_stmt|;
name|void
name|getUnrollingPreferences
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|ScalarEvolution
operator|&
name|SE
argument_list|,
name|TTI
operator|::
name|UnrollingPreferences
operator|&
name|UP
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

