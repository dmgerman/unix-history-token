begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ExecutionContextScope.h ---------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_ExecutionContextScope_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ExecutionContextScope_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ExecutionContextScope ExecutionContextScope.h "lldb/Symbol/ExecutionContextScope.h"
comment|/// @brief Inherit from this if your object can reconstruct its
comment|///        execution context.
comment|///
comment|/// Many objects that have pointers back to parent execution context
comment|/// objects can inherit from this pure virtual class can reconstruct
comment|/// their execution context without having to keep a complete
comment|/// ExecutionContext object in the object state. Examples of these
comment|/// objects include: Process, Thread, RegisterContext and StackFrame.
comment|///
comment|/// Objects can contain a valid pointer to an instance of this so they
comment|/// can reconstruct the execution context.
comment|///
comment|/// Objects that adhere to this protocol can reconstruct enough of a
comment|/// execution context to allow functions that take a execution contexts
comment|/// to be called.
comment|//----------------------------------------------------------------------
name|class
name|ExecutionContextScope
block|{
name|public
label|:
name|virtual
operator|~
name|ExecutionContextScope
argument_list|()
block|{}
name|virtual
name|lldb
operator|::
name|TargetSP
name|CalculateTarget
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|lldb
operator|::
name|ProcessSP
name|CalculateProcess
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|lldb
operator|::
name|ThreadSP
name|CalculateThread
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|lldb
operator|::
name|StackFrameSP
name|CalculateStackFrame
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Reconstruct the object's execution context into \a sc.
comment|///
comment|/// The object should fill in as much of the ExecutionContextScope as it
comment|/// can so function calls that require a execution context can be made
comment|/// for the given object.
comment|///
comment|/// @param[out] exe_ctx
comment|///     A reference to an execution context object that gets filled
comment|///     in.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|CalculateExecutionContext
parameter_list|(
name|ExecutionContext
modifier|&
name|exe_ctx
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ExecutionContextScope_h_
end_comment

end_unit

