begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interfaces to system-dependent kernel and library entries.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"lisp.h"
end_include

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_comment
comment|/* In this file, open, read and write refer to the system calls,    not our sugared interfaces  sys_open, sys_read and sys_write.    Contrariwise, for systems where we use the system calls directly,    define sys_read, etc. here as aliases for them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|read
end_ifndef

begin_define
define|#
directive|define
name|sys_read
value|read
end_define

begin_define
define|#
directive|define
name|sys_write
value|write
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* `read' is not a macro */
end_comment

begin_undef
undef|#
directive|undef
name|read
end_undef

begin_undef
undef|#
directive|undef
name|write
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|open
end_ifndef

begin_define
define|#
directive|define
name|sys_open
value|open
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* `open' is not a macro.  */
end_comment

begin_undef
undef|#
directive|undef
name|open
end_undef

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
file|<sys/stat.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD4_1
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_1
end_ifdef

begin_include
include|#
directive|include
file|<wait.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not 4.1 */
end_comment

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not 4.1 */
end_comment

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_define
define|#
directive|define
name|TERMINAL
value|struct sgttyb
end_define

begin_define
define|#
directive|define
name|OSPEED
parameter_list|(
name|str
parameter_list|)
value|str.sg_ospeed
end_define

begin_define
define|#
directive|define
name|TABS_OK
parameter_list|(
name|str
parameter_list|)
value|((str.sg_flags& XTABS) != XTABS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get rid of LLITOUT in 4.1, since it is said to stimulate kernel bugs.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_1
end_ifdef

begin_undef
undef|#
directive|undef
name|LLITOUT
end_undef

begin_define
define|#
directive|define
name|LLITOUT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 4.1 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TIMEVAL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TIMEVAL */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_define
define|#
directive|define
name|TIOCGETP
value|TCGETA
end_define

begin_define
define|#
directive|define
name|TIOCSETN
value|TCSETA
end_define

begin_define
define|#
directive|define
name|TIOCSETP
value|TCSETAF
end_define

begin_define
define|#
directive|define
name|TERMINAL
value|struct termio
end_define

begin_define
define|#
directive|define
name|OSPEED
parameter_list|(
name|str
parameter_list|)
value|(str.c_cflag& CBAUD)
end_define

begin_define
define|#
directive|define
name|TABS_OK
parameter_list|(
name|str
parameter_list|)
value|((str.c_oflag& TABDLY) != TAB3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USG */
end_comment

begin_include
include|#
directive|include
file|"termhooks.h"
end_include

begin_include
include|#
directive|include
file|"termchar.h"
end_include

begin_include
include|#
directive|include
file|"termopts.h"
end_include

begin_include
include|#
directive|include
file|"dispextern.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NONSYSTEM_DIR_LIBRARY
end_ifdef

begin_include
include|#
directive|include
file|"ndir.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NONSYSTEM_DIR_LIBRARY */
end_comment

begin_comment
comment|/* Define SIGCHLD as an alias for SIGCLD.  There are many conditionals    testing SIGCHLD.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SIGCHLD
argument_list|)
operator|&&
name|defined
argument_list|(
name|SIGCLD
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGCHLD
value|SIGCLD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGCLD and not SIGCHLD */
end_comment

begin_decl_stmt
specifier|static
name|int
name|baud_convert
index|[]
init|=
block|{
literal|0
block|,
literal|50
block|,
literal|75
block|,
literal|110
block|,
literal|135
block|,
literal|150
block|,
literal|200
block|,
literal|300
block|,
literal|600
block|,
literal|1200
block|,
literal|1800
block|,
literal|2400
block|,
literal|4800
block|,
literal|9600
block|,
literal|19200
block|,
literal|38400
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|ospeed
decl_stmt|;
end_decl_stmt

begin_macro
name|discard_tty_input
argument_list|()
end_macro

begin_block
block|{
name|TERMINAL
name|buf
decl_stmt|;
if|if
condition|(
name|noninteractive
condition|)
return|return;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGETP
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSETP
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|SIGTSTP
end_ifdef

begin_macro
name|stuff_char
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Should perhaps error if in batch mode */
ifdef|#
directive|ifdef
name|TIOCSTI
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSTI
argument_list|,
operator|&
name|c
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* no TIOCSTI */
name|error
argument_list|(
literal|"Cannot stuff terminal input characters in this version of Unix."
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* no TIOCSTI */
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGTSTP */
end_comment

begin_macro
name|init_baud_rate
argument_list|()
end_macro

begin_block
block|{
name|TERMINAL
name|sg
decl_stmt|;
if|if
condition|(
name|noninteractive
condition|)
name|ospeed
operator|=
literal|0
expr_stmt|;
else|else
block|{
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGETP
argument_list|,
operator|&
name|sg
argument_list|)
expr_stmt|;
name|ospeed
operator|=
name|OSPEED
argument_list|(
name|sg
argument_list|)
expr_stmt|;
block|}
name|baud_rate
operator|=
name|ospeed
operator|==
literal|0
condition|?
literal|1200
else|:
name|ospeed
operator|<
sizeof|sizeof
name|baud_convert
operator|/
sizeof|sizeof
name|baud_convert
index|[
literal|0
index|]
condition|?
name|baud_convert
index|[
name|ospeed
index|]
else|:
literal|9600
expr_stmt|;
block|}
end_block

begin_macro
name|set_exclusive_use
argument_list|(
argument|fd
argument_list|)
end_macro

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|FIOCLEX
name|ioctl
argument_list|(
name|fd
argument_list|,
name|FIOCLEX
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Ok to do nothing if this feature does not exist */
block|}
end_block

begin_ifndef
ifndef|#
directive|ifndef
name|subprocesses
end_ifndef

begin_macro
name|wait_without_blocking
argument_list|()
end_macro

begin_block
block|{
ifndef|#
directive|ifndef
name|USG
name|wait3
argument_list|(
literal|0
argument_list|,
name|WNOHANG
operator||
name|WUNTRACED
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
name|croak
argument_list|(
literal|"wait_without_blocking"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not subprocesses */
end_comment

begin_decl_stmt
name|int
name|wait_debugging
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set nonzero to make following function work under dbx 		         (at least for bsd).  */
end_comment

begin_comment
comment|/* Wait for subprocess with process id `pid' to terminate and    make sure it will get eliminated (not remain forever as a zombie) */
end_comment

begin_macro
name|wait_for_termination
argument_list|(
argument|pid
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pid
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|status
decl_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
ifdef|#
directive|ifdef
name|subprocesses
ifdef|#
directive|ifdef
name|BSD
comment|/* Note that kill returns -1 even if the process is just a zombie now. 	 But inevitably a SIGCHLD interrupt should be generated 	 and child_sig will do wait3 and make the process go away. */
comment|/* There is some indication that there is a bug involved with 	 termination of subprocesses, perhaps involving a kernel bug too, 	 but no idea what it is.  Just as a hunch we signal SIGCHLD to see 	 if that causes the problem to go away or get worse.  */
ifdef|#
directive|ifdef
name|BSD4_1
specifier|extern
name|int
name|synch_process_pid
decl_stmt|;
name|sighold
argument_list|(
name|SIGCHLD
argument_list|)
expr_stmt|;
if|if
condition|(
name|synch_process_pid
operator|==
literal|0
condition|)
block|{
name|sigrelse
argument_list|(
name|SIGCHLD
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|wait_debugging
condition|)
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
else|else
name|sigpause
argument_list|(
name|SIGCHLD
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* not BSD4_1 */
name|sigsetmask
argument_list|(
literal|1
operator|<<
operator|(
name|SIGCHLD
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
literal|0
operator|>
name|kill
argument_list|(
name|pid
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|sigsetmask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGCHLD
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|wait_debugging
condition|)
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
else|else
name|sigpause
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* not BSD4_1 */
else|#
directive|else
comment|/* not BSD */
ifdef|#
directive|ifdef
name|UNIPLUS
if|if
condition|(
literal|0
operator|>
name|kill
argument_list|(
name|pid
argument_list|,
literal|0
argument_list|)
condition|)
break|break;
name|wait
argument_list|(
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* neither BSD nor UNIPLUS: random sysV */
if|if
condition|(
literal|0
operator|>
name|kill
argument_list|(
name|pid
argument_list|,
literal|0
argument_list|)
condition|)
break|break;
name|pause
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* not UNIPLUS */
endif|#
directive|endif
comment|/* not BSD */
else|#
directive|else
comment|/* not subprocesses */
ifndef|#
directive|ifndef
name|BSD4_1
if|if
condition|(
literal|0
operator|>
name|kill
argument_list|(
name|pid
argument_list|,
literal|0
argument_list|)
condition|)
break|break;
name|wait
argument_list|(
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* BSD4_1 */
name|int
name|status
decl_stmt|;
name|status
operator|=
name|wait
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|==
name|pid
operator|||
name|status
operator|==
operator|-
literal|1
condition|)
break|break;
endif|#
directive|endif
comment|/* BSD4_1 */
endif|#
directive|endif
comment|/* not subprocesses */
block|}
block|}
end_block

begin_comment
comment|/*  *	Insert description of what this command is really supposed to  *	to (I.E. what state is the child process line to be placed into,  *	and why).  I have tried to interpret this as much as possible from  *	the BSD setup and map to an appropriate USG control, but don't  *	guarantee the results.  fnf@unisoft  */
end_comment

begin_macro
name|child_setup_tty
argument_list|(
argument|out
argument_list|)
end_macro

begin_decl_stmt
name|int
name|out
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|TERMINAL
name|s
decl_stmt|;
name|ioctl
argument_list|(
name|out
argument_list|,
name|TIOCGETP
argument_list|,
operator|&
name|s
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|USG
name|s
operator|.
name|c_oflag
operator||=
name|OPOST
expr_stmt|;
comment|/* Enable output postprocessing */
name|s
operator|.
name|c_oflag
operator|&=
operator|~
name|ONLCR
expr_stmt|;
comment|/* Disable map of NL to CR-NL on output */
name|s
operator|.
name|c_oflag
operator|&=
operator|~
operator|(
name|NLDLY
operator||
name|CRDLY
operator||
name|TABDLY
operator||
name|BSDLY
operator||
name|VTDLY
operator||
name|FFDLY
operator|)
expr_stmt|;
comment|/* No output delays */
name|s
operator|.
name|c_lflag
operator|&=
operator|~
name|ECHO
expr_stmt|;
comment|/* Disable echo */
name|s
operator|.
name|c_lflag
operator|&=
operator|~
name|ICANON
expr_stmt|;
comment|/* Disable erase/kill processing */
name|s
operator|.
name|c_lflag
operator||=
name|ISIG
expr_stmt|;
comment|/* Enable signals */
name|s
operator|.
name|c_iflag
operator|&=
operator|~
name|IUCLC
expr_stmt|;
comment|/* Disable map of upper case to lower on input */
name|s
operator|.
name|c_oflag
operator|&=
operator|~
name|OLCUC
expr_stmt|;
comment|/* Disable map of lower case to upper on output */
name|s
operator|.
name|c_cc
index|[
name|VMIN
index|]
operator|=
literal|1
expr_stmt|;
comment|/* minimum number of characters to accept */
name|s
operator|.
name|c_cc
index|[
name|VTIME
index|]
operator|=
literal|0
expr_stmt|;
comment|/* wait forever for at least 1 character */
else|#
directive|else
comment|/* not USG */
name|s
operator|.
name|sg_flags
operator|&=
operator|~
operator|(
name|ECHO
operator||
name|CRMOD
operator||
name|ANYP
operator||
name|ALLDELAY
operator||
name|RAW
operator||
name|LCASE
operator||
name|CBREAK
operator||
name|TANDEM
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* not USG */
name|ioctl
argument_list|(
name|out
argument_list|,
name|TIOCSETN
argument_list|,
operator|&
name|s
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|BSD4_1
if|if
condition|(
name|interrupt_input
condition|)
name|reset_sigio
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* BSD4_1 */
block|}
end_block

begin_macro
name|setpgrp_of_tty
argument_list|(
argument|pid
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pid
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|TIOCSPGRP
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSPGRP
argument_list|,
operator|&
name|pid
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Just ignore this for now and hope for the best */
endif|#
directive|endif
block|}
end_block

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|F_SETFL
end_ifdef

begin_macro
name|init_sigio
argument_list|()
end_macro

begin_block
block|{
name|request_sigio
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|reset_sigio
argument_list|()
end_macro

begin_block
block|{
name|unrequest_sigio
argument_list|()
expr_stmt|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|FASYNC
end_ifdef

begin_comment
comment|/* F_SETFL does not imply existance of FASYNC */
end_comment

begin_decl_stmt
name|int
name|old_fcntl_flags
decl_stmt|;
end_decl_stmt

begin_macro
name|request_sigio
argument_list|()
end_macro

begin_block
block|{
name|old_fcntl_flags
operator|=
name|fcntl
argument_list|(
literal|0
argument_list|,
name|F_GETFL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|fcntl
argument_list|(
literal|0
argument_list|,
name|F_SETFL
argument_list|,
name|old_fcntl_flags
operator||
name|FASYNC
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|unrequest_sigio
argument_list|()
end_macro

begin_block
block|{
name|fcntl
argument_list|(
literal|0
argument_list|,
name|F_SETFL
argument_list|,
name|old_fcntl_flags
argument_list|)
expr_stmt|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no FASYNC */
end_comment

begin_macro
name|request_sigio
argument_list|()
end_macro

begin_block
block|{
name|croak
argument_list|(
literal|"request_sigio"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|unrequest_sigio
argument_list|()
end_macro

begin_block
block|{
name|croak
argument_list|(
literal|"unrequest_sigio"
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FASYNC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* F_SETFL */
end_comment

begin_escape
end_escape

begin_decl_stmt
name|TERMINAL
name|old_gtty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The initial tty mode bits */
end_comment

begin_decl_stmt
name|int
name|term_initted
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if outer tty status has been recorded */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|F_SETOWN
end_ifdef

begin_decl_stmt
name|int
name|old_fcntl_owner
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* F_SETOWN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCGLTC
end_ifdef

begin_decl_stmt
name|struct
name|tchars
name|old_tchars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ltchars
name|old_ltchars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|old_lmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current lmode value. */
end_comment

begin_comment
comment|/* Needed as global for 4.1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIOCGLTC */
end_comment

begin_comment
comment|/* This may also be defined in stdio,    but if so, this does no harm,    and using the same name avoids wasting the other one's space.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_decl_stmt
name|unsigned
name|char
name|_sobuf
index|[
name|BUFSIZ
operator|+
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
name|_sobuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|init_sys_modes
argument_list|()
end_macro

begin_block
block|{
name|TERMINAL
name|sg
decl_stmt|;
ifdef|#
directive|ifdef
name|TIOCGLTC
name|struct
name|tchars
name|tchars
decl_stmt|;
specifier|static
name|struct
name|tchars
name|new_tchars
init|=
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|}
decl_stmt|;
specifier|static
name|struct
name|ltchars
name|new_ltchars
init|=
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|}
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|noninteractive
condition|)
return|return;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGETP
argument_list|,
operator|&
name|old_gtty
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|read_socket_hook
condition|)
block|{
name|sg
operator|=
name|old_gtty
expr_stmt|;
ifdef|#
directive|ifdef
name|USG
name|sg
operator|.
name|c_iflag
operator||=
operator|(
name|IGNBRK
operator|)
expr_stmt|;
comment|/* Ignore break condition */
name|sg
operator|.
name|c_iflag
operator|&=
operator|~
name|ICRNL
expr_stmt|;
comment|/* Disable map of CR to NL on input */
ifdef|#
directive|ifdef
name|ISTRIP
name|sg
operator|.
name|c_iflag
operator|&=
operator|~
name|ISTRIP
expr_stmt|;
comment|/* don't strip 8th bit on input */
endif|#
directive|endif
name|sg
operator|.
name|c_lflag
operator|&=
operator|~
name|ECHO
expr_stmt|;
comment|/* Disable echo */
name|sg
operator|.
name|c_lflag
operator|&=
operator|~
name|ICANON
expr_stmt|;
comment|/* Disable erase/kill processing */
name|sg
operator|.
name|c_lflag
operator||=
name|ISIG
expr_stmt|;
comment|/* Enable signals */
if|if
condition|(
name|flow_control
condition|)
block|{
name|sg
operator|.
name|c_iflag
operator||=
name|IXON
expr_stmt|;
comment|/* Enable start/stop output control */
ifdef|#
directive|ifdef
name|IXANY
name|sg
operator|.
name|c_iflag
operator|&=
operator|~
name|IXANY
expr_stmt|;
endif|#
directive|endif
comment|/* IXANY */
block|}
else|else
name|sg
operator|.
name|c_iflag
operator|&=
operator|~
name|IXON
expr_stmt|;
comment|/* Disable start/stop output control */
name|sg
operator|.
name|c_oflag
operator|&=
operator|~
name|ONLCR
expr_stmt|;
comment|/* Disable map of NL to CR-NL on output */
name|sg
operator|.
name|c_oflag
operator|&=
operator|~
name|TAB3
expr_stmt|;
comment|/* Disable tab expansion */
ifdef|#
directive|ifdef
name|CS8
name|sg
operator|.
name|c_cflag
operator||=
name|CS8
expr_stmt|;
comment|/* allow 8th bit on input */
name|sg
operator|.
name|c_cflag
operator|&=
operator|~
name|PARENB
expr_stmt|;
comment|/* Don't check parity */
endif|#
directive|endif
name|sg
operator|.
name|c_cc
index|[
name|VINTR
index|]
operator|=
literal|'\007'
expr_stmt|;
comment|/* ^G gives SIGINT */
ifdef|#
directive|ifdef
name|HPUX
comment|/* Can't use CDEL as that makes Meta-DEL do SIGQUIT. 	 Instead set up C-g for both; we handle both alike 	 so which one it really gives us does not matter.  */
name|sg
operator|.
name|c_cc
index|[
name|VQUIT
index|]
operator|=
literal|'\007'
expr_stmt|;
else|#
directive|else
comment|/* not HPUX */
name|sg
operator|.
name|c_cc
index|[
name|VQUIT
index|]
operator|=
name|CDEL
expr_stmt|;
comment|/* Turn off SIGQUIT */
endif|#
directive|endif
comment|/* not HPUX */
name|sg
operator|.
name|c_cc
index|[
name|VMIN
index|]
operator|=
literal|1
expr_stmt|;
comment|/* Input should wait for at least 1 char */
name|sg
operator|.
name|c_cc
index|[
name|VTIME
index|]
operator|=
literal|0
expr_stmt|;
comment|/* no matter how long that takes.  */
ifdef|#
directive|ifdef
name|VSWTCH
name|sg
operator|.
name|c_cc
index|[
name|VSWTCH
index|]
operator|=
name|CDEL
expr_stmt|;
comment|/* Turn off shell layering use of C-z */
endif|#
directive|endif
comment|/* VSWTCH */
else|#
directive|else
comment|/* if not USG */
name|sg
operator|.
name|sg_flags
operator|&=
operator|~
operator|(
name|ECHO
operator||
name|CRMOD
operator||
name|XTABS
operator|)
expr_stmt|;
name|sg
operator|.
name|sg_flags
operator||=
name|ANYP
expr_stmt|;
name|sg
operator|.
name|sg_flags
operator||=
name|interrupt_input
condition|?
name|RAW
else|:
name|CBREAK
expr_stmt|;
endif|#
directive|endif
comment|/* not USG (BSD, that is) */
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSETN
argument_list|,
operator|&
name|sg
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|F_SETFL
ifdef|#
directive|ifdef
name|F_GETOWN
comment|/* F_SETFL does not imply existance of F_GETOWN */
if|if
condition|(
name|interrupt_input
condition|)
block|{
name|old_fcntl_owner
operator|=
name|fcntl
argument_list|(
literal|0
argument_list|,
name|F_GETOWN
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|fcntl
argument_list|(
literal|0
argument_list|,
name|F_SETOWN
argument_list|,
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
name|init_sigio
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* F_GETOWN */
endif|#
directive|endif
comment|/* F_SETFL */
comment|/* If going to use CBREAK mode, we must request C-g to interrupt 	   and turn off start and stop chars, etc. 	   If not going to use CBREAK mode, do this anyway 	   so as to turn off local flow control for user coming over 	   network on 4.2; in this case, only t_stopc and t_startc really matter.  */
ifdef|#
directive|ifdef
name|TIOCGLTC
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGETC
argument_list|,
operator|&
name|old_tchars
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGLTC
argument_list|,
operator|&
name|old_ltchars
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCLGET
argument_list|,
operator|&
name|old_lmode
argument_list|)
expr_stmt|;
comment|/* Note: if not using CBREAK mode, it makes no difference how we set this */
name|tchars
operator|=
name|new_tchars
expr_stmt|;
name|tchars
operator|.
name|t_intrc
operator|=
literal|07
expr_stmt|;
if|if
condition|(
name|flow_control
condition|)
block|{
name|tchars
operator|.
name|t_startc
operator|=
literal|'\021'
expr_stmt|;
name|tchars
operator|.
name|t_stopc
operator|=
literal|'\023'
expr_stmt|;
block|}
comment|/* LPASS8 is new in 4.3, and makes cbreak mode provide all 8 bits.  */
ifndef|#
directive|ifndef
name|LPASS8
define|#
directive|define
name|LPASS8
value|0
endif|#
directive|endif
ifdef|#
directive|ifdef
name|BSD4_1
define|#
directive|define
name|LNOFLSH
value|0100000
endif|#
directive|endif
name|lmode
operator|=
name|LDECCTQ
operator||
name|LLITOUT
operator||
name|LPASS8
operator||
name|LNOFLSH
operator||
name|old_lmode
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSETC
argument_list|,
operator|&
name|tchars
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSLTC
argument_list|,
operator|&
name|new_ltchars
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCLSET
argument_list|,
operator|&
name|lmode
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|TIOCGLTC
ifdef|#
directive|ifdef
name|BSD4_1
if|if
condition|(
name|interrupt_input
condition|)
name|init_sigio
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
name|screen_garbaged
operator|=
literal|1
expr_stmt|;
name|setbuf
argument_list|(
name|stdout
argument_list|,
name|_sobuf
argument_list|)
expr_stmt|;
name|term_initted
operator|=
literal|1
expr_stmt|;
name|set_terminal_modes
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Return nonzero if safe to use tabs in output.    At the time this is called, init_sys_modes has not been done yet.  */
end_comment

begin_macro
name|tabs_safe_p
argument_list|()
end_macro

begin_block
block|{
name|TERMINAL
name|sg
decl_stmt|;
if|if
condition|(
name|noninteractive
condition|)
return|return
literal|1
return|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGETP
argument_list|,
operator|&
name|sg
argument_list|)
expr_stmt|;
return|return
operator|(
name|TABS_OK
argument_list|(
name|sg
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/* Get terminal size from system.    Store number of lines into *heightp and width into *widthp.    If zero or a negative number is stored, the value is not valid.  */
end_comment

begin_macro
name|get_screen_size
argument_list|(
argument|widthp
argument_list|,
argument|heightp
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|widthp
decl_stmt|,
modifier|*
name|heightp
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Define the 4.3 names in terms of the Sun names    if the latter exist and the former do not.  */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TIOCGWINSZ
argument_list|)
operator|&&
name|defined
argument_list|(
name|TIOCGSIZE
argument_list|)
define|#
directive|define
name|TIOCGWINSZ
value|TIOCGSIZE
define|#
directive|define
name|winsize
value|ttysize
define|#
directive|define
name|ws_row
value|ts_lines
define|#
directive|define
name|ws_col
value|ts_cols
endif|#
directive|endif
comment|/* Sun */
ifdef|#
directive|ifdef
name|TIOCGWINSZ
name|struct
name|winsize
name|size
decl_stmt|;
operator|*
name|widthp
operator|=
literal|0
expr_stmt|;
operator|*
name|heightp
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGWINSZ
argument_list|,
operator|&
name|size
argument_list|)
operator|<
literal|0
condition|)
return|return;
operator|*
name|widthp
operator|=
name|size
operator|.
name|ws_col
expr_stmt|;
operator|*
name|heightp
operator|=
name|size
operator|.
name|ws_row
expr_stmt|;
else|#
directive|else
comment|/* system doesn't know size */
operator|*
name|widthp
operator|=
literal|0
expr_stmt|;
operator|*
name|heightp
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* system does not know size */
block|}
end_block

begin_escape
end_escape

begin_macro
name|reset_sys_modes
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|noninteractive
condition|)
block|{
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|term_initted
condition|)
return|return;
name|topos
argument_list|(
name|screen_height
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|clear_end_of_line
argument_list|(
name|screen_width
argument_list|)
expr_stmt|;
comment|/* clear_end_of_line may move the cursor */
name|topos
argument_list|(
name|screen_height
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|reset_terminal_modes
argument_list|()
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
if|if
condition|(
name|read_socket_hook
condition|)
return|return;
ifdef|#
directive|ifdef
name|TIOCGLTC
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSETC
argument_list|,
operator|&
name|old_tchars
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSLTC
argument_list|,
operator|&
name|old_ltchars
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCLSET
argument_list|,
operator|&
name|old_lmode
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TIOCGLTC */
ifdef|#
directive|ifdef
name|F_SETFL
ifdef|#
directive|ifdef
name|F_SETOWN
comment|/* F_SETFL does not imply existance of F_SETOWN */
if|if
condition|(
name|interrupt_input
condition|)
block|{
ifdef|#
directive|ifdef
name|FASYNC
name|old_fcntl_flags
operator|&=
operator|~
name|FASYNC
expr_stmt|;
endif|#
directive|endif
comment|/* FASYNC */
name|reset_sigio
argument_list|()
expr_stmt|;
name|reset_sigio
argument_list|()
expr_stmt|;
name|fcntl
argument_list|(
literal|0
argument_list|,
name|F_SETOWN
argument_list|,
name|old_fcntl_owner
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* F_SETOWN */
endif|#
directive|endif
comment|/* F_SETFL */
ifdef|#
directive|ifdef
name|BSD4_1
if|if
condition|(
name|interrupt_input
condition|)
name|reset_sigio
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* BSD4_1 */
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSETN
argument_list|,
operator|&
name|old_gtty
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  *	flush any pending output  */
end_comment

begin_macro
name|flush_pending_output
argument_list|(
argument|channel
argument_list|)
end_macro

begin_decl_stmt
name|int
name|channel
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|USG
name|ioctl
argument_list|(
name|channel
argument_list|,
name|TCFLSH
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|#
directive|else
name|ioctl
argument_list|(
name|channel
argument_list|,
name|TIOCFLUSH
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_comment
comment|/*  *	Return the address of the start of the text segment prior to  *	doing an unexec().  After unexec() the return value is undefined.  *	See crt0.c for further explanation and _start().  *  */
end_comment

begin_function
name|char
modifier|*
name|start_of_text
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|TEXT_START
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|TEXT_START
operator|)
return|;
else|#
directive|else
specifier|extern
name|int
name|_start
parameter_list|()
function_decl|;
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|_start
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  *	Return the address of the start of the data segment prior to  *	doing an unexec().  After unexec() the return value is undefined.  *	See crt0.c for further information and definition of data_start.  *  *	Apparently, on BSD systems this is etext at startup.  On  *	USG systems (swapping) this is highly mmu dependent and  *	is also dependent on whether or not the program is running  *	with shared text.  Generally there is a (possibly large)  *	gap between end of text and start of data with shared text.  *  *	On Uniplus+ systems with shared text, data starts at a  *	fixed address.  Each port (from a given oem) is generally  *	different, and the specific value of the start of data can  *	be obtained via the UniPlus+ specific "uvar(2)" system call,  *	however the method outlined in crt0.c seems to be more portable.  *  *	Probably what will have to happen when a USG unexec is available,  *	at least on UniPlus, is temacs will have to be made unshared so  *	that text and data are contiguous.  Then once loadup is complete,  *	unexec will produce a shared executable where the data can be  *	at the normal shared text boundry and the startofdata variable  *	will be patched by unexec to the correct value.  *  */
end_comment

begin_function
name|char
modifier|*
name|start_of_data
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|DATA_START
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|DATA_START
operator|)
return|;
else|#
directive|else
specifier|extern
name|int
name|data_start
decl_stmt|;
return|return
operator|(
operator|(
name|char
operator|*
operator|)
operator|&
name|data_start
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|NOTDEF
end_ifdef

begin_comment
comment|/*  *	Return the address of the end of the text segment prior to  *	doing an unexec().  After unexec() the return value is undefined.  */
end_comment

begin_function
name|char
modifier|*
name|end_of_text
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|TEXT_END
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|TEXT_END
operator|)
return|;
else|#
directive|else
specifier|extern
name|int
name|etext
decl_stmt|;
return|return
operator|(
operator|(
name|char
operator|*
operator|)
operator|&
name|etext
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  *	Return the address of the end of the data segment prior to  *	doing an unexec().  After unexec() the return value is undefined.  */
end_comment

begin_function
name|char
modifier|*
name|end_of_data
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|DATA_END
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|DATA_END
operator|)
return|;
else|#
directive|else
specifier|extern
name|int
name|edata
decl_stmt|;
return|return
operator|(
operator|(
name|char
operator|*
operator|)
operator|&
name|edata
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
endif|NOTDEF
end_endif

begin_escape
end_escape

begin_comment
comment|/* Get_system_name returns as its value  a string for the Lisp function system-name to return. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_decl_stmt
name|struct
name|utsname
name|get_system_name_name
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_1
end_ifdef

begin_include
include|#
directive|include
file|<whoami.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|get_system_name
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|USG
name|uname
argument_list|(
operator|&
name|get_system_name_name
argument_list|)
expr_stmt|;
return|return
operator|(
name|get_system_name_name
operator|.
name|nodename
operator|)
return|;
else|#
directive|else
comment|/* Not USG */
ifdef|#
directive|ifdef
name|BSD4_1
return|return
name|sysname
return|;
else|#
directive|else
comment|/* BSD, not 4.1 */
specifier|static
name|char
name|system_name_saved
index|[
literal|32
index|]
decl_stmt|;
operator|(
name|void
operator|)
name|gethostname
argument_list|(
name|system_name_saved
argument_list|,
sizeof|sizeof
argument_list|(
name|system_name_saved
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|system_name_saved
operator|)
return|;
endif|#
directive|endif
comment|/* BSD, not 4.1 */
endif|#
directive|endif
comment|/* not USG */
block|}
end_function

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SELECT
end_ifndef

begin_comment
comment|/* Emulate as much as select as is possible under 4.1 and needed by Gnu Emacs  * Only checks read descriptors.  */
end_comment

begin_comment
comment|/* How long to wait between checking fds in select */
end_comment

begin_define
define|#
directive|define
name|SELECT_PAUSE
value|1
end_define

begin_decl_stmt
name|int
name|select_alarmed
decl_stmt|;
end_decl_stmt

begin_macro
name|select_alarm
argument_list|()
end_macro

begin_block
block|{
name|select_alarmed
operator|=
literal|1
expr_stmt|;
ifdef|#
directive|ifdef
name|BSD4_1
name|sigrelse
argument_list|(
name|SIGALRM
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* not BSD4_1 */
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* not BSD4_1 */
block|}
end_block

begin_comment
comment|/* Only rfds are checked and timeout must point somewhere */
end_comment

begin_function
name|int
name|select
parameter_list|(
name|nfds
parameter_list|,
name|rfds
parameter_list|,
name|wfds
parameter_list|,
name|efds
parameter_list|,
name|timeout
parameter_list|)
name|int
name|nfds
decl_stmt|;
name|int
modifier|*
name|rfds
decl_stmt|,
decl|*
name|wfds
decl_stmt|,
modifier|*
name|efds
decl_stmt|,
modifier|*
name|timeout
decl_stmt|;
end_function

begin_block
block|{
name|int
name|ravail
init|=
literal|0
decl_stmt|,
name|orfds
init|=
literal|0
decl_stmt|,
name|old_alarm
decl_stmt|,
name|val
decl_stmt|;
specifier|extern
name|int
name|kbd_count
decl_stmt|;
specifier|extern
name|int
name|proc_buffered_char
index|[]
decl_stmt|;
specifier|extern
name|int
name|child_changed
decl_stmt|;
name|int
function_decl|(
modifier|*
name|old_trap
function_decl|)
parameter_list|()
function_decl|;
name|char
name|buf
decl_stmt|;
if|if
condition|(
name|rfds
condition|)
block|{
name|orfds
operator|=
operator|*
name|rfds
expr_stmt|;
operator|*
name|rfds
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|wfds
condition|)
operator|*
name|wfds
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|efds
condition|)
operator|*
name|efds
operator|=
literal|0
expr_stmt|;
comment|/* If we are looking only for the terminal, with no timeout,      just read it and wait -- that's more efficient.  */
if|if
condition|(
name|orfds
operator|==
literal|1
operator|&&
operator|*
name|timeout
operator|==
literal|100000
operator|&&
operator|!
name|child_changed
condition|)
block|{
if|if
condition|(
operator|!
name|kbd_count
condition|)
name|read_input_waiting
argument_list|()
expr_stmt|;
operator|*
name|rfds
operator|=
literal|1
expr_stmt|;
return|return
literal|1
return|;
block|}
comment|/* Once a second, till the timer expires, check all the flagged read    * descriptors to see if any input is available.  If there is some then    * set the corresponding bit in the return copy of rfds.    */
while|while
condition|(
literal|1
condition|)
block|{
specifier|register
name|int
name|to_check
decl_stmt|,
name|bit
decl_stmt|,
name|fd
decl_stmt|;
if|if
condition|(
name|rfds
condition|)
block|{
for|for
control|(
name|to_check
operator|=
name|nfds
operator|,
name|bit
operator|=
literal|1
operator|,
name|fd
operator|=
literal|0
init|;
operator|--
name|to_check
operator|>=
literal|0
condition|;
name|bit
operator|<<=
literal|1
operator|,
name|fd
operator|++
control|)
block|{
if|if
condition|(
name|orfds
operator|&
name|bit
condition|)
block|{
name|int
name|avail
init|=
literal|0
decl_stmt|,
name|status
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|bit
operator|==
literal|1
condition|)
name|avail
operator|=
name|detect_input_pending
argument_list|()
expr_stmt|;
comment|/* Special keyboard handler */
else|else
block|{
ifdef|#
directive|ifdef
name|FIONREAD
name|status
operator|=
name|ioctl
argument_list|(
name|fd
argument_list|,
name|FIONREAD
argument_list|,
operator|&
name|avail
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* no FIONREAD */
comment|/* Hoping it will return -1 if nothing available 			 or 0 if all 0 chars requested are read.  */
if|if
condition|(
name|proc_buffered_char
index|[
name|fd
index|]
operator|>=
literal|0
condition|)
name|avail
operator|=
literal|1
expr_stmt|;
else|else
block|{
name|avail
operator|=
name|read
argument_list|(
name|fd
argument_list|,
operator|&
name|buf
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|avail
operator|>
literal|0
condition|)
name|proc_buffered_char
index|[
name|fd
index|]
operator|=
name|buf
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* no FIONREAD */
block|}
if|if
condition|(
name|status
operator|>=
literal|0
operator|&&
name|avail
operator|>
literal|0
condition|)
block|{
operator|(
operator|*
name|rfds
operator|)
operator||=
name|bit
expr_stmt|;
name|ravail
operator|++
expr_stmt|;
block|}
block|}
block|}
block|}
if|if
condition|(
operator|*
name|timeout
operator|==
literal|0
operator|||
name|ravail
operator|!=
literal|0
operator|||
name|child_changed
condition|)
break|break;
name|old_alarm
operator|=
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|old_trap
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|select_alarm
argument_list|)
expr_stmt|;
name|select_alarmed
operator|=
literal|0
expr_stmt|;
name|alarm
argument_list|(
name|SELECT_PAUSE
argument_list|)
expr_stmt|;
comment|/* Wait for a SIGALRM (or maybe a SIGTINT) */
while|while
condition|(
name|select_alarmed
operator|==
literal|0
operator|&&
operator|*
name|timeout
operator|!=
literal|0
operator|&&
name|child_changed
operator|==
literal|0
condition|)
block|{
comment|/* If we are interested in terminal input, 	     wait by reading the terminal. 	     That makes instant wakeup for terminal input at least.  */
if|if
condition|(
name|orfds
operator|&
literal|1
condition|)
block|{
name|read_input_waiting
argument_list|()
expr_stmt|;
if|if
condition|(
name|kbd_count
condition|)
name|select_alarmed
operator|=
literal|1
expr_stmt|;
block|}
else|else
name|pause
argument_list|()
expr_stmt|;
block|}
operator|(
operator|*
name|timeout
operator|)
operator|-=
name|SELECT_PAUSE
expr_stmt|;
comment|/* Reset the old alarm if there was one */
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|old_trap
argument_list|)
expr_stmt|;
if|if
condition|(
name|old_alarm
operator|!=
literal|0
condition|)
block|{
comment|/* Reset or forge an interrupt for the original handler. */
name|old_alarm
operator|-=
name|SELECT_PAUSE
expr_stmt|;
if|if
condition|(
name|old_alarm
operator|<=
literal|0
condition|)
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGALRM
argument_list|)
expr_stmt|;
comment|/* Fake an alarm with the orig' handler */
else|else
name|alarm
argument_list|(
name|old_alarm
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|*
name|timeout
operator|==
literal|0
condition|)
comment|/* Stop on timer being cleared */
break|break;
block|}
return|return
name|ravail
return|;
block|}
end_block

begin_comment
comment|/* Read keyboard input into the standard buffer,    waiting for at least one character.  */
end_comment

begin_macro
name|read_input_waiting
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|int
name|kbd_count
decl_stmt|;
specifier|extern
name|unsigned
name|char
name|kbd_buffer
index|[]
decl_stmt|;
specifier|extern
name|unsigned
name|char
modifier|*
name|kbd_ptr
decl_stmt|;
name|int
name|val
init|=
name|read
argument_list|(
name|fileno
argument_list|(
name|stdin
argument_list|)
argument_list|,
name|kbd_buffer
argument_list|,
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|val
operator|>
literal|0
condition|)
block|{
name|kbd_ptr
operator|=
name|kbd_buffer
expr_stmt|;
name|kbd_count
operator|=
name|val
expr_stmt|;
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_SELECT */
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_1
end_ifdef

begin_comment
comment|/* VARARGS */
end_comment

begin_macro
name|setpriority
argument_list|()
end_macro

begin_block
block|{
return|return
literal|0
return|;
block|}
end_block

begin_comment
comment|/*  * Partially emulate 4.2 open call.  * open is defined as this in 4.1.  *  * - added by Michael Bloom @ Citicorp/TTI  *  */
end_comment

begin_function
name|int
name|sys_open
parameter_list|(
name|path
parameter_list|,
name|oflag
parameter_list|,
name|mode
parameter_list|)
name|char
modifier|*
name|path
decl_stmt|;
name|int
name|oflag
decl_stmt|,
name|mode
decl_stmt|;
block|{
if|if
condition|(
name|oflag
operator|&
name|O_CREAT
condition|)
return|return
name|creat
argument_list|(
name|path
argument_list|,
name|mode
argument_list|)
return|;
else|else
return|return
name|open
argument_list|(
name|path
argument_list|,
name|oflag
argument_list|)
return|;
block|}
end_function

begin_macro
name|init_sigio
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|noninteractive
condition|)
return|return;
name|lmode
operator|=
name|LINTRUP
operator||
name|lmode
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCLSET
argument_list|,
operator|&
name|lmode
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|reset_sigio
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|noninteractive
condition|)
return|return;
name|lmode
operator|=
operator|~
name|LINTRUP
operator|&
name|lmode
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCLSET
argument_list|,
operator|&
name|lmode
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|request_sigio
argument_list|()
end_macro

begin_block
block|{
name|sigrelse
argument_list|(
name|SIGTINT
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|unrequest_sigio
argument_list|()
end_macro

begin_block
block|{
name|sighold
argument_list|(
name|SIGTINT
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* still inside #ifdef BSD4_1 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|subprocesses
end_ifdef

begin_decl_stmt
name|int
name|sigheld
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mask of held signals */
end_comment

begin_macro
name|sigholdx
argument_list|(
argument|signum
argument_list|)
end_macro

begin_decl_stmt
name|int
name|signum
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|sigheld
operator||=
name|sigbit
argument_list|(
name|signum
argument_list|)
expr_stmt|;
name|sighold
argument_list|(
name|signum
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|sigisheld
argument_list|(
argument|signum
argument_list|)
end_macro

begin_decl_stmt
name|int
name|signum
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|sigheld
operator||=
name|sigbit
argument_list|(
name|signum
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|sigunhold
argument_list|(
argument|signum
argument_list|)
end_macro

begin_decl_stmt
name|int
name|signum
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|sigheld
operator|&=
operator|~
name|sigbit
argument_list|(
name|signum
argument_list|)
expr_stmt|;
name|sigrelse
argument_list|(
name|signum
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|sigfree
argument_list|()
end_macro

begin_comment
comment|/* Free all held signals */
end_comment

begin_block
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NSIG
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|sigheld
operator|&
name|sigbit
argument_list|(
name|i
argument_list|)
condition|)
name|sigrelse
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|sigheld
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_macro
name|sigbit
argument_list|(
argument|i
argument_list|)
end_macro

begin_block
block|{
return|return
literal|1
operator|<<
operator|(
name|i
operator|-
literal|1
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* subprocesses */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4_1 */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|BSTRING
end_ifndef

begin_function
name|void
name|bzero
parameter_list|(
name|b
parameter_list|,
name|length
parameter_list|)
specifier|register
name|char
modifier|*
name|b
decl_stmt|;
specifier|register
name|int
name|length
decl_stmt|;
block|{
while|while
condition|(
name|length
operator|--
operator|>
literal|0
condition|)
operator|*
name|b
operator|++
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
name|void
name|bcopy
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|length
parameter_list|)
specifier|register
name|char
modifier|*
name|b1
decl_stmt|;
specifier|register
name|char
modifier|*
name|b2
decl_stmt|;
specifier|register
name|int
name|length
decl_stmt|;
block|{
while|while
condition|(
name|length
operator|--
operator|>
literal|0
condition|)
operator|*
name|b2
operator|++
operator|=
operator|*
name|b1
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|int
name|bcmp
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|length
parameter_list|)
comment|/* This could be a macro! */
specifier|register
name|char
modifier|*
name|b1
decl_stmt|;
specifier|register
name|char
modifier|*
name|b2
decl_stmt|;
specifier|register
name|int
name|length
decl_stmt|;
block|{
while|while
condition|(
name|length
operator|--
operator|>
literal|0
condition|)
if|if
condition|(
operator|*
name|b1
operator|++
operator|!=
operator|*
name|b2
operator|++
condition|)
return|return
literal|1
return|;
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
comment|/* not BSTRING */
end_comment

begin_escape
end_escape

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD4_1
argument_list|)
operator|||
name|defined
argument_list|(
name|USG
argument_list|)
end_if

begin_comment
comment|/*  *	The BSD random(3) returns numbers in the range of  *	0 to 2e31 - 1.  The USG rand(3C) returns numbers in the  *	range of 0 to 2e15 - 1.  This is probably not significant  *	in this usage.  */
end_comment

begin_function
name|long
name|random
parameter_list|()
block|{
return|return
operator|(
name|rand
argument_list|()
operator|)
return|;
block|}
end_function

begin_macro
name|srandom
argument_list|(
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|int
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|srand
argument_list|(
name|arg
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bsd4.1 or any USG */
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_comment
comment|/*  *	All of the following are for USG.  *  *	On USG systems the system calls are interruptable by signals  *	that the user program has elected to catch.  Thus the system call  *	must be retried in these cases.  To handle this without massive  *	changes in the source code, we remap the standard system call names  *	to names for our own functions in sysdep.c that do the system call  *	with retries.  Actually, for portability reasons, it is good  *	programming practice, as this example shows, to limit all actual  *	system calls to a single occurance in the source.  Sure, this  *	adds an extra level of function call overhead but it is almost  *	always negligible.   Fred Fish, Unisoft Systems Inc.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sys_siglist
index|[
name|NSIG
operator|+
literal|1
index|]
init|=
block|{
literal|"bogus signal"
block|,
comment|/* 0 */
literal|"hangup"
block|,
comment|/* 1  SIGHUP */
literal|"interrupt"
block|,
comment|/* 2  SIGINT */
literal|"quit"
block|,
comment|/* 3  SIGQUIT */
literal|"illegal instruction"
block|,
comment|/* 4  SIGILL */
literal|"trace trap"
block|,
comment|/* 5  SIGTRAP */
literal|"IOT instruction"
block|,
comment|/* 6  SIGIOT */
literal|"EMT instruction"
block|,
comment|/* 7  SIGEMT */
literal|"floating point exception"
block|,
comment|/* 8  SIGFPE */
literal|"kill"
block|,
comment|/* 9  SIGKILL */
literal|"bus error"
block|,
comment|/* 10 SIGBUS */
literal|"segmentation violation"
block|,
comment|/* 11 SIGSEGV */
literal|"bad argument to system call"
block|,
comment|/* 12 SIGSYS */
literal|"write on a pipe with no one to read it"
block|,
comment|/* 13 SIGPIPE */
literal|"alarm clock"
block|,
comment|/* 14 SIGALRM */
literal|"software termination signum"
block|,
comment|/* 15 SIGTERM */
literal|"user defined signal 1"
block|,
comment|/* 16 SIGUSR1 */
literal|"user defined signal 2"
block|,
comment|/* 17 SIGUSR2 */
literal|"death of a child"
block|,
comment|/* 18 SIGCLD */
literal|"power-fail restart"
block|,
comment|/* 19 SIGPWR */
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|sys_read
parameter_list|(
name|fildes
parameter_list|,
name|buf
parameter_list|,
name|nbyte
parameter_list|)
name|int
name|fildes
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|unsigned
name|int
name|nbyte
decl_stmt|;
block|{
specifier|register
name|int
name|rtnval
decl_stmt|;
while|while
condition|(
operator|(
name|rtnval
operator|=
name|read
argument_list|(
name|fildes
argument_list|,
name|buf
argument_list|,
name|nbyte
argument_list|)
operator|)
operator|==
operator|-
literal|1
operator|&&
name|errno
operator|==
name|EINTR
condition|)
empty_stmt|;
return|return
operator|(
name|rtnval
operator|)
return|;
block|}
end_function

begin_function
name|int
comment|/* VARARGS 2 */
name|sys_open
parameter_list|(
name|path
parameter_list|,
name|oflag
parameter_list|,
name|mode
parameter_list|)
name|char
modifier|*
name|path
decl_stmt|;
name|int
name|oflag
decl_stmt|,
name|mode
decl_stmt|;
block|{
specifier|register
name|int
name|rtnval
decl_stmt|;
while|while
condition|(
operator|(
name|rtnval
operator|=
name|open
argument_list|(
name|path
argument_list|,
name|oflag
argument_list|,
name|mode
argument_list|)
operator|)
operator|==
operator|-
literal|1
operator|&&
name|errno
operator|==
name|EINTR
condition|)
empty_stmt|;
return|return
operator|(
name|rtnval
operator|)
return|;
block|}
end_function

begin_function
name|int
name|sys_write
parameter_list|(
name|fildes
parameter_list|,
name|buf
parameter_list|,
name|nbyte
parameter_list|)
name|int
name|fildes
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|unsigned
name|int
name|nbyte
decl_stmt|;
block|{
specifier|register
name|int
name|rtnval
decl_stmt|;
while|while
condition|(
operator|(
name|rtnval
operator|=
name|write
argument_list|(
name|fildes
argument_list|,
name|buf
argument_list|,
name|nbyte
argument_list|)
operator|)
operator|==
operator|-
literal|1
operator|&&
name|errno
operator|==
name|EINTR
condition|)
empty_stmt|;
return|return
operator|(
name|rtnval
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *	Warning, this function may not duplicate 4.2 action properly  *	under error conditions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_comment
comment|/* In 4.1, param.h fails to define this.  */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|getwd
parameter_list|(
name|pathname
parameter_list|)
name|char
modifier|*
name|pathname
decl_stmt|;
block|{
specifier|extern
name|char
modifier|*
name|getcwd
parameter_list|()
function_decl|;
return|return
operator|(
name|getcwd
argument_list|(
name|pathname
argument_list|,
name|MAXPATHLEN
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *	Emulate rename using unlink/link.  Note that this is  *	only partially correct.  Also, doesn't enforce restriction  *	that files be of same type (regular->regular, dir->dir, etc).  */
end_comment

begin_macro
name|rename
argument_list|(
argument|from
argument_list|,
argument|to
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|from
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|to
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|access
argument_list|(
name|from
argument_list|,
literal|0
argument_list|)
operator|==
literal|0
condition|)
block|{
name|unlink
argument_list|(
name|to
argument_list|)
expr_stmt|;
if|if
condition|(
name|link
argument_list|(
name|from
argument_list|,
name|to
argument_list|)
operator|==
literal|0
condition|)
if|if
condition|(
name|unlink
argument_list|(
name|from
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/* VARARGS */
end_comment

begin_macro
name|setpriority
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_ifndef
ifndef|#
directive|ifndef
name|HPUX
end_ifndef

begin_comment
comment|/*  *	Substitute fork(2) for vfork(2) on USG flavors.  */
end_comment

begin_macro
name|vfork
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|fork
argument_list|()
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  *	Emulate BSD dup2(2).  First close newd if it already exists.  *	Then, attempt to dup oldd.  If not successful, call dup2 recursively  *	until we are, then close the unsuccessful ones.  */
end_comment

begin_macro
name|dup2
argument_list|(
argument|oldd
argument_list|,
argument|newd
argument_list|)
end_macro

begin_decl_stmt
name|int
name|oldd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|newd
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|fd
decl_stmt|;
name|close
argument_list|(
name|newd
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|fd
operator|=
name|dup
argument_list|(
name|oldd
argument_list|)
operator|)
operator|!=
name|newd
condition|)
block|{
name|dup2
argument_list|(
name|oldd
argument_list|,
name|newd
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  *	Gettimeofday.  Simulate as much as possible.  Only accurate  *	to nearest second.  Emacs doesn't use tzp so ignore it for now.  *	Only needed when subprocesses are defined.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|subprocesses
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|STRIDE
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_TIMEVAL
argument_list|)
end_if

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|gettimeofday
argument_list|(
argument|tp
argument_list|,
argument|tzp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|timeval
modifier|*
name|tp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timezone
modifier|*
name|tzp
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|long
name|time
parameter_list|()
function_decl|;
name|tp
operator|->
name|tv_sec
operator|=
name|time
argument_list|(
operator|(
name|long
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|tp
operator|->
name|tv_usec
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* subprocess&& ~STRIDE&& HAVE_TIMEVAL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HPUX */
end_comment

begin_comment
comment|/*  *	This function will go away as soon as all the stubs fixed.  (fnf)  */
end_comment

begin_macro
name|croak
argument_list|(
argument|badfunc
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|badfunc
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"%s not yet implemented\r\n"
argument_list|,
name|badfunc
argument_list|)
expr_stmt|;
name|reset_sys_modes
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USG */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Directory routines for systems that don't have them. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NONSYSTEM_DIR_LIBRARY
end_ifdef

begin_function
name|DIR
modifier|*
name|opendir
parameter_list|(
name|filename
parameter_list|)
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* name of directory */
block|{
specifier|register
name|DIR
modifier|*
name|dirp
decl_stmt|;
comment|/* -> malloc'ed storage */
specifier|register
name|int
name|fd
decl_stmt|;
comment|/* file descriptor for read */
name|struct
name|stat
name|sbuf
decl_stmt|;
comment|/* result of fstat() */
name|fd
operator|=
name|sys_open
argument_list|(
name|filename
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|fstat
argument_list|(
name|fd
argument_list|,
operator|&
name|sbuf
argument_list|)
operator|<
literal|0
operator|||
operator|(
name|sbuf
operator|.
name|st_mode
operator|&
name|S_IFMT
operator|)
operator|!=
name|S_IFDIR
operator|||
operator|(
name|dirp
operator|=
operator|(
name|DIR
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|DIR
argument_list|)
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|/* bad luck today */
block|}
name|dirp
operator|->
name|dd_fd
operator|=
name|fd
expr_stmt|;
name|dirp
operator|->
name|dd_loc
operator|=
name|dirp
operator|->
name|dd_size
operator|=
literal|0
expr_stmt|;
comment|/* refill needed */
return|return
name|dirp
return|;
block|}
end_function

begin_function
name|void
name|closedir
parameter_list|(
name|dirp
parameter_list|)
specifier|register
name|DIR
modifier|*
name|dirp
decl_stmt|;
comment|/* stream from opendir() */
block|{
name|close
argument_list|(
name|dirp
operator|->
name|dd_fd
argument_list|)
expr_stmt|;
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|dirp
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|DIRSIZ
value|14
end_define

begin_struct
struct|struct
name|olddir
block|{
name|ino_t
name|od_ino
decl_stmt|;
comment|/* inode */
name|char
name|od_name
index|[
name|DIRSIZ
index|]
decl_stmt|;
comment|/* filename */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|direct
name|dir_static
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* simulated directory contents */
end_comment

begin_function
name|struct
name|direct
modifier|*
name|readdir
parameter_list|(
name|dirp
parameter_list|)
specifier|register
name|DIR
modifier|*
name|dirp
decl_stmt|;
comment|/* stream from opendir() */
block|{
specifier|register
name|struct
name|olddir
modifier|*
name|dp
decl_stmt|;
comment|/* -> directory data */
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|dirp
operator|->
name|dd_loc
operator|>=
name|dirp
operator|->
name|dd_size
condition|)
name|dirp
operator|->
name|dd_loc
operator|=
name|dirp
operator|->
name|dd_size
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|dirp
operator|->
name|dd_size
operator|==
literal|0
comment|/* refill buffer */
operator|&&
operator|(
name|dirp
operator|->
name|dd_size
operator|=
name|sys_read
argument_list|(
name|dirp
operator|->
name|dd_fd
argument_list|,
name|dirp
operator|->
name|dd_buf
argument_list|,
name|DIRBLKSIZ
argument_list|)
operator|)
operator|<=
literal|0
condition|)
return|return
literal|0
return|;
name|dp
operator|=
operator|(
expr|struct
name|olddir
operator|*
operator|)
operator|&
name|dirp
operator|->
name|dd_buf
index|[
name|dirp
operator|->
name|dd_loc
index|]
expr_stmt|;
name|dirp
operator|->
name|dd_loc
operator|+=
sizeof|sizeof
argument_list|(
expr|struct
name|olddir
argument_list|)
expr_stmt|;
if|if
condition|(
name|dp
operator|->
name|od_ino
operator|!=
literal|0
condition|)
comment|/* not deleted entry */
block|{
name|dir_static
operator|.
name|d_ino
operator|=
name|dp
operator|->
name|od_ino
expr_stmt|;
name|strncpy
argument_list|(
name|dir_static
operator|.
name|d_name
argument_list|,
name|dp
operator|->
name|od_name
argument_list|,
name|DIRSIZ
argument_list|)
expr_stmt|;
name|dir_static
operator|.
name|d_name
index|[
name|DIRSIZ
index|]
operator|=
literal|'\0'
expr_stmt|;
name|dir_static
operator|.
name|d_namlen
operator|=
name|strlen
argument_list|(
name|dir_static
operator|.
name|d_name
argument_list|)
expr_stmt|;
name|dir_static
operator|.
name|d_reclen
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|direct
argument_list|)
operator|-
name|MAXNAMLEN
operator|+
literal|3
operator|+
name|dir_static
operator|.
name|d_namlen
operator|-
name|dir_static
operator|.
name|d_namlen
operator|%
literal|4
expr_stmt|;
return|return
operator|&
name|dir_static
return|;
comment|/* -> simulated structure */
block|}
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NONSYSTEM_DIR_LIBRARY */
end_comment

end_unit

