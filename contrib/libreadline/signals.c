begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* signals.c -- signal handling support for readline. */
end_comment

begin_comment
comment|/* Copyright (C) 1987, 1989, 1992 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 1, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_define
define|#
directive|define
name|READLINE_LIBRARY
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CONFIG_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Just for NULL.  Yuck. */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_UNISTD_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UNISTD_H */
end_comment

begin_comment
comment|/* System-specific feature definitions and include files. */
end_comment

begin_include
include|#
directive|include
file|"rldefs.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GWINSZ_IN_SYS_IOCTL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GWINSZ_IN_SYS_IOCTL */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GO32__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HANDLE_SIGNALS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GO32__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HANDLE_SIGNALS
argument_list|)
end_if

begin_comment
comment|/* Some standard library routines. */
end_comment

begin_include
include|#
directive|include
file|"readline.h"
end_include

begin_include
include|#
directive|include
file|"history.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|readline_echoing_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rl_pending_input
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_meta_flag
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|free_undo_list
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_rl_get_screen_size
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_rl_redisplay_after_sigwinch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_rl_clean_up_for_exit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_rl_kill_kbd_macro
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_rl_init_argument
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|rl_deprep_terminal
argument_list|()
decl_stmt|,
name|rl_prep_terminal
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|RETSIGTYPE
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VOID_SIGHANDLER
argument_list|)
end_if

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RETSIGTYPE
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !VOID_SIGHANDLER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !RETSIGTYPE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VOID_SIGHANDLER
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGHANDLER_RETURN
value|return
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIGHANDLER_RETURN
value|return (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This typedef is equivalant to the one for Function; it allows us    to say SigHandler *foo = signal (SIGKILL, SIG_IGN); */
end_comment

begin_typedef
typedef|typedef
name|RETSIGTYPE
name|SigHandler
parameter_list|()
function_decl|;
end_typedef

begin_function_decl
specifier|static
name|SigHandler
modifier|*
name|rl_set_sighandler
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*					        		    */
end_comment

begin_comment
comment|/*			   Signal Handling                          */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* If we're not being compiled as part of bash, initialize handlers for    and catch the job control signals (SIGTTIN, SIGTTOU, SIGTSTP) and    SIGTERM. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SHELL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HANDLE_JOB_SIGNALS
end_define

begin_define
define|#
directive|define
name|HANDLE_SIGTERM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SHELL */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_POSIX_SIGNALS
argument_list|)
end_if

begin_typedef
typedef|typedef
name|struct
name|sigaction
name|sighandler_cxt
typedef|;
end_typedef

begin_define
define|#
directive|define
name|rl_sigaction
parameter_list|(
name|s
parameter_list|,
name|nh
parameter_list|,
name|oh
parameter_list|)
value|sigaction(s, nh, oh)
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
block|{
name|SigHandler
modifier|*
name|sa_handler
decl_stmt|;
block|}
name|sighandler_cxt
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sigemptyset
parameter_list|(
name|m
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_POSIX_SIGNALS */
end_comment

begin_decl_stmt
specifier|static
name|sighandler_cxt
name|old_int
decl_stmt|,
name|old_alrm
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HANDLE_JOB_SIGNALS
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|sighandler_cxt
name|old_tstp
decl_stmt|,
name|old_ttou
decl_stmt|,
name|old_ttin
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HANDLE_JOB_SIGNALS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HANDLE_SIGTERM
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|sighandler_cxt
name|old_term
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SIGWINCH
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|sighandler_cxt
name|old_winch
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Readline signal handler functions. */
end_comment

begin_function
specifier|static
name|RETSIGTYPE
name|rl_signal_handler
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_POSIX_SIGNALS
argument_list|)
name|sigset_t
name|set
decl_stmt|;
else|#
directive|else
comment|/* !HAVE_POSIX_SIGNALS */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_BSD_SIGNALS
argument_list|)
name|long
name|omask
decl_stmt|;
else|#
directive|else
comment|/* !HAVE_BSD_SIGNALS */
name|sighandler_cxt
name|dummy_cxt
decl_stmt|;
comment|/* needed for rl_set_sighandler call */
endif|#
directive|endif
comment|/* !HAVE_BSD_SIGNALS */
endif|#
directive|endif
comment|/* !HAVE_POSIX_SIGNALS */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_BSD_SIGNALS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_POSIX_SIGNALS
argument_list|)
comment|/* Since the signal will not be blocked while we are in the signal      handler, ignore it until rl_clear_signals resets the catcher. */
if|if
condition|(
name|sig
operator|==
name|SIGINT
operator|||
name|sig
operator|==
name|SIGALRM
condition|)
name|rl_set_sighandler
argument_list|(
name|sig
argument_list|,
name|SIG_IGN
argument_list|,
operator|&
name|dummy_cxt
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* !HAVE_BSD_SIGNALS&& !HAVE_POSIX_SIGNALS */
switch|switch
condition|(
name|sig
condition|)
block|{
case|case
name|SIGINT
case|:
block|{
specifier|register
name|HIST_ENTRY
modifier|*
name|entry
decl_stmt|;
name|free_undo_list
argument_list|()
expr_stmt|;
name|entry
operator|=
name|current_history
argument_list|()
expr_stmt|;
if|if
condition|(
name|entry
condition|)
name|entry
operator|->
name|data
operator|=
operator|(
name|char
operator|*
operator|)
name|NULL
expr_stmt|;
block|}
name|_rl_kill_kbd_macro
argument_list|()
expr_stmt|;
name|rl_clear_message
argument_list|()
expr_stmt|;
name|_rl_init_argument
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SIGTSTP
argument_list|)
case|case
name|SIGTSTP
case|:
case|case
name|SIGTTOU
case|:
case|case
name|SIGTTIN
case|:
endif|#
directive|endif
comment|/* SIGTSTP */
case|case
name|SIGALRM
case|:
case|case
name|SIGTERM
case|:
name|_rl_clean_up_for_exit
argument_list|()
expr_stmt|;
call|(
modifier|*
name|rl_deprep_term_function
call|)
argument_list|()
expr_stmt|;
name|rl_clear_signals
argument_list|()
expr_stmt|;
name|rl_pending_input
operator|=
literal|0
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_POSIX_SIGNALS
argument_list|)
name|sigprocmask
argument_list|(
name|SIG_BLOCK
argument_list|,
operator|(
name|sigset_t
operator|*
operator|)
name|NULL
argument_list|,
operator|&
name|set
argument_list|)
expr_stmt|;
name|sigdelset
argument_list|(
operator|&
name|set
argument_list|,
name|sig
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* !HAVE_POSIX_SIGNALS */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_BSD_SIGNALS
argument_list|)
name|omask
operator|=
name|sigblock
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_BSD_SIGNALS */
endif|#
directive|endif
comment|/* !HAVE_POSIX_SIGNALS */
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|sig
argument_list|)
expr_stmt|;
comment|/* Let the signal that we just sent through.  */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_POSIX_SIGNALS
argument_list|)
name|sigprocmask
argument_list|(
name|SIG_SETMASK
argument_list|,
operator|&
name|set
argument_list|,
operator|(
name|sigset_t
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* !HAVE_POSIX_SIGNALS */
if|#
directive|if
name|defined
argument_list|(
name|HAVE_BSD_SIGNALS
argument_list|)
name|sigsetmask
argument_list|(
name|omask
operator|&
operator|~
operator|(
name|sigmask
argument_list|(
name|sig
argument_list|)
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_BSD_SIGNALS */
endif|#
directive|endif
comment|/* !HAVE_POSIX_SIGNALS */
call|(
modifier|*
name|rl_prep_term_function
call|)
argument_list|(
name|_rl_meta_flag
argument_list|)
expr_stmt|;
name|rl_set_signals
argument_list|()
expr_stmt|;
block|}
name|SIGHANDLER_RETURN
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SIGWINCH
argument_list|)
end_if

begin_function
specifier|static
name|RETSIGTYPE
name|rl_handle_sigwinch
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
name|SigHandler
modifier|*
name|oh
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|MUST_REINSTALL_SIGHANDLERS
argument_list|)
name|sighandler_cxt
name|dummy_winch
decl_stmt|;
comment|/* We don't want to change old_winch -- it holds the state of SIGWINCH      disposition set by the calling application.  We need this state      because we call the application's SIGWINCH handler after updating      our own idea of the screen size. */
name|rl_set_sighandler
argument_list|(
name|SIGWINCH
argument_list|,
name|rl_handle_sigwinch
argument_list|,
operator|&
name|dummy_winch
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|readline_echoing_p
condition|)
block|{
name|_rl_get_screen_size
argument_list|(
name|fileno
argument_list|(
name|rl_instream
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|_rl_redisplay_after_sigwinch
argument_list|()
expr_stmt|;
block|}
comment|/* If another sigwinch handler has been installed, call it. */
name|oh
operator|=
operator|(
name|SigHandler
operator|*
operator|)
name|old_winch
operator|.
name|sa_handler
expr_stmt|;
if|if
condition|(
name|oh
operator|&&
name|oh
operator|!=
operator|(
name|SigHandler
operator|*
operator|)
name|SIG_IGN
operator|&&
name|oh
operator|!=
operator|(
name|SigHandler
operator|*
operator|)
name|SIG_DFL
condition|)
call|(
modifier|*
name|oh
call|)
argument_list|(
name|sig
argument_list|)
expr_stmt|;
name|SIGHANDLER_RETURN
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGWINCH */
end_comment

begin_comment
comment|/* Functions to manage signal handling. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_POSIX_SIGNALS
argument_list|)
end_if

begin_function
specifier|static
name|int
name|rl_sigaction
parameter_list|(
name|sig
parameter_list|,
name|nh
parameter_list|,
name|oh
parameter_list|)
name|int
name|sig
decl_stmt|;
name|sighandler_cxt
modifier|*
name|nh
decl_stmt|,
decl|*
name|oh
decl_stmt|;
end_function

begin_block
block|{
name|oh
operator|->
name|sa_handler
operator|=
name|signal
argument_list|(
name|sig
argument_list|,
name|nh
operator|->
name|sa_handler
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_POSIX_SIGNALS */
end_comment

begin_comment
comment|/* Set up a readline-specific signal handler, saving the old signal    information in OHANDLER.  Return the old signal handler, like    signal(). */
end_comment

begin_function
specifier|static
name|SigHandler
modifier|*
name|rl_set_sighandler
parameter_list|(
name|sig
parameter_list|,
name|handler
parameter_list|,
name|ohandler
parameter_list|)
name|int
name|sig
decl_stmt|;
name|SigHandler
modifier|*
name|handler
decl_stmt|;
name|sighandler_cxt
modifier|*
name|ohandler
decl_stmt|;
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_POSIX_SIGNALS
argument_list|)
name|struct
name|sigaction
name|act
decl_stmt|;
name|act
operator|.
name|sa_handler
operator|=
name|handler
expr_stmt|;
name|act
operator|.
name|sa_flags
operator|=
literal|0
expr_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|act
operator|.
name|sa_mask
argument_list|)
expr_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|ohandler
operator|->
name|sa_mask
argument_list|)
expr_stmt|;
name|sigaction
argument_list|(
name|sig
argument_list|,
operator|&
name|act
argument_list|,
name|ohandler
argument_list|)
expr_stmt|;
else|#
directive|else
name|ohandler
operator|->
name|sa_handler
operator|=
operator|(
name|SigHandler
operator|*
operator|)
name|signal
argument_list|(
name|sig
argument_list|,
name|handler
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* !HAVE_POSIX_SIGNALS */
return|return
operator|(
name|ohandler
operator|->
name|sa_handler
operator|)
return|;
block|}
end_function

begin_function
name|int
name|rl_set_signals
parameter_list|()
block|{
name|sighandler_cxt
name|dummy
decl_stmt|;
name|SigHandler
modifier|*
name|oh
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_POSIX_SIGNALS
argument_list|)
name|sigemptyset
argument_list|(
operator|&
name|dummy
operator|.
name|sa_mask
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|oh
operator|=
name|rl_set_sighandler
argument_list|(
name|SIGINT
argument_list|,
name|rl_signal_handler
argument_list|,
operator|&
name|old_int
argument_list|)
expr_stmt|;
if|if
condition|(
name|oh
operator|==
operator|(
name|SigHandler
operator|*
operator|)
name|SIG_IGN
condition|)
name|rl_sigaction
argument_list|(
name|SIGINT
argument_list|,
operator|&
name|old_int
argument_list|,
operator|&
name|dummy
argument_list|)
expr_stmt|;
name|oh
operator|=
name|rl_set_sighandler
argument_list|(
name|SIGALRM
argument_list|,
name|rl_signal_handler
argument_list|,
operator|&
name|old_alrm
argument_list|)
expr_stmt|;
if|if
condition|(
name|oh
operator|==
operator|(
name|SigHandler
operator|*
operator|)
name|SIG_IGN
condition|)
name|rl_sigaction
argument_list|(
name|SIGALRM
argument_list|,
operator|&
name|old_alrm
argument_list|,
operator|&
name|dummy
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_POSIX_SIGNALS
argument_list|)
operator|&&
name|defined
argument_list|(
name|SA_RESTART
argument_list|)
comment|/* If the application using readline has already installed a signal      handler with SA_RESTART, SIGALRM will cause reads to be restarted      automatically, so readline should just get out of the way.  Since      we tested for SIG_IGN above, we can just test for SIG_DFL here. */
if|if
condition|(
name|oh
operator|!=
operator|(
name|SigHandler
operator|*
operator|)
name|SIG_DFL
operator|&&
operator|(
name|old_alrm
operator|.
name|sa_flags
operator|&
name|SA_RESTART
operator|)
condition|)
name|rl_sigaction
argument_list|(
name|SIGALRM
argument_list|,
operator|&
name|old_alrm
argument_list|,
operator|&
name|dummy
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_POSIX_SIGNALS */
if|#
directive|if
name|defined
argument_list|(
name|HANDLE_JOB_SIGNALS
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|SIGTSTP
argument_list|)
name|oh
operator|=
name|rl_set_sighandler
argument_list|(
name|SIGTSTP
argument_list|,
name|rl_signal_handler
argument_list|,
operator|&
name|old_tstp
argument_list|)
expr_stmt|;
if|if
condition|(
name|oh
operator|==
operator|(
name|SigHandler
operator|*
operator|)
name|SIG_IGN
condition|)
name|rl_sigaction
argument_list|(
name|SIGTSTP
argument_list|,
operator|&
name|old_tstp
argument_list|,
operator|&
name|dummy
argument_list|)
expr_stmt|;
else|#
directive|else
name|oh
operator|=
operator|(
name|SigHandler
operator|*
operator|)
name|NULL
expr_stmt|;
endif|#
directive|endif
comment|/* SIGTSTP */
if|#
directive|if
name|defined
argument_list|(
name|SIGTTOU
argument_list|)
name|rl_set_sighandler
argument_list|(
name|SIGTTOU
argument_list|,
name|rl_signal_handler
argument_list|,
operator|&
name|old_ttou
argument_list|)
expr_stmt|;
name|rl_set_sighandler
argument_list|(
name|SIGTTIN
argument_list|,
name|rl_signal_handler
argument_list|,
operator|&
name|old_ttin
argument_list|)
expr_stmt|;
if|if
condition|(
name|oh
operator|==
operator|(
name|SigHandler
operator|*
operator|)
name|SIG_IGN
condition|)
block|{
name|rl_set_sighandler
argument_list|(
name|SIGTTOU
argument_list|,
name|SIG_IGN
argument_list|,
operator|&
name|dummy
argument_list|)
expr_stmt|;
name|rl_set_sighandler
argument_list|(
name|SIGTTIN
argument_list|,
name|SIG_IGN
argument_list|,
operator|&
name|dummy
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* SIGTTOU */
endif|#
directive|endif
comment|/* HANDLE_JOB_SIGNALS */
if|#
directive|if
name|defined
argument_list|(
name|HANDLE_SIGTERM
argument_list|)
comment|/* Handle SIGTERM if we're not being compiled as part of bash. */
name|rl_set_sighandler
argument_list|(
name|SIGTERM
argument_list|,
name|rl_signal_handler
argument_list|,
operator|&
name|old_term
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HANDLE_SIGTERM */
if|#
directive|if
name|defined
argument_list|(
name|SIGWINCH
argument_list|)
name|rl_set_sighandler
argument_list|(
name|SIGWINCH
argument_list|,
name|rl_handle_sigwinch
argument_list|,
operator|&
name|old_winch
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SIGWINCH */
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|rl_clear_signals
parameter_list|()
block|{
name|sighandler_cxt
name|dummy
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_POSIX_SIGNALS
argument_list|)
name|sigemptyset
argument_list|(
operator|&
name|dummy
operator|.
name|sa_mask
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|rl_sigaction
argument_list|(
name|SIGINT
argument_list|,
operator|&
name|old_int
argument_list|,
operator|&
name|dummy
argument_list|)
expr_stmt|;
name|rl_sigaction
argument_list|(
name|SIGALRM
argument_list|,
operator|&
name|old_alrm
argument_list|,
operator|&
name|dummy
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HANDLE_JOB_SIGNALS
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|SIGTSTP
argument_list|)
name|rl_sigaction
argument_list|(
name|SIGTSTP
argument_list|,
operator|&
name|old_tstp
argument_list|,
operator|&
name|dummy
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|SIGTTOU
argument_list|)
name|rl_sigaction
argument_list|(
name|SIGTTOU
argument_list|,
operator|&
name|old_ttou
argument_list|,
operator|&
name|dummy
argument_list|)
expr_stmt|;
name|rl_sigaction
argument_list|(
name|SIGTTIN
argument_list|,
operator|&
name|old_ttin
argument_list|,
operator|&
name|dummy
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SIGTTOU */
endif|#
directive|endif
comment|/* HANDLE_JOB_SIGNALS */
if|#
directive|if
name|defined
argument_list|(
name|HANDLE_SIGTERM
argument_list|)
name|rl_sigaction
argument_list|(
name|SIGTERM
argument_list|,
operator|&
name|old_term
argument_list|,
operator|&
name|dummy
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HANDLE_SIGTERM */
if|#
directive|if
name|defined
argument_list|(
name|SIGWINCH
argument_list|)
name|sigemptyset
argument_list|(
operator|&
name|dummy
operator|.
name|sa_mask
argument_list|)
expr_stmt|;
name|rl_sigaction
argument_list|(
name|SIGWINCH
argument_list|,
operator|&
name|old_winch
argument_list|,
operator|&
name|dummy
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HANDLE_SIGNALS */
end_comment

end_unit

