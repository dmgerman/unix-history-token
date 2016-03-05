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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FastMathFlags
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
struct_decl|struct
name|AAMDNodes
struct_decl|;
name|template
operator|<
operator|>
expr|struct
name|SymbolTableListSentinelTraits
operator|<
name|Instruction
operator|>
operator|:
name|public
name|ilist_half_embedded_sentinel_traits
operator|<
name|Instruction
operator|>
block|{}
expr_stmt|;
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
name|void
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
name|Instruction
argument_list|(
specifier|const
name|Instruction
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
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
comment|/// HasMetadataBit - This is a bit stored in the SubClassData field which
comment|/// indicates whether this instruction has metadata attached to it or not.
name|HasMetadataBit
init|=
literal|1
operator|<<
literal|15
block|}
enum|;
name|public
label|:
comment|// Out of line virtual method, so the vtable, etc has a home.
operator|~
name|Instruction
argument_list|()
name|override
expr_stmt|;
comment|/// user_back - Specialize the methods defined in Value, as we know that an
comment|/// instruction can only be used by other instructions.
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
comment|/// \brief Return the module owning the function this instruction belongs to
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
function_decl|;
comment|/// \brief Return the function this instruction belongs to.
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
function_decl|;
comment|/// removeFromParent - This method unlinks 'this' from the containing basic
comment|/// block, but does not delete it.
comment|///
name|void
name|removeFromParent
parameter_list|()
function_decl|;
comment|/// eraseFromParent - This method unlinks 'this' from the containing basic
comment|/// block and deletes it.
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
comment|/// moveBefore - Unlink this instruction from its current basic block and
comment|/// insert it into the basic block that MovePos lives in, right before
comment|/// MovePos.
name|void
name|moveBefore
parameter_list|(
name|Instruction
modifier|*
name|MovePos
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// Subclass classification.
comment|//===--------------------------------------------------------------------===//
comment|/// getOpcode() returns a member of one of the enums like Instruction::Add.
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
comment|/// @brief Determine if the Opcode is one of the shift instructions.
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
comment|/// isLogicalShift - Return true if this is a logical shift left or a logical
comment|/// shift right.
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
comment|/// isArithmeticShift - Return true if this is an arithmetic shift right.
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
comment|/// @brief Determine if the OpCode is one of the CastInst instructions.
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
comment|/// @brief Determine if the OpCode is one of the FuncletPadInst instructions.
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
comment|/// hasMetadata() - Return true if this instruction has any metadata attached
comment|/// to it.
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
comment|/// hasMetadataOtherThanDebugLoc - Return true if this instruction has
comment|/// metadata attached to it other than a debug location.
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
comment|/// getMetadata - Get the metadata of given kind attached to this Instruction.
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
comment|/// getMetadata - Get the metadata of given kind attached to this Instruction.
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
comment|/// getAllMetadata - Get all metadata attached to this Instruction.  The first
comment|/// element of each pair returned is the KindID, the second element is the
comment|/// metadata value.  This list is returned sorted by the KindID.
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
comment|/// getAllMetadataOtherThanDebugLoc - This does the same thing as
comment|/// getAllMetadata, except that it filters out the debug location.
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
comment|/// getAAMetadata - Fills the AAMDNodes structure with AA metadata from
comment|/// this instruction. When Merge is true, the existing AA metadata is
comment|/// merged with that from this instruction providing the most-general result.
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
comment|/// setMetadata - Set the metadata of the specified kind to the specified
comment|/// node.  This updates/replaces metadata if already present, or removes it if
comment|/// Node is null.
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
comment|/// setAAMetadata - Sets the metadata on this instruction from the
comment|/// AAMDNodes structure.
name|void
name|setAAMetadata
parameter_list|(
specifier|const
name|AAMDNodes
modifier|&
name|N
parameter_list|)
function_decl|;
comment|/// setDebugLoc - Set the debug location information for this instruction.
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
comment|/// getDebugLoc - Return the debug location for this node as a DebugLoc.
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
name|private
label|:
comment|/// hasMetadataHashEntry - Return true if we have an entry in the on-the-side
comment|/// metadata hash.
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
name|void
name|clearMetadataHashEntries
parameter_list|()
function_decl|;
name|public
label|:
comment|//===--------------------------------------------------------------------===//
comment|// Predicates and helper methods.
comment|//===--------------------------------------------------------------------===//
comment|/// isAssociative - Return true if the instruction is associative:
comment|///
comment|///   Associative operators satisfy:  x op (y op z) === (x op y) op z
comment|///
comment|/// In LLVM, the Add, Mul, And, Or, and Xor operators are associative.
comment|///
name|bool
name|isAssociative
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|bool
name|isAssociative
parameter_list|(
name|unsigned
name|op
parameter_list|)
function_decl|;
comment|/// isCommutative - Return true if the instruction is commutative:
comment|///
comment|///   Commutative operators satisfy: (x op y) === (y op x)
comment|///
comment|/// In LLVM, these are the associative operators, plus SetEQ and SetNE, when
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
name|op
parameter_list|)
function_decl|;
comment|/// isIdempotent - Return true if the instruction is idempotent:
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
name|op
parameter_list|)
function_decl|;
comment|/// isNilpotent - Return true if the instruction is nilpotent:
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
name|op
parameter_list|)
function_decl|;
comment|/// mayWriteToMemory - Return true if this instruction may modify memory.
comment|///
name|bool
name|mayWriteToMemory
argument_list|()
specifier|const
expr_stmt|;
comment|/// mayReadFromMemory - Return true if this instruction may read memory.
comment|///
name|bool
name|mayReadFromMemory
argument_list|()
specifier|const
expr_stmt|;
comment|/// mayReadOrWriteMemory - Return true if this instruction may read or
comment|/// write memory.
comment|///
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
comment|/// isAtomic - Return true if this instruction has an
comment|/// AtomicOrdering of unordered or higher.
comment|///
name|bool
name|isAtomic
argument_list|()
specifier|const
expr_stmt|;
comment|/// mayThrow - Return true if this instruction may throw an exception.
comment|///
name|bool
name|mayThrow
argument_list|()
specifier|const
expr_stmt|;
comment|/// mayReturn - Return true if this is a function that may return.
comment|/// this is true for all normal instructions. The only exception
comment|/// is functions that are marked with the 'noreturn' attribute.
comment|///
name|bool
name|mayReturn
argument_list|()
specifier|const
expr_stmt|;
comment|/// mayHaveSideEffects - Return true if the instruction may have side effects.
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
operator|||
operator|!
name|mayReturn
argument_list|()
return|;
block|}
comment|/// \brief Return true if the instruction is a variety of EH-block.
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
comment|/// clone() - Create a copy of 'this' instruction that is identical in all
comment|/// ways except the following:
comment|///   * The instruction has no parent
comment|///   * The instruction has no name
comment|///
name|Instruction
operator|*
name|clone
argument_list|()
specifier|const
expr_stmt|;
comment|/// isIdenticalTo - Return true if the specified instruction is exactly
comment|/// identical to the current one.  This means that all operands match and any
comment|/// extra information (e.g. load is volatile) agree.
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
comment|/// isIdenticalToWhenDefined - This is like isIdenticalTo, except that it
comment|/// ignores the SubclassOptionalData flags, which specify conditions
comment|/// under which the instruction's result is undefined.
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
comment|/// isUsedOutsideOfBlock - Return true if there are any uses of this
comment|/// instruction in blocks other than the specified block.  Note that PHI nodes
comment|/// are considered to evaluate their operands in the corresponding predecessor
comment|/// block.
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
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|Instruction
operator|>
expr_stmt|;
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
comment|// Instruction* is only 4-byte aligned.
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|Instruction
operator|*
operator|>
block|{
typedef|typedef
name|Instruction
modifier|*
name|PT
typedef|;
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|PT P
argument_list|)
block|{
return|return
name|P
return|;
block|}
specifier|static
specifier|inline
name|PT
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|PT
operator|>
operator|(
name|P
operator|)
return|;
block|}
block|enum
block|{
name|NumLowBitsAvailable
operator|=
literal|2
block|}
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

