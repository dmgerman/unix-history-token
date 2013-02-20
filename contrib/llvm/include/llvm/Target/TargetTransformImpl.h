begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- llvm/Target/TargetTransformImpl.h - Target Loop Trans Info----*- C++ -*-=//
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
comment|// This file contains the target-specific implementations of the
end_comment

begin_comment
comment|// TargetTransform interfaces.
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
name|LLVM_TARGET_TARGET_TRANSFORMATION_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGET_TRANSFORMATION_IMPL_H
end_define

begin_include
include|#
directive|include
file|"llvm/TargetTransformInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetLowering
decl_stmt|;
comment|/// ScalarTargetTransformInfo - This is a default implementation for the
comment|/// ScalarTargetTransformInfo interface. Different targets can implement
comment|/// this interface differently.
name|class
name|ScalarTargetTransformImpl
range|:
name|public
name|ScalarTargetTransformInfo
block|{
name|private
operator|:
specifier|const
name|TargetLowering
operator|*
name|TLI
block|;
name|public
operator|:
comment|/// Ctor
name|explicit
name|ScalarTargetTransformImpl
argument_list|(
specifier|const
name|TargetLowering
operator|*
name|TL
argument_list|)
operator|:
name|TLI
argument_list|(
argument|TL
argument_list|)
block|{}
name|virtual
name|bool
name|isLegalAddImmediate
argument_list|(
argument|int64_t imm
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isLegalICmpImmediate
argument_list|(
argument|int64_t imm
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isLegalAddressingMode
argument_list|(
argument|const AddrMode&AM
argument_list|,
argument|Type *Ty
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isTruncateFree
argument_list|(
argument|Type *Ty1
argument_list|,
argument|Type *Ty2
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isTypeLegal
argument_list|(
argument|Type *Ty
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getJumpBufAlignment
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|getJumpBufSize
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|shouldBuildLookupTables
argument_list|()
specifier|const
block|; }
decl_stmt|;
name|class
name|VectorTargetTransformImpl
range|:
name|public
name|VectorTargetTransformInfo
block|{
name|protected
operator|:
specifier|const
name|TargetLowering
operator|*
name|TLI
block|;
comment|/// Estimate the cost of type-legalization and the legalized type.
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|MVT
operator|>
name|getTypeLegalizationCost
argument_list|(
argument|Type *Ty
argument_list|)
specifier|const
block|;
comment|/// Estimate the overhead of scalarizing an instruction. Insert and Extract
comment|/// are set if the result needs to be inserted and/or extracted from vectors.
name|unsigned
name|getScalarizationOverhead
argument_list|(
argument|Type *Ty
argument_list|,
argument|bool Insert
argument_list|,
argument|bool Extract
argument_list|)
specifier|const
block|;
comment|// Get the ISD node that corresponds to the Instruction class opcode.
name|int
name|InstructionOpcodeToISD
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|public
operator|:
name|explicit
name|VectorTargetTransformImpl
argument_list|(
specifier|const
name|TargetLowering
operator|*
name|TL
argument_list|)
operator|:
name|TLI
argument_list|(
argument|TL
argument_list|)
block|{}
name|virtual
operator|~
name|VectorTargetTransformImpl
argument_list|()
block|{}
name|virtual
name|unsigned
name|getInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Ty1
argument_list|,
argument|Type *Ty2
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getArithmeticInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Ty
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getBroadcastCost
argument_list|(
argument|Type *Tp
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getCastInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Dst
argument_list|,
argument|Type *Src
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getCFInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getCmpSelInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *ValTy
argument_list|,
argument|Type *CondTy
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getVectorInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Val
argument_list|,
argument|unsigned Index
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getMemoryOpCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Src
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned AddressSpace
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getNumberOfParts
argument_list|(
argument|Type *Tp
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

