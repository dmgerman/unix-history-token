begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Instruction.h - Instruction class definition -------*- C++ -*-===//
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
comment|// This file contains the declaration of the Instruction class, which is the
end_comment

begin_comment
comment|// base class for all of the LLVM instructions.
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
name|LLVM_IR_INSTRUCTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_INSTRUCTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/None.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/SymbolTableListTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/User.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
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
name|BasicBlock
decl_stmt|;
name|class
name|FastMathFlags
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
struct_decl|struct
name|AAMDNodes
struct_decl|;
name|class
name|Instruction
range|:
name|public
name|User
decl_stmt|,
name|public
name|ilist_node_with_parent
decl|<
name|Instruction
decl_stmt|,
name|BasicBlock
decl|>
block|{
name|BasicBlock
modifier|*
name|Parent
decl_stmt|;
name|DebugLoc
name|DbgLoc
decl_stmt|;
comment|// 'dbg' Metadata cache.
enum|enum
block|{
comment|/// This is a bit stored in the SubClassData field which indicates whether
comment|/// this instruction has metadata attached to it or not.
name|HasMetadataBit
init|=
literal|1
operator|<<
literal|15
block|}
enum|;
name|public
label|:
name|Instruction
argument_list|(
specifier|const
name|Instruction
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|Instruction
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Instruction
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
comment|// Out of line virtual method, so the vtable, etc has a home.
operator|~
name|Instruction
argument_list|()
name|override
expr_stmt|;
comment|/// Specialize the methods defined in Value, as we know that an instruction
comment|/// can only be used by other instructions.
name|Instruction
modifier|*
name|user_back
parameter_list|()
block|{
return|return
name|cast
operator|<
name|Instruction
operator|>
operator|(
operator|*
name|user_begin
argument_list|()
operator|)
return|;
block|}
specifier|const
name|Instruction
operator|*
name|user_back
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Instruction
operator|>
operator|(
operator|*
name|user_begin
argument_list|()
operator|)
return|;
block|}
specifier|inline
specifier|const
name|BasicBlock
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|Parent
return|;
block|}
specifier|inline
name|BasicBlock
modifier|*
name|getParent
parameter_list|()
block|{
return|return
name|Parent
return|;
block|}
comment|/// Return the module owning the function this instruction belongs to
comment|/// or nullptr it the function does not have a module.
comment|///
comment|/// Note: this is undefined behavior if the instruction does not have a
comment|/// parent, or the parent basic block does not have a parent function.
specifier|const
name|Module
operator|*
name|getModule
argument_list|()
specifier|const
expr_stmt|;
name|Module
modifier|*
name|getModule
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|Module
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|Instruction
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getModule
argument_list|()
operator|)
return|;
block|}
comment|/// Return the function this instruction belongs to.
comment|///
comment|/// Note: it is undefined behavior to call this on an instruction not
comment|/// currently inserted into a function.
specifier|const
name|Function
operator|*
name|getFunction
argument_list|()
specifier|const
expr_stmt|;
name|Function
modifier|*
name|getFunction
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|Function
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|Instruction
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getFunction
argument_list|()
operator|)
return|;
block|}
comment|/// This method unlinks 'this' from the containing basic block, but does not
comment|/// delete it.
name|void
name|removeFromParent
parameter_list|()
function_decl|;
comment|/// This method unlinks 'this' from the containing basic block and deletes it.
comment|///
comment|/// \returns an iterator pointing to the element after the erased one
name|SymbolTableList
operator|<
name|Instruction
operator|>
operator|::
name|iterator
name|eraseFromParent
argument_list|()
expr_stmt|;
comment|/// Insert an unlinked instruction into a basic block immediately before
comment|/// the specified instruction.
name|void
name|insertBefore
parameter_list|(
name|Instruction
modifier|*
name|InsertPos
parameter_list|)
function_decl|;
comment|/// Insert an unlinked instruction into a basic block immediately after the
comment|/// specified instruction.
name|void
name|insertAfter
parameter_list|(
name|Instruction
modifier|*
name|InsertPos
parameter_list|)
function_decl|;
comment|/// Unlink this instruction from its current basic block and insert it into
comment|/// the basic block that MovePos lives in, right before MovePos.
name|void
name|moveBefore
parameter_list|(
name|Instruction
modifier|*
name|MovePos
parameter_list|)
function_decl|;
comment|/// Unlink this instruction and insert into BB before I.
comment|///
comment|/// \pre I is a valid iterator into BB.
name|void
name|moveBefore
argument_list|(
name|BasicBlock
operator|&
name|BB
argument_list|,
name|SymbolTableList
operator|<
name|Instruction
operator|>
operator|::
name|iterator
name|I
argument_list|)
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Subclass classification.
comment|//===--------------------------------------------------------------------===//
comment|/// Returns a member of one of the enums like Instruction::Add.
name|unsigned
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|getValueID
argument_list|()
operator|-
name|InstructionVal
return|;
block|}
specifier|const
name|char
operator|*
name|getOpcodeName
argument_list|()
specifier|const
block|{
return|return
name|getOpcodeName
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|isTerminator
argument_list|()
specifier|const
block|{
return|return
name|isTerminator
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|isBinaryOp
argument_list|()
specifier|const
block|{
return|return
name|isBinaryOp
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|isShift
parameter_list|()
block|{
return|return
name|isShift
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|isCast
argument_list|()
specifier|const
block|{
return|return
name|isCast
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|isFuncletPad
argument_list|()
specifier|const
block|{
return|return
name|isFuncletPad
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|char
modifier|*
name|getOpcodeName
parameter_list|(
name|unsigned
name|OpCode
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|bool
name|isTerminator
parameter_list|(
name|unsigned
name|OpCode
parameter_list|)
block|{
return|return
name|OpCode
operator|>=
name|TermOpsBegin
operator|&&
name|OpCode
operator|<
name|TermOpsEnd
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isBinaryOp
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
return|return
name|Opcode
operator|>=
name|BinaryOpsBegin
operator|&&
name|Opcode
operator|<
name|BinaryOpsEnd
return|;
block|}
comment|/// Determine if the Opcode is one of the shift instructions.
specifier|static
specifier|inline
name|bool
name|isShift
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
return|return
name|Opcode
operator|>=
name|Shl
operator|&&
name|Opcode
operator|<=
name|AShr
return|;
block|}
comment|/// Return true if this is a logical shift left or a logical shift right.
specifier|inline
name|bool
name|isLogicalShift
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|Shl
operator|||
name|getOpcode
argument_list|()
operator|==
name|LShr
return|;
block|}
comment|/// Return true if this is an arithmetic shift right.
specifier|inline
name|bool
name|isArithmeticShift
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|AShr
return|;
block|}
comment|/// Return true if this is and/or/xor.
specifier|inline
name|bool
name|isBitwiseLogicOp
argument_list|()
specifier|const
block|{
return|return
name|getOpcode
argument_list|()
operator|==
name|And
operator|||
name|getOpcode
argument_list|()
operator|==
name|Or
operator|||
name|getOpcode
argument_list|()
operator|==
name|Xor
return|;
block|}
comment|/// Determine if the OpCode is one of the CastInst instructions.
specifier|static
specifier|inline
name|bool
name|isCast
parameter_list|(
name|unsigned
name|OpCode
parameter_list|)
block|{
return|return
name|OpCode
operator|>=
name|CastOpsBegin
operator|&&
name|OpCode
operator|<
name|CastOpsEnd
return|;
block|}
comment|/// Determine if the OpCode is one of the FuncletPadInst instructions.
specifier|static
specifier|inline
name|bool
name|isFuncletPad
parameter_list|(
name|unsigned
name|OpCode
parameter_list|)
block|{
return|return
name|OpCode
operator|>=
name|FuncletPadOpsBegin
operator|&&
name|OpCode
operator|<
name|FuncletPadOpsEnd
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Metadata manipulation.
comment|//===--------------------------------------------------------------------===//
comment|/// Return true if this instruction has any metadata attached to it.
name|bool
name|hasMetadata
argument_list|()
specifier|const
block|{
return|return
name|DbgLoc
operator|||
name|hasMetadataHashEntry
argument_list|()
return|;
block|}
comment|/// Return true if this instruction has metadata attached to it other than a
comment|/// debug location.
name|bool
name|hasMetadataOtherThanDebugLoc
argument_list|()
specifier|const
block|{
return|return
name|hasMetadataHashEntry
argument_list|()
return|;
block|}
comment|/// Get the metadata of given kind attached to this Instruction.
comment|/// If the metadata is not found then return null.
name|MDNode
modifier|*
name|getMetadata
argument_list|(
name|unsigned
name|KindID
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|hasMetadata
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
name|getMetadataImpl
argument_list|(
name|KindID
argument_list|)
return|;
block|}
comment|/// Get the metadata of given kind attached to this Instruction.
comment|/// If the metadata is not found then return null.
name|MDNode
modifier|*
name|getMetadata
argument_list|(
name|StringRef
name|Kind
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|hasMetadata
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
name|getMetadataImpl
argument_list|(
name|Kind
argument_list|)
return|;
block|}
comment|/// Get all metadata attached to this Instruction. The first element of each
comment|/// pair returned is the KindID, the second element is the metadata value.
comment|/// This list is returned sorted by the KindID.
name|void
name|getAllMetadata
argument_list|(
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
argument_list|,
name|MDNode
operator|*
operator|>>
operator|&
name|MDs
argument_list|)
decl|const
block|{
if|if
condition|(
name|hasMetadata
argument_list|()
condition|)
name|getAllMetadataImpl
argument_list|(
name|MDs
argument_list|)
expr_stmt|;
block|}
comment|/// This does the same thing as getAllMetadata, except that it filters out the
comment|/// debug location.
name|void
name|getAllMetadataOtherThanDebugLoc
argument_list|(
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
argument_list|,
name|MDNode
operator|*
operator|>>
operator|&
name|MDs
argument_list|)
decl|const
block|{
if|if
condition|(
name|hasMetadataOtherThanDebugLoc
argument_list|()
condition|)
name|getAllMetadataOtherThanDebugLocImpl
argument_list|(
name|MDs
argument_list|)
expr_stmt|;
block|}
comment|/// Fills the AAMDNodes structure with AA metadata from this instruction.
comment|/// When Merge is true, the existing AA metadata is merged with that from this
comment|/// instruction providing the most-general result.
name|void
name|getAAMetadata
argument_list|(
name|AAMDNodes
operator|&
name|N
argument_list|,
name|bool
name|Merge
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|/// Set the metadata of the specified kind to the specified node. This updates
comment|/// or replaces metadata if already present, or removes it if Node is null.
name|void
name|setMetadata
parameter_list|(
name|unsigned
name|KindID
parameter_list|,
name|MDNode
modifier|*
name|Node
parameter_list|)
function_decl|;
name|void
name|setMetadata
parameter_list|(
name|StringRef
name|Kind
parameter_list|,
name|MDNode
modifier|*
name|Node
parameter_list|)
function_decl|;
comment|/// Copy metadata from \p SrcInst to this instruction. \p WL, if not empty,
comment|/// specifies the list of meta data that needs to be copied. If \p WL is
comment|/// empty, all meta data will be copied.
name|void
name|copyMetadata
argument_list|(
specifier|const
name|Instruction
operator|&
name|SrcInst
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|WL
operator|=
name|ArrayRef
operator|<
name|unsigned
operator|>
operator|(
operator|)
argument_list|)
decl_stmt|;
comment|/// If the instruction has "branch_weights" MD_prof metadata and the MDNode
comment|/// has three operands (including name string), swap the order of the
comment|/// metadata.
name|void
name|swapProfMetadata
parameter_list|()
function_decl|;
comment|/// Drop all unknown metadata except for debug locations.
comment|/// @{
comment|/// Passes are required to drop metadata they don't understand. This is a
comment|/// convenience method for passes to do so.
name|void
name|dropUnknownNonDebugMetadata
argument_list|(
name|ArrayRef
operator|<
name|unsigned
operator|>
name|KnownIDs
argument_list|)
decl_stmt|;
name|void
name|dropUnknownNonDebugMetadata
parameter_list|()
block|{
return|return
name|dropUnknownNonDebugMetadata
argument_list|(
name|None
argument_list|)
return|;
block|}
name|void
name|dropUnknownNonDebugMetadata
parameter_list|(
name|unsigned
name|ID1
parameter_list|)
block|{
return|return
name|dropUnknownNonDebugMetadata
argument_list|(
name|makeArrayRef
argument_list|(
name|ID1
argument_list|)
argument_list|)
return|;
block|}
name|void
name|dropUnknownNonDebugMetadata
parameter_list|(
name|unsigned
name|ID1
parameter_list|,
name|unsigned
name|ID2
parameter_list|)
block|{
name|unsigned
name|IDs
index|[]
init|=
block|{
name|ID1
block|,
name|ID2
block|}
decl_stmt|;
return|return
name|dropUnknownNonDebugMetadata
argument_list|(
name|IDs
argument_list|)
return|;
block|}
comment|/// @}
comment|/// Sets the metadata on this instruction from the AAMDNodes structure.
name|void
name|setAAMetadata
parameter_list|(
specifier|const
name|AAMDNodes
modifier|&
name|N
parameter_list|)
function_decl|;
comment|/// Retrieve the raw weight values of a conditional branch or select.
comment|/// Returns true on success with profile weights filled in.
comment|/// Returns false if no metadata or invalid metadata was found.
name|bool
name|extractProfMetadata
argument_list|(
name|uint64_t
operator|&
name|TrueVal
argument_list|,
name|uint64_t
operator|&
name|FalseVal
argument_list|)
decl|const
decl_stmt|;
comment|/// Retrieve total raw weight values of a branch.
comment|/// Returns true on success with profile total weights filled in.
comment|/// Returns false if no metadata was found.
name|bool
name|extractProfTotalWeight
argument_list|(
name|uint64_t
operator|&
name|TotalVal
argument_list|)
decl|const
decl_stmt|;
comment|/// Updates branch_weights metadata by scaling it by \p S / \p T.
name|void
name|updateProfWeight
parameter_list|(
name|uint64_t
name|S
parameter_list|,
name|uint64_t
name|T
parameter_list|)
function_decl|;
comment|/// Sets the branch_weights metadata to \p W for CallInst.
name|void
name|setProfWeight
parameter_list|(
name|uint64_t
name|W
parameter_list|)
function_decl|;
comment|/// Set the debug location information for this instruction.
name|void
name|setDebugLoc
parameter_list|(
name|DebugLoc
name|Loc
parameter_list|)
block|{
name|DbgLoc
operator|=
name|std
operator|::
name|move
argument_list|(
name|Loc
argument_list|)
expr_stmt|;
block|}
comment|/// Return the debug location for this node as a DebugLoc.
specifier|const
name|DebugLoc
operator|&
name|getDebugLoc
argument_list|()
specifier|const
block|{
return|return
name|DbgLoc
return|;
block|}
comment|/// Set or clear the nsw flag on this instruction, which must be an operator
comment|/// which supports this flag. See LangRef.html for the meaning of this flag.
name|void
name|setHasNoUnsignedWrap
parameter_list|(
name|bool
name|b
init|=
name|true
parameter_list|)
function_decl|;
comment|/// Set or clear the nsw flag on this instruction, which must be an operator
comment|/// which supports this flag. See LangRef.html for the meaning of this flag.
name|void
name|setHasNoSignedWrap
parameter_list|(
name|bool
name|b
init|=
name|true
parameter_list|)
function_decl|;
comment|/// Set or clear the exact flag on this instruction, which must be an operator
comment|/// which supports this flag. See LangRef.html for the meaning of this flag.
name|void
name|setIsExact
parameter_list|(
name|bool
name|b
init|=
name|true
parameter_list|)
function_decl|;
comment|/// Determine whether the no unsigned wrap flag is set.
name|bool
name|hasNoUnsignedWrap
argument_list|()
specifier|const
expr_stmt|;
comment|/// Determine whether the no signed wrap flag is set.
name|bool
name|hasNoSignedWrap
argument_list|()
specifier|const
expr_stmt|;
comment|/// Drops flags that may cause this instruction to evaluate to poison despite
comment|/// having non-poison inputs.
name|void
name|dropPoisonGeneratingFlags
parameter_list|()
function_decl|;
comment|/// Determine whether the exact flag is set.
name|bool
name|isExact
argument_list|()
specifier|const
expr_stmt|;
comment|/// Set or clear the unsafe-algebra flag on this instruction, which must be an
comment|/// operator which supports this flag. See LangRef.html for the meaning of
comment|/// this flag.
name|void
name|setHasUnsafeAlgebra
parameter_list|(
name|bool
name|B
parameter_list|)
function_decl|;
comment|/// Set or clear the no-nans flag on this instruction, which must be an
comment|/// operator which supports this flag. See LangRef.html for the meaning of
comment|/// this flag.
name|void
name|setHasNoNaNs
parameter_list|(
name|bool
name|B
parameter_list|)
function_decl|;
comment|/// Set or clear the no-infs flag on this instruction, which must be an
comment|/// operator which supports this flag. See LangRef.html for the meaning of
comment|/// this flag.
name|void
name|setHasNoInfs
parameter_list|(
name|bool
name|B
parameter_list|)
function_decl|;
comment|/// Set or clear the no-signed-zeros flag on this instruction, which must be
comment|/// an operator which supports this flag. See LangRef.html for the meaning of
comment|/// this flag.
name|void
name|setHasNoSignedZeros
parameter_list|(
name|bool
name|B
parameter_list|)
function_decl|;
comment|/// Set or clear the allow-reciprocal flag on this instruction, which must be
comment|/// an operator which supports this flag. See LangRef.html for the meaning of
comment|/// this flag.
name|void
name|setHasAllowReciprocal
parameter_list|(
name|bool
name|B
parameter_list|)
function_decl|;
comment|/// Convenience function for setting multiple fast-math flags on this
comment|/// instruction, which must be an operator which supports these flags. See
comment|/// LangRef.html for the meaning of these flags.
name|void
name|setFastMathFlags
parameter_list|(
name|FastMathFlags
name|FMF
parameter_list|)
function_decl|;
comment|/// Convenience function for transferring all fast-math flag values to this
comment|/// instruction, which must be an operator which supports these flags. See
comment|/// LangRef.html for the meaning of these flags.
name|void
name|copyFastMathFlags
parameter_list|(
name|FastMathFlags
name|FMF
parameter_list|)
function_decl|;
comment|/// Determine whether the unsafe-algebra flag is set.
name|bool
name|hasUnsafeAlgebra
argument_list|()
specifier|const
expr_stmt|;
comment|/// Determine whether the no-NaNs flag is set.
name|bool
name|hasNoNaNs
argument_list|()
specifier|const
expr_stmt|;
comment|/// Determine whether the no-infs flag is set.
name|bool
name|hasNoInfs
argument_list|()
specifier|const
expr_stmt|;
comment|/// Determine whether the no-signed-zeros flag is set.
name|bool
name|hasNoSignedZeros
argument_list|()
specifier|const
expr_stmt|;
comment|/// Determine whether the allow-reciprocal flag is set.
name|bool
name|hasAllowReciprocal
argument_list|()
specifier|const
expr_stmt|;
comment|/// Determine whether the allow-contract flag is set.
name|bool
name|hasAllowContract
argument_list|()
specifier|const
expr_stmt|;
comment|/// Convenience function for getting all the fast-math flags, which must be an
comment|/// operator which supports these flags. See LangRef.html for the meaning of
comment|/// these flags.
name|FastMathFlags
name|getFastMathFlags
argument_list|()
specifier|const
expr_stmt|;
comment|/// Copy I's fast-math flags
name|void
name|copyFastMathFlags
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// Convenience method to copy supported wrapping, exact, and fast-math flags
comment|/// from V to this instruction.
name|void
name|copyIRFlags
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// Logical 'and' of any supported wrapping, exact, and fast-math flags of
comment|/// V and this instruction.
name|void
name|andIRFlags
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
name|private
label|:
comment|/// Return true if we have an entry in the on-the-side metadata hash.
name|bool
name|hasMetadataHashEntry
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getSubclassDataFromValue
argument_list|()
operator|&
name|HasMetadataBit
operator|)
operator|!=
literal|0
return|;
block|}
comment|// These are all implemented in Metadata.cpp.
name|MDNode
modifier|*
name|getMetadataImpl
argument_list|(
name|unsigned
name|KindID
argument_list|)
decl|const
decl_stmt|;
name|MDNode
modifier|*
name|getMetadataImpl
argument_list|(
name|StringRef
name|Kind
argument_list|)
decl|const
decl_stmt|;
name|void
name|getAllMetadataImpl
argument_list|(
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
argument_list|,
name|MDNode
operator|*
operator|>>
operator|&
argument_list|)
decl|const
decl_stmt|;
name|void
name|getAllMetadataOtherThanDebugLocImpl
argument_list|(
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
argument_list|,
name|MDNode
operator|*
operator|>>
operator|&
argument_list|)
decl|const
decl_stmt|;
comment|/// Clear all hashtable-based metadata from this instruction.
name|void
name|clearMetadataHashEntries
parameter_list|()
function_decl|;
name|public
label|:
comment|//===--------------------------------------------------------------------===//
comment|// Predicates and helper methods.
comment|//===--------------------------------------------------------------------===//
comment|/// Return true if the instruction is associative:
comment|///
comment|///   Associative operators satisfy:  x op (y op z) === (x op y) op z
comment|///
comment|/// In LLVM, the Add, Mul, And, Or, and Xor operators are associative.
comment|///
name|bool
name|isAssociative
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
specifier|static
name|bool
name|isAssociative
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
return|return
name|Opcode
operator|==
name|And
operator|||
name|Opcode
operator|==
name|Or
operator|||
name|Opcode
operator|==
name|Xor
operator|||
name|Opcode
operator|==
name|Add
operator|||
name|Opcode
operator|==
name|Mul
return|;
block|}
comment|/// Return true if the instruction is commutative:
comment|///
comment|///   Commutative operators satisfy: (x op y) === (y op x)
comment|///
comment|/// In LLVM, these are the commutative operators, plus SetEQ and SetNE, when
comment|/// applied to any type.
comment|///
name|bool
name|isCommutative
argument_list|()
specifier|const
block|{
return|return
name|isCommutative
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isCommutative
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
switch|switch
condition|(
name|Opcode
condition|)
block|{
case|case
name|Add
case|:
case|case
name|FAdd
case|:
case|case
name|Mul
case|:
case|case
name|FMul
case|:
case|case
name|And
case|:
case|case
name|Or
case|:
case|case
name|Xor
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
comment|/// Return true if the instruction is idempotent:
comment|///
comment|///   Idempotent operators satisfy:  x op x === x
comment|///
comment|/// In LLVM, the And and Or operators are idempotent.
comment|///
name|bool
name|isIdempotent
argument_list|()
specifier|const
block|{
return|return
name|isIdempotent
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isIdempotent
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
return|return
name|Opcode
operator|==
name|And
operator|||
name|Opcode
operator|==
name|Or
return|;
block|}
comment|/// Return true if the instruction is nilpotent:
comment|///
comment|///   Nilpotent operators satisfy:  x op x === Id,
comment|///
comment|///   where Id is the identity for the operator, i.e. a constant such that
comment|///     x op Id === x and Id op x === x for all x.
comment|///
comment|/// In LLVM, the Xor operator is nilpotent.
comment|///
name|bool
name|isNilpotent
argument_list|()
specifier|const
block|{
return|return
name|isNilpotent
argument_list|(
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isNilpotent
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
return|return
name|Opcode
operator|==
name|Xor
return|;
block|}
comment|/// Return true if this instruction may modify memory.
name|bool
name|mayWriteToMemory
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if this instruction may read memory.
name|bool
name|mayReadFromMemory
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if this instruction may read or write memory.
name|bool
name|mayReadOrWriteMemory
argument_list|()
specifier|const
block|{
return|return
name|mayReadFromMemory
argument_list|()
operator|||
name|mayWriteToMemory
argument_list|()
return|;
block|}
comment|/// Return true if this instruction has an AtomicOrdering of unordered or
comment|/// higher.
name|bool
name|isAtomic
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if this instruction may throw an exception.
name|bool
name|mayThrow
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if this instruction behaves like a memory fence: it can load
comment|/// or store to memory location without being given a memory location.
name|bool
name|isFenceLike
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|getOpcode
argument_list|()
condition|)
block|{
default|default:
return|return
name|false
return|;
comment|// This list should be kept in sync with the list in mayWriteToMemory for
comment|// all opcodes which don't have a memory location.
case|case
name|Instruction
operator|::
name|Fence
case|:
case|case
name|Instruction
operator|::
name|CatchPad
case|:
case|case
name|Instruction
operator|::
name|CatchRet
case|:
case|case
name|Instruction
operator|::
name|Call
case|:
case|case
name|Instruction
operator|::
name|Invoke
case|:
return|return
name|true
return|;
block|}
block|}
comment|/// Return true if the instruction may have side effects.
comment|///
comment|/// Note that this does not consider malloc and alloca to have side
comment|/// effects because the newly allocated memory is completely invisible to
comment|/// instructions which don't use the returned value.  For cases where this
comment|/// matters, isSafeToSpeculativelyExecute may be more appropriate.
name|bool
name|mayHaveSideEffects
argument_list|()
specifier|const
block|{
return|return
name|mayWriteToMemory
argument_list|()
operator|||
name|mayThrow
argument_list|()
return|;
block|}
comment|/// Return true if the instruction is a variety of EH-block.
name|bool
name|isEHPad
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|getOpcode
argument_list|()
condition|)
block|{
case|case
name|Instruction
operator|::
name|CatchSwitch
case|:
case|case
name|Instruction
operator|::
name|CatchPad
case|:
case|case
name|Instruction
operator|::
name|CleanupPad
case|:
case|case
name|Instruction
operator|::
name|LandingPad
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
comment|/// Create a copy of 'this' instruction that is identical in all ways except
comment|/// the following:
comment|///   * The instruction has no parent
comment|///   * The instruction has no name
comment|///
name|Instruction
operator|*
name|clone
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if the specified instruction is exactly identical to the
comment|/// current one. This means that all operands match and any extra information
comment|/// (e.g. load is volatile) agree.
name|bool
name|isIdenticalTo
argument_list|(
specifier|const
name|Instruction
operator|*
name|I
argument_list|)
decl|const
decl_stmt|;
comment|/// This is like isIdenticalTo, except that it ignores the
comment|/// SubclassOptionalData flags, which may specify conditions under which the
comment|/// instruction's result is undefined.
name|bool
name|isIdenticalToWhenDefined
argument_list|(
specifier|const
name|Instruction
operator|*
name|I
argument_list|)
decl|const
decl_stmt|;
comment|/// When checking for operation equivalence (using isSameOperationAs) it is
comment|/// sometimes useful to ignore certain attributes.
enum|enum
name|OperationEquivalenceFlags
block|{
comment|/// Check for equivalence ignoring load/store alignment.
name|CompareIgnoringAlignment
init|=
literal|1
operator|<<
literal|0
block|,
comment|/// Check for equivalence treating a type and a vector of that type
comment|/// as equivalent.
name|CompareUsingScalarTypes
init|=
literal|1
operator|<<
literal|1
block|}
enum|;
comment|/// This function determines if the specified instruction executes the same
comment|/// operation as the current one. This means that the opcodes, type, operand
comment|/// types and any other factors affecting the operation must be the same. This
comment|/// is similar to isIdenticalTo except the operands themselves don't have to
comment|/// be identical.
comment|/// @returns true if the specified instruction is the same operation as
comment|/// the current one.
comment|/// @brief Determine if one instruction is the same operation as another.
name|bool
name|isSameOperationAs
argument_list|(
specifier|const
name|Instruction
operator|*
name|I
argument_list|,
name|unsigned
name|flags
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// Return true if there are any uses of this instruction in blocks other than
comment|/// the specified block. Note that PHI nodes are considered to evaluate their
comment|/// operands in the corresponding predecessor block.
name|bool
name|isUsedOutsideOfBlock
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|>=
name|Value
operator|::
name|InstructionVal
return|;
block|}
comment|//----------------------------------------------------------------------
comment|// Exported enumerations.
comment|//
enum|enum
name|TermOps
block|{
comment|// These terminate basic blocks
define|#
directive|define
name|FIRST_TERM_INST
parameter_list|(
name|N
parameter_list|)
value|TermOpsBegin = N,
define|#
directive|define
name|HANDLE_TERM_INST
parameter_list|(
name|N
parameter_list|,
name|OPC
parameter_list|,
name|CLASS
parameter_list|)
value|OPC = N,
define|#
directive|define
name|LAST_TERM_INST
parameter_list|(
name|N
parameter_list|)
value|TermOpsEnd = N+1
include|#
directive|include
file|"llvm/IR/Instruction.def"
block|}
enum|;
enum|enum
name|BinaryOps
block|{
define|#
directive|define
name|FIRST_BINARY_INST
parameter_list|(
name|N
parameter_list|)
value|BinaryOpsBegin = N,
define|#
directive|define
name|HANDLE_BINARY_INST
parameter_list|(
name|N
parameter_list|,
name|OPC
parameter_list|,
name|CLASS
parameter_list|)
value|OPC = N,
define|#
directive|define
name|LAST_BINARY_INST
parameter_list|(
name|N
parameter_list|)
value|BinaryOpsEnd = N+1
include|#
directive|include
file|"llvm/IR/Instruction.def"
block|}
enum|;
enum|enum
name|MemoryOps
block|{
define|#
directive|define
name|FIRST_MEMORY_INST
parameter_list|(
name|N
parameter_list|)
value|MemoryOpsBegin = N,
define|#
directive|define
name|HANDLE_MEMORY_INST
parameter_list|(
name|N
parameter_list|,
name|OPC
parameter_list|,
name|CLASS
parameter_list|)
value|OPC = N,
define|#
directive|define
name|LAST_MEMORY_INST
parameter_list|(
name|N
parameter_list|)
value|MemoryOpsEnd = N+1
include|#
directive|include
file|"llvm/IR/Instruction.def"
block|}
enum|;
enum|enum
name|CastOps
block|{
define|#
directive|define
name|FIRST_CAST_INST
parameter_list|(
name|N
parameter_list|)
value|CastOpsBegin = N,
define|#
directive|define
name|HANDLE_CAST_INST
parameter_list|(
name|N
parameter_list|,
name|OPC
parameter_list|,
name|CLASS
parameter_list|)
value|OPC = N,
define|#
directive|define
name|LAST_CAST_INST
parameter_list|(
name|N
parameter_list|)
value|CastOpsEnd = N+1
include|#
directive|include
file|"llvm/IR/Instruction.def"
block|}
enum|;
enum|enum
name|FuncletPadOps
block|{
define|#
directive|define
name|FIRST_FUNCLETPAD_INST
parameter_list|(
name|N
parameter_list|)
value|FuncletPadOpsBegin = N,
define|#
directive|define
name|HANDLE_FUNCLETPAD_INST
parameter_list|(
name|N
parameter_list|,
name|OPC
parameter_list|,
name|CLASS
parameter_list|)
value|OPC = N,
define|#
directive|define
name|LAST_FUNCLETPAD_INST
parameter_list|(
name|N
parameter_list|)
value|FuncletPadOpsEnd = N+1
include|#
directive|include
file|"llvm/IR/Instruction.def"
block|}
enum|;
enum|enum
name|OtherOps
block|{
define|#
directive|define
name|FIRST_OTHER_INST
parameter_list|(
name|N
parameter_list|)
value|OtherOpsBegin = N,
define|#
directive|define
name|HANDLE_OTHER_INST
parameter_list|(
name|N
parameter_list|,
name|OPC
parameter_list|,
name|CLASS
parameter_list|)
value|OPC = N,
define|#
directive|define
name|LAST_OTHER_INST
parameter_list|(
name|N
parameter_list|)
value|OtherOpsEnd = N+1
include|#
directive|include
file|"llvm/IR/Instruction.def"
block|}
enum|;
name|private
label|:
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|Instruction
operator|>
expr_stmt|;
comment|// Shadow Value::setValueSubclassData with a private forwarding method so that
comment|// subclasses cannot accidentally use it.
name|void
name|setValueSubclassData
parameter_list|(
name|unsigned
name|short
name|D
parameter_list|)
block|{
name|Value
operator|::
name|setValueSubclassData
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
name|unsigned
name|short
name|getSubclassDataFromValue
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|::
name|getSubclassDataFromValue
argument_list|()
return|;
block|}
name|void
name|setHasMetadataHashEntry
parameter_list|(
name|bool
name|V
parameter_list|)
block|{
name|setValueSubclassData
argument_list|(
operator|(
name|getSubclassDataFromValue
argument_list|()
operator|&
operator|~
name|HasMetadataBit
operator|)
operator||
operator|(
name|V
condition|?
name|HasMetadataBit
else|:
literal|0
operator|)
argument_list|)
expr_stmt|;
block|}
name|void
name|setParent
parameter_list|(
name|BasicBlock
modifier|*
name|P
parameter_list|)
function_decl|;
name|protected
label|:
comment|// Instruction subclasses can stick up to 15 bits of stuff into the
comment|// SubclassData field of instruction with these members.
comment|// Verify that only the low 15 bits are used.
name|void
name|setInstructionSubclassData
parameter_list|(
name|unsigned
name|short
name|D
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|D
operator|&
name|HasMetadataBit
operator|)
operator|==
literal|0
operator|&&
literal|"Out of range value put into field"
argument_list|)
expr_stmt|;
name|setValueSubclassData
argument_list|(
operator|(
name|getSubclassDataFromValue
argument_list|()
operator|&
name|HasMetadataBit
operator|)
operator||
name|D
argument_list|)
expr_stmt|;
block|}
name|unsigned
name|getSubclassDataFromInstruction
argument_list|()
specifier|const
block|{
return|return
name|getSubclassDataFromValue
argument_list|()
operator|&
operator|~
name|HasMetadataBit
return|;
block|}
name|Instruction
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned iType
argument_list|,
argument|Use *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
empty_stmt|;
name|Instruction
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned iType
argument_list|,
argument|Use *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
empty_stmt|;
name|private
label|:
comment|/// Create a copy of this instruction.
name|Instruction
operator|*
name|cloneImpl
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_INSTRUCTION_H
end_comment

end_unit

