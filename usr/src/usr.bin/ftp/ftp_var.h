begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)ftp_var.h	5.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * FTP global variables.  */
end_comment

begin_comment
comment|/*  * Options and other state info.  */
end_comment

begin_decl_stmt
name|int
name|trace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trace packets exchanged */
end_comment

begin_decl_stmt
name|int
name|hash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print # for each buffer transferred */
end_comment

begin_decl_stmt
name|int
name|sendport
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use PORT cmd for each data connection */
end_comment

begin_decl_stmt
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print messages coming back from server */
end_comment

begin_decl_stmt
name|int
name|connected
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* connected to server */
end_comment

begin_decl_stmt
name|int
name|fromatty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input is from a terminal */
end_comment

begin_decl_stmt
name|int
name|interactive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interactively prompt on m* cmds */
end_comment

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debugging level */
end_comment

begin_decl_stmt
name|int
name|bell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ring bell on cmd completion */
end_comment

begin_decl_stmt
name|int
name|doglob
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* glob local file names */
end_comment

begin_decl_stmt
name|int
name|autologin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* establish user account on connection */
end_comment

begin_decl_stmt
name|int
name|proxy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* proxy server connection active */
end_comment

begin_decl_stmt
name|int
name|proxflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* proxy connection exists */
end_comment

begin_decl_stmt
name|int
name|sunique
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* store files on server with unique name */
end_comment

begin_decl_stmt
name|int
name|runique
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* store local files with unique name */
end_comment

begin_decl_stmt
name|int
name|mcase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* map upper to lower case for mget names */
end_comment

begin_decl_stmt
name|int
name|ntflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use ntin ntout tables for name translation */
end_comment

begin_decl_stmt
name|int
name|mapflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use mapin mapout templates on file names */
end_comment

begin_decl_stmt
name|int
name|code
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return/reply code for ftp command */
end_comment

begin_decl_stmt
name|int
name|crflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if 1, strip car. rets. on ascii gets */
end_comment

begin_decl_stmt
name|char
name|pasv
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* passive port for proxy data connection */
end_comment

begin_decl_stmt
name|char
modifier|*
name|altarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* argv[1] with no shell-like preprocessing  */
end_comment

begin_decl_stmt
name|char
name|ntin
index|[
literal|17
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input translation table */
end_comment

begin_decl_stmt
name|char
name|ntout
index|[
literal|17
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output translation table */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_decl_stmt
name|char
name|mapin
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input map template */
end_comment

begin_decl_stmt
name|char
name|mapout
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output map template */
end_comment

begin_decl_stmt
name|char
name|typename
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of file transfer type */
end_comment

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file transfer type */
end_comment

begin_decl_stmt
name|char
name|structname
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of file transfer structure */
end_comment

begin_decl_stmt
name|int
name|stru
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file transfer structure */
end_comment

begin_decl_stmt
name|char
name|formname
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of file transfer format */
end_comment

begin_decl_stmt
name|int
name|form
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file transfer format */
end_comment

begin_decl_stmt
name|char
name|modename
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of file transfer mode */
end_comment

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file transfer mode */
end_comment

begin_decl_stmt
name|char
name|bytename
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local byte size in ascii */
end_comment

begin_decl_stmt
name|int
name|bytesize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local byte size in binary */
end_comment

begin_decl_stmt
name|char
modifier|*
name|hostname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of host connected to */
end_comment

begin_decl_stmt
name|struct
name|servent
modifier|*
name|sp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* service spec for tcp/ftp */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
name|jmp_buf
name|toplevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* non-local goto stuff for cmd scanner */
end_comment

begin_decl_stmt
name|char
name|line
index|[
literal|200
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input line buffer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|stringbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current scan point in line buffer */
end_comment

begin_decl_stmt
name|char
name|argbuf
index|[
literal|200
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* argument storage buffer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|argbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current storage point in arg buffer */
end_comment

begin_decl_stmt
name|int
name|margc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of arguments on input line */
end_comment

begin_decl_stmt
name|char
modifier|*
name|margv
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* args parsed from input line */
end_comment

begin_decl_stmt
name|int
name|cpend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag: if != 0, then pending server reply */
end_comment

begin_decl_stmt
name|int
name|mflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag: if != 0, then active multi command */
end_comment

begin_decl_stmt
name|int
name|options
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used during socket creation */
end_comment

begin_comment
comment|/*  * Format of command table.  */
end_comment

begin_struct
struct|struct
name|cmd
block|{
name|char
modifier|*
name|c_name
decl_stmt|;
comment|/* name of command */
name|char
modifier|*
name|c_help
decl_stmt|;
comment|/* help string */
name|char
name|c_bell
decl_stmt|;
comment|/* give bell when command completes */
name|char
name|c_conn
decl_stmt|;
comment|/* must be connected to use command */
name|char
name|c_proxy
decl_stmt|;
comment|/* proxy server may execute */
name|int
function_decl|(
modifier|*
name|c_handler
function_decl|)
parameter_list|()
function_decl|;
comment|/* function to call */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|macel
block|{
name|char
name|mac_name
index|[
literal|9
index|]
decl_stmt|;
comment|/* macro name */
name|char
modifier|*
name|mac_start
decl_stmt|;
comment|/* start of macro in macbuf */
name|char
modifier|*
name|mac_end
decl_stmt|;
comment|/* end of macro in macbuf */
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|macnum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of defined macros */
end_comment

begin_decl_stmt
name|struct
name|macel
name|macros
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|macbuf
index|[
literal|4096
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|tail
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|remglob
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|mktemp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strncpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strncat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

end_unit

