begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * io.c - input/output routines for Phantasia  */
end_comment

begin_include
include|#
directive|include
file|"include.h"
end_include

begin_comment
comment|/************************************************************************ / / FUNCTION NAME: getstring() / / FUNCTION: read a string from operator / / AUTHOR: E. A. Estes, 12/4/85 / / ARGUMENTS: /	char *cp - pointer to buffer area to fill /	int mx - maximum number of characters to put in buffer / / RETURN VALUE: none / / MODULES CALLED: wmove(), _filbuf(), clearok(), waddstr(), wrefresh(),  /	wclrtoeol() / / GLOBAL INPUTS: Echo, _iob[], Wizard, *stdscr / / GLOBAL OUTPUTS: _iob[] / / DESCRIPTION: /	Read a string from the keyboard. /	This routine is specially designed to: / /	    - strip non-printing characters (unless Wizard) /	    - echo, if desired /	    - redraw the screen if CH_REDRAW is entered /	    - read in only 'mx - 1' characters or less characters /	    - nul-terminate string, and throw away newline / /	'mx' is assumed to be at least 2. / /************************************************************************/
end_comment

begin_expr_stmt
name|getstring
argument_list|(
name|cp
argument_list|,
name|mx
argument_list|)
specifier|register
name|char
operator|*
name|cp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|mx
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|inptr
decl_stmt|;
comment|/* pointer into string for next string */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* original x, y coordinates on screen */
name|int
name|ch
decl_stmt|;
comment|/* input */
name|getyx
argument_list|(
name|stdscr
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|/* get coordinates on screen */
name|inptr
operator|=
name|cp
expr_stmt|;
operator|*
name|inptr
operator|=
literal|'\0'
expr_stmt|;
comment|/* clear string to start */
operator|--
name|mx
expr_stmt|;
comment|/* reserve room in string for nul terminator */
do|do
comment|/* get characters and process */
block|{
if|if
condition|(
name|Echo
condition|)
name|mvaddstr
argument_list|(
name|y
argument_list|,
name|x
argument_list|,
name|cp
argument_list|)
expr_stmt|;
comment|/* print string on screen */
name|clrtoeol
argument_list|()
expr_stmt|;
comment|/* clear any data after string */
name|refresh
argument_list|()
expr_stmt|;
comment|/* update screen */
name|ch
operator|=
name|getchar
argument_list|()
expr_stmt|;
comment|/* get character */
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
name|CH_ERASE
case|:
comment|/* back up one character */
if|if
condition|(
name|inptr
operator|>
name|cp
condition|)
operator|--
name|inptr
expr_stmt|;
break|break;
case|case
name|CH_KILL
case|:
comment|/* back up to original location */
name|inptr
operator|=
name|cp
expr_stmt|;
break|break;
case|case
name|CH_NEWLINE
case|:
comment|/* terminate string */
break|break;
case|case
name|CH_REDRAW
case|:
comment|/* redraw screen */
name|clearok
argument_list|(
name|stdscr
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
continue|continue;
default|default:
comment|/* put data in string */
if|if
condition|(
name|ch
operator|>=
literal|' '
operator|||
name|Wizard
condition|)
comment|/* printing char; put in string */
operator|*
name|inptr
operator|++
operator|=
name|ch
expr_stmt|;
block|}
operator|*
name|inptr
operator|=
literal|'\0'
expr_stmt|;
comment|/* terminate string */
block|}
do|while
condition|(
name|ch
operator|!=
name|CH_NEWLINE
operator|&&
name|inptr
operator|<
name|cp
operator|+
name|mx
condition|)
do|;
block|}
end_block

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/************************************************************************ / / FUNCTION NAME: more() / / FUNCTION: pause and prompt player / / AUTHOR: E. A. Estes, 12/4/85 / / ARGUMENTS: /	int where - line on screen on which to pause / / RETURN VALUE: none / / MODULES CALLED: wmove(), waddstr(), getanswer() / / GLOBAL INPUTS: *stdscr / / GLOBAL OUTPUTS: none / / DESCRIPTION: /	Print a message, and wait for a space character. / /************************************************************************/
end_comment

begin_macro
name|more
argument_list|(
argument|where
argument_list|)
end_macro

begin_decl_stmt
name|int
name|where
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|mvaddstr
argument_list|(
name|where
argument_list|,
literal|0
argument_list|,
literal|"-- more --"
argument_list|)
expr_stmt|;
name|getanswer
argument_list|(
literal|" "
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/************************************************************************ / / FUNCTION NAME: infloat() / / FUNCTION: input a floating point number from operator / / AUTHOR: E. A. Estes, 12/4/85 / / ARGUMENTS: none / / RETURN VALUE: floating point number from operator / / MODULES CALLED: sscanf(), getstring() / / GLOBAL INPUTS: Databuf[] / / GLOBAL OUTPUTS: none / / DESCRIPTION: /	Read a string from player, and scan for a floating point /	number. /	If no valid number is found, return 0.0. / /************************************************************************/
end_comment

begin_function
name|double
name|infloat
parameter_list|()
block|{
name|double
name|result
decl_stmt|;
comment|/* return value */
name|getstring
argument_list|(
name|Databuf
argument_list|,
name|SZ_DATABUF
argument_list|)
expr_stmt|;
if|if
condition|(
name|sscanf
argument_list|(
name|Databuf
argument_list|,
literal|"%F"
argument_list|,
operator|&
name|result
argument_list|)
operator|<
literal|1
condition|)
comment|/* no valid number entered */
name|result
operator|=
literal|0.0
expr_stmt|;
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/************************************************************************ / / FUNCTION NAME: inputoption() / / FUNCTION: input an option value from player / / AUTHOR: E. A. Estes, 12/4/85 / / ARGUMENTS: none / / RETURN VALUE: none / / MODULES CALLED: floor(), drandom(), getanswer() / / GLOBAL INPUTS: Player / / GLOBAL OUTPUTS: Player / / DESCRIPTION: /	Age increases with every move. /	Refresh screen, and get a single character option from player. /	Return a random value if player's ring has gone bad. / /************************************************************************/
end_comment

begin_macro
name|inputoption
argument_list|()
end_macro

begin_block
block|{
operator|++
name|Player
operator|.
name|p_age
expr_stmt|;
comment|/* increase age */
if|if
condition|(
name|Player
operator|.
name|p_ring
operator|.
name|ring_type
operator|!=
name|R_SPOILED
condition|)
comment|/* ring ok */
return|return
operator|(
name|getanswer
argument_list|(
literal|"T "
argument_list|,
name|TRUE
argument_list|)
operator|)
return|;
else|else
comment|/* bad ring */
block|{
name|getanswer
argument_list|(
literal|" "
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|int
operator|)
name|ROLL
argument_list|(
literal|0.0
argument_list|,
literal|5.0
argument_list|)
operator|+
literal|'0'
operator|)
return|;
block|}
block|}
end_block

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/************************************************************************ / / FUNCTION NAME: interrupt() / / FUNCTION: handle interrupt from operator / / AUTHOR: E. A. Estes, 12/4/85 / / ARGUMENTS: none / / RETURN VALUE: none / / MODULES CALLED: fork(), exit(), wait(), death(), alarm(), execl(), wmove(),  /	getgid(), signal(), getenv(), wclear(), setuid(), getuid(), setgid(),  /	crmode(), clearok(), waddstr(), cleanup(), wrefresh(), leavegame(),  /	getanswer() / / GLOBAL INPUTS: Player, *stdscr / / GLOBAL OUTPUTS: none / / DESCRIPTION: /	Allow player to quit upon hitting the interrupt key. /	If the player wants to quit while in battle, he/she automatically /	dies. /	If SHELL is defined, spawn a shell if the if the question is /	answered with a '!'. /	We are careful to save the state of the screen, and return it /	to its original condition. / /************************************************************************/
end_comment

begin_macro
name|interrupt
argument_list|()
end_macro

begin_block
block|{
name|char
name|line
index|[
literal|81
index|]
decl_stmt|;
comment|/* a place to store data already on screen */
specifier|register
name|int
name|loop
decl_stmt|;
comment|/* counter */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* coordinates on screen */
name|int
name|ch
decl_stmt|;
comment|/* input */
name|unsigned
name|savealarm
decl_stmt|;
comment|/* to save alarm value */
ifdef|#
directive|ifdef
name|SHELL
specifier|register
name|char
modifier|*
name|shell
decl_stmt|;
comment|/* pointer to shell to spawn */
name|int
name|childpid
decl_stmt|;
comment|/* pid of spawned process */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SYS3
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SYS5
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|savealarm
operator|=
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* turn off any alarms */
name|getyx
argument_list|(
name|stdscr
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|/* save cursor location */
for|for
control|(
name|loop
operator|=
literal|0
init|;
name|loop
operator|<
literal|80
condition|;
operator|++
name|loop
control|)
comment|/* save line on screen */
block|{
name|move
argument_list|(
literal|4
argument_list|,
name|loop
argument_list|)
expr_stmt|;
name|line
index|[
name|loop
index|]
operator|=
name|inch
argument_list|()
expr_stmt|;
block|}
name|line
index|[
literal|80
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* nul terminate */
if|if
condition|(
name|Player
operator|.
name|p_status
operator|==
name|S_INBATTLE
operator|||
name|Player
operator|.
name|p_status
operator|==
name|S_MONSTER
condition|)
comment|/* in midst of fighting */
block|{
name|mvaddstr
argument_list|(
literal|4
argument_list|,
literal|0
argument_list|,
literal|"Quitting now will automatically kill your character.  Still want to ? "
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SHELL
name|ch
operator|=
name|getanswer
argument_list|(
literal|"NY!"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
else|#
directive|else
name|ch
operator|=
name|getanswer
argument_list|(
literal|"NY"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|ch
operator|==
literal|'Y'
condition|)
name|death
argument_list|(
literal|"Bailing out"
argument_list|)
expr_stmt|;
comment|/*NOTREACHED*/
block|}
else|else
block|{
ifdef|#
directive|ifdef
name|SHELL
name|mvaddstr
argument_list|(
literal|4
argument_list|,
literal|0
argument_list|,
literal|"Do you really want to quit [! = Shell] ? "
argument_list|)
expr_stmt|;
name|ch
operator|=
name|getanswer
argument_list|(
literal|"NY!"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
else|#
directive|else
name|mvaddstr
argument_list|(
literal|4
argument_list|,
literal|0
argument_list|,
literal|"Do you really want to quit ? "
argument_list|)
expr_stmt|;
name|ch
operator|=
name|getanswer
argument_list|(
literal|"NY"
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|ch
operator|==
literal|'Y'
condition|)
name|leavegame
argument_list|()
expr_stmt|;
comment|/*NOTREACHED*/
block|}
ifdef|#
directive|ifdef
name|SHELL
if|if
condition|(
name|ch
operator|==
literal|'!'
condition|)
comment|/* shell escape */
block|{
if|if
condition|(
operator|(
name|shell
operator|=
name|getenv
argument_list|(
literal|"SHELL"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
comment|/* use default */
name|shell
operator|=
name|SHELL
expr_stmt|;
if|if
condition|(
operator|(
name|childpid
operator|=
name|fork
argument_list|()
operator|)
operator|==
literal|0
condition|)
comment|/* in child */
block|{
name|clear
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
name|cleanup
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
comment|/* out of curses, close files */
name|setuid
argument_list|(
name|getuid
argument_list|()
argument_list|)
expr_stmt|;
comment|/* make sure we are running with real uid */
name|setgid
argument_list|(
name|getgid
argument_list|()
argument_list|)
expr_stmt|;
comment|/* make sure we are running with real gid */
name|execl
argument_list|(
name|shell
argument_list|,
name|shell
argument_list|,
literal|"-i"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|execl
argument_list|(
name|SHELL
argument_list|,
name|SHELL
argument_list|,
literal|"-i"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* last resort */
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/*NOTREACHED*/
block|}
else|else
comment|/* in parent */
block|{
while|while
condition|(
name|wait
argument_list|(
operator|(
name|int
operator|*
operator|)
name|NULL
argument_list|)
operator|!=
name|childpid
condition|)
empty_stmt|;
comment|/* wait until done */
name|crmode
argument_list|()
expr_stmt|;
comment|/* restore keyboard */
name|clearok
argument_list|(
name|stdscr
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
comment|/* force redraw of screen */
block|}
block|}
endif|#
directive|endif
name|mvaddstr
argument_list|(
literal|4
argument_list|,
literal|0
argument_list|,
name|line
argument_list|)
expr_stmt|;
comment|/* restore data on screen */
name|move
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|/* restore cursor */
name|refresh
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|SYS3
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|interrupt
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SYS5
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|interrupt
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|alarm
argument_list|(
name|savealarm
argument_list|)
expr_stmt|;
comment|/* restore alarm */
block|}
end_block

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/************************************************************************ / / FUNCTION NAME: getanswer() / / FUNCTION: get an answer from operator / / AUTHOR: E. A. Estes, 12/4/85 / / ARGUMENTS: /	char *choices - string of (upper case) valid choices /	bool def - set if default answer / / RETURN VALUE: none / / MODULES CALLED: alarm(), wmove(), waddch(), signal(), setjmp(), strchr(),  /	_filbuf(), clearok(), toupper(), wrefresh(), mvprintw(), wclrtoeol() / / GLOBAL INPUTS: catchalarm(), Echo, _iob[], _ctype[], *stdscr, Timeout,  /	Timeoenv[] / / GLOBAL OUTPUTS: _iob[] / / DESCRIPTION: /	Get a single character answer from operator. /	Timeout waiting for response.  If we timeout, or the /	answer in not in the list of valid choices, print choices, /	and wait again, otherwise return the first character in ths /	list of choices. /	Give up after 3 tries. / /************************************************************************/
end_comment

begin_macro
name|getanswer
argument_list|(
argument|choices
argument_list|,
argument|def
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|choices
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|def
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|ch
decl_stmt|;
comment|/* input */
name|int
name|loop
decl_stmt|;
comment|/* counter */
name|int
name|oldx
decl_stmt|,
name|oldy
decl_stmt|;
comment|/* original coordinates on screen */
name|getyx
argument_list|(
name|stdscr
argument_list|,
name|oldy
argument_list|,
name|oldx
argument_list|)
expr_stmt|;
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* make sure alarm is off */
for|for
control|(
name|loop
operator|=
literal|3
init|;
name|loop
condition|;
operator|--
name|loop
control|)
comment|/* try for 3 times */
block|{
if|if
condition|(
name|setjmp
argument_list|(
name|Timeoenv
argument_list|)
operator|!=
literal|0
condition|)
comment|/* timed out waiting for response */
block|{
if|if
condition|(
name|def
operator|||
name|loop
operator|<=
literal|1
condition|)
comment|/* return default answer */
break|break;
else|else
comment|/* prompt, and try again */
goto|goto
name|YELL
goto|;
block|}
else|else
comment|/* wait for response */
block|{
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|BSD41
name|sigset
argument_list|(
name|SIGALRM
argument_list|,
name|catchalarm
argument_list|)
expr_stmt|;
else|#
directive|else
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|catchalarm
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* set timeout */
if|if
condition|(
name|Timeout
condition|)
name|alarm
argument_list|(
literal|7
argument_list|)
expr_stmt|;
comment|/* short */
else|else
name|alarm
argument_list|(
literal|600
argument_list|)
expr_stmt|;
comment|/* long */
name|ch
operator|=
name|getchar
argument_list|()
expr_stmt|;
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* turn off timeout */
if|if
condition|(
name|ch
operator|<
literal|0
condition|)
comment|/* caught some signal */
block|{
operator|++
name|loop
expr_stmt|;
continue|continue;
block|}
elseif|else
if|if
condition|(
name|ch
operator|==
name|CH_REDRAW
condition|)
comment|/* redraw screen */
block|{
name|clearok
argument_list|(
name|stdscr
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
comment|/* force clear screen */
operator|++
name|loop
expr_stmt|;
comment|/* don't count this input */
continue|continue;
block|}
elseif|else
if|if
condition|(
name|Echo
condition|)
block|{
name|addch
argument_list|(
name|ch
argument_list|)
expr_stmt|;
comment|/* echo character */
name|refresh
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|islower
argument_list|(
name|ch
argument_list|)
condition|)
comment|/* convert to upper case */
name|ch
operator|=
name|toupper
argument_list|(
name|ch
argument_list|)
expr_stmt|;
if|if
condition|(
name|def
operator|||
name|strchr
argument_list|(
name|choices
argument_list|,
name|ch
argument_list|)
operator|!=
name|NULL
condition|)
comment|/* valid choice */
return|return
operator|(
name|ch
operator|)
return|;
elseif|else
if|if
condition|(
operator|!
name|def
operator|&&
name|loop
operator|>
literal|1
condition|)
comment|/* bad choice; prompt, and try again */
block|{
name|YELL
label|:
name|mvprintw
argument_list|(
name|oldy
operator|+
literal|1
argument_list|,
literal|0
argument_list|,
literal|"Please choose one of : [%s]\n"
argument_list|,
name|choices
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|oldy
argument_list|,
name|oldx
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
continue|continue;
block|}
else|else
comment|/* return default answer */
break|break;
block|}
block|}
return|return
operator|(
operator|*
name|choices
operator|)
return|;
block|}
end_block

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/************************************************************************ / / FUNCTION NAME: catchalarm() / / FUNCTION: catch timer when waiting for input / / AUTHOR: E. A. Estes, 12/4/85 / / ARGUMENTS: none / / RETURN VALUE: none / / MODULES CALLED: longjmp() / / GLOBAL INPUTS: Timeoenv[] / / GLOBAL OUTPUTS: none / / DESCRIPTION: /	Come here when the alarm expires while waiting for input. /	Simply longjmp() into getanswer(). / /************************************************************************/
end_comment

begin_macro
name|catchalarm
argument_list|()
end_macro

begin_block
block|{
name|longjmp
argument_list|(
name|Timeoenv
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

