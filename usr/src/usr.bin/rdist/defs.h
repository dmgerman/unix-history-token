begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)defs.h	5.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/*  * The version number should be changed whenever the protocol changes.  */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|3
end_define

begin_define
define|#
directive|define
name|MAILCMD
value|"/usr/lib/sendmail -oi -t"
end_define

begin_comment
comment|/* defines for yacc */
end_comment

begin_define
define|#
directive|define
name|EQUAL
value|1
end_define

begin_define
define|#
directive|define
name|LP
value|2
end_define

begin_define
define|#
directive|define
name|RP
value|3
end_define

begin_define
define|#
directive|define
name|SM
value|4
end_define

begin_define
define|#
directive|define
name|ARROW
value|5
end_define

begin_define
define|#
directive|define
name|COLON
value|6
end_define

begin_define
define|#
directive|define
name|DCOLON
value|7
end_define

begin_define
define|#
directive|define
name|NAME
value|8
end_define

begin_define
define|#
directive|define
name|STRING
value|9
end_define

begin_define
define|#
directive|define
name|INSTALL
value|10
end_define

begin_define
define|#
directive|define
name|NOTIFY
value|11
end_define

begin_define
define|#
directive|define
name|EXCEPT
value|12
end_define

begin_define
define|#
directive|define
name|PATTERN
value|13
end_define

begin_define
define|#
directive|define
name|SPECIAL
value|14
end_define

begin_define
define|#
directive|define
name|OPTION
value|15
end_define

begin_comment
comment|/* lexical definitions */
end_comment

begin_define
define|#
directive|define
name|QUOTE
value|0200
end_define

begin_comment
comment|/* used internally for quoted characters */
end_comment

begin_define
define|#
directive|define
name|TRIM
value|0177
end_define

begin_comment
comment|/* Mask to strip quote bit */
end_comment

begin_comment
comment|/* table sizes */
end_comment

begin_define
define|#
directive|define
name|HASHSIZE
value|1021
end_define

begin_define
define|#
directive|define
name|INMAX
value|3500
end_define

begin_comment
comment|/* option flags */
end_comment

begin_define
define|#
directive|define
name|VERIFY
value|0x1
end_define

begin_define
define|#
directive|define
name|WHOLE
value|0x2
end_define

begin_define
define|#
directive|define
name|YOUNGER
value|0x4
end_define

begin_define
define|#
directive|define
name|COMPARE
value|0x8
end_define

begin_define
define|#
directive|define
name|REMOVE
value|0x10
end_define

begin_define
define|#
directive|define
name|FOLLOW
value|0x20
end_define

begin_define
define|#
directive|define
name|IGNLNKS
value|0x40
end_define

begin_comment
comment|/* expand type definitions */
end_comment

begin_define
define|#
directive|define
name|E_VARS
value|0x1
end_define

begin_define
define|#
directive|define
name|E_SHELL
value|0x2
end_define

begin_define
define|#
directive|define
name|E_TILDE
value|0x4
end_define

begin_define
define|#
directive|define
name|E_ALL
value|0x7
end_define

begin_comment
comment|/* actions for lookup() */
end_comment

begin_define
define|#
directive|define
name|LOOKUP
value|0
end_define

begin_define
define|#
directive|define
name|INSERT
value|1
end_define

begin_define
define|#
directive|define
name|REPLACE
value|2
end_define

begin_define
define|#
directive|define
name|ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDIR)
end_define

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|x
parameter_list|)
value|(struct x *) malloc(sizeof(struct x))
end_define

begin_struct
struct|struct
name|namelist
block|{
comment|/* for making lists of strings */
name|char
modifier|*
name|n_name
decl_stmt|;
name|struct
name|namelist
modifier|*
name|n_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|subcmd
block|{
name|short
name|sc_type
decl_stmt|;
comment|/* type - INSTALL,NOTIFY,EXCEPT,SPECIAL */
name|short
name|sc_options
decl_stmt|;
name|char
modifier|*
name|sc_name
decl_stmt|;
name|struct
name|namelist
modifier|*
name|sc_args
decl_stmt|;
name|struct
name|subcmd
modifier|*
name|sc_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cmd
block|{
name|int
name|c_type
decl_stmt|;
comment|/* type - ARROW,DCOLON */
name|char
modifier|*
name|c_name
decl_stmt|;
comment|/* hostname or time stamp file name */
name|char
modifier|*
name|c_label
decl_stmt|;
comment|/* label for partial update */
name|struct
name|namelist
modifier|*
name|c_files
decl_stmt|;
name|struct
name|subcmd
modifier|*
name|c_cmds
decl_stmt|;
name|struct
name|cmd
modifier|*
name|c_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linkbuf
block|{
name|ino_t
name|inum
decl_stmt|;
name|dev_t
name|devnum
decl_stmt|;
name|int
name|count
decl_stmt|;
name|char
name|pathname
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|struct
name|linkbuf
modifier|*
name|nextp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debugging flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NOP flag, don't execute commands */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|qflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Quiet. don't print messages */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|options
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global options */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nerrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of errors seen */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote file descriptor */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|iamremote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* acting as remote server */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|tmpfile
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file name for logging changes */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|linkbuf
modifier|*
name|ihead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of files with more than one link */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to static area used by getpwent */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|group
modifier|*
name|gr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to static area used by getgrent */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|host
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* host name of master copy */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|buf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* general purpose buffer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system error number */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|makestr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|namelist
modifier|*
name|makenl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|subcmd
modifier|*
name|makesubcmd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|namelist
modifier|*
name|lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|namelist
modifier|*
name|expand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|exptilde
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

end_unit

