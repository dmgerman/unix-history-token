begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Tony Nardo of the Johns Hopkins University/Applied Physics Lab.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)finger.h	5.5 (Berkeley) 6/1/90  */
end_comment

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<utmp.h>
end_include

begin_comment
comment|/*  * All unique persons are linked in a list headed by "head" and linkd  * by the "next" field, as well as kept in a hash table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|person
block|{
name|struct
name|person
modifier|*
name|next
decl_stmt|;
comment|/* link to next person */
name|struct
name|person
modifier|*
name|hlink
decl_stmt|;
comment|/* link to next person in hash bucket */
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
name|struct
name|where
modifier|*
name|whead
decl_stmt|,
modifier|*
name|wtail
decl_stmt|;
comment|/* list of where he is or has been */
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
comment|/* next place he is or has been */
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
name|HBITS
value|8
end_define

begin_comment
comment|/* number of bits in hash code */
end_comment

begin_define
define|#
directive|define
name|HSIZE
value|(1<< 8)
end_define

begin_comment
comment|/* hash table size */
end_comment

begin_define
define|#
directive|define
name|HMASK
value|(HSIZE - 1)
end_define

begin_comment
comment|/* hash code mask */
end_comment

begin_decl_stmt
name|PERSON
modifier|*
name|htab
index|[
name|HSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the buckets */
end_comment

begin_decl_stmt
name|PERSON
modifier|*
name|phead
decl_stmt|,
modifier|*
name|ptail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the linked list of all people */
end_comment

begin_decl_stmt
name|int
name|entries
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of people */
end_comment

begin_decl_stmt
name|PERSON
modifier|*
name|enter_person
argument_list|()
decl_stmt|,
modifier|*
name|find_person
argument_list|()
decl_stmt|,
modifier|*
name|palloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|WHERE
modifier|*
name|walloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|tbuf
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temp buffer for anybody */
end_comment

end_unit

