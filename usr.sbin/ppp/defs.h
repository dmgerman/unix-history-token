begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 - 2001 Brian Somers<brian@Awfulhak.org>  *          based on work by Toshiharu OHNO<tony-o@iij.ad.jp>  *                           Internet Initiative Japan, Inc (IIJ)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Check the following definitions for your machine environment */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|MODEM_LIST
value|"/dev/cuaa1\0/dev/cuaa0"
end_define

begin_comment
comment|/* name of tty device */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__OpenBSD__
end_ifdef

begin_define
define|#
directive|define
name|MODEM_LIST
value|"/dev/cua01\0/dev/cua00"
end_define

begin_comment
comment|/* name of tty device */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MODEM_LIST
value|"/dev/tty01\0/dev/tty00"
end_define

begin_comment
comment|/* name of tty device */
end_comment

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
name|NMODEMS
value|2
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PPP_CONFDIR
end_ifndef

begin_define
define|#
directive|define
name|PPP_CONFDIR
value|"/etc/ppp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TUN_NAME
value|"tun"
end_define

begin_define
define|#
directive|define
name|TUN_PREFIX
value|(_PATH_DEV TUN_NAME)
end_define

begin_comment
comment|/* /dev/tun */
end_comment

begin_define
define|#
directive|define
name|MODEM_SPEED
value|B38400
end_define

begin_comment
comment|/* tty speed */
end_comment

begin_define
define|#
directive|define
name|SERVER_PORT
value|3000
end_define

begin_comment
comment|/* Base server port no. */
end_comment

begin_define
define|#
directive|define
name|MODEM_CTSRTS
value|1
end_define

begin_comment
comment|/* Default (true): use CTS/RTS signals */
end_comment

begin_define
define|#
directive|define
name|RECONNECT_TIMEOUT
value|3
end_define

begin_comment
comment|/* Default timer for carrier loss */
end_comment

begin_define
define|#
directive|define
name|DIAL_TIMEOUT
value|30
end_define

begin_comment
comment|/* Default and Max random time to redial */
end_comment

begin_define
define|#
directive|define
name|DIAL_NEXT_TIMEOUT
value|3
end_define

begin_comment
comment|/* Default Hold time to next number redial */
end_comment

begin_define
define|#
directive|define
name|SCRIPT_LEN
value|512
end_define

begin_comment
comment|/* Size of login/dial/hangup scripts */
end_comment

begin_define
define|#
directive|define
name|LINE_LEN
value|SCRIPT_LEN
end_define

begin_comment
comment|/* Size of lines */
end_comment

begin_define
define|#
directive|define
name|DEVICE_LEN
value|SCRIPT_LEN
end_define

begin_comment
comment|/* Size of individual devices */
end_comment

begin_define
define|#
directive|define
name|AUTHLEN
value|100
end_define

begin_comment
comment|/* Size of authname/authkey */
end_comment

begin_define
define|#
directive|define
name|CHAPDIGESTLEN
value|100
end_define

begin_comment
comment|/* Maximum chap digest */
end_comment

begin_define
define|#
directive|define
name|CHAPCHALLENGELEN
value|48
end_define

begin_comment
comment|/* Maximum chap challenge */
end_comment

begin_define
define|#
directive|define
name|CHAPAUTHRESPONSELEN
value|48
end_define

begin_comment
comment|/* Maximum chap authresponse (chap81) */
end_comment

begin_define
define|#
directive|define
name|MAXARGS
value|40
end_define

begin_comment
comment|/* How many args per config line */
end_comment

begin_define
define|#
directive|define
name|NCP_IDLE_TIMEOUT
value|180
end_define

begin_comment
comment|/* Drop all links */
end_comment

begin_define
define|#
directive|define
name|CHOKED_TIMEOUT
value|120
end_define

begin_comment
comment|/* Delete queued packets w/ blocked tun */
end_comment

begin_define
define|#
directive|define
name|MIN_LQRPERIOD
value|1
end_define

begin_comment
comment|/* Minimum LQR frequency */
end_comment

begin_define
define|#
directive|define
name|DEF_LQRPERIOD
value|30
end_define

begin_comment
comment|/* Default LQR frequency */
end_comment

begin_define
define|#
directive|define
name|MIN_FSMRETRY
value|1
end_define

begin_comment
comment|/* Minimum FSM retry frequency */
end_comment

begin_define
define|#
directive|define
name|DEF_FSMRETRY
value|3
end_define

begin_comment
comment|/* FSM retry frequency */
end_comment

begin_define
define|#
directive|define
name|DEF_FSMTRIES
value|5
end_define

begin_comment
comment|/* Default max retries */
end_comment

begin_define
define|#
directive|define
name|DEF_FSMAUTHTRIES
value|3
end_define

begin_comment
comment|/* Default max auth retries */
end_comment

begin_define
define|#
directive|define
name|DEF_IFQUEUE
value|30
end_define

begin_comment
comment|/* Default interface queue size */
end_comment

begin_define
define|#
directive|define
name|CONFFILE
value|"ppp.conf"
end_define

begin_define
define|#
directive|define
name|LINKUPFILE
value|"ppp.linkup"
end_define

begin_define
define|#
directive|define
name|LINKDOWNFILE
value|"ppp.linkdown"
end_define

begin_define
define|#
directive|define
name|SECRETFILE
value|"ppp.secret"
end_define

begin_define
define|#
directive|define
name|EX_SIG
value|-1
end_define

begin_define
define|#
directive|define
name|EX_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|EX_START
value|1
end_define

begin_define
define|#
directive|define
name|EX_SOCK
value|2
end_define

begin_define
define|#
directive|define
name|EX_MODEM
value|3
end_define

begin_define
define|#
directive|define
name|EX_DIAL
value|4
end_define

begin_define
define|#
directive|define
name|EX_DEAD
value|5
end_define

begin_define
define|#
directive|define
name|EX_DONE
value|6
end_define

begin_define
define|#
directive|define
name|EX_REBOOT
value|7
end_define

begin_define
define|#
directive|define
name|EX_ERRDEAD
value|8
end_define

begin_define
define|#
directive|define
name|EX_HANGUP
value|9
end_define

begin_define
define|#
directive|define
name|EX_TERM
value|10
end_define

begin_define
define|#
directive|define
name|EX_NODIAL
value|11
end_define

begin_define
define|#
directive|define
name|EX_NOLOGIN
value|12
end_define

begin_comment
comment|/* return values for -background mode, not really exits */
end_comment

begin_define
define|#
directive|define
name|EX_REDIAL
value|13
end_define

begin_define
define|#
directive|define
name|EX_RECONNECT
value|14
end_define

begin_comment
comment|/* physical::type values (OR'd in bundle::phys_type) */
end_comment

begin_define
define|#
directive|define
name|PHYS_NONE
value|0
end_define

begin_define
define|#
directive|define
name|PHYS_INTERACTIVE
value|1
end_define

begin_comment
comment|/* Manual link */
end_comment

begin_define
define|#
directive|define
name|PHYS_AUTO
value|2
end_define

begin_comment
comment|/* Dial-on-demand link */
end_comment

begin_define
define|#
directive|define
name|PHYS_DIRECT
value|4
end_define

begin_comment
comment|/* Incoming link, deleted when closed */
end_comment

begin_define
define|#
directive|define
name|PHYS_DEDICATED
value|8
end_define

begin_comment
comment|/* Dedicated link */
end_comment

begin_define
define|#
directive|define
name|PHYS_DDIAL
value|16
end_define

begin_comment
comment|/* Dial immediately, stay connected */
end_comment

begin_define
define|#
directive|define
name|PHYS_BACKGROUND
value|32
end_define

begin_comment
comment|/* Dial immediately, deleted when closed */
end_comment

begin_define
define|#
directive|define
name|PHYS_FOREGROUND
value|64
end_define

begin_comment
comment|/* Pseudo mode, same as background */
end_comment

begin_define
define|#
directive|define
name|PHYS_ALL
value|127
end_define

begin_comment
comment|/* flags passed to findblank() and MakeArgs() */
end_comment

begin_define
define|#
directive|define
name|PARSE_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|PARSE_REDUCE
value|1
end_define

begin_define
define|#
directive|define
name|PARSE_NOHASH
value|2
end_define

begin_comment
comment|/* flags passed to loadmodules */
end_comment

begin_define
define|#
directive|define
name|LOAD_QUIETLY
value|1
end_define

begin_define
define|#
directive|define
name|LOAD_VERBOSLY
value|2
end_define

begin_define
define|#
directive|define
name|ROUNDUP
parameter_list|(
name|x
parameter_list|)
value|((x) ? (1 + (((x) - 1) | (sizeof(long) - 1))) : sizeof(long))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|__FreeBSD__
operator|<
literal|3
end_if

begin_function_decl
specifier|extern
name|void
name|randinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|random
value|arc4random
end_define

begin_define
define|#
directive|define
name|randinit
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|ssize_t
name|fullread
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|mode2Nam
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|Nam2mode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|in_addr
name|GetIpAddr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|SpeedToInt
parameter_list|(
name|speed_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|speed_t
name|IntToSpeed
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|findblank
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|MakeArgs
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|NumStr
parameter_list|(
name|long
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|HexStr
parameter_list|(
name|long
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|ex_desc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SetTitle
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fd_set
modifier|*
name|mkfdset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|zerofdset
parameter_list|(
name|fd_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Concatinate
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|loadmodules
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

end_unit

