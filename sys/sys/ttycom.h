begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ttycom.h	8.1 (Berkeley) 3/28/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TTYCOM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TTYCOM_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/*  * Tty ioctl's except for those supported only for backwards compatibility  * with the old tty driver.  */
end_comment

begin_comment
comment|/*  * Window/terminal size structure.  This information is stored by the kernel  * in order to provide a consistent interface, but is not used by the kernel.  */
end_comment

begin_struct
struct|struct
name|winsize
block|{
name|unsigned
name|short
name|ws_row
decl_stmt|;
comment|/* rows, in characters */
name|unsigned
name|short
name|ws_col
decl_stmt|;
comment|/* columns, in characters */
name|unsigned
name|short
name|ws_xpixel
decl_stmt|;
comment|/* horizontal size, pixels */
name|unsigned
name|short
name|ws_ypixel
decl_stmt|;
comment|/* vertical size, pixels */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TIOCMODG
value|_IOR('t', 3, int)
end_define

begin_comment
comment|/* get modem control state */
end_comment

begin_define
define|#
directive|define
name|TIOCMODS
value|_IOW('t', 4, int)
end_define

begin_comment
comment|/* set modem control state */
end_comment

begin_define
define|#
directive|define
name|TIOCM_LE
value|0001
end_define

begin_comment
comment|/* line enable */
end_comment

begin_define
define|#
directive|define
name|TIOCM_DTR
value|0002
end_define

begin_comment
comment|/* data terminal ready */
end_comment

begin_define
define|#
directive|define
name|TIOCM_RTS
value|0004
end_define

begin_comment
comment|/* request to send */
end_comment

begin_define
define|#
directive|define
name|TIOCM_ST
value|0010
end_define

begin_comment
comment|/* secondary transmit */
end_comment

begin_define
define|#
directive|define
name|TIOCM_SR
value|0020
end_define

begin_comment
comment|/* secondary receive */
end_comment

begin_define
define|#
directive|define
name|TIOCM_CTS
value|0040
end_define

begin_comment
comment|/* clear to send */
end_comment

begin_define
define|#
directive|define
name|TIOCM_CAR
value|0100
end_define

begin_comment
comment|/* carrier detect */
end_comment

begin_define
define|#
directive|define
name|TIOCM_CD
value|TIOCM_CAR
end_define

begin_define
define|#
directive|define
name|TIOCM_RNG
value|0200
end_define

begin_comment
comment|/* ring */
end_comment

begin_define
define|#
directive|define
name|TIOCM_RI
value|TIOCM_RNG
end_define

begin_define
define|#
directive|define
name|TIOCM_DSR
value|0400
end_define

begin_comment
comment|/* data set ready */
end_comment

begin_comment
comment|/* 8-10 compat */
end_comment

begin_define
define|#
directive|define
name|TIOCEXCL
value|_IO('t', 13)
end_define

begin_comment
comment|/* set exclusive use of tty */
end_comment

begin_define
define|#
directive|define
name|TIOCNXCL
value|_IO('t', 14)
end_define

begin_comment
comment|/* reset exclusive use of tty */
end_comment

begin_comment
comment|/* 15 unused */
end_comment

begin_define
define|#
directive|define
name|TIOCFLUSH
value|_IOW('t', 16, int)
end_define

begin_comment
comment|/* flush buffers */
end_comment

begin_comment
comment|/* 17-18 compat */
end_comment

begin_define
define|#
directive|define
name|TIOCGETA
value|_IOR('t', 19, struct termios)
end_define

begin_comment
comment|/* get termios struct */
end_comment

begin_define
define|#
directive|define
name|TIOCSETA
value|_IOW('t', 20, struct termios)
end_define

begin_comment
comment|/* set termios struct */
end_comment

begin_define
define|#
directive|define
name|TIOCSETAW
value|_IOW('t', 21, struct termios)
end_define

begin_comment
comment|/* drain output, set */
end_comment

begin_define
define|#
directive|define
name|TIOCSETAF
value|_IOW('t', 22, struct termios)
end_define

begin_comment
comment|/* drn out, fls in, set */
end_comment

begin_define
define|#
directive|define
name|TIOCGETD
value|_IOR('t', 26, int)
end_define

begin_comment
comment|/* get line discipline */
end_comment

begin_define
define|#
directive|define
name|TIOCSETD
value|_IOW('t', 27, int)
end_define

begin_comment
comment|/* set line discipline */
end_comment

begin_comment
comment|/* 127-124 compat */
end_comment

begin_define
define|#
directive|define
name|TIOCSBRK
value|_IO('t', 123)
end_define

begin_comment
comment|/* set break bit */
end_comment

begin_define
define|#
directive|define
name|TIOCCBRK
value|_IO('t', 122)
end_define

begin_comment
comment|/* clear break bit */
end_comment

begin_define
define|#
directive|define
name|TIOCSDTR
value|_IO('t', 121)
end_define

begin_comment
comment|/* set data terminal ready */
end_comment

begin_define
define|#
directive|define
name|TIOCCDTR
value|_IO('t', 120)
end_define

begin_comment
comment|/* clear data terminal ready */
end_comment

begin_define
define|#
directive|define
name|TIOCGPGRP
value|_IOR('t', 119, int)
end_define

begin_comment
comment|/* get pgrp of tty */
end_comment

begin_define
define|#
directive|define
name|TIOCSPGRP
value|_IOW('t', 118, int)
end_define

begin_comment
comment|/* set pgrp of tty */
end_comment

begin_comment
comment|/* 117-116 compat */
end_comment

begin_define
define|#
directive|define
name|TIOCOUTQ
value|_IOR('t', 115, int)
end_define

begin_comment
comment|/* output queue size */
end_comment

begin_define
define|#
directive|define
name|TIOCSTI
value|_IOW('t', 114, char)
end_define

begin_comment
comment|/* simulate terminal input */
end_comment

begin_define
define|#
directive|define
name|TIOCNOTTY
value|_IO('t', 113)
end_define

begin_comment
comment|/* void tty association */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT
value|_IOW('t', 112, int)
end_define

begin_comment
comment|/* pty: set/clear packet mode */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_DATA
value|0x00
end_define

begin_comment
comment|/* data packet */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_FLUSHREAD
value|0x01
end_define

begin_comment
comment|/* flush packet */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_FLUSHWRITE
value|0x02
end_define

begin_comment
comment|/* flush packet */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_STOP
value|0x04
end_define

begin_comment
comment|/* stop output */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_START
value|0x08
end_define

begin_comment
comment|/* start output */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_NOSTOP
value|0x10
end_define

begin_comment
comment|/* no more ^S, ^Q */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_DOSTOP
value|0x20
end_define

begin_comment
comment|/* now do ^S ^Q */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_IOCTL
value|0x40
end_define

begin_comment
comment|/* state change of pty driver */
end_comment

begin_define
define|#
directive|define
name|TIOCSTOP
value|_IO('t', 111)
end_define

begin_comment
comment|/* stop output, like ^S */
end_comment

begin_define
define|#
directive|define
name|TIOCSTART
value|_IO('t', 110)
end_define

begin_comment
comment|/* start output, like ^Q */
end_comment

begin_define
define|#
directive|define
name|TIOCMSET
value|_IOW('t', 109, int)
end_define

begin_comment
comment|/* set all modem bits */
end_comment

begin_define
define|#
directive|define
name|TIOCMBIS
value|_IOW('t', 108, int)
end_define

begin_comment
comment|/* bis modem bits */
end_comment

begin_define
define|#
directive|define
name|TIOCMBIC
value|_IOW('t', 107, int)
end_define

begin_comment
comment|/* bic modem bits */
end_comment

begin_define
define|#
directive|define
name|TIOCMGET
value|_IOR('t', 106, int)
end_define

begin_comment
comment|/* get all modem bits */
end_comment

begin_define
define|#
directive|define
name|TIOCREMOTE
value|_IOW('t', 105, int)
end_define

begin_comment
comment|/* remote input editing */
end_comment

begin_define
define|#
directive|define
name|TIOCGWINSZ
value|_IOR('t', 104, struct winsize)
end_define

begin_comment
comment|/* get window size */
end_comment

begin_define
define|#
directive|define
name|TIOCSWINSZ
value|_IOW('t', 103, struct winsize)
end_define

begin_comment
comment|/* set window size */
end_comment

begin_define
define|#
directive|define
name|TIOCUCNTL
value|_IOW('t', 102, int)
end_define

begin_comment
comment|/* pty: set/clr usr cntl mode */
end_comment

begin_define
define|#
directive|define
name|TIOCSTAT
value|_IO('t', 101)
end_define

begin_comment
comment|/* simulate ^T status message */
end_comment

begin_define
define|#
directive|define
name|UIOCCMD
parameter_list|(
name|n
parameter_list|)
value|_IO('u', n)
end_define

begin_comment
comment|/* usr cntl op "n" */
end_comment

begin_define
define|#
directive|define
name|TIOCCONS
value|_IOW('t', 98, int)
end_define

begin_comment
comment|/* become virtual console */
end_comment

begin_define
define|#
directive|define
name|TIOCSCTTY
value|_IO('t', 97)
end_define

begin_comment
comment|/* become controlling tty */
end_comment

begin_define
define|#
directive|define
name|TIOCEXT
value|_IOW('t', 96, int)
end_define

begin_comment
comment|/* pty: external processing */
end_comment

begin_define
define|#
directive|define
name|TIOCSIG
value|_IO('t', 95)
end_define

begin_comment
comment|/* pty: generate signal */
end_comment

begin_define
define|#
directive|define
name|TIOCDRAIN
value|_IO('t', 94)
end_define

begin_comment
comment|/* wait till output drained */
end_comment

begin_define
define|#
directive|define
name|TIOCMSDTRWAIT
value|_IOW('t', 91, int)
end_define

begin_comment
comment|/* modem: set wait on close */
end_comment

begin_define
define|#
directive|define
name|TIOCMGDTRWAIT
value|_IOR('t', 90, int)
end_define

begin_comment
comment|/* modem: get wait on close */
end_comment

begin_define
define|#
directive|define
name|TIOCTIMESTAMP
value|_IOR('t', 89, struct timeval)
end_define

begin_comment
comment|/* enable/get timestamp 						 * of last input event */
end_comment

begin_define
define|#
directive|define
name|TIOCDCDTIMESTAMP
value|_IOR('t', 88, struct timeval)
end_define

begin_comment
comment|/* enable/get timestamp 						 * of last DCd rise */
end_comment

begin_define
define|#
directive|define
name|TIOCSDRAINWAIT
value|_IOW('t', 87, int)
end_define

begin_comment
comment|/* set ttywait timeout */
end_comment

begin_define
define|#
directive|define
name|TIOCGDRAINWAIT
value|_IOR('t', 86, int)
end_define

begin_comment
comment|/* get ttywait timeout */
end_comment

begin_define
define|#
directive|define
name|TTYDISC
value|0
end_define

begin_comment
comment|/* termios tty line discipline */
end_comment

begin_define
define|#
directive|define
name|SLIPDISC
value|4
end_define

begin_comment
comment|/* serial IP discipline */
end_comment

begin_define
define|#
directive|define
name|PPPDISC
value|5
end_define

begin_comment
comment|/* PPP discipline */
end_comment

begin_define
define|#
directive|define
name|NETGRAPHDISC
value|6
end_define

begin_comment
comment|/* Netgraph tty node discipline */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TTYCOM_H_ */
end_comment

end_unit

