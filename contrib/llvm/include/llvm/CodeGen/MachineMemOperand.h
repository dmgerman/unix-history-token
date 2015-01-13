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
file|"llvm/IR/Value.h"
end_include

begin_comment
comment|// PointerLikeTypeTraits<Value*>
end_comment

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
comment|/// MachinePointerInfo - This class contains a discriminated union of
comment|/// information about pointers in memory operands, relating them back to LLVM IR
comment|/// or to virtual locations (such as frame indices) that are exposed during
comment|/// codegen.
struct|struct
name|MachinePointerInfo
block|{
comment|/// V - This is the IR pointer value for the access, or it is null if unknown.
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
comment|/// getAddrSpace - Return the LLVM IR address space number that this pointer
comment|/// points into.
name|unsigned
name|getAddrSpace
argument_list|()
decl|const
struct|;
comment|/// getConstantPool - Return a MachinePointerInfo record that refers to the
comment|/// constant pool.
specifier|static
name|MachinePointerInfo
name|getConstantPool
parameter_list|()
function_decl|;
comment|/// getFixedStack - Return a MachinePointerInfo record that refers to the
comment|/// the specified FrameIndex.
specifier|static
name|MachinePointerInfo
name|getFixedStack
parameter_list|(
name|int
name|FI
parameter_list|,
name|int64_t
name|offset
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// getJumpTable - Return a MachinePointerInfo record that refers to a
comment|/// jump table entry.
specifier|static
name|MachinePointerInfo
name|getJumpTable
parameter_list|()
function_decl|;
comment|/// getGOT - Return a MachinePointerInfo record that refers to a
comment|/// GOT entry.
specifier|static
name|MachinePointerInfo
name|getGOT
parameter_list|()
function_decl|;
comment|/// getStack - stack pointer relative access.
specifier|static
name|MachinePointerInfo
name|getStack
parameter_list|(
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
comment|/// MachineMemOperand - A description of a memory reference used in the backend.
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
name|MachinePointerInfo
name|PtrInfo
decl_stmt|;
name|uint64_t
name|Size
decl_stmt|;
name|unsigned
name|Flags
decl_stmt|;
specifier|const
name|MDNode
modifier|*
name|TBAAInfo
decl_stmt|;
specifier|const
name|MDNode
modifier|*
name|Ranges
decl_stmt|;
name|public
label|:
comment|/// Flags values. These may be or'd together.
enum|enum
name|MemOperandFlags
block|{
comment|/// The memory access reads data.
name|MOLoad
init|=
literal|1
block|,
comment|/// The memory access writes data.
name|MOStore
init|=
literal|2
block|,
comment|/// The memory access is volatile.
name|MOVolatile
init|=
literal|4
block|,
comment|/// The memory access is non-temporal.
name|MONonTemporal
init|=
literal|8
block|,
comment|/// The memory access is invariant.
name|MOInvariant
init|=
literal|16
block|,
comment|// Target hints allow target passes to annotate memory operations.
name|MOTargetStartBit
init|=
literal|5
block|,
name|MOTargetNumBits
init|=
literal|3
block|,
comment|// This is the number of bits we need to represent flags.
name|MOMaxBits
init|=
literal|8
block|}
enum|;
comment|/// MachineMemOperand - Construct an MachineMemOperand object with the
comment|/// specified PtrInfo, flags, size, and base alignment.
name|MachineMemOperand
argument_list|(
argument|MachinePointerInfo PtrInfo
argument_list|,
argument|unsigned flags
argument_list|,
argument|uint64_t s
argument_list|,
argument|unsigned base_alignment
argument_list|,
argument|const MDNode *TBAAInfo = nullptr
argument_list|,
argument|const MDNode *Ranges = nullptr
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
comment|/// getValue - Return the base address of the memory access. This may either
comment|/// be a normal LLVM IR Value, or one of the special values used in CodeGen.
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
comment|/// getFlags - Return the raw flags of the source value, \see MemOperandFlags.
name|unsigned
name|int
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
operator|(
operator|(
literal|1
operator|<<
name|MOMaxBits
operator|)
operator|-
literal|1
operator|)
return|;
block|}
comment|/// Bitwise OR the current flags with the given flags.
name|void
name|setFlags
parameter_list|(
name|unsigned
name|f
parameter_list|)
block|{
name|Flags
operator||=
operator|(
name|f
operator|&
operator|(
operator|(
literal|1
operator|<<
name|MOMaxBits
operator|)
operator|-
literal|1
operator|)
operator|)
expr_stmt|;
block|}
comment|/// getOffset - For normal values, this is a byte offset added to the base
comment|/// address. For PseudoSourceValue::FPRel values, this is the FrameIndex
comment|/// number.
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
comment|/// getSize - Return the size in bytes of the memory reference.
name|uint64_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
comment|/// getAlignment - Return the minimum known alignment in bytes of the
comment|/// actual memory reference.
name|uint64_t
name|getAlignment
argument_list|()
specifier|const
expr_stmt|;
comment|/// getBaseAlignment - Return the minimum known alignment in bytes of the
comment|/// base address, without the offset.
name|uint64_t
name|getBaseAlignment
argument_list|()
specifier|const
block|{
return|return
operator|(
literal|1u
operator|<<
operator|(
name|Flags
operator|>>
name|MOMaxBits
operator|)
operator|)
operator|>>
literal|1
return|;
block|}
comment|/// getTBAAInfo - Return the TBAA tag for the memory reference.
specifier|const
name|MDNode
operator|*
name|getTBAAInfo
argument_list|()
specifier|const
block|{
return|return
name|TBAAInfo
return|;
block|}
comment|/// getRanges - Return the range tag for the memory reference.
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
name|bool
name|isLoad
argument_list|()
specifier|const
block|{
return|return
name|Flags
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
name|Flags
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
name|Flags
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
name|Flags
operator|&
name|MONonTemporal
return|;
block|}
name|bool
name|isInvariant
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
name|MOInvariant
return|;
block|}
comment|/// isUnordered - Returns true if this memory operation doesn't have any
comment|/// ordering constraints other than normal aliasing. Volatile and atomic
comment|/// memory operations can't be reordered.
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
comment|/// refineAlignment - Update this MachineMemOperand to reflect the alignment
comment|/// of MMO, if it has a greater alignment. This must only be used when the
comment|/// new alignment applies to all users of this MachineMemOperand.
name|void
name|refineAlignment
parameter_list|(
specifier|const
name|MachineMemOperand
modifier|*
name|MMO
parameter_list|)
function_decl|;
comment|/// setValue - Change the SourceValue for this MachineMemOperand. This
comment|/// should only be used when an object is being relocated and all references
comment|/// to it are being updated.
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
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
expr_stmt|;
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

