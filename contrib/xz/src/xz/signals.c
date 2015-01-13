begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       signals.c
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

begin_include
include|#
directive|include
file|"private.h"
end_include

begin_decl_stmt
specifier|volatile
name|sig_atomic_t
name|user_abort
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
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
end_if

begin_comment
comment|/// If we were interrupted by a signal, we store the signal number so that
end_comment

begin_comment
comment|/// we can raise that signal to kill the program when all cleanups have
end_comment

begin_comment
comment|/// been done.
end_comment

begin_decl_stmt
specifier|static
specifier|volatile
name|sig_atomic_t
name|exit_signal
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Mask of signals for which have have established a signal handler to set
end_comment

begin_comment
comment|/// user_abort to true.
end_comment

begin_decl_stmt
specifier|static
name|sigset_t
name|hooked_signals
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// True once signals_init() has finished. This is used to skip blocking
end_comment

begin_comment
comment|/// signals (with uninitialized hooked_signals) if signals_block() and
end_comment

begin_comment
comment|/// signals_unblock() are called before signals_init() has been called.
end_comment

begin_decl_stmt
specifier|static
name|bool
name|signals_are_initialized
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// signals_block() and signals_unblock() can be called recursively.
end_comment

begin_decl_stmt
specifier|static
name|size_t
name|signals_block_count
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|signal_handler
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
name|exit_signal
operator|=
name|sig
expr_stmt|;
name|user_abort
operator|=
name|true
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|signals_init
parameter_list|(
name|void
parameter_list|)
block|{
comment|// List of signals for which we establish the signal handler.
specifier|static
specifier|const
name|int
name|sigs
index|[]
init|=
block|{
name|SIGINT
block|,
name|SIGTERM
block|,
ifdef|#
directive|ifdef
name|SIGHUP
name|SIGHUP
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SIGPIPE
name|SIGPIPE
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SIGXCPU
name|SIGXCPU
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SIGXFSZ
name|SIGXFSZ
block|,
endif|#
directive|endif
block|}
decl_stmt|;
comment|// Mask of the signals for which we have established a signal handler.
name|sigemptyset
argument_list|(
operator|&
name|hooked_signals
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ARRAY_SIZE
argument_list|(
name|sigs
argument_list|)
condition|;
operator|++
name|i
control|)
name|sigaddset
argument_list|(
operator|&
name|hooked_signals
argument_list|,
name|sigs
index|[
name|i
index|]
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SIGALRM
comment|// Add also the signals from message.c to hooked_signals.
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|message_progress_sigs
index|[
name|i
index|]
operator|!=
literal|0
condition|;
operator|++
name|i
control|)
name|sigaddset
argument_list|(
operator|&
name|hooked_signals
argument_list|,
name|message_progress_sigs
index|[
name|i
index|]
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Using "my_sa" because "sa" may conflict with a sockaddr variable
comment|// from system headers on Solaris.
name|struct
name|sigaction
name|my_sa
decl_stmt|;
comment|// All the signals that we handle we also blocked while the signal
comment|// handler runs.
name|my_sa
operator|.
name|sa_mask
operator|=
name|hooked_signals
expr_stmt|;
comment|// Don't set SA_RESTART, because we want EINTR so that we can check
comment|// for user_abort and cleanup before exiting. We block the signals
comment|// for which we have established a handler when we don't want EINTR.
name|my_sa
operator|.
name|sa_flags
operator|=
literal|0
expr_stmt|;
name|my_sa
operator|.
name|sa_handler
operator|=
operator|&
name|signal_handler
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ARRAY_SIZE
argument_list|(
name|sigs
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
comment|// If the parent process has left some signals ignored,
comment|// we don't unignore them.
name|struct
name|sigaction
name|old
decl_stmt|;
if|if
condition|(
name|sigaction
argument_list|(
name|sigs
index|[
name|i
index|]
argument_list|,
name|NULL
argument_list|,
operator|&
name|old
argument_list|)
operator|==
literal|0
operator|&&
name|old
operator|.
name|sa_handler
operator|==
name|SIG_IGN
condition|)
continue|continue;
comment|// Establish the signal handler.
if|if
condition|(
name|sigaction
argument_list|(
name|sigs
index|[
name|i
index|]
argument_list|,
operator|&
name|my_sa
argument_list|,
name|NULL
argument_list|)
condition|)
name|message_signal_handler
argument_list|()
expr_stmt|;
block|}
name|signals_are_initialized
operator|=
name|true
expr_stmt|;
return|return;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|__VMS
end_ifndef

begin_function
specifier|extern
name|void
name|signals_block
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|signals_are_initialized
condition|)
block|{
if|if
condition|(
name|signals_block_count
operator|++
operator|==
literal|0
condition|)
block|{
specifier|const
name|int
name|saved_errno
init|=
name|errno
decl_stmt|;
name|mythread_sigmask
argument_list|(
name|SIG_BLOCK
argument_list|,
operator|&
name|hooked_signals
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|errno
operator|=
name|saved_errno
expr_stmt|;
block|}
block|}
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|signals_unblock
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|signals_are_initialized
condition|)
block|{
name|assert
argument_list|(
name|signals_block_count
operator|>
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|--
name|signals_block_count
operator|==
literal|0
condition|)
block|{
specifier|const
name|int
name|saved_errno
init|=
name|errno
decl_stmt|;
name|mythread_sigmask
argument_list|(
name|SIG_UNBLOCK
argument_list|,
operator|&
name|hooked_signals
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|errno
operator|=
name|saved_errno
expr_stmt|;
block|}
block|}
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|extern
name|void
name|signals_exit
parameter_list|(
name|void
parameter_list|)
block|{
specifier|const
name|int
name|sig
init|=
name|exit_signal
decl_stmt|;
if|if
condition|(
name|sig
operator|!=
literal|0
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|TUKLIB_DOSLIKE
argument_list|)
operator|||
name|defined
argument_list|(
name|__VMS
argument_list|)
comment|// Don't raise(), set only exit status. This avoids
comment|// printing unwanted message about SIGINT when the user
comment|// presses C-c.
name|set_exit_status
argument_list|(
name|E_ERROR
argument_list|)
expr_stmt|;
else|#
directive|else
name|struct
name|sigaction
name|sa
decl_stmt|;
name|sa
operator|.
name|sa_handler
operator|=
name|SIG_DFL
expr_stmt|;
name|sigfillset
argument_list|(
operator|&
name|sa
operator|.
name|sa_mask
argument_list|)
expr_stmt|;
name|sa
operator|.
name|sa_flags
operator|=
literal|0
expr_stmt|;
name|sigaction
argument_list|(
name|sig
argument_list|,
operator|&
name|sa
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|raise
argument_list|(
name|exit_signal
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
return|return;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|// While Windows has some very basic signal handling functions as required
end_comment

begin_comment
comment|// by C89, they are not really used, and e.g. SIGINT doesn't work exactly
end_comment

begin_comment
comment|// the way it does on POSIX (Windows creates a new thread for the signal
end_comment

begin_comment
comment|// handler). Instead, we use SetConsoleCtrlHandler() to catch user
end_comment

begin_comment
comment|// pressing C-c, because that seems to be the recommended way to do it.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOTE: This doesn't work under MSYS. Trying with SIGINT doesn't work
end_comment

begin_comment
comment|// either even if it appeared to work at first. So test using Windows
end_comment

begin_comment
comment|// console window.
end_comment

begin_decl_stmt
specifier|static
name|BOOL
name|WINAPI
name|signal_handler
argument_list|(
name|DWORD
name|type
name|lzma_attribute
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
argument_list|)
block|{
comment|// Since we don't get a signal number which we could raise() at
comment|// signals_exit() like on POSIX, just set the exit status to
comment|// indicate an error, so that we cannot return with zero exit status.
name|set_exit_status
argument_list|(
name|E_ERROR
argument_list|)
expr_stmt|;
name|user_abort
operator|=
name|true
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_decl_stmt

begin_function
specifier|extern
name|void
name|signals_init
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|SetConsoleCtrlHandler
argument_list|(
operator|&
name|signal_handler
argument_list|,
name|TRUE
argument_list|)
condition|)
name|message_signal_handler
argument_list|()
expr_stmt|;
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

