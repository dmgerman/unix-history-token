begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BlackfinTargetMachine.h - TargetMachine for Blackfin ----*- C++ -*-===//
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
comment|// This file declares the Blackfin specific subclass of TargetMachine.
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
name|BLACKFINTARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|BLACKFINTARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"BlackfinInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"BlackfinIntrinsicInfo.h"
end_include

begin_include
include|#
directive|include
file|"BlackfinISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"BlackfinFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"BlackfinSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"BlackfinSelectionDAGInfo.h"
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

begin_include
include|#
directive|include
file|"llvm/Target/TargetFrameLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BlackfinTargetMachine
range|:
name|public
name|LLVMTargetMachine
block|{
specifier|const
name|TargetData
name|DataLayout
block|;
name|BlackfinSubtarget
name|Subtarget
block|;
name|BlackfinTargetLowering
name|TLInfo
block|;
name|BlackfinSelectionDAGInfo
name|TSInfo
block|;
name|BlackfinInstrInfo
name|InstrInfo
block|;
name|BlackfinFrameLowering
name|FrameLowering
block|;
name|BlackfinIntrinsicInfo
name|IntrinsicInfo
block|;
name|public
operator|:
name|BlackfinTargetMachine
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
name|CPU
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|FS
argument_list|)
block|;
name|virtual
specifier|const
name|BlackfinInstrInfo
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
specifier|const
name|BlackfinSubtarget
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
name|BlackfinRegisterInfo
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
name|BlackfinTargetLowering
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
name|BlackfinSelectionDAGInfo
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
name|bool
name|addInstSelector
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|)
block|;
specifier|const
name|TargetIntrinsicInfo
operator|*
name|getIntrinsicInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|IntrinsicInfo
return|;
block|}
expr|}
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

