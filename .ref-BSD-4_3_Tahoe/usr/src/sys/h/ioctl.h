begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ioctl.h	7.6 (Berkeley) 12/18/87  */
end_comment

begin_comment
comment|/*  * Ioctl definitions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOCTL_
end_ifndef

begin_define
define|#
directive|define
name|_IOCTL_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"ttychars.h"
end_include

begin_include
include|#
directive|include
file|"ttydev.h"
end_include

begin_else
else|#
directive|else
end_else

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

begin_comment
comment|/*  * Window/terminal size structure.  * This information is stored by the kernel  * in order to provide a consistent interface,  * but is not used by the kernel.  *  * Type must be "unsigned short" so that types.h not required.  */
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

begin_comment
comment|/*  * Pun for SUN.  */
end_comment

begin_struct
struct|struct
name|ttysize
block|{
name|unsigned
name|short
name|ts_lines
decl_stmt|;
name|unsigned
name|short
name|ts_cols
decl_stmt|;
name|unsigned
name|short
name|ts_xxx
decl_stmt|;
name|unsigned
name|short
name|ts_yyy
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TIOCGSIZE
value|TIOCGWINSZ
end_define

begin_define
define|#
directive|define
name|TIOCSSIZE
value|TIOCSWINSZ
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_IO
end_ifndef

begin_comment
comment|/*  * Ioctl's have the command encoded in the lower word,  * and the size of any in or out parameters in the upper  * word.  The high 3 bits of the upper word are used  * to encode the in/out status of the parameter.  */
end_comment

begin_define
define|#
directive|define
name|IOCPARM_MASK
value|0x1fff
end_define

begin_comment
comment|/* parameter length, at most 13 bits */
end_comment

begin_define
define|#
directive|define
name|IOCPARM_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& IOCPARM_MASK)
end_define

begin_define
define|#
directive|define
name|IOCPARM_MAX
value|NBPG
end_define

begin_comment
comment|/* max size of ioctl, mult. of NBPG */
end_comment

begin_define
define|#
directive|define
name|IOC_VOID
value|0x20000000
end_define

begin_comment
comment|/* no parameters */
end_comment

begin_define
define|#
directive|define
name|IOC_OUT
value|0x40000000
end_define

begin_comment
comment|/* copy out parameters */
end_comment

begin_define
define|#
directive|define
name|IOC_IN
value|0x80000000
end_define

begin_comment
comment|/* copy in parameters */
end_comment

begin_define
define|#
directive|define
name|IOC_INOUT
value|(IOC_IN|IOC_OUT)
end_define

begin_define
define|#
directive|define
name|IOC_DIRMASK
value|0xe0000000
end_define

begin_comment
comment|/* mask for IN/OUT/VOID */
end_comment

begin_comment
comment|/* the 0x20000000 is so we can distinguish new ioctl's from old */
end_comment

begin_define
define|#
directive|define
name|_IO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(IOC_VOID|(x<<8)|y)
end_define

begin_define
define|#
directive|define
name|_IOR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|t
parameter_list|)
value|(IOC_OUT|((sizeof(t)&IOCPARM_MASK)<<16)|(x<<8)|y)
end_define

begin_define
define|#
directive|define
name|_IOW
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|t
parameter_list|)
value|(IOC_IN|((sizeof(t)&IOCPARM_MASK)<<16)|(x<<8)|y)
end_define

begin_comment
comment|/* this should be _IORW, but stdio got there first */
end_comment

begin_define
define|#
directive|define
name|_IOWR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|t
parameter_list|)
value|(IOC_INOUT|((sizeof(t)&IOCPARM_MASK)<<16)|(x<<8)|y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * tty ioctl commands  */
end_comment

begin_define
define|#
directive|define
name|TIOCGETD
value|_IOR('t', 0, int)
end_define

begin_comment
comment|/* get line discipline */
end_comment

begin_define
define|#
directive|define
name|TIOCSETD
value|_IOW('t', 1, int)
end_define

begin_comment
comment|/* set line discipline */
end_comment

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
comment|/* as above, but no flushtty */
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

begin_define
define|#
directive|define
name|TIOCFLUSH
value|_IOW('t', 16, int)
end_define

begin_comment
comment|/* flush buffers */
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
comment|/* start/stop output on carrier intr */
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
comment|/* SIGSTOP on background output */
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
comment|/* no SIGHUP on carrier drop */
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

begin_comment
comment|/* locals, from 127 down */
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

begin_define
define|#
directive|define
name|TIOCSLTC
value|_IOW('t',117,struct ltchars)
end_define

begin_comment
comment|/* set local special chars */
end_comment

begin_define
define|#
directive|define
name|TIOCGLTC
value|_IOR('t',116,struct ltchars)
end_define

begin_comment
comment|/* get local special chars */
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
value|_IO('t', 98)
end_define

begin_comment
comment|/* become virtual console */
end_comment

begin_define
define|#
directive|define
name|OTTYDISC
value|0
end_define

begin_comment
comment|/* old, v7 std tty driver */
end_comment

begin_define
define|#
directive|define
name|NETLDISC
value|1
end_define

begin_comment
comment|/* line discip for berk net */
end_comment

begin_define
define|#
directive|define
name|NTTYDISC
value|2
end_define

begin_comment
comment|/* new tty discipline */
end_comment

begin_define
define|#
directive|define
name|TABLDISC
value|3
end_define

begin_comment
comment|/* tablet discipline */
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
name|FIOCLEX
value|_IO('f', 1)
end_define

begin_comment
comment|/* set close on exec on fd */
end_comment

begin_define
define|#
directive|define
name|FIONCLEX
value|_IO('f', 2)
end_define

begin_comment
comment|/* remove close on exec */
end_comment

begin_comment
comment|/* another local */
end_comment

begin_define
define|#
directive|define
name|FIONREAD
value|_IOR('f', 127, int)
end_define

begin_comment
comment|/* get # bytes to read */
end_comment

begin_define
define|#
directive|define
name|FIONBIO
value|_IOW('f', 126, int)
end_define

begin_comment
comment|/* set/clear non-blocking i/o */
end_comment

begin_define
define|#
directive|define
name|FIOASYNC
value|_IOW('f', 125, int)
end_define

begin_comment
comment|/* set/clear async i/o */
end_comment

begin_define
define|#
directive|define
name|FIOSETOWN
value|_IOW('f', 124, int)
end_define

begin_comment
comment|/* set owner */
end_comment

begin_define
define|#
directive|define
name|FIOGETOWN
value|_IOR('f', 123, int)
end_define

begin_comment
comment|/* get owner */
end_comment

begin_comment
comment|/* socket i/o controls */
end_comment

begin_define
define|#
directive|define
name|SIOCSHIWAT
value|_IOW('s',  0, int)
end_define

begin_comment
comment|/* set high watermark */
end_comment

begin_define
define|#
directive|define
name|SIOCGHIWAT
value|_IOR('s',  1, int)
end_define

begin_comment
comment|/* get high watermark */
end_comment

begin_define
define|#
directive|define
name|SIOCSLOWAT
value|_IOW('s',  2, int)
end_define

begin_comment
comment|/* set low watermark */
end_comment

begin_define
define|#
directive|define
name|SIOCGLOWAT
value|_IOR('s',  3, int)
end_define

begin_comment
comment|/* get low watermark */
end_comment

begin_define
define|#
directive|define
name|SIOCATMARK
value|_IOR('s',  7, int)
end_define

begin_comment
comment|/* at oob mark? */
end_comment

begin_define
define|#
directive|define
name|SIOCSPGRP
value|_IOW('s',  8, int)
end_define

begin_comment
comment|/* set process group */
end_comment

begin_define
define|#
directive|define
name|SIOCGPGRP
value|_IOR('s',  9, int)
end_define

begin_comment
comment|/* get process group */
end_comment

begin_define
define|#
directive|define
name|SIOCADDRT
value|_IOW('r', 10, struct rtentry)
end_define

begin_comment
comment|/* add route */
end_comment

begin_define
define|#
directive|define
name|SIOCDELRT
value|_IOW('r', 11, struct rtentry)
end_define

begin_comment
comment|/* delete route */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFADDR
value|_IOW('i', 12, struct ifreq)
end_define

begin_comment
comment|/* set ifnet address */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFADDR
value|_IOWR('i',13, struct ifreq)
end_define

begin_comment
comment|/* get ifnet address */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFDSTADDR
value|_IOW('i', 14, struct ifreq)
end_define

begin_comment
comment|/* set p-p address */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFDSTADDR
value|_IOWR('i',15, struct ifreq)
end_define

begin_comment
comment|/* get p-p address */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFFLAGS
value|_IOW('i', 16, struct ifreq)
end_define

begin_comment
comment|/* set ifnet flags */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFFLAGS
value|_IOWR('i',17, struct ifreq)
end_define

begin_comment
comment|/* get ifnet flags */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFBRDADDR
value|_IOWR('i',18, struct ifreq)
end_define

begin_comment
comment|/* get broadcast addr */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFBRDADDR
value|_IOW('i',19, struct ifreq)
end_define

begin_comment
comment|/* set broadcast addr */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFCONF
value|_IOWR('i',20, struct ifconf)
end_define

begin_comment
comment|/* get ifnet list */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFNETMASK
value|_IOWR('i',21, struct ifreq)
end_define

begin_comment
comment|/* get net addr mask */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFNETMASK
value|_IOW('i',22, struct ifreq)
end_define

begin_comment
comment|/* set net addr mask */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFMETRIC
value|_IOWR('i',23, struct ifreq)
end_define

begin_comment
comment|/* get IF metric */
end_comment

begin_define
define|#
directive|define
name|SIOCSIFMETRIC
value|_IOW('i',24, struct ifreq)
end_define

begin_comment
comment|/* set IF metric */
end_comment

begin_define
define|#
directive|define
name|SIOCSARP
value|_IOW('i', 30, struct arpreq)
end_define

begin_comment
comment|/* set arp entry */
end_comment

begin_define
define|#
directive|define
name|SIOCGARP
value|_IOWR('i',31, struct arpreq)
end_define

begin_comment
comment|/* get arp entry */
end_comment

begin_define
define|#
directive|define
name|SIOCDARP
value|_IOW('i', 32, struct arpreq)
end_define

begin_comment
comment|/* delete arp entry */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

