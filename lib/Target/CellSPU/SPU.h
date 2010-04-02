begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SPU.h - Top-level interface for Cell SPU Target ----------*- C++ -*-==//
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
comment|// Cell SPU back-end.
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
name|LLVM_TARGET_IBMCELLSPU_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_IBMCELLSPU_H
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
name|SPUTargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|FunctionPass
modifier|*
name|createSPUISelDag
parameter_list|(
name|SPUTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
specifier|extern
name|Target
name|TheCellSPUTarget
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Defines symbolic names for the SPU instructions.
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|"SPUGenInstrNames.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_TARGET_IBMCELLSPU_H */
end_comment

end_unit

