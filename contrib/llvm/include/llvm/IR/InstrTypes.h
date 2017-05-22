begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/InstrTypes.h - Important Instruction subclasses -----*- C++ -*-===//
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
name|LLVM_IR_INSTRTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_INSTRTYPES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
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
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Attributes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DerivedTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instruction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/LLVMContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/OperandTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Type.h"
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
file|"llvm/Support/ErrorHandling.h"
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
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===----------------------------------------------------------------------===//
comment|//                            TerminatorInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// Subclasses of this class are all able to terminate a basic
comment|/// block. Thus, these are all the flow control type of operations.
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
argument|Type *Ty
argument_list|,
argument|Instruction::TermOps iType
argument_list|,
argument|Use *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|Instruction *InsertBefore = nullptr
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
argument|Type *Ty
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
name|public
operator|:
comment|/// Return the number of successors that this terminator has.
name|unsigned
name|getNumSuccessors
argument_list|()
specifier|const
block|;
comment|/// Return the specified successor.
name|BasicBlock
operator|*
name|getSuccessor
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|;
comment|/// Update the specified successor to point at the provided block.
name|void
name|setSuccessor
argument_list|(
argument|unsigned idx
argument_list|,
argument|BasicBlock *B
argument_list|)
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
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
comment|// \brief Returns true if this terminator relates to exception handling.
name|bool
name|isExceptional
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
name|CatchRet
case|:
case|case
name|Instruction
operator|::
name|CleanupRet
case|:
case|case
name|Instruction
operator|::
name|Invoke
case|:
case|case
name|Instruction
operator|::
name|Resume
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
comment|//===--------------------------------------------------------------------===//
comment|// succ_iterator definition
comment|//===--------------------------------------------------------------------===//
name|template
operator|<
name|class
name|Term
block|,
name|class
name|BB
operator|>
comment|// Successor Iterator
name|class
name|SuccIterator
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|random_access_iterator_tag
block|,
name|BB
block|,
name|int
block|,
name|BB
operator|*
block|,
name|BB
operator|*
operator|>
block|{
name|using
name|super
operator|=
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|random_access_iterator_tag
block|,
name|BB
block|,
name|int
block|,
name|BB
operator|*
block|,
name|BB
operator|*
operator|>
block|;
name|public
operator|:
name|using
name|pointer
operator|=
name|typename
name|super
operator|::
name|pointer
block|;
name|using
name|reference
operator|=
name|typename
name|super
operator|::
name|reference
block|;
name|private
operator|:
name|Term
name|TermInst
block|;
name|unsigned
name|idx
block|;
name|using
name|Self
operator|=
name|SuccIterator
operator|<
name|Term
block|,
name|BB
operator|>
block|;
specifier|inline
name|bool
name|index_is_valid
argument_list|(
argument|unsigned idx
argument_list|)
block|{
return|return
name|idx
operator|<
name|TermInst
operator|->
name|getNumSuccessors
argument_list|()
return|;
block|}
comment|/// \brief Proxy object to allow write access in operator[]
name|class
name|SuccessorProxy
block|{
name|Self
name|it
block|;
name|public
operator|:
name|explicit
name|SuccessorProxy
argument_list|(
specifier|const
name|Self
operator|&
name|it
argument_list|)
operator|:
name|it
argument_list|(
argument|it
argument_list|)
block|{}
name|SuccessorProxy
argument_list|(
specifier|const
name|SuccessorProxy
operator|&
argument_list|)
operator|=
expr|default
block|;
name|SuccessorProxy
operator|&
name|operator
operator|=
operator|(
name|SuccessorProxy
name|r
operator|)
block|{
operator|*
name|this
operator|=
name|reference
argument_list|(
name|r
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|SuccessorProxy
operator|&
name|operator
operator|=
operator|(
name|reference
name|r
operator|)
block|{
name|it
operator|.
name|TermInst
operator|->
name|setSuccessor
argument_list|(
name|it
operator|.
name|idx
argument_list|,
name|r
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|operator
name|reference
argument_list|()
specifier|const
block|{
return|return
operator|*
name|it
return|;
block|}
expr|}
block|;
name|public
operator|:
comment|// begin iterator
name|explicit
specifier|inline
name|SuccIterator
argument_list|(
argument|Term T
argument_list|)
operator|:
name|TermInst
argument_list|(
name|T
argument_list|)
block|,
name|idx
argument_list|(
literal|0
argument_list|)
block|{}
comment|// end iterator
specifier|inline
name|SuccIterator
argument_list|(
argument|Term T
argument_list|,
argument|bool
argument_list|)
operator|:
name|TermInst
argument_list|(
argument|T
argument_list|)
block|{
if|if
condition|(
name|TermInst
condition|)
name|idx
operator|=
name|TermInst
operator|->
name|getNumSuccessors
argument_list|()
expr_stmt|;
else|else
comment|// Term == NULL happens, if a basic block is not fully constructed and
comment|// consequently getTerminator() returns NULL. In this case we construct
comment|// a SuccIterator which describes a basic block that has zero
comment|// successors.
comment|// Defining SuccIterator for incomplete and malformed CFGs is especially
comment|// useful for debugging.
name|idx
operator|=
literal|0
expr_stmt|;
block|}
comment|/// This is used to interface between code that wants to
comment|/// operate on terminator instructions directly.
name|unsigned
name|getSuccessorIndex
argument_list|()
specifier|const
block|{
return|return
name|idx
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Self
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|idx
operator|==
name|x
operator|.
name|idx
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Self
operator|&
name|x
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|x
operator|)
return|;
block|}
specifier|inline
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|TermInst
operator|->
name|getSuccessor
argument_list|(
name|idx
argument_list|)
return|;
block|}
specifier|inline
name|pointer
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
name|operator
operator|*
operator|(
operator|)
return|;
block|}
specifier|inline
name|Self
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|idx
block|;
return|return
operator|*
name|this
return|;
block|}
comment|// Preincrement
specifier|inline
name|Self
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|Self
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
specifier|inline
name|Self
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
operator|--
name|idx
block|;
return|return
operator|*
name|this
return|;
block|}
comment|// Predecrement
specifier|inline
name|Self
name|operator
operator|--
operator|(
name|int
operator|)
block|{
comment|// Postdecrement
name|Self
name|tmp
operator|=
operator|*
name|this
block|;
operator|--
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Self
operator|&
name|x
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|TermInst
operator|==
name|x
operator|.
name|TermInst
operator|&&
literal|"Cannot compare iterators of different blocks!"
argument_list|)
block|;
return|return
name|idx
operator|<
name|x
operator|.
name|idx
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|Self
operator|&
name|x
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|TermInst
operator|==
name|x
operator|.
name|TermInst
operator|&&
literal|"Cannot compare iterators of different blocks!"
argument_list|)
block|;
return|return
name|idx
operator|<=
name|x
operator|.
name|idx
return|;
block|}
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|Self
operator|&
name|x
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|TermInst
operator|==
name|x
operator|.
name|TermInst
operator|&&
literal|"Cannot compare iterators of different blocks!"
argument_list|)
block|;
return|return
name|idx
operator|>=
name|x
operator|.
name|idx
return|;
block|}
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|Self
operator|&
name|x
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|TermInst
operator|==
name|x
operator|.
name|TermInst
operator|&&
literal|"Cannot compare iterators of different blocks!"
argument_list|)
block|;
return|return
name|idx
operator|>
name|x
operator|.
name|idx
return|;
block|}
specifier|inline
name|Self
operator|&
name|operator
operator|+=
operator|(
name|int
name|Right
operator|)
block|{
name|unsigned
name|new_idx
operator|=
name|idx
operator|+
name|Right
block|;
name|assert
argument_list|(
name|index_is_valid
argument_list|(
name|new_idx
argument_list|)
operator|&&
literal|"Iterator index out of bound"
argument_list|)
block|;
name|idx
operator|=
name|new_idx
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|Self
name|operator
operator|+
operator|(
name|int
name|Right
operator|)
specifier|const
block|{
name|Self
name|tmp
operator|=
operator|*
name|this
block|;
name|tmp
operator|+=
name|Right
block|;
return|return
name|tmp
return|;
block|}
specifier|inline
name|Self
operator|&
name|operator
operator|-=
operator|(
name|int
name|Right
operator|)
block|{
return|return
name|operator
operator|+=
operator|(
operator|-
name|Right
operator|)
return|;
block|}
specifier|inline
name|Self
name|operator
operator|-
operator|(
name|int
name|Right
operator|)
specifier|const
block|{
return|return
name|operator
operator|+
operator|(
operator|-
name|Right
operator|)
return|;
block|}
specifier|inline
name|int
name|operator
operator|-
operator|(
specifier|const
name|Self
operator|&
name|x
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|TermInst
operator|==
name|x
operator|.
name|TermInst
operator|&&
literal|"Cannot work on iterators of different blocks!"
argument_list|)
block|;
name|int
name|distance
operator|=
name|idx
operator|-
name|x
operator|.
name|idx
block|;
return|return
name|distance
return|;
block|}
specifier|inline
name|SuccessorProxy
name|operator
index|[]
operator|(
name|int
name|offset
operator|)
block|{
name|Self
name|tmp
operator|=
operator|*
name|this
block|;
name|tmp
operator|+=
name|offset
block|;
return|return
name|SuccessorProxy
argument_list|(
name|tmp
argument_list|)
return|;
block|}
comment|/// Get the source BB of this iterator.
specifier|inline
name|BB
operator|*
name|getSource
argument_list|()
block|{
name|assert
argument_list|(
name|TermInst
operator|&&
literal|"Source not available, if basic block was malformed"
argument_list|)
block|;
return|return
name|TermInst
operator|->
name|getParent
argument_list|()
return|;
block|}
expr|}
block|;
name|using
name|succ_iterator
operator|=
name|SuccIterator
operator|<
name|TerminatorInst
operator|*
block|,
name|BasicBlock
operator|>
block|;
name|using
name|succ_const_iterator
operator|=
name|SuccIterator
operator|<
specifier|const
name|TerminatorInst
operator|*
block|,
specifier|const
name|BasicBlock
operator|>
block|;
name|using
name|succ_range
operator|=
name|iterator_range
operator|<
name|succ_iterator
operator|>
block|;
name|using
name|succ_const_range
operator|=
name|iterator_range
operator|<
name|succ_const_iterator
operator|>
block|;
name|private
operator|:
specifier|inline
name|succ_iterator
name|succ_begin
argument_list|()
block|{
return|return
name|succ_iterator
argument_list|(
name|this
argument_list|)
return|;
block|}
specifier|inline
name|succ_const_iterator
name|succ_begin
argument_list|()
specifier|const
block|{
return|return
name|succ_const_iterator
argument_list|(
name|this
argument_list|)
return|;
block|}
specifier|inline
name|succ_iterator
name|succ_end
argument_list|()
block|{
return|return
name|succ_iterator
argument_list|(
name|this
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|inline
name|succ_const_iterator
name|succ_end
argument_list|()
specifier|const
block|{
return|return
name|succ_const_iterator
argument_list|(
name|this
argument_list|,
name|true
argument_list|)
return|;
block|}
name|public
operator|:
specifier|inline
name|succ_range
name|successors
argument_list|()
block|{
return|return
name|succ_range
argument_list|(
name|succ_begin
argument_list|()
argument_list|,
name|succ_end
argument_list|()
argument_list|)
return|;
block|}
specifier|inline
name|succ_const_range
name|successors
argument_list|()
specifier|const
block|{
return|return
name|succ_const_range
argument_list|(
name|succ_begin
argument_list|()
argument_list|,
name|succ_end
argument_list|()
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
name|protected
operator|:
name|UnaryInstruction
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned iType
argument_list|,
argument|Value *V
argument_list|,
argument|Instruction *IB = nullptr
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
argument|Type *Ty
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
name|void
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|,
name|unsigned
argument_list|)
operator|=
name|delete
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
name|UnaryInstruction
block|,
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
name|protected
operator|:
name|BinaryOperator
argument_list|(
argument|BinaryOps iType
argument_list|,
argument|Value *S1
argument_list|,
argument|Value *S2
argument_list|,
argument|Type *Ty
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
argument|Type *Ty
argument_list|,
argument|const Twine&Name
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|void
name|init
argument_list|(
argument|BinaryOps iType
argument_list|)
block|;
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|BinaryOperator
operator|*
name|cloneImpl
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
name|void
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|,
name|unsigned
argument_list|)
operator|=
name|delete
block|;
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|/// Construct a binary instruction, given the opcode and the two
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
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
comment|/// Construct a binary instruction, given the opcode and the two
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
comment|/// These methods just forward to Create, and are useful when you
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
file|"llvm/IR/Instruction.def"
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
file|"llvm/IR/Instruction.def"
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
file|"llvm/IR/Instruction.def"
specifier|static
name|BinaryOperator
operator|*
name|CreateWithCopiedFlags
argument_list|(
argument|BinaryOps Opc
argument_list|,
argument|Value *V1
argument_list|,
argument|Value *V2
argument_list|,
argument|BinaryOperator *CopyBO
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|)
block|{
name|BinaryOperator
operator|*
name|BO
operator|=
name|Create
argument_list|(
name|Opc
argument_list|,
name|V1
argument_list|,
name|V2
argument_list|,
name|Name
argument_list|)
block|;
name|BO
operator|->
name|copyIRFlags
argument_list|(
name|CopyBO
argument_list|)
block|;
return|return
name|BO
return|;
block|}
specifier|static
name|BinaryOperator
operator|*
name|CreateNSW
argument_list|(
argument|BinaryOps Opc
argument_list|,
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
name|Create
argument_list|(
name|Opc
argument_list|,
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
name|CreateNSW
argument_list|(
argument|BinaryOps Opc
argument_list|,
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
name|Create
argument_list|(
name|Opc
argument_list|,
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
name|CreateNSW
argument_list|(
argument|BinaryOps Opc
argument_list|,
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
name|Create
argument_list|(
name|Opc
argument_list|,
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
specifier|static
name|BinaryOperator
operator|*
name|CreateNUW
argument_list|(
argument|BinaryOps Opc
argument_list|,
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
name|Create
argument_list|(
name|Opc
argument_list|,
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
name|CreateNUW
argument_list|(
argument|BinaryOps Opc
argument_list|,
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
name|Create
argument_list|(
name|Opc
argument_list|,
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
name|CreateNUW
argument_list|(
argument|BinaryOps Opc
argument_list|,
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
name|Create
argument_list|(
name|Opc
argument_list|,
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
specifier|static
name|BinaryOperator
operator|*
name|CreateExact
argument_list|(
argument|BinaryOps Opc
argument_list|,
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
name|Create
argument_list|(
name|Opc
argument_list|,
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
name|CreateExact
argument_list|(
argument|BinaryOps Opc
argument_list|,
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
name|Create
argument_list|(
name|Opc
argument_list|,
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
name|CreateExact
argument_list|(
argument|BinaryOps Opc
argument_list|,
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
name|Create
argument_list|(
name|Opc
argument_list|,
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
define|#
directive|define
name|DEFINE_HELPERS
parameter_list|(
name|OPC
parameter_list|,
name|NUWNSWEXACT
parameter_list|)
define|\
value|static BinaryOperator *Create##NUWNSWEXACT##OPC(Value *V1, Value *V2,        \                                                   const Twine&Name = "") {    \     return Create##NUWNSWEXACT(Instruction::OPC, V1, V2, Name);                \   }                                                                            \   static BinaryOperator *Create##NUWNSWEXACT##OPC(                             \       Value *V1, Value *V2, const Twine&Name, BasicBlock *BB) {               \     return Create##NUWNSWEXACT(Instruction::OPC, V1, V2, Name, BB);            \   }                                                                            \   static BinaryOperator *Create##NUWNSWEXACT##OPC(                             \       Value *V1, Value *V2, const Twine&Name, Instruction *I) {               \     return Create##NUWNSWEXACT(Instruction::OPC, V1, V2, Name, I);             \   }
name|DEFINE_HELPERS
argument_list|(
argument|Add
argument_list|,
argument|NSW
argument_list|)
comment|// CreateNSWAdd
name|DEFINE_HELPERS
argument_list|(
argument|Add
argument_list|,
argument|NUW
argument_list|)
comment|// CreateNUWAdd
name|DEFINE_HELPERS
argument_list|(
argument|Sub
argument_list|,
argument|NSW
argument_list|)
comment|// CreateNSWSub
name|DEFINE_HELPERS
argument_list|(
argument|Sub
argument_list|,
argument|NUW
argument_list|)
comment|// CreateNUWSub
name|DEFINE_HELPERS
argument_list|(
argument|Mul
argument_list|,
argument|NSW
argument_list|)
comment|// CreateNSWMul
name|DEFINE_HELPERS
argument_list|(
argument|Mul
argument_list|,
argument|NUW
argument_list|)
comment|// CreateNUWMul
name|DEFINE_HELPERS
argument_list|(
argument|Shl
argument_list|,
argument|NSW
argument_list|)
comment|// CreateNSWShl
name|DEFINE_HELPERS
argument_list|(
argument|Shl
argument_list|,
argument|NUW
argument_list|)
comment|// CreateNUWShl
name|DEFINE_HELPERS
argument_list|(
argument|SDiv
argument_list|,
argument|Exact
argument_list|)
comment|// CreateExactSDiv
name|DEFINE_HELPERS
argument_list|(
argument|UDiv
argument_list|,
argument|Exact
argument_list|)
comment|// CreateExactUDiv
name|DEFINE_HELPERS
argument_list|(
argument|AShr
argument_list|,
argument|Exact
argument_list|)
comment|// CreateExactAShr
name|DEFINE_HELPERS
argument_list|(
argument|LShr
argument_list|,
argument|Exact
argument_list|)
comment|// CreateExactLShr
undef|#
directive|undef
name|DEFINE_HELPERS
comment|/// Helper functions to construct and inspect unary operations (NEG and NOT)
comment|/// via binary operators SUB and XOR:
comment|///
comment|/// Create the NEG and NOT instructions out of SUB and XOR instructions.
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
name|nullptr
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
name|nullptr
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
name|CreateNUWNeg
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
name|nullptr
argument_list|)
block|;
specifier|static
name|BinaryOperator
operator|*
name|CreateNUWNeg
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
name|nullptr
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
name|nullptr
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
comment|/// Check if the given Value is a NEG, FNeg, or NOT instruction.
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
argument|const Value *V
argument_list|,
argument|bool IgnoreZeroSign=false
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
comment|/// Helper functions to extract the unary argument of a NEG, FNEG or NOT
comment|/// operation implemented via Sub, FSub, or Xor.
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
comment|/// Exchange the two operands to this instruction.
comment|/// This instruction is safe to use on any binary instruction and
comment|/// does not modify the semantics of the instruction.  If the instruction
comment|/// cannot be reversed (ie, it's a Div), then return true.
comment|///
name|bool
name|swapOperands
argument_list|()
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|BinaryOperator
block|,
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
comment|/// This is the base class for all instructions that perform data
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
argument|Type *Ty
argument_list|,
argument|unsigned iType
argument_list|,
argument|Value *S
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
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
argument|Type *Ty
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
name|nullptr
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
name|nullptr
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
name|nullptr
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
comment|/// @brief Create a BitCast AddrSpaceCast, or a PtrToInt cast instruction.
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
comment|/// @brief Create a BitCast, AddrSpaceCast or a PtrToInt cast instruction.
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
name|nullptr
comment|///< Place to insert the instruction
argument_list|)
block|;
comment|/// @brief Create a BitCast or an AddrSpaceCast cast instruction.
specifier|static
name|CastInst
operator|*
name|CreatePointerBitCastOrAddrSpaceCast
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The pointer value to be casted (operand 0)
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
comment|/// @brief Create a BitCast or an AddrSpaceCast cast instruction.
specifier|static
name|CastInst
operator|*
name|CreatePointerBitCastOrAddrSpaceCast
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The pointer value to be casted (operand 0)
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
name|nullptr
comment|///< Place to insert the instruction
argument_list|)
block|;
comment|/// @brief Create a BitCast, a PtrToInt, or an IntToPTr cast instruction.
comment|///
comment|/// If the value is a pointer type and the destination an integer type,
comment|/// creates a PtrToInt cast. If the value is an integer type and the
comment|/// destination a pointer type, creates an IntToPtr cast. Otherwise, creates
comment|/// a bitcast.
specifier|static
name|CastInst
operator|*
name|CreateBitOrPointerCast
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The pointer value to be casted (operand 0)
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
name|nullptr
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
argument|Type *Ty
argument_list|,
comment|///< The type to which cast should be made
argument|bool isSigned
argument_list|,
comment|///< Whether to regard S as signed or not
argument|const Twine&Name =
literal|""
argument_list|,
comment|///< Name for the instruction
argument|Instruction *InsertBefore = nullptr
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
argument|Type *Ty
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
name|nullptr
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
name|nullptr
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
name|Type
operator|*
name|SrcTy
argument_list|,
comment|///< The Type from which the value should be cast.
name|Type
operator|*
name|DestTy
comment|///< The Type to which the value should be cast.
argument_list|)
block|;
comment|/// @brief Check whether a bitcast between these types is valid
specifier|static
name|bool
name|isBitCastable
argument_list|(
name|Type
operator|*
name|SrcTy
argument_list|,
comment|///< The Type from which the value should be cast.
name|Type
operator|*
name|DestTy
comment|///< The Type to which the value should be cast.
argument_list|)
block|;
comment|/// @brief Check whether a bitcast, inttoptr, or ptrtoint cast between these
comment|/// types is valid and a no-op.
comment|///
comment|/// This ensures that any pointer<->integer cast has enough bits in the
comment|/// integer and any other cast is a bitcast.
specifier|static
name|bool
name|isBitOrNoopPointerCastable
argument_list|(
name|Type
operator|*
name|SrcTy
argument_list|,
comment|///< The Type from which the value should be cast.
name|Type
operator|*
name|DestTy
argument_list|,
comment|///< The Type to which the value should be cast.
specifier|const
name|DataLayout
operator|&
name|DL
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
argument|Type *Ty
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
comment|/// long->double, or int->ptr.
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
comment|/// platform. Generally, the result of DataLayout::getIntPtrType() should be
comment|/// passed in. If that's not available, use Type::Int64Ty, which will make
comment|/// the isNoopCast call conservative.
comment|/// @brief Determine if the described cast is a no-op cast.
specifier|static
name|bool
name|isNoopCast
argument_list|(
argument|Instruction::CastOps Opcode
argument_list|,
comment|///< Opcode of cast
argument|Type *SrcTy
argument_list|,
comment|///< SrcTy of cast
argument|Type *DstTy
argument_list|,
comment|///< DstTy of cast
argument|Type *IntPtrTy
comment|///< Integer type corresponding to Ptr types
argument_list|)
block|;
comment|/// @brief Determine if this cast is a no-op cast.
name|bool
name|isNoopCast
argument_list|(
argument|Type *IntPtrTy
comment|///< Integer type corresponding to pointer
argument_list|)
specifier|const
block|;
comment|/// @brief Determine if this cast is a no-op cast.
comment|///
comment|/// \param DL is the DataLayout to get the Int Ptr type from.
name|bool
name|isNoopCast
argument_list|(
argument|const DataLayout&DL
argument_list|)
specifier|const
block|;
comment|/// Determine how a pair of casts can be eliminated, if they can be at all.
comment|/// This is a helper function for both CastInst and ConstantExpr.
comment|/// @returns 0 if the CastInst pair can't be eliminated, otherwise
comment|/// returns Instruction::CastOps value for a cast that can replace
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
argument|Type *SrcTy
argument_list|,
comment|///< SrcTy of 1st cast
argument|Type *MidTy
argument_list|,
comment|///< DstTy of 1st cast& SrcTy of 2nd cast
argument|Type *DstTy
argument_list|,
comment|///< DstTy of 2nd cast
argument|Type *SrcIntPtrTy
argument_list|,
comment|///< Integer type corresponding to Ptr SrcTy, or null
argument|Type *MidIntPtrTy
argument_list|,
comment|///< Integer type corresponding to Ptr MidTy, or null
argument|Type *DstIntPtrTy
comment|///< Integer type corresponding to Ptr DstTy, or null
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
argument|Type *DstTy
argument_list|)
block|;
comment|/// @brief Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|class
name|CmpInst
operator|:
name|public
name|Instruction
block|{
name|public
operator|:
comment|/// This enumeration lists the possible predicates for CmpInst subclasses.
comment|/// Values in the range 0-31 are reserved for FCmpInst, while values in the
comment|/// range 32-64 are reserved for ICmpInst. This is necessary to ensure the
comment|/// predicate values are not overlapping between the classes.
comment|///
comment|/// Some passes (e.g. InstCombine) depend on the bit-wise characteristics of
comment|/// FCMP_* values. Changing the bit patterns requires a potential change to
comment|/// those passes.
expr|enum
name|Predicate
block|{
comment|// Opcode              U L G E    Intuitive operation
name|FCMP_FALSE
operator|=
literal|0
block|,
comment|///< 0 0 0 0    Always false (always folded)
name|FCMP_OEQ
operator|=
literal|1
block|,
comment|///< 0 0 0 1    True if ordered and equal
name|FCMP_OGT
operator|=
literal|2
block|,
comment|///< 0 0 1 0    True if ordered and greater than
name|FCMP_OGE
operator|=
literal|3
block|,
comment|///< 0 0 1 1    True if ordered and greater than or equal
name|FCMP_OLT
operator|=
literal|4
block|,
comment|///< 0 1 0 0    True if ordered and less than
name|FCMP_OLE
operator|=
literal|5
block|,
comment|///< 0 1 0 1    True if ordered and less than or equal
name|FCMP_ONE
operator|=
literal|6
block|,
comment|///< 0 1 1 0    True if ordered and operands are unequal
name|FCMP_ORD
operator|=
literal|7
block|,
comment|///< 0 1 1 1    True if ordered (no nans)
name|FCMP_UNO
operator|=
literal|8
block|,
comment|///< 1 0 0 0    True if unordered: isnan(X) | isnan(Y)
name|FCMP_UEQ
operator|=
literal|9
block|,
comment|///< 1 0 0 1    True if unordered or equal
name|FCMP_UGT
operator|=
literal|10
block|,
comment|///< 1 0 1 0    True if unordered or greater than
name|FCMP_UGE
operator|=
literal|11
block|,
comment|///< 1 0 1 1    True if unordered, greater than, or equal
name|FCMP_ULT
operator|=
literal|12
block|,
comment|///< 1 1 0 0    True if unordered or less than
name|FCMP_ULE
operator|=
literal|13
block|,
comment|///< 1 1 0 1    True if unordered, less than, or equal
name|FCMP_UNE
operator|=
literal|14
block|,
comment|///< 1 1 1 0    True if unordered or not equal
name|FCMP_TRUE
operator|=
literal|15
block|,
comment|///< 1 1 1 1    Always true (always folded)
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
comment|///< equal
name|ICMP_NE
operator|=
literal|33
block|,
comment|///< not equal
name|ICMP_UGT
operator|=
literal|34
block|,
comment|///< unsigned greater than
name|ICMP_UGE
operator|=
literal|35
block|,
comment|///< unsigned greater or equal
name|ICMP_ULT
operator|=
literal|36
block|,
comment|///< unsigned less than
name|ICMP_ULE
operator|=
literal|37
block|,
comment|///< unsigned less or equal
name|ICMP_SGT
operator|=
literal|38
block|,
comment|///< signed greater than
name|ICMP_SGE
operator|=
literal|39
block|,
comment|///< signed greater or equal
name|ICMP_SLT
operator|=
literal|40
block|,
comment|///< signed less than
name|ICMP_SLE
operator|=
literal|41
block|,
comment|///< signed less or equal
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
name|protected
operator|:
name|CmpInst
argument_list|(
argument|Type *ty
argument_list|,
argument|Instruction::OtherOps op
argument_list|,
argument|Predicate pred
argument_list|,
argument|Value *LHS
argument_list|,
argument|Value *RHS
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|CmpInst
argument_list|(
argument|Type *ty
argument_list|,
argument|Instruction::OtherOps op
argument_list|,
argument|Predicate pred
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
name|CmpInst
argument_list|()
operator|=
name|delete
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
name|void
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|,
name|unsigned
argument_list|)
operator|=
name|delete
block|;
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
argument|Predicate predicate
argument_list|,
argument|Value *S1
argument_list|,
argument|Value *S2
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
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
argument|Predicate predicate
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
specifier|static
name|StringRef
name|getPredicateName
argument_list|(
argument|Predicate P
argument_list|)
block|;
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
specifier|const
block|;
comment|/// This is just a convenience that dispatches to the subclasses.
comment|/// @brief Determine if this is an equals/not equals predicate.
name|bool
name|isEquality
argument_list|()
specifier|const
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
comment|/// For example, ULT->SLT, ULE->SLE, UGT->SGT, UGE->SGE, SLT->Failed assert
comment|/// @returns the signed version of the unsigned predicate pred.
comment|/// @brief return the signed version of a predicate
specifier|static
name|Predicate
name|getSignedPredicate
argument_list|(
argument|Predicate pred
argument_list|)
block|;
comment|/// For example, ULT->SLT, ULE->SLE, UGT->SGT, UGE->SGE, SLT->Failed assert
comment|/// @returns the signed version of the predicate for this instruction (which
comment|/// has to be an unsigned predicate).
comment|/// @brief return the signed version of a predicate
name|Predicate
name|getSignedPredicate
argument_list|()
block|{
return|return
name|getSignedPredicate
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
argument|Predicate predicate
argument_list|)
block|;
comment|/// @returns true if the predicate is signed, false otherwise.
comment|/// @brief Determine if the predicate is an signed operation.
specifier|static
name|bool
name|isSigned
argument_list|(
argument|Predicate predicate
argument_list|)
block|;
comment|/// @brief Determine if the predicate is an ordered operation.
specifier|static
name|bool
name|isOrdered
argument_list|(
argument|Predicate predicate
argument_list|)
block|;
comment|/// @brief Determine if the predicate is an unordered operation.
specifier|static
name|bool
name|isUnordered
argument_list|(
argument|Predicate predicate
argument_list|)
block|;
comment|/// Determine if the predicate is true when comparing a value with itself.
specifier|static
name|bool
name|isTrueWhenEqual
argument_list|(
argument|Predicate predicate
argument_list|)
block|;
comment|/// Determine if the predicate is false when comparing a value with itself.
specifier|static
name|bool
name|isFalseWhenEqual
argument_list|(
argument|Predicate predicate
argument_list|)
block|;
comment|/// Determine if Pred1 implies Pred2 is true when two compares have matching
comment|/// operands.
specifier|static
name|bool
name|isImpliedTrueByMatchingCmp
argument_list|(
argument|Predicate Pred1
argument_list|,
argument|Predicate Pred2
argument_list|)
block|;
comment|/// Determine if Pred1 implies Pred2 is false when two compares have matching
comment|/// operands.
specifier|static
name|bool
name|isImpliedFalseByMatchingCmp
argument_list|(
argument|Predicate Pred1
argument_list|,
argument|Predicate Pred2
argument_list|)
block|;
comment|/// @brief Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|Type
operator|*
name|makeCmpResultType
argument_list|(
argument|Type* opnd_type
argument_list|)
block|{
if|if
condition|(
name|VectorType
modifier|*
name|vt
init|=
name|dyn_cast
operator|<
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
name|CmpInst
block|,
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
comment|//===----------------------------------------------------------------------===//
comment|//                           FuncletPadInst Class
comment|//===----------------------------------------------------------------------===//
name|class
name|FuncletPadInst
operator|:
name|public
name|Instruction
block|{
name|private
operator|:
name|FuncletPadInst
argument_list|(
specifier|const
name|FuncletPadInst
operator|&
name|CPI
argument_list|)
block|;
name|explicit
name|FuncletPadInst
argument_list|(
argument|Instruction::FuncletPadOps Op
argument_list|,
argument|Value *ParentPad
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
block|;
name|explicit
name|FuncletPadInst
argument_list|(
argument|Instruction::FuncletPadOps Op
argument_list|,
argument|Value *ParentPad
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|void
name|init
argument_list|(
name|Value
operator|*
name|ParentPad
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Args
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|)
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|friend
name|class
name|CatchPadInst
block|;
name|friend
name|class
name|CleanupPadInst
block|;
name|FuncletPadInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|/// getNumArgOperands - Return the number of funcletpad arguments.
comment|///
name|unsigned
name|getNumArgOperands
argument_list|()
specifier|const
block|{
return|return
name|getNumOperands
argument_list|()
operator|-
literal|1
return|;
block|}
comment|/// Convenience accessors
comment|/// \brief Return the outer EH-pad this funclet is nested within.
comment|///
comment|/// Note: This returns the associated CatchSwitchInst if this FuncletPadInst
comment|/// is a CatchPadInst.
name|Value
operator|*
name|getParentPad
argument_list|()
specifier|const
block|{
return|return
name|Op
operator|<
operator|-
literal|1
operator|>
operator|(
operator|)
return|;
block|}
name|void
name|setParentPad
argument_list|(
argument|Value *ParentPad
argument_list|)
block|{
name|assert
argument_list|(
name|ParentPad
argument_list|)
block|;
name|Op
operator|<
operator|-
literal|1
operator|>
operator|(
operator|)
operator|=
name|ParentPad
block|;   }
comment|/// getArgOperand/setArgOperand - Return/set the i-th funcletpad argument.
comment|///
name|Value
operator|*
name|getArgOperand
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|getOperand
argument_list|(
name|i
argument_list|)
return|;
block|}
name|void
name|setArgOperand
argument_list|(
argument|unsigned i
argument_list|,
argument|Value *v
argument_list|)
block|{
name|setOperand
argument_list|(
name|i
argument_list|,
name|v
argument_list|)
block|; }
comment|/// arg_operands - iteration adapter for range-for loops.
name|op_range
name|arg_operands
argument_list|()
block|{
return|return
name|op_range
argument_list|(
name|op_begin
argument_list|()
argument_list|,
name|op_end
argument_list|()
operator|-
literal|1
argument_list|)
return|;
block|}
comment|/// arg_operands - iteration adapter for range-for loops.
name|const_op_range
name|arg_operands
argument_list|()
specifier|const
block|{
return|return
name|const_op_range
argument_list|(
name|op_begin
argument_list|()
argument_list|,
name|op_end
argument_list|()
operator|-
literal|1
argument_list|)
return|;
block|}
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|isFuncletPad
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
name|FuncletPadInst
operator|>
operator|:
name|public
name|VariadicOperandTraits
operator|<
name|FuncletPadInst
block|,
comment|/*MINARITY=*/
literal|1
operator|>
block|{}
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|FuncletPadInst
argument_list|,
argument|Value
argument_list|)
comment|/// \brief A lightweight accessor for an operand bundle meant to be passed
comment|/// around by value.
block|struct
name|OperandBundleUse
block|{
name|ArrayRef
operator|<
name|Use
operator|>
name|Inputs
block|;
name|OperandBundleUse
argument_list|()
operator|=
expr|default
block|;
name|explicit
name|OperandBundleUse
argument_list|(
name|StringMapEntry
operator|<
name|uint32_t
operator|>
operator|*
name|Tag
argument_list|,
name|ArrayRef
operator|<
name|Use
operator|>
name|Inputs
argument_list|)
operator|:
name|Inputs
argument_list|(
name|Inputs
argument_list|)
block|,
name|Tag
argument_list|(
argument|Tag
argument_list|)
block|{}
comment|/// \brief Return true if the operand at index \p Idx in this operand bundle
comment|/// has the attribute A.
name|bool
name|operandHasAttr
argument_list|(
argument|unsigned Idx
argument_list|,
argument|Attribute::AttrKind A
argument_list|)
specifier|const
block|{
if|if
condition|(
name|isDeoptOperandBundle
argument_list|()
condition|)
if|if
condition|(
name|A
operator|==
name|Attribute
operator|::
name|ReadOnly
operator|||
name|A
operator|==
name|Attribute
operator|::
name|NoCapture
condition|)
return|return
name|Inputs
index|[
name|Idx
index|]
operator|->
name|getType
argument_list|()
operator|->
name|isPointerTy
argument_list|()
return|;
comment|// Conservative answer:  no operands have any attributes.
return|return
name|false
return|;
block|}
comment|/// \brief Return the tag of this operand bundle as a string.
name|StringRef
name|getTagName
argument_list|()
specifier|const
block|{
return|return
name|Tag
operator|->
name|getKey
argument_list|()
return|;
block|}
comment|/// \brief Return the tag of this operand bundle as an integer.
comment|///
comment|/// Operand bundle tags are interned by LLVMContextImpl::getOrInsertBundleTag,
comment|/// and this function returns the unique integer getOrInsertBundleTag
comment|/// associated the tag of this operand bundle to.
name|uint32_t
name|getTagID
argument_list|()
specifier|const
block|{
return|return
name|Tag
operator|->
name|getValue
argument_list|()
return|;
block|}
comment|/// \brief Return true if this is a "deopt" operand bundle.
name|bool
name|isDeoptOperandBundle
argument_list|()
specifier|const
block|{
return|return
name|getTagID
argument_list|()
operator|==
name|LLVMContext
operator|::
name|OB_deopt
return|;
block|}
comment|/// \brief Return true if this is a "funclet" operand bundle.
name|bool
name|isFuncletOperandBundle
argument_list|()
specifier|const
block|{
return|return
name|getTagID
argument_list|()
operator|==
name|LLVMContext
operator|::
name|OB_funclet
return|;
block|}
name|private
operator|:
comment|/// \brief Pointer to an entry in LLVMContextImpl::getOrInsertBundleTag.
name|StringMapEntry
operator|<
name|uint32_t
operator|>
operator|*
name|Tag
block|; }
block|;
comment|/// \brief A container for an operand bundle being viewed as a set of values
comment|/// rather than a set of uses.
comment|///
comment|/// Unlike OperandBundleUse, OperandBundleDefT owns the memory it carries, and
comment|/// so it is possible to create and pass around "self-contained" instances of
comment|/// OperandBundleDef and ConstOperandBundleDef.
name|template
operator|<
name|typename
name|InputTy
operator|>
name|class
name|OperandBundleDefT
block|{
name|std
operator|::
name|string
name|Tag
block|;
name|std
operator|::
name|vector
operator|<
name|InputTy
operator|>
name|Inputs
block|;
name|public
operator|:
name|explicit
name|OperandBundleDefT
argument_list|(
argument|std::string Tag
argument_list|,
argument|std::vector<InputTy> Inputs
argument_list|)
operator|:
name|Tag
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Tag
argument_list|)
argument_list|)
block|,
name|Inputs
argument_list|(
argument|std::move(Inputs)
argument_list|)
block|{}
name|explicit
name|OperandBundleDefT
argument_list|(
argument|std::string Tag
argument_list|,
argument|ArrayRef<InputTy> Inputs
argument_list|)
operator|:
name|Tag
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Tag
argument_list|)
argument_list|)
block|,
name|Inputs
argument_list|(
argument|Inputs
argument_list|)
block|{}
name|explicit
name|OperandBundleDefT
argument_list|(
argument|const OperandBundleUse&OBU
argument_list|)
block|{
name|Tag
operator|=
name|OBU
operator|.
name|getTagName
argument_list|()
block|;
name|Inputs
operator|.
name|insert
argument_list|(
name|Inputs
operator|.
name|end
argument_list|()
argument_list|,
name|OBU
operator|.
name|Inputs
operator|.
name|begin
argument_list|()
argument_list|,
name|OBU
operator|.
name|Inputs
operator|.
name|end
argument_list|()
argument_list|)
block|;   }
name|ArrayRef
operator|<
name|InputTy
operator|>
name|inputs
argument_list|()
specifier|const
block|{
return|return
name|Inputs
return|;
block|}
name|using
name|input_iterator
operator|=
name|typename
name|std
operator|::
name|vector
operator|<
name|InputTy
operator|>
operator|::
name|const_iterator
block|;
name|size_t
name|input_size
argument_list|()
specifier|const
block|{
return|return
name|Inputs
operator|.
name|size
argument_list|()
return|;
block|}
name|input_iterator
name|input_begin
argument_list|()
specifier|const
block|{
return|return
name|Inputs
operator|.
name|begin
argument_list|()
return|;
block|}
name|input_iterator
name|input_end
argument_list|()
specifier|const
block|{
return|return
name|Inputs
operator|.
name|end
argument_list|()
return|;
block|}
name|StringRef
name|getTag
argument_list|()
specifier|const
block|{
return|return
name|Tag
return|;
block|}
expr|}
block|;
name|using
name|OperandBundleDef
operator|=
name|OperandBundleDefT
operator|<
name|Value
operator|*
operator|>
block|;
name|using
name|ConstOperandBundleDef
operator|=
name|OperandBundleDefT
operator|<
specifier|const
name|Value
operator|*
operator|>
block|;
comment|/// \brief A mixin to add operand bundle functionality to llvm instruction
comment|/// classes.
comment|///
comment|/// OperandBundleUser uses the descriptor area co-allocated with the host User
comment|/// to store some meta information about which operands are "normal" operands,
comment|/// and which ones belong to some operand bundle.
comment|///
comment|/// The layout of an operand bundle user is
comment|///
comment|///          +-----------uint32_t End-------------------------------------+
comment|///          |                                                            |
comment|///          |  +--------uint32_t Begin--------------------+              |
comment|///          |  |                                          |              |
comment|///          ^  ^                                          v              v
comment|///  |------|------|----|----|----|----|----|---------|----|---------|----|-----
comment|///  | BOI0 | BOI1 | .. | DU | U0 | U1 | .. | BOI0_U0 | .. | BOI1_U0 | .. | Un
comment|///  |------|------|----|----|----|----|----|---------|----|---------|----|-----
comment|///   v  v                                  ^              ^
comment|///   |  |                                  |              |
comment|///   |  +--------uint32_t Begin------------+              |
comment|///   |                                                    |
comment|///   +-----------uint32_t End-----------------------------+
comment|///
comment|///
comment|/// BOI0, BOI1 ... are descriptions of operand bundles in this User's use list.
comment|/// These descriptions are installed and managed by this class, and they're all
comment|/// instances of OperandBundleUser<T>::BundleOpInfo.
comment|///
comment|/// DU is an additional descriptor installed by User's 'operator new' to keep
comment|/// track of the 'BOI0 ... BOIN' co-allocation.  OperandBundleUser does not
comment|/// access or modify DU in any way, it's an implementation detail private to
comment|/// User.
comment|///
comment|/// The regular Use& vector for the User starts at U0.  The operand bundle uses
comment|/// are part of the Use& vector, just like normal uses.  In the diagram above,
comment|/// the operand bundle uses start at BOI0_U0.  Each instance of BundleOpInfo has
comment|/// information about a contiguous set of uses constituting an operand bundle,
comment|/// and the total set of operand bundle uses themselves form a contiguous set of
comment|/// uses (i.e. there are no gaps between uses corresponding to individual
comment|/// operand bundles).
comment|///
comment|/// This class does not know the location of the set of operand bundle uses
comment|/// within the use list -- that is decided by the User using this class via the
comment|/// BeginIdx argument in populateBundleOperandInfos.
comment|///
comment|/// Currently operand bundle users with hung-off operands are not supported.
name|template
operator|<
name|typename
name|InstrTy
block|,
name|typename
name|OpIteratorTy
operator|>
name|class
name|OperandBundleUser
block|{
name|public
operator|:
comment|/// \brief Return the number of operand bundles associated with this User.
name|unsigned
name|getNumOperandBundles
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|distance
argument_list|(
name|bundle_op_info_begin
argument_list|()
argument_list|,
name|bundle_op_info_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Return true if this User has any operand bundles.
name|bool
name|hasOperandBundles
argument_list|()
specifier|const
block|{
return|return
name|getNumOperandBundles
argument_list|()
operator|!=
literal|0
return|;
block|}
comment|/// \brief Return the index of the first bundle operand in the Use array.
name|unsigned
name|getBundleOperandsStartIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasOperandBundles
argument_list|()
operator|&&
literal|"Don't call otherwise!"
argument_list|)
block|;
return|return
name|bundle_op_info_begin
argument_list|()
operator|->
name|Begin
return|;
block|}
comment|/// \brief Return the index of the last bundle operand in the Use array.
name|unsigned
name|getBundleOperandsEndIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasOperandBundles
argument_list|()
operator|&&
literal|"Don't call otherwise!"
argument_list|)
block|;
return|return
name|bundle_op_info_end
argument_list|()
index|[
operator|-
literal|1
index|]
operator|.
name|End
return|;
block|}
comment|/// Return true if the operand at index \p Idx is a bundle operand.
name|bool
name|isBundleOperand
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
return|return
name|hasOperandBundles
argument_list|()
operator|&&
name|Idx
operator|>=
name|getBundleOperandsStartIndex
argument_list|()
operator|&&
name|Idx
operator|<
name|getBundleOperandsEndIndex
argument_list|()
return|;
block|}
comment|/// \brief Return the total number operands (not operand bundles) used by
comment|/// every operand bundle in this OperandBundleUser.
name|unsigned
name|getNumTotalBundleOperands
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|hasOperandBundles
argument_list|()
condition|)
return|return
literal|0
return|;
name|unsigned
name|Begin
operator|=
name|getBundleOperandsStartIndex
argument_list|()
block|;
name|unsigned
name|End
operator|=
name|getBundleOperandsEndIndex
argument_list|()
block|;
name|assert
argument_list|(
name|Begin
operator|<=
name|End
operator|&&
literal|"Should be!"
argument_list|)
block|;
return|return
name|End
operator|-
name|Begin
return|;
block|}
comment|/// \brief Return the operand bundle at a specific index.
name|OperandBundleUse
name|getOperandBundleAt
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Index
operator|<
name|getNumOperandBundles
argument_list|()
operator|&&
literal|"Index out of bounds!"
argument_list|)
block|;
return|return
name|operandBundleFromBundleOpInfo
argument_list|(
operator|*
operator|(
name|bundle_op_info_begin
argument_list|()
operator|+
name|Index
operator|)
argument_list|)
return|;
block|}
comment|/// \brief Return the number of operand bundles with the tag Name attached to
comment|/// this instruction.
name|unsigned
name|countOperandBundlesOfType
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|{
name|unsigned
name|Count
operator|=
literal|0
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|getNumOperandBundles
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|getOperandBundleAt
argument_list|(
name|i
argument_list|)
operator|.
name|getTagName
argument_list|()
operator|==
name|Name
condition|)
name|Count
operator|++
expr_stmt|;
return|return
name|Count
return|;
block|}
comment|/// \brief Return the number of operand bundles with the tag ID attached to
comment|/// this instruction.
name|unsigned
name|countOperandBundlesOfType
argument_list|(
argument|uint32_t ID
argument_list|)
specifier|const
block|{
name|unsigned
name|Count
operator|=
literal|0
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|getNumOperandBundles
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|getOperandBundleAt
argument_list|(
name|i
argument_list|)
operator|.
name|getTagID
argument_list|()
operator|==
name|ID
condition|)
name|Count
operator|++
expr_stmt|;
return|return
name|Count
return|;
block|}
comment|/// \brief Return an operand bundle by name, if present.
comment|///
comment|/// It is an error to call this for operand bundle types that may have
comment|/// multiple instances of them on the same instruction.
name|Optional
operator|<
name|OperandBundleUse
operator|>
name|getOperandBundle
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|countOperandBundlesOfType
argument_list|(
name|Name
argument_list|)
operator|<
literal|2
operator|&&
literal|"Precondition violated!"
argument_list|)
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|getNumOperandBundles
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
name|OperandBundleUse
name|U
init|=
name|getOperandBundleAt
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|U
operator|.
name|getTagName
argument_list|()
operator|==
name|Name
condition|)
return|return
name|U
return|;
block|}
return|return
name|None
return|;
block|}
comment|/// \brief Return an operand bundle by tag ID, if present.
comment|///
comment|/// It is an error to call this for operand bundle types that may have
comment|/// multiple instances of them on the same instruction.
name|Optional
operator|<
name|OperandBundleUse
operator|>
name|getOperandBundle
argument_list|(
argument|uint32_t ID
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|countOperandBundlesOfType
argument_list|(
name|ID
argument_list|)
operator|<
literal|2
operator|&&
literal|"Precondition violated!"
argument_list|)
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|getNumOperandBundles
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
name|OperandBundleUse
name|U
init|=
name|getOperandBundleAt
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|U
operator|.
name|getTagID
argument_list|()
operator|==
name|ID
condition|)
return|return
name|U
return|;
block|}
return|return
name|None
return|;
block|}
comment|/// \brief Return the list of operand bundles attached to this instruction as
comment|/// a vector of OperandBundleDefs.
comment|///
comment|/// This function copies the OperandBundeUse instances associated with this
comment|/// OperandBundleUser to a vector of OperandBundleDefs.  Note:
comment|/// OperandBundeUses and OperandBundleDefs are non-trivially *different*
comment|/// representations of operand bundles (see documentation above).
name|void
name|getOperandBundlesAsDefs
argument_list|(
argument|SmallVectorImpl<OperandBundleDef>&Defs
argument_list|)
specifier|const
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|getNumOperandBundles
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
name|Defs
operator|.
name|emplace_back
argument_list|(
name|getOperandBundleAt
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Return the operand bundle for the operand at index OpIdx.
comment|///
comment|/// It is an error to call this with an OpIdx that does not correspond to an
comment|/// bundle operand.
name|OperandBundleUse
name|getOperandBundleForOperand
argument_list|(
argument|unsigned OpIdx
argument_list|)
specifier|const
block|{
return|return
name|operandBundleFromBundleOpInfo
argument_list|(
name|getBundleOpInfoForOperand
argument_list|(
name|OpIdx
argument_list|)
argument_list|)
return|;
block|}
comment|/// \brief Return true if this operand bundle user has operand bundles that
comment|/// may read from the heap.
name|bool
name|hasReadingOperandBundles
argument_list|()
specifier|const
block|{
comment|// Implementation note: this is a conservative implementation of operand
comment|// bundle semantics, where *any* operand bundle forces a callsite to be at
comment|// least readonly.
return|return
name|hasOperandBundles
argument_list|()
return|;
block|}
comment|/// \brief Return true if this operand bundle user has operand bundles that
comment|/// may write to the heap.
name|bool
name|hasClobberingOperandBundles
argument_list|()
specifier|const
block|{
for|for
control|(
name|auto
operator|&
name|BOI
operator|:
name|bundle_op_infos
argument_list|()
control|)
block|{
if|if
condition|(
name|BOI
operator|.
name|Tag
operator|->
name|second
operator|==
name|LLVMContext
operator|::
name|OB_deopt
operator|||
name|BOI
operator|.
name|Tag
operator|->
name|second
operator|==
name|LLVMContext
operator|::
name|OB_funclet
condition|)
continue|continue;
comment|// This instruction has an operand bundle that is not known to us.
comment|// Assume the worst.
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|/// \brief Return true if the bundle operand at index \p OpIdx has the
comment|/// attribute \p A.
name|bool
name|bundleOperandHasAttr
argument_list|(
argument|unsigned OpIdx
argument_list|,
argument|Attribute::AttrKind A
argument_list|)
specifier|const
block|{
name|auto
operator|&
name|BOI
operator|=
name|getBundleOpInfoForOperand
argument_list|(
name|OpIdx
argument_list|)
block|;
name|auto
name|OBU
operator|=
name|operandBundleFromBundleOpInfo
argument_list|(
name|BOI
argument_list|)
block|;
return|return
name|OBU
operator|.
name|operandHasAttr
argument_list|(
name|OpIdx
operator|-
name|BOI
operator|.
name|Begin
argument_list|,
name|A
argument_list|)
return|;
block|}
comment|/// \brief Return true if \p Other has the same sequence of operand bundle
comment|/// tags with the same number of operands on each one of them as this
comment|/// OperandBundleUser.
name|bool
name|hasIdenticalOperandBundleSchema
argument_list|(
argument|const OperandBundleUser<InstrTy
argument_list|,
argument|OpIteratorTy>&Other
argument_list|)
specifier|const
block|{
if|if
condition|(
name|getNumOperandBundles
argument_list|()
operator|!=
name|Other
operator|.
name|getNumOperandBundles
argument_list|()
condition|)
return|return
name|false
return|;
return|return
name|std
operator|::
name|equal
argument_list|(
name|bundle_op_info_begin
argument_list|()
argument_list|,
name|bundle_op_info_end
argument_list|()
argument_list|,
name|Other
operator|.
name|bundle_op_info_begin
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Return true if this operand bundle user contains operand bundles
comment|/// with tags other than those specified in \p IDs.
name|bool
name|hasOperandBundlesOtherThan
argument_list|(
argument|ArrayRef<uint32_t> IDs
argument_list|)
specifier|const
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|getNumOperandBundles
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
name|uint32_t
name|ID
init|=
name|getOperandBundleAt
argument_list|(
name|i
argument_list|)
operator|.
name|getTagID
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|is_contained
argument_list|(
name|IDs
argument_list|,
name|ID
argument_list|)
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|protected
operator|:
comment|/// \brief Is the function attribute S disallowed by some operand bundle on
comment|/// this operand bundle user?
name|bool
name|isFnAttrDisallowedByOpBundle
argument_list|(
argument|StringRef S
argument_list|)
specifier|const
block|{
comment|// Operand bundles only possibly disallow readnone, readonly and argmenonly
comment|// attributes.  All String attributes are fine.
return|return
name|false
return|;
block|}
comment|/// \brief Is the function attribute A disallowed by some operand bundle on
comment|/// this operand bundle user?
name|bool
name|isFnAttrDisallowedByOpBundle
argument_list|(
argument|Attribute::AttrKind A
argument_list|)
specifier|const
block|{
switch|switch
condition|(
name|A
condition|)
block|{
default|default:
return|return
name|false
return|;
case|case
name|Attribute
operator|::
name|ArgMemOnly
case|:
return|return
name|hasReadingOperandBundles
argument_list|()
return|;
case|case
name|Attribute
operator|::
name|ReadNone
case|:
return|return
name|hasReadingOperandBundles
argument_list|()
return|;
case|case
name|Attribute
operator|::
name|ReadOnly
case|:
return|return
name|hasClobberingOperandBundles
argument_list|()
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"switch has a default case!"
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Used to keep track of an operand bundle.  See the main comment on
comment|/// OperandBundleUser above.
expr|struct
name|BundleOpInfo
block|{
comment|/// \brief The operand bundle tag, interned by
comment|/// LLVMContextImpl::getOrInsertBundleTag.
name|StringMapEntry
operator|<
name|uint32_t
operator|>
operator|*
name|Tag
block|;
comment|/// \brief The index in the Use& vector where operands for this operand
comment|/// bundle starts.
name|uint32_t
name|Begin
block|;
comment|/// \brief The index in the Use& vector where operands for this operand
comment|/// bundle ends.
name|uint32_t
name|End
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|BundleOpInfo
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Tag
operator|==
name|Other
operator|.
name|Tag
operator|&&
name|Begin
operator|==
name|Other
operator|.
name|Begin
operator|&&
name|End
operator|==
name|Other
operator|.
name|End
return|;
block|}
expr|}
block|;
comment|/// \brief Simple helper function to map a BundleOpInfo to an
comment|/// OperandBundleUse.
name|OperandBundleUse
name|operandBundleFromBundleOpInfo
argument_list|(
argument|const BundleOpInfo&BOI
argument_list|)
specifier|const
block|{
name|auto
name|op_begin
operator|=
name|static_cast
operator|<
specifier|const
name|InstrTy
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|op_begin
argument_list|()
block|;
name|ArrayRef
operator|<
name|Use
operator|>
name|Inputs
argument_list|(
name|op_begin
operator|+
name|BOI
operator|.
name|Begin
argument_list|,
name|op_begin
operator|+
name|BOI
operator|.
name|End
argument_list|)
block|;
return|return
name|OperandBundleUse
argument_list|(
name|BOI
operator|.
name|Tag
argument_list|,
name|Inputs
argument_list|)
return|;
block|}
name|using
name|bundle_op_iterator
operator|=
name|BundleOpInfo
operator|*
block|;
name|using
name|const_bundle_op_iterator
operator|=
specifier|const
name|BundleOpInfo
operator|*
block|;
comment|/// \brief Return the start of the list of BundleOpInfo instances associated
comment|/// with this OperandBundleUser.
name|bundle_op_iterator
name|bundle_op_info_begin
argument_list|()
block|{
if|if
condition|(
operator|!
name|static_cast
operator|<
name|InstrTy
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|hasDescriptor
argument_list|()
condition|)
return|return
name|nullptr
return|;
name|uint8_t
operator|*
name|BytesBegin
operator|=
name|static_cast
operator|<
name|InstrTy
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getDescriptor
argument_list|()
operator|.
name|begin
argument_list|()
block|;
return|return
name|reinterpret_cast
operator|<
name|bundle_op_iterator
operator|>
operator|(
name|BytesBegin
operator|)
return|;
block|}
comment|/// \brief Return the start of the list of BundleOpInfo instances associated
comment|/// with this OperandBundleUser.
name|const_bundle_op_iterator
name|bundle_op_info_begin
argument_list|()
specifier|const
block|{
name|auto
operator|*
name|NonConstThis
operator|=
name|const_cast
operator|<
name|OperandBundleUser
operator|<
name|InstrTy
block|,
name|OpIteratorTy
operator|>
operator|*
operator|>
operator|(
name|this
operator|)
block|;
return|return
name|NonConstThis
operator|->
name|bundle_op_info_begin
argument_list|()
return|;
block|}
comment|/// \brief Return the end of the list of BundleOpInfo instances associated
comment|/// with this OperandBundleUser.
name|bundle_op_iterator
name|bundle_op_info_end
argument_list|()
block|{
if|if
condition|(
operator|!
name|static_cast
operator|<
name|InstrTy
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|hasDescriptor
argument_list|()
condition|)
return|return
name|nullptr
return|;
name|uint8_t
operator|*
name|BytesEnd
operator|=
name|static_cast
operator|<
name|InstrTy
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getDescriptor
argument_list|()
operator|.
name|end
argument_list|()
block|;
return|return
name|reinterpret_cast
operator|<
name|bundle_op_iterator
operator|>
operator|(
name|BytesEnd
operator|)
return|;
block|}
comment|/// \brief Return the end of the list of BundleOpInfo instances associated
comment|/// with this OperandBundleUser.
name|const_bundle_op_iterator
name|bundle_op_info_end
argument_list|()
specifier|const
block|{
name|auto
operator|*
name|NonConstThis
operator|=
name|const_cast
operator|<
name|OperandBundleUser
operator|<
name|InstrTy
block|,
name|OpIteratorTy
operator|>
operator|*
operator|>
operator|(
name|this
operator|)
block|;
return|return
name|NonConstThis
operator|->
name|bundle_op_info_end
argument_list|()
return|;
block|}
comment|/// \brief Return the range [\p bundle_op_info_begin, \p bundle_op_info_end).
name|iterator_range
operator|<
name|bundle_op_iterator
operator|>
name|bundle_op_infos
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|bundle_op_info_begin
argument_list|()
argument_list|,
name|bundle_op_info_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Return the range [\p bundle_op_info_begin, \p bundle_op_info_end).
name|iterator_range
operator|<
name|const_bundle_op_iterator
operator|>
name|bundle_op_infos
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|bundle_op_info_begin
argument_list|()
argument_list|,
name|bundle_op_info_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Populate the BundleOpInfo instances and the Use& vector from \p
comment|/// Bundles.  Return the op_iterator pointing to the Use& one past the last
comment|/// last bundle operand use.
comment|///
comment|/// Each \p OperandBundleDef instance is tracked by a OperandBundleInfo
comment|/// instance allocated in this User's descriptor.
name|OpIteratorTy
name|populateBundleOperandInfos
argument_list|(
argument|ArrayRef<OperandBundleDef> Bundles
argument_list|,
argument|const unsigned BeginIndex
argument_list|)
block|{
name|auto
name|It
operator|=
name|static_cast
operator|<
name|InstrTy
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|op_begin
argument_list|()
operator|+
name|BeginIndex
block|;
for|for
control|(
name|auto
operator|&
name|B
operator|:
name|Bundles
control|)
name|It
operator|=
name|std
operator|::
name|copy
argument_list|(
name|B
operator|.
name|input_begin
argument_list|()
argument_list|,
name|B
operator|.
name|input_end
argument_list|()
argument_list|,
name|It
argument_list|)
expr_stmt|;
name|auto
operator|*
name|ContextImpl
operator|=
name|static_cast
operator|<
name|InstrTy
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getContext
argument_list|()
operator|.
name|pImpl
block|;
name|auto
name|BI
operator|=
name|Bundles
operator|.
name|begin
argument_list|()
block|;
name|unsigned
name|CurrentIndex
operator|=
name|BeginIndex
block|;
for|for
control|(
name|auto
operator|&
name|BOI
operator|:
name|bundle_op_infos
argument_list|()
control|)
block|{
name|assert
argument_list|(
name|BI
operator|!=
name|Bundles
operator|.
name|end
argument_list|()
operator|&&
literal|"Incorrect allocation?"
argument_list|)
expr_stmt|;
name|BOI
operator|.
name|Tag
operator|=
name|ContextImpl
operator|->
name|getOrInsertBundleTag
argument_list|(
name|BI
operator|->
name|getTag
argument_list|()
argument_list|)
expr_stmt|;
name|BOI
operator|.
name|Begin
operator|=
name|CurrentIndex
expr_stmt|;
name|BOI
operator|.
name|End
operator|=
name|CurrentIndex
operator|+
name|BI
operator|->
name|input_size
argument_list|()
expr_stmt|;
name|CurrentIndex
operator|=
name|BOI
operator|.
name|End
expr_stmt|;
name|BI
operator|++
expr_stmt|;
block|}
name|assert
argument_list|(
name|BI
operator|==
name|Bundles
operator|.
name|end
argument_list|()
operator|&&
literal|"Incorrect allocation?"
argument_list|)
expr_stmt|;
return|return
name|It
return|;
block|}
comment|/// \brief Return the BundleOpInfo for the operand at index OpIdx.
comment|///
comment|/// It is an error to call this with an OpIdx that does not correspond to an
comment|/// bundle operand.
specifier|const
name|BundleOpInfo
operator|&
name|getBundleOpInfoForOperand
argument_list|(
argument|unsigned OpIdx
argument_list|)
specifier|const
block|{
for|for
control|(
name|auto
operator|&
name|BOI
operator|:
name|bundle_op_infos
argument_list|()
control|)
if|if
condition|(
name|BOI
operator|.
name|Begin
operator|<=
name|OpIdx
operator|&&
name|OpIdx
operator|<
name|BOI
operator|.
name|End
condition|)
return|return
name|BOI
return|;
name|llvm_unreachable
argument_list|(
literal|"Did not find operand bundle for operand!"
argument_list|)
block|;   }
comment|/// \brief Return the total number of values used in \p Bundles.
specifier|static
name|unsigned
name|CountBundleInputs
argument_list|(
argument|ArrayRef<OperandBundleDef> Bundles
argument_list|)
block|{
name|unsigned
name|Total
operator|=
literal|0
block|;
for|for
control|(
name|auto
operator|&
name|B
operator|:
name|Bundles
control|)
name|Total
operator|+=
name|B
operator|.
name|input_size
argument_list|()
expr_stmt|;
return|return
name|Total
return|;
block|}
end_decl_stmt

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_INSTRTYPES_H
end_comment

end_unit

