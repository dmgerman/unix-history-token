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
file|"ELFWriter.h"
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
comment|/// ELFCodeEmitter - This class is used by the ELFWriter to
comment|/// emit the code for functions to the ELF file.
name|class
name|ELFCodeEmitter
range|:
name|public
name|MachineCodeEmitter
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
comment|/// FnStartPtr - Pointer to the start location of the current function
comment|/// in the buffer
name|uint8_t
operator|*
name|FnStartPtr
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
block|;     }
name|virtual
name|uintptr_t
name|getMachineBasicBlockAddress
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|)
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
name|getConstantPoolEntryAddress
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"CP not implementated yet!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|virtual
name|uintptr_t
name|getJumpTableEntryAddress
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"JT not implementated yet!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|virtual
name|uintptr_t
name|getMachineBasicBlockAddress
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"JT not implementated yet!"
argument_list|)
expr_stmt|;
return|return
literal|0
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
literal|"Label address not implementated yet!"
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
literal|"emit Label not implementated yet!"
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
comment|// end class ELFCodeEmitter
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

