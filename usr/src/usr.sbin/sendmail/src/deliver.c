begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Eric P. Allman  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)deliver.c	5.52 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"sendmail.h"
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NAMED_BIND
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<resolv.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  DELIVER -- Deliver a message to a list of addresses. ** **	This routine delivers to everyone on the same host as the **	user on the head of the list.  It is clever about mailers **	that don't handle multiple users.  It is NOT guaranteed **	that it will deliver to all these addresses however -- so **	deliver should be called once for each address on the **	list. ** **	Parameters: **		e -- the envelope to deliver. **		firstto -- head of the address list to deliver to. ** **	Returns: **		zero -- successfully delivered. **		else -- some failure, see ExitStat for more info. ** **	Side Effects: **		The standard input is passed off to someone. */
end_comment

begin_expr_stmt
name|deliver
argument_list|(
name|e
argument_list|,
name|firstto
argument_list|)
specifier|register
name|ENVELOPE
operator|*
name|e
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ADDRESS
modifier|*
name|firstto
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|host
decl_stmt|;
comment|/* host being sent to */
name|char
modifier|*
name|user
decl_stmt|;
comment|/* user being sent to */
name|char
modifier|*
modifier|*
name|pvp
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|mvp
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|register
name|MAILER
modifier|*
name|m
decl_stmt|;
comment|/* mailer for this recipient */
name|ADDRESS
modifier|*
name|ctladdr
decl_stmt|;
specifier|register
name|ADDRESS
modifier|*
name|to
init|=
name|firstto
decl_stmt|;
name|bool
name|clever
init|=
name|FALSE
decl_stmt|;
comment|/* running user smtp to this mailer */
name|ADDRESS
modifier|*
name|tochain
init|=
name|NULL
decl_stmt|;
comment|/* chain of users in this mailer call */
name|int
name|rcode
decl_stmt|;
comment|/* response code */
name|char
modifier|*
name|from
decl_stmt|;
comment|/* pointer to from person */
name|char
modifier|*
name|pv
index|[
name|MAXPV
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|tobuf
index|[
name|MAXLINE
operator|-
literal|50
index|]
decl_stmt|;
comment|/* text line of to people */
name|char
name|buf
index|[
name|MAXNAME
index|]
decl_stmt|;
name|char
name|tfrombuf
index|[
name|MAXNAME
index|]
decl_stmt|;
comment|/* translated from person */
name|char
name|rpathbuf
index|[
name|MAXNAME
index|]
decl_stmt|;
comment|/* translated return path */
specifier|extern
name|bool
name|checkcompat
parameter_list|()
function_decl|;
specifier|extern
name|ADDRESS
modifier|*
name|getctladdr
parameter_list|()
function_decl|;
specifier|extern
name|char
modifier|*
name|remotename
parameter_list|()
function_decl|;
name|errno
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|ForceMail
operator|&&
name|bitset
argument_list|(
name|QDONTSEND
operator||
name|QPSEUDO
argument_list|,
name|to
operator|->
name|q_flags
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
ifdef|#
directive|ifdef
name|NAMED_BIND
comment|/* unless interactive, try twice, over a minute */
if|if
condition|(
name|OpMode
operator|==
name|MD_DAEMON
operator|||
name|OpMode
operator|==
name|MD_SMTP
condition|)
block|{
name|_res
operator|.
name|retrans
operator|=
literal|30
expr_stmt|;
name|_res
operator|.
name|retry
operator|=
literal|2
expr_stmt|;
block|}
endif|#
directive|endif
name|m
operator|=
name|to
operator|->
name|q_mailer
expr_stmt|;
name|host
operator|=
name|to
operator|->
name|q_host
expr_stmt|;
if|if
condition|(
name|tTd
argument_list|(
literal|10
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"\n--deliver, mailer=%d, host=`%s', first user=`%s'\n"
argument_list|,
name|m
operator|->
name|m_mno
argument_list|,
name|host
argument_list|,
name|to
operator|->
name|q_user
argument_list|)
expr_stmt|;
comment|/* 	**  If this mailer is expensive, and if we don't want to make 	**  connections now, just mark these addresses and return. 	**	This is useful if we want to batch connections to 	**	reduce load.  This will cause the messages to be 	**	queued up, and a daemon will come along to send the 	**	messages later. 	**		This should be on a per-mailer basis. 	*/
if|if
condition|(
name|NoConnect
operator|&&
operator|!
name|QueueRun
operator|&&
name|bitnset
argument_list|(
name|M_EXPENSIVE
argument_list|,
name|m
operator|->
name|m_flags
argument_list|)
operator|&&
operator|!
name|Verbose
condition|)
block|{
for|for
control|(
init|;
name|to
operator|!=
name|NULL
condition|;
name|to
operator|=
name|to
operator|->
name|q_next
control|)
block|{
if|if
condition|(
name|bitset
argument_list|(
name|QDONTSEND
argument_list|,
name|to
operator|->
name|q_flags
argument_list|)
operator|||
name|to
operator|->
name|q_mailer
operator|!=
name|m
condition|)
continue|continue;
name|to
operator|->
name|q_flags
operator||=
name|QQUEUEUP
operator||
name|QDONTSEND
expr_stmt|;
name|e
operator|->
name|e_to
operator|=
name|to
operator|->
name|q_paddr
expr_stmt|;
name|message
argument_list|(
name|Arpa_Info
argument_list|,
literal|"queued"
argument_list|)
expr_stmt|;
if|if
condition|(
name|LogLevel
operator|>
literal|4
condition|)
name|logdelivery
argument_list|(
literal|"queued"
argument_list|)
expr_stmt|;
block|}
name|e
operator|->
name|e_to
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* 	**  Do initial argv setup. 	**	Insert the mailer name.  Notice that $x expansion is 	**	NOT done on the mailer name.  Then, if the mailer has 	**	a picky -f flag, we insert it as appropriate.  This 	**	code does not check for 'pv' overflow; this places a 	**	manifest lower limit of 4 for MAXPV. 	**		The from address rewrite is expected to make 	**		the address relative to the other end. 	*/
comment|/* rewrite from address, using rewriting rules */
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|rpathbuf
argument_list|,
name|remotename
argument_list|(
name|e
operator|->
name|e_returnpath
argument_list|,
name|m
argument_list|,
name|TRUE
argument_list|,
name|TRUE
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|e_returnpath
operator|==
name|e
operator|->
name|e_sender
condition|)
block|{
name|from
operator|=
name|rpathbuf
expr_stmt|;
block|}
else|else
block|{
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|tfrombuf
argument_list|,
name|remotename
argument_list|(
name|e
operator|->
name|e_sender
argument_list|,
name|m
argument_list|,
name|TRUE
argument_list|,
name|TRUE
argument_list|)
argument_list|)
expr_stmt|;
name|from
operator|=
name|tfrombuf
expr_stmt|;
block|}
name|define
argument_list|(
literal|'f'
argument_list|,
name|e
operator|->
name|e_returnpath
argument_list|,
name|e
argument_list|)
expr_stmt|;
comment|/* raw return path */
name|define
argument_list|(
literal|'<'
argument_list|,
name|rpathbuf
argument_list|,
name|e
argument_list|)
expr_stmt|;
comment|/* translated return path */
name|define
argument_list|(
literal|'g'
argument_list|,
name|from
argument_list|,
name|e
argument_list|)
expr_stmt|;
comment|/* translated sender */
name|define
argument_list|(
literal|'h'
argument_list|,
name|host
argument_list|,
name|e
argument_list|)
expr_stmt|;
comment|/* to host */
name|Errors
operator|=
literal|0
expr_stmt|;
name|pvp
operator|=
name|pv
expr_stmt|;
operator|*
name|pvp
operator|++
operator|=
name|m
operator|->
name|m_argv
index|[
literal|0
index|]
expr_stmt|;
comment|/* insert -f or -r flag as appropriate */
if|if
condition|(
name|FromFlag
operator|&&
operator|(
name|bitnset
argument_list|(
name|M_FOPT
argument_list|,
name|m
operator|->
name|m_flags
argument_list|)
operator|||
name|bitnset
argument_list|(
name|M_ROPT
argument_list|,
name|m
operator|->
name|m_flags
argument_list|)
operator|)
condition|)
block|{
if|if
condition|(
name|bitnset
argument_list|(
name|M_FOPT
argument_list|,
name|m
operator|->
name|m_flags
argument_list|)
condition|)
operator|*
name|pvp
operator|++
operator|=
literal|"-f"
expr_stmt|;
else|else
operator|*
name|pvp
operator|++
operator|=
literal|"-r"
expr_stmt|;
operator|*
name|pvp
operator|++
operator|=
name|newstr
argument_list|(
name|rpathbuf
argument_list|)
expr_stmt|;
block|}
comment|/* 	**  Append the other fixed parts of the argv.  These run 	**  up to the first entry containing "$u".  There can only 	**  be one of these, and there are only a few more slots 	**  in the pv after it. 	*/
for|for
control|(
name|mvp
operator|=
name|m
operator|->
name|m_argv
init|;
operator|(
name|p
operator|=
operator|*
operator|++
name|mvp
operator|)
operator|!=
name|NULL
condition|;
control|)
block|{
while|while
condition|(
operator|(
name|p
operator|=
name|index
argument_list|(
name|p
argument_list|,
literal|'\001'
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
if|if
condition|(
operator|*
operator|++
name|p
operator|==
literal|'u'
condition|)
break|break;
if|if
condition|(
name|p
operator|!=
name|NULL
condition|)
break|break;
comment|/* this entry is safe -- go ahead and process it */
name|expand
argument_list|(
operator|*
name|mvp
argument_list|,
name|buf
argument_list|,
operator|&
name|buf
index|[
sizeof|sizeof
name|buf
operator|-
literal|1
index|]
argument_list|,
name|e
argument_list|)
expr_stmt|;
operator|*
name|pvp
operator|++
operator|=
name|newstr
argument_list|(
name|buf
argument_list|)
expr_stmt|;
if|if
condition|(
name|pvp
operator|>=
operator|&
name|pv
index|[
name|MAXPV
operator|-
literal|3
index|]
condition|)
block|{
name|syserr
argument_list|(
literal|"Too many parameters to %s before $u"
argument_list|,
name|pv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
comment|/* 	**  If we have no substitution for the user name in the argument 	**  list, we know that we must supply the names otherwise -- and 	**  SMTP is the answer!! 	*/
if|if
condition|(
operator|*
name|mvp
operator|==
name|NULL
condition|)
block|{
comment|/* running SMTP */
ifdef|#
directive|ifdef
name|SMTP
name|clever
operator|=
name|TRUE
expr_stmt|;
operator|*
name|pvp
operator|=
name|NULL
expr_stmt|;
else|#
directive|else
else|SMTP
comment|/* oops!  we don't implement SMTP */
name|syserr
argument_list|(
literal|"SMTP style mailer"
argument_list|)
expr_stmt|;
return|return
operator|(
name|EX_SOFTWARE
operator|)
return|;
endif|#
directive|endif
endif|SMTP
block|}
comment|/* 	**  At this point *mvp points to the argument with $u.  We 	**  run through our address list and append all the addresses 	**  we can.  If we run out of space, do not fret!  We can 	**  always send another copy later. 	*/
name|tobuf
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
name|e
operator|->
name|e_to
operator|=
name|tobuf
expr_stmt|;
name|ctladdr
operator|=
name|NULL
expr_stmt|;
for|for
control|(
init|;
name|to
operator|!=
name|NULL
condition|;
name|to
operator|=
name|to
operator|->
name|q_next
control|)
block|{
comment|/* avoid sending multiple recipients to dumb mailers */
if|if
condition|(
name|tobuf
index|[
literal|0
index|]
operator|!=
literal|'\0'
operator|&&
operator|!
name|bitnset
argument_list|(
name|M_MUSER
argument_list|,
name|m
operator|->
name|m_flags
argument_list|)
condition|)
break|break;
comment|/* if already sent or not for this host, don't send */
if|if
condition|(
name|bitset
argument_list|(
name|QDONTSEND
argument_list|,
name|to
operator|->
name|q_flags
argument_list|)
operator|||
name|strcmp
argument_list|(
name|to
operator|->
name|q_host
argument_list|,
name|host
argument_list|)
operator|!=
literal|0
operator|||
name|to
operator|->
name|q_mailer
operator|!=
name|firstto
operator|->
name|q_mailer
condition|)
continue|continue;
comment|/* avoid overflowing tobuf */
if|if
condition|(
sizeof|sizeof
name|tobuf
operator|<
operator|(
name|strlen
argument_list|(
name|to
operator|->
name|q_paddr
argument_list|)
operator|+
name|strlen
argument_list|(
name|tobuf
argument_list|)
operator|+
literal|2
operator|)
condition|)
break|break;
if|if
condition|(
name|tTd
argument_list|(
literal|10
argument_list|,
literal|1
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"\nsend to "
argument_list|)
expr_stmt|;
name|printaddr
argument_list|(
name|to
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
block|}
comment|/* compute effective uid/gid when sending */
if|if
condition|(
name|to
operator|->
name|q_mailer
operator|==
name|ProgMailer
condition|)
name|ctladdr
operator|=
name|getctladdr
argument_list|(
name|to
argument_list|)
expr_stmt|;
name|user
operator|=
name|to
operator|->
name|q_user
expr_stmt|;
name|e
operator|->
name|e_to
operator|=
name|to
operator|->
name|q_paddr
expr_stmt|;
name|to
operator|->
name|q_flags
operator||=
name|QDONTSEND
expr_stmt|;
comment|/* 		**  Check to see that these people are allowed to 		**  talk to each other. 		*/
if|if
condition|(
name|m
operator|->
name|m_maxsize
operator|!=
literal|0
operator|&&
name|e
operator|->
name|e_msgsize
operator|>
name|m
operator|->
name|m_maxsize
condition|)
block|{
name|NoReturn
operator|=
name|TRUE
expr_stmt|;
name|usrerr
argument_list|(
literal|"Message is too large; %ld bytes max"
argument_list|,
name|m
operator|->
name|m_maxsize
argument_list|)
expr_stmt|;
name|giveresponse
argument_list|(
name|EX_UNAVAILABLE
argument_list|,
name|m
argument_list|,
name|e
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
operator|!
name|checkcompat
argument_list|(
name|to
argument_list|)
condition|)
block|{
name|giveresponse
argument_list|(
name|EX_UNAVAILABLE
argument_list|,
name|m
argument_list|,
name|e
argument_list|)
expr_stmt|;
continue|continue;
block|}
comment|/* 		**  Strip quote bits from names if the mailer is dumb 		**	about them. 		*/
if|if
condition|(
name|bitnset
argument_list|(
name|M_STRIPQ
argument_list|,
name|m
operator|->
name|m_flags
argument_list|)
condition|)
block|{
name|stripquotes
argument_list|(
name|user
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|stripquotes
argument_list|(
name|host
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|stripquotes
argument_list|(
name|user
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|stripquotes
argument_list|(
name|host
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
block|}
comment|/* hack attack -- delivermail compatibility */
if|if
condition|(
name|m
operator|==
name|ProgMailer
operator|&&
operator|*
name|user
operator|==
literal|'|'
condition|)
name|user
operator|++
expr_stmt|;
comment|/* 		**  If an error message has already been given, don't 		**	bother to send to this address. 		** 		**>>>>>>>>>> This clause assumes that the local mailer 		**>> NOTE>> cannot do any further aliasing; that 		**>>>>>>>>>> function is subsumed by sendmail. 		*/
if|if
condition|(
name|bitset
argument_list|(
name|QBADADDR
operator||
name|QQUEUEUP
argument_list|,
name|to
operator|->
name|q_flags
argument_list|)
condition|)
continue|continue;
comment|/* save statistics.... */
name|markstats
argument_list|(
name|e
argument_list|,
name|to
argument_list|)
expr_stmt|;
comment|/* 		**  See if this user name is "special". 		**	If the user name has a slash in it, assume that this 		**	is a file -- send it off without further ado.  Note 		**	that this type of addresses is not processed along 		**	with the others, so we fudge on the To person. 		*/
if|if
condition|(
name|m
operator|==
name|LocalMailer
condition|)
block|{
if|if
condition|(
name|user
index|[
literal|0
index|]
operator|==
literal|'/'
condition|)
block|{
name|rcode
operator|=
name|mailfile
argument_list|(
name|user
argument_list|,
name|getctladdr
argument_list|(
name|to
argument_list|)
argument_list|)
expr_stmt|;
name|giveresponse
argument_list|(
name|rcode
argument_list|,
name|m
argument_list|,
name|e
argument_list|)
expr_stmt|;
if|if
condition|(
name|rcode
operator|==
name|EX_OK
condition|)
name|to
operator|->
name|q_flags
operator||=
name|QSENT
expr_stmt|;
continue|continue;
block|}
block|}
comment|/* 		**  Address is verified -- add this user to mailer 		**  argv, and add it to the print list of recipients. 		*/
comment|/* link together the chain of recipients */
name|to
operator|->
name|q_tchain
operator|=
name|tochain
expr_stmt|;
name|tochain
operator|=
name|to
expr_stmt|;
comment|/* create list of users for error messages */
operator|(
name|void
operator|)
name|strcat
argument_list|(
name|tobuf
argument_list|,
literal|","
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcat
argument_list|(
name|tobuf
argument_list|,
name|to
operator|->
name|q_paddr
argument_list|)
expr_stmt|;
name|define
argument_list|(
literal|'u'
argument_list|,
name|user
argument_list|,
name|e
argument_list|)
expr_stmt|;
comment|/* to user */
name|define
argument_list|(
literal|'z'
argument_list|,
name|to
operator|->
name|q_home
argument_list|,
name|e
argument_list|)
expr_stmt|;
comment|/* user's home */
comment|/* 		**  Expand out this user into argument list. 		*/
if|if
condition|(
operator|!
name|clever
condition|)
block|{
name|expand
argument_list|(
operator|*
name|mvp
argument_list|,
name|buf
argument_list|,
operator|&
name|buf
index|[
sizeof|sizeof
name|buf
operator|-
literal|1
index|]
argument_list|,
name|e
argument_list|)
expr_stmt|;
operator|*
name|pvp
operator|++
operator|=
name|newstr
argument_list|(
name|buf
argument_list|)
expr_stmt|;
if|if
condition|(
name|pvp
operator|>=
operator|&
name|pv
index|[
name|MAXPV
operator|-
literal|2
index|]
condition|)
block|{
comment|/* allow some space for trailing parms */
break|break;
block|}
block|}
block|}
comment|/* see if any addresses still exist */
if|if
condition|(
name|tobuf
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
block|{
name|define
argument_list|(
literal|'g'
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|define
argument_list|(
literal|'<'
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|,
name|e
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* print out messages as full list */
name|e
operator|->
name|e_to
operator|=
name|tobuf
operator|+
literal|1
expr_stmt|;
comment|/* 	**  Fill out any parameters after the $u parameter. 	*/
while|while
condition|(
operator|!
name|clever
operator|&&
operator|*
operator|++
name|mvp
operator|!=
name|NULL
condition|)
block|{
name|expand
argument_list|(
operator|*
name|mvp
argument_list|,
name|buf
argument_list|,
operator|&
name|buf
index|[
sizeof|sizeof
name|buf
operator|-
literal|1
index|]
argument_list|,
name|e
argument_list|)
expr_stmt|;
operator|*
name|pvp
operator|++
operator|=
name|newstr
argument_list|(
name|buf
argument_list|)
expr_stmt|;
if|if
condition|(
name|pvp
operator|>=
operator|&
name|pv
index|[
name|MAXPV
index|]
condition|)
name|syserr
argument_list|(
literal|"deliver: pv overflow after $u for %s"
argument_list|,
name|pv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
operator|*
name|pvp
operator|++
operator|=
name|NULL
expr_stmt|;
comment|/* 	**  Call the mailer. 	**	The argument vector gets built, pipes 	**	are created as necessary, and we fork& exec as 	**	appropriate. 	**	If we are running SMTP, we just need to clean up. 	*/
if|if
condition|(
name|ctladdr
operator|==
name|NULL
condition|)
name|ctladdr
operator|=
operator|&
name|e
operator|->
name|e_from
expr_stmt|;
ifdef|#
directive|ifdef
name|NAMED_BIND
if|if
condition|(
name|ConfigLevel
operator|<
literal|2
condition|)
name|_res
operator|.
name|options
operator|&=
operator|~
operator|(
name|RES_DEFNAMES
operator||
name|RES_DNSRCH
operator|)
expr_stmt|;
comment|/* XXX */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SMTP
if|if
condition|(
name|clever
condition|)
block|{
name|rcode
operator|=
name|EX_OK
expr_stmt|;
ifdef|#
directive|ifdef
name|NAMED_BIND
if|if
condition|(
name|host
index|[
literal|0
index|]
operator|&&
name|host
index|[
literal|0
index|]
operator|!=
literal|'['
condition|)
block|{
name|expand
argument_list|(
literal|"\001j"
argument_list|,
name|buf
argument_list|,
operator|&
name|buf
index|[
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
operator|-
literal|1
index|]
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|Nmx
operator|=
name|getmxrr
argument_list|(
name|host
argument_list|,
name|MxHosts
argument_list|,
name|buf
argument_list|,
operator|&
name|rcode
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
name|Nmx
operator|=
literal|1
expr_stmt|;
name|MxHosts
index|[
literal|0
index|]
operator|=
name|host
expr_stmt|;
block|}
if|if
condition|(
name|Nmx
operator|>=
literal|0
condition|)
block|{
name|message
argument_list|(
name|Arpa_Info
argument_list|,
literal|"Connecting to %s (%s)..."
argument_list|,
name|MxHosts
index|[
literal|0
index|]
argument_list|,
name|m
operator|->
name|m_name
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|rcode
operator|=
name|smtpinit
argument_list|(
name|m
argument_list|,
name|pv
argument_list|)
operator|)
operator|==
name|EX_OK
condition|)
block|{
specifier|register
name|char
modifier|*
name|t
init|=
name|tobuf
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
comment|/* send the recipient list */
name|tobuf
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|to
operator|=
name|tochain
init|;
name|to
condition|;
name|to
operator|=
name|to
operator|->
name|q_tchain
control|)
block|{
name|e
operator|->
name|e_to
operator|=
name|to
operator|->
name|q_paddr
expr_stmt|;
if|if
condition|(
operator|(
name|i
operator|=
name|smtprcpt
argument_list|(
name|to
argument_list|,
name|m
argument_list|)
operator|)
operator|!=
name|EX_OK
condition|)
block|{
name|markfailure
argument_list|(
name|e
argument_list|,
name|to
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|giveresponse
argument_list|(
name|i
argument_list|,
name|m
argument_list|,
name|e
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|*
name|t
operator|++
operator|=
literal|','
expr_stmt|;
for|for
control|(
name|p
operator|=
name|to
operator|->
name|q_paddr
init|;
operator|*
name|p
condition|;
operator|*
name|t
operator|++
operator|=
operator|*
name|p
operator|++
control|)
empty_stmt|;
block|}
block|}
comment|/* now send the data */
if|if
condition|(
name|tobuf
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
name|e
operator|->
name|e_to
operator|=
name|NULL
expr_stmt|;
else|else
block|{
name|e
operator|->
name|e_to
operator|=
name|tobuf
operator|+
literal|1
expr_stmt|;
name|rcode
operator|=
name|smtpdata
argument_list|(
name|m
argument_list|,
name|e
argument_list|)
expr_stmt|;
block|}
comment|/* now close the connection */
name|smtpquit
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
endif|#
directive|endif
comment|/* SMTP */
block|{
specifier|static
name|int
name|sendoff
parameter_list|()
function_decl|;
name|message
argument_list|(
name|Arpa_Info
argument_list|,
literal|"Connecting to %s (%s)..."
argument_list|,
name|host
argument_list|,
name|m
operator|->
name|m_name
argument_list|)
expr_stmt|;
name|rcode
operator|=
name|sendoff
argument_list|(
name|e
argument_list|,
name|m
argument_list|,
name|pv
argument_list|,
name|ctladdr
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|NAMED_BIND
if|if
condition|(
name|ConfigLevel
operator|<
literal|2
condition|)
name|_res
operator|.
name|options
operator||=
name|RES_DEFNAMES
operator||
name|RES_DNSRCH
expr_stmt|;
comment|/* XXX */
endif|#
directive|endif
comment|/* 	**  Do final status disposal. 	**	We check for something in tobuf for the SMTP case. 	**	If we got a temporary failure, arrange to queue the 	**		addressees. 	*/
if|if
condition|(
name|tobuf
index|[
literal|0
index|]
operator|!=
literal|'\0'
condition|)
name|giveresponse
argument_list|(
name|rcode
argument_list|,
name|m
argument_list|,
name|e
argument_list|)
expr_stmt|;
for|for
control|(
name|to
operator|=
name|tochain
init|;
name|to
operator|!=
name|NULL
condition|;
name|to
operator|=
name|to
operator|->
name|q_tchain
control|)
if|if
condition|(
name|rcode
operator|!=
name|EX_OK
condition|)
name|markfailure
argument_list|(
name|e
argument_list|,
name|to
argument_list|,
name|rcode
argument_list|)
expr_stmt|;
else|else
name|to
operator|->
name|q_flags
operator||=
name|QSENT
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
name|define
argument_list|(
literal|'g'
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|define
argument_list|(
literal|'<'
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|,
name|e
argument_list|)
expr_stmt|;
return|return
operator|(
name|rcode
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  MARKFAILURE -- mark a failure on a specific address. ** **	Parameters: **		e -- the envelope we are sending. **		q -- the address to mark. **		rcode -- the code signifying the particular failure. ** **	Returns: **		none. ** **	Side Effects: **		marks the address (and possibly the envelope) with the **			failure so that an error will be returned or **			the message will be queued, as appropriate. */
end_comment

begin_expr_stmt
name|markfailure
argument_list|(
name|e
argument_list|,
name|q
argument_list|,
name|rcode
argument_list|)
specifier|register
name|ENVELOPE
operator|*
name|e
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|ADDRESS
modifier|*
name|q
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rcode
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|rcode
operator|==
name|EX_OK
condition|)
return|return;
elseif|else
if|if
condition|(
name|rcode
operator|!=
name|EX_TEMPFAIL
operator|&&
name|rcode
operator|!=
name|EX_IOERR
operator|&&
name|rcode
operator|!=
name|EX_OSERR
condition|)
name|q
operator|->
name|q_flags
operator||=
name|QBADADDR
expr_stmt|;
elseif|else
if|if
condition|(
name|curtime
argument_list|()
operator|>
name|e
operator|->
name|e_ctime
operator|+
name|TimeOut
condition|)
block|{
specifier|extern
name|char
modifier|*
name|pintvl
parameter_list|()
function_decl|;
name|char
name|buf
index|[
name|MAXLINE
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|bitset
argument_list|(
name|EF_TIMEOUT
argument_list|,
name|e
operator|->
name|e_flags
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"Cannot send message for %s"
argument_list|,
name|pintvl
argument_list|(
name|TimeOut
argument_list|,
name|FALSE
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|e_message
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|e
operator|->
name|e_message
argument_list|)
expr_stmt|;
name|e
operator|->
name|e_message
operator|=
name|newstr
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|message
argument_list|(
name|Arpa_Info
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
name|q
operator|->
name|q_flags
operator||=
name|QBADADDR
expr_stmt|;
name|e
operator|->
name|e_flags
operator||=
name|EF_TIMEOUT
expr_stmt|;
block|}
else|else
name|q
operator|->
name|q_flags
operator||=
name|QQUEUEUP
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  DOFORK -- do a fork, retrying a couple of times on failure. ** **	This MUST be a macro, since after a vfork we are running **	two processes on the same stack!!! ** **	Parameters: **		none. ** **	Returns: **		From a macro???  You've got to be kidding! ** **	Side Effects: **		Modifies the ==> LOCAL<== variable 'pid', leaving: **			pid of child in parent, zero in child. **			-1 on unrecoverable error. ** **	Notes: **		I'm awfully sorry this looks so awful.  That's **		vfork for you..... */
end_comment

begin_define
define|#
directive|define
name|NFORKTRIES
value|5
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VMUNIX
end_ifdef

begin_define
define|#
directive|define
name|XFORK
value|vfork
end_define

begin_else
else|#
directive|else
else|VMUNIX
end_else

begin_define
define|#
directive|define
name|XFORK
value|fork
end_define

begin_endif
endif|#
directive|endif
endif|VMUNIX
end_endif

begin_define
define|#
directive|define
name|DOFORK
parameter_list|(
name|fORKfN
parameter_list|)
define|\
value|{\ 	register int i;\ \ 	for (i = NFORKTRIES; --i>= 0; )\ 	{\ 		pid = fORKfN();\ 		if (pid>= 0)\ 			break;\ 		if (i> 0)\ 			sleep((unsigned) NFORKTRIES - i);\ 	}\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* **  DOFORK -- simple fork interface to DOFORK. ** **	Parameters: **		none. ** **	Returns: **		pid of child in parent. **		zero in child. **		-1 on error. ** **	Side Effects: **		returns twice, once in parent and once in child. */
end_comment

begin_macro
name|dofork
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|pid
decl_stmt|;
name|DOFORK
argument_list|(
name|fork
argument_list|)
expr_stmt|;
return|return
operator|(
name|pid
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  SENDOFF -- send off call to mailer& collect response. ** **	Parameters: **		e -- the envelope to mail. **		m -- mailer descriptor. **		pvp -- parameter vector to send to it. **		ctladdr -- an address pointer controlling the **			user/groupid etc. of the mailer. ** **	Returns: **		exit status of mailer. ** **	Side Effects: **		none. */
end_comment

begin_expr_stmt
specifier|static
name|sendoff
argument_list|(
name|e
argument_list|,
name|m
argument_list|,
name|pvp
argument_list|,
name|ctladdr
argument_list|)
specifier|register
name|ENVELOPE
operator|*
name|e
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|MAILER
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|pvp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDRESS
modifier|*
name|ctladdr
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|auto
name|FILE
modifier|*
name|mfile
decl_stmt|;
specifier|auto
name|FILE
modifier|*
name|rfile
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
name|int
name|pid
decl_stmt|;
comment|/* 	**  Create connection to mailer. 	*/
name|pid
operator|=
name|openmailer
argument_list|(
name|m
argument_list|,
name|pvp
argument_list|,
name|ctladdr
argument_list|,
name|FALSE
argument_list|,
operator|&
name|mfile
argument_list|,
operator|&
name|rfile
argument_list|)
expr_stmt|;
if|if
condition|(
name|pid
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* 	**  Format and send message. 	*/
name|putfromline
argument_list|(
name|mfile
argument_list|,
name|m
argument_list|)
expr_stmt|;
call|(
modifier|*
name|e
operator|->
name|e_puthdr
call|)
argument_list|(
name|mfile
argument_list|,
name|m
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|putline
argument_list|(
literal|"\n"
argument_list|,
name|mfile
argument_list|,
name|m
argument_list|)
expr_stmt|;
call|(
modifier|*
name|e
operator|->
name|e_putbody
call|)
argument_list|(
name|mfile
argument_list|,
name|m
argument_list|,
name|e
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|mfile
argument_list|)
expr_stmt|;
if|if
condition|(
name|rfile
operator|!=
name|NULL
condition|)
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|rfile
argument_list|)
expr_stmt|;
name|i
operator|=
name|endmailer
argument_list|(
name|pid
argument_list|,
name|pvp
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* arrange a return receipt if requested */
if|if
condition|(
name|e
operator|->
name|e_receiptto
operator|!=
name|NULL
operator|&&
name|bitnset
argument_list|(
name|M_LOCAL
argument_list|,
name|m
operator|->
name|m_flags
argument_list|)
condition|)
block|{
name|e
operator|->
name|e_flags
operator||=
name|EF_SENDRECEIPT
expr_stmt|;
comment|/* do we want to send back more info? */
block|}
return|return
operator|(
name|i
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  ENDMAILER -- Wait for mailer to terminate. ** **	We should never get fatal errors (e.g., segmentation **	violation), so we report those specially.  For other **	errors, we choose a status message (into statmsg), **	and if it represents an error, we print it. ** **	Parameters: **		pid -- pid of mailer. **		name -- name of mailer (for error messages). ** **	Returns: **		exit code of mailer. ** **	Side Effects: **		none. */
end_comment

begin_macro
name|endmailer
argument_list|(
argument|pid
argument_list|,
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|st
decl_stmt|;
comment|/* in the IPC case there is nothing to wait for */
if|if
condition|(
name|pid
operator|==
literal|0
condition|)
return|return
operator|(
name|EX_OK
operator|)
return|;
comment|/* wait for the mailer process to die and collect status */
name|st
operator|=
name|waitfor
argument_list|(
name|pid
argument_list|)
expr_stmt|;
if|if
condition|(
name|st
operator|==
operator|-
literal|1
condition|)
block|{
name|syserr
argument_list|(
literal|"endmailer %s: wait"
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return
operator|(
name|EX_SOFTWARE
operator|)
return|;
block|}
comment|/* see if it died a horrid death */
if|if
condition|(
operator|(
name|st
operator|&
literal|0377
operator|)
operator|!=
literal|0
condition|)
block|{
name|syserr
argument_list|(
literal|"mailer %s died with signal %o"
argument_list|,
name|name
argument_list|,
name|st
argument_list|)
expr_stmt|;
name|ExitStat
operator|=
name|EX_TEMPFAIL
expr_stmt|;
return|return
operator|(
name|EX_TEMPFAIL
operator|)
return|;
block|}
comment|/* normal death -- return status */
name|st
operator|=
operator|(
name|st
operator|>>
literal|8
operator|)
operator|&
literal|0377
expr_stmt|;
return|return
operator|(
name|st
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  OPENMAILER -- open connection to mailer. ** **	Parameters: **		m -- mailer descriptor. **		pvp -- parameter vector to pass to mailer. **		ctladdr -- controlling address for user. **		clever -- create a full duplex connection. **		pmfile -- pointer to mfile (to mailer) connection. **		prfile -- pointer to rfile (from mailer) connection. ** **	Returns: **		pid of mailer (> 0 ). **		-1 on error. **		zero on an IPC connection. ** **	Side Effects: **		creates a mailer in a subprocess. */
end_comment

begin_macro
name|openmailer
argument_list|(
argument|m
argument_list|,
argument|pvp
argument_list|,
argument|ctladdr
argument_list|,
argument|clever
argument_list|,
argument|pmfile
argument_list|,
argument|prfile
argument_list|)
end_macro

begin_decl_stmt
name|MAILER
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|pvp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDRESS
modifier|*
name|ctladdr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|clever
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
modifier|*
name|pmfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
modifier|*
name|prfile
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|pid
decl_stmt|;
name|int
name|mpvect
index|[
literal|2
index|]
decl_stmt|;
name|int
name|rpvect
index|[
literal|2
index|]
decl_stmt|;
name|FILE
modifier|*
name|mfile
init|=
name|NULL
decl_stmt|;
name|FILE
modifier|*
name|rfile
init|=
name|NULL
decl_stmt|;
specifier|extern
name|FILE
modifier|*
name|fdopen
parameter_list|()
function_decl|;
if|if
condition|(
name|tTd
argument_list|(
literal|11
argument_list|,
literal|1
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"openmailer:"
argument_list|)
expr_stmt|;
name|printav
argument_list|(
name|pvp
argument_list|)
expr_stmt|;
block|}
name|errno
operator|=
literal|0
expr_stmt|;
name|CurHostName
operator|=
name|m
operator|->
name|m_mailer
expr_stmt|;
comment|/* 	**  Deal with the special case of mail handled through an IPC 	**  connection. 	**	In this case we don't actually fork.  We must be 	**	running SMTP for this to work.  We will return a 	**	zero pid to indicate that we are running IPC. 	**  We also handle a debug version that just talks to stdin/out. 	*/
comment|/* check for Local Person Communication -- not for mortals!!! */
if|if
condition|(
name|strcmp
argument_list|(
name|m
operator|->
name|m_mailer
argument_list|,
literal|"[LPC]"
argument_list|)
operator|==
literal|0
condition|)
block|{
operator|*
name|pmfile
operator|=
name|stdout
expr_stmt|;
operator|*
name|prfile
operator|=
name|stdin
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|strcmp
argument_list|(
name|m
operator|->
name|m_mailer
argument_list|,
literal|"[IPC]"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|m
operator|->
name|m_mailer
argument_list|,
literal|"[TCP]"
argument_list|)
operator|==
literal|0
condition|)
block|{
ifdef|#
directive|ifdef
name|HOSTINFO
specifier|register
name|STAB
modifier|*
name|st
decl_stmt|;
specifier|extern
name|STAB
modifier|*
name|stab
parameter_list|()
function_decl|;
endif|#
directive|endif
endif|HOSTINFO
ifdef|#
directive|ifdef
name|DAEMON
specifier|register
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
specifier|register
name|u_short
name|port
decl_stmt|;
name|CurHostName
operator|=
name|pvp
index|[
literal|1
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|clever
condition|)
name|syserr
argument_list|(
literal|"non-clever IPC"
argument_list|)
expr_stmt|;
if|if
condition|(
name|pvp
index|[
literal|2
index|]
operator|!=
name|NULL
condition|)
name|port
operator|=
name|atoi
argument_list|(
name|pvp
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
else|else
name|port
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|Nmx
condition|;
name|j
operator|++
control|)
block|{
name|CurHostName
operator|=
name|MxHosts
index|[
name|j
index|]
expr_stmt|;
ifdef|#
directive|ifdef
name|HOSTINFO
comment|/* see if we already know that this host is fried */
name|st
operator|=
name|stab
argument_list|(
name|MxHosts
index|[
name|j
index|]
argument_list|,
name|ST_HOST
argument_list|,
name|ST_FIND
argument_list|)
expr_stmt|;
if|if
condition|(
name|st
operator|==
name|NULL
operator|||
name|st
operator|->
name|s_host
operator|.
name|ho_exitstat
operator|==
name|EX_OK
condition|)
block|{
name|message
argument_list|(
name|Arpa_Info
argument_list|,
literal|"Connecting to %s (%s)..."
argument_list|,
name|MxHosts
index|[
name|j
index|]
argument_list|,
name|m
operator|->
name|m_name
argument_list|)
expr_stmt|;
name|i
operator|=
name|makeconnection
argument_list|(
name|MxHosts
index|[
name|j
index|]
argument_list|,
name|port
argument_list|,
name|pmfile
argument_list|,
name|prfile
argument_list|,
name|bitnset
argument_list|(
name|M_SECURE_PORT
argument_list|,
name|m
operator|->
name|m_flags
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|i
operator|=
name|st
operator|->
name|s_host
operator|.
name|ho_exitstat
expr_stmt|;
name|errno
operator|=
name|st
operator|->
name|s_host
operator|.
name|ho_errno
expr_stmt|;
block|}
else|#
directive|else
else|HOSTINFO
name|message
argument_list|(
name|Arpa_Info
argument_list|,
literal|"Connecting to %s (%s)..."
argument_list|,
name|MxHosts
index|[
name|j
index|]
argument_list|,
name|m
operator|->
name|m_name
argument_list|)
expr_stmt|;
name|i
operator|=
name|makeconnection
argument_list|(
argument|MxHosts[j]
argument_list|,
argument|port
argument_list|,
argument|pmfile
argument_list|,
argument|prfile
argument_list|,
argument|bitnset(M_SECURE_PORT, m->m_flags);
endif|#
directive|endif
endif|HOSTINFO
argument|if (i != EX_OK) 			{
ifdef|#
directive|ifdef
name|HOSTINFO
comment|/* enter status of this host */
argument|if (st == NULL) 					st = stab(MxHosts[j], ST_HOST, ST_ENTER); 				st->s_host.ho_exitstat = i; 				st->s_host.ho_errno = errno;
endif|#
directive|endif
endif|HOSTINFO
argument|ExitStat = i; 				continue; 			} 			else 				return (
literal|0
argument|); 		} 		return (-
literal|1
argument|);
else|#
directive|else
else|DAEMON
argument|syserr(
literal|"openmailer: no IPC"
argument|); 		return (-
literal|1
argument|);
endif|#
directive|endif
endif|DAEMON
argument|}
comment|/* create a pipe to shove the mail through */
argument|if (pipe(mpvect)<
literal|0
argument|) 	{ 		syserr(
literal|"openmailer: pipe (to mailer)"
argument|); 		return (-
literal|1
argument|); 	}
ifdef|#
directive|ifdef
name|SMTP
comment|/* if this mailer speaks smtp, create a return pipe */
argument|if (clever&& pipe(rpvect)<
literal|0
argument|) 	{ 		syserr(
literal|"openmailer: pipe (from mailer)"
argument|); 		(void) close(mpvect[
literal|0
argument|]); 		(void) close(mpvect[
literal|1
argument|]); 		return (-
literal|1
argument|); 	}
endif|#
directive|endif
endif|SMTP
comment|/* 	**  Actually fork the mailer process. 	**	DOFORK is clever about retrying. 	** 	**	Dispose of SIGCHLD signal catchers that may be laying 	**	around so that endmail will get it. 	*/
argument|if (CurEnv->e_xfp != NULL) 		(void) fflush(CurEnv->e_xfp);
comment|/* for debugging */
argument|(void) fflush(stdout);
ifdef|#
directive|ifdef
name|SIGCHLD
argument|(void) signal(SIGCHLD, SIG_DFL);
endif|#
directive|endif
endif|SIGCHLD
argument|DOFORK(XFORK);
comment|/* pid is set by DOFORK */
argument|if (pid<
literal|0
argument|) 	{
comment|/* failure */
argument|syserr(
literal|"openmailer: cannot fork"
argument|); 		(void) close(mpvect[
literal|0
argument|]); 		(void) close(mpvect[
literal|1
argument|]);
ifdef|#
directive|ifdef
name|SMTP
argument|if (clever) 		{ 			(void) close(rpvect[
literal|0
argument|]); 			(void) close(rpvect[
literal|1
argument|]); 		}
endif|#
directive|endif
endif|SMTP
argument|return (-
literal|1
argument|); 	} 	else if (pid ==
literal|0
argument|) 	{ 		int i; 		extern int DtableSize;
comment|/* child -- set up input& exec mailer */
comment|/* make diagnostic output be standard output */
argument|(void) signal(SIGINT, SIG_IGN); 		(void) signal(SIGHUP, SIG_IGN); 		(void) signal(SIGTERM, SIG_DFL);
comment|/* arrange to filter standard& diag output of command */
argument|if (clever) 		{ 			(void) close(rpvect[
literal|0
argument|]); 			(void) close(
literal|1
argument|); 			(void) dup(rpvect[
literal|1
argument|]); 			(void) close(rpvect[
literal|1
argument|]); 		} 		else if (OpMode == MD_SMTP || HoldErrs) 		{
comment|/* put mailer output in transcript */
argument|(void) close(
literal|1
argument|); 			(void) dup(fileno(CurEnv->e_xfp)); 		} 		(void) close(
literal|2
argument|); 		(void) dup(
literal|1
argument|);
comment|/* arrange to get standard input */
argument|(void) close(mpvect[
literal|1
argument|]); 		(void) close(
literal|0
argument|); 		if (dup(mpvect[
literal|0
argument|])<
literal|0
argument|) 		{ 			syserr(
literal|"Cannot dup to zero!"
argument|); 			_exit(EX_OSERR); 		} 		(void) close(mpvect[
literal|0
argument|]); 		if (!bitnset(M_RESTR, m->m_flags)) 		{ 			if (ctladdr == NULL || ctladdr->q_uid ==
literal|0
argument|) 			{ 				(void) setgid(DefGid); 				(void) initgroups(DefUser, DefGid); 				(void) setuid(DefUid); 			} 			else 			{ 				(void) setgid(ctladdr->q_gid); 				(void) initgroups(ctladdr->q_ruser? 					ctladdr->q_ruser: ctladdr->q_user, 					ctladdr->q_gid); 				(void) setuid(ctladdr->q_uid); 			} 		}
comment|/* arrange for all the files to be closed */
argument|for (i =
literal|3
argument|; i< DtableSize; i++) { 			register int j; 			if ((j = fcntl(i, F_GETFD,
literal|0
argument|)) != -
literal|1
argument|) 				(void)fcntl(i, F_SETFD, j|
literal|1
argument|); 		}
comment|/* try to execute the mailer */
argument|execve(m->m_mailer, pvp, UserEnviron); 		syserr(
literal|"Cannot exec %s"
argument|, m->m_mailer); 		if (m == LocalMailer) 			_exit(EX_TEMPFAIL); 		switch (errno) 		{ 		  case EIO: 		  case EAGAIN: 		  case ENOMEM:
ifdef|#
directive|ifdef
name|EPROCLIM
argument|case EPROCLIM:
endif|#
directive|endif
argument|_exit(EX_TEMPFAIL); 		} 		_exit(EX_UNAVAILABLE); 	}
comment|/* 	**  Set up return value. 	*/
argument|(void) close(mpvect[
literal|0
argument|]); 	mfile = fdopen(mpvect[
literal|1
argument|],
literal|"w"
argument|); 	if (clever) 	{ 		(void) close(rpvect[
literal|1
argument|]); 		rfile = fdopen(rpvect[
literal|0
argument|],
literal|"r"
argument|); 	} else 		rfile = NULL;  	*pmfile = mfile; 	*prfile = rfile;  	return (pid); }
comment|/* **  GIVERESPONSE -- Interpret an error response from a mailer ** **	Parameters: **		stat -- the status code from the mailer (high byte **			only; core dumps must have been taken care of **			already). **		m -- the mailer descriptor for this mailer. ** **	Returns: **		none. ** **	Side Effects: **		Errors may be incremented. **		ExitStat may be set. */
argument|giveresponse(stat, m, e) 	int stat; 	register MAILER *m; 	ENVELOPE *e; { 	register char *statmsg; 	extern char *SysExMsg[]; 	register int i; 	extern int N_SysEx;
ifdef|#
directive|ifdef
name|NAMED_BIND
argument|extern int h_errno;
endif|#
directive|endif
argument|char buf[MAXLINE];
ifdef|#
directive|ifdef
name|lint
argument|if (m == NULL) 		return;
endif|#
directive|endif
endif|lint
comment|/* 	**  Compute status message from code. 	*/
argument|i = stat - EX__BASE; 	if (stat ==
literal|0
argument|) 		statmsg =
literal|"250 Sent"
argument|; 	else if (i<
literal|0
argument||| i> N_SysEx) 	{ 		(void) sprintf(buf,
literal|"554 unknown mailer error %d"
argument|, stat); 		stat = EX_UNAVAILABLE; 		statmsg = buf; 	} 	else if (stat == EX_TEMPFAIL) 	{ 		(void) strcpy(buf, SysExMsg[i]);
ifdef|#
directive|ifdef
name|NAMED_BIND
argument|if (h_errno == TRY_AGAIN) 		{ 			extern char *errstring();  			statmsg = errstring(h_errno+MAX_ERRNO); 		} 		else
endif|#
directive|endif
argument|{ 			if (errno !=
literal|0
argument|) 			{ 				extern char *errstring();  				statmsg = errstring(errno); 			} 			else 			{
ifdef|#
directive|ifdef
name|SMTP
argument|extern char SmtpError[];  				statmsg = SmtpError;
else|#
directive|else
else|SMTP
argument|statmsg = NULL;
endif|#
directive|endif
endif|SMTP
argument|} 		} 		if (statmsg != NULL&& statmsg[
literal|0
argument|] !=
literal|'\0'
argument|) 		{ 			(void) strcat(buf,
literal|": "
argument|); 			(void) strcat(buf, statmsg); 		} 		statmsg = buf; 	} 	else 	{ 		statmsg = SysExMsg[i]; 	}
comment|/* 	**  Print the message as appropriate 	*/
argument|if (stat == EX_OK || stat == EX_TEMPFAIL) 		message(Arpa_Info,&statmsg[
literal|4
argument|]); 	else 	{ 		Errors++; 		usrerr(statmsg); 	}
comment|/* 	**  Final cleanup. 	**	Log a record of the transaction.  Compute the new 	**	ExitStat -- if we already had an error, stick with 	**	that. 	*/
argument|if (LogLevel> ((stat ==
literal|0
argument||| stat == EX_TEMPFAIL) ?
literal|3
argument|:
literal|2
argument|)) 		logdelivery(&statmsg[
literal|4
argument|]);  	if (stat != EX_TEMPFAIL) 		setstat(stat); 	if (stat != EX_OK) 	{ 		if (e->e_message != NULL) 			free(e->e_message); 		e->e_message = newstr(&statmsg[
literal|4
argument|]); 	} 	errno =
literal|0
argument|;
ifdef|#
directive|ifdef
name|NAMED_BIND
argument|h_errno =
literal|0
argument|;
endif|#
directive|endif
argument|}
comment|/* **  LOGDELIVERY -- log the delivery in the system log ** **	Parameters: **		stat -- the message to print for the status ** **	Returns: **		none ** **	Side Effects: **		none */
argument|logdelivery(stat) 	char *stat; { 	extern char *pintvl();
ifdef|#
directive|ifdef
name|LOG
argument|syslog(LOG_INFO,
literal|"%s: to=%s, delay=%s, stat=%s"
argument|, CurEnv->e_id, 	       CurEnv->e_to, pintvl(curtime() - CurEnv->e_ctime, TRUE), stat);
endif|#
directive|endif
endif|LOG
argument|}
comment|/* **  PUTFROMLINE -- output a UNIX-style from line (or whatever) ** **	then passes the rest of the message through.  If we have **	managed to extract a date already, use that; otherwise, **	use the current date/time. ** **	One of the ugliest hacks seen by human eyes is contained herein: **	UUCP wants those stupid "remote from<host>" lines.  Why oh why **	does a well-meaning programmer such as myself have to deal with **	this kind of antique garbage???? ** **	Parameters: **		fp -- the file to output to. **		m -- the mailer describing this entry. ** **	Returns: **		none ** **	Side Effects: **		outputs some text to fp. */
argument|putfromline(fp, m) 	register FILE *fp; 	register MAILER *m; { 	char *template =
literal|"\001l\n"
argument|; 	char buf[MAXLINE]; 	extern char SentDate[];  	if (bitnset(M_NHDR, m->m_flags)) 		return;
ifdef|#
directive|ifdef
name|UGLYUUCP
argument|if (bitnset(M_UGLYUUCP, m->m_flags)) 	{ 		char *bang; 		char xbuf[MAXLINE];  		expand(
literal|"\001<"
argument|, buf,&buf[sizeof buf -
literal|1
argument|], CurEnv); 		bang = index(buf,
literal|'!'
argument|); 		if (bang == NULL) 			syserr(
literal|"No ! in UUCP! (%s)"
argument|, buf); 		else 		{ 			*bang++ =
literal|'\0'
argument|; 			(void) sprintf(xbuf,
literal|"From %s  \001d remote from %s\n"
argument|, bang, buf); 			template = xbuf; 		} 	}
endif|#
directive|endif
endif|UGLYUUCP
argument|expand(template, buf,&buf[sizeof buf -
literal|1
argument|], CurEnv); 	putline(buf, fp, m); }
comment|/* **  PUTBODY -- put the body of a message. ** **	Parameters: **		fp -- file to output onto. **		m -- a mailer descriptor to control output format. **		e -- the envelope to put out. ** **	Returns: **		none. ** **	Side Effects: **		The message is written onto fp. */
argument|putbody(fp, m, e) 	FILE *fp; 	MAILER *m; 	register ENVELOPE *e; { 	char buf[MAXLINE];
comment|/* 	**  Output the body of the message 	*/
argument|if (e->e_dfp == NULL) 	{ 		if (e->e_df != NULL) 		{ 			e->e_dfp = fopen(e->e_df,
literal|"r"
argument|); 			if (e->e_dfp == NULL) 				syserr(
literal|"putbody: Cannot open %s for %s from %s"
argument|, 				e->e_df, e->e_to, e->e_from); 		} 		else 			putline(
literal|"<<< No Message Collected>>>"
argument|, fp, m); 	} 	if (e->e_dfp != NULL) 	{ 		rewind(e->e_dfp); 		while (!ferror(fp)&& fgets(buf, sizeof buf, e->e_dfp) != NULL) 		{ 			if (buf[
literal|0
argument|] ==
literal|'F'
argument|&& bitnset(M_ESCFROM, m->m_flags)&& 			    strncmp(buf,
literal|"From "
argument|,
literal|5
argument|) ==
literal|0
argument|) 				(void) putc(
literal|'>'
argument|, fp); 			putline(buf, fp, m); 		}  		if (ferror(e->e_dfp)) 		{ 			syserr(
literal|"putbody: read error"
argument|); 			ExitStat = EX_IOERR; 		} 	}  	(void) fflush(fp); 	if (ferror(fp)&& errno != EPIPE) 	{ 		syserr(
literal|"putbody: write error"
argument|); 		ExitStat = EX_IOERR; 	} 	errno =
literal|0
argument|; }
comment|/* **  MAILFILE -- Send a message to a file. ** **	If the file has the setuid/setgid bits set, but NO execute **	bits, sendmail will try to become the owner of that file **	rather than the real user.  Obviously, this only works if **	sendmail runs as root. ** **	This could be done as a subordinate mailer, except that it **	is used implicitly to save messages in ~/dead.letter.  We **	view this as being sufficiently important as to include it **	here.  For example, if the system is dying, we shouldn't have **	to create another process plus some pipes to save the message. ** **	Parameters: **		filename -- the name of the file to send to. **		ctladdr -- the controlling address header -- includes **			the userid/groupid to be when sending. ** **	Returns: **		The exit code associated with the operation. ** **	Side Effects: **		none. */
argument|mailfile(filename, ctladdr) 	char *filename; 	ADDRESS *ctladdr; { 	register FILE *f; 	register int pid; 	ENVELOPE *e = CurEnv;
comment|/* 	**  Fork so we can change permissions here. 	**	Note that we MUST use fork, not vfork, because of 	**	the complications of calling subroutines, etc. 	*/
argument|DOFORK(fork);  	if (pid<
literal|0
argument|) 		return (EX_OSERR); 	else if (pid ==
literal|0
argument|) 	{
comment|/* child -- actually write to file */
argument|struct stat stb;  		(void) signal(SIGINT, SIG_DFL); 		(void) signal(SIGHUP, SIG_DFL); 		(void) signal(SIGTERM, SIG_DFL); 		(void) umask(OldUmask); 		if (stat(filename,&stb)<
literal|0
argument|) 		{ 			errno =
literal|0
argument|; 			stb.st_mode =
literal|0666
argument|; 		} 		if (bitset(
literal|0111
argument|, stb.st_mode)) 			exit(EX_CANTCREAT); 		if (ctladdr == NULL) 			ctladdr =&e->e_from;
comment|/* we have to open the dfile BEFORE setuid */
argument|if (e->e_dfp == NULL&&  e->e_df != NULL) 		{ 			e->e_dfp = fopen(e->e_df,
literal|"r"
argument|); 			if (e->e_dfp == NULL) { 				syserr(
literal|"mailfile: Cannot open %s for %s from %s"
argument|, 				e->e_df, e->e_to, e->e_from); 			} 		}  		if (!bitset(S_ISGID, stb.st_mode) || setgid(stb.st_gid)<
literal|0
argument|) 		{ 			if (ctladdr->q_uid ==
literal|0
argument|) { 				(void) setgid(DefGid); 				(void) initgroups(DefUser, DefGid); 			} else { 				(void) setgid(ctladdr->q_gid); 				(void) initgroups(ctladdr->q_ruser? 					ctladdr->q_ruser: ctladdr->q_user, 					ctladdr->q_gid); 			} 		} 		if (!bitset(S_ISUID, stb.st_mode) || setuid(stb.st_uid)<
literal|0
argument|) 		{ 			if (ctladdr->q_uid ==
literal|0
argument|) 				(void) setuid(DefUid); 			else 				(void) setuid(ctladdr->q_uid); 		} 		f = dfopen(filename,
literal|"a"
argument|); 		if (f == NULL) 			exit(EX_CANTCREAT);  		putfromline(f, ProgMailer); 		(*CurEnv->e_puthdr)(f, ProgMailer, CurEnv); 		putline(
literal|"\n"
argument|, f, ProgMailer); 		(*CurEnv->e_putbody)(f, ProgMailer, CurEnv); 		putline(
literal|"\n"
argument|, f, ProgMailer); 		(void) fclose(f); 		(void) fflush(stdout);
comment|/* reset ISUID& ISGID bits for paranoid systems */
argument|(void) chmod(filename, (int) stb.st_mode); 		exit(EX_OK);
comment|/*NOTREACHED*/
argument|} 	else 	{
comment|/* parent -- wait for exit status */
argument|int st;  		st = waitfor(pid); 		if ((st&
literal|0377
argument|) !=
literal|0
argument|) 			return (EX_UNAVAILABLE); 		else 			return ((st>>
literal|8
argument|)&
literal|0377
argument|);
comment|/*NOTREACHED*/
argument|} }
comment|/* **  SENDALL -- actually send all the messages. ** **	Parameters: **		e -- the envelope to send. **		mode -- the delivery mode to use.  If SM_DEFAULT, use **			the current SendMode. ** **	Returns: **		none. ** **	Side Effects: **		Scans the send lists and sends everything it finds. **		Delivers any appropriate error messages. **		If we are running in a non-interactive mode, takes the **			appropriate action. */
argument|sendall(e, mode) 	ENVELOPE *e; 	char mode; { 	register ADDRESS *q; 	bool oldverbose; 	int pid; 	int nsent;
ifdef|#
directive|ifdef
name|LOCKF
argument|struct flock lfd;
endif|#
directive|endif
comment|/* determine actual delivery mode */
argument|if (mode == SM_DEFAULT) 	{ 		extern bool shouldqueue();  		if (shouldqueue(e->e_msgpriority)) 			mode = SM_QUEUE; 		else 			mode = SendMode; 	}  	if (tTd(
literal|13
argument|,
literal|1
argument|)) 	{ 		printf(
literal|"\nSENDALL: mode %c, sendqueue:\n"
argument|, mode); 		printaddr(e->e_sendqueue, TRUE); 	}
comment|/* 	**  Do any preprocessing necessary for the mode we are running. 	**	Check to make sure the hop count is reasonable. 	**	Delete sends to the sender in mailing lists. 	*/
argument|CurEnv = e;  	if (e->e_hopcount> MaxHopCount) 	{ 		errno =
literal|0
argument|; 		syserr(
literal|"sendall: too many hops %d (%d max): from %s, to %s"
argument|, 			e->e_hopcount, MaxHopCount, e->e_from, e->e_to); 		return; 	}  	if (!MeToo) 	{ 		extern ADDRESS *recipient();  		e->e_from.q_flags |= QDONTSEND; 		(void) recipient(&e->e_from,&e->e_sendqueue); 	}
ifdef|#
directive|ifdef
name|QUEUE
argument|if ((mode == SM_QUEUE || mode == SM_FORK || 	     (mode != SM_VERIFY&& SuperSafe))&& 	    !bitset(EF_INQUEUE, e->e_flags)) 		queueup(e, TRUE, mode == SM_QUEUE);
endif|#
directive|endif
endif|QUEUE
argument|oldverbose = Verbose; 	switch (mode) 	{ 	  case SM_VERIFY: 		Verbose = TRUE; 		break;  	  case SM_QUEUE:   queueonly: 		e->e_flags |= EF_INQUEUE|EF_KEEPQUEUE; 		return;  	  case SM_FORK: 		if (e->e_xfp != NULL) 			(void) fflush(e->e_xfp);
ifdef|#
directive|ifdef
name|LOCKF
comment|/* 		**  Since lockf has the interesting semantic that the 		**  lock is lost when we fork, we have to risk losing 		**  the lock here by closing before the fork, and then 		**  trying to get it back in the child. 		*/
argument|if (e->e_lockfp != NULL) 		{ 			(void) fclose(e->e_lockfp); 			e->e_lockfp = NULL; 		}
endif|#
directive|endif
comment|/* LOCKF */
argument|pid = fork(); 		if (pid<
literal|0
argument|) 		{ 			goto queueonly; 		} 		else if (pid>
literal|0
argument|) 		{
comment|/* be sure we leave the temp files to our child */
argument|e->e_id = e->e_df = NULL;
ifndef|#
directive|ifndef
name|LOCKF
argument|if (e->e_lockfp != NULL) 				(void) fclose(e->e_lockfp);
endif|#
directive|endif
argument|return; 		}
comment|/* double fork to avoid zombies */
argument|if (fork()>
literal|0
argument|) 			exit(EX_OK);
comment|/* be sure we are immune from the terminal */
argument|disconnect(FALSE);
ifdef|#
directive|ifdef
name|LOCKF
comment|/* 		**  Now try to get our lock back. 		*/
argument|lfd.l_type = F_WRLCK; 		lfd.l_whence = lfd.l_start = lfd.l_len =
literal|0
argument|; 		e->e_lockfp = fopen(queuename(e,
literal|'q'
argument|),
literal|"r+"
argument|); 		if (e->e_lockfp == NULL || 		    fcntl(fileno(e->e_lockfp), F_SETLK,&lfd)<
literal|0
argument|) 		{
comment|/* oops....  lost it */
ifdef|#
directive|ifdef
name|LOG
argument|if (LogLevel>
literal|5
argument|) 				syslog(LOG_NOTICE,
literal|"%s: lost lock: %m"
argument|, 					CurEnv->e_id);
endif|#
directive|endif
comment|/* LOG */
argument|exit(EX_OK); 		}
endif|#
directive|endif
comment|/* LOCKF */
argument|break; 	}
comment|/* 	**  Run through the list and send everything. 	*/
argument|nsent =
literal|0
argument|; 	for (q = e->e_sendqueue; q != NULL; q = q->q_next) 	{ 		if (mode == SM_VERIFY) 		{ 			e->e_to = q->q_paddr; 			if (!bitset(QDONTSEND|QBADADDR, q->q_flags)) 				message(Arpa_Info,
literal|"deliverable"
argument|); 		} 		else if (!bitset(QDONTSEND, q->q_flags)) 		{
ifdef|#
directive|ifdef
name|QUEUE
comment|/* 			**  Checkpoint the send list every few addresses 			*/
argument|if (nsent>= CheckpointInterval) 			{ 				queueup(e, TRUE, FALSE); 				nsent =
literal|0
argument|; 			}
endif|#
directive|endif
comment|/* QUEUE */
argument|if (deliver(e, q) == EX_OK) 				nsent++; 		} 	} 	Verbose = oldverbose;
comment|/* 	**  Now run through and check for errors. 	*/
argument|if (mode == SM_VERIFY) 		return;  	for (q = e->e_sendqueue; q != NULL; q = q->q_next) 	{ 		register ADDRESS *qq;  		if (tTd(
literal|13
argument|,
literal|3
argument|)) 		{ 			printf(
literal|"Checking "
argument|); 			printaddr(q, FALSE); 		}
comment|/* only send errors if the message failed */
argument|if (!bitset(QBADADDR, q->q_flags)) 			continue;
comment|/* we have an address that failed -- find the parent */
argument|for (qq = q; qq != NULL; qq = qq->q_alias) 		{ 			char obuf[MAXNAME +
literal|6
argument|]; 			extern char *aliaslookup();
comment|/* we can only have owners for local addresses */
argument|if (!bitnset(M_LOCAL, qq->q_mailer->m_flags)) 				continue;
comment|/* see if the owner list exists */
argument|(void) strcpy(obuf,
literal|"owner-"
argument|); 			if (strncmp(qq->q_user,
literal|"owner-"
argument|,
literal|6
argument|) ==
literal|0
argument|) 				(void) strcat(obuf,
literal|"owner"
argument|); 			else 				(void) strcat(obuf, qq->q_user); 			makelower(obuf); 			if (aliaslookup(obuf) == NULL) 				continue;  			if (tTd(
literal|13
argument|,
literal|4
argument|)) 				printf(
literal|"Errors to %s\n"
argument|, obuf);
comment|/* owner list exists -- add it to the error queue */
argument|sendtolist(obuf, (ADDRESS *) NULL,&e->e_errorqueue); 			ErrorMode = EM_MAIL; 			break; 		}
comment|/* if we did not find an owner, send to the sender */
argument|if (qq == NULL&& bitset(QBADADDR, q->q_flags)) 			sendtolist(e->e_from.q_paddr, qq,&e->e_errorqueue); 	}  	if (mode == SM_FORK) 		finis(); }
end_block

end_unit

