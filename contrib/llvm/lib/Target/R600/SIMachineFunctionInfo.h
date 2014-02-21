begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SIMachineFunctionInfo.h - SIMachineFunctionInfo interface -*- C++ -*-==//
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
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIMACHINEFUNCTIONINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|SIMACHINEFUNCTIONINFO_H_
end_define

begin_include
include|#
directive|include
file|"AMDGPUMachineFunction.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// This class keeps track of the SPI_SP_INPUT_ADDR config register, which
comment|/// tells the hardware which interpolation parameters to load.
name|class
name|SIMachineFunctionInfo
range|:
name|public
name|AMDGPUMachineFunction
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|SIMachineFunctionInfo
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|unsigned
name|PSInputAddr
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//_SIMACHINEFUNCTIONINFO_H_
end_comment

end_unit

