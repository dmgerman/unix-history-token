begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Instructions.h - Instruction subclass definitions --*- C++ -*-===//
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
name|LLVM_INSTRUCTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_INSTRUCTIONS_H
end_define

begin_include
include|#
directive|include
file|"llvm/InstrTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DerivedTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Attributes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/LLVMContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
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
name|ConstantInt
decl_stmt|;
name|class
name|ConstantRange
decl_stmt|;
name|class
name|APInt
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//                             AllocationInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// AllocationInst - This class is the common base class of MallocInst and
comment|/// AllocaInst.
comment|///
name|class
name|AllocationInst
range|:
name|public
name|UnaryInstruction
block|{
name|protected
operator|:
name|AllocationInst
argument_list|(
argument|const Type *Ty
argument_list|,
argument|Value *ArraySize
argument_list|,
argument|unsigned iTy
argument_list|,
argument|unsigned Align
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|;
name|AllocationInst
argument_list|(
argument|const Type *Ty
argument_list|,
argument|Value *ArraySize
argument_list|,
argument|unsigned iTy
argument_list|,
argument|unsigned Align
argument_list|,
argument|const Twine&Name
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|public
operator|:
comment|// Out of line virtual method, so the vtable, etc. has a home.
name|virtual
operator|~
name|AllocationInst
argument_list|()
block|;
comment|/// isArrayAllocation - Return true if there is an allocation size parameter
comment|/// to the allocation instruction that is not 1.
comment|///
name|bool
name|isArrayAllocation
argument_list|()
specifier|const
block|;
comment|/// getArraySize - Get the number of elements allocated. For a simple
comment|/// allocation of a single element, this will return a constant 1 value.
comment|///
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
comment|/// getType - Overload to return most specific pointer type
comment|///
specifier|const
name|PointerType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|PointerType
operator|*
operator|>
operator|(
name|Instruction
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// getAllocatedType - Return the type that is being allocated by the
comment|/// instruction.
comment|///
specifier|const
name|Type
operator|*
name|getAllocatedType
argument_list|()
specifier|const
block|;
comment|/// getAlignment - Return the alignment of the memory that is being allocated
comment|/// by the instruction.
comment|///
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
operator|(
literal|1u
operator|<<
name|SubclassData
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
name|virtual
name|AllocationInst
operator|*
name|clone
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const AllocationInst *
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
name|Malloc
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
comment|//                                MallocInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// MallocInst - an instruction to allocated memory on the heap
comment|///
name|class
name|MallocInst
operator|:
name|public
name|AllocationInst
block|{
name|public
operator|:
name|explicit
name|MallocInst
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
name|Value
operator|*
name|ArraySize
operator|=
literal|0
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
literal|0
argument_list|)
operator|:
name|AllocationInst
argument_list|(
argument|Ty
argument_list|,
argument|ArraySize
argument_list|,
argument|Malloc
argument_list|,
literal|0
argument_list|,
argument|NameStr
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
name|MallocInst
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
name|Value
operator|*
name|ArraySize
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
name|AllocationInst
argument_list|(
argument|Ty
argument_list|,
argument|ArraySize
argument_list|,
argument|Malloc
argument_list|,
literal|0
argument_list|,
argument|NameStr
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{}
name|MallocInst
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
literal|0
argument_list|)
operator|:
name|AllocationInst
argument_list|(
argument|Ty
argument_list|,
literal|0
argument_list|,
argument|Malloc
argument_list|,
literal|0
argument_list|,
argument|NameStr
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
name|MallocInst
argument_list|(
specifier|const
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
name|AllocationInst
argument_list|(
argument|Ty
argument_list|,
literal|0
argument_list|,
argument|Malloc
argument_list|,
literal|0
argument_list|,
argument|NameStr
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{}
name|MallocInst
argument_list|(
argument|const Type *Ty
argument_list|,
argument|Value *ArraySize
argument_list|,
argument|unsigned Align
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
operator|:
name|AllocationInst
argument_list|(
argument|Ty
argument_list|,
argument|ArraySize
argument_list|,
argument|Malloc
argument_list|,
argument|Align
argument_list|,
argument|NameStr
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{}
name|MallocInst
argument_list|(
argument|const Type *Ty
argument_list|,
argument|Value *ArraySize
argument_list|,
argument|unsigned Align
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
operator|:
name|AllocationInst
argument_list|(
argument|Ty
argument_list|,
argument|ArraySize
argument_list|,
argument|Malloc
argument_list|,
argument|Align
argument_list|,
argument|NameStr
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
name|virtual
name|MallocInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const MallocInst *
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
operator|(
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Malloc
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
comment|//===----------------------------------------------------------------------===//
comment|//                                AllocaInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// AllocaInst - an instruction to allocate memory on the stack
comment|///
name|class
name|AllocaInst
operator|:
name|public
name|AllocationInst
block|{
name|public
operator|:
name|explicit
name|AllocaInst
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
name|Value
operator|*
name|ArraySize
operator|=
literal|0
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
literal|0
argument_list|)
operator|:
name|AllocationInst
argument_list|(
argument|Ty
argument_list|,
argument|ArraySize
argument_list|,
argument|Alloca
argument_list|,
literal|0
argument_list|,
argument|NameStr
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
name|AllocaInst
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
name|Value
operator|*
name|ArraySize
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
name|AllocationInst
argument_list|(
argument|Ty
argument_list|,
argument|ArraySize
argument_list|,
argument|Alloca
argument_list|,
literal|0
argument_list|,
argument|NameStr
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{}
name|AllocaInst
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
literal|0
argument_list|)
operator|:
name|AllocationInst
argument_list|(
argument|Ty
argument_list|,
literal|0
argument_list|,
argument|Alloca
argument_list|,
literal|0
argument_list|,
argument|NameStr
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
name|AllocaInst
argument_list|(
specifier|const
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
name|AllocationInst
argument_list|(
argument|Ty
argument_list|,
literal|0
argument_list|,
argument|Alloca
argument_list|,
literal|0
argument_list|,
argument|NameStr
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{}
name|AllocaInst
argument_list|(
argument|const Type *Ty
argument_list|,
argument|Value *ArraySize
argument_list|,
argument|unsigned Align
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
operator|:
name|AllocationInst
argument_list|(
argument|Ty
argument_list|,
argument|ArraySize
argument_list|,
argument|Alloca
argument_list|,
argument|Align
argument_list|,
argument|NameStr
argument_list|,
argument|InsertBefore
argument_list|)
block|{}
name|AllocaInst
argument_list|(
argument|const Type *Ty
argument_list|,
argument|Value *ArraySize
argument_list|,
argument|unsigned Align
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
operator|:
name|AllocationInst
argument_list|(
argument|Ty
argument_list|,
argument|ArraySize
argument_list|,
argument|Alloca
argument_list|,
argument|Align
argument_list|,
argument|NameStr
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{}
name|virtual
name|AllocaInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// isStaticAlloca - Return true if this alloca is in the entry block of the
comment|/// function and is a constant size.  If so, the code generator will fold it
comment|/// into the prolog/epilog code, so it is basically free.
name|bool
name|isStaticAlloca
argument_list|()
specifier|const
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const AllocaInst *
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
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|//                                 FreeInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// FreeInst - an instruction to deallocate memory
comment|///
name|class
name|FreeInst
operator|:
name|public
name|UnaryInstruction
block|{
name|void
name|AssertOK
argument_list|()
block|;
name|public
operator|:
name|explicit
name|FreeInst
argument_list|(
name|Value
operator|*
name|Ptr
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
literal|0
argument_list|)
block|;
name|FreeInst
argument_list|(
name|Value
operator|*
name|Ptr
argument_list|,
name|BasicBlock
operator|*
name|InsertAfter
argument_list|)
block|;
name|virtual
name|FreeInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|// Accessor methods for consistency with other memory operations
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
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const FreeInst *
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
operator|(
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Free
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
comment|//===----------------------------------------------------------------------===//
comment|//                                LoadInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// LoadInst - an instruction for reading from memory.  This uses the
comment|/// SubclassData field in Value to store whether or not the load is volatile.
comment|///
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
argument|Value *Ptr
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|bool isVolatile = false
argument_list|,
argument|Instruction *InsertBefore =
literal|0
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
argument|Instruction *InsertBefore =
literal|0
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
name|explicit
name|LoadInst
argument_list|(
argument|Value *Ptr
argument_list|,
argument|const char *NameStr =
literal|0
argument_list|,
argument|bool isVolatile = false
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|;
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
comment|/// isVolatile - Return true if this is a load from a volatile memory
comment|/// location.
comment|///
name|bool
name|isVolatile
argument_list|()
specifier|const
block|{
return|return
name|SubclassData
operator|&
literal|1
return|;
block|}
comment|/// setVolatile - Specify whether this is a volatile load or not.
comment|///
name|void
name|setVolatile
argument_list|(
argument|bool V
argument_list|)
block|{
name|SubclassData
operator|=
operator|(
name|SubclassData
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
block|;   }
name|virtual
name|LoadInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// getAlignment - Return the alignment of the access that is being performed
comment|///
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
name|SubclassData
operator|>>
literal|1
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
name|unsigned
name|getPointerAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|getPointerOperand
argument_list|()
operator|->
name|getType
argument_list|()
operator|)
operator|->
name|getAddressSpace
argument_list|()
return|;
block|}
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const LoadInst *
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
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|//                                StoreInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// StoreInst - an instruction for storing to memory
comment|///
name|class
name|StoreInst
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
name|void
name|AssertOK
argument_list|()
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
argument|Instruction *InsertBefore =
literal|0
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
argument|Instruction *InsertBefore =
literal|0
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
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
comment|/// isVolatile - Return true if this is a load from a volatile memory
comment|/// location.
comment|///
name|bool
name|isVolatile
argument_list|()
specifier|const
block|{
return|return
name|SubclassData
operator|&
literal|1
return|;
block|}
comment|/// setVolatile - Specify whether this is a volatile load or not.
comment|///
name|void
name|setVolatile
argument_list|(
argument|bool V
argument_list|)
block|{
name|SubclassData
operator|=
operator|(
name|SubclassData
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
block|;   }
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|/// getAlignment - Return the alignment of the access that is being performed
comment|///
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
name|SubclassData
operator|>>
literal|1
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
name|virtual
name|StoreInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
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
name|unsigned
name|getPointerAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|getPointerOperand
argument_list|()
operator|->
name|getType
argument_list|()
operator|)
operator|->
name|getAddressSpace
argument_list|()
return|;
block|}
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const StoreInst *
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
comment|//                             GetElementPtrInst Class
comment|//===----------------------------------------------------------------------===//
comment|// checkType - Simple wrapper function to give a better assertion failure
comment|// message on bad indexes for a gep instruction.
comment|//
specifier|static
specifier|inline
specifier|const
name|Type
operator|*
name|checkType
argument_list|(
argument|const Type *Ty
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
comment|/// GetElementPtrInst - an instruction for type-safe pointer arithmetic to
comment|/// access elements of arrays and structs
comment|///
name|class
name|GetElementPtrInst
operator|:
name|public
name|Instruction
block|{
name|GetElementPtrInst
argument_list|(
specifier|const
name|GetElementPtrInst
operator|&
name|GEPI
argument_list|)
block|;
name|void
name|init
argument_list|(
argument|Value *Ptr
argument_list|,
argument|Value* const *Idx
argument_list|,
argument|unsigned NumIdx
argument_list|,
argument|const Twine&NameStr
argument_list|)
block|;
name|void
name|init
argument_list|(
name|Value
operator|*
name|Ptr
argument_list|,
name|Value
operator|*
name|Idx
argument_list|,
specifier|const
name|Twine
operator|&
name|NameStr
argument_list|)
block|;
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|void
name|init
argument_list|(
argument|Value *Ptr
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
comment|// This argument ensures that we have an iterator we can
comment|// do arithmetic on in constant time
argument|std::random_access_iterator_tag
argument_list|)
block|{
name|unsigned
name|NumIdx
operator|=
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|std
operator|::
name|distance
argument_list|(
name|IdxBegin
argument_list|,
name|IdxEnd
argument_list|)
operator|)
block|;
if|if
condition|(
name|NumIdx
operator|>
literal|0
condition|)
block|{
comment|// This requires that the iterator points to contiguous memory.
name|init
argument_list|(
name|Ptr
argument_list|,
operator|&
operator|*
name|IdxBegin
argument_list|,
name|NumIdx
argument_list|,
name|NameStr
argument_list|)
expr_stmt|;
comment|// FIXME: for the general case
comment|// we have to build an array here
block|}
else|else
block|{
name|init
argument_list|(
name|Ptr
argument_list|,
literal|0
argument_list|,
name|NumIdx
argument_list|,
name|NameStr
argument_list|)
expr_stmt|;
block|}
block|}
comment|/// getIndexedType - Returns the type of the element that would be loaded with
comment|/// a load instruction with the specified parameters.
comment|///
comment|/// Null is returned if the indices are invalid for the specified
comment|/// pointer type.
comment|///
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|static
specifier|const
name|Type
operator|*
name|getIndexedType
argument_list|(
argument|const Type *Ptr
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
comment|// This argument ensures that we
comment|// have an iterator we can do
comment|// arithmetic on in constant time
argument|std::random_access_iterator_tag
argument_list|)
block|{
name|unsigned
name|NumIdx
operator|=
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|std
operator|::
name|distance
argument_list|(
name|IdxBegin
argument_list|,
name|IdxEnd
argument_list|)
operator|)
block|;
if|if
condition|(
name|NumIdx
operator|>
literal|0
condition|)
comment|// This requires that the iterator points to contiguous memory.
return|return
name|getIndexedType
argument_list|(
name|Ptr
argument_list|,
operator|&
operator|*
name|IdxBegin
argument_list|,
name|NumIdx
argument_list|)
return|;
else|else
return|return
name|getIndexedType
argument_list|(
name|Ptr
argument_list|,
operator|(
name|Value
operator|*
specifier|const
operator|*
operator|)
literal|0
argument_list|,
name|NumIdx
argument_list|)
return|;
block|}
comment|/// Constructors - Create a getelementptr instruction with a base pointer an
comment|/// list of indices.  The first ctor can optionally insert before an existing
comment|/// instruction, the second appends the new instruction to the specified
comment|/// BasicBlock.
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|inline
name|GetElementPtrInst
argument_list|(
argument|Value *Ptr
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
block|;
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|inline
name|GetElementPtrInst
argument_list|(
argument|Value *Ptr
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
comment|/// Constructors - These two constructors are convenience methods because one
comment|/// and two index getelementptr instructions are so common.
name|GetElementPtrInst
argument_list|(
name|Value
operator|*
name|Ptr
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
literal|0
argument_list|)
block|;
name|GetElementPtrInst
argument_list|(
name|Value
operator|*
name|Ptr
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
name|public
operator|:
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|static
name|GetElementPtrInst
operator|*
name|Create
argument_list|(
argument|Value *Ptr
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|{
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|InputIterator
operator|>
operator|::
name|difference_type
name|Values
operator|=
literal|1
operator|+
name|std
operator|::
name|distance
argument_list|(
name|IdxBegin
argument_list|,
name|IdxEnd
argument_list|)
block|;
return|return
name|new
argument_list|(
argument|Values
argument_list|)
name|GetElementPtrInst
argument_list|(
name|Ptr
argument_list|,
name|IdxBegin
argument_list|,
name|IdxEnd
argument_list|,
name|Values
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|static
name|GetElementPtrInst
operator|*
name|Create
argument_list|(
argument|Value *Ptr
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|InputIterator
operator|>
operator|::
name|difference_type
name|Values
operator|=
literal|1
operator|+
name|std
operator|::
name|distance
argument_list|(
name|IdxBegin
argument_list|,
name|IdxEnd
argument_list|)
block|;
return|return
name|new
argument_list|(
argument|Values
argument_list|)
name|GetElementPtrInst
argument_list|(
name|Ptr
argument_list|,
name|IdxBegin
argument_list|,
name|IdxEnd
argument_list|,
name|Values
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Constructors - These two creators are convenience methods because one
comment|/// index getelementptr instructions are so common.
specifier|static
name|GetElementPtrInst
operator|*
name|Create
argument_list|(
argument|Value *Ptr
argument_list|,
argument|Value *Idx
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|2
argument_list|)
name|GetElementPtrInst
argument_list|(
name|Ptr
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
name|GetElementPtrInst
operator|*
name|Create
argument_list|(
argument|Value *Ptr
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
name|GetElementPtrInst
argument_list|(
name|Ptr
argument_list|,
name|Idx
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Create an "inbounds" getelementptr. See the documentation for the
comment|/// "inbounds" flag in LangRef.html for details.
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|static
name|GetElementPtrInst
operator|*
name|CreateInBounds
argument_list|(
argument|Value *Ptr
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|{
name|GetElementPtrInst
operator|*
name|GEP
operator|=
name|Create
argument_list|(
name|Ptr
argument_list|,
name|IdxBegin
argument_list|,
name|IdxEnd
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
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|static
name|GetElementPtrInst
operator|*
name|CreateInBounds
argument_list|(
argument|Value *Ptr
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
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
name|Ptr
argument_list|,
name|IdxBegin
argument_list|,
name|IdxEnd
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
specifier|static
name|GetElementPtrInst
operator|*
name|CreateInBounds
argument_list|(
argument|Value *Ptr
argument_list|,
argument|Value *Idx
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|{
name|GetElementPtrInst
operator|*
name|GEP
operator|=
name|Create
argument_list|(
name|Ptr
argument_list|,
name|Idx
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
argument|Value *Idx
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
name|Ptr
argument_list|,
name|Idx
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
name|virtual
name|GetElementPtrInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|// getType - Overload to return most specific pointer type...
specifier|const
name|PointerType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|PointerType
operator|*
operator|>
operator|(
name|Instruction
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// getIndexedType - Returns the type of the element that would be loaded with
comment|/// a load instruction with the specified parameters.
comment|///
comment|/// Null is returned if the indices are invalid for the specified
comment|/// pointer type.
comment|///
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|static
specifier|const
name|Type
operator|*
name|getIndexedType
argument_list|(
argument|const Type *Ptr
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|)
block|{
return|return
name|getIndexedType
argument_list|(
argument|Ptr
argument_list|,
argument|IdxBegin
argument_list|,
argument|IdxEnd
argument_list|,
argument|typename std::iterator_traits<InputIterator>::                           iterator_category()
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|Type
operator|*
name|getIndexedType
argument_list|(
argument|const Type *Ptr
argument_list|,
argument|Value* const *Idx
argument_list|,
argument|unsigned NumIdx
argument_list|)
block|;
specifier|static
specifier|const
name|Type
operator|*
name|getIndexedType
argument_list|(
argument|const Type *Ptr
argument_list|,
argument|uint64_t const *Idx
argument_list|,
argument|unsigned NumIdx
argument_list|)
block|;
specifier|static
specifier|const
name|Type
operator|*
name|getIndexedType
argument_list|(
specifier|const
name|Type
operator|*
name|Ptr
argument_list|,
name|Value
operator|*
name|Idx
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
comment|// get index for modifying correct operand
block|}
name|unsigned
name|getPointerAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|getType
argument_list|()
operator|)
operator|->
name|getAddressSpace
argument_list|()
return|;
block|}
comment|/// getPointerOperandType - Method to return the pointer operand as a
comment|/// PointerType.
specifier|const
name|PointerType
operator|*
name|getPointerOperandType
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|PointerType
operator|*
operator|>
operator|(
name|getPointerOperand
argument_list|()
operator|->
name|getType
argument_list|()
operator|)
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
comment|/// hasAllZeroIndices - Return true if all of the indices of this GEP are
comment|/// zeros.  If so, the result pointer and the first operand have the same
comment|/// value, just potentially different types.
name|bool
name|hasAllZeroIndices
argument_list|()
specifier|const
block|;
comment|/// hasAllConstantIndices - Return true if all of the indices of this GEP are
comment|/// constant integers.  If so, the result pointer and the first operand have
comment|/// a constant offset between them.
name|bool
name|hasAllConstantIndices
argument_list|()
specifier|const
block|;
comment|/// setIsInBounds - Set or clear the inbounds flag on this GEP instruction.
comment|/// See LangRef.html for the meaning of inbounds on a getelementptr.
name|void
name|setIsInBounds
argument_list|(
argument|bool b = true
argument_list|)
block|;
comment|/// isInBounds - Determine whether the GEP has the inbounds flag.
name|bool
name|isInBounds
argument_list|()
specifier|const
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const GetElementPtrInst *
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
literal|1
operator|>
block|{ }
block|;
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|GetElementPtrInst
operator|::
name|GetElementPtrInst
argument_list|(
argument|Value *Ptr
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
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
argument|PointerType::get(checkType(                                    getIndexedType(Ptr->getType(),                                                   IdxBegin, IdxEnd)),                                  cast<PointerType>(Ptr->getType())                                    ->getAddressSpace())
argument_list|,
argument|GetElementPtr
argument_list|,
argument|OperandTraits<GetElementPtrInst>::op_end(this) - Values
argument_list|,
argument|Values
argument_list|,
argument|InsertBefore
argument_list|)
block|{
name|init
argument_list|(
argument|Ptr
argument_list|,
argument|IdxBegin
argument_list|,
argument|IdxEnd
argument_list|,
argument|NameStr
argument_list|,
argument|typename std::iterator_traits<InputIterator>::iterator_category()
argument_list|)
block|; }
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|GetElementPtrInst
operator|::
name|GetElementPtrInst
argument_list|(
argument|Value *Ptr
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
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
argument|PointerType::get(checkType(                                    getIndexedType(Ptr->getType(),                                                   IdxBegin, IdxEnd)),                                  cast<PointerType>(Ptr->getType())                                    ->getAddressSpace())
argument_list|,
argument|GetElementPtr
argument_list|,
argument|OperandTraits<GetElementPtrInst>::op_end(this) - Values
argument_list|,
argument|Values
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{
name|init
argument_list|(
argument|Ptr
argument_list|,
argument|IdxBegin
argument_list|,
argument|IdxEnd
argument_list|,
argument|NameStr
argument_list|,
argument|typename std::iterator_traits<InputIterator>::iterator_category()
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
comment|/// @brief Represent an integer comparison operator.
name|class
name|ICmpInst
operator|:
name|public
name|CmpInst
block|{
name|public
operator|:
comment|/// @brief Constructor with insert-before-instruction semantics.
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
name|assert
argument_list|(
name|pred
operator|>=
name|CmpInst
operator|::
name|FIRST_ICMP_PREDICATE
operator|&&
name|pred
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
name|isIntOrIntVector
argument_list|()
operator|||
name|isa
operator|<
name|PointerType
operator|>
operator|(
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|->
name|getType
argument_list|()
operator|)
operator|)
operator|&&
literal|"Invalid operand types for ICmp instruction"
argument_list|)
block|;   }
comment|/// @brief Constructor with insert-at-end semantics.
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
name|assert
argument_list|(
name|pred
operator|>=
name|CmpInst
operator|::
name|FIRST_ICMP_PREDICATE
operator|&&
name|pred
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
name|isIntOrIntVector
argument_list|()
operator|||
name|isa
operator|<
name|PointerType
operator|>
operator|(
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|->
name|getType
argument_list|()
operator|)
operator|)
operator|&&
literal|"Invalid operand types for ICmp instruction"
argument_list|)
block|;   }
comment|/// @brief Constructor with no-insertion semantics
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
name|assert
argument_list|(
name|pred
operator|>=
name|CmpInst
operator|::
name|FIRST_ICMP_PREDICATE
operator|&&
name|pred
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
name|isIntOrIntVector
argument_list|()
operator|||
name|isa
operator|<
name|PointerType
operator|>
operator|(
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|->
name|getType
argument_list|()
operator|)
operator|)
operator|&&
literal|"Invalid operand types for ICmp instruction"
argument_list|)
block|;   }
comment|/// For example, EQ->EQ, SLE->SLE, UGT->SGT, etc.
comment|/// @returns the predicate that would be the result if the operand were
comment|/// regarded as signed.
comment|/// @brief Return the signed version of the predicate
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
comment|/// @brief Return the signed version of the predicate.
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
comment|/// @brief Return the unsigned version of the predicate
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
comment|/// @brief Return the unsigned version of the predicate.
specifier|static
name|Predicate
name|getUnsignedPredicate
argument_list|(
argument|Predicate pred
argument_list|)
block|;
comment|/// isEquality - Return true if this predicate is either EQ or NE.  This also
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
comment|/// isEquality - Return true if this predicate is either EQ or NE.  This also
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
comment|/// @brief Determine if this relation is commutative.
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
comment|/// isRelational - Return true if the predicate is relational (not EQ or NE).
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
comment|/// isRelational - Return true if the predicate is relational (not EQ or NE).
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
comment|/// @returns true if the predicate of this ICmpInst is signed, false otherwise
comment|/// @brief Determine if this instruction's predicate is signed.
name|bool
name|isSignedPredicate
argument_list|()
specifier|const
block|{
return|return
name|isSignedPredicate
argument_list|(
name|getPredicate
argument_list|()
argument_list|)
return|;
block|}
comment|/// @returns true if the predicate provided is signed, false otherwise
comment|/// @brief Determine if the predicate is signed.
specifier|static
name|bool
name|isSignedPredicate
argument_list|(
argument|Predicate pred
argument_list|)
block|;
comment|/// @returns true if the specified compare predicate is
comment|/// true when both operands are equal...
comment|/// @brief Determine if the icmp is true when both operands are equal
specifier|static
name|bool
name|isTrueWhenEqual
argument_list|(
argument|ICmpInst::Predicate pred
argument_list|)
block|{
return|return
name|pred
operator|==
name|ICmpInst
operator|::
name|ICMP_EQ
operator|||
name|pred
operator|==
name|ICmpInst
operator|::
name|ICMP_UGE
operator|||
name|pred
operator|==
name|ICmpInst
operator|::
name|ICMP_SGE
operator|||
name|pred
operator|==
name|ICmpInst
operator|::
name|ICMP_ULE
operator|||
name|pred
operator|==
name|ICmpInst
operator|::
name|ICMP_SLE
return|;
block|}
comment|/// @returns true if the specified compare instruction is
comment|/// true when both operands are equal...
comment|/// @brief Determine if the ICmpInst returns true when both operands are equal
name|bool
name|isTrueWhenEqual
argument_list|()
block|{
return|return
name|isTrueWhenEqual
argument_list|(
name|getPredicate
argument_list|()
argument_list|)
return|;
block|}
comment|/// Initialize a set of values that all satisfy the predicate with C.
comment|/// @brief Make a ConstantRange for a relation with a constant value.
specifier|static
name|ConstantRange
name|makeConstantRange
argument_list|(
argument|Predicate pred
argument_list|,
argument|const APInt&C
argument_list|)
block|;
comment|/// Exchange the two operands to this instruction in such a way that it does
comment|/// not modify the semantics of the instruction. The predicate value may be
comment|/// changed to retain the same result if the predicate is order dependent
comment|/// (e.g. ult).
comment|/// @brief Swap operands and adjust predicate.
name|void
name|swapOperands
argument_list|()
block|{
name|SubclassData
operator|=
name|getSwappedPredicate
argument_list|()
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
name|virtual
name|ICmpInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const ICmpInst *
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
comment|/// @brief Represents a floating point comparison operator.
name|class
name|FCmpInst
operator|:
name|public
name|CmpInst
block|{
name|public
operator|:
comment|/// @brief Constructor with insert-before-instruction semantics.
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
name|isFPOrFPVector
argument_list|()
operator|&&
literal|"Invalid operand types for FCmp instruction"
argument_list|)
block|;   }
comment|/// @brief Constructor with insert-at-end semantics.
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
name|isFPOrFPVector
argument_list|()
operator|&&
literal|"Invalid operand types for FCmp instruction"
argument_list|)
block|;   }
comment|/// @brief Constructor with no-insertion semantics
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
name|isFPOrFPVector
argument_list|()
operator|&&
literal|"Invalid operand types for FCmp instruction"
argument_list|)
block|;   }
comment|/// @returns true if the predicate of this instruction is EQ or NE.
comment|/// @brief Determine if this is an equality predicate.
name|bool
name|isEquality
argument_list|()
specifier|const
block|{
return|return
name|SubclassData
operator|==
name|FCMP_OEQ
operator|||
name|SubclassData
operator|==
name|FCMP_ONE
operator|||
name|SubclassData
operator|==
name|FCMP_UEQ
operator|||
name|SubclassData
operator|==
name|FCMP_UNE
return|;
block|}
comment|/// @returns true if the predicate of this instruction is commutative.
comment|/// @brief Determine if this is a commutative predicate.
name|bool
name|isCommutative
argument_list|()
specifier|const
block|{
return|return
name|isEquality
argument_list|()
operator|||
name|SubclassData
operator|==
name|FCMP_FALSE
operator|||
name|SubclassData
operator|==
name|FCMP_TRUE
operator|||
name|SubclassData
operator|==
name|FCMP_ORD
operator|||
name|SubclassData
operator|==
name|FCMP_UNO
return|;
block|}
comment|/// @returns true if the predicate is relational (not EQ or NE).
comment|/// @brief Determine if this a relational predicate.
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
comment|/// @brief Swap operands and adjust predicate.
name|void
name|swapOperands
argument_list|()
block|{
name|SubclassData
operator|=
name|getSwappedPredicate
argument_list|()
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
name|virtual
name|FCmpInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// @brief Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const FCmpInst *
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
comment|//                                 CallInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// CallInst - This class represents a function call, abstracting a target
comment|/// machine's calling convention.  This class uses low bit of the SubClassData
comment|/// field to indicate whether or not this is a tail call.  The rest of the bits
comment|/// hold the calling convention of the call.
comment|///
name|class
name|CallInst
operator|:
name|public
name|Instruction
block|{
name|AttrListPtr
name|AttributeList
block|;
comment|///< parameter attributes for call
name|CallInst
argument_list|(
specifier|const
name|CallInst
operator|&
name|CI
argument_list|)
block|;
name|void
name|init
argument_list|(
argument|Value *Func
argument_list|,
argument|Value* const *Params
argument_list|,
argument|unsigned NumParams
argument_list|)
block|;
name|void
name|init
argument_list|(
name|Value
operator|*
name|Func
argument_list|,
name|Value
operator|*
name|Actual1
argument_list|,
name|Value
operator|*
name|Actual2
argument_list|)
block|;
name|void
name|init
argument_list|(
name|Value
operator|*
name|Func
argument_list|,
name|Value
operator|*
name|Actual
argument_list|)
block|;
name|void
name|init
argument_list|(
name|Value
operator|*
name|Func
argument_list|)
block|;
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|void
name|init
argument_list|(
argument|Value *Func
argument_list|,
argument|InputIterator ArgBegin
argument_list|,
argument|InputIterator ArgEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
comment|// This argument ensures that we have an iterator we can
comment|// do arithmetic on in constant time
argument|std::random_access_iterator_tag
argument_list|)
block|{
name|unsigned
name|NumArgs
operator|=
operator|(
name|unsigned
operator|)
name|std
operator|::
name|distance
argument_list|(
name|ArgBegin
argument_list|,
name|ArgEnd
argument_list|)
block|;
comment|// This requires that the iterator points to contiguous memory.
name|init
argument_list|(
name|Func
argument_list|,
name|NumArgs
condition|?
operator|&
operator|*
name|ArgBegin
else|:
literal|0
argument_list|,
name|NumArgs
argument_list|)
block|;
name|setName
argument_list|(
name|NameStr
argument_list|)
block|;   }
comment|/// Construct a CallInst given a range of arguments.  InputIterator
comment|/// must be a random-access iterator pointing to contiguous storage
comment|/// (e.g. a std::vector<>::iterator).  Checks are made for
comment|/// random-accessness but not for contiguous storage as that would
comment|/// incur runtime overhead.
comment|/// @brief Construct a CallInst from a range of arguments
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|CallInst
argument_list|(
argument|Value *Func
argument_list|,
argument|InputIterator ArgBegin
argument_list|,
argument|InputIterator ArgEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
block|;
comment|/// Construct a CallInst given a range of arguments.  InputIterator
comment|/// must be a random-access iterator pointing to contiguous storage
comment|/// (e.g. a std::vector<>::iterator).  Checks are made for
comment|/// random-accessness but not for contiguous storage as that would
comment|/// incur runtime overhead.
comment|/// @brief Construct a CallInst from a range of arguments
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|inline
name|CallInst
argument_list|(
argument|Value *Func
argument_list|,
argument|InputIterator ArgBegin
argument_list|,
argument|InputIterator ArgEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|CallInst
argument_list|(
name|Value
operator|*
name|F
argument_list|,
name|Value
operator|*
name|Actual
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
name|Value
operator|*
name|Actual
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
name|public
operator|:
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|static
name|CallInst
operator|*
name|Create
argument_list|(
argument|Value *Func
argument_list|,
argument|InputIterator ArgBegin
argument_list|,
argument|InputIterator ArgEnd
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|(unsigned)(ArgEnd - ArgBegin +
literal|1
argument|)
argument_list|)
name|CallInst
argument_list|(
name|Func
argument_list|,
name|ArgBegin
argument_list|,
name|ArgEnd
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|static
name|CallInst
operator|*
name|Create
argument_list|(
argument|Value *Func
argument_list|,
argument|InputIterator ArgBegin
argument_list|,
argument|InputIterator ArgEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|(unsigned)(ArgEnd - ArgBegin +
literal|1
argument|)
argument_list|)
name|CallInst
argument_list|(
name|Func
argument_list|,
name|ArgBegin
argument_list|,
name|ArgEnd
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
argument|Value *Actual
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|2
argument_list|)
name|CallInst
argument_list|(
name|F
argument_list|,
name|Actual
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
argument|Value *Actual
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
name|CallInst
argument_list|(
name|F
argument_list|,
name|Actual
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
argument|Instruction *InsertBefore =
literal|0
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
comment|/// CreateMalloc - Generate the IR for a call to malloc:
comment|/// 1. Compute the malloc call's argument as the specified type's size,
comment|///    possibly multiplied by the array size if the array size is not
comment|///    constant 1.
comment|/// 2. Call malloc with that argument.
comment|/// 3. Bitcast the result of the malloc call to the specified type.
specifier|static
name|Value
operator|*
name|CreateMalloc
argument_list|(
name|Instruction
operator|*
name|InsertBefore
argument_list|,
specifier|const
name|Type
operator|*
name|IntPtrTy
argument_list|,
specifier|const
name|Type
operator|*
name|AllocTy
argument_list|,
name|Value
operator|*
name|ArraySize
operator|=
literal|0
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
name|Value
operator|*
name|CreateMalloc
argument_list|(
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|,
specifier|const
name|Type
operator|*
name|IntPtrTy
argument_list|,
specifier|const
name|Type
operator|*
name|AllocTy
argument_list|,
name|Value
operator|*
name|ArraySize
operator|=
literal|0
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|)
block|;
operator|~
name|CallInst
argument_list|()
block|;
name|bool
name|isTailCall
argument_list|()
specifier|const
block|{
return|return
name|SubclassData
operator|&
literal|1
return|;
block|}
name|void
name|setTailCall
argument_list|(
argument|bool isTC = true
argument_list|)
block|{
name|SubclassData
operator|=
operator|(
name|SubclassData
operator|&
operator|~
literal|1
operator|)
operator||
name|unsigned
argument_list|(
name|isTC
argument_list|)
block|;   }
name|virtual
name|CallInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
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
name|SubclassData
operator|>>
literal|1
operator|)
return|;
block|}
name|void
name|setCallingConv
argument_list|(
argument|CallingConv::ID CC
argument_list|)
block|{
name|SubclassData
operator|=
operator|(
name|SubclassData
operator|&
literal|1
operator|)
operator||
operator|(
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|CC
operator|)
operator|<<
literal|1
operator|)
block|;   }
comment|/// getAttributes - Return the parameter attributes for this call.
comment|///
specifier|const
name|AttrListPtr
operator|&
name|getAttributes
argument_list|()
specifier|const
block|{
return|return
name|AttributeList
return|;
block|}
comment|/// setAttributes - Set the parameter attributes for this call.
comment|///
name|void
name|setAttributes
argument_list|(
argument|const AttrListPtr&Attrs
argument_list|)
block|{
name|AttributeList
operator|=
name|Attrs
block|; }
comment|/// addAttribute - adds the attribute to the list of attributes.
name|void
name|addAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attributes attr
argument_list|)
block|;
comment|/// removeAttribute - removes the attribute from the list of attributes.
name|void
name|removeAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attributes attr
argument_list|)
block|;
comment|/// @brief Determine whether the call or the callee has the given attribute.
name|bool
name|paramHasAttr
argument_list|(
argument|unsigned i
argument_list|,
argument|Attributes attr
argument_list|)
specifier|const
block|;
comment|/// @brief Extract the alignment for a call or parameter (0=unknown).
name|unsigned
name|getParamAlignment
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|AttributeList
operator|.
name|getParamAlignment
argument_list|(
name|i
argument_list|)
return|;
block|}
comment|/// @brief Determine if the call does not access memory.
name|bool
name|doesNotAccessMemory
argument_list|()
specifier|const
block|{
return|return
name|paramHasAttr
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|ReadNone
argument_list|)
return|;
block|}
name|void
name|setDoesNotAccessMemory
argument_list|(
argument|bool NotAccessMemory = true
argument_list|)
block|{
if|if
condition|(
name|NotAccessMemory
condition|)
name|addAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|ReadNone
argument_list|)
expr_stmt|;
else|else
name|removeAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|ReadNone
argument_list|)
expr_stmt|;
block|}
comment|/// @brief Determine if the call does not access or only reads memory.
name|bool
name|onlyReadsMemory
argument_list|()
specifier|const
block|{
return|return
name|doesNotAccessMemory
argument_list|()
operator|||
name|paramHasAttr
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|ReadOnly
argument_list|)
return|;
block|}
name|void
name|setOnlyReadsMemory
argument_list|(
argument|bool OnlyReadsMemory = true
argument_list|)
block|{
if|if
condition|(
name|OnlyReadsMemory
condition|)
name|addAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
else|else
name|removeAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|ReadOnly
operator||
name|Attribute
operator|::
name|ReadNone
argument_list|)
expr_stmt|;
block|}
comment|/// @brief Determine if the call cannot return.
name|bool
name|doesNotReturn
argument_list|()
specifier|const
block|{
return|return
name|paramHasAttr
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|NoReturn
argument_list|)
return|;
block|}
name|void
name|setDoesNotReturn
argument_list|(
argument|bool DoesNotReturn = true
argument_list|)
block|{
if|if
condition|(
name|DoesNotReturn
condition|)
name|addAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|NoReturn
argument_list|)
expr_stmt|;
else|else
name|removeAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|NoReturn
argument_list|)
expr_stmt|;
block|}
comment|/// @brief Determine if the call cannot unwind.
name|bool
name|doesNotThrow
argument_list|()
specifier|const
block|{
return|return
name|paramHasAttr
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|NoUnwind
argument_list|)
return|;
block|}
name|void
name|setDoesNotThrow
argument_list|(
argument|bool DoesNotThrow = true
argument_list|)
block|{
if|if
condition|(
name|DoesNotThrow
condition|)
name|addAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|NoUnwind
argument_list|)
expr_stmt|;
else|else
name|removeAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|NoUnwind
argument_list|)
expr_stmt|;
block|}
comment|/// @brief Determine if the call returns a structure through first
comment|/// pointer argument.
name|bool
name|hasStructRetAttr
argument_list|()
specifier|const
block|{
comment|// Be friendly and also check the callee.
return|return
name|paramHasAttr
argument_list|(
literal|1
argument_list|,
name|Attribute
operator|::
name|StructRet
argument_list|)
return|;
block|}
comment|/// @brief Determine if any call argument is an aggregate passed by value.
name|bool
name|hasByValArgument
argument_list|()
specifier|const
block|{
return|return
name|AttributeList
operator|.
name|hasAttrSomewhere
argument_list|(
name|Attribute
operator|::
name|ByVal
argument_list|)
return|;
block|}
comment|/// getCalledFunction - Return the function called, or null if this is an
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
literal|0
operator|>
operator|(
operator|)
operator|)
return|;
block|}
comment|/// getCalledValue - Get a pointer to the function that is invoked by this
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
literal|0
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
literal|0
operator|>
operator|(
operator|)
return|;
block|}
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const CallInst *
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
literal|1
operator|>
block|{ }
block|;
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|CallInst
operator|::
name|CallInst
argument_list|(
argument|Value *Func
argument_list|,
argument|InputIterator ArgBegin
argument_list|,
argument|InputIterator ArgEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
operator|:
name|Instruction
argument_list|(
argument|cast<FunctionType>(cast<PointerType>(Func->getType())                                    ->getElementType())->getReturnType()
argument_list|,
argument|Instruction::Call
argument_list|,
argument|OperandTraits<CallInst>::op_end(this) - (ArgEnd - ArgBegin +
literal|1
argument|)
argument_list|,
argument|(unsigned)(ArgEnd - ArgBegin +
literal|1
argument|)
argument_list|,
argument|InsertAtEnd
argument_list|)
block|{
name|init
argument_list|(
argument|Func
argument_list|,
argument|ArgBegin
argument_list|,
argument|ArgEnd
argument_list|,
argument|NameStr
argument_list|,
argument|typename std::iterator_traits<InputIterator>::iterator_category()
argument_list|)
block|; }
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|CallInst
operator|::
name|CallInst
argument_list|(
argument|Value *Func
argument_list|,
argument|InputIterator ArgBegin
argument_list|,
argument|InputIterator ArgEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
operator|:
name|Instruction
argument_list|(
argument|cast<FunctionType>(cast<PointerType>(Func->getType())                                    ->getElementType())->getReturnType()
argument_list|,
argument|Instruction::Call
argument_list|,
argument|OperandTraits<CallInst>::op_end(this) - (ArgEnd - ArgBegin +
literal|1
argument|)
argument_list|,
argument|(unsigned)(ArgEnd - ArgBegin +
literal|1
argument|)
argument_list|,
argument|InsertBefore
argument_list|)
block|{
name|init
argument_list|(
argument|Func
argument_list|,
argument|ArgBegin
argument_list|,
argument|ArgEnd
argument_list|,
argument|NameStr
argument_list|,
argument|typename std::iterator_traits<InputIterator>::iterator_category()
argument_list|)
block|; }
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|CallInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                               SelectInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// SelectInst - This class represents the LLVM 'select' instruction.
comment|///
name|class
name|SelectInst
operator|:
name|public
name|Instruction
block|{
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
argument|Instruction *InsertBefore =
literal|0
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
name|InsertBefore
argument_list|)
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
comment|/// areInvalidOperands - Return a string if the specified operands are invalid
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
name|virtual
name|SelectInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SelectInst *
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
comment|/// VAArgInst - This class represents the va_arg llvm instruction, which returns
comment|/// an argument of the specified type given a va_list and increments that list
comment|///
name|class
name|VAArgInst
operator|:
name|public
name|UnaryInstruction
block|{
name|public
operator|:
name|VAArgInst
argument_list|(
name|Value
operator|*
name|List
argument_list|,
specifier|const
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
literal|0
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
specifier|const
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
name|virtual
name|VAArgInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const VAArgInst *
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
comment|/// ExtractElementInst - This instruction extracts a single (scalar)
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
literal|0
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
argument|Instruction *InsertBefore =
literal|0
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
comment|/// isValidOperands - Return true if an extractelement instruction can be
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
name|virtual
name|ExtractElementInst
operator|*
name|clone
argument_list|()
specifier|const
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
specifier|const
name|VectorType
operator|*
name|getVectorOperandType
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|VectorType
operator|*
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
argument|const ExtractElementInst *
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
comment|/// InsertElementInst - This instruction inserts a single (scalar)
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
literal|0
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
argument|Instruction *InsertBefore =
literal|0
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
comment|/// isValidOperands - Return true if an insertelement instruction can be
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
name|virtual
name|InsertElementInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// getType - Overload to return most specific vector type.
comment|///
specifier|const
name|VectorType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|VectorType
operator|*
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
argument|const InsertElementInst *
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
comment|/// ShuffleVectorInst - This instruction constructs a fixed permutation of two
comment|/// input vectors.
comment|///
name|class
name|ShuffleVectorInst
operator|:
name|public
name|Instruction
block|{
name|public
operator|:
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
literal|0
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
comment|/// isValidOperands - Return true if a shufflevector instruction can be
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
name|virtual
name|ShuffleVectorInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// getType - Overload to return most specific vector type.
comment|///
specifier|const
name|VectorType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|VectorType
operator|*
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
comment|/// getMaskValue - Return the index from the shuffle mask for the specified
comment|/// output result.  This is either -1 if the element is undef or a number less
comment|/// than 2*numelements.
name|int
name|getMaskValue
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const ShuffleVectorInst *
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
comment|/// ExtractValueInst - This instruction extracts a struct member or array
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
name|void
name|init
argument_list|(
argument|const unsigned *Idx
argument_list|,
argument|unsigned NumIdx
argument_list|,
argument|const Twine&NameStr
argument_list|)
block|;
name|void
name|init
argument_list|(
argument|unsigned Idx
argument_list|,
argument|const Twine&NameStr
argument_list|)
block|;
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|void
name|init
argument_list|(
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
comment|// This argument ensures that we have an iterator we can
comment|// do arithmetic on in constant time
argument|std::random_access_iterator_tag
argument_list|)
block|{
name|unsigned
name|NumIdx
operator|=
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|std
operator|::
name|distance
argument_list|(
name|IdxBegin
argument_list|,
name|IdxEnd
argument_list|)
operator|)
block|;
comment|// There's no fundamental reason why we require at least one index
comment|// (other than weirdness with&*IdxBegin being invalid; see
comment|// getelementptr's init routine for example). But there's no
comment|// present need to support it.
name|assert
argument_list|(
name|NumIdx
operator|>
literal|0
operator|&&
literal|"ExtractValueInst must have at least one index"
argument_list|)
block|;
comment|// This requires that the iterator points to contiguous memory.
name|init
argument_list|(
operator|&
operator|*
name|IdxBegin
argument_list|,
name|NumIdx
argument_list|,
name|NameStr
argument_list|)
block|;
comment|// FIXME: for the general case
comment|// we have to build an array here
block|}
comment|/// getIndexedType - Returns the type of the element that would be extracted
comment|/// with an extractvalue instruction with the specified parameters.
comment|///
comment|/// Null is returned if the indices are invalid for the specified
comment|/// pointer type.
comment|///
specifier|static
specifier|const
name|Type
operator|*
name|getIndexedType
argument_list|(
argument|const Type *Agg
argument_list|,
argument|const unsigned *Idx
argument_list|,
argument|unsigned NumIdx
argument_list|)
block|;
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|static
specifier|const
name|Type
operator|*
name|getIndexedType
argument_list|(
argument|const Type *Ptr
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
comment|// This argument ensures that we
comment|// have an iterator we can do
comment|// arithmetic on in constant time
argument|std::random_access_iterator_tag
argument_list|)
block|{
name|unsigned
name|NumIdx
operator|=
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|std
operator|::
name|distance
argument_list|(
name|IdxBegin
argument_list|,
name|IdxEnd
argument_list|)
operator|)
block|;
if|if
condition|(
name|NumIdx
operator|>
literal|0
condition|)
comment|// This requires that the iterator points to contiguous memory.
return|return
name|getIndexedType
argument_list|(
name|Ptr
argument_list|,
operator|&
operator|*
name|IdxBegin
argument_list|,
name|NumIdx
argument_list|)
return|;
else|else
return|return
name|getIndexedType
argument_list|(
name|Ptr
argument_list|,
operator|(
specifier|const
name|unsigned
operator|*
operator|)
literal|0
argument_list|,
name|NumIdx
argument_list|)
return|;
block|}
comment|/// Constructors - Create a extractvalue instruction with a base aggregate
comment|/// value and a list of indices.  The first ctor can optionally insert before
comment|/// an existing instruction, the second appends the new instruction to the
comment|/// specified BasicBlock.
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|inline
name|ExtractValueInst
argument_list|(
argument|Value *Agg
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
block|;
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|inline
name|ExtractValueInst
argument_list|(
argument|Value *Agg
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
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
name|public
operator|:
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|static
name|ExtractValueInst
operator|*
name|Create
argument_list|(
argument|Value *Agg
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|{
return|return
name|new
name|ExtractValueInst
argument_list|(
name|Agg
argument_list|,
name|IdxBegin
argument_list|,
name|IdxEnd
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|static
name|ExtractValueInst
operator|*
name|Create
argument_list|(
argument|Value *Agg
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
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
name|IdxBegin
argument_list|,
name|IdxEnd
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Constructors - These two creators are convenience methods because one
comment|/// index extractvalue instructions are much more common than those with
comment|/// more than one.
specifier|static
name|ExtractValueInst
operator|*
name|Create
argument_list|(
argument|Value *Agg
argument_list|,
argument|unsigned Idx
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|{
name|unsigned
name|Idxs
index|[
literal|1
index|]
operator|=
block|{
name|Idx
block|}
block|;
return|return
name|new
name|ExtractValueInst
argument_list|(
name|Agg
argument_list|,
name|Idxs
argument_list|,
name|Idxs
operator|+
literal|1
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
argument|unsigned Idx
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
name|unsigned
name|Idxs
index|[
literal|1
index|]
operator|=
block|{
name|Idx
block|}
block|;
return|return
name|new
name|ExtractValueInst
argument_list|(
name|Agg
argument_list|,
name|Idxs
argument_list|,
name|Idxs
operator|+
literal|1
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
name|virtual
name|ExtractValueInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// getIndexedType - Returns the type of the element that would be extracted
comment|/// with an extractvalue instruction with the specified parameters.
comment|///
comment|/// Null is returned if the indices are invalid for the specified
comment|/// pointer type.
comment|///
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|static
specifier|const
name|Type
operator|*
name|getIndexedType
argument_list|(
argument|const Type *Ptr
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|)
block|{
return|return
name|getIndexedType
argument_list|(
argument|Ptr
argument_list|,
argument|IdxBegin
argument_list|,
argument|IdxEnd
argument_list|,
argument|typename std::iterator_traits<InputIterator>::                           iterator_category()
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|Type
operator|*
name|getIndexedType
argument_list|(
argument|const Type *Ptr
argument_list|,
argument|unsigned Idx
argument_list|)
block|;
typedef|typedef
specifier|const
name|unsigned
modifier|*
name|idx_iterator
typedef|;
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
name|unsigned
name|getNumIndices
argument_list|()
specifier|const
block|{
comment|// Note: always non-negative
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
argument|const ExtractValueInst *
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
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|ExtractValueInst
operator|::
name|ExtractValueInst
argument_list|(
argument|Value *Agg
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
operator|:
name|UnaryInstruction
argument_list|(
argument|checkType(getIndexedType(Agg->getType(),                                               IdxBegin, IdxEnd))
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
argument|IdxBegin
argument_list|,
argument|IdxEnd
argument_list|,
argument|NameStr
argument_list|,
argument|typename std::iterator_traits<InputIterator>::iterator_category()
argument_list|)
block|; }
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|ExtractValueInst
operator|::
name|ExtractValueInst
argument_list|(
argument|Value *Agg
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
operator|:
name|UnaryInstruction
argument_list|(
argument|checkType(getIndexedType(Agg->getType(),                                               IdxBegin, IdxEnd))
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
argument|IdxBegin
argument_list|,
argument|IdxEnd
argument_list|,
argument|NameStr
argument_list|,
argument|typename std::iterator_traits<InputIterator>::iterator_category()
argument_list|)
block|; }
comment|//===----------------------------------------------------------------------===//
comment|//                                InsertValueInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// InsertValueInst - This instruction inserts a struct field of array element
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
name|InsertValueInst
argument_list|(
specifier|const
name|InsertValueInst
operator|&
name|IVI
argument_list|)
block|;
name|void
name|init
argument_list|(
argument|Value *Agg
argument_list|,
argument|Value *Val
argument_list|,
argument|const unsigned *Idx
argument_list|,
argument|unsigned NumIdx
argument_list|,
argument|const Twine&NameStr
argument_list|)
block|;
name|void
name|init
argument_list|(
argument|Value *Agg
argument_list|,
argument|Value *Val
argument_list|,
argument|unsigned Idx
argument_list|,
argument|const Twine&NameStr
argument_list|)
block|;
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|void
name|init
argument_list|(
argument|Value *Agg
argument_list|,
argument|Value *Val
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
comment|// This argument ensures that we have an iterator we can
comment|// do arithmetic on in constant time
argument|std::random_access_iterator_tag
argument_list|)
block|{
name|unsigned
name|NumIdx
operator|=
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|std
operator|::
name|distance
argument_list|(
name|IdxBegin
argument_list|,
name|IdxEnd
argument_list|)
operator|)
block|;
comment|// There's no fundamental reason why we require at least one index
comment|// (other than weirdness with&*IdxBegin being invalid; see
comment|// getelementptr's init routine for example). But there's no
comment|// present need to support it.
name|assert
argument_list|(
name|NumIdx
operator|>
literal|0
operator|&&
literal|"InsertValueInst must have at least one index"
argument_list|)
block|;
comment|// This requires that the iterator points to contiguous memory.
name|init
argument_list|(
name|Agg
argument_list|,
name|Val
argument_list|,
operator|&
operator|*
name|IdxBegin
argument_list|,
name|NumIdx
argument_list|,
name|NameStr
argument_list|)
block|;
comment|// FIXME: for the general case
comment|// we have to build an array here
block|}
comment|/// Constructors - Create a insertvalue instruction with a base aggregate
comment|/// value, a value to insert, and a list of indices.  The first ctor can
comment|/// optionally insert before an existing instruction, the second appends
comment|/// the new instruction to the specified BasicBlock.
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|inline
name|InsertValueInst
argument_list|(
argument|Value *Agg
argument_list|,
argument|Value *Val
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
block|;
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|inline
name|InsertValueInst
argument_list|(
argument|Value *Agg
argument_list|,
argument|Value *Val
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
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
argument|Instruction *InsertBefore =
literal|0
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
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|static
name|InsertValueInst
operator|*
name|Create
argument_list|(
argument|Value *Agg
argument_list|,
argument|Value *Val
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
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
name|IdxBegin
argument_list|,
name|IdxEnd
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|static
name|InsertValueInst
operator|*
name|Create
argument_list|(
argument|Value *Agg
argument_list|,
argument|Value *Val
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
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
name|IdxBegin
argument_list|,
name|IdxEnd
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
comment|/// Constructors - These two creators are convenience methods because one
comment|/// index insertvalue instructions are much more common than those with
comment|/// more than one.
specifier|static
name|InsertValueInst
operator|*
name|Create
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
argument|Instruction *InsertBefore =
literal|0
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
name|Idx
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
argument|unsigned Idx
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
name|Idx
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
name|virtual
name|InsertValueInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
typedef|typedef
specifier|const
name|unsigned
modifier|*
name|idx_iterator
typedef|;
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
name|unsigned
name|getNumIndices
argument_list|()
specifier|const
block|{
comment|// Note: always non-negative
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
argument|const InsertValueInst *
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
literal|2
operator|>
block|{ }
block|;
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|InsertValueInst
operator|::
name|InsertValueInst
argument_list|(
argument|Value *Agg
argument_list|,
argument|Value *Val
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
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
argument|Agg
argument_list|,
argument|Val
argument_list|,
argument|IdxBegin
argument_list|,
argument|IdxEnd
argument_list|,
argument|NameStr
argument_list|,
argument|typename std::iterator_traits<InputIterator>::iterator_category()
argument_list|)
block|; }
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|InsertValueInst
operator|::
name|InsertValueInst
argument_list|(
argument|Value *Agg
argument_list|,
argument|Value *Val
argument_list|,
argument|InputIterator IdxBegin
argument_list|,
argument|InputIterator IdxEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
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
argument|Agg
argument_list|,
argument|Val
argument_list|,
argument|IdxBegin
argument_list|,
argument|IdxEnd
argument_list|,
argument|NameStr
argument_list|,
argument|typename std::iterator_traits<InputIterator>::iterator_category()
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
comment|/// ReservedSpace - The number of operands actually allocated.  NumOperands is
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
name|explicit
name|PHINode
argument_list|(
specifier|const
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
literal|0
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
literal|0
argument_list|,
literal|0
argument_list|,
name|InsertBefore
argument_list|)
block|,
name|ReservedSpace
argument_list|(
literal|0
argument_list|)
block|{
name|setName
argument_list|(
name|NameStr
argument_list|)
block|;   }
name|PHINode
argument_list|(
specifier|const
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
name|Instruction
argument_list|(
name|Ty
argument_list|,
name|Instruction
operator|::
name|PHI
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|InsertAtEnd
argument_list|)
block|,
name|ReservedSpace
argument_list|(
literal|0
argument_list|)
block|{
name|setName
argument_list|(
name|NameStr
argument_list|)
block|;   }
name|public
operator|:
specifier|static
name|PHINode
operator|*
name|Create
argument_list|(
argument|const Type *Ty
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|{
return|return
name|new
name|PHINode
argument_list|(
name|Ty
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
argument|const Type *Ty
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
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
operator|~
name|PHINode
argument_list|()
block|;
comment|/// reserveOperandSpace - This method can be used to avoid repeated
comment|/// reallocation of PHI operand lists by reserving space for the correct
comment|/// number of operands before adding them.  Unlike normal vector reserves,
comment|/// this method can also be used to trim the operand space.
name|void
name|reserveOperandSpace
argument_list|(
argument|unsigned NumValues
argument_list|)
block|{
name|resizeOperands
argument_list|(
name|NumValues
operator|*
literal|2
argument_list|)
block|;   }
name|virtual
name|PHINode
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|/// getNumIncomingValues - Return the number of incoming edges
comment|///
name|unsigned
name|getNumIncomingValues
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
comment|/// getIncomingValue - Return incoming value number x
comment|///
name|Value
operator|*
name|getIncomingValue
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|*
literal|2
operator|<
name|getNumOperands
argument_list|()
operator|&&
literal|"Invalid value number!"
argument_list|)
block|;
return|return
name|getOperand
argument_list|(
name|i
operator|*
literal|2
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
name|i
operator|*
literal|2
operator|<
name|getNumOperands
argument_list|()
operator|&&
literal|"Invalid value number!"
argument_list|)
block|;
name|setOperand
argument_list|(
name|i
operator|*
literal|2
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
operator|*
literal|2
return|;
block|}
specifier|static
name|unsigned
name|getIncomingValueNumForOperand
argument_list|(
argument|unsigned i
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|%
literal|2
operator|==
literal|0
operator|&&
literal|"Invalid incoming-value operand index!"
argument_list|)
block|;
return|return
name|i
operator|/
literal|2
return|;
block|}
comment|/// getIncomingBlock - Return incoming basic block #i.
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
name|cast
operator|<
name|BasicBlock
operator|>
operator|(
name|getOperand
argument_list|(
name|i
operator|*
literal|2
operator|+
literal|1
argument_list|)
operator|)
return|;
block|}
comment|/// getIncomingBlock - Return incoming basic block corresponding
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
name|cast
operator|<
name|BasicBlock
operator|>
operator|(
operator|(
operator|&
name|U
operator|+
literal|1
operator|)
operator|->
name|get
argument_list|()
operator|)
return|;
block|}
comment|/// getIncomingBlock - Return incoming basic block corresponding
comment|/// to value use iterator.
comment|///
name|template
operator|<
name|typename
name|U
operator|>
name|BasicBlock
operator|*
name|getIncomingBlock
argument_list|(
argument|value_use_iterator<U> I
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
name|setOperand
argument_list|(
name|i
operator|*
literal|2
operator|+
literal|1
argument_list|,
name|BB
argument_list|)
block|;   }
specifier|static
name|unsigned
name|getOperandNumForIncomingBlock
argument_list|(
argument|unsigned i
argument_list|)
block|{
return|return
name|i
operator|*
literal|2
operator|+
literal|1
return|;
block|}
specifier|static
name|unsigned
name|getIncomingBlockNumForOperand
argument_list|(
argument|unsigned i
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|%
literal|2
operator|==
literal|1
operator|&&
literal|"Invalid incoming-block operand index!"
argument_list|)
block|;
return|return
name|i
operator|/
literal|2
return|;
block|}
comment|/// addIncoming - Add an incoming value to the end of the PHI list
comment|///
name|void
name|addIncoming
argument_list|(
argument|Value *V
argument_list|,
argument|BasicBlock *BB
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
name|BB
operator|&&
literal|"PHI node got a null basic block!"
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
name|unsigned
name|OpNo
operator|=
name|NumOperands
block|;
if|if
condition|(
name|OpNo
operator|+
literal|2
operator|>
name|ReservedSpace
condition|)
name|resizeOperands
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// Get more space!
comment|// Initialize some new operands.
name|NumOperands
operator|=
name|OpNo
operator|+
literal|2
block|;
name|OperandList
index|[
name|OpNo
index|]
operator|=
name|V
block|;
name|OperandList
index|[
name|OpNo
operator|+
literal|1
index|]
operator|=
name|BB
block|;   }
comment|/// removeIncomingValue - Remove an incoming value.  This is useful if a
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
comment|/// getBasicBlockIndex - Return the first index of the specified basic
comment|/// block in the value list for this PHI.  Returns -1 if no instance.
comment|///
name|int
name|getBasicBlockIndex
argument_list|(
argument|const BasicBlock *BB
argument_list|)
specifier|const
block|{
name|Use
operator|*
name|OL
operator|=
name|OperandList
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
name|getNumOperands
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
name|i
operator|+=
literal|2
control|)
if|if
condition|(
name|OL
index|[
name|i
operator|+
literal|1
index|]
operator|.
name|get
argument_list|()
operator|==
name|BB
condition|)
return|return
name|i
operator|/
literal|2
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
return|return
name|getIncomingValue
argument_list|(
name|getBasicBlockIndex
argument_list|(
name|BB
argument_list|)
argument_list|)
return|;
block|}
comment|/// hasConstantValue - If the specified PHI node always merges together the
comment|/// same value, return the value, otherwise return null.
comment|///
comment|/// If the PHI has undef operands, but all the rest of the operands are
comment|/// some unique value, return that value if it can be proved that the
comment|/// value dominates the PHI. If DT is null, use a conservative check,
comment|/// otherwise use DT to test for dominance.
comment|///
name|Value
operator|*
name|hasConstantValue
argument_list|(
argument|DominatorTree *DT =
literal|0
argument_list|)
specifier|const
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const PHINode *
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
name|resizeOperands
argument_list|(
argument|unsigned NumOperands
argument_list|)
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
comment|//                               ReturnInst Class
comment|//===----------------------------------------------------------------------===//
comment|//===---------------------------------------------------------------------------
comment|/// ReturnInst - Return a value (possibly void), from a function.  Execution
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
literal|0
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
literal|0
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
name|public
operator|:
specifier|static
name|ReturnInst
operator|*
name|Create
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|Value *retVal =
literal|0
argument_list|,
argument|Instruction *InsertBefore =
literal|0
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
name|virtual
operator|~
name|ReturnInst
argument_list|()
block|;
name|virtual
name|ReturnInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
comment|/// Convenience accessor
name|Value
operator|*
name|getReturnValue
argument_list|(
argument|unsigned n =
literal|0
argument_list|)
specifier|const
block|{
return|return
name|n
operator|<
name|getNumOperands
argument_list|()
operator|?
name|getOperand
argument_list|(
name|n
argument_list|)
operator|:
literal|0
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
argument|const ReturnInst *
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
name|virtual
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|virtual
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
name|OptionalOperandTraits
operator|<
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
comment|/// BranchInst - Conditional or Unconditional Branch instruction.
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
name|void
name|AssertOK
argument_list|()
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
literal|0
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
literal|0
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
name|public
operator|:
specifier|static
name|BranchInst
operator|*
name|Create
argument_list|(
argument|BasicBlock *IfTrue
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|{
return|return
name|new
argument_list|(
literal|1
argument_list|,
argument|true
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
argument|Instruction *InsertBefore =
literal|0
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
argument_list|,
argument|true
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
operator|~
name|BranchInst
argument_list|()
block|;
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
name|virtual
name|BranchInst
operator|*
name|clone
argument_list|()
specifier|const
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
comment|// setUnconditionalDest - Change the current branch to an unconditional branch
comment|// targeting the specified block.
comment|// FIXME: Eliminate this ugly method.
name|void
name|setUnconditionalDest
argument_list|(
argument|BasicBlock *Dest
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
name|Dest
block|;
if|if
condition|(
name|isConditional
argument_list|()
condition|)
block|{
comment|// Convert this to an uncond branch.
name|Op
operator|<
operator|-
literal|2
operator|>
operator|(
operator|)
operator|=
literal|0
expr_stmt|;
name|Op
operator|<
operator|-
literal|3
operator|>
operator|(
operator|)
operator|=
literal|0
expr_stmt|;
name|NumOperands
operator|=
literal|1
expr_stmt|;
name|OperandList
operator|=
name|op_begin
argument_list|()
expr_stmt|;
block|}
block|}
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
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const BranchInst *
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
name|virtual
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|virtual
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
literal|1
operator|>
block|{}
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
comment|/// SwitchInst - Multiway switch
comment|///
name|class
name|SwitchInst
operator|:
name|public
name|TerminatorInst
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
name|RI
argument_list|)
block|;
name|void
name|init
argument_list|(
argument|Value *Value
argument_list|,
argument|BasicBlock *Default
argument_list|,
argument|unsigned NumCases
argument_list|)
block|;
name|void
name|resizeOperands
argument_list|(
argument|unsigned No
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
comment|/// SwitchInst ctor - Create a new switch instruction, specifying a value to
comment|/// switch on and a default destination.  The number of additional cases can
comment|/// be specified here to make memory allocation more efficient.  This
comment|/// constructor can also autoinsert before another instruction.
name|SwitchInst
argument_list|(
argument|Value *Value
argument_list|,
argument|BasicBlock *Default
argument_list|,
argument|unsigned NumCases
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|;
comment|/// SwitchInst ctor - Create a new switch instruction, specifying a value to
comment|/// switch on and a default destination.  The number of additional cases can
comment|/// be specified here to make memory allocation more efficient.  This
comment|/// constructor also autoinserts at the end of the specified BasicBlock.
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
name|public
operator|:
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
argument|Instruction *InsertBefore =
literal|0
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
operator|~
name|SwitchInst
argument_list|()
block|;
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
comment|/// getNumCases - return the number of 'cases' in this switch instruction.
comment|/// Note that case #0 is always the default case.
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
return|;
block|}
comment|/// getCaseValue - Return the specified case value.  Note that case #0, the
comment|/// default destination, does not have a case value.
name|ConstantInt
operator|*
name|getCaseValue
argument_list|(
argument|unsigned i
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|&&
name|i
operator|<
name|getNumCases
argument_list|()
operator|&&
literal|"Illegal case value to get!"
argument_list|)
block|;
return|return
name|getSuccessorValue
argument_list|(
name|i
argument_list|)
return|;
block|}
comment|/// getCaseValue - Return the specified case value.  Note that case #0, the
comment|/// default destination, does not have a case value.
specifier|const
name|ConstantInt
operator|*
name|getCaseValue
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|&&
name|i
operator|<
name|getNumCases
argument_list|()
operator|&&
literal|"Illegal case value to get!"
argument_list|)
block|;
return|return
name|getSuccessorValue
argument_list|(
name|i
argument_list|)
return|;
block|}
comment|/// findCaseValue - Search all of the case values for the specified constant.
comment|/// If it is explicitly handled, return the case number of it, otherwise
comment|/// return 0 to indicate that it is handled by the default handler.
name|unsigned
name|findCaseValue
argument_list|(
argument|const ConstantInt *C
argument_list|)
specifier|const
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|1
init|,
name|e
init|=
name|getNumCases
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
name|getCaseValue
argument_list|(
name|i
argument_list|)
operator|==
name|C
condition|)
return|return
name|i
return|;
return|return
literal|0
return|;
block|}
comment|/// findCaseDest - Finds the unique case value for a given successor. Returns
comment|/// null if the successor is not found, not unique, or is the default case.
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
name|NULL
return|;
name|ConstantInt
operator|*
name|CI
operator|=
name|NULL
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|1
init|,
name|e
init|=
name|getNumCases
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
if|if
condition|(
name|getSuccessor
argument_list|(
name|i
argument_list|)
operator|==
name|BB
condition|)
block|{
if|if
condition|(
name|CI
condition|)
return|return
name|NULL
return|;
comment|// Multiple cases lead to BB.
else|else
name|CI
operator|=
name|getCaseValue
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|CI
return|;
block|}
comment|/// addCase - Add an entry to the switch instruction...
comment|///
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
comment|/// removeCase - This method removes the specified successor from the switch
comment|/// instruction.  Note that this cannot be used to remove the default
comment|/// destination (successor #0).
comment|///
name|void
name|removeCase
argument_list|(
argument|unsigned idx
argument_list|)
block|;
name|virtual
name|SwitchInst
operator|*
name|clone
argument_list|()
specifier|const
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
comment|// getSuccessorValue - Return the value associated with the specified
comment|// successor.
name|ConstantInt
operator|*
name|getSuccessorValue
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
literal|"Successor # out of range!"
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
name|ConstantInt
operator|*
operator|>
operator|(
name|getOperand
argument_list|(
name|idx
operator|*
literal|2
argument_list|)
operator|)
return|;
block|}
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SwitchInst *
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
name|virtual
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|virtual
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
comment|//                               InvokeInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// InvokeInst - Invoke instruction.  The SubclassData field is used to hold the
comment|/// calling convention of the call.
comment|///
name|class
name|InvokeInst
operator|:
name|public
name|TerminatorInst
block|{
name|AttrListPtr
name|AttributeList
block|;
name|InvokeInst
argument_list|(
specifier|const
name|InvokeInst
operator|&
name|BI
argument_list|)
block|;
name|void
name|init
argument_list|(
argument|Value *Fn
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|Value* const *Args
argument_list|,
argument|unsigned NumArgs
argument_list|)
block|;
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|void
name|init
argument_list|(
argument|Value *Func
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|InputIterator ArgBegin
argument_list|,
argument|InputIterator ArgEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
comment|// This argument ensures that we have an iterator we can
comment|// do arithmetic on in constant time
argument|std::random_access_iterator_tag
argument_list|)
block|{
name|unsigned
name|NumArgs
operator|=
operator|(
name|unsigned
operator|)
name|std
operator|::
name|distance
argument_list|(
name|ArgBegin
argument_list|,
name|ArgEnd
argument_list|)
block|;
comment|// This requires that the iterator points to contiguous memory.
name|init
argument_list|(
name|Func
argument_list|,
name|IfNormal
argument_list|,
name|IfException
argument_list|,
name|NumArgs
condition|?
operator|&
operator|*
name|ArgBegin
else|:
literal|0
argument_list|,
name|NumArgs
argument_list|)
block|;
name|setName
argument_list|(
name|NameStr
argument_list|)
block|;   }
comment|/// Construct an InvokeInst given a range of arguments.
comment|/// InputIterator must be a random-access iterator pointing to
comment|/// contiguous storage (e.g. a std::vector<>::iterator).  Checks are
comment|/// made for random-accessness but not for contiguous storage as
comment|/// that would incur runtime overhead.
comment|///
comment|/// @brief Construct an InvokeInst from a range of arguments
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|inline
name|InvokeInst
argument_list|(
argument|Value *Func
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|InputIterator ArgBegin
argument_list|,
argument|InputIterator ArgEnd
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
block|;
comment|/// Construct an InvokeInst given a range of arguments.
comment|/// InputIterator must be a random-access iterator pointing to
comment|/// contiguous storage (e.g. a std::vector<>::iterator).  Checks are
comment|/// made for random-accessness but not for contiguous storage as
comment|/// that would incur runtime overhead.
comment|///
comment|/// @brief Construct an InvokeInst from a range of arguments
name|template
operator|<
name|typename
name|InputIterator
operator|>
specifier|inline
name|InvokeInst
argument_list|(
argument|Value *Func
argument_list|,
argument|BasicBlock *IfNormal
argument_list|,
argument|BasicBlock *IfException
argument_list|,
argument|InputIterator ArgBegin
argument_list|,
argument|InputIterator ArgEnd
argument_list|,
argument|unsigned Values
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
name|public
operator|:
name|template
operator|<
name|typename
name|InputIterator
operator|>
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
argument|InputIterator ArgBegin
argument_list|,
argument|InputIterator ArgEnd
argument_list|,
argument|const Twine&NameStr =
literal|""
argument_list|,
argument|Instruction *InsertBefore =
literal|0
argument_list|)
block|{
name|unsigned
name|Values
argument_list|(
name|ArgEnd
operator|-
name|ArgBegin
operator|+
literal|3
argument_list|)
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
name|ArgBegin
argument_list|,
name|ArgEnd
argument_list|,
name|Values
argument_list|,
name|NameStr
argument_list|,
name|InsertBefore
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|InputIterator
operator|>
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
argument|InputIterator ArgBegin
argument_list|,
argument|InputIterator ArgEnd
argument_list|,
argument|const Twine&NameStr
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|{
name|unsigned
name|Values
argument_list|(
name|ArgEnd
operator|-
name|ArgBegin
operator|+
literal|3
argument_list|)
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
name|ArgBegin
argument_list|,
name|ArgEnd
argument_list|,
name|Values
argument_list|,
name|NameStr
argument_list|,
name|InsertAtEnd
argument_list|)
return|;
block|}
name|virtual
name|InvokeInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
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
name|SubclassData
operator|)
return|;
block|}
name|void
name|setCallingConv
argument_list|(
argument|CallingConv::ID CC
argument_list|)
block|{
name|SubclassData
operator|=
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|CC
operator|)
block|;   }
comment|/// getAttributes - Return the parameter attributes for this invoke.
comment|///
specifier|const
name|AttrListPtr
operator|&
name|getAttributes
argument_list|()
specifier|const
block|{
return|return
name|AttributeList
return|;
block|}
comment|/// setAttributes - Set the parameter attributes for this invoke.
comment|///
name|void
name|setAttributes
argument_list|(
argument|const AttrListPtr&Attrs
argument_list|)
block|{
name|AttributeList
operator|=
name|Attrs
block|; }
comment|/// addAttribute - adds the attribute to the list of attributes.
name|void
name|addAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attributes attr
argument_list|)
block|;
comment|/// removeAttribute - removes the attribute from the list of attributes.
name|void
name|removeAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attributes attr
argument_list|)
block|;
comment|/// @brief Determine whether the call or the callee has the given attribute.
name|bool
name|paramHasAttr
argument_list|(
argument|unsigned i
argument_list|,
argument|Attributes attr
argument_list|)
specifier|const
block|;
comment|/// @brief Extract the alignment for a call or parameter (0=unknown).
name|unsigned
name|getParamAlignment
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|AttributeList
operator|.
name|getParamAlignment
argument_list|(
name|i
argument_list|)
return|;
block|}
comment|/// @brief Determine if the call does not access memory.
name|bool
name|doesNotAccessMemory
argument_list|()
specifier|const
block|{
return|return
name|paramHasAttr
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|ReadNone
argument_list|)
return|;
block|}
name|void
name|setDoesNotAccessMemory
argument_list|(
argument|bool NotAccessMemory = true
argument_list|)
block|{
if|if
condition|(
name|NotAccessMemory
condition|)
name|addAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|ReadNone
argument_list|)
expr_stmt|;
else|else
name|removeAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|ReadNone
argument_list|)
expr_stmt|;
block|}
comment|/// @brief Determine if the call does not access or only reads memory.
name|bool
name|onlyReadsMemory
argument_list|()
specifier|const
block|{
return|return
name|doesNotAccessMemory
argument_list|()
operator|||
name|paramHasAttr
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|ReadOnly
argument_list|)
return|;
block|}
name|void
name|setOnlyReadsMemory
argument_list|(
argument|bool OnlyReadsMemory = true
argument_list|)
block|{
if|if
condition|(
name|OnlyReadsMemory
condition|)
name|addAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
else|else
name|removeAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|ReadOnly
operator||
name|Attribute
operator|::
name|ReadNone
argument_list|)
expr_stmt|;
block|}
comment|/// @brief Determine if the call cannot return.
name|bool
name|doesNotReturn
argument_list|()
specifier|const
block|{
return|return
name|paramHasAttr
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|NoReturn
argument_list|)
return|;
block|}
name|void
name|setDoesNotReturn
argument_list|(
argument|bool DoesNotReturn = true
argument_list|)
block|{
if|if
condition|(
name|DoesNotReturn
condition|)
name|addAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|NoReturn
argument_list|)
expr_stmt|;
else|else
name|removeAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|NoReturn
argument_list|)
expr_stmt|;
block|}
comment|/// @brief Determine if the call cannot unwind.
name|bool
name|doesNotThrow
argument_list|()
specifier|const
block|{
return|return
name|paramHasAttr
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|NoUnwind
argument_list|)
return|;
block|}
name|void
name|setDoesNotThrow
argument_list|(
argument|bool DoesNotThrow = true
argument_list|)
block|{
if|if
condition|(
name|DoesNotThrow
condition|)
name|addAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|NoUnwind
argument_list|)
expr_stmt|;
else|else
name|removeAttribute
argument_list|(
operator|~
literal|0
argument_list|,
name|Attribute
operator|::
name|NoUnwind
argument_list|)
expr_stmt|;
block|}
comment|/// @brief Determine if the call returns a structure through first
comment|/// pointer argument.
name|bool
name|hasStructRetAttr
argument_list|()
specifier|const
block|{
comment|// Be friendly and also check the callee.
return|return
name|paramHasAttr
argument_list|(
literal|1
argument_list|,
name|Attribute
operator|::
name|StructRet
argument_list|)
return|;
block|}
comment|/// @brief Determine if any call argument is an aggregate passed by value.
name|bool
name|hasByValArgument
argument_list|()
specifier|const
block|{
return|return
name|AttributeList
operator|.
name|hasAttrSomewhere
argument_list|(
name|Attribute
operator|::
name|ByVal
argument_list|)
return|;
block|}
comment|/// getCalledFunction - Return the function called, or null if this is an
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
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|)
return|;
block|}
comment|/// getCalledValue - Get a pointer to the function that is invoked by this
comment|/// instruction
specifier|const
name|Value
operator|*
name|getCalledValue
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
name|getCalledValue
argument_list|()
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
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
name|getOperand
argument_list|(
literal|1
argument_list|)
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
name|getOperand
argument_list|(
literal|2
argument_list|)
operator|)
return|;
block|}
name|void
name|setNormalDest
argument_list|(
argument|BasicBlock *B
argument_list|)
block|{
name|setOperand
argument_list|(
literal|1
argument_list|,
name|B
argument_list|)
block|;   }
name|void
name|setUnwindDest
argument_list|(
argument|BasicBlock *B
argument_list|)
block|{
name|setOperand
argument_list|(
literal|2
argument_list|,
name|B
argument_list|)
block|;   }
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
name|setOperand
argument_list|(
name|idx
operator|+
literal|1
argument_list|,
name|NewSucc
argument_list|)
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
argument|const InvokeInst *
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
name|virtual
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|virtual
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
name|InvokeInst
operator|>
operator|:
name|public
name|VariadicOperandTraits
operator|<
literal|3
operator|>
block|{ }
block|;
name|template
operator|<
name|typename
name|InputIterator
operator|>
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
argument|InputIterator ArgBegin
argument_list|,
argument|InputIterator ArgEnd
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
argument|cast<FunctionType>(cast<PointerType>(Func->getType())                                       ->getElementType())->getReturnType()
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
argument|Func
argument_list|,
argument|IfNormal
argument_list|,
argument|IfException
argument_list|,
argument|ArgBegin
argument_list|,
argument|ArgEnd
argument_list|,
argument|NameStr
argument_list|,
argument|typename std::iterator_traits<InputIterator>::iterator_category()
argument_list|)
block|; }
name|template
operator|<
name|typename
name|InputIterator
operator|>
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
argument|InputIterator ArgBegin
argument_list|,
argument|InputIterator ArgEnd
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
argument|cast<FunctionType>(cast<PointerType>(Func->getType())                                       ->getElementType())->getReturnType()
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
argument|Func
argument_list|,
argument|IfNormal
argument_list|,
argument|IfException
argument_list|,
argument|ArgBegin
argument_list|,
argument|ArgEnd
argument_list|,
argument|NameStr
argument_list|,
argument|typename std::iterator_traits<InputIterator>::iterator_category()
argument_list|)
block|; }
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|InvokeInst
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|//                              UnwindInst Class
comment|//===----------------------------------------------------------------------===//
comment|//===---------------------------------------------------------------------------
comment|/// UnwindInst - Immediately exit the current function, unwinding the stack
comment|/// until an invoke instruction is found.
comment|///
name|class
name|UnwindInst
operator|:
name|public
name|TerminatorInst
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
name|public
operator|:
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
name|explicit
name|UnwindInst
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|Instruction
operator|*
name|InsertBefore
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|UnwindInst
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
name|virtual
name|UnwindInst
operator|*
name|clone
argument_list|()
specifier|const
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
argument|const UnwindInst *
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
name|Unwind
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
name|virtual
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setSuccessorV
argument_list|(
argument|unsigned idx
argument_list|,
argument|BasicBlock *B
argument_list|)
block|; }
block|;
comment|//===----------------------------------------------------------------------===//
comment|//                           UnreachableInst Class
comment|//===----------------------------------------------------------------------===//
comment|//===---------------------------------------------------------------------------
comment|/// UnreachableInst - This function has undefined behavior.  In particular, the
comment|/// presence of this instruction indicates some higher level knowledge that the
comment|/// end of the block cannot be reached.
comment|///
name|class
name|UnreachableInst
operator|:
name|public
name|TerminatorInst
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
name|public
operator|:
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
literal|0
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
name|virtual
name|UnreachableInst
operator|*
name|clone
argument_list|()
specifier|const
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
argument|const UnreachableInst *
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
name|virtual
name|BasicBlock
operator|*
name|getSuccessorV
argument_list|(
argument|unsigned idx
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getNumSuccessorsV
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setSuccessorV
argument_list|(
argument|unsigned idx
argument_list|,
argument|BasicBlock *B
argument_list|)
block|; }
block|;
comment|//===----------------------------------------------------------------------===//
comment|//                                 TruncInst Class
comment|//===----------------------------------------------------------------------===//
comment|/// @brief This class represents a truncation of integer types.
name|class
name|TruncInst
operator|:
name|public
name|CastInst
block|{
name|public
operator|:
comment|/// @brief Constructor with insert-before-instruction semantics
name|TruncInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be truncated
specifier|const
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
literal|0
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// @brief Constructor with insert-at-end-of-block semantics
name|TruncInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be truncated
specifier|const
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
comment|/// @brief Clone an identical TruncInst
name|virtual
name|TruncInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// @brief Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const TruncInst *
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
comment|/// @brief This class represents zero extension of integer types.
name|class
name|ZExtInst
operator|:
name|public
name|CastInst
block|{
name|public
operator|:
comment|/// @brief Constructor with insert-before-instruction semantics
name|ZExtInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be zero extended
specifier|const
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
literal|0
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// @brief Constructor with insert-at-end semantics.
name|ZExtInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be zero extended
specifier|const
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
comment|/// @brief Clone an identical ZExtInst
name|virtual
name|ZExtInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// @brief Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const ZExtInst *
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
comment|/// @brief This class represents a sign extension of integer types.
name|class
name|SExtInst
operator|:
name|public
name|CastInst
block|{
name|public
operator|:
comment|/// @brief Constructor with insert-before-instruction semantics
name|SExtInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be sign extended
specifier|const
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
literal|0
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// @brief Constructor with insert-at-end-of-block semantics
name|SExtInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be sign extended
specifier|const
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
comment|/// @brief Clone an identical SExtInst
name|virtual
name|SExtInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// @brief Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SExtInst *
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
comment|/// @brief This class represents a truncation of floating point types.
name|class
name|FPTruncInst
operator|:
name|public
name|CastInst
block|{
name|public
operator|:
comment|/// @brief Constructor with insert-before-instruction semantics
name|FPTruncInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be truncated
specifier|const
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
literal|0
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// @brief Constructor with insert-before-instruction semantics
name|FPTruncInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be truncated
specifier|const
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
comment|/// @brief Clone an identical FPTruncInst
name|virtual
name|FPTruncInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// @brief Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const FPTruncInst *
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
comment|/// @brief This class represents an extension of floating point types.
name|class
name|FPExtInst
operator|:
name|public
name|CastInst
block|{
name|public
operator|:
comment|/// @brief Constructor with insert-before-instruction semantics
name|FPExtInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be extended
specifier|const
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
literal|0
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// @brief Constructor with insert-at-end-of-block semantics
name|FPExtInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be extended
specifier|const
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
comment|/// @brief Clone an identical FPExtInst
name|virtual
name|FPExtInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// @brief Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const FPExtInst *
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
comment|/// @brief This class represents a cast unsigned integer to floating point.
name|class
name|UIToFPInst
operator|:
name|public
name|CastInst
block|{
name|public
operator|:
comment|/// @brief Constructor with insert-before-instruction semantics
name|UIToFPInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
specifier|const
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
literal|0
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// @brief Constructor with insert-at-end-of-block semantics
name|UIToFPInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
specifier|const
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
comment|/// @brief Clone an identical UIToFPInst
name|virtual
name|UIToFPInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// @brief Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const UIToFPInst *
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
comment|/// @brief This class represents a cast from signed integer to floating point.
name|class
name|SIToFPInst
operator|:
name|public
name|CastInst
block|{
name|public
operator|:
comment|/// @brief Constructor with insert-before-instruction semantics
name|SIToFPInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
specifier|const
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
literal|0
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// @brief Constructor with insert-at-end-of-block semantics
name|SIToFPInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
specifier|const
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
comment|/// @brief Clone an identical SIToFPInst
name|virtual
name|SIToFPInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// @brief Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SIToFPInst *
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
comment|/// @brief This class represents a cast from floating point to unsigned integer
name|class
name|FPToUIInst
operator|:
name|public
name|CastInst
block|{
name|public
operator|:
comment|/// @brief Constructor with insert-before-instruction semantics
name|FPToUIInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
specifier|const
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
literal|0
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// @brief Constructor with insert-at-end-of-block semantics
name|FPToUIInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
specifier|const
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
comment|/// @brief Clone an identical FPToUIInst
name|virtual
name|FPToUIInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// @brief Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const FPToUIInst *
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
comment|/// @brief This class represents a cast from floating point to signed integer.
name|class
name|FPToSIInst
operator|:
name|public
name|CastInst
block|{
name|public
operator|:
comment|/// @brief Constructor with insert-before-instruction semantics
name|FPToSIInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
specifier|const
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
literal|0
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// @brief Constructor with insert-at-end-of-block semantics
name|FPToSIInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
specifier|const
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
comment|/// @brief Clone an identical FPToSIInst
name|virtual
name|FPToSIInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|/// @brief Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const FPToSIInst *
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
comment|/// @brief This class represents a cast from an integer to a pointer.
name|class
name|IntToPtrInst
operator|:
name|public
name|CastInst
block|{
name|public
operator|:
comment|/// @brief Constructor with insert-before-instruction semantics
name|IntToPtrInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
specifier|const
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
literal|0
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// @brief Constructor with insert-at-end-of-block semantics
name|IntToPtrInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
specifier|const
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
comment|/// @brief Clone an identical IntToPtrInst
name|virtual
name|IntToPtrInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const IntToPtrInst *
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
comment|/// @brief This class represents a cast from a pointer to an integer
name|class
name|PtrToIntInst
operator|:
name|public
name|CastInst
block|{
name|public
operator|:
comment|/// @brief Constructor with insert-before-instruction semantics
name|PtrToIntInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
specifier|const
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
literal|0
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// @brief Constructor with insert-at-end-of-block semantics
name|PtrToIntInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be converted
specifier|const
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
comment|/// @brief Clone an identical PtrToIntInst
name|virtual
name|PtrToIntInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const PtrToIntInst *
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
comment|/// @brief This class represents a no-op cast from one type to another.
name|class
name|BitCastInst
operator|:
name|public
name|CastInst
block|{
name|public
operator|:
comment|/// @brief Constructor with insert-before-instruction semantics
name|BitCastInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be casted
specifier|const
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
literal|0
comment|///< Where to insert the new instruction
argument_list|)
block|;
comment|/// @brief Constructor with insert-at-end-of-block semantics
name|BitCastInst
argument_list|(
name|Value
operator|*
name|S
argument_list|,
comment|///< The value to be casted
specifier|const
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
comment|/// @brief Clone an identical BitCastInst
name|virtual
name|BitCastInst
operator|*
name|clone
argument_list|()
specifier|const
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const BitCastInst *
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
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

