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
file|"MCTargetDesc/XCoreMCTargetDesc.h"
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
name|FunctionPass
decl_stmt|;
name|class
name|ModulePass
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
name|void
name|initializeXCoreLowerThreadLocalPass
parameter_list|(
name|PassRegistry
modifier|&
name|p
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createXCoreISelDag
argument_list|(
name|XCoreTargetMachine
operator|&
name|TM
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
name|ModulePass
modifier|*
name|createXCoreLowerThreadLocalPass
parameter_list|()
function_decl|;
name|ImmutablePass
modifier|*
name|createXCoreTargetTransformInfoPass
parameter_list|(
specifier|const
name|XCoreTargetMachine
modifier|*
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

