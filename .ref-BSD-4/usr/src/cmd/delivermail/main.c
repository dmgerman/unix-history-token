begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"dlvrmail.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|LOG
end_ifdef

begin_include
include|#
directive|include
file|<log.h>
end_include

begin_endif
endif|#
directive|endif
endif|LOG
end_endif

begin_decl_stmt
specifier|static
name|char
name|SccsId
index|[]
init|=
literal|"@(#)main.c	1.11	10/18/80"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  DELIVERMAIL -- Deliver mail to a set of destinations ** **	This is the basic mail router.  All user mail programs should **	call this routine to actually deliver mail.  Delivermail in **	turn calls a bunch of mail servers that do the real work of **	delivering the mail. ** **	Delivermail is driven by tables defined in config.c.  This **	file will be different from system to system, but the rest **	of the code will be the same.  This table could be read in, **	but it seemed nicer to have it compiled in, since deliver- **	mail will potentially be exercised a lot. ** **	Usage: **		/etc/delivermail [-f name] [-a] [-q] [-v] [-n] [-m] addr ... ** **	Positional Parameters: **		addr -- the address to deliver the mail to.  There **			can be several. ** **	Flags: **		-f name		The mail is from "name" -- used for **				the header in local mail, and to **				deliver reports of failures to. **		-r name		Same as -f; however, this flag is **				reserved to indicate special processing **				for remote mail delivery as needed **				in the future.  So, network servers **				should use -r. **		-a		This mail should be in ARPANET std **				format (not used). **		-n		Don't do aliasing.  This might be used **				when delivering responses, for **				instance. **		-d		Run in debug mode. **		-em		Mail back a response if there was an **				error in processing.  This should be **				used when the origin of this message **				is another machine. **		-ew		Write back a response if the user is **				still logged in, otherwise, act like **				-em. **		-eq		Don't print any error message (just **				return exit status). **		-ep		(default)  Print error messages **				normally. **		-ee		Send BerkNet style errors.  This **				is equivalent to MailBack except **				that it has gives zero return code **				(unless there were errors during **				returning).  This used to be **				"EchoBack", but you know how the old **				software bounces. **		-m		In group expansion, send to the **				sender also (stands for the Mail metoo **				option. **		-i		Do not terminate mail on a line **				containing just dot. **		-s		Save UNIX-like "From" lines on the **				front of messages. ** **	Return Codes: **		As defined in<sysexits.h>. ** **		These codes are actually returned from the auxiliary **		mailers; it is their responsibility to make them **		correct. ** **	Compilation Flags: **		LOG -- if set, everything is logged. ** **	Compilation Instructions: **		cc -c -O main.c config.c deliver.c parse.c **		cc -n -s *.o -lS **		chown root a.out **		chmod 755 a.out **		mv a.out delivermail ** **	Deficiencies: **		It ought to collect together messages that are **			destined for a single host and send these **			to the auxiliary mail server together. **		It should take "user at host" as three separate **			parameters and combine them into one address. ** **	Author: **		Eric Allman, UCB/INGRES */
end_comment

begin_decl_stmt
name|bool
name|ArpaFmt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mail is expected to be in ARPANET format */
end_comment

begin_decl_stmt
name|bool
name|FromFlag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from person is explicitly specified */
end_comment

begin_decl_stmt
name|bool
name|Debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* run in debug mode */
end_comment

begin_decl_stmt
name|bool
name|MailBack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mail back response on error */
end_comment

begin_decl_stmt
name|bool
name|BerkNet
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* called from BerkNet */
end_comment

begin_decl_stmt
name|bool
name|WriteBack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* write back response on error */
end_comment

begin_decl_stmt
name|bool
name|HasXscrpt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, the transcript file exists */
end_comment

begin_decl_stmt
name|bool
name|NoAlias
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't do aliasing */
end_comment

begin_decl_stmt
name|bool
name|ForceMail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mail even if already sent a copy */
end_comment

begin_decl_stmt
name|bool
name|MeToo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* send to the sender also if in a group expansion */
end_comment

begin_decl_stmt
name|bool
name|SaveFrom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* save From lines on the front of messages */
end_comment

begin_decl_stmt
name|bool
name|IgnrDot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, ignore dot when collecting mail */
end_comment

begin_decl_stmt
name|bool
name|SuprErrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* supress errors if set */
end_comment

begin_decl_stmt
name|int
name|Errors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of errors */
end_comment

begin_decl_stmt
name|char
name|InFileName
index|[]
init|=
literal|"/tmp/mailtXXXXXX"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Transcript
index|[]
init|=
literal|"/tmp/mailxXXXXXX"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|addrq
name|From
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the from person */
end_comment

begin_decl_stmt
name|char
modifier|*
name|To
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the target person */
end_comment

begin_decl_stmt
name|int
name|HopCount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hop count */
end_comment

begin_decl_stmt
name|int
name|ExitStat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the exit status byte */
end_comment

begin_decl_stmt
name|addrq
name|SendQ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* queue of people to send to */
end_comment

begin_decl_stmt
name|addrq
name|AliasQ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* queue of people who turned out to be aliases */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|extern
name|char
modifier|*
name|maketemp
parameter_list|()
function_decl|;
specifier|extern
name|char
modifier|*
name|getname
parameter_list|()
function_decl|;
specifier|extern
name|int
name|finis
parameter_list|()
function_decl|;
specifier|extern
name|addrq
modifier|*
name|parse
parameter_list|()
function_decl|;
specifier|register
name|addrq
modifier|*
name|q
decl_stmt|;
specifier|extern
name|char
name|Version
index|[]
decl_stmt|;
specifier|extern
name|int
name|errno
decl_stmt|;
name|char
modifier|*
name|from
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
typedef|typedef
name|int
function_decl|(
modifier|*
name|fnptr
function_decl|)
parameter_list|()
function_decl|;
if|if
condition|(
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
operator|!=
name|SIG_IGN
condition|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|finis
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|finis
argument_list|)
expr_stmt|;
name|setbuf
argument_list|(
name|stdout
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|LOG
name|initlog
argument_list|(
literal|"delivermail"
argument_list|,
literal|0
argument_list|,
name|LOG_INDEP
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|LOG
ifdef|#
directive|ifdef
name|DEBUG
ifdef|#
directive|ifdef
name|DEBUGFILE
if|if
condition|(
operator|(
name|i
operator|=
name|open
argument_list|(
name|DEBUGFILE
argument_list|,
literal|1
argument_list|)
operator|)
operator|>
literal|0
condition|)
block|{
name|lseek
argument_list|(
name|i
argument_list|,
literal|0L
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|close
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|dup
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|Debug
operator|++
expr_stmt|;
block|}
endif|#
directive|endif
endif|DEBUGFILE
endif|#
directive|endif
name|errno
operator|=
literal|0
expr_stmt|;
name|from
operator|=
name|NULL
expr_stmt|;
comment|/* 	** Crack argv. 	*/
while|while
condition|(
operator|--
name|argc
operator|>
literal|0
operator|&&
operator|(
name|p
operator|=
operator|*
operator|++
name|argv
operator|)
index|[
literal|0
index|]
operator|==
literal|'-'
condition|)
block|{
switch|switch
condition|(
name|p
index|[
literal|1
index|]
condition|)
block|{
case|case
literal|'r'
case|:
comment|/* obsolete -f flag */
case|case
literal|'f'
case|:
comment|/* from address */
name|p
operator|+=
literal|2
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|==
literal|'\0'
condition|)
block|{
name|p
operator|=
operator|*
operator|++
name|argv
expr_stmt|;
if|if
condition|(
operator|--
name|argc
operator|<=
literal|0
operator|||
operator|*
name|p
operator|==
literal|'-'
condition|)
block|{
name|syserr
argument_list|(
literal|"No \"from\" person"
argument_list|)
expr_stmt|;
name|argc
operator|++
expr_stmt|;
name|argv
operator|--
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|from
operator|!=
name|NULL
condition|)
block|{
name|syserr
argument_list|(
literal|"More than one \"from\" person"
argument_list|)
expr_stmt|;
break|break;
block|}
name|from
operator|=
name|p
expr_stmt|;
break|break;
case|case
literal|'h'
case|:
comment|/* hop count */
name|p
operator|+=
literal|2
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|==
literal|'\0'
condition|)
block|{
name|p
operator|=
operator|*
operator|++
name|argv
expr_stmt|;
if|if
condition|(
operator|--
name|argc
operator|<=
literal|0
operator|||
operator|*
name|p
operator|<
literal|'0'
operator|||
operator|*
name|p
operator|>
literal|'9'
condition|)
block|{
name|syserr
argument_list|(
literal|"Bad hop count (%s)"
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|argc
operator|++
expr_stmt|;
name|argv
operator|--
expr_stmt|;
break|break;
block|}
block|}
name|HopCount
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'e'
case|:
comment|/* error message disposition */
switch|switch
condition|(
name|p
index|[
literal|2
index|]
condition|)
block|{
case|case
literal|'p'
case|:
comment|/* print errors normally */
break|break;
comment|/* (default) */
case|case
literal|'q'
case|:
comment|/* be silent about it */
name|freopen
argument_list|(
literal|"/dev/null"
argument_list|,
literal|"w"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'m'
case|:
comment|/* mail back */
name|MailBack
operator|++
expr_stmt|;
name|openxscrpt
argument_list|()
expr_stmt|;
break|break;
case|case
literal|'e'
case|:
comment|/* do berknet error processing */
name|BerkNet
operator|++
expr_stmt|;
name|openxscrpt
argument_list|()
expr_stmt|;
break|break;
case|case
literal|'w'
case|:
comment|/* write back (or mail) */
name|WriteBack
operator|++
expr_stmt|;
name|openxscrpt
argument_list|()
expr_stmt|;
break|break;
block|}
break|break;
ifdef|#
directive|ifdef
name|DEBUG
case|case
literal|'d'
case|:
comment|/* debug */
name|Debug
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|Version
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
endif|DEBUG
case|case
literal|'n'
case|:
comment|/* don't alias */
name|NoAlias
operator|++
expr_stmt|;
break|break;
case|case
literal|'m'
case|:
comment|/* send to me too */
name|MeToo
operator|++
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
comment|/* don't let dot stop me */
name|IgnrDot
operator|++
expr_stmt|;
break|break;
case|case
literal|'a'
case|:
comment|/* arpanet format */
name|ArpaFmt
operator|++
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
comment|/* save From lines in headers */
name|SaveFrom
operator|++
expr_stmt|;
break|break;
default|default:
comment|/* at Eric Schmidt's suggestion, this will not be an error.... 			syserr("Unknown flag %s", p); 			... seems that upward compatibility will be easier. */
break|break;
block|}
block|}
if|if
condition|(
name|from
operator|!=
name|NULL
operator|&&
name|ArpaFmt
condition|)
name|syserr
argument_list|(
literal|"-f and -a are mutually exclusive"
argument_list|)
expr_stmt|;
comment|/* 	** Get a temp file. 	*/
name|p
operator|=
name|maketemp
argument_list|()
expr_stmt|;
if|if
condition|(
name|from
operator|==
name|NULL
condition|)
name|from
operator|=
name|p
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|Debug
condition|)
name|printf
argument_list|(
literal|"Message-Id:<%s>\n"
argument_list|,
name|MsgId
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|DEBUG
comment|/* 	**  Figure out who it's coming from. 	**	Under certain circumstances allow the user to say who 	**	s/he is (using -f or -r).  These are: 	**	1.  The user's uid is zero (root). 	**	2.  The user's login name is "network" (mail from 	**	    a network server). 	**	3.  The user's login name is "uucp" (mail from the 	**	    uucp network). 	**	4.  The address the user is trying to claim has a 	**	    "!" character in it (since #3 doesn't do it for 	**	    us if we are dialing out). 	**	A better check to replace #3& #4 would be if the 	**	effective uid is "UUCP" -- this would require me 	**	to rewrite getpwent to "grab" uucp as it went by, 	**	make getname more nasty, do another passwd file 	**	scan, or compile the UID of "UUCP" into the code, 	**	all of which are reprehensible. 	** 	**	Assuming all of these fail, we figure out something 	**	ourselves. 	*/
name|errno
operator|=
literal|0
expr_stmt|;
name|p
operator|=
name|getname
argument_list|()
expr_stmt|;
if|if
condition|(
name|p
operator|==
name|NULL
operator|||
name|p
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
block|{
name|syserr
argument_list|(
literal|"Who are you? (uid=%d)"
argument_list|,
name|getuid
argument_list|()
argument_list|)
expr_stmt|;
name|finis
argument_list|()
expr_stmt|;
block|}
name|errno
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|from
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|p
argument_list|,
literal|"network"
argument_list|)
operator|!=
literal|0
operator|&&
name|strcmp
argument_list|(
name|p
argument_list|,
literal|"uucp"
argument_list|)
operator|!=
literal|0
operator|&&
name|index
argument_list|(
name|from
argument_list|,
literal|'!'
argument_list|)
operator|==
name|NULL
operator|&&
name|getuid
argument_list|()
operator|!=
literal|0
condition|)
block|{
comment|/* network sends -r regardless (why why why?) */
comment|/* syserr("%s, you cannot use the -f flag", p); */
name|from
operator|=
name|NULL
expr_stmt|;
block|}
block|}
if|if
condition|(
name|from
operator|==
name|NULL
operator|||
name|from
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
name|from
operator|=
name|p
expr_stmt|;
else|else
name|FromFlag
operator|++
expr_stmt|;
name|SuprErrs
operator|=
name|TRUE
expr_stmt|;
if|if
condition|(
name|parse
argument_list|(
name|from
argument_list|,
operator|&
name|From
argument_list|,
literal|0
argument_list|)
operator|==
name|NULL
condition|)
block|{
comment|/* too many arpanet hosts generate garbage From addresses .... 		syserr("Bad from address `%s'", from); 		.... so we will just ignore this address */
name|from
operator|=
name|p
expr_stmt|;
name|FromFlag
operator|=
name|FALSE
expr_stmt|;
block|}
name|SuprErrs
operator|=
name|FALSE
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|Debug
condition|)
name|printf
argument_list|(
literal|"From person = \"%s\"\n"
argument_list|,
name|From
operator|.
name|q_paddr
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|DEBUG
if|if
condition|(
name|argc
operator|<=
literal|0
condition|)
name|usrerr
argument_list|(
literal|"Usage: /etc/delivermail [flags] addr..."
argument_list|)
expr_stmt|;
comment|/* 	**  Process Hop count. 	**	The Hop count tells us how many times this message has 	**	been processed by delivermail.  If it exceeds some 	**	fairly large threshold, then we assume that we have 	**	an infinite forwarding loop and die. 	*/
if|if
condition|(
operator|++
name|HopCount
operator|>
name|MAXHOP
condition|)
name|syserr
argument_list|(
literal|"Infinite forwarding loop (%s->%s)"
argument_list|,
name|From
operator|.
name|q_paddr
argument_list|,
operator|*
name|argv
argument_list|)
expr_stmt|;
comment|/* 	** Scan argv and deliver the message to everyone. 	*/
for|for
control|(
init|;
name|argc
operator|--
operator|>
literal|0
condition|;
name|argv
operator|++
control|)
block|{
name|sendto
argument_list|(
operator|*
name|argv
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/* if we have had errors sofar, drop out now */
if|if
condition|(
name|Errors
operator|>
literal|0
operator|&&
name|ExitStat
operator|==
name|EX_OK
condition|)
name|ExitStat
operator|=
name|EX_USAGE
expr_stmt|;
if|if
condition|(
name|ExitStat
operator|!=
name|EX_OK
condition|)
name|finis
argument_list|()
expr_stmt|;
comment|/* 	**  See if we have anyone to send to at all. 	*/
if|if
condition|(
name|nxtinq
argument_list|(
operator|&
name|SendQ
argument_list|)
operator|==
name|NULL
operator|&&
name|ExitStat
operator|==
name|EX_OK
condition|)
block|{
name|syserr
argument_list|(
literal|"Noone to send to!"
argument_list|)
expr_stmt|;
name|ExitStat
operator|=
name|EX_USAGE
expr_stmt|;
name|finis
argument_list|()
expr_stmt|;
block|}
comment|/* 	**  Do aliasing. 	**	First arrange that the person who is sending the mail 	**	will not be expanded (unless explicitly requested). 	*/
if|if
condition|(
operator|!
name|MeToo
condition|)
name|recipient
argument_list|(
operator|&
name|From
argument_list|,
operator|&
name|AliasQ
argument_list|)
expr_stmt|;
name|To
operator|=
name|NULL
expr_stmt|;
name|alias
argument_list|()
expr_stmt|;
if|if
condition|(
name|nxtinq
argument_list|(
operator|&
name|SendQ
argument_list|)
operator|==
name|NULL
operator|&&
name|ExitStat
operator|==
name|EX_OK
condition|)
block|{
comment|/* 		syserr("Vacant send queue; probably aliasing loop"); 		ExitStat = EX_SOFTWARE; 		finis(); */
name|recipient
argument_list|(
operator|&
name|From
argument_list|,
operator|&
name|SendQ
argument_list|)
expr_stmt|;
block|}
comment|/* 	**  Actually send everything. 	*/
for|for
control|(
name|q
operator|=
operator|&
name|SendQ
init|;
operator|(
name|q
operator|=
name|nxtinq
argument_list|(
name|q
argument_list|)
operator|)
operator|!=
name|NULL
condition|;
control|)
name|deliver
argument_list|(
name|q
argument_list|,
operator|(
name|fnptr
operator|)
name|NULL
argument_list|)
expr_stmt|;
comment|/* 	** All done. 	*/
name|finis
argument_list|()
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  FINIS -- Clean up and exit. ** **	Parameters: **		none ** **	Returns: **		never ** **	Side Effects: **		exits delivermail ** **	Called By: **		main **		via signal on interrupt. ** **	Deficiencies: **		It may be that it should only remove the input **			file if there have been no errors. */
end_comment

begin_macro
name|finis
argument_list|()
end_macro

begin_block
block|{
comment|/* mail back the transcript on errors */
if|if
condition|(
name|ExitStat
operator|!=
name|EX_OK
condition|)
name|savemail
argument_list|()
expr_stmt|;
if|if
condition|(
name|HasXscrpt
condition|)
name|unlink
argument_list|(
name|Transcript
argument_list|)
expr_stmt|;
name|unlink
argument_list|(
name|InFileName
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|ExitStat
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  OPENXSCRPT -- Open transcript file ** **	Creates a transcript file for possible eventual mailing or **	sending back. ** **	Parameters: **		none ** **	Returns: **		none ** **	Side Effects: **		Turns the standard output into a special file **			somewhere. ** **	Called By: **		main */
end_comment

begin_macro
name|openxscrpt
argument_list|()
end_macro

begin_block
block|{
name|mktemp
argument_list|(
name|Transcript
argument_list|)
expr_stmt|;
name|HasXscrpt
operator|++
expr_stmt|;
if|if
condition|(
name|freopen
argument_list|(
name|Transcript
argument_list|,
literal|"w"
argument_list|,
name|stdout
argument_list|)
operator|==
name|NULL
condition|)
name|syserr
argument_list|(
literal|"Can't create %s"
argument_list|,
name|Transcript
argument_list|)
expr_stmt|;
name|chmod
argument_list|(
name|Transcript
argument_list|,
literal|0600
argument_list|)
expr_stmt|;
name|setbuf
argument_list|(
name|stdout
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

