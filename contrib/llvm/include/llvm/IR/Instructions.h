begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Instructions.h - Instruction subclass definitions ---*- C++ -*-===//
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
comment|// This file exposes the class definitions of all of the subclasses of the
end_comment

begin_comment
comment|// Instruction class.  This is meant to be an easy way to get access to all
end_comment

begin_comment
comment|// instruction subclasses.
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
name|LLVM_IR_INSTRUCTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_INSTRUCTIONS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator.h"
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
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
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
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Constant.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DerivedTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InstrTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instruction.h"
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
file|"llvm/IR/Use.h"
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
file|"llvm/Support/AtomicOrdering.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|APInt
decl_stmt|;
name|class
name|ConstantInt
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
enum|enum
name|SynchronizationScope
block|{
name|SingleThread
init|=
literal|0
block|,
name|CrossThread
init|=
literal|1
block|}
enum|;
comment|//===----------------------------------------------------------------------===//
comment|//                                AllocaInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// an instruction to allocate memory on the stack
name|class
name|AllocaInst
range|:
name|public
name|UnaryInstruction
block|{
name|Type
operator|*
name|AllocatedType
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|AllocaInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
name|explicit
name|AllocaInst
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned AddrSpace
argument_list|,
argument|Value *ArraySize = nullptr
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|AllocaInst
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned AddrSpace
argument_list|,
argument|Value *ArraySize
argument_list|,
argument|const Twine&Name
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|AllocaInst
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned AddrSpace
argument_list|,
argument|const Twine&Name
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|AllocaInst
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned AddrSpace
argument_list|,
argument|const Twine&Name
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|AllocaInst
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned AddrSpace
argument_list|,
argument|Value *ArraySize
argument_list|,
argument|unsigned Align
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|AllocaInst
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned AddrSpace
argument_list|,
argument|Value *ArraySize
argument_list|,
argument|unsigned Align
argument_list|,
argument|const Twine&Name
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
comment|/// Return true if there is an allocation size parameter to the allocation
comment|/// instruction that is not 1.
name|bool
name|isArrayAllocation
argument_list|()
specifier|const
block|;
comment|/// Get the number of elements allocated. For a simple allocation of a single
comment|/// element, this will return a constant 1 value.
specifier|const
name|Value
operator|*
name|getArraySize
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|Value
operator|*
name|getArraySize
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// Overload to return most specific pointer type.
name|PointerType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Instruction
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// Return the type that is being allocated by the instruction.
name|Type
operator|*
name|getAllocatedType
argument_list|()
specifier|const
block|{
return|return
name|AllocatedType
return|;
block|}
comment|/// for use only in special circumstances that need to generically
comment|/// transform a whole instruction (eg: IR linking and vectorization).
name|void
name|setAllocatedType
argument_list|(
argument|Type *Ty
argument_list|)
block|{
name|AllocatedType
operator|=
name|Ty
block|; }
comment|/// Return the alignment of the memory that is being allocated by the
comment|/// instruction.
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
operator|(
literal|1u
operator|<<
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|31
operator|)
operator|)
operator|>>
literal|1
return|;
block|}
name|void
name|setAlignment
argument_list|(
argument|unsigned Align
argument_list|)
block|;
comment|/// Return true if this alloca is in the entry block of the function and is a
comment|/// constant size. If so, the code generator will fold it into the
comment|/// prolog/epilog code, so it is basically free.
name|bool
name|isStaticAlloca
argument_list|()
specifier|const
block|;
comment|/// Return true if this alloca is used as an inalloca argument to a call. Such
comment|/// allocas are never considered static even if they are in the entry block.
name|bool
name|isUsedWithInAlloca
argument_list|()
specifier|const
block|{
return|return
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|32
return|;
block|}
comment|/// Specify whether this alloca is used to represent the arguments to a call.
name|void
name|setUsedWithInAlloca
argument_list|(
argument|bool V
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
literal|32
operator|)
operator||
operator|(
name|V
operator|?
literal|32
operator|:
literal|0
operator|)
argument_list|)
block|;   }
comment|/// Return true if this alloca is used as a swifterror argument to a call.
name|bool
name|isSwiftError
argument_list|()
specifier|const
block|{
return|return
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|64
return|;
block|}
comment|/// Specify whether this alloca is used to represent a swifterror.
name|void
name|setSwiftError
argument_list|(
argument|bool V
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
literal|64
operator|)
operator||
operator|(
name|V
condition|?
literal|64
else|:
literal|0
operator|)
argument_list|)
block|;   }
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
operator|(
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Alloca
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
name|private
operator|:
comment|// Shadow Instruction::setInstructionSubclassData with a private forwarding
comment|// method so that subclasses cannot accidentally use it.
name|void
name|setInstructionSubclassData
argument_list|(
argument|unsigned short D
argument_list|)
block|{
name|Instruction
operator|::
name|setInstructionSubclassData
argument_list|(
name|D
argument_list|)
block|;   }
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|//                                LoadInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// An instruction for reading from memory. This uses the SubclassData field in
comment|/// Value to store whether or not the load is volatile.
name|class
name|LoadInst
operator|:
name|public
name|UnaryInstruction
block|{
name|void
name|AssertOK
argument_list|()
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|LoadInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
name|LoadInst
argument_list|(
name|Value
operator|*
name|Ptr
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
block|;
name|LoadInst
argument_list|(
name|Value
operator|*
name|Ptr
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
name|LoadInst
argument_list|(
argument|Type *Ty
argument_list|,
argument|Value *Ptr
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|bool isVolatile = false
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|LoadInst
argument_list|(
argument|Value *Ptr
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|bool isVolatile = false
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
operator|:
name|LoadInst
argument_list|(
argument|cast<PointerType>(Ptr->getType())->getElementType()
argument_list|,
argument|Ptr
argument_list|,
argument|NameStr
argument_list|,
argument|isVolatile
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
name|LoadInst
argument_list|(
argument|Value *Ptr
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|bool isVolatile
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|LoadInst
argument_list|(
argument|Value *Ptr
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|bool isVolatile
argument_list|,
argument|unsigned Align
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
operator|:
name|LoadInst
argument_list|(
argument|cast<PointerType>(Ptr->getType())->getElementType()
argument_list|,
argument|Ptr
argument_list|,
argument|NameStr
argument_list|,
argument|isVolatile
argument_list|,
argument|Align
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
name|LoadInst
argument_list|(
argument|Type *Ty
argument_list|,
argument|Value *Ptr
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|bool isVolatile
argument_list|,
argument|unsigned Align
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|LoadInst
argument_list|(
argument|Value *Ptr
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|bool isVolatile
argument_list|,
argument|unsigned Align
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|LoadInst
argument_list|(
argument|Value *Ptr
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|bool isVolatile
argument_list|,
argument|unsigned Align
argument_list|,
argument|AtomicOrdering Order
argument_list|,
argument|SynchronizationScope SynchScope = CrossThread
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
operator|:
name|LoadInst
argument_list|(
argument|cast<PointerType>(Ptr->getType())->getElementType()
argument_list|,
argument|Ptr
argument_list|,
argument|NameStr
argument_list|,
argument|isVolatile
argument_list|,
argument|Align
argument_list|,
argument|Order
argument_list|,
argument|SynchScope
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
name|LoadInst
argument_list|(
argument|Type *Ty
argument_list|,
argument|Value *Ptr
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|bool isVolatile
argument_list|,
argument|unsigned Align
argument_list|,
argument|AtomicOrdering Order
argument_list|,
argument|SynchronizationScope SynchScope = CrossThread
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|LoadInst
argument_list|(
argument|Value *Ptr
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|bool isVolatile
argument_list|,
argument|unsigned Align
argument_list|,
argument|AtomicOrdering Order
argument_list|,
argument|SynchronizationScope SynchScope
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|LoadInst
argument_list|(
name|Value
operator|*
name|Ptr
argument_list|,
specifier|const
name|char
operator|*
name|NameStr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
block|;
name|LoadInst
argument_list|(
name|Value
operator|*
name|Ptr
argument_list|,
specifier|const
name|char
operator|*
name|NameStr
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
name|LoadInst
argument_list|(
argument|Type *Ty
argument_list|,
argument|Value *Ptr
argument_list|,
argument|const char *NameStr = nullptr
argument_list|,
argument|bool isVolatile = false
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|explicit
name|LoadInst
argument_list|(
argument|Value *Ptr
argument_list|,
argument|const char *NameStr = nullptr
argument_list|,
argument|bool isVolatile = false
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
operator|:
name|LoadInst
argument_list|(
argument|cast<PointerType>(Ptr->getType())->getElementType()
argument_list|,
argument|Ptr
argument_list|,
argument|NameStr
argument_list|,
argument|isVolatile
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
name|LoadInst
argument_list|(
argument|Value *Ptr
argument_list|,
argument|const char *NameStr
argument_list|,
argument|bool isVolatile
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
comment|/// Return true if this is a load from a volatile memory location.
name|bool
name|isVolatile
argument_list|()
specifier|const
block|{
return|return
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|1
return|;
block|}
comment|/// Specify whether this is a volatile load or not.
name|void
name|setVolatile
argument_list|(
argument|bool V
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
literal|1
operator|)
operator||
operator|(
name|V
condition|?
literal|1
else|:
literal|0
operator|)
argument_list|)
block|;   }
comment|/// Return the alignment of the access that is being performed.
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
operator|(
literal|1
operator|<<
operator|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|>>
literal|1
operator|)
operator|&
literal|31
operator|)
operator|)
operator|>>
literal|1
return|;
block|}
name|void
name|setAlignment
argument_list|(
argument|unsigned Align
argument_list|)
block|;
comment|/// Returns the ordering effect of this fence.
name|AtomicOrdering
name|getOrdering
argument_list|()
specifier|const
block|{
return|return
name|AtomicOrdering
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|>>
literal|7
operator|)
operator|&
literal|7
argument_list|)
return|;
block|}
comment|/// Set the ordering constraint on this load. May not be Release or
comment|/// AcquireRelease.
name|void
name|setOrdering
argument_list|(
argument|AtomicOrdering Ordering
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
operator|(
literal|7
operator|<<
literal|7
operator|)
operator|)
operator||
operator|(
operator|(
name|unsigned
operator|)
name|Ordering
operator|<<
literal|7
operator|)
argument_list|)
block|;   }
name|SynchronizationScope
name|getSynchScope
argument_list|()
specifier|const
block|{
return|return
name|SynchronizationScope
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|>>
literal|6
operator|)
operator|&
literal|1
argument_list|)
return|;
block|}
comment|/// Specify whether this load is ordered with respect to all
comment|/// concurrently executing threads, or only with respect to signal handlers
comment|/// executing in the same thread.
name|void
name|setSynchScope
argument_list|(
argument|SynchronizationScope xthread
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
operator|(
literal|1
operator|<<
literal|6
operator|)
operator|)
operator||
operator|(
name|xthread
operator|<<
literal|6
operator|)
argument_list|)
block|;   }
name|void
name|setAtomic
argument_list|(
argument|AtomicOrdering Ordering
argument_list|,
argument|SynchronizationScope SynchScope = CrossThread
argument_list|)
block|{
name|setOrdering
argument_list|(
name|Ordering
argument_list|)
block|;
name|setSynchScope
argument_list|(
name|SynchScope
argument_list|)
block|;   }
name|bool
name|isSimple
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isAtomic
argument_list|()
operator|&&
operator|!
name|isVolatile
argument_list|()
return|;
block|}
name|bool
name|isUnordered
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getOrdering
argument_list|()
operator|==
name|AtomicOrdering
operator|::
name|NotAtomic
operator|||
name|getOrdering
argument_list|()
operator|==
name|AtomicOrdering
operator|::
name|Unordered
operator|)
operator|&&
operator|!
name|isVolatile
argument_list|()
return|;
block|}
name|Value
operator|*
name|getPointerOperand
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getPointerOperand
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getPointerOperandIndex
argument_list|()
block|{
return|return
literal|0U
return|;
block|}
name|Type
operator|*
name|getPointerOperandType
argument_list|()
specifier|const
block|{
return|return
name|getPointerOperand
argument_list|()
operator|->
name|getType
argument_list|()
return|;
block|}
comment|/// Returns the address space of the pointer operand.
name|unsigned
name|getPointerAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|getPointerOperandType
argument_list|()
operator|->
name|getPointerAddressSpace
argument_list|()
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
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Load
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
name|private
operator|:
comment|// Shadow Instruction::setInstructionSubclassData with a private forwarding
comment|// method so that subclasses cannot accidentally use it.
name|void
name|setInstructionSubclassData
argument_list|(
argument|unsigned short D
argument_list|)
block|{
name|Instruction
operator|::
name|setInstructionSubclassData
argument_list|(
name|D
argument_list|)
block|;   }
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|//                                StoreInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// An instruction for storing to memory.
name|class
name|StoreInst
operator|:
name|public
name|Instruction
block|{
name|void
name|AssertOK
argument_list|()
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|StoreInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
name|StoreInst
argument_list|(
name|Value
operator|*
name|Val
argument_list|,
name|Value
operator|*
name|Ptr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
block|;
name|StoreInst
argument_list|(
name|Value
operator|*
name|Val
argument_list|,
name|Value
operator|*
name|Ptr
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
name|StoreInst
argument_list|(
argument|Value *Val
argument_list|,
argument|Value *Ptr
argument_list|,
argument|bool isVolatile = false
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|StoreInst
argument_list|(
argument|Value *Val
argument_list|,
argument|Value *Ptr
argument_list|,
argument|bool isVolatile
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|StoreInst
argument_list|(
argument|Value *Val
argument_list|,
argument|Value *Ptr
argument_list|,
argument|bool isVolatile
argument_list|,
argument|unsigned Align
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|StoreInst
argument_list|(
argument|Value *Val
argument_list|,
argument|Value *Ptr
argument_list|,
argument|bool isVolatile
argument_list|,
argument|unsigned Align
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|StoreInst
argument_list|(
argument|Value *Val
argument_list|,
argument|Value *Ptr
argument_list|,
argument|bool isVolatile
argument_list|,
argument|unsigned Align
argument_list|,
argument|AtomicOrdering Order
argument_list|,
argument|SynchronizationScope SynchScope = CrossThread
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|StoreInst
argument_list|(
argument|Value *Val
argument_list|,
argument|Value *Ptr
argument_list|,
argument|bool isVolatile
argument_list|,
argument|unsigned Align
argument_list|,
argument|AtomicOrdering Order
argument_list|,
argument|SynchronizationScope SynchScope
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
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
comment|/// Return true if this is a store to a volatile memory location.
name|bool
name|isVolatile
argument_list|()
specifier|const
block|{
return|return
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|1
return|;
block|}
comment|/// Specify whether this is a volatile store or not.
name|void
name|setVolatile
argument_list|(
argument|bool V
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
literal|1
operator|)
operator||
operator|(
name|V
condition|?
literal|1
else|:
literal|0
operator|)
argument_list|)
block|;   }
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|/// Return the alignment of the access that is being performed
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
operator|(
literal|1
operator|<<
operator|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|>>
literal|1
operator|)
operator|&
literal|31
operator|)
operator|)
operator|>>
literal|1
return|;
block|}
name|void
name|setAlignment
argument_list|(
argument|unsigned Align
argument_list|)
block|;
comment|/// Returns the ordering effect of this store.
name|AtomicOrdering
name|getOrdering
argument_list|()
specifier|const
block|{
return|return
name|AtomicOrdering
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|>>
literal|7
operator|)
operator|&
literal|7
argument_list|)
return|;
block|}
comment|/// Set the ordering constraint on this store.  May not be Acquire or
comment|/// AcquireRelease.
name|void
name|setOrdering
argument_list|(
argument|AtomicOrdering Ordering
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
operator|(
literal|7
operator|<<
literal|7
operator|)
operator|)
operator||
operator|(
operator|(
name|unsigned
operator|)
name|Ordering
operator|<<
literal|7
operator|)
argument_list|)
block|;   }
name|SynchronizationScope
name|getSynchScope
argument_list|()
specifier|const
block|{
return|return
name|SynchronizationScope
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|>>
literal|6
operator|)
operator|&
literal|1
argument_list|)
return|;
block|}
comment|/// Specify whether this store instruction is ordered with respect to all
comment|/// concurrently executing threads, or only with respect to signal handlers
comment|/// executing in the same thread.
name|void
name|setSynchScope
argument_list|(
argument|SynchronizationScope xthread
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
operator|(
literal|1
operator|<<
literal|6
operator|)
operator|)
operator||
operator|(
name|xthread
operator|<<
literal|6
operator|)
argument_list|)
block|;   }
name|void
name|setAtomic
argument_list|(
argument|AtomicOrdering Ordering
argument_list|,
argument|SynchronizationScope SynchScope = CrossThread
argument_list|)
block|{
name|setOrdering
argument_list|(
name|Ordering
argument_list|)
block|;
name|setSynchScope
argument_list|(
name|SynchScope
argument_list|)
block|;   }
name|bool
name|isSimple
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isAtomic
argument_list|()
operator|&&
operator|!
name|isVolatile
argument_list|()
return|;
block|}
name|bool
name|isUnordered
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getOrdering
argument_list|()
operator|==
name|AtomicOrdering
operator|::
name|NotAtomic
operator|||
name|getOrdering
argument_list|()
operator|==
name|AtomicOrdering
operator|::
name|Unordered
operator|)
operator|&&
operator|!
name|isVolatile
argument_list|()
return|;
block|}
name|Value
operator|*
name|getValueOperand
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getValueOperand
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|Value
operator|*
name|getPointerOperand
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|1
argument_list|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getPointerOperand
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|1
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getPointerOperandIndex
argument_list|()
block|{
return|return
literal|1U
return|;
block|}
name|Type
operator|*
name|getPointerOperandType
argument_list|()
specifier|const
block|{
return|return
name|getPointerOperand
argument_list|()
operator|->
name|getType
argument_list|()
return|;
block|}
comment|/// Returns the address space of the pointer operand.
name|unsigned
name|getPointerAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|getPointerOperandType
argument_list|()
operator|->
name|getPointerAddressSpace
argument_list|()
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
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Store
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
name|private
operator|:
comment|// Shadow Instruction::setInstructionSubclassData with a private forwarding
comment|// method so that subclasses cannot accidentally use it.
name|void
name|setInstructionSubclassData
argument_list|(
argument|unsigned short D
argument_list|)
block|{
name|Instruction
operator|::
name|setInstructionSubclassData
argument_list|(
name|D
argument_list|)
block|;   }
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|StoreInst
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|StoreInst
block|,
literal|2
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|StoreInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                                FenceInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// An instruction for ordering other memory operations.
name|class
name|FenceInst
operator|:
name|public
name|Instruction
block|{
name|void
name|Init
argument_list|(
argument|AtomicOrdering Ordering
argument_list|,
argument|SynchronizationScope SynchScope
argument_list|)
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|FenceInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|// Ordering may only be Acquire, Release, AcquireRelease, or
comment|// SequentiallyConsistent.
name|FenceInst
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|AtomicOrdering Ordering
argument_list|,
argument|SynchronizationScope SynchScope = CrossThread
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|FenceInst
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|AtomicOrdering Ordering
argument_list|,
argument|SynchronizationScope SynchScope
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
comment|// allocate space for exactly zero operands
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
literal|0
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
comment|/// Returns the ordering effect of this fence.
name|AtomicOrdering
name|getOrdering
argument_list|()
specifier|const
block|{
return|return
name|AtomicOrdering
argument_list|(
name|getSubclassDataFromInstruction
argument_list|()
operator|>>
literal|1
argument_list|)
return|;
block|}
comment|/// Set the ordering constraint on this fence.  May only be Acquire, Release,
comment|/// AcquireRelease, or SequentiallyConsistent.
name|void
name|setOrdering
argument_list|(
argument|AtomicOrdering Ordering
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|1
operator|)
operator||
operator|(
operator|(
name|unsigned
operator|)
name|Ordering
operator|<<
literal|1
operator|)
argument_list|)
block|;   }
name|SynchronizationScope
name|getSynchScope
argument_list|()
specifier|const
block|{
return|return
name|SynchronizationScope
argument_list|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|1
argument_list|)
return|;
block|}
comment|/// Specify whether this fence orders other operations with respect to all
comment|/// concurrently executing threads, or only with respect to signal handlers
comment|/// executing in the same thread.
name|void
name|setSynchScope
argument_list|(
argument|SynchronizationScope xthread
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
literal|1
operator|)
operator||
name|xthread
argument_list|)
block|;   }
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
name|Fence
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
name|private
operator|:
comment|// Shadow Instruction::setInstructionSubclassData with a private forwarding
comment|// method so that subclasses cannot accidentally use it.
name|void
name|setInstructionSubclassData
argument_list|(
argument|unsigned short D
argument_list|)
block|{
name|Instruction
operator|::
name|setInstructionSubclassData
argument_list|(
name|D
argument_list|)
block|;   }
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|//                                AtomicCmpXchgInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// an instruction that atomically checks whether a
comment|/// specified value is in a memory location, and, if it is, stores a new value
comment|/// there.  Returns the value that was loaded.
comment|///
name|class
name|AtomicCmpXchgInst
operator|:
name|public
name|Instruction
block|{
name|void
name|Init
argument_list|(
argument|Value *Ptr
argument_list|,
argument|Value *Cmp
argument_list|,
argument|Value *NewVal
argument_list|,
argument|AtomicOrdering SuccessOrdering
argument_list|,
argument|AtomicOrdering FailureOrdering
argument_list|,
argument|SynchronizationScope SynchScope
argument_list|)
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|AtomicCmpXchgInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
name|AtomicCmpXchgInst
argument_list|(
argument|Value *Ptr
argument_list|,
argument|Value *Cmp
argument_list|,
argument|Value *NewVal
argument_list|,
argument|AtomicOrdering SuccessOrdering
argument_list|,
argument|AtomicOrdering FailureOrdering
argument_list|,
argument|SynchronizationScope SynchScope
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|AtomicCmpXchgInst
argument_list|(
argument|Value *Ptr
argument_list|,
argument|Value *Cmp
argument_list|,
argument|Value *NewVal
argument_list|,
argument|AtomicOrdering SuccessOrdering
argument_list|,
argument|AtomicOrdering FailureOrdering
argument_list|,
argument|SynchronizationScope SynchScope
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
comment|// allocate space for exactly three operands
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
literal|3
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
comment|/// Return true if this is a cmpxchg from a volatile memory
comment|/// location.
comment|///
name|bool
name|isVolatile
argument_list|()
specifier|const
block|{
return|return
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|1
return|;
block|}
comment|/// Specify whether this is a volatile cmpxchg.
comment|///
name|void
name|setVolatile
argument_list|(
argument|bool V
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
literal|1
operator|)
operator||
operator|(
name|unsigned
operator|)
name|V
argument_list|)
block|;   }
comment|/// Return true if this cmpxchg may spuriously fail.
name|bool
name|isWeak
argument_list|()
specifier|const
block|{
return|return
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|0x100
return|;
block|}
name|void
name|setWeak
argument_list|(
argument|bool IsWeak
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
literal|0x100
operator|)
operator||
operator|(
name|IsWeak
operator|<<
literal|8
operator|)
argument_list|)
block|;   }
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|/// Set the ordering constraint on this cmpxchg.
name|void
name|setSuccessOrdering
argument_list|(
argument|AtomicOrdering Ordering
argument_list|)
block|{
name|assert
argument_list|(
name|Ordering
operator|!=
name|AtomicOrdering
operator|::
name|NotAtomic
operator|&&
literal|"CmpXchg instructions can only be atomic."
argument_list|)
block|;
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
literal|0x1c
operator|)
operator||
operator|(
operator|(
name|unsigned
operator|)
name|Ordering
operator|<<
literal|2
operator|)
argument_list|)
block|;   }
name|void
name|setFailureOrdering
argument_list|(
argument|AtomicOrdering Ordering
argument_list|)
block|{
name|assert
argument_list|(
name|Ordering
operator|!=
name|AtomicOrdering
operator|::
name|NotAtomic
operator|&&
literal|"CmpXchg instructions can only be atomic."
argument_list|)
block|;
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
literal|0xe0
operator|)
operator||
operator|(
operator|(
name|unsigned
operator|)
name|Ordering
operator|<<
literal|5
operator|)
argument_list|)
block|;   }
comment|/// Specify whether this cmpxchg is atomic and orders other operations with
comment|/// respect to all concurrently executing threads, or only with respect to
comment|/// signal handlers executing in the same thread.
name|void
name|setSynchScope
argument_list|(
argument|SynchronizationScope SynchScope
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
literal|2
operator|)
operator||
operator|(
name|SynchScope
operator|<<
literal|1
operator|)
argument_list|)
block|;   }
comment|/// Returns the ordering constraint on this cmpxchg.
name|AtomicOrdering
name|getSuccessOrdering
argument_list|()
specifier|const
block|{
return|return
name|AtomicOrdering
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|>>
literal|2
operator|)
operator|&
literal|7
argument_list|)
return|;
block|}
comment|/// Returns the ordering constraint on this cmpxchg.
name|AtomicOrdering
name|getFailureOrdering
argument_list|()
specifier|const
block|{
return|return
name|AtomicOrdering
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|>>
literal|5
operator|)
operator|&
literal|7
argument_list|)
return|;
block|}
comment|/// Returns whether this cmpxchg is atomic between threads or only within a
comment|/// single thread.
name|SynchronizationScope
name|getSynchScope
argument_list|()
specifier|const
block|{
return|return
name|SynchronizationScope
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|2
operator|)
operator|>>
literal|1
argument_list|)
return|;
block|}
name|Value
operator|*
name|getPointerOperand
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getPointerOperand
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getPointerOperandIndex
argument_list|()
block|{
return|return
literal|0U
return|;
block|}
name|Value
operator|*
name|getCompareOperand
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|1
argument_list|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getCompareOperand
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|1
argument_list|)
return|;
block|}
name|Value
operator|*
name|getNewValOperand
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|2
argument_list|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getNewValOperand
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|2
argument_list|)
return|;
block|}
comment|/// Returns the address space of the pointer operand.
name|unsigned
name|getPointerAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|getPointerOperand
argument_list|()
operator|->
name|getType
argument_list|()
operator|->
name|getPointerAddressSpace
argument_list|()
return|;
block|}
comment|/// Returns the strongest permitted ordering on failure, given the
comment|/// desired ordering on success.
comment|///
comment|/// If the comparison in a cmpxchg operation fails, there is no atomic store
comment|/// so release semantics cannot be provided. So this function drops explicit
comment|/// Release requests from the AtomicOrdering. A SequentiallyConsistent
comment|/// operation would remain SequentiallyConsistent.
specifier|static
name|AtomicOrdering
name|getStrongestFailureOrdering
argument_list|(
argument|AtomicOrdering SuccessOrdering
argument_list|)
block|{
switch|switch
condition|(
name|SuccessOrdering
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"invalid cmpxchg success ordering"
argument_list|)
expr_stmt|;
case|case
name|AtomicOrdering
operator|::
name|Release
case|:
case|case
name|AtomicOrdering
operator|::
name|Monotonic
case|:
return|return
name|AtomicOrdering
operator|::
name|Monotonic
return|;
case|case
name|AtomicOrdering
operator|::
name|AcquireRelease
case|:
case|case
name|AtomicOrdering
operator|::
name|Acquire
case|:
return|return
name|AtomicOrdering
operator|::
name|Acquire
return|;
case|case
name|AtomicOrdering
operator|::
name|SequentiallyConsistent
case|:
return|return
name|AtomicOrdering
operator|::
name|SequentiallyConsistent
return|;
block|}
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
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|AtomicCmpXchg
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
name|private
operator|:
comment|// Shadow Instruction::setInstructionSubclassData with a private forwarding
comment|// method so that subclasses cannot accidentally use it.
name|void
name|setInstructionSubclassData
argument_list|(
argument|unsigned short D
argument_list|)
block|{
name|Instruction
operator|::
name|setInstructionSubclassData
argument_list|(
name|D
argument_list|)
block|;   }
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|AtomicCmpXchgInst
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|AtomicCmpXchgInst
block|,
literal|3
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|AtomicCmpXchgInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                                AtomicRMWInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// an instruction that atomically reads a memory location,
comment|/// combines it with another value, and then stores the result back.  Returns
comment|/// the old value.
comment|///
name|class
name|AtomicRMWInst
operator|:
name|public
name|Instruction
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|AtomicRMWInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// This enumeration lists the possible modifications atomicrmw can make.  In
comment|/// the descriptions, 'p' is the pointer to the instruction's memory location,
comment|/// 'old' is the initial value of *p, and 'v' is the other value passed to the
comment|/// instruction.  These instructions always return 'old'.
expr|enum
name|BinOp
block|{
comment|/// *p = v
name|Xchg
block|,
comment|/// *p = old + v
name|Add
block|,
comment|/// *p = old - v
name|Sub
block|,
comment|/// *p = old& v
name|And
block|,
comment|/// *p = ~(old& v)
name|Nand
block|,
comment|/// *p = old | v
name|Or
block|,
comment|/// *p = old ^ v
name|Xor
block|,
comment|/// *p = old>signed v ? old : v
name|Max
block|,
comment|/// *p = old<signed v ? old : v
name|Min
block|,
comment|/// *p = old>unsigned v ? old : v
name|UMax
block|,
comment|/// *p = old<unsigned v ? old : v
name|UMin
block|,
name|FIRST_BINOP
operator|=
name|Xchg
block|,
name|LAST_BINOP
operator|=
name|UMin
block|,
name|BAD_BINOP
block|}
block|;
name|AtomicRMWInst
argument_list|(
argument|BinOp Operation
argument_list|,
argument|Value *Ptr
argument_list|,
argument|Value *Val
argument_list|,
argument|AtomicOrdering Ordering
argument_list|,
argument|SynchronizationScope SynchScope
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|AtomicRMWInst
argument_list|(
argument|BinOp Operation
argument_list|,
argument|Value *Ptr
argument_list|,
argument|Value *Val
argument_list|,
argument|AtomicOrdering Ordering
argument_list|,
argument|SynchronizationScope SynchScope
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
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
name|BinOp
name|getOperation
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|BinOp
operator|>
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|>>
literal|5
operator|)
return|;
block|}
name|void
name|setOperation
argument_list|(
argument|BinOp Operation
argument_list|)
block|{
name|unsigned
name|short
name|SubclassData
operator|=
name|getSubclassDataFromInstruction
argument_list|()
block|;
name|setInstructionSubclassData
argument_list|(
operator|(
name|SubclassData
operator|&
literal|31
operator|)
operator||
operator|(
name|Operation
operator|<<
literal|5
operator|)
argument_list|)
block|;   }
comment|/// Return true if this is a RMW on a volatile memory location.
comment|///
name|bool
name|isVolatile
argument_list|()
specifier|const
block|{
return|return
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|1
return|;
block|}
comment|/// Specify whether this is a volatile RMW or not.
comment|///
name|void
name|setVolatile
argument_list|(
argument|bool V
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
literal|1
operator|)
operator||
operator|(
name|unsigned
operator|)
name|V
argument_list|)
block|;   }
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|/// Set the ordering constraint on this RMW.
name|void
name|setOrdering
argument_list|(
argument|AtomicOrdering Ordering
argument_list|)
block|{
name|assert
argument_list|(
name|Ordering
operator|!=
name|AtomicOrdering
operator|::
name|NotAtomic
operator|&&
literal|"atomicrmw instructions can only be atomic."
argument_list|)
block|;
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
operator|(
literal|7
operator|<<
literal|2
operator|)
operator|)
operator||
operator|(
operator|(
name|unsigned
operator|)
name|Ordering
operator|<<
literal|2
operator|)
argument_list|)
block|;   }
comment|/// Specify whether this RMW orders other operations with respect to all
comment|/// concurrently executing threads, or only with respect to signal handlers
comment|/// executing in the same thread.
name|void
name|setSynchScope
argument_list|(
argument|SynchronizationScope SynchScope
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
literal|2
operator|)
operator||
operator|(
name|SynchScope
operator|<<
literal|1
operator|)
argument_list|)
block|;   }
comment|/// Returns the ordering constraint on this RMW.
name|AtomicOrdering
name|getOrdering
argument_list|()
specifier|const
block|{
return|return
name|AtomicOrdering
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|>>
literal|2
operator|)
operator|&
literal|7
argument_list|)
return|;
block|}
comment|/// Returns whether this RMW is atomic between threads or only within a
comment|/// single thread.
name|SynchronizationScope
name|getSynchScope
argument_list|()
specifier|const
block|{
return|return
name|SynchronizationScope
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|2
operator|)
operator|>>
literal|1
argument_list|)
return|;
block|}
name|Value
operator|*
name|getPointerOperand
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getPointerOperand
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getPointerOperandIndex
argument_list|()
block|{
return|return
literal|0U
return|;
block|}
name|Value
operator|*
name|getValOperand
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|1
argument_list|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getValOperand
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|1
argument_list|)
return|;
block|}
comment|/// Returns the address space of the pointer operand.
name|unsigned
name|getPointerAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|getPointerOperand
argument_list|()
operator|->
name|getType
argument_list|()
operator|->
name|getPointerAddressSpace
argument_list|()
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
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|AtomicRMW
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
name|private
operator|:
name|void
name|Init
argument_list|(
argument|BinOp Operation
argument_list|,
argument|Value *Ptr
argument_list|,
argument|Value *Val
argument_list|,
argument|AtomicOrdering Ordering
argument_list|,
argument|SynchronizationScope SynchScope
argument_list|)
block|;
comment|// Shadow Instruction::setInstructionSubclassData with a private forwarding
comment|// method so that subclasses cannot accidentally use it.
name|void
name|setInstructionSubclassData
argument_list|(
argument|unsigned short D
argument_list|)
block|{
name|Instruction
operator|::
name|setInstructionSubclassData
argument_list|(
name|D
argument_list|)
block|;   }
block|}
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|AtomicRMWInst
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|AtomicRMWInst
block|,
literal|2
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|AtomicRMWInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                             GetElementPtrInst Class
comment|//===----------------------------------------------------------------------===//
comment|// checkGEPType - Simple wrapper function to give a better assertion failure
comment|// message on bad indexes for a gep instruction.
comment|//
specifier|inline
name|Type
operator|*
name|checkGEPType
argument_list|(
argument|Type *Ty
argument_list|)
block|{
name|assert
argument_list|(
name|Ty
operator|&&
literal|"Invalid GetElementPtrInst indices for type!"
argument_list|)
block|;
return|return
name|Ty
return|;
block|}
comment|/// an instruction for type-safe pointer arithmetic to
comment|/// access elements of arrays and structs
comment|///
name|class
name|GetElementPtrInst
operator|:
name|public
name|Instruction
block|{
name|Type
operator|*
name|SourceElementType
block|;
name|Type
operator|*
name|ResultElementType
block|;
name|GetElementPtrInst
argument_list|(
specifier|const
name|GetElementPtrInst
operator|&
name|GEPI
argument_list|)
block|;
comment|/// Constructors - Create a getelementptr instruction with a base pointer an
comment|/// list of indices. The first ctor can optionally insert before an existing
comment|/// instruction, the second appends the new instruction to the specified
comment|/// BasicBlock.
specifier|inline
name|GetElementPtrInst
argument_list|(
argument|Type *PointeeType
argument_list|,
argument|Value *Ptr
argument_list|,
argument|ArrayRef<Value *> IdxList
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
block|;
specifier|inline
name|GetElementPtrInst
argument_list|(
argument|Type *PointeeType
argument_list|,
argument|Value *Ptr
argument_list|,
argument|ArrayRef<Value *> IdxList
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
name|Ptr
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|IdxList
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
name|GetElementPtrInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
specifier|static
name|GetElementPtrInst
operator|*
name|Create
argument_list|(
argument|Type *PointeeType
argument_list|,
argument|Value *Ptr
argument_list|,
argument|ArrayRef<Value *> IdxList
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
name|unsigned
name|Values
operator|=
literal|1
operator|+
name|unsigned
argument_list|(
name|IdxList
operator|.
name|size
argument_list|()
argument_list|)
block|;
if|if
condition|(
operator|!
name|PointeeType
condition|)
name|PointeeType
operator|=
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Ptr
operator|->
name|getType
argument_list|()
operator|->
name|getScalarType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
expr_stmt|;
else|else
name|assert
argument_list|(
name|PointeeType
operator|==
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Ptr
operator|->
name|getType
argument_list|()
operator|->
name|getScalarType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|new
argument_list|(
argument|Values
argument_list|)
name|GetElementPtrInst
argument_list|(
name|PointeeType
argument_list|,
name|Ptr
argument_list|,
name|IdxList
argument_list|,
name|Values
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|GetElementPtrInst
operator|*
name|Create
argument_list|(
argument|Type *PointeeType
argument_list|,
argument|Value *Ptr
argument_list|,
argument|ArrayRef<Value *> IdxList
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
name|unsigned
name|Values
operator|=
literal|1
operator|+
name|unsigned
argument_list|(
name|IdxList
operator|.
name|size
argument_list|()
argument_list|)
block|;
if|if
condition|(
operator|!
name|PointeeType
condition|)
name|PointeeType
operator|=
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Ptr
operator|->
name|getType
argument_list|()
operator|->
name|getScalarType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
expr_stmt|;
else|else
name|assert
argument_list|(
name|PointeeType
operator|==
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Ptr
operator|->
name|getType
argument_list|()
operator|->
name|getScalarType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|new
argument_list|(
argument|Values
argument_list|)
name|GetElementPtrInst
argument_list|(
name|PointeeType
argument_list|,
name|Ptr
argument_list|,
name|IdxList
argument_list|,
name|Values
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Create an "inbounds" getelementptr. See the documentation for the
comment|/// "inbounds" flag in LangRef.html for details.
specifier|static
name|GetElementPtrInst
operator|*
name|CreateInBounds
argument_list|(
argument|Value *Ptr
argument_list|,
argument|ArrayRef<Value *> IdxList
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|CreateInBounds
argument_list|(
name|nullptr
argument_list|,
name|Ptr
argument_list|,
name|IdxList
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|GetElementPtrInst
operator|*
name|CreateInBounds
argument_list|(
argument|Type *PointeeType
argument_list|,
argument|Value *Ptr
argument_list|,
argument|ArrayRef<Value *> IdxList
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
name|GetElementPtrInst
operator|*
name|GEP
operator|=
name|Create
argument_list|(
name|PointeeType
argument_list|,
name|Ptr
argument_list|,
name|IdxList
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
block|;
name|GEP
operator|->
name|setIsInBounds
argument_list|(
name|true
argument_list|)
block|;
return|return
name|GEP
return|;
block|}
specifier|static
name|GetElementPtrInst
operator|*
name|CreateInBounds
argument_list|(
argument|Value *Ptr
argument_list|,
argument|ArrayRef<Value *> IdxList
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|CreateInBounds
argument_list|(
name|nullptr
argument_list|,
name|Ptr
argument_list|,
name|IdxList
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
specifier|static
name|GetElementPtrInst
operator|*
name|CreateInBounds
argument_list|(
argument|Type *PointeeType
argument_list|,
argument|Value *Ptr
argument_list|,
argument|ArrayRef<Value *> IdxList
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
name|GetElementPtrInst
operator|*
name|GEP
operator|=
name|Create
argument_list|(
name|PointeeType
argument_list|,
name|Ptr
argument_list|,
name|IdxList
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
block|;
name|GEP
operator|->
name|setIsInBounds
argument_list|(
name|true
argument_list|)
block|;
return|return
name|GEP
return|;
block|}
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
name|Type
operator|*
name|getSourceElementType
argument_list|()
specifier|const
block|{
return|return
name|SourceElementType
return|;
block|}
name|void
name|setSourceElementType
argument_list|(
argument|Type *Ty
argument_list|)
block|{
name|SourceElementType
operator|=
name|Ty
block|; }
name|void
name|setResultElementType
argument_list|(
argument|Type *Ty
argument_list|)
block|{
name|ResultElementType
operator|=
name|Ty
block|; }
name|Type
operator|*
name|getResultElementType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|ResultElementType
operator|==
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|getType
argument_list|()
operator|->
name|getScalarType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
argument_list|)
block|;
return|return
name|ResultElementType
return|;
block|}
comment|/// Returns the address space of this instruction's pointer type.
name|unsigned
name|getAddressSpace
argument_list|()
specifier|const
block|{
comment|// Note that this is always the same as the pointer operand's address space
comment|// and that is cheaper to compute, so cheat here.
return|return
name|getPointerAddressSpace
argument_list|()
return|;
block|}
comment|/// Returns the type of the element that would be loaded with
comment|/// a load instruction with the specified parameters.
comment|///
comment|/// Null is returned if the indices are invalid for the specified
comment|/// pointer type.
comment|///
specifier|static
name|Type
operator|*
name|getIndexedType
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|IdxList
argument_list|)
block|;
specifier|static
name|Type
operator|*
name|getIndexedType
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|ArrayRef
operator|<
name|Constant
operator|*
operator|>
name|IdxList
argument_list|)
block|;
specifier|static
name|Type
operator|*
name|getIndexedType
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|IdxList
argument_list|)
block|;
specifier|inline
name|op_iterator
name|idx_begin
argument_list|()
block|{
return|return
name|op_begin
argument_list|()
operator|+
literal|1
return|;
block|}
specifier|inline
name|const_op_iterator
name|idx_begin
argument_list|()
specifier|const
block|{
return|return
name|op_begin
argument_list|()
operator|+
literal|1
return|;
block|}
specifier|inline
name|op_iterator
name|idx_end
argument_list|()
block|{
return|return
name|op_end
argument_list|()
return|;
block|}
specifier|inline
name|const_op_iterator
name|idx_end
argument_list|()
specifier|const
block|{
return|return
name|op_end
argument_list|()
return|;
block|}
specifier|inline
name|iterator_range
operator|<
name|op_iterator
operator|>
name|indices
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|idx_begin
argument_list|()
argument_list|,
name|idx_end
argument_list|()
argument_list|)
return|;
block|}
specifier|inline
name|iterator_range
operator|<
name|const_op_iterator
operator|>
name|indices
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|idx_begin
argument_list|()
argument_list|,
name|idx_end
argument_list|()
argument_list|)
return|;
block|}
name|Value
operator|*
name|getPointerOperand
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getPointerOperand
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getPointerOperandIndex
argument_list|()
block|{
return|return
literal|0U
return|;
comment|// get index for modifying correct operand.
block|}
comment|/// Method to return the pointer operand as a
comment|/// PointerType.
name|Type
operator|*
name|getPointerOperandType
argument_list|()
specifier|const
block|{
return|return
name|getPointerOperand
argument_list|()
operator|->
name|getType
argument_list|()
return|;
block|}
comment|/// Returns the address space of the pointer operand.
name|unsigned
name|getPointerAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|getPointerOperandType
argument_list|()
operator|->
name|getPointerAddressSpace
argument_list|()
return|;
block|}
comment|/// Returns the pointer type returned by the GEP
comment|/// instruction, which may be a vector of pointers.
specifier|static
name|Type
operator|*
name|getGEPReturnType
argument_list|(
argument|Value *Ptr
argument_list|,
argument|ArrayRef<Value *> IdxList
argument_list|)
block|{
return|return
name|getGEPReturnType
argument_list|(
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Ptr
operator|->
name|getType
argument_list|()
operator|->
name|getScalarType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
argument_list|,
name|Ptr
argument_list|,
name|IdxList
argument_list|)
return|;
block|}
specifier|static
name|Type
operator|*
name|getGEPReturnType
argument_list|(
argument|Type *ElTy
argument_list|,
argument|Value *Ptr
argument_list|,
argument|ArrayRef<Value *> IdxList
argument_list|)
block|{
name|Type
operator|*
name|PtrTy
operator|=
name|PointerType
operator|::
name|get
argument_list|(
name|checkGEPType
argument_list|(
name|getIndexedType
argument_list|(
name|ElTy
argument_list|,
name|IdxList
argument_list|)
argument_list|)
argument_list|,
name|Ptr
operator|->
name|getType
argument_list|()
operator|->
name|getPointerAddressSpace
argument_list|()
argument_list|)
block|;
comment|// Vector GEP
if|if
condition|(
name|Ptr
operator|->
name|getType
argument_list|()
operator|->
name|isVectorTy
argument_list|()
condition|)
block|{
name|unsigned
name|NumElem
init|=
name|Ptr
operator|->
name|getType
argument_list|()
operator|->
name|getVectorNumElements
argument_list|()
decl_stmt|;
return|return
name|VectorType
operator|::
name|get
argument_list|(
name|PtrTy
argument_list|,
name|NumElem
argument_list|)
return|;
block|}
for|for
control|(
name|Value
modifier|*
name|Index
range|:
name|IdxList
control|)
if|if
condition|(
name|Index
operator|->
name|getType
argument_list|()
operator|->
name|isVectorTy
argument_list|()
condition|)
block|{
name|unsigned
name|NumElem
init|=
name|Index
operator|->
name|getType
argument_list|()
operator|->
name|getVectorNumElements
argument_list|()
decl_stmt|;
return|return
name|VectorType
operator|::
name|get
argument_list|(
name|PtrTy
argument_list|,
name|NumElem
argument_list|)
return|;
block|}
comment|// Scalar GEP
return|return
name|PtrTy
return|;
block|}
name|unsigned
name|getNumIndices
argument_list|()
specifier|const
block|{
comment|// Note: always non-negative
return|return
name|getNumOperands
argument_list|()
operator|-
literal|1
return|;
block|}
name|bool
name|hasIndices
argument_list|()
specifier|const
block|{
return|return
name|getNumOperands
argument_list|()
operator|>
literal|1
return|;
block|}
comment|/// Return true if all of the indices of this GEP are
comment|/// zeros.  If so, the result pointer and the first operand have the same
comment|/// value, just potentially different types.
name|bool
name|hasAllZeroIndices
argument_list|()
specifier|const
block|;
comment|/// Return true if all of the indices of this GEP are
comment|/// constant integers.  If so, the result pointer and the first operand have
comment|/// a constant offset between them.
name|bool
name|hasAllConstantIndices
argument_list|()
specifier|const
block|;
comment|/// Set or clear the inbounds flag on this GEP instruction.
comment|/// See LangRef.html for the meaning of inbounds on a getelementptr.
name|void
name|setIsInBounds
argument_list|(
argument|bool b = true
argument_list|)
block|;
comment|/// Determine whether the GEP has the inbounds flag.
name|bool
name|isInBounds
argument_list|()
specifier|const
block|;
comment|/// Accumulate the constant address offset of this GEP if possible.
comment|///
comment|/// This routine accepts an APInt into which it will accumulate the constant
comment|/// offset of this GEP if the GEP is in fact constant. If the GEP is not
comment|/// all-constant, it returns false and the value of the offset APInt is
comment|/// undefined (it is *not* preserved!). The APInt passed into this routine
comment|/// must be at least as wide as the IntPtr type for the address space of
comment|/// the base GEP pointer.
name|bool
name|accumulateConstantOffset
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|APInt&Offset
argument_list|)
specifier|const
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
operator|(
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|GetElementPtr
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
name|GetElementPtrInst
operator|>
operator|:
name|public
name|VariadicOperandTraits
operator|<
name|GetElementPtrInst
block|,
literal|1
operator|>
block|{ }
block|;
name|GetElementPtrInst
operator|::
name|GetElementPtrInst
argument_list|(
argument|Type *PointeeType
argument_list|,
argument|Value *Ptr
argument_list|,
argument|ArrayRef<Value *> IdxList
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
operator|:
name|Instruction
argument_list|(
name|getGEPReturnType
argument_list|(
name|PointeeType
argument_list|,
name|Ptr
argument_list|,
name|IdxList
argument_list|)
argument_list|,
name|GetElementPtr
argument_list|,
name|OperandTraits
operator|<
name|GetElementPtrInst
operator|>
operator|::
name|op_end
argument_list|(
name|this
argument_list|)
operator|-
name|Values
argument_list|,
name|Values
argument_list|,
name|InsertBefore
argument_list|)
block|,
name|SourceElementType
argument_list|(
name|PointeeType
argument_list|)
block|,
name|ResultElementType
argument_list|(
argument|getIndexedType(PointeeType, IdxList)
argument_list|)
block|{
name|assert
argument_list|(
name|ResultElementType
operator|==
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|getType
argument_list|()
operator|->
name|getScalarType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
argument_list|)
block|;
name|init
argument_list|(
name|Ptr
argument_list|,
name|IdxList
argument_list|,
name|NameStr
argument_list|)
block|; }
name|GetElementPtrInst
operator|::
name|GetElementPtrInst
argument_list|(
argument|Type *PointeeType
argument_list|,
argument|Value *Ptr
argument_list|,
argument|ArrayRef<Value *> IdxList
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
operator|:
name|Instruction
argument_list|(
name|getGEPReturnType
argument_list|(
name|PointeeType
argument_list|,
name|Ptr
argument_list|,
name|IdxList
argument_list|)
argument_list|,
name|GetElementPtr
argument_list|,
name|OperandTraits
operator|<
name|GetElementPtrInst
operator|>
operator|::
name|op_end
argument_list|(
name|this
argument_list|)
operator|-
name|Values
argument_list|,
name|Values
argument_list|,
name|InsertAtEnd
argument_list|)
block|,
name|SourceElementType
argument_list|(
name|PointeeType
argument_list|)
block|,
name|ResultElementType
argument_list|(
argument|getIndexedType(PointeeType, IdxList)
argument_list|)
block|{
name|assert
argument_list|(
name|ResultElementType
operator|==
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|getType
argument_list|()
operator|->
name|getScalarType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
argument_list|)
block|;
name|init
argument_list|(
name|Ptr
argument_list|,
name|IdxList
argument_list|,
name|NameStr
argument_list|)
block|; }
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|GetElementPtrInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                               ICmpInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This instruction compares its operands according to the predicate given
comment|/// to the constructor. It only operates on integers or pointers. The operands
comment|/// must be identical types.
comment|/// Represent an integer comparison operator.
name|class
name|ICmpInst
operator|:
name|public
name|CmpInst
block|{
name|void
name|AssertOK
argument_list|()
block|{
name|assert
argument_list|(
name|getPredicate
argument_list|()
operator|>=
name|CmpInst
operator|::
name|FIRST_ICMP_PREDICATE
operator|&&
name|getPredicate
argument_list|()
operator|<=
name|CmpInst
operator|::
name|LAST_ICMP_PREDICATE
operator|&&
literal|"Invalid ICmp predicate value"
argument_list|)
block|;
name|assert
argument_list|(
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|->
name|getType
argument_list|()
operator|==
name|getOperand
argument_list|(
literal|1
argument_list|)
operator|->
name|getType
argument_list|()
operator|&&
literal|"Both operands to ICmp instruction are not of the same type!"
argument_list|)
block|;
comment|// Check that the operands are the right type
name|assert
argument_list|(
operator|(
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|->
name|getType
argument_list|()
operator|->
name|isIntOrIntVectorTy
argument_list|()
operator|||
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|->
name|getType
argument_list|()
operator|->
name|isPtrOrPtrVectorTy
argument_list|()
operator|)
operator|&&
literal|"Invalid operand types for ICmp instruction"
argument_list|)
block|;   }
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
comment|/// Clone an identical ICmpInst
name|ICmpInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Constructor with insert-before-instruction semantics.
name|ICmpInst
argument_list|(
argument|Instruction *InsertBefore
argument_list|,
comment|///< Where to insert
argument|Predicate pred
argument_list|,
comment|///< The predicate to use for the comparison
argument|Value *LHS
argument_list|,
comment|///< The left-hand-side of the expression
argument|Value *RHS
argument_list|,
comment|///< The right-hand-side of the expression
argument|const Twine&NameStr =
literal|""
comment|///< Name of the instruction
argument_list|)
operator|:
name|CmpInst
argument_list|(
argument|makeCmpResultType(LHS->getType())
argument_list|,
argument|Instruction::ICmp
argument_list|,
argument|pred
argument_list|,
argument|LHS
argument_list|,
argument|RHS
argument_list|,
argument|NameStr
argument_list|,
argument|InsertBefore
argument_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|AssertOK
argument_list|()
block|;
endif|#
directive|endif
block|}
comment|/// Constructor with insert-at-end semantics.
name|ICmpInst
argument_list|(
argument|BasicBlock&InsertAtEnd
argument_list|,
comment|///< Block to insert into.
argument|Predicate pred
argument_list|,
comment|///< The predicate to use for the comparison
argument|Value *LHS
argument_list|,
comment|///< The left-hand-side of the expression
argument|Value *RHS
argument_list|,
comment|///< The right-hand-side of the expression
argument|const Twine&NameStr =
literal|""
comment|///< Name of the instruction
argument_list|)
operator|:
name|CmpInst
argument_list|(
argument|makeCmpResultType(LHS->getType())
argument_list|,
argument|Instruction::ICmp
argument_list|,
argument|pred
argument_list|,
argument|LHS
argument_list|,
argument|RHS
argument_list|,
argument|NameStr
argument_list|,
argument|&InsertAtEnd
argument_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|AssertOK
argument_list|()
block|;
endif|#
directive|endif
block|}
comment|/// Constructor with no-insertion semantics
name|ICmpInst
argument_list|(
argument|Predicate pred
argument_list|,
comment|///< The predicate to use for the comparison
argument|Value *LHS
argument_list|,
comment|///< The left-hand-side of the expression
argument|Value *RHS
argument_list|,
comment|///< The right-hand-side of the expression
argument|const Twine&NameStr =
literal|""
comment|///< Name of the instruction
argument_list|)
operator|:
name|CmpInst
argument_list|(
argument|makeCmpResultType(LHS->getType())
argument_list|,
argument|Instruction::ICmp
argument_list|,
argument|pred
argument_list|,
argument|LHS
argument_list|,
argument|RHS
argument_list|,
argument|NameStr
argument_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|AssertOK
argument_list|()
block|;
endif|#
directive|endif
block|}
comment|/// For example, EQ->EQ, SLE->SLE, UGT->SGT, etc.
comment|/// @returns the predicate that would be the result if the operand were
comment|/// regarded as signed.
comment|/// Return the signed version of the predicate
name|Predicate
name|getSignedPredicate
argument_list|()
specifier|const
block|{
return|return
name|getSignedPredicate
argument_list|(
name|getPredicate
argument_list|()
argument_list|)
return|;
block|}
comment|/// This is a static version that you can use without an instruction.
comment|/// Return the signed version of the predicate.
specifier|static
name|Predicate
name|getSignedPredicate
argument_list|(
argument|Predicate pred
argument_list|)
block|;
comment|/// For example, EQ->EQ, SLE->ULE, UGT->UGT, etc.
comment|/// @returns the predicate that would be the result if the operand were
comment|/// regarded as unsigned.
comment|/// Return the unsigned version of the predicate
name|Predicate
name|getUnsignedPredicate
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedPredicate
argument_list|(
name|getPredicate
argument_list|()
argument_list|)
return|;
block|}
comment|/// This is a static version that you can use without an instruction.
comment|/// Return the unsigned version of the predicate.
specifier|static
name|Predicate
name|getUnsignedPredicate
argument_list|(
argument|Predicate pred
argument_list|)
block|;
comment|/// Return true if this predicate is either EQ or NE.  This also
comment|/// tests for commutativity.
specifier|static
name|bool
name|isEquality
argument_list|(
argument|Predicate P
argument_list|)
block|{
return|return
name|P
operator|==
name|ICMP_EQ
operator|||
name|P
operator|==
name|ICMP_NE
return|;
block|}
comment|/// Return true if this predicate is either EQ or NE.  This also
comment|/// tests for commutativity.
name|bool
name|isEquality
argument_list|()
specifier|const
block|{
return|return
name|isEquality
argument_list|(
name|getPredicate
argument_list|()
argument_list|)
return|;
block|}
comment|/// @returns true if the predicate of this ICmpInst is commutative
comment|/// Determine if this relation is commutative.
name|bool
name|isCommutative
argument_list|()
specifier|const
block|{
return|return
name|isEquality
argument_list|()
return|;
block|}
comment|/// Return true if the predicate is relational (not EQ or NE).
comment|///
name|bool
name|isRelational
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isEquality
argument_list|()
return|;
block|}
comment|/// Return true if the predicate is relational (not EQ or NE).
comment|///
specifier|static
name|bool
name|isRelational
argument_list|(
argument|Predicate P
argument_list|)
block|{
return|return
operator|!
name|isEquality
argument_list|(
name|P
argument_list|)
return|;
block|}
comment|/// Exchange the two operands to this instruction in such a way that it does
comment|/// not modify the semantics of the instruction. The predicate value may be
comment|/// changed to retain the same result if the predicate is order dependent
comment|/// (e.g. ult).
comment|/// Swap operands and adjust predicate.
name|void
name|swapOperands
argument_list|()
block|{
name|setPredicate
argument_list|(
name|getSwappedPredicate
argument_list|()
argument_list|)
block|;
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
operator|.
name|swap
argument_list|(
name|Op
operator|<
literal|1
operator|>
operator|(
operator|)
argument_list|)
block|;   }
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
name|ICmp
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
comment|//                               FCmpInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This instruction compares its operands according to the predicate given
comment|/// to the constructor. It only operates on floating point values or packed
comment|/// vectors of floating point values. The operands must be identical types.
comment|/// Represents a floating point comparison operator.
name|class
name|FCmpInst
operator|:
name|public
name|CmpInst
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
comment|/// Clone an identical FCmpInst
name|FCmpInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Constructor with insert-before-instruction semantics.
name|FCmpInst
argument_list|(
argument|Instruction *InsertBefore
argument_list|,
comment|///< Where to insert
argument|Predicate pred
argument_list|,
comment|///< The predicate to use for the comparison
argument|Value *LHS
argument_list|,
comment|///< The left-hand-side of the expression
argument|Value *RHS
argument_list|,
comment|///< The right-hand-side of the expression
argument|const Twine&NameStr =
literal|""
comment|///< Name of the instruction
argument_list|)
operator|:
name|CmpInst
argument_list|(
argument|makeCmpResultType(LHS->getType())
argument_list|,
argument|Instruction::FCmp
argument_list|,
argument|pred
argument_list|,
argument|LHS
argument_list|,
argument|RHS
argument_list|,
argument|NameStr
argument_list|,
argument|InsertBefore
argument_list|)
block|{
name|assert
argument_list|(
name|pred
operator|<=
name|FCmpInst
operator|::
name|LAST_FCMP_PREDICATE
operator|&&
literal|"Invalid FCmp predicate value"
argument_list|)
block|;
name|assert
argument_list|(
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|->
name|getType
argument_list|()
operator|==
name|getOperand
argument_list|(
literal|1
argument_list|)
operator|->
name|getType
argument_list|()
operator|&&
literal|"Both operands to FCmp instruction are not of the same type!"
argument_list|)
block|;
comment|// Check that the operands are the right type
name|assert
argument_list|(
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|->
name|getType
argument_list|()
operator|->
name|isFPOrFPVectorTy
argument_list|()
operator|&&
literal|"Invalid operand types for FCmp instruction"
argument_list|)
block|;   }
comment|/// Constructor with insert-at-end semantics.
name|FCmpInst
argument_list|(
argument|BasicBlock&InsertAtEnd
argument_list|,
comment|///< Block to insert into.
argument|Predicate pred
argument_list|,
comment|///< The predicate to use for the comparison
argument|Value *LHS
argument_list|,
comment|///< The left-hand-side of the expression
argument|Value *RHS
argument_list|,
comment|///< The right-hand-side of the expression
argument|const Twine&NameStr =
literal|""
comment|///< Name of the instruction
argument_list|)
operator|:
name|CmpInst
argument_list|(
argument|makeCmpResultType(LHS->getType())
argument_list|,
argument|Instruction::FCmp
argument_list|,
argument|pred
argument_list|,
argument|LHS
argument_list|,
argument|RHS
argument_list|,
argument|NameStr
argument_list|,
argument|&InsertAtEnd
argument_list|)
block|{
name|assert
argument_list|(
name|pred
operator|<=
name|FCmpInst
operator|::
name|LAST_FCMP_PREDICATE
operator|&&
literal|"Invalid FCmp predicate value"
argument_list|)
block|;
name|assert
argument_list|(
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|->
name|getType
argument_list|()
operator|==
name|getOperand
argument_list|(
literal|1
argument_list|)
operator|->
name|getType
argument_list|()
operator|&&
literal|"Both operands to FCmp instruction are not of the same type!"
argument_list|)
block|;
comment|// Check that the operands are the right type
name|assert
argument_list|(
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|->
name|getType
argument_list|()
operator|->
name|isFPOrFPVectorTy
argument_list|()
operator|&&
literal|"Invalid operand types for FCmp instruction"
argument_list|)
block|;   }
comment|/// Constructor with no-insertion semantics
name|FCmpInst
argument_list|(
argument|Predicate pred
argument_list|,
comment|///< The predicate to use for the comparison
argument|Value *LHS
argument_list|,
comment|///< The left-hand-side of the expression
argument|Value *RHS
argument_list|,
comment|///< The right-hand-side of the expression
argument|const Twine&NameStr =
literal|""
comment|///< Name of the instruction
argument_list|)
operator|:
name|CmpInst
argument_list|(
argument|makeCmpResultType(LHS->getType())
argument_list|,
argument|Instruction::FCmp
argument_list|,
argument|pred
argument_list|,
argument|LHS
argument_list|,
argument|RHS
argument_list|,
argument|NameStr
argument_list|)
block|{
name|assert
argument_list|(
name|pred
operator|<=
name|FCmpInst
operator|::
name|LAST_FCMP_PREDICATE
operator|&&
literal|"Invalid FCmp predicate value"
argument_list|)
block|;
name|assert
argument_list|(
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|->
name|getType
argument_list|()
operator|==
name|getOperand
argument_list|(
literal|1
argument_list|)
operator|->
name|getType
argument_list|()
operator|&&
literal|"Both operands to FCmp instruction are not of the same type!"
argument_list|)
block|;
comment|// Check that the operands are the right type
name|assert
argument_list|(
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|->
name|getType
argument_list|()
operator|->
name|isFPOrFPVectorTy
argument_list|()
operator|&&
literal|"Invalid operand types for FCmp instruction"
argument_list|)
block|;   }
comment|/// @returns true if the predicate of this instruction is EQ or NE.
comment|/// Determine if this is an equality predicate.
specifier|static
name|bool
name|isEquality
argument_list|(
argument|Predicate Pred
argument_list|)
block|{
return|return
name|Pred
operator|==
name|FCMP_OEQ
operator|||
name|Pred
operator|==
name|FCMP_ONE
operator|||
name|Pred
operator|==
name|FCMP_UEQ
operator|||
name|Pred
operator|==
name|FCMP_UNE
return|;
block|}
comment|/// @returns true if the predicate of this instruction is EQ or NE.
comment|/// Determine if this is an equality predicate.
name|bool
name|isEquality
argument_list|()
specifier|const
block|{
return|return
name|isEquality
argument_list|(
name|getPredicate
argument_list|()
argument_list|)
return|;
block|}
comment|/// @returns true if the predicate of this instruction is commutative.
comment|/// Determine if this is a commutative predicate.
name|bool
name|isCommutative
argument_list|()
specifier|const
block|{
return|return
name|isEquality
argument_list|()
operator|||
name|getPredicate
argument_list|()
operator|==
name|FCMP_FALSE
operator|||
name|getPredicate
argument_list|()
operator|==
name|FCMP_TRUE
operator|||
name|getPredicate
argument_list|()
operator|==
name|FCMP_ORD
operator|||
name|getPredicate
argument_list|()
operator|==
name|FCMP_UNO
return|;
block|}
comment|/// @returns true if the predicate is relational (not EQ or NE).
comment|/// Determine if this a relational predicate.
name|bool
name|isRelational
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isEquality
argument_list|()
return|;
block|}
comment|/// Exchange the two operands to this instruction in such a way that it does
comment|/// not modify the semantics of the instruction. The predicate value may be
comment|/// changed to retain the same result if the predicate is order dependent
comment|/// (e.g. ult).
comment|/// Swap operands and adjust predicate.
name|void
name|swapOperands
argument_list|()
block|{
name|setPredicate
argument_list|(
name|getSwappedPredicate
argument_list|()
argument_list|)
block|;
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
operator|.
name|swap
argument_list|(
name|Op
operator|<
literal|1
operator|>
operator|(
operator|)
argument_list|)
block|;   }
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
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
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents a function call, abstracting a target
comment|/// machine's calling convention.  This class uses low bit of the SubClassData
comment|/// field to indicate whether or not this is a tail call.  The rest of the bits
comment|/// hold the calling convention of the call.
comment|///
name|class
name|CallInst
operator|:
name|public
name|Instruction
block|,
name|public
name|OperandBundleUser
operator|<
name|CallInst
block|,
name|User
operator|::
name|op_iterator
operator|>
block|{
name|friend
name|class
name|OperandBundleUser
operator|<
name|CallInst
block|,
name|User
operator|::
name|op_iterator
operator|>
block|;
name|AttributeList
name|Attrs
block|;
comment|///< parameter attributes for call
name|FunctionType
operator|*
name|FTy
block|;
name|CallInst
argument_list|(
specifier|const
name|CallInst
operator|&
name|CI
argument_list|)
block|;
comment|/// Construct a CallInst given a range of arguments.
comment|/// Construct a CallInst from a range of arguments
specifier|inline
name|CallInst
argument_list|(
name|FunctionType
operator|*
name|Ty
argument_list|,
name|Value
operator|*
name|Func
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Args
argument_list|,
name|ArrayRef
operator|<
name|OperandBundleDef
operator|>
name|Bundles
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
block|;
specifier|inline
name|CallInst
argument_list|(
name|Value
operator|*
name|Func
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Args
argument_list|,
name|ArrayRef
operator|<
name|OperandBundleDef
operator|>
name|Bundles
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
operator|:
name|CallInst
argument_list|(
argument|cast<FunctionType>(                      cast<PointerType>(Func->getType())->getElementType())
argument_list|,
argument|Func
argument_list|,
argument|Args
argument_list|,
argument|Bundles
argument_list|,
argument|NameStr
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
specifier|inline
name|CallInst
argument_list|(
name|Value
operator|*
name|Func
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
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
operator|:
name|CallInst
argument_list|(
argument|Func
argument_list|,
argument|Args
argument_list|,
argument|None
argument_list|,
argument|NameStr
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
comment|/// Construct a CallInst given a range of arguments.
comment|/// Construct a CallInst from a range of arguments
specifier|inline
name|CallInst
argument_list|(
name|Value
operator|*
name|Func
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Args
argument_list|,
name|ArrayRef
operator|<
name|OperandBundleDef
operator|>
name|Bundles
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
name|explicit
name|CallInst
argument_list|(
name|Value
operator|*
name|F
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
block|;
name|CallInst
argument_list|(
name|Value
operator|*
name|F
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
name|void
name|init
argument_list|(
argument|Value *Func
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|ArrayRef<OperandBundleDef> Bundles
argument_list|,
argument|const Twine&NameStr
argument_list|)
block|{
name|init
argument_list|(
name|cast
operator|<
name|FunctionType
operator|>
operator|(
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Func
operator|->
name|getType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
operator|)
argument_list|,
name|Func
argument_list|,
name|Args
argument_list|,
name|Bundles
argument_list|,
name|NameStr
argument_list|)
block|;   }
name|void
name|init
argument_list|(
name|FunctionType
operator|*
name|FTy
argument_list|,
name|Value
operator|*
name|Func
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Args
argument_list|,
name|ArrayRef
operator|<
name|OperandBundleDef
operator|>
name|Bundles
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|)
block|;
name|void
name|init
argument_list|(
name|Value
operator|*
name|Func
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|)
block|;
name|bool
name|hasDescriptor
argument_list|()
specifier|const
block|{
return|return
name|HasDescriptor
return|;
block|}
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|CallInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
specifier|static
name|CallInst
operator|*
name|Create
argument_list|(
argument|Value *Func
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|ArrayRef<OperandBundleDef> Bundles = None
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|cast
operator|<
name|FunctionType
operator|>
operator|(
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Func
operator|->
name|getType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
operator|)
argument_list|,
name|Func
argument_list|,
name|Args
argument_list|,
name|Bundles
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|CallInst
operator|*
name|Create
argument_list|(
argument|Value *Func
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|cast
operator|<
name|FunctionType
operator|>
operator|(
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Func
operator|->
name|getType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
operator|)
argument_list|,
name|Func
argument_list|,
name|Args
argument_list|,
name|None
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|CallInst
operator|*
name|Create
argument_list|(
argument|FunctionType *Ty
argument_list|,
argument|Value *Func
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|unsigned(Args.size() +
literal|1
argument|)
argument_list|)
name|CallInst
argument_list|(
name|Ty
argument_list|,
name|Func
argument_list|,
name|Args
argument_list|,
name|None
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|CallInst
operator|*
name|Create
argument_list|(
argument|FunctionType *Ty
argument_list|,
argument|Value *Func
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|ArrayRef<OperandBundleDef> Bundles = None
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
specifier|const
name|unsigned
name|TotalOps
operator|=
name|unsigned
argument_list|(
name|Args
operator|.
name|size
argument_list|()
argument_list|)
operator|+
name|CountBundleInputs
argument_list|(
name|Bundles
argument_list|)
operator|+
literal|1
block|;
specifier|const
name|unsigned
name|DescriptorBytes
operator|=
name|Bundles
operator|.
name|size
argument_list|()
operator|*
sizeof|sizeof
argument_list|(
name|BundleOpInfo
argument_list|)
block|;
return|return
name|new
argument_list|(
argument|TotalOps
argument_list|,
argument|DescriptorBytes
argument_list|)
name|CallInst
argument_list|(
name|Ty
argument_list|,
name|Func
argument_list|,
name|Args
argument_list|,
name|Bundles
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|CallInst
operator|*
name|Create
argument_list|(
argument|Value *Func
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|ArrayRef<OperandBundleDef> Bundles
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
specifier|const
name|unsigned
name|TotalOps
operator|=
name|unsigned
argument_list|(
name|Args
operator|.
name|size
argument_list|()
argument_list|)
operator|+
name|CountBundleInputs
argument_list|(
name|Bundles
argument_list|)
operator|+
literal|1
block|;
specifier|const
name|unsigned
name|DescriptorBytes
operator|=
name|Bundles
operator|.
name|size
argument_list|()
operator|*
sizeof|sizeof
argument_list|(
name|BundleOpInfo
argument_list|)
block|;
return|return
name|new
argument_list|(
argument|TotalOps
argument_list|,
argument|DescriptorBytes
argument_list|)
name|CallInst
argument_list|(
name|Func
argument_list|,
name|Args
argument_list|,
name|Bundles
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
specifier|static
name|CallInst
operator|*
name|Create
argument_list|(
argument|Value *Func
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|unsigned(Args.size() +
literal|1
argument|)
argument_list|)
name|CallInst
argument_list|(
name|Func
argument_list|,
name|Args
argument_list|,
name|None
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
specifier|static
name|CallInst
operator|*
name|Create
argument_list|(
argument|Value *F
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|1
argument_list|)
name|CallInst
argument_list|(
name|F
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|CallInst
operator|*
name|Create
argument_list|(
argument|Value *F
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|1
argument_list|)
name|CallInst
argument_list|(
name|F
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Create a clone of \p CI with a different set of operand bundles and
comment|/// insert it before \p InsertPt.
comment|///
comment|/// The returned call instruction is identical \p CI in every way except that
comment|/// the operand bundles for the new instruction are set to the operand bundles
comment|/// in \p Bundles.
specifier|static
name|CallInst
operator|*
name|Create
argument_list|(
name|CallInst
operator|*
name|CI
argument_list|,
name|ArrayRef
operator|<
name|OperandBundleDef
operator|>
name|Bundles
argument_list|,
name|Instruction
operator|*
name|InsertPt
operator|=
name|nullptr
argument_list|)
block|;
comment|/// Generate the IR for a call to malloc:
comment|/// 1. Compute the malloc call's argument as the specified type's size,
comment|///    possibly multiplied by the array size if the array size is not
comment|///    constant 1.
comment|/// 2. Call malloc with that argument.
comment|/// 3. Bitcast the result of the malloc call to the specified type.
specifier|static
name|Instruction
operator|*
name|CreateMalloc
argument_list|(
name|Instruction
operator|*
name|InsertBefore
argument_list|,
name|Type
operator|*
name|IntPtrTy
argument_list|,
name|Type
operator|*
name|AllocTy
argument_list|,
name|Value
operator|*
name|AllocSize
argument_list|,
name|Value
operator|*
name|ArraySize
operator|=
name|nullptr
argument_list|,
name|Function
operator|*
name|MallocF
operator|=
name|nullptr
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|)
block|;
specifier|static
name|Instruction
operator|*
name|CreateMalloc
argument_list|(
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|,
name|Type
operator|*
name|IntPtrTy
argument_list|,
name|Type
operator|*
name|AllocTy
argument_list|,
name|Value
operator|*
name|AllocSize
argument_list|,
name|Value
operator|*
name|ArraySize
operator|=
name|nullptr
argument_list|,
name|Function
operator|*
name|MallocF
operator|=
name|nullptr
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|)
block|;
specifier|static
name|Instruction
operator|*
name|CreateMalloc
argument_list|(
name|Instruction
operator|*
name|InsertBefore
argument_list|,
name|Type
operator|*
name|IntPtrTy
argument_list|,
name|Type
operator|*
name|AllocTy
argument_list|,
name|Value
operator|*
name|AllocSize
argument_list|,
name|Value
operator|*
name|ArraySize
operator|=
name|nullptr
argument_list|,
name|ArrayRef
operator|<
name|OperandBundleDef
operator|>
name|Bundles
operator|=
name|None
argument_list|,
name|Function
operator|*
name|MallocF
operator|=
name|nullptr
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|)
block|;
specifier|static
name|Instruction
operator|*
name|CreateMalloc
argument_list|(
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|,
name|Type
operator|*
name|IntPtrTy
argument_list|,
name|Type
operator|*
name|AllocTy
argument_list|,
name|Value
operator|*
name|AllocSize
argument_list|,
name|Value
operator|*
name|ArraySize
operator|=
name|nullptr
argument_list|,
name|ArrayRef
operator|<
name|OperandBundleDef
operator|>
name|Bundles
operator|=
name|None
argument_list|,
name|Function
operator|*
name|MallocF
operator|=
name|nullptr
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|)
block|;
comment|/// Generate the IR for a call to the builtin free function.
specifier|static
name|Instruction
operator|*
name|CreateFree
argument_list|(
name|Value
operator|*
name|Source
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
block|;
specifier|static
name|Instruction
operator|*
name|CreateFree
argument_list|(
name|Value
operator|*
name|Source
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
specifier|static
name|Instruction
operator|*
name|CreateFree
argument_list|(
name|Value
operator|*
name|Source
argument_list|,
name|ArrayRef
operator|<
name|OperandBundleDef
operator|>
name|Bundles
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
block|;
specifier|static
name|Instruction
operator|*
name|CreateFree
argument_list|(
name|Value
operator|*
name|Source
argument_list|,
name|ArrayRef
operator|<
name|OperandBundleDef
operator|>
name|Bundles
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
name|FunctionType
operator|*
name|getFunctionType
argument_list|()
specifier|const
block|{
return|return
name|FTy
return|;
block|}
name|void
name|mutateFunctionType
argument_list|(
argument|FunctionType *FTy
argument_list|)
block|{
name|mutateType
argument_list|(
name|FTy
operator|->
name|getReturnType
argument_list|()
argument_list|)
block|;
name|this
operator|->
name|FTy
operator|=
name|FTy
block|;   }
comment|// Note that 'musttail' implies 'tail'.
expr|enum
name|TailCallKind
block|{
name|TCK_None
operator|=
literal|0
block|,
name|TCK_Tail
operator|=
literal|1
block|,
name|TCK_MustTail
operator|=
literal|2
block|,
name|TCK_NoTail
operator|=
literal|3
block|}
block|;
name|TailCallKind
name|getTailCallKind
argument_list|()
specifier|const
block|{
return|return
name|TailCallKind
argument_list|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|3
argument_list|)
return|;
block|}
name|bool
name|isTailCall
argument_list|()
specifier|const
block|{
name|unsigned
name|Kind
operator|=
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|3
block|;
return|return
name|Kind
operator|==
name|TCK_Tail
operator|||
name|Kind
operator|==
name|TCK_MustTail
return|;
block|}
name|bool
name|isMustTailCall
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|3
operator|)
operator|==
name|TCK_MustTail
return|;
block|}
name|bool
name|isNoTailCall
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|3
operator|)
operator|==
name|TCK_NoTail
return|;
block|}
name|void
name|setTailCall
argument_list|(
argument|bool isTC = true
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
literal|3
operator|)
operator||
name|unsigned
argument_list|(
name|isTC
operator|?
name|TCK_Tail
operator|:
name|TCK_None
argument_list|)
argument_list|)
block|;   }
name|void
name|setTailCallKind
argument_list|(
argument|TailCallKind TCK
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
literal|3
operator|)
operator||
name|unsigned
argument_list|(
name|TCK
argument_list|)
argument_list|)
block|;   }
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|/// Return the number of call arguments.
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
name|getNumTotalBundleOperands
argument_list|()
operator|-
literal|1
return|;
block|}
comment|/// getArgOperand/setArgOperand - Return/set the i-th call argument.
comment|///
name|Value
operator|*
name|getArgOperand
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumArgOperands
argument_list|()
operator|&&
literal|"Out of bounds!"
argument_list|)
block|;
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
name|assert
argument_list|(
name|i
operator|<
name|getNumArgOperands
argument_list|()
operator|&&
literal|"Out of bounds!"
argument_list|)
block|;
name|setOperand
argument_list|(
name|i
argument_list|,
name|v
argument_list|)
block|;   }
comment|/// Return the iterator pointing to the beginning of the argument list.
name|op_iterator
name|arg_begin
argument_list|()
block|{
return|return
name|op_begin
argument_list|()
return|;
block|}
comment|/// Return the iterator pointing to the end of the argument list.
name|op_iterator
name|arg_end
argument_list|()
block|{
comment|// [ call args ], [ operand bundles ], callee
return|return
name|op_end
argument_list|()
operator|-
name|getNumTotalBundleOperands
argument_list|()
operator|-
literal|1
return|;
block|}
comment|/// Iteration adapter for range-for loops.
name|iterator_range
operator|<
name|op_iterator
operator|>
name|arg_operands
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|arg_begin
argument_list|()
argument_list|,
name|arg_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// Return the iterator pointing to the beginning of the argument list.
name|const_op_iterator
name|arg_begin
argument_list|()
specifier|const
block|{
return|return
name|op_begin
argument_list|()
return|;
block|}
comment|/// Return the iterator pointing to the end of the argument list.
name|const_op_iterator
name|arg_end
argument_list|()
specifier|const
block|{
comment|// [ call args ], [ operand bundles ], callee
return|return
name|op_end
argument_list|()
operator|-
name|getNumTotalBundleOperands
argument_list|()
operator|-
literal|1
return|;
block|}
comment|/// Iteration adapter for range-for loops.
name|iterator_range
operator|<
name|const_op_iterator
operator|>
name|arg_operands
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|arg_begin
argument_list|()
argument_list|,
name|arg_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// Wrappers for getting the \c Use of a call argument.
specifier|const
name|Use
operator|&
name|getArgOperandUse
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumArgOperands
argument_list|()
operator|&&
literal|"Out of bounds!"
argument_list|)
block|;
return|return
name|getOperandUse
argument_list|(
name|i
argument_list|)
return|;
block|}
name|Use
operator|&
name|getArgOperandUse
argument_list|(
argument|unsigned i
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumArgOperands
argument_list|()
operator|&&
literal|"Out of bounds!"
argument_list|)
block|;
return|return
name|getOperandUse
argument_list|(
name|i
argument_list|)
return|;
block|}
comment|/// If one of the arguments has the 'returned' attribute, return its
comment|/// operand value. Otherwise, return nullptr.
name|Value
operator|*
name|getReturnedArgOperand
argument_list|()
specifier|const
block|;
comment|/// getCallingConv/setCallingConv - Get or set the calling convention of this
comment|/// function call.
name|CallingConv
operator|::
name|ID
name|getCallingConv
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|CallingConv
operator|::
name|ID
operator|>
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|>>
literal|2
operator|)
return|;
block|}
name|void
name|setCallingConv
argument_list|(
argument|CallingConv::ID CC
argument_list|)
block|{
name|auto
name|ID
operator|=
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|CC
operator|)
block|;
name|assert
argument_list|(
operator|!
operator|(
name|ID
operator|&
operator|~
name|CallingConv
operator|::
name|MaxID
operator|)
operator|&&
literal|"Unsupported calling convention"
argument_list|)
block|;
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|3
operator|)
operator||
operator|(
name|ID
operator|<<
literal|2
operator|)
argument_list|)
block|;   }
comment|/// Return the parameter attributes for this call.
comment|///
name|AttributeList
name|getAttributes
argument_list|()
specifier|const
block|{
return|return
name|Attrs
return|;
block|}
comment|/// Set the parameter attributes for this call.
comment|///
name|void
name|setAttributes
argument_list|(
argument|AttributeList A
argument_list|)
block|{
name|Attrs
operator|=
name|A
block|; }
comment|/// adds the attribute to the list of attributes.
name|void
name|addAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
block|;
comment|/// adds the attribute to the list of attributes.
name|void
name|addAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute Attr
argument_list|)
block|;
comment|/// Adds the attribute to the indicated argument
name|void
name|addParamAttr
argument_list|(
argument|unsigned ArgNo
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
block|;
comment|/// removes the attribute from the list of attributes.
name|void
name|removeAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
block|;
comment|/// removes the attribute from the list of attributes.
name|void
name|removeAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|StringRef Kind
argument_list|)
block|;
comment|/// Removes the attribute from the given argument
name|void
name|removeParamAttr
argument_list|(
argument|unsigned ArgNo
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
block|;
comment|/// adds the dereferenceable attribute to the list of attributes.
name|void
name|addDereferenceableAttr
argument_list|(
argument|unsigned i
argument_list|,
argument|uint64_t Bytes
argument_list|)
block|;
comment|/// adds the dereferenceable_or_null attribute to the list of
comment|/// attributes.
name|void
name|addDereferenceableOrNullAttr
argument_list|(
argument|unsigned i
argument_list|,
argument|uint64_t Bytes
argument_list|)
block|;
comment|/// Determine whether this call has the given attribute.
name|bool
name|hasFnAttr
argument_list|(
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|!=
name|Attribute
operator|::
name|NoBuiltin
operator|&&
literal|"Use CallInst::isNoBuiltin() to check for Attribute::NoBuiltin"
argument_list|)
block|;
return|return
name|hasFnAttrImpl
argument_list|(
name|Kind
argument_list|)
return|;
block|}
comment|/// Determine whether this call has the given attribute.
name|bool
name|hasFnAttr
argument_list|(
argument|StringRef Kind
argument_list|)
specifier|const
block|{
return|return
name|hasFnAttrImpl
argument_list|(
name|Kind
argument_list|)
return|;
block|}
comment|/// Determine whether the return value has the given attribute.
name|bool
name|hasRetAttr
argument_list|(
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|;
comment|/// Determine whether the argument or parameter has the given attribute.
name|bool
name|paramHasAttr
argument_list|(
argument|unsigned ArgNo
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|;
comment|/// Get the attribute of a given kind at a position.
name|Attribute
name|getAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|{
return|return
name|getAttributes
argument_list|()
operator|.
name|getAttribute
argument_list|(
name|i
argument_list|,
name|Kind
argument_list|)
return|;
block|}
comment|/// Get the attribute of a given kind at a position.
name|Attribute
name|getAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|StringRef Kind
argument_list|)
specifier|const
block|{
return|return
name|getAttributes
argument_list|()
operator|.
name|getAttribute
argument_list|(
name|i
argument_list|,
name|Kind
argument_list|)
return|;
block|}
comment|/// Return true if the data operand at index \p i has the attribute \p
comment|/// A.
comment|///
comment|/// Data operands include call arguments and values used in operand bundles,
comment|/// but does not include the callee operand.  This routine dispatches to the
comment|/// underlying AttributeList or the OperandBundleUser as appropriate.
comment|///
comment|/// The index \p i is interpreted as
comment|///
comment|///  \p i == Attribute::ReturnIndex  -> the return value
comment|///  \p i in [1, arg_size + 1)  -> argument number (\p i - 1)
comment|///  \p i in [arg_size + 1, data_operand_size + 1) -> bundle operand at index
comment|///     (\p i - 1) in the operand list.
name|bool
name|dataOperandHasImpliedAttr
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|;
comment|/// Extract the alignment of the return value.
name|unsigned
name|getRetAlignment
argument_list|()
specifier|const
block|{
return|return
name|Attrs
operator|.
name|getRetAlignment
argument_list|()
return|;
block|}
comment|/// Extract the alignment for a call or parameter (0=unknown).
name|unsigned
name|getParamAlignment
argument_list|(
argument|unsigned ArgNo
argument_list|)
specifier|const
block|{
return|return
name|Attrs
operator|.
name|getParamAlignment
argument_list|(
name|ArgNo
argument_list|)
return|;
block|}
comment|/// Extract the number of dereferenceable bytes for a call or
comment|/// parameter (0=unknown).
name|uint64_t
name|getDereferenceableBytes
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|Attrs
operator|.
name|getDereferenceableBytes
argument_list|(
name|i
argument_list|)
return|;
block|}
comment|/// Extract the number of dereferenceable_or_null bytes for a call or
comment|/// parameter (0=unknown).
name|uint64_t
name|getDereferenceableOrNullBytes
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|Attrs
operator|.
name|getDereferenceableOrNullBytes
argument_list|(
name|i
argument_list|)
return|;
block|}
comment|/// @brief Determine if the return value is marked with NoAlias attribute.
name|bool
name|returnDoesNotAlias
argument_list|()
specifier|const
block|{
return|return
name|Attrs
operator|.
name|hasAttribute
argument_list|(
name|AttributeList
operator|::
name|ReturnIndex
argument_list|,
name|Attribute
operator|::
name|NoAlias
argument_list|)
return|;
block|}
comment|/// Return true if the call should not be treated as a call to a
comment|/// builtin.
name|bool
name|isNoBuiltin
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttrImpl
argument_list|(
name|Attribute
operator|::
name|NoBuiltin
argument_list|)
operator|&&
operator|!
name|hasFnAttrImpl
argument_list|(
name|Attribute
operator|::
name|Builtin
argument_list|)
return|;
block|}
comment|/// Return true if the call should not be inlined.
name|bool
name|isNoInline
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|NoInline
argument_list|)
return|;
block|}
name|void
name|setIsNoInline
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|NoInline
argument_list|)
block|;   }
comment|/// Return true if the call can return twice
name|bool
name|canReturnTwice
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|ReturnsTwice
argument_list|)
return|;
block|}
name|void
name|setCanReturnTwice
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|ReturnsTwice
argument_list|)
block|;   }
comment|/// Determine if the call does not access memory.
name|bool
name|doesNotAccessMemory
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|ReadNone
argument_list|)
return|;
block|}
name|void
name|setDoesNotAccessMemory
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|ReadNone
argument_list|)
block|;   }
comment|/// Determine if the call does not access or only reads memory.
name|bool
name|onlyReadsMemory
argument_list|()
specifier|const
block|{
return|return
name|doesNotAccessMemory
argument_list|()
operator|||
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|ReadOnly
argument_list|)
return|;
block|}
name|void
name|setOnlyReadsMemory
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|ReadOnly
argument_list|)
block|;   }
comment|/// Determine if the call does not access or only writes memory.
name|bool
name|doesNotReadMemory
argument_list|()
specifier|const
block|{
return|return
name|doesNotAccessMemory
argument_list|()
operator|||
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|WriteOnly
argument_list|)
return|;
block|}
name|void
name|setDoesNotReadMemory
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|WriteOnly
argument_list|)
block|;   }
comment|/// @brief Determine if the call can access memmory only using pointers based
comment|/// on its arguments.
name|bool
name|onlyAccessesArgMemory
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|ArgMemOnly
argument_list|)
return|;
block|}
name|void
name|setOnlyAccessesArgMemory
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|ArgMemOnly
argument_list|)
block|;   }
comment|/// Determine if the call cannot return.
name|bool
name|doesNotReturn
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|NoReturn
argument_list|)
return|;
block|}
name|void
name|setDoesNotReturn
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|NoReturn
argument_list|)
block|;   }
comment|/// Determine if the call cannot unwind.
name|bool
name|doesNotThrow
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|NoUnwind
argument_list|)
return|;
block|}
name|void
name|setDoesNotThrow
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|NoUnwind
argument_list|)
block|;   }
comment|/// Determine if the call cannot be duplicated.
name|bool
name|cannotDuplicate
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|NoDuplicate
argument_list|)
return|;
block|}
name|void
name|setCannotDuplicate
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|NoDuplicate
argument_list|)
block|;   }
comment|/// Determine if the call is convergent
name|bool
name|isConvergent
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|Convergent
argument_list|)
return|;
block|}
name|void
name|setConvergent
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|Convergent
argument_list|)
block|;   }
name|void
name|setNotConvergent
argument_list|()
block|{
name|removeAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|Convergent
argument_list|)
block|;   }
comment|/// Determine if the call returns a structure through first
comment|/// pointer argument.
name|bool
name|hasStructRetAttr
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getNumArgOperands
argument_list|()
operator|==
literal|0
condition|)
return|return
name|false
return|;
comment|// Be friendly and also check the callee.
return|return
name|paramHasAttr
argument_list|(
literal|0
argument_list|,
name|Attribute
operator|::
name|StructRet
argument_list|)
return|;
block|}
comment|/// Determine if any call argument is an aggregate passed by value.
name|bool
name|hasByValArgument
argument_list|()
specifier|const
block|{
return|return
name|Attrs
operator|.
name|hasAttrSomewhere
argument_list|(
name|Attribute
operator|::
name|ByVal
argument_list|)
return|;
block|}
comment|/// Return the function called, or null if this is an
comment|/// indirect function invocation.
comment|///
name|Function
operator|*
name|getCalledFunction
argument_list|()
specifier|const
block|{
return|return
name|dyn_cast
operator|<
name|Function
operator|>
operator|(
name|Op
operator|<
operator|-
literal|1
operator|>
operator|(
operator|)
operator|)
return|;
block|}
comment|/// Get a pointer to the function that is invoked by this
comment|/// instruction.
specifier|const
name|Value
operator|*
name|getCalledValue
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
name|Value
operator|*
name|getCalledValue
argument_list|()
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
comment|/// Set the function called.
name|void
name|setCalledFunction
argument_list|(
argument|Value* Fn
argument_list|)
block|{
name|setCalledFunction
argument_list|(
name|cast
operator|<
name|FunctionType
operator|>
operator|(
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Fn
operator|->
name|getType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
operator|)
argument_list|,
name|Fn
argument_list|)
block|;   }
name|void
name|setCalledFunction
argument_list|(
argument|FunctionType *FTy
argument_list|,
argument|Value *Fn
argument_list|)
block|{
name|this
operator|->
name|FTy
operator|=
name|FTy
block|;
name|assert
argument_list|(
name|FTy
operator|==
name|cast
operator|<
name|FunctionType
operator|>
operator|(
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Fn
operator|->
name|getType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
operator|)
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
name|Fn
block|;   }
comment|/// Check if this call is an inline asm statement.
name|bool
name|isInlineAsm
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|InlineAsm
operator|>
operator|(
name|Op
operator|<
operator|-
literal|1
operator|>
operator|(
operator|)
operator|)
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
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Call
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
name|private
operator|:
name|template
operator|<
name|typename
name|AttrKind
operator|>
name|bool
name|hasFnAttrImpl
argument_list|(
argument|AttrKind Kind
argument_list|)
specifier|const
block|{
if|if
condition|(
name|Attrs
operator|.
name|hasAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Kind
argument_list|)
condition|)
return|return
name|true
return|;
comment|// Operand bundles override attributes on the called function, but don't
comment|// override attributes directly present on the call instruction.
if|if
condition|(
name|isFnAttrDisallowedByOpBundle
argument_list|(
name|Kind
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
specifier|const
name|Function
modifier|*
name|F
init|=
name|getCalledFunction
argument_list|()
condition|)
return|return
name|F
operator|->
name|getAttributes
argument_list|()
operator|.
name|hasAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Kind
argument_list|)
return|;
return|return
name|false
return|;
block|}
comment|// Shadow Instruction::setInstructionSubclassData with a private forwarding
comment|// method so that subclasses cannot accidentally use it.
name|void
name|setInstructionSubclassData
argument_list|(
argument|unsigned short D
argument_list|)
block|{
name|Instruction
operator|::
name|setInstructionSubclassData
argument_list|(
name|D
argument_list|)
block|;   }
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|CallInst
operator|>
operator|:
name|public
name|VariadicOperandTraits
operator|<
name|CallInst
block|,
literal|1
operator|>
block|{ }
block|;
name|CallInst
operator|::
name|CallInst
argument_list|(
name|Value
operator|*
name|Func
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Args
argument_list|,
name|ArrayRef
operator|<
name|OperandBundleDef
operator|>
name|Bundles
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
operator|:
name|Instruction
argument_list|(
argument|cast<FunctionType>(cast<PointerType>(Func->getType())                                  ->getElementType())->getReturnType()
argument_list|,
argument|Instruction::Call
argument_list|,
argument|OperandTraits<CallInst>::op_end(this) -                                  (Args.size() + CountBundleInputs(Bundles) +
literal|1
argument|)
argument_list|,
argument|unsigned(Args.size() + CountBundleInputs(Bundles) +
literal|1
argument|)
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{
name|init
argument_list|(
name|Func
argument_list|,
name|Args
argument_list|,
name|Bundles
argument_list|,
name|NameStr
argument_list|)
block|; }
name|CallInst
operator|::
name|CallInst
argument_list|(
name|FunctionType
operator|*
name|Ty
argument_list|,
name|Value
operator|*
name|Func
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Args
argument_list|,
name|ArrayRef
operator|<
name|OperandBundleDef
operator|>
name|Bundles
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
operator|:
name|Instruction
argument_list|(
argument|Ty->getReturnType()
argument_list|,
argument|Instruction::Call
argument_list|,
argument|OperandTraits<CallInst>::op_end(this) -                       (Args.size() + CountBundleInputs(Bundles) +
literal|1
argument|)
argument_list|,
argument|unsigned(Args.size() + CountBundleInputs(Bundles) +
literal|1
argument|)
argument_list|,
argument|InsertBefore
argument_list|)
block|{
name|init
argument_list|(
name|Ty
argument_list|,
name|Func
argument_list|,
name|Args
argument_list|,
name|Bundles
argument_list|,
name|NameStr
argument_list|)
block|; }
comment|// Note: if you get compile errors about private methods then
comment|//       please update your code to use the high-level operand
comment|//       interfaces. See line 943 above.
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|CallInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                               SelectInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents the LLVM 'select' instruction.
comment|///
name|class
name|SelectInst
operator|:
name|public
name|Instruction
block|{
name|SelectInst
argument_list|(
name|Value
operator|*
name|C
argument_list|,
name|Value
operator|*
name|S1
argument_list|,
name|Value
operator|*
name|S2
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
operator|:
name|Instruction
argument_list|(
argument|S1->getType()
argument_list|,
argument|Instruction::Select
argument_list|,
argument|&Op<
literal|0
argument|>()
argument_list|,
literal|3
argument_list|,
argument|InsertBefore
argument_list|)
block|{
name|init
argument_list|(
name|C
argument_list|,
name|S1
argument_list|,
name|S2
argument_list|)
block|;
name|setName
argument_list|(
name|NameStr
argument_list|)
block|;   }
name|SelectInst
argument_list|(
name|Value
operator|*
name|C
argument_list|,
name|Value
operator|*
name|S1
argument_list|,
name|Value
operator|*
name|S2
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
operator|:
name|Instruction
argument_list|(
argument|S1->getType()
argument_list|,
argument|Instruction::Select
argument_list|,
argument|&Op<
literal|0
argument|>()
argument_list|,
literal|3
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{
name|init
argument_list|(
name|C
argument_list|,
name|S1
argument_list|,
name|S2
argument_list|)
block|;
name|setName
argument_list|(
name|NameStr
argument_list|)
block|;   }
name|void
name|init
argument_list|(
argument|Value *C
argument_list|,
argument|Value *S1
argument_list|,
argument|Value *S2
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|areInvalidOperands
argument_list|(
name|C
argument_list|,
name|S1
argument_list|,
name|S2
argument_list|)
operator|&&
literal|"Invalid operands for select"
argument_list|)
block|;
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
operator|=
name|C
block|;
name|Op
operator|<
literal|1
operator|>
operator|(
operator|)
operator|=
name|S1
block|;
name|Op
operator|<
literal|2
operator|>
operator|(
operator|)
operator|=
name|S2
block|;   }
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|SelectInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
specifier|static
name|SelectInst
operator|*
name|Create
argument_list|(
argument|Value *C
argument_list|,
argument|Value *S1
argument_list|,
argument|Value *S2
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|,
argument|Instruction *MDFrom = nullptr
argument_list|)
block|{
name|SelectInst
operator|*
name|Sel
operator|=
name|new
argument_list|(
literal|3
argument_list|)
name|SelectInst
argument_list|(
name|C
argument_list|,
name|S1
argument_list|,
name|S2
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
block|;
if|if
condition|(
name|MDFrom
condition|)
name|Sel
operator|->
name|copyMetadata
argument_list|(
operator|*
name|MDFrom
argument_list|)
expr_stmt|;
return|return
name|Sel
return|;
block|}
specifier|static
name|SelectInst
operator|*
name|Create
argument_list|(
argument|Value *C
argument_list|,
argument|Value *S1
argument_list|,
argument|Value *S2
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|3
argument_list|)
name|SelectInst
argument_list|(
name|C
argument_list|,
name|S1
argument_list|,
name|S2
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getCondition
argument_list|()
specifier|const
block|{
return|return
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getTrueValue
argument_list|()
specifier|const
block|{
return|return
name|Op
operator|<
literal|1
operator|>
operator|(
operator|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getFalseValue
argument_list|()
specifier|const
block|{
return|return
name|Op
operator|<
literal|2
operator|>
operator|(
operator|)
return|;
block|}
name|Value
operator|*
name|getCondition
argument_list|()
block|{
return|return
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
return|;
block|}
name|Value
operator|*
name|getTrueValue
argument_list|()
block|{
return|return
name|Op
operator|<
literal|1
operator|>
operator|(
operator|)
return|;
block|}
name|Value
operator|*
name|getFalseValue
argument_list|()
block|{
return|return
name|Op
operator|<
literal|2
operator|>
operator|(
operator|)
return|;
block|}
name|void
name|setCondition
argument_list|(
argument|Value *V
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
block|; }
name|void
name|setTrueValue
argument_list|(
argument|Value *V
argument_list|)
block|{
name|Op
operator|<
literal|1
operator|>
operator|(
operator|)
operator|=
name|V
block|; }
name|void
name|setFalseValue
argument_list|(
argument|Value *V
argument_list|)
block|{
name|Op
operator|<
literal|2
operator|>
operator|(
operator|)
operator|=
name|V
block|; }
comment|/// Return a string if the specified operands are invalid
comment|/// for a select operation, otherwise return null.
specifier|static
specifier|const
name|char
operator|*
name|areInvalidOperands
argument_list|(
name|Value
operator|*
name|Cond
argument_list|,
name|Value
operator|*
name|True
argument_list|,
name|Value
operator|*
name|False
argument_list|)
block|;
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
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
name|Select
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
name|SelectInst
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|SelectInst
block|,
literal|3
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|SelectInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                                VAArgInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents the va_arg llvm instruction, which returns
comment|/// an argument of the specified type given a va_list and increments that list
comment|///
name|class
name|VAArgInst
operator|:
name|public
name|UnaryInstruction
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|VAArgInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
name|VAArgInst
argument_list|(
name|Value
operator|*
name|List
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
operator|=
literal|""
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
argument_list|)
operator|:
name|UnaryInstruction
argument_list|(
argument|Ty
argument_list|,
argument|VAArg
argument_list|,
argument|List
argument_list|,
argument|InsertBefore
argument_list|)
block|{
name|setName
argument_list|(
name|NameStr
argument_list|)
block|;   }
name|VAArgInst
argument_list|(
name|Value
operator|*
name|List
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
operator|:
name|UnaryInstruction
argument_list|(
argument|Ty
argument_list|,
argument|VAArg
argument_list|,
argument|List
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{
name|setName
argument_list|(
name|NameStr
argument_list|)
block|;   }
name|Value
operator|*
name|getPointerOperand
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getPointerOperand
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getPointerOperandIndex
argument_list|()
block|{
return|return
literal|0U
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
name|getOpcode
argument_list|()
operator|==
name|VAArg
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
comment|//                                ExtractElementInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This instruction extracts a single (scalar)
comment|/// element from a VectorType value
comment|///
name|class
name|ExtractElementInst
operator|:
name|public
name|Instruction
block|{
name|ExtractElementInst
argument_list|(
name|Value
operator|*
name|Vec
argument_list|,
name|Value
operator|*
name|Idx
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
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
name|ExtractElementInst
argument_list|(
name|Value
operator|*
name|Vec
argument_list|,
name|Value
operator|*
name|Idx
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|ExtractElementInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
specifier|static
name|ExtractElementInst
operator|*
name|Create
argument_list|(
argument|Value *Vec
argument_list|,
argument|Value *Idx
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|2
argument_list|)
name|ExtractElementInst
argument_list|(
name|Vec
argument_list|,
name|Idx
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|ExtractElementInst
operator|*
name|Create
argument_list|(
argument|Value *Vec
argument_list|,
argument|Value *Idx
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|2
argument_list|)
name|ExtractElementInst
argument_list|(
name|Vec
argument_list|,
name|Idx
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Return true if an extractelement instruction can be
comment|/// formed with the specified operands.
specifier|static
name|bool
name|isValidOperands
argument_list|(
specifier|const
name|Value
operator|*
name|Vec
argument_list|,
specifier|const
name|Value
operator|*
name|Idx
argument_list|)
block|;
name|Value
operator|*
name|getVectorOperand
argument_list|()
block|{
return|return
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
return|;
block|}
name|Value
operator|*
name|getIndexOperand
argument_list|()
block|{
return|return
name|Op
operator|<
literal|1
operator|>
operator|(
operator|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getVectorOperand
argument_list|()
specifier|const
block|{
return|return
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getIndexOperand
argument_list|()
specifier|const
block|{
return|return
name|Op
operator|<
literal|1
operator|>
operator|(
operator|)
return|;
block|}
name|VectorType
operator|*
name|getVectorOperandType
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|VectorType
operator|>
operator|(
name|getVectorOperand
argument_list|()
operator|->
name|getType
argument_list|()
operator|)
return|;
block|}
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
name|ExtractElement
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
name|ExtractElementInst
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|ExtractElementInst
block|,
literal|2
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|ExtractElementInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                                InsertElementInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This instruction inserts a single (scalar)
comment|/// element into a VectorType value
comment|///
name|class
name|InsertElementInst
operator|:
name|public
name|Instruction
block|{
name|InsertElementInst
argument_list|(
name|Value
operator|*
name|Vec
argument_list|,
name|Value
operator|*
name|NewElt
argument_list|,
name|Value
operator|*
name|Idx
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
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
name|InsertElementInst
argument_list|(
name|Value
operator|*
name|Vec
argument_list|,
name|Value
operator|*
name|NewElt
argument_list|,
name|Value
operator|*
name|Idx
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|InsertElementInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
specifier|static
name|InsertElementInst
operator|*
name|Create
argument_list|(
argument|Value *Vec
argument_list|,
argument|Value *NewElt
argument_list|,
argument|Value *Idx
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|3
argument_list|)
name|InsertElementInst
argument_list|(
name|Vec
argument_list|,
name|NewElt
argument_list|,
name|Idx
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|InsertElementInst
operator|*
name|Create
argument_list|(
argument|Value *Vec
argument_list|,
argument|Value *NewElt
argument_list|,
argument|Value *Idx
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|3
argument_list|)
name|InsertElementInst
argument_list|(
name|Vec
argument_list|,
name|NewElt
argument_list|,
name|Idx
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Return true if an insertelement instruction can be
comment|/// formed with the specified operands.
specifier|static
name|bool
name|isValidOperands
argument_list|(
specifier|const
name|Value
operator|*
name|Vec
argument_list|,
specifier|const
name|Value
operator|*
name|NewElt
argument_list|,
specifier|const
name|Value
operator|*
name|Idx
argument_list|)
block|;
comment|/// Overload to return most specific vector type.
comment|///
name|VectorType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|VectorType
operator|>
operator|(
name|Instruction
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
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
name|InsertElement
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
name|InsertElementInst
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|InsertElementInst
block|,
literal|3
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|InsertElementInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                           ShuffleVectorInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This instruction constructs a fixed permutation of two
comment|/// input vectors.
comment|///
name|class
name|ShuffleVectorInst
operator|:
name|public
name|Instruction
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|ShuffleVectorInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
name|ShuffleVectorInst
argument_list|(
name|Value
operator|*
name|V1
argument_list|,
name|Value
operator|*
name|V2
argument_list|,
name|Value
operator|*
name|Mask
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
operator|=
literal|""
argument_list|,
name|Instruction
operator|*
name|InsertBefor
operator|=
name|nullptr
argument_list|)
block|;
name|ShuffleVectorInst
argument_list|(
name|Value
operator|*
name|V1
argument_list|,
name|Value
operator|*
name|V2
argument_list|,
name|Value
operator|*
name|Mask
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
comment|// allocate space for exactly three operands
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
literal|3
argument_list|)
return|;
block|}
comment|/// Return true if a shufflevector instruction can be
comment|/// formed with the specified operands.
specifier|static
name|bool
name|isValidOperands
argument_list|(
specifier|const
name|Value
operator|*
name|V1
argument_list|,
specifier|const
name|Value
operator|*
name|V2
argument_list|,
specifier|const
name|Value
operator|*
name|Mask
argument_list|)
block|;
comment|/// Overload to return most specific vector type.
comment|///
name|VectorType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|VectorType
operator|>
operator|(
name|Instruction
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
name|Constant
operator|*
name|getMask
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Constant
operator|>
operator|(
name|getOperand
argument_list|(
literal|2
argument_list|)
operator|)
return|;
block|}
comment|/// Return the shuffle mask value for the specified element of the mask.
comment|/// Return -1 if the element is undef.
specifier|static
name|int
name|getMaskValue
argument_list|(
argument|Constant *Mask
argument_list|,
argument|unsigned Elt
argument_list|)
block|;
comment|/// Return the shuffle mask value of this instruction for the given element
comment|/// index. Return -1 if the element is undef.
name|int
name|getMaskValue
argument_list|(
argument|unsigned Elt
argument_list|)
specifier|const
block|{
return|return
name|getMaskValue
argument_list|(
name|getMask
argument_list|()
argument_list|,
name|Elt
argument_list|)
return|;
block|}
comment|/// Convert the input shuffle mask operand to a vector of integers. Undefined
comment|/// elements of the mask are returned as -1.
specifier|static
name|void
name|getShuffleMask
argument_list|(
name|Constant
operator|*
name|Mask
argument_list|,
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|Result
argument_list|)
block|;
comment|/// Return the mask for this instruction as a vector of integers. Undefined
comment|/// elements of the mask are returned as -1.
name|void
name|getShuffleMask
argument_list|(
argument|SmallVectorImpl<int>&Result
argument_list|)
specifier|const
block|{
return|return
name|getShuffleMask
argument_list|(
name|getMask
argument_list|()
argument_list|,
name|Result
argument_list|)
return|;
block|}
name|SmallVector
operator|<
name|int
block|,
literal|16
operator|>
name|getShuffleMask
argument_list|()
specifier|const
block|{
name|SmallVector
operator|<
name|int
block|,
literal|16
operator|>
name|Mask
block|;
name|getShuffleMask
argument_list|(
name|Mask
argument_list|)
block|;
return|return
name|Mask
return|;
block|}
comment|/// Change values in a shuffle permute mask assuming the two vector operands
comment|/// of length InVecNumElts have swapped position.
specifier|static
name|void
name|commuteShuffleMask
argument_list|(
argument|MutableArrayRef<int> Mask
argument_list|,
argument|unsigned InVecNumElts
argument_list|)
block|{
for|for
control|(
name|int
modifier|&
name|Idx
range|:
name|Mask
control|)
block|{
if|if
condition|(
name|Idx
operator|==
operator|-
literal|1
condition|)
continue|continue;
name|Idx
operator|=
name|Idx
operator|<
operator|(
name|int
operator|)
name|InVecNumElts
condition|?
name|Idx
operator|+
name|InVecNumElts
else|:
name|Idx
operator|-
name|InVecNumElts
expr_stmt|;
name|assert
argument_list|(
name|Idx
operator|>=
literal|0
operator|&&
name|Idx
operator|<
operator|(
name|int
operator|)
name|InVecNumElts
operator|*
literal|2
operator|&&
literal|"shufflevector mask index out of range"
argument_list|)
expr_stmt|;
block|}
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
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|ShuffleVector
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
name|ShuffleVectorInst
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|ShuffleVectorInst
block|,
literal|3
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|ShuffleVectorInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                                ExtractValueInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This instruction extracts a struct member or array
comment|/// element value from an aggregate value.
comment|///
name|class
name|ExtractValueInst
operator|:
name|public
name|UnaryInstruction
block|{
name|SmallVector
operator|<
name|unsigned
block|,
literal|4
operator|>
name|Indices
block|;
name|ExtractValueInst
argument_list|(
specifier|const
name|ExtractValueInst
operator|&
name|EVI
argument_list|)
block|;
comment|/// Constructors - Create a extractvalue instruction with a base aggregate
comment|/// value and a list of indices.  The first ctor can optionally insert before
comment|/// an existing instruction, the second appends the new instruction to the
comment|/// specified BasicBlock.
specifier|inline
name|ExtractValueInst
argument_list|(
name|Value
operator|*
name|Agg
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Idxs
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
block|;
specifier|inline
name|ExtractValueInst
argument_list|(
name|Value
operator|*
name|Agg
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Idxs
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
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
name|init
argument_list|(
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Idxs
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
name|ExtractValueInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
specifier|static
name|ExtractValueInst
operator|*
name|Create
argument_list|(
argument|Value *Agg
argument_list|,
argument|ArrayRef<unsigned> Idxs
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|new
name|ExtractValueInst
argument_list|(
name|Agg
argument_list|,
name|Idxs
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|ExtractValueInst
operator|*
name|Create
argument_list|(
argument|Value *Agg
argument_list|,
argument|ArrayRef<unsigned> Idxs
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
name|ExtractValueInst
argument_list|(
name|Agg
argument_list|,
name|Idxs
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Returns the type of the element that would be extracted
comment|/// with an extractvalue instruction with the specified parameters.
comment|///
comment|/// Null is returned if the indices are invalid for the specified type.
specifier|static
name|Type
operator|*
name|getIndexedType
argument_list|(
name|Type
operator|*
name|Agg
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Idxs
argument_list|)
block|;
name|using
name|idx_iterator
operator|=
specifier|const
name|unsigned
operator|*
block|;
specifier|inline
name|idx_iterator
name|idx_begin
argument_list|()
specifier|const
block|{
return|return
name|Indices
operator|.
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|idx_iterator
name|idx_end
argument_list|()
specifier|const
block|{
return|return
name|Indices
operator|.
name|end
argument_list|()
return|;
block|}
specifier|inline
name|iterator_range
operator|<
name|idx_iterator
operator|>
name|indices
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|idx_begin
argument_list|()
argument_list|,
name|idx_end
argument_list|()
argument_list|)
return|;
block|}
name|Value
operator|*
name|getAggregateOperand
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getAggregateOperand
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getAggregateOperandIndex
argument_list|()
block|{
return|return
literal|0U
return|;
comment|// get index for modifying correct operand
block|}
name|ArrayRef
operator|<
name|unsigned
operator|>
name|getIndices
argument_list|()
specifier|const
block|{
return|return
name|Indices
return|;
block|}
name|unsigned
name|getNumIndices
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|Indices
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|hasIndices
argument_list|()
specifier|const
block|{
return|return
name|true
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
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|ExtractValue
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
name|ExtractValueInst
operator|::
name|ExtractValueInst
argument_list|(
name|Value
operator|*
name|Agg
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Idxs
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
operator|:
name|UnaryInstruction
argument_list|(
argument|checkGEPType(getIndexedType(Agg->getType(), Idxs))
argument_list|,
argument|ExtractValue
argument_list|,
argument|Agg
argument_list|,
argument|InsertBefore
argument_list|)
block|{
name|init
argument_list|(
name|Idxs
argument_list|,
name|NameStr
argument_list|)
block|; }
name|ExtractValueInst
operator|::
name|ExtractValueInst
argument_list|(
name|Value
operator|*
name|Agg
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Idxs
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
operator|:
name|UnaryInstruction
argument_list|(
argument|checkGEPType(getIndexedType(Agg->getType(), Idxs))
argument_list|,
argument|ExtractValue
argument_list|,
argument|Agg
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{
name|init
argument_list|(
name|Idxs
argument_list|,
name|NameStr
argument_list|)
block|; }
comment|//===----------------------------------------------------------------------===//
comment|//                                InsertValueInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This instruction inserts a struct field of array element
comment|/// value into an aggregate value.
comment|///
name|class
name|InsertValueInst
operator|:
name|public
name|Instruction
block|{
name|SmallVector
operator|<
name|unsigned
block|,
literal|4
operator|>
name|Indices
block|;
name|InsertValueInst
argument_list|(
specifier|const
name|InsertValueInst
operator|&
name|IVI
argument_list|)
block|;
comment|/// Constructors - Create a insertvalue instruction with a base aggregate
comment|/// value, a value to insert, and a list of indices.  The first ctor can
comment|/// optionally insert before an existing instruction, the second appends
comment|/// the new instruction to the specified BasicBlock.
specifier|inline
name|InsertValueInst
argument_list|(
name|Value
operator|*
name|Agg
argument_list|,
name|Value
operator|*
name|Val
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Idxs
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
block|;
specifier|inline
name|InsertValueInst
argument_list|(
name|Value
operator|*
name|Agg
argument_list|,
name|Value
operator|*
name|Val
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Idxs
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
comment|/// Constructors - These two constructors are convenience methods because one
comment|/// and two index insertvalue instructions are so common.
name|InsertValueInst
argument_list|(
argument|Value *Agg
argument_list|,
argument|Value *Val
argument_list|,
argument|unsigned Idx
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|InsertValueInst
argument_list|(
argument|Value *Agg
argument_list|,
argument|Value *Val
argument_list|,
argument|unsigned Idx
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
name|Agg
argument_list|,
name|Value
operator|*
name|Val
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Idxs
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
name|InsertValueInst
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
specifier|static
name|InsertValueInst
operator|*
name|Create
argument_list|(
argument|Value *Agg
argument_list|,
argument|Value *Val
argument_list|,
argument|ArrayRef<unsigned> Idxs
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|new
name|InsertValueInst
argument_list|(
name|Agg
argument_list|,
name|Val
argument_list|,
name|Idxs
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|InsertValueInst
operator|*
name|Create
argument_list|(
argument|Value *Agg
argument_list|,
argument|Value *Val
argument_list|,
argument|ArrayRef<unsigned> Idxs
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
name|InsertValueInst
argument_list|(
name|Agg
argument_list|,
name|Val
argument_list|,
name|Idxs
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
name|using
name|idx_iterator
operator|=
specifier|const
name|unsigned
operator|*
block|;
specifier|inline
name|idx_iterator
name|idx_begin
argument_list|()
specifier|const
block|{
return|return
name|Indices
operator|.
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|idx_iterator
name|idx_end
argument_list|()
specifier|const
block|{
return|return
name|Indices
operator|.
name|end
argument_list|()
return|;
block|}
specifier|inline
name|iterator_range
operator|<
name|idx_iterator
operator|>
name|indices
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|idx_begin
argument_list|()
argument_list|,
name|idx_end
argument_list|()
argument_list|)
return|;
block|}
name|Value
operator|*
name|getAggregateOperand
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getAggregateOperand
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getAggregateOperandIndex
argument_list|()
block|{
return|return
literal|0U
return|;
comment|// get index for modifying correct operand
block|}
name|Value
operator|*
name|getInsertedValueOperand
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|1
argument_list|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getInsertedValueOperand
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|1
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getInsertedValueOperandIndex
argument_list|()
block|{
return|return
literal|1U
return|;
comment|// get index for modifying correct operand
block|}
name|ArrayRef
operator|<
name|unsigned
operator|>
name|getIndices
argument_list|()
specifier|const
block|{
return|return
name|Indices
return|;
block|}
name|unsigned
name|getNumIndices
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|Indices
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|hasIndices
argument_list|()
specifier|const
block|{
return|return
name|true
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
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|InsertValue
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
name|InsertValueInst
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|InsertValueInst
block|,
literal|2
operator|>
block|{ }
block|;
name|InsertValueInst
operator|::
name|InsertValueInst
argument_list|(
name|Value
operator|*
name|Agg
argument_list|,
name|Value
operator|*
name|Val
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Idxs
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
operator|:
name|Instruction
argument_list|(
argument|Agg->getType()
argument_list|,
argument|InsertValue
argument_list|,
argument|OperandTraits<InsertValueInst>::op_begin(this)
argument_list|,
literal|2
argument_list|,
argument|InsertBefore
argument_list|)
block|{
name|init
argument_list|(
name|Agg
argument_list|,
name|Val
argument_list|,
name|Idxs
argument_list|,
name|NameStr
argument_list|)
block|; }
name|InsertValueInst
operator|::
name|InsertValueInst
argument_list|(
name|Value
operator|*
name|Agg
argument_list|,
name|Value
operator|*
name|Val
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Idxs
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
operator|:
name|Instruction
argument_list|(
argument|Agg->getType()
argument_list|,
argument|InsertValue
argument_list|,
argument|OperandTraits<InsertValueInst>::op_begin(this)
argument_list|,
literal|2
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{
name|init
argument_list|(
name|Agg
argument_list|,
name|Val
argument_list|,
name|Idxs
argument_list|,
name|NameStr
argument_list|)
block|; }
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|InsertValueInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                               PHINode Class
comment|//===----------------------------------------------------------------------===//
comment|// PHINode - The PHINode class is used to represent the magical mystical PHI
comment|// node, that can not exist in nature, but can be synthesized in a computer
comment|// scientist's overactive imagination.
comment|//
name|class
name|PHINode
operator|:
name|public
name|Instruction
block|{
comment|/// The number of operands actually allocated.  NumOperands is
comment|/// the number actually in use.
name|unsigned
name|ReservedSpace
block|;
name|PHINode
argument_list|(
specifier|const
name|PHINode
operator|&
name|PN
argument_list|)
block|;
comment|// allocate space for exactly zero operands
name|explicit
name|PHINode
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned NumReservedValues
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
operator|:
name|Instruction
argument_list|(
name|Ty
argument_list|,
name|Instruction
operator|::
name|PHI
argument_list|,
name|nullptr
argument_list|,
literal|0
argument_list|,
name|InsertBefore
argument_list|)
block|,
name|ReservedSpace
argument_list|(
argument|NumReservedValues
argument_list|)
block|{
name|setName
argument_list|(
name|NameStr
argument_list|)
block|;
name|allocHungoffUses
argument_list|(
name|ReservedSpace
argument_list|)
block|;   }
name|PHINode
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned NumReservedValues
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
operator|:
name|Instruction
argument_list|(
name|Ty
argument_list|,
name|Instruction
operator|::
name|PHI
argument_list|,
name|nullptr
argument_list|,
literal|0
argument_list|,
name|InsertAtEnd
argument_list|)
block|,
name|ReservedSpace
argument_list|(
argument|NumReservedValues
argument_list|)
block|{
name|setName
argument_list|(
name|NameStr
argument_list|)
block|;
name|allocHungoffUses
argument_list|(
name|ReservedSpace
argument_list|)
block|;   }
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
argument_list|)
return|;
block|}
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|PHINode
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
comment|// allocHungoffUses - this is more complicated than the generic
comment|// User::allocHungoffUses, because we have to allocate Uses for the incoming
comment|// values and pointers to the incoming blocks, all in one allocation.
name|void
name|allocHungoffUses
argument_list|(
argument|unsigned N
argument_list|)
block|{
name|User
operator|::
name|allocHungoffUses
argument_list|(
name|N
argument_list|,
comment|/* IsPhi */
name|true
argument_list|)
block|;   }
name|public
operator|:
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
comment|/// Constructors - NumReservedValues is a hint for the number of incoming
comment|/// edges that this phi node will have (use 0 if you really have no idea).
specifier|static
name|PHINode
operator|*
name|Create
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned NumReservedValues
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|new
name|PHINode
argument_list|(
name|Ty
argument_list|,
name|NumReservedValues
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|PHINode
operator|*
name|Create
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned NumReservedValues
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
name|PHINode
argument_list|(
name|Ty
argument_list|,
name|NumReservedValues
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|// Block iterator interface. This provides access to the list of incoming
comment|// basic blocks, which parallels the list of incoming values.
name|using
name|block_iterator
operator|=
name|BasicBlock
operator|*
operator|*
block|;
name|using
name|const_block_iterator
operator|=
name|BasicBlock
operator|*
specifier|const
operator|*
block|;
name|block_iterator
name|block_begin
argument_list|()
block|{
name|Use
operator|::
name|UserRef
operator|*
name|ref
operator|=
name|reinterpret_cast
operator|<
name|Use
operator|::
name|UserRef
operator|*
operator|>
operator|(
name|op_begin
argument_list|()
operator|+
name|ReservedSpace
operator|)
block|;
return|return
name|reinterpret_cast
operator|<
name|block_iterator
operator|>
operator|(
name|ref
operator|+
literal|1
operator|)
return|;
block|}
name|const_block_iterator
name|block_begin
argument_list|()
specifier|const
block|{
specifier|const
name|Use
operator|::
name|UserRef
operator|*
name|ref
operator|=
name|reinterpret_cast
operator|<
specifier|const
name|Use
operator|::
name|UserRef
operator|*
operator|>
operator|(
name|op_begin
argument_list|()
operator|+
name|ReservedSpace
operator|)
block|;
return|return
name|reinterpret_cast
operator|<
name|const_block_iterator
operator|>
operator|(
name|ref
operator|+
literal|1
operator|)
return|;
block|}
name|block_iterator
name|block_end
argument_list|()
block|{
return|return
name|block_begin
argument_list|()
operator|+
name|getNumOperands
argument_list|()
return|;
block|}
name|const_block_iterator
name|block_end
argument_list|()
specifier|const
block|{
return|return
name|block_begin
argument_list|()
operator|+
name|getNumOperands
argument_list|()
return|;
block|}
name|iterator_range
operator|<
name|block_iterator
operator|>
name|blocks
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|block_begin
argument_list|()
argument_list|,
name|block_end
argument_list|()
argument_list|)
return|;
block|}
name|iterator_range
operator|<
name|const_block_iterator
operator|>
name|blocks
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|block_begin
argument_list|()
argument_list|,
name|block_end
argument_list|()
argument_list|)
return|;
block|}
name|op_range
name|incoming_values
argument_list|()
block|{
return|return
name|operands
argument_list|()
return|;
block|}
name|const_op_range
name|incoming_values
argument_list|()
specifier|const
block|{
return|return
name|operands
argument_list|()
return|;
block|}
comment|/// Return the number of incoming edges
comment|///
name|unsigned
name|getNumIncomingValues
argument_list|()
specifier|const
block|{
return|return
name|getNumOperands
argument_list|()
return|;
block|}
comment|/// Return incoming value number x
comment|///
name|Value
operator|*
name|getIncomingValue
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
name|setIncomingValue
argument_list|(
argument|unsigned i
argument_list|,
argument|Value *V
argument_list|)
block|{
name|assert
argument_list|(
name|V
operator|&&
literal|"PHI node got a null value!"
argument_list|)
block|;
name|assert
argument_list|(
name|getType
argument_list|()
operator|==
name|V
operator|->
name|getType
argument_list|()
operator|&&
literal|"All operands to PHI node must be the same type as the PHI node!"
argument_list|)
block|;
name|setOperand
argument_list|(
name|i
argument_list|,
name|V
argument_list|)
block|;   }
specifier|static
name|unsigned
name|getOperandNumForIncomingValue
argument_list|(
argument|unsigned i
argument_list|)
block|{
return|return
name|i
return|;
block|}
specifier|static
name|unsigned
name|getIncomingValueNumForOperand
argument_list|(
argument|unsigned i
argument_list|)
block|{
return|return
name|i
return|;
block|}
comment|/// Return incoming basic block number @p i.
comment|///
name|BasicBlock
operator|*
name|getIncomingBlock
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|block_begin
argument_list|()
index|[
name|i
index|]
return|;
block|}
comment|/// Return incoming basic block corresponding
comment|/// to an operand of the PHI.
comment|///
name|BasicBlock
operator|*
name|getIncomingBlock
argument_list|(
argument|const Use&U
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|this
operator|==
name|U
operator|.
name|getUser
argument_list|()
operator|&&
literal|"Iterator doesn't point to PHI's Uses?"
argument_list|)
block|;
return|return
name|getIncomingBlock
argument_list|(
name|unsigned
argument_list|(
operator|&
name|U
operator|-
name|op_begin
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
comment|/// Return incoming basic block corresponding
comment|/// to value use iterator.
comment|///
name|BasicBlock
operator|*
name|getIncomingBlock
argument_list|(
argument|Value::const_user_iterator I
argument_list|)
specifier|const
block|{
return|return
name|getIncomingBlock
argument_list|(
name|I
operator|.
name|getUse
argument_list|()
argument_list|)
return|;
block|}
name|void
name|setIncomingBlock
argument_list|(
argument|unsigned i
argument_list|,
argument|BasicBlock *BB
argument_list|)
block|{
name|assert
argument_list|(
name|BB
operator|&&
literal|"PHI node got a null basic block!"
argument_list|)
block|;
name|block_begin
argument_list|()
index|[
name|i
index|]
operator|=
name|BB
block|;   }
comment|/// Add an incoming value to the end of the PHI list
comment|///
name|void
name|addIncoming
argument_list|(
argument|Value *V
argument_list|,
argument|BasicBlock *BB
argument_list|)
block|{
if|if
condition|(
name|getNumOperands
argument_list|()
operator|==
name|ReservedSpace
condition|)
name|growOperands
argument_list|()
expr_stmt|;
comment|// Get more space!
comment|// Initialize some new operands.
name|setNumHungOffUseOperands
argument_list|(
name|getNumOperands
argument_list|()
operator|+
literal|1
argument_list|)
block|;
name|setIncomingValue
argument_list|(
name|getNumOperands
argument_list|()
operator|-
literal|1
argument_list|,
name|V
argument_list|)
block|;
name|setIncomingBlock
argument_list|(
name|getNumOperands
argument_list|()
operator|-
literal|1
argument_list|,
name|BB
argument_list|)
block|;   }
comment|/// Remove an incoming value.  This is useful if a
comment|/// predecessor basic block is deleted.  The value removed is returned.
comment|///
comment|/// If the last incoming value for a PHI node is removed (and DeletePHIIfEmpty
comment|/// is true), the PHI node is destroyed and any uses of it are replaced with
comment|/// dummy values.  The only time there should be zero incoming values to a PHI
comment|/// node is when the block is dead, so this strategy is sound.
comment|///
name|Value
operator|*
name|removeIncomingValue
argument_list|(
argument|unsigned Idx
argument_list|,
argument|bool DeletePHIIfEmpty = true
argument_list|)
block|;
name|Value
operator|*
name|removeIncomingValue
argument_list|(
argument|const BasicBlock *BB
argument_list|,
argument|bool DeletePHIIfEmpty=true
argument_list|)
block|{
name|int
name|Idx
operator|=
name|getBasicBlockIndex
argument_list|(
name|BB
argument_list|)
block|;
name|assert
argument_list|(
name|Idx
operator|>=
literal|0
operator|&&
literal|"Invalid basic block argument to remove!"
argument_list|)
block|;
return|return
name|removeIncomingValue
argument_list|(
name|Idx
argument_list|,
name|DeletePHIIfEmpty
argument_list|)
return|;
block|}
comment|/// Return the first index of the specified basic
comment|/// block in the value list for this PHI.  Returns -1 if no instance.
comment|///
name|int
name|getBasicBlockIndex
argument_list|(
argument|const BasicBlock *BB
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
name|getNumOperands
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
name|block_begin
argument_list|()
index|[
name|i
index|]
operator|==
name|BB
condition|)
return|return
name|i
return|;
return|return
operator|-
literal|1
return|;
block|}
name|Value
operator|*
name|getIncomingValueForBlock
argument_list|(
argument|const BasicBlock *BB
argument_list|)
specifier|const
block|{
name|int
name|Idx
operator|=
name|getBasicBlockIndex
argument_list|(
name|BB
argument_list|)
block|;
name|assert
argument_list|(
name|Idx
operator|>=
literal|0
operator|&&
literal|"Invalid basic block argument!"
argument_list|)
block|;
return|return
name|getIncomingValue
argument_list|(
name|Idx
argument_list|)
return|;
block|}
comment|/// If the specified PHI node always merges together the
comment|/// same value, return the value, otherwise return null.
name|Value
operator|*
name|hasConstantValue
argument_list|()
specifier|const
block|;
comment|/// Whether the specified PHI node always merges
comment|/// together the same value, assuming undefs are equal to a unique
comment|/// non-undef value.
name|bool
name|hasConstantOrUndefValue
argument_list|()
specifier|const
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|PHI
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
name|private
operator|:
name|void
name|growOperands
argument_list|()
block|; }
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|PHINode
operator|>
operator|:
name|public
name|HungoffOperandTraits
operator|<
literal|2
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|PHINode
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                           LandingPadInst Class
comment|//===----------------------------------------------------------------------===//
comment|//===---------------------------------------------------------------------------
comment|/// The landingpad instruction holds all of the information
comment|/// necessary to generate correct exception handling. The landingpad instruction
comment|/// cannot be moved from the top of a landing pad block, which itself is
comment|/// accessible only from the 'unwind' edge of an invoke. This uses the
comment|/// SubclassData field in Value to store whether or not the landingpad is a
comment|/// cleanup.
comment|///
name|class
name|LandingPadInst
operator|:
name|public
name|Instruction
block|{
comment|/// The number of operands actually allocated.  NumOperands is
comment|/// the number actually in use.
name|unsigned
name|ReservedSpace
block|;
name|LandingPadInst
argument_list|(
specifier|const
name|LandingPadInst
operator|&
name|LP
argument_list|)
block|;
name|public
operator|:
expr|enum
name|ClauseType
block|{
name|Catch
block|,
name|Filter
block|}
block|;
name|private
operator|:
name|explicit
name|LandingPadInst
argument_list|(
argument|Type *RetTy
argument_list|,
argument|unsigned NumReservedValues
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
block|;
name|explicit
name|LandingPadInst
argument_list|(
argument|Type *RetTy
argument_list|,
argument|unsigned NumReservedValues
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
comment|// Allocate space for exactly zero operands.
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
argument_list|)
return|;
block|}
name|void
name|growOperands
argument_list|(
argument|unsigned Size
argument_list|)
block|;
name|void
name|init
argument_list|(
argument|unsigned NumReservedValues
argument_list|,
argument|const Twine&NameStr
argument_list|)
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|LandingPadInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
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
comment|/// Constructors - NumReservedClauses is a hint for the number of incoming
comment|/// clauses that this landingpad will have (use 0 if you really have no idea).
specifier|static
name|LandingPadInst
operator|*
name|Create
argument_list|(
argument|Type *RetTy
argument_list|,
argument|unsigned NumReservedClauses
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
specifier|static
name|LandingPadInst
operator|*
name|Create
argument_list|(
argument|Type *RetTy
argument_list|,
argument|unsigned NumReservedClauses
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|/// Return 'true' if this landingpad instruction is a
comment|/// cleanup. I.e., it should be run when unwinding even if its landing pad
comment|/// doesn't catch the exception.
name|bool
name|isCleanup
argument_list|()
specifier|const
block|{
return|return
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|1
return|;
block|}
comment|/// Indicate that this landingpad instruction is a cleanup.
name|void
name|setCleanup
argument_list|(
argument|bool V
argument_list|)
block|{
name|setInstructionSubclassData
argument_list|(
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|&
operator|~
literal|1
operator|)
operator||
operator|(
name|V
operator|?
literal|1
operator|:
literal|0
operator|)
argument_list|)
block|;   }
comment|/// Add a catch or filter clause to the landing pad.
name|void
name|addClause
argument_list|(
name|Constant
operator|*
name|ClauseVal
argument_list|)
block|;
comment|/// Get the value of the clause at index Idx. Use isCatch/isFilter to
comment|/// determine what type of clause this is.
name|Constant
operator|*
name|getClause
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
return|return
name|cast
operator|<
name|Constant
operator|>
operator|(
name|getOperandList
argument_list|()
index|[
name|Idx
index|]
operator|)
return|;
block|}
comment|/// Return 'true' if the clause and index Idx is a catch clause.
name|bool
name|isCatch
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
return|return
operator|!
name|isa
operator|<
name|ArrayType
operator|>
operator|(
name|getOperandList
argument_list|()
index|[
name|Idx
index|]
operator|->
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// Return 'true' if the clause and index Idx is a filter clause.
name|bool
name|isFilter
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
return|return
name|isa
operator|<
name|ArrayType
operator|>
operator|(
name|getOperandList
argument_list|()
index|[
name|Idx
index|]
operator|->
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// Get the number of clauses for this landing pad.
name|unsigned
name|getNumClauses
argument_list|()
specifier|const
block|{
return|return
name|getNumOperands
argument_list|()
return|;
block|}
comment|/// Grow the size of the operand list to accommodate the new
comment|/// number of clauses.
name|void
name|reserveClauses
argument_list|(
argument|unsigned Size
argument_list|)
block|{
name|growOperands
argument_list|(
name|Size
argument_list|)
block|; }
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
name|LandingPad
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
name|LandingPadInst
operator|>
operator|:
name|public
name|HungoffOperandTraits
operator|<
literal|1
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|LandingPadInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                               ReturnInst Class
comment|//===----------------------------------------------------------------------===//
comment|//===---------------------------------------------------------------------------
comment|/// Return a value (possibly void), from a function.  Execution
comment|/// does not continue in this function any longer.
comment|///
name|class
name|ReturnInst
operator|:
name|public
name|TerminatorInst
block|{
name|ReturnInst
argument_list|(
specifier|const
name|ReturnInst
operator|&
name|RI
argument_list|)
block|;
name|private
operator|:
comment|// ReturnInst constructors:
comment|// ReturnInst()                  - 'ret void' instruction
comment|// ReturnInst(    null)          - 'ret void' instruction
comment|// ReturnInst(Value* X)          - 'ret X'    instruction
comment|// ReturnInst(    null, Inst *I) - 'ret void' instruction, insert before I
comment|// ReturnInst(Value* X, Inst *I) - 'ret X'    instruction, insert before I
comment|// ReturnInst(    null, BB *B)   - 'ret void' instruction, insert @ end of B
comment|// ReturnInst(Value* X, BB *B)   - 'ret X'    instruction, insert @ end of B
comment|//
comment|// NOTE: If the Value* passed is of type void then the constructor behaves as
comment|// if it was passed NULL.
name|explicit
name|ReturnInst
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|Value
operator|*
name|retVal
operator|=
name|nullptr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
argument_list|)
block|;
name|ReturnInst
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|Value
operator|*
name|retVal
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
name|explicit
name|ReturnInst
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|ReturnInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
specifier|static
name|ReturnInst
operator|*
name|Create
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|Value *retVal = nullptr
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|!!retVal
argument_list|)
name|ReturnInst
argument_list|(
name|C
argument_list|,
name|retVal
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|ReturnInst
operator|*
name|Create
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|Value *retVal
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|!!retVal
argument_list|)
name|ReturnInst
argument_list|(
name|C
argument_list|,
name|retVal
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
specifier|static
name|ReturnInst
operator|*
name|Create
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|0
argument_list|)
name|ReturnInst
argument_list|(
name|C
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|/// Convenience accessor. Returns null if there is no return value.
name|Value
operator|*
name|getReturnValue
argument_list|()
specifier|const
block|{
return|return
name|getNumOperands
argument_list|()
operator|!=
literal|0
condition|?
name|getOperand
argument_list|(
literal|0
argument_list|)
else|:
name|nullptr
return|;
block|}
name|unsigned
name|getNumSuccessors
argument_list|()
specifier|const
block|{
return|return
literal|0
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
operator|(
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Ret
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
name|private
operator|:
name|friend
name|TerminatorInst
block|;
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|;
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|void
name|setSuccessorV
argument_list|(
argument|unsigned idx
argument_list|,
argument|BasicBlock *B
argument_list|)
block|; }
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|ReturnInst
operator|>
operator|:
name|public
name|VariadicOperandTraits
operator|<
name|ReturnInst
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|ReturnInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                               BranchInst Class
comment|//===----------------------------------------------------------------------===//
comment|//===---------------------------------------------------------------------------
comment|/// Conditional or Unconditional Branch instruction.
comment|///
name|class
name|BranchInst
operator|:
name|public
name|TerminatorInst
block|{
comment|/// Ops list - Branches are strange.  The operands are ordered:
comment|///  [Cond, FalseDest,] TrueDest.  This makes some accessors faster because
comment|/// they don't have to check for cond/uncond branchness. These are mostly
comment|/// accessed relative from op_end().
name|BranchInst
argument_list|(
specifier|const
name|BranchInst
operator|&
name|BI
argument_list|)
block|;
comment|// BranchInst constructors (where {B, T, F} are blocks, and C is a condition):
comment|// BranchInst(BB *B)                           - 'br B'
comment|// BranchInst(BB* T, BB *F, Value *C)          - 'br C, T, F'
comment|// BranchInst(BB* B, Inst *I)                  - 'br B'        insert before I
comment|// BranchInst(BB* T, BB *F, Value *C, Inst *I) - 'br C, T, F', insert before I
comment|// BranchInst(BB* B, BB *I)                    - 'br B'        insert at end
comment|// BranchInst(BB* T, BB *F, Value *C, BB *I)   - 'br C, T, F', insert at end
name|explicit
name|BranchInst
argument_list|(
name|BasicBlock
operator|*
name|IfTrue
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
argument_list|)
block|;
name|BranchInst
argument_list|(
name|BasicBlock
operator|*
name|IfTrue
argument_list|,
name|BasicBlock
operator|*
name|IfFalse
argument_list|,
name|Value
operator|*
name|Cond
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
argument_list|)
block|;
name|BranchInst
argument_list|(
name|BasicBlock
operator|*
name|IfTrue
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
name|BranchInst
argument_list|(
name|BasicBlock
operator|*
name|IfTrue
argument_list|,
name|BasicBlock
operator|*
name|IfFalse
argument_list|,
name|Value
operator|*
name|Cond
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
name|void
name|AssertOK
argument_list|()
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|BranchInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
specifier|static
name|BranchInst
operator|*
name|Create
argument_list|(
argument|BasicBlock *IfTrue
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|1
argument_list|)
name|BranchInst
argument_list|(
name|IfTrue
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|BranchInst
operator|*
name|Create
argument_list|(
argument|BasicBlock *IfTrue
argument_list|,
argument|BasicBlock *IfFalse
argument_list|,
argument|Value *Cond
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|3
argument_list|)
name|BranchInst
argument_list|(
name|IfTrue
argument_list|,
name|IfFalse
argument_list|,
name|Cond
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|BranchInst
operator|*
name|Create
argument_list|(
argument|BasicBlock *IfTrue
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|1
argument_list|)
name|BranchInst
argument_list|(
name|IfTrue
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
specifier|static
name|BranchInst
operator|*
name|Create
argument_list|(
argument|BasicBlock *IfTrue
argument_list|,
argument|BasicBlock *IfFalse
argument_list|,
argument|Value *Cond
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|3
argument_list|)
name|BranchInst
argument_list|(
name|IfTrue
argument_list|,
name|IfFalse
argument_list|,
name|Cond
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
name|bool
name|isUnconditional
argument_list|()
specifier|const
block|{
return|return
name|getNumOperands
argument_list|()
operator|==
literal|1
return|;
block|}
name|bool
name|isConditional
argument_list|()
specifier|const
block|{
return|return
name|getNumOperands
argument_list|()
operator|==
literal|3
return|;
block|}
name|Value
operator|*
name|getCondition
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isConditional
argument_list|()
operator|&&
literal|"Cannot get condition of an uncond branch!"
argument_list|)
block|;
return|return
name|Op
operator|<
operator|-
literal|3
operator|>
operator|(
operator|)
return|;
block|}
name|void
name|setCondition
argument_list|(
argument|Value *V
argument_list|)
block|{
name|assert
argument_list|(
name|isConditional
argument_list|()
operator|&&
literal|"Cannot set condition of unconditional branch!"
argument_list|)
block|;
name|Op
operator|<
operator|-
literal|3
operator|>
operator|(
operator|)
operator|=
name|V
block|;   }
name|unsigned
name|getNumSuccessors
argument_list|()
specifier|const
block|{
return|return
literal|1
operator|+
name|isConditional
argument_list|()
return|;
block|}
name|BasicBlock
operator|*
name|getSuccessor
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumSuccessors
argument_list|()
operator|&&
literal|"Successor # out of range for Branch!"
argument_list|)
block|;
return|return
name|cast_or_null
operator|<
name|BasicBlock
operator|>
operator|(
operator|(
operator|&
name|Op
operator|<
operator|-
literal|1
operator|>
operator|(
operator|)
operator|-
name|i
operator|)
operator|->
name|get
argument_list|()
operator|)
return|;
block|}
name|void
name|setSuccessor
argument_list|(
argument|unsigned idx
argument_list|,
argument|BasicBlock *NewSucc
argument_list|)
block|{
name|assert
argument_list|(
name|idx
operator|<
name|getNumSuccessors
argument_list|()
operator|&&
literal|"Successor # out of range for Branch!"
argument_list|)
block|;
operator|*
operator|(
operator|&
name|Op
operator|<
operator|-
literal|1
operator|>
operator|(
operator|)
operator|-
name|idx
operator|)
operator|=
name|NewSucc
block|;   }
comment|/// Swap the successors of this branch instruction.
comment|///
comment|/// Swaps the successors of the branch instruction. This also swaps any
comment|/// branch weight metadata associated with the instruction so that it
comment|/// continues to map correctly to each operand.
name|void
name|swapSuccessors
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
operator|(
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Br
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
name|private
operator|:
name|friend
name|TerminatorInst
block|;
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|;
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|void
name|setSuccessorV
argument_list|(
argument|unsigned idx
argument_list|,
argument|BasicBlock *B
argument_list|)
block|; }
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|BranchInst
operator|>
operator|:
name|public
name|VariadicOperandTraits
operator|<
name|BranchInst
block|,
literal|1
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|BranchInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                               SwitchInst Class
comment|//===----------------------------------------------------------------------===//
comment|//===---------------------------------------------------------------------------
comment|/// Multiway switch
comment|///
name|class
name|SwitchInst
operator|:
name|public
name|TerminatorInst
block|{
name|unsigned
name|ReservedSpace
block|;
comment|// Operand[0]    = Value to switch on
comment|// Operand[1]    = Default basic block destination
comment|// Operand[2n  ] = Value to match
comment|// Operand[2n+1] = BasicBlock to go to on match
name|SwitchInst
argument_list|(
specifier|const
name|SwitchInst
operator|&
name|SI
argument_list|)
block|;
comment|/// Create a new switch instruction, specifying a value to switch on and a
comment|/// default destination. The number of additional cases can be specified here
comment|/// to make memory allocation more efficient. This constructor can also
comment|/// auto-insert before another instruction.
name|SwitchInst
argument_list|(
argument|Value *Value
argument_list|,
argument|BasicBlock *Default
argument_list|,
argument|unsigned NumCases
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
block|;
comment|/// Create a new switch instruction, specifying a value to switch on and a
comment|/// default destination. The number of additional cases can be specified here
comment|/// to make memory allocation more efficient. This constructor also
comment|/// auto-inserts at the end of the specified BasicBlock.
name|SwitchInst
argument_list|(
argument|Value *Value
argument_list|,
argument|BasicBlock *Default
argument_list|,
argument|unsigned NumCases
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
comment|// allocate space for exactly zero operands
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
argument_list|)
return|;
block|}
name|void
name|init
argument_list|(
argument|Value *Value
argument_list|,
argument|BasicBlock *Default
argument_list|,
argument|unsigned NumReserved
argument_list|)
block|;
name|void
name|growOperands
argument_list|()
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|SwitchInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
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
comment|// -2
specifier|static
specifier|const
name|unsigned
name|DefaultPseudoIndex
operator|=
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
operator|~
literal|0L
operator|-
literal|1
operator|)
block|;
name|template
operator|<
name|typename
name|CaseHandleT
operator|>
name|class
name|CaseIteratorImpl
block|;
comment|/// A handle to a particular switch case. It exposes a convenient interface
comment|/// to both the case value and the successor block.
comment|///
comment|/// We define this as a template and instantiate it to form both a const and
comment|/// non-const handle.
name|template
operator|<
name|typename
name|SwitchInstT
block|,
name|typename
name|ConstantIntT
block|,
name|typename
name|BasicBlockT
operator|>
name|class
name|CaseHandleImpl
block|{
comment|// Directly befriend both const and non-const iterators.
name|friend
name|class
name|SwitchInst
operator|::
name|CaseIteratorImpl
operator|<
name|CaseHandleImpl
operator|<
name|SwitchInstT
block|,
name|ConstantIntT
block|,
name|BasicBlockT
operator|>>
block|;
name|protected
operator|:
comment|// Expose the switch type we're parameterized with to the iterator.
name|using
name|SwitchInstType
operator|=
name|SwitchInstT
block|;
name|SwitchInstT
operator|*
name|SI
block|;
name|ptrdiff_t
name|Index
block|;
name|CaseHandleImpl
argument_list|()
operator|=
expr|default
block|;
name|CaseHandleImpl
argument_list|(
argument|SwitchInstT *SI
argument_list|,
argument|ptrdiff_t Index
argument_list|)
operator|:
name|SI
argument_list|(
name|SI
argument_list|)
block|,
name|Index
argument_list|(
argument|Index
argument_list|)
block|{}
name|public
operator|:
comment|/// Resolves case value for current case.
name|ConstantIntT
operator|*
name|getCaseValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|unsigned
operator|)
name|Index
operator|<
name|SI
operator|->
name|getNumCases
argument_list|()
operator|&&
literal|"Index out the number of cases."
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
name|ConstantIntT
operator|*
operator|>
operator|(
name|SI
operator|->
name|getOperand
argument_list|(
literal|2
operator|+
name|Index
operator|*
literal|2
argument_list|)
operator|)
return|;
block|}
comment|/// Resolves successor for current case.
name|BasicBlockT
operator|*
name|getCaseSuccessor
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
operator|(
name|unsigned
operator|)
name|Index
operator|<
name|SI
operator|->
name|getNumCases
argument_list|()
operator|||
operator|(
name|unsigned
operator|)
name|Index
operator|==
name|DefaultPseudoIndex
operator|)
operator|&&
literal|"Index out the number of cases."
argument_list|)
block|;
return|return
name|SI
operator|->
name|getSuccessor
argument_list|(
name|getSuccessorIndex
argument_list|()
argument_list|)
return|;
block|}
comment|/// Returns number of current case.
name|unsigned
name|getCaseIndex
argument_list|()
specifier|const
block|{
return|return
name|Index
return|;
block|}
comment|/// Returns TerminatorInst's successor index for current case successor.
name|unsigned
name|getSuccessorIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
operator|(
name|unsigned
operator|)
name|Index
operator|==
name|DefaultPseudoIndex
operator|||
operator|(
name|unsigned
operator|)
name|Index
operator|<
name|SI
operator|->
name|getNumCases
argument_list|()
operator|)
operator|&&
literal|"Index out the number of cases."
argument_list|)
block|;
return|return
operator|(
name|unsigned
operator|)
name|Index
operator|!=
name|DefaultPseudoIndex
condition|?
name|Index
operator|+
literal|1
else|:
literal|0
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|CaseHandleImpl
operator|&
name|RHS
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|SI
operator|==
name|RHS
operator|.
name|SI
operator|&&
literal|"Incompatible operators."
argument_list|)
block|;
return|return
name|Index
operator|==
name|RHS
operator|.
name|Index
return|;
block|}
expr|}
block|;
name|using
name|ConstCaseHandle
operator|=
name|CaseHandleImpl
operator|<
specifier|const
name|SwitchInst
block|,
specifier|const
name|ConstantInt
block|,
specifier|const
name|BasicBlock
operator|>
block|;
name|class
name|CaseHandle
operator|:
name|public
name|CaseHandleImpl
operator|<
name|SwitchInst
block|,
name|ConstantInt
block|,
name|BasicBlock
operator|>
block|{
name|friend
name|class
name|SwitchInst
operator|::
name|CaseIteratorImpl
operator|<
name|CaseHandle
operator|>
block|;
name|public
operator|:
name|CaseHandle
argument_list|(
argument|SwitchInst *SI
argument_list|,
argument|ptrdiff_t Index
argument_list|)
operator|:
name|CaseHandleImpl
argument_list|(
argument|SI
argument_list|,
argument|Index
argument_list|)
block|{}
comment|/// Sets the new value for current case.
name|void
name|setValue
argument_list|(
argument|ConstantInt *V
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|unsigned
operator|)
name|Index
operator|<
name|SI
operator|->
name|getNumCases
argument_list|()
operator|&&
literal|"Index out the number of cases."
argument_list|)
block|;
name|SI
operator|->
name|setOperand
argument_list|(
literal|2
operator|+
name|Index
operator|*
literal|2
argument_list|,
name|reinterpret_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|V
operator|)
argument_list|)
block|;     }
comment|/// Sets the new successor for current case.
name|void
name|setSuccessor
argument_list|(
argument|BasicBlock *S
argument_list|)
block|{
name|SI
operator|->
name|setSuccessor
argument_list|(
name|getSuccessorIndex
argument_list|()
argument_list|,
name|S
argument_list|)
block|;     }
block|}
block|;
name|template
operator|<
name|typename
name|CaseHandleT
operator|>
name|class
name|CaseIteratorImpl
operator|:
name|public
name|iterator_facade_base
operator|<
name|CaseIteratorImpl
operator|<
name|CaseHandleT
operator|>
block|,
name|std
operator|::
name|random_access_iterator_tag
block|,
name|CaseHandleT
operator|>
block|{
name|using
name|SwitchInstT
operator|=
name|typename
name|CaseHandleT
operator|::
name|SwitchInstType
block|;
name|CaseHandleT
name|Case
block|;
name|public
operator|:
comment|/// Default constructed iterator is in an invalid state until assigned to
comment|/// a case for a particular switch.
name|CaseIteratorImpl
argument_list|()
operator|=
expr|default
block|;
comment|/// Initializes case iterator for given SwitchInst and for given
comment|/// case number.
name|CaseIteratorImpl
argument_list|(
argument|SwitchInstT *SI
argument_list|,
argument|unsigned CaseNum
argument_list|)
operator|:
name|Case
argument_list|(
argument|SI
argument_list|,
argument|CaseNum
argument_list|)
block|{}
comment|/// Initializes case iterator for given SwitchInst and for given
comment|/// TerminatorInst's successor index.
specifier|static
name|CaseIteratorImpl
name|fromSuccessorIndex
argument_list|(
argument|SwitchInstT *SI
argument_list|,
argument|unsigned SuccessorIndex
argument_list|)
block|{
name|assert
argument_list|(
name|SuccessorIndex
operator|<
name|SI
operator|->
name|getNumSuccessors
argument_list|()
operator|&&
literal|"Successor index # out of range!"
argument_list|)
block|;
return|return
name|SuccessorIndex
operator|!=
literal|0
condition|?
name|CaseIteratorImpl
argument_list|(
name|SI
argument_list|,
name|SuccessorIndex
operator|-
literal|1
argument_list|)
else|:
name|CaseIteratorImpl
argument_list|(
name|SI
argument_list|,
name|DefaultPseudoIndex
argument_list|)
return|;
block|}
comment|/// Support converting to the const variant. This will be a no-op for const
comment|/// variant.
name|operator
name|CaseIteratorImpl
operator|<
name|ConstCaseHandle
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|CaseIteratorImpl
operator|<
name|ConstCaseHandle
operator|>
operator|(
name|Case
operator|.
name|SI
expr|,
name|Case
operator|.
name|Index
operator|)
return|;
block|}
name|CaseIteratorImpl
operator|&
name|operator
operator|+=
operator|(
name|ptrdiff_t
name|N
operator|)
block|{
comment|// Check index correctness after addition.
comment|// Note: Index == getNumCases() means end().
name|assert
argument_list|(
name|Case
operator|.
name|Index
operator|+
name|N
operator|>=
literal|0
operator|&&
call|(
name|unsigned
call|)
argument_list|(
name|Case
operator|.
name|Index
operator|+
name|N
argument_list|)
operator|<=
name|Case
operator|.
name|SI
operator|->
name|getNumCases
argument_list|()
operator|&&
literal|"Case.Index out the number of cases."
argument_list|)
block|;
name|Case
operator|.
name|Index
operator|+=
name|N
block|;
return|return
operator|*
name|this
return|;
block|}
name|CaseIteratorImpl
operator|&
name|operator
operator|-=
operator|(
name|ptrdiff_t
name|N
operator|)
block|{
comment|// Check index correctness after subtraction.
comment|// Note: Case.Index == getNumCases() means end().
name|assert
argument_list|(
name|Case
operator|.
name|Index
operator|-
name|N
operator|>=
literal|0
operator|&&
call|(
name|unsigned
call|)
argument_list|(
name|Case
operator|.
name|Index
operator|-
name|N
argument_list|)
operator|<=
name|Case
operator|.
name|SI
operator|->
name|getNumCases
argument_list|()
operator|&&
literal|"Case.Index out the number of cases."
argument_list|)
block|;
name|Case
operator|.
name|Index
operator|-=
name|N
block|;
return|return
operator|*
name|this
return|;
block|}
name|ptrdiff_t
name|operator
operator|-
operator|(
specifier|const
name|CaseIteratorImpl
operator|&
name|RHS
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Case
operator|.
name|SI
operator|==
name|RHS
operator|.
name|Case
operator|.
name|SI
operator|&&
literal|"Incompatible operators."
argument_list|)
block|;
return|return
name|Case
operator|.
name|Index
operator|-
name|RHS
operator|.
name|Case
operator|.
name|Index
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|CaseIteratorImpl
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Case
operator|==
name|RHS
operator|.
name|Case
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|CaseIteratorImpl
operator|&
name|RHS
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Case
operator|.
name|SI
operator|==
name|RHS
operator|.
name|Case
operator|.
name|SI
operator|&&
literal|"Incompatible operators."
argument_list|)
block|;
return|return
name|Case
operator|.
name|Index
operator|<
name|RHS
operator|.
name|Case
operator|.
name|Index
return|;
block|}
name|CaseHandleT
operator|&
name|operator
operator|*
operator|(
operator|)
block|{
return|return
name|Case
return|;
block|}
specifier|const
name|CaseHandleT
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Case
return|;
block|}
expr|}
block|;
name|using
name|CaseIt
operator|=
name|CaseIteratorImpl
operator|<
name|CaseHandle
operator|>
block|;
name|using
name|ConstCaseIt
operator|=
name|CaseIteratorImpl
operator|<
name|ConstCaseHandle
operator|>
block|;
specifier|static
name|SwitchInst
operator|*
name|Create
argument_list|(
argument|Value *Value
argument_list|,
argument|BasicBlock *Default
argument_list|,
argument|unsigned NumCases
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|new
name|SwitchInst
argument_list|(
name|Value
argument_list|,
name|Default
argument_list|,
name|NumCases
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|SwitchInst
operator|*
name|Create
argument_list|(
argument|Value *Value
argument_list|,
argument|BasicBlock *Default
argument_list|,
argument|unsigned NumCases
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
name|SwitchInst
argument_list|(
name|Value
argument_list|,
name|Default
argument_list|,
name|NumCases
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|// Accessor Methods for Switch stmt
name|Value
operator|*
name|getCondition
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|void
name|setCondition
argument_list|(
argument|Value *V
argument_list|)
block|{
name|setOperand
argument_list|(
literal|0
argument_list|,
name|V
argument_list|)
block|; }
name|BasicBlock
operator|*
name|getDefaultDest
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|BasicBlock
operator|>
operator|(
name|getOperand
argument_list|(
literal|1
argument_list|)
operator|)
return|;
block|}
name|void
name|setDefaultDest
argument_list|(
argument|BasicBlock *DefaultCase
argument_list|)
block|{
name|setOperand
argument_list|(
literal|1
argument_list|,
name|reinterpret_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|DefaultCase
operator|)
argument_list|)
block|;   }
comment|/// Return the number of 'cases' in this switch instruction, excluding the
comment|/// default case.
name|unsigned
name|getNumCases
argument_list|()
specifier|const
block|{
return|return
name|getNumOperands
argument_list|()
operator|/
literal|2
operator|-
literal|1
return|;
block|}
comment|/// Returns a read/write iterator that points to the first case in the
comment|/// SwitchInst.
name|CaseIt
name|case_begin
argument_list|()
block|{
return|return
name|CaseIt
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// Returns a read-only iterator that points to the first case in the
comment|/// SwitchInst.
name|ConstCaseIt
name|case_begin
argument_list|()
specifier|const
block|{
return|return
name|ConstCaseIt
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// Returns a read/write iterator that points one past the last in the
comment|/// SwitchInst.
name|CaseIt
name|case_end
argument_list|()
block|{
return|return
name|CaseIt
argument_list|(
name|this
argument_list|,
name|getNumCases
argument_list|()
argument_list|)
return|;
block|}
comment|/// Returns a read-only iterator that points one past the last in the
comment|/// SwitchInst.
name|ConstCaseIt
name|case_end
argument_list|()
specifier|const
block|{
return|return
name|ConstCaseIt
argument_list|(
name|this
argument_list|,
name|getNumCases
argument_list|()
argument_list|)
return|;
block|}
comment|/// Iteration adapter for range-for loops.
name|iterator_range
operator|<
name|CaseIt
operator|>
name|cases
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|case_begin
argument_list|()
argument_list|,
name|case_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// Constant iteration adapter for range-for loops.
name|iterator_range
operator|<
name|ConstCaseIt
operator|>
name|cases
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|case_begin
argument_list|()
argument_list|,
name|case_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// Returns an iterator that points to the default case.
comment|/// Note: this iterator allows to resolve successor only. Attempt
comment|/// to resolve case value causes an assertion.
comment|/// Also note, that increment and decrement also causes an assertion and
comment|/// makes iterator invalid.
name|CaseIt
name|case_default
argument_list|()
block|{
return|return
name|CaseIt
argument_list|(
name|this
argument_list|,
name|DefaultPseudoIndex
argument_list|)
return|;
block|}
name|ConstCaseIt
name|case_default
argument_list|()
specifier|const
block|{
return|return
name|ConstCaseIt
argument_list|(
name|this
argument_list|,
name|DefaultPseudoIndex
argument_list|)
return|;
block|}
comment|/// Search all of the case values for the specified constant. If it is
comment|/// explicitly handled, return the case iterator of it, otherwise return
comment|/// default case iterator to indicate that it is handled by the default
comment|/// handler.
name|CaseIt
name|findCaseValue
argument_list|(
argument|const ConstantInt *C
argument_list|)
block|{
name|CaseIt
name|I
operator|=
name|llvm
operator|::
name|find_if
argument_list|(
name|cases
argument_list|()
argument_list|,
index|[
name|C
index|]
operator|(
name|CaseHandle
operator|&
name|Case
operator|)
block|{
return|return
name|Case
operator|.
name|getCaseValue
argument_list|()
operator|==
name|C
return|;
block|}
argument_list|)
block|;
if|if
condition|(
name|I
operator|!=
name|case_end
argument_list|()
condition|)
return|return
name|I
return|;
return|return
name|case_default
argument_list|()
return|;
block|}
name|ConstCaseIt
name|findCaseValue
argument_list|(
argument|const ConstantInt *C
argument_list|)
specifier|const
block|{
name|ConstCaseIt
name|I
operator|=
name|llvm
operator|::
name|find_if
argument_list|(
name|cases
argument_list|()
argument_list|,
index|[
name|C
index|]
operator|(
name|ConstCaseHandle
operator|&
name|Case
operator|)
block|{
return|return
name|Case
operator|.
name|getCaseValue
argument_list|()
operator|==
name|C
return|;
block|}
argument_list|)
block|;
if|if
condition|(
name|I
operator|!=
name|case_end
argument_list|()
condition|)
return|return
name|I
return|;
return|return
name|case_default
argument_list|()
return|;
block|}
comment|/// Finds the unique case value for a given successor. Returns null if the
comment|/// successor is not found, not unique, or is the default case.
name|ConstantInt
operator|*
name|findCaseDest
argument_list|(
argument|BasicBlock *BB
argument_list|)
block|{
if|if
condition|(
name|BB
operator|==
name|getDefaultDest
argument_list|()
condition|)
return|return
name|nullptr
return|;
name|ConstantInt
operator|*
name|CI
operator|=
name|nullptr
block|;
for|for
control|(
name|auto
name|Case
range|:
name|cases
argument_list|()
control|)
block|{
if|if
condition|(
name|Case
operator|.
name|getCaseSuccessor
argument_list|()
operator|!=
name|BB
condition|)
continue|continue;
if|if
condition|(
name|CI
condition|)
return|return
name|nullptr
return|;
comment|// Multiple cases lead to BB.
name|CI
operator|=
name|Case
operator|.
name|getCaseValue
argument_list|()
expr_stmt|;
block|}
return|return
name|CI
return|;
block|}
comment|/// Add an entry to the switch instruction.
comment|/// Note:
comment|/// This action invalidates case_end(). Old case_end() iterator will
comment|/// point to the added case.
name|void
name|addCase
argument_list|(
name|ConstantInt
operator|*
name|OnVal
argument_list|,
name|BasicBlock
operator|*
name|Dest
argument_list|)
block|;
comment|/// This method removes the specified case and its successor from the switch
comment|/// instruction. Note that this operation may reorder the remaining cases at
comment|/// index idx and above.
comment|/// Note:
comment|/// This action invalidates iterators for all cases following the one removed,
comment|/// including the case_end() iterator. It returns an iterator for the next
comment|/// case.
name|CaseIt
name|removeCase
argument_list|(
argument|CaseIt I
argument_list|)
block|;
name|unsigned
name|getNumSuccessors
argument_list|()
specifier|const
block|{
return|return
name|getNumOperands
argument_list|()
operator|/
literal|2
return|;
block|}
name|BasicBlock
operator|*
name|getSuccessor
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|idx
operator|<
name|getNumSuccessors
argument_list|()
operator|&&
literal|"Successor idx out of range for switch!"
argument_list|)
block|;
return|return
name|cast
operator|<
name|BasicBlock
operator|>
operator|(
name|getOperand
argument_list|(
name|idx
operator|*
literal|2
operator|+
literal|1
argument_list|)
operator|)
return|;
block|}
name|void
name|setSuccessor
argument_list|(
argument|unsigned idx
argument_list|,
argument|BasicBlock *NewSucc
argument_list|)
block|{
name|assert
argument_list|(
name|idx
operator|<
name|getNumSuccessors
argument_list|()
operator|&&
literal|"Successor # out of range for switch!"
argument_list|)
block|;
name|setOperand
argument_list|(
name|idx
operator|*
literal|2
operator|+
literal|1
argument_list|,
name|NewSucc
argument_list|)
block|;   }
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
name|Switch
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
name|private
operator|:
name|friend
name|TerminatorInst
block|;
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|;
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|void
name|setSuccessorV
argument_list|(
argument|unsigned idx
argument_list|,
argument|BasicBlock *B
argument_list|)
block|; }
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|SwitchInst
operator|>
operator|:
name|public
name|HungoffOperandTraits
operator|<
literal|2
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|SwitchInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                             IndirectBrInst Class
comment|//===----------------------------------------------------------------------===//
comment|//===---------------------------------------------------------------------------
comment|/// Indirect Branch Instruction.
comment|///
name|class
name|IndirectBrInst
operator|:
name|public
name|TerminatorInst
block|{
name|unsigned
name|ReservedSpace
block|;
comment|// Operand[0]   = Address to jump to
comment|// Operand[n+1] = n-th destination
name|IndirectBrInst
argument_list|(
specifier|const
name|IndirectBrInst
operator|&
name|IBI
argument_list|)
block|;
comment|/// Create a new indirectbr instruction, specifying an
comment|/// Address to jump to.  The number of expected destinations can be specified
comment|/// here to make memory allocation more efficient.  This constructor can also
comment|/// autoinsert before another instruction.
name|IndirectBrInst
argument_list|(
argument|Value *Address
argument_list|,
argument|unsigned NumDests
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
block|;
comment|/// Create a new indirectbr instruction, specifying an
comment|/// Address to jump to.  The number of expected destinations can be specified
comment|/// here to make memory allocation more efficient.  This constructor also
comment|/// autoinserts at the end of the specified BasicBlock.
name|IndirectBrInst
argument_list|(
argument|Value *Address
argument_list|,
argument|unsigned NumDests
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
comment|// allocate space for exactly zero operands
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
argument_list|)
return|;
block|}
name|void
name|init
argument_list|(
argument|Value *Address
argument_list|,
argument|unsigned NumDests
argument_list|)
block|;
name|void
name|growOperands
argument_list|()
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|IndirectBrInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
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
specifier|static
name|IndirectBrInst
operator|*
name|Create
argument_list|(
argument|Value *Address
argument_list|,
argument|unsigned NumDests
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|new
name|IndirectBrInst
argument_list|(
name|Address
argument_list|,
name|NumDests
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|IndirectBrInst
operator|*
name|Create
argument_list|(
argument|Value *Address
argument_list|,
argument|unsigned NumDests
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
name|IndirectBrInst
argument_list|(
name|Address
argument_list|,
name|NumDests
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Provide fast operand accessors.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|// Accessor Methods for IndirectBrInst instruction.
name|Value
operator|*
name|getAddress
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|const
name|Value
operator|*
name|getAddress
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|void
name|setAddress
argument_list|(
argument|Value *V
argument_list|)
block|{
name|setOperand
argument_list|(
literal|0
argument_list|,
name|V
argument_list|)
block|; }
comment|/// return the number of possible destinations in this
comment|/// indirectbr instruction.
name|unsigned
name|getNumDestinations
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
comment|/// Return the specified destination.
name|BasicBlock
operator|*
name|getDestination
argument_list|(
argument|unsigned i
argument_list|)
block|{
return|return
name|getSuccessor
argument_list|(
name|i
argument_list|)
return|;
block|}
specifier|const
name|BasicBlock
operator|*
name|getDestination
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|getSuccessor
argument_list|(
name|i
argument_list|)
return|;
block|}
comment|/// Add a destination.
comment|///
name|void
name|addDestination
argument_list|(
name|BasicBlock
operator|*
name|Dest
argument_list|)
block|;
comment|/// This method removes the specified successor from the
comment|/// indirectbr instruction.
name|void
name|removeDestination
argument_list|(
argument|unsigned i
argument_list|)
block|;
name|unsigned
name|getNumSuccessors
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
name|BasicBlock
operator|*
name|getSuccessor
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|cast
operator|<
name|BasicBlock
operator|>
operator|(
name|getOperand
argument_list|(
name|i
operator|+
literal|1
argument_list|)
operator|)
return|;
block|}
name|void
name|setSuccessor
argument_list|(
argument|unsigned i
argument_list|,
argument|BasicBlock *NewSucc
argument_list|)
block|{
name|setOperand
argument_list|(
name|i
operator|+
literal|1
argument_list|,
name|NewSucc
argument_list|)
block|;   }
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
name|IndirectBr
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
name|private
operator|:
name|friend
name|TerminatorInst
block|;
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|;
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|void
name|setSuccessorV
argument_list|(
argument|unsigned idx
argument_list|,
argument|BasicBlock *B
argument_list|)
block|; }
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|IndirectBrInst
operator|>
operator|:
name|public
name|HungoffOperandTraits
operator|<
literal|1
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|IndirectBrInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                               InvokeInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// Invoke instruction.  The SubclassData field is used to hold the
comment|/// calling convention of the call.
comment|///
name|class
name|InvokeInst
operator|:
name|public
name|TerminatorInst
block|,
name|public
name|OperandBundleUser
operator|<
name|InvokeInst
block|,
name|User
operator|::
name|op_iterator
operator|>
block|{
name|friend
name|class
name|OperandBundleUser
operator|<
name|InvokeInst
block|,
name|User
operator|::
name|op_iterator
operator|>
block|;
name|AttributeList
name|Attrs
block|;
name|FunctionType
operator|*
name|FTy
block|;
name|InvokeInst
argument_list|(
specifier|const
name|InvokeInst
operator|&
name|BI
argument_list|)
block|;
comment|/// Construct an InvokeInst given a range of arguments.
comment|///
comment|/// Construct an InvokeInst from a range of arguments
specifier|inline
name|InvokeInst
argument_list|(
argument|Value *Func
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|ArrayRef<OperandBundleDef> Bundles
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
operator|:
name|InvokeInst
argument_list|(
argument|cast<FunctionType>(                        cast<PointerType>(Func->getType())->getElementType())
argument_list|,
argument|Func
argument_list|,
argument|IfNormal
argument_list|,
argument|IfException
argument_list|,
argument|Args
argument_list|,
argument|Bundles
argument_list|,
argument|Values
argument_list|,
argument|NameStr
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
specifier|inline
name|InvokeInst
argument_list|(
argument|FunctionType *Ty
argument_list|,
argument|Value *Func
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|ArrayRef<OperandBundleDef> Bundles
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
block|;
comment|/// Construct an InvokeInst given a range of arguments.
comment|///
comment|/// Construct an InvokeInst from a range of arguments
specifier|inline
name|InvokeInst
argument_list|(
argument|Value *Func
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|ArrayRef<OperandBundleDef> Bundles
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|bool
name|hasDescriptor
argument_list|()
specifier|const
block|{
return|return
name|HasDescriptor
return|;
block|}
name|void
name|init
argument_list|(
argument|Value *Func
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|ArrayRef<OperandBundleDef> Bundles
argument_list|,
argument|const Twine&NameStr
argument_list|)
block|{
name|init
argument_list|(
name|cast
operator|<
name|FunctionType
operator|>
operator|(
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Func
operator|->
name|getType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
operator|)
argument_list|,
name|Func
argument_list|,
name|IfNormal
argument_list|,
name|IfException
argument_list|,
name|Args
argument_list|,
name|Bundles
argument_list|,
name|NameStr
argument_list|)
block|;   }
name|void
name|init
argument_list|(
name|FunctionType
operator|*
name|FTy
argument_list|,
name|Value
operator|*
name|Func
argument_list|,
name|BasicBlock
operator|*
name|IfNormal
argument_list|,
name|BasicBlock
operator|*
name|IfException
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Args
argument_list|,
name|ArrayRef
operator|<
name|OperandBundleDef
operator|>
name|Bundles
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
name|InvokeInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
specifier|static
name|InvokeInst
operator|*
name|Create
argument_list|(
argument|Value *Func
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|cast
operator|<
name|FunctionType
operator|>
operator|(
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Func
operator|->
name|getType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
operator|)
argument_list|,
name|Func
argument_list|,
name|IfNormal
argument_list|,
name|IfException
argument_list|,
name|Args
argument_list|,
name|None
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|InvokeInst
operator|*
name|Create
argument_list|(
argument|Value *Func
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|ArrayRef<OperandBundleDef> Bundles = None
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|cast
operator|<
name|FunctionType
operator|>
operator|(
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Func
operator|->
name|getType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
operator|)
argument_list|,
name|Func
argument_list|,
name|IfNormal
argument_list|,
name|IfException
argument_list|,
name|Args
argument_list|,
name|Bundles
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|InvokeInst
operator|*
name|Create
argument_list|(
argument|FunctionType *Ty
argument_list|,
argument|Value *Func
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
name|unsigned
name|Values
operator|=
name|unsigned
argument_list|(
name|Args
operator|.
name|size
argument_list|()
argument_list|)
operator|+
literal|3
block|;
return|return
name|new
argument_list|(
argument|Values
argument_list|)
name|InvokeInst
argument_list|(
name|Ty
argument_list|,
name|Func
argument_list|,
name|IfNormal
argument_list|,
name|IfException
argument_list|,
name|Args
argument_list|,
name|None
argument_list|,
name|Values
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|InvokeInst
operator|*
name|Create
argument_list|(
argument|FunctionType *Ty
argument_list|,
argument|Value *Func
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|ArrayRef<OperandBundleDef> Bundles = None
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
name|unsigned
name|Values
operator|=
name|unsigned
argument_list|(
name|Args
operator|.
name|size
argument_list|()
argument_list|)
operator|+
name|CountBundleInputs
argument_list|(
name|Bundles
argument_list|)
operator|+
literal|3
block|;
name|unsigned
name|DescriptorBytes
operator|=
name|Bundles
operator|.
name|size
argument_list|()
operator|*
sizeof|sizeof
argument_list|(
name|BundleOpInfo
argument_list|)
block|;
return|return
name|new
argument_list|(
argument|Values
argument_list|,
argument|DescriptorBytes
argument_list|)
name|InvokeInst
argument_list|(
name|Ty
argument_list|,
name|Func
argument_list|,
name|IfNormal
argument_list|,
name|IfException
argument_list|,
name|Args
argument_list|,
name|Bundles
argument_list|,
name|Values
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|InvokeInst
operator|*
name|Create
argument_list|(
argument|Value *Func
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
name|unsigned
name|Values
operator|=
name|unsigned
argument_list|(
name|Args
operator|.
name|size
argument_list|()
argument_list|)
operator|+
literal|3
block|;
return|return
name|new
argument_list|(
argument|Values
argument_list|)
name|InvokeInst
argument_list|(
name|Func
argument_list|,
name|IfNormal
argument_list|,
name|IfException
argument_list|,
name|Args
argument_list|,
name|None
argument_list|,
name|Values
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
specifier|static
name|InvokeInst
operator|*
name|Create
argument_list|(
argument|Value *Func
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|ArrayRef<OperandBundleDef> Bundles
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
name|unsigned
name|Values
operator|=
name|unsigned
argument_list|(
name|Args
operator|.
name|size
argument_list|()
argument_list|)
operator|+
name|CountBundleInputs
argument_list|(
name|Bundles
argument_list|)
operator|+
literal|3
block|;
name|unsigned
name|DescriptorBytes
operator|=
name|Bundles
operator|.
name|size
argument_list|()
operator|*
sizeof|sizeof
argument_list|(
name|BundleOpInfo
argument_list|)
block|;
return|return
name|new
argument_list|(
argument|Values
argument_list|,
argument|DescriptorBytes
argument_list|)
name|InvokeInst
argument_list|(
name|Func
argument_list|,
name|IfNormal
argument_list|,
name|IfException
argument_list|,
name|Args
argument_list|,
name|Bundles
argument_list|,
name|Values
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Create a clone of \p II with a different set of operand bundles and
comment|/// insert it before \p InsertPt.
comment|///
comment|/// The returned invoke instruction is identical to \p II in every way except
comment|/// that the operand bundles for the new instruction are set to the operand
comment|/// bundles in \p Bundles.
specifier|static
name|InvokeInst
operator|*
name|Create
argument_list|(
name|InvokeInst
operator|*
name|II
argument_list|,
name|ArrayRef
operator|<
name|OperandBundleDef
operator|>
name|Bundles
argument_list|,
name|Instruction
operator|*
name|InsertPt
operator|=
name|nullptr
argument_list|)
block|;
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
name|FunctionType
operator|*
name|getFunctionType
argument_list|()
specifier|const
block|{
return|return
name|FTy
return|;
block|}
name|void
name|mutateFunctionType
argument_list|(
argument|FunctionType *FTy
argument_list|)
block|{
name|mutateType
argument_list|(
name|FTy
operator|->
name|getReturnType
argument_list|()
argument_list|)
block|;
name|this
operator|->
name|FTy
operator|=
name|FTy
block|;   }
comment|/// Return the number of invoke arguments.
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
name|getNumTotalBundleOperands
argument_list|()
operator|-
literal|3
return|;
block|}
comment|/// getArgOperand/setArgOperand - Return/set the i-th invoke argument.
comment|///
name|Value
operator|*
name|getArgOperand
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumArgOperands
argument_list|()
operator|&&
literal|"Out of bounds!"
argument_list|)
block|;
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
name|assert
argument_list|(
name|i
operator|<
name|getNumArgOperands
argument_list|()
operator|&&
literal|"Out of bounds!"
argument_list|)
block|;
name|setOperand
argument_list|(
name|i
argument_list|,
name|v
argument_list|)
block|;   }
comment|/// Return the iterator pointing to the beginning of the argument list.
name|op_iterator
name|arg_begin
argument_list|()
block|{
return|return
name|op_begin
argument_list|()
return|;
block|}
comment|/// Return the iterator pointing to the end of the argument list.
name|op_iterator
name|arg_end
argument_list|()
block|{
comment|// [ invoke args ], [ operand bundles ], normal dest, unwind dest, callee
return|return
name|op_end
argument_list|()
operator|-
name|getNumTotalBundleOperands
argument_list|()
operator|-
literal|3
return|;
block|}
comment|/// Iteration adapter for range-for loops.
name|iterator_range
operator|<
name|op_iterator
operator|>
name|arg_operands
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|arg_begin
argument_list|()
argument_list|,
name|arg_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// Return the iterator pointing to the beginning of the argument list.
name|const_op_iterator
name|arg_begin
argument_list|()
specifier|const
block|{
return|return
name|op_begin
argument_list|()
return|;
block|}
comment|/// Return the iterator pointing to the end of the argument list.
name|const_op_iterator
name|arg_end
argument_list|()
specifier|const
block|{
comment|// [ invoke args ], [ operand bundles ], normal dest, unwind dest, callee
return|return
name|op_end
argument_list|()
operator|-
name|getNumTotalBundleOperands
argument_list|()
operator|-
literal|3
return|;
block|}
comment|/// Iteration adapter for range-for loops.
name|iterator_range
operator|<
name|const_op_iterator
operator|>
name|arg_operands
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|arg_begin
argument_list|()
argument_list|,
name|arg_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// Wrappers for getting the \c Use of a invoke argument.
specifier|const
name|Use
operator|&
name|getArgOperandUse
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumArgOperands
argument_list|()
operator|&&
literal|"Out of bounds!"
argument_list|)
block|;
return|return
name|getOperandUse
argument_list|(
name|i
argument_list|)
return|;
block|}
name|Use
operator|&
name|getArgOperandUse
argument_list|(
argument|unsigned i
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumArgOperands
argument_list|()
operator|&&
literal|"Out of bounds!"
argument_list|)
block|;
return|return
name|getOperandUse
argument_list|(
name|i
argument_list|)
return|;
block|}
comment|/// If one of the arguments has the 'returned' attribute, return its
comment|/// operand value. Otherwise, return nullptr.
name|Value
operator|*
name|getReturnedArgOperand
argument_list|()
specifier|const
block|;
comment|/// getCallingConv/setCallingConv - Get or set the calling convention of this
comment|/// function call.
name|CallingConv
operator|::
name|ID
name|getCallingConv
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|CallingConv
operator|::
name|ID
operator|>
operator|(
name|getSubclassDataFromInstruction
argument_list|()
operator|)
return|;
block|}
name|void
name|setCallingConv
argument_list|(
argument|CallingConv::ID CC
argument_list|)
block|{
name|auto
name|ID
operator|=
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|CC
operator|)
block|;
name|assert
argument_list|(
operator|!
operator|(
name|ID
operator|&
operator|~
name|CallingConv
operator|::
name|MaxID
operator|)
operator|&&
literal|"Unsupported calling convention"
argument_list|)
block|;
name|setInstructionSubclassData
argument_list|(
name|ID
argument_list|)
block|;   }
comment|/// Return the parameter attributes for this invoke.
comment|///
name|AttributeList
name|getAttributes
argument_list|()
specifier|const
block|{
return|return
name|Attrs
return|;
block|}
comment|/// Set the parameter attributes for this invoke.
comment|///
name|void
name|setAttributes
argument_list|(
argument|AttributeList A
argument_list|)
block|{
name|Attrs
operator|=
name|A
block|; }
comment|/// adds the attribute to the list of attributes.
name|void
name|addAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
block|;
comment|/// adds the attribute to the list of attributes.
name|void
name|addAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute Attr
argument_list|)
block|;
comment|/// Adds the attribute to the indicated argument
name|void
name|addParamAttr
argument_list|(
argument|unsigned ArgNo
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
block|;
comment|/// removes the attribute from the list of attributes.
name|void
name|removeAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
block|;
comment|/// removes the attribute from the list of attributes.
name|void
name|removeAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|StringRef Kind
argument_list|)
block|;
comment|/// Removes the attribute from the given argument
name|void
name|removeParamAttr
argument_list|(
argument|unsigned ArgNo
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
block|;
comment|/// adds the dereferenceable attribute to the list of attributes.
name|void
name|addDereferenceableAttr
argument_list|(
argument|unsigned i
argument_list|,
argument|uint64_t Bytes
argument_list|)
block|;
comment|/// adds the dereferenceable_or_null attribute to the list of
comment|/// attributes.
name|void
name|addDereferenceableOrNullAttr
argument_list|(
argument|unsigned i
argument_list|,
argument|uint64_t Bytes
argument_list|)
block|;
comment|/// Determine whether this call has the given attribute.
name|bool
name|hasFnAttr
argument_list|(
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|!=
name|Attribute
operator|::
name|NoBuiltin
operator|&&
literal|"Use CallInst::isNoBuiltin() to check for Attribute::NoBuiltin"
argument_list|)
block|;
return|return
name|hasFnAttrImpl
argument_list|(
name|Kind
argument_list|)
return|;
block|}
comment|/// Determine whether this call has the given attribute.
name|bool
name|hasFnAttr
argument_list|(
argument|StringRef Kind
argument_list|)
specifier|const
block|{
return|return
name|hasFnAttrImpl
argument_list|(
name|Kind
argument_list|)
return|;
block|}
comment|/// Determine whether the return value has the given attribute.
name|bool
name|hasRetAttr
argument_list|(
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|;
comment|/// Determine whether the argument or parameter has the given attribute.
name|bool
name|paramHasAttr
argument_list|(
argument|unsigned ArgNo
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|;
comment|/// Get the attribute of a given kind at a position.
name|Attribute
name|getAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|{
return|return
name|getAttributes
argument_list|()
operator|.
name|getAttribute
argument_list|(
name|i
argument_list|,
name|Kind
argument_list|)
return|;
block|}
comment|/// Get the attribute of a given kind at a position.
name|Attribute
name|getAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|StringRef Kind
argument_list|)
specifier|const
block|{
return|return
name|getAttributes
argument_list|()
operator|.
name|getAttribute
argument_list|(
name|i
argument_list|,
name|Kind
argument_list|)
return|;
block|}
comment|/// Return true if the data operand at index \p i has the attribute \p
comment|/// A.
comment|///
comment|/// Data operands include invoke arguments and values used in operand bundles,
comment|/// but does not include the invokee operand, or the two successor blocks.
comment|/// This routine dispatches to the underlying AttributeList or the
comment|/// OperandBundleUser as appropriate.
comment|///
comment|/// The index \p i is interpreted as
comment|///
comment|///  \p i == Attribute::ReturnIndex  -> the return value
comment|///  \p i in [1, arg_size + 1)  -> argument number (\p i - 1)
comment|///  \p i in [arg_size + 1, data_operand_size + 1) -> bundle operand at index
comment|///     (\p i - 1) in the operand list.
name|bool
name|dataOperandHasImpliedAttr
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|;
comment|/// Extract the alignment of the return value.
name|unsigned
name|getRetAlignment
argument_list|()
specifier|const
block|{
return|return
name|Attrs
operator|.
name|getRetAlignment
argument_list|()
return|;
block|}
comment|/// Extract the alignment for a call or parameter (0=unknown).
name|unsigned
name|getParamAlignment
argument_list|(
argument|unsigned ArgNo
argument_list|)
specifier|const
block|{
return|return
name|Attrs
operator|.
name|getParamAlignment
argument_list|(
name|ArgNo
argument_list|)
return|;
block|}
comment|/// Extract the number of dereferenceable bytes for a call or
comment|/// parameter (0=unknown).
name|uint64_t
name|getDereferenceableBytes
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|Attrs
operator|.
name|getDereferenceableBytes
argument_list|(
name|i
argument_list|)
return|;
block|}
comment|/// Extract the number of dereferenceable_or_null bytes for a call or
comment|/// parameter (0=unknown).
name|uint64_t
name|getDereferenceableOrNullBytes
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|Attrs
operator|.
name|getDereferenceableOrNullBytes
argument_list|(
name|i
argument_list|)
return|;
block|}
comment|/// @brief Determine if the return value is marked with NoAlias attribute.
name|bool
name|returnDoesNotAlias
argument_list|()
specifier|const
block|{
return|return
name|Attrs
operator|.
name|hasAttribute
argument_list|(
name|AttributeList
operator|::
name|ReturnIndex
argument_list|,
name|Attribute
operator|::
name|NoAlias
argument_list|)
return|;
block|}
comment|/// Return true if the call should not be treated as a call to a
comment|/// builtin.
name|bool
name|isNoBuiltin
argument_list|()
specifier|const
block|{
comment|// We assert in hasFnAttr if one passes in Attribute::NoBuiltin, so we have
comment|// to check it by hand.
return|return
name|hasFnAttrImpl
argument_list|(
name|Attribute
operator|::
name|NoBuiltin
argument_list|)
operator|&&
operator|!
name|hasFnAttrImpl
argument_list|(
name|Attribute
operator|::
name|Builtin
argument_list|)
return|;
block|}
comment|/// Return true if the call should not be inlined.
name|bool
name|isNoInline
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|NoInline
argument_list|)
return|;
block|}
name|void
name|setIsNoInline
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|NoInline
argument_list|)
block|;   }
comment|/// Determine if the call does not access memory.
name|bool
name|doesNotAccessMemory
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|ReadNone
argument_list|)
return|;
block|}
name|void
name|setDoesNotAccessMemory
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|ReadNone
argument_list|)
block|;   }
comment|/// Determine if the call does not access or only reads memory.
name|bool
name|onlyReadsMemory
argument_list|()
specifier|const
block|{
return|return
name|doesNotAccessMemory
argument_list|()
operator|||
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|ReadOnly
argument_list|)
return|;
block|}
name|void
name|setOnlyReadsMemory
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|ReadOnly
argument_list|)
block|;   }
comment|/// Determine if the call does not access or only writes memory.
name|bool
name|doesNotReadMemory
argument_list|()
specifier|const
block|{
return|return
name|doesNotAccessMemory
argument_list|()
operator|||
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|WriteOnly
argument_list|)
return|;
block|}
name|void
name|setDoesNotReadMemory
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|WriteOnly
argument_list|)
block|;   }
comment|/// @brief Determine if the call access memmory only using it's pointer
comment|/// arguments.
name|bool
name|onlyAccessesArgMemory
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|ArgMemOnly
argument_list|)
return|;
block|}
name|void
name|setOnlyAccessesArgMemory
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|ArgMemOnly
argument_list|)
block|;   }
comment|/// Determine if the call cannot return.
name|bool
name|doesNotReturn
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|NoReturn
argument_list|)
return|;
block|}
name|void
name|setDoesNotReturn
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|NoReturn
argument_list|)
block|;   }
comment|/// Determine if the call cannot unwind.
name|bool
name|doesNotThrow
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|NoUnwind
argument_list|)
return|;
block|}
name|void
name|setDoesNotThrow
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|NoUnwind
argument_list|)
block|;   }
comment|/// Determine if the invoke cannot be duplicated.
name|bool
name|cannotDuplicate
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|NoDuplicate
argument_list|)
return|;
block|}
name|void
name|setCannotDuplicate
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|NoDuplicate
argument_list|)
block|;   }
comment|/// Determine if the invoke is convergent
name|bool
name|isConvergent
argument_list|()
specifier|const
block|{
return|return
name|hasFnAttr
argument_list|(
name|Attribute
operator|::
name|Convergent
argument_list|)
return|;
block|}
name|void
name|setConvergent
argument_list|()
block|{
name|addAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|Convergent
argument_list|)
block|;   }
name|void
name|setNotConvergent
argument_list|()
block|{
name|removeAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Attribute
operator|::
name|Convergent
argument_list|)
block|;   }
comment|/// Determine if the call returns a structure through first
comment|/// pointer argument.
name|bool
name|hasStructRetAttr
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getNumArgOperands
argument_list|()
operator|==
literal|0
condition|)
return|return
name|false
return|;
comment|// Be friendly and also check the callee.
return|return
name|paramHasAttr
argument_list|(
literal|0
argument_list|,
name|Attribute
operator|::
name|StructRet
argument_list|)
return|;
block|}
comment|/// Determine if any call argument is an aggregate passed by value.
name|bool
name|hasByValArgument
argument_list|()
specifier|const
block|{
return|return
name|Attrs
operator|.
name|hasAttrSomewhere
argument_list|(
name|Attribute
operator|::
name|ByVal
argument_list|)
return|;
block|}
comment|/// Return the function called, or null if this is an
comment|/// indirect function invocation.
comment|///
name|Function
operator|*
name|getCalledFunction
argument_list|()
specifier|const
block|{
return|return
name|dyn_cast
operator|<
name|Function
operator|>
operator|(
name|Op
operator|<
operator|-
literal|3
operator|>
operator|(
operator|)
operator|)
return|;
block|}
comment|/// Get a pointer to the function that is invoked by this
comment|/// instruction
specifier|const
name|Value
operator|*
name|getCalledValue
argument_list|()
specifier|const
block|{
return|return
name|Op
operator|<
operator|-
literal|3
operator|>
operator|(
operator|)
return|;
block|}
name|Value
operator|*
name|getCalledValue
argument_list|()
block|{
return|return
name|Op
operator|<
operator|-
literal|3
operator|>
operator|(
operator|)
return|;
block|}
comment|/// Set the function called.
name|void
name|setCalledFunction
argument_list|(
argument|Value* Fn
argument_list|)
block|{
name|setCalledFunction
argument_list|(
name|cast
operator|<
name|FunctionType
operator|>
operator|(
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Fn
operator|->
name|getType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
operator|)
argument_list|,
name|Fn
argument_list|)
block|;   }
name|void
name|setCalledFunction
argument_list|(
argument|FunctionType *FTy
argument_list|,
argument|Value *Fn
argument_list|)
block|{
name|this
operator|->
name|FTy
operator|=
name|FTy
block|;
name|assert
argument_list|(
name|FTy
operator|==
name|cast
operator|<
name|FunctionType
operator|>
operator|(
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Fn
operator|->
name|getType
argument_list|()
operator|)
operator|->
name|getElementType
argument_list|()
operator|)
argument_list|)
block|;
name|Op
operator|<
operator|-
literal|3
operator|>
operator|(
operator|)
operator|=
name|Fn
block|;   }
comment|// get*Dest - Return the destination basic blocks...
name|BasicBlock
operator|*
name|getNormalDest
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|BasicBlock
operator|>
operator|(
name|Op
operator|<
operator|-
literal|2
operator|>
operator|(
operator|)
operator|)
return|;
block|}
name|BasicBlock
operator|*
name|getUnwindDest
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|BasicBlock
operator|>
operator|(
name|Op
operator|<
operator|-
literal|1
operator|>
operator|(
operator|)
operator|)
return|;
block|}
name|void
name|setNormalDest
argument_list|(
argument|BasicBlock *B
argument_list|)
block|{
name|Op
operator|<
operator|-
literal|2
operator|>
operator|(
operator|)
operator|=
name|reinterpret_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|B
operator|)
block|;   }
name|void
name|setUnwindDest
argument_list|(
argument|BasicBlock *B
argument_list|)
block|{
name|Op
operator|<
operator|-
literal|1
operator|>
operator|(
operator|)
operator|=
name|reinterpret_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|B
operator|)
block|;   }
comment|/// Get the landingpad instruction from the landing pad
comment|/// block (the unwind destination).
name|LandingPadInst
operator|*
name|getLandingPadInst
argument_list|()
specifier|const
block|;
name|BasicBlock
operator|*
name|getSuccessor
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
literal|2
operator|&&
literal|"Successor # out of range for invoke!"
argument_list|)
block|;
return|return
name|i
operator|==
literal|0
condition|?
name|getNormalDest
argument_list|()
else|:
name|getUnwindDest
argument_list|()
return|;
block|}
name|void
name|setSuccessor
argument_list|(
argument|unsigned idx
argument_list|,
argument|BasicBlock *NewSucc
argument_list|)
block|{
name|assert
argument_list|(
name|idx
operator|<
literal|2
operator|&&
literal|"Successor # out of range for invoke!"
argument_list|)
block|;
operator|*
operator|(
operator|&
name|Op
operator|<
operator|-
literal|2
operator|>
operator|(
operator|)
operator|+
name|idx
operator|)
operator|=
name|reinterpret_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|NewSucc
operator|)
block|;   }
name|unsigned
name|getNumSuccessors
argument_list|()
specifier|const
block|{
return|return
literal|2
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
operator|(
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Invoke
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
name|private
operator|:
name|friend
name|TerminatorInst
block|;
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|;
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|void
name|setSuccessorV
argument_list|(
argument|unsigned idx
argument_list|,
argument|BasicBlock *B
argument_list|)
block|;
name|template
operator|<
name|typename
name|AttrKind
operator|>
name|bool
name|hasFnAttrImpl
argument_list|(
argument|AttrKind Kind
argument_list|)
specifier|const
block|{
if|if
condition|(
name|Attrs
operator|.
name|hasAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Kind
argument_list|)
condition|)
return|return
name|true
return|;
comment|// Operand bundles override attributes on the called function, but don't
comment|// override attributes directly present on the invoke instruction.
if|if
condition|(
name|isFnAttrDisallowedByOpBundle
argument_list|(
name|Kind
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
specifier|const
name|Function
modifier|*
name|F
init|=
name|getCalledFunction
argument_list|()
condition|)
return|return
name|F
operator|->
name|getAttributes
argument_list|()
operator|.
name|hasAttribute
argument_list|(
name|AttributeList
operator|::
name|FunctionIndex
argument_list|,
name|Kind
argument_list|)
return|;
return|return
name|false
return|;
block|}
comment|// Shadow Instruction::setInstructionSubclassData with a private forwarding
comment|// method so that subclasses cannot accidentally use it.
name|void
name|setInstructionSubclassData
argument_list|(
argument|unsigned short D
argument_list|)
block|{
name|Instruction
operator|::
name|setInstructionSubclassData
argument_list|(
name|D
argument_list|)
block|;   }
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|InvokeInst
operator|>
operator|:
name|public
name|VariadicOperandTraits
operator|<
name|InvokeInst
block|,
literal|3
operator|>
block|{ }
block|;
name|InvokeInst
operator|::
name|InvokeInst
argument_list|(
argument|FunctionType *Ty
argument_list|,
argument|Value *Func
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|ArrayRef<OperandBundleDef> Bundles
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
operator|:
name|TerminatorInst
argument_list|(
argument|Ty->getReturnType()
argument_list|,
argument|Instruction::Invoke
argument_list|,
argument|OperandTraits<InvokeInst>::op_end(this) - Values
argument_list|,
argument|Values
argument_list|,
argument|InsertBefore
argument_list|)
block|{
name|init
argument_list|(
name|Ty
argument_list|,
name|Func
argument_list|,
name|IfNormal
argument_list|,
name|IfException
argument_list|,
name|Args
argument_list|,
name|Bundles
argument_list|,
name|NameStr
argument_list|)
block|; }
name|InvokeInst
operator|::
name|InvokeInst
argument_list|(
argument|Value *Func
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|ArrayRef<OperandBundleDef> Bundles
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
operator|:
name|TerminatorInst
argument_list|(
argument|cast<FunctionType>(cast<PointerType>(Func->getType())                                  ->getElementType())->getReturnType()
argument_list|,
argument|Instruction::Invoke
argument_list|,
argument|OperandTraits<InvokeInst>::op_end(this) - Values
argument_list|,
argument|Values
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{
name|init
argument_list|(
name|Func
argument_list|,
name|IfNormal
argument_list|,
name|IfException
argument_list|,
name|Args
argument_list|,
name|Bundles
argument_list|,
name|NameStr
argument_list|)
block|; }
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|InvokeInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                              ResumeInst Class
comment|//===----------------------------------------------------------------------===//
comment|//===---------------------------------------------------------------------------
comment|/// Resume the propagation of an exception.
comment|///
name|class
name|ResumeInst
operator|:
name|public
name|TerminatorInst
block|{
name|ResumeInst
argument_list|(
specifier|const
name|ResumeInst
operator|&
name|RI
argument_list|)
block|;
name|explicit
name|ResumeInst
argument_list|(
name|Value
operator|*
name|Exn
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
argument_list|)
block|;
name|ResumeInst
argument_list|(
name|Value
operator|*
name|Exn
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|ResumeInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
specifier|static
name|ResumeInst
operator|*
name|Create
argument_list|(
argument|Value *Exn
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|1
argument_list|)
name|ResumeInst
argument_list|(
name|Exn
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|ResumeInst
operator|*
name|Create
argument_list|(
argument|Value *Exn
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|1
argument_list|)
name|ResumeInst
argument_list|(
name|Exn
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|/// Convenience accessor.
name|Value
operator|*
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
return|;
block|}
name|unsigned
name|getNumSuccessors
argument_list|()
specifier|const
block|{
return|return
literal|0
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
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Resume
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
name|private
operator|:
name|friend
name|TerminatorInst
block|;
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|;
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|void
name|setSuccessorV
argument_list|(
argument|unsigned idx
argument_list|,
argument|BasicBlock *B
argument_list|)
block|; }
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|ResumeInst
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|ResumeInst
block|,
literal|1
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|ResumeInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                         CatchSwitchInst Class
comment|//===----------------------------------------------------------------------===//
name|class
name|CatchSwitchInst
operator|:
name|public
name|TerminatorInst
block|{
comment|/// The number of operands actually allocated.  NumOperands is
comment|/// the number actually in use.
name|unsigned
name|ReservedSpace
block|;
comment|// Operand[0] = Outer scope
comment|// Operand[1] = Unwind block destination
comment|// Operand[n] = BasicBlock to go to on match
name|CatchSwitchInst
argument_list|(
specifier|const
name|CatchSwitchInst
operator|&
name|CSI
argument_list|)
block|;
comment|/// Create a new switch instruction, specifying a
comment|/// default destination.  The number of additional handlers can be specified
comment|/// here to make memory allocation more efficient.
comment|/// This constructor can also autoinsert before another instruction.
name|CatchSwitchInst
argument_list|(
argument|Value *ParentPad
argument_list|,
argument|BasicBlock *UnwindDest
argument_list|,
argument|unsigned NumHandlers
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
block|;
comment|/// Create a new switch instruction, specifying a
comment|/// default destination.  The number of additional handlers can be specified
comment|/// here to make memory allocation more efficient.
comment|/// This constructor also autoinserts at the end of the specified BasicBlock.
name|CatchSwitchInst
argument_list|(
argument|Value *ParentPad
argument_list|,
argument|BasicBlock *UnwindDest
argument_list|,
argument|unsigned NumHandlers
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
comment|// allocate space for exactly zero operands
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
argument_list|)
return|;
block|}
name|void
name|init
argument_list|(
argument|Value *ParentPad
argument_list|,
argument|BasicBlock *UnwindDest
argument_list|,
argument|unsigned NumReserved
argument_list|)
block|;
name|void
name|growOperands
argument_list|(
argument|unsigned Size
argument_list|)
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|CatchSwitchInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
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
specifier|static
name|CatchSwitchInst
operator|*
name|Create
argument_list|(
argument|Value *ParentPad
argument_list|,
argument|BasicBlock *UnwindDest
argument_list|,
argument|unsigned NumHandlers
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
return|return
name|new
name|CatchSwitchInst
argument_list|(
name|ParentPad
argument_list|,
name|UnwindDest
argument_list|,
name|NumHandlers
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|CatchSwitchInst
operator|*
name|Create
argument_list|(
argument|Value *ParentPad
argument_list|,
argument|BasicBlock *UnwindDest
argument_list|,
argument|unsigned NumHandlers
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
name|CatchSwitchInst
argument_list|(
name|ParentPad
argument_list|,
name|UnwindDest
argument_list|,
name|NumHandlers
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|// Accessor Methods for CatchSwitch stmt
name|Value
operator|*
name|getParentPad
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|void
name|setParentPad
argument_list|(
argument|Value *ParentPad
argument_list|)
block|{
name|setOperand
argument_list|(
literal|0
argument_list|,
name|ParentPad
argument_list|)
block|; }
comment|// Accessor Methods for CatchSwitch stmt
name|bool
name|hasUnwindDest
argument_list|()
specifier|const
block|{
return|return
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|1
return|;
block|}
name|bool
name|unwindsToCaller
argument_list|()
specifier|const
block|{
return|return
operator|!
name|hasUnwindDest
argument_list|()
return|;
block|}
name|BasicBlock
operator|*
name|getUnwindDest
argument_list|()
specifier|const
block|{
if|if
condition|(
name|hasUnwindDest
argument_list|()
condition|)
return|return
name|cast
operator|<
name|BasicBlock
operator|>
operator|(
name|getOperand
argument_list|(
literal|1
argument_list|)
operator|)
return|;
return|return
name|nullptr
return|;
block|}
name|void
name|setUnwindDest
argument_list|(
argument|BasicBlock *UnwindDest
argument_list|)
block|{
name|assert
argument_list|(
name|UnwindDest
argument_list|)
block|;
name|assert
argument_list|(
name|hasUnwindDest
argument_list|()
argument_list|)
block|;
name|setOperand
argument_list|(
literal|1
argument_list|,
name|UnwindDest
argument_list|)
block|;   }
comment|/// return the number of 'handlers' in this catchswitch
comment|/// instruction, except the default handler
name|unsigned
name|getNumHandlers
argument_list|()
specifier|const
block|{
if|if
condition|(
name|hasUnwindDest
argument_list|()
condition|)
return|return
name|getNumOperands
argument_list|()
operator|-
literal|2
return|;
return|return
name|getNumOperands
argument_list|()
operator|-
literal|1
return|;
block|}
name|private
operator|:
specifier|static
name|BasicBlock
operator|*
name|handler_helper
argument_list|(
argument|Value *V
argument_list|)
block|{
return|return
name|cast
operator|<
name|BasicBlock
operator|>
operator|(
name|V
operator|)
return|;
block|}
specifier|static
specifier|const
name|BasicBlock
operator|*
name|handler_helper
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|cast
operator|<
name|BasicBlock
operator|>
operator|(
name|V
operator|)
return|;
block|}
name|public
operator|:
name|using
name|DerefFnTy
operator|=
name|std
operator|::
name|pointer_to_unary_function
operator|<
name|Value
operator|*
block|,
name|BasicBlock
operator|*
operator|>
block|;
name|using
name|handler_iterator
operator|=
name|mapped_iterator
operator|<
name|op_iterator
block|,
name|DerefFnTy
operator|>
block|;
name|using
name|handler_range
operator|=
name|iterator_range
operator|<
name|handler_iterator
operator|>
block|;
name|using
name|ConstDerefFnTy
operator|=
name|std
operator|::
name|pointer_to_unary_function
operator|<
specifier|const
name|Value
operator|*
block|,
specifier|const
name|BasicBlock
operator|*
operator|>
block|;
name|using
name|const_handler_iterator
operator|=
name|mapped_iterator
operator|<
name|const_op_iterator
block|,
name|ConstDerefFnTy
operator|>
block|;
name|using
name|const_handler_range
operator|=
name|iterator_range
operator|<
name|const_handler_iterator
operator|>
block|;
comment|/// Returns an iterator that points to the first handler in CatchSwitchInst.
name|handler_iterator
name|handler_begin
argument_list|()
block|{
name|op_iterator
name|It
operator|=
name|op_begin
argument_list|()
operator|+
literal|1
block|;
if|if
condition|(
name|hasUnwindDest
argument_list|()
condition|)
operator|++
name|It
expr_stmt|;
return|return
name|handler_iterator
argument_list|(
name|It
argument_list|,
name|DerefFnTy
argument_list|(
name|handler_helper
argument_list|)
argument_list|)
return|;
block|}
comment|/// Returns an iterator that points to the first handler in the
comment|/// CatchSwitchInst.
name|const_handler_iterator
name|handler_begin
argument_list|()
specifier|const
block|{
name|const_op_iterator
name|It
operator|=
name|op_begin
argument_list|()
operator|+
literal|1
block|;
if|if
condition|(
name|hasUnwindDest
argument_list|()
condition|)
operator|++
name|It
expr_stmt|;
return|return
name|const_handler_iterator
argument_list|(
name|It
argument_list|,
name|ConstDerefFnTy
argument_list|(
name|handler_helper
argument_list|)
argument_list|)
return|;
block|}
comment|/// Returns a read-only iterator that points one past the last
comment|/// handler in the CatchSwitchInst.
name|handler_iterator
name|handler_end
argument_list|()
block|{
return|return
name|handler_iterator
argument_list|(
name|op_end
argument_list|()
argument_list|,
name|DerefFnTy
argument_list|(
name|handler_helper
argument_list|)
argument_list|)
return|;
block|}
comment|/// Returns an iterator that points one past the last handler in the
comment|/// CatchSwitchInst.
name|const_handler_iterator
name|handler_end
argument_list|()
specifier|const
block|{
return|return
name|const_handler_iterator
argument_list|(
name|op_end
argument_list|()
argument_list|,
name|ConstDerefFnTy
argument_list|(
name|handler_helper
argument_list|)
argument_list|)
return|;
block|}
comment|/// iteration adapter for range-for loops.
name|handler_range
name|handlers
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|handler_begin
argument_list|()
argument_list|,
name|handler_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// iteration adapter for range-for loops.
name|const_handler_range
name|handlers
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|handler_begin
argument_list|()
argument_list|,
name|handler_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// Add an entry to the switch instruction...
comment|/// Note:
comment|/// This action invalidates handler_end(). Old handler_end() iterator will
comment|/// point to the added handler.
name|void
name|addHandler
argument_list|(
name|BasicBlock
operator|*
name|Dest
argument_list|)
block|;
name|void
name|removeHandler
argument_list|(
argument|handler_iterator HI
argument_list|)
block|;
name|unsigned
name|getNumSuccessors
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
name|BasicBlock
operator|*
name|getSuccessor
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|getNumSuccessors
argument_list|()
operator|&&
literal|"Successor # out of range for catchswitch!"
argument_list|)
block|;
return|return
name|cast
operator|<
name|BasicBlock
operator|>
operator|(
name|getOperand
argument_list|(
name|Idx
operator|+
literal|1
argument_list|)
operator|)
return|;
block|}
name|void
name|setSuccessor
argument_list|(
argument|unsigned Idx
argument_list|,
argument|BasicBlock *NewSucc
argument_list|)
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|getNumSuccessors
argument_list|()
operator|&&
literal|"Successor # out of range for catchswitch!"
argument_list|)
block|;
name|setOperand
argument_list|(
name|Idx
operator|+
literal|1
argument_list|,
name|NewSucc
argument_list|)
block|;   }
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
name|CatchSwitch
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
name|private
operator|:
name|friend
name|TerminatorInst
block|;
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|;
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|void
name|setSuccessorV
argument_list|(
argument|unsigned Idx
argument_list|,
argument|BasicBlock *B
argument_list|)
block|; }
decl_stmt|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|CatchSwitchInst
operator|>
operator|:
name|public
name|HungoffOperandTraits
operator|<
literal|2
operator|>
block|{}
expr_stmt|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|CatchSwitchInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                               CleanupPadInst Class
comment|//===----------------------------------------------------------------------===//
name|class
name|CleanupPadInst
range|:
name|public
name|FuncletPadInst
block|{
name|private
operator|:
name|explicit
name|CleanupPadInst
argument_list|(
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
operator|:
name|FuncletPadInst
argument_list|(
argument|Instruction::CleanupPad
argument_list|,
argument|ParentPad
argument_list|,
argument|Args
argument_list|,
argument|Values
argument_list|,
argument|NameStr
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
name|explicit
name|CleanupPadInst
argument_list|(
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
operator|:
name|FuncletPadInst
argument_list|(
argument|Instruction::CleanupPad
argument_list|,
argument|ParentPad
argument_list|,
argument|Args
argument_list|,
argument|Values
argument_list|,
argument|NameStr
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|CleanupPadInst
operator|*
name|Create
argument_list|(
argument|Value *ParentPad
argument_list|,
argument|ArrayRef<Value *> Args = None
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
name|unsigned
name|Values
operator|=
literal|1
operator|+
name|Args
operator|.
name|size
argument_list|()
block|;
return|return
name|new
argument_list|(
argument|Values
argument_list|)
name|CleanupPadInst
argument_list|(
name|ParentPad
argument_list|,
name|Args
argument_list|,
name|Values
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|CleanupPadInst
operator|*
name|Create
argument_list|(
argument|Value *ParentPad
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
name|unsigned
name|Values
operator|=
literal|1
operator|+
name|Args
operator|.
name|size
argument_list|()
block|;
return|return
name|new
argument_list|(
argument|Values
argument_list|)
name|CleanupPadInst
argument_list|(
name|ParentPad
argument_list|,
name|Args
argument_list|,
name|Values
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|CleanupPad
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
comment|//                               CatchPadInst Class
comment|//===----------------------------------------------------------------------===//
name|class
name|CatchPadInst
operator|:
name|public
name|FuncletPadInst
block|{
name|private
operator|:
name|explicit
name|CatchPadInst
argument_list|(
argument|Value *CatchSwitch
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
operator|:
name|FuncletPadInst
argument_list|(
argument|Instruction::CatchPad
argument_list|,
argument|CatchSwitch
argument_list|,
argument|Args
argument_list|,
argument|Values
argument_list|,
argument|NameStr
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
name|explicit
name|CatchPadInst
argument_list|(
argument|Value *CatchSwitch
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
operator|:
name|FuncletPadInst
argument_list|(
argument|Instruction::CatchPad
argument_list|,
argument|CatchSwitch
argument_list|,
argument|Args
argument_list|,
argument|Values
argument_list|,
argument|NameStr
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|CatchPadInst
operator|*
name|Create
argument_list|(
argument|Value *CatchSwitch
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
name|unsigned
name|Values
operator|=
literal|1
operator|+
name|Args
operator|.
name|size
argument_list|()
block|;
return|return
name|new
argument_list|(
argument|Values
argument_list|)
name|CatchPadInst
argument_list|(
name|CatchSwitch
argument_list|,
name|Args
argument_list|,
name|Values
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|CatchPadInst
operator|*
name|Create
argument_list|(
argument|Value *CatchSwitch
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
name|unsigned
name|Values
operator|=
literal|1
operator|+
name|Args
operator|.
name|size
argument_list|()
block|;
return|return
name|new
argument_list|(
argument|Values
argument_list|)
name|CatchPadInst
argument_list|(
name|CatchSwitch
argument_list|,
name|Args
argument_list|,
name|Values
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Convenience accessors
name|CatchSwitchInst
operator|*
name|getCatchSwitch
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CatchSwitchInst
operator|>
operator|(
name|Op
operator|<
operator|-
literal|1
operator|>
operator|(
operator|)
operator|)
return|;
block|}
name|void
name|setCatchSwitch
argument_list|(
argument|Value *CatchSwitch
argument_list|)
block|{
name|assert
argument_list|(
name|CatchSwitch
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
name|CatchSwitch
block|;   }
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|CatchPad
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
comment|//                               CatchReturnInst Class
comment|//===----------------------------------------------------------------------===//
name|class
name|CatchReturnInst
operator|:
name|public
name|TerminatorInst
block|{
name|CatchReturnInst
argument_list|(
specifier|const
name|CatchReturnInst
operator|&
name|RI
argument_list|)
block|;
name|CatchReturnInst
argument_list|(
name|Value
operator|*
name|CatchPad
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
block|;
name|CatchReturnInst
argument_list|(
name|Value
operator|*
name|CatchPad
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
name|void
name|init
argument_list|(
name|Value
operator|*
name|CatchPad
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|CatchReturnInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
specifier|static
name|CatchReturnInst
operator|*
name|Create
argument_list|(
argument|Value *CatchPad
argument_list|,
argument|BasicBlock *BB
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
name|assert
argument_list|(
name|CatchPad
argument_list|)
block|;
name|assert
argument_list|(
name|BB
argument_list|)
block|;
return|return
name|new
argument_list|(
literal|2
argument_list|)
name|CatchReturnInst
argument_list|(
name|CatchPad
argument_list|,
name|BB
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|CatchReturnInst
operator|*
name|Create
argument_list|(
argument|Value *CatchPad
argument_list|,
argument|BasicBlock *BB
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
name|assert
argument_list|(
name|CatchPad
argument_list|)
block|;
name|assert
argument_list|(
name|BB
argument_list|)
block|;
return|return
name|new
argument_list|(
literal|2
argument_list|)
name|CatchReturnInst
argument_list|(
name|CatchPad
argument_list|,
name|BB
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|/// Convenience accessors.
name|CatchPadInst
operator|*
name|getCatchPad
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CatchPadInst
operator|>
operator|(
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
operator|)
return|;
block|}
name|void
name|setCatchPad
argument_list|(
argument|CatchPadInst *CatchPad
argument_list|)
block|{
name|assert
argument_list|(
name|CatchPad
argument_list|)
block|;
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
operator|=
name|CatchPad
block|;   }
name|BasicBlock
operator|*
name|getSuccessor
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|BasicBlock
operator|>
operator|(
name|Op
operator|<
literal|1
operator|>
operator|(
operator|)
operator|)
return|;
block|}
name|void
name|setSuccessor
argument_list|(
argument|BasicBlock *NewSucc
argument_list|)
block|{
name|assert
argument_list|(
name|NewSucc
argument_list|)
block|;
name|Op
operator|<
literal|1
operator|>
operator|(
operator|)
operator|=
name|NewSucc
block|;   }
name|unsigned
name|getNumSuccessors
argument_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
comment|/// Get the parentPad of this catchret's catchpad's catchswitch.
comment|/// The successor block is implicitly a member of this funclet.
name|Value
operator|*
name|getCatchSwitchParentPad
argument_list|()
specifier|const
block|{
return|return
name|getCatchPad
argument_list|()
operator|->
name|getCatchSwitch
argument_list|()
operator|->
name|getParentPad
argument_list|()
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
operator|(
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|CatchRet
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
name|private
operator|:
name|friend
name|TerminatorInst
block|;
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|;
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|void
name|setSuccessorV
argument_list|(
argument|unsigned Idx
argument_list|,
argument|BasicBlock *B
argument_list|)
block|; }
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|CatchReturnInst
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|CatchReturnInst
block|,
literal|2
operator|>
block|{}
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|CatchReturnInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                               CleanupReturnInst Class
comment|//===----------------------------------------------------------------------===//
name|class
name|CleanupReturnInst
operator|:
name|public
name|TerminatorInst
block|{
name|private
operator|:
name|CleanupReturnInst
argument_list|(
specifier|const
name|CleanupReturnInst
operator|&
name|RI
argument_list|)
block|;
name|CleanupReturnInst
argument_list|(
argument|Value *CleanupPad
argument_list|,
argument|BasicBlock *UnwindBB
argument_list|,
argument|unsigned Values
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|;
name|CleanupReturnInst
argument_list|(
argument|Value *CleanupPad
argument_list|,
argument|BasicBlock *UnwindBB
argument_list|,
argument|unsigned Values
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|void
name|init
argument_list|(
name|Value
operator|*
name|CleanupPad
argument_list|,
name|BasicBlock
operator|*
name|UnwindBB
argument_list|)
block|;
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|CleanupReturnInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
specifier|static
name|CleanupReturnInst
operator|*
name|Create
argument_list|(
argument|Value *CleanupPad
argument_list|,
argument|BasicBlock *UnwindBB = nullptr
argument_list|,
argument|Instruction *InsertBefore = nullptr
argument_list|)
block|{
name|assert
argument_list|(
name|CleanupPad
argument_list|)
block|;
name|unsigned
name|Values
operator|=
literal|1
block|;
if|if
condition|(
name|UnwindBB
condition|)
operator|++
name|Values
expr_stmt|;
return|return
name|new
argument_list|(
argument|Values
argument_list|)
name|CleanupReturnInst
argument_list|(
name|CleanupPad
argument_list|,
name|UnwindBB
argument_list|,
name|Values
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
specifier|static
name|CleanupReturnInst
operator|*
name|Create
argument_list|(
argument|Value *CleanupPad
argument_list|,
argument|BasicBlock *UnwindBB
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
name|assert
argument_list|(
name|CleanupPad
argument_list|)
block|;
name|unsigned
name|Values
operator|=
literal|1
block|;
if|if
condition|(
name|UnwindBB
condition|)
operator|++
name|Values
expr_stmt|;
return|return
name|new
argument_list|(
argument|Values
argument_list|)
name|CleanupReturnInst
argument_list|(
name|CleanupPad
argument_list|,
name|UnwindBB
argument_list|,
name|Values
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
name|bool
name|hasUnwindDest
argument_list|()
specifier|const
block|{
return|return
name|getSubclassDataFromInstruction
argument_list|()
operator|&
literal|1
return|;
block|}
name|bool
name|unwindsToCaller
argument_list|()
specifier|const
block|{
return|return
operator|!
name|hasUnwindDest
argument_list|()
return|;
block|}
comment|/// Convenience accessor.
name|CleanupPadInst
operator|*
name|getCleanupPad
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CleanupPadInst
operator|>
operator|(
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
operator|)
return|;
block|}
name|void
name|setCleanupPad
argument_list|(
argument|CleanupPadInst *CleanupPad
argument_list|)
block|{
name|assert
argument_list|(
name|CleanupPad
argument_list|)
block|;
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
operator|=
name|CleanupPad
block|;   }
name|unsigned
name|getNumSuccessors
argument_list|()
specifier|const
block|{
return|return
name|hasUnwindDest
argument_list|()
operator|?
literal|1
operator|:
literal|0
return|;
block|}
name|BasicBlock
operator|*
name|getUnwindDest
argument_list|()
specifier|const
block|{
return|return
name|hasUnwindDest
argument_list|()
condition|?
name|cast
operator|<
name|BasicBlock
operator|>
operator|(
name|Op
operator|<
literal|1
operator|>
operator|(
operator|)
operator|)
else|:
name|nullptr
return|;
block|}
name|void
name|setUnwindDest
argument_list|(
argument|BasicBlock *NewDest
argument_list|)
block|{
name|assert
argument_list|(
name|NewDest
argument_list|)
block|;
name|assert
argument_list|(
name|hasUnwindDest
argument_list|()
argument_list|)
block|;
name|Op
operator|<
literal|1
operator|>
operator|(
operator|)
operator|=
name|NewDest
block|;   }
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
operator|(
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|CleanupRet
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
name|private
operator|:
name|friend
name|TerminatorInst
block|;
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|;
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|void
name|setSuccessorV
argument_list|(
argument|unsigned Idx
argument_list|,
argument|BasicBlock *B
argument_list|)
block|;
comment|// Shadow Instruction::setInstructionSubclassData with a private forwarding
comment|// method so that subclasses cannot accidentally use it.
name|void
name|setInstructionSubclassData
argument_list|(
argument|unsigned short D
argument_list|)
block|{
name|Instruction
operator|::
name|setInstructionSubclassData
argument_list|(
name|D
argument_list|)
block|;   }
block|}
decl_stmt|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|CleanupReturnInst
operator|>
operator|:
name|public
name|VariadicOperandTraits
operator|<
name|CleanupReturnInst
operator|,
comment|/*MINARITY=*/
literal|1
operator|>
block|{}
expr_stmt|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|CleanupReturnInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                           UnreachableInst Class
comment|//===----------------------------------------------------------------------===//
comment|//===---------------------------------------------------------------------------
comment|/// This function has undefined behavior.  In particular, the
comment|/// presence of this instruction indicates some higher level knowledge that the
comment|/// end of the block cannot be reached.
comment|///
name|class
name|UnreachableInst
range|:
name|public
name|TerminatorInst
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
name|UnreachableInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
name|explicit
name|UnreachableInst
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
argument_list|)
block|;
name|explicit
name|UnreachableInst
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
block|;
comment|// allocate space for exactly zero operands
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
literal|0
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
name|unsigned
name|getNumSuccessors
argument_list|()
specifier|const
block|{
return|return
literal|0
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
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Unreachable
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
name|private
operator|:
name|friend
name|TerminatorInst
block|;
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|;
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|void
name|setSuccessorV
argument_list|(
argument|unsigned idx
argument_list|,
argument|BasicBlock *B
argument_list|)
block|; }
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//                                 TruncInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents a truncation of integer types.
name|class
name|TruncInst
range|:
name|public
name|CastInst
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
comment|/// Clone an identical TruncInst
name|TruncInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Constructor with insert-before-instruction semantics
name|TruncInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be truncated
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The (smaller) type to truncate to
specifier|const
name|Twine
operator|&
name|NameStr
operator|=
literal|""
argument_list|,
comment|///< A name for the new instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// Constructor with insert-at-end-of-block semantics
name|TruncInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be truncated
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The (smaller) type to truncate to
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
comment|///< A name for the new instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|Trunc
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
comment|//                                 ZExtInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents zero extension of integer types.
name|class
name|ZExtInst
operator|:
name|public
name|CastInst
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
comment|/// Clone an identical ZExtInst
name|ZExtInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Constructor with insert-before-instruction semantics
name|ZExtInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be zero extended
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to zero extend to
specifier|const
name|Twine
operator|&
name|NameStr
operator|=
literal|""
argument_list|,
comment|///< A name for the new instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// Constructor with insert-at-end semantics.
name|ZExtInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be zero extended
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to zero extend to
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
comment|///< A name for the new instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|ZExt
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
comment|//                                 SExtInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents a sign extension of integer types.
name|class
name|SExtInst
operator|:
name|public
name|CastInst
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
comment|/// Clone an identical SExtInst
name|SExtInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Constructor with insert-before-instruction semantics
name|SExtInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be sign extended
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to sign extend to
specifier|const
name|Twine
operator|&
name|NameStr
operator|=
literal|""
argument_list|,
comment|///< A name for the new instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// Constructor with insert-at-end-of-block semantics
name|SExtInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be sign extended
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to sign extend to
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
comment|///< A name for the new instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|SExt
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
comment|//                                 FPTruncInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents a truncation of floating point types.
name|class
name|FPTruncInst
operator|:
name|public
name|CastInst
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
comment|/// Clone an identical FPTruncInst
name|FPTruncInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Constructor with insert-before-instruction semantics
name|FPTruncInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be truncated
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to truncate to
specifier|const
name|Twine
operator|&
name|NameStr
operator|=
literal|""
argument_list|,
comment|///< A name for the new instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// Constructor with insert-before-instruction semantics
name|FPTruncInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be truncated
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to truncate to
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
comment|///< A name for the new instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|FPTrunc
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
comment|//                                 FPExtInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents an extension of floating point types.
name|class
name|FPExtInst
operator|:
name|public
name|CastInst
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
comment|/// Clone an identical FPExtInst
name|FPExtInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Constructor with insert-before-instruction semantics
name|FPExtInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be extended
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to extend to
specifier|const
name|Twine
operator|&
name|NameStr
operator|=
literal|""
argument_list|,
comment|///< A name for the new instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// Constructor with insert-at-end-of-block semantics
name|FPExtInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be extended
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to extend to
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
comment|///< A name for the new instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|FPExt
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
comment|//                                 UIToFPInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents a cast unsigned integer to floating point.
name|class
name|UIToFPInst
operator|:
name|public
name|CastInst
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
comment|/// Clone an identical UIToFPInst
name|UIToFPInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Constructor with insert-before-instruction semantics
name|UIToFPInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to convert to
specifier|const
name|Twine
operator|&
name|NameStr
operator|=
literal|""
argument_list|,
comment|///< A name for the new instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// Constructor with insert-at-end-of-block semantics
name|UIToFPInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to convert to
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
comment|///< A name for the new instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|UIToFP
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
comment|//                                 SIToFPInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents a cast from signed integer to floating point.
name|class
name|SIToFPInst
operator|:
name|public
name|CastInst
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
comment|/// Clone an identical SIToFPInst
name|SIToFPInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Constructor with insert-before-instruction semantics
name|SIToFPInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to convert to
specifier|const
name|Twine
operator|&
name|NameStr
operator|=
literal|""
argument_list|,
comment|///< A name for the new instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// Constructor with insert-at-end-of-block semantics
name|SIToFPInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to convert to
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
comment|///< A name for the new instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|SIToFP
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
comment|//                                 FPToUIInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents a cast from floating point to unsigned integer
name|class
name|FPToUIInst
operator|:
name|public
name|CastInst
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
comment|/// Clone an identical FPToUIInst
name|FPToUIInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Constructor with insert-before-instruction semantics
name|FPToUIInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to convert to
specifier|const
name|Twine
operator|&
name|NameStr
operator|=
literal|""
argument_list|,
comment|///< A name for the new instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// Constructor with insert-at-end-of-block semantics
name|FPToUIInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to convert to
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
comment|///< A name for the new instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|FPToUI
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
comment|//                                 FPToSIInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents a cast from floating point to signed integer.
name|class
name|FPToSIInst
operator|:
name|public
name|CastInst
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
comment|/// Clone an identical FPToSIInst
name|FPToSIInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Constructor with insert-before-instruction semantics
name|FPToSIInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to convert to
specifier|const
name|Twine
operator|&
name|NameStr
operator|=
literal|""
argument_list|,
comment|///< A name for the new instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// Constructor with insert-at-end-of-block semantics
name|FPToSIInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to convert to
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
comment|///< A name for the new instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|FPToSI
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
comment|//                                 IntToPtrInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents a cast from an integer to a pointer.
name|class
name|IntToPtrInst
operator|:
name|public
name|CastInst
block|{
name|public
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
comment|/// Constructor with insert-before-instruction semantics
name|IntToPtrInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to convert to
specifier|const
name|Twine
operator|&
name|NameStr
operator|=
literal|""
argument_list|,
comment|///< A name for the new instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// Constructor with insert-at-end-of-block semantics
name|IntToPtrInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to convert to
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
comment|///< A name for the new instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// Clone an identical IntToPtrInst.
name|IntToPtrInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
comment|/// Returns the address space of this instruction's pointer type.
name|unsigned
name|getAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|->
name|getPointerAddressSpace
argument_list|()
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
name|getOpcode
argument_list|()
operator|==
name|IntToPtr
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
comment|//                                 PtrToIntInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents a cast from a pointer to an integer.
name|class
name|PtrToIntInst
operator|:
name|public
name|CastInst
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
comment|/// Clone an identical PtrToIntInst.
name|PtrToIntInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Constructor with insert-before-instruction semantics
name|PtrToIntInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to convert to
specifier|const
name|Twine
operator|&
name|NameStr
operator|=
literal|""
argument_list|,
comment|///< A name for the new instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// Constructor with insert-at-end-of-block semantics
name|PtrToIntInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to convert to
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
comment|///< A name for the new instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
argument_list|)
block|;
comment|/// Gets the pointer operand.
name|Value
operator|*
name|getPointerOperand
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// Gets the pointer operand.
specifier|const
name|Value
operator|*
name|getPointerOperand
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// Gets the operand index of the pointer operand.
specifier|static
name|unsigned
name|getPointerOperandIndex
argument_list|()
block|{
return|return
literal|0U
return|;
block|}
comment|/// Returns the address space of the pointer operand.
name|unsigned
name|getPointerAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|getPointerOperand
argument_list|()
operator|->
name|getType
argument_list|()
operator|->
name|getPointerAddressSpace
argument_list|()
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
name|getOpcode
argument_list|()
operator|==
name|PtrToInt
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
comment|//                             BitCastInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents a no-op cast from one type to another.
name|class
name|BitCastInst
operator|:
name|public
name|CastInst
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
comment|/// Clone an identical BitCastInst.
name|BitCastInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Constructor with insert-before-instruction semantics
name|BitCastInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be casted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to casted to
specifier|const
name|Twine
operator|&
name|NameStr
operator|=
literal|""
argument_list|,
comment|///< A name for the new instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// Constructor with insert-at-end-of-block semantics
name|BitCastInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be casted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to casted to
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
comment|///< A name for the new instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
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
name|BitCast
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
comment|//                          AddrSpaceCastInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// This class represents a conversion between pointers from one address space
comment|/// to another.
name|class
name|AddrSpaceCastInst
operator|:
name|public
name|CastInst
block|{
name|protected
operator|:
comment|// Note: Instruction needs to be a friend here to call cloneImpl.
name|friend
name|class
name|Instruction
block|;
comment|/// Clone an identical AddrSpaceCastInst.
name|AddrSpaceCastInst
operator|*
name|cloneImpl
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// Constructor with insert-before-instruction semantics
name|AddrSpaceCastInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be casted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to casted to
specifier|const
name|Twine
operator|&
name|NameStr
operator|=
literal|""
argument_list|,
comment|///< A name for the new instruction
name|Instruction
operator|*
name|InsertBefore
operator|=
name|nullptr
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// Constructor with insert-at-end-of-block semantics
name|AddrSpaceCastInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be casted
name|Type
operator|*
name|Ty
argument_list|,
comment|///< The type to casted to
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
comment|///< A name for the new instruction
name|BasicBlock
operator|*
name|InsertAtEnd
comment|///< The block to insert the instruction into
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
name|AddrSpaceCast
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
comment|/// Gets the pointer operand.
name|Value
operator|*
name|getPointerOperand
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// Gets the pointer operand.
specifier|const
name|Value
operator|*
name|getPointerOperand
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// Gets the operand index of the pointer operand.
specifier|static
name|unsigned
name|getPointerOperandIndex
argument_list|()
block|{
return|return
literal|0U
return|;
block|}
comment|/// Returns the address space of the pointer operand.
name|unsigned
name|getSrcAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|getPointerOperand
argument_list|()
operator|->
name|getType
argument_list|()
operator|->
name|getPointerAddressSpace
argument_list|()
return|;
block|}
comment|/// Returns the address space of the result.
name|unsigned
name|getDestAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|->
name|getPointerAddressSpace
argument_list|()
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_INSTRUCTIONS_H
end_comment

end_unit

