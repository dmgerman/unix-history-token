begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SparcMachineFunctionInfo.h - Sparc Machine Function Info -*- C++ -*-===//
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
comment|// This file declares  Sparc specific per-machine-function information.
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
name|SPARCMACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|SPARCMACHINEFUNCTIONINFO_H
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
name|SparcMachineFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
name|private
operator|:
name|unsigned
name|GlobalBaseReg
block|;
name|public
operator|:
name|SparcMachineFunctionInfo
argument_list|()
operator|:
name|GlobalBaseReg
argument_list|(
literal|0
argument_list|)
block|{}
name|SparcMachineFunctionInfo
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
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

