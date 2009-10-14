begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SPUTargetMachine.h - Define TargetMachine for Cell SPU ----*- C++ -*-=//
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
comment|// This file declares the CellSPU-specific subclass of TargetMachine.
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
name|SPU_TARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|SPU_TARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"SPUSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"SPUInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"SPUISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"SPUFrameInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetData.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PassManager
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|TargetFrameInfo
decl_stmt|;
comment|/// SPUTargetMachine
comment|///
name|class
name|SPUTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
name|SPUSubtarget
name|Subtarget
block|;
specifier|const
name|TargetData
name|DataLayout
block|;
name|SPUInstrInfo
name|InstrInfo
block|;
name|SPUFrameInfo
name|FrameInfo
block|;
name|SPUTargetLowering
name|TLInfo
block|;
name|InstrItineraryData
name|InstrItins
block|;
name|public
operator|:
name|SPUTargetMachine
argument_list|(
specifier|const
name|Target
operator|&
name|T
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|TT
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|FS
argument_list|)
block|;
comment|/// Return the subtarget implementation object
name|virtual
specifier|const
name|SPUSubtarget
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
name|SPUInstrInfo
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
specifier|const
name|SPUFrameInfo
operator|*
name|getFrameInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|FrameInfo
return|;
block|}
comment|/*!     \note Cell SPU does not support JIT today. It could support JIT at some     point.    */
name|virtual
name|TargetJITInfo
operator|*
name|getJITInfo
argument_list|()
block|{
return|return
name|NULL
return|;
block|}
name|virtual
name|SPUTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|SPUTargetLowering
operator|*
operator|>
operator|(
operator|&
name|TLInfo
operator|)
return|;
block|}
name|virtual
specifier|const
name|SPURegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|InstrInfo
operator|.
name|getRegisterInfo
argument_list|()
return|;
block|}
name|virtual
specifier|const
name|TargetData
operator|*
name|getTargetData
argument_list|()
specifier|const
block|{
return|return
operator|&
name|DataLayout
return|;
block|}
name|virtual
specifier|const
name|InstrItineraryData
name|getInstrItineraryData
argument_list|()
specifier|const
block|{
return|return
name|InstrItins
return|;
block|}
comment|// Pass Pipeline Configuration
name|virtual
name|bool
name|addInstSelector
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|CodeGenOpt::Level OptLevel
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

