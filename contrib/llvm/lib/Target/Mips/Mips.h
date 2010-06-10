begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Mips.h - Top-level interface for Mips representation ----*- C++ -*-===//
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
comment|// This file contains the entry points for global functions defined in
end_comment

begin_comment
comment|// the LLVM Mips back-end.
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
name|TARGET_MIPS_H
end_ifndef

begin_define
define|#
directive|define
name|TARGET_MIPS_H
end_define

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
name|MipsTargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|MachineCodeEmitter
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|FunctionPass
modifier|*
name|createMipsISelDag
parameter_list|(
name|MipsTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createMipsDelaySlotFillerPass
parameter_list|(
name|MipsTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
specifier|extern
name|Target
name|TheMipsTarget
decl_stmt|;
specifier|extern
name|Target
name|TheMipselTarget
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_comment
comment|// Defines symbolic names for Mips registers.  This defines a mapping from
end_comment

begin_comment
comment|// register name to register number.
end_comment

begin_include
include|#
directive|include
file|"MipsGenRegisterNames.inc"
end_include

begin_comment
comment|// Defines symbolic names for the Mips instructions.
end_comment

begin_include
include|#
directive|include
file|"MipsGenInstrNames.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

