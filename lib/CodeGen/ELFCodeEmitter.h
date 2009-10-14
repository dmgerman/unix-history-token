begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/CodeGen/ELFCodeEmitter.h ----------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|ELFCODEEMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|ELFCODEEMITTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/ObjectCodeEmitter.h"
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
name|ELFWriter
decl_stmt|;
name|class
name|ELFSection
decl_stmt|;
comment|/// ELFCodeEmitter - This class is used by the ELFWriter to
comment|/// emit the code for functions to the ELF file.
name|class
name|ELFCodeEmitter
range|:
name|public
name|ObjectCodeEmitter
block|{
name|ELFWriter
operator|&
name|EW
block|;
comment|/// Target machine description
name|TargetMachine
operator|&
name|TM
block|;
comment|/// Section containing code for functions
name|ELFSection
operator|*
name|ES
block|;
comment|/// Relocations - Record relocations needed by the current function
name|std
operator|::
name|vector
operator|<
name|MachineRelocation
operator|>
name|Relocations
block|;
comment|/// JTRelocations - Record relocations needed by the relocation
comment|/// section.
name|std
operator|::
name|vector
operator|<
name|MachineRelocation
operator|>
name|JTRelocations
block|;
comment|/// FnStartPtr - Function offset from the beginning of ELFSection 'ES'
name|uintptr_t
name|FnStartOff
block|;
name|public
operator|:
name|explicit
name|ELFCodeEmitter
argument_list|(
name|ELFWriter
operator|&
name|ew
argument_list|)
operator|:
name|EW
argument_list|(
name|ew
argument_list|)
block|,
name|TM
argument_list|(
argument|EW.TM
argument_list|)
block|{}
comment|/// addRelocation - Register new relocations for this function
name|void
name|addRelocation
argument_list|(
argument|const MachineRelocation&MR
argument_list|)
block|{
name|Relocations
operator|.
name|push_back
argument_list|(
name|MR
argument_list|)
block|;     }
comment|/// emitConstantPool - For each constant pool entry, figure out which
comment|/// section the constant should live in and emit data to it
name|void
name|emitConstantPool
argument_list|(
name|MachineConstantPool
operator|*
name|MCP
argument_list|)
block|;
comment|/// emitJumpTables - Emit all the jump tables for a given jump table
comment|/// info and record them to the appropriate section.
name|void
name|emitJumpTables
argument_list|(
name|MachineJumpTableInfo
operator|*
name|MJTI
argument_list|)
block|;
name|void
name|startFunction
argument_list|(
name|MachineFunction
operator|&
name|F
argument_list|)
block|;
name|bool
name|finishFunction
argument_list|(
name|MachineFunction
operator|&
name|F
argument_list|)
block|;
comment|/// emitLabel - Emits a label
name|virtual
name|void
name|emitLabel
argument_list|(
argument|uint64_t LabelID
argument_list|)
block|{
name|assert
argument_list|(
literal|"emitLabel not implemented"
argument_list|)
block|;     }
comment|/// getLabelAddress - Return the address of the specified LabelID,
comment|/// only usable after the LabelID has been emitted.
name|virtual
name|uintptr_t
name|getLabelAddress
argument_list|(
argument|uint64_t Label
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
literal|"getLabelAddress not implemented"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
name|virtual
name|void
name|setModuleInfo
argument_list|(
argument|llvm::MachineModuleInfo* MMI
argument_list|)
block|{}
expr|}
block|;
comment|// end class ELFCodeEmitter
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

