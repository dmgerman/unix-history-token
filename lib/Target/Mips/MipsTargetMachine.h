begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsTargetMachine.h - Define TargetMachine for Mips -----*- C++ -*-===//
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
comment|// This file declares the Mips specific subclass of TargetMachine.
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
name|MIPSTARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSTARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"MipsSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/Passes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGISel.h"
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
name|formatted_raw_ostream
decl_stmt|;
name|class
name|MipsRegisterInfo
decl_stmt|;
name|class
name|MipsTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|MipsSubtarget
operator|*
name|Subtarget
block|;
name|MipsSubtarget
name|DefaultSubtarget
block|;
name|MipsSubtarget
name|NoMips16Subtarget
block|;
name|MipsSubtarget
name|Mips16Subtarget
block|;
name|public
operator|:
name|MipsTargetMachine
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
argument|bool isLittle
argument_list|)
block|;
name|virtual
operator|~
name|MipsTargetMachine
argument_list|()
block|{}
name|void
name|addAnalysisPasses
argument_list|(
argument|PassManagerBase&PM
argument_list|)
name|override
block|;
specifier|const
name|MipsInstrInfo
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
name|TargetFrameLowering
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
specifier|const
name|MipsSubtarget
operator|*
name|getSubtargetImpl
argument_list|()
specifier|const
name|override
block|{
if|if
condition|(
name|Subtarget
condition|)
return|return
name|Subtarget
return|;
return|return
operator|&
name|DefaultSubtarget
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
name|Subtarget
operator|->
name|inMips16Mode
argument_list|()
operator|?
name|nullptr
operator|:
operator|&
name|getSubtargetImpl
argument_list|()
operator|->
name|getInstrItineraryData
argument_list|()
return|;
block|}
name|MipsJITInfo
modifier|*
name|getJITInfo
parameter_list|()
function|override
block|{
return|return
name|Subtarget
operator|->
name|getJITInfo
argument_list|()
return|;
block|}
specifier|const
name|MipsRegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
name|override
block|{
return|return
name|getSubtargetImpl
argument_list|()
operator|->
name|getRegisterInfo
argument_list|()
return|;
block|}
specifier|const
name|MipsTargetLowering
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
name|MipsSelectionDAGInfo
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
comment|/// \brief Reset the subtarget for the Mips target.
name|void
name|resetSubtarget
parameter_list|(
name|MachineFunction
modifier|*
name|MF
parameter_list|)
function_decl|;
comment|// Pass Pipeline Configuration
name|TargetPassConfig
modifier|*
name|createPassConfig
argument_list|(
name|PassManagerBase
operator|&
name|PM
argument_list|)
name|override
decl_stmt|;
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
name|override
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// MipsebTargetMachine - Mips32/64 big endian target machine.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|MipsebTargetMachine
range|:
name|public
name|MipsTargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|MipsebTargetMachine
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
end_decl_stmt

begin_comment
comment|/// MipselTargetMachine - Mips32/64 little endian target machine.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|MipselTargetMachine
range|:
name|public
name|MipsTargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|MipselTargetMachine
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
end_decl_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

