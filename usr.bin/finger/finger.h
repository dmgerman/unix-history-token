begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Tony Nardo of the Johns Hopkins University/Applied Physics Lab.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)finger.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|person
block|{
name|uid_t
name|uid
decl_stmt|;
comment|/* user id */
name|char
modifier|*
name|dir
decl_stmt|;
comment|/* user's home directory */
name|char
modifier|*
name|homephone
decl_stmt|;
comment|/* pointer to home phone no. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* login name */
name|char
modifier|*
name|office
decl_stmt|;
comment|/* pointer to office name */
name|char
modifier|*
name|officephone
decl_stmt|;
comment|/* pointer to office phone no. */
name|char
modifier|*
name|realname
decl_stmt|;
comment|/* pointer to full name */
name|char
modifier|*
name|shell
decl_stmt|;
comment|/* user's shell */
name|time_t
name|mailread
decl_stmt|;
comment|/* last time mail was read */
name|time_t
name|mailrecv
decl_stmt|;
comment|/* last time mail was received */
name|struct
name|where
modifier|*
name|whead
decl_stmt|,
modifier|*
name|wtail
decl_stmt|;
comment|/* list of where user is or has been */
block|}
name|PERSON
typedef|;
end_typedef

begin_enum
enum|enum
name|status
block|{
name|LASTLOG
block|,
name|LOGGEDIN
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|where
block|{
name|struct
name|where
modifier|*
name|next
decl_stmt|;
comment|/* next place user is or has been */
name|enum
name|status
name|info
decl_stmt|;
comment|/* type/status of request */
name|short
name|writable
decl_stmt|;
comment|/* tty is writable */
name|time_t
name|loginat
decl_stmt|;
comment|/* time of (last) login */
name|time_t
name|idletime
decl_stmt|;
comment|/* how long idle (if logged in) */
name|char
name|tty
index|[
name|UT_LINESIZE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* null terminated tty line */
name|char
name|host
index|[
name|UT_HOSTSIZE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* null terminated remote host name */
block|}
name|WHERE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UNPRIV_NAME
value|"nobody"
end_define

begin_comment
comment|/* Preferred privilege level */
end_comment

begin_define
define|#
directive|define
name|UNPRIV_UGID
value|32767
end_define

begin_comment
comment|/* Default uid and gid */
end_comment

begin_define
define|#
directive|define
name|OUTPUT_MAX
value|100000
end_define

begin_comment
comment|/* Do not keep listinging forever */
end_comment

begin_define
define|#
directive|define
name|TIME_LIMIT
value|360
end_define

begin_comment
comment|/* Do not keep listinging forever */
end_comment

begin_include
include|#
directive|include
file|"extern.h"
end_include

end_unit

