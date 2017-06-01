begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AVRTargetMachine.h - Define TargetMachine for AVR -------*- C++ -*-===//
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
comment|// This file declares the AVR specific subclass of TargetMachine.
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
name|LLVM_AVR_TARGET_MACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AVR_TARGET_MACHINE_H
end_define

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

begin_include
include|#
directive|include
file|"AVRFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"AVRISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"AVRInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"AVRSelectionDAGInfo.h"
end_include

begin_include
include|#
directive|include
file|"AVRSubtarget.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A generic AVR implementation.
name|class
name|AVRTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|public
operator|:
name|AVRTargetMachine
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
specifier|const
name|AVRSubtarget
operator|*
name|getSubtargetImpl
argument_list|()
specifier|const
block|;
specifier|const
name|AVRSubtarget
operator|*
name|getSubtargetImpl
argument_list|(
argument|const Function&
argument_list|)
specifier|const
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
name|this
operator|->
name|TLOF
operator|.
name|get
argument_list|()
return|;
block|}
name|TargetPassConfig
operator|*
name|createPassConfig
argument_list|(
argument|PassManagerBase&PM
argument_list|)
name|override
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
name|AVRSubtarget
name|SubTarget
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

begin_comment
comment|// LLVM_AVR_TARGET_MACHINE_H
end_comment

end_unit

