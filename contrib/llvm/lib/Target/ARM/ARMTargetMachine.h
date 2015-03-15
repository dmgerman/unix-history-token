begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMTargetMachine.h - Define TargetMachine for ARM -------*- C++ -*-===//
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
comment|// This file declares the ARM specific subclass of TargetMachine.
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
name|LLVM_LIB_TARGET_ARM_ARMTARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_ARMTARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"ARMInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"ARMSubtarget.h"
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
name|class
name|ARMBaseTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|public
operator|:
expr|enum
name|ARMABI
block|{
name|ARM_ABI_UNKNOWN
block|,
name|ARM_ABI_APCS
block|,
name|ARM_ABI_AAPCS
comment|// ARM EABI
block|}
name|TargetABI
block|;
name|protected
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|TargetLoweringObjectFile
operator|>
name|TLOF
block|;
name|ARMSubtarget
name|Subtarget
block|;
name|bool
name|isLittle
block|;
name|mutable
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ARMSubtarget
operator|>>
name|SubtargetMap
block|;
name|public
operator|:
name|ARMBaseTargetMachine
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
operator|~
name|ARMBaseTargetMachine
argument_list|()
name|override
block|;
specifier|const
name|ARMSubtarget
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
name|ARMSubtarget
operator|*
name|getSubtargetImpl
argument_list|(
argument|const Function&F
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Register ARM analysis passes with a pass manager.
name|void
name|addAnalysisPasses
argument_list|(
argument|PassManagerBase&PM
argument_list|)
name|override
block|;
comment|// Pass Pipeline Configuration
name|TargetPassConfig
operator|*
name|createPassConfig
argument_list|(
argument|PassManagerBase&PM
argument_list|)
name|override
block|;
name|TargetLoweringObjectFile
operator|*
name|getObjFileLowering
argument_list|()
specifier|const
name|override
block|{
return|return
name|TLOF
operator|.
name|get
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// ARMTargetMachine - ARM target machine.
comment|///
name|class
name|ARMTargetMachine
operator|:
name|public
name|ARMBaseTargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|ARMTargetMachine
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
block|; }
block|;
comment|/// ARMLETargetMachine - ARM little endian target machine.
comment|///
name|class
name|ARMLETargetMachine
operator|:
name|public
name|ARMTargetMachine
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|ARMLETargetMachine
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
block|;
comment|/// ARMBETargetMachine - ARM big endian target machine.
comment|///
name|class
name|ARMBETargetMachine
operator|:
name|public
name|ARMTargetMachine
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|ARMBETargetMachine
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
block|;
comment|/// ThumbTargetMachine - Thumb target machine.
comment|/// Due to the way architectures are handled, this represents both
comment|///   Thumb-1 and Thumb-2.
comment|///
name|class
name|ThumbTargetMachine
operator|:
name|public
name|ARMBaseTargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|ThumbTargetMachine
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
block|; }
block|;
comment|/// ThumbLETargetMachine - Thumb little endian target machine.
comment|///
name|class
name|ThumbLETargetMachine
operator|:
name|public
name|ThumbTargetMachine
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|ThumbLETargetMachine
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
block|;
comment|/// ThumbBETargetMachine - Thumb big endian target machine.
comment|///
name|class
name|ThumbBETargetMachine
operator|:
name|public
name|ThumbTargetMachine
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
name|public
operator|:
name|ThumbBETargetMachine
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
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

