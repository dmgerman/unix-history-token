begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SparcTargetMachine.h - Define TargetMachine for Sparc ---*- C++ -*-===//
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
comment|// This file declares the Sparc specific subclass of TargetMachine.
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
name|LLVM_LIB_TARGET_SPARC_SPARCTARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_SPARC_SPARCTARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"SparcInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"SparcSubtarget.h"
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
name|SparcTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|TargetLoweringObjectFile
operator|>
name|TLOF
block|;
name|SparcSubtarget
name|Subtarget
block|;
name|bool
name|is64Bit
block|;
name|mutable
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|SparcSubtarget
operator|>>
name|SubtargetMap
block|;
name|public
operator|:
name|SparcTargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Optional<Reloc::Model> RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|,
argument|bool is64bit
argument_list|)
block|;
operator|~
name|SparcTargetMachine
argument_list|()
name|override
block|;
specifier|const
name|SparcSubtarget
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
specifier|const
name|SparcSubtarget
operator|*
name|getSubtargetImpl
argument_list|(
argument|const Function&
argument_list|)
specifier|const
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
name|bool
name|isMachineVerifierClean
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
expr|}
block|;
comment|/// Sparc 32-bit target machine
comment|///
name|class
name|SparcV8TargetMachine
operator|:
name|public
name|SparcTargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|SparcV8TargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Optional<Reloc::Model> RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|)
block|; }
block|;
comment|/// Sparc 64-bit target machine
comment|///
name|class
name|SparcV9TargetMachine
operator|:
name|public
name|SparcTargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|SparcV9TargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Optional<Reloc::Model> RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|)
block|; }
block|;
name|class
name|SparcelTargetMachine
operator|:
name|public
name|SparcTargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|SparcelTargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|const Triple&TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Optional<Reloc::Model> RM
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

