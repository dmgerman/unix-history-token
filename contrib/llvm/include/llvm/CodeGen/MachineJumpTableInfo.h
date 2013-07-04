begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CodeGen/MachineJumpTableInfo.h - Abstract Jump Tables  --*- C++ -*-===//
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
comment|// The MachineJumpTableInfo class keeps track of jump tables referenced by
end_comment

begin_comment
comment|// lowered switch instructions in the MachineFunction.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Instructions reference the address of these jump tables through the use of
end_comment

begin_comment
comment|// MO_JumpTableIndex values.  When emitting assembly or machine code, these
end_comment

begin_comment
comment|// virtual address references are converted to refer to the address of the
end_comment

begin_comment
comment|// function jump tables.
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
name|LLVM_CODEGEN_MACHINEJUMPTABLEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEJUMPTABLEINFO_H
end_define

begin_include
include|#
directive|include
file|<cassert>
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
name|MachineBasicBlock
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// MachineJumpTableEntry - One jump table in the jump table info.
comment|///
struct|struct
name|MachineJumpTableEntry
block|{
comment|/// MBBs - The vector of basic blocks from which to create the jump table.
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
name|MBBs
expr_stmt|;
name|explicit
name|MachineJumpTableEntry
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|&
name|M
argument_list|)
range|:
name|MBBs
argument_list|(
argument|M
argument_list|)
block|{}
block|}
struct|;
name|class
name|MachineJumpTableInfo
block|{
name|public
label|:
comment|/// JTEntryKind - This enum indicates how each entry of the jump table is
comment|/// represented and emitted.
enum|enum
name|JTEntryKind
block|{
comment|/// EK_BlockAddress - Each entry is a plain address of block, e.g.:
comment|///     .word LBB123
name|EK_BlockAddress
block|,
comment|/// EK_GPRel64BlockAddress - Each entry is an address of block, encoded
comment|/// with a relocation as gp-relative, e.g.:
comment|///     .gpdword LBB123
name|EK_GPRel64BlockAddress
block|,
comment|/// EK_GPRel32BlockAddress - Each entry is an address of block, encoded
comment|/// with a relocation as gp-relative, e.g.:
comment|///     .gprel32 LBB123
name|EK_GPRel32BlockAddress
block|,
comment|/// EK_LabelDifference32 - Each entry is the address of the block minus
comment|/// the address of the jump table.  This is used for PIC jump tables where
comment|/// gprel32 is not supported.  e.g.:
comment|///      .word LBB123 - LJTI1_2
comment|/// If the .set directive is supported, this is emitted as:
comment|///      .set L4_5_set_123, LBB123 - LJTI1_2
comment|///      .word L4_5_set_123
name|EK_LabelDifference32
block|,
comment|/// EK_Inline - Jump table entries are emitted inline at their point of
comment|/// use. It is the responsibility of the target to emit the entries.
name|EK_Inline
block|,
comment|/// EK_Custom32 - Each entry is a 32-bit value that is custom lowered by the
comment|/// TargetLowering::LowerCustomJumpTableEntry hook.
name|EK_Custom32
block|}
enum|;
name|private
label|:
name|JTEntryKind
name|EntryKind
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|MachineJumpTableEntry
operator|>
name|JumpTables
expr_stmt|;
name|public
label|:
name|explicit
name|MachineJumpTableInfo
argument_list|(
argument|JTEntryKind Kind
argument_list|)
block|:
name|EntryKind
argument_list|(
argument|Kind
argument_list|)
block|{}
name|JTEntryKind
name|getEntryKind
argument_list|()
specifier|const
block|{
return|return
name|EntryKind
return|;
block|}
comment|/// getEntrySize - Return the size of each entry in the jump table.
name|unsigned
name|getEntrySize
argument_list|(
specifier|const
name|DataLayout
operator|&
name|TD
argument_list|)
decl|const
decl_stmt|;
comment|/// getEntryAlignment - Return the alignment of each entry in the jump table.
name|unsigned
name|getEntryAlignment
argument_list|(
specifier|const
name|DataLayout
operator|&
name|TD
argument_list|)
decl|const
decl_stmt|;
comment|/// createJumpTableIndex - Create a new jump table.
comment|///
name|unsigned
name|createJumpTableIndex
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|&
name|DestBBs
argument_list|)
decl_stmt|;
comment|/// isEmpty - Return true if there are no jump tables.
comment|///
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|JumpTables
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
name|MachineJumpTableEntry
operator|>
operator|&
name|getJumpTables
argument_list|()
specifier|const
block|{
return|return
name|JumpTables
return|;
block|}
comment|/// RemoveJumpTable - Mark the specific index as being dead.  This will
comment|/// prevent it from being emitted.
name|void
name|RemoveJumpTable
parameter_list|(
name|unsigned
name|Idx
parameter_list|)
block|{
name|JumpTables
index|[
name|Idx
index|]
operator|.
name|MBBs
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|/// ReplaceMBBInJumpTables - If Old is the target of any jump tables, update
comment|/// the jump tables to branch to New instead.
name|bool
name|ReplaceMBBInJumpTables
parameter_list|(
name|MachineBasicBlock
modifier|*
name|Old
parameter_list|,
name|MachineBasicBlock
modifier|*
name|New
parameter_list|)
function_decl|;
comment|/// ReplaceMBBInJumpTable - If Old is a target of the jump tables, update
comment|/// the jump table to branch to New instead.
name|bool
name|ReplaceMBBInJumpTable
parameter_list|(
name|unsigned
name|Idx
parameter_list|,
name|MachineBasicBlock
modifier|*
name|Old
parameter_list|,
name|MachineBasicBlock
modifier|*
name|New
parameter_list|)
function_decl|;
comment|/// print - Used by the MachineFunction printer to print information about
comment|/// jump tables.  Implemented in MachineFunction.cpp
comment|///
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// dump - Call to stderr.
comment|///
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
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

