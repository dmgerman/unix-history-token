begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
comment|/* **  CONF.C -- Sendmail Configuration Tables. ** **	Defines the configuration of this installation. ** **	Compilation Flags: **		NETV6MAIL -- set if you want to use "v6mail" that **			comes with the Berkeley network.  Normally **			/bin/mail will work fine, but around Berkeley **			we use v6mail because it is a "fixed target". **			Also, only v6mail has the "/dev/mail" stuff **			in it (for biff(1)). **		V6 -- running on a version 6 system.  This determines **			whether to define certain routines between **			the two systems.  If you are running a funny **			system, e.g., V6 with long tty names, this **			should be checked carefully. ** **	Configuration Variables: **		Mailer -- a table of mailers known to the system. **			This should be fairly static.  The fields are: **			- the pathname of the mailer. **			- a list of flags describing the properties **			  of this mailer: **			   M_FOPT -- if set, the mailer has a picky "-f" **				option.  In this mode, the mailer will **				only accept the "-f" option if the **				sender is actually "root", "network", **				and possibly (but not necessarily) if **				the -f argument matches the real sender. **				The effect is that if the "-f" option **				is given to sendmail then it will be **				passed through (as arguments 1& 2) to **				the mailer. **			   M_ROPT -- identical to M_FOPT, except uses **				-r instead. **			   M_QUIET -- if set, don't print a message if **				the mailer returns bad status. **			   M_RESTR -- if set, this mailer is restricted **				to use by "daemon"; otherwise, we do a **				setuid(getuid()) before calling the **				mailer. **			   M_NHDR -- if set, the mailer doesn't want us **				to insert a UNIX "From" line before **				outputing. **			   M_NOHOST -- if set, this mailer doesn't care **				about the host part (e.g., the local **				mailer). **			   M_STRIPQ -- if set, strip quote (`"') **				characters out of parameters as you **				transliterate them into the argument **				vector.  For example, the local mailer **				is called directly, so these should be **				stripped, but the program-mailer (i.e., **				csh) should leave them in. **			   M_NEEDDATE -- this mailer requires a Date: **				field in the message. **			   M_NEEDFROM -- this mailer requires a From: **				field in the message. **			   M_MSGID -- this mailer requires a Message-Id **				field in the message. **			   M_ARPAFMT == M_NEEDDATE|M_NEEDFROM|M_MSGID. **			- an exit status to use as the code for the **			  error message print if the mailer returns **			  something we don't understand. **			- A list of names that are to be considered **			  "local" (and hence are stripped off) for **			  this mailer. **			- An argument vector to be passed to the **			  mailer; this is macro substituted. **>>>>>>>>>> Entry zero must be for the local **>> NOTE>> mailer and entry one must be for **>>>>>>>>>> the shell. **		HdrInfo -- a table describing well-known header fields. **			Each entry has the field name and some flags, **			which can be: **			- H_EOH -- this field is equivalent to a blank **			  line; i.e., it signifies end of header. **			- H_DELETE -- delete this field. **			There is also a field pointing to a pointer **			that should be set to point to this header. */
end_comment

begin_decl_stmt
specifier|static
name|char
name|SccsId
index|[]
init|=
literal|"@(#)conf.c	3.15	%G%"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<whoami.h>
end_include

begin_comment
comment|/* definitions of machine id's at berkeley */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BERKELEY
end_ifdef

begin_define
define|#
directive|define
name|NETV6MAIL
end_define

begin_comment
comment|/* use /usr/net/bin/v6mail for local delivery */
end_comment

begin_endif
endif|#
directive|endif
endif|BERKELEY
end_endif

begin_comment
comment|/* local mail -- must be #0 */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|LocalArgv
index|[]
init|=
block|{
literal|"...local%mail"
block|,
literal|"-d"
block|,
literal|"$u"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|mailer
name|LocalMailer
init|=
block|{
ifdef|#
directive|ifdef
name|NETV6MAIL
literal|"local"
block|,
literal|"/usr/net/bin/v6mail"
block|,
else|#
directive|else
literal|"local"
block|,
literal|"/bin/mail"
block|,
endif|#
directive|endif
name|M_ROPT
operator||
name|M_NOHOST
operator||
name|M_STRIPQ
operator||
name|M_ARPAFMT
operator||
name|M_MUSER
operator||
name|M_NHDR
block|,
name|EX_NOUSER
block|,
literal|"$f"
block|,
name|LocalArgv
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pipes through programs -- must be #1 -- also used for files */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ProgArgv
index|[]
init|=
block|{
literal|"...prog%mail"
block|,
literal|"-fc"
block|,
literal|"$u"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|mailer
name|ProgMailer
init|=
block|{
literal|"prog"
block|,
literal|"/bin/csh"
block|,
name|M_NOHOST
operator||
name|M_ARPAFMT
block|,
name|EX_UNAVAILABLE
block|,
literal|"$f"
block|,
name|ProgArgv
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user-private mailers -- must be #2 */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|PrivArgv
index|[]
init|=
block|{
literal|"...priv%mail"
block|,
literal|"$u"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|mailer
name|PrivMailer
init|=
block|{
literal|"priv"
block|,
name|NULL
block|,
name|M_ROPT
operator||
name|M_NOHOST
operator||
name|M_STRIPQ
operator||
name|M_ARPAFMT
block|,
name|EX_UNAVAILABLE
block|,
literal|"$f"
block|,
name|PrivArgv
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local berkeley mail */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|BerkArgv
index|[]
init|=
block|{
literal|"...berk%mail"
block|,
literal|"-m"
block|,
literal|"$h"
block|,
literal|"-h"
block|,
literal|"$c"
block|,
literal|"-t"
block|,
literal|"$u"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|mailer
name|BerkMailer
init|=
block|{
literal|"berk"
block|,
literal|"/usr/net/bin/sendberkmail"
block|,
name|M_FOPT
operator||
name|M_NEEDDATE
operator||
name|M_FULLNAME
operator||
name|M_STRIPQ
block|,
name|EX_UNAVAILABLE
block|,
literal|"$B:$f"
block|,
name|BerkArgv
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* arpanet mail */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ArpaArgv
index|[]
init|=
block|{
literal|"...arpa%mail"
block|,
literal|"$f"
block|,
literal|"$h"
block|,
literal|"$u"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|mailer
name|ArpaMailer
init|=
block|{
literal|"arpa"
block|,
literal|"/usr/lib/mailers/arpa"
block|,
name|M_STRIPQ
operator||
name|M_ARPAFMT
operator||
name|M_USR_UPPER
block|,
literal|0
block|,
literal|"$f@$A"
block|,
name|ArpaArgv
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* uucp mail (cheat& use Bell's v7 mail) */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|UucpArgv
index|[]
init|=
block|{
literal|"...uucp%mail"
block|,
literal|"-"
block|,
literal|"$h!rmail"
block|,
literal|"($u)"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|mailer
name|UucpMailer
init|=
block|{
literal|"uucp"
block|,
literal|"/usr/bin/uux"
block|,
name|M_ROPT
operator||
name|M_STRIPQ
operator||
name|M_NEEDDATE
operator||
name|M_FULLNAME
operator||
name|M_MUSER
block|,
name|EX_NOUSER
block|,
literal|"$U!$f"
block|,
name|UucpArgv
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mailer
modifier|*
name|Mailer
index|[]
init|=
block|{
operator|&
name|LocalMailer
block|,
comment|/* 0 -- must be 0 */
operator|&
name|ProgMailer
block|,
comment|/* 1 -- must be 1 */
operator|&
name|PrivMailer
block|,
comment|/* 2 -- must be 2 */
operator|&
name|BerkMailer
block|,
comment|/* 3 */
operator|&
name|ArpaMailer
block|,
comment|/* 4 */
operator|&
name|UucpMailer
block|,
comment|/* 5 */
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offsets for arbitrary mailers */
end_comment

begin_define
define|#
directive|define
name|M_BERK
value|2
end_define

begin_comment
comment|/* berknet */
end_comment

begin_define
define|#
directive|define
name|M_ARPA
value|3
end_define

begin_comment
comment|/* arpanet */
end_comment

begin_define
define|#
directive|define
name|M_UUCP
value|4
end_define

begin_comment
comment|/* UUCPnet */
end_comment

begin_comment
comment|/* **  Header info table **	Final (null) entry contains the flags used for any other field. */
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
name|H_CHECK
block|,
name|M_NEEDFROM
block|,
literal|"full-name"
block|,
name|H_ACHECK
block|,
name|M_FULLNAME
block|,
literal|"to"
block|,
literal|0
block|,
name|NULL
block|,
literal|"cc"
block|,
literal|0
block|,
name|NULL
block|,
literal|"subject"
block|,
literal|0
block|,
name|NULL
block|,
literal|"message-id"
block|,
name|H_CHECK
block|,
name|M_MSGID
block|,
literal|"message"
block|,
name|H_EOH
block|,
name|NULL
block|,
name|NULL
block|,
literal|0
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|V6
end_ifdef

begin_comment
comment|/* **  TTYPATH -- Get the path of the user's tty -- Version 6 version. ** **	Returns the pathname of the user's tty.  Returns NULL if **	the user is not logged in or if s/he has write permission **	denied. ** **	Parameters: **		none ** **	Returns: **		pathname of the user's tty. **		NULL if not logged in or write permission denied. ** **	Side Effects: **		none. ** **	WARNING: **		Return value is in a local buffer. ** **	Called By: **		savemail */
end_comment

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
name|int
name|i
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
name|i
operator|=
name|ttyn
argument_list|(
literal|2
argument_list|)
operator|)
operator|==
literal|'x'
operator|&&
operator|(
name|i
operator|=
name|ttyn
argument_list|(
literal|1
argument_list|)
operator|)
operator|==
literal|'x'
operator|&&
operator|(
name|i
operator|=
name|ttyn
argument_list|(
literal|0
argument_list|)
operator|)
operator|==
literal|'x'
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
name|i
expr_stmt|;
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

begin_expr_stmt
name|index
argument_list|(
name|s
argument_list|,
name|c
argument_list|)
specifier|register
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
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
comment|/* **  TTYPATH -- Get the path of the user's tty -- Version 7 version. ** **	Returns the pathname of the user's tty.  Returns NULL if **	the user is not logged in or if s/he has write permission **	denied. ** **	Parameters: **		none ** **	Returns: **		pathname of the user's tty. **		NULL if not logged in or write permission denied. ** **	Side Effects: **		none. ** **	WARNING: **		Return value is in a local buffer. ** **	Called By: **		savemail */
end_comment

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

begin_endif
endif|#
directive|endif
endif|V6
end_endif

begin_escape
end_escape

begin_comment
comment|/* **  CHECKCOMPAT -- check for From and To person compatible. ** **	This routine can be supplied on a per-installation basis **	to determine whether a person is allowed to send a message. **	This allows restriction of certain types of internet **	forwarding or registration of users. ** **	If the hosts are found to be incompatible, an error **	message should be given using "usrerr" and FALSE should **	be returned. ** **	Parameters: **		to -- the person being sent to. ** **	Returns: **		TRUE -- ok to send. **		FALSE -- not ok. ** **	Side Effects: **		none (unless you include the usrerr stuff) */
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
name|lint
name|ADDRESS
modifier|*
name|x
init|=
name|to
decl_stmt|;
name|to
operator|=
name|x
expr_stmt|;
endif|#
directive|endif
endif|lint
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
end_function

end_unit

