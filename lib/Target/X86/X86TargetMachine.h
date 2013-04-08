begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86TargetMachine.h - Define TargetMachine for the X86 ---*- C++ -*-===//
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
comment|// This file declares the X86 specific subclass of TargetMachine.
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
name|X86TARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|X86TARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"X86.h"
end_include

begin_include
include|#
directive|include
file|"X86FrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"X86ISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"X86InstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"X86JITInfo.h"
end_include

begin_include
include|#
directive|include
file|"X86SelectionDAGInfo.h"
end_include

begin_include
include|#
directive|include
file|"X86Subtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|class
name|X86TargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|X86Subtarget
name|Subtarget
block|;
name|X86FrameLowering
name|FrameLowering
block|;
name|InstrItineraryData
name|InstrItins
block|;
name|public
operator|:
name|X86TargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Reloc::Model RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|,
argument|bool is64Bit
argument_list|)
block|;
name|virtual
specifier|const
name|X86InstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"getInstrInfo not implemented"
argument_list|)
block|;   }
name|virtual
specifier|const
name|TargetFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
block|{
return|return
operator|&
name|FrameLowering
return|;
block|}
name|virtual
name|X86JITInfo
operator|*
name|getJITInfo
argument_list|()
block|{
name|llvm_unreachable
argument_list|(
literal|"getJITInfo not implemented"
argument_list|)
block|;   }
name|virtual
specifier|const
name|X86Subtarget
operator|*
name|getSubtargetImpl
argument_list|()
specifier|const
block|{
return|return
operator|&
name|Subtarget
return|;
block|}
name|virtual
specifier|const
name|X86TargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"getTargetLowering not implemented"
argument_list|)
block|;   }
name|virtual
specifier|const
name|X86SelectionDAGInfo
operator|*
name|getSelectionDAGInfo
argument_list|()
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"getSelectionDAGInfo not implemented"
argument_list|)
block|;   }
name|virtual
specifier|const
name|X86RegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|getInstrInfo
argument_list|()
operator|->
name|getRegisterInfo
argument_list|()
return|;
block|}
name|virtual
specifier|const
name|InstrItineraryData
operator|*
name|getInstrItineraryData
argument_list|()
specifier|const
block|{
return|return
operator|&
name|InstrItins
return|;
block|}
comment|/// \brief Register X86 analysis passes with a pass manager.
name|virtual
name|void
name|addAnalysisPasses
argument_list|(
name|PassManagerBase
operator|&
name|PM
argument_list|)
block|;
comment|// Set up the pass pipeline.
name|virtual
name|TargetPassConfig
operator|*
name|createPassConfig
argument_list|(
name|PassManagerBase
operator|&
name|PM
argument_list|)
block|;
name|virtual
name|bool
name|addCodeEmitter
argument_list|(
name|PassManagerBase
operator|&
name|PM
argument_list|,
name|JITCodeEmitter
operator|&
name|JCE
argument_list|)
block|; }
decl_stmt|;
comment|/// X86_32TargetMachine - X86 32-bit target machine.
comment|///
name|class
name|X86_32TargetMachine
range|:
name|public
name|X86TargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
specifier|const
name|DataLayout
name|DL
block|;
comment|// Calculates type size& alignment
name|X86InstrInfo
name|InstrInfo
block|;
name|X86TargetLowering
name|TLInfo
block|;
name|X86SelectionDAGInfo
name|TSInfo
block|;
name|X86JITInfo
name|JITInfo
block|;
name|public
operator|:
name|X86_32TargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Reloc::Model RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|)
block|;
name|virtual
specifier|const
name|DataLayout
operator|*
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
operator|&
name|DL
return|;
block|}
name|virtual
specifier|const
name|X86TargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
operator|&
name|TLInfo
return|;
block|}
name|virtual
specifier|const
name|X86SelectionDAGInfo
operator|*
name|getSelectionDAGInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|TSInfo
return|;
block|}
name|virtual
specifier|const
name|X86InstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|InstrInfo
return|;
block|}
name|virtual
name|X86JITInfo
operator|*
name|getJITInfo
argument_list|()
block|{
return|return
operator|&
name|JITInfo
return|;
block|}
expr|}
block|;
comment|/// X86_64TargetMachine - X86 64-bit target machine.
comment|///
name|class
name|X86_64TargetMachine
operator|:
name|public
name|X86TargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
specifier|const
name|DataLayout
name|DL
block|;
comment|// Calculates type size& alignment
name|X86InstrInfo
name|InstrInfo
block|;
name|X86TargetLowering
name|TLInfo
block|;
name|X86SelectionDAGInfo
name|TSInfo
block|;
name|X86JITInfo
name|JITInfo
block|;
name|public
operator|:
name|X86_64TargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Reloc::Model RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|)
block|;
name|virtual
specifier|const
name|DataLayout
operator|*
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
operator|&
name|DL
return|;
block|}
name|virtual
specifier|const
name|X86TargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
operator|&
name|TLInfo
return|;
block|}
name|virtual
specifier|const
name|X86SelectionDAGInfo
operator|*
name|getSelectionDAGInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|TSInfo
return|;
block|}
name|virtual
specifier|const
name|X86InstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|InstrInfo
return|;
block|}
name|virtual
name|X86JITInfo
operator|*
name|getJITInfo
argument_list|()
block|{
return|return
operator|&
name|JITInfo
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

