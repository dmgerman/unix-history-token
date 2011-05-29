begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ProfilingUtils.h - Helper functions shared by profilers --*- C++ -*-===//
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
comment|// This file defines a few helper functions which are used by profile
end_comment

begin_comment
comment|// instrumentation code to instrument the code.  This allows the profiler pass
end_comment

begin_comment
comment|// to worry about *what* to insert, and these functions take care of *how* to do
end_comment

begin_comment
comment|// it.
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
name|PROFILINGUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|PROFILINGUTILS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|PointerType
decl_stmt|;
name|void
name|InsertProfilingInitCall
parameter_list|(
name|Function
modifier|*
name|MainFn
parameter_list|,
specifier|const
name|char
modifier|*
name|FnName
parameter_list|,
name|GlobalValue
modifier|*
name|Arr
init|=
literal|0
parameter_list|,
name|PointerType
modifier|*
name|arrayType
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|IncrementCounterInBlock
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|unsigned
name|CounterNum
parameter_list|,
name|GlobalValue
modifier|*
name|CounterArray
parameter_list|,
name|bool
name|beginning
init|=
name|true
parameter_list|)
function_decl|;
name|void
name|InsertProfilingShutdownCall
parameter_list|(
name|Function
modifier|*
name|Callee
parameter_list|,
name|Module
modifier|*
name|Mod
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

