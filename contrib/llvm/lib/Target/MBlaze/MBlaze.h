begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MBlaze.h - Top-level interface for MBlaze ---------------*- C++ -*-===//
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
comment|// the LLVM MBlaze back-end.
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
name|TARGET_MBLAZE_H
end_ifndef

begin_define
define|#
directive|define
name|TARGET_MBLAZE_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/MBlazeBaseInfo.h"
end_include

begin_include
include|#
directive|include
file|"MCTargetDesc/MBlazeMCTargetDesc.h"
end_include

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
name|MBlazeTargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|MachineCodeEmitter
decl_stmt|;
name|FunctionPass
modifier|*
name|createMBlazeISelDag
parameter_list|(
name|MBlazeTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createMBlazeDelaySlotFillerPass
parameter_list|(
name|MBlazeTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

