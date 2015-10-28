begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// WebAssemblyMachineFuctionInfo.h-WebAssembly machine function info -*- C++ -*-
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file declares WebAssembly-specific per-machine-function
end_comment

begin_comment
comment|/// information.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYMACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYMACHINEFUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"WebAssemblyRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// This class is derived from MachineFunctionInfo and contains private
comment|/// WebAssembly-specific information for each MachineFunction.
name|class
name|WebAssemblyFunctionInfo
name|final
range|:
name|public
name|MachineFunctionInfo
block|{
name|MachineFunction
operator|&
name|MF
block|;
name|public
operator|:
name|explicit
name|WebAssemblyFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|MF
argument_list|(
argument|MF
argument_list|)
block|{}
operator|~
name|WebAssemblyFunctionInfo
argument_list|()
name|override
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

