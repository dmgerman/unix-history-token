begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: extern.h,v 1.43 2001/12/04 13:54:12 lukem Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)extern.h	8.2 (Berkeley) 4/4/94  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997-2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Luke Mewburn.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (C) 1997 and 1998 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_LONG_LONG
end_ifdef

begin_define
define|#
directive|define
name|LLF
value|"%ld"
end_define

begin_define
define|#
directive|define
name|LLFP
parameter_list|(
name|x
parameter_list|)
value|"%" x "ld"
end_define

begin_define
define|#
directive|define
name|LLT
value|long
end_define

begin_define
define|#
directive|define
name|ULLF
value|"%lu"
end_define

begin_define
define|#
directive|define
name|ULLFP
parameter_list|(
name|x
parameter_list|)
value|"%" x "lu"
end_define

begin_define
define|#
directive|define
name|ULLT
value|unsigned long
end_define

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

begin_if
if|#
directive|if
name|HAVE_PRINTF_QD
end_if

begin_define
define|#
directive|define
name|LLF
value|"%qd"
end_define

begin_define
define|#
directive|define
name|LLFP
parameter_list|(
name|x
parameter_list|)
value|"%" x "qd"
end_define

begin_define
define|#
directive|define
name|LLT
value|long long
end_define

begin_define
define|#
directive|define
name|ULLF
value|"%qu"
end_define

begin_define
define|#
directive|define
name|ULLFP
parameter_list|(
name|x
parameter_list|)
value|"%" x "qu"
end_define

begin_define
define|#
directive|define
name|ULLT
value|unsigned long long
end_define

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLF
value|"%lld"
end_define

begin_define
define|#
directive|define
name|LLFP
parameter_list|(
name|x
parameter_list|)
value|"%" x "lld"
end_define

begin_define
define|#
directive|define
name|LLT
value|long long
end_define

begin_define
define|#
directive|define
name|ULLF
value|"%llu"
end_define

begin_define
define|#
directive|define
name|ULLFP
parameter_list|(
name|x
parameter_list|)
value|"%" x "llu"
end_define

begin_define
define|#
directive|define
name|ULLT
value|unsigned long long
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FTP_BUFLEN
value|512
end_define

begin_function_decl
name|void
name|abor
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blkfree
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|closedataconn
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|conffilename
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|copyblk
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|count_users
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cwd
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|dataconn
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|off_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delete
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|display_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|do_conversion
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dologout
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|feat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|format_path
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ftpd_pclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|ftpd_popen
parameter_list|(
name|char
modifier|*
index|[]
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getline
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_curclass
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|logxfer
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|off_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|void	logwtmp(const char *, const char *, const char *);
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|tab
modifier|*
name|lookup
parameter_list|(
name|struct
name|tab
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|makedir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlsd
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlst
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|opts
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|parse_conf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pass
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|passive
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lpsvproto2af
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|af2lpsvproto
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|epsvproto2af
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|af2epsvproto
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|long_passive
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|extended_port
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|epsv_protounsupp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perror_reply
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pwd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|removedir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|renamecmd
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|renamefrom
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reply
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|retrieve
parameter_list|(
name|char
modifier|*
index|[]
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|send_file_list
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|show_chdir_messages
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sizecmd
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|statcmd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|statfilecmd
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|statxfer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|store
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LLT
name|strsuftoll
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|user
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xstrdup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|yyerror
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SETPROCTITLE
value|1
end_define

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

begin_struct
struct|struct
name|sockinet
block|{
union|union
name|sockunion
block|{
name|struct
name|sockaddr_in
name|su_sin
decl_stmt|;
ifdef|#
directive|ifdef
name|INET6
name|struct
name|sockaddr_in6
name|su_sin6
decl_stmt|;
endif|#
directive|endif
block|}
name|si_su
union|;
if|#
directive|if
operator|!
name|HAVE_SOCKADDR_SA_LEN
name|int
name|si_len
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_if
if|#
directive|if
operator|!
name|HAVE_SOCKADDR_SA_LEN
end_if

begin_define
define|#
directive|define
name|su_len
value|si_len
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|su_len
value|si_su.su_sin.sin_len
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|su_addr
value|si_su.su_sin.sin_addr
end_define

begin_define
define|#
directive|define
name|su_family
value|si_su.su_sin.sin_family
end_define

begin_define
define|#
directive|define
name|su_port
value|si_su.su_sin.sin_port
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_define
define|#
directive|define
name|su_6addr
value|si_su.su_sin6.sin6_addr
end_define

begin_define
define|#
directive|define
name|su_scope_id
value|si_su.su_sin6.sin6_scope_id
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|tab
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|short
name|token
decl_stmt|;
name|short
name|state
decl_stmt|;
name|short
name|flags
decl_stmt|;
comment|/* 1 if command implemented, 2 if has options, 	                   4 if can occur OOB */
name|char
modifier|*
name|help
decl_stmt|;
name|char
modifier|*
name|options
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ftpconv
block|{
name|struct
name|ftpconv
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|suffix
decl_stmt|;
comment|/* Suffix of requested name */
name|char
modifier|*
name|types
decl_stmt|;
comment|/* Valid file types */
name|char
modifier|*
name|disable
decl_stmt|;
comment|/* File to disable conversions */
name|char
modifier|*
name|command
decl_stmt|;
comment|/* Command to do the conversion */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CLASS_GUEST
block|,
name|CLASS_CHROOT
block|,
name|CLASS_REAL
block|}
name|class_ft
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|FLAG_checkportcmd
init|=
literal|1
operator|<<
literal|0
block|,
comment|/* Check port commands */
name|FLAG_denyquick
init|=
literal|1
operator|<<
literal|1
block|,
comment|/* Check ftpusers(5) before PASS */
name|FLAG_modify
init|=
literal|1
operator|<<
literal|2
block|,
comment|/* Allow CHMOD, DELE, MKD, RMD, RNFR, 					   UMASK */
name|FLAG_passive
init|=
literal|1
operator|<<
literal|3
block|,
comment|/* Allow PASV mode */
name|FLAG_private
init|=
literal|1
operator|<<
literal|4
block|,
comment|/* Don't publish class info in STAT */
name|FLAG_sanenames
init|=
literal|1
operator|<<
literal|5
block|,
comment|/* Restrict names of uploaded files */
name|FLAG_upload
init|=
literal|1
operator|<<
literal|6
block|,
comment|/* As per modify, but also allow 					   APPE, STOR, STOU */
block|}
name|classflag_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CURCLASS_FLAGS_SET
parameter_list|(
name|x
parameter_list|)
value|(curclass.flags |=  (FLAG_ ## x))
end_define

begin_define
define|#
directive|define
name|CURCLASS_FLAGS_CLR
parameter_list|(
name|x
parameter_list|)
value|(curclass.flags&= ~(FLAG_ ## x))
end_define

begin_define
define|#
directive|define
name|CURCLASS_FLAGS_ISSET
parameter_list|(
name|x
parameter_list|)
value|(curclass.flags&   (FLAG_ ## x))
end_define

begin_struct
struct|struct
name|ftpclass
block|{
name|struct
name|sockinet
name|advertise
decl_stmt|;
comment|/* PASV address to advertise as */
name|char
modifier|*
name|chroot
decl_stmt|;
comment|/* Directory to chroot(2) to at login */
name|char
modifier|*
name|classname
decl_stmt|;
comment|/* Current class */
name|struct
name|ftpconv
modifier|*
name|conversions
decl_stmt|;
comment|/* List of conversions */
name|char
modifier|*
name|display
decl_stmt|;
comment|/* File to display upon chdir */
name|char
modifier|*
name|homedir
decl_stmt|;
comment|/* Directory to chdir(2) to at login */
name|classflag_t
name|flags
decl_stmt|;
comment|/* Flags; see classflag_t above */
name|int
name|limit
decl_stmt|;
comment|/* Max connections (-1 = unlimited) */
name|char
modifier|*
name|limitfile
decl_stmt|;
comment|/* File to display if limit reached */
name|LLT
name|maxfilesize
decl_stmt|;
comment|/* Maximum file size of uploads */
name|LLT
name|maxrateget
decl_stmt|;
comment|/* Maximum get transfer rate throttle */
name|LLT
name|maxrateput
decl_stmt|;
comment|/* Maximum put transfer rate throttle */
name|unsigned
name|int
name|maxtimeout
decl_stmt|;
comment|/* Maximum permitted timeout */
name|char
modifier|*
name|motd
decl_stmt|;
comment|/* MotD file to display after login */
name|char
modifier|*
name|notify
decl_stmt|;
comment|/* Files to notify about upon chdir */
name|int
name|portmin
decl_stmt|;
comment|/* Minumum port for passive mode */
name|int
name|portmax
decl_stmt|;
comment|/* Maximum port for passive mode */
name|LLT
name|rateget
decl_stmt|;
comment|/* Get (RETR) transfer rate throttle */
name|LLT
name|rateput
decl_stmt|;
comment|/* Put (STOR) transfer rate throttle */
name|unsigned
name|int
name|timeout
decl_stmt|;
comment|/* Default timeout */
name|class_ft
name|type
decl_stmt|;
comment|/* Class type */
name|mode_t
name|umask
decl_stmt|;
comment|/* Umask to use */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|ftp_loop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ftp_handle_line
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

begin_decl_stmt
name|GLOBAL
name|struct
name|sockinet
name|ctrl_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|struct
name|sockinet
name|data_dest
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|struct
name|sockinet
name|data_source
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|struct
name|sockinet
name|his_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|struct
name|sockinet
name|pasv_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|int
name|connections
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|struct
name|ftpclass
name|curclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|jmp_buf
name|errcatch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|emailaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|int
name|form
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|int
name|gidcount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of entries in gidlist[] */
end_comment

begin_decl_stmt
name|GLOBAL
name|gid_t
name|gidlist
index|[
name|NGROUPS_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|int
name|hasyyerrored
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|char
name|hostname
index|[
name|MAXHOSTNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|char
name|homedir
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KERBEROS5
end_ifdef

begin_decl_stmt
name|GLOBAL
name|krb5_context
name|kcontext
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|GLOBAL
name|int
name|logged_in
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|int
name|logging
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|int
name|pdata
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for passive mode */
end_comment

begin_if
if|#
directive|if
name|HAVE_SETPROCTITLE
end_if

begin_decl_stmt
name|GLOBAL
name|char
name|proctitle
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial part of title */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|GLOBAL
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|int
name|quietmessages
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|char
name|remotehost
index|[
name|MAXHOSTNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|off_t
name|restart_point
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|char
name|tmpline
index|[
name|FTP_BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|sig_atomic_t
name|transflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|int
name|usedefault
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for data transfers */
end_comment

begin_decl_stmt
name|GLOBAL
specifier|const
name|char
modifier|*
name|version
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|int
name|is_oob
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total file data bytes */
end_comment

begin_decl_stmt
name|GLOBAL
name|off_t
name|total_data_in
decl_stmt|,
name|total_data_out
decl_stmt|,
name|total_data
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total number of data files */
end_comment

begin_decl_stmt
name|GLOBAL
name|off_t
name|total_files_in
decl_stmt|,
name|total_files_out
decl_stmt|,
name|total_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total bytes */
end_comment

begin_decl_stmt
name|GLOBAL
name|off_t
name|total_bytes_in
decl_stmt|,
name|total_bytes_out
decl_stmt|,
name|total_bytes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total number of xfers */
end_comment

begin_decl_stmt
name|GLOBAL
name|off_t
name|total_xfers_in
decl_stmt|,
name|total_xfers_out
decl_stmt|,
name|total_xfers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tab
name|cmdtab
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INTERNAL_LS
value|"/bin/ls"
end_define

begin_define
define|#
directive|define
name|CMD_IMPLEMENTED
parameter_list|(
name|x
parameter_list|)
value|((x)->flags != 0)
end_define

begin_define
define|#
directive|define
name|CMD_HAS_OPTIONS
parameter_list|(
name|x
parameter_list|)
value|((x)->flags& 0x2)
end_define

begin_define
define|#
directive|define
name|CMD_OOB
parameter_list|(
name|x
parameter_list|)
value|((x)->flags& 0x4)
end_define

begin_define
define|#
directive|define
name|CPUTC
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|do { \ 				putc(c, f); total_bytes++; total_bytes_out++; \ 			} while (0);
end_define

begin_define
define|#
directive|define
name|CURCLASSTYPE
value|curclass.type == CLASS_GUEST  ? "GUEST"  : \ 		    	curclass.type == CLASS_CHROOT ? "CHROOT" : \ 		    	curclass.type == CLASS_REAL   ? "REAL"   : \ 			"<unknown>"
end_define

begin_define
define|#
directive|define
name|ISDOTDIR
parameter_list|(
name|x
parameter_list|)
value|(x[0] == '.'&& x[1] == '\0')
end_define

begin_define
define|#
directive|define
name|ISDOTDOTDIR
parameter_list|(
name|x
parameter_list|)
value|(x[0] == '.'&& x[1] == '.'&& x[2] == '\0')
end_define

begin_define
define|#
directive|define
name|EMPTYSTR
parameter_list|(
name|p
parameter_list|)
value|((p) == NULL || *(p) == '\0')
end_define

begin_define
define|#
directive|define
name|NEXTWORD
parameter_list|(
name|P
parameter_list|,
name|W
parameter_list|)
value|do { \ 				(W) = strsep(&(P), " \t"); \ 			} while ((W) != NULL&& *(W) == '\0')
end_define

begin_define
define|#
directive|define
name|PLURAL
parameter_list|(
name|s
parameter_list|)
value|((s) == 1 ? "" : "s")
end_define

begin_define
define|#
directive|define
name|REASSIGN
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|do { if (X) free(X); (X)=(Y); } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IPPORT_ANONMAX
end_ifndef

begin_define
define|#
directive|define
name|IPPORT_ANONMAX
value|65535
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

