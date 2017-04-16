begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- WebAssemblyUtilities - WebAssembly Utility Functions ---*- C++ -*-====//
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
comment|/// \brief This file contains the declaration of the WebAssembly-specific
end_comment

begin_comment
comment|/// utility functions.
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
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYUTILITIES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYUTILITIES_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineLoop
decl_stmt|;
name|class
name|WebAssemblyFunctionInfo
decl_stmt|;
name|namespace
name|WebAssembly
block|{
name|bool
name|isArgument
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
name|bool
name|isCopy
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
name|bool
name|isTee
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
name|bool
name|isChild
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|,
specifier|const
name|WebAssemblyFunctionInfo
modifier|&
name|MFI
parameter_list|)
function_decl|;
name|bool
name|isCallIndirect
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
block|}
comment|// end namespace WebAssembly
comment|/// Return the "bottom" block of a loop. This differs from
comment|/// MachineLoop::getBottomBlock in that it works even if the loop is
comment|/// discontiguous.
name|MachineBasicBlock
modifier|*
name|LoopBottom
parameter_list|(
specifier|const
name|MachineLoop
modifier|*
name|Loop
parameter_list|)
function_decl|;
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

