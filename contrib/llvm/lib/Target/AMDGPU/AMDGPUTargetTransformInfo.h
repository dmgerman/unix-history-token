begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUTargetTransformInfo.h - AMDGPU specific TTI -------*- C++ -*-===//
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
comment|/// AMDGPU target machine. It uses the target's detailed information to
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
name|LLVM_LIB_TARGET_R600_AMDGPUTARGETTRANSFORMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_R600_AMDGPUTARGETTRANSFORMINFO_H
end_define

begin_include
include|#
directive|include
file|"AMDGPU.h"
end_include

begin_include
include|#
directive|include
file|"AMDGPUTargetMachine.h"
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
name|AMDGPUTTIImpl
range|:
name|public
name|BasicTTIImplBase
operator|<
name|AMDGPUTTIImpl
operator|>
block|{
typedef|typedef
name|BasicTTIImplBase
operator|<
name|AMDGPUTTIImpl
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
name|AMDGPUSubtarget
modifier|*
name|ST
decl_stmt|;
specifier|const
name|AMDGPUTargetLowering
modifier|*
name|TLI
decl_stmt|;
specifier|const
name|AMDGPUSubtarget
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
name|AMDGPUTargetLowering
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
name|AMDGPUTTIImpl
argument_list|(
specifier|const
name|AMDGPUTargetMachine
operator|*
name|TM
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
operator|:
name|BaseT
argument_list|(
name|TM
argument_list|,
name|DL
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
comment|// Provide value semantics. MSVC requires that we spell all of these out.
name|AMDGPUTTIImpl
argument_list|(
specifier|const
name|AMDGPUTTIImpl
operator|&
name|Arg
argument_list|)
operator|:
name|BaseT
argument_list|(
name|static_cast
operator|<
specifier|const
name|BaseT
operator|&
operator|>
operator|(
name|Arg
operator|)
argument_list|)
operator|,
name|ST
argument_list|(
name|Arg
operator|.
name|ST
argument_list|)
operator|,
name|TLI
argument_list|(
argument|Arg.TLI
argument_list|)
block|{}
name|AMDGPUTTIImpl
argument_list|(
name|AMDGPUTTIImpl
operator|&&
name|Arg
argument_list|)
operator|:
name|BaseT
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|static_cast
operator|<
name|BaseT
operator|&
operator|>
operator|(
name|Arg
operator|)
argument_list|)
argument_list|)
operator|,
name|ST
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Arg
operator|.
name|ST
argument_list|)
argument_list|)
operator|,
name|TLI
argument_list|(
argument|std::move(Arg.TLI)
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
name|void
name|getUnrollingPreferences
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|TTI
operator|::
name|UnrollingPreferences
operator|&
name|UP
argument_list|)
decl_stmt|;
name|TTI
operator|::
name|PopcntSupportKind
name|getPopcntSupport
argument_list|(
argument|unsigned TyWidth
argument_list|)
block|{
name|assert
argument_list|(
name|isPowerOf2_32
argument_list|(
name|TyWidth
argument_list|)
operator|&&
literal|"Ty width must be power of 2"
argument_list|)
block|;
return|return
name|ST
operator|->
name|hasBCNT
argument_list|(
name|TyWidth
argument_list|)
condition|?
name|TTI
operator|::
name|PSK_FastHardware
else|:
name|TTI
operator|::
name|PSK_Software
return|;
block|}
name|unsigned
name|getNumberOfRegisters
parameter_list|(
name|bool
name|Vector
parameter_list|)
function_decl|;
name|unsigned
name|getRegisterBitWidth
parameter_list|(
name|bool
name|Vector
parameter_list|)
function_decl|;
name|unsigned
name|getMaxInterleaveFactor
parameter_list|(
name|unsigned
name|VF
parameter_list|)
function_decl|;
name|unsigned
name|getCFInstrCost
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
function_decl|;
name|int
name|getVectorInstrCost
parameter_list|(
name|unsigned
name|Opcode
parameter_list|,
name|Type
modifier|*
name|ValTy
parameter_list|,
name|unsigned
name|Index
parameter_list|)
function_decl|;
name|bool
name|isSourceOfDivergence
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
decl|const
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

