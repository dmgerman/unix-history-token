begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MachOEmitter.h - Target-independent Mach-O Emitter class ----------===//
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
name|MACHOCODEEMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|MACHOCODEEMITTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/ObjectCodeEmitter.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachOWriter
decl_stmt|;
comment|/// MachOCodeEmitter - This class is used by the MachOWriter to emit the code
comment|/// for functions to the Mach-O file.
name|class
name|MachOCodeEmitter
range|:
name|public
name|ObjectCodeEmitter
block|{
name|MachOWriter
operator|&
name|MOW
block|;
comment|/// Target machine description.
name|TargetMachine
operator|&
name|TM
block|;
comment|/// is64Bit/isLittleEndian - This information is inferred from the target
comment|/// machine directly, indicating what header values and flags to set.
name|bool
name|is64Bit
block|,
name|isLittleEndian
block|;
specifier|const
name|MCAsmInfo
operator|*
name|MAI
block|;
comment|/// Relocations - These are the relocations that the function needs, as
comment|/// emitted.
name|std
operator|::
name|vector
operator|<
name|MachineRelocation
operator|>
name|Relocations
block|;
name|std
operator|::
name|map
operator|<
name|uint64_t
block|,
name|uintptr_t
operator|>
name|Labels
block|;
name|public
operator|:
name|MachOCodeEmitter
argument_list|(
name|MachOWriter
operator|&
name|mow
argument_list|,
name|MachOSection
operator|&
name|mos
argument_list|)
block|;
name|virtual
name|void
name|startFunction
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|virtual
name|bool
name|finishFunction
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|virtual
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
block|;   }
name|void
name|emitConstantPool
argument_list|(
name|MachineConstantPool
operator|*
name|MCP
argument_list|)
block|;
name|void
name|emitJumpTables
argument_list|(
name|MachineJumpTableInfo
operator|*
name|MJTI
argument_list|)
block|;
name|virtual
name|void
name|emitLabel
argument_list|(
argument|uint64_t LabelID
argument_list|)
block|{
name|Labels
index|[
name|LabelID
index|]
operator|=
name|getCurrentPCOffset
argument_list|()
block|;   }
name|virtual
name|uintptr_t
name|getLabelAddress
argument_list|(
argument|uint64_t Label
argument_list|)
specifier|const
block|{
return|return
name|Labels
operator|.
name|find
argument_list|(
name|Label
argument_list|)
operator|->
name|second
return|;
block|}
name|virtual
name|void
name|setModuleInfo
argument_list|(
argument|llvm::MachineModuleInfo* MMI
argument_list|)
block|{ }
expr|}
block|;
comment|// end class MachOCodeEmitter
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

