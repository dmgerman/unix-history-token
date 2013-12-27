begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------------------- KQueue.h -----------------------------*- C++ -*-===//
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
name|utility_KQueue_h_
end_ifndef

begin_define
define|#
directive|define
name|utility_KQueue_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLDB_USE_KQUEUES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LLDB_USE_KQUEUES
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/event.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|KQueue
block|{
name|public
label|:
name|KQueue
argument_list|()
operator|:
name|m_fd
argument_list|(
argument|-
literal|1
argument_list|)
block|{     }
operator|~
name|KQueue
argument_list|()
block|{
name|Close
argument_list|()
block|;     }
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|m_fd
operator|>=
literal|0
return|;
block|}
name|int
name|GetFD
parameter_list|(
name|bool
name|can_create
parameter_list|)
function_decl|;
name|int
name|Close
parameter_list|()
function_decl|;
name|bool
name|AddFDEvent
parameter_list|(
name|int
name|fd
parameter_list|,
name|bool
name|read
parameter_list|,
name|bool
name|write
parameter_list|,
name|bool
name|vnode
parameter_list|)
function_decl|;
name|int
name|WaitForEvents
parameter_list|(
name|struct
name|kevent
modifier|*
name|events
parameter_list|,
name|int
name|num_events
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|,
name|uint32_t
name|timeout_usec
init|=
name|UINT32_MAX
parameter_list|)
function_decl|;
comment|// UINT32_MAX means infinite timeout
name|protected
label|:
name|int
name|m_fd
decl_stmt|;
comment|// The kqueue fd
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
comment|// #ifdef LLDB_USE_KQUEUES
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef utility_KQueue_h_
end_comment

end_unit

