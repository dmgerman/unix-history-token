begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"parms.h"
end_include

begin_include
include|#
directive|include
file|"structs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RCSIDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header: miscio.c,v 1.7.0.1 85/09/28 11:23:51 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  miscio stuff:  *  * ttystrt/ttystop switch back and forth to character-at-a-time mode  *  * catchem makes our program ignore kills and coredumps.  *  * getnum is a char at a time input routine  *  * gchar sucks in 1 character. masks off parity. Uses raw mode to do this  *  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_comment
comment|/* Bell's Sys III and V */
end_comment

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_decl_stmt
name|struct
name|termio
name|tty
decl_stmt|,
name|otty
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|defined(USG)
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|V7
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD4x
argument_list|)
end_if

begin_comment
comment|/* Standard Bell V7 and Berkeley too */
end_comment

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_decl_stmt
name|int
name|oldmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prev mode bits */
end_comment

begin_decl_stmt
name|long
name|oldlocalbits
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prev local bits */
end_comment

begin_decl_stmt
name|struct
name|sgttyb
name|tty
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|defined(V7) || defined(BSD4x)
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD2x
end_ifdef

begin_comment
comment|/* Berkeley PDP-11 Unix */
end_comment

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_decl_stmt
name|int
name|oldmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prev mode bits */
end_comment

begin_decl_stmt
name|int
name|oldlocalbits
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 2.8 Bsd uses 16 bits */
end_comment

begin_decl_stmt
name|struct
name|sgttyb
name|tty
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|defined(BSD2x)
end_endif

begin_decl_stmt
name|char
name|ttyerase
decl_stmt|,
comment|/* user's chosen erase character */
name|ttykill
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and his line kill character */
end_comment

begin_decl_stmt
name|int
name|modeset
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* == 1 if ttyflags messed with */
end_comment

begin_decl_stmt
name|short
name|ospeed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for tputs padding */
end_comment

begin_macro
name|ttystrt
argument_list|()
end_macro

begin_block
block|{
if|#
directive|if
name|defined
argument_list|(
name|BSD2x
argument_list|)
name|int
name|localbits
decl_stmt|;
comment|/* 2.8 Bsd uses 16 bits */
endif|#
directive|endif
endif|defined(BSD2x)
if|#
directive|if
name|defined
argument_list|(
name|BSD4x
argument_list|)
name|long
name|localbits
decl_stmt|;
comment|/* for ctlecho and tildes */
endif|#
directive|endif
endif|defined(BSD4x)
comment|/*  *	Grab the current tty state  */
ifdef|#
directive|ifdef
name|V7
comment|/* V7 has simple tty controls */
if|if
condition|(
name|gtty
argument_list|(
literal|0
argument_list|,
operator|&
name|tty
argument_list|)
operator|<
literal|0
condition|)
comment|/* failure to grab */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Unable to gtty\n"
argument_list|,
name|Invokedas
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|defined(V7)
ifdef|#
directive|ifdef
name|USG
comment|/* BTL SYS III& V  */
if|if
condition|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|tty
argument_list|)
operator|<
literal|0
operator|||
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|otty
argument_list|)
operator|<
literal|0
condition|)
comment|/* one failed */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Unable to get tty state\n"
argument_list|,
name|Invokedas
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|defined(USG)
if|#
directive|if
name|defined
argument_list|(
name|BSD4x
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD2x
argument_list|)
comment|/* Berkeley Unices */
if|if
condition|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGETP
argument_list|,
operator|&
name|tty
argument_list|)
operator|<
literal|0
operator|||
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCLGET
argument_list|,
operator|&
name|oldlocalbits
argument_list|)
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Unable to get tty states\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|defined(BSD4x) || defined(BSD2x)
comment|/*  *	Modify the state to what we want:  cbreak, fix tildes for cursor  *	and disable "control-echo" (berkeley)  */
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
name|tty
operator|.
name|c_lflag
operator|&=
name|NOT
name|ICANON
expr_stmt|;
name|tty
operator|.
name|c_cc
index|[
name|VEOF
index|]
operator|=
literal|1
expr_stmt|;
name|tty
operator|.
name|c_cc
index|[
name|VEOL
index|]
operator|=
literal|1
expr_stmt|;
name|ospeed
operator|=
name|tty
operator|.
name|c_cflag
operator|&
name|CBAUD
expr_stmt|;
name|ttyerase
operator|=
name|tty
operator|.
name|c_cc
index|[
name|VERASE
index|]
expr_stmt|;
comment|/* grab erase char */
name|ttykill
operator|=
name|tty
operator|.
name|c_cc
index|[
name|VKILL
index|]
expr_stmt|;
comment|/* and kill char */
endif|#
directive|endif
endif|defined(USG)
if|#
directive|if
name|defined
argument_list|(
name|BSD4x
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD2x
argument_list|)
operator|||
name|defined
argument_list|(
name|V7
argument_list|)
name|oldmode
operator|=
name|tty
operator|.
name|sg_flags
expr_stmt|;
name|tty
operator|.
name|sg_flags
operator||=
name|CBREAK
expr_stmt|;
name|ospeed
operator|=
name|tty
operator|.
name|sg_ospeed
expr_stmt|;
comment|/* speed of terminal */
name|ttyerase
operator|=
name|tty
operator|.
name|sg_erase
expr_stmt|;
comment|/* grab erase character */
name|ttykill
operator|=
name|tty
operator|.
name|sg_kill
expr_stmt|;
comment|/* and kill character */
endif|#
directive|endif
endif|defined(BSD4x) || defined(BSD2x) || defined(V7)
comment|/*  *	Now actually tell the system that we want it this way  */
if|#
directive|if
name|defined
argument_list|(
name|V7
argument_list|)
if|if
condition|(
name|stty
argument_list|(
literal|0
argument_list|,
operator|&
name|tty
argument_list|)
operator|<
literal|0
condition|)
comment|/* failed */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Unable to stty\n"
argument_list|,
name|Invokedas
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|defined(V7)
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
if|if
condition|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCSETA
argument_list|,
operator|&
name|tty
argument_list|)
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Unable to set tty state\n"
argument_list|,
name|Invokedas
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|defined(USG)
if|#
directive|if
name|defined
argument_list|(
name|BSD4x
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD2x
argument_list|)
name|localbits
operator|=
name|LTILDE
operator||
name|LCTLECH
expr_stmt|;
comment|/* zap tildes (hazeltines) and ctlecho */
if|if
condition|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSETN
argument_list|,
operator|&
name|tty
argument_list|)
operator|<
literal|0
operator|||
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCLBIC
argument_list|,
operator|&
name|localbits
argument_list|)
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Unable to set tty state\n"
argument_list|,
name|Invokedas
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|defined(BSD4x) || defined(BSD2x)
name|modeset
operator|=
literal|1
expr_stmt|;
name|cmstart
argument_list|()
expr_stmt|;
comment|/* so can cursor address reliably */
block|}
end_block

begin_macro
name|ttystop
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|modeset
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|V7
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD4x
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD2x
argument_list|)
name|tty
operator|.
name|sg_flags
operator|=
name|oldmode
expr_stmt|;
endif|#
directive|endif
endif|defined(V7) || defined(BSD4x) || defined(BSD2x)
if|#
directive|if
name|defined
argument_list|(
name|V7
argument_list|)
if|if
condition|(
name|stty
argument_list|(
literal|0
argument_list|,
operator|&
name|tty
argument_list|)
operator|<
literal|0
condition|)
comment|/* vanilla Version 7 */
name|printf
argument_list|(
literal|"ttystop: stty"
argument_list|)
expr_stmt|;
comment|/* cant use x cause he calls us */
endif|#
directive|endif
endif|defined(V7)
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
if|if
condition|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCSETA
argument_list|,
operator|&
name|otty
argument_list|)
operator|<
literal|0
condition|)
comment|/* Unix 4.0 */
name|printf
argument_list|(
literal|"ttystop: stty"
argument_list|)
expr_stmt|;
comment|/* cant use x cause he calls us */
endif|#
directive|endif
endif|defined(USG)
if|#
directive|if
name|defined
argument_list|(
name|BSD4x
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD2x
argument_list|)
if|if
condition|(
operator|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSETN
argument_list|,
operator|&
name|tty
argument_list|)
operator|<
literal|0
operator|)
operator|||
operator|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCLSET
argument_list|,
operator|&
name|oldlocalbits
argument_list|)
operator|<
literal|0
operator|)
condition|)
name|printf
argument_list|(
literal|"ttystop: stty"
argument_list|)
expr_stmt|;
comment|/* cant use x cause he calls us */
endif|#
directive|endif
endif|defined(BSD4x) || defined(BSD2x)
block|}
name|cmstop
argument_list|()
expr_stmt|;
comment|/* get out of cursor addressing mode */
name|modeset
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|int
argument_list|(
operator|*
name|osigint
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|osigquit
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hold signal status */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SIGTSTP
argument_list|)
end_if

begin_function_decl
specifier|static
name|int
function_decl|(
modifier|*
name|osigtstp
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* control-z job stop */
end_comment

begin_endif
endif|#
directive|endif
endif|defined(SIGTSTP)
end_endif

begin_macro
name|catchint
argument_list|()
end_macro

begin_block
block|{
name|intflag
operator|=
literal|1
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|catchint
argument_list|)
expr_stmt|;
comment|/* fix em up again */
ifndef|#
directive|ifndef
name|DEBUG
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|catchint
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|DEBUG
block|}
end_block

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SIGTSTP
argument_list|)
end_if

begin_macro
name|catchz
argument_list|()
end_macro

begin_comment
comment|/* handle ^Z gracefully */
end_comment

begin_block
block|{
name|int
name|wasset
decl_stmt|;
comment|/* tty mode flag */
if|if
condition|(
name|ignoresigs
condition|)
comment|/* if in critical section */
block|{
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|catchz
argument_list|)
expr_stmt|;
comment|/* re-catch */
return|return;
comment|/* and ignore */
block|}
if|if
condition|(
operator|(
name|wasset
operator|=
name|modeset
operator|)
operator|!=
literal|0
condition|)
comment|/* want assignment */
block|{
name|at
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* go to bottom corner */
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|ttystop
argument_list|()
expr_stmt|;
comment|/* fix tty modes */
block|}
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
comment|/* make sure it nabs us */
if|#
directive|if
name|defined
argument_list|(
name|BSD42
argument_list|)
comment|/*  *	since 4.2 Bsd blocks signals while we are handling them, we  *	have to explicitly tell the kernel that we want the signals  *	to come through.  *	It would probably be more correct to only let some signals  *	through instead of all.  */
operator|(
name|void
operator|)
name|sigsetmask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* pass signals */
endif|#
directive|endif
endif|BSD42
name|kill
argument_list|(
literal|0
argument_list|,
name|SIGTSTP
argument_list|)
expr_stmt|;
comment|/* halt myself */
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|catchz
argument_list|)
expr_stmt|;
comment|/* ready to catch again */
if|if
condition|(
name|wasset
condition|)
name|ttystrt
argument_list|()
expr_stmt|;
comment|/* fix his tty */
block|}
end_block

begin_endif
endif|#
directive|endif
endif|defined(SIGTSTP)
end_endif

begin_macro
name|catchem
argument_list|()
end_macro

begin_block
block|{
name|osigint
operator|=
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|catchint
argument_list|)
expr_stmt|;
comment|/* interrupts */
ifndef|#
directive|ifndef
name|DEBUG
name|osigquit
operator|=
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|catchint
argument_list|)
expr_stmt|;
comment|/* quits */
endif|#
directive|endif
endif|DEBUG
if|#
directive|if
name|defined
argument_list|(
name|SIGTSTP
argument_list|)
name|osigtstp
operator|=
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|catchz
argument_list|)
expr_stmt|;
comment|/* control Z */
endif|#
directive|endif
block|}
end_block

begin_macro
name|uncatchem
argument_list|()
end_macro

begin_comment
comment|/* restore signal status */
end_comment

begin_block
block|{
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|osigint
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|DEBUG
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|osigquit
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|DEBUG
if|#
directive|if
name|defined
argument_list|(
name|SIGTSTP
argument_list|)
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|osigtstp
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_macro
name|gchar
argument_list|()
end_macro

begin_comment
comment|/*  *	Return next character from tty.  *	this is all done in cbreak mode of course  */
end_comment

begin_block
block|{
name|char
name|c
decl_stmt|;
specifier|register
name|int
name|retcode
decl_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
comment|/* get rid of what's there */
while|while
condition|(
operator|(
name|retcode
operator|=
name|read
argument_list|(
literal|0
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
operator|)
operator|<=
literal|0
condition|)
comment|/* try reading */
if|if
condition|(
name|retcode
operator|==
literal|0
operator|||
name|errno
operator|!=
name|EINTR
condition|)
comment|/* if bizarre */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Bad tty read\n"
argument_list|,
name|Invokedas
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|intflag
operator|=
literal|0
expr_stmt|;
comment|/* remove any pending */
return|return
operator|(
name|c
operator|&
literal|0177
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  *	getnum (c)   *	grab a number from the terminal. "c" is the first digit o   *	the number.   *	  *	Originally coded:	Rob Kolstad	Fall 1980  *	Modified:		Ray Essick (with help from Malcolm Slaney)  *						July 1982  *				to handle user defined erase and kill  *				characters.  */
end_comment

begin_macro
name|getnum
argument_list|(
argument|c
argument_list|)
end_macro

begin_comment
comment|/* c is the initial character! */
end_comment

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|num
decl_stmt|,
name|numin
decl_stmt|;
name|num
operator|=
name|c
operator|-
literal|'0'
expr_stmt|;
name|numin
operator|=
literal|1
expr_stmt|;
name|putc
argument_list|(
name|c
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|c
operator|=
name|gchar
argument_list|()
expr_stmt|;
comment|/* get next digit */
if|if
condition|(
name|c
operator|==
name|ttyerase
condition|)
comment|/* want to erase? */
block|{
if|if
condition|(
name|numin
operator|>
literal|0
condition|)
comment|/* if have some */
block|{
if|if
condition|(
name|c
operator|!=
literal|'\10'
condition|)
comment|/* Assumes physically */
name|printf
argument_list|(
literal|"\10\10  \10\10"
argument_list|)
expr_stmt|;
comment|/* backspaces on ^H */
else|else
name|printf
argument_list|(
literal|" \10"
argument_list|)
expr_stmt|;
name|numin
operator|--
expr_stmt|;
name|num
operator|/=
literal|10
expr_stmt|;
comment|/* drop that digit */
block|}
else|else
block|{
comment|/* nothing to zap */
if|if
condition|(
name|c
operator|!=
literal|'\10'
condition|)
comment|/* non-backspace char */
name|printf
argument_list|(
literal|"\10\10 "
argument_list|)
expr_stmt|;
else|else
name|putchar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
comment|/* backspace */
block|}
block|}
elseif|else
if|if
condition|(
name|c
operator|==
name|ttykill
condition|)
block|{
name|num
operator|=
literal|0
expr_stmt|;
comment|/* blast it away */
name|numin
operator|++
expr_stmt|;
while|while
condition|(
name|numin
operator|>
literal|0
condition|)
comment|/* erase the screen */
block|{
name|numin
operator|--
expr_stmt|;
name|printf
argument_list|(
literal|"\10 \10"
argument_list|)
expr_stmt|;
block|}
name|numin
operator|=
literal|0
expr_stmt|;
comment|/* in case */
block|}
else|else
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'\n'
case|:
case|case
literal|'\r'
case|:
return|return
name|num
return|;
comment|/* done */
default|default:
if|if
condition|(
name|c
operator|<
literal|'0'
operator|||
name|c
operator|>
literal|'9'
condition|)
block|{
name|printf
argument_list|(
literal|"\10 \10\07"
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|numin
operator|++
expr_stmt|;
name|num
operator|=
literal|10
operator|*
name|num
operator|+
operator|(
name|c
operator|-
literal|'0'
operator|)
expr_stmt|;
break|break;
block|}
block|}
block|}
end_block

begin_comment
comment|/*  *	gline( p, i) - suck a maximum of i characters from the tty.  *	do erase and kill processing.  *	The line is terminated by the user typing a<cr> or<nl>. This  *	character is converted to null and left on the end of the  *	string returned. The count of characters (including the null  *	terminator) is returned.  *	The array passed in is assumed to have i+1 elements  *	(enough for the characters plus the terminator)  *  *	Original Coding:	Ray Essick	December 1981  *	Repaired to use user's erase and kill characters  *				Malcolm Slaney	July 1982  *  */
end_comment

begin_macro
name|gline
argument_list|(
argument|p
argument_list|,
argument|max
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|numin
decl_stmt|;
specifier|register
name|char
modifier|*
name|q
decl_stmt|;
comment|/* pointer to buffer */
specifier|register
name|char
name|c
decl_stmt|;
comment|/* hold the input character */
name|q
operator|=
name|p
expr_stmt|;
comment|/* get base */
name|numin
operator|=
literal|0
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|c
operator|=
name|gchar
argument_list|()
expr_stmt|;
comment|/* flushes stdout also */
if|if
condition|(
name|c
operator|==
name|ttyerase
condition|)
block|{
if|if
condition|(
name|numin
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|c
operator|!=
literal|'\10'
condition|)
comment|/* Assumes TTY physically */
name|printf
argument_list|(
literal|"\10\10  \10\10"
argument_list|)
expr_stmt|;
comment|/* backspaces on ^H */
else|else
name|printf
argument_list|(
literal|" \10"
argument_list|)
expr_stmt|;
name|numin
operator|--
expr_stmt|;
name|q
operator|--
expr_stmt|;
comment|/* back up in buffer also */
block|}
else|else
block|{
if|if
condition|(
name|c
operator|!=
literal|'\10'
condition|)
name|printf
argument_list|(
literal|"\10 \10"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|c
operator|==
name|ttykill
condition|)
block|{
name|numin
operator|++
expr_stmt|;
while|while
condition|(
name|numin
operator|>
literal|0
condition|)
comment|/* erase the screen */
block|{
name|numin
operator|--
expr_stmt|;
name|printf
argument_list|(
literal|"\10 \10"
argument_list|)
expr_stmt|;
block|}
name|q
operator|=
name|p
expr_stmt|;
comment|/* reset pointer */
name|numin
operator|=
literal|0
expr_stmt|;
comment|/* in case .. */
block|}
else|else
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'\n'
case|:
case|case
literal|'\r'
case|:
if|if
condition|(
name|numin
operator|>=
name|max
condition|)
comment|/* should only ever be = */
block|{
name|p
index|[
name|max
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* put a null at the end */
return|return
name|max
operator|+
literal|1
return|;
comment|/* which is how many we return */
block|}
operator|*
name|q
operator|=
literal|'\0'
expr_stmt|;
name|numin
operator|++
expr_stmt|;
return|return
name|numin
return|;
case|case
literal|'\\'
case|:
comment|/* escape character */
name|printf
argument_list|(
literal|"\010"
argument_list|)
expr_stmt|;
comment|/* back space to it */
name|c
operator|=
name|gchar
argument_list|()
expr_stmt|;
comment|/* grab escaped character */
comment|/* and fall through to default */
default|default:
comment|/* add character to buffer */
if|if
condition|(
name|numin
operator|<
name|max
condition|)
block|{
operator|*
name|q
operator|++
operator|=
name|c
expr_stmt|;
name|numin
operator|++
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"\10 \10"
argument_list|)
expr_stmt|;
comment|/* show him I ignored char */
block|}
break|break;
block|}
block|}
block|}
end_block

begin_macro
name|askyn
argument_list|(
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* returns y or n to the question */
end_comment

begin_block
block|{
name|char
name|c
decl_stmt|;
comment|/* return temp */
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|p
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|c
operator|=
name|gchar
argument_list|()
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'y'
operator|||
name|c
operator|==
literal|'n'
condition|)
break|break;
name|printf
argument_list|(
literal|"\07 y or n please\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
argument_list|)
expr_stmt|;
block|}
return|return
name|c
return|;
block|}
end_block

begin_comment
comment|/*  * return 1 if there is input from the terminal,  * 0 otherwise.  systems without the appropriate  * call should always return 0.  */
end_comment

begin_macro
name|isinput
argument_list|()
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|FIONREAD
comment|/* BSD 4.1, 4.1a, 4.2 */
name|long
name|retval
decl_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|FIONREAD
argument_list|,
operator|&
name|retval
argument_list|)
condition|)
return|return
literal|0
return|;
comment|/* failed, say no input */
return|return
operator|(
name|retval
operator|!=
literal|0
operator|)
return|;
comment|/* count of characters */
endif|#
directive|endif
endif|FIONREAD
return|return
literal|0
return|;
comment|/* for other systems */
block|}
end_block

begin_comment
comment|/*  *	mapch(c) char c;  *  *	prints control characters as ^x style.   *	others as normal.  */
end_comment

begin_macro
name|mapch
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
if|if
condition|(
name|c
operator|<
literal|40
condition|)
block|{
name|putchar
argument_list|(
literal|'^'
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
name|c
operator||
literal|0100
argument_list|)
expr_stmt|;
comment|/* make visible */
block|}
elseif|else
if|if
condition|(
name|c
operator|==
literal|0177
condition|)
block|{
name|putchar
argument_list|(
literal|'^'
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'?'
argument_list|)
expr_stmt|;
block|}
else|else
name|putchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

