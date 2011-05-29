begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- XCore.h - Top-level interface for XCore representation --*- C++ -*-===//
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
comment|// XCore back-end.
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
name|TARGET_XCORE_H
end_ifndef

begin_define
define|#
directive|define
name|TARGET_XCORE_H
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
name|TargetMachine
decl_stmt|;
name|class
name|XCoreTargetMachine
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|FunctionPass
modifier|*
name|createXCoreISelDag
parameter_list|(
name|XCoreTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
specifier|extern
name|Target
name|TheXCoreTarget
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_comment
comment|// Defines symbolic names for XCore registers.  This defines a mapping from
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
file|"XCoreGenRegisterNames.inc"
end_include

begin_comment
comment|// Defines symbolic names for the XCore instructions.
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|"XCoreGenInstrNames.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

