begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1995 Eric P. Allman  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_if
if|#
directive|if
name|USERDB
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)udb.c	8.32 (Berkeley) 11/18/95 (with USERDB)"
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
literal|"@(#)udb.c	8.32 (Berkeley) 11/18/95 (without USERDB)"
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

begin_if
if|#
directive|if
name|USERDB
end_if

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NEWDB
end_ifdef

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBT
value|struct _data_base_thang_
end_define

begin_macro
name|DBT
end_macro

begin_block
block|{
name|void
modifier|*
name|data
decl_stmt|;
comment|/* pointer to data */
name|size_t
name|size
decl_stmt|;
comment|/* length of data */
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HESIOD
end_ifdef

begin_include
include|#
directive|include
file|<hesiod.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HESIOD */
end_comment

begin_comment
comment|/* **  UDB.C -- interface between sendmail and Berkeley User Data Base. ** **	This depends on the 4.4BSD db package. */
end_comment

begin_struct
struct|struct
name|udbent
block|{
name|char
modifier|*
name|udb_spec
decl_stmt|;
comment|/* string version of spec */
name|int
name|udb_type
decl_stmt|;
comment|/* type of entry */
name|char
modifier|*
name|udb_default
decl_stmt|;
comment|/* default host for outgoing mail */
union|union
block|{
comment|/* type UE_REMOTE -- do remote call for lookup */
struct|struct
block|{
name|struct
name|sockaddr_in
name|_udb_addr
decl_stmt|;
comment|/* address */
name|int
name|_udb_timeout
decl_stmt|;
comment|/* timeout */
block|}
name|udb_remote
struct|;
define|#
directive|define
name|udb_addr
value|udb_u.udb_remote._udb_addr
define|#
directive|define
name|udb_timeout
value|udb_u.udb_remote._udb_timeout
comment|/* type UE_FORWARD -- forward message to remote */
struct|struct
block|{
name|char
modifier|*
name|_udb_fwdhost
decl_stmt|;
comment|/* name of forward host */
block|}
name|udb_forward
struct|;
define|#
directive|define
name|udb_fwdhost
value|udb_u.udb_forward._udb_fwdhost
ifdef|#
directive|ifdef
name|NEWDB
comment|/* type UE_FETCH -- lookup in local database */
struct|struct
block|{
name|char
modifier|*
name|_udb_dbname
decl_stmt|;
comment|/* pathname of database */
name|DB
modifier|*
name|_udb_dbp
decl_stmt|;
comment|/* open database ptr */
block|}
name|udb_lookup
struct|;
define|#
directive|define
name|udb_dbname
value|udb_u.udb_lookup._udb_dbname
define|#
directive|define
name|udb_dbp
value|udb_u.udb_lookup._udb_dbp
endif|#
directive|endif
block|}
name|udb_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UDB_EOLIST
value|0
end_define

begin_comment
comment|/* end of list */
end_comment

begin_define
define|#
directive|define
name|UDB_SKIP
value|1
end_define

begin_comment
comment|/* skip this entry */
end_comment

begin_define
define|#
directive|define
name|UDB_REMOTE
value|2
end_define

begin_comment
comment|/* look up in remote database */
end_comment

begin_define
define|#
directive|define
name|UDB_DBFETCH
value|3
end_define

begin_comment
comment|/* look up in local database */
end_comment

begin_define
define|#
directive|define
name|UDB_FORWARD
value|4
end_define

begin_comment
comment|/* forward to remote host */
end_comment

begin_define
define|#
directive|define
name|UDB_HESIOD
value|5
end_define

begin_comment
comment|/* look up via hesiod */
end_comment

begin_define
define|#
directive|define
name|MAXUDBENT
value|10
end_define

begin_comment
comment|/* maximum number of UDB entries */
end_comment

begin_struct
struct|struct
name|option
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* **  UDBEXPAND -- look up user in database and expand ** **	Parameters: **		a -- address to expand. **		sendq -- pointer to head of sendq to put the expansions in. **		aliaslevel -- the current alias nesting depth. **		e -- the current envelope. ** **	Returns: **		EX_TEMPFAIL -- if something "odd" happened -- probably due **			to accessing a file on an NFS server that is down. **		EX_OK -- otherwise. ** **	Side Effects: **		Modifies sendq. */
end_comment

begin_decl_stmt
name|int
name|UdbPort
init|=
literal|1616
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|UdbTimeout
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|udbent
name|UdbEnts
index|[
name|MAXUDBENT
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|UdbSock
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|UdbInitialized
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|udbexpand
parameter_list|(
name|a
parameter_list|,
name|sendq
parameter_list|,
name|aliaslevel
parameter_list|,
name|e
parameter_list|)
specifier|register
name|ADDRESS
modifier|*
name|a
decl_stmt|;
name|ADDRESS
modifier|*
modifier|*
name|sendq
decl_stmt|;
name|int
name|aliaslevel
decl_stmt|;
specifier|register
name|ENVELOPE
modifier|*
name|e
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|DBT
name|key
decl_stmt|;
name|DBT
name|info
decl_stmt|;
name|bool
name|breakout
decl_stmt|;
specifier|register
name|struct
name|udbent
modifier|*
name|up
decl_stmt|;
name|int
name|keylen
decl_stmt|;
name|int
name|naddrs
decl_stmt|;
name|char
name|keybuf
index|[
name|MAXKEY
index|]
decl_stmt|;
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
if|if
condition|(
name|tTd
argument_list|(
literal|28
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"udbexpand(%s)\n"
argument_list|,
name|a
operator|->
name|q_paddr
argument_list|)
expr_stmt|;
comment|/* make certain we are supposed to send to this address */
if|if
condition|(
name|bitset
argument_list|(
name|QDONTSEND
operator||
name|QVERIFIED
argument_list|,
name|a
operator|->
name|q_flags
argument_list|)
condition|)
return|return
name|EX_OK
return|;
name|e
operator|->
name|e_to
operator|=
name|a
operator|->
name|q_paddr
expr_stmt|;
comment|/* on first call, locate the database */
if|if
condition|(
operator|!
name|UdbInitialized
condition|)
block|{
specifier|extern
name|int
name|_udbx_init
parameter_list|()
function_decl|;
if|if
condition|(
name|_udbx_init
argument_list|()
operator|==
name|EX_TEMPFAIL
condition|)
return|return
name|EX_TEMPFAIL
return|;
block|}
comment|/* short circuit the process if no chance of a match */
if|if
condition|(
name|UdbSpec
operator|==
name|NULL
operator|||
name|UdbSpec
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
return|return
name|EX_OK
return|;
comment|/* short circuit name begins with '\\' since it can't possibly match */
if|if
condition|(
name|a
operator|->
name|q_user
index|[
literal|0
index|]
operator|==
literal|'\\'
condition|)
return|return
name|EX_OK
return|;
comment|/* if name is too long, assume it won't match */
if|if
condition|(
name|strlen
argument_list|(
name|a
operator|->
name|q_user
argument_list|)
operator|>
sizeof|sizeof
name|keybuf
operator|-
literal|12
condition|)
return|return
name|EX_OK
return|;
comment|/* if name begins with a colon, it indicates our metadata */
if|if
condition|(
name|a
operator|->
name|q_user
index|[
literal|0
index|]
operator|==
literal|':'
condition|)
return|return
name|EX_OK
return|;
comment|/* build actual database key */
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|keybuf
argument_list|,
name|a
operator|->
name|q_user
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcat
argument_list|(
name|keybuf
argument_list|,
literal|":maildrop"
argument_list|)
expr_stmt|;
name|keylen
operator|=
name|strlen
argument_list|(
name|keybuf
argument_list|)
expr_stmt|;
name|breakout
operator|=
name|FALSE
expr_stmt|;
for|for
control|(
name|up
operator|=
name|UdbEnts
init|;
operator|!
name|breakout
condition|;
name|up
operator|++
control|)
block|{
name|char
modifier|*
name|user
decl_stmt|;
comment|/* 		**  Select action based on entry type. 		** 		**	On dropping out of this switch, "class" should 		**	explain the type of the data, and "user" should 		**	contain the user information. 		*/
switch|switch
condition|(
name|up
operator|->
name|udb_type
condition|)
block|{
ifdef|#
directive|ifdef
name|NEWDB
case|case
name|UDB_DBFETCH
case|:
name|key
operator|.
name|data
operator|=
name|keybuf
expr_stmt|;
name|key
operator|.
name|size
operator|=
name|keylen
expr_stmt|;
if|if
condition|(
name|tTd
argument_list|(
literal|28
argument_list|,
literal|80
argument_list|)
condition|)
name|printf
argument_list|(
literal|"udbexpand: trying %s (%d) via db\n"
argument_list|,
name|keybuf
argument_list|,
name|keylen
argument_list|)
expr_stmt|;
name|i
operator|=
call|(
modifier|*
name|up
operator|->
name|udb_dbp
operator|->
name|seq
call|)
argument_list|(
name|up
operator|->
name|udb_dbp
argument_list|,
operator|&
name|key
argument_list|,
operator|&
name|info
argument_list|,
name|R_CURSOR
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>
literal|0
operator|||
name|info
operator|.
name|size
operator|<=
literal|0
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|28
argument_list|,
literal|2
argument_list|)
condition|)
name|printf
argument_list|(
literal|"udbexpand: no match on %s (%d)\n"
argument_list|,
name|keybuf
argument_list|,
name|keylen
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|tTd
argument_list|(
literal|28
argument_list|,
literal|80
argument_list|)
condition|)
name|printf
argument_list|(
literal|"udbexpand: match %.*s: %.*s\n"
argument_list|,
name|key
operator|.
name|size
argument_list|,
name|key
operator|.
name|data
argument_list|,
name|info
operator|.
name|size
argument_list|,
name|info
operator|.
name|data
argument_list|)
expr_stmt|;
name|naddrs
operator|=
literal|0
expr_stmt|;
name|a
operator|->
name|q_flags
operator|&=
operator|~
name|QSELFREF
expr_stmt|;
while|while
condition|(
name|i
operator|==
literal|0
operator|&&
name|key
operator|.
name|size
operator|==
name|keylen
operator|&&
name|bcmp
argument_list|(
name|key
operator|.
name|data
argument_list|,
name|keybuf
argument_list|,
name|keylen
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|bitset
argument_list|(
name|EF_VRFYONLY
argument_list|,
name|e
operator|->
name|e_flags
argument_list|)
condition|)
block|{
name|a
operator|->
name|q_flags
operator||=
name|QVERIFIED
expr_stmt|;
return|return
name|EX_OK
return|;
block|}
name|breakout
operator|=
name|TRUE
expr_stmt|;
if|if
condition|(
name|info
operator|.
name|size
operator|<
sizeof|sizeof
name|buf
condition|)
name|user
operator|=
name|buf
expr_stmt|;
else|else
name|user
operator|=
name|xalloc
argument_list|(
name|info
operator|.
name|size
operator|+
literal|1
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|info
operator|.
name|data
argument_list|,
name|user
argument_list|,
name|info
operator|.
name|size
argument_list|)
expr_stmt|;
name|user
index|[
name|info
operator|.
name|size
index|]
operator|=
literal|'\0'
expr_stmt|;
name|message
argument_list|(
literal|"expanded to %s"
argument_list|,
name|user
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|LOG
if|if
condition|(
name|LogLevel
operator|>=
literal|10
condition|)
name|syslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"%s: expand %.100s => %s"
argument_list|,
name|e
operator|->
name|e_id
argument_list|,
name|e
operator|->
name|e_to
argument_list|,
name|shortenstring
argument_list|(
name|user
argument_list|,
literal|203
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|naddrs
operator|+=
name|sendtolist
argument_list|(
name|user
argument_list|,
name|a
argument_list|,
name|sendq
argument_list|,
name|aliaslevel
operator|+
literal|1
argument_list|,
name|e
argument_list|)
expr_stmt|;
if|if
condition|(
name|user
operator|!=
name|buf
condition|)
name|free
argument_list|(
name|user
argument_list|)
expr_stmt|;
comment|/* get the next record */
name|i
operator|=
call|(
modifier|*
name|up
operator|->
name|udb_dbp
operator|->
name|seq
call|)
argument_list|(
name|up
operator|->
name|udb_dbp
argument_list|,
operator|&
name|key
argument_list|,
operator|&
name|info
argument_list|,
name|R_NEXT
argument_list|)
expr_stmt|;
block|}
comment|/* if nothing ever matched, try next database */
if|if
condition|(
operator|!
name|breakout
condition|)
continue|continue;
if|if
condition|(
name|naddrs
operator|>
literal|0
operator|&&
operator|!
name|bitset
argument_list|(
name|QSELFREF
argument_list|,
name|a
operator|->
name|q_flags
argument_list|)
condition|)
block|{
if|if
condition|(
name|tTd
argument_list|(
literal|28
argument_list|,
literal|5
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"udbexpand: QDONTSEND "
argument_list|)
expr_stmt|;
name|printaddr
argument_list|(
name|a
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
block|}
name|a
operator|->
name|q_flags
operator||=
name|QDONTSEND
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|<
literal|0
condition|)
block|{
name|syserr
argument_list|(
literal|"udbexpand: db-get %.*s stat %d"
argument_list|,
name|key
operator|.
name|size
argument_list|,
name|key
operator|.
name|data
argument_list|,
name|i
argument_list|)
expr_stmt|;
return|return
name|EX_TEMPFAIL
return|;
block|}
comment|/* 			**  If this address has a -request address, reflect 			**  it into the envelope. 			*/
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|keybuf
argument_list|,
name|a
operator|->
name|q_user
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcat
argument_list|(
name|keybuf
argument_list|,
literal|":mailsender"
argument_list|)
expr_stmt|;
name|keylen
operator|=
name|strlen
argument_list|(
name|keybuf
argument_list|)
expr_stmt|;
name|key
operator|.
name|data
operator|=
name|keybuf
expr_stmt|;
name|key
operator|.
name|size
operator|=
name|keylen
expr_stmt|;
name|i
operator|=
call|(
modifier|*
name|up
operator|->
name|udb_dbp
operator|->
name|get
call|)
argument_list|(
name|up
operator|->
name|udb_dbp
argument_list|,
operator|&
name|key
argument_list|,
operator|&
name|info
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|!=
literal|0
operator|||
name|info
operator|.
name|size
operator|<=
literal|0
condition|)
break|break;
name|a
operator|->
name|q_owner
operator|=
name|xalloc
argument_list|(
name|info
operator|.
name|size
operator|+
literal|1
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|info
operator|.
name|data
argument_list|,
name|a
operator|->
name|q_owner
argument_list|,
name|info
operator|.
name|size
argument_list|)
expr_stmt|;
name|a
operator|->
name|q_owner
index|[
name|info
operator|.
name|size
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* announce delivery; NORECEIPT bit set later */
if|if
condition|(
name|e
operator|->
name|e_xfp
operator|!=
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|e
operator|->
name|e_xfp
argument_list|,
literal|"Message delivered to mailing list %s\n"
argument_list|,
name|a
operator|->
name|q_paddr
argument_list|)
expr_stmt|;
block|}
name|e
operator|->
name|e_flags
operator||=
name|EF_SENDRECEIPT
expr_stmt|;
name|a
operator|->
name|q_flags
operator||=
name|QDELIVERED
operator||
name|QEXPANDED
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HESIOD
case|case
name|UDB_HESIOD
case|:
name|key
operator|.
name|data
operator|=
name|keybuf
expr_stmt|;
name|key
operator|.
name|size
operator|=
name|keylen
expr_stmt|;
if|if
condition|(
name|tTd
argument_list|(
literal|28
argument_list|,
literal|80
argument_list|)
condition|)
name|printf
argument_list|(
literal|"udbexpand: trying %s (%d) via hesiod\n"
argument_list|,
name|keybuf
argument_list|,
name|keylen
argument_list|)
expr_stmt|;
comment|/* look up the key via hesiod */
name|i
operator|=
name|hes_udb_get
argument_list|(
operator|&
name|key
argument_list|,
operator|&
name|info
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|<
literal|0
condition|)
block|{
name|syserr
argument_list|(
literal|"udbexpand: hesiod-get %.*s stat %d"
argument_list|,
name|key
operator|.
name|size
argument_list|,
name|key
operator|.
name|data
argument_list|,
name|i
argument_list|)
expr_stmt|;
return|return
name|EX_TEMPFAIL
return|;
block|}
elseif|else
if|if
condition|(
name|i
operator|>
literal|0
operator|||
name|info
operator|.
name|size
operator|<=
literal|0
condition|)
block|{
if|#
directive|if
name|HES_GETMAILHOST
name|struct
name|hes_postoffice
modifier|*
name|hp
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|tTd
argument_list|(
literal|28
argument_list|,
literal|2
argument_list|)
condition|)
name|printf
argument_list|(
literal|"udbexpand: no match on %s (%d)\n"
argument_list|,
name|keybuf
argument_list|,
name|keylen
argument_list|)
expr_stmt|;
if|#
directive|if
name|HES_GETMAILHOST
if|if
condition|(
name|tTd
argument_list|(
literal|28
argument_list|,
literal|8
argument_list|)
condition|)
name|printf
argument_list|(
literal|"  ... trying hes_getmailhost(%s)\n"
argument_list|,
name|a
operator|->
name|q_user
argument_list|)
expr_stmt|;
name|hp
operator|=
name|hes_getmailhost
argument_list|(
name|a
operator|->
name|q_user
argument_list|)
expr_stmt|;
if|if
condition|(
name|hp
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|hes_error
argument_list|()
operator|==
name|HES_ER_NET
condition|)
block|{
name|syserr
argument_list|(
literal|"udbexpand: hesiod-getmail %s stat %d"
argument_list|,
name|a
operator|->
name|q_user
argument_list|,
name|hes_error
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|EX_TEMPFAIL
return|;
block|}
if|if
condition|(
name|tTd
argument_list|(
literal|28
argument_list|,
literal|2
argument_list|)
condition|)
name|printf
argument_list|(
literal|"hes_getmailhost(%s): %d\n"
argument_list|,
argument|a->q_user
argument_list|,
argument|hes_error(); 					continue; 				} 				sprintf(info.data,
literal|"%s@%s"
argument|, 					hp->po_name, hp->po_host); 				info.size = strlen(info.data);
else|#
directive|else
argument|continue;
endif|#
directive|endif
argument|} 			if (tTd(
literal|28
argument|,
literal|80
argument|)) 				printf(
literal|"udbexpand: match %.*s: %.*s\n"
argument|, 					key.size, key.data, info.size, info.data); 			a->q_flags&= ~QSELFREF;  			if (bitset(EF_VRFYONLY, e->e_flags)) 			{ 				a->q_flags |= QVERIFIED; 				return EX_OK; 			}  			breakout = TRUE; 			if (info.size< sizeof buf) 				user = buf; 			else 				user = xalloc(info.size +
literal|1
argument|); 			bcopy(info.data, user, info.size); 			user[info.size] =
literal|'\0'
argument|;  			message(
literal|"hesioded to %s"
argument|, user);
ifdef|#
directive|ifdef
name|LOG
argument|if (LogLevel>=
literal|10
argument|) 				syslog(LOG_INFO,
literal|"%s: hesiod %.100s => %s"
argument|, 					e->e_id, e->e_to, 					shortenstring(user,
literal|203
argument|));
endif|#
directive|endif
argument|naddrs = sendtolist(user, a, sendq, aliaslevel +
literal|1
argument|, e);  			if (user != buf) 				free(user);  			if (naddrs>
literal|0
argument|&& !bitset(QSELFREF, a->q_flags)) 			{ 				if (tTd(
literal|28
argument|,
literal|5
argument|)) 				{ 					printf(
literal|"udbexpand: QDONTSEND "
argument|); 					printaddr(a, FALSE); 				} 				a->q_flags |= QDONTSEND; 			}
comment|/* 			**  If this address has a -request address, reflect 			**  it into the envelope. 			*/
argument|(void) strcpy(keybuf, a->q_user); 			(void) strcat(keybuf,
literal|":mailsender"
argument|); 			keylen = strlen(keybuf); 			key.data = keybuf; 			key.size = keylen; 			i = hes_udb_get(&key,&info); 			if (i !=
literal|0
argument||| info.size<=
literal|0
argument|) 				break; 			a->q_owner = xalloc(info.size +
literal|1
argument|); 			bcopy(info.data, a->q_owner, info.size); 			a->q_owner[info.size] =
literal|'\0'
argument|; 			break;
endif|#
directive|endif
comment|/* HESIOD */
argument|case UDB_REMOTE:
comment|/* not yet implemented */
argument|continue;  		  case UDB_FORWARD: 			if (bitset(EF_VRFYONLY, e->e_flags)) 				return EX_OK; 			i = strlen(up->udb_fwdhost) + strlen(a->q_user) +
literal|1
argument|; 			if (i< sizeof buf) 				user = buf; 			else 				user = xalloc(i +
literal|1
argument|); 			(void) sprintf(user,
literal|"%s@%s"
argument|, a->q_user, up->udb_fwdhost); 			message(
literal|"expanded to %s"
argument|, user); 			a->q_flags&= ~QSELFREF; 			naddrs = sendtolist(user, a, sendq, aliaslevel +
literal|1
argument|, e); 			if (naddrs>
literal|0
argument|&& !bitset(QSELFREF, a->q_flags)) 			{ 				if (tTd(
literal|28
argument|,
literal|5
argument|)) 				{ 					printf(
literal|"udbexpand: QDONTSEND "
argument|); 					printaddr(a, FALSE); 				} 				a->q_flags |= QDONTSEND; 			} 			if (user != buf) 				free(user); 			breakout = TRUE; 			break;  		  case UDB_EOLIST: 			breakout = TRUE; 			continue;  		  default:
comment|/* unknown entry type */
argument|continue; 		} 	} 	return EX_OK; }
comment|/* **  UDBSENDER -- return canonical external name of sender, given local name ** **	Parameters: **		sender -- the name of the sender on the local machine. ** **	Returns: **		The external name for this sender, if derivable from the **			database. **		NULL -- if nothing is changed from the database. ** **	Side Effects: **		none. */
argument|char * udbsender(sender) 	char *sender; { 	extern char *udbmatch();  	return udbmatch(sender,
literal|"mailname"
argument|); }   char * udbmatch(user, field) 	char *user; 	char *field; { 	register char *p; 	register struct udbent *up; 	int i; 	int keylen; 	DBT key
argument_list|,
argument|info; 	char keybuf[MAXKEY];  	if (tTd(
literal|28
argument|,
literal|1
argument|)) 		printf(
literal|"udbmatch(%s, %s)\n"
argument|, user, field);  	if (!UdbInitialized) 	{ 		if (_udbx_init() == EX_TEMPFAIL) 			return NULL; 	}
comment|/* short circuit if no spec */
argument|if (UdbSpec == NULL || UdbSpec[
literal|0
argument|] ==
literal|'\0'
argument|) 		return NULL;
comment|/* short circuit name begins with '\\' since it can't possibly match */
argument|if (user[
literal|0
argument|] ==
literal|'\\'
argument|) 		return NULL;
comment|/* long names can never match and are a pain to deal with */
argument|if ((strlen(user) + strlen(field))> sizeof keybuf -
literal|4
argument|) 		return NULL;
comment|/* names beginning with colons indicate metadata */
argument|if (user[
literal|0
argument|] ==
literal|':'
argument|) 		return NULL;
comment|/* build database key */
argument|(void) strcpy(keybuf, user); 	(void) strcat(keybuf,
literal|":"
argument|); 	(void) strcat(keybuf, field); 	keylen = strlen(keybuf);  	for (up = UdbEnts; up->udb_type != UDB_EOLIST; up++) 	{
comment|/* 		**  Select action based on entry type. 		*/
argument|switch (up->udb_type) 		{
ifdef|#
directive|ifdef
name|NEWDB
argument|case UDB_DBFETCH: 			key.data = keybuf; 			key.size = keylen; 			i = (*up->udb_dbp->get)(up->udb_dbp,&key,&info,
literal|0
argument|); 			if (i !=
literal|0
argument||| info.size<=
literal|0
argument|) 			{ 				if (tTd(
literal|28
argument|,
literal|2
argument|)) 					printf(
literal|"udbmatch: no match on %s (%d) via db\n"
argument|, 							keybuf, keylen); 				continue; 			}  			p = xalloc(info.size +
literal|1
argument|); 			bcopy(info.data, p, info.size); 			p[info.size] =
literal|'\0'
argument|; 			if (tTd(
literal|28
argument|,
literal|1
argument|)) 				printf(
literal|"udbmatch ==> %s\n"
argument|, p); 			return p; 			break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HESIOD
argument|case UDB_HESIOD: 			key.data = keybuf; 			key.size = keylen; 			i = hes_udb_get(&key,&info);  			if (i !=
literal|0
argument||| info.size<=
literal|0
argument|) 			{ 				if (tTd(
literal|28
argument|,
literal|2
argument|)) 					printf(
literal|"udbmatch: no match on %s (%d) via hesiod\n"
argument|, 							keybuf, keylen); 				continue; 			}  			p = xalloc(info.size +
literal|1
argument|); 			bcopy(info.data, p, info.size); 			p[info.size] =
literal|'\0'
argument|; 			if (tTd(
literal|28
argument|,
literal|1
argument|)) 				printf(
literal|"udbmatch ==> %s\n"
argument|, p); 			return p;
endif|#
directive|endif
comment|/* HESIOD */
argument|} 	}  	if (strcmp(field,
literal|"mailname"
argument|) !=
literal|0
argument|) 		return NULL;
comment|/* 	**  Nothing yet.  Search again for a default case.  But only 	**  use it if we also have a forward (:maildrop) pointer already 	**  in the database. 	*/
comment|/* build database key */
argument|(void) strcpy(keybuf, user); 	(void) strcat(keybuf,
literal|":maildrop"
argument|); 	keylen = strlen(keybuf);  	for (up = UdbEnts; up->udb_type != UDB_EOLIST; up++) 	{ 		switch (up->udb_type) 		{
ifdef|#
directive|ifdef
name|NEWDB
argument|case UDB_DBFETCH:
comment|/* get the default case for this database */
argument|if (up->udb_default == NULL) 			{ 				key.data =
literal|":default:mailname"
argument|; 				key.size = strlen(key.data); 				i = (*up->udb_dbp->get)(up->udb_dbp,&key,&info,
literal|0
argument|); 				if (i !=
literal|0
argument||| info.size<=
literal|0
argument|) 				{
comment|/* no default case */
argument|up->udb_default =
literal|""
argument|; 					continue; 				}
comment|/* save the default case */
argument|up->udb_default = xalloc(info.size +
literal|1
argument|); 				bcopy(info.data, up->udb_default, info.size); 				up->udb_default[info.size] =
literal|'\0'
argument|; 			} 			else if (up->udb_default[
literal|0
argument|] ==
literal|'\0'
argument|) 				continue;
comment|/* we have a default case -- verify user:maildrop */
argument|key.data = keybuf; 			key.size = keylen; 			i = (*up->udb_dbp->get)(up->udb_dbp,&key,&info,
literal|0
argument|); 			if (i !=
literal|0
argument||| info.size<=
literal|0
argument|) 			{
comment|/* nope -- no aliasing for this user */
argument|continue; 			}
comment|/* they exist -- build the actual address */
argument|p = xalloc(strlen(user) + strlen(up->udb_default) +
literal|2
argument|); 			(void) strcpy(p, user); 			(void) strcat(p,
literal|"@"
argument|); 			(void) strcat(p, up->udb_default); 			if (tTd(
literal|28
argument|,
literal|1
argument|)) 				printf(
literal|"udbmatch ==> %s\n"
argument|, p); 			return p; 			break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HESIOD
argument|case UDB_HESIOD:
comment|/* get the default case for this database */
argument|if (up->udb_default == NULL) 			{ 				key.data =
literal|":default:mailname"
argument|; 				key.size = strlen(key.data); 				i = hes_udb_get(&key,&info);   				if (i !=
literal|0
argument||| info.size<=
literal|0
argument|) 				{
comment|/* no default case */
argument|up->udb_default =
literal|""
argument|; 					continue; 				}
comment|/* save the default case */
argument|up->udb_default = xalloc(info.size +
literal|1
argument|); 				bcopy(info.data, up->udb_default, info.size); 				up->udb_default[info.size] =
literal|'\0'
argument|; 			} 			else if (up->udb_default[
literal|0
argument|] ==
literal|'\0'
argument|) 				continue;
comment|/* we have a default case -- verify user:maildrop */
argument|key.data = keybuf; 			key.size = keylen; 			i = hes_udb_get(&key,&info); 			if (i !=
literal|0
argument||| info.size<=
literal|0
argument|) 			{
comment|/* nope -- no aliasing for this user */
argument|continue; 			}
comment|/* they exist -- build the actual address */
argument|p = xalloc(strlen(user) + strlen(up->udb_default) +
literal|2
argument|); 			(void) strcpy(p, user); 			(void) strcat(p,
literal|"@"
argument|); 			(void) strcat(p, up->udb_default); 			if (tTd(
literal|28
argument|,
literal|1
argument|)) 				printf(
literal|"udbmatch ==> %s\n"
argument|, p); 			return p; 			break;
endif|#
directive|endif
comment|/* HESIOD */
argument|} 	}
comment|/* still nothing....  too bad */
argument|return NULL; }
comment|/* **  UDB_MAP_LOOKUP -- look up arbitrary entry in user database map ** **	Parameters: **		map -- the map being queried. **		name -- the name to look up. **		av -- arguments to the map lookup. **		statp -- to get any error status. ** **	Returns: **		NULL if name not found in map. **		The rewritten name otherwise. */
argument|char * udb_map_lookup(map, name, av, statp) 	MAP *map; 	char *name; 	char **av; 	int *statp; { 	char *val; 	char *key; 	char keybuf[MAXNAME +
literal|1
argument|];  	if (tTd(
literal|28
argument|,
literal|20
argument|) || tTd(
literal|38
argument|,
literal|20
argument|)) 		printf(
literal|"udb_map_lookup(%s, %s)\n"
argument|, map->map_mname, name);  	if (bitset(MF_NOFOLDCASE, map->map_mflags)) 	{ 		key = name; 	} 	else 	{ 		int keysize = strlen(name);  		if (keysize> sizeof keybuf -
literal|1
argument|) 			keysize = sizeof keybuf -
literal|1
argument|; 		bcopy(name, keybuf, keysize); 		keybuf[keysize] =
literal|'\0'
argument|; 		makelower(keybuf); 		key = keybuf; 	} 	val = udbmatch(key, map->map_file); 	if (val == NULL) 		return NULL; 	if (bitset(MF_MATCHONLY, map->map_mflags)) 		return map_rewrite(map, name, strlen(name), NULL); 	else 		return map_rewrite(map, val, strlen(val), av); }
comment|/* **  _UDBX_INIT -- parse the UDB specification, opening any valid entries. ** **	Parameters: **		none. ** **	Returns: **		EX_TEMPFAIL -- if it appeared it couldn't get hold of a **			database due to a host being down or some similar **			(recoverable) situation. **		EX_OK -- otherwise. ** **	Side Effects: **		Fills in the UdbEnts structure from UdbSpec. */
define|#
directive|define
name|MAXUDBOPTS
value|27
argument|int _udbx_init() { 	register char *p; 	register struct udbent *up;  	if (UdbInitialized) 		return EX_OK;
ifdef|#
directive|ifdef
name|UDB_DEFAULT_SPEC
argument|if (UdbSpec == NULL) 		UdbSpec = UDB_DEFAULT_SPEC;
endif|#
directive|endif
argument|p = UdbSpec; 	up = UdbEnts; 	while (p != NULL) 	{ 		char *spec; 		int nopts;
if|#
directive|if
literal|0
argument|auto int rcode; 		int nmx; 		int i; 		register struct hostent *h; 		char *mxhosts[MAXMXHOSTS + 1];
endif|#
directive|endif
argument|struct option opts[MAXUDBOPTS +
literal|1
argument|];  		while (*p ==
literal|' '
argument||| *p ==
literal|'\t'
argument||| *p ==
literal|','
argument|) 			p++; 		if (*p ==
literal|'\0'
argument|) 			break; 		spec = p; 		p = strchr(p,
literal|','
argument|); 		if (p != NULL) 			*p++ =
literal|'\0'
argument|;
comment|/* extract options */
argument|nopts = _udb_parsespec(spec, opts, MAXUDBOPTS);
comment|/* 		**  Decode database specification. 		** 		**	In the sendmail tradition, the leading character 		**	defines the semantics of the rest of the entry. 		** 		**	+hostname --	send a datagram to the udb server 		**			on host "hostname" asking for the 		**			home mail server for this user. 		**	*hostname --	similar to +hostname, except that the 		**			hostname is searched as an MX record; 		**			resulting hosts are searched as for 		**			+mxhostname.  If no MX host is found, 		**			this is the same as +hostname. 		**	@hostname --	forward email to the indicated host. 		**			This should be the last in the list, 		**			since it always matches the input. 		**	/dbname	 --	search the named database on the local 		**			host using the Berkeley db package. 		**	Hesiod --	search the named database with BIND 		**			using the MIT Hesiod package. 		*/
argument|switch (*spec) 		{
if|#
directive|if
literal|0
argument|case '+':
comment|/* search remote database */
argument|case '*':
comment|/* search remote database (expand MX) */
argument|if (*spec == '*') 			{
if|#
directive|if
name|NAMED_BIND
argument|nmx = getmxrr(spec + 1, mxhosts, FALSE,&rcode);
else|#
directive|else
argument|mxhosts[0] = spec + 1; 				nmx = 1; 				rcode = 0;
endif|#
directive|endif
argument|if (tTd(28, 16)) 				{ 					int i;  					printf("getmxrr(%s): %d", spec + 1, nmx); 					for (i = 0; i<= nmx; i++) 						printf(" %s", mxhosts[i]); 					printf("\n"); 				} 			} 			else 			{ 				nmx = 1; 				mxhosts[0] = spec + 1; 			}  			for (i = 0; i< nmx; i++) 			{ 				h = sm_gethostbyname(mxhosts[i]); 				if (h == NULL) 					continue; 				up->udb_type = UDB_REMOTE; 				up->udb_addr.sin_family = h->h_addrtype; 				bcopy(h->h_addr_list[0], 				      (char *)&up->udb_addr.sin_addr, 				      INADDRSZ); 				up->udb_addr.sin_port = UdbPort; 				up->udb_timeout = UdbTimeout; 				up++; 			}
comment|/* set up a datagram socket */
argument|if (UdbSock< 0) 			{ 				UdbSock = socket(AF_INET, SOCK_DGRAM, 0); 				(void) fcntl(UdbSock, F_SETFD, 1); 			} 			break;
endif|#
directive|endif
argument|case
literal|'@'
argument|:
comment|/* forward to remote host */
argument|up->udb_type = UDB_FORWARD; 			up->udb_fwdhost = spec +
literal|1
argument|; 			up++; 			break;
ifdef|#
directive|ifdef
name|HESIOD
argument|case
literal|'h'
argument|:
comment|/* use hesiod */
argument|case
literal|'H'
argument|: 			if (strcasecmp(spec,
literal|"hesiod"
argument|) !=
literal|0
argument|) 				goto badspec; 			up->udb_type = UDB_HESIOD; 			up++; 			break;
endif|#
directive|endif
comment|/* HESIOD */
ifdef|#
directive|ifdef
name|NEWDB
argument|case
literal|'/'
argument|:
comment|/* look up remote name */
argument|up->udb_dbname = spec; 			errno =
literal|0
argument|; 			up->udb_dbp = dbopen(spec, O_RDONLY,
literal|0644
argument|, DB_BTREE, NULL); 			if (up->udb_dbp == NULL) 			{ 				if (tTd(
literal|28
argument|,
literal|1
argument|)) 				{ 					int saveerrno = errno;  					printf(
literal|"dbopen(%s): %s"
argument|, 						spec, errstring(errno)); 					errno = saveerrno; 				} 				if (errno != ENOENT&& errno != EACCES) 				{
ifdef|#
directive|ifdef
name|LOG
argument|if (LogLevel>
literal|2
argument|) 						syslog(LOG_ERR,
literal|"dbopen(%s): %s"
argument|, 							spec, errstring(errno));
endif|#
directive|endif
argument|up->udb_type = UDB_EOLIST; 					goto tempfail; 				} 				break; 			} 			up->udb_type = UDB_DBFETCH; 			up++; 			break;
endif|#
directive|endif
argument|default: badspec: 			syserr(
literal|"Unknown UDB spec %s"
argument|, spec); 			break; 		} 	} 	up->udb_type = UDB_EOLIST;  	if (tTd(
literal|28
argument|,
literal|4
argument|)) 	{ 		for (up = UdbEnts; up->udb_type != UDB_EOLIST; up++) 		{ 			switch (up->udb_type) 			{
ifdef|#
directive|ifdef
name|DAEMON
argument|case UDB_REMOTE: 				printf(
literal|"REMOTE: addr %s, timeo %d\n"
argument|, 					anynet_ntoa((SOCKADDR *)&up->udb_addr), 					up->udb_timeout); 				break;
endif|#
directive|endif
argument|case UDB_DBFETCH:
ifdef|#
directive|ifdef
name|NEWDB
argument|printf(
literal|"FETCH: file %s\n"
argument|, 					up->udb_dbname);
else|#
directive|else
argument|printf(
literal|"FETCH\n"
argument|);
endif|#
directive|endif
argument|break;  			  case UDB_FORWARD: 				printf(
literal|"FORWARD: host %s\n"
argument|, 					up->udb_fwdhost); 				break;  			  case UDB_HESIOD: 				printf(
literal|"HESIOD\n"
argument|); 				break;  			  default: 				printf(
literal|"UNKNOWN\n"
argument|); 				break; 			} 		} 	}  	UdbInitialized = TRUE; 	errno =
literal|0
argument|; 	return EX_OK;
comment|/* 	**  On temporary failure, back out anything we've already done 	*/
argument|tempfail:
ifdef|#
directive|ifdef
name|NEWDB
argument|for (up = UdbEnts; up->udb_type != UDB_EOLIST; up++) 	{ 		if (up->udb_type == UDB_DBFETCH) 		{ 			(*up->udb_dbp->close)(up->udb_dbp); 		} 	}
endif|#
directive|endif
argument|return EX_TEMPFAIL; }  int _udb_parsespec(udbspec, opt, maxopts) 	char *udbspec; 	struct option opt[]; 	int maxopts; { 	register char *spec; 	register char *spec_end; 	register int optnum;  	spec_end = strchr(udbspec,
literal|':'
argument|); 	for (optnum =
literal|0
argument|; optnum< maxopts&& (spec = spec_end) != NULL; optnum++) 	{ 		register char *p;  		while (isascii(*spec)&& isspace(*spec)) 			spec++; 		spec_end = strchr(spec,
literal|':'
argument|); 		if (spec_end != NULL) 			*spec_end++ =
literal|'\0'
argument|;  		opt[optnum].name = spec; 		opt[optnum].val = NULL; 		p = strchr(spec,
literal|'='
argument|); 		if (p != NULL) 			opt[optnum].val = ++p; 	} 	return optnum; }
ifdef|#
directive|ifdef
name|HESIOD
argument|int hes_udb_get(key, info) 	DBT *key; 	DBT *info; { 	char *name
argument_list|,
argument|*type; 	char *p
argument_list|,
argument|**hp; 	char kbuf[MAXKEY +
literal|1
argument|];  	strcpy(kbuf, key->data); 	name = kbuf; 	type = strrchr(name,
literal|':'
argument|); 	if (type == NULL) 		return
literal|1
argument|; 	*type++ =
literal|'\0'
argument|; 	if (strchr(name,
literal|'@'
argument|) != NULL) 		return
literal|1
argument|;  	if (tTd(
literal|28
argument|,
literal|1
argument|)) 		printf(
literal|"hes_udb_get(%s, %s)\n"
argument|, name, type);
comment|/* make the hesiod query */
argument|hp = hes_resolve(name, type); 	*--type =
literal|':'
argument|; 	if (hp == NULL || hp[
literal|0
argument|] == NULL) 	{
comment|/* network problem or timeout */
argument|if (hes_error() == HES_ER_NET) 			return -
literal|1
argument|;  		return
literal|1
argument|; 	} 	else 	{
comment|/* 		**  If there are multiple matches, just return the 		**  first one. 		** 		**  XXX These should really be returned; for example, 		**  XXX it is legal for :maildrop to be multi-valued. 		*/
argument|info->data = hp[
literal|0
argument|]; 		info->size = (size_t) strlen(info->data); 	}  	if (tTd(
literal|28
argument|,
literal|80
argument|)) 		printf(
literal|"hes_udb_get => %s\n"
argument|, *hp);  	return
literal|0
argument|; }
endif|#
directive|endif
comment|/* HESIOD */
else|#
directive|else
comment|/* not USERDB */
argument|int udbexpand(a, sendq, aliaslevel, e) 	ADDRESS *a; 	ADDRESS **sendq; 	int aliaslevel; 	ENVELOPE *e; { 	return EX_OK; }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USERDB */
end_comment

end_unit

