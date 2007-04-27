begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ioctl_compat.h	8.4 (Berkeley) 1/21/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_IOCTL_COMPAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_IOCTL_COMPAT_H_
end_define

begin_include
include|#
directive|include
file|<sys/ttychars.h>
end_include

begin_include
include|#
directive|include
file|<sys/ttydev.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OLD_TTY
end_ifdef

begin_warning
warning|#
directive|warning
literal|"Old BSD tty API used and depends on COMPAT_43TTY. Use termios.h instead"
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|tchars
block|{
name|char
name|t_intrc
decl_stmt|;
comment|/* interrupt */
name|char
name|t_quitc
decl_stmt|;
comment|/* quit */
name|char
name|t_startc
decl_stmt|;
comment|/* start output */
name|char
name|t_stopc
decl_stmt|;
comment|/* stop output */
name|char
name|t_eofc
decl_stmt|;
comment|/* end-of-file */
name|char
name|t_brkc
decl_stmt|;
comment|/* input delimiter (like nl) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ltchars
block|{
name|char
name|t_suspc
decl_stmt|;
comment|/* stop process signal */
name|char
name|t_dsuspc
decl_stmt|;
comment|/* delayed stop process signal */
name|char
name|t_rprntc
decl_stmt|;
comment|/* reprint line */
name|char
name|t_flushc
decl_stmt|;
comment|/* flush output (toggles) */
name|char
name|t_werasc
decl_stmt|;
comment|/* word erase */
name|char
name|t_lnextc
decl_stmt|;
comment|/* literal next character */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure for TIOCGETP and TIOCSETP ioctls.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SGTTYB_
end_ifndef

begin_define
define|#
directive|define
name|_SGTTYB_
end_define

begin_struct
struct|struct
name|sgttyb
block|{
name|char
name|sg_ispeed
decl_stmt|;
comment|/* input speed */
name|char
name|sg_ospeed
decl_stmt|;
comment|/* output speed */
name|char
name|sg_erase
decl_stmt|;
comment|/* erase character */
name|char
name|sg_kill
decl_stmt|;
comment|/* kill character */
name|short
name|sg_flags
decl_stmt|;
comment|/* mode flags */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OLD_TTY
end_ifdef

begin_undef
undef|#
directive|undef
name|TIOCGETD
end_undef

begin_define
define|#
directive|define
name|TIOCGETD
value|_IOR('t', 0, int)
end_define

begin_comment
comment|/* get line discipline */
end_comment

begin_undef
undef|#
directive|undef
name|TIOCSETD
end_undef

begin_define
define|#
directive|define
name|TIOCSETD
value|_IOW('t', 1, int)
end_define

begin_comment
comment|/* set line discipline */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OTIOCGETD
value|_IOR('t', 0, int)
end_define

begin_comment
comment|/* get line discipline */
end_comment

begin_define
define|#
directive|define
name|OTIOCSETD
value|_IOW('t', 1, int)
end_define

begin_comment
comment|/* set line discipline */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TIOCHPCL
value|_IO('t', 2)
end_define

begin_comment
comment|/* hang up on last close */
end_comment

begin_define
define|#
directive|define
name|TIOCGETP
value|_IOR('t', 8,struct sgttyb)
end_define

begin_comment
comment|/* get parameters -- gtty */
end_comment

begin_define
define|#
directive|define
name|TIOCSETP
value|_IOW('t', 9,struct sgttyb)
end_define

begin_comment
comment|/* set parameters -- stty */
end_comment

begin_define
define|#
directive|define
name|TIOCSETN
value|_IOW('t',10,struct sgttyb)
end_define

begin_comment
comment|/* as above, but no flushtty*/
end_comment

begin_define
define|#
directive|define
name|TIOCSETC
value|_IOW('t',17,struct tchars)
end_define

begin_comment
comment|/* set special characters */
end_comment

begin_define
define|#
directive|define
name|TIOCGETC
value|_IOR('t',18,struct tchars)
end_define

begin_comment
comment|/* get special characters */
end_comment

begin_define
define|#
directive|define
name|TANDEM
value|0x00000001
end_define

begin_comment
comment|/* send stopc on out q full */
end_comment

begin_define
define|#
directive|define
name|CBREAK
value|0x00000002
end_define

begin_comment
comment|/* half-cooked mode */
end_comment

begin_define
define|#
directive|define
name|LCASE
value|0x00000004
end_define

begin_comment
comment|/* simulate lower case */
end_comment

begin_define
define|#
directive|define
name|ECHO
value|0x00000008
end_define

begin_comment
comment|/* echo input */
end_comment

begin_define
define|#
directive|define
name|CRMOD
value|0x00000010
end_define

begin_comment
comment|/* map \r to \r\n on output */
end_comment

begin_define
define|#
directive|define
name|RAW
value|0x00000020
end_define

begin_comment
comment|/* no i/o processing */
end_comment

begin_define
define|#
directive|define
name|ODDP
value|0x00000040
end_define

begin_comment
comment|/* get/send odd parity */
end_comment

begin_define
define|#
directive|define
name|EVENP
value|0x00000080
end_define

begin_comment
comment|/* get/send even parity */
end_comment

begin_define
define|#
directive|define
name|ANYP
value|0x000000c0
end_define

begin_comment
comment|/* get any parity/send none */
end_comment

begin_define
define|#
directive|define
name|NLDELAY
value|0x00000300
end_define

begin_comment
comment|/* \n delay */
end_comment

begin_define
define|#
directive|define
name|NL0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NL1
value|0x00000100
end_define

begin_comment
comment|/* tty 37 */
end_comment

begin_define
define|#
directive|define
name|NL2
value|0x00000200
end_define

begin_comment
comment|/* vt05 */
end_comment

begin_define
define|#
directive|define
name|NL3
value|0x00000300
end_define

begin_define
define|#
directive|define
name|TBDELAY
value|0x00000c00
end_define

begin_comment
comment|/* horizontal tab delay */
end_comment

begin_define
define|#
directive|define
name|TAB0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|TAB1
value|0x00000400
end_define

begin_comment
comment|/* tty 37 */
end_comment

begin_define
define|#
directive|define
name|TAB2
value|0x00000800
end_define

begin_define
define|#
directive|define
name|XTABS
value|0x00000c00
end_define

begin_comment
comment|/* expand tabs on output */
end_comment

begin_define
define|#
directive|define
name|CRDELAY
value|0x00003000
end_define

begin_comment
comment|/* \r delay */
end_comment

begin_define
define|#
directive|define
name|CR0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CR1
value|0x00001000
end_define

begin_comment
comment|/* tn 300 */
end_comment

begin_define
define|#
directive|define
name|CR2
value|0x00002000
end_define

begin_comment
comment|/* tty 37 */
end_comment

begin_define
define|#
directive|define
name|CR3
value|0x00003000
end_define

begin_comment
comment|/* concept 100 */
end_comment

begin_define
define|#
directive|define
name|VTDELAY
value|0x00004000
end_define

begin_comment
comment|/* vertical tab delay */
end_comment

begin_define
define|#
directive|define
name|FF0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FF1
value|0x00004000
end_define

begin_comment
comment|/* tty 37 */
end_comment

begin_define
define|#
directive|define
name|BSDELAY
value|0x00008000
end_define

begin_comment
comment|/* \b delay */
end_comment

begin_define
define|#
directive|define
name|BS0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BS1
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ALLDELAY
value|(NLDELAY|TBDELAY|CRDELAY|VTDELAY|BSDELAY)
end_define

begin_define
define|#
directive|define
name|CRTBS
value|0x00010000
end_define

begin_comment
comment|/* do backspacing for crt */
end_comment

begin_define
define|#
directive|define
name|PRTERA
value|0x00020000
end_define

begin_comment
comment|/* \ ... / erase */
end_comment

begin_define
define|#
directive|define
name|CRTERA
value|0x00040000
end_define

begin_comment
comment|/* " \b " to wipe out char */
end_comment

begin_define
define|#
directive|define
name|TILDE
value|0x00080000
end_define

begin_comment
comment|/* hazeltine tilde kludge */
end_comment

begin_define
define|#
directive|define
name|MDMBUF
value|0x00100000
end_define

begin_comment
comment|/*start/stop output on carrier*/
end_comment

begin_define
define|#
directive|define
name|LITOUT
value|0x00200000
end_define

begin_comment
comment|/* literal output */
end_comment

begin_define
define|#
directive|define
name|TOSTOP
value|0x00400000
end_define

begin_comment
comment|/*SIGSTOP on background output*/
end_comment

begin_define
define|#
directive|define
name|FLUSHO
value|0x00800000
end_define

begin_comment
comment|/* flush output to terminal */
end_comment

begin_define
define|#
directive|define
name|NOHANG
value|0x01000000
end_define

begin_comment
comment|/* (no-op) was no SIGHUP on carrier drop */
end_comment

begin_define
define|#
directive|define
name|L001000
value|0x02000000
end_define

begin_define
define|#
directive|define
name|CRTKIL
value|0x04000000
end_define

begin_comment
comment|/* kill line with " \b " */
end_comment

begin_define
define|#
directive|define
name|PASS8
value|0x08000000
end_define

begin_define
define|#
directive|define
name|CTLECH
value|0x10000000
end_define

begin_comment
comment|/* echo control chars as ^X */
end_comment

begin_define
define|#
directive|define
name|PENDIN
value|0x20000000
end_define

begin_comment
comment|/* tp->t_rawq needs reread */
end_comment

begin_define
define|#
directive|define
name|DECCTQ
value|0x40000000
end_define

begin_comment
comment|/* only ^Q starts after ^S */
end_comment

begin_define
define|#
directive|define
name|NOFLSH
value|0x80000000
end_define

begin_comment
comment|/* no output flush on signal */
end_comment

begin_define
define|#
directive|define
name|TIOCLBIS
value|_IOW('t', 127, int)
end_define

begin_comment
comment|/* bis local mode bits */
end_comment

begin_define
define|#
directive|define
name|TIOCLBIC
value|_IOW('t', 126, int)
end_define

begin_comment
comment|/* bic local mode bits */
end_comment

begin_define
define|#
directive|define
name|TIOCLSET
value|_IOW('t', 125, int)
end_define

begin_comment
comment|/* set entire local mode word */
end_comment

begin_define
define|#
directive|define
name|TIOCLGET
value|_IOR('t', 124, int)
end_define

begin_comment
comment|/* get local modes */
end_comment

begin_define
define|#
directive|define
name|LCRTBS
value|(CRTBS>>16)
end_define

begin_define
define|#
directive|define
name|LPRTERA
value|(PRTERA>>16)
end_define

begin_define
define|#
directive|define
name|LCRTERA
value|(CRTERA>>16)
end_define

begin_define
define|#
directive|define
name|LTILDE
value|(TILDE>>16)
end_define

begin_define
define|#
directive|define
name|LMDMBUF
value|(MDMBUF>>16)
end_define

begin_define
define|#
directive|define
name|LLITOUT
value|(LITOUT>>16)
end_define

begin_define
define|#
directive|define
name|LTOSTOP
value|(TOSTOP>>16)
end_define

begin_define
define|#
directive|define
name|LFLUSHO
value|(FLUSHO>>16)
end_define

begin_define
define|#
directive|define
name|LNOHANG
value|(NOHANG>>16)
end_define

begin_define
define|#
directive|define
name|LCRTKIL
value|(CRTKIL>>16)
end_define

begin_define
define|#
directive|define
name|LPASS8
value|(PASS8>>16)
end_define

begin_define
define|#
directive|define
name|LCTLECH
value|(CTLECH>>16)
end_define

begin_define
define|#
directive|define
name|LPENDIN
value|(PENDIN>>16)
end_define

begin_define
define|#
directive|define
name|LDECCTQ
value|(DECCTQ>>16)
end_define

begin_define
define|#
directive|define
name|LNOFLSH
value|(NOFLSH>>16)
end_define

begin_define
define|#
directive|define
name|TIOCSLTC
value|_IOW('t',117,struct ltchars)
end_define

begin_comment
comment|/* set local special chars*/
end_comment

begin_define
define|#
directive|define
name|TIOCGLTC
value|_IOR('t',116,struct ltchars)
end_define

begin_comment
comment|/* get local special chars*/
end_comment

begin_define
define|#
directive|define
name|OTIOCCONS
value|_IO('t', 98)
end_define

begin_comment
comment|/* for hp300 -- sans int arg */
end_comment

begin_define
define|#
directive|define
name|OTTYDISC
value|0
end_define

begin_define
define|#
directive|define
name|NETLDISC
value|1
end_define

begin_define
define|#
directive|define
name|NTTYDISC
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_IOCTL_COMPAT_H_ */
end_comment

end_unit

