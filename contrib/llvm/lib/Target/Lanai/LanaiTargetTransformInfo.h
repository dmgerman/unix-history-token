begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LanaiTargetTransformInfo.h - Lanai specific TTI ---------*- C++ -*-===//
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
comment|// This file a TargetTransformInfo::Concept conforming object specific to the
end_comment

begin_comment
comment|// Lanai target machine. It uses the target's detailed information to
end_comment

begin_comment
comment|// provide more precise answers to certain TTI queries, while letting the
end_comment

begin_comment
comment|// target independent and default TTI implementations handle the rest.
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
name|LLVM_LIB_TARGET_LANAI_LANAITARGETTRANSFORMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_LANAI_LANAITARGETTRANSFORMINFO_H
end_define

begin_include
include|#
directive|include
file|"Lanai.h"
end_include

begin_include
include|#
directive|include
file|"LanaiSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"LanaiTargetMachine.h"
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
name|LanaiTTIImpl
range|:
name|public
name|BasicTTIImplBase
operator|<
name|LanaiTTIImpl
operator|>
block|{
typedef|typedef
name|BasicTTIImplBase
operator|<
name|LanaiTTIImpl
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
name|LanaiSubtarget
modifier|*
name|ST
decl_stmt|;
specifier|const
name|LanaiTargetLowering
modifier|*
name|TLI
decl_stmt|;
specifier|const
name|LanaiSubtarget
operator|*
name|getST
argument_list|()
specifier|const
block|{
return|return
name|ST
return|;
block|}
specifier|const
name|LanaiTargetLowering
operator|*
name|getTLI
argument_list|()
specifier|const
block|{
return|return
name|TLI
return|;
block|}
name|public
label|:
name|explicit
name|LanaiTTIImpl
argument_list|(
specifier|const
name|LanaiTargetMachine
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
argument_list|(
name|F
argument_list|)
argument_list|)
operator|,
name|TLI
argument_list|(
argument|ST->getTargetLowering()
argument_list|)
block|{}
name|bool
name|shouldBuildLookupTables
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|TargetTransformInfo
operator|::
name|PopcntSupportKind
name|getPopcntSupport
argument_list|(
argument|unsigned TyWidth
argument_list|)
block|{
if|if
condition|(
name|TyWidth
operator|==
literal|32
condition|)
return|return
name|TTI
operator|::
name|PSK_FastHardware
return|;
return|return
name|TTI
operator|::
name|PSK_Software
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|unsigned
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
block|{
name|int
name|ISD
init|=
name|TLI
operator|->
name|InstructionOpcodeToISD
argument_list|(
name|Opcode
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|ISD
condition|)
block|{
default|default:
return|return
name|BaseT
operator|::
name|getArithmeticInstrCost
argument_list|(
name|Opcode
argument_list|,
name|Ty
argument_list|,
name|Opd1Info
argument_list|,
name|Opd2Info
argument_list|,
name|Opd1PropInfo
argument_list|,
name|Opd2PropInfo
argument_list|)
return|;
case|case
name|ISD
operator|::
name|MUL
case|:
case|case
name|ISD
operator|::
name|SDIV
case|:
case|case
name|ISD
operator|::
name|UDIV
case|:
case|case
name|ISD
operator|::
name|UREM
case|:
comment|// This increases the cost associated with multiplication and division
comment|// to 64 times what the baseline arithmetic cost is. The arithmetic
comment|// instruction cost was arbitrarily chosen to reduce the desirability
comment|// of emitting arithmetic instructions that are emulated in software.
comment|// TODO: Investigate the performance impact given specialized lowerings.
return|return
literal|64
operator|*
name|BaseT
operator|::
name|getArithmeticInstrCost
argument_list|(
name|Opcode
argument_list|,
name|Ty
argument_list|,
name|Opd1Info
argument_list|,
name|Opd2Info
argument_list|,
name|Opd1PropInfo
argument_list|,
name|Opd2PropInfo
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_LANAI_LANAITARGETTRANSFORMINFO_H
end_comment

end_unit

