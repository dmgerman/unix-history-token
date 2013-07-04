begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- R600MachineFunctionInfo.h - R600 Machine Function Info ----*- C++ -*-=//
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
comment|/// \file
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMDGPUMACHINEFUNCTION_H
end_ifndef

begin_define
define|#
directive|define
name|AMDGPUMACHINEFUNCTION_H
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
name|AMDGPUMachineFunction
range|:
name|public
name|MachineFunctionInfo
block|{
name|private
operator|:
specifier|static
specifier|const
name|char
operator|*
name|ShaderTypeAttribute
block|;
name|public
operator|:
name|AMDGPUMachineFunction
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|unsigned
name|ShaderType
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// AMDGPUMACHINEFUNCTION_H
end_comment

end_unit

