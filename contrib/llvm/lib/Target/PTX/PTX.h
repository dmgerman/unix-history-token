begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PTX.h - Top-level interface for PTX representation ------*- C++ -*-===//
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
comment|// PTX back-end.
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
name|PTX_H
end_ifndef

begin_define
define|#
directive|define
name|PTX_H
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
name|PTXTargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|namespace
name|PTX
block|{
enum|enum
name|StateSpace
block|{
name|GLOBAL
init|=
literal|0
block|,
comment|// default to global state space
name|CONSTANT
init|=
literal|1
block|,
name|LOCAL
init|=
literal|2
block|,
name|PARAMETER
init|=
literal|3
block|,
name|SHARED
init|=
literal|4
block|}
enum|;
enum|enum
name|Predicate
block|{
name|PRED_NORMAL
init|=
literal|0
block|,
name|PRED_NEGATE
init|=
literal|1
block|}
enum|;
block|}
comment|// namespace PTX
name|FunctionPass
modifier|*
name|createPTXISelDag
argument_list|(
name|PTXTargetMachine
operator|&
name|TM
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
name|FunctionPass
modifier|*
name|createPTXMFInfoExtract
argument_list|(
name|PTXTargetMachine
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
name|ThePTX32Target
decl_stmt|;
specifier|extern
name|Target
name|ThePTX64Target
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm;
end_comment

begin_comment
comment|// Defines symbolic names for PTX registers.
end_comment

begin_include
include|#
directive|include
file|"PTXGenRegisterNames.inc"
end_include

begin_comment
comment|// Defines symbolic names for the PTX instructions.
end_comment

begin_include
include|#
directive|include
file|"PTXGenInstrNames.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PTX_H
end_comment

end_unit

