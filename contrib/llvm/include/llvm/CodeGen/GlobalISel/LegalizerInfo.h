begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/CodeGen/GlobalISel/LegalizerInfo.h ------------------*- C++ -*-===//
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
comment|/// Interface for Targets to specify which operations they can successfully
end_comment

begin_comment
comment|/// select and how the others should be expanded most efficiently.
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
name|LLVM_CODEGEN_GLOBALISEL_LEGALIZERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_LEGALIZERINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/None.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/LowLevelTypeImpl.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetOpcodes.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineIRBuilder
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
comment|/// Legalization is decided based on an instruction's opcode, which type slot
comment|/// we're considering, and what the existing type is. These aspects are gathered
comment|/// together for convenience in the InstrAspect class.
struct|struct
name|InstrAspect
block|{
name|unsigned
name|Opcode
decl_stmt|;
name|unsigned
name|Idx
init|=
literal|0
decl_stmt|;
name|LLT
name|Type
decl_stmt|;
name|InstrAspect
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|LLT Type
argument_list|)
block|:
name|Opcode
argument_list|(
name|Opcode
argument_list|)
operator|,
name|Type
argument_list|(
argument|Type
argument_list|)
block|{}
name|InstrAspect
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned Idx
argument_list|,
argument|LLT Type
argument_list|)
operator|:
name|Opcode
argument_list|(
name|Opcode
argument_list|)
operator|,
name|Idx
argument_list|(
name|Idx
argument_list|)
operator|,
name|Type
argument_list|(
argument|Type
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|InstrAspect
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Opcode
operator|==
name|RHS
operator|.
name|Opcode
operator|&&
name|Idx
operator|==
name|RHS
operator|.
name|Idx
operator|&&
name|Type
operator|==
name|RHS
operator|.
name|Type
return|;
block|}
block|}
struct|;
name|class
name|LegalizerInfo
block|{
name|public
label|:
block|enum
name|LegalizeAction
label|:
name|std
operator|::
name|uint8_t
block|{
comment|/// The operation is expected to be selectable directly by the target, and
comment|/// no transformation is necessary.
name|Legal
block|,
comment|/// The operation should be synthesized from multiple instructions acting on
comment|/// a narrower scalar base-type. For example a 64-bit add might be
comment|/// implemented in terms of 32-bit add-with-carry.
name|NarrowScalar
block|,
comment|/// The operation should be implemented in terms of a wider scalar
comment|/// base-type. For example a<2 x s8> add could be implemented as a<2
comment|/// x s32> add (ignoring the high bits).
name|WidenScalar
block|,
comment|/// The (vector) operation should be implemented by splitting it into
comment|/// sub-vectors where the operation is legal. For example a<8 x s64> add
comment|/// might be implemented as 4 separate<2 x s64> adds.
name|FewerElements
block|,
comment|/// The (vector) operation should be implemented by widening the input
comment|/// vector and ignoring the lanes added by doing so. For example<2 x i8> is
comment|/// rarely legal, but you might perform an<8 x i8> and then only look at
comment|/// the first two results.
name|MoreElements
block|,
comment|/// The operation itself must be expressed in terms of simpler actions on
comment|/// this target. E.g. a SREM replaced by an SDIV and subtraction.
name|Lower
block|,
comment|/// The operation should be implemented as a call to some kind of runtime
comment|/// support library. For example this usually happens on machines that don't
comment|/// support floating-point operations natively.
name|Libcall
block|,
comment|/// The target wants to do something special with this combination of
comment|/// operand and type. A callback will be issued when it is needed.
name|Custom
block|,
comment|/// This operation is completely unsupported on the target. A programming
comment|/// error has occurred.
name|Unsupported
block|,
comment|/// Sentinel value for when no action was found in the specified table.
name|NotFound
block|,   }
expr_stmt|;
name|LegalizerInfo
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|LegalizerInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Compute any ancillary tables needed to quickly decide how an operation
comment|/// should be handled. This must be called after all "set*Action"methods but
comment|/// before any query is made or incorrect results may be returned.
name|void
name|computeTables
parameter_list|()
function_decl|;
specifier|static
name|bool
name|needsLegalizingToDifferentSize
parameter_list|(
specifier|const
name|LegalizeAction
name|Action
parameter_list|)
block|{
switch|switch
condition|(
name|Action
condition|)
block|{
case|case
name|NarrowScalar
case|:
case|case
name|WidenScalar
case|:
case|case
name|FewerElements
case|:
case|case
name|MoreElements
case|:
case|case
name|Unsupported
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
comment|/// More friendly way to set an action for common types that have an LLT
comment|/// representation.
name|void
name|setAction
parameter_list|(
specifier|const
name|InstrAspect
modifier|&
name|Aspect
parameter_list|,
name|LegalizeAction
name|Action
parameter_list|)
block|{
name|TablesInitialized
operator|=
name|false
expr_stmt|;
name|unsigned
name|Opcode
init|=
name|Aspect
operator|.
name|Opcode
operator|-
name|FirstOp
decl_stmt|;
if|if
condition|(
name|Actions
index|[
name|Opcode
index|]
operator|.
name|size
argument_list|()
operator|<=
name|Aspect
operator|.
name|Idx
condition|)
name|Actions
index|[
name|Opcode
index|]
operator|.
name|resize
argument_list|(
name|Aspect
operator|.
name|Idx
operator|+
literal|1
argument_list|)
expr_stmt|;
name|Actions
index|[
name|Aspect
operator|.
name|Opcode
operator|-
name|FirstOp
index|]
index|[
name|Aspect
operator|.
name|Idx
index|]
index|[
name|Aspect
operator|.
name|Type
index|]
operator|=
name|Action
expr_stmt|;
block|}
comment|/// If an operation on a given vector type (say<M x iN>) isn't explicitly
comment|/// specified, we proceed in 2 stages. First we legalize the underlying scalar
comment|/// (so that there's at least one legal vector with that scalar), then we
comment|/// adjust the number of elements in the vector so that it is legal. The
comment|/// desired action in the first step is controlled by this function.
name|void
name|setScalarInVectorAction
parameter_list|(
name|unsigned
name|Opcode
parameter_list|,
name|LLT
name|ScalarTy
parameter_list|,
name|LegalizeAction
name|Action
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|ScalarTy
operator|.
name|isVector
argument_list|()
argument_list|)
expr_stmt|;
name|ScalarInVectorActions
index|[
name|std
operator|::
name|make_pair
argument_list|(
name|Opcode
argument_list|,
name|ScalarTy
argument_list|)
index|]
operator|=
name|Action
expr_stmt|;
block|}
comment|/// Determine what action should be taken to legalize the given generic
comment|/// instruction opcode, type-index and type. Requires computeTables to have
comment|/// been called.
comment|///
comment|/// \returns a pair consisting of the kind of legalization that should be
comment|/// performed and the destination type.
name|std
operator|::
name|pair
operator|<
name|LegalizeAction
operator|,
name|LLT
operator|>
name|getAction
argument_list|(
argument|const InstrAspect&Aspect
argument_list|)
specifier|const
expr_stmt|;
comment|/// Determine what action should be taken to legalize the given generic
comment|/// instruction.
comment|///
comment|/// \returns a tuple consisting of the LegalizeAction that should be
comment|/// performed, the type-index it should be performed on and the destination
comment|/// type.
name|std
operator|::
name|tuple
operator|<
name|LegalizeAction
operator|,
name|unsigned
operator|,
name|LLT
operator|>
name|getAction
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|const MachineRegisterInfo&MRI
argument_list|)
specifier|const
expr_stmt|;
comment|/// Iterate the given function (typically something like doubling the width)
comment|/// on Ty until we find a legal type for this operation.
name|Optional
operator|<
name|LLT
operator|>
name|findLegalizableSize
argument_list|(
argument|const InstrAspect&Aspect
argument_list|,
argument|function_ref<LLT(LLT)> NextType
argument_list|)
specifier|const
block|{
name|LegalizeAction
name|Action
block|;
specifier|const
name|TypeMap
operator|&
name|Map
operator|=
name|Actions
index|[
name|Aspect
operator|.
name|Opcode
operator|-
name|FirstOp
index|]
index|[
name|Aspect
operator|.
name|Idx
index|]
block|;
name|LLT
name|Ty
operator|=
name|Aspect
operator|.
name|Type
block|;
do|do
block|{
name|Ty
operator|=
name|NextType
argument_list|(
name|Ty
argument_list|)
expr_stmt|;
name|auto
name|ActionIt
init|=
name|Map
operator|.
name|find
argument_list|(
name|Ty
argument_list|)
decl_stmt|;
if|if
condition|(
name|ActionIt
operator|==
name|Map
operator|.
name|end
argument_list|()
condition|)
block|{
name|auto
name|DefaultIt
init|=
name|DefaultActions
operator|.
name|find
argument_list|(
name|Aspect
operator|.
name|Opcode
argument_list|)
decl_stmt|;
if|if
condition|(
name|DefaultIt
operator|==
name|DefaultActions
operator|.
name|end
argument_list|()
condition|)
return|return
name|None
return|;
name|Action
operator|=
name|DefaultIt
operator|->
name|second
expr_stmt|;
block|}
else|else
name|Action
operator|=
name|ActionIt
operator|->
name|second
expr_stmt|;
block|}
while|while
condition|(
name|needsLegalizingToDifferentSize
argument_list|(
name|Action
argument_list|)
condition|)
empty_stmt|;
do|return Ty;   }
comment|/// Find what type it's actually OK to perform the given operation on, given
comment|/// the general approach we've decided to take.
do|Optional<LLT> findLegalType(const InstrAspect&Aspect
operator|,
do|LegalizeAction Action
block|)
specifier|const
expr_stmt|;
name|std
operator|::
name|pair
operator|<
name|LegalizeAction
operator|,
name|LLT
operator|>
name|findLegalAction
argument_list|(
argument|const InstrAspect&Aspect
argument_list|,
argument|LegalizeAction Action
argument_list|)
specifier|const
block|{
name|auto
name|LegalType
operator|=
name|findLegalType
argument_list|(
name|Aspect
argument_list|,
name|Action
argument_list|)
block|;
if|if
condition|(
operator|!
name|LegalType
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|LegalizeAction
operator|::
name|Unsupported
argument_list|,
name|LLT
argument_list|()
argument_list|)
return|;
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|Action
argument_list|,
operator|*
name|LegalType
argument_list|)
return|;
block|}
comment|/// Find the specified \p Aspect in the primary (explicitly set) Actions
comment|/// table. Returns either the action the target requested or NotFound if there
comment|/// was no setAction call.
name|LegalizeAction
name|findInActions
argument_list|(
specifier|const
name|InstrAspect
operator|&
name|Aspect
argument_list|)
decl|const
block|{
if|if
condition|(
name|Aspect
operator|.
name|Opcode
operator|<
name|FirstOp
operator|||
name|Aspect
operator|.
name|Opcode
operator|>
name|LastOp
condition|)
return|return
name|NotFound
return|;
if|if
condition|(
name|Aspect
operator|.
name|Idx
operator|>=
name|Actions
index|[
name|Aspect
operator|.
name|Opcode
operator|-
name|FirstOp
index|]
operator|.
name|size
argument_list|()
condition|)
return|return
name|NotFound
return|;
specifier|const
name|TypeMap
modifier|&
name|Map
init|=
name|Actions
index|[
name|Aspect
operator|.
name|Opcode
operator|-
name|FirstOp
index|]
index|[
name|Aspect
operator|.
name|Idx
index|]
decl_stmt|;
name|auto
name|ActionIt
init|=
name|Map
operator|.
name|find
argument_list|(
name|Aspect
operator|.
name|Type
argument_list|)
decl_stmt|;
if|if
condition|(
name|ActionIt
operator|==
name|Map
operator|.
name|end
argument_list|()
condition|)
return|return
name|NotFound
return|;
return|return
name|ActionIt
operator|->
name|second
return|;
block|}
name|bool
name|isLegal
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|,
specifier|const
name|MachineRegisterInfo
operator|&
name|MRI
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|legalizeCustom
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineRegisterInfo
operator|&
name|MRI
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
specifier|static
specifier|const
name|int
name|FirstOp
init|=
name|TargetOpcode
operator|::
name|PRE_ISEL_GENERIC_OPCODE_START
decl_stmt|;
specifier|static
specifier|const
name|int
name|LastOp
init|=
name|TargetOpcode
operator|::
name|PRE_ISEL_GENERIC_OPCODE_END
decl_stmt|;
name|using
name|TypeMap
init|=
name|DenseMap
operator|<
name|LLT
decl_stmt|,
name|LegalizeAction
decl|>
decl_stmt|;
name|using
name|SIVActionMap
init|=
name|DenseMap
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
decl_stmt|,
name|LLT
decl|>
decl_stmt|,
name|LegalizeAction
decl|>
decl_stmt|;
name|SmallVector
operator|<
name|TypeMap
operator|,
literal|1
operator|>
name|Actions
index|[
name|LastOp
operator|-
name|FirstOp
operator|+
literal|1
index|]
expr_stmt|;
name|SIVActionMap
name|ScalarInVectorActions
decl_stmt|;
name|DenseMap
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|LLT
operator|>
operator|,
name|uint16_t
operator|>
name|MaxLegalVectorElts
expr_stmt|;
name|DenseMap
operator|<
name|unsigned
operator|,
name|LegalizeAction
operator|>
name|DefaultActions
expr_stmt|;
name|bool
name|TablesInitialized
init|=
name|false
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

begin_comment
comment|// LLVM_CODEGEN_GLOBALISEL_LEGALIZERINFO_H
end_comment

end_unit

