begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPC.h - Top-level interface for PowerPC Target ----------*- C++ -*-===//
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
comment|// This file contains the entry points for global functions defined in the LLVM
end_comment

begin_comment
comment|// PowerPC back-end.
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
name|LLVM_TARGET_POWERPC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_POWERPC_H
end_define

begin_comment
comment|// GCC #defines PPC on Linux but we use it as our namespace name
end_comment

begin_undef
undef|#
directive|undef
name|PPC
end_undef

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PPCTargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|MachineCodeEmitter
decl_stmt|;
name|class
name|ObjectCodeEmitter
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|FunctionPass
modifier|*
name|createPPCBranchSelectionPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPPCISelDag
parameter_list|(
name|PPCTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createPPCCodeEmitterPass
parameter_list|(
name|PPCTargetMachine
modifier|&
name|TM
parameter_list|,
name|MachineCodeEmitter
modifier|&
name|MCE
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createPPCJITCodeEmitterPass
parameter_list|(
name|PPCTargetMachine
modifier|&
name|TM
parameter_list|,
name|JITCodeEmitter
modifier|&
name|MCE
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createPPCObjectCodeEmitterPass
parameter_list|(
name|PPCTargetMachine
modifier|&
name|TM
parameter_list|,
name|ObjectCodeEmitter
modifier|&
name|OCE
parameter_list|)
function_decl|;
specifier|extern
name|Target
name|ThePPC32Target
decl_stmt|;
specifier|extern
name|Target
name|ThePPC64Target
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_comment
comment|// Defines symbolic names for PowerPC registers.  This defines a mapping from
end_comment

begin_comment
comment|// register name to register number.
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|"PPCGenRegisterNames.inc"
end_include

begin_comment
comment|// Defines symbolic names for the PowerPC instructions.
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|"PPCGenInstrNames.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

