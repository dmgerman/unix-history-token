begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)finger.h	5.4 (Berkeley) %G%  */
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

