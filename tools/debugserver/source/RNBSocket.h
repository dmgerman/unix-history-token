begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RNBSocket.h ---------------------------------------------*- C++ -*-===//
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
comment|//  Created by Greg Clayton on 12/12/07.
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
name|__RNBSocket_h__
end_ifndef

begin_define
define|#
directive|define
name|__RNBSocket_h__
end_define

begin_include
include|#
directive|include
file|"DNBTimer.h"
end_include

begin_include
include|#
directive|include
file|"RNBDefs.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_LOCKDOWN
end_ifdef

begin_include
include|#
directive|include
file|"lockdown.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|class
name|RNBSocket
block|{
name|public
label|:
typedef|typedef
name|void
function_decl|(
modifier|*
name|PortBoundCallback
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
name|baton
parameter_list|,
name|uint16_t
name|port
parameter_list|)
function_decl|;
name|RNBSocket
argument_list|()
operator|:
name|m_fd
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
ifdef|#
directive|ifdef
name|WITH_LOCKDOWN
name|m_fd_from_lockdown
argument_list|(
name|false
argument_list|)
operator|,
name|m_ld_conn
argument_list|()
operator|,
endif|#
directive|endif
name|m_timer
argument_list|(
argument|true
argument_list|)
comment|// Make a thread safe timer
block|{   }
operator|~
name|RNBSocket
argument_list|(
argument|void
argument_list|)
block|{
name|Disconnect
argument_list|(
name|false
argument_list|)
block|; }
name|rnb_err_t
name|Listen
argument_list|(
argument|const char *listen_host
argument_list|,
argument|uint16_t port
argument_list|,
argument|PortBoundCallback callback
argument_list|,
argument|const void *callback_baton
argument_list|)
expr_stmt|;
name|rnb_err_t
name|Connect
parameter_list|(
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|uint16_t
name|port
parameter_list|)
function_decl|;
name|rnb_err_t
name|useFD
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|WITH_LOCKDOWN
name|rnb_err_t
name|ConnectToService
parameter_list|()
function_decl|;
endif|#
directive|endif
name|rnb_err_t
name|OpenFile
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
name|rnb_err_t
name|Disconnect
parameter_list|(
name|bool
name|save_errno
parameter_list|)
function_decl|;
name|rnb_err_t
name|Read
argument_list|(
name|std
operator|::
name|string
operator|&
name|p
argument_list|)
decl_stmt|;
name|rnb_err_t
name|Write
parameter_list|(
specifier|const
name|void
modifier|*
name|buffer
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
name|bool
name|IsConnected
argument_list|()
specifier|const
block|{
return|return
name|m_fd
operator|!=
operator|-
literal|1
return|;
block|}
name|void
name|SaveErrno
parameter_list|(
name|int
name|curr_errno
parameter_list|)
function_decl|;
name|DNBTimer
modifier|&
name|Timer
parameter_list|()
block|{
return|return
name|m_timer
return|;
block|}
specifier|static
name|int
name|SetSocketOption
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|level
parameter_list|,
name|int
name|option_name
parameter_list|,
name|int
name|option_value
parameter_list|)
function_decl|;
name|private
label|:
comment|// Outlaw some constructors
name|RNBSocket
argument_list|(
specifier|const
name|RNBSocket
operator|&
argument_list|)
expr_stmt|;
name|protected
label|:
name|rnb_err_t
name|ClosePort
parameter_list|(
name|int
modifier|&
name|fd
parameter_list|,
name|bool
name|save_errno
parameter_list|)
function_decl|;
name|int
name|m_fd
decl_stmt|;
comment|// Socket we use to communicate once conn established
ifdef|#
directive|ifdef
name|WITH_LOCKDOWN
name|bool
name|m_fd_from_lockdown
decl_stmt|;
name|lockdown_connection
name|m_ld_conn
decl_stmt|;
endif|#
directive|endif
name|DNBTimer
name|m_timer
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef __RNBSocket_h__
end_comment

end_unit

