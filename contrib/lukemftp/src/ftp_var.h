begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ftp_var.h,v 1.64 2003/01/21 16:08:07 jhawk Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996-2003 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Luke Mewburn.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1985, 1989, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ftp_var.h	8.4 (Berkeley) 10/9/94  */
end_comment

begin_comment
comment|/*  * Copyright (C) 1997 and 1998 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * FTP global variables.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMALL
end_ifdef

begin_undef
undef|#
directive|undef
name|NO_EDITCOMPLETE
end_undef

begin_define
define|#
directive|define
name|NO_EDITCOMPLETE
end_define

begin_undef
undef|#
directive|undef
name|NO_PROGRESS
end_undef

begin_define
define|#
directive|define
name|NO_PROGRESS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
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
name|NO_EDITCOMPLETE
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
comment|/* !NO_EDITCOMPLETE */
end_comment

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_include
include|#
directive|include
file|"progressbar.h"
end_include

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
name|NO_EDITCOMPLETE
name|char
modifier|*
name|c_complete
decl_stmt|;
comment|/* context sensitive completion list */
endif|#
directive|endif
comment|/* !NO_EDITCOMPLETE */
name|void
function_decl|(
modifier|*
name|c_handler
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/* function to call */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Format of macro table  */
end_comment

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

begin_comment
comment|/*  * Format of option table  */
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
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Indices to features[]; an array containing status of remote server  * features; -1 not known (FEAT failed), 0 absent, 1 present.  */
end_comment

begin_enum
enum|enum
block|{
name|FEAT_FEAT
init|=
literal|0
block|,
comment|/* FEAT, OPTS */
name|FEAT_MDTM
block|,
comment|/* MDTM */
name|FEAT_MLST
block|,
comment|/* MLSD, MLST */
name|FEAT_REST_STREAM
block|,
comment|/* RESTart STREAM */
name|FEAT_SIZE
block|,
comment|/* SIZE */
name|FEAT_TVFS
block|,
comment|/* TVFS (not used) */
name|FEAT_max
block|}
enum|;
end_enum

begin_comment
comment|/*  * Global defines  */
end_comment

begin_define
define|#
directive|define
name|FTPBUFLEN
value|MAXPATHLEN + 200
end_define

begin_define
define|#
directive|define
name|MAX_IN_PORT_T
value|0xffffU
end_define

begin_define
define|#
directive|define
name|HASHBYTES
value|1024
end_define

begin_comment
comment|/* default mark for `hash' command */
end_comment

begin_define
define|#
directive|define
name|DEFAULTINCR
value|1024
end_define

begin_comment
comment|/* default increment for `rate' command */
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
name|DEFAULTPAGER
value|"more"
end_define

begin_comment
comment|/* default pager if $PAGER isn't set */
end_comment

begin_define
define|#
directive|define
name|DEFAULTPROMPT
value|"ftp> "
end_define

begin_comment
comment|/* default prompt  if `set prompt' is empty */
end_comment

begin_define
define|#
directive|define
name|DEFAULTRPROMPT
value|""
end_define

begin_comment
comment|/* default rprompt if `set rprompt' is empty */
end_comment

begin_define
define|#
directive|define
name|TMPFILE
value|"ftpXXXXXXXXXX"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|GLOBAL
end_ifndef

begin_define
define|#
directive|define
name|GLOBAL
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Options and other state info.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|trace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trace packets exchanged */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|hash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print # for each buffer transferred */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|mark
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of bytes between hashes */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|sendport
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use PORT/LPRT cmd for each data connection */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|connected
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 = connected to server, -1 = logged in */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|interactive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interactively prompt on m* cmds */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|confirmrest
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* confirm rest of current m* cmd */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debugging level */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|bell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ring bell on cmd completion */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|doglob
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* glob local file names */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|autologin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* establish user account on connection */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|proxy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* proxy server connection active */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|proxflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* proxy connection exists */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|gatemode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use gate-ftp */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|gateserver
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* server to use for gate-ftp */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|sunique
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* store files on server with unique name */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|runique
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* store local files with unique name */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|mcase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* map upper to lower case for mget names */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|ntflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use ntin ntout tables for name translation */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|mapflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use mapin mapout templates on file names */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|preserve
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* preserve modification time on files */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|code
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return/reply code for ftp command */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|crflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if 1, strip car. rets. on ascii gets */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|passivemode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* passive mode enabled */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|activefallback
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fall back to active mode if passive fails */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|altarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* argv[1] with no shell-like preprocessing  */
end_comment

begin_decl_stmt
name|GLOBAL
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
name|GLOBAL
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
name|GLOBAL
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
name|GLOBAL
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
name|GLOBAL
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
name|GLOBAL
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* requested file transfer type */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|curtype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current file transfer type */
end_comment

begin_decl_stmt
name|GLOBAL
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
name|GLOBAL
name|int
name|stru
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file transfer structure */
end_comment

begin_decl_stmt
name|GLOBAL
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
name|GLOBAL
name|int
name|form
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file transfer format */
end_comment

begin_decl_stmt
name|GLOBAL
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
name|GLOBAL
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file transfer mode */
end_comment

begin_decl_stmt
name|GLOBAL
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
name|GLOBAL
name|int
name|bytesize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local byte size in binary */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|anonftp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* automatic anonymous login */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|dirchange
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote directory changed by cd command */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|flushcache
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set HTTP cache flush headers with request */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|rate_get
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum get xfer rate */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|rate_get_incr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* increment for get xfer rate */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|rate_put
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum put xfer rate */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|rate_put_incr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* increment for put xfer rate */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|retry_connect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* seconds between retrying connection */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|tmpdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporary directory */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|epsv4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use EPSV/EPRT on IPv4 connections */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|epsv4bad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EPSV doesn't work on the current server */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|editing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command line editing enabled */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|features
index|[
name|FEAT_max
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote FEATures supported */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_EDITCOMPLETE
end_ifndef

begin_decl_stmt
name|GLOBAL
name|EditLine
modifier|*
name|el
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* editline(3) status structure */
end_comment

begin_decl_stmt
name|GLOBAL
name|History
modifier|*
name|hist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* editline(3) history structure */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|cursor_pos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cursor position we're looking for */
end_comment

begin_decl_stmt
name|GLOBAL
name|size_t
name|cursor_argc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of cursor in margv */
end_comment

begin_decl_stmt
name|GLOBAL
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
comment|/* !NO_EDITCOMPLETE */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|direction
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* direction transfer is occurring */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|hostname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of host connected to */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|unix_server
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* server is unix, can use binary for ascii */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|unix_proxy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* proxy is unix, can use binary for ascii */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
name|remotepwd
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote dir */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|username
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of user logged in as. (dynamic) */
end_comment

begin_decl_stmt
name|GLOBAL
name|sa_family_t
name|family
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* address family to use for connections */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|ftpport
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* port number to use for FTP connections */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|httpport
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* port number to use for HTTP connections */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|gateport
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* port number to use for gateftp connections */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|outfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filename to output URLs to */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|restartautofetch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restart auto-fetch */
end_comment

begin_decl_stmt
name|GLOBAL
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
name|GLOBAL
name|char
modifier|*
name|stringbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current scan point in line buffer */
end_comment

begin_decl_stmt
name|GLOBAL
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
name|GLOBAL
name|char
modifier|*
name|argbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current storage point in arg buffer */
end_comment

begin_decl_stmt
name|GLOBAL
name|StringList
modifier|*
name|marg_sl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stringlist containing margv */
end_comment

begin_decl_stmt
name|GLOBAL
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
name|GLOBAL
name|int
name|cpend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag: if != 0, then pending server reply */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|mflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag: if != 0, then active multi command */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|options
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used during socket creation */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|sndbuf_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* socket send buffer size */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|rcvbuf_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* socket receive buffer size */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|macnum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of defined macros */
end_comment

begin_decl_stmt
name|GLOBAL
name|struct
name|macel
name|macros
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|char
name|macbuf
index|[
literal|4096
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|localhome
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local home directory */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|localname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local user name */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
name|netrc
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* path to .netrc file */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
name|reply_string
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first line of previous reply */
end_comment

begin_function_decl
name|GLOBAL
name|void
function_decl|(
modifier|*
name|reply_callback
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 					 * function to call for each line in 					 * the server's reply except for the 					 * first (`xxx-') and last (`xxx ') 					 */
end_comment

begin_decl_stmt
name|GLOBAL
name|FILE
modifier|*
name|cin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|FILE
modifier|*
name|cout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|int
name|data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cmd
name|cmdtab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|option
name|optiontab
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|EMPTYSTRING
parameter_list|(
name|x
parameter_list|)
value|((x) == NULL || (*(x) == '\0'))
end_define

begin_define
define|#
directive|define
name|FREEPTR
parameter_list|(
name|x
parameter_list|)
value|if ((x) != NULL) { free(x); (x) = NULL; }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_4
end_ifdef

begin_define
define|#
directive|define
name|HAVE_SOCKADDR_SA_LEN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NO_LONG_LONG
end_ifdef

begin_define
define|#
directive|define
name|STRTOLL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|strtol(x,y,z)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STRTOLL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|strtoll(x,y,z)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

