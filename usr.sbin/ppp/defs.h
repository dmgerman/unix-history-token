begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  *	TODO:  */
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
value|"/dev/cuaa1, /dev/cuaa0"
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
value|"/dev/cua01, /dev/cua00"
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
value|"/dev/tty01, /dev/tty00"
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
name|_PATH_PPP
value|"/etc/ppp"
end_define

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
comment|/* Size of login scripts */
end_comment

begin_define
define|#
directive|define
name|LINE_LEN
value|SCRIPT_LEN
end_define

begin_comment
comment|/* Size of login scripts */
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
name|LINK_MINWEIGHT
value|20
end_define

begin_define
define|#
directive|define
name|MIN_LQRPERIOD
value|2
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
value|3
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
name|DEF_REQs
value|5
end_define

begin_comment
comment|/* This number of REQs in IRC */
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
value|10
end_define

begin_define
define|#
directive|define
name|EX_TERM
value|11
end_define

begin_define
define|#
directive|define
name|EX_NODIAL
value|12
end_define

begin_define
define|#
directive|define
name|EX_NOLOGIN
value|13
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
name|PHYS_ALL
value|63
end_define

begin_function_decl
specifier|extern
name|void
name|randinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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

end_unit

