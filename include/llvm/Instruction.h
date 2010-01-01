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
name|LLVM_INSTRUCTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_INSTRUCTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/User.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContext
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|template
operator|<
name|typename
name|ValueSubClass
operator|,
name|typename
name|ItemParentClass
operator|>
name|class
name|SymbolTableListTraits
expr_stmt|;
name|class
name|Instruction
range|:
name|public
name|User
decl_stmt|,
name|public
name|ilist_node
decl|<
name|Instruction
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
decl_stmt|;
comment|// Do not implement
name|Instruction
argument_list|(
specifier|const
name|Instruction
operator|&
argument_list|)
expr_stmt|;
comment|// Do not implement
name|BasicBlock
modifier|*
name|Parent
decl_stmt|;
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
expr_stmt|;
comment|/// use_back - Specialize the methods defined in Value, as we know that an
comment|/// instruction can only be used by other instructions.
name|Instruction
modifier|*
name|use_back
parameter_list|()
block|{
return|return
name|cast
operator|<
name|Instruction
operator|>
operator|(
operator|*
name|use_begin
argument_list|()
operator|)
return|;
block|}
specifier|const
name|Instruction
operator|*
name|use_back
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
name|use_begin
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
name|void
name|eraseFromParent
parameter_list|()
function_decl|;
comment|/// insertBefore - Insert an unlinked instructions into a basic block
comment|/// immediately before the specified instruction.
name|void
name|insertBefore
parameter_list|(
name|Instruction
modifier|*
name|InsertPos
parameter_list|)
function_decl|;
comment|/// insertAfter - Insert an unlinked instructions into a basic block
comment|/// immediately after the specified instruction.
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
literal|0
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
specifier|const
name|char
operator|*
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
literal|0
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
operator|>
expr|>
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
comment|/// setMetadata - Set the metadata of of the specified kind to the specified
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
specifier|const
name|char
modifier|*
name|Kind
parameter_list|,
name|MDNode
modifier|*
name|Node
parameter_list|)
function_decl|;
name|private
label|:
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
specifier|const
name|char
operator|*
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
operator|>
expr|>
operator|&
argument_list|)
decl|const
decl_stmt|;
name|void
name|removeAllMetadata
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
comment|/// In LLVM, the Add, Mul, And, Or, and Xor operators are associative, when
comment|/// not applied to floating point types.
comment|///
name|bool
name|isAssociative
argument_list|()
specifier|const
block|{
return|return
name|isAssociative
argument_list|(
name|getOpcode
argument_list|()
argument_list|,
name|getType
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isAssociative
parameter_list|(
name|unsigned
name|op
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
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
comment|/// mayThrow - Return true if this instruction may throw an exception.
comment|///
name|bool
name|mayThrow
argument_list|()
specifier|const
expr_stmt|;
comment|/// mayHaveSideEffects - Return true if the instruction may have side effects.
comment|///
comment|/// Note that this does not consider malloc and alloca to have side
comment|/// effects because the newly allocated memory is completely invisible to
comment|/// instructions which don't used the returned value.  For cases where this
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
comment|/// isSafeToSpeculativelyExecute - Return true if the instruction does not
comment|/// have any effects besides calculating the result and does not have
comment|/// undefined behavior.
comment|///
comment|/// This method never returns true for an instruction that returns true for
comment|/// mayHaveSideEffects; however, this method also does some other checks in
comment|/// addition. It checks for undefined behavior, like dividing by zero or
comment|/// loading from an invalid pointer (but not for undefined results, like a
comment|/// shift with a shift amount larger than the width of the result). It checks
comment|/// for malloc and alloca because speculatively executing them might cause a
comment|/// memory leak. It also returns false for instructions related to control
comment|/// flow, specifically terminators and PHI nodes.
comment|///
comment|/// This method only looks at the instruction itself and its operands, so if
comment|/// this method returns true, it is safe to move the instruction as long as
comment|/// the correct dominance relationships for the operands and users hold.
comment|/// However, this method can return true for instructions that read memory;
comment|/// for such instructions, moving them may change the resulting value.
name|bool
name|isSafeToSpeculativelyExecute
argument_list|()
specifier|const
expr_stmt|;
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
name|Instruction
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
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
file|"llvm/Instruction.def"
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
file|"llvm/Instruction.def"
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
file|"llvm/Instruction.def"
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
file|"llvm/Instruction.def"
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
file|"llvm/Instruction.def"
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
name|setHasMetadata
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
operator|,
name|BasicBlock
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
argument|const Type *Ty
argument_list|,
argument|unsigned iType
argument_list|,
argument|Use *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
empty_stmt|;
name|Instruction
argument_list|(
argument|const Type *Ty
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
name|virtual
name|Instruction
operator|*
name|clone_impl
argument_list|()
specifier|const
operator|=
literal|0
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

