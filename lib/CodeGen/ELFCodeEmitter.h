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
name|TargetMachine
operator|&
name|TM
block|;
name|ELFSection
operator|*
name|ES
block|;
comment|// Section to write to.
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
name|assert
argument_list|(
literal|0
operator|&&
literal|"relo not handled yet!"
argument_list|)
block|;     }
name|virtual
name|void
name|StartMachineBasicBlock
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|)
block|{     }
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
literal|0
operator|&&
literal|"CP not implementated yet!"
argument_list|)
block|;
return|return
literal|0
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
literal|0
operator|&&
literal|"JT not implementated yet!"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
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
literal|0
operator|&&
literal|"JT not implementated yet!"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
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
literal|0
operator|&&
literal|"Label address not implementated yet!"
argument_list|)
block|;
name|abort
argument_list|()
block|;
return|return
literal|0
return|;
block|}
name|virtual
name|void
name|emitLabel
argument_list|(
argument|uint64_t LabelID
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"emit Label not implementated yet!"
argument_list|)
block|;
name|abort
argument_list|()
block|;     }
name|virtual
name|void
name|setModuleInfo
argument_list|(
argument|llvm::MachineModuleInfo* MMI
argument_list|)
block|{ }
comment|/// JIT SPECIFIC FUNCTIONS - DO NOT IMPLEMENT THESE HERE!
name|void
name|startGVStub
argument_list|(
argument|const GlobalValue* F
argument_list|,
argument|unsigned StubSize
argument_list|,
argument|unsigned Alignment =
literal|1
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"JIT specific function called!"
argument_list|)
block|;
name|abort
argument_list|()
block|;     }
name|void
name|startGVStub
argument_list|(
argument|const GlobalValue* F
argument_list|,
argument|void *Buffer
argument_list|,
argument|unsigned StubSize
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"JIT specific function called!"
argument_list|)
block|;
name|abort
argument_list|()
block|;     }
name|void
operator|*
name|finishGVStub
argument_list|(
argument|const GlobalValue *F
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"JIT specific function called!"
argument_list|)
block|;
name|abort
argument_list|()
block|;
return|return
literal|0
return|;
block|}
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

