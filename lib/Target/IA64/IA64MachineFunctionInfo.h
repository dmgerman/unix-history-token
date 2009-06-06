begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IA64MachineFunctionInfo.h - IA64-specific information ---*- C++ -*-===//
end_comment

begin_comment
comment|//===--                   for MachineFunction                 ---*- C++ -*-===//
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
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file declares IA64-specific per-machine-function information.
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
name|IA64MACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|IA64MACHINEFUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_comment
comment|//#include "IA64JITInfo.h"
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|IA64FunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
name|public
operator|:
name|unsigned
name|outRegsUsed
block|;
comment|// how many 'out' registers are used
comment|// by this machinefunction? (used to compute the appropriate
comment|// entry in the 'alloc' instruction at the top of the
comment|// machinefunction)
name|explicit
name|IA64FunctionInfo
argument_list|(
argument|MachineFunction& MF
argument_list|)
block|{
name|outRegsUsed
operator|=
literal|0
block|; }
block|;  }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

