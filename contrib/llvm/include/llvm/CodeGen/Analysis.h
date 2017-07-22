begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodeGen/Analysis.h - CodeGen LLVM IR Analysis Utilities --*- C++ -*-===//
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
comment|// This file declares several CodeGen-specific LLVM IR analysis utilities.
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
name|LLVM_CODEGEN_ANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_ANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ISDOpcodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallSite.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InlineAsm.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|TargetLoweringBase
decl_stmt|;
name|class
name|TargetLowering
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|SDNode
decl_stmt|;
name|class
name|SDValue
decl_stmt|;
name|class
name|SelectionDAG
decl_stmt|;
struct_decl|struct
name|EVT
struct_decl|;
comment|/// \brief Compute the linearized index of a member in a nested
comment|/// aggregate/struct/array.
comment|///
comment|/// Given an LLVM IR aggregate type and a sequence of insertvalue or
comment|/// extractvalue indices that identify a member, return the linearized index of
comment|/// the start of the member, i.e the number of element in memory before the
comment|/// sought one. This is disconnected from the number of bytes.
comment|///
comment|/// \param Ty is the type indexed by \p Indices.
comment|/// \param Indices is an optional pointer in the indices list to the current
comment|/// index.
comment|/// \param IndicesEnd is the end of the indices list.
comment|/// \param CurIndex is the current index in the recursion.
comment|///
comment|/// \returns \p CurIndex plus the linear index in \p Ty  the indices list.
name|unsigned
name|ComputeLinearIndex
parameter_list|(
name|Type
modifier|*
name|Ty
parameter_list|,
specifier|const
name|unsigned
modifier|*
name|Indices
parameter_list|,
specifier|const
name|unsigned
modifier|*
name|IndicesEnd
parameter_list|,
name|unsigned
name|CurIndex
init|=
literal|0
parameter_list|)
function_decl|;
specifier|inline
name|unsigned
name|ComputeLinearIndex
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Indices
argument_list|,
name|unsigned
name|CurIndex
operator|=
literal|0
argument_list|)
block|{
return|return
name|ComputeLinearIndex
argument_list|(
name|Ty
argument_list|,
name|Indices
operator|.
name|begin
argument_list|()
argument_list|,
name|Indices
operator|.
name|end
argument_list|()
argument_list|,
name|CurIndex
argument_list|)
return|;
block|}
comment|/// ComputeValueVTs - Given an LLVM IR type, compute a sequence of
comment|/// EVTs that represent all the individual underlying
comment|/// non-aggregate types that comprise it.
comment|///
comment|/// If Offsets is non-null, it points to a vector to be filled in
comment|/// with the in-memory offsets of each of the individual values.
comment|///
name|void
name|ComputeValueVTs
argument_list|(
specifier|const
name|TargetLowering
operator|&
name|TLI
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
name|SmallVectorImpl
operator|<
name|EVT
operator|>
operator|&
name|ValueVTs
argument_list|,
name|SmallVectorImpl
operator|<
name|uint64_t
operator|>
operator|*
name|Offsets
operator|=
name|nullptr
argument_list|,
name|uint64_t
name|StartingOffset
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// ExtractTypeInfo - Returns the type info, possibly bitcast, encoded in V.
name|GlobalValue
modifier|*
name|ExtractTypeInfo
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// hasInlineAsmMemConstraint - Return true if the inline asm instruction being
comment|/// processed uses a memory 'm' constraint.
name|bool
name|hasInlineAsmMemConstraint
argument_list|(
name|InlineAsm
operator|::
name|ConstraintInfoVector
operator|&
name|CInfos
argument_list|,
specifier|const
name|TargetLowering
operator|&
name|TLI
argument_list|)
decl_stmt|;
comment|/// getFCmpCondCode - Return the ISD condition code corresponding to
comment|/// the given LLVM IR floating-point condition code.  This includes
comment|/// consideration of global floating-point math flags.
comment|///
name|ISD
operator|::
name|CondCode
name|getFCmpCondCode
argument_list|(
argument|FCmpInst::Predicate Pred
argument_list|)
expr_stmt|;
comment|/// getFCmpCodeWithoutNaN - Given an ISD condition code comparing floats,
comment|/// return the equivalent code if we're allowed to assume that NaNs won't occur.
name|ISD
operator|::
name|CondCode
name|getFCmpCodeWithoutNaN
argument_list|(
argument|ISD::CondCode CC
argument_list|)
expr_stmt|;
comment|/// getICmpCondCode - Return the ISD condition code corresponding to
comment|/// the given LLVM IR integer condition code.
comment|///
name|ISD
operator|::
name|CondCode
name|getICmpCondCode
argument_list|(
argument|ICmpInst::Predicate Pred
argument_list|)
expr_stmt|;
comment|/// Test if the given instruction is in a position to be optimized
comment|/// with a tail-call. This roughly means that it's in a block with
comment|/// a return and there's nothing that needs to be scheduled
comment|/// between it and the return.
comment|///
comment|/// This function only tests target-independent requirements.
name|bool
name|isInTailCallPosition
parameter_list|(
name|ImmutableCallSite
name|CS
parameter_list|,
specifier|const
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
comment|/// Test if given that the input instruction is in the tail call position, if
comment|/// there is an attribute mismatch between the caller and the callee that will
comment|/// inhibit tail call optimizations.
comment|/// \p AllowDifferingSizes is an output parameter which, if forming a tail call
comment|/// is permitted, determines whether it's permitted only if the size of the
comment|/// caller's and callee's return types match exactly.
name|bool
name|attributesPermitTailCall
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|ReturnInst
modifier|*
name|Ret
parameter_list|,
specifier|const
name|TargetLoweringBase
modifier|&
name|TLI
parameter_list|,
name|bool
modifier|*
name|AllowDifferingSizes
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Test if given that the input instruction is in the tail call position if the
comment|/// return type or any attributes of the function will inhibit tail call
comment|/// optimization.
name|bool
name|returnTypeIsEligibleForTailCall
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|ReturnInst
modifier|*
name|Ret
parameter_list|,
specifier|const
name|TargetLoweringBase
modifier|&
name|TLI
parameter_list|)
function_decl|;
name|DenseMap
operator|<
specifier|const
name|MachineBasicBlock
operator|*
operator|,
name|int
operator|>
name|getFuncletMembership
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
expr_stmt|;
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

