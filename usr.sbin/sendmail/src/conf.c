begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1995, 1996 Eric P. Allman  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)conf.c	8.325 (Berkeley) 12/1/96"
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
file|"pathnames.h"
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* **  CONF.C -- Sendmail Configuration Tables. ** **	Defines the configuration of this installation. ** **	Configuration Variables: **		HdrInfo -- a table describing well-known header fields. **			Each entry has the field name and some flags, **			which are described in sendmail.h. ** **	Notes: **		I have tried to put almost all the reasonable **		configuration information into the configuration **		file read at runtime.  My intent is that anything **		here is a function of the version of UNIX you **		are running, or is really static -- for example **		the headers are a superset of widely used **		protocols.  If you find yourself playing with **		this file too much, you may be making a mistake! */
end_comment

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
comment|/* originator fields, most to least significant  */
block|{
literal|"resent-sender"
block|,
name|H_FROM
operator||
name|H_RESENT
block|}
block|,
block|{
literal|"resent-from"
block|,
name|H_FROM
operator||
name|H_RESENT
block|}
block|,
block|{
literal|"resent-reply-to"
block|,
name|H_FROM
operator||
name|H_RESENT
block|}
block|,
block|{
literal|"sender"
block|,
name|H_FROM
block|}
block|,
block|{
literal|"from"
block|,
name|H_FROM
block|}
block|,
block|{
literal|"reply-to"
block|,
name|H_FROM
block|}
block|,
block|{
literal|"errors-to"
block|,
name|H_FROM
operator||
name|H_ERRORSTO
block|}
block|,
block|{
literal|"full-name"
block|,
name|H_ACHECK
block|}
block|,
block|{
literal|"return-receipt-to"
block|,
name|H_RECEIPTTO
block|}
block|,
comment|/* destination fields */
block|{
literal|"to"
block|,
name|H_RCPT
block|}
block|,
block|{
literal|"resent-to"
block|,
name|H_RCPT
operator||
name|H_RESENT
block|}
block|,
block|{
literal|"cc"
block|,
name|H_RCPT
block|}
block|,
block|{
literal|"resent-cc"
block|,
name|H_RCPT
operator||
name|H_RESENT
block|}
block|,
block|{
literal|"bcc"
block|,
name|H_RCPT
operator||
name|H_BCC
block|}
block|,
block|{
literal|"resent-bcc"
block|,
name|H_RCPT
operator||
name|H_BCC
operator||
name|H_RESENT
block|}
block|,
block|{
literal|"apparently-to"
block|,
name|H_RCPT
block|}
block|,
comment|/* message identification and control */
block|{
literal|"message-id"
block|,
literal|0
block|}
block|,
block|{
literal|"resent-message-id"
block|,
name|H_RESENT
block|}
block|,
block|{
literal|"message"
block|,
name|H_EOH
block|}
block|,
block|{
literal|"text"
block|,
name|H_EOH
block|}
block|,
comment|/* date fields */
block|{
literal|"date"
block|,
literal|0
block|}
block|,
block|{
literal|"resent-date"
block|,
name|H_RESENT
block|}
block|,
comment|/* trace fields */
block|{
literal|"received"
block|,
name|H_TRACE
operator||
name|H_FORCE
block|}
block|,
block|{
literal|"x400-received"
block|,
name|H_TRACE
operator||
name|H_FORCE
block|}
block|,
block|{
literal|"via"
block|,
name|H_TRACE
operator||
name|H_FORCE
block|}
block|,
block|{
literal|"mail-from"
block|,
name|H_TRACE
operator||
name|H_FORCE
block|}
block|,
comment|/* miscellaneous fields */
block|{
literal|"comments"
block|,
name|H_FORCE
operator||
name|H_ENCODABLE
block|}
block|,
block|{
literal|"return-path"
block|,
name|H_FORCE
operator||
name|H_ACHECK
block|}
block|,
block|{
literal|"content-transfer-encoding"
block|,
name|H_CTE
block|}
block|,
block|{
literal|"content-type"
block|,
name|H_CTYPE
block|}
block|,
block|{
literal|"content-length"
block|,
name|H_ACHECK
block|}
block|,
block|{
literal|"subject"
block|,
name|H_ENCODABLE
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  Location of system files/databases/etc. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|PidFile
init|=
name|_PATH_SENDMAILPID
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stores daemon proc id */
end_comment

begin_comment
comment|/* **  Privacy values */
end_comment

begin_decl_stmt
name|struct
name|prival
name|PrivacyValues
index|[]
init|=
block|{
block|{
literal|"public"
block|,
name|PRIV_PUBLIC
block|}
block|,
block|{
literal|"needmailhelo"
block|,
name|PRIV_NEEDMAILHELO
block|}
block|,
block|{
literal|"needexpnhelo"
block|,
name|PRIV_NEEDEXPNHELO
block|}
block|,
block|{
literal|"needvrfyhelo"
block|,
name|PRIV_NEEDVRFYHELO
block|}
block|,
block|{
literal|"noexpn"
block|,
name|PRIV_NOEXPN
block|}
block|,
block|{
literal|"novrfy"
block|,
name|PRIV_NOVRFY
block|}
block|,
block|{
literal|"restrictmailq"
block|,
name|PRIV_RESTRICTMAILQ
block|}
block|,
block|{
literal|"restrictqrun"
block|,
name|PRIV_RESTRICTQRUN
block|}
block|,
block|{
literal|"authwarnings"
block|,
name|PRIV_AUTHWARNINGS
block|}
block|,
block|{
literal|"noreceipts"
block|,
name|PRIV_NORECEIPTS
block|}
block|,
block|{
literal|"goaway"
block|,
name|PRIV_GOAWAY
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  Miscellaneous stuff. */
end_comment

begin_decl_stmt
name|int
name|DtableSize
init|=
literal|50
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max open files; reset in 4.2bsd */
end_comment

begin_escape
end_escape

begin_comment
comment|/* **  SETDEFAULTS -- set default values ** **	Because of the way freezing is done, these must be initialized **	using direct code. ** **	Parameters: **		e -- the default envelope. ** **	Returns: **		none. ** **	Side Effects: **		Initializes a bunch of global variables to their **		default values. */
end_comment

begin_define
define|#
directive|define
name|MINUTES
value|* 60
end_define

begin_define
define|#
directive|define
name|HOURS
value|* 60 MINUTES
end_define

begin_define
define|#
directive|define
name|DAYS
value|* 24 HOURS
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAXRULERECURSION
end_ifndef

begin_define
define|#
directive|define
name|MAXRULERECURSION
value|50
end_define

begin_comment
comment|/* max ruleset recursion depth */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|setdefaults
parameter_list|(
name|e
parameter_list|)
specifier|register
name|ENVELOPE
modifier|*
name|e
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
specifier|extern
name|void
name|inittimeouts
parameter_list|()
function_decl|;
specifier|extern
name|void
name|setdefuser
parameter_list|()
function_decl|;
specifier|extern
name|void
name|setupmaps
parameter_list|()
function_decl|;
specifier|extern
name|void
name|setupmailers
parameter_list|()
function_decl|;
name|SpaceSub
operator|=
literal|' '
expr_stmt|;
comment|/* option B */
name|QueueLA
operator|=
literal|8
expr_stmt|;
comment|/* option x */
name|RefuseLA
operator|=
literal|12
expr_stmt|;
comment|/* option X */
name|WkRecipFact
operator|=
literal|30000L
expr_stmt|;
comment|/* option y */
name|WkClassFact
operator|=
literal|1800L
expr_stmt|;
comment|/* option z */
name|WkTimeFact
operator|=
literal|90000L
expr_stmt|;
comment|/* option Z */
name|QueueFactor
operator|=
name|WkRecipFact
operator|*
literal|20
expr_stmt|;
comment|/* option q */
name|FileMode
operator|=
operator|(
name|RealUid
operator|!=
name|geteuid
argument_list|()
operator|)
condition|?
literal|0644
else|:
literal|0600
expr_stmt|;
comment|/* option F */
name|DefUid
operator|=
literal|1
expr_stmt|;
comment|/* option u */
name|DefGid
operator|=
literal|1
expr_stmt|;
comment|/* option g */
name|CheckpointInterval
operator|=
literal|10
expr_stmt|;
comment|/* option C */
name|MaxHopCount
operator|=
literal|25
expr_stmt|;
comment|/* option h */
name|e
operator|->
name|e_sendmode
operator|=
name|SM_FORK
expr_stmt|;
comment|/* option d */
name|e
operator|->
name|e_errormode
operator|=
name|EM_PRINT
expr_stmt|;
comment|/* option e */
name|SevenBitInput
operator|=
name|FALSE
expr_stmt|;
comment|/* option 7 */
name|MaxMciCache
operator|=
literal|1
expr_stmt|;
comment|/* option k */
name|MciCacheTimeout
operator|=
literal|5
name|MINUTES
expr_stmt|;
comment|/* option K */
name|LogLevel
operator|=
literal|9
expr_stmt|;
comment|/* option L */
name|inittimeouts
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
comment|/* option r */
name|PrivacyFlags
operator|=
literal|0
expr_stmt|;
comment|/* option p */
if|#
directive|if
name|MIME8TO7
name|MimeMode
operator|=
name|MM_CVTMIME
operator||
name|MM_PASS8BIT
expr_stmt|;
comment|/* option 8 */
else|#
directive|else
name|MimeMode
operator|=
name|MM_PASS8BIT
expr_stmt|;
endif|#
directive|endif
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAXTOCLASS
condition|;
name|i
operator|++
control|)
block|{
name|TimeOuts
operator|.
name|to_q_return
index|[
name|i
index|]
operator|=
literal|5
name|DAYS
expr_stmt|;
comment|/* option T */
name|TimeOuts
operator|.
name|to_q_warning
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
comment|/* option T */
block|}
name|ServiceSwitchFile
operator|=
literal|"/etc/service.switch"
expr_stmt|;
name|ServiceCacheMaxAge
operator|=
operator|(
name|time_t
operator|)
literal|10
expr_stmt|;
name|HostsFile
operator|=
name|_PATH_HOSTS
expr_stmt|;
name|MustQuoteChars
operator|=
literal|"@,;:\\()[].'"
expr_stmt|;
name|MciInfoTimeout
operator|=
literal|30
name|MINUTES
expr_stmt|;
name|MaxRuleRecursion
operator|=
name|MAXRULERECURSION
expr_stmt|;
name|MaxAliasRecursion
operator|=
literal|10
expr_stmt|;
name|MaxMacroRecursion
operator|=
literal|10
expr_stmt|;
name|ColonOkInAddr
operator|=
name|TRUE
expr_stmt|;
name|DoubleBounceAddr
operator|=
literal|"postmaster"
expr_stmt|;
name|setdefuser
argument_list|()
expr_stmt|;
name|setupmaps
argument_list|()
expr_stmt|;
name|setupmailers
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* **  SETDEFUSER -- set/reset DefUser using DefUid (for initgroups()) */
end_comment

begin_function
name|void
name|setdefuser
parameter_list|()
block|{
name|struct
name|passwd
modifier|*
name|defpwent
decl_stmt|;
specifier|static
name|char
name|defuserbuf
index|[
literal|40
index|]
decl_stmt|;
name|DefUser
operator|=
name|defuserbuf
expr_stmt|;
name|defpwent
operator|=
name|sm_getpwuid
argument_list|(
name|DefUid
argument_list|)
expr_stmt|;
name|snprintf
argument_list|(
name|defuserbuf
argument_list|,
sizeof|sizeof
name|defuserbuf
argument_list|,
literal|"%s"
argument_list|,
name|defpwent
operator|==
name|NULL
condition|?
literal|"nobody"
else|:
name|defpwent
operator|->
name|pw_name
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  HOST_MAP_INIT -- initialize host class structures */
end_comment

begin_decl_stmt
name|bool
name|host_map_init
name|__P
argument_list|(
operator|(
name|MAP
operator|*
name|map
operator|,
name|char
operator|*
name|args
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|bool
name|host_map_init
parameter_list|(
name|map
parameter_list|,
name|args
parameter_list|)
name|MAP
modifier|*
name|map
decl_stmt|;
name|char
modifier|*
name|args
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|p
init|=
name|args
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
while|while
condition|(
name|isascii
argument_list|(
operator|*
name|p
argument_list|)
operator|&&
name|isspace
argument_list|(
operator|*
name|p
argument_list|)
condition|)
name|p
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|!=
literal|'-'
condition|)
break|break;
switch|switch
condition|(
operator|*
operator|++
name|p
condition|)
block|{
case|case
literal|'a'
case|:
name|map
operator|->
name|map_app
operator|=
operator|++
name|p
expr_stmt|;
break|break;
case|case
literal|'m'
case|:
name|map
operator|->
name|map_mflags
operator||=
name|MF_MATCHONLY
expr_stmt|;
break|break;
case|case
literal|'t'
case|:
name|map
operator|->
name|map_mflags
operator||=
name|MF_NODEFER
expr_stmt|;
break|break;
block|}
while|while
condition|(
operator|*
name|p
operator|!=
literal|'\0'
operator|&&
operator|!
operator|(
name|isascii
argument_list|(
operator|*
name|p
argument_list|)
operator|&&
name|isspace
argument_list|(
operator|*
name|p
argument_list|)
operator|)
condition|)
name|p
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|!=
literal|'\0'
condition|)
operator|*
name|p
operator|++
operator|=
literal|'\0'
expr_stmt|;
block|}
if|if
condition|(
name|map
operator|->
name|map_app
operator|!=
name|NULL
condition|)
name|map
operator|->
name|map_app
operator|=
name|newstr
argument_list|(
name|map
operator|->
name|map_app
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  SETUPMAILERS -- initialize default mailers */
end_comment

begin_function
name|void
name|setupmailers
parameter_list|()
block|{
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
specifier|extern
name|void
name|makemailer
parameter_list|()
function_decl|;
name|strcpy
argument_list|(
name|buf
argument_list|,
literal|"prog, P=/bin/sh, F=lsoDq9, T=DNS/RFC822/X-Unix, A=sh -c \201u"
argument_list|)
expr_stmt|;
name|makemailer
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|buf
argument_list|,
literal|"*file*, P=[FILE], F=lsDFMPEouq9, T=DNS/RFC822/X-Unix, A=FILE \201u"
argument_list|)
expr_stmt|;
name|makemailer
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|buf
argument_list|,
literal|"*include*, P=/dev/null, F=su, A=INCLUDE \201u"
argument_list|)
expr_stmt|;
name|makemailer
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  SETUPMAPS -- set up map classes */
end_comment

begin_define
define|#
directive|define
name|MAPDEF
parameter_list|(
name|name
parameter_list|,
name|ext
parameter_list|,
name|flags
parameter_list|,
name|parse
parameter_list|,
name|open
parameter_list|,
name|close
parameter_list|,
name|lookup
parameter_list|,
name|store
parameter_list|)
define|\
value|{ \ 		extern bool parse __P((MAP *, char *)); \ 		extern bool open __P((MAP *, int)); \ 		extern void close __P((MAP *)); \ 		extern char *lookup __P((MAP *, char *, char **, int *)); \ 		extern void store __P((MAP *, char *, char *)); \ 		s = stab(name, ST_MAPCLASS, ST_ENTER); \ 		s->s_mapclass.map_cname = name; \ 		s->s_mapclass.map_ext = ext; \ 		s->s_mapclass.map_cflags = flags; \ 		s->s_mapclass.map_parse = parse; \ 		s->s_mapclass.map_open = open; \ 		s->s_mapclass.map_close = close; \ 		s->s_mapclass.map_lookup = lookup; \ 		s->s_mapclass.map_store = store; \ 	}
end_define

begin_function
name|void
name|setupmaps
parameter_list|()
block|{
specifier|register
name|STAB
modifier|*
name|s
decl_stmt|;
ifdef|#
directive|ifdef
name|NEWDB
name|MAPDEF
argument_list|(
literal|"hash"
argument_list|,
literal|".db"
argument_list|,
name|MCF_ALIASOK
operator||
name|MCF_REBUILDABLE
argument_list|,
name|map_parseargs
argument_list|,
name|hash_map_open
argument_list|,
name|db_map_close
argument_list|,
name|db_map_lookup
argument_list|,
name|db_map_store
argument_list|)
expr_stmt|;
name|MAPDEF
argument_list|(
literal|"btree"
argument_list|,
literal|".db"
argument_list|,
name|MCF_ALIASOK
operator||
name|MCF_REBUILDABLE
argument_list|,
name|map_parseargs
argument_list|,
name|bt_map_open
argument_list|,
name|db_map_close
argument_list|,
name|db_map_lookup
argument_list|,
name|db_map_store
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NDBM
name|MAPDEF
argument_list|(
literal|"dbm"
argument_list|,
literal|".dir"
argument_list|,
name|MCF_ALIASOK
operator||
name|MCF_REBUILDABLE
argument_list|,
name|map_parseargs
argument_list|,
name|ndbm_map_open
argument_list|,
name|ndbm_map_close
argument_list|,
name|ndbm_map_lookup
argument_list|,
name|ndbm_map_store
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NIS
name|MAPDEF
argument_list|(
literal|"nis"
argument_list|,
name|NULL
argument_list|,
name|MCF_ALIASOK
argument_list|,
name|map_parseargs
argument_list|,
name|nis_map_open
argument_list|,
name|null_map_close
argument_list|,
name|nis_map_lookup
argument_list|,
name|null_map_store
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NISPLUS
name|MAPDEF
argument_list|(
literal|"nisplus"
argument_list|,
name|NULL
argument_list|,
name|MCF_ALIASOK
argument_list|,
name|map_parseargs
argument_list|,
name|nisplus_map_open
argument_list|,
name|null_map_close
argument_list|,
name|nisplus_map_lookup
argument_list|,
name|null_map_store
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LDAPMAP
name|MAPDEF
argument_list|(
literal|"ldapx"
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|ldap_map_parseargs
argument_list|,
name|ldap_map_open
argument_list|,
name|ldap_map_close
argument_list|,
name|ldap_map_lookup
argument_list|,
name|null_map_store
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HESIOD
name|MAPDEF
argument_list|(
literal|"hesiod"
argument_list|,
name|NULL
argument_list|,
name|MCF_ALIASOK
operator||
name|MCF_ALIASONLY
argument_list|,
name|map_parseargs
argument_list|,
name|hes_map_open
argument_list|,
name|null_map_close
argument_list|,
name|hes_map_lookup
argument_list|,
name|null_map_store
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|NETINFO
name|MAPDEF
argument_list|(
literal|"netinfo"
argument_list|,
name|NULL
argument_list|,
name|MCF_ALIASOK
argument_list|,
name|map_parseargs
argument_list|,
name|ni_map_open
argument_list|,
name|null_map_close
argument_list|,
name|ni_map_lookup
argument_list|,
name|null_map_store
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
literal|0
block|MAPDEF("dns", NULL, 0, 		dns_map_init, null_map_open, null_map_close, 		dns_map_lookup, null_map_store);
endif|#
directive|endif
if|#
directive|if
name|NAMED_BIND
comment|/* best MX DNS lookup */
name|MAPDEF
argument_list|(
literal|"bestmx"
argument_list|,
name|NULL
argument_list|,
name|MCF_OPTFILE
argument_list|,
name|map_parseargs
argument_list|,
name|null_map_open
argument_list|,
name|null_map_close
argument_list|,
name|bestmx_map_lookup
argument_list|,
name|null_map_store
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|MAPDEF
argument_list|(
literal|"host"
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|host_map_init
argument_list|,
name|null_map_open
argument_list|,
name|null_map_close
argument_list|,
name|host_map_lookup
argument_list|,
name|null_map_store
argument_list|)
expr_stmt|;
name|MAPDEF
argument_list|(
literal|"text"
argument_list|,
name|NULL
argument_list|,
name|MCF_ALIASOK
argument_list|,
name|map_parseargs
argument_list|,
name|text_map_open
argument_list|,
name|null_map_close
argument_list|,
name|text_map_lookup
argument_list|,
name|null_map_store
argument_list|)
expr_stmt|;
name|MAPDEF
argument_list|(
literal|"stab"
argument_list|,
name|NULL
argument_list|,
name|MCF_ALIASOK
operator||
name|MCF_ALIASONLY
argument_list|,
name|map_parseargs
argument_list|,
name|stab_map_open
argument_list|,
name|null_map_close
argument_list|,
name|stab_map_lookup
argument_list|,
name|stab_map_store
argument_list|)
expr_stmt|;
name|MAPDEF
argument_list|(
literal|"implicit"
argument_list|,
name|NULL
argument_list|,
name|MCF_ALIASOK
operator||
name|MCF_ALIASONLY
operator||
name|MCF_REBUILDABLE
argument_list|,
name|map_parseargs
argument_list|,
name|impl_map_open
argument_list|,
name|impl_map_close
argument_list|,
name|impl_map_lookup
argument_list|,
name|impl_map_store
argument_list|)
expr_stmt|;
comment|/* access to system passwd file */
name|MAPDEF
argument_list|(
literal|"user"
argument_list|,
name|NULL
argument_list|,
name|MCF_OPTFILE
argument_list|,
name|map_parseargs
argument_list|,
name|user_map_open
argument_list|,
name|null_map_close
argument_list|,
name|user_map_lookup
argument_list|,
name|null_map_store
argument_list|)
expr_stmt|;
comment|/* dequote map */
name|MAPDEF
argument_list|(
literal|"dequote"
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|dequote_init
argument_list|,
name|null_map_open
argument_list|,
name|null_map_close
argument_list|,
name|dequote_map
argument_list|,
name|null_map_store
argument_list|)
expr_stmt|;
if|#
directive|if
name|USERDB
comment|/* user database */
name|MAPDEF
argument_list|(
literal|"userdb"
argument_list|,
literal|".db"
argument_list|,
literal|0
argument_list|,
name|map_parseargs
argument_list|,
name|null_map_open
argument_list|,
name|null_map_close
argument_list|,
name|udb_map_lookup
argument_list|,
name|null_map_store
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* arbitrary programs */
name|MAPDEF
argument_list|(
literal|"program"
argument_list|,
name|NULL
argument_list|,
name|MCF_ALIASOK
argument_list|,
name|map_parseargs
argument_list|,
name|null_map_open
argument_list|,
name|null_map_close
argument_list|,
name|prog_map_lookup
argument_list|,
name|null_map_store
argument_list|)
expr_stmt|;
comment|/* sequenced maps */
name|MAPDEF
argument_list|(
literal|"sequence"
argument_list|,
name|NULL
argument_list|,
name|MCF_ALIASOK
argument_list|,
name|seq_map_parse
argument_list|,
name|null_map_open
argument_list|,
name|null_map_close
argument_list|,
name|seq_map_lookup
argument_list|,
name|seq_map_store
argument_list|)
expr_stmt|;
comment|/* switched interface to sequenced maps */
name|MAPDEF
argument_list|(
literal|"switch"
argument_list|,
name|NULL
argument_list|,
name|MCF_ALIASOK
argument_list|,
name|map_parseargs
argument_list|,
name|switch_map_open
argument_list|,
name|null_map_close
argument_list|,
name|seq_map_lookup
argument_list|,
name|seq_map_store
argument_list|)
expr_stmt|;
comment|/* null map lookup -- really for internal use only */
name|MAPDEF
argument_list|(
literal|"null"
argument_list|,
name|NULL
argument_list|,
name|MCF_ALIASOK
operator||
name|MCF_OPTFILE
argument_list|,
name|map_parseargs
argument_list|,
name|null_map_open
argument_list|,
name|null_map_close
argument_list|,
name|null_map_lookup
argument_list|,
name|null_map_store
argument_list|)
expr_stmt|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|MAPDEF
end_undef

begin_escape
end_escape

begin_comment
comment|/* **  INITHOSTMAPS -- initial host-dependent maps ** **	This should act as an interface to any local service switch **	provided by the host operating system. ** **	Parameters: **		none ** **	Returns: **		none ** **	Side Effects: **		Should define maps "host" and "users" as necessary **		for this OS.  If they are not defined, they will get **		a default value later.  It should check to make sure **		they are not defined first, since it's possible that **		the config file has provided an override. */
end_comment

begin_function
name|void
name|inithostmaps
parameter_list|()
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|int
name|nmaps
decl_stmt|;
name|char
modifier|*
name|maptype
index|[
name|MAXMAPSTACK
index|]
decl_stmt|;
name|short
name|mapreturn
index|[
name|MAXMAPACTIONS
index|]
decl_stmt|;
name|char
name|buf
index|[
name|MAXLINE
index|]
decl_stmt|;
comment|/* 	**  Set up default hosts maps. 	*/
if|#
directive|if
literal|0
block|nmaps = switch_map_find("hosts", maptype, mapreturn); 	for (i = 0; i< nmaps; i++) 	{ 		if (strcmp(maptype[i], "files") == 0&& 		    stab("hosts.files", ST_MAP, ST_FIND) == NULL) 		{ 			strcpy(buf, "hosts.files text -k 0 -v 1 /etc/hosts"); 			(void) makemapentry(buf); 		}
if|#
directive|if
name|NAMED_BIND
block|else if (strcmp(maptype[i], "dns") == 0&& 		    stab("hosts.dns", ST_MAP, ST_FIND) == NULL) 		{ 			strcpy(buf, "hosts.dns dns A"); 			(void) makemapentry(buf); 		}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NISPLUS
block|else if (strcmp(maptype[i], "nisplus") == 0&& 		    stab("hosts.nisplus", ST_MAP, ST_FIND) == NULL) 		{ 			strcpy(buf, "hosts.nisplus nisplus -k name -v address -d hosts.org_dir"); 			(void) makemapentry(buf); 		}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NIS
block|else if (strcmp(maptype[i], "nis") == 0&& 		    stab("hosts.nis", ST_MAP, ST_FIND) == NULL) 		{ 			strcpy(buf, "hosts.nis nis -d -k 0 -v 1 hosts.byname"); 			(void) makemapentry(buf); 		}
endif|#
directive|endif
if|#
directive|if
name|NETINFO
block|else if (strcmp(maptype[i], "netinfo") == 0)&& 		    stab("hosts.netinfo", ST_MAP, ST_FIND) == NULL) 		{ 			strcpy(buf, "hosts.netinfo netinfo -v name /machines"); 			(void) makemapentry(buf); 		}
endif|#
directive|endif
block|}
endif|#
directive|endif
comment|/* 	**  Make sure we have a host map. 	*/
if|if
condition|(
name|stab
argument_list|(
literal|"host"
argument_list|,
name|ST_MAP
argument_list|,
name|ST_FIND
argument_list|)
operator|==
name|NULL
condition|)
block|{
comment|/* user didn't initialize: set up host map */
name|strcpy
argument_list|(
name|buf
argument_list|,
literal|"host host"
argument_list|)
expr_stmt|;
if|#
directive|if
name|NAMED_BIND
if|if
condition|(
name|ConfigLevel
operator|>=
literal|2
condition|)
name|strcat
argument_list|(
name|buf
argument_list|,
literal|" -a."
argument_list|)
expr_stmt|;
endif|#
directive|endif
operator|(
name|void
operator|)
name|makemapentry
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
comment|/* 	**  Set up default aliases maps 	*/
name|nmaps
operator|=
name|switch_map_find
argument_list|(
literal|"aliases"
argument_list|,
name|maptype
argument_list|,
name|mapreturn
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nmaps
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|maptype
index|[
name|i
index|]
argument_list|,
literal|"files"
argument_list|)
operator|==
literal|0
operator|&&
name|stab
argument_list|(
literal|"aliases.files"
argument_list|,
name|ST_MAP
argument_list|,
name|ST_FIND
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|strcpy
argument_list|(
name|buf
argument_list|,
literal|"aliases.files null"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|makemapentry
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|NISPLUS
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|maptype
index|[
name|i
index|]
argument_list|,
literal|"nisplus"
argument_list|)
operator|==
literal|0
operator|&&
name|stab
argument_list|(
literal|"aliases.nisplus"
argument_list|,
name|ST_MAP
argument_list|,
name|ST_FIND
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|strcpy
argument_list|(
name|buf
argument_list|,
literal|"aliases.nisplus nisplus -kalias -vexpansion -d mail_aliases.org_dir"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|makemapentry
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NIS
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|maptype
index|[
name|i
index|]
argument_list|,
literal|"nis"
argument_list|)
operator|==
literal|0
operator|&&
name|stab
argument_list|(
literal|"aliases.nis"
argument_list|,
name|ST_MAP
argument_list|,
name|ST_FIND
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|strcpy
argument_list|(
name|buf
argument_list|,
literal|"aliases.nis nis -d mail.aliases"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|makemapentry
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NETINFO
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|maptype
index|[
name|i
index|]
argument_list|,
literal|"netinfo"
argument_list|)
operator|==
literal|0
operator|&&
name|stab
argument_list|(
literal|"aliases.netinfo"
argument_list|,
name|ST_MAP
argument_list|,
name|ST_FIND
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|strcpy
argument_list|(
name|buf
argument_list|,
literal|"aliases.netinfo netinfo -z, /aliases"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|makemapentry
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HESIOD
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|maptype
index|[
name|i
index|]
argument_list|,
literal|"hesiod"
argument_list|)
operator|==
literal|0
operator|&&
name|stab
argument_list|(
literal|"aliases.hesiod"
argument_list|,
name|ST_MAP
argument_list|,
name|ST_FIND
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|strcpy
argument_list|(
name|buf
argument_list|,
literal|"aliases.hesiod hesiod aliases"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|makemapentry
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
if|if
condition|(
name|stab
argument_list|(
literal|"aliases"
argument_list|,
name|ST_MAP
argument_list|,
name|ST_FIND
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|strcpy
argument_list|(
name|buf
argument_list|,
literal|"aliases switch aliases"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|makemapentry
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
literal|0
comment|/* "user" map class is a better choice */
comment|/* 	**  Set up default users maps. 	*/
block|nmaps = switch_map_find("passwd", maptype, mapreturn); 	for (i = 0; i< nmaps; i++) 	{ 		if (strcmp(maptype[i], "files") == 0&& 		    stab("users.files", ST_MAP, ST_FIND) == NULL) 		{ 			strcpy(buf, "users.files text -m -z: -k0 -v6 /etc/passwd"); 			(void) makemapentry(buf); 		}
ifdef|#
directive|ifdef
name|NISPLUS
block|else if (strcmp(maptype[i], "nisplus") == 0&& 		    stab("users.nisplus", ST_MAP, ST_FIND) == NULL) 		{ 			strcpy(buf, "users.nisplus nisplus -m -kname -vhome -d passwd.org_dir"); 			(void) makemapentry(buf); 		}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NIS
block|else if (strcmp(maptype[i], "nis") == 0&& 		    stab("users.nis", ST_MAP, ST_FIND) == NULL) 		{ 			strcpy(buf, "users.nis nis -m -d passwd.byname"); 			(void) makemapentry(buf); 		}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HESIOD
block|else if (strcmp(maptype[i], "hesiod") == 0)&& 		    stab("users.hesiod", ST_MAP, ST_FIND) == NULL) 		{ 			strcpy(buf, "users.hesiod hesiod"); 			(void) makemapentry(buf); 		}
endif|#
directive|endif
block|} 	if (stab("users", ST_MAP, ST_FIND) == NULL) 	{ 		strcpy(buf, "users switch -m passwd"); 		(void) makemapentry(buf); 	}
endif|#
directive|endif
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  SWITCH_MAP_FIND -- find the list of types associated with a map ** **	This is the system-dependent interface to the service switch. ** **	Parameters: **		service -- the name of the service of interest. **		maptype -- an out-array of strings containing the types **			of access to use for this service.  There can **			be at most MAXMAPSTACK types for a single service. **		mapreturn -- an out-array of return information bitmaps **			for the map. ** **	Returns: **		The number of map types filled in, or -1 for failure. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOLARIS
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|sony_news
argument_list|)
operator|&&
name|defined
argument_list|(
name|__svr4
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|_USE_SUN_NSSWITCH_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_USE_SUN_NSSWITCH_
end_ifdef

begin_include
include|#
directive|include
file|<nsswitch.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__osf__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__alpha
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|_USE_DEC_SVC_CONF_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_USE_DEC_SVC_CONF_
end_ifdef

begin_include
include|#
directive|include
file|<sys/svcinfo.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|switch_map_find
parameter_list|(
name|service
parameter_list|,
name|maptype
parameter_list|,
name|mapreturn
parameter_list|)
name|char
modifier|*
name|service
decl_stmt|;
name|char
modifier|*
name|maptype
index|[
name|MAXMAPSTACK
index|]
decl_stmt|;
name|short
name|mapreturn
index|[
name|MAXMAPACTIONS
index|]
decl_stmt|;
block|{
name|int
name|svcno
decl_stmt|;
ifdef|#
directive|ifdef
name|_USE_SUN_NSSWITCH_
name|struct
name|__nsw_switchconfig
modifier|*
name|nsw_conf
decl_stmt|;
name|enum
name|__nsw_parse_err
name|pserr
decl_stmt|;
name|struct
name|__nsw_lookup
modifier|*
name|lk
decl_stmt|;
specifier|static
name|struct
name|__nsw_lookup
name|lkp0
init|=
block|{
literal|"files"
block|,
block|{
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
name|NULL
block|,
name|NULL
block|}
decl_stmt|;
specifier|static
name|struct
name|__nsw_switchconfig
name|lkp_default
init|=
block|{
literal|0
block|,
literal|"sendmail"
block|,
literal|3
block|,
operator|&
name|lkp0
block|}
decl_stmt|;
for|for
control|(
name|svcno
operator|=
literal|0
init|;
name|svcno
operator|<
name|MAXMAPACTIONS
condition|;
name|svcno
operator|++
control|)
name|mapreturn
index|[
name|svcno
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|(
name|nsw_conf
operator|=
name|__nsw_getconfig
argument_list|(
name|service
argument_list|,
operator|&
name|pserr
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|lk
operator|=
name|lkp_default
operator|.
name|lookups
expr_stmt|;
else|else
name|lk
operator|=
name|nsw_conf
operator|->
name|lookups
expr_stmt|;
name|svcno
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|lk
operator|!=
name|NULL
condition|)
block|{
name|maptype
index|[
name|svcno
index|]
operator|=
name|lk
operator|->
name|service_name
expr_stmt|;
if|if
condition|(
name|lk
operator|->
name|actions
index|[
name|__NSW_NOTFOUND
index|]
operator|==
name|__NSW_RETURN
condition|)
name|mapreturn
index|[
name|MA_NOTFOUND
index|]
operator||=
literal|1
operator|<<
name|svcno
expr_stmt|;
if|if
condition|(
name|lk
operator|->
name|actions
index|[
name|__NSW_TRYAGAIN
index|]
operator|==
name|__NSW_RETURN
condition|)
name|mapreturn
index|[
name|MA_TRYAGAIN
index|]
operator||=
literal|1
operator|<<
name|svcno
expr_stmt|;
if|if
condition|(
name|lk
operator|->
name|actions
index|[
name|__NSW_UNAVAIL
index|]
operator|==
name|__NSW_RETURN
condition|)
name|mapreturn
index|[
name|MA_TRYAGAIN
index|]
operator||=
literal|1
operator|<<
name|svcno
expr_stmt|;
name|svcno
operator|++
expr_stmt|;
name|lk
operator|=
name|lk
operator|->
name|next
expr_stmt|;
block|}
return|return
name|svcno
return|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_USE_DEC_SVC_CONF_
name|struct
name|svcinfo
modifier|*
name|svcinfo
decl_stmt|;
name|int
name|svc
decl_stmt|;
for|for
control|(
name|svcno
operator|=
literal|0
init|;
name|svcno
operator|<
name|MAXMAPACTIONS
condition|;
name|svcno
operator|++
control|)
name|mapreturn
index|[
name|svcno
index|]
operator|=
literal|0
expr_stmt|;
name|svcinfo
operator|=
name|getsvc
argument_list|()
expr_stmt|;
if|if
condition|(
name|svcinfo
operator|==
name|NULL
condition|)
goto|goto
name|punt
goto|;
if|if
condition|(
name|strcmp
argument_list|(
name|service
argument_list|,
literal|"hosts"
argument_list|)
operator|==
literal|0
condition|)
name|svc
operator|=
name|SVC_HOSTS
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|service
argument_list|,
literal|"aliases"
argument_list|)
operator|==
literal|0
condition|)
name|svc
operator|=
name|SVC_ALIASES
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|service
argument_list|,
literal|"passwd"
argument_list|)
operator|==
literal|0
condition|)
name|svc
operator|=
name|SVC_PASSWD
expr_stmt|;
else|else
return|return
operator|-
literal|1
return|;
for|for
control|(
name|svcno
operator|=
literal|0
init|;
name|svcno
operator|<
name|SVC_PATHSIZE
condition|;
name|svcno
operator|++
control|)
block|{
switch|switch
condition|(
name|svcinfo
operator|->
name|svcpath
index|[
name|svc
index|]
index|[
name|svcno
index|]
condition|)
block|{
case|case
name|SVC_LOCAL
case|:
name|maptype
index|[
name|svcno
index|]
operator|=
literal|"files"
expr_stmt|;
break|break;
case|case
name|SVC_YP
case|:
name|maptype
index|[
name|svcno
index|]
operator|=
literal|"nis"
expr_stmt|;
break|break;
case|case
name|SVC_BIND
case|:
name|maptype
index|[
name|svcno
index|]
operator|=
literal|"dns"
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|SVC_HESIOD
case|case
name|SVC_HESIOD
case|:
name|maptype
index|[
name|svcno
index|]
operator|=
literal|"hesiod"
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|SVC_LAST
case|:
return|return
name|svcno
return|;
block|}
block|}
return|return
name|svcno
return|;
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_USE_SUN_NSSWITCH_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_USE_DEC_SVC_CONF_
argument_list|)
comment|/* 	**  Fall-back mechanism. 	*/
name|STAB
modifier|*
name|st
decl_stmt|;
name|time_t
name|now
init|=
name|curtime
argument_list|()
decl_stmt|;
for|for
control|(
name|svcno
operator|=
literal|0
init|;
name|svcno
operator|<
name|MAXMAPACTIONS
condition|;
name|svcno
operator|++
control|)
name|mapreturn
index|[
name|svcno
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|(
name|now
operator|-
name|ServiceCacheTime
operator|)
operator|>
operator|(
name|time_t
operator|)
name|ServiceCacheMaxAge
condition|)
block|{
comment|/* (re)read service switch */
specifier|register
name|FILE
modifier|*
name|fp
decl_stmt|;
if|if
condition|(
name|ConfigFileRead
condition|)
name|ServiceCacheTime
operator|=
name|now
expr_stmt|;
name|fp
operator|=
name|fopen
argument_list|(
name|ServiceSwitchFile
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
if|if
condition|(
name|fp
operator|!=
name|NULL
condition|)
block|{
name|char
name|buf
index|[
name|MAXLINE
index|]
decl_stmt|;
while|while
condition|(
name|fgets
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|,
name|fp
argument_list|)
operator|!=
name|NULL
condition|)
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|strpbrk
argument_list|(
name|buf
argument_list|,
literal|"#\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|!=
name|NULL
condition|)
operator|*
name|p
operator|=
literal|'\0'
expr_stmt|;
name|p
operator|=
name|strpbrk
argument_list|(
name|buf
argument_list|,
literal|" \t"
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|!=
name|NULL
condition|)
operator|*
name|p
operator|++
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|buf
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
continue|continue;
while|while
condition|(
name|isspace
argument_list|(
operator|*
name|p
argument_list|)
condition|)
name|p
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|==
literal|'\0'
condition|)
continue|continue;
comment|/* 				**  Find/allocate space for this service entry. 				**	Space for all of the service strings 				**	are allocated at once.  This means 				**	that we only have to free the first 				**	one to free all of them. 				*/
name|st
operator|=
name|stab
argument_list|(
name|buf
argument_list|,
name|ST_SERVICE
argument_list|,
name|ST_ENTER
argument_list|)
expr_stmt|;
if|if
condition|(
name|st
operator|->
name|s_service
index|[
literal|0
index|]
operator|!=
name|NULL
condition|)
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
name|st
operator|->
name|s_service
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|p
operator|=
name|newstr
argument_list|(
name|p
argument_list|)
expr_stmt|;
for|for
control|(
name|svcno
operator|=
literal|0
init|;
name|svcno
operator|<
name|MAXMAPSTACK
condition|;
control|)
block|{
if|if
condition|(
operator|*
name|p
operator|==
literal|'\0'
condition|)
break|break;
name|st
operator|->
name|s_service
index|[
name|svcno
operator|++
index|]
operator|=
name|p
expr_stmt|;
name|p
operator|=
name|strpbrk
argument_list|(
name|p
argument_list|,
literal|" \t"
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
break|break;
operator|*
name|p
operator|++
operator|=
literal|'\0'
expr_stmt|;
while|while
condition|(
name|isspace
argument_list|(
operator|*
name|p
argument_list|)
condition|)
name|p
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|svcno
operator|<
name|MAXMAPSTACK
condition|)
name|st
operator|->
name|s_service
index|[
name|svcno
index|]
operator|=
name|NULL
expr_stmt|;
block|}
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* look up entry in cache */
name|st
operator|=
name|stab
argument_list|(
name|service
argument_list|,
name|ST_SERVICE
argument_list|,
name|ST_FIND
argument_list|)
expr_stmt|;
if|if
condition|(
name|st
operator|!=
name|NULL
operator|&&
name|st
operator|->
name|s_service
index|[
literal|0
index|]
operator|!=
name|NULL
condition|)
block|{
comment|/* extract data */
name|svcno
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|svcno
operator|<
name|MAXMAPSTACK
condition|)
block|{
name|maptype
index|[
name|svcno
index|]
operator|=
name|st
operator|->
name|s_service
index|[
name|svcno
index|]
expr_stmt|;
if|if
condition|(
name|maptype
index|[
name|svcno
operator|++
index|]
operator|==
name|NULL
condition|)
break|break;
block|}
return|return
operator|--
name|svcno
return|;
block|}
endif|#
directive|endif
comment|/* if the service file doesn't work, use an absolute fallback */
name|punt
label|:
for|for
control|(
name|svcno
operator|=
literal|0
init|;
name|svcno
operator|<
name|MAXMAPACTIONS
condition|;
name|svcno
operator|++
control|)
name|mapreturn
index|[
name|svcno
index|]
operator|=
literal|0
expr_stmt|;
name|svcno
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|service
argument_list|,
literal|"aliases"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|maptype
index|[
name|svcno
operator|++
index|]
operator|=
literal|"files"
expr_stmt|;
ifdef|#
directive|ifdef
name|AUTO_NIS_ALIASES
ifdef|#
directive|ifdef
name|NISPLUS
name|maptype
index|[
name|svcno
operator|++
index|]
operator|=
literal|"nisplus"
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NIS
name|maptype
index|[
name|svcno
operator|++
index|]
operator|=
literal|"nis"
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
return|return
name|svcno
return|;
block|}
if|if
condition|(
name|strcmp
argument_list|(
name|service
argument_list|,
literal|"hosts"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|#
directive|if
name|NAMED_BIND
name|maptype
index|[
name|svcno
operator|++
index|]
operator|=
literal|"dns"
expr_stmt|;
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_USE_SUN_NSSWITCH_
argument_list|)
comment|/* SunOS */
name|maptype
index|[
name|svcno
operator|++
index|]
operator|=
literal|"nis"
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|maptype
index|[
name|svcno
operator|++
index|]
operator|=
literal|"files"
expr_stmt|;
return|return
name|svcno
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  USERNAME -- return the user id of the logged in user. ** **	Parameters: **		none. ** **	Returns: **		The login name of the logged in user. ** **	Side Effects: **		none. ** **	Notes: **		The return value is statically allocated. */
end_comment

begin_function
name|char
modifier|*
name|username
parameter_list|()
block|{
specifier|static
name|char
modifier|*
name|myname
init|=
name|NULL
decl_stmt|;
specifier|extern
name|char
modifier|*
name|getlogin
parameter_list|()
function_decl|;
specifier|register
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
comment|/* cache the result */
if|if
condition|(
name|myname
operator|==
name|NULL
condition|)
block|{
name|myname
operator|=
name|getlogin
argument_list|()
expr_stmt|;
if|if
condition|(
name|myname
operator|==
name|NULL
operator|||
name|myname
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
block|{
name|pw
operator|=
name|sm_getpwuid
argument_list|(
name|RealUid
argument_list|)
expr_stmt|;
if|if
condition|(
name|pw
operator|!=
name|NULL
condition|)
name|myname
operator|=
name|newstr
argument_list|(
name|pw
operator|->
name|pw_name
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|uid_t
name|uid
init|=
name|RealUid
decl_stmt|;
name|myname
operator|=
name|newstr
argument_list|(
name|myname
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|pw
operator|=
name|sm_getpwnam
argument_list|(
name|myname
argument_list|)
operator|)
operator|==
name|NULL
operator|||
operator|(
name|uid
operator|!=
literal|0
operator|&&
name|uid
operator|!=
name|pw
operator|->
name|pw_uid
operator|)
condition|)
block|{
name|pw
operator|=
name|sm_getpwuid
argument_list|(
name|uid
argument_list|)
expr_stmt|;
if|if
condition|(
name|pw
operator|!=
name|NULL
condition|)
name|myname
operator|=
name|newstr
argument_list|(
name|pw
operator|->
name|pw_name
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|myname
operator|==
name|NULL
operator|||
name|myname
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
block|{
name|syserr
argument_list|(
literal|"554 Who are you?"
argument_list|)
expr_stmt|;
name|myname
operator|=
literal|"postmaster"
expr_stmt|;
block|}
block|}
return|return
operator|(
name|myname
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  TTYPATH -- Get the path of the user's tty ** **	Returns the pathname of the user's tty.  Returns NULL if **	the user is not logged in or if s/he has write permission **	denied. ** **	Parameters: **		none ** **	Returns: **		pathname of the user's tty. **		NULL if not logged in or write permission denied. ** **	Side Effects: **		none. ** **	WARNING: **		Return value is in a local buffer. ** **	Called By: **		savemail */
end_comment

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
comment|/* **  CHECKCOMPAT -- check for From and To person compatible. ** **	This routine can be supplied on a per-installation basis **	to determine whether a person is allowed to send a message. **	This allows restriction of certain types of internet **	forwarding or registration of users. ** **	If the hosts are found to be incompatible, an error **	message should be given using "usrerr" and an EX_ code **	should be returned.  You can also set to->q_status to **	a DSN-style status code. ** **	EF_NO_BODY_RETN can be set in e->e_flags to suppress the **	body during the return-to-sender function; this should be done **	on huge messages.  This bit may already be set by the ESMTP **	protocol. ** **	Parameters: **		to -- the person being sent to. ** **	Returns: **		an exit status ** **	Side Effects: **		none (unless you include the usrerr stuff) */
end_comment

begin_function
name|int
name|checkcompat
parameter_list|(
name|to
parameter_list|,
name|e
parameter_list|)
specifier|register
name|ADDRESS
modifier|*
name|to
decl_stmt|;
specifier|register
name|ENVELOPE
modifier|*
name|e
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|lint
if|if
condition|(
name|to
operator|==
name|NULL
condition|)
name|to
operator|++
expr_stmt|;
endif|#
directive|endif
comment|/* lint */
if|if
condition|(
name|tTd
argument_list|(
literal|49
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"checkcompat(to=%s, from=%s)\n"
argument_list|,
name|to
operator|->
name|q_paddr
argument_list|,
name|e
operator|->
name|e_from
operator|.
name|q_paddr
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|EXAMPLE_CODE
comment|/* this code is intended as an example only */
specifier|register
name|STAB
modifier|*
name|s
decl_stmt|;
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
name|strcmp
argument_list|(
name|e
operator|->
name|e_from
operator|.
name|q_mailer
operator|->
name|m_name
argument_list|,
literal|"local"
argument_list|)
operator|!=
literal|0
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
literal|"553 No ARPA mail through this machine: see your system administration"
argument_list|)
expr_stmt|;
comment|/* e->e_flags |= EF_NO_BODY_RETN; to supress body on return */
name|to
operator|->
name|q_status
operator|=
literal|"5.7.1"
expr_stmt|;
return|return
operator|(
name|EX_UNAVAILABLE
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* EXAMPLE_CODE */
return|return
operator|(
name|EX_OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  SETSIGNAL -- set a signal handler ** **	This is essentially old BSD "signal(3)". */
end_comment

begin_function
name|sigfunc_t
name|setsignal
parameter_list|(
name|sig
parameter_list|,
name|handler
parameter_list|)
name|int
name|sig
decl_stmt|;
name|sigfunc_t
name|handler
decl_stmt|;
block|{
if|#
directive|if
name|defined
argument_list|(
name|SYS5SIGNALS
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD4_3
argument_list|)
return|return
name|signal
argument_list|(
name|sig
argument_list|,
name|handler
argument_list|)
return|;
else|#
directive|else
name|struct
name|sigaction
name|n
decl_stmt|,
name|o
decl_stmt|;
name|bzero
argument_list|(
operator|&
name|n
argument_list|,
sizeof|sizeof
name|n
argument_list|)
expr_stmt|;
if|#
directive|if
name|USE_SA_SIGACTION
name|n
operator|.
name|sa_sigaction
operator|=
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|,
name|siginfo_t
operator|*
argument_list|,
name|void
operator|*
argument_list|)
operator|)
name|handler
expr_stmt|;
name|n
operator|.
name|sa_flags
operator|=
name|SA_RESTART
operator||
name|SA_SIGINFO
expr_stmt|;
else|#
directive|else
name|n
operator|.
name|sa_handler
operator|=
name|handler
expr_stmt|;
ifdef|#
directive|ifdef
name|SA_RESTART
name|n
operator|.
name|sa_flags
operator|=
name|SA_RESTART
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
if|if
condition|(
name|sigaction
argument_list|(
name|sig
argument_list|,
operator|&
name|n
argument_list|,
operator|&
name|o
argument_list|)
operator|<
literal|0
condition|)
return|return
name|SIG_ERR
return|;
return|return
name|o
operator|.
name|sa_handler
return|;
endif|#
directive|endif
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  BLOCKSIGNAL -- hold a signal to prevent delivery ** **	Parameters: **		sig -- the signal to block. ** **	Returns: **		1 signal was previously blocked **		0 signal was not previously blocked **		-1 on failure. */
end_comment

begin_function
name|int
name|blocksignal
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|BSD4_3
ifndef|#
directive|ifndef
name|sigmask
define|#
directive|define
name|sigmask
parameter_list|(
name|s
parameter_list|)
value|(1<< ((s) - 1))
endif|#
directive|endif
return|return
operator|(
name|sigblock
argument_list|(
name|sigmask
argument_list|(
name|sig
argument_list|)
argument_list|)
operator|&
name|sigmask
argument_list|(
name|sig
argument_list|)
operator|)
operator|!=
literal|0
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|ALTOS_SYSTEM_V
name|sigfunc_t
name|handler
decl_stmt|;
name|handler
operator|=
name|sigset
argument_list|(
name|sig
argument_list|,
name|SIG_HOLD
argument_list|)
expr_stmt|;
if|if
condition|(
name|handler
operator|==
name|SIG_ERR
condition|)
return|return
operator|-
literal|1
return|;
else|else
return|return
name|handler
operator|==
name|SIG_HOLD
return|;
else|#
directive|else
name|sigset_t
name|sset
decl_stmt|,
name|oset
decl_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|sset
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
name|sset
argument_list|,
name|sig
argument_list|)
expr_stmt|;
if|if
condition|(
name|sigprocmask
argument_list|(
name|SIG_BLOCK
argument_list|,
operator|&
name|sset
argument_list|,
operator|&
name|oset
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
else|else
return|return
name|sigismember
argument_list|(
operator|&
name|oset
argument_list|,
name|sig
argument_list|)
return|;
endif|#
directive|endif
endif|#
directive|endif
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  RELEASESIGNAL -- release a held signal ** **	Parameters: **		sig -- the signal to release. ** **	Returns: **		1 signal was previously blocked **		0 signal was not previously blocked **		-1 on failure. */
end_comment

begin_function
name|int
name|releasesignal
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|BSD4_3
return|return
operator|(
name|sigsetmask
argument_list|(
name|sigblock
argument_list|(
literal|0
argument_list|)
operator|&
operator|~
name|sigmask
argument_list|(
name|sig
argument_list|)
argument_list|)
operator|&
name|sigmask
argument_list|(
name|sig
argument_list|)
operator|)
operator|!=
literal|0
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|ALTOS_SYSTEM_V
name|sigfunc_t
name|handler
decl_stmt|;
name|handler
operator|=
name|sigset
argument_list|(
name|sig
argument_list|,
name|SIG_HOLD
argument_list|)
expr_stmt|;
if|if
condition|(
name|sigrelse
argument_list|(
name|sig
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
else|else
return|return
name|handler
operator|==
name|SIG_HOLD
return|;
else|#
directive|else
name|sigset_t
name|sset
decl_stmt|,
name|oset
decl_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|sset
argument_list|)
expr_stmt|;
name|sigaddset
argument_list|(
operator|&
name|sset
argument_list|,
name|sig
argument_list|)
expr_stmt|;
if|if
condition|(
name|sigprocmask
argument_list|(
name|SIG_UNBLOCK
argument_list|,
operator|&
name|sset
argument_list|,
operator|&
name|oset
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
else|else
return|return
name|sigismember
argument_list|(
operator|&
name|oset
argument_list|,
name|sig
argument_list|)
return|;
endif|#
directive|endif
endif|#
directive|endif
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  HOLDSIGS -- arrange to hold all signals ** **	Parameters: **		none. ** **	Returns: **		none. ** **	Side Effects: **		Arranges that signals are held. */
end_comment

begin_function
name|void
name|holdsigs
parameter_list|()
block|{ }
end_function

begin_escape
end_escape

begin_comment
comment|/* **  RLSESIGS -- arrange to release all signals ** **	This undoes the effect of holdsigs. ** **	Parameters: **		none. ** **	Returns: **		none. ** **	Side Effects: **		Arranges that signals are released. */
end_comment

begin_function
name|void
name|rlsesigs
parameter_list|()
block|{ }
end_function

begin_escape
end_escape

begin_comment
comment|/* **  INIT_MD -- do machine dependent initializations ** **	Systems that have global modes that should be set should do **	them here rather than in main. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AUX_SOURCE
end_ifdef

begin_include
include|#
directive|include
file|<compat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SHARE_V1
end_if

begin_include
include|#
directive|include
file|<shares.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|init_md
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
ifdef|#
directive|ifdef
name|_AUX_SOURCE
name|setcompat
argument_list|(
name|getcompat
argument_list|()
operator||
name|COMPAT_BSDPROT
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SUN_EXTENSIONS
name|init_md_sun
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|_CONVEX_SOURCE
comment|/* keep gethostby*() from stripping the local domain name */
name|set_domain_trim_off
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|SECUREWARE
operator|||
name|defined
argument_list|(
name|_SCO_unix_
argument_list|)
name|set_auth_parameters
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|_SCO_unix_
comment|/* 	**  This is required for highest security levels (the kernel 	**  won't let it call set*uid() or run setuid binaries without 	**  it).  It may be necessary on other SECUREWARE systems. 	*/
if|if
condition|(
name|getluid
argument_list|()
operator|==
operator|-
literal|1
condition|)
name|setluid
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|VENDOR_DEFAULT
name|VendorCode
operator|=
name|VENDOR_DEFAULT
expr_stmt|;
else|#
directive|else
name|VendorCode
operator|=
name|VENDOR_BERKELEY
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  INIT_VENDOR_MACROS -- vendor-dependent macro initializations ** **	Called once, on startup. ** **	Parameters: **		e -- the global envelope. ** **	Returns: **		none. ** **	Side Effects: **		vendor-dependent. */
end_comment

begin_function
name|void
name|init_vendor_macros
parameter_list|(
name|e
parameter_list|)
specifier|register
name|ENVELOPE
modifier|*
name|e
decl_stmt|;
block|{ }
end_function

begin_escape
end_escape

begin_comment
comment|/* **  GETLA -- get the current load average ** **	This code stolen from la.c. ** **	Parameters: **		none. ** **	Returns: **		The current load average as an integer. ** **	Side Effects: **		none. */
end_comment

begin_comment
comment|/* try to guess what style of load average we have */
end_comment

begin_define
define|#
directive|define
name|LA_ZERO
value|1
end_define

begin_comment
comment|/* always return load average as zero */
end_comment

begin_define
define|#
directive|define
name|LA_INT
value|2
end_define

begin_comment
comment|/* read kmem for avenrun; interpret as long */
end_comment

begin_define
define|#
directive|define
name|LA_FLOAT
value|3
end_define

begin_comment
comment|/* read kmem for avenrun; interpret as float */
end_comment

begin_define
define|#
directive|define
name|LA_SUBR
value|4
end_define

begin_comment
comment|/* call getloadavg */
end_comment

begin_define
define|#
directive|define
name|LA_MACH
value|5
end_define

begin_comment
comment|/* MACH load averages (as on NeXT boxes) */
end_comment

begin_define
define|#
directive|define
name|LA_SHORT
value|6
end_define

begin_comment
comment|/* read kmem for avenrun; interpret as short */
end_comment

begin_define
define|#
directive|define
name|LA_PROCSTR
value|7
end_define

begin_comment
comment|/* read string ("1.17") from /proc/loadavg */
end_comment

begin_define
define|#
directive|define
name|LA_READKSYM
value|8
end_define

begin_comment
comment|/* SVR4: use MIOC_READKSYM ioctl call */
end_comment

begin_define
define|#
directive|define
name|LA_DGUX
value|9
end_define

begin_comment
comment|/* special DGUX implementation */
end_comment

begin_define
define|#
directive|define
name|LA_HPUX
value|10
end_define

begin_comment
comment|/* special HPUX implementation */
end_comment

begin_define
define|#
directive|define
name|LA_IRIX6
value|11
end_define

begin_comment
comment|/* special IRIX 6.2 implementation */
end_comment

begin_define
define|#
directive|define
name|LA_KSTAT
value|12
end_define

begin_comment
comment|/* special Solaris kstat(3k) implementation */
end_comment

begin_define
define|#
directive|define
name|LA_DEVSHORT
value|13
end_define

begin_comment
comment|/* read short from a device */
end_comment

begin_define
define|#
directive|define
name|LA_ALPHAOSF
value|14
end_define

begin_comment
comment|/* Digital UNIX (OSF/1 on Alpha) table() call */
end_comment

begin_comment
comment|/* do guesses based on general OS type */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_ZERO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FSHIFT
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|unixpc
argument_list|)
end_if

begin_define
define|#
directive|define
name|FSHIFT
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha
argument_list|)
operator|||
name|defined
argument_list|(
name|IRIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|FSHIFT
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FSHIFT
end_ifndef

begin_define
define|#
directive|define
name|FSHIFT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FSCALE
end_ifndef

begin_define
define|#
directive|define
name|FSCALE
value|(1<< FSHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LA_AVENRUN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSTEM5
end_ifdef

begin_define
define|#
directive|define
name|LA_AVENRUN
value|"avenrun"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LA_AVENRUN
value|"_avenrun"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_KMEM should be defined in<paths.h> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_KMEM
end_ifndef

begin_define
define|#
directive|define
name|_PATH_KMEM
value|"/dev/kmem"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|LA_TYPE
operator|==
name|LA_INT
operator|)
operator|||
operator|(
name|LA_TYPE
operator|==
name|LA_FLOAT
operator|)
operator|||
operator|(
name|LA_TYPE
operator|==
name|LA_SHORT
operator|)
end_if

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IRIX64
end_ifdef

begin_define
define|#
directive|define
name|nlist
value|nlist64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_UNIX should be defined in<paths.h> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UNIX
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSTEM5
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unix"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/vmunix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_AUX_SOURCE
end_ifdef

begin_decl_stmt
name|struct
name|nlist
name|Nl
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|struct
name|nlist
name|Nl
index|[]
init|=
block|{
block|{
name|LA_AVENRUN
block|}
block|,
block|{
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|X_AVENRUN
value|0
end_define

begin_function
name|int
name|getla
parameter_list|()
block|{
specifier|static
name|int
name|kmem
init|=
operator|-
literal|1
decl_stmt|;
if|#
directive|if
name|LA_TYPE
operator|==
name|LA_INT
name|long
name|avenrun
index|[
literal|3
index|]
decl_stmt|;
else|#
directive|else
if|#
directive|if
name|LA_TYPE
operator|==
name|LA_SHORT
name|short
name|avenrun
index|[
literal|3
index|]
decl_stmt|;
else|#
directive|else
name|double
name|avenrun
index|[
literal|3
index|]
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
specifier|extern
name|int
name|errno
decl_stmt|;
specifier|extern
name|off_t
name|lseek
parameter_list|()
function_decl|;
if|if
condition|(
name|kmem
operator|<
literal|0
condition|)
block|{
ifdef|#
directive|ifdef
name|_AUX_SOURCE
name|strcpy
argument_list|(
name|Nl
index|[
name|X_AVENRUN
index|]
operator|.
name|n_name
argument_list|,
name|LA_AVENRUN
argument_list|)
expr_stmt|;
name|Nl
index|[
literal|1
index|]
operator|.
name|n_name
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|_AIX3
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX4
argument_list|)
if|if
condition|(
name|knlist
argument_list|(
name|Nl
argument_list|,
literal|1
argument_list|,
sizeof|sizeof
name|Nl
index|[
literal|0
index|]
argument_list|)
operator|<
literal|0
condition|)
else|#
directive|else
if|if
condition|(
name|nlist
argument_list|(
name|_PATH_UNIX
argument_list|,
name|Nl
argument_list|)
operator|<
literal|0
condition|)
endif|#
directive|endif
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: nlist(%s): %s\n"
argument_list|,
name|_PATH_UNIX
argument_list|,
name|errstring
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|Nl
index|[
name|X_AVENRUN
index|]
operator|.
name|n_value
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: nlist(%s, %s) ==> 0\n"
argument_list|,
name|_PATH_UNIX
argument_list|,
name|LA_AVENRUN
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|NAMELISTMASK
name|Nl
index|[
name|X_AVENRUN
index|]
operator|.
name|n_value
operator|&=
name|NAMELISTMASK
expr_stmt|;
endif|#
directive|endif
name|kmem
operator|=
name|open
argument_list|(
name|_PATH_KMEM
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|kmem
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: open(/dev/kmem): %s\n"
argument_list|,
name|errstring
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
operator|(
name|void
operator|)
name|fcntl
argument_list|(
name|kmem
argument_list|,
name|F_SETFD
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|20
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: symbol address = %#lx\n"
argument_list|,
operator|(
name|u_long
operator|)
name|Nl
index|[
name|X_AVENRUN
index|]
operator|.
name|n_value
argument_list|)
expr_stmt|;
if|if
condition|(
name|lseek
argument_list|(
name|kmem
argument_list|,
operator|(
name|off_t
operator|)
name|Nl
index|[
name|X_AVENRUN
index|]
operator|.
name|n_value
argument_list|,
name|SEEK_SET
argument_list|)
operator|==
operator|-
literal|1
operator|||
name|read
argument_list|(
name|kmem
argument_list|,
operator|(
name|char
operator|*
operator|)
name|avenrun
argument_list|,
sizeof|sizeof
argument_list|(
name|avenrun
argument_list|)
argument_list|)
operator|<
sizeof|sizeof
argument_list|(
name|avenrun
argument_list|)
condition|)
block|{
comment|/* thank you Ian */
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: lseek or read: %s\n"
argument_list|,
name|errstring
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|#
directive|if
operator|(
name|LA_TYPE
operator|==
name|LA_INT
operator|)
operator|||
operator|(
name|LA_TYPE
operator|==
name|LA_SHORT
operator|)
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|5
argument_list|)
condition|)
block|{
if|#
directive|if
name|LA_TYPE
operator|==
name|LA_SHORT
name|printf
argument_list|(
literal|"getla: avenrun = %d"
argument_list|,
name|avenrun
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|15
argument_list|)
condition|)
name|printf
argument_list|(
literal|", %d, %d"
argument_list|,
name|avenrun
index|[
literal|1
index|]
argument_list|,
name|avenrun
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"getla: avenrun = %ld"
argument_list|,
name|avenrun
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|15
argument_list|)
condition|)
name|printf
argument_list|(
literal|", %ld, %ld"
argument_list|,
name|avenrun
index|[
literal|1
index|]
argument_list|,
name|avenrun
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: %d\n"
argument_list|,
call|(
name|int
call|)
argument_list|(
name|avenrun
index|[
literal|0
index|]
operator|+
name|FSCALE
operator|/
literal|2
argument_list|)
operator|>>
name|FSHIFT
argument_list|)
expr_stmt|;
return|return
operator|(
call|(
name|int
call|)
argument_list|(
name|avenrun
index|[
literal|0
index|]
operator|+
name|FSCALE
operator|/
literal|2
argument_list|)
operator|>>
name|FSHIFT
operator|)
return|;
else|#
directive|else
comment|/* LA_TYPE == LA_FLOAT */
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|5
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"getla: avenrun = %g"
argument_list|,
name|avenrun
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|15
argument_list|)
condition|)
name|printf
argument_list|(
literal|", %g, %g"
argument_list|,
name|avenrun
index|[
literal|1
index|]
argument_list|,
name|avenrun
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: %d\n"
argument_list|,
call|(
name|int
call|)
argument_list|(
name|avenrun
index|[
literal|0
index|]
operator|+
literal|0.5
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
call|(
name|int
call|)
argument_list|(
name|avenrun
index|[
literal|0
index|]
operator|+
literal|0.5
argument_list|)
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LA_TYPE == LA_INT or LA_SHORT or LA_FLOAT */
end_comment

begin_if
if|#
directive|if
name|LA_TYPE
operator|==
name|LA_READKSYM
end_if

begin_include
include|#
directive|include
file|<sys/ksym.h>
end_include

begin_macro
name|getla
argument_list|()
end_macro

begin_block
block|{
specifier|static
name|int
name|kmem
init|=
operator|-
literal|1
decl_stmt|;
name|long
name|avenrun
index|[
literal|3
index|]
decl_stmt|;
specifier|extern
name|int
name|errno
decl_stmt|;
name|struct
name|mioc_rksym
name|mirk
decl_stmt|;
if|if
condition|(
name|kmem
operator|<
literal|0
condition|)
block|{
name|kmem
operator|=
name|open
argument_list|(
literal|"/dev/kmem"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|kmem
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: open(/dev/kmem): %s\n"
argument_list|,
name|errstring
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
operator|(
name|void
operator|)
name|fcntl
argument_list|(
name|kmem
argument_list|,
name|F_SETFD
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|mirk
operator|.
name|mirk_symname
operator|=
name|LA_AVENRUN
expr_stmt|;
name|mirk
operator|.
name|mirk_buf
operator|=
name|avenrun
expr_stmt|;
name|mirk
operator|.
name|mirk_buflen
operator|=
sizeof|sizeof
argument_list|(
name|avenrun
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|kmem
argument_list|,
name|MIOC_READKSYM
argument_list|,
operator|&
name|mirk
argument_list|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: ioctl(MIOC_READKSYM) failed: %s\n"
argument_list|,
name|errstring
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|5
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"getla: avenrun = %d"
argument_list|,
name|avenrun
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|15
argument_list|)
condition|)
name|printf
argument_list|(
literal|", %d, %d"
argument_list|,
name|avenrun
index|[
literal|1
index|]
argument_list|,
name|avenrun
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: %d\n"
argument_list|,
call|(
name|int
call|)
argument_list|(
name|avenrun
index|[
literal|0
index|]
operator|+
name|FSCALE
operator|/
literal|2
argument_list|)
operator|>>
name|FSHIFT
argument_list|)
expr_stmt|;
return|return
operator|(
call|(
name|int
call|)
argument_list|(
name|avenrun
index|[
literal|0
index|]
operator|+
name|FSCALE
operator|/
literal|2
argument_list|)
operator|>>
name|FSHIFT
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LA_TYPE == LA_READKSYM */
end_comment

begin_if
if|#
directive|if
name|LA_TYPE
operator|==
name|LA_DGUX
end_if

begin_include
include|#
directive|include
file|<sys/dg_sys_info.h>
end_include

begin_function
name|int
name|getla
parameter_list|()
block|{
name|struct
name|dg_sys_info_load_info
name|load_info
decl_stmt|;
name|dg_sys_info
argument_list|(
operator|(
name|long
operator|*
operator|)
operator|&
name|load_info
argument_list|,
name|DG_SYS_INFO_LOAD_INFO_TYPE
argument_list|,
name|DG_SYS_INFO_LOAD_VERSION_0
argument_list|)
expr_stmt|;
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: %d\n"
argument_list|,
call|(
name|int
call|)
argument_list|(
name|load_info
operator|.
name|one_minute
operator|+
literal|0.5
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
call|(
name|int
call|)
argument_list|(
name|load_info
operator|.
name|one_minute
operator|+
literal|0.5
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LA_TYPE == LA_DGUX */
end_comment

begin_if
if|#
directive|if
name|LA_TYPE
operator|==
name|LA_HPUX
end_if

begin_comment
comment|/* forward declarations to keep gcc from complaining */
end_comment

begin_struct_decl
struct_decl|struct
name|pst_dynamic
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pst_status
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pst_static
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pst_vminfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pst_diskinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pst_processor
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pst_lv
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pst_swapinfo
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/pstat.h>
end_include

begin_function
name|int
name|getla
parameter_list|()
block|{
name|struct
name|pst_dynamic
name|pstd
decl_stmt|;
if|if
condition|(
name|pstat_getdynamic
argument_list|(
operator|&
name|pstd
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pst_dynamic
argument_list|)
argument_list|,
operator|(
name|size_t
operator|)
literal|1
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: %d\n"
argument_list|,
call|(
name|int
call|)
argument_list|(
name|pstd
operator|.
name|psd_avg_1_min
operator|+
literal|0.5
argument_list|)
argument_list|)
expr_stmt|;
return|return
call|(
name|int
call|)
argument_list|(
name|pstd
operator|.
name|psd_avg_1_min
operator|+
literal|0.5
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LA_TYPE == LA_HPUX */
end_comment

begin_if
if|#
directive|if
name|LA_TYPE
operator|==
name|LA_SUBR
end_if

begin_function
name|int
name|getla
parameter_list|()
block|{
name|double
name|avenrun
index|[
literal|3
index|]
decl_stmt|;
if|if
condition|(
name|getloadavg
argument_list|(
name|avenrun
argument_list|,
sizeof|sizeof
argument_list|(
name|avenrun
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|avenrun
index|[
literal|0
index|]
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|perror
argument_list|(
literal|"getla: getloadavg failed:"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: %d\n"
argument_list|,
call|(
name|int
call|)
argument_list|(
name|avenrun
index|[
literal|0
index|]
operator|+
literal|0.5
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
call|(
name|int
call|)
argument_list|(
name|avenrun
index|[
literal|0
index|]
operator|+
literal|0.5
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LA_TYPE == LA_SUBR */
end_comment

begin_if
if|#
directive|if
name|LA_TYPE
operator|==
name|LA_MACH
end_if

begin_comment
comment|/* **  This has been tested on NEXTSTEP release 2.1/3.X. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NX_CURRENT_COMPILER_RELEASE
argument_list|)
operator|&&
name|NX_CURRENT_COMPILER_RELEASE
operator|>
name|NX_COMPILER_RELEASE_3_0
end_if

begin_include
include|#
directive|include
file|<mach/mach.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<mach.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|getla
parameter_list|()
block|{
name|processor_set_t
name|default_set
decl_stmt|;
name|kern_return_t
name|error
decl_stmt|;
name|unsigned
name|int
name|info_count
decl_stmt|;
name|struct
name|processor_set_basic_info
name|info
decl_stmt|;
name|host_t
name|host
decl_stmt|;
name|error
operator|=
name|processor_set_default
argument_list|(
name|host_self
argument_list|()
argument_list|,
operator|&
name|default_set
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
name|KERN_SUCCESS
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|perror
argument_list|(
literal|"getla: processor_set_default failed:"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|info_count
operator|=
name|PROCESSOR_SET_BASIC_INFO_COUNT
expr_stmt|;
if|if
condition|(
name|processor_set_info
argument_list|(
name|default_set
argument_list|,
name|PROCESSOR_SET_BASIC_INFO
argument_list|,
operator|&
name|host
argument_list|,
operator|(
name|processor_set_info_t
operator|)
operator|&
name|info
argument_list|,
operator|&
name|info_count
argument_list|)
operator|!=
name|KERN_SUCCESS
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|perror
argument_list|(
literal|"getla: processor_set_info failed:"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: %d\n"
argument_list|,
call|(
name|int
call|)
argument_list|(
name|info
operator|.
name|load_average
operator|+
operator|(
name|LOAD_SCALE
operator|/
literal|2
operator|)
argument_list|)
operator|/
name|LOAD_SCALE
argument_list|)
expr_stmt|;
return|return
call|(
name|int
call|)
argument_list|(
name|info
operator|.
name|load_average
operator|+
operator|(
name|LOAD_SCALE
operator|/
literal|2
operator|)
argument_list|)
operator|/
name|LOAD_SCALE
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LA_TYPE == LA_MACH */
end_comment

begin_if
if|#
directive|if
name|LA_TYPE
operator|==
name|LA_PROCSTR
end_if

begin_comment
comment|/* **  Read /proc/loadavg for the load average.  This is assumed to be **  in a format like "0.15 0.12 0.06". ** **	Initially intended for Linux.  This has been in the kernel **	since at least 0.99.15. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_LOADAVG
end_ifndef

begin_define
define|#
directive|define
name|_PATH_LOADAVG
value|"/proc/loadavg"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|getla
parameter_list|()
block|{
name|double
name|avenrun
decl_stmt|;
specifier|register
name|int
name|result
decl_stmt|;
name|FILE
modifier|*
name|fp
decl_stmt|;
name|fp
operator|=
name|fopen
argument_list|(
name|_PATH_LOADAVG
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
if|if
condition|(
name|fp
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: fopen(%s): %s\n"
argument_list|,
name|_PATH_LOADAVG
argument_list|,
name|errstring
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|result
operator|=
name|fscanf
argument_list|(
name|fp
argument_list|,
literal|"%lf"
argument_list|,
operator|&
name|avenrun
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|!=
literal|1
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: fscanf() = %d: %s\n"
argument_list|,
name|result
argument_list|,
name|errstring
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla(): %.2f\n"
argument_list|,
name|avenrun
argument_list|)
expr_stmt|;
return|return
operator|(
call|(
name|int
call|)
argument_list|(
name|avenrun
operator|+
literal|0.5
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LA_TYPE == LA_PROCSTR */
end_comment

begin_if
if|#
directive|if
name|LA_TYPE
operator|==
name|LA_IRIX6
end_if

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_define
define|#
directive|define
name|X_AVENRUN
value|0
end_define

begin_decl_stmt
name|struct
name|nlist
name|Nl32
index|[]
init|=
block|{
block|{
name|LA_AVENRUN
block|}
block|,
block|{
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nlist64
name|Nl64
index|[]
init|=
block|{
block|{
name|LA_AVENRUN
block|}
block|,
block|{
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|getla
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|int
name|kmem
init|=
operator|-
literal|1
decl_stmt|;
specifier|static
enum|enum
block|{
name|getla_none
block|,
name|getla_32
block|,
name|getla_64
block|}
name|kernel_type
init|=
name|getla_none
enum|;
name|uint32_t
name|avenrun32
index|[
literal|3
index|]
decl_stmt|;
name|uint64_t
name|avenrun64
index|[
literal|3
index|]
decl_stmt|;
if|if
condition|(
name|kernel_type
operator|==
name|getla_none
condition|)
block|{
comment|/* Try 32 bit kernel ... */
name|errno
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|nlist
argument_list|(
name|_PATH_UNIX
argument_list|,
name|Nl32
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|20
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: Kernel is 32bit\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Nl32
index|[
name|X_AVENRUN
index|]
operator|.
name|n_value
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: nlist(%s, %s) ==> 0\n"
argument_list|,
name|_PATH_UNIX
argument_list|,
name|LA_AVENRUN
argument_list|)
expr_stmt|;
block|}
else|else
name|kernel_type
operator|=
name|getla_32
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|errno
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: nlist(%s): %s\n"
argument_list|,
name|_PATH_UNIX
argument_list|,
name|errstring
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|20
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: Kernel is not 32bit\n"
argument_list|)
expr_stmt|;
block|}
comment|/* Try 64 bit kernel ... */
name|errno
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|nlist64
argument_list|(
name|_PATH_UNIX
argument_list|,
name|Nl64
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|20
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: Kernel is 64bit\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Nl64
index|[
name|X_AVENRUN
index|]
operator|.
name|n_value
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: nlist(%s, %s) ==> 0\n"
argument_list|,
name|_PATH_UNIX
argument_list|,
name|LA_AVENRUN
argument_list|)
expr_stmt|;
block|}
else|else
name|kernel_type
operator|=
name|getla_64
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|errno
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: nlist64(%s): %s\n"
argument_list|,
name|_PATH_UNIX
argument_list|,
name|errstring
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|20
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: Kernel is not 64bit\n"
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|kernel_type
operator|==
name|getla_none
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: Failed to determine kernel type\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|kmem
operator|<
literal|0
condition|)
block|{
name|kmem
operator|=
name|open
argument_list|(
name|_PATH_KMEM
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|kmem
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: open(/dev/kmem): %s\n"
argument_list|,
name|errstring
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
operator|(
name|void
operator|)
name|fcntl
argument_list|(
name|kmem
argument_list|,
name|F_SETFD
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|kernel_type
condition|)
block|{
case|case
name|getla_32
case|:
if|if
condition|(
name|lseek
argument_list|(
name|kmem
argument_list|,
operator|(
name|off_t
operator|)
name|Nl32
index|[
name|X_AVENRUN
index|]
operator|.
name|n_value
argument_list|,
name|SEEK_SET
argument_list|)
operator|==
operator|-
literal|1
operator|||
name|read
argument_list|(
name|kmem
argument_list|,
operator|(
name|char
operator|*
operator|)
name|avenrun32
argument_list|,
sizeof|sizeof
argument_list|(
name|avenrun32
argument_list|)
argument_list|)
operator|<
sizeof|sizeof
argument_list|(
name|avenrun32
argument_list|)
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: lseek or read: %s\n"
argument_list|,
name|errstring
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|5
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"getla: avenrun{32} = %ld"
argument_list|,
operator|(
name|long
name|int
operator|)
name|avenrun32
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|15
argument_list|)
condition|)
name|printf
argument_list|(
literal|", %ld, %ld"
argument_list|,
operator|(
name|long
name|int
operator|)
name|avenrun32
index|[
literal|1
index|]
argument_list|,
operator|(
name|long
name|int
operator|)
name|avenrun32
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: %d\n"
argument_list|,
call|(
name|int
call|)
argument_list|(
name|avenrun32
index|[
literal|0
index|]
operator|+
name|FSCALE
operator|/
literal|2
argument_list|)
operator|>>
name|FSHIFT
argument_list|)
expr_stmt|;
return|return
operator|(
call|(
name|int
call|)
argument_list|(
name|avenrun32
index|[
literal|0
index|]
operator|+
name|FSCALE
operator|/
literal|2
argument_list|)
operator|>>
name|FSHIFT
operator|)
return|;
case|case
name|getla_64
case|:
comment|/* Using of lseek64 is perhaps overkill ... */
if|if
condition|(
name|lseek64
argument_list|(
name|kmem
argument_list|,
operator|(
name|off64_t
operator|)
name|Nl64
index|[
name|X_AVENRUN
index|]
operator|.
name|n_value
argument_list|,
name|SEEK_SET
argument_list|)
operator|==
operator|-
literal|1
operator|||
name|read
argument_list|(
name|kmem
argument_list|,
operator|(
name|char
operator|*
operator|)
name|avenrun64
argument_list|,
sizeof|sizeof
argument_list|(
name|avenrun64
argument_list|)
argument_list|)
operator|<
sizeof|sizeof
argument_list|(
name|avenrun64
argument_list|)
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: lseek64 or read: %s\n"
argument_list|,
name|errstring
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|5
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"getla: avenrun{64} = %lld"
argument_list|,
operator|(
name|long
name|long
name|int
operator|)
name|avenrun64
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|15
argument_list|)
condition|)
name|printf
argument_list|(
literal|", %lld, %lld"
argument_list|,
operator|(
name|long
name|long
name|int
operator|)
name|avenrun64
index|[
literal|1
index|]
argument_list|,
operator|(
name|long
name|long
name|int
operator|)
name|avenrun64
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: %d\n"
argument_list|,
call|(
name|int
call|)
argument_list|(
name|avenrun64
index|[
literal|0
index|]
operator|+
name|FSCALE
operator|/
literal|2
argument_list|)
operator|>>
name|FSHIFT
argument_list|)
expr_stmt|;
return|return
operator|(
call|(
name|int
call|)
argument_list|(
name|avenrun64
index|[
literal|0
index|]
operator|+
name|FSCALE
operator|/
literal|2
argument_list|)
operator|>>
name|FSHIFT
operator|)
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LA_TYPE
operator|==
name|LA_KSTAT
end_if

begin_include
include|#
directive|include
file|<kstat.h>
end_include

begin_function
name|int
name|getla
parameter_list|()
block|{
name|kstat_ctl_t
modifier|*
name|kc
decl_stmt|;
name|kstat_t
modifier|*
name|ksp
decl_stmt|;
name|kstat_named_t
modifier|*
name|ksn
decl_stmt|;
name|int
name|la
decl_stmt|;
name|kc
operator|=
name|kstat_open
argument_list|()
expr_stmt|;
if|if
condition|(
name|kc
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: kstat_open(): %s\n"
argument_list|,
name|errstring
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|ksp
operator|=
name|kstat_lookup
argument_list|(
name|kc
argument_list|,
literal|"unix"
argument_list|,
literal|0
argument_list|,
literal|"system_misc"
argument_list|)
expr_stmt|;
comment|/* NULL on error */
if|if
condition|(
name|ksp
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"getla: kstat_lookup(): %s\n"
argument_list|,
argument|errstring(errno); 		return -
literal|1
argument|; 	} 	if (kstat_read(kc, ksp, NULL)<
literal|0
argument|) 	{ 		if (tTd(
literal|3
argument|,
literal|1
argument|)) 			printf(
literal|"getla: kstat_read(): %s\n"
argument|, 				errstring(errno); 		return -
literal|1
argument|; 	} 	ksn = (kstat_named_t *) kstat_data_lookup(ksp,
literal|"avenrun_1min"
argument|); 	la = (ksn->value.ul + FSCALE/
literal|2
argument|)>> FSHIFT; 	kstat_close(kc); 	return la; }
endif|#
directive|endif
comment|/* LA_TYPE == LA_KSTAT */
if|#
directive|if
name|LA_TYPE
operator|==
name|LA_DEVSHORT
comment|/* **  Read /dev/table/avenrun for the load average.  This should contain **  three shorts for the 1, 5, and 15 minute loads.  We only read the **  first, since that's all we care about. ** **	Intended for SCO OpenServer 5. */
ifndef|#
directive|ifndef
name|_PATH_AVENRUN
define|#
directive|define
name|_PATH_AVENRUN
value|"/dev/table/avenrun"
endif|#
directive|endif
argument|int getla() { 	static int afd = -
literal|1
argument|; 	short avenrun; 	int loadav; 	int r;  	errno = EBADF;  	if (afd == -
literal|1
argument||| lseek(afd,
literal|0L
argument|, SEEK_SET) == -
literal|1
argument|) 	{ 		if (errno != EBADF) 			return -
literal|1
argument|; 		afd = open(_PATH_AVENRUN, O_RDONLY|O_SYNC); 		if (afd<
literal|0
argument|) 		{ 			syslog(LOG_ERR,
literal|"can't open %s: %m"
argument|, _PATH_AVENRUN); 			return -
literal|1
argument|; 		} 	}  	r = read(afd,&avenrun, sizeof avenrun);  	if (tTd(
literal|3
argument|,
literal|5
argument|)) 		printf(
literal|"getla: avenrun = %d\n"
argument|, avenrun); 	loadav = (int) (avenrun + FSCALE/
literal|2
argument|)>> FSHIFT; 	if (tTd(
literal|3
argument|,
literal|1
argument|)) 		printf(
literal|"getla: %d\n"
argument|, loadav); 	return loadav; }
endif|#
directive|endif
comment|/* LA_TYPE == LA_DEVSHORT */
if|#
directive|if
name|LA_TYPE
operator|==
name|LA_ALPHAOSF
include|#
directive|include
file|<sys/table.h>
argument|int getla() { 	int ave =
literal|0
argument|; 	struct tbl_loadavg tab;  	if (table(TBL_LOADAVG,
literal|0
argument|,&tab,
literal|1
argument|, sizeof(tab)) == -
literal|1
argument|) 	{ 		if (tTd(
literal|3
argument|,
literal|1
argument|)) 			printf(
literal|"getla: table %s\n"
argument|, errstring(errno)); 		return (-
literal|1
argument|); 	}  	if (tTd(
literal|3
argument|,
literal|1
argument|)) 		printf(
literal|"getla: scale = %d\n"
argument|, tab.tl_lscale);  	if (tab.tl_lscale) 		ave = (tab.tl_avenrun.l[
literal|0
argument|] + (tab.tl_lscale/
literal|2
argument|)) / tab.tl_lscale; 	else 		ave = (int) (tab.tl_avenrun.d[
literal|0
argument|] +
literal|0.5
argument|);  	if (tTd(
literal|3
argument|,
literal|1
argument|)) 		printf(
literal|"getla: %d\n"
argument|, ave);  	return ave; }
endif|#
directive|endif
if|#
directive|if
name|LA_TYPE
operator|==
name|LA_ZERO
argument|int getla() { 	if (tTd(
literal|3
argument|,
literal|1
argument|)) 		printf(
literal|"getla: ZERO\n"
argument|); 	return (
literal|0
argument|); }
endif|#
directive|endif
comment|/* LA_TYPE == LA_ZERO */
comment|/*  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Authors:  Many and varied...  */
comment|/* Non Apollo stuff removed by Don Lewis 11/15/93 */
ifndef|#
directive|ifndef
name|lint
argument|static char  rcsid[] =
literal|"@(#)$Id: getloadavg.c,v 1.16 1991/06/21 12:51:15 paul Exp $"
argument|;
endif|#
directive|endif
comment|/* !lint */
ifdef|#
directive|ifdef
name|apollo
undef|#
directive|undef
name|volatile
include|#
directive|include
file|<apollo/base.h>
comment|/* ARGSUSED */
argument|int getloadavg( call_data )      caddr_t	call_data;
comment|/* pointer to (double) return value */
argument|{      double *avenrun = (double *) call_data;      int i;      status_$t      st;      long loadav[
literal|3
argument|];      proc1_$get_loadav(loadav,&st);      *avenrun = loadav[
literal|0
argument|] / (double) (
literal|1
argument|<<
literal|16
argument|);      return(
literal|0
argument|); }
endif|#
directive|endif
comment|/* apollo */
comment|/* **  SHOULDQUEUE -- should this message be queued or sent? ** **	Compares the message cost to the load average to decide. ** **	Parameters: **		pri -- the priority of the message in question. **		ctime -- the message creation time. ** **	Returns: **		TRUE -- if this message should be queued up for the **			time being. **		FALSE -- if the load is low enough to send this message. ** **	Side Effects: **		none. */
argument|bool shouldqueue(pri, ctime) 	long pri; 	time_t ctime; { 	bool rval;  	if (tTd(
literal|3
argument|,
literal|30
argument|)) 		printf(
literal|"shouldqueue: CurrentLA=%d, pri=%ld: "
argument|, CurrentLA, pri); 	if (CurrentLA< QueueLA) 	{ 		if (tTd(
literal|3
argument|,
literal|30
argument|)) 			printf(
literal|"FALSE (CurrentLA< QueueLA)\n"
argument|); 		return (FALSE); 	}
if|#
directive|if
literal|0
comment|/* this code is reported to cause oscillation around RefuseLA */
argument|if (CurrentLA>= RefuseLA&& QueueLA< RefuseLA) 	{ 		if (tTd(3, 30)) 			printf("TRUE (CurrentLA>= RefuseLA)\n"); 		return (TRUE); 	}
endif|#
directive|endif
argument|rval = pri> (QueueFactor / (CurrentLA - QueueLA +
literal|1
argument|)); 	if (tTd(
literal|3
argument|,
literal|30
argument|)) 		printf(
literal|"%s (by calculation)\n"
argument|, rval ?
literal|"TRUE"
argument|:
literal|"FALSE"
argument|); 	return rval; }
comment|/* **  REFUSECONNECTIONS -- decide if connections should be refused ** **	Parameters: **		port -- port number (for error messages only) ** **	Returns: **		TRUE if incoming SMTP connections should be refused **			(for now). **		FALSE if we should accept new work. ** **	Side Effects: **		Sets process title when it is rejecting connections. */
argument|bool refuseconnections(port) 	int port; { 	time_t now; 	static time_t lastconn = (time_t)
literal|0
argument|; 	static int conncnt =
literal|0
argument|; 	extern bool enoughdiskspace(); 	extern void setproctitle __P((const char *, ...));
ifdef|#
directive|ifdef
name|XLA
argument|if (!xla_smtp_ok()) 		return TRUE;
endif|#
directive|endif
argument|now = curtime(); 	if (now != lastconn) 	{ 		lastconn = now; 		conncnt =
literal|0
argument|; 	} 	else if (conncnt++> ConnRateThrottle&& ConnRateThrottle>
literal|0
argument|) 	{
comment|/* sleep to flatten out connection load */
argument|setproctitle(
literal|"deferring connections on port %d: %d per second"
argument|, 			port, ConnRateThrottle);
ifdef|#
directive|ifdef
name|LOG
argument|if (LogLevel>=
literal|14
argument|) 			syslog(LOG_INFO,
literal|"deferring connections on port %d: %d per second"
argument|, 				port, ConnRateThrottle);
endif|#
directive|endif
argument|sleep(
literal|1
argument|); 	}  	CurrentLA = getla(); 	if (CurrentLA>= RefuseLA) 	{ 		setproctitle(
literal|"rejecting connections on port %d: load average: %d"
argument|, 			port, CurrentLA);
ifdef|#
directive|ifdef
name|LOG
argument|if (LogLevel>=
literal|14
argument|) 			syslog(LOG_INFO,
literal|"rejecting connections on port %d: load average: %d"
argument|, 				port, CurrentLA);
endif|#
directive|endif
argument|return TRUE; 	}  	if (!enoughdiskspace(MinBlocksFree +
literal|1
argument|)) 	{ 		setproctitle(
literal|"rejecting connections on port %d: min free: %d"
argument|, 			port, MinBlocksFree);
ifdef|#
directive|ifdef
name|LOG
argument|if (LogLevel>=
literal|14
argument|) 			syslog(LOG_INFO,
literal|"rejecting connections on port %d: min free: %d"
argument|, 				port, MinBlocksFree);
endif|#
directive|endif
argument|return TRUE; 	}  	if (MaxChildren>
literal|0
argument|&& CurChildren>= MaxChildren) 	{ 		extern void proc_list_probe __P((void));  		proc_list_probe(); 		if (CurChildren>= MaxChildren) 		{ 			setproctitle(
literal|"rejecting connections on port %d: %d children, max %d"
argument|, 				port, CurChildren, MaxChildren);
ifdef|#
directive|ifdef
name|LOG
argument|if (LogLevel>=
literal|14
argument|) 				syslog(LOG_INFO,
literal|"rejecting connections on port %d: %d children, max %d"
argument|, 					port, CurChildren, MaxChildren);
endif|#
directive|endif
argument|return TRUE; 		} 	}  	return FALSE; }
comment|/* **  SETPROCTITLE -- set process title for ps ** **	Parameters: **		fmt -- a printf style format string. **		a, b, c -- possible parameters to fmt. ** **	Returns: **		none. ** **	Side Effects: **		Clobbers argv of our main procedure so ps(1) will **		display the title. */
define|#
directive|define
name|SPT_NONE
value|0
comment|/* don't use it at all */
define|#
directive|define
name|SPT_REUSEARGV
value|1
comment|/* cover argv with title information */
define|#
directive|define
name|SPT_BUILTIN
value|2
comment|/* use libc builtin */
define|#
directive|define
name|SPT_PSTAT
value|3
comment|/* use pstat(PSTAT_SETCMD, ...) */
define|#
directive|define
name|SPT_PSSTRINGS
value|4
comment|/* use PS_STRINGS->... */
define|#
directive|define
name|SPT_SYSMIPS
value|5
comment|/* use sysmips() supported by NEWS-OS 6 */
define|#
directive|define
name|SPT_SCO
value|6
comment|/* write kernel u. area */
ifndef|#
directive|ifndef
name|SPT_TYPE
define|#
directive|define
name|SPT_TYPE
value|SPT_REUSEARGV
endif|#
directive|endif
if|#
directive|if
name|SPT_TYPE
operator|!=
name|SPT_NONE
operator|&&
name|SPT_TYPE
operator|!=
name|SPT_BUILTIN
if|#
directive|if
name|SPT_TYPE
operator|==
name|SPT_PSTAT
include|#
directive|include
file|<sys/pstat.h>
endif|#
directive|endif
if|#
directive|if
name|SPT_TYPE
operator|==
name|SPT_PSSTRINGS
include|#
directive|include
file|<machine/vmparam.h>
include|#
directive|include
file|<sys/exec.h>
ifndef|#
directive|ifndef
name|PS_STRINGS
comment|/* hmmmm....  apparently not available after all */
undef|#
directive|undef
name|SPT_TYPE
define|#
directive|define
name|SPT_TYPE
value|SPT_REUSEARGV
else|#
directive|else
ifndef|#
directive|ifndef
name|NKPDE
comment|/* FreeBSD 2.0 */
define|#
directive|define
name|NKPDE
value|63
argument|typedef unsigned int	*pt_entry_t;
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
name|SPT_TYPE
operator|==
name|SPT_PSSTRINGS
define|#
directive|define
name|SETPROC_STATIC
value|static
else|#
directive|else
define|#
directive|define
name|SETPROC_STATIC
endif|#
directive|endif
if|#
directive|if
name|SPT_TYPE
operator|==
name|SPT_SYSMIPS
include|#
directive|include
file|<sys/sysmips.h>
include|#
directive|include
file|<sys/sysnews.h>
endif|#
directive|endif
if|#
directive|if
name|SPT_TYPE
operator|==
name|SPT_SCO
include|#
directive|include
file|<sys/immu.h>
include|#
directive|include
file|<sys/dir.h>
include|#
directive|include
file|<sys/user.h>
include|#
directive|include
file|<sys/fs/s5param.h>
if|#
directive|if
name|PSARGSZ
operator|>
name|MAXLINE
define|#
directive|define
name|SPT_BUFSIZE
value|PSARGSZ
endif|#
directive|endif
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SPT_PADCHAR
define|#
directive|define
name|SPT_PADCHAR
value|' '
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SPT_BUFSIZE
define|#
directive|define
name|SPT_BUFSIZE
value|MAXLINE
endif|#
directive|endif
endif|#
directive|endif
comment|/* SPT_TYPE != SPT_NONE&& SPT_TYPE != SPT_BUILTIN */
comment|/* **  Pointers for setproctitle. **	This allows "ps" listings to give more useful information. */
argument|char		**Argv = NULL;
comment|/* pointer to argument vector */
argument|char		*LastArgv = NULL;
comment|/* end of argv */
argument|void initsetproctitle(argc, argv, envp) 	int argc; 	char **argv; 	char **envp; { 	register int i; 	extern char **environ;
comment|/*         **  Move the environment so setproctitle can use the space at 	**  the top of memory. 	*/
argument|for (i =
literal|0
argument|; envp[i] != NULL; i++) 		continue; 	environ = (char **) xalloc(sizeof (char *) * (i +
literal|1
argument|)); 	for (i =
literal|0
argument|; envp[i] != NULL; i++) 		environ[i] = newstr(envp[i]); 	environ[i] = NULL;
comment|/* 	**  Save start and extent of argv for setproctitle. 	*/
argument|Argv = argv; 	if (i>
literal|0
argument|) 		LastArgv = envp[i -
literal|1
argument|] + strlen(envp[i -
literal|1
argument|]); 	else 		LastArgv = argv[argc -
literal|1
argument|] + strlen(argv[argc -
literal|1
argument|]); }
if|#
directive|if
name|SPT_TYPE
operator|!=
name|SPT_BUILTIN
comment|/*VARARGS1*/
argument|void
ifdef|#
directive|ifdef
name|__STDC__
argument|setproctitle(const char *fmt, ...)
else|#
directive|else
argument|setproctitle(fmt, va_alist) 	const char *fmt; 	va_dcl
endif|#
directive|endif
argument|{
if|#
directive|if
name|SPT_TYPE
operator|!=
name|SPT_NONE
argument|register char *p; 	register int i; 	SETPROC_STATIC char buf[SPT_BUFSIZE]; 	VA_LOCAL_DECL
if|#
directive|if
name|SPT_TYPE
operator|==
name|SPT_PSTAT
argument|union pstun pst;
endif|#
directive|endif
if|#
directive|if
name|SPT_TYPE
operator|==
name|SPT_SCO
argument|off_t seek_off; 	static int kmem = -
literal|1
argument|; 	static int kmempid = -
literal|1
argument|; 	struct user u;
endif|#
directive|endif
argument|p = buf;
comment|/* print sendmail: heading for grep */
argument|(void) strcpy(p,
literal|"sendmail: "
argument|); 	p += strlen(p);
comment|/* print the argument string */
argument|VA_START(fmt); 	(void) vsnprintf(p, SPACELEFT(buf, p), fmt, ap); 	VA_END;  	i = strlen(buf);
if|#
directive|if
name|SPT_TYPE
operator|==
name|SPT_PSTAT
argument|pst.pst_command = buf; 	pstat(PSTAT_SETCMD, pst, i,
literal|0
argument|,
literal|0
argument|);
endif|#
directive|endif
if|#
directive|if
name|SPT_TYPE
operator|==
name|SPT_PSSTRINGS
argument|PS_STRINGS->ps_nargvstr =
literal|1
argument|; 	PS_STRINGS->ps_argvstr = buf;
endif|#
directive|endif
if|#
directive|if
name|SPT_TYPE
operator|==
name|SPT_SYSMIPS
argument|sysmips(SONY_SYSNEWS, NEWS_SETPSARGS, buf);
endif|#
directive|endif
if|#
directive|if
name|SPT_TYPE
operator|==
name|SPT_SCO
argument|if (kmem<
literal|0
argument||| kmempid != getpid()) 	{ 		if (kmem>=
literal|0
argument|) 			close(kmem); 		kmem = open(_PATH_KMEM, O_RDWR,
literal|0
argument|); 		if (kmem<
literal|0
argument|) 			return; 		(void) fcntl(kmem, F_SETFD,
literal|1
argument|); 		kmempid = getpid(); 	} 	buf[PSARGSZ -
literal|1
argument|] =
literal|'\0'
argument|; 	seek_off = UVUBLK + (off_t) u.u_psargs - (off_t)&u; 	if (lseek(kmem, (off_t) seek_off, SEEK_SET) == seek_off) 		(void) write(kmem, buf, PSARGSZ);
endif|#
directive|endif
if|#
directive|if
name|SPT_TYPE
operator|==
name|SPT_REUSEARGV
argument|if (i> LastArgv - Argv[
literal|0
argument|] -
literal|2
argument|) 	{ 		i = LastArgv - Argv[
literal|0
argument|] -
literal|2
argument|; 		buf[i] =
literal|'\0'
argument|; 	} 	(void) strcpy(Argv[
literal|0
argument|], buf); 	p =&Argv[
literal|0
argument|][i]; 	while (p< LastArgv) 		*p++ = SPT_PADCHAR; 	Argv[
literal|1
argument|] = NULL;
endif|#
directive|endif
endif|#
directive|endif
comment|/* SPT_TYPE != SPT_NONE */
argument|}
endif|#
directive|endif
comment|/* SPT_TYPE != SPT_BUILTIN */
comment|/* **  REAPCHILD -- pick up the body of my child, lest it become a zombie ** **	Parameters: **		sig -- the signal that got us here (unused). ** **	Returns: **		none. ** **	Side Effects: **		Picks up extant zombies. */
argument|void reapchild(sig) 	int sig; { 	int olderrno = errno; 	pid_t pid;
ifdef|#
directive|ifdef
name|HASWAITPID
argument|auto int status; 	int count;  	count =
literal|0
argument|; 	while ((pid = waitpid(-
literal|1
argument|,&status, WNOHANG))>
literal|0
argument|) 	{ 		if (count++>
literal|1000
argument|) 		{
ifdef|#
directive|ifdef
name|LOG
argument|if (LogLevel>
literal|0
argument|) 				syslog(LOG_ALERT,
literal|"reapchild: waitpid loop: pid=%d, status=%x"
argument|, 					pid, status);
endif|#
directive|endif
argument|break; 		} 		proc_list_drop(pid); 	}
else|#
directive|else
ifdef|#
directive|ifdef
name|WNOHANG
argument|union wait status;  	while ((pid = wait3(&status, WNOHANG, (struct rusage *) NULL))>
literal|0
argument|) 		proc_list_drop(pid);
else|#
directive|else
comment|/* WNOHANG */
argument|auto int status;  	while ((pid = wait(&status))>
literal|0
argument|) 		proc_list_drop(pid);
endif|#
directive|endif
comment|/* WNOHANG */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SYS5SIGNALS
argument|(void) setsignal(SIGCHLD, reapchild);
endif|#
directive|endif
argument|errno = olderrno; }
comment|/* **  PUTENV -- emulation of putenv() in terms of setenv() ** **	Not needed on Posix-compliant systems. **	This doesn't have full Posix semantics, but it's good enough **		for sendmail. ** **	Parameter: **		env -- the environment to put. ** **	Returns: **		none. */
ifdef|#
directive|ifdef
name|NEEDPUTENV
if|#
directive|if
name|NEEDPUTENV
operator|==
literal|2
comment|/* no setenv(3) call available */
argument|int putenv(str) 	char *str; { 	char **current; 	int matchlen, envlen=
literal|0
argument|; 	char *tmp; 	char **newenv; 	static int first=
literal|1
argument|; 	extern char **environ;
comment|/* 	 * find out how much of str to match when searching 	 * for a string to replace. 	 */
argument|if ((tmp = strchr(str,
literal|'='
argument|)) == NULL || tmp == str) 		matchlen = strlen(str); 	else 		matchlen = (int) (tmp - str); 	++matchlen;
comment|/* 	 * Search for an existing string in the environment and find the 	 * length of environ.  If found, replace and exit. 	 */
argument|for (current=environ; *current; current++) { 		++envlen;  		if (strncmp(str, *current, matchlen) ==
literal|0
argument|) {
comment|/* found it, now insert the new version */
argument|*current = (char *)str; 			return(
literal|0
argument|); 		} 	}
comment|/* 	 * There wasn't already a slot so add space for a new slot. 	 * If this is our first time through, use malloc(), else realloc(). 	 */
argument|if (first) { 		newenv = (char **) malloc(sizeof(char *) * (envlen +
literal|2
argument|)); 		if (newenv == NULL) 			return(-
literal|1
argument|);  		first=
literal|0
argument|; 		(void) memcpy(newenv, environ, sizeof(char *) * envlen); 	} else { 		newenv = (char **) realloc((char *)environ, sizeof(char *) * (envlen +
literal|2
argument|)); 		if (newenv == NULL) 			return(-
literal|1
argument|); 	}
comment|/* actually add in the new entry */
argument|environ = newenv; 	environ[envlen] = (char *)str; 	environ[envlen+
literal|1
argument|] = NULL;  	return(
literal|0
argument|); }
else|#
directive|else
comment|/* implement putenv() in terms of setenv() */
argument|int putenv(env) 	char *env; { 	char *p; 	int l; 	char nbuf[
literal|100
argument|];  	p = strchr(env,
literal|'='
argument|); 	if (p == NULL) 		return
literal|0
argument|; 	l = p - env; 	if (l> sizeof nbuf -
literal|1
argument|) 		l = sizeof nbuf -
literal|1
argument|; 	bcopy(env, nbuf, l); 	nbuf[l] =
literal|'\0'
argument|; 	return setenv(nbuf, ++p,
literal|1
argument|); }
endif|#
directive|endif
endif|#
directive|endif
comment|/* **  UNSETENV -- remove a variable from the environment ** **	Not needed on newer systems. ** **	Parameters: **		name -- the string name of the environment variable to be **			deleted from the current environment. ** **	Returns: **		none. ** **	Globals: **		environ -- a pointer to the current environment. ** **	Side Effects: **		Modifies environ. */
ifndef|#
directive|ifndef
name|HASUNSETENV
argument|void unsetenv(name) 	char *name; { 	extern char **environ; 	register char **pp; 	int len = strlen(name);  	for (pp = environ; *pp != NULL; pp++) 	{ 		if (strncmp(name, *pp, len) ==
literal|0
argument|&& 		    ((*pp)[len] ==
literal|'='
argument||| (*pp)[len] ==
literal|'\0'
argument|)) 			break; 	}  	for (; *pp != NULL; pp++) 		*pp = pp[
literal|1
argument|]; }
endif|#
directive|endif
comment|/* **  GETDTABLESIZE -- return number of file descriptors ** **	Only on non-BSD systems ** **	Parameters: **		none ** **	Returns: **		size of file descriptor table ** **	Side Effects: **		none */
ifdef|#
directive|ifdef
name|SOLARIS
include|#
directive|include
file|<sys/resource.h>
endif|#
directive|endif
argument|int getdtsize() {
ifdef|#
directive|ifdef
name|RLIMIT_NOFILE
argument|struct rlimit rl;  	if (getrlimit(RLIMIT_NOFILE,&rl)>=
literal|0
argument|) 		return rl.rlim_cur;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HASGETDTABLESIZE
argument|return getdtablesize();
else|#
directive|else
ifdef|#
directive|ifdef
name|_SC_OPEN_MAX
argument|return sysconf(_SC_OPEN_MAX);
else|#
directive|else
argument|return NOFILE;
endif|#
directive|endif
endif|#
directive|endif
argument|}
comment|/* **  UNAME -- get the UUCP name of this system. */
ifndef|#
directive|ifndef
name|HASUNAME
argument|int uname(name) 	struct utsname *name; { 	FILE *file; 	char *n;  	name->nodename[
literal|0
argument|] =
literal|'\0'
argument|;
comment|/* try /etc/whoami -- one line with the node name */
argument|if ((file = fopen(
literal|"/etc/whoami"
argument|,
literal|"r"
argument|)) != NULL) 	{ 		(void) fgets(name->nodename, NODE_LENGTH +
literal|1
argument|, file); 		(void) fclose(file); 		n = strchr(name->nodename,
literal|'\n'
argument|); 		if (n != NULL) 			*n =
literal|'\0'
argument|; 		if (name->nodename[
literal|0
argument|] !=
literal|'\0'
argument|) 			return (
literal|0
argument|); 	}
comment|/* try /usr/include/whoami.h -- has a #define somewhere */
argument|if ((file = fopen(
literal|"/usr/include/whoami.h"
argument|,
literal|"r"
argument|)) != NULL) 	{ 		char buf[MAXLINE];  		while (fgets(buf, MAXLINE, file) != NULL) 			if (sscanf(buf,
literal|"#define sysname \"%*[^\"]\""
argument|, 					NODE_LENGTH, name->nodename)>
literal|0
argument|) 				break; 		(void) fclose(file); 		if (name->nodename[
literal|0
argument|] !=
literal|'\0'
argument|) 			return (
literal|0
argument|); 	}
ifdef|#
directive|ifdef
name|TRUST_POPEN
comment|/* 	**  Popen is known to have security holes. 	*/
comment|/* try uuname -l to return local name */
argument|if ((file = popen(
literal|"uuname -l"
argument|,
literal|"r"
argument|)) != NULL) 	{ 		(void) fgets(name, NODE_LENGTH +
literal|1
argument|, file); 		(void) pclose(file); 		n = strchr(name,
literal|'\n'
argument|); 		if (n != NULL) 			*n =
literal|'\0'
argument|; 		if (name->nodename[
literal|0
argument|] !=
literal|'\0'
argument|) 			return (
literal|0
argument|); 	}
endif|#
directive|endif
argument|return (-
literal|1
argument|); }
endif|#
directive|endif
comment|/* HASUNAME */
comment|/* **  INITGROUPS -- initialize groups ** **	Stub implementation for System V style systems */
ifndef|#
directive|ifndef
name|HASINITGROUPS
argument|initgroups(name, basegid) 	char *name; 	int basegid; { 	return
literal|0
argument|; }
endif|#
directive|endif
comment|/* **  SETSID -- set session id (for non-POSIX systems) */
ifndef|#
directive|ifndef
name|HASSETSID
argument|pid_t setsid __P ((void)) {
ifdef|#
directive|ifdef
name|TIOCNOTTY
argument|int fd;  	fd = open(
literal|"/dev/tty"
argument|, O_RDWR,
literal|0
argument|); 	if (fd>=
literal|0
argument|) 	{ 		(void) ioctl(fd, (int) TIOCNOTTY, (char *)
literal|0
argument|); 		(void) close(fd); 	}
endif|#
directive|endif
comment|/* TIOCNOTTY */
ifdef|#
directive|ifdef
name|SYS5SETPGRP
argument|return setpgrp();
else|#
directive|else
argument|return setpgid(
literal|0
argument|, getpid());
endif|#
directive|endif
argument|}
endif|#
directive|endif
comment|/* **  FSYNC -- dummy fsync */
ifdef|#
directive|ifdef
name|NEEDFSYNC
argument|fsync(fd) 	int fd; {
ifdef|#
directive|ifdef
name|O_SYNC
argument|return fcntl(fd, F_SETFL, O_SYNC);
else|#
directive|else
comment|/* nothing we can do */
argument|return
literal|0
argument|;
endif|#
directive|endif
argument|}
endif|#
directive|endif
comment|/* **  DGUX_INET_ADDR -- inet_addr for DG/UX ** **	Data General DG/UX version of inet_addr returns a struct in_addr **	instead of a long.  This patches things.  Only needed on versions **	prior to 5.4.3. */
ifdef|#
directive|ifdef
name|DGUX_5_4_2
undef|#
directive|undef
name|inet_addr
argument|long dgux_inet_addr(host) 	char *host; { 	struct in_addr haddr;  	haddr = inet_addr(host); 	return haddr.s_addr; }
endif|#
directive|endif
comment|/* **  GETOPT -- for old systems or systems with bogus implementations */
ifdef|#
directive|ifdef
name|NEEDGETOPT
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
comment|/* ** this version hacked to add `atend' flag to allow state machine ** to reset if invoked by the program to scan args for a 2nd time */
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
argument|static char sccsid[] =
literal|"@(#)getopt.c	4.3 (Berkeley) 3/9/86"
argument|;
endif|#
directive|endif
comment|/* LIBC_SCCS and not lint */
include|#
directive|include
file|<stdio.h>
comment|/*  * get option letter from argument vector  */
ifdef|#
directive|ifdef
name|_CONVEX_SOURCE
argument|extern int	optind, opterr, optopt; extern char	*optarg;
else|#
directive|else
argument|int	opterr =
literal|1
argument|;
comment|/* if error message should be printed */
argument|int	optind =
literal|1
argument|;
comment|/* index into parent argv vector */
argument|int	optopt =
literal|0
argument|;
comment|/* character checked for validity */
argument|char	*optarg = NULL;
comment|/* argument associated with option */
endif|#
directive|endif
define|#
directive|define
name|BADCH
value|(int)'?'
define|#
directive|define
name|EMSG
value|""
define|#
directive|define
name|tell
parameter_list|(
name|s
parameter_list|)
value|if (opterr) {fputs(*nargv,stderr);fputs(s,stderr); \ 		fputc(optopt,stderr);fputc('\n',stderr);return(BADCH);}
argument|getopt(nargc,nargv,ostr) 	int		nargc; 	char *const	*nargv; 	const char	*ostr; { 	static char	*place = EMSG;
comment|/* option letter processing */
argument|static char	atend =
literal|0
argument|; 	register char	*oli;
comment|/* option letter list index */
argument|if (atend) { 		atend =
literal|0
argument|; 		place = EMSG; 	} 	if(!*place) {
comment|/* update scanning pointer */
argument|if (optind>= nargc || *(place = nargv[optind]) !=
literal|'-'
argument||| !*++place) { 			atend++; 			return(EOF); 		} 		if (*place ==
literal|'-'
argument|) {
comment|/* found "--" */
argument|++optind; 			atend++; 			return(EOF); 		} 	}
comment|/* option letter okay? */
argument|if ((optopt = (int)*place++) == (int)
literal|':'
argument||| !(oli = strchr(ostr,optopt))) { 		if (!*place) ++optind; 		tell(
literal|": illegal option -- "
argument|); 	} 	if (oli&& *++oli !=
literal|':'
argument|) {
comment|/* don't need argument */
argument|optarg = NULL; 		if (!*place) ++optind; 	} 	else {
comment|/* need an argument */
argument|if (*place) optarg = place;
comment|/* no white space */
argument|else if (nargc<= ++optind) {
comment|/* no arg */
argument|place = EMSG; 			tell(
literal|": option requires an argument -- "
argument|); 		} 	 	else optarg = nargv[optind];
comment|/* white space */
argument|place = EMSG; 		++optind; 	} 	return(optopt);
comment|/* dump back option letter */
argument|}
endif|#
directive|endif
comment|/* **  VFPRINTF, VSPRINTF -- for old 4.3 BSD systems missing a real version */
ifdef|#
directive|ifdef
name|NEEDVPRINTF
define|#
directive|define
name|MAXARG
value|16
argument|vfprintf(fp, fmt, ap) 	FILE *fp; 	char *fmt; 	char **ap; { 	char *bp[MAXARG]; 	int i =
literal|0
argument|;  	while (*ap&& i< MAXARG) 		bp[i++] = *ap++; 	fprintf(fp, fmt, bp[
literal|0
argument|], bp[
literal|1
argument|], bp[
literal|2
argument|], bp[
literal|3
argument|], 			 bp[
literal|4
argument|], bp[
literal|5
argument|], bp[
literal|6
argument|], bp[
literal|7
argument|], 			 bp[
literal|8
argument|], bp[
literal|9
argument|], bp[
literal|10
argument|], bp[
literal|11
argument|], 			 bp[
literal|12
argument|], bp[
literal|13
argument|], bp[
literal|14
argument|], bp[
literal|15
argument|]); }  vsprintf(s, fmt, ap) 	char *s; 	char *fmt; 	char **ap; { 	char *bp[MAXARG]; 	int i =
literal|0
argument|;  	while (*ap&& i< MAXARG) 		bp[i++] = *ap++; 	sprintf(s, fmt, bp[
literal|0
argument|], bp[
literal|1
argument|], bp[
literal|2
argument|], bp[
literal|3
argument|], 			bp[
literal|4
argument|], bp[
literal|5
argument|], bp[
literal|6
argument|], bp[
literal|7
argument|], 			bp[
literal|8
argument|], bp[
literal|9
argument|], bp[
literal|10
argument|], bp[
literal|11
argument|], 			bp[
literal|12
argument|], bp[
literal|13
argument|], bp[
literal|14
argument|], bp[
literal|15
argument|]); }
endif|#
directive|endif
comment|/* **  SNPRINTF, VSNPRINT -- counted versions of printf ** **	These versions have been grabbed off the net.  They have been **	cleaned up to compile properly and support for .precision and **	%lx has been added. */
if|#
directive|if
operator|!
name|HASSNPRINTF
comment|/**************************************************************  * Original:  * Patrick Powell Tue Apr 11 09:48:21 PDT 1995  * A bombproof version of doprnt (dopr) included.  * Sigh.  This sort of thing is always nasty do deal with.  Note that  * the version here does not include floating point...  *  * snprintf() is used instead of sprintf() as it does limit checks  * for string length.  This covers a nasty loophole.  *  * The other functions are there to prevent NULL pointers from  * causing nast effects.  **************************************************************/
comment|/*static char _id[] = "$Id: snprintf.c,v 1.2 1995/10/09 11:19:47 roberto Exp $";*/
argument|static void dopr(); static char *end; static int	SnprfOverflow;
comment|/* VARARGS3 */
argument|int
ifdef|#
directive|ifdef
name|__STDC__
argument|snprintf(char *str, size_t count, const char *fmt, ...)
else|#
directive|else
argument|snprintf(str, count, fmt, va_alist) 	char *str; 	size_t count; 	const char *fmt; 	va_dcl
endif|#
directive|endif
argument|{ 	int len; 	VA_LOCAL_DECL  	VA_START(fmt); 	len = vsnprintf(str, count, fmt, ap); 	VA_END; 	return len; }
ifndef|#
directive|ifndef
name|luna2
argument|int vsnprintf(str, count, fmt, args) 	char *str; 	size_t count; 	const char *fmt; 	va_list args; { 	str[
literal|0
argument|] =
literal|0
argument|; 	end = str + count -
literal|1
argument|; 	SnprfOverflow =
literal|0
argument|; 	dopr( str, fmt, args ); 	if (count>
literal|0
argument|) 		end[
literal|0
argument|] =
literal|0
argument|; 	if (SnprfOverflow&& tTd(
literal|57
argument|,
literal|2
argument|)) 		printf(
literal|"\nvsnprintf overflow, len = %d, str = %s"
argument|, 			count, shortenstring(str,
literal|203
argument|)); 	return strlen(str); }
comment|/*  * dopr(): poor man's version of doprintf  */
argument|static void fmtstr __P((char *value, int ljust, int len, int zpad, int maxwidth)); static void fmtnum __P((long value, int base, int dosign, int ljust, int len, int zpad)); static void dostr __P(( char * , int )); static char *output; static void dopr_outch __P(( int c ));  static void dopr( buffer, format, args )        char *buffer;        const char *format;        va_list args; {        int ch;        long value;        int longflag  =
literal|0
argument|;        int pointflag =
literal|0
argument|;        int maxwidth  =
literal|0
argument|;        char *strvalue;        int ljust;        int len;        int zpad;         output = buffer;        while( (ch = *format++) ){                switch( ch ){                case
literal|'%'
argument|:                        ljust = len = zpad = maxwidth =
literal|0
argument|;                        longflag = pointflag =
literal|0
argument|;                nextch:                        ch = *format++;                        switch( ch ){                        case
literal|0
argument|:                                dostr(
literal|"**end of format**"
argument|,
literal|0
argument|);                                return;                        case
literal|'-'
argument|: ljust =
literal|1
argument|; goto nextch;                        case
literal|'0'
argument|:
comment|/* set zero padding if len not set */
argument|if(len==
literal|0
argument|&& !pointflag) zpad =
literal|'0'
argument|;                        case
literal|'1'
argument|: case
literal|'2'
argument|: case
literal|'3'
argument|:                        case
literal|'4'
argument|: case
literal|'5'
argument|: case
literal|'6'
argument|:                        case
literal|'7'
argument|: case
literal|'8'
argument|: case
literal|'9'
argument|: 			       if (pointflag) 				 maxwidth = maxwidth*
literal|10
argument|+ ch -
literal|'0'
argument|; 			       else 				 len = len*
literal|10
argument|+ ch -
literal|'0'
argument|;                                goto nextch; 		       case
literal|'*'
argument|:  			       if (pointflag) 				 maxwidth = va_arg( args, int ); 			       else 				 len = va_arg( args, int ); 			       goto nextch; 		       case
literal|'.'
argument|: pointflag =
literal|1
argument|; goto nextch;                        case
literal|'l'
argument|: longflag =
literal|1
argument|; goto nextch;                        case
literal|'u'
argument|: case
literal|'U'
argument|:
comment|/*fmtnum(value,base,dosign,ljust,len,zpad) */
argument|if( longflag ){                                        value = va_arg( args, long );                                } else {                                        value = va_arg( args, int );                                }                                fmtnum( value,
literal|10
argument|,
literal|0
argument|, ljust, len, zpad ); break;                        case
literal|'o'
argument|: case
literal|'O'
argument|:
comment|/*fmtnum(value,base,dosign,ljust,len,zpad) */
argument|if( longflag ){                                        value = va_arg( args, long );                                } else {                                        value = va_arg( args, int );                                }                                fmtnum( value,
literal|8
argument|,
literal|0
argument|, ljust, len, zpad ); break;                        case
literal|'d'
argument|: case
literal|'D'
argument|:                                if( longflag ){                                        value = va_arg( args, long );                                } else {                                        value = va_arg( args, int );                                }                                fmtnum( value,
literal|10
argument|,
literal|1
argument|, ljust, len, zpad ); break;                        case
literal|'x'
argument|:                                if( longflag ){                                        value = va_arg( args, long );                                } else {                                        value = va_arg( args, int );                                }                                fmtnum( value,
literal|16
argument|,
literal|0
argument|, ljust, len, zpad ); break;                        case
literal|'X'
argument|:                                if( longflag ){                                        value = va_arg( args, long );                                } else {                                        value = va_arg( args, int );                                }                                fmtnum( value,-
literal|16
argument|,
literal|0
argument|, ljust, len, zpad ); break;                        case
literal|'s'
argument|:                                strvalue = va_arg( args, char *); 			       if (maxwidth>
literal|0
argument||| !pointflag) { 				 if (pointflag&& len> maxwidth) 				   len = maxwidth;
comment|/* Adjust padding */
argument|fmtstr( strvalue,ljust,len,zpad, maxwidth); 			       } 			       break;                        case
literal|'c'
argument|:                                ch = va_arg( args, int );                                dopr_outch( ch ); break;                        case
literal|'%'
argument|: dopr_outch( ch ); continue;                        default:                                dostr(
literal|"???????"
argument|,
literal|0
argument|);                        }                        break;                default:                        dopr_outch( ch );                        break;                }        }        *output =
literal|0
argument|; }  static void fmtstr(  value, ljust, len, zpad, maxwidth )        char *value;        int ljust, len, zpad, maxwidth; {        int padlen, strlen;
comment|/* amount to pad */
argument|if( value ==
literal|0
argument|){                value =
literal|"<NULL>"
argument|;        }        for( strlen =
literal|0
argument|; value[strlen]; ++ strlen );
comment|/* strlen */
argument|if (strlen> maxwidth&& maxwidth) 	 strlen = maxwidth;        padlen = len - strlen;        if( padlen<
literal|0
argument|) padlen =
literal|0
argument|;        if( ljust ) padlen = -padlen;        while( padlen>
literal|0
argument|) {                dopr_outch(
literal|' '
argument|);                --padlen;        }        dostr( value, maxwidth );        while( padlen<
literal|0
argument|) {                dopr_outch(
literal|' '
argument|);                ++padlen;        } }  static void fmtnum(  value, base, dosign, ljust, len, zpad )        long value;        int base, dosign, ljust, len, zpad; {        int signvalue =
literal|0
argument|;        unsigned long uvalue;        char convert[
literal|20
argument|];        int place =
literal|0
argument|;        int padlen =
literal|0
argument|;
comment|/* amount to pad */
argument|int caps =
literal|0
argument|;
comment|/* DEBUGP(("value 0x%x, base %d, dosign %d, ljust %d, len %d, zpad %d\n",                value, base, dosign, ljust, len, zpad )); */
argument|uvalue = value;        if( dosign ){                if( value<
literal|0
argument|) {                        signvalue =
literal|'-'
argument|;                        uvalue = -value;                }        }        if( base<
literal|0
argument|){                caps =
literal|1
argument|;                base = -base;        }        do{                convert[place++] =                        (caps?
literal|"0123456789ABCDEF"
argument|:
literal|"0123456789abcdef"
argument|)                         [uvalue % (unsigned)base  ];                uvalue = (uvalue / (unsigned)base );        }while(uvalue);        convert[place] =
literal|0
argument|;        padlen = len - place;        if( padlen<
literal|0
argument|) padlen =
literal|0
argument|;        if( ljust ) padlen = -padlen;
comment|/* DEBUGP(( "str '%s', place %d, sign %c, padlen %d\n",                convert,place,signvalue,padlen)); */
argument|if( zpad&& padlen>
literal|0
argument|){                if( signvalue ){                        dopr_outch( signvalue );                        --padlen;                        signvalue =
literal|0
argument|;                }                while( padlen>
literal|0
argument|){                        dopr_outch( zpad );                        --padlen;                }        }        while( padlen>
literal|0
argument|) {                dopr_outch(
literal|' '
argument|);                --padlen;        }        if( signvalue ) dopr_outch( signvalue );        while( place>
literal|0
argument|) dopr_outch( convert[--place] );        while( padlen<
literal|0
argument|){                dopr_outch(
literal|' '
argument|);                ++padlen;        } }  static void dostr( str , cut)      char *str;      int cut; {   if (cut) {     while(*str&& cut-->
literal|0
argument|) dopr_outch(*str++);   } else {     while(*str) dopr_outch(*str++);   } }  static void dopr_outch( c )        int c; {
if|#
directive|if
literal|0
argument|if( iscntrl(c)&& c != '\n'&& c != '\t' ){                c = '@' + (c& 0x1F);                if( end == 0 || output< end )                        *output++ = '^';        }
endif|#
directive|endif
argument|if( end ==
literal|0
argument||| output< end )                *output++ = c;        else 		SnprfOverflow++; }
endif|#
directive|endif
comment|/* !luna2 */
endif|#
directive|endif
comment|/* !HASSNPRINTF */
comment|/* **  USERSHELLOK -- tell if a user's shell is ok for unrestricted use ** **	Parameters: **		user -- the name of the user we are checking. **		shell -- the user's shell from /etc/passwd ** **	Returns: **		TRUE -- if it is ok to use this for unrestricted access. **		FALSE -- if the shell is restricted. */
if|#
directive|if
operator|!
name|HASGETUSERSHELL
ifndef|#
directive|ifndef
name|_PATH_SHELLS
define|#
directive|define
name|_PATH_SHELLS
value|"/etc/shells"
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|_AIX3
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX4
argument_list|)
include|#
directive|include
file|<userconf.h>
include|#
directive|include
file|<usersec.h>
endif|#
directive|endif
argument|char	*DefaultUserShells[] = {
literal|"/bin/sh"
argument|,
comment|/* standard shell */
literal|"/usr/bin/sh"
argument|,
literal|"/bin/csh"
argument|,
comment|/* C shell */
literal|"/usr/bin/csh"
argument|,
ifdef|#
directive|ifdef
name|__hpux
ifdef|#
directive|ifdef
name|V4FS
literal|"/usr/bin/rsh"
argument|,
comment|/* restricted Bourne shell */
literal|"/usr/bin/ksh"
argument|,
comment|/* Korn shell */
literal|"/usr/bin/rksh"
argument|,
comment|/* restricted Korn shell */
literal|"/usr/bin/pam"
argument|,
literal|"/usr/bin/keysh"
argument|,
comment|/* key shell (extended Korn shell) */
literal|"/usr/bin/posix/sh"
argument|,
else|#
directive|else
literal|"/bin/rsh"
argument|,
comment|/* restricted Bourne shell */
literal|"/bin/ksh"
argument|,
comment|/* Korn shell */
literal|"/bin/rksh"
argument|,
comment|/* restricted Korn shell */
literal|"/bin/pam"
argument|,
literal|"/usr/bin/keysh"
argument|,
comment|/* key shell (extended Korn shell) */
literal|"/bin/posix/sh"
argument|,
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|_AIX3
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX4
argument_list|)
literal|"/bin/ksh"
argument|,
comment|/* Korn shell */
literal|"/usr/bin/ksh"
argument|,
literal|"/bin/tsh"
argument|,
comment|/* trusted shell */
literal|"/usr/bin/tsh"
argument|,
literal|"/bin/bsh"
argument|,
comment|/* Bourne shell */
literal|"/usr/bin/bsh"
argument|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__svr4__
literal|"/bin/ksh"
argument|,
comment|/* Korn shell */
literal|"/usr/bin/ksh"
argument|,
endif|#
directive|endif
argument|NULL };
endif|#
directive|endif
define|#
directive|define
name|WILDCARD_SHELL
value|"/SENDMAIL/ANY/SHELL/"
argument|bool usershellok(user, shell) 	char *user; 	char *shell; {
if|#
directive|if
name|HASGETUSERSHELL
argument|register char *p; 	extern char *getusershell();  	if (shell == NULL || shell[
literal|0
argument|] ==
literal|'\0'
argument||| wordinclass(user,
literal|'t'
argument|) || 	    ConfigLevel<=
literal|1
argument|) 		return TRUE;  	setusershell(); 	while ((p = getusershell()) != NULL) 		if (strcmp(p, shell) ==
literal|0
argument||| strcmp(p, WILDCARD_SHELL) ==
literal|0
argument|) 			break; 	endusershell(); 	return p != NULL;
else|#
directive|else
if|#
directive|if
name|USEGETCONFATTR
argument|auto char *v;
endif|#
directive|endif
argument|register FILE *shellf; 	char buf[MAXLINE];  	if (shell == NULL || shell[
literal|0
argument|] ==
literal|'\0'
argument||| wordinclass(user,
literal|'t'
argument|)) 		return TRUE;
if|#
directive|if
name|USEGETCONFATTR
comment|/* 	**  Naturally IBM has a "better" idea..... 	** 	**	What a crock.  This interface isn't documented, it is 	**	considered part of the security library (-ls), and it 	**	only works if you are running as root (since the list 	**	of valid shells is obviously a source of great concern). 	**	I recommend that you do NOT define USEGETCONFATTR, 	**	especially since you are going to have to set up an 	**	/etc/shells anyhow to handle the cases where getconfattr 	**	fails. 	*/
argument|if (getconfattr(SC_SYS_LOGIN, SC_SHELLS,&v, SEC_LIST) ==
literal|0
argument|&& v != NULL) 	{ 		while (*v !=
literal|'\0'
argument|) 		{ 			if (strcmp(v, shell) ==
literal|0
argument||| strcmp(v, WILDCARD_SHELL) ==
literal|0
argument|) 				return TRUE; 			v += strlen(v) +
literal|1
argument|; 		} 		return FALSE; 	}
endif|#
directive|endif
argument|shellf = fopen(_PATH_SHELLS,
literal|"r"
argument|); 	if (shellf == NULL) 	{
comment|/* no /etc/shells; see if it is one of the std shells */
argument|char **d;  		for (d = DefaultUserShells; *d != NULL; d++) 		{ 			if (strcmp(shell, *d) ==
literal|0
argument|) 				return TRUE; 		} 		return FALSE; 	}  	while (fgets(buf, sizeof buf, shellf) != NULL) 	{ 		register char *p, *q;  		p = buf; 		while (*p !=
literal|'\0'
argument|&& *p !=
literal|'#'
argument|&& *p !=
literal|'/'
argument|) 			p++; 		if (*p ==
literal|'#'
argument||| *p ==
literal|'\0'
argument|) 			continue; 		q = p; 		while (*p !=
literal|'\0'
argument|&& *p !=
literal|'#'
argument|&& !isspace(*p)) 			p++; 		*p =
literal|'\0'
argument|; 		if (strcmp(shell, q) ==
literal|0
argument||| strcmp(WILDCARD_SHELL, q) ==
literal|0
argument|) 		{ 			fclose(shellf); 			return TRUE; 		} 	} 	fclose(shellf); 	return FALSE;
endif|#
directive|endif
argument|}
comment|/* **  FREEDISKSPACE -- see how much free space is on the queue filesystem ** **	Only implemented if you have statfs. ** **	Parameters: **		dir -- the directory in question. **		bsize -- a variable into which the filesystem **			block size is stored. ** **	Returns: **		The number of bytes free on the queue filesystem. **		-1 if the statfs call fails. ** **	Side effects: **		Puts the filesystem block size into bsize. */
comment|/* statfs types */
define|#
directive|define
name|SFS_NONE
value|0
comment|/* no statfs implementation */
define|#
directive|define
name|SFS_USTAT
value|1
comment|/* use ustat */
define|#
directive|define
name|SFS_4ARGS
value|2
comment|/* use four-argument statfs call */
define|#
directive|define
name|SFS_VFS
value|3
comment|/* use<sys/vfs.h> implementation */
define|#
directive|define
name|SFS_MOUNT
value|4
comment|/* use<sys/mount.h> implementation */
define|#
directive|define
name|SFS_STATFS
value|5
comment|/* use<sys/statfs.h> implementation */
define|#
directive|define
name|SFS_STATVFS
value|6
comment|/* use<sys/statvfs.h> implementation */
ifndef|#
directive|ifndef
name|SFS_TYPE
define|#
directive|define
name|SFS_TYPE
value|SFS_NONE
endif|#
directive|endif
if|#
directive|if
name|SFS_TYPE
operator|==
name|SFS_USTAT
include|#
directive|include
file|<ustat.h>
endif|#
directive|endif
if|#
directive|if
name|SFS_TYPE
operator|==
name|SFS_4ARGS
operator|||
name|SFS_TYPE
operator|==
name|SFS_STATFS
include|#
directive|include
file|<sys/statfs.h>
endif|#
directive|endif
if|#
directive|if
name|SFS_TYPE
operator|==
name|SFS_VFS
include|#
directive|include
file|<sys/vfs.h>
endif|#
directive|endif
if|#
directive|if
name|SFS_TYPE
operator|==
name|SFS_MOUNT
include|#
directive|include
file|<sys/mount.h>
endif|#
directive|endif
if|#
directive|if
name|SFS_TYPE
operator|==
name|SFS_STATVFS
include|#
directive|include
file|<sys/statvfs.h>
endif|#
directive|endif
argument|long freediskspace(dir, bsize) 	char *dir; 	long *bsize; {
if|#
directive|if
name|SFS_TYPE
operator|!=
name|SFS_NONE
if|#
directive|if
name|SFS_TYPE
operator|==
name|SFS_USTAT
argument|struct ustat fs; 	struct stat statbuf;
define|#
directive|define
name|FSBLOCKSIZE
value|DEV_BSIZE
define|#
directive|define
name|SFS_BAVAIL
value|f_tfree
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|ultrix
argument_list|)
argument|struct fs_data fs;
define|#
directive|define
name|SFS_BAVAIL
value|fd_bfreen
define|#
directive|define
name|FSBLOCKSIZE
value|1024L
else|#
directive|else
if|#
directive|if
name|SFS_TYPE
operator|==
name|SFS_STATVFS
argument|struct statvfs fs;
define|#
directive|define
name|FSBLOCKSIZE
value|fs.f_frsize
else|#
directive|else
argument|struct statfs fs;
define|#
directive|define
name|FSBLOCKSIZE
value|fs.f_bsize
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SFS_BAVAIL
define|#
directive|define
name|SFS_BAVAIL
value|f_bavail
endif|#
directive|endif
if|#
directive|if
name|SFS_TYPE
operator|==
name|SFS_USTAT
argument|if (stat(dir,&statbuf) ==
literal|0
argument|&& ustat(statbuf.st_dev,&fs) ==
literal|0
argument|)
else|#
directive|else
if|#
directive|if
name|SFS_TYPE
operator|==
name|SFS_4ARGS
argument|if (statfs(dir,&fs, sizeof fs,
literal|0
argument|) ==
literal|0
argument|)
else|#
directive|else
if|#
directive|if
name|SFS_TYPE
operator|==
name|SFS_STATVFS
argument|if (statvfs(dir,&fs) ==
literal|0
argument|)
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|ultrix
argument_list|)
argument|if (statfs(dir,&fs)>
literal|0
argument|)
else|#
directive|else
argument|if (statfs(dir,&fs) ==
literal|0
argument|)
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
argument|{ 		if (bsize != NULL) 			*bsize = FSBLOCKSIZE; 		if (fs.SFS_BAVAIL<
literal|0
argument|) 			return
literal|0
argument|; 		else 			return fs.SFS_BAVAIL; 	}
endif|#
directive|endif
argument|return (-
literal|1
argument|); }
comment|/* **  ENOUGHDISKSPACE -- is there enough free space on the queue fs? ** **	Only implemented if you have statfs. ** **	Parameters: **		msize -- the size to check against.  If zero, we don't yet **		know how big the message will be, so just check for **		a "reasonable" amount. ** **	Returns: **		TRUE if there is enough space. **		FALSE otherwise. */
argument|bool enoughdiskspace(msize) 	long msize; { 	long bfree, bsize;  	if (MinBlocksFree<=
literal|0
argument|&& msize<=
literal|0
argument|) 	{ 		if (tTd(
literal|4
argument|,
literal|80
argument|)) 			printf(
literal|"enoughdiskspace: no threshold\n"
argument|); 		return TRUE; 	}  	if ((bfree = freediskspace(QueueDir,&bsize))>=
literal|0
argument|) 	{ 		if (tTd(
literal|4
argument|,
literal|80
argument|)) 			printf(
literal|"enoughdiskspace: bavail=%ld, need=%ld\n"
argument|, 				bfree, msize);
comment|/* convert msize to block count */
argument|msize = msize / bsize +
literal|1
argument|; 		if (MinBlocksFree>=
literal|0
argument|) 			msize += MinBlocksFree;  		if (bfree< msize) 		{
ifdef|#
directive|ifdef
name|LOG
argument|if (LogLevel>
literal|0
argument|) 				syslog(LOG_ALERT,
literal|"%s: low on space (have %ld, %s needs %ld in %s)"
argument|, 					CurEnv->e_id == NULL ?
literal|"[NOQUEUE]"
argument|: CurEnv->e_id, 					bfree, 					CurHostName == NULL ?
literal|"SMTP-DAEMON"
argument|: CurHostName, 					msize, QueueDir);
endif|#
directive|endif
argument|return FALSE; 		} 	} 	else if (tTd(
literal|4
argument|,
literal|80
argument|)) 		printf(
literal|"enoughdiskspace failure: min=%ld, need=%ld: %s\n"
argument|, 			MinBlocksFree, msize, errstring(errno)); 	return TRUE; }
comment|/* **  TRANSIENTERROR -- tell if an error code indicates a transient failure ** **	This looks at an errno value and tells if this is likely to **	go away if retried later. ** **	Parameters: **		err -- the errno code to classify. ** **	Returns: **		TRUE if this is probably transient. **		FALSE otherwise. */
argument|bool transienterror(err) 	int err; { 	switch (err) 	{ 	  case EIO:
comment|/* I/O error */
argument|case ENXIO:
comment|/* Device not configured */
argument|case EAGAIN:
comment|/* Resource temporarily unavailable */
argument|case ENOMEM:
comment|/* Cannot allocate memory */
argument|case ENODEV:
comment|/* Operation not supported by device */
argument|case ENFILE:
comment|/* Too many open files in system */
argument|case EMFILE:
comment|/* Too many open files */
argument|case ENOSPC:
comment|/* No space left on device */
ifdef|#
directive|ifdef
name|ETIMEDOUT
argument|case ETIMEDOUT:
comment|/* Connection timed out */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ESTALE
argument|case ESTALE:
comment|/* Stale NFS file handle */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ENETDOWN
argument|case ENETDOWN:
comment|/* Network is down */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ENETUNREACH
argument|case ENETUNREACH:
comment|/* Network is unreachable */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ENETRESET
argument|case ENETRESET:
comment|/* Network dropped connection on reset */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ECONNABORTED
argument|case ECONNABORTED:
comment|/* Software caused connection abort */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ECONNRESET
argument|case ECONNRESET:
comment|/* Connection reset by peer */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ENOBUFS
argument|case ENOBUFS:
comment|/* No buffer space available */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ESHUTDOWN
argument|case ESHUTDOWN:
comment|/* Can't send after socket shutdown */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ECONNREFUSED
argument|case ECONNREFUSED:
comment|/* Connection refused */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EHOSTDOWN
argument|case EHOSTDOWN:
comment|/* Host is down */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EHOSTUNREACH
argument|case EHOSTUNREACH:
comment|/* No route to host */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EDQUOT
argument|case EDQUOT:
comment|/* Disc quota exceeded */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EPROCLIM
argument|case EPROCLIM:
comment|/* Too many processes */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EUSERS
argument|case EUSERS:
comment|/* Too many users */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EDEADLK
argument|case EDEADLK:
comment|/* Resource deadlock avoided */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EISCONN
argument|case EISCONN:
comment|/* Socket already connected */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EINPROGRESS
argument|case EINPROGRESS:
comment|/* Operation now in progress */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EALREADY
argument|case EALREADY:
comment|/* Operation already in progress */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EADDRINUSE
argument|case EADDRINUSE:
comment|/* Address already in use */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EADDRNOTAVAIL
argument|case EADDRNOTAVAIL:
comment|/* Can't assign requested address */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ETXTBSY
argument|case ETXTBSY:
comment|/* (Apollo) file locked */
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|ENOSR
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|ENOBUFS
argument_list|)
operator|||
operator|(
name|ENOBUFS
operator|!=
name|ENOSR
operator|)
operator|)
argument|case ENOSR:
comment|/* Out of streams resources */
endif|#
directive|endif
argument|case EOPENTIMEOUT:
comment|/* PSEUDO: open timed out */
argument|return TRUE; 	}
comment|/* nope, must be permanent */
argument|return FALSE; }
comment|/* **  LOCKFILE -- lock a file using flock or (shudder) fcntl locking ** **	Parameters: **		fd -- the file descriptor of the file. **		filename -- the file name (for error messages). **		ext -- the filename extension. **		type -- type of the lock.  Bits can be: **			LOCK_EX -- exclusive lock. **			LOCK_NB -- non-blocking. ** **	Returns: **		TRUE if the lock was acquired. **		FALSE otherwise. */
argument|bool lockfile(fd, filename, ext, type) 	int fd; 	char *filename; 	char *ext; 	int type; {
if|#
directive|if
operator|!
name|HASFLOCK
argument|int action; 	struct flock lfd;  	if (ext == NULL) 		ext =
literal|""
argument|;  	bzero(&lfd, sizeof lfd); 	if (bitset(LOCK_UN, type)) 		lfd.l_type = F_UNLCK; 	else if (bitset(LOCK_EX, type)) 		lfd.l_type = F_WRLCK; 	else 		lfd.l_type = F_RDLCK;  	if (bitset(LOCK_NB, type)) 		action = F_SETLK; 	else 		action = F_SETLKW;  	if (tTd(
literal|55
argument|,
literal|60
argument|)) 		printf(
literal|"lockfile(%s%s, action=%d, type=%d): "
argument|, 			filename, ext, action, lfd.l_type);  	if (fcntl(fd, action,&lfd)>=
literal|0
argument|) 	{ 		if (tTd(
literal|55
argument|,
literal|60
argument|)) 			printf(
literal|"SUCCESS\n"
argument|); 		return TRUE; 	}  	if (tTd(
literal|55
argument|,
literal|60
argument|)) 		printf(
literal|"(%s) "
argument|, errstring(errno));
comment|/* 	**  On SunOS, if you are testing using -oQ/tmp/mqueue or 	**  -oA/tmp/aliases or anything like that, and /tmp is mounted 	**  as type "tmp" (that is, served from swap space), the 	**  previous fcntl will fail with "Invalid argument" errors. 	**  Since this is fairly common during testing, we will assume 	**  that this indicates that the lock is successfully grabbed. 	*/
argument|if (errno == EINVAL) 	{ 		if (tTd(
literal|55
argument|,
literal|60
argument|)) 			printf(
literal|"SUCCESS\n"
argument|); 		return TRUE; 	}  	if (!bitset(LOCK_NB, type) || (errno != EACCES&& errno != EAGAIN)) 	{ 		int omode = -
literal|1
argument|;
ifdef|#
directive|ifdef
name|F_GETFL
argument|int oerrno = errno;  		(void) fcntl(fd, F_GETFL,&omode); 		errno = oerrno;
endif|#
directive|endif
argument|syserr(
literal|"cannot lockf(%s%s, fd=%d, type=%o, omode=%o, euid=%d)"
argument|, 			filename, ext, fd, type, omode, geteuid()); 	}
else|#
directive|else
argument|if (ext == NULL) 		ext =
literal|""
argument|;  	if (tTd(
literal|55
argument|,
literal|60
argument|)) 		printf(
literal|"lockfile(%s%s, type=%o): "
argument|, filename, ext, type);  	if (flock(fd, type)>=
literal|0
argument|) 	{ 		if (tTd(
literal|55
argument|,
literal|60
argument|)) 			printf(
literal|"SUCCESS\n"
argument|); 		return TRUE; 	}  	if (tTd(
literal|55
argument|,
literal|60
argument|)) 		printf(
literal|"(%s) "
argument|, errstring(errno));  	if (!bitset(LOCK_NB, type) || errno != EWOULDBLOCK) 	{ 		int omode = -
literal|1
argument|;
ifdef|#
directive|ifdef
name|F_GETFL
argument|int oerrno = errno;  		(void) fcntl(fd, F_GETFL,&omode); 		errno = oerrno;
endif|#
directive|endif
argument|syserr(
literal|"cannot flock(%s%s, fd=%d, type=%o, omode=%o, euid=%d)"
argument|, 			filename, ext, fd, type, omode, geteuid()); 	}
endif|#
directive|endif
argument|if (tTd(
literal|55
argument|,
literal|60
argument|)) 		printf(
literal|"FAIL\n"
argument|); 	return FALSE; }
comment|/* **  CHOWNSAFE -- tell if chown is "safe" (executable only by root) ** **	Parameters: **		fd -- the file descriptor to check. ** **	Returns: **		TRUE -- if only root can chown the file to an arbitrary **			user. **		FALSE -- if an arbitrary user can give away a file. */
argument|bool chownsafe(fd) 	int fd; {
ifdef|#
directive|ifdef
name|__hpux
argument|char *s; 	int tfd; 	uid_t o_uid, o_euid; 	gid_t o_gid, o_egid; 	bool rval; 	struct stat stbuf;  	o_uid = getuid(); 	o_euid = geteuid(); 	o_gid = getgid(); 	o_egid = getegid(); 	fstat(fd,&stbuf); 	setresuid(stbuf.st_uid, stbuf.st_uid, -
literal|1
argument|); 	setresgid(stbuf.st_gid, stbuf.st_gid, -
literal|1
argument|); 	s = tmpnam(NULL); 	tfd = open(s, O_RDONLY|O_CREAT,
literal|0600
argument|); 	rval = fchown(tfd, DefUid, DefGid) !=
literal|0
argument|; 	close(tfd); 	setresuid(o_uid, o_euid, -
literal|1
argument|); 	setresgid(o_gid, o_egid, -
literal|1
argument|); 	unlink(s); 	return rval;
else|#
directive|else
ifdef|#
directive|ifdef
name|_POSIX_CHOWN_RESTRICTED
if|#
directive|if
name|_POSIX_CHOWN_RESTRICTED
operator|==
operator|-
literal|1
argument|return FALSE;
else|#
directive|else
argument|return TRUE;
endif|#
directive|endif
else|#
directive|else
ifdef|#
directive|ifdef
name|_PC_CHOWN_RESTRICTED
argument|int rval;
comment|/* 	**  Some systems (e.g., SunOS) seem to have the call and the 	**  #define _PC_CHOWN_RESTRICTED, but don't actually implement 	**  the call.  This heuristic checks for that. 	*/
argument|errno =
literal|0
argument|; 	rval = fpathconf(fd, _PC_CHOWN_RESTRICTED); 	if (errno ==
literal|0
argument|) 		return rval>
literal|0
argument|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|BSD
argument|return TRUE;
else|#
directive|else
argument|return FALSE;
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
argument|}
comment|/* **  RESETLIMITS -- reset system controlled resource limits ** **	This is to avoid denial-of-service attacks ** **	Parameters: **		none ** **	Returns: **		none */
if|#
directive|if
name|HASSETRLIMIT
ifdef|#
directive|ifdef
name|RLIMIT_NEEDS_SYS_TIME_H
include|#
directive|include
file|<sys/time.h>
endif|#
directive|endif
include|#
directive|include
file|<sys/resource.h>
endif|#
directive|endif
ifndef|#
directive|ifndef
name|FD_SETSIZE
define|#
directive|define
name|FD_SETSIZE
value|256
endif|#
directive|endif
argument|void resetlimits() {
if|#
directive|if
name|HASSETRLIMIT
argument|struct rlimit lim;  	lim.rlim_cur = lim.rlim_max = RLIM_INFINITY; 	(void) setrlimit(RLIMIT_CPU,&lim); 	(void) setrlimit(RLIMIT_FSIZE,&lim);
ifdef|#
directive|ifdef
name|RLIMIT_NOFILE
argument|lim.rlim_cur = lim.rlim_max = FD_SETSIZE; 	(void) setrlimit(RLIMIT_NOFILE,&lim);
endif|#
directive|endif
else|#
directive|else
if|#
directive|if
name|HASULIMIT
argument|(void) ulimit(
literal|2
argument|,
literal|0x3fffff
argument|); 	(void) ulimit(
literal|4
argument|, FD_SETSIZE);
endif|#
directive|endif
endif|#
directive|endif
argument|errno =
literal|0
argument|; }
comment|/* **  GETCFNAME -- return the name of the .cf file. ** **	Some systems (e.g., NeXT) determine this dynamically. */
argument|char * getcfname() {  	if (ConfFile != NULL) 		return ConfFile;
if|#
directive|if
name|NETINFO
argument|{ 		extern char *ni_propval(); 		char *cflocation;  		cflocation = ni_propval(
literal|"/locations"
argument|, NULL,
literal|"sendmail"
argument|,
literal|"sendmail.cf"
argument|,
literal|'\0'
argument|); 		if (cflocation != NULL) 			return cflocation; 	}
endif|#
directive|endif
argument|return _PATH_SENDMAILCF; }
comment|/* **  SETVENDOR -- process vendor code from V configuration line ** **	Parameters: **		vendor -- string representation of vendor. ** **	Returns: **		TRUE -- if ok. **		FALSE -- if vendor code could not be processed. ** **	Side Effects: **		It is reasonable to set mode flags here to tweak **		processing in other parts of the code if necessary. **		For example, if you are a vendor that uses $%y to **		indicate YP lookups, you could enable that here. */
argument|bool setvendor(vendor) 	char *vendor; { 	if (strcasecmp(vendor,
literal|"Berkeley"
argument|) ==
literal|0
argument|) 	{ 		VendorCode = VENDOR_BERKELEY; 		return TRUE; 	}
comment|/* add vendor extensions here */
ifdef|#
directive|ifdef
name|SUN_EXTENSIONS
argument|if (strcasecmp(vendor,
literal|"Sun"
argument|) ==
literal|0
argument|) 	{ 		VendorCode = VENDOR_SUN; 		return TRUE; 	}
endif|#
directive|endif
argument|return FALSE; }
comment|/* **  VENDOR_PRE_DEFAULTS, VENDOR_POST_DEFAULTS -- set vendor-specific defaults ** **	Vendor_pre_defaults is called before reading the configuration **	file; vendor_post_defaults is called immediately after. ** **	Parameters: **		e -- the global environment to initialize. ** **	Returns: **		none. */
if|#
directive|if
name|SHARE_V1
argument|int	DefShareUid;
comment|/* default share uid to run as -- unused??? */
endif|#
directive|endif
argument|void vendor_pre_defaults(e) 	ENVELOPE *e; {
if|#
directive|if
name|SHARE_V1
comment|/* OTHERUID is defined in shares.h, do not be alarmed */
argument|DefShareUid = OTHERUID;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SUN_EXTENSIONS
argument|sun_pre_defaults(e);
endif|#
directive|endif
ifdef|#
directive|ifdef
name|apollo
comment|/* stupid domain/os can't even open /etc/sendmail.cf without this */
argument|setuserenv(
literal|"ISP"
argument|, NULL); 	setuserenv(
literal|"SYSTYPE"
argument|, NULL);
endif|#
directive|endif
argument|}   void vendor_post_defaults(e) 	ENVELOPE *e; {
ifdef|#
directive|ifdef
name|SUN_EXTENSIONS
argument|sun_post_defaults(e);
endif|#
directive|endif
argument|}
comment|/* **  VENDOR_DAEMON_SETUP -- special vendor setup needed for daemon mode */
argument|void vendor_daemon_setup(e) 	ENVELOPE *e; {
if|#
directive|if
name|SECUREWARE
argument|if (getluid() != -
literal|1
argument|) 	{ 		usrerr(
literal|"Daemon cannot have LUID"
argument|); 		exit(EX_USAGE); 	}
endif|#
directive|endif
comment|/* SECUREWARE */
argument|}
comment|/* **  VENDOR_SET_UID -- do setup for setting a user id ** **	This is called when we are still root. ** **	Parameters: **		uid -- the uid we are about to become. ** **	Returns: **		none. */
argument|void vendor_set_uid(uid) 	UID_T uid; {
comment|/*  	**  We need to setup the share groups (lnodes) 	**  and and auditing inforation (luid's) 	**  before we loose our ``root''ness. 	*/
if|#
directive|if
name|SHARE_V1
argument|if (setupshares(uid, syserr) !=
literal|0
argument|) 		syserr(
literal|"Unable to set up shares"
argument|);
endif|#
directive|endif
if|#
directive|if
name|SECUREWARE
argument|(void) setup_secure(uid);
endif|#
directive|endif
argument|}
comment|/* **  VALIDATE_CONNECTION -- check connection for rationality ** **	If the connection is rejected, this routine should log an **	appropriate message -- but should never issue any SMTP protocol. ** **	Parameters: **		sap -- a pointer to a SOCKADDR naming the peer. **		hostname -- the name corresponding to sap. **		e -- the current envelope. ** **	Returns: **		TRUE -- if the connection should be accepted. **		FALSE -- if it should be rejected. */
if|#
directive|if
name|TCPWRAPPERS
include|#
directive|include
file|<tcpd.h>
argument|int	allow_severity	= LOG_INFO; int	deny_severity	= LOG_WARNING;
endif|#
directive|endif
if|#
directive|if
name|DAEMON
argument|bool validate_connection(sap, hostname, e) 	SOCKADDR *sap; 	char *hostname; 	ENVELOPE *e; { 	if (rscheck(
literal|"check_relay"
argument|, hostname, anynet_ntoa(sap), e) != EX_OK) 		return FALSE;
if|#
directive|if
name|TCPWRAPPERS
argument|if (!hosts_ctl(
literal|"sendmail"
argument|, hostname, anynet_ntoa(sap), STRING_UNKNOWN)) 		return FALSE;
endif|#
directive|endif
argument|return TRUE; }
endif|#
directive|endif
comment|/* **  STRTOL -- convert string to long integer ** **	For systems that don't have it in the C library. ** **	This is taken verbatim from the 4.4-Lite C library. */
ifdef|#
directive|ifdef
name|NEEDSTRTOL
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
argument|static char sccsid[] =
literal|"@(#)strtol.c	8.1 (Berkeley) 6/4/93"
argument|;
endif|#
directive|endif
comment|/* LIBC_SCCS and not lint */
include|#
directive|include
file|<limits.h>
comment|/*  * Convert a string to a long integer.  *  * Ignores `locale' stuff.  Assumes that the upper and lower case  * alphabets and digits are each contiguous.  */
argument|long strtol(nptr, endptr, base) 	const char *nptr; 	char **endptr; 	register int base; { 	register const char *s = nptr; 	register unsigned long acc; 	register int c; 	register unsigned long cutoff; 	register int neg =
literal|0
argument|, any, cutlim;
comment|/* 	 * Skip white space and pick up leading +/- sign if any. 	 * If base is 0, allow 0x for hex and 0 for octal, else 	 * assume decimal; if base is already 16, allow 0x. 	 */
argument|do { 		c = *s++; 	} while (isspace(c)); 	if (c ==
literal|'-'
argument|) { 		neg =
literal|1
argument|; 		c = *s++; 	} else if (c ==
literal|'+'
argument|) 		c = *s++; 	if ((base ==
literal|0
argument||| base ==
literal|16
argument|)&& 	    c ==
literal|'0'
argument|&& (*s ==
literal|'x'
argument||| *s ==
literal|'X'
argument|)) { 		c = s[
literal|1
argument|]; 		s +=
literal|2
argument|; 		base =
literal|16
argument|; 	} 	if (base ==
literal|0
argument|) 		base = c ==
literal|'0'
argument|?
literal|8
argument|:
literal|10
argument|;
comment|/* 	 * Compute the cutoff value between legal numbers and illegal 	 * numbers.  That is the largest legal value, divided by the 	 * base.  An input number that is greater than this value, if 	 * followed by a legal input character, is too big.  One that 	 * is equal to this value may be valid or not; the limit 	 * between valid and invalid numbers is then based on the last 	 * digit.  For instance, if the range for longs is 	 * [-2147483648..2147483647] and the input base is 10, 	 * cutoff will be set to 214748364 and cutlim to either 	 * 7 (neg==0) or 8 (neg==1), meaning that if we have accumulated 	 * a value> 214748364, or equal but the next digit is> 7 (or 8), 	 * the number is too big, and we will return a range error. 	 * 	 * Set any if any `digits' consumed; make it negative to indicate 	 * overflow. 	 */
argument|cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX; 	cutlim = cutoff % (unsigned long)base; 	cutoff /= (unsigned long)base; 	for (acc =
literal|0
argument|, any =
literal|0
argument|;; c = *s++) { 		if (isdigit(c)) 			c -=
literal|'0'
argument|; 		else if (isalpha(c)) 			c -= isupper(c) ?
literal|'A'
argument|-
literal|10
argument|:
literal|'a'
argument|-
literal|10
argument|; 		else 			break; 		if (c>= base) 			break; 		if (any<
literal|0
argument||| acc> cutoff || acc == cutoff&& c> cutlim) 			any = -
literal|1
argument|; 		else { 			any =
literal|1
argument|; 			acc *= base; 			acc += c; 		} 	} 	if (any<
literal|0
argument|) { 		acc = neg ? LONG_MIN : LONG_MAX; 		errno = ERANGE; 	} else if (neg) 		acc = -acc; 	if (endptr !=
literal|0
argument|) 		*endptr = (char *)(any ? s -
literal|1
argument|: nptr); 	return (acc); }
endif|#
directive|endif
comment|/* **  STRSTR -- find first substring in string ** **	Parameters: **		big -- the big (full) string. **		little -- the little (sub) string. ** **	Returns: **		A pointer to the first instance of little in big. **		big if little is the null string. **		NULL if little is not contained in big. */
ifdef|#
directive|ifdef
name|NEEDSTRSTR
argument|char * strstr(big, little) 	char *big; 	char *little; { 	register char *p = big; 	int l;  	if (*little ==
literal|'\0'
argument|) 		return big; 	l = strlen(little);  	while ((p = strchr(p, *little)) != NULL) 	{ 		if (strncmp(p, little, l) ==
literal|0
argument|) 			return p; 		p++; 	} 	return NULL; }
endif|#
directive|endif
comment|/* **  SM_GETHOSTBY{NAME,ADDR} -- compatibility routines for gethostbyXXX ** **	Some operating systems have wierd problems with the gethostbyXXX **	routines.  For example, Solaris versions at least through 2.3 **	don't properly deliver a canonical h_name field.  This tries to **	work around these problems. */
argument|struct hostent * sm_gethostbyname(name) 	char *name; { 	struct hostent *h;
if|#
directive|if
operator|(
name|SOLARIS
operator|>
literal|10000
operator|&&
name|SOLARIS
operator|<
literal|20400
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|SOLARIS
argument_list|)
operator|&&
name|SOLARIS
operator|<
literal|204
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|sony_news
argument_list|)
operator|&&
name|defined
argument_list|(
name|__svr4
argument_list|)
operator|)
if|#
directive|if
name|SOLARIS
operator|==
literal|20300
operator|||
name|SOLARIS
operator|==
literal|203
argument|static struct hostent hp; 	static char buf[
literal|1000
argument|]; 	extern struct hostent *_switch_gethostbyname_r();  	if (tTd(
literal|61
argument|,
literal|10
argument|)) 		printf(
literal|"_switch_gethostbyname_r(%s)... "
argument|, name); 	h = _switch_gethostbyname_r(name,&hp, buf, sizeof(buf),&h_errno);
else|#
directive|else
argument|extern struct hostent *__switch_gethostbyname();  	if (tTd(
literal|61
argument|,
literal|10
argument|)) 		printf(
literal|"__switch_gethostbyname(%s)... "
argument|, name); 	h = __switch_gethostbyname(name);
endif|#
directive|endif
else|#
directive|else
argument|int nmaps; 	char *maptype[MAXMAPSTACK]; 	short mapreturn[MAXMAPACTIONS]; 	char hbuf[MAXNAME];  	if (tTd(
literal|61
argument|,
literal|10
argument|)) 		printf(
literal|"gethostbyname(%s)... "
argument|, name); 	h = gethostbyname(name); 	if (h == NULL) 	{ 		if (tTd(
literal|61
argument|,
literal|10
argument|)) 			printf(
literal|"failure\n"
argument|);  		nmaps = switch_map_find(
literal|"hosts"
argument|, maptype, mapreturn); 		while (--nmaps>=
literal|0
argument|) 			if (strcmp(maptype[nmaps],
literal|"nis"
argument|) ==
literal|0
argument||| 			    strcmp(maptype[nmaps],
literal|"files"
argument|) ==
literal|0
argument|) 				break; 		if (nmaps>=
literal|0
argument|) 		{
comment|/* try short name */
argument|if (strlen(name)> (SIZE_T) sizeof hbuf -
literal|1
argument|) 				return NULL; 			strcpy(hbuf, name); 			shorten_hostname(hbuf);
comment|/* if it hasn't been shortened, there's no point */
argument|if (strcmp(hbuf, name) !=
literal|0
argument|) 			{ 				if (tTd(
literal|61
argument|,
literal|10
argument|)) 					printf(
literal|"gethostbyname(%s)... "
argument|, hbuf); 				h = gethostbyname(hbuf); 			} 		} 	}
endif|#
directive|endif
argument|if (tTd(
literal|61
argument|,
literal|10
argument|)) 	{ 		if (h == NULL) 			printf(
literal|"failure\n"
argument|); 		else 			printf(
literal|"%s\n"
argument|, h->h_name); 	} 	return h; }  struct hostent * sm_gethostbyaddr(addr, len, type) 	char *addr; 	int len; 	int type; {
if|#
directive|if
operator|(
name|SOLARIS
operator|>
literal|10000
operator|&&
name|SOLARIS
operator|<
literal|20400
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|SOLARIS
argument_list|)
operator|&&
name|SOLARIS
operator|<
literal|204
operator|)
if|#
directive|if
name|SOLARIS
operator|==
literal|20300
operator|||
name|SOLARIS
operator|==
literal|203
argument|static struct hostent hp; 	static char buf[
literal|1000
argument|]; 	extern struct hostent *_switch_gethostbyaddr_r();  	return _switch_gethostbyaddr_r(addr, len, type,&hp, buf, sizeof(buf),&h_errno);
else|#
directive|else
argument|extern struct hostent *__switch_gethostbyaddr();  	return __switch_gethostbyaddr(addr, len, type);
endif|#
directive|endif
else|#
directive|else
argument|return gethostbyaddr(addr, len, type);
endif|#
directive|endif
argument|}
comment|/* **  SM_GETPW{NAM,UID} -- wrapper for getpwnam and getpwuid */
argument|struct passwd * sm_getpwnam(user) 	char *user; {
ifdef|#
directive|ifdef
name|_AIX4
argument|extern struct passwd *_getpwnam_shadow(const char *, const int);  	return _getpwnam_shadow(user,
literal|0
argument|);
else|#
directive|else
argument|return getpwnam(user);
endif|#
directive|endif
argument|}  struct passwd * sm_getpwuid(uid) 	UID_T uid; {
if|#
directive|if
name|defined
argument_list|(
name|_AIX4
argument_list|)
operator|&&
literal|0
argument|extern struct passwd *_getpwuid_shadow(const int, const int);  	return _getpwuid_shadow(uid,
literal|0
argument|);
else|#
directive|else
argument|return getpwuid(uid);
endif|#
directive|endif
argument|}
comment|/* **  SECUREWARE_SETUP_SECURE -- Convex SecureWare setup ** **	Set up the trusted computing environment for C2 level security **	under SecureWare. ** **	Parameters: **		uid -- uid of the user to initialize in the TCB ** **	Returns: **		none ** **	Side Effects: **		Initialized the user in the trusted computing base */
if|#
directive|if
name|SECUREWARE
include|#
directive|include
file|<sys/security.h>
include|#
directive|include
file|<prot.h>
argument|void secureware_setup_secure(uid) 	UID_T uid; { 	int rc;  	if (getluid() != -
literal|1
argument|) 		return; 	 	if ((rc = set_secure_info(uid)) != SSI_GOOD_RETURN) 	{ 		switch (rc) 		{ 		  case SSI_NO_PRPW_ENTRY: 			syserr(
literal|"No protected passwd entry, uid = %d"
argument|, uid); 			break;  		  case SSI_LOCKED: 			syserr(
literal|"Account has been disabled, uid = %d"
argument|, uid); 			break;  		  case SSI_RETIRED: 			syserr(
literal|"Account has been retired, uid = %d"
argument|, uid); 			break;  		  case SSI_BAD_SET_LUID: 			syserr(
literal|"Could not set LUID, uid = %d"
argument|, uid); 			break;  		  case SSI_BAD_SET_PRIVS: 			syserr(
literal|"Could not set kernel privs, uid = %d"
argument|, uid);  		  default: 			syserr(
literal|"Unknown return code (%d) from set_secure_info(%d)"
argument|,  				rc, uid); 			break; 		} 		exit(EX_NOPERM); 	} }
endif|#
directive|endif
comment|/* SECUREWARE */
comment|/* **  LOAD_IF_NAMES -- load interface-specific names into $=w ** **	Parameters: **		none. ** **	Returns: **		none. ** **	Side Effects: **		Loads $=w with the names of all the interfaces. */
ifdef|#
directive|ifdef
name|SIOCGIFCONF
argument|struct rtentry; struct mbuf;
include|#
directive|include
file|<arpa/inet.h>
ifndef|#
directive|ifndef
name|SUNOS403
include|#
directive|include
file|<sys/time.h>
endif|#
directive|endif
include|#
directive|include
file|<net/if.h>
endif|#
directive|endif
argument|void load_if_names() {
ifdef|#
directive|ifdef
name|SIOCGIFCONF
argument|int s; 	int i;         struct ifconf ifc; 	char interfacebuf[
literal|1024
argument|];  	s = socket(AF_INET, SOCK_DGRAM,
literal|0
argument|); 	if (s == -
literal|1
argument|) 		return;
comment|/* get the list of known IP address from the kernel */
argument|ifc.ifc_buf = interfacebuf;         ifc.ifc_len = sizeof interfacebuf; 	if (ioctl(s, SIOCGIFCONF, (char *)&ifc)<
literal|0
argument|) 	{ 		if (tTd(
literal|0
argument|,
literal|4
argument|)) 			printf(
literal|"SIOGIFCONF failed: %s\n"
argument|, errstring(errno)); 		close(s); 		return; 	}
comment|/* scan the list of IP address */
argument|if (tTd(
literal|0
argument|,
literal|40
argument|)) 		printf(
literal|"scanning for interface specific names, ifc_len=%d\n"
argument|, 			ifc.ifc_len);  	for (i =
literal|0
argument|; i< ifc.ifc_len; ) 	{ 		struct ifreq *ifr = (struct ifreq *)&ifc.ifc_buf[i]; 		struct sockaddr *sa =&ifr->ifr_addr; 		struct in_addr ia; 		struct hostent *hp;
ifdef|#
directive|ifdef
name|SIOCGIFFLAGS
argument|struct ifreq ifrf;
endif|#
directive|endif
argument|char ip_addr[
literal|256
argument|]; 		extern char *inet_ntoa(); 		extern struct hostent *gethostbyaddr();
ifdef|#
directive|ifdef
name|BSD4_4_SOCKADDR
argument|if (sa->sa_len> sizeof ifr->ifr_addr) 			i += sizeof ifr->ifr_name + sa->sa_len; 		else
endif|#
directive|endif
argument|i += sizeof *ifr;  		if (tTd(
literal|0
argument|,
literal|20
argument|)) 			printf(
literal|"%s\n"
argument|, anynet_ntoa((SOCKADDR *) sa));  		if (ifr->ifr_addr.sa_family != AF_INET) 			continue;
ifdef|#
directive|ifdef
name|SIOCGIFFLAGS
argument|bzero(&ifrf, sizeof(struct ifreq)); 		strncpy(ifrf.ifr_name, ifr->ifr_name, sizeof(ifrf.ifr_name)); 		ioctl(s, SIOCGIFFLAGS, (char *)&ifrf); 		if (tTd(
literal|0
argument|,
literal|41
argument|)) 			printf(
literal|"\tflags: %x\n"
argument|, ifrf.ifr_flags); 		if (!bitset(IFF_UP, ifrf.ifr_flags)) 			continue;
else|#
directive|else
argument|if (!bitset(IFF_UP, ifr->ifr_flags)) 			continue;
endif|#
directive|endif
comment|/* extract IP address from the list*/
argument|ia = (((struct sockaddr_in *) sa)->sin_addr); 		if (ia.s_addr == INADDR_ANY || ia.s_addr == INADDR_NONE) 		{ 			message(
literal|"WARNING: interface %s is UP with %s address"
argument|, 				ifr->ifr_name, inet_ntoa(ia)); 			continue; 		}
comment|/* save IP address in text from */
argument|(void) snprintf(ip_addr, sizeof ip_addr,
literal|"[%.*s]"
argument|, 			sizeof ip_addr -
literal|3
argument|, 			inet_ntoa(ia)); 		if (!wordinclass(ip_addr,
literal|'w'
argument|)) 		{ 			setclass(
literal|'w'
argument|, ip_addr); 			if (tTd(
literal|0
argument|,
literal|4
argument|)) 				printf(
literal|"\ta.k.a.: %s\n"
argument|, ip_addr); 		}
comment|/* skip "loopback" interface "lo" */
argument|if (strcmp(
literal|"lo0"
argument|, ifr->ifr_name) ==
literal|0
argument|) 			continue;
comment|/* lookup name with IP address */
argument|hp = sm_gethostbyaddr((char *)&ia, sizeof(ia), AF_INET); 		if (hp == NULL) 		{
ifdef|#
directive|ifdef
name|LOG
argument|if (LogLevel>
literal|3
argument|) 				syslog(LOG_WARNING,
literal|"gethostbyaddr() failed for %.100s\n"
argument|, 					inet_ntoa(ia));
endif|#
directive|endif
argument|continue; 		}
comment|/* save its cname */
argument|if (!wordinclass((char *) hp->h_name,
literal|'w'
argument|)) 		{ 			setclass(
literal|'w'
argument|, (char *) hp->h_name); 			if (tTd(
literal|0
argument|,
literal|4
argument|)) 				printf(
literal|"\ta.k.a.: %s\n"
argument|, hp->h_name); 		}
comment|/* save all it aliases name */
argument|while (*hp->h_aliases) 		{ 			if (!wordinclass(*hp->h_aliases,
literal|'w'
argument|)) 			{ 				setclass(
literal|'w'
argument|, *hp->h_aliases); 				if (tTd(
literal|0
argument|,
literal|4
argument|)) 				printf(
literal|"\ta.k.a.: %s\n"
argument|, *hp->h_aliases); 			} 			hp->h_aliases++; 		} 	} 	close(s);
endif|#
directive|endif
argument|}
comment|/* **  HARD_SYSLOG -- call syslog repeatedly until it works ** **	Needed on HP-UX, which apparently doesn't guarantee that **	syslog succeeds during interrupt handlers. */
ifdef|#
directive|ifdef
name|__hpux
define|#
directive|define
name|MAXSYSLOGTRIES
value|100
undef|#
directive|undef
name|syslog
ifdef|#
directive|ifdef
name|V4FS
define|#
directive|define
name|XCNST
value|const
define|#
directive|define
name|CAST
value|(const char *)
else|#
directive|else
define|#
directive|define
name|XCNST
define|#
directive|define
name|CAST
endif|#
directive|endif
argument|void
ifdef|#
directive|ifdef
name|__STDC__
argument|hard_syslog(int pri, XCNST char *msg, ...)
else|#
directive|else
argument|hard_syslog(pri, msg, va_alist) 	int pri; 	XCNST char *msg; 	va_dcl
endif|#
directive|endif
argument|{ 	int i; 	char buf[SYSLOG_BUFSIZE *
literal|2
argument|]; 	VA_LOCAL_DECL;  	VA_START(msg); 	vsnprintf(buf, sizeof buf, msg, ap); 	VA_END;  	for (i = MAXSYSLOGTRIES; --i>=
literal|0
argument|&& syslog(pri, CAST
literal|"%s"
argument|, buf)<
literal|0
argument|; ) 		continue; }
undef|#
directive|undef
name|CAST
endif|#
directive|endif
comment|/* **  LOCAL_HOSTNAME_LENGTH ** **	This is required to get sendmail to compile against BIND 4.9.x **	on Ultrix. */
if|#
directive|if
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|&&
name|NAMED_BIND
include|#
directive|include
file|<resolv.h>
if|#
directive|if
name|__RES
operator|>=
literal|19931104
operator|&&
name|__RES
operator|<
literal|19950621
argument|int local_hostname_length(hostname) 	char *hostname; { 	int len_host, len_domain;  	if (!*_res.defdname) 		res_init(); 	len_host = strlen(hostname); 	len_domain = strlen(_res.defdname); 	if (len_host> len_domain&& 	    (strcasecmp(hostname + len_host - len_domain,_res.defdname) ==
literal|0
argument|)&& 	    hostname[len_host - len_domain -
literal|1
argument|] ==
literal|'.'
argument|) 		return len_host - len_domain -
literal|1
argument|; 	else 		return
literal|0
argument|; }
endif|#
directive|endif
endif|#
directive|endif
comment|/* **  Compile-Time options */
argument|char	*CompileOptions[] = {
if|#
directive|if
name|HESIOD
literal|"HESIOD"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HES_GETMAILHOST
literal|"HES_GETMAILHOST"
argument|,
endif|#
directive|endif
if|#
directive|if
name|LDAPMAP
literal|"LDAPMAP"
argument|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LOG
literal|"LOG"
argument|,
endif|#
directive|endif
if|#
directive|if
name|MATCHGECOS
literal|"MATCHGECOS"
argument|,
endif|#
directive|endif
if|#
directive|if
name|MIME7TO8
literal|"MIME7TO8"
argument|,
endif|#
directive|endif
if|#
directive|if
name|MIME8TO7
literal|"MIME8TO7"
argument|,
endif|#
directive|endif
if|#
directive|if
name|NAMED_BIND
literal|"NAMED_BIND"
argument|,
endif|#
directive|endif
if|#
directive|if
name|NDBM
literal|"NDBM"
argument|,
endif|#
directive|endif
if|#
directive|if
name|NETINET
literal|"NETINET"
argument|,
endif|#
directive|endif
if|#
directive|if
name|NETINFO
literal|"NETINFO"
argument|,
endif|#
directive|endif
if|#
directive|if
name|NETISO
literal|"NETISO"
argument|,
endif|#
directive|endif
if|#
directive|if
name|NETNS
literal|"NETNS"
argument|,
endif|#
directive|endif
if|#
directive|if
name|NETUNIX
literal|"NETUNIX"
argument|,
endif|#
directive|endif
if|#
directive|if
name|NETX25
literal|"NETX25"
argument|,
endif|#
directive|endif
if|#
directive|if
name|NEWDB
literal|"NEWDB"
argument|,
endif|#
directive|endif
if|#
directive|if
name|NIS
literal|"NIS"
argument|,
endif|#
directive|endif
if|#
directive|if
name|NISPLUS
literal|"NISPLUS"
argument|,
endif|#
directive|endif
if|#
directive|if
name|QUEUE
literal|"QUEUE"
argument|,
endif|#
directive|endif
if|#
directive|if
name|SCANF
literal|"SCANF"
argument|,
endif|#
directive|endif
if|#
directive|if
name|SMTP
literal|"SMTP"
argument|,
endif|#
directive|endif
if|#
directive|if
name|SMTPDEBUG
literal|"SMTPDEBUG"
argument|,
endif|#
directive|endif
if|#
directive|if
name|SUID_ROOT_FILES_OK
literal|"SUID_ROOT_FILES_OK"
argument|,
endif|#
directive|endif
if|#
directive|if
name|TCPWRAPPERS
literal|"TCPWRAPPERS"
argument|,
endif|#
directive|endif
if|#
directive|if
name|USERDB
literal|"USERDB"
argument|,
endif|#
directive|endif
if|#
directive|if
name|XDEBUG
literal|"XDEBUG"
argument|,
endif|#
directive|endif
if|#
directive|if
name|XLA
literal|"XLA"
argument|,
endif|#
directive|endif
argument|NULL };
comment|/* **  OS compile options. */
argument|char	*OsCompileOptions[] = {
if|#
directive|if
name|HASFCHMOD
literal|"HASFCHMOD"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HASFLOCK
literal|"HASFLOCK"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HASGETDTABLESIZE
literal|"HASGETDTABLESIZE"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HASGETUSERSHELL
literal|"HASGETUSERSHELL"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HASINITGROUPS
literal|"HASINITGROUPS"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HASLSTAT
literal|"HASLSTAT"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HASSETREUID
literal|"HASSETREUID"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HASSETRLIMIT
literal|"HASSETRLIMIT"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HASSETSID
literal|"HASSETSID"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HASSETUSERCONTEXT
literal|"HASSETUSERCONTEXT"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HASSETVBUF
literal|"HASSETVBUF"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HASSNPRINTF
literal|"HASSNPRINTF"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HASULIMIT
literal|"HASULIMIT"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HASUNAME
literal|"HASUNAME"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HASUNSETENV
literal|"HASUNSETENV"
argument|,
endif|#
directive|endif
if|#
directive|if
name|HASWAITPID
literal|"HASWAITPID"
argument|,
endif|#
directive|endif
if|#
directive|if
name|IDENTPROTO
literal|"IDENTPROTO"
argument|,
endif|#
directive|endif
if|#
directive|if
name|IP_SRCROUTE
literal|"IP_SRCROUTE"
argument|,
endif|#
directive|endif
if|#
directive|if
name|NEEDFSYNC
literal|"NEEDFSYNC"
argument|,
endif|#
directive|endif
if|#
directive|if
name|NOFTRUNCATE
literal|"NOFTRUNCATE"
argument|,
endif|#
directive|endif
if|#
directive|if
name|RLIMIT_NEEDS_SYS_TIME_H
literal|"RLIMIT_NEEDS_SYS_TIME_H"
argument|,
endif|#
directive|endif
if|#
directive|if
name|SECUREWARE
literal|"SECUREWARE"
argument|,
endif|#
directive|endif
if|#
directive|if
name|SHARE_V1
literal|"SHARE_V1"
argument|,
endif|#
directive|endif
if|#
directive|if
name|SYS5SETPGRP
literal|"SYS5SETPGRP"
argument|,
endif|#
directive|endif
if|#
directive|if
name|SYSTEM5
literal|"SYSTEM5"
argument|,
endif|#
directive|endif
if|#
directive|if
name|USE_SA_SIGACTION
literal|"USE_SA_SIGACTION"
argument|,
endif|#
directive|endif
if|#
directive|if
name|USESETEUID
literal|"USESETEUID"
argument|,
endif|#
directive|endif
argument|NULL };
end_function

end_unit

