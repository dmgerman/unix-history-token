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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_SYS_FILE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NO_SYS_FILE */
end_comment

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STDLIB_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"ansi_stdlib.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STDLIB_H */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* Not all systems declare ERRNO in errno.h... and some systems #define it! */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|errno
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !errno */
end_comment

begin_include
include|#
directive|include
file|"posixstat.h"
end_include

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
name|sighandler
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sighandler
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VOID_SIGHANDLER */
end_comment

begin_comment
comment|/* This typedef is equivalant to the one for Function; it allows us    to say SigHandler *foo = signal (SIGKILL, SIG_IGN); */
end_comment

begin_typedef
typedef|typedef
name|sighandler
name|SigHandler
parameter_list|()
function_decl|;
end_typedef

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
name|STATIC_MALLOC
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
modifier|*
name|xmalloc
argument_list|()
decl_stmt|,
modifier|*
name|xrealloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xmalloc
argument_list|()
decl_stmt|,
modifier|*
name|xrealloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STATIC_MALLOC */
end_comment

begin_escape
end_escape

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
name|SigHandler
modifier|*
name|old_sigwinch
init|=
operator|(
name|SigHandler
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|sighandler
name|rl_handle_sigwinch
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
if|if
condition|(
name|readline_echoing_p
condition|)
block|{
name|_rl_set_screen_size
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
if|if
condition|(
name|old_sigwinch
operator|&&
name|old_sigwinch
operator|!=
operator|(
name|SigHandler
operator|*
operator|)
name|SIG_IGN
operator|&&
name|old_sigwinch
operator|!=
operator|(
name|SigHandler
operator|*
operator|)
name|SIG_DFL
condition|)
call|(
modifier|*
name|old_sigwinch
call|)
argument_list|(
name|sig
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VOID_SIGHANDLER
argument_list|)
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* VOID_SIGHANDLER */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGWINCH */
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
comment|/* Interrupt handling. */
end_comment

begin_decl_stmt
specifier|static
name|SigHandler
modifier|*
name|old_int
init|=
operator|(
name|SigHandler
operator|*
operator|)
name|NULL
decl_stmt|,
modifier|*
name|old_alrm
init|=
operator|(
name|SigHandler
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SHELL
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|SigHandler
modifier|*
name|old_tstp
init|=
operator|(
name|SigHandler
operator|*
operator|)
name|NULL
decl_stmt|,
modifier|*
name|old_ttou
init|=
operator|(
name|SigHandler
operator|*
operator|)
name|NULL
decl_stmt|,
modifier|*
name|old_ttin
init|=
operator|(
name|SigHandler
operator|*
operator|)
name|NULL
decl_stmt|,
modifier|*
name|old_cont
init|=
operator|(
name|SigHandler
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SHELL */
end_comment

begin_comment
comment|/* Handle an interrupt character. */
end_comment

begin_function
specifier|static
name|sighandler
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
endif|#
directive|endif
comment|/* HAVE_BSD_SIGNALS */
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
condition|)
name|signal
argument_list|(
name|sig
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* !HAVE_BSD_SIGNALS */
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
name|rl_init_argument
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
name|rl_clean_up_for_exit
argument_list|()
expr_stmt|;
name|rl_deprep_terminal
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
name|rl_prep_terminal
argument_list|(
name|_rl_meta_flag
argument_list|)
expr_stmt|;
name|rl_set_signals
argument_list|()
expr_stmt|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VOID_SIGHANDLER
argument_list|)
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* !VOID_SIGHANDLER */
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_POSIX_SIGNALS
argument_list|)
end_if

begin_function
specifier|static
name|SigHandler
modifier|*
name|rl_set_sighandler
parameter_list|(
name|sig
parameter_list|,
name|handler
parameter_list|)
name|int
name|sig
decl_stmt|;
name|SigHandler
modifier|*
name|handler
decl_stmt|;
block|{
name|struct
name|sigaction
name|act
decl_stmt|,
name|oact
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
name|oact
operator|.
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
operator|&
name|oact
argument_list|)
expr_stmt|;
return|return
operator|(
name|oact
operator|.
name|sa_handler
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_POSIX_SIGNALS */
end_comment

begin_define
define|#
directive|define
name|rl_set_sighandler
parameter_list|(
name|sig
parameter_list|,
name|handler
parameter_list|)
value|(SigHandler *)signal (sig, handler)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_POSIX_SIGNALS */
end_comment

begin_macro
name|rl_set_signals
argument_list|()
end_macro

begin_block
block|{
name|old_int
operator|=
operator|(
name|SigHandler
operator|*
operator|)
name|rl_set_sighandler
argument_list|(
name|SIGINT
argument_list|,
name|rl_signal_handler
argument_list|)
expr_stmt|;
if|if
condition|(
name|old_int
operator|==
operator|(
name|SigHandler
operator|*
operator|)
name|SIG_IGN
condition|)
name|rl_set_sighandler
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|old_alrm
operator|=
operator|(
name|SigHandler
operator|*
operator|)
name|rl_set_sighandler
argument_list|(
name|SIGALRM
argument_list|,
name|rl_signal_handler
argument_list|)
expr_stmt|;
if|if
condition|(
name|old_alrm
operator|==
operator|(
name|SigHandler
operator|*
operator|)
name|SIG_IGN
condition|)
name|rl_set_sighandler
argument_list|(
name|SIGALRM
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SHELL
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|SIGTSTP
argument_list|)
name|old_tstp
operator|=
operator|(
name|SigHandler
operator|*
operator|)
name|rl_set_sighandler
argument_list|(
name|SIGTSTP
argument_list|,
name|rl_signal_handler
argument_list|)
expr_stmt|;
if|if
condition|(
name|old_tstp
operator|==
operator|(
name|SigHandler
operator|*
operator|)
name|SIG_IGN
condition|)
name|rl_set_sighandler
argument_list|(
name|SIGTSTP
argument_list|,
name|SIG_IGN
argument_list|)
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
name|old_ttou
operator|=
operator|(
name|SigHandler
operator|*
operator|)
name|rl_set_sighandler
argument_list|(
name|SIGTTOU
argument_list|,
name|rl_signal_handler
argument_list|)
expr_stmt|;
name|old_ttin
operator|=
operator|(
name|SigHandler
operator|*
operator|)
name|rl_set_sighandler
argument_list|(
name|SIGTTIN
argument_list|,
name|rl_signal_handler
argument_list|)
expr_stmt|;
if|if
condition|(
name|old_tstp
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
argument_list|)
expr_stmt|;
name|rl_set_sighandler
argument_list|(
name|SIGTTIN
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* SIGTTOU */
endif|#
directive|endif
comment|/* !SHELL */
if|#
directive|if
name|defined
argument_list|(
name|SIGWINCH
argument_list|)
name|old_sigwinch
operator|=
operator|(
name|SigHandler
operator|*
operator|)
name|rl_set_sighandler
argument_list|(
name|SIGWINCH
argument_list|,
name|rl_handle_sigwinch
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SIGWINCH */
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|rl_clear_signals
argument_list|()
end_macro

begin_block
block|{
name|rl_set_sighandler
argument_list|(
name|SIGINT
argument_list|,
name|old_int
argument_list|)
expr_stmt|;
name|rl_set_sighandler
argument_list|(
name|SIGALRM
argument_list|,
name|old_alrm
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SHELL
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|SIGTSTP
argument_list|)
name|rl_set_sighandler
argument_list|(
name|SIGTSTP
argument_list|,
name|old_tstp
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
name|rl_set_sighandler
argument_list|(
name|SIGTTOU
argument_list|,
name|old_ttou
argument_list|)
expr_stmt|;
name|rl_set_sighandler
argument_list|(
name|SIGTTIN
argument_list|,
name|old_ttin
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SIGTTOU */
endif|#
directive|endif
comment|/* !SHELL */
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
name|old_sigwinch
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
comment|/* HANDLE_SIGNALS */
end_comment

end_unit

