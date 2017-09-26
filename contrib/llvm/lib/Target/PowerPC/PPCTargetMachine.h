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
name|LLVM_LIB_TARGET_POWERPC_PPCTARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_POWERPC_PPCTARGETMACHINE_H
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
comment|/// Common code between 32-bit and 64-bit PowerPC targets.
comment|///
name|class
name|PPCTargetMachine
name|final
range|:
name|public
name|LLVMTargetMachine
block|{
name|public
operator|:
expr|enum
name|PPCABI
block|{
name|PPC_ABI_UNKNOWN
block|,
name|PPC_ABI_ELFv1
block|,
name|PPC_ABI_ELFv2
block|}
block|;
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|TargetLoweringObjectFile
operator|>
name|TLOF
block|;
name|PPCABI
name|TargetABI
block|;
name|mutable
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|PPCSubtarget
operator|>>
name|SubtargetMap
block|;
name|public
operator|:
name|PPCTargetMachine
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
block|;
operator|~
name|PPCTargetMachine
argument_list|()
name|override
block|;
specifier|const
name|PPCSubtarget
operator|*
name|getSubtargetImpl
argument_list|(
argument|const Function&F
argument_list|)
specifier|const
name|override
block|;
comment|// The no argument getSubtargetImpl, while it exists on some targets, is
comment|// deprecated and should not be used.
specifier|const
name|PPCSubtarget
operator|*
name|getSubtargetImpl
argument_list|()
specifier|const
operator|=
name|delete
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
name|bool
name|isELFv2ABI
argument_list|()
specifier|const
block|{
return|return
name|TargetABI
operator|==
name|PPC_ABI_ELFv2
return|;
block|}
name|bool
name|isPPC64
argument_list|()
specifier|const
block|{
specifier|const
name|Triple
operator|&
name|TT
operator|=
name|getTargetTriple
argument_list|()
block|;
return|return
operator|(
name|TT
operator|.
name|getArch
argument_list|()
operator|==
name|Triple
operator|::
name|ppc64
operator|||
name|TT
operator|.
name|getArch
argument_list|()
operator|==
name|Triple
operator|::
name|ppc64le
operator|)
return|;
block|}
block|;
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
block|; }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

