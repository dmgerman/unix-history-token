begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: ftp_var.h,v 2.0 85/11/21 07:22:46 jqj Exp $ */
end_comment

begin_comment
comment|/* $Log:	ftp_var.h,v $  * Revision 2.0  85/11/21  07:22:46  jqj  * 4.3BSD standard release  *   * Revision 1.1  85/05/27  06:30:59  jqj  * Initial revision  *   * Revision 1.1  85/05/27  06:30:59  jqj  * Initial revision  *   * based on Berkeley tcp/ftp  */
end_comment

begin_comment
comment|/*	ftp_var.h	4.6	83/07/26	*/
end_comment

begin_comment
comment|/*  * FTP global variables.  */
end_comment

begin_include
include|#
directive|include
file|"Filing4.h"
end_include

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
name|verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print messages coming back from server */
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
name|typevalue
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

begin_comment
comment|/*  * Connection information  */
end_comment

begin_decl_stmt
specifier|extern
name|CourierConnection
modifier|*
name|connected
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* connected to server */
end_comment

begin_comment
comment|/*  * stuff borrowed from<arpa/ftp.h> since we don't want all of that!  */
end_comment

begin_comment
comment|/*  * Type codes  */
end_comment

begin_define
define|#
directive|define
name|TYPE_A
value|1
end_define

begin_comment
comment|/* ASCII -- map CR<=> LF */
end_comment

begin_comment
comment|/* #define	TYPE_E		2	/* EBCDIC */
end_comment

begin_define
define|#
directive|define
name|TYPE_I
value|3
end_define

begin_comment
comment|/* image */
end_comment

begin_define
define|#
directive|define
name|TYPE_L
value|4
end_define

begin_comment
comment|/* local byte size */
end_comment

begin_comment
comment|/*  * Form codes  */
end_comment

begin_define
define|#
directive|define
name|FORM_N
value|1
end_define

begin_comment
comment|/* non-print */
end_comment

begin_comment
comment|/* #define	FORM_T		2	/* telnet format effectors */
end_comment

begin_comment
comment|/* #define	FORM_C		3	/* carriage control (ASA) */
end_comment

begin_comment
comment|/*  * Structure codes  */
end_comment

begin_define
define|#
directive|define
name|STRU_F
value|1
end_define

begin_comment
comment|/* file (no record structure) */
end_comment

begin_comment
comment|/* #define	STRU_R		2	/* record structure */
end_comment

begin_comment
comment|/* #define	STRU_P		3	/* page structure */
end_comment

begin_comment
comment|/*  * Mode types  */
end_comment

begin_define
define|#
directive|define
name|MODE_S
value|1
end_define

begin_comment
comment|/* stream */
end_comment

begin_comment
comment|/* #define	MODE_B		2	/* block */
end_comment

begin_comment
comment|/* #define	MODE_C		3	/* compressed */
end_comment

end_unit

