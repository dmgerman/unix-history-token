begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/InstrTypes.h - Important Instruction subclasses ----*- C++ -*-===//
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
comment|// This file defines various meta classes of instructions that exist in the VM
end_comment

begin_comment
comment|// representation.  Specific concrete subclasses of these may be found in the
end_comment

begin_comment
comment|// i*.h files...
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
name|LLVM_INSTRUCTION_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_INSTRUCTION_TYPES_H
end_define

begin_include
include|#
directive|include
file|"llvm/Instruction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/OperandTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Operator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DerivedTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContext
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//                            TerminatorInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// TerminatorInst - Subclasses of this class are all able to terminate a basic
comment|/// block.  Thus, these are all the flow control type of operations.
comment|///
name|class
name|TerminatorInst
range|:
name|public
name|Instruction
block|{
name|protected
operator|:
name|TerminatorInst
argument_list|(
argument|const Type *Ty
argument_list|,
argument|Instruction::TermOps iType
argument_list|,
argument|Use *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
operator|:
name|Instruction
argument_list|(
argument|Ty
argument_list|,
argument|iType
argument_list|,
argument|Ops
argument_list|,
argument|NumOps
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
name|TerminatorInst
argument_list|(
argument|const Type *Ty
argument_list|,
argument|Instruction::TermOps iType
argument_list|,
argument|Use *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
operator|:
name|Instruction
argument_list|(
argument|Ty
argument_list|,
argument|iType
argument_list|,
argument|Ops
argument_list|,
argument|NumOps
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{}
comment|// Out of line virtual method, so the vtable, etc has a home.
operator|~
name|TerminatorInst
argument_list|()
block|;
comment|/// Virtual methods - Terminators should overload these and provide inline
comment|/// overrides of non-V methods.
name|virtual
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setSuccessorV
argument_list|(
argument|unsigned idx
argument_list|,
argument|BasicBlock *B
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|TerminatorInst
operator|*
name|clone_impl
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|public
operator|:
comment|/// getNumSuccessors - Return the number of successors that this terminator
comment|/// has.
name|unsigned
name|getNumSuccessors
argument_list|()
specifier|const
block|{
return|return
name|getNumSuccessorsV
argument_list|()
return|;
block|}
comment|/// getSuccessor - Return the specified successor.
comment|///
name|BasicBlock
operator|*
name|getSuccessor
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|{
return|return
name|getSuccessorV
argument_list|(
name|idx
argument_list|)
return|;
block|}
comment|/// setSuccessor - Update the specified successor to point at the provided
comment|/// block.
name|void
name|setSuccessor
argument_list|(
argument|unsigned idx
argument_list|,
argument|BasicBlock *B
argument_list|)
block|{
name|setSuccessorV
argument_list|(
name|idx
argument_list|,
name|B
argument_list|)
block|;   }
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const TerminatorInst *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Instruction *I
argument_list|)
block|{
return|return
name|I
operator|->
name|isTerminator
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|isa
operator|<
name|Instruction
operator|>
operator|(
name|V
operator|)
operator|&&
name|classof
argument_list|(
name|cast
operator|<
name|Instruction
operator|>
operator|(
name|V
operator|)
argument_list|)
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|//                          UnaryInstruction Class
comment|//===----------------------------------------------------------------------===//
name|class
name|UnaryInstruction
operator|:
name|public
name|Instruction
block|{
name|void
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|,
name|unsigned
argument_list|)
block|;
comment|// Do not implement
name|protected
operator|:
name|UnaryInstruction
argument_list|(
argument|const Type *Ty
argument_list|,
argument|unsigned iType
argument_list|,
argument|Value *V
argument_list|,
argument|Instruction *IB =
literal|0
argument_list|)
operator|:
name|Instruction
argument_list|(
argument|Ty
argument_list|,
argument|iType
argument_list|,
argument|&Op<
literal|0
argument|>()
argument_list|,
literal|1
argument_list|,
argument|IB
argument_list|)
block|{
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
operator|=
name|V
block|;   }
name|UnaryInstruction
argument_list|(
argument|const Type *Ty
argument_list|,
argument|unsigned iType
argument_list|,
argument|Value *V
argument_list|,
argument|BasicBlock *IAE
argument_list|)
operator|:
name|Instruction
argument_list|(
argument|Ty
argument_list|,
argument|iType
argument_list|,
argument|&Op<
literal|0
argument|>()
argument_list|,
literal|1
argument_list|,
argument|IAE
argument_list|)
block|{
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
operator|=
name|V
block|;   }
name|public
operator|:
comment|// allocate space for exactly one operand
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|,
literal|1
argument_list|)
return|;
block|}
comment|// Out of line virtual method, so the vtable, etc has a home.
operator|~
name|UnaryInstruction
argument_list|()
block|;
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const UnaryInstruction *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Instruction *I
argument_list|)
block|{
return|return
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Alloca
operator|||
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Load
operator|||
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|VAArg
operator|||
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|ExtractValue
operator|||
operator|(
name|I
operator|->
name|getOpcode
argument_list|()
operator|>=
name|CastOpsBegin
operator|&&
name|I
operator|->
name|getOpcode
argument_list|()
operator|<
name|CastOpsEnd
operator|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|isa
operator|<
name|Instruction
operator|>
operator|(
name|V
operator|)
operator|&&
name|classof
argument_list|(
name|cast
operator|<
name|Instruction
operator|>
operator|(
name|V
operator|)
argument_list|)
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|UnaryInstruction
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
literal|1
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|UnaryInstruction
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                           BinaryOperator Class
comment|//===----------------------------------------------------------------------===//
name|class
name|BinaryOperator
operator|:
name|public
name|Instruction
block|{
name|void
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|,
name|unsigned
argument_list|)
block|;
comment|// Do not implement
name|protected
operator|:
name|void
name|init
argument_list|(
argument|BinaryOps iType
argument_list|)
block|;
name|BinaryOperator
argument_list|(
argument|BinaryOps iType
argument_list|,
argument|Value *S1
argument_list|,
argument|Value *S2
argument_list|,
argument|const Type *Ty
argument_list|,
argument|const Twine&Name
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
block|;
name|BinaryOperator
argument_list|(
argument|BinaryOps iType
argument_list|,
argument|Value *S1
argument_list|,
argument|Value *S2
argument_list|,
argument|const Type *Ty
argument_list|,
argument|const Twine&Name
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|virtual
name|BinaryOperator
operator|*
name|clone_impl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|// allocate space for exactly two operands
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|,
literal|2
argument_list|)
return|;
block|}
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|/// Create() - Construct a binary instruction, given the opcode and the two
comment|/// operands.  Optionally (if InstBefore is specified) insert the instruction
comment|/// into a BasicBlock right before the specified instruction.  The specified
comment|/// Instruction is allowed to be a dereferenced end iterator.
comment|///
specifier|static
name|BinaryOperator
operator|*
name|Create
argument_list|(
argument|BinaryOps Op
argument_list|,
argument|Value *S1
argument_list|,
argument|Value *S2
argument_list|,
argument|const Twine&Name = Twine()
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|;
comment|/// Create() - Construct a binary instruction, given the opcode and the two
comment|/// operands.  Also automatically insert this instruction to the end of the
comment|/// BasicBlock specified.
comment|///
specifier|static
name|BinaryOperator
operator|*
name|Create
argument_list|(
argument|BinaryOps Op
argument_list|,
argument|Value *S1
argument_list|,
argument|Value *S2
argument_list|,
argument|const Twine&Name
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
comment|/// Create* - These methods just forward to Create, and are useful when you
comment|/// statically know what type of instruction you're going to create.  These
comment|/// helpers just save some typing.
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
define|\
value|static BinaryOperator *Create##OPC(Value *V1, Value *V2, \                                      const Twine&Name = "") {\     return Create(Instruction::OPC, V1, V2, Name);\   }
include|#
directive|include
file|"llvm/Instruction.def"
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
define|\
value|static BinaryOperator *Create##OPC(Value *V1, Value *V2, \                                      const Twine&Name, BasicBlock *BB) {\     return Create(Instruction::OPC, V1, V2, Name, BB);\   }
include|#
directive|include
file|"llvm/Instruction.def"
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
define|\
value|static BinaryOperator *Create##OPC(Value *V1, Value *V2, \                                      const Twine&Name, Instruction *I) {\     return Create(Instruction::OPC, V1, V2, Name, I);\   }
include|#
directive|include
file|"llvm/Instruction.def"
comment|/// CreateNSWAdd - Create an Add operator with the NSW flag set.
comment|///
specifier|static
name|BinaryOperator
operator|*
name|CreateNSWAdd
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateAdd
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|)
block|;
name|BO
operator|->
name|setHasNoSignedWrap
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
specifier|static
name|BinaryOperator
operator|*
name|CreateNSWAdd
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name
argument_list|,
argument|BasicBlock *BB
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateAdd
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|,
name|BB
argument_list|)
block|;
name|BO
operator|->
name|setHasNoSignedWrap
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
specifier|static
name|BinaryOperator
operator|*
name|CreateNSWAdd
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name
argument_list|,
argument|Instruction *I
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateAdd
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|,
name|I
argument_list|)
block|;
name|BO
operator|->
name|setHasNoSignedWrap
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
comment|/// CreateNUWAdd - Create an Add operator with the NUW flag set.
comment|///
specifier|static
name|BinaryOperator
operator|*
name|CreateNUWAdd
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateAdd
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|)
block|;
name|BO
operator|->
name|setHasNoUnsignedWrap
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
specifier|static
name|BinaryOperator
operator|*
name|CreateNUWAdd
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name
argument_list|,
argument|BasicBlock *BB
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateAdd
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|,
name|BB
argument_list|)
block|;
name|BO
operator|->
name|setHasNoUnsignedWrap
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
specifier|static
name|BinaryOperator
operator|*
name|CreateNUWAdd
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name
argument_list|,
argument|Instruction *I
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateAdd
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|,
name|I
argument_list|)
block|;
name|BO
operator|->
name|setHasNoUnsignedWrap
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
comment|/// CreateNSWSub - Create an Sub operator with the NSW flag set.
comment|///
specifier|static
name|BinaryOperator
operator|*
name|CreateNSWSub
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateSub
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|)
block|;
name|BO
operator|->
name|setHasNoSignedWrap
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
specifier|static
name|BinaryOperator
operator|*
name|CreateNSWSub
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name
argument_list|,
argument|BasicBlock *BB
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateSub
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|,
name|BB
argument_list|)
block|;
name|BO
operator|->
name|setHasNoSignedWrap
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
specifier|static
name|BinaryOperator
operator|*
name|CreateNSWSub
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name
argument_list|,
argument|Instruction *I
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateSub
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|,
name|I
argument_list|)
block|;
name|BO
operator|->
name|setHasNoSignedWrap
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
comment|/// CreateNUWSub - Create an Sub operator with the NUW flag set.
comment|///
specifier|static
name|BinaryOperator
operator|*
name|CreateNUWSub
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateSub
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|)
block|;
name|BO
operator|->
name|setHasNoUnsignedWrap
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
specifier|static
name|BinaryOperator
operator|*
name|CreateNUWSub
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name
argument_list|,
argument|BasicBlock *BB
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateSub
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|,
name|BB
argument_list|)
block|;
name|BO
operator|->
name|setHasNoUnsignedWrap
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
specifier|static
name|BinaryOperator
operator|*
name|CreateNUWSub
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name
argument_list|,
argument|Instruction *I
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateSub
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|,
name|I
argument_list|)
block|;
name|BO
operator|->
name|setHasNoUnsignedWrap
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
comment|/// CreateNSWMul - Create a Mul operator with the NSW flag set.
comment|///
specifier|static
name|BinaryOperator
operator|*
name|CreateNSWMul
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateMul
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|)
block|;
name|BO
operator|->
name|setHasNoSignedWrap
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
specifier|static
name|BinaryOperator
operator|*
name|CreateNSWMul
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name
argument_list|,
argument|BasicBlock *BB
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateMul
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|,
name|BB
argument_list|)
block|;
name|BO
operator|->
name|setHasNoSignedWrap
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
specifier|static
name|BinaryOperator
operator|*
name|CreateNSWMul
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name
argument_list|,
argument|Instruction *I
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateMul
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|,
name|I
argument_list|)
block|;
name|BO
operator|->
name|setHasNoSignedWrap
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
comment|/// CreateExactSDiv - Create an SDiv operator with the exact flag set.
comment|///
specifier|static
name|BinaryOperator
operator|*
name|CreateExactSDiv
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateSDiv
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|)
block|;
name|BO
operator|->
name|setIsExact
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
specifier|static
name|BinaryOperator
operator|*
name|CreateExactSDiv
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name
argument_list|,
argument|BasicBlock *BB
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateSDiv
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|,
name|BB
argument_list|)
block|;
name|BO
operator|->
name|setIsExact
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
specifier|static
name|BinaryOperator
operator|*
name|CreateExactSDiv
argument_list|(
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|const Twine&Name
argument_list|,
argument|Instruction *I
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|CreateSDiv
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|,
name|I
argument_list|)
block|;
name|BO
operator|->
name|setIsExact
argument_list|(
name|true
argument_list|)
block|;
return|return
name|BO
return|;
block|}
comment|/// Helper functions to construct and inspect unary operations (NEG and NOT)
comment|/// via binary operators SUB and XOR:
comment|///
comment|/// CreateNeg, CreateNot - Create the NEG and NOT
comment|///     instructions out of SUB and XOR instructions.
comment|///
specifier|static
name|BinaryOperator
operator|*
name|CreateNeg
argument_list|(
name|Value
operator|*
name|Op
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|BinaryOperator
operator|*
name|CreateNeg
argument_list|(
name|Value
operator|*
name|Op
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
specifier|static
name|BinaryOperator
operator|*
name|CreateNSWNeg
argument_list|(
name|Value
operator|*
name|Op
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|BinaryOperator
operator|*
name|CreateNSWNeg
argument_list|(
name|Value
operator|*
name|Op
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
specifier|static
name|BinaryOperator
operator|*
name|CreateFNeg
argument_list|(
name|Value
operator|*
name|Op
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|BinaryOperator
operator|*
name|CreateFNeg
argument_list|(
name|Value
operator|*
name|Op
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
specifier|static
name|BinaryOperator
operator|*
name|CreateNot
argument_list|(
name|Value
operator|*
name|Op
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|BinaryOperator
operator|*
name|CreateNot
argument_list|(
name|Value
operator|*
name|Op
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
comment|/// isNeg, isFNeg, isNot - Check if the given Value is a
comment|/// NEG, FNeg, or NOT instruction.
comment|///
specifier|static
name|bool
name|isNeg
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
block|;
specifier|static
name|bool
name|isFNeg
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
block|;
specifier|static
name|bool
name|isNot
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
block|;
comment|/// getNegArgument, getNotArgument - Helper functions to extract the
comment|///     unary argument of a NEG, FNEG or NOT operation implemented via
comment|///     Sub, FSub, or Xor.
comment|///
specifier|static
specifier|const
name|Value
operator|*
name|getNegArgument
argument_list|(
specifier|const
name|Value
operator|*
name|BinOp
argument_list|)
block|;
specifier|static
name|Value
operator|*
name|getNegArgument
argument_list|(
name|Value
operator|*
name|BinOp
argument_list|)
block|;
specifier|static
specifier|const
name|Value
operator|*
name|getFNegArgument
argument_list|(
specifier|const
name|Value
operator|*
name|BinOp
argument_list|)
block|;
specifier|static
name|Value
operator|*
name|getFNegArgument
argument_list|(
name|Value
operator|*
name|BinOp
argument_list|)
block|;
specifier|static
specifier|const
name|Value
operator|*
name|getNotArgument
argument_list|(
specifier|const
name|Value
operator|*
name|BinOp
argument_list|)
block|;
specifier|static
name|Value
operator|*
name|getNotArgument
argument_list|(
name|Value
operator|*
name|BinOp
argument_list|)
block|;
name|BinaryOps
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|BinaryOps
operator|>
operator|(
name|Instruction
operator|::
name|getOpcode
argument_list|()
operator|)
return|;
block|}
comment|/// swapOperands - Exchange the two operands to this instruction.
comment|/// This instruction is safe to use on any binary instruction and
comment|/// does not modify the semantics of the instruction.  If the instruction
comment|/// cannot be reversed (ie, it's a Div), then return true.
comment|///
name|bool
name|swapOperands
argument_list|()
block|;
comment|/// setHasNoUnsignedWrap - Set or clear the nsw flag on this instruction,
comment|/// which must be an operator which supports this flag. See LangRef.html
comment|/// for the meaning of this flag.
name|void
name|setHasNoUnsignedWrap
argument_list|(
argument|bool b = true
argument_list|)
block|;
comment|/// setHasNoSignedWrap - Set or clear the nsw flag on this instruction,
comment|/// which must be an operator which supports this flag. See LangRef.html
comment|/// for the meaning of this flag.
name|void
name|setHasNoSignedWrap
argument_list|(
argument|bool b = true
argument_list|)
block|;
comment|/// setIsExact - Set or clear the exact flag on this instruction,
comment|/// which must be an operator which supports this flag. See LangRef.html
comment|/// for the meaning of this flag.
name|void
name|setIsExact
argument_list|(
argument|bool b = true
argument_list|)
block|;
comment|/// hasNoUnsignedWrap - Determine whether the no unsigned wrap flag is set.
name|bool
name|hasNoUnsignedWrap
argument_list|()
specifier|const
block|;
comment|/// hasNoSignedWrap - Determine whether the no signed wrap flag is set.
name|bool
name|hasNoSignedWrap
argument_list|()
specifier|const
block|;
comment|/// isExact - Determine whether the exact flag is set.
name|bool
name|isExact
argument_list|()
specifier|const
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const BinaryOperator *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Instruction *I
argument_list|)
block|{
return|return
name|I
operator|->
name|isBinaryOp
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|isa
operator|<
name|Instruction
operator|>
operator|(
name|V
operator|)
operator|&&
name|classof
argument_list|(
name|cast
operator|<
name|Instruction
operator|>
operator|(
name|V
operator|)
argument_list|)
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|BinaryOperator
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
literal|2
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|BinaryOperator
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                               CastInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// CastInst - This is the base class for all instructions that perform data
comment|/// casts. It is simply provided so that instruction category testing
comment|/// can be performed with code like:
comment|///
comment|/// if (isa<CastInst>(Instr)) { ... }
comment|/// @brief Base class of casting instructions.
name|class
name|CastInst
operator|:
name|public
name|UnaryInstruction
block|{
name|protected
operator|:
comment|/// @brief Constructor with insert-before-instruction semantics for subclasses
name|CastInst
argument_list|(
argument|const Type *Ty
argument_list|,
argument|unsigned iType
argument_list|,
argument|Value *S
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
operator|:
name|UnaryInstruction
argument_list|(
argument|Ty
argument_list|,
argument|iType
argument_list|,
argument|S
argument_list|,
argument|InsertBefore
argument_list|)
block|{
name|setName
argument_list|(
name|NameStr
argument_list|)
block|;   }
comment|/// @brief Constructor with insert-at-end-of-block semantics for subclasses
name|CastInst
argument_list|(
argument|const Type *Ty
argument_list|,
argument|unsigned iType
argument_list|,
argument|Value *S
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
operator|:
name|UnaryInstruction
argument_list|(
argument|Ty
argument_list|,
argument|iType
argument_list|,
argument|S
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{
name|setName
argument_list|(
name|NameStr
argument_list|)
block|;   }
name|public
operator|:
comment|/// Provides a way to construct any of the CastInst subclasses using an
comment|/// opcode instead of the subclass's constructor. The opcode must be in the
comment|/// CastOps category (Instruction::isCast(opcode) returns true). This
comment|/// constructor has insert-before-instruction semantics to automatically
comment|/// insert the new CastInst before InsertBefore (if it is non-null).
comment|/// @brief Construct any of the CastInst subclasses
specifier|static
name|CastInst
operator|*
name|Create
argument_list|(
name|Instruction
operator|::
name|CastOps
argument_list|,
comment|///< The opcode of the cast instruction
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be casted (operand 0)
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to which cast should be made
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|,
comment|///< Name for the instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
literal|0
comment|///< Place to insert the instruction
argument_list|)
block|;
comment|/// Provides a way to construct any of the CastInst subclasses using an
comment|/// opcode instead of the subclass's constructor. The opcode must be in the
comment|/// CastOps category. This constructor has insert-at-end-of-block semantics
comment|/// to automatically insert the new CastInst at the end of InsertAtEnd (if
comment|/// its non-null).
comment|/// @brief Construct any of the CastInst subclasses
specifier|static
name|CastInst
operator|*
name|Create
argument_list|(
name|Instruction
operator|::
name|CastOps
argument_list|,
comment|///< The opcode for the cast instruction
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be casted (operand 0)
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to which operand is casted
specifier|const
name|Twine
operator|&
name|Name
argument_list|,
comment|///< The name for the instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// @brief Create a ZExt or BitCast cast instruction
specifier|static
name|CastInst
operator|*
name|CreateZExtOrBitCast
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be casted (operand 0)
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to which cast should be made
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|,
comment|///< Name for the instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
literal|0
comment|///< Place to insert the instruction
argument_list|)
block|;
comment|/// @brief Create a ZExt or BitCast cast instruction
specifier|static
name|CastInst
operator|*
name|CreateZExtOrBitCast
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be casted (operand 0)
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to which operand is casted
specifier|const
name|Twine
operator|&
name|Name
argument_list|,
comment|///< The name for the instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// @brief Create a SExt or BitCast cast instruction
specifier|static
name|CastInst
operator|*
name|CreateSExtOrBitCast
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be casted (operand 0)
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to which cast should be made
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|,
comment|///< Name for the instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
literal|0
comment|///< Place to insert the instruction
argument_list|)
block|;
comment|/// @brief Create a SExt or BitCast cast instruction
specifier|static
name|CastInst
operator|*
name|CreateSExtOrBitCast
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be casted (operand 0)
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to which operand is casted
specifier|const
name|Twine
operator|&
name|Name
argument_list|,
comment|///< The name for the instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// @brief Create a BitCast or a PtrToInt cast instruction
specifier|static
name|CastInst
operator|*
name|CreatePointerCast
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The pointer value to be casted (operand 0)
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to which operand is casted
specifier|const
name|Twine
operator|&
name|Name
argument_list|,
comment|///< The name for the instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// @brief Create a BitCast or a PtrToInt cast instruction
specifier|static
name|CastInst
operator|*
name|CreatePointerCast
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The pointer value to be casted (operand 0)
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to which cast should be made
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|,
comment|///< Name for the instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
literal|0
comment|///< Place to insert the instruction
argument_list|)
block|;
comment|/// @brief Create a ZExt, BitCast, or Trunc for int -> int casts.
specifier|static
name|CastInst
operator|*
name|CreateIntegerCast
argument_list|(
argument|Value *S
argument_list|,
comment|///< The pointer value to be casted (operand 0)
argument|const Type *Ty
argument_list|,
comment|///< The type to which cast should be made
argument|bool isSigned
argument_list|,
comment|///< Whether to regard S as signed or not
argument|const Twine&Name =
literal|""
argument_list|,
comment|///< Name for the instruction
argument|Instruction *InsertBefore =
literal|0
comment|///< Place to insert the instruction
argument_list|)
block|;
comment|/// @brief Create a ZExt, BitCast, or Trunc for int -> int casts.
specifier|static
name|CastInst
operator|*
name|CreateIntegerCast
argument_list|(
argument|Value *S
argument_list|,
comment|///< The integer value to be casted (operand 0)
argument|const Type *Ty
argument_list|,
comment|///< The integer type to which operand is casted
argument|bool isSigned
argument_list|,
comment|///< Whether to regard S as signed or not
argument|const Twine&Name
argument_list|,
comment|///< The name for the instruction
argument|BasicBlock *InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// @brief Create an FPExt, BitCast, or FPTrunc for fp -> fp casts
specifier|static
name|CastInst
operator|*
name|CreateFPCast
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The floating point value to be casted
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The floating point type to cast to
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|,
comment|///< Name for the instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
literal|0
comment|///< Place to insert the instruction
argument_list|)
block|;
comment|/// @brief Create an FPExt, BitCast, or FPTrunc for fp -> fp casts
specifier|static
name|CastInst
operator|*
name|CreateFPCast
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The floating point value to be casted
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The floating point type to cast to
specifier|const
name|Twine
operator|&
name|Name
argument_list|,
comment|///< The name for the instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// @brief Create a Trunc or BitCast cast instruction
specifier|static
name|CastInst
operator|*
name|CreateTruncOrBitCast
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be casted (operand 0)
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to which cast should be made
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|,
comment|///< Name for the instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
literal|0
comment|///< Place to insert the instruction
argument_list|)
block|;
comment|/// @brief Create a Trunc or BitCast cast instruction
specifier|static
name|CastInst
operator|*
name|CreateTruncOrBitCast
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be casted (operand 0)
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to which operand is casted
specifier|const
name|Twine
operator|&
name|Name
argument_list|,
comment|///< The name for the instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// @brief Check whether it is valid to call getCastOpcode for these types.
specifier|static
name|bool
name|isCastable
argument_list|(
specifier|const
name|Type
operator|*
name|SrcTy
argument_list|,
comment|///< The Type from which the value should be cast.
specifier|const
name|Type
operator|*
name|DestTy
comment|///< The Type to which the value should be cast.
argument_list|)
block|;
comment|/// Returns the opcode necessary to cast Val into Ty using usual casting
comment|/// rules.
comment|/// @brief Infer the opcode for cast operand and type
specifier|static
name|Instruction
operator|::
name|CastOps
name|getCastOpcode
argument_list|(
argument|const Value *Val
argument_list|,
comment|///< The value to cast
argument|bool SrcIsSigned
argument_list|,
comment|///< Whether to treat the source as signed
argument|const Type *Ty
argument_list|,
comment|///< The Type to which the value should be casted
argument|bool DstIsSigned
comment|///< Whether to treate the dest. as signed
argument_list|)
block|;
comment|/// There are several places where we need to know if a cast instruction
comment|/// only deals with integer source and destination types. To simplify that
comment|/// logic, this method is provided.
comment|/// @returns true iff the cast has only integral typed operand and dest type.
comment|/// @brief Determine if this is an integer-only cast.
name|bool
name|isIntegerCast
argument_list|()
specifier|const
block|;
comment|/// A lossless cast is one that does not alter the basic value. It implies
comment|/// a no-op cast but is more stringent, preventing things like int->float,
comment|/// long->double, int->ptr, or vector->anything.
comment|/// @returns true iff the cast is lossless.
comment|/// @brief Determine if this is a lossless cast.
name|bool
name|isLosslessCast
argument_list|()
specifier|const
block|;
comment|/// A no-op cast is one that can be effected without changing any bits.
comment|/// It implies that the source and destination types are the same size. The
comment|/// IntPtrTy argument is used to make accurate determinations for casts
comment|/// involving Integer and Pointer types. They are no-op casts if the integer
comment|/// is the same size as the pointer. However, pointer size varies with
comment|/// platform. Generally, the result of TargetData::getIntPtrType() should be
comment|/// passed in. If that's not available, use Type::Int64Ty, which will make
comment|/// the isNoopCast call conservative.
comment|/// @brief Determine if this cast is a no-op cast.
name|bool
name|isNoopCast
argument_list|(
argument|const Type *IntPtrTy
comment|///< Integer type corresponding to pointer
argument_list|)
specifier|const
block|;
comment|/// Determine how a pair of casts can be eliminated, if they can be at all.
comment|/// This is a helper function for both CastInst and ConstantExpr.
comment|/// @returns 0 if the CastInst pair can't be eliminated
comment|/// @returns Instruction::CastOps value for a cast that can replace
comment|/// the pair, casting SrcTy to DstTy.
comment|/// @brief Determine if a cast pair is eliminable
specifier|static
name|unsigned
name|isEliminableCastPair
argument_list|(
argument|Instruction::CastOps firstOpcode
argument_list|,
comment|///< Opcode of first cast
argument|Instruction::CastOps secondOpcode
argument_list|,
comment|///< Opcode of second cast
argument|const Type *SrcTy
argument_list|,
comment|///< SrcTy of 1st cast
argument|const Type *MidTy
argument_list|,
comment|///< DstTy of 1st cast& SrcTy of 2nd cast
argument|const Type *DstTy
argument_list|,
comment|///< DstTy of 2nd cast
argument|const Type *IntPtrTy
comment|///< Integer type corresponding to Ptr types, or null
argument_list|)
block|;
comment|/// @brief Return the opcode of this CastInst
name|Instruction
operator|::
name|CastOps
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|Instruction
operator|::
name|CastOps
argument_list|(
name|Instruction
operator|::
name|getOpcode
argument_list|()
argument_list|)
return|;
block|}
comment|/// @brief Return the source type, as a convenience
specifier|const
name|Type
operator|*
name|getSrcTy
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|->
name|getType
argument_list|()
return|;
block|}
comment|/// @brief Return the destination type, as a convenience
specifier|const
name|Type
operator|*
name|getDestTy
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
return|;
block|}
comment|/// This method can be used to determine if a cast from S to DstTy using
comment|/// Opcode op is valid or not.
comment|/// @returns true iff the proposed cast is valid.
comment|/// @brief Determine if a cast is valid without creating one.
specifier|static
name|bool
name|castIsValid
argument_list|(
argument|Instruction::CastOps op
argument_list|,
argument|Value *S
argument_list|,
argument|const Type *DstTy
argument_list|)
block|;
comment|/// @brief Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const CastInst *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Instruction *I
argument_list|)
block|{
return|return
name|I
operator|->
name|isCast
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|isa
operator|<
name|Instruction
operator|>
operator|(
name|V
operator|)
operator|&&
name|classof
argument_list|(
name|cast
operator|<
name|Instruction
operator|>
operator|(
name|V
operator|)
argument_list|)
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|//                               CmpInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class is the base class for the comparison instructions.
comment|/// @brief Abstract base class of comparison instructions.
comment|// FIXME: why not derive from BinaryOperator?
name|class
name|CmpInst
operator|:
name|public
name|Instruction
block|{
name|void
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|,
name|unsigned
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|CmpInst
argument_list|()
block|;
comment|// do not implement
name|protected
operator|:
name|CmpInst
argument_list|(
argument|const Type *ty
argument_list|,
argument|Instruction::OtherOps op
argument_list|,
argument|unsigned short pred
argument_list|,
argument|Value *LHS
argument_list|,
argument|Value *RHS
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|;
name|CmpInst
argument_list|(
argument|const Type *ty
argument_list|,
argument|Instruction::OtherOps op
argument_list|,
argument|unsigned short pred
argument_list|,
argument|Value *LHS
argument_list|,
argument|Value *RHS
argument_list|,
argument|const Twine&Name
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|public
operator|:
comment|/// This enumeration lists the possible predicates for CmpInst subclasses.
comment|/// Values in the range 0-31 are reserved for FCmpInst, while values in the
comment|/// range 32-64 are reserved for ICmpInst. This is necessary to ensure the
comment|/// predicate values are not overlapping between the classes.
expr|enum
name|Predicate
block|{
comment|// Opcode             U L G E    Intuitive operation
name|FCMP_FALSE
operator|=
literal|0
block|,
comment|/// 0 0 0 0    Always false (always folded)
name|FCMP_OEQ
operator|=
literal|1
block|,
comment|/// 0 0 0 1    True if ordered and equal
name|FCMP_OGT
operator|=
literal|2
block|,
comment|/// 0 0 1 0    True if ordered and greater than
name|FCMP_OGE
operator|=
literal|3
block|,
comment|/// 0 0 1 1    True if ordered and greater than or equal
name|FCMP_OLT
operator|=
literal|4
block|,
comment|/// 0 1 0 0    True if ordered and less than
name|FCMP_OLE
operator|=
literal|5
block|,
comment|/// 0 1 0 1    True if ordered and less than or equal
name|FCMP_ONE
operator|=
literal|6
block|,
comment|/// 0 1 1 0    True if ordered and operands are unequal
name|FCMP_ORD
operator|=
literal|7
block|,
comment|/// 0 1 1 1    True if ordered (no nans)
name|FCMP_UNO
operator|=
literal|8
block|,
comment|/// 1 0 0 0    True if unordered: isnan(X) | isnan(Y)
name|FCMP_UEQ
operator|=
literal|9
block|,
comment|/// 1 0 0 1    True if unordered or equal
name|FCMP_UGT
operator|=
literal|10
block|,
comment|/// 1 0 1 0    True if unordered or greater than
name|FCMP_UGE
operator|=
literal|11
block|,
comment|/// 1 0 1 1    True if unordered, greater than, or equal
name|FCMP_ULT
operator|=
literal|12
block|,
comment|/// 1 1 0 0    True if unordered or less than
name|FCMP_ULE
operator|=
literal|13
block|,
comment|/// 1 1 0 1    True if unordered, less than, or equal
name|FCMP_UNE
operator|=
literal|14
block|,
comment|/// 1 1 1 0    True if unordered or not equal
name|FCMP_TRUE
operator|=
literal|15
block|,
comment|/// 1 1 1 1    Always true (always folded)
name|FIRST_FCMP_PREDICATE
operator|=
name|FCMP_FALSE
block|,
name|LAST_FCMP_PREDICATE
operator|=
name|FCMP_TRUE
block|,
name|BAD_FCMP_PREDICATE
operator|=
name|FCMP_TRUE
operator|+
literal|1
block|,
name|ICMP_EQ
operator|=
literal|32
block|,
comment|/// equal
name|ICMP_NE
operator|=
literal|33
block|,
comment|/// not equal
name|ICMP_UGT
operator|=
literal|34
block|,
comment|/// unsigned greater than
name|ICMP_UGE
operator|=
literal|35
block|,
comment|/// unsigned greater or equal
name|ICMP_ULT
operator|=
literal|36
block|,
comment|/// unsigned less than
name|ICMP_ULE
operator|=
literal|37
block|,
comment|/// unsigned less or equal
name|ICMP_SGT
operator|=
literal|38
block|,
comment|/// signed greater than
name|ICMP_SGE
operator|=
literal|39
block|,
comment|/// signed greater or equal
name|ICMP_SLT
operator|=
literal|40
block|,
comment|/// signed less than
name|ICMP_SLE
operator|=
literal|41
block|,
comment|/// signed less or equal
name|FIRST_ICMP_PREDICATE
operator|=
name|ICMP_EQ
block|,
name|LAST_ICMP_PREDICATE
operator|=
name|ICMP_SLE
block|,
name|BAD_ICMP_PREDICATE
operator|=
name|ICMP_SLE
operator|+
literal|1
block|}
block|;
comment|// allocate space for exactly two operands
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|,
literal|2
argument_list|)
return|;
block|}
comment|/// Construct a compare instruction, given the opcode, the predicate and
comment|/// the two operands.  Optionally (if InstBefore is specified) insert the
comment|/// instruction into a BasicBlock right before the specified instruction.
comment|/// The specified Instruction is allowed to be a dereferenced end iterator.
comment|/// @brief Create a CmpInst
specifier|static
name|CmpInst
operator|*
name|Create
argument_list|(
argument|OtherOps Op
argument_list|,
argument|unsigned short predicate
argument_list|,
argument|Value *S1
argument_list|,
argument|Value *S2
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|;
comment|/// Construct a compare instruction, given the opcode, the predicate and the
comment|/// two operands.  Also automatically insert this instruction to the end of
comment|/// the BasicBlock specified.
comment|/// @brief Create a CmpInst
specifier|static
name|CmpInst
operator|*
name|Create
argument_list|(
argument|OtherOps Op
argument_list|,
argument|unsigned short predicate
argument_list|,
argument|Value *S1
argument_list|,
argument|Value *S2
argument_list|,
argument|const Twine&Name
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
comment|/// @brief Get the opcode casted to the right type
name|OtherOps
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|OtherOps
operator|>
operator|(
name|Instruction
operator|::
name|getOpcode
argument_list|()
operator|)
return|;
block|}
comment|/// @brief Return the predicate for this instruction.
name|Predicate
name|getPredicate
argument_list|()
specifier|const
block|{
return|return
name|Predicate
argument_list|(
name|getSubclassDataFromInstruction
argument_list|()
argument_list|)
return|;
block|}
comment|/// @brief Set the predicate for this instruction to the specified value.
name|void
name|setPredicate
argument_list|(
argument|Predicate P
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
name|P
argument_list|)
block|; }
specifier|static
name|bool
name|isFPPredicate
argument_list|(
argument|Predicate P
argument_list|)
block|{
return|return
name|P
operator|>=
name|FIRST_FCMP_PREDICATE
operator|&&
name|P
operator|<=
name|LAST_FCMP_PREDICATE
return|;
block|}
specifier|static
name|bool
name|isIntPredicate
argument_list|(
argument|Predicate P
argument_list|)
block|{
return|return
name|P
operator|>=
name|FIRST_ICMP_PREDICATE
operator|&&
name|P
operator|<=
name|LAST_ICMP_PREDICATE
return|;
block|}
name|bool
name|isFPPredicate
argument_list|()
specifier|const
block|{
return|return
name|isFPPredicate
argument_list|(
name|getPredicate
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|isIntPredicate
argument_list|()
specifier|const
block|{
return|return
name|isIntPredicate
argument_list|(
name|getPredicate
argument_list|()
argument_list|)
return|;
block|}
comment|/// For example, EQ -> NE, UGT -> ULE, SLT -> SGE,
comment|///              OEQ -> UNE, UGT -> OLE, OLT -> UGE, etc.
comment|/// @returns the inverse predicate for the instruction's current predicate.
comment|/// @brief Return the inverse of the instruction's predicate.
name|Predicate
name|getInversePredicate
argument_list|()
specifier|const
block|{
return|return
name|getInversePredicate
argument_list|(
name|getPredicate
argument_list|()
argument_list|)
return|;
block|}
comment|/// For example, EQ -> NE, UGT -> ULE, SLT -> SGE,
comment|///              OEQ -> UNE, UGT -> OLE, OLT -> UGE, etc.
comment|/// @returns the inverse predicate for predicate provided in \p pred.
comment|/// @brief Return the inverse of a given predicate
specifier|static
name|Predicate
name|getInversePredicate
argument_list|(
argument|Predicate pred
argument_list|)
block|;
comment|/// For example, EQ->EQ, SLE->SGE, ULT->UGT,
comment|///              OEQ->OEQ, ULE->UGE, OLT->OGT, etc.
comment|/// @returns the predicate that would be the result of exchanging the two
comment|/// operands of the CmpInst instruction without changing the result
comment|/// produced.
comment|/// @brief Return the predicate as if the operands were swapped
name|Predicate
name|getSwappedPredicate
argument_list|()
specifier|const
block|{
return|return
name|getSwappedPredicate
argument_list|(
name|getPredicate
argument_list|()
argument_list|)
return|;
block|}
comment|/// This is a static version that you can use without an instruction
comment|/// available.
comment|/// @brief Return the predicate as if the operands were swapped.
specifier|static
name|Predicate
name|getSwappedPredicate
argument_list|(
argument|Predicate pred
argument_list|)
block|;
comment|/// @brief Provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|/// This is just a convenience that dispatches to the subclasses.
comment|/// @brief Swap the operands and adjust predicate accordingly to retain
comment|/// the same comparison.
name|void
name|swapOperands
argument_list|()
block|;
comment|/// This is just a convenience that dispatches to the subclasses.
comment|/// @brief Determine if this CmpInst is commutative.
name|bool
name|isCommutative
argument_list|()
block|;
comment|/// This is just a convenience that dispatches to the subclasses.
comment|/// @brief Determine if this is an equals/not equals predicate.
name|bool
name|isEquality
argument_list|()
block|;
comment|/// @returns true if the comparison is signed, false otherwise.
comment|/// @brief Determine if this instruction is using a signed comparison.
name|bool
name|isSigned
argument_list|()
specifier|const
block|{
return|return
name|isSigned
argument_list|(
name|getPredicate
argument_list|()
argument_list|)
return|;
block|}
comment|/// @returns true if the comparison is unsigned, false otherwise.
comment|/// @brief Determine if this instruction is using an unsigned comparison.
name|bool
name|isUnsigned
argument_list|()
specifier|const
block|{
return|return
name|isUnsigned
argument_list|(
name|getPredicate
argument_list|()
argument_list|)
return|;
block|}
comment|/// This is just a convenience.
comment|/// @brief Determine if this is true when both operands are the same.
name|bool
name|isTrueWhenEqual
argument_list|()
specifier|const
block|{
return|return
name|isTrueWhenEqual
argument_list|(
name|getPredicate
argument_list|()
argument_list|)
return|;
block|}
comment|/// This is just a convenience.
comment|/// @brief Determine if this is false when both operands are the same.
name|bool
name|isFalseWhenEqual
argument_list|()
specifier|const
block|{
return|return
name|isFalseWhenEqual
argument_list|(
name|getPredicate
argument_list|()
argument_list|)
return|;
block|}
comment|/// @returns true if the predicate is unsigned, false otherwise.
comment|/// @brief Determine if the predicate is an unsigned operation.
specifier|static
name|bool
name|isUnsigned
argument_list|(
argument|unsigned short predicate
argument_list|)
block|;
comment|/// @returns true if the predicate is signed, false otherwise.
comment|/// @brief Determine if the predicate is an signed operation.
specifier|static
name|bool
name|isSigned
argument_list|(
argument|unsigned short predicate
argument_list|)
block|;
comment|/// @brief Determine if the predicate is an ordered operation.
specifier|static
name|bool
name|isOrdered
argument_list|(
argument|unsigned short predicate
argument_list|)
block|;
comment|/// @brief Determine if the predicate is an unordered operation.
specifier|static
name|bool
name|isUnordered
argument_list|(
argument|unsigned short predicate
argument_list|)
block|;
comment|/// Determine if the predicate is true when comparing a value with itself.
specifier|static
name|bool
name|isTrueWhenEqual
argument_list|(
argument|unsigned short predicate
argument_list|)
block|;
comment|/// Determine if the predicate is false when comparing a value with itself.
specifier|static
name|bool
name|isFalseWhenEqual
argument_list|(
argument|unsigned short predicate
argument_list|)
block|;
comment|/// @brief Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const CmpInst *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Instruction *I
argument_list|)
block|{
return|return
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|ICmp
operator|||
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|FCmp
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|isa
operator|<
name|Instruction
operator|>
operator|(
name|V
operator|)
operator|&&
name|classof
argument_list|(
name|cast
operator|<
name|Instruction
operator|>
operator|(
name|V
operator|)
argument_list|)
return|;
block|}
comment|/// @brief Create a result type for fcmp/icmp
specifier|static
specifier|const
name|Type
operator|*
name|makeCmpResultType
argument_list|(
argument|const Type* opnd_type
argument_list|)
block|{
if|if
condition|(
specifier|const
name|VectorType
modifier|*
name|vt
init|=
name|dyn_cast
operator|<
specifier|const
name|VectorType
operator|>
operator|(
name|opnd_type
operator|)
condition|)
block|{
return|return
name|VectorType
operator|::
name|get
argument_list|(
name|Type
operator|::
name|getInt1Ty
argument_list|(
name|opnd_type
operator|->
name|getContext
argument_list|()
argument_list|)
argument_list|,
name|vt
operator|->
name|getNumElements
argument_list|()
argument_list|)
return|;
block|}
return|return
name|Type
operator|::
name|getInt1Ty
argument_list|(
name|opnd_type
operator|->
name|getContext
argument_list|()
argument_list|)
return|;
block|}
name|private
operator|:
comment|// Shadow Value::setValueSubclassData with a private forwarding method so that
comment|// subclasses cannot accidentally use it.
name|void
name|setValueSubclassData
argument_list|(
argument|unsigned short D
argument_list|)
block|{
name|Value
operator|::
name|setValueSubclassData
argument_list|(
name|D
argument_list|)
block|;   }
expr|}
block|;
comment|// FIXME: these are redundant if CmpInst< BinaryOperator
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|CmpInst
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
literal|2
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|CmpInst
argument_list|,
argument|Value
argument_list|)
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

