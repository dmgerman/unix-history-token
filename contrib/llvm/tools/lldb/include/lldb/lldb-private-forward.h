begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-private-forward.h ----------------------------------*- C++ -*-===//
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
name|LLDB_lldb_private_forward_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_lldb_private_forward_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// ---------------------------------------------------------------
comment|// Class forward decls.
comment|// ---------------------------------------------------------------
name|class
name|NativeBreakpoint
decl_stmt|;
name|class
name|NativeBreakpointList
decl_stmt|;
name|class
name|NativeProcessProtocol
decl_stmt|;
name|class
name|NativeRegisterContext
decl_stmt|;
name|class
name|NativeThreadProtocol
decl_stmt|;
name|class
name|ResumeActionList
decl_stmt|;
name|class
name|UnixSignals
decl_stmt|;
comment|// ---------------------------------------------------------------
comment|// SP/WP decls.
comment|// ---------------------------------------------------------------
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|NativeBreakpoint
operator|>
name|NativeBreakpointSP
expr_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|lldb_private
operator|::
name|NativeRegisterContext
operator|>
name|NativeRegisterContextSP
expr_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|lldb_private
operator|::
name|NativeThreadProtocol
operator|>
name|NativeThreadProtocolSP
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef LLDB_lldb_private_forward_h_
end_comment

end_unit

