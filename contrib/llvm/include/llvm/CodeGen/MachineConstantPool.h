begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodeGen/MachineConstantPool.h - Abstract Constant Pool ---*- C++ -*-===//
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
comment|/// @file
end_comment

begin_comment
comment|/// This file declares the MachineConstantPool class which is an abstract
end_comment

begin_comment
comment|/// constant pool to keep track of constants referenced by a function.
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
name|LLVM_CODEGEN_MACHINECONSTANTPOOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINECONSTANTPOOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/SectionKind.h"
end_include

begin_include
include|#
directive|include
file|<climits>
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
name|class
name|Constant
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|FoldingSetNodeID
decl_stmt|;
name|class
name|MachineConstantPool
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|Type
decl_stmt|;
comment|/// Abstract base class for all machine specific constantpool value subclasses.
comment|///
name|class
name|MachineConstantPoolValue
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|Type
modifier|*
name|Ty
decl_stmt|;
name|public
label|:
name|explicit
name|MachineConstantPoolValue
argument_list|(
name|Type
operator|*
name|ty
argument_list|)
operator|:
name|Ty
argument_list|(
argument|ty
argument_list|)
block|{}
name|virtual
operator|~
name|MachineConstantPoolValue
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// getType - get type of this MachineConstantPoolValue.
comment|///
name|Type
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Ty
return|;
block|}
name|virtual
name|int
name|getExistingMachineCPValue
parameter_list|(
name|MachineConstantPool
modifier|*
name|CP
parameter_list|,
name|unsigned
name|Alignment
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|addSelectionDAGCSEId
parameter_list|(
name|FoldingSetNodeID
modifier|&
name|ID
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// print - Implement operator<<
name|virtual
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
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
name|MachineConstantPoolValue
operator|&
name|V
operator|)
block|{
name|V
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
comment|/// This class is a data container for one entry in a MachineConstantPool.
comment|/// It contains a pointer to the value and an offset from the start of
comment|/// the constant pool.
comment|/// @brief An entry in a MachineConstantPool
name|class
name|MachineConstantPoolEntry
block|{
name|public
label|:
comment|/// The constant itself.
union|union
block|{
specifier|const
name|Constant
modifier|*
name|ConstVal
decl_stmt|;
name|MachineConstantPoolValue
modifier|*
name|MachineCPVal
decl_stmt|;
block|}
name|Val
union|;
comment|/// The required alignment for this entry. The top bit is set when Val is
comment|/// a target specific MachineConstantPoolValue.
name|unsigned
name|Alignment
decl_stmt|;
name|MachineConstantPoolEntry
argument_list|(
argument|const Constant *V
argument_list|,
argument|unsigned A
argument_list|)
block|:
name|Alignment
argument_list|(
argument|A
argument_list|)
block|{
name|Val
operator|.
name|ConstVal
operator|=
name|V
expr_stmt|;
block|}
name|MachineConstantPoolEntry
argument_list|(
argument|MachineConstantPoolValue *V
argument_list|,
argument|unsigned A
argument_list|)
block|:
name|Alignment
argument_list|(
argument|A
argument_list|)
block|{
name|Val
operator|.
name|MachineCPVal
operator|=
name|V
expr_stmt|;
name|Alignment
operator||=
literal|1U
operator|<<
operator|(
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
operator|*
name|CHAR_BIT
operator|-
literal|1
operator|)
expr_stmt|;
block|}
comment|/// isMachineConstantPoolEntry - Return true if the MachineConstantPoolEntry
comment|/// is indeed a target specific constantpool entry, not a wrapper over a
comment|/// Constant.
name|bool
name|isMachineConstantPoolEntry
argument_list|()
specifier|const
block|{
return|return
operator|(
name|int
operator|)
name|Alignment
operator|<
literal|0
return|;
block|}
name|int
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|Alignment
operator|&
operator|~
operator|(
literal|1
operator|<<
operator|(
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
operator|*
name|CHAR_BIT
operator|-
literal|1
operator|)
operator|)
return|;
block|}
name|Type
operator|*
name|getType
argument_list|()
specifier|const
expr_stmt|;
comment|/// This method classifies the entry according to whether or not it may
comment|/// generate a relocation entry.  This must be conservative, so if it might
comment|/// codegen to a relocatable entry, it should say so.
name|bool
name|needsRelocation
argument_list|()
specifier|const
expr_stmt|;
name|SectionKind
name|getSectionKind
argument_list|(
specifier|const
name|DataLayout
operator|*
name|DL
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
comment|/// The MachineConstantPool class keeps track of constants referenced by a
comment|/// function which must be spilled to memory.  This is used for constants which
comment|/// are unable to be used directly as operands to instructions, which typically
comment|/// include floating point and large integer constants.
comment|///
comment|/// Instructions reference the address of these constant pool constants through
comment|/// the use of MO_ConstantPoolIndex values.  When emitting assembly or machine
comment|/// code, these virtual address references are converted to refer to the
comment|/// address of the function constant pool values.
comment|/// @brief The machine constant pool.
name|class
name|MachineConstantPool
block|{
name|unsigned
name|PoolAlignment
decl_stmt|;
comment|///< The alignment for the pool.
name|std
operator|::
name|vector
operator|<
name|MachineConstantPoolEntry
operator|>
name|Constants
expr_stmt|;
comment|///< The pool of constants.
comment|/// MachineConstantPoolValues that use an existing MachineConstantPoolEntry.
name|DenseSet
operator|<
name|MachineConstantPoolValue
operator|*
operator|>
name|MachineCPVsSharingEntries
expr_stmt|;
specifier|const
name|DataLayout
modifier|&
name|DL
decl_stmt|;
specifier|const
name|DataLayout
operator|&
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
name|DL
return|;
block|}
name|public
label|:
comment|/// @brief The only constructor.
name|explicit
name|MachineConstantPool
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
operator|:
name|PoolAlignment
argument_list|(
literal|1
argument_list|)
operator|,
name|DL
argument_list|(
argument|DL
argument_list|)
block|{}
operator|~
name|MachineConstantPool
argument_list|()
expr_stmt|;
comment|/// getConstantPoolAlignment - Return the alignment required by
comment|/// the whole constant pool, of which the first element must be aligned.
name|unsigned
name|getConstantPoolAlignment
argument_list|()
specifier|const
block|{
return|return
name|PoolAlignment
return|;
block|}
comment|/// getConstantPoolIndex - Create a new entry in the constant pool or return
comment|/// an existing one.  User must specify the minimum required alignment for
comment|/// the object.
name|unsigned
name|getConstantPoolIndex
parameter_list|(
specifier|const
name|Constant
modifier|*
name|C
parameter_list|,
name|unsigned
name|Alignment
parameter_list|)
function_decl|;
name|unsigned
name|getConstantPoolIndex
parameter_list|(
name|MachineConstantPoolValue
modifier|*
name|V
parameter_list|,
name|unsigned
name|Alignment
parameter_list|)
function_decl|;
comment|/// isEmpty - Return true if this constant pool contains no constants.
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|Constants
operator|.
name|empty
argument_list|()
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|MachineConstantPoolEntry
operator|>
operator|&
name|getConstants
argument_list|()
specifier|const
block|{
return|return
name|Constants
return|;
block|}
comment|/// print - Used by the MachineFunction printer to print information about
comment|/// constant pool objects.  Implemented in MachineFunction.cpp
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// dump - Call print(cerr) to be called from the debugger.
name|void
name|dump
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
comment|// LLVM_CODEGEN_MACHINECONSTANTPOOL_H
end_comment

end_unit

