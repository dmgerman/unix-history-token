begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- SystemZMachineFuctionInfo.h - SystemZ machine function info -*- C++ -*-=//
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
comment|// This file declares SystemZ-specific per-machine-function information.
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
name|SYSTEMZMACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|SYSTEMZMACHINEFUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// SystemZMachineFunctionInfo - This class is derived from MachineFunction and
comment|/// contains private SystemZ target-specific information for each MachineFunction.
name|class
name|SystemZMachineFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
comment|/// CalleeSavedFrameSize - Size of the callee-saved register portion of the
comment|/// stack frame in bytes.
name|unsigned
name|CalleeSavedFrameSize
block|;
comment|/// LowReg - Low register of range of callee-saved registers to store.
name|unsigned
name|LowReg
block|;
comment|/// HighReg - High register of range of callee-saved registers to store.
name|unsigned
name|HighReg
block|;
name|public
operator|:
name|SystemZMachineFunctionInfo
argument_list|()
operator|:
name|CalleeSavedFrameSize
argument_list|(
literal|0
argument_list|)
block|{}
name|SystemZMachineFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|CalleeSavedFrameSize
argument_list|(
literal|0
argument_list|)
block|{}
name|unsigned
name|getCalleeSavedFrameSize
argument_list|()
specifier|const
block|{
return|return
name|CalleeSavedFrameSize
return|;
block|}
name|void
name|setCalleeSavedFrameSize
argument_list|(
argument|unsigned bytes
argument_list|)
block|{
name|CalleeSavedFrameSize
operator|=
name|bytes
block|; }
name|unsigned
name|getLowReg
argument_list|()
specifier|const
block|{
return|return
name|LowReg
return|;
block|}
name|void
name|setLowReg
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|LowReg
operator|=
name|Reg
block|; }
name|unsigned
name|getHighReg
argument_list|()
specifier|const
block|{
return|return
name|HighReg
return|;
block|}
name|void
name|setHighReg
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|HighReg
operator|=
name|Reg
block|; }
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

