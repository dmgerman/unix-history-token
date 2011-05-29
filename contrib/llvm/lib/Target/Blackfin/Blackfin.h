begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== Blackfin.h - Top-level interface for Blackfin backend -----*- C++ -*-===//
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
comment|// Blackfin back-end.
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
name|TARGET_BLACKFIN_H
end_ifndef

begin_define
define|#
directive|define
name|TARGET_BLACKFIN_H
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
name|FunctionPass
decl_stmt|;
name|class
name|BlackfinTargetMachine
decl_stmt|;
name|FunctionPass
modifier|*
name|createBlackfinISelDag
argument_list|(
name|BlackfinTargetMachine
operator|&
name|TM
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
specifier|extern
name|Target
name|TheBlackfinTarget
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_comment
comment|// Defines symbolic names for Blackfin registers.  This defines a mapping from
end_comment

begin_comment
comment|// register name to register number.
end_comment

begin_include
include|#
directive|include
file|"BlackfinGenRegisterNames.inc"
end_include

begin_comment
comment|// Defines symbolic names for the Blackfin instructions.
end_comment

begin_include
include|#
directive|include
file|"BlackfinGenInstrNames.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

