begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)finger.h	5.7 (Berkeley) %G%  */
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

begin_include
include|#
directive|include
file|"extern.h"
end_include

end_unit

