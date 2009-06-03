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
file|"MachOWriter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineCodeEmitter.h"
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
comment|/// MachOCodeEmitter - This class is used by the MachOWriter to emit the code
comment|/// for functions to the Mach-O file.
name|class
name|MachOCodeEmitter
range|:
name|public
name|MachineCodeEmitter
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
name|TargetAsmInfo
operator|*
name|TAI
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
comment|/// CPLocations - This is a map of constant pool indices to offsets from the
comment|/// start of the section for that constant pool index.
name|std
operator|::
name|vector
operator|<
name|uintptr_t
operator|>
name|CPLocations
block|;
comment|/// CPSections - This is a map of constant pool indices to the MachOSection
comment|/// containing the constant pool entry for that index.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|CPSections
block|;
comment|/// JTLocations - This is a map of jump table indices to offsets from the
comment|/// start of the section for that jump table index.
name|std
operator|::
name|vector
operator|<
name|uintptr_t
operator|>
name|JTLocations
block|;
comment|/// MBBLocations - This vector is a mapping from MBB ID's to their address.
comment|/// It is filled in by the StartMachineBasicBlock callback and queried by
comment|/// the getMachineBasicBlockAddress callback.
name|std
operator|::
name|vector
operator|<
name|uintptr_t
operator|>
name|MBBLocations
block|;
name|public
operator|:
name|MachOCodeEmitter
argument_list|(
name|MachOWriter
operator|&
name|mow
argument_list|)
operator|:
name|MOW
argument_list|(
name|mow
argument_list|)
block|,
name|TM
argument_list|(
argument|MOW.TM
argument_list|)
block|{
name|is64Bit
operator|=
name|TM
operator|.
name|getTargetData
argument_list|()
operator|->
name|getPointerSizeInBits
argument_list|()
operator|==
literal|64
block|;
name|isLittleEndian
operator|=
name|TM
operator|.
name|getTargetData
argument_list|()
operator|->
name|isLittleEndian
argument_list|()
block|;
name|TAI
operator|=
name|TM
operator|.
name|getTargetAsmInfo
argument_list|()
block|;     }
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
name|uintptr_t
name|getConstantPoolEntryAddress
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|CPLocations
operator|.
name|size
argument_list|()
operator|>
name|Index
operator|&&
literal|"CP not emitted!"
argument_list|)
block|;
return|return
name|CPLocations
index|[
name|Index
index|]
return|;
block|}
name|virtual
name|uintptr_t
name|getJumpTableEntryAddress
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|JTLocations
operator|.
name|size
argument_list|()
operator|>
name|Index
operator|&&
literal|"JT not emitted!"
argument_list|)
block|;
return|return
name|JTLocations
index|[
name|Index
index|]
return|;
block|}
name|virtual
name|void
name|StartMachineBasicBlock
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|)
block|{
if|if
condition|(
name|MBBLocations
operator|.
name|size
argument_list|()
operator|<=
operator|(
name|unsigned
operator|)
name|MBB
operator|->
name|getNumber
argument_list|()
condition|)
name|MBBLocations
operator|.
name|resize
argument_list|(
operator|(
name|MBB
operator|->
name|getNumber
argument_list|()
operator|+
literal|1
operator|)
operator|*
literal|2
argument_list|)
expr_stmt|;
name|MBBLocations
index|[
name|MBB
operator|->
name|getNumber
argument_list|()
index|]
operator|=
name|getCurrentPCOffset
argument_list|()
block|;   }
name|virtual
name|uintptr_t
name|getMachineBasicBlockAddress
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|MBBLocations
operator|.
name|size
argument_list|()
operator|>
operator|(
name|unsigned
operator|)
name|MBB
operator|->
name|getNumber
argument_list|()
operator|&&
name|MBBLocations
index|[
name|MBB
operator|->
name|getNumber
argument_list|()
index|]
operator|&&
literal|"MBB not emitted!"
argument_list|)
block|;
return|return
name|MBBLocations
index|[
name|MBB
operator|->
name|getNumber
argument_list|()
index|]
return|;
block|}
name|virtual
name|uintptr_t
name|getLabelAddress
argument_list|(
name|uint64_t
name|Label
argument_list|)
decl|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"get Label not implemented"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
name|virtual
name|void
name|emitLabel
parameter_list|(
name|uint64_t
name|LabelID
parameter_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"emit Label not implemented"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
name|virtual
name|void
name|setModuleInfo
argument_list|(
name|llvm
operator|::
name|MachineModuleInfo
operator|*
name|MMI
argument_list|)
block|{ }
comment|/// JIT SPECIFIC FUNCTIONS - DO NOT IMPLEMENT THESE HERE!
name|virtual
name|void
name|startGVStub
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|F
parameter_list|,
name|unsigned
name|StubSize
parameter_list|,
name|unsigned
name|Alignment
init|=
literal|1
parameter_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"JIT specific function called!"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
name|virtual
name|void
name|startGVStub
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|F
parameter_list|,
name|void
modifier|*
name|Buffer
parameter_list|,
name|unsigned
name|StubSize
parameter_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"JIT specific function called!"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
name|virtual
name|void
modifier|*
name|finishGVStub
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|F
parameter_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"JIT specific function called!"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// end class MachOCodeEmitter
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

