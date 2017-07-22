begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- WebAssemblyTargetTransformInfo.h - WebAssembly-specific TTI -*- C++ -*-=//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file a TargetTransformInfo::Concept conforming object specific
end_comment

begin_comment
comment|/// to the WebAssembly target machine.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It uses the target's detailed information to provide more precise answers to
end_comment

begin_comment
comment|/// certain TTI queries, while letting the target independent and default TTI
end_comment

begin_comment
comment|/// implementations handle the rest.
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
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYTARGETTRANSFORMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYTARGETTRANSFORMINFO_H
end_define

begin_include
include|#
directive|include
file|"WebAssemblyTargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/BasicTTIImpl.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|WebAssemblyTTIImpl
name|final
range|:
name|public
name|BasicTTIImplBase
operator|<
name|WebAssemblyTTIImpl
operator|>
block|{
typedef|typedef
name|BasicTTIImplBase
operator|<
name|WebAssemblyTTIImpl
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
name|WebAssemblySubtarget
modifier|*
name|ST
decl_stmt|;
specifier|const
name|WebAssemblyTargetLowering
modifier|*
name|TLI
decl_stmt|;
specifier|const
name|WebAssemblySubtarget
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
name|WebAssemblyTargetLowering
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
name|WebAssemblyTTIImpl
argument_list|(
specifier|const
name|WebAssemblyTargetMachine
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
comment|/// \name Scalar TTI Implementations
comment|/// @{
comment|// TODO: Implement more Scalar TTI for WebAssembly
name|TTI
operator|::
name|PopcntSupportKind
name|getPopcntSupport
argument_list|(
argument|unsigned TyWidth
argument_list|)
specifier|const
expr_stmt|;
comment|/// @}
comment|/// \name Vector TTI Implementations
comment|/// @{
name|unsigned
name|getNumberOfRegisters
parameter_list|(
name|bool
name|Vector
parameter_list|)
function_decl|;
name|unsigned
name|getRegisterBitWidth
argument_list|(
name|bool
name|Vector
argument_list|)
decl|const
decl_stmt|;
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
decl_stmt|;
name|unsigned
name|getVectorInstrCost
parameter_list|(
name|unsigned
name|Opcode
parameter_list|,
name|Type
modifier|*
name|Val
parameter_list|,
name|unsigned
name|Index
parameter_list|)
function_decl|;
comment|/// @}
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

