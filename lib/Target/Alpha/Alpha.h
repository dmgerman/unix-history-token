begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Alpha.h - Top-level interface for Alpha representation --*- C++ -*-===//
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
comment|// Alpha back-end.
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
name|TARGET_ALPHA_H
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ALPHA_H
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
name|AlphaTargetMachine
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
name|createAlphaISelDag
parameter_list|(
name|AlphaTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createAlphaPatternInstructionSelector
parameter_list|(
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createAlphaCodeEmitterPass
parameter_list|(
name|AlphaTargetMachine
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
name|createAlphaJITCodeEmitterPass
parameter_list|(
name|AlphaTargetMachine
modifier|&
name|TM
parameter_list|,
name|JITCodeEmitter
modifier|&
name|JCE
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createAlphaObjectCodeEmitterPass
parameter_list|(
name|AlphaTargetMachine
modifier|&
name|TM
parameter_list|,
name|ObjectCodeEmitter
modifier|&
name|OCE
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createAlphaLLRPPass
parameter_list|(
name|AlphaTargetMachine
modifier|&
name|tm
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createAlphaBranchSelectionPass
parameter_list|()
function_decl|;
specifier|extern
name|Target
name|TheAlphaTarget
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_comment
comment|// Defines symbolic names for Alpha registers.  This defines a mapping from
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
file|"AlphaGenRegisterNames.inc"
end_include

begin_comment
comment|// Defines symbolic names for the Alpha instructions.
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|"AlphaGenInstrNames.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

