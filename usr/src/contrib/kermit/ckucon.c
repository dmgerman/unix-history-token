begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
modifier|*
name|connv
init|=
literal|"Connect Command for Unix, V4C(014) 29 Jul 85"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  C K U C O N  --  Dumb terminal connection to remote system, for Unix  */
end_comment

begin_comment
comment|/*  This module should work under all versions of Unix.  It calls externally  defined system-dependent functions for i/o, but depends upon the existence  of the fork() function.   Author: Frank da Cruz (SY.FDC@CU20B),  Columbia University Center for Computing Activities, January 1985.  Copyright (C) 1985, Trustees of Columbia University in the City of New York.  Permission is granted to any individual or institution to use, copy, or  redistribute this software so long as it is not sold for profit, provided this  copyright notice is retained.    Enhanced by H. Fischer to detect when child process (modem reader)  reports that the communications line has been broken and hang up.  Also enhanced to allow escaping from connect state to command  interpreter, to allow sending/receiving without breaking connection. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_comment
comment|/* Character types */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_include
include|#
directive|include
file|"ckcker.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SIGUSR1
end_ifndef

begin_define
define|#
directive|define
name|SIGUSR1
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|local
decl_stmt|,
name|speed
decl_stmt|,
name|escape
decl_stmt|,
name|duplex
decl_stmt|,
name|parity
decl_stmt|,
name|flow
decl_stmt|,
name|seslog
decl_stmt|,
name|mdmtyp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ttname
index|[]
decl_stmt|,
name|sesfil
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|CHAR
name|dopar
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|i
decl_stmt|,
name|active
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables global to this module */
end_comment

begin_function_decl
name|char
modifier|*
name|chstr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
name|temp
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LBUFL
value|200
end_define

begin_comment
comment|/* Line buffer */
end_comment

begin_decl_stmt
name|char
name|lbuf
index|[
name|LBUFL
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Connect state parent/child communication signal handlers */
end_comment

begin_decl_stmt
specifier|static
name|jmp_buf
name|env_con
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Envir ptr for connect errors */
end_comment

begin_expr_stmt
specifier|static
name|conn_int
argument_list|()
block|{
comment|/* Modem read failure handler, */
name|longjmp
argument_list|(
name|env_con
argument_list|,
literal|1
argument_list|)
block|;
comment|/* notifies parent process to stop */
block|}
comment|/*  C O N E C T  --  Perform terminal connection  */
name|conect
argument_list|()
block|{
name|int
name|pid
block|,
comment|/* process id of child (modem reader) */
name|parent_id
block|,
comment|/* process id of parent (keyboard reader) */
name|n
block|;
name|int
name|c
block|;
comment|/* c is a character, but must be signed  				   integer to pass thru -1, which is the 				   modem disconnection signal, and is 				   different from the character 0377 */
name|char
name|errmsg
index|[
literal|50
index|]
block|,
operator|*
name|erp
block|;
if|if
condition|(
operator|!
name|local
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, you must 'set line' first\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|speed
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, you must 'set speed' first\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
end_if

begin_if
if|if
condition|(
operator|(
name|escape
operator|<
literal|0
operator|)
operator|||
operator|(
name|escape
operator|>
literal|0177
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"Your escape character is not ASCII - %d\n"
argument_list|,
name|escape
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
end_if

begin_if
if|if
condition|(
name|ttopen
argument_list|(
name|ttname
argument_list|,
operator|&
name|local
argument_list|,
name|mdmtyp
argument_list|)
operator|<
literal|0
condition|)
block|{
name|erp
operator|=
name|errmsg
expr_stmt|;
name|sprintf
argument_list|(
name|erp
argument_list|,
literal|"Sorry, can't open %s"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
name|perror
argument_list|(
name|errmsg
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
end_if

begin_expr_stmt
name|printf
argument_list|(
literal|"Connecting thru %s, speed %d.\r\n"
argument_list|,
name|ttname
argument_list|,
name|speed
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"The escape character is %s (%d).\r\n"
argument_list|,
name|chstr
argument_list|(
name|escape
argument_list|)
argument_list|,
name|escape
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"Type the escape character followed by C to get back,\r\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"or followed by ? to see other options.\r\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|seslog
condition|)
name|printf
argument_list|(
literal|"(Session logged to %s.)\r\n"
argument_list|,
name|sesfil
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* Condition console terminal and communication line */
end_comment

begin_if
if|if
condition|(
name|conbin
argument_list|(
name|escape
argument_list|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, can't condition console terminal\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
end_if

begin_if
if|if
condition|(
name|ttvt
argument_list|(
name|speed
argument_list|,
name|flow
argument_list|)
operator|<
literal|0
condition|)
block|{
name|conres
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"Sorry, Can't condition communication line\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
end_if

begin_comment
comment|/* cont'd... */
end_comment

begin_escape
end_escape

begin_comment
comment|/* ...connect, cont'd */
end_comment

begin_expr_stmt
name|parent_id
operator|=
name|getpid
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* get parent id for signalling */
end_comment

begin_expr_stmt
name|pid
operator|=
name|fork
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* All ok, make a fork */
end_comment

begin_if
if|if
condition|(
name|pid
condition|)
block|{
name|active
operator|=
literal|1
expr_stmt|;
comment|/* This fork reads, sends keystrokes */
if|if
condition|(
operator|!
name|setjmp
argument_list|(
name|env_con
argument_list|)
condition|)
block|{
comment|/* comm error in child process */
name|signal
argument_list|(
name|SIGUSR1
argument_list|,
name|conn_int
argument_list|)
expr_stmt|;
comment|/* routine for child process exit */
while|while
condition|(
name|active
condition|)
block|{
name|c
operator|=
name|coninc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
expr_stmt|;
comment|/* Get character from keyboard */
if|if
condition|(
name|c
operator|==
name|escape
condition|)
block|{
comment|/* Look for escape char */
name|c
operator|=
name|coninc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
expr_stmt|;
comment|/* Got esc, get its arg */
name|doesc
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* And process it */
block|}
else|else
block|{
comment|/* Ordinary character */
if|if
condition|(
name|ttoc
argument_list|(
name|dopar
argument_list|(
name|c
argument_list|)
argument_list|)
operator|>
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|duplex
condition|)
block|{
comment|/* Half duplex? */
name|conoc
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Yes, also echo it. */
if|if
condition|(
name|seslog
condition|)
comment|/* And maybe log it. */
if|if
condition|(
name|zchout
argument_list|(
name|ZSFILE
argument_list|,
name|c
argument_list|)
operator|<
literal|0
condition|)
name|seslog
operator|=
literal|0
expr_stmt|;
block|}
block|}
else|else
block|{
name|perror
argument_list|(
literal|"\r\nCan't send character"
argument_list|)
expr_stmt|;
name|active
operator|=
literal|0
expr_stmt|;
block|}
block|}
block|}
block|}
comment|/* Come here on death of child */
name|kill
argument_list|(
name|pid
argument_list|,
literal|9
argument_list|)
expr_stmt|;
comment|/* Done, kill inferior fork. */
name|wait
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Wait till gone. */
name|conres
argument_list|()
expr_stmt|;
comment|/* Reset the console. */
name|printf
argument_list|(
literal|"[Back at Local System]\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
else|else
block|{
comment|/* Inferior reads, prints port input */
while|while
condition|(
literal|1
condition|)
block|{
comment|/* Fresh read, wait for a character */
if|if
condition|(
operator|(
name|c
operator|=
name|ttinc
argument_list|(
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
comment|/* Comm line hangup detected */
if|if
condition|(
name|errno
operator|==
literal|9999
condition|)
comment|/* this value set by ckutio.c myread */
name|printf
argument_list|(
literal|"\r\nCommunications disconnect "
argument_list|)
expr_stmt|;
else|else
name|perror
argument_list|(
literal|"\r\nCan't get character"
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|parent_id
argument_list|,
name|SIGUSR1
argument_list|)
expr_stmt|;
comment|/* notify parent. */
name|pause
argument_list|()
expr_stmt|;
comment|/* Wait to be killed by parent. */
block|}
name|c
operator|&=
literal|0177
expr_stmt|;
comment|/* Got a char, strip parity, etc */
name|conoc
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Put it on the screen. */
if|if
condition|(
name|seslog
condition|)
name|zchout
argument_list|(
name|ZSFILE
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|/* If logging, log it. */
while|while
condition|(
operator|(
name|n
operator|=
name|ttchk
argument_list|()
operator|)
operator|>
literal|0
condition|)
block|{
comment|/* Any more left in buffer? */
if|if
condition|(
name|n
operator|>
name|LBUFL
condition|)
name|n
operator|=
name|LBUFL
expr_stmt|;
comment|/* Get them all at once. */
if|if
condition|(
operator|(
name|n
operator|=
name|ttxin
argument_list|(
name|n
argument_list|,
name|lbuf
argument_list|)
operator|)
operator|>
literal|0
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
name|i
operator|++
control|)
name|lbuf
index|[
name|i
index|]
operator|&=
literal|0177
expr_stmt|;
comment|/* Strip */
name|conxo
argument_list|(
name|n
argument_list|,
name|lbuf
argument_list|)
expr_stmt|;
comment|/* Output */
if|if
condition|(
name|seslog
condition|)
name|zsoutx
argument_list|(
name|ZSFILE
argument_list|,
name|lbuf
argument_list|,
name|n
argument_list|)
expr_stmt|;
comment|/* Log */
block|}
block|}
block|}
block|}
end_if

begin_escape
unit|}
end_escape

begin_comment
comment|/*  H C O N N E  --  Give help message for connect.  */
end_comment

begin_expr_stmt
unit|hconne
operator|(
operator|)
block|{
name|int
name|c
block|;
specifier|static
name|char
operator|*
name|hlpmsg
index|[]
operator|=
block|{
literal|"\ \r\nC to close the connection, or:"
block|,
literal|"\r\n  0 (zero) to send a null"
block|,
literal|"\r\n  B to send a BREAK"
block|,
literal|"\r\n  H to hangup and close connection"
block|,
literal|"\r\n  S for status"
block|,
literal|"\r\n  ? for help"
block|,
literal|"\r\n escape character twice to send the escape character.\r\n\r\n"
block|,
literal|""
block|}
block|;
name|conola
argument_list|(
name|hlpmsg
argument_list|)
block|;
comment|/* Print the help message. */
name|conol
argument_list|(
literal|"Command>"
argument_list|)
block|;
comment|/* Prompt for command. */
name|c
operator|=
name|coninc
argument_list|(
literal|0
argument_list|)
block|;
name|conoc
argument_list|(
name|c
argument_list|)
block|;
comment|/* Echo it. */
name|conoll
argument_list|(
literal|""
argument_list|)
block|;
name|c
operator|&=
literal|0177
block|;
comment|/* Strip any parity. */
return|return
operator|(
name|c
operator|)
return|;
comment|/* Return it. */
block|}
end_expr_stmt

begin_comment
comment|/*  C H S T R  --  Make a printable string out of a character  */
end_comment

begin_function
name|char
modifier|*
name|chstr
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
specifier|static
name|char
name|s
index|[
literal|8
index|]
decl_stmt|;
name|char
modifier|*
name|cp
init|=
name|s
decl_stmt|;
if|if
condition|(
name|c
operator|<
name|SP
condition|)
block|{
name|sprintf
argument_list|(
name|cp
argument_list|,
literal|"CTRL-%c"
argument_list|,
name|ctl
argument_list|(
name|c
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
name|sprintf
argument_list|(
name|cp
argument_list|,
literal|"'%c'\n"
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|cp
operator|=
name|s
expr_stmt|;
return|return
operator|(
name|cp
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  D O E S C  --  Process an escape character argument  */
end_comment

begin_macro
name|doesc
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
name|CHAR
name|d
decl_stmt|;
name|c
operator|&=
literal|0177
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
if|if
condition|(
name|c
operator|==
name|escape
condition|)
block|{
comment|/* Send escape character */
name|d
operator|=
name|dopar
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|ttoc
argument_list|(
name|d
argument_list|)
expr_stmt|;
return|return;
block|}
elseif|else
comment|/* Or else look it up below. */
if|if
condition|(
name|isupper
argument_list|(
name|c
argument_list|)
condition|)
name|c
operator|=
name|tolower
argument_list|(
name|c
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'c'
case|:
comment|/* Close connection */
case|case
literal|'\03'
case|:
name|active
operator|=
literal|0
expr_stmt|;
name|conol
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
return|return;
case|case
literal|'b'
case|:
comment|/* Send a BREAK signal */
case|case
literal|'\02'
case|:
name|ttsndb
argument_list|()
expr_stmt|;
return|return;
case|case
literal|'h'
case|:
comment|/* Hangup */
case|case
literal|'\010'
case|:
name|tthang
argument_list|()
expr_stmt|;
name|active
operator|=
literal|0
expr_stmt|;
name|conol
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
return|return;
case|case
literal|'s'
case|:
comment|/* Status */
case|case
literal|'\023'
case|:
name|conol
argument_list|(
literal|"\r\nConnected thru "
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|ttname
argument_list|)
expr_stmt|;
if|if
condition|(
name|speed
operator|>=
literal|0
condition|)
block|{
name|sprintf
argument_list|(
name|temp
argument_list|,
literal|", speed %d"
argument_list|,
name|speed
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|temp
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|parity
condition|)
block|{
name|conol
argument_list|(
literal|", "
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|parity
condition|)
block|{
case|case
literal|'e'
case|:
name|conol
argument_list|(
literal|"even"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'o'
case|:
name|conol
argument_list|(
literal|"odd"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|conol
argument_list|(
literal|"space"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'m'
case|:
name|conol
argument_list|(
literal|"mark"
argument_list|)
expr_stmt|;
break|break;
block|}
name|conol
argument_list|(
literal|" parity"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|seslog
condition|)
block|{
name|conol
argument_list|(
literal|", logging to "
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|sesfil
argument_list|)
expr_stmt|;
block|}
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
return|return;
case|case
literal|'?'
case|:
comment|/* Help */
name|c
operator|=
name|hconne
argument_list|()
expr_stmt|;
continue|continue;
case|case
literal|'0'
case|:
comment|/* Send a null */
name|c
operator|=
literal|'\0'
expr_stmt|;
name|d
operator|=
name|dopar
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|ttoc
argument_list|(
name|d
argument_list|)
expr_stmt|;
return|return;
case|case
name|SP
case|:
comment|/* Space, ignore */
return|return;
default|default:
comment|/* Other */
name|conoc
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
return|return;
comment|/* Invalid esc arg, beep */
block|}
block|}
block|}
end_block

end_unit

