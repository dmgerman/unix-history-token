begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: ftp_var.h,v 1.6 1997/12/13 20:38:18 pst Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD: ftp_var.h,v 1.20.2.1 1997/11/18 01:01:37 mellon Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1985, 1989, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ftp_var.h	8.4 (Berkeley) 10/9/94  */
end_comment

begin_comment
comment|/*  * FTP global variables.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<stringlist.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SMALL
end_ifndef

begin_include
include|#
directive|include
file|<histedit.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SMALL */
end_comment

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_define
define|#
directive|define
name|HASHBYTES
value|1024
end_define

begin_define
define|#
directive|define
name|FTPBUFLEN
value|MAXPATHLEN + 200
end_define

begin_define
define|#
directive|define
name|STALLTIME
value|5
end_define

begin_comment
comment|/* # of seconds of no xfer before "stalling" */
end_comment

begin_define
define|#
directive|define
name|FTP_PORT
value|21
end_define

begin_comment
comment|/* default if ! getservbyname("ftp/tcp") */
end_comment

begin_define
define|#
directive|define
name|HTTP_PORT
value|80
end_define

begin_comment
comment|/* default if ! getservbyname("http/tcp") */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GATE_PORT
end_ifndef

begin_define
define|#
directive|define
name|GATE_PORT
value|21
end_define

begin_comment
comment|/* default if ! getservbyname("ftpgate/tcp") */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GATE_SERVER
end_ifndef

begin_define
define|#
directive|define
name|GATE_SERVER
value|""
end_define

begin_comment
comment|/* default server */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PAGER
value|"more"
end_define

begin_comment
comment|/* default pager if $PAGER isn't set */
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
name|mark
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of bytes between hashes */
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
comment|/* 1 = connected to server, -1 = logged in */
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
name|confirmrest
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* confirm rest of current m* cmd */
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
name|gatemode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use gate-ftp */
end_comment

begin_decl_stmt
name|char
modifier|*
name|gateserver
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* server to use for gate-ftp */
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
name|preserve
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* preserve modification time on files */
end_comment

begin_decl_stmt
name|int
name|progress
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* display transfer progress bar */
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
name|int
name|passivemode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* passive mode enabled */
end_comment

begin_decl_stmt
name|int
name|restricted_data_ports
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* enable quarantine FTP area */
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
comment|/* requested file transfer type */
end_comment

begin_decl_stmt
name|int
name|curtype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current file transfer type */
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
name|int
name|anonftp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* automatic anonymous login */
end_comment

begin_decl_stmt
name|int
name|dirchange
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote directory changed by cd command */
end_comment

begin_decl_stmt
name|int
name|ttywidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* width of tty */
end_comment

begin_decl_stmt
name|char
modifier|*
name|tmpdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporary directory */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SMALL
end_ifndef

begin_decl_stmt
name|int
name|editing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command line editing enabled */
end_comment

begin_decl_stmt
name|EditLine
modifier|*
name|el
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* editline(3) status structure */
end_comment

begin_decl_stmt
name|History
modifier|*
name|hist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* editline(3) history structure */
end_comment

begin_decl_stmt
name|char
modifier|*
name|cursor_pos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cursor position we're looking for */
end_comment

begin_decl_stmt
name|size_t
name|cursor_argc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of cursor in margv */
end_comment

begin_decl_stmt
name|size_t
name|cursor_argo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset of cursor in margv[cursor_argc] */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SMALL */
end_comment

begin_decl_stmt
name|off_t
name|bytes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current # of bytes read */
end_comment

begin_decl_stmt
name|off_t
name|filesize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of file being transferred */
end_comment

begin_decl_stmt
name|char
modifier|*
name|direction
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* direction transfer is occurring */
end_comment

begin_decl_stmt
name|off_t
name|restart_point
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset to restart transfer */
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
name|int
name|unix_server
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* server is unix, can use binary for ascii */
end_comment

begin_decl_stmt
name|int
name|unix_proxy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* proxy is unix, can use binary for ascii */
end_comment

begin_decl_stmt
name|u_int16_t
name|ftpport
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* port number to use for ftp connections */
end_comment

begin_decl_stmt
name|u_int16_t
name|httpport
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* port number to use for http connections */
end_comment

begin_decl_stmt
name|u_int16_t
name|gateport
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* port number to use for gateftp connections */
end_comment

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
name|FTPBUFLEN
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
name|FTPBUFLEN
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
name|StringList
modifier|*
name|marg_sl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stringlist containing margv */
end_comment

begin_decl_stmt
name|int
name|margc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of arguments on input line */
end_comment

begin_define
define|#
directive|define
name|margv
value|(marg_sl->sl_str)
end_define

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
ifndef|#
directive|ifndef
name|SMALL
name|char
modifier|*
name|c_complete
decl_stmt|;
comment|/* context sensitive completion list */
endif|#
directive|endif
comment|/* !SMALL */
name|void
argument_list|(
argument|*c_handler
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
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

end_unit

