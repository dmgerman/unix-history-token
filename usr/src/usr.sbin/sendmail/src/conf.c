begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|"sendmail.h"
end_include

begin_comment
comment|/* **  CONF.C -- Sendmail Configuration Tables. ** **	Defines the configuration of this installation. ** **	Compilation Flags: **		V6 -- running on a version 6 system.  This determines **			whether to define certain routines between **			the two systems.  If you are running a funny **			system, e.g., V6 with long tty names, this **			should be checked carefully. ** **	Configuration Variables: **		HdrInfo -- a table describing well-known header fields. **			Each entry has the field name and some flags, **			which are described in sendmail.h. **		StdTimezone -- name of local timezone in standard time **			(V6 only). **		DstTimezone -- name of local timezone in daylight savings **			time (V6 only). ** **	Notes: **		I have tried to put almost all the reasonable **		configuration information into the configuration **		file read at runtime.  My intent is that anything **		here is a function of the version of UNIX you **		are running, or is really static -- for example **		the headers are a superset of widely used **		protocols.  If you find yourself playing with **		this file too much, you may be making a mistake! */
end_comment

begin_expr_stmt
name|SCCSID
argument_list|(
argument|@
operator|(
operator|#
operator|)
name|conf
operator|.
name|c
literal|3.52
operator|%
name|G
operator|%
argument_list|)
expr_stmt|;
end_expr_stmt

begin_escape
end_escape

begin_comment
comment|/* **  Header info table **	Final (null) entry contains the flags used for any other field. ** **	Not all of these are actually handled specially by sendmail **	at this time.  They are included as placeholders, to let **	you know that "someday" I intend to have sendmail do **	something with them. */
end_comment

begin_decl_stmt
name|struct
name|hdrinfo
name|HdrInfo
index|[]
init|=
block|{
literal|"date"
block|,
name|H_CHECK
block|,
name|M_NEEDDATE
block|,
literal|"from"
block|,
name|H_ADDR
operator||
name|H_FROM
operator||
name|H_CHECK
block|,
name|M_NEEDFROM
block|,
literal|"original-from"
block|,
literal|0
block|,
literal|0
block|,
literal|"sender"
block|,
name|H_ADDR
block|,
literal|0
block|,
literal|"full-name"
block|,
name|H_ACHECK
block|,
name|M_FULLNAME
block|,
literal|"to"
block|,
name|H_ADDR
operator||
name|H_RCPT
block|,
literal|0
block|,
literal|"cc"
block|,
name|H_ADDR
operator||
name|H_RCPT
block|,
literal|0
block|,
literal|"bcc"
block|,
name|H_ADDR
operator||
name|H_RCPT
block|,
literal|0
block|,
literal|"message-id"
block|,
literal|0
block|,
literal|0
block|,
literal|"message"
block|,
name|H_EOH
block|,
literal|0
block|,
literal|"text"
block|,
name|H_EOH
block|,
literal|0
block|,
literal|"posted-date"
block|,
literal|0
block|,
literal|0
block|,
literal|"return-receipt-to"
block|,
literal|0
block|,
literal|0
block|,
literal|"received-date"
block|,
name|H_CHECK
block|,
name|M_LOCAL
block|,
literal|"received-from"
block|,
name|H_CHECK
block|,
name|M_LOCAL
block|,
literal|"precedence"
block|,
literal|0
block|,
literal|0
block|,
literal|"mail-from"
block|,
name|H_FORCE
block|,
literal|0
block|,
literal|"via"
block|,
name|H_FORCE
block|,
literal|0
block|,
name|NULL
block|,
literal|0
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  ARPANET error message numbers. */
end_comment

begin_decl_stmt
name|char
name|Arpa_Info
index|[]
init|=
literal|"050"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* arbitrary info */
end_comment

begin_decl_stmt
name|char
name|Arpa_Syserr
index|[]
init|=
literal|"451"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* some (transient) system error */
end_comment

begin_decl_stmt
name|char
name|Arpa_Usrerr
index|[]
init|=
literal|"554"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* some (fatal) user error */
end_comment

begin_comment
comment|/* **  Location of system files/databases/etc. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|AliasFile
init|=
literal|"/usr/lib/aliases"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* alias file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ConfFile
init|=
literal|"/usr/lib/sendmail.cf"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* runtime configuration */
end_comment

begin_decl_stmt
name|char
modifier|*
name|StatFile
init|=
literal|"/usr/lib/sendmail.st"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* statistics summary */
end_comment

begin_decl_stmt
name|char
modifier|*
name|HelpFile
init|=
literal|"/usr/lib/sendmail.hf"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* help file */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|QUEUE
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|QueueDir
init|=
literal|"/usr/spool/mqueue"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* queue of saved mail */
end_comment

begin_else
else|#
directive|else
else|QUEUE
end_else

begin_decl_stmt
name|char
modifier|*
name|QueueDir
init|=
literal|"/tmp"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of temp files */
end_comment

begin_endif
endif|#
directive|endif
endif|QUEUE
end_endif

begin_decl_stmt
name|char
modifier|*
name|XcriptFile
init|=
literal|"/tmp/mailxXXXXXX"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* template for transcript */
end_comment

begin_comment
comment|/* **  Other configuration. */
end_comment

begin_decl_stmt
name|int
name|DefUid
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the uid to execute mailers as */
end_comment

begin_decl_stmt
name|int
name|DefGid
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ditto for gid */
end_comment

begin_decl_stmt
name|time_t
name|TimeOut
init|=
literal|3
operator|*
literal|24
operator|*
literal|60
operator|*
literal|60L
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default timeout for queue files */
end_comment

begin_decl_stmt
name|char
modifier|*
name|TextTimeOut
init|=
literal|"three days"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* text of above for error messages */
end_comment

begin_decl_stmt
name|int
name|ReadTimeout
init|=
literal|10
operator|*
literal|60
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* timeout on external reads */
end_comment

begin_decl_stmt
name|int
name|LogLevel
init|=
literal|9
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default logging level */
end_comment

begin_comment
comment|/* **  V6 system configuration. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V6
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|StdTimezone
init|=
literal|"PST"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* std time timezone */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DstTimezone
init|=
literal|"PDT"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* daylight time timezone */
end_comment

begin_endif
endif|#
directive|endif
endif|V6
end_endif

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|V6
end_ifdef

begin_comment
comment|/* **  TTYNAME -- return name of terminal. ** **	Parameters: **		fd -- file descriptor to check. ** **	Returns: **		pointer to full path of tty. **		NULL if no tty. ** **	Side Effects: **		none. */
end_comment

begin_function
name|char
modifier|*
name|ttyname
parameter_list|(
name|fd
parameter_list|)
name|int
name|fd
decl_stmt|;
block|{
specifier|register
name|char
name|tn
decl_stmt|;
specifier|static
name|char
name|pathn
index|[]
init|=
literal|"/dev/ttyx"
decl_stmt|;
comment|/* compute the pathname of the controlling tty */
if|if
condition|(
operator|(
name|tn
operator|=
name|ttyn
argument_list|(
name|fd
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|errno
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|pathn
index|[
literal|8
index|]
operator|=
name|tn
expr_stmt|;
return|return
operator|(
name|pathn
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  FDOPEN -- Open a stdio file given an open file descriptor. ** **	This is included here because it is standard in v7, but we **	need it in v6. ** **	Algorithm: **		Open /dev/null to create a descriptor. **		Close that descriptor. **		Copy the existing fd into the descriptor. ** **	Parameters: **		fd -- the open file descriptor. **		type -- "r", "w", or whatever. ** **	Returns: **		The file descriptor it creates. ** **	Side Effects: **		none ** **	Called By: **		deliver ** **	Notes: **		The mode of fd must match "type". */
end_comment

begin_function
name|FILE
modifier|*
name|fdopen
parameter_list|(
name|fd
parameter_list|,
name|type
parameter_list|)
name|int
name|fd
decl_stmt|;
name|char
modifier|*
name|type
decl_stmt|;
block|{
specifier|register
name|FILE
modifier|*
name|f
decl_stmt|;
name|f
operator|=
name|fopen
argument_list|(
literal|"/dev/null"
argument_list|,
name|type
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
name|fileno
argument_list|(
name|f
argument_list|)
argument_list|)
expr_stmt|;
name|fileno
argument_list|(
name|f
argument_list|)
operator|=
name|fd
expr_stmt|;
return|return
operator|(
name|f
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  INDEX -- Return pointer to character in string ** **	For V7 compatibility. ** **	Parameters: **		s -- a string to scan. **		c -- a character to look for. ** **	Returns: **		If c is in s, returns the address of the first **			instance of c in s. **		NULL if c is not in s. ** **	Side Effects: **		none. */
end_comment

begin_function
name|char
modifier|*
name|index
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
specifier|register
name|char
name|c
decl_stmt|;
block|{
while|while
condition|(
operator|*
name|s
operator|!=
literal|'\0'
condition|)
block|{
if|if
condition|(
operator|*
name|s
operator|++
operator|==
name|c
condition|)
return|return
operator|(
operator|--
name|s
operator|)
return|;
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  UMASK -- fake the umask system call. ** **	Since V6 always acts like the umask is zero, we will just **	assume the same thing. */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|umask
argument_list|(
argument|nmask
argument_list|)
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

begin_comment
comment|/* **  GETRUID -- get real user id. */
end_comment

begin_macro
name|getruid
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|getuid
argument_list|()
operator|&
literal|0377
operator|)
return|;
block|}
end_block

begin_comment
comment|/* **  GETRGID -- get real group id. */
end_comment

begin_macro
name|getrgid
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|getgid
argument_list|()
operator|&
literal|0377
operator|)
return|;
block|}
end_block

begin_comment
comment|/* **  GETEUID -- get effective user id. */
end_comment

begin_macro
name|geteuid
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
operator|(
name|getuid
argument_list|()
operator|>>
literal|8
operator|)
operator|&
literal|0377
operator|)
return|;
block|}
end_block

begin_comment
comment|/* **  GETEGID -- get effective group id. */
end_comment

begin_macro
name|getegid
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
operator|(
name|getgid
argument_list|()
operator|>>
literal|8
operator|)
operator|&
literal|0377
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
endif|V6
end_endif

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|V6
end_ifndef

begin_comment
comment|/* **  GETRUID -- get real user id (V7) */
end_comment

begin_macro
name|getruid
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|Mode
operator|==
name|MD_DAEMON
condition|)
return|return
operator|(
name|RealUid
operator|)
return|;
else|else
return|return
operator|(
name|getuid
argument_list|()
operator|)
return|;
block|}
end_block

begin_comment
comment|/* **  GETRGID -- get real group id (V7). */
end_comment

begin_macro
name|getrgid
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|Mode
operator|==
name|MD_DAEMON
condition|)
return|return
operator|(
name|RealGid
operator|)
return|;
else|else
return|return
operator|(
name|getgid
argument_list|()
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
endif|V6
end_endif

begin_escape
end_escape

begin_comment
comment|/* **  TTYPATH -- Get the path of the user's tty ** **	Returns the pathname of the user's tty.  Returns NULL if **	the user is not logged in or if s/he has write permission **	denied. ** **	Parameters: **		none ** **	Returns: **		pathname of the user's tty. **		NULL if not logged in or write permission denied. ** **	Side Effects: **		none. ** **	WARNING: **		Return value is in a local buffer. ** **	Called By: **		savemail */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_function
name|char
modifier|*
name|ttypath
parameter_list|()
block|{
name|struct
name|stat
name|stbuf
decl_stmt|;
specifier|register
name|char
modifier|*
name|pathn
decl_stmt|;
specifier|extern
name|char
modifier|*
name|ttyname
parameter_list|()
function_decl|;
specifier|extern
name|char
modifier|*
name|getlogin
parameter_list|()
function_decl|;
comment|/* compute the pathname of the controlling tty */
if|if
condition|(
operator|(
name|pathn
operator|=
name|ttyname
argument_list|(
literal|2
argument_list|)
operator|)
operator|==
name|NULL
operator|&&
operator|(
name|pathn
operator|=
name|ttyname
argument_list|(
literal|1
argument_list|)
operator|)
operator|==
name|NULL
operator|&&
operator|(
name|pathn
operator|=
name|ttyname
argument_list|(
literal|0
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|errno
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
comment|/* see if we have write permission */
if|if
condition|(
name|stat
argument_list|(
name|pathn
argument_list|,
operator|&
name|stbuf
argument_list|)
operator|<
literal|0
operator|||
operator|!
name|bitset
argument_list|(
literal|02
argument_list|,
name|stbuf
operator|.
name|st_mode
argument_list|)
condition|)
block|{
name|errno
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
comment|/* see if the user is logged in */
if|if
condition|(
name|getlogin
argument_list|()
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
comment|/* looks good */
return|return
operator|(
name|pathn
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  CHECKCOMPAT -- check for From and To person compatible. ** **	This routine can be supplied on a per-installation basis **	to determine whether a person is allowed to send a message. **	This allows restriction of certain types of internet **	forwarding or registration of users. ** **	If the hosts are found to be incompatible, an error **	message should be given using "usrerr" and FALSE should **	be returned. ** **	'NoReturn' can be set to suppress the return-to-sender **	function; this should be done on huge messages. ** **	Parameters: **		to -- the person being sent to. ** **	Returns: **		TRUE -- ok to send. **		FALSE -- not ok. ** **	Side Effects: **		none (unless you include the usrerr stuff) */
end_comment

begin_function
name|bool
name|checkcompat
parameter_list|(
name|to
parameter_list|)
specifier|register
name|ADDRESS
modifier|*
name|to
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|ING70
specifier|register
name|STAB
modifier|*
name|s
decl_stmt|;
endif|#
directive|endif
endif|ING70
if|if
condition|(
name|to
operator|->
name|q_mailer
operator|!=
name|LocalMailer
operator|&&
name|CurEnv
operator|->
name|e_msgsize
operator|>
literal|100000
condition|)
block|{
name|usrerr
argument_list|(
literal|"Message exceeds 100000 bytes"
argument_list|)
expr_stmt|;
name|NoReturn
operator|++
expr_stmt|;
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|ING70
name|s
operator|=
name|stab
argument_list|(
literal|"arpa"
argument_list|,
name|ST_MAILER
argument_list|,
name|ST_FIND
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|!=
name|NULL
operator|&&
name|CurEnv
operator|->
name|e_from
operator|.
name|q_mailer
operator|!=
name|LocalMailer
operator|&&
name|to
operator|->
name|q_mailer
operator|==
name|s
operator|->
name|s_mailer
condition|)
block|{
name|usrerr
argument_list|(
literal|"No ARPA mail through this machine: see your system administration"
argument_list|)
expr_stmt|;
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
endif|#
directive|endif
endif|ING70
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
end_function

end_unit

