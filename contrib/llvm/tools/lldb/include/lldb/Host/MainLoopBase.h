begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MainLoopBase.h ------------------------------------------*- C++ -*-===//
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
name|lldb_Host_posix_MainLoopBase_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_posix_MainLoopBase_h_
end_define

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/IOObject.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Status.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// The purpose of this class is to enable multiplexed processing of data from
comment|// different sources
comment|// without resorting to multi-threading. Clients can register IOObjects, which
comment|// will be monitored
comment|// for readability, and when they become ready, the specified callback will be
comment|// invoked.
comment|// Monitoring for writability is not supported, but can be easily added if
comment|// needed.
comment|//
comment|// The RegisterReadObject function return a handle, which controls the duration
comment|// of the monitoring. When
comment|// this handle is destroyed, the callback is deregistered.
comment|//
comment|// This class simply defines the interface common for all platforms, actual
comment|// implementations are
comment|// platform-specific.
name|class
name|MainLoopBase
block|{
name|private
label|:
name|class
name|ReadHandle
decl_stmt|;
name|public
label|:
name|MainLoopBase
argument_list|()
block|{}
name|virtual
operator|~
name|MainLoopBase
argument_list|()
block|{}
typedef|typedef
name|std
operator|::
name|unique_ptr
operator|<
name|ReadHandle
operator|>
name|ReadHandleUP
expr_stmt|;
typedef|typedef
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|MainLoopBase
operator|&
argument_list|)
operator|>
name|Callback
expr_stmt|;
name|virtual
name|ReadHandleUP
name|RegisterReadObject
argument_list|(
specifier|const
name|lldb
operator|::
name|IOObjectSP
operator|&
name|object_sp
argument_list|,
specifier|const
name|Callback
operator|&
name|callback
argument_list|,
name|Status
operator|&
name|error
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Not implemented"
argument_list|)
expr_stmt|;
block|}
comment|// Waits for registered events and invoke the proper callbacks. Returns when
comment|// all callbacks
comment|// deregister themselves or when someone requests termination.
name|virtual
name|Status
name|Run
parameter_list|()
block|{
name|llvm_unreachable
argument_list|(
literal|"Not implemented"
argument_list|)
expr_stmt|;
block|}
comment|// Requests the exit of the Run() function.
name|virtual
name|void
name|RequestTermination
parameter_list|()
block|{
name|llvm_unreachable
argument_list|(
literal|"Not implemented"
argument_list|)
expr_stmt|;
block|}
name|protected
label|:
name|ReadHandleUP
name|CreateReadHandle
argument_list|(
specifier|const
name|lldb
operator|::
name|IOObjectSP
operator|&
name|object_sp
argument_list|)
block|{
return|return
name|ReadHandleUP
argument_list|(
argument|new ReadHandle(*this, object_sp->GetWaitableHandle())
argument_list|)
return|;
block|}
name|virtual
name|void
name|UnregisterReadObject
argument_list|(
name|IOObject
operator|::
name|WaitableHandle
name|handle
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Not implemented"
argument_list|)
expr_stmt|;
block|}
name|private
label|:
name|class
name|ReadHandle
block|{
name|public
label|:
operator|~
name|ReadHandle
argument_list|()
block|{
name|m_mainloop
operator|.
name|UnregisterReadObject
argument_list|(
name|m_handle
argument_list|)
block|; }
name|private
operator|:
name|ReadHandle
argument_list|(
argument|MainLoopBase&mainloop
argument_list|,
argument|IOObject::WaitableHandle handle
argument_list|)
operator|:
name|m_mainloop
argument_list|(
name|mainloop
argument_list|)
operator|,
name|m_handle
argument_list|(
argument|handle
argument_list|)
block|{}
name|MainLoopBase
operator|&
name|m_mainloop
expr_stmt|;
name|IOObject
operator|::
name|WaitableHandle
name|m_handle
expr_stmt|;
name|friend
name|class
name|MainLoopBase
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ReadHandle
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|MainLoopBase
argument_list|)
expr_stmt|;
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
comment|// lldb_Host_posix_MainLoopBase_h_
end_comment

end_unit

