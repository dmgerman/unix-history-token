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
file|"postbox.h"
end_include

begin_comment
comment|/* **  CONF.C -- Postbox Configuration Tables. ** **	Defines the configuration of this installation. ** **	Compilation Flags: **		HASARPA -- set if this machine has a connection to **			the Arpanet. **		HASUUCP -- set if this machine has a connection to **			the UUCP network. **		NETV6MAIL -- set if you want to use "v6mail" that **			comes with the Berkeley network.  Normally **			/bin/mail will work fine, but around Berkeley **			we use v6mail because it is a "fixed target". **			Also, only v6mail has the "/dev/mail" stuff **			in it (for biff(1)). **		V6 -- running on a version 6 system.  This determines **			whether to define certain routines between **			the two systems.  If you are running a funny **			system, e.g., V6 with long tty names, this **			should be checked carefully. **		DUMBMAIL -- set if your /bin/mail doesn't have the **			-d flag. ** **	Configuration Variables: **		ArpaHost -- the arpanet name of the host through **			which arpanet mail will be sent. **		MyLocName -- the name of the host on a local network. **			This is used to disambiguate the contents of **			ArpaHost among many hosts who may be sharing **			a gateway. **		DaemonName -- the name of this agent for use in **			error messages, typically "~MAILER~DAEMON~" **			at this host on the local net. **		ArpaLocal -- a list of local names for this host on **			the arpanet.  Only functional if HASARPA set. **		UucpLocal -- ditto for the Arpanet. **		BerkLocal -- ditto for the Berknet. **		Mailer -- a table of mailers known to the system. **			The fields are: **			- the pathname of the mailer. **			- a list of flags describing the properties **			  of this mailer: **			   M_FOPT -- if set, the mailer has a picky "-f" **				option.  In this mode, the mailer will **				only accept the "-f" option if the **				sender is actually "root", "network", **				and possibly (but not necessarily) if **				the -f argument matches the real sender. **				The effect is that if the "-f" option **				is given to postbox then it will be **				passed through (as arguments 1& 2) to **				the mailer. **			   M_ROPT -- identical to M_FOPT, except uses **				-r instead. **			   M_QUIET -- if set, don't print a message if **				the mailer returns bad status. **			   M_RESTR -- if set, this mailer is restricted **				to use by "daemon"; otherwise, we do a **				setuid(getuid()) before calling the **				mailer. **			   M_HDR -- if set, the mailer wants us to **				insert a UNIX "From" line before **				outputing. **			   M_FHDR -- if set, the header that we **				generate will be used literally, so **				we must force it to be correct.  The **				effect is that we generate a header **				even if one exists. **			   M_NOHOST -- if set, this mailer doesn't care **				about the host part (e.g., the local **				mailer). **			   M_STRIPQ -- if set, strip quote (`"') **				characters out of parameters as you **				transliterate them into the argument **				vector.  For example, the local mailer **				is called directly, so these should be **				stripped, but the program-mailer (i.e., **				csh) should leave them in. **			   M_NEEDDATE -- this mailer requires a Date: **				field in the message. **			   M_NEEDFROM -- this mailer requires a From: **				field in the message. **			   M_MSGID -- this mailer requires a Message-Id **				field in the message. **			   M_COMMAS -- this mailer wants comma- **				seperated To: and Cc: fields. **			   M_ARPAFMT == M_NEEDDATE|M_NEEDFROM|M_MSGID| **				M_COMMAS. **			- an exit status to use as the code for the **			  error message print if the mailer returns **			  something we don't understand. **			- A list of names that are to be considered **			  "local" (and hence are stripped off) for **			  this mailer. **			- An argument vector to be passed to the **			  mailer with the following substitutions: **			   $f - the from person name. **			   $u - the target user name. **			   $h - the target user host. **			   $c - the hop count. **>>>>>>>>>> Entry zero must be for the local **>> NOTE>> mailer and entry one must be for **>>>>>>>>>> the shell. **		ParseTab -- a table driving the parsing process.  Each **			entry contains: **			- a character that will trigger this entry. **			- an index into the Mailer table. **			- a word of flags, described in postbox.h. **			- an argument.  If we have P_MAP, it is the **			  character to turn the trigger character into. **			  If we have P_MOVE, it is the site to send it **			  to, using the mailer specified above. **			This table will almost certainly have to be **			changed on your site if you have anything more **			than the UUCP net. **		HdrInfo -- a table describing well-known header fields. **			Each entry has the field name and some flags, **			which can be: **			H_CONCAT -- if there is more than one field **				of this name, turn it into a comma- **				seperated list. **			H_DELETE -- delete this field. */
end_comment

begin_decl_stmt
specifier|static
name|char
name|SccsId
index|[]
init|=
literal|"@(#)conf.c	3.4	%G%"
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

begin_decl_stmt
name|char
modifier|*
name|ArpaHost
init|=
literal|"Berkeley"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* host name of gateway on Arpanet */
end_comment

begin_decl_stmt
name|char
modifier|*
name|UucpHost
init|=
literal|"ucbvax"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* host name of gateway on UUCP net */
end_comment

begin_define
define|#
directive|define
name|BerkHost
value|MyLocName
end_define

begin_comment
comment|/* host name of gateway on Berk net */
end_comment

begin_define
define|#
directive|define
name|NETV6MAIL
end_define

begin_comment
comment|/* use /usr/net/bin/v6mail for local delivery */
end_comment

begin_else
else|#
directive|else
else|BERKELEY
end_else

begin_decl_stmt
name|char
modifier|*
name|ArpaHost
init|=
literal|"[unknown]"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|MyLocName
init|=
name|sysname
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HASUUCP
end_define

begin_comment
comment|/* default to having UUCP net */
end_comment

begin_decl_stmt
name|char
modifier|*
name|UucpLocal
index|[]
init|=
block|{
name|sysname
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|BERKELEY
end_endif

begin_comment
comment|/* Specific Configurations for Berkeley Machines */
end_comment

begin_comment
comment|/* Berkeley people: mail changes to csvax:eric or they will be lost! */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ING70
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|BerkLocal
index|[]
init|=
block|{
literal|"i"
block|,
literal|"ingres"
block|,
literal|"ing70"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ArpaLocal
init|=
block|{
literal|"berkeley"
block|,
literal|"ucb"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|MyLocName
init|=
literal|"Ing70"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|DaemonName
init|=
literal|"Ing70:~MAILER~DAEMON~"
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HASARPA
end_define

begin_define
define|#
directive|define
name|V6
end_define

begin_endif
endif|#
directive|endif
endif|ING70
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INGVAX
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|BerkLocal
index|[]
init|=
block|{
literal|"j"
block|,
literal|"ingvax"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|MyLocName
init|=
literal|"IngVax"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|DaemonName
init|=
literal|"IngVax:~MAILER~DAEMON~"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|INGVAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CSVAX
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|BerkLocal
index|[]
init|=
block|{
literal|"v"
block|,
literal|"csvax"
block|,
literal|"vax"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|UucpLocal
index|[]
init|=
block|{
literal|"ucbvax"
block|,
literal|"ernie"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|MyLocName
init|=
literal|"CSVAX"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|DaemonName
init|=
literal|"CSVAX:~MAILER~DAEMON~"
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HASUUCP
end_define

begin_endif
endif|#
directive|endif
endif|CSVAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ARPAVAX
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|BerkLocal
index|[]
init|=
block|{
literal|"r"
block|,
literal|"arpavax"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|MyLocName
init|=
literal|"ARPAVAX"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|DaemonName
init|=
literal|"ARPAVAX:~MAILER~DAEMON~"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|ARPAVAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CORY
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|BerkLocal
index|[]
init|=
block|{
literal|"y"
block|,
literal|"cory"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|MyLocName
init|=
literal|"Cory"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|DaemonName
init|=
literal|"Cory:~MAILER~DAEMON~"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|CORY
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ONYX
end_ifdef

begin_expr_stmt
specifier|static
name|char
operator|*
name|BerkLocal
index|[
index|[]
operator|=
block|{
literal|"x"
block|,
literal|"onyx"
block|,
name|NULL
block|}
expr|;
name|char
operator|*
name|MyLocName
operator|=
literal|"Onyx"
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|DaemonName
init|=
literal|"Onyx:~MAILER~DAEMON~"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|ONYX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IMAGE
end_ifdef

begin_comment
comment|/* untested */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|BerkLocal
index|[]
init|=
block|{
literal|"m"
block|,
literal|"image"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|MyLocName
init|=
literal|"Image"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|DaemonName
init|=
literal|"Image:~MAILER~DAEMON~"
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|V6
end_define

begin_endif
endif|#
directive|endif
endif|IMAGE
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ESVAX
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|BerkLocal
index|[]
init|=
block|{
literal|"o"
block|,
literal|"esvax"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|MyLocName
init|=
literal|"ESVAX"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|DaemonName
init|=
literal|"ESVAX:~MAILER~DAEMON~"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|ESVAX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EECS40
end_ifdef

begin_comment
comment|/* untested */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|BerkLocal
index|[]
init|=
block|{
literal|"z"
block|,
literal|"eecs40"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|MyLocName
init|=
literal|"EECS40"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|DaemonName
init|=
literal|"EECS40:~MAILER~DAEMON~"
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|V6
end_define

begin_endif
endif|#
directive|endif
endif|EECS40
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASARPA
end_ifndef

begin_define
define|#
directive|define
name|ArpaLocal
value|NULL
end_define

begin_endif
endif|#
directive|endif
endif|HASARPA
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASUUCP
end_ifndef

begin_define
define|#
directive|define
name|UucpLocal
value|NULL
end_define

begin_endif
endif|#
directive|endif
endif|HASUUCP
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
literal|"/usr/net/bin/v6mail"
block|,
else|#
directive|else
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
block|,
name|EX_NOUSER
block|,
name|NULL
block|,
literal|"$f"
block|,
name|NULL
block|,
name|LocalArgv
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pipes through programs -- must be #1 */
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
literal|"/bin/csh"
block|,
name|M_HDR
operator||
name|M_FHDR
operator||
name|M_NOHOST
block|,
name|EX_UNAVAILABLE
block|,
name|NULL
block|,
literal|"$f"
block|,
name|NULL
block|,
name|ProgArgv
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
literal|"-t"
block|,
literal|"$u"
block|,
literal|"-h"
block|,
literal|"$c"
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
literal|"/usr/net/bin/sendberkmail"
block|,
name|M_FOPT
operator||
name|M_HDR
operator||
name|M_STRIPQ
block|,
name|EX_UNAVAILABLE
block|,
name|BerkLocal
block|,
literal|"$B:$f"
block|,
name|NULL
block|,
name|BerkArgv
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
literal|"/usr/lib/mailers/arpa"
block|,
name|M_STRIPQ
operator||
name|M_ARPAFMT
block|,
literal|0
block|,
name|ArpaLocal
block|,
literal|"$f@$A"
block|,
name|NULL
block|,
name|ArpaArgv
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
ifdef|#
directive|ifdef
name|DUMBMAIL
literal|"-d"
block|,
endif|#
directive|endif
endif|DUMBMAIL
literal|"$h!$u"
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
literal|"/bin/mail"
block|,
name|M_ROPT
operator||
name|M_STRIPQ
block|,
name|EX_NOUSER
block|,
name|UucpLocal
block|,
literal|"$U!$f"
block|,
name|NULL
block|,
name|UucpArgv
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
name|BerkMailer
block|,
comment|/* 2 */
operator|&
name|ArpaMailer
block|,
comment|/* 3 */
operator|&
name|UucpMailer
block|,
comment|/* 4 */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NMAILERS
value|(sizeof Mailer / sizeof Mailer[0])
end_define

begin_define
define|#
directive|define
name|M_LOCAL
value|0
end_define

begin_define
define|#
directive|define
name|M_PROG
value|1
end_define

begin_define
define|#
directive|define
name|M_BERK
value|2
end_define

begin_define
define|#
directive|define
name|M_ARPA
value|3
end_define

begin_define
define|#
directive|define
name|M_UUCP
value|4
end_define

begin_comment
comment|/* list of messages for each mailer (sorted by host) */
end_comment

begin_decl_stmt
name|ADDRESS
name|MailList
index|[
name|NMAILERS
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BERKELEY
end_ifdef

begin_decl_stmt
name|struct
name|parsetab
name|ParseTab
index|[]
init|=
block|{
literal|':'
block|,
name|M_BERK
block|,
name|P_ONE
block|,
name|NULL
block|,
ifdef|#
directive|ifdef
name|HASARPA
literal|'@'
block|,
name|M_ARPA
block|,
name|P_HLAST
operator||
name|P_USR_UPPER
block|,
name|NULL
block|,
else|#
directive|else
literal|'@'
block|,
name|M_BERK
block|,
name|P_HLAST
operator||
name|P_USR_UPPER
operator||
name|P_MOVE
block|,
literal|"ing70"
block|,
endif|#
directive|endif
endif|HASARPA
literal|'^'
block|,
operator|-
literal|1
block|,
name|P_MAP
block|,
literal|"!"
block|,
ifdef|#
directive|ifdef
name|HASUUCP
literal|'!'
block|,
name|M_UUCP
block|,
literal|0
block|,
name|NULL
block|,
else|#
directive|else
literal|'!'
block|,
name|M_BERK
block|,
name|P_MOVE
block|,
literal|"csvax"
block|,
endif|#
directive|endif
endif|HASUUCP
literal|'.'
block|,
operator|-
literal|1
block|,
name|P_MAP
operator||
name|P_ONE
block|,
literal|":"
block|,
literal|'\0'
block|,
name|M_LOCAL
block|,
name|P_MOVE
block|,
literal|""
block|, }
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
else|BERKELEY
end_else

begin_decl_stmt
name|struct
name|parsetab
name|ParseTab
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|HASARPA
literal|'@'
block|,
name|M_ARPA
block|,
name|P_HLAST
operator||
name|P_USR_UPPER
block|,
name|NULL
block|,
endif|#
directive|endif
endif|HASARPA
ifdef|#
directive|ifdef
name|HASUUCP
literal|'^'
block|,
operator|-
literal|1
block|,
name|P_MAP
block|,
literal|"!"
block|,
literal|'!'
block|,
name|M_UUCP
block|,
literal|0
block|,
name|NULL
block|,
endif|#
directive|endif
endif|HASUUCP
literal|'\0'
block|,
name|M_LOCAL
block|,
name|P_MOVE
block|,
literal|""
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|BERKELEY
end_endif

begin_comment
comment|/* **  Header info table */
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
literal|0
block|,
literal|"from"
block|,
literal|0
block|,
literal|"to"
block|,
name|H_CONCAT
block|,
literal|"cc"
block|,
name|H_CONCAT
block|,
literal|"subject"
block|,
literal|0
block|,
literal|"message-id"
block|,
literal|0
block|,
name|NULL
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* **  INITMACS -- initialize predefined macros. ** **	Parameters: **		none. ** **	Returns: **		none. ** **	Side Effects: **		Macros array gets initialized. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Macro
index|[
literal|26
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MACRO
parameter_list|(
name|x
parameter_list|)
value|Macro[x - 'A']
end_define

begin_macro
name|initmacs
argument_list|()
end_macro

begin_block
block|{
name|MACRO
argument_list|(
literal|'A'
argument_list|)
operator|=
name|ArpaHost
expr_stmt|;
name|MACRO
argument_list|(
literal|'B'
argument_list|)
operator|=
name|BerkHost
expr_stmt|;
name|MACRO
argument_list|(
literal|'U'
argument_list|)
operator|=
name|UucpHost
expr_stmt|;
block|}
end_block

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
specifier|extern
name|int
name|errno
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
name|int
name|errno
decl_stmt|;
specifier|extern
name|char
modifier|*
name|ttyname
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
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
end_function

end_unit

