begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: defs.h,v 1.4.2.9 1997/09/10 02:23:28 brian Exp $  *  *	TODO:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEFS_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|"mbuf.h"
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_comment
comment|/*  *  Check follwiing definitions for your machine envirinment  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|MODEM_DEV
value|"/dev/cuaa1"
end_define

begin_comment
comment|/* name of tty device */
end_comment

begin_define
define|#
directive|define
name|BASE_MODEM_DEV
value|"cuaa1"
end_define

begin_comment
comment|/* name of base tty device */
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
name|MODEM_DEV
value|"/dev/cua01"
end_define

begin_comment
comment|/* name of tty device */
end_comment

begin_define
define|#
directive|define
name|BASE_MODEM_DEV
value|"cua01"
end_define

begin_comment
comment|/* name of base tty device */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MODEM_DEV
value|"/dev/tty01"
end_define

begin_comment
comment|/* name of tty device */
end_comment

begin_define
define|#
directive|define
name|BASE_MODEM_DEV
value|"tty01"
end_define

begin_comment
comment|/* name of base tty device */
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
value|TRUE
end_define

begin_comment
comment|/* Default (true): use CTS/RTS signals */
end_comment

begin_define
define|#
directive|define
name|RECONNECT_TIMER
value|3
end_define

begin_comment
comment|/* Default timer for carrier loss */
end_comment

begin_define
define|#
directive|define
name|RECONNECT_TRIES
value|0
end_define

begin_comment
comment|/* Default retries on carrier loss */
end_comment

begin_define
define|#
directive|define
name|REDIAL_PERIOD
value|30
end_define

begin_comment
comment|/* Default Hold time to redial */
end_comment

begin_define
define|#
directive|define
name|NEXT_REDIAL_PERIOD
value|3
end_define

begin_comment
comment|/* Default Hold time to next number redial */
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

begin_comment
comment|/*  *  Definition of working mode  */
end_comment

begin_define
define|#
directive|define
name|MODE_INTER
value|1
end_define

begin_comment
comment|/* Interactive mode */
end_comment

begin_define
define|#
directive|define
name|MODE_AUTO
value|2
end_define

begin_comment
comment|/* Auto calling mode */
end_comment

begin_define
define|#
directive|define
name|MODE_DIRECT
value|4
end_define

begin_comment
comment|/* Direct connection mode */
end_comment

begin_define
define|#
directive|define
name|MODE_DEDICATED
value|8
end_define

begin_comment
comment|/* Dedicated line mode */
end_comment

begin_define
define|#
directive|define
name|MODE_DDIAL
value|16
end_define

begin_comment
comment|/* Dedicated dialing line mode */
end_comment

begin_define
define|#
directive|define
name|MODE_ALIAS
value|32
end_define

begin_comment
comment|/* Packet aliasing (masquerading) */
end_comment

begin_define
define|#
directive|define
name|MODE_BACKGROUND
value|64
end_define

begin_comment
comment|/* Background mode. */
end_comment

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

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|BGFiledes
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|modem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tun_in
decl_stmt|,
name|tun_out
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|netfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dstsystem
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIGALRM
end_ifdef

begin_function_decl
name|u_int
name|nointr_sleep
parameter_list|(
name|u_int
name|sec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nointr_usleep
parameter_list|(
name|u_int
name|usec
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEFS_H_ */
end_comment

end_unit

