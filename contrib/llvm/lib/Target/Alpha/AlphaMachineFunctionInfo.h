begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//====- AlphaMachineFuctionInfo.h - Alpha machine function info -*- C++ -*-===//
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
comment|// This file declares Alpha-specific per-machine-function information.
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
name|ALPHAMACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|ALPHAMACHINEFUNCTIONINFO_H
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
comment|/// AlphaMachineFunctionInfo - This class is derived from MachineFunction
comment|/// private Alpha target-specific information for each MachineFunction.
name|class
name|AlphaMachineFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
comment|/// GlobalBaseReg - keeps track of the virtual register initialized for
comment|/// use as the global base register. This is used for PIC in some PIC
comment|/// relocation models.
name|unsigned
name|GlobalBaseReg
block|;
comment|/// GlobalRetAddr = keeps track of the virtual register initialized for
comment|/// the return address value.
name|unsigned
name|GlobalRetAddr
block|;
comment|/// VarArgsOffset - What is the offset to the first vaarg
name|int
name|VarArgsOffset
block|;
comment|/// VarArgsBase - What is the base FrameIndex
name|int
name|VarArgsBase
block|;
name|public
operator|:
name|AlphaMachineFunctionInfo
argument_list|()
operator|:
name|GlobalBaseReg
argument_list|(
literal|0
argument_list|)
block|,
name|GlobalRetAddr
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsOffset
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsBase
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|AlphaMachineFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|GlobalBaseReg
argument_list|(
literal|0
argument_list|)
block|,
name|GlobalRetAddr
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsOffset
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsBase
argument_list|(
literal|0
argument_list|)
block|{}
name|unsigned
name|getGlobalBaseReg
argument_list|()
specifier|const
block|{
return|return
name|GlobalBaseReg
return|;
block|}
name|void
name|setGlobalBaseReg
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|GlobalBaseReg
operator|=
name|Reg
block|; }
name|unsigned
name|getGlobalRetAddr
argument_list|()
specifier|const
block|{
return|return
name|GlobalRetAddr
return|;
block|}
name|void
name|setGlobalRetAddr
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|GlobalRetAddr
operator|=
name|Reg
block|; }
name|int
name|getVarArgsOffset
argument_list|()
specifier|const
block|{
return|return
name|VarArgsOffset
return|;
block|}
name|void
name|setVarArgsOffset
argument_list|(
argument|int Offset
argument_list|)
block|{
name|VarArgsOffset
operator|=
name|Offset
block|; }
name|int
name|getVarArgsBase
argument_list|()
specifier|const
block|{
return|return
name|VarArgsBase
return|;
block|}
name|void
name|setVarArgsBase
argument_list|(
argument|int Base
argument_list|)
block|{
name|VarArgsBase
operator|=
name|Base
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

