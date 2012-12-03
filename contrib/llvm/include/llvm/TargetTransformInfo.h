begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Transforms/TargetTransformInfo.h --------------------*- C++ -*-===//
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
comment|// This pass exposes codegen information to IR-level passes. Every
end_comment

begin_comment
comment|// transformation that uses codegen information is broken into three parts:
end_comment

begin_comment
comment|// 1. The IR-level analysis pass.
end_comment

begin_comment
comment|// 2. The IR-level transformation interface which provides the needed
end_comment

begin_comment
comment|//    information.
end_comment

begin_comment
comment|// 3. Codegen-level implementation which uses target-specific hooks.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines #2, which is the interface that IR-level transformations
end_comment

begin_comment
comment|// use for querying the codegen.
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
name|LLVM_TRANSFORMS_TARGET_TRANSFORM_INTERFACE
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_TARGET_TRANSFORM_INTERFACE
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/AddressingMode.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Type.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ScalarTargetTransformInfo
decl_stmt|;
name|class
name|VectorTargetTransformInfo
decl_stmt|;
comment|/// TargetTransformInfo - This pass provides access to the codegen
comment|/// interfaces that are needed for IR-level transformations.
name|class
name|TargetTransformInfo
range|:
name|public
name|ImmutablePass
block|{
name|private
operator|:
specifier|const
name|ScalarTargetTransformInfo
operator|*
name|STTI
block|;
specifier|const
name|VectorTargetTransformInfo
operator|*
name|VTTI
block|;
name|public
operator|:
comment|/// Default ctor.
comment|///
comment|/// @note This has to exist, because this is a pass, but it should never be
comment|/// used.
name|TargetTransformInfo
argument_list|()
block|;
name|TargetTransformInfo
argument_list|(
specifier|const
name|ScalarTargetTransformInfo
operator|*
name|S
argument_list|,
specifier|const
name|VectorTargetTransformInfo
operator|*
name|V
argument_list|)
operator|:
name|ImmutablePass
argument_list|(
name|ID
argument_list|)
block|,
name|STTI
argument_list|(
name|S
argument_list|)
block|,
name|VTTI
argument_list|(
argument|V
argument_list|)
block|{
name|initializeTargetTransformInfoPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
name|TargetTransformInfo
argument_list|(
specifier|const
name|TargetTransformInfo
operator|&
name|T
argument_list|)
operator|:
name|ImmutablePass
argument_list|(
name|ID
argument_list|)
block|,
name|STTI
argument_list|(
name|T
operator|.
name|STTI
argument_list|)
block|,
name|VTTI
argument_list|(
argument|T.VTTI
argument_list|)
block|{ }
specifier|const
name|ScalarTargetTransformInfo
operator|*
name|getScalarTargetTransformInfo
argument_list|()
specifier|const
block|{
return|return
name|STTI
return|;
block|}
specifier|const
name|VectorTargetTransformInfo
operator|*
name|getVectorTargetTransformInfo
argument_list|()
specifier|const
block|{
return|return
name|VTTI
return|;
block|}
comment|/// Pass identification, replacement for typeid.
specifier|static
name|char
name|ID
block|; }
decl_stmt|;
comment|// ---------------------------------------------------------------------------//
comment|//  The classes below are inherited and implemented by target-specific classes
comment|//  in the codegen.
comment|// ---------------------------------------------------------------------------//
comment|/// ScalarTargetTransformInfo - This interface is used by IR-level passes
comment|/// that need target-dependent information for generic scalar transformations.
comment|/// LSR, and LowerInvoke use this interface.
name|class
name|ScalarTargetTransformInfo
block|{
name|public
label|:
name|virtual
operator|~
name|ScalarTargetTransformInfo
argument_list|()
block|{}
comment|/// isLegalAddImmediate - Return true if the specified immediate is legal
comment|/// add immediate, that is the target has add instructions which can add
comment|/// a register with the immediate without having to materialize the
comment|/// immediate into a register.
name|virtual
name|bool
name|isLegalAddImmediate
argument_list|(
argument|int64_t
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// isLegalICmpImmediate - Return true if the specified immediate is legal
comment|/// icmp immediate, that is the target has icmp instructions which can compare
comment|/// a register against the immediate without having to materialize the
comment|/// immediate into a register.
name|virtual
name|bool
name|isLegalICmpImmediate
argument_list|(
name|int64_t
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// isLegalAddressingMode - Return true if the addressing mode represented by
comment|/// AM is legal for this target, for a load/store of the specified type.
comment|/// The type may be VoidTy, in which case only return true if the addressing
comment|/// mode is legal for a load/store of any legal type.
comment|/// TODO: Handle pre/postinc as well.
name|virtual
name|bool
name|isLegalAddressingMode
argument_list|(
specifier|const
name|AddrMode
operator|&
name|AM
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// isTruncateFree - Return true if it's free to truncate a value of
comment|/// type Ty1 to type Ty2. e.g. On x86 it's free to truncate a i32 value in
comment|/// register EAX to i16 by referencing its sub-register AX.
name|virtual
name|bool
name|isTruncateFree
argument_list|(
name|Type
operator|*
name|Ty1
argument_list|,
name|Type
operator|*
name|Ty2
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Is this type legal.
name|virtual
name|bool
name|isTypeLegal
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// getJumpBufAlignment - returns the target's jmp_buf alignment in bytes
name|virtual
name|unsigned
name|getJumpBufAlignment
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// getJumpBufSize - returns the target's jmp_buf size in bytes.
name|virtual
name|unsigned
name|getJumpBufSize
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// shouldBuildLookupTables - Return true if switches should be turned into
comment|/// lookup tables for the target.
name|virtual
name|bool
name|shouldBuildLookupTables
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
block|}
empty_stmt|;
comment|/// VectorTargetTransformInfo - This interface is used by the vectorizers
comment|/// to estimate the profitability of vectorization for different instructions.
name|class
name|VectorTargetTransformInfo
block|{
name|public
label|:
name|virtual
operator|~
name|VectorTargetTransformInfo
argument_list|()
block|{}
comment|/// Returns the expected cost of the instruction opcode. The opcode is one of
comment|/// the enums like Instruction::Add. The type arguments are the type of the
comment|/// operation.
comment|/// Most instructions only use the first type and in that case the second
comment|/// operand is ignored.
comment|///
comment|/// Exceptions:
comment|/// * Br instructions do not use any of the types.
comment|/// * Select instructions pass the return type as Ty1 and the selector as Ty2.
comment|/// * Cast instructions pass the destination as Ty1 and the source as Ty2.
comment|/// * Insert/Extract element pass only the vector type as Ty1.
comment|/// * ShuffleVector, Load, Store do not use this call.
name|virtual
name|unsigned
name|getInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Ty1 =
literal|0
argument_list|,
argument|Type *Ty2 =
literal|0
argument_list|)
specifier|const
block|{
return|return
literal|1
return|;
block|}
comment|/// Returns the expected cost of arithmetic ops, such as mul, xor, fsub, etc.
name|virtual
name|unsigned
name|getArithmeticInstrCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
decl|const
block|{
return|return
literal|1
return|;
block|}
comment|/// Returns the cost of a vector broadcast of a scalar at place zero to a
comment|/// vector of type 'Tp'.
name|virtual
name|unsigned
name|getBroadcastCost
argument_list|(
name|Type
operator|*
name|Tp
argument_list|)
decl|const
block|{
return|return
literal|1
return|;
block|}
comment|/// Returns the expected cost of cast instructions, such as bitcast, trunc,
comment|/// zext, etc.
name|virtual
name|unsigned
name|getCastInstrCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|Dst
argument_list|,
name|Type
operator|*
name|Src
argument_list|)
decl|const
block|{
return|return
literal|1
return|;
block|}
comment|/// Returns the expected cost of control-flow related instrutctions such as
comment|/// Phi, Ret, Br.
name|virtual
name|unsigned
name|getCFInstrCost
argument_list|(
name|unsigned
name|Opcode
argument_list|)
decl|const
block|{
return|return
literal|1
return|;
block|}
comment|/// Returns the expected cost of compare and select instructions.
name|virtual
name|unsigned
name|getCmpSelInstrCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|ValTy
argument_list|,
name|Type
operator|*
name|CondTy
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
literal|1
return|;
block|}
comment|/// Returns the expected cost of vector Insert and Extract.
comment|/// Use -1 to indicate that there is no information on the index value.
name|virtual
name|unsigned
name|getVectorInstrCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|Val
argument_list|,
name|unsigned
name|Index
operator|=
operator|-
literal|1
argument_list|)
decl|const
block|{
return|return
literal|1
return|;
block|}
comment|/// Returns the cost of Load and Store instructions.
name|virtual
name|unsigned
name|getMemoryOpCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|Src
argument_list|,
name|unsigned
name|Alignment
argument_list|,
name|unsigned
name|AddressSpace
argument_list|)
decl|const
block|{
return|return
literal|1
return|;
block|}
comment|/// Returns the number of pieces into which the provided type must be
comment|/// split during legalization. Zero is returned when the answer is unknown.
name|virtual
name|unsigned
name|getNumberOfParts
argument_list|(
name|Type
operator|*
name|Tp
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

