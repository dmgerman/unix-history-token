begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Eric P. Allman  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_include
include|#
directive|include
file|"sendmail.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SMTP
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)usersmtp.c	5.15 (Berkeley) %G% (with SMTP)"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)usersmtp.c	5.15 (Berkeley) %G% (without SMTP)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
file|<sysexits.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SMTP
end_ifdef

begin_comment
comment|/* **  USERSMTP -- run SMTP protocol from the user end. ** **	This protocol is described in RFC821. */
end_comment

begin_define
define|#
directive|define
name|REPLYTYPE
parameter_list|(
name|r
parameter_list|)
value|((r) / 100)
end_define

begin_comment
comment|/* first digit of reply code */
end_comment

begin_define
define|#
directive|define
name|REPLYCLASS
parameter_list|(
name|r
parameter_list|)
value|(((r) / 10) % 10)
end_define

begin_comment
comment|/* second digit of reply code */
end_comment

begin_define
define|#
directive|define
name|SMTPCLOSING
value|421
end_define

begin_comment
comment|/* "Service Shutting Down" */
end_comment

begin_decl_stmt
name|char
name|SmtpMsgBuffer
index|[
name|MAXLINE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for commands */
end_comment

begin_decl_stmt
name|char
name|SmtpReplyBuffer
index|[
name|MAXLINE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for replies */
end_comment

begin_decl_stmt
name|char
name|SmtpError
index|[
name|MAXLINE
index|]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* save failure error messages */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|SmtpOut
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output file */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|SmtpIn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file */
end_comment

begin_decl_stmt
name|int
name|SmtpPid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pid of mailer */
end_comment

begin_comment
comment|/* following represents the state of the SMTP connection */
end_comment

begin_decl_stmt
name|int
name|SmtpState
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* connection state, see below */
end_comment

begin_define
define|#
directive|define
name|SMTP_CLOSED
value|0
end_define

begin_comment
comment|/* connection is closed */
end_comment

begin_define
define|#
directive|define
name|SMTP_OPEN
value|1
end_define

begin_comment
comment|/* connection is open for business */
end_comment

begin_define
define|#
directive|define
name|SMTP_SSD
value|2
end_define

begin_comment
comment|/* service shutting down */
end_comment

begin_escape
end_escape

begin_comment
comment|/* **  SMTPINIT -- initialize SMTP. ** **	Opens the connection and sends the initial protocol. ** **	Parameters: **		m -- mailer to create connection to. **		pvp -- pointer to parameter vector to pass to **			the mailer. ** **	Returns: **		appropriate exit status -- EX_OK on success. **		If not EX_OK, it should close the connection. ** **	Side Effects: **		creates connection and sends initial protocol. */
end_comment

begin_decl_stmt
name|jmp_buf
name|CtxGreeting
decl_stmt|;
end_decl_stmt

begin_macro
name|smtpinit
argument_list|(
argument|m
argument_list|,
argument|pvp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|mailer
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

begin_block
block|{
specifier|register
name|int
name|r
decl_stmt|;
name|EVENT
modifier|*
name|gte
decl_stmt|;
name|char
name|buf
index|[
name|MAXNAME
index|]
decl_stmt|;
extern|extern greettimeout(
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* 	**  Open the connection to the mailer. 	*/
end_comment

begin_if
if|if
condition|(
name|SmtpState
operator|==
name|SMTP_OPEN
condition|)
name|syserr
argument_list|(
literal|"smtpinit: already open"
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|SmtpIn
operator|=
name|SmtpOut
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SmtpState
operator|=
name|SMTP_CLOSED
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SmtpError
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SmtpPhase
operator|=
literal|"user open"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|setproctitle
argument_list|(
literal|"%s %s: %s"
argument_list|,
name|CurEnv
operator|->
name|e_id
argument_list|,
name|pvp
index|[
literal|1
index|]
argument_list|,
name|SmtpPhase
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SmtpPid
operator|=
name|openmailer
argument_list|(
name|m
argument_list|,
name|pvp
argument_list|,
operator|(
name|ADDRESS
operator|*
operator|)
name|NULL
argument_list|,
name|TRUE
argument_list|,
operator|&
name|SmtpOut
argument_list|,
operator|&
name|SmtpIn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|SmtpPid
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|18
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"smtpinit: cannot open %s: stat %d errno %d\n"
argument_list|,
name|pvp
index|[
literal|0
index|]
argument_list|,
name|ExitStat
argument_list|,
name|errno
argument_list|)
expr_stmt|;
if|if
condition|(
name|CurEnv
operator|->
name|e_xfp
operator|!=
name|NULL
condition|)
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|extern
name|char
modifier|*
name|errstring
parameter_list|()
function_decl|;
specifier|extern
name|char
modifier|*
name|statstring
parameter_list|()
function_decl|;
if|if
condition|(
name|errno
operator|==
literal|0
condition|)
block|{
name|p
operator|=
name|statstring
argument_list|(
name|ExitStat
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|CurEnv
operator|->
name|e_xfp
argument_list|,
literal|"%.3s %s.%s... %s\n"
argument_list|,
name|p
argument_list|,
name|pvp
index|[
literal|1
index|]
argument_list|,
name|m
operator|->
name|m_name
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|r
operator|=
name|errno
expr_stmt|;
name|fprintf
argument_list|(
name|CurEnv
operator|->
name|e_xfp
argument_list|,
literal|"421 %s.%s... Deferred: %s\n"
argument_list|,
name|pvp
index|[
literal|1
index|]
argument_list|,
name|m
operator|->
name|m_name
argument_list|,
name|errstring
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|errno
operator|=
name|r
expr_stmt|;
block|}
block|}
return|return
operator|(
name|ExitStat
operator|)
return|;
block|}
end_if

begin_expr_stmt
name|SmtpState
operator|=
name|SMTP_OPEN
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	**  Get the greeting message. 	**	This should appear spontaneously.  Give it five minutes to 	**	happen. 	*/
end_comment

begin_if
if|if
condition|(
name|setjmp
argument_list|(
name|CtxGreeting
argument_list|)
operator|!=
literal|0
condition|)
goto|goto
name|tempfail
goto|;
end_if

begin_expr_stmt
name|gte
operator|=
name|setevent
argument_list|(
operator|(
name|time_t
operator|)
literal|300
argument_list|,
name|greettimeout
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SmtpPhase
operator|=
literal|"greeting wait"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|setproctitle
argument_list|(
literal|"%s %s: %s"
argument_list|,
name|CurEnv
operator|->
name|e_id
argument_list|,
name|CurHostName
argument_list|,
name|SmtpPhase
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|r
operator|=
name|reply
argument_list|(
name|m
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|clrevent
argument_list|(
name|gte
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|r
operator|<
literal|0
operator|||
name|REPLYTYPE
argument_list|(
name|r
argument_list|)
operator|!=
literal|2
condition|)
goto|goto
name|tempfail
goto|;
end_if

begin_comment
comment|/* 	**  Send the HELO command. 	**	My mother taught me to always introduce myself. 	*/
end_comment

begin_expr_stmt
name|smtpmessage
argument_list|(
literal|"HELO %s"
argument_list|,
name|m
argument_list|,
name|MyHostName
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SmtpPhase
operator|=
literal|"HELO wait"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|setproctitle
argument_list|(
literal|"%s %s: %s"
argument_list|,
name|CurEnv
operator|->
name|e_id
argument_list|,
name|CurHostName
argument_list|,
name|SmtpPhase
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|r
operator|=
name|reply
argument_list|(
name|m
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|r
operator|<
literal|0
condition|)
goto|goto
name|tempfail
goto|;
elseif|else
if|if
condition|(
name|REPLYTYPE
argument_list|(
name|r
argument_list|)
operator|==
literal|5
condition|)
goto|goto
name|unavailable
goto|;
elseif|else
if|if
condition|(
name|REPLYTYPE
argument_list|(
name|r
argument_list|)
operator|!=
literal|2
condition|)
goto|goto
name|tempfail
goto|;
end_if

begin_comment
comment|/* 	**  If this is expected to be another sendmail, send some internal 	**  commands. 	*/
end_comment

begin_if
if|if
condition|(
name|bitnset
argument_list|(
name|M_INTERNAL
argument_list|,
name|m
operator|->
name|m_flags
argument_list|)
condition|)
block|{
comment|/* tell it to be verbose */
name|smtpmessage
argument_list|(
literal|"VERB"
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|r
operator|=
name|reply
argument_list|(
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|<
literal|0
condition|)
goto|goto
name|tempfail
goto|;
comment|/* tell it we will be sending one transaction only */
name|smtpmessage
argument_list|(
literal|"ONEX"
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|r
operator|=
name|reply
argument_list|(
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|<
literal|0
condition|)
goto|goto
name|tempfail
goto|;
block|}
end_if

begin_comment
comment|/* 	**  Send the HOPS command. 	**	This is non-standard and may give an "unknown command". 	**		This is not an error. 	**	It can give a "bad hop count" error if the hop 	**		count is exceeded. 	*/
end_comment

begin_comment
comment|/* 	**  Send the MAIL command. 	**	Designates the sender. 	*/
end_comment

begin_expr_stmt
name|expand
argument_list|(
literal|"\001g"
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
name|CurEnv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|CurEnv
operator|->
name|e_from
operator|.
name|q_mailer
operator|==
name|LocalMailer
operator|||
operator|!
name|bitnset
argument_list|(
name|M_FROMPATH
argument_list|,
name|m
operator|->
name|m_flags
argument_list|)
condition|)
block|{
name|smtpmessage
argument_list|(
literal|"MAIL From:<%s>"
argument_list|,
name|m
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|smtpmessage
argument_list|(
literal|"MAIL From:<@%s%c%s>"
argument_list|,
name|m
argument_list|,
name|MyHostName
argument_list|,
name|buf
index|[
literal|0
index|]
operator|==
literal|'@'
condition|?
literal|','
else|:
literal|':'
argument_list|,
name|buf
argument_list|)
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|SmtpPhase
operator|=
literal|"MAIL wait"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|setproctitle
argument_list|(
literal|"%s %s: %s"
argument_list|,
name|CurEnv
operator|->
name|e_id
argument_list|,
name|CurHostName
argument_list|,
name|SmtpPhase
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|r
operator|=
name|reply
argument_list|(
name|m
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|r
operator|<
literal|0
operator|||
name|REPLYTYPE
argument_list|(
name|r
argument_list|)
operator|==
literal|4
condition|)
goto|goto
name|tempfail
goto|;
elseif|else
if|if
condition|(
name|r
operator|==
literal|250
condition|)
return|return
operator|(
name|EX_OK
operator|)
return|;
elseif|else
if|if
condition|(
name|r
operator|==
literal|552
condition|)
goto|goto
name|unavailable
goto|;
end_if

begin_comment
comment|/* protocol error -- close up */
end_comment

begin_expr_stmt
name|smtpquit
argument_list|(
name|m
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|EX_PROTOCOL
operator|)
return|;
end_return

begin_comment
comment|/* signal a temporary failure */
end_comment

begin_label
name|tempfail
label|:
end_label

begin_expr_stmt
name|smtpquit
argument_list|(
name|m
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|EX_TEMPFAIL
operator|)
return|;
end_return

begin_comment
comment|/* signal service unavailable */
end_comment

begin_label
name|unavailable
label|:
end_label

begin_expr_stmt
name|smtpquit
argument_list|(
name|m
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|EX_UNAVAILABLE
operator|)
return|;
end_return

begin_macro
unit|}   static
name|greettimeout
argument_list|()
end_macro

begin_block
block|{
comment|/* timeout reading the greeting message */
name|longjmp
argument_list|(
name|CtxGreeting
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  SMTPRCPT -- designate recipient. ** **	Parameters: **		to -- address of recipient. **		m -- the mailer we are sending to. ** **	Returns: **		exit status corresponding to recipient status. ** **	Side Effects: **		Sends the mail via SMTP. */
end_comment

begin_macro
name|smtprcpt
argument_list|(
argument|to
argument_list|,
argument|m
argument_list|)
end_macro

begin_decl_stmt
name|ADDRESS
modifier|*
name|to
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|MAILER
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|r
decl_stmt|;
specifier|extern
name|char
modifier|*
name|remotename
parameter_list|()
function_decl|;
name|smtpmessage
argument_list|(
literal|"RCPT To:<%s>"
argument_list|,
name|m
argument_list|,
name|remotename
argument_list|(
name|to
operator|->
name|q_user
argument_list|,
name|m
argument_list|,
name|FALSE
argument_list|,
name|TRUE
argument_list|)
argument_list|)
expr_stmt|;
name|SmtpPhase
operator|=
literal|"RCPT wait"
expr_stmt|;
name|setproctitle
argument_list|(
literal|"%s %s: %s"
argument_list|,
name|CurEnv
operator|->
name|e_id
argument_list|,
name|CurHostName
argument_list|,
name|SmtpPhase
argument_list|)
expr_stmt|;
name|r
operator|=
name|reply
argument_list|(
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|<
literal|0
operator|||
name|REPLYTYPE
argument_list|(
name|r
argument_list|)
operator|==
literal|4
condition|)
return|return
operator|(
name|EX_TEMPFAIL
operator|)
return|;
elseif|else
if|if
condition|(
name|REPLYTYPE
argument_list|(
name|r
argument_list|)
operator|==
literal|2
condition|)
return|return
operator|(
name|EX_OK
operator|)
return|;
elseif|else
if|if
condition|(
name|r
operator|==
literal|550
operator|||
name|r
operator|==
literal|551
operator|||
name|r
operator|==
literal|553
condition|)
return|return
operator|(
name|EX_NOUSER
operator|)
return|;
elseif|else
if|if
condition|(
name|r
operator|==
literal|552
operator|||
name|r
operator|==
literal|554
condition|)
return|return
operator|(
name|EX_UNAVAILABLE
operator|)
return|;
return|return
operator|(
name|EX_PROTOCOL
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  SMTPDATA -- send the data and clean up the transaction. ** **	Parameters: **		m -- mailer being sent to. **		e -- the envelope for this message. ** **	Returns: **		exit status corresponding to DATA command. ** **	Side Effects: **		none. */
end_comment

begin_macro
name|smtpdata
argument_list|(
argument|m
argument_list|,
argument|e
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|mailer
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|ENVELOPE
modifier|*
name|e
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|r
decl_stmt|;
comment|/* 	**  Send the data. 	**	First send the command and check that it is ok. 	**	Then send the data. 	**	Follow it up with a dot to terminate. 	**	Finally get the results of the transaction. 	*/
comment|/* send the command and check ok to proceed */
name|smtpmessage
argument_list|(
literal|"DATA"
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|SmtpPhase
operator|=
literal|"DATA wait"
expr_stmt|;
name|setproctitle
argument_list|(
literal|"%s %s: %s"
argument_list|,
name|CurEnv
operator|->
name|e_id
argument_list|,
name|CurHostName
argument_list|,
name|SmtpPhase
argument_list|)
expr_stmt|;
name|r
operator|=
name|reply
argument_list|(
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|<
literal|0
operator|||
name|REPLYTYPE
argument_list|(
name|r
argument_list|)
operator|==
literal|4
condition|)
return|return
operator|(
name|EX_TEMPFAIL
operator|)
return|;
elseif|else
if|if
condition|(
name|r
operator|==
literal|554
condition|)
return|return
operator|(
name|EX_UNAVAILABLE
operator|)
return|;
elseif|else
if|if
condition|(
name|r
operator|!=
literal|354
condition|)
return|return
operator|(
name|EX_PROTOCOL
operator|)
return|;
comment|/* now output the actual message */
call|(
modifier|*
name|e
operator|->
name|e_puthdr
call|)
argument_list|(
name|SmtpOut
argument_list|,
name|m
argument_list|,
name|CurEnv
argument_list|)
expr_stmt|;
name|putline
argument_list|(
literal|"\n"
argument_list|,
name|SmtpOut
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
name|SmtpOut
argument_list|,
name|m
argument_list|,
name|CurEnv
argument_list|)
expr_stmt|;
comment|/* terminate the message */
name|fprintf
argument_list|(
name|SmtpOut
argument_list|,
literal|".%s"
argument_list|,
name|m
operator|->
name|m_eol
argument_list|)
expr_stmt|;
if|if
condition|(
name|Verbose
operator|&&
operator|!
name|HoldErrs
condition|)
name|nmessage
argument_list|(
name|Arpa_Info
argument_list|,
literal|">>> ."
argument_list|)
expr_stmt|;
comment|/* check for the results of the transaction */
name|SmtpPhase
operator|=
literal|"result wait"
expr_stmt|;
name|setproctitle
argument_list|(
literal|"%s %s: %s"
argument_list|,
name|CurEnv
operator|->
name|e_id
argument_list|,
name|CurHostName
argument_list|,
name|SmtpPhase
argument_list|)
expr_stmt|;
name|r
operator|=
name|reply
argument_list|(
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|<
literal|0
operator|||
name|REPLYTYPE
argument_list|(
name|r
argument_list|)
operator|==
literal|4
condition|)
return|return
operator|(
name|EX_TEMPFAIL
operator|)
return|;
elseif|else
if|if
condition|(
name|r
operator|==
literal|250
condition|)
return|return
operator|(
name|EX_OK
operator|)
return|;
elseif|else
if|if
condition|(
name|r
operator|==
literal|552
operator|||
name|r
operator|==
literal|554
condition|)
return|return
operator|(
name|EX_UNAVAILABLE
operator|)
return|;
return|return
operator|(
name|EX_PROTOCOL
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  SMTPQUIT -- close the SMTP connection. ** **	Parameters: **		m -- a pointer to the mailer. ** **	Returns: **		none. ** **	Side Effects: **		sends the final protocol and closes the connection. */
end_comment

begin_expr_stmt
name|smtpquit
argument_list|(
name|m
argument_list|)
specifier|register
name|MAILER
operator|*
name|m
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|int
name|i
decl_stmt|;
comment|/* if the connection is already closed, don't bother */
if|if
condition|(
name|SmtpIn
operator|==
name|NULL
condition|)
return|return;
comment|/* send the quit message if not a forced quit */
if|if
condition|(
name|SmtpState
operator|==
name|SMTP_OPEN
operator|||
name|SmtpState
operator|==
name|SMTP_SSD
condition|)
block|{
name|smtpmessage
argument_list|(
literal|"QUIT"
argument_list|,
name|m
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|reply
argument_list|(
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|SmtpState
operator|==
name|SMTP_CLOSED
condition|)
return|return;
block|}
comment|/* now actually close the connection */
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|SmtpIn
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|SmtpOut
argument_list|)
expr_stmt|;
name|SmtpIn
operator|=
name|SmtpOut
operator|=
name|NULL
expr_stmt|;
name|SmtpState
operator|=
name|SMTP_CLOSED
expr_stmt|;
comment|/* and pick up the zombie */
name|i
operator|=
name|endmailer
argument_list|(
name|SmtpPid
argument_list|,
name|m
operator|->
name|m_argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|!=
name|EX_OK
condition|)
name|syserr
argument_list|(
literal|"smtpquit %s: stat %d"
argument_list|,
name|m
operator|->
name|m_argv
index|[
literal|0
index|]
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  REPLY -- read arpanet reply ** **	Parameters: **		m -- the mailer we are reading the reply from. ** **	Returns: **		reply code it reads. ** **	Side Effects: **		flushes the mail file. */
end_comment

begin_macro
name|reply
argument_list|(
argument|m
argument_list|)
end_macro

begin_decl_stmt
name|MAILER
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|SmtpOut
argument_list|)
expr_stmt|;
if|if
condition|(
name|tTd
argument_list|(
literal|18
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"reply\n"
argument_list|)
expr_stmt|;
comment|/* 	**  Read the input line, being careful not to hang. 	*/
for|for
control|(
init|;
condition|;
control|)
block|{
specifier|register
name|int
name|r
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
comment|/* actually do the read */
if|if
condition|(
name|CurEnv
operator|->
name|e_xfp
operator|!=
name|NULL
condition|)
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|CurEnv
operator|->
name|e_xfp
argument_list|)
expr_stmt|;
comment|/* for debugging */
comment|/* if we are in the process of closing just give the code */
if|if
condition|(
name|SmtpState
operator|==
name|SMTP_CLOSED
condition|)
return|return
operator|(
name|SMTPCLOSING
operator|)
return|;
comment|/* get the line from the other side */
name|p
operator|=
name|sfgets
argument_list|(
name|SmtpReplyBuffer
argument_list|,
sizeof|sizeof
name|SmtpReplyBuffer
argument_list|,
name|SmtpIn
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
block|{
specifier|extern
name|char
name|MsgBuf
index|[]
decl_stmt|;
comment|/* err.c */
specifier|extern
name|char
name|Arpa_TSyserr
index|[]
decl_stmt|;
comment|/* conf.c */
comment|/* if the remote end closed early, fake an error */
if|if
condition|(
name|errno
operator|==
literal|0
condition|)
ifdef|#
directive|ifdef
name|ECONNRESET
name|errno
operator|=
name|ECONNRESET
expr_stmt|;
else|#
directive|else
else|ECONNRESET
name|errno
operator|=
name|EPIPE
expr_stmt|;
endif|#
directive|endif
endif|ECONNRESET
name|message
argument_list|(
name|Arpa_TSyserr
argument_list|,
literal|"reply: read error"
argument_list|)
expr_stmt|;
comment|/* if debugging, pause so we can see state */
if|if
condition|(
name|tTd
argument_list|(
literal|18
argument_list|,
literal|100
argument_list|)
condition|)
name|pause
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|LOG
name|syslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"%s"
argument_list|,
operator|&
name|MsgBuf
index|[
literal|4
index|]
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|LOG
name|SmtpState
operator|=
name|SMTP_CLOSED
expr_stmt|;
name|smtpquit
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|fixcrlf
argument_list|(
name|SmtpReplyBuffer
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
if|if
condition|(
name|CurEnv
operator|->
name|e_xfp
operator|!=
name|NULL
operator|&&
name|index
argument_list|(
literal|"45"
argument_list|,
name|SmtpReplyBuffer
index|[
literal|0
index|]
argument_list|)
operator|!=
name|NULL
condition|)
block|{
comment|/* serious error -- log the previous command */
if|if
condition|(
name|SmtpMsgBuffer
index|[
literal|0
index|]
operator|!=
literal|'\0'
condition|)
name|fprintf
argument_list|(
name|CurEnv
operator|->
name|e_xfp
argument_list|,
literal|">>> %s\n"
argument_list|,
name|SmtpMsgBuffer
argument_list|)
expr_stmt|;
name|SmtpMsgBuffer
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* now log the message as from the other side */
name|fprintf
argument_list|(
name|CurEnv
operator|->
name|e_xfp
argument_list|,
literal|"<<< %s\n"
argument_list|,
name|SmtpReplyBuffer
argument_list|)
expr_stmt|;
block|}
comment|/* display the input for verbose mode */
if|if
condition|(
name|Verbose
operator|&&
operator|!
name|HoldErrs
condition|)
name|nmessage
argument_list|(
name|Arpa_Info
argument_list|,
literal|"%s"
argument_list|,
name|SmtpReplyBuffer
argument_list|)
expr_stmt|;
comment|/* if continuation is required, we can go on */
if|if
condition|(
name|SmtpReplyBuffer
index|[
literal|3
index|]
operator|==
literal|'-'
operator|||
operator|!
name|isdigit
argument_list|(
name|SmtpReplyBuffer
index|[
literal|0
index|]
argument_list|)
condition|)
continue|continue;
comment|/* decode the reply code */
name|r
operator|=
name|atoi
argument_list|(
name|SmtpReplyBuffer
argument_list|)
expr_stmt|;
comment|/* extra semantics: 0xx codes are "informational" */
if|if
condition|(
name|r
operator|<
literal|100
condition|)
continue|continue;
comment|/* reply code 421 is "Service Shutting Down" */
if|if
condition|(
name|r
operator|==
name|SMTPCLOSING
operator|&&
name|SmtpState
operator|!=
name|SMTP_SSD
condition|)
block|{
comment|/* send the quit protocol */
name|SmtpState
operator|=
name|SMTP_SSD
expr_stmt|;
name|smtpquit
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
comment|/* save temporary failure messages for posterity */
if|if
condition|(
name|SmtpReplyBuffer
index|[
literal|0
index|]
operator|==
literal|'4'
operator|&&
name|SmtpError
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|SmtpError
argument_list|,
operator|&
name|SmtpReplyBuffer
index|[
literal|4
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
name|r
operator|)
return|;
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  SMTPMESSAGE -- send message to server ** **	Parameters: **		f -- format **		m -- the mailer to control formatting. **		a, b, c -- parameters ** **	Returns: **		none. ** **	Side Effects: **		writes message to SmtpOut. */
end_comment

begin_comment
comment|/*VARARGS1*/
end_comment

begin_macro
name|smtpmessage
argument_list|(
argument|f
argument_list|,
argument|m
argument_list|,
argument|a
argument_list|,
argument|b
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MAILER
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|SmtpMsgBuffer
argument_list|,
name|f
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|tTd
argument_list|(
literal|18
argument_list|,
literal|1
argument_list|)
operator|||
operator|(
name|Verbose
operator|&&
operator|!
name|HoldErrs
operator|)
condition|)
name|nmessage
argument_list|(
name|Arpa_Info
argument_list|,
literal|">>> %s"
argument_list|,
name|SmtpMsgBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|SmtpOut
operator|!=
name|NULL
condition|)
name|fprintf
argument_list|(
name|SmtpOut
argument_list|,
literal|"%s%s"
argument_list|,
name|SmtpMsgBuffer
argument_list|,
name|m
operator|==
literal|0
condition|?
literal|"\r\n"
else|:
name|m
operator|->
name|m_eol
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
endif|SMTP
end_endif

end_unit

