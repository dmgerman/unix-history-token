begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: ftp_var.h,v 2.4 87/04/01 13:53:05 ed Exp $ */
end_comment

begin_comment
comment|/* $Log:	ftp_var.h,v $  * Revision 2.4  87/04/01  13:53:05  ed  * include FilingSubset1.h from standard include/xnscourier directory.  *   * Revision 2.3  87/01/09  16:48:41  ed  * Use FilingSubset Protocol  * file types moved to filetypes.h to share with server code  *   * Revision 2.2  86/12/15  11:41:12  jqj  * Added support for more ViewPoint file types (no other attributes, though)  *   * Revision 2.1  86/12/11  06:12:10  jqj  * Eliminated form, mode, and struct commands.  Started adding support for  * more file types.  *   * Revision 2.0  85/11/21  07:22:46  jqj  * 4.3BSD standard release  *   * Revision 1.1  85/05/27  06:30:59  jqj  * Initial revision  *   * Revision 1.1  85/05/27  06:30:59  jqj  * Initial revision  *   * based on Berkeley tcp/ftp  */
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
file|<xnscourier/FilingSubset1.h>
end_include

begin_include
include|#
directive|include
file|<xnscourier/filetypes.h>
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
name|int
name|usefiling
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use Filing instead of FilingSubset */
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
name|LongCardinal
name|typevalue
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file transfer type */
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
comment|/*  * Type codes  *	Server needed access to the types also, so they were moved to  *		../filing_common/filetypes.h	ed 1/9/87  */
end_comment

end_unit

