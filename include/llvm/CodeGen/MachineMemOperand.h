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
file|"llvm/System/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|FoldingSetNodeID
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// MachineMemOperand - A description of a memory reference used in the backend.
comment|/// Instead of holding a StoreInst or LoadInst, this class holds the address
comment|/// Value of the reference along with a byte size and offset. This allows it
comment|/// to describe lowered loads and stores. Also, the special PseudoSourceValue
comment|/// objects can be used to represent loads and stores to memory locations
comment|/// that aren't explicit in the regular LLVM IR.
comment|///
name|class
name|MachineMemOperand
block|{
name|int64_t
name|Offset
decl_stmt|;
name|uint64_t
name|Size
decl_stmt|;
specifier|const
name|Value
modifier|*
name|V
decl_stmt|;
name|unsigned
name|int
name|Flags
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
block|}
enum|;
comment|/// MachineMemOperand - Construct an MachineMemOperand object with the
comment|/// specified address Value, flags, offset, size, and base alignment.
name|MachineMemOperand
argument_list|(
argument|const Value *v
argument_list|,
argument|unsigned int f
argument_list|,
argument|int64_t o
argument_list|,
argument|uint64_t s
argument_list|,
argument|unsigned int base_alignment
argument_list|)
empty_stmt|;
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
name|V
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
literal|7
return|;
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
name|Offset
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
literal|3
operator|)
operator|)
operator|>>
literal|1
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
name|V
operator|=
name|NewSV
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
empty_stmt|;
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

