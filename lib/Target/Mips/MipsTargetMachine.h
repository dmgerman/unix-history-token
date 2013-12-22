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
file|"MipsFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"MipsISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"MipsInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"MipsJITInfo.h"
end_include

begin_include
include|#
directive|include
file|"MipsSelectionDAGInfo.h"
end_include

begin_include
include|#
directive|include
file|"MipsSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
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
name|Subtarget
block|;
specifier|const
name|DataLayout
name|DL
block|;
comment|// Calculates type size& alignment
name|OwningPtr
operator|<
specifier|const
name|MipsInstrInfo
operator|>
name|InstrInfo
block|;
name|OwningPtr
operator|<
specifier|const
name|MipsFrameLowering
operator|>
name|FrameLowering
block|;
name|OwningPtr
operator|<
specifier|const
name|MipsTargetLowering
operator|>
name|TLInfo
block|;
name|OwningPtr
operator|<
specifier|const
name|MipsInstrInfo
operator|>
name|InstrInfo16
block|;
name|OwningPtr
operator|<
specifier|const
name|MipsFrameLowering
operator|>
name|FrameLowering16
block|;
name|OwningPtr
operator|<
specifier|const
name|MipsTargetLowering
operator|>
name|TLInfo16
block|;
name|OwningPtr
operator|<
specifier|const
name|MipsInstrInfo
operator|>
name|InstrInfoSE
block|;
name|OwningPtr
operator|<
specifier|const
name|MipsFrameLowering
operator|>
name|FrameLoweringSE
block|;
name|OwningPtr
operator|<
specifier|const
name|MipsTargetLowering
operator|>
name|TLInfoSE
block|;
name|MipsSelectionDAGInfo
name|TSInfo
block|;
specifier|const
name|InstrItineraryData
operator|&
name|InstrItins
block|;
name|MipsJITInfo
name|JITInfo
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
name|virtual
name|void
name|addAnalysisPasses
argument_list|(
name|PassManagerBase
operator|&
name|PM
argument_list|)
block|;
name|virtual
specifier|const
name|MipsInstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
block|{
return|return
name|InstrInfo
operator|.
name|get
argument_list|()
return|;
block|}
name|virtual
specifier|const
name|TargetFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
block|{
return|return
name|FrameLowering
operator|.
name|get
argument_list|()
return|;
block|}
name|virtual
specifier|const
name|MipsSubtarget
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
name|InstrItineraryData
operator|*
name|getInstrItineraryData
argument_list|()
specifier|const
block|{
return|return
name|Subtarget
operator|.
name|inMips16Mode
argument_list|()
operator|?
literal|0
operator|:
operator|&
name|InstrItins
return|;
block|}
name|virtual
name|MipsJITInfo
operator|*
name|getJITInfo
argument_list|()
block|{
return|return
operator|&
name|JITInfo
return|;
block|}
name|virtual
specifier|const
name|MipsRegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|InstrInfo
operator|->
name|getRegisterInfo
argument_list|()
return|;
block|}
name|virtual
specifier|const
name|MipsTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
name|TLInfo
operator|.
name|get
argument_list|()
return|;
block|}
name|virtual
specifier|const
name|MipsSelectionDAGInfo
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
comment|// Pass Pipeline Configuration
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
block|;
comment|// Set helper classes
name|void
name|setHelperClassesMips16
argument_list|()
block|;
name|void
name|setHelperClassesMipsSE
argument_list|()
block|;   }
decl_stmt|;
comment|/// MipsebTargetMachine - Mips32/64 big endian target machine.
comment|///
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
comment|/// MipselTargetMachine - Mips32/64 little endian target machine.
comment|///
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

