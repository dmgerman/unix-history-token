begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ForwardDecl.h -------------------------------------------*- C++ -*-===//
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
name|liblldb_Plugins_Process_Windows_ForwardDecl_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Plugins_Process_Windows_ForwardDecl_H_
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_comment
comment|// ExceptionResult is returned by the debug delegate to specify how it processed
end_comment

begin_comment
comment|// the exception.
end_comment

begin_decl_stmt
name|enum
name|class
name|ExceptionResult
block|{
name|BreakInDebugger
operator|,
comment|// Break in the debugger and give the user a chance to
comment|// interact with
comment|// the program before continuing.
name|MaskException
operator|,
comment|// Eat the exception and don't let the application know it
comment|// occurred.
name|SendToApplication
comment|// Send the exception to the application to be handled as if
comment|// there were
comment|// no debugger attached.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ProcessWindows
decl_stmt|;
name|class
name|IDebugDelegate
decl_stmt|;
name|class
name|DebuggerThread
decl_stmt|;
name|class
name|ExceptionRecord
decl_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|IDebugDelegate
operator|>
name|DebugDelegateSP
expr_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|DebuggerThread
operator|>
name|DebuggerThreadSP
expr_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|ExceptionRecord
operator|>
name|ExceptionRecordSP
expr_stmt|;
typedef|typedef
name|std
operator|::
name|unique_ptr
operator|<
name|ExceptionRecord
operator|>
name|ExceptionRecordUP
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

