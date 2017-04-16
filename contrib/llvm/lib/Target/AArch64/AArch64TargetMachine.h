begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- AArch64TargetMachine.h - Define TargetMachine for AArch64 -*- C++ -*-==//
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
comment|// This file declares the AArch64 specific subclass of TargetMachine.
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
name|LLVM_LIB_TARGET_AARCH64_AARCH64TARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AARCH64_AARCH64TARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"AArch64InstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"AArch64Subtarget.h"
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
name|AArch64RegisterBankInfo
decl_stmt|;
name|class
name|AArch64TargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
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
name|mutable
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|AArch64Subtarget
operator|>>
name|SubtargetMap
block|;
name|public
operator|:
name|AArch64TargetMachine
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
argument|bool IsLittleEndian
argument_list|)
block|;
operator|~
name|AArch64TargetMachine
argument_list|()
name|override
block|;
specifier|const
name|AArch64Subtarget
operator|*
name|getSubtargetImpl
argument_list|(
argument|const Function&F
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
comment|/// \brief Get the TargetIRAnalysis for this target.
name|TargetIRAnalysis
name|getTargetIRAnalysis
argument_list|()
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
name|private
operator|:
name|bool
name|isLittle
block|; }
decl_stmt|;
comment|// AArch64 little endian target machine.
comment|//
name|class
name|AArch64leTargetMachine
range|:
name|public
name|AArch64TargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|AArch64leTargetMachine
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
decl_stmt|;
comment|// AArch64 big endian target machine.
comment|//
name|class
name|AArch64beTargetMachine
range|:
name|public
name|AArch64TargetMachine
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|AArch64beTargetMachine
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

