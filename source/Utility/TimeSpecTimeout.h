begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------------------- TimeSpecTimeout.h --------------------*- C++ -*-===//
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
name|utility_TimeSpecTimeout_h_
end_ifndef

begin_define
define|#
directive|define
name|utility_TimeSpecTimeout_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/TimeValue.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|TimeSpecTimeout
block|{
name|public
label|:
name|TimeSpecTimeout
argument_list|()
operator|:
name|m_infinite
argument_list|(
argument|false
argument_list|)
block|{
name|m_timespec
operator|.
name|tv_sec
operator|=
literal|0
block|;
name|m_timespec
operator|.
name|tv_nsec
operator|=
literal|0
block|;     }
operator|~
name|TimeSpecTimeout
argument_list|()
block|{     }
comment|//----------------------------------------------------------------------
comment|/// Sets the timespec pointer correctly given a timeout relative to the
comment|/// current time. This function should be called immediately prior to
comment|/// calling the function you will use this timeout with since time can
comment|/// elapse between when this function is called and when the timeout is
comment|/// used.
comment|///
comment|/// @param[in] timeout_usec
comment|///     The timeout in micro seconds. If timeout_usec is UINT32_MAX, the
comment|///     timeout should be set to INFINITE. Otherwise the current time is
comment|///     filled into the timespec and \a timeout_usec is added to the
comment|///     current time.
comment|///
comment|/// @return
comment|///     If the timeout is INFINITE, then return NULL, otherwise return
comment|///     a pointer to the timespec with the appropriate timeout value.
comment|//----------------------------------------------------------------------
specifier|const
expr|struct
name|timespec
operator|*
name|SetAbsoluteTimeoutMircoSeconds32
argument_list|(
argument|uint32_t timeout_usec
argument_list|)
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Sets the timespec pointer correctly given a relative time in micro
comment|/// seconds.
comment|///
comment|/// @param[in] timeout_usec
comment|///     The timeout in micro seconds. If timeout_usec is UINT32_MAX, the
comment|///     timeout should be set to INFINITE. Otherwise \a timeout_usec
comment|///     is correctly placed into the timespec.
comment|///
comment|/// @return
comment|///     If the timeout is INFINITE, then return NULL, otherwise return
comment|///     a pointer to the timespec with the appropriate timeout value.
comment|//----------------------------------------------------------------------
specifier|const
name|struct
name|timespec
modifier|*
name|SetRelativeTimeoutMircoSeconds32
parameter_list|(
name|uint32_t
name|timeout_usec
parameter_list|)
function_decl|;
comment|//----------------------------------------------------------------------
comment|/// Gets the timespec pointer that is appropriate for the timeout
comment|/// specified. This function should only be used after a call to
comment|/// SetRelativeTimeoutXXX() functions.
comment|///
comment|/// @return
comment|///     If the timeout is INFINITE, then return NULL, otherwise return
comment|///     a pointer to the timespec with the appropriate timeout value.
comment|//----------------------------------------------------------------------
specifier|const
expr|struct
name|timespec
operator|*
name|GetTimeSpecPtr
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_infinite
condition|)
return|return
name|nullptr
return|;
return|return
operator|&
name|m_timespec
return|;
block|}
name|protected
label|:
name|struct
name|timespec
name|m_timespec
decl_stmt|;
name|bool
name|m_infinite
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef utility_TimeSpecTimeout_h_
end_comment

end_unit

