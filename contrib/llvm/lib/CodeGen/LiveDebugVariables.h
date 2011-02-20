begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LiveDebugVariables.h - Tracking debug info variables ----*- c++ -*--===//
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
comment|// This file provides the interface to the LiveDebugVariables analysis.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The analysis removes DBG_VALUE instructions for virtual registers and tracks
end_comment

begin_comment
comment|// live user variables in a data structure that can be updated during register
end_comment

begin_comment
comment|// allocation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// After register allocation new DBG_VALUE instructions are emitted to reflect
end_comment

begin_comment
comment|// the new locations of user variables.
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
name|LLVM_CODEGEN_LIVEDEBUGVARIABLES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LIVEDEBUGVARIABLES_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|VirtRegMap
decl_stmt|;
name|class
name|LiveDebugVariables
range|:
name|public
name|MachineFunctionPass
block|{
name|void
operator|*
name|pImpl
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|LiveDebugVariables
argument_list|()
block|;
operator|~
name|LiveDebugVariables
argument_list|()
block|;
comment|/// renameRegister - Move any user variables in OldReg to NewReg:SubIdx.
comment|/// @param OldReg Old virtual register that is going away.
comment|/// @param NewReg New register holding the user variables.
comment|/// @param SubIdx If NewReg is a virtual register, SubIdx may indicate a sub-
comment|///               register.
name|void
name|renameRegister
argument_list|(
argument|unsigned OldReg
argument_list|,
argument|unsigned NewReg
argument_list|,
argument|unsigned SubIdx
argument_list|)
block|;
comment|/// emitDebugValues - Emit new DBG_VALUE instructions reflecting the changes
comment|/// that happened during register allocation.
comment|/// @param VRM Rename virtual registers according to map.
name|void
name|emitDebugValues
argument_list|(
name|VirtRegMap
operator|*
name|VRM
argument_list|)
block|;
comment|/// dump - Print data structures to dbgs().
name|void
name|dump
argument_list|()
block|;
name|private
operator|:
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
argument_list|)
block|;
name|virtual
name|void
name|releaseMemory
argument_list|()
block|;
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&
argument_list|)
specifier|const
block|;  }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_LIVEDEBUGVARIABLES_H
end_comment

end_unit

