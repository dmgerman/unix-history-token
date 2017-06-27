begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- llvm/CodeGen/MachineMemOperand.h - MachineMemOperand class -*- C++ -*-==//
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
comment|// This file contains the declaration of the MachineMemOperand class, which is a
end_comment

begin_comment
comment|// description of a memory reference. It is used to help track dependencies
end_comment

begin_comment
comment|// in the backend.
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
name|LLVM_CODEGEN_MACHINEMEMOPERAND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEMEMOPERAND_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitmaskEnum.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/PseudoSourceValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Metadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_comment
comment|// PointerLikeTypeTraits<Value*>
end_comment

begin_include
include|#
directive|include
file|"llvm/Support/AtomicOrdering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FoldingSetNodeID
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|ModuleSlotTracker
decl_stmt|;
comment|/// This class contains a discriminated union of information about pointers in
comment|/// memory operands, relating them back to LLVM IR or to virtual locations (such
comment|/// as frame indices) that are exposed during codegen.
struct|struct
name|MachinePointerInfo
block|{
comment|/// This is the IR pointer value for the access, or it is null if unknown.
comment|/// If this is null, then the access is to a pointer in the default address
comment|/// space.
name|PointerUnion
operator|<
specifier|const
name|Value
operator|*
operator|,
specifier|const
name|PseudoSourceValue
operator|*
operator|>
name|V
expr_stmt|;
comment|/// Offset - This is an offset from the base Value*.
name|int64_t
name|Offset
decl_stmt|;
name|explicit
name|MachinePointerInfo
argument_list|(
argument|const Value *v = nullptr
argument_list|,
argument|int64_t offset =
literal|0
argument_list|)
block|:
name|V
argument_list|(
name|v
argument_list|)
operator|,
name|Offset
argument_list|(
argument|offset
argument_list|)
block|{}
name|explicit
name|MachinePointerInfo
argument_list|(
argument|const PseudoSourceValue *v
argument_list|,
argument|int64_t offset =
literal|0
argument_list|)
operator|:
name|V
argument_list|(
name|v
argument_list|)
operator|,
name|Offset
argument_list|(
argument|offset
argument_list|)
block|{}
name|MachinePointerInfo
name|getWithOffset
argument_list|(
argument|int64_t O
argument_list|)
specifier|const
block|{
if|if
condition|(
name|V
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|MachinePointerInfo
argument_list|()
return|;
if|if
condition|(
name|V
operator|.
name|is
operator|<
specifier|const
name|Value
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|MachinePointerInfo
argument_list|(
name|V
operator|.
name|get
operator|<
specifier|const
name|Value
operator|*
operator|>
operator|(
operator|)
argument_list|,
name|Offset
operator|+
name|O
argument_list|)
return|;
return|return
name|MachinePointerInfo
argument_list|(
name|V
operator|.
name|get
operator|<
specifier|const
name|PseudoSourceValue
operator|*
operator|>
operator|(
operator|)
argument_list|,
name|Offset
operator|+
name|O
argument_list|)
return|;
block|}
comment|/// Return true if memory region [V, V+Offset+Size) is known to be
comment|/// dereferenceable.
name|bool
name|isDereferenceable
argument_list|(
name|unsigned
name|Size
argument_list|,
name|LLVMContext
operator|&
name|C
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
decl|const
struct|;
comment|/// Return the LLVM IR address space number that this pointer points into.
name|unsigned
name|getAddrSpace
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return a MachinePointerInfo record that refers to the constant pool.
specifier|static
name|MachinePointerInfo
name|getConstantPool
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function_decl|;
comment|/// Return a MachinePointerInfo record that refers to the specified
comment|/// FrameIndex.
specifier|static
name|MachinePointerInfo
name|getFixedStack
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|,
name|int
name|FI
parameter_list|,
name|int64_t
name|Offset
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Return a MachinePointerInfo record that refers to a jump table entry.
specifier|static
name|MachinePointerInfo
name|getJumpTable
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function_decl|;
comment|/// Return a MachinePointerInfo record that refers to a GOT entry.
specifier|static
name|MachinePointerInfo
name|getGOT
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function_decl|;
comment|/// Stack pointer relative access.
specifier|static
name|MachinePointerInfo
name|getStack
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|,
name|int64_t
name|Offset
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// A description of a memory reference used in the backend.
end_comment

begin_comment
comment|/// Instead of holding a StoreInst or LoadInst, this class holds the address
end_comment

begin_comment
comment|/// Value of the reference along with a byte size and offset. This allows it
end_comment

begin_comment
comment|/// to describe lowered loads and stores. Also, the special PseudoSourceValue
end_comment

begin_comment
comment|/// objects can be used to represent loads and stores to memory locations
end_comment

begin_comment
comment|/// that aren't explicit in the regular LLVM IR.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|MachineMemOperand
block|{
name|public
label|:
comment|/// Flags values. These may be or'd together.
enum|enum
name|Flags
enum|:
name|uint16_t
block|{
comment|// No flags set.
name|MONone
init|=
literal|0
block|,
comment|/// The memory access reads data.
name|MOLoad
init|=
literal|1u
operator|<<
literal|0
block|,
comment|/// The memory access writes data.
name|MOStore
init|=
literal|1u
operator|<<
literal|1
block|,
comment|/// The memory access is volatile.
name|MOVolatile
init|=
literal|1u
operator|<<
literal|2
block|,
comment|/// The memory access is non-temporal.
name|MONonTemporal
init|=
literal|1u
operator|<<
literal|3
block|,
comment|/// The memory access is dereferenceable (i.e., doesn't trap).
name|MODereferenceable
init|=
literal|1u
operator|<<
literal|4
block|,
comment|/// The memory access always returns the same value (or traps).
name|MOInvariant
init|=
literal|1u
operator|<<
literal|5
block|,
comment|// Reserved for use by target-specific passes.
name|MOTargetFlag1
init|=
literal|1u
operator|<<
literal|6
block|,
name|MOTargetFlag2
init|=
literal|1u
operator|<<
literal|7
block|,
name|MOTargetFlag3
init|=
literal|1u
operator|<<
literal|8
block|,
name|LLVM_MARK_AS_BITMASK_ENUM
argument_list|(
comment|/* LargestFlag = */
argument|MOTargetFlag3
argument_list|)
block|}
enum|;
name|private
label|:
comment|/// Atomic information for this memory operation.
struct|struct
name|MachineAtomicInfo
block|{
comment|/// Synchronization scope for this memory operation.
name|unsigned
name|SynchScope
range|:
literal|1
decl_stmt|;
comment|// enum SynchronizationScope
comment|/// Atomic ordering requirements for this memory operation. For cmpxchg
comment|/// atomic operations, atomic ordering requirements when store occurs.
name|unsigned
name|Ordering
range|:
literal|4
decl_stmt|;
comment|// enum AtomicOrdering
comment|/// For cmpxchg atomic operations, atomic ordering requirements when store
comment|/// does not occur.
name|unsigned
name|FailureOrdering
range|:
literal|4
decl_stmt|;
comment|// enum AtomicOrdering
block|}
struct|;
name|MachinePointerInfo
name|PtrInfo
decl_stmt|;
name|uint64_t
name|Size
decl_stmt|;
name|Flags
name|FlagVals
decl_stmt|;
name|uint16_t
name|BaseAlignLog2
decl_stmt|;
comment|// log_2(base_alignment) + 1
name|MachineAtomicInfo
name|AtomicInfo
decl_stmt|;
name|AAMDNodes
name|AAInfo
decl_stmt|;
specifier|const
name|MDNode
modifier|*
name|Ranges
decl_stmt|;
name|public
label|:
comment|/// Construct a MachineMemOperand object with the specified PtrInfo, flags,
comment|/// size, and base alignment. For atomic operations the synchronization scope
comment|/// and atomic ordering requirements must also be specified. For cmpxchg
comment|/// atomic operations the atomic ordering requirements when store does not
comment|/// occur must also be specified.
name|MachineMemOperand
argument_list|(
argument|MachinePointerInfo PtrInfo
argument_list|,
argument|Flags flags
argument_list|,
argument|uint64_t s
argument_list|,
argument|unsigned base_alignment
argument_list|,
argument|const AAMDNodes&AAInfo = AAMDNodes()
argument_list|,
argument|const MDNode *Ranges = nullptr
argument_list|,
argument|SynchronizationScope SynchScope = CrossThread
argument_list|,
argument|AtomicOrdering Ordering = AtomicOrdering::NotAtomic
argument_list|,
argument|AtomicOrdering FailureOrdering = AtomicOrdering::NotAtomic
argument_list|)
empty_stmt|;
specifier|const
name|MachinePointerInfo
operator|&
name|getPointerInfo
argument_list|()
specifier|const
block|{
return|return
name|PtrInfo
return|;
block|}
comment|/// Return the base address of the memory access. This may either be a normal
comment|/// LLVM IR Value, or one of the special values used in CodeGen.
comment|/// Special values are those obtained via
comment|/// PseudoSourceValue::getFixedStack(int), PseudoSourceValue::getStack, and
comment|/// other PseudoSourceValue member functions which return objects which stand
comment|/// for frame/stack pointer relative references and other special references
comment|/// which are not representable in the high-level IR.
specifier|const
name|Value
operator|*
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|PtrInfo
operator|.
name|V
operator|.
name|dyn_cast
operator|<
specifier|const
name|Value
operator|*
operator|>
operator|(
operator|)
return|;
block|}
specifier|const
name|PseudoSourceValue
operator|*
name|getPseudoValue
argument_list|()
specifier|const
block|{
return|return
name|PtrInfo
operator|.
name|V
operator|.
name|dyn_cast
operator|<
specifier|const
name|PseudoSourceValue
operator|*
operator|>
operator|(
operator|)
return|;
block|}
specifier|const
name|void
operator|*
name|getOpaqueValue
argument_list|()
specifier|const
block|{
return|return
name|PtrInfo
operator|.
name|V
operator|.
name|getOpaqueValue
argument_list|()
return|;
block|}
comment|/// Return the raw flags of the source value, \see Flags.
name|Flags
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|FlagVals
return|;
block|}
comment|/// Bitwise OR the current flags with the given flags.
name|void
name|setFlags
parameter_list|(
name|Flags
name|f
parameter_list|)
block|{
name|FlagVals
operator||=
name|f
expr_stmt|;
block|}
comment|/// For normal values, this is a byte offset added to the base address.
comment|/// For PseudoSourceValue::FPRel values, this is the FrameIndex number.
name|int64_t
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|PtrInfo
operator|.
name|Offset
return|;
block|}
name|unsigned
name|getAddrSpace
argument_list|()
specifier|const
block|{
return|return
name|PtrInfo
operator|.
name|getAddrSpace
argument_list|()
return|;
block|}
comment|/// Return the size in bytes of the memory reference.
name|uint64_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
comment|/// Return the minimum known alignment in bytes of the actual memory
comment|/// reference.
name|uint64_t
name|getAlignment
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return the minimum known alignment in bytes of the base address, without
comment|/// the offset.
name|uint64_t
name|getBaseAlignment
argument_list|()
specifier|const
block|{
return|return
operator|(
literal|1u
operator|<<
name|BaseAlignLog2
operator|)
operator|>>
literal|1
return|;
block|}
comment|/// Return the AA tags for the memory reference.
name|AAMDNodes
name|getAAInfo
argument_list|()
specifier|const
block|{
return|return
name|AAInfo
return|;
block|}
comment|/// Return the range tag for the memory reference.
specifier|const
name|MDNode
operator|*
name|getRanges
argument_list|()
specifier|const
block|{
return|return
name|Ranges
return|;
block|}
comment|/// Return the synchronization scope for this memory operation.
name|SynchronizationScope
name|getSynchScope
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|SynchronizationScope
operator|>
operator|(
name|AtomicInfo
operator|.
name|SynchScope
operator|)
return|;
block|}
comment|/// Return the atomic ordering requirements for this memory operation. For
comment|/// cmpxchg atomic operations, return the atomic ordering requirements when
comment|/// store occurs.
name|AtomicOrdering
name|getOrdering
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|AtomicOrdering
operator|>
operator|(
name|AtomicInfo
operator|.
name|Ordering
operator|)
return|;
block|}
comment|/// For cmpxchg atomic operations, return the atomic ordering requirements
comment|/// when store does not occur.
name|AtomicOrdering
name|getFailureOrdering
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|AtomicOrdering
operator|>
operator|(
name|AtomicInfo
operator|.
name|FailureOrdering
operator|)
return|;
block|}
name|bool
name|isLoad
argument_list|()
specifier|const
block|{
return|return
name|FlagVals
operator|&
name|MOLoad
return|;
block|}
name|bool
name|isStore
argument_list|()
specifier|const
block|{
return|return
name|FlagVals
operator|&
name|MOStore
return|;
block|}
name|bool
name|isVolatile
argument_list|()
specifier|const
block|{
return|return
name|FlagVals
operator|&
name|MOVolatile
return|;
block|}
name|bool
name|isNonTemporal
argument_list|()
specifier|const
block|{
return|return
name|FlagVals
operator|&
name|MONonTemporal
return|;
block|}
name|bool
name|isDereferenceable
argument_list|()
specifier|const
block|{
return|return
name|FlagVals
operator|&
name|MODereferenceable
return|;
block|}
name|bool
name|isInvariant
argument_list|()
specifier|const
block|{
return|return
name|FlagVals
operator|&
name|MOInvariant
return|;
block|}
comment|/// Returns true if this operation has an atomic ordering requirement of
comment|/// unordered or higher, false otherwise.
name|bool
name|isAtomic
argument_list|()
specifier|const
block|{
return|return
name|getOrdering
argument_list|()
operator|!=
name|AtomicOrdering
operator|::
name|NotAtomic
return|;
block|}
comment|/// Returns true if this memory operation doesn't have any ordering
comment|/// constraints other than normal aliasing. Volatile and atomic memory
comment|/// operations can't be reordered.
comment|///
comment|/// Currently, we don't model the difference between volatile and atomic
comment|/// operations. They should retain their ordering relative to all memory
comment|/// operations.
name|bool
name|isUnordered
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isVolatile
argument_list|()
return|;
block|}
comment|/// Update this MachineMemOperand to reflect the alignment of MMO, if it has a
comment|/// greater alignment. This must only be used when the new alignment applies
comment|/// to all users of this MachineMemOperand.
name|void
name|refineAlignment
parameter_list|(
specifier|const
name|MachineMemOperand
modifier|*
name|MMO
parameter_list|)
function_decl|;
comment|/// Change the SourceValue for this MachineMemOperand. This should only be
comment|/// used when an object is being relocated and all references to it are being
comment|/// updated.
name|void
name|setValue
parameter_list|(
specifier|const
name|Value
modifier|*
name|NewSV
parameter_list|)
block|{
name|PtrInfo
operator|.
name|V
operator|=
name|NewSV
expr_stmt|;
block|}
name|void
name|setValue
parameter_list|(
specifier|const
name|PseudoSourceValue
modifier|*
name|NewSV
parameter_list|)
block|{
name|PtrInfo
operator|.
name|V
operator|=
name|NewSV
expr_stmt|;
block|}
name|void
name|setOffset
parameter_list|(
name|int64_t
name|NewOffset
parameter_list|)
block|{
name|PtrInfo
operator|.
name|Offset
operator|=
name|NewOffset
expr_stmt|;
block|}
comment|/// Profile - Gather unique data for the object.
comment|///
name|void
name|Profile
argument_list|(
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
decl|const
decl_stmt|;
comment|/// Support for operator<<.
comment|/// @{
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|ModuleSlotTracker
operator|&
name|MST
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MachineMemOperand
operator|&
name|LHS
operator|,
specifier|const
name|MachineMemOperand
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|getValue
argument_list|()
operator|==
name|RHS
operator|.
name|getValue
argument_list|()
operator|&&
name|LHS
operator|.
name|getPseudoValue
argument_list|()
operator|==
name|RHS
operator|.
name|getPseudoValue
argument_list|()
operator|&&
name|LHS
operator|.
name|getSize
argument_list|()
operator|==
name|RHS
operator|.
name|getSize
argument_list|()
operator|&&
name|LHS
operator|.
name|getOffset
argument_list|()
operator|==
name|RHS
operator|.
name|getOffset
argument_list|()
operator|&&
name|LHS
operator|.
name|getFlags
argument_list|()
operator|==
name|RHS
operator|.
name|getFlags
argument_list|()
operator|&&
name|LHS
operator|.
name|getAAInfo
argument_list|()
operator|==
name|RHS
operator|.
name|getAAInfo
argument_list|()
operator|&&
name|LHS
operator|.
name|getRanges
argument_list|()
operator|==
name|RHS
operator|.
name|getRanges
argument_list|()
operator|&&
name|LHS
operator|.
name|getAlignment
argument_list|()
operator|==
name|RHS
operator|.
name|getAlignment
argument_list|()
operator|&&
name|LHS
operator|.
name|getAddrSpace
argument_list|()
operator|==
name|RHS
operator|.
name|getAddrSpace
argument_list|()
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|MachineMemOperand
operator|&
name|LHS
operator|,
specifier|const
name|MachineMemOperand
operator|&
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|MachineMemOperand
operator|&
name|MRO
operator|)
block|{
name|MRO
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

