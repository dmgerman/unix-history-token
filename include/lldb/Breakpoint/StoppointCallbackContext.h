begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StoppointCallbackContext.h ------------------------------*- C++ -*-===//
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
name|liblldb_StoppointCallbackContext_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_StoppointCallbackContext_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContext.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class StoppointCallbackContext StoppointCallbackContext.h "lldb/Breakpoint/StoppointCallbackContext.h"
comment|/// @brief Class holds the information that a breakpoint callback needs to evaluate this stop.
comment|//----------------------------------------------------------------------
comment|//----------------------------------------------------------------------
comment|/// General Outline:
comment|/// When we hit a breakpoint we need to package up whatever information is needed
comment|/// to evaluate breakpoint commands and conditions.  This class is the container of
comment|/// that information.
comment|//----------------------------------------------------------------------
name|class
name|StoppointCallbackContext
block|{
name|public
label|:
name|StoppointCallbackContext
argument_list|()
expr_stmt|;
name|StoppointCallbackContext
argument_list|(
argument|Event *event
argument_list|,
argument|const ExecutionContext&exe_ctx
argument_list|,
argument|bool synchronously = false
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Clear the object's state.
comment|///
comment|/// Sets the event, process and thread to NULL, and the frame index to an
comment|/// invalid value.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
name|Event
modifier|*
name|event
decl_stmt|;
comment|// This is the event, the callback can modify this to indicate
comment|// the meaning of the breakpoint hit
name|ExecutionContextRef
name|exe_ctx_ref
decl_stmt|;
comment|// This tells us where we have stopped, what thread.
name|bool
name|is_synchronous
decl_stmt|;
comment|// Is the callback being executed synchronously with the breakpoint,
comment|// or asynchronously as the event is retrieved?
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
comment|// liblldb_StoppointCallbackContext_h_
end_comment

end_unit

