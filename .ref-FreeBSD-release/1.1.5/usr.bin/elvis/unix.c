begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* unix.c */
end_comment

begin_comment
comment|/* Author:  *	Steve Kirkendall  *	14407 SW Teal Blvd. #C  *	Beaverton, OR 97005  *	kirkenda@cs.pdx.edu  */
end_comment

begin_comment
comment|/* This file contains the unix-specific versions the ttyread() functions.  * There are actually three versions of ttyread() defined here, because  * BSD, SysV, and V7 all need quite different implementations.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_if
if|#
directive|if
name|ANY_UNIX
end_if

begin_include
include|#
directive|include
file|"vi.h"
end_include

begin_if
if|#
directive|if
name|BSD
end_if

begin_comment
comment|/* For BSD, we use select() to wait for characters to become available,  * and then do a read() to actually get the characters.  We also try to  * handle SIGWINCH -- if the signal arrives during the select() call, then  * we adjust the o_columns and o_lines variables, and fake a control-L.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_function
name|int
name|ttyread
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|time
parameter_list|)
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* where to store the gotten characters */
name|int
name|len
decl_stmt|;
comment|/* maximum number of characters to read */
name|int
name|time
decl_stmt|;
comment|/* maximum time to allow for reading */
block|{
name|fd_set
name|rd
decl_stmt|;
comment|/* the file descriptors that we want to read from */
specifier|static
name|tty
expr_stmt|;
comment|/* 'y' if reading from tty, or 'n' if not a tty */
name|int
name|i
decl_stmt|;
name|struct
name|timeval
name|t
decl_stmt|;
name|struct
name|timeval
modifier|*
name|tp
decl_stmt|;
comment|/* do we know whether this is a tty or not? */
if|if
condition|(
operator|!
name|tty
condition|)
block|{
name|tty
operator|=
operator|(
name|isatty
argument_list|(
literal|0
argument_list|)
condition|?
literal|'y'
else|:
literal|'n'
operator|)
expr_stmt|;
block|}
comment|/* compute the timeout value */
if|if
condition|(
name|time
condition|)
block|{
name|t
operator|.
name|tv_sec
operator|=
name|time
operator|/
literal|10
expr_stmt|;
name|t
operator|.
name|tv_usec
operator|=
operator|(
name|time
operator|%
literal|10
operator|)
operator|*
literal|100000L
expr_stmt|;
name|tp
operator|=
operator|&
name|t
expr_stmt|;
block|}
else|else
block|{
name|tp
operator|=
operator|(
expr|struct
name|timeval
operator|*
operator|)
literal|0
expr_stmt|;
block|}
comment|/* loop until we get characters or a definite EOF */
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|tty
operator|==
literal|'y'
condition|)
block|{
comment|/* wait until timeout or characters are available */
name|FD_ZERO
argument_list|(
operator|&
name|rd
argument_list|)
expr_stmt|;
name|FD_SET
argument_list|(
literal|0
argument_list|,
operator|&
name|rd
argument_list|)
expr_stmt|;
name|i
operator|=
name|select
argument_list|(
literal|1
argument_list|,
operator|&
name|rd
argument_list|,
operator|(
name|fd_set
operator|*
operator|)
literal|0
argument_list|,
operator|(
name|fd_set
operator|*
operator|)
literal|0
argument_list|,
name|tp
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* if reading from a file or pipe, never timeout! 			 * (This also affects the way that EOF is detected) 			 */
name|i
operator|=
literal|1
expr_stmt|;
block|}
comment|/* react accordingly... */
switch|switch
condition|(
name|i
condition|)
block|{
case|case
operator|-
literal|1
case|:
comment|/* assume we got an EINTR because of SIGWINCH */
if|if
condition|(
operator|*
name|o_lines
operator|!=
name|LINES
operator|||
operator|*
name|o_columns
operator|!=
name|COLS
condition|)
block|{
ifndef|#
directive|ifndef
name|CRUNCH
operator|*
name|o_nearscroll
operator|=
endif|#
directive|endif
operator|*
name|o_lines
operator|=
name|LINES
expr_stmt|;
operator|*
name|o_columns
operator|=
name|COLS
expr_stmt|;
ifndef|#
directive|ifndef
name|CRUNCH
if|if
condition|(
operator|!
name|wset
condition|)
block|{
operator|*
name|o_window
operator|=
name|LINES
operator|-
literal|1
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|mode
operator|!=
name|MODE_EX
condition|)
block|{
comment|/* pretend the user hit ^L */
operator|*
name|buf
operator|=
name|ctrl
argument_list|(
literal|'L'
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
block|}
break|break;
case|case
literal|0
case|:
comment|/* timeout */
return|return
literal|0
return|;
default|default:
comment|/* characters available */
return|return
name|read
argument_list|(
literal|0
argument_list|,
name|buf
argument_list|,
name|len
argument_list|)
return|;
block|}
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|UNIXV
operator|||
name|COH_386
end_if

begin_comment
comment|/* For System-V, we use VMIN/VTIME to implement the timeout.  For no timeout,  * VMIN should be 1 and VTIME should be 0; for timeout, VMIN should be 0 and  * VTIME should be the timeout value.  */
end_comment

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_function
name|int
name|ttyread
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|time
parameter_list|)
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* where to store the gotten characters */
name|int
name|len
decl_stmt|;
comment|/* maximum number of characters to read */
name|int
name|time
decl_stmt|;
comment|/* maximum time to allow for reading */
block|{
name|struct
name|termio
name|tio
decl_stmt|;
name|int
name|bytes
decl_stmt|;
comment|/* number of bytes actually read */
comment|/* arrange for timeout */
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|tio
argument_list|)
expr_stmt|;
if|if
condition|(
name|time
condition|)
block|{
name|tio
operator|.
name|c_cc
index|[
name|VMIN
index|]
operator|=
literal|0
expr_stmt|;
name|tio
operator|.
name|c_cc
index|[
name|VTIME
index|]
operator|=
name|time
expr_stmt|;
block|}
else|else
block|{
name|tio
operator|.
name|c_cc
index|[
name|VMIN
index|]
operator|=
literal|1
expr_stmt|;
name|tio
operator|.
name|c_cc
index|[
name|VTIME
index|]
operator|=
literal|0
expr_stmt|;
block|}
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCSETA
argument_list|,
operator|&
name|tio
argument_list|)
expr_stmt|;
comment|/* Perform the read.  Loop if EINTR error happens */
while|while
condition|(
operator|(
name|bytes
operator|=
name|read
argument_list|(
literal|0
argument_list|,
name|buf
argument_list|,
operator|(
name|unsigned
operator|)
name|len
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
comment|/* probably EINTR error because a SIGWINCH was received */
if|if
condition|(
operator|*
name|o_lines
operator|!=
name|LINES
operator|||
operator|*
name|o_columns
operator|!=
name|COLS
condition|)
block|{
operator|*
name|o_lines
operator|=
name|LINES
expr_stmt|;
operator|*
name|o_columns
operator|=
name|COLS
expr_stmt|;
ifndef|#
directive|ifndef
name|CRUNCH
if|if
condition|(
operator|!
name|wset
condition|)
block|{
operator|*
name|o_nearscroll
operator|=
name|LINES
expr_stmt|;
operator|*
name|o_window
operator|=
name|LINES
operator|-
literal|1
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|mode
operator|!=
name|MODE_EX
condition|)
block|{
comment|/* pretend the user hit ^L */
operator|*
name|buf
operator|=
name|ctrl
argument_list|(
literal|'L'
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
block|}
block|}
comment|/* return the number of bytes read */
return|return
name|bytes
return|;
comment|/* NOTE: The terminal may be left in a timeout-mode after this function 	 * returns.  This shouldn't be a problem since Elvis *NEVER* tries to 	 * read from the keyboard except through this function. 	 */
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* any other version of UNIX, assume it is V7 compatible */
end_comment

begin_comment
comment|/* For V7 UNIX (including Minix) we set an alarm() before doing a blocking  * read(), and assume that the SIGALRM signal will cause the read() function  * to give up.  */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
specifier|static
name|jmp_buf
name|env
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|SIGTYPE
name|dummy
parameter_list|(
name|signo
parameter_list|)
name|int
name|signo
decl_stmt|;
block|{
name|longjmp
argument_list|(
name|env
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|ttyread
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|,
name|time
parameter_list|)
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* where to store the gotten characters */
name|int
name|len
decl_stmt|;
comment|/* maximum number of characters to read */
name|int
name|time
decl_stmt|;
comment|/* maximum time to allow for reading */
block|{
comment|/* arrange for timeout */
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|dummy
argument_list|)
expr_stmt|;
name|alarm
argument_list|(
name|time
argument_list|)
expr_stmt|;
comment|/* perform the blocking read */
if|if
condition|(
name|setjmp
argument_list|(
name|env
argument_list|)
operator|==
literal|0
condition|)
block|{
name|len
operator|=
name|read
argument_list|(
literal|0
argument_list|,
name|buf
argument_list|,
operator|(
name|unsigned
operator|)
name|len
argument_list|)
expr_stmt|;
block|}
else|else
comment|/* I guess we timed out */
block|{
name|len
operator|=
literal|0
expr_stmt|;
block|}
comment|/* cancel the alarm */
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|dummy
argument_list|)
expr_stmt|;
comment|/*<-- to work around a bug in Minix */
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* return the number of bytes read */
if|if
condition|(
name|len
operator|<
literal|0
condition|)
name|len
operator|=
literal|0
expr_stmt|;
return|return
name|len
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_SYSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !BSD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANY_UNIX */
end_comment

end_unit

