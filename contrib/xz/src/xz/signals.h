begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       signals.h
end_comment

begin_comment
comment|/// \brief      Handling signals to abort operation
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|/// If this is true, we will clean up the possibly incomplete output file,
end_comment

begin_comment
comment|/// return to main() as soon as practical. That is, the code needs to poll
end_comment

begin_comment
comment|/// this variable in various places.
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|sig_atomic_t
name|user_abort
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Initialize the signal handler, which will set user_abort to true when
end_comment

begin_comment
comment|/// user e.g. presses C-c.
end_comment

begin_function_decl
specifier|extern
name|void
name|signals_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|__VMS
argument_list|)
end_if

begin_define
define|#
directive|define
name|signals_block
parameter_list|()
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|signals_unblock
parameter_list|()
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/// Block the signals which don't have SA_RESTART and which would just set
end_comment

begin_comment
comment|/// user_abort to true. This is handy when we don't want to handle EINTR
end_comment

begin_comment
comment|/// and don't want SA_RESTART either.
end_comment

begin_function_decl
specifier|extern
name|void
name|signals_block
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Unblock the signals blocked by signals_block().
end_comment

begin_function_decl
specifier|extern
name|void
name|signals_unblock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_define
define|#
directive|define
name|signals_exit
parameter_list|()
value|do { } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/// If user has sent us a signal earlier to terminate the process,
end_comment

begin_comment
comment|/// re-raise that signal to actually terminate the process.
end_comment

begin_function_decl
specifier|extern
name|void
name|signals_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

