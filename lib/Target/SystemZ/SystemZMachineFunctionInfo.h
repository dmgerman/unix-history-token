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
name|class
name|SystemZMachineFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|unsigned
name|LowSavedGPR
block|;
name|unsigned
name|HighSavedGPR
block|;
name|unsigned
name|VarArgsFirstGPR
block|;
name|unsigned
name|VarArgsFirstFPR
block|;
name|unsigned
name|VarArgsFrameIndex
block|;
name|unsigned
name|RegSaveFrameIndex
block|;
name|bool
name|ManipulatesSP
block|;
name|public
operator|:
name|explicit
name|SystemZMachineFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|LowSavedGPR
argument_list|(
literal|0
argument_list|)
block|,
name|HighSavedGPR
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsFirstGPR
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsFirstFPR
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsFrameIndex
argument_list|(
literal|0
argument_list|)
block|,
name|RegSaveFrameIndex
argument_list|(
literal|0
argument_list|)
block|,
name|ManipulatesSP
argument_list|(
argument|false
argument_list|)
block|{}
comment|// Get and set the first call-saved GPR that should be saved and restored
comment|// by this function.  This is 0 if no GPRs need to be saved or restored.
name|unsigned
name|getLowSavedGPR
argument_list|()
specifier|const
block|{
return|return
name|LowSavedGPR
return|;
block|}
name|void
name|setLowSavedGPR
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|LowSavedGPR
operator|=
name|Reg
block|; }
comment|// Get and set the last call-saved GPR that should be saved and restored
comment|// by this function.
name|unsigned
name|getHighSavedGPR
argument_list|()
specifier|const
block|{
return|return
name|HighSavedGPR
return|;
block|}
name|void
name|setHighSavedGPR
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|HighSavedGPR
operator|=
name|Reg
block|; }
comment|// Get and set the number of fixed (as opposed to variable) arguments
comment|// that are passed in GPRs to this function.
name|unsigned
name|getVarArgsFirstGPR
argument_list|()
specifier|const
block|{
return|return
name|VarArgsFirstGPR
return|;
block|}
name|void
name|setVarArgsFirstGPR
argument_list|(
argument|unsigned GPR
argument_list|)
block|{
name|VarArgsFirstGPR
operator|=
name|GPR
block|; }
comment|// Likewise FPRs.
name|unsigned
name|getVarArgsFirstFPR
argument_list|()
specifier|const
block|{
return|return
name|VarArgsFirstFPR
return|;
block|}
name|void
name|setVarArgsFirstFPR
argument_list|(
argument|unsigned FPR
argument_list|)
block|{
name|VarArgsFirstFPR
operator|=
name|FPR
block|; }
comment|// Get and set the frame index of the first stack vararg.
name|unsigned
name|getVarArgsFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|VarArgsFrameIndex
return|;
block|}
name|void
name|setVarArgsFrameIndex
argument_list|(
argument|unsigned FI
argument_list|)
block|{
name|VarArgsFrameIndex
operator|=
name|FI
block|; }
comment|// Get and set the frame index of the register save area
comment|// (i.e. the incoming stack pointer).
name|unsigned
name|getRegSaveFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|RegSaveFrameIndex
return|;
block|}
name|void
name|setRegSaveFrameIndex
argument_list|(
argument|unsigned FI
argument_list|)
block|{
name|RegSaveFrameIndex
operator|=
name|FI
block|; }
comment|// Get and set whether the function directly manipulates the stack pointer,
comment|// e.g. through STACKSAVE or STACKRESTORE.
name|bool
name|getManipulatesSP
argument_list|()
specifier|const
block|{
return|return
name|ManipulatesSP
return|;
block|}
name|void
name|setManipulatesSP
argument_list|(
argument|bool MSP
argument_list|)
block|{
name|ManipulatesSP
operator|=
name|MSP
block|; }
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

