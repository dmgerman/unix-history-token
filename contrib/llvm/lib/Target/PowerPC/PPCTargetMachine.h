begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCTargetMachine.h - Define TargetMachine for PowerPC ---*- C++ -*-===//
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
comment|// This file declares the PowerPC specific subclass of TargetMachine.
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
name|PPC_TARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|PPC_TARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"PPCInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"PPCSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
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
comment|/// PPCTargetMachine - Common code between 32-bit and 64-bit PowerPC targets.
comment|///
name|class
name|PPCTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|PPCSubtarget
name|Subtarget
block|;
name|public
operator|:
name|PPCTargetMachine
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
specifier|const
name|PPCInstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
name|override
block|{
return|return
name|getSubtargetImpl
argument_list|()
operator|->
name|getInstrInfo
argument_list|()
return|;
block|}
specifier|const
name|PPCFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
name|override
block|{
return|return
name|getSubtargetImpl
argument_list|()
operator|->
name|getFrameLowering
argument_list|()
return|;
block|}
name|PPCJITInfo
operator|*
name|getJITInfo
argument_list|()
name|override
block|{
return|return
name|Subtarget
operator|.
name|getJITInfo
argument_list|()
return|;
block|}
specifier|const
name|PPCTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
name|override
block|{
return|return
name|getSubtargetImpl
argument_list|()
operator|->
name|getTargetLowering
argument_list|()
return|;
block|}
specifier|const
name|PPCSelectionDAGInfo
operator|*
name|getSelectionDAGInfo
argument_list|()
specifier|const
name|override
block|{
return|return
name|getSubtargetImpl
argument_list|()
operator|->
name|getSelectionDAGInfo
argument_list|()
return|;
block|}
specifier|const
name|PPCRegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
name|override
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
specifier|const
name|DataLayout
operator|*
name|getDataLayout
argument_list|()
specifier|const
name|override
block|{
return|return
name|getSubtargetImpl
argument_list|()
operator|->
name|getDataLayout
argument_list|()
return|;
block|}
specifier|const
name|PPCSubtarget
operator|*
name|getSubtargetImpl
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|Subtarget
return|;
block|}
specifier|const
name|InstrItineraryData
operator|*
name|getInstrItineraryData
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|getSubtargetImpl
argument_list|()
operator|->
name|getInstrItineraryData
argument_list|()
return|;
block|}
comment|// Pass Pipeline Configuration
name|TargetPassConfig
operator|*
name|createPassConfig
argument_list|(
argument|PassManagerBase&PM
argument_list|)
name|override
block|;
name|bool
name|addCodeEmitter
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|JITCodeEmitter&JCE
argument_list|)
name|override
block|;
comment|/// \brief Register PPC analysis passes with a pass manager.
name|void
name|addAnalysisPasses
argument_list|(
argument|PassManagerBase&PM
argument_list|)
name|override
block|; }
decl_stmt|;
comment|/// PPC32TargetMachine - PowerPC 32-bit target machine.
comment|///
name|class
name|PPC32TargetMachine
range|:
name|public
name|PPCTargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|PPC32TargetMachine
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
block|; }
decl_stmt|;
comment|/// PPC64TargetMachine - PowerPC 64-bit target machine.
comment|///
name|class
name|PPC64TargetMachine
range|:
name|public
name|PPCTargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|PPC64TargetMachine
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
block|; }
decl_stmt|;
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

