begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	ioctl.h	4.14	82/01/19	*/
end_comment

begin_comment
comment|/*  * ioctl definitions, and special character and local tty definitions  */
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
comment|/*  * local mode settings  */
end_comment

begin_define
define|#
directive|define
name|LCRTBS
value|0000001
end_define

begin_comment
comment|/* correct backspacing for crt */
end_comment

begin_define
define|#
directive|define
name|LPRTERA
value|0000002
end_define

begin_comment
comment|/* printing terminal \ ... / erase */
end_comment

begin_define
define|#
directive|define
name|LCRTERA
value|0000004
end_define

begin_comment
comment|/* do " \b " to wipe out character */
end_comment

begin_define
define|#
directive|define
name|LTILDE
value|0000010
end_define

begin_comment
comment|/* IIASA - hazeltine tilde kludge */
end_comment

begin_define
define|#
directive|define
name|LMDMBUF
value|0000020
end_define

begin_comment
comment|/* IIASA - start/stop output on carrier intr */
end_comment

begin_define
define|#
directive|define
name|LLITOUT
value|0000040
end_define

begin_comment
comment|/* IIASA - suppress any output translations */
end_comment

begin_define
define|#
directive|define
name|LTOSTOP
value|0000100
end_define

begin_comment
comment|/* send stop for any background tty output */
end_comment

begin_define
define|#
directive|define
name|LFLUSHO
value|0000200
end_define

begin_comment
comment|/* flush output sent to terminal */
end_comment

begin_define
define|#
directive|define
name|LNOHANG
value|0000400
end_define

begin_comment
comment|/* IIASA - don't send hangup on carrier drop */
end_comment

begin_define
define|#
directive|define
name|LETXACK
value|0001000
end_define

begin_comment
comment|/* IIASA - diablo style buffer hacking */
end_comment

begin_define
define|#
directive|define
name|LCRTKIL
value|0002000
end_define

begin_comment
comment|/* erase whole line on kill with " \b " */
end_comment

begin_define
define|#
directive|define
name|L004000
value|0004000
end_define

begin_define
define|#
directive|define
name|LCTLECH
value|0010000
end_define

begin_comment
comment|/* echo control characters as ^X */
end_comment

begin_define
define|#
directive|define
name|LPENDIN
value|0020000
end_define

begin_comment
comment|/* tp->t_rawq is waiting to be reread */
end_comment

begin_define
define|#
directive|define
name|LDECCTQ
value|0040000
end_define

begin_comment
comment|/* only ^Q starts after ^S */
end_comment

begin_define
define|#
directive|define
name|LNOFLSH
value|0100000
end_define

begin_comment
comment|/* dont flush output on signals */
end_comment

begin_comment
comment|/* local state */
end_comment

begin_define
define|#
directive|define
name|LSBKSL
value|01
end_define

begin_comment
comment|/* state bit for lowercase backslash work */
end_comment

begin_define
define|#
directive|define
name|LSQUOT
value|02
end_define

begin_comment
comment|/* last character input was \ */
end_comment

begin_define
define|#
directive|define
name|LSERASE
value|04
end_define

begin_comment
comment|/* within a \.../ for LPRTRUB */
end_comment

begin_define
define|#
directive|define
name|LSLNCH
value|010
end_define

begin_comment
comment|/* next character is literal */
end_comment

begin_define
define|#
directive|define
name|LSTYPEN
value|020
end_define

begin_comment
comment|/* retyping suspended input (LPENDIN) */
end_comment

begin_define
define|#
directive|define
name|LSCNTTB
value|040
end_define

begin_comment
comment|/* counting width of tab; leave LFLUSHO alone */
end_comment

begin_comment
comment|/*  * tty ioctl commands  */
end_comment

begin_define
define|#
directive|define
name|TIOCGETD
value|(('t'<<8)|0)
end_define

begin_comment
comment|/* get line discipline */
end_comment

begin_define
define|#
directive|define
name|TIOCSETD
value|(('t'<<8)|1)
end_define

begin_comment
comment|/* set line discipline */
end_comment

begin_define
define|#
directive|define
name|TIOCHPCL
value|(('t'<<8)|2)
end_define

begin_comment
comment|/* set hangup line on close bit */
end_comment

begin_define
define|#
directive|define
name|TIOCMODG
value|(('t'<<8)|3)
end_define

begin_comment
comment|/* modem bits get (???) */
end_comment

begin_define
define|#
directive|define
name|TIOCMODS
value|(('t'<<8)|4)
end_define

begin_comment
comment|/* modem bits set (???) */
end_comment

begin_define
define|#
directive|define
name|TIOCGETP
value|(('t'<<8)|8)
end_define

begin_comment
comment|/* get parameters - like old gtty */
end_comment

begin_define
define|#
directive|define
name|TIOCSETP
value|(('t'<<8)|9)
end_define

begin_comment
comment|/* set parameters - like old stty */
end_comment

begin_define
define|#
directive|define
name|TIOCSETN
value|(('t'<<8)|10)
end_define

begin_comment
comment|/* set params w/o flushing buffers */
end_comment

begin_comment
comment|/* 13 was EXCL */
end_comment

begin_comment
comment|/* 14 was NEXCL */
end_comment

begin_define
define|#
directive|define
name|TIOCFLUSH
value|(('t'<<8)|16)
end_define

begin_comment
comment|/* flush buffers */
end_comment

begin_define
define|#
directive|define
name|TIOCSETC
value|(('t'<<8)|17)
end_define

begin_comment
comment|/* set special characters */
end_comment

begin_define
define|#
directive|define
name|TIOCGETC
value|(('t'<<8)|18)
end_define

begin_comment
comment|/* get special characters */
end_comment

begin_define
define|#
directive|define
name|TIOCIOANS
value|(('t'<<8)|20)
end_define

begin_define
define|#
directive|define
name|TIOCSIGNAL
value|(('t'<<8)|21)
end_define

begin_define
define|#
directive|define
name|TIOCUTTY
value|(('t'<<8)|22)
end_define

begin_comment
comment|/* locals, from 127 down */
end_comment

begin_define
define|#
directive|define
name|TIOCLBIS
value|(('t'<<8)|127)
end_define

begin_comment
comment|/* bis local mode bits */
end_comment

begin_define
define|#
directive|define
name|TIOCLBIC
value|(('t'<<8)|126)
end_define

begin_comment
comment|/* bic local mode bits */
end_comment

begin_define
define|#
directive|define
name|TIOCLSET
value|(('t'<<8)|125)
end_define

begin_comment
comment|/* set entire local mode word */
end_comment

begin_define
define|#
directive|define
name|TIOCLGET
value|(('t'<<8)|124)
end_define

begin_comment
comment|/* get local modes */
end_comment

begin_define
define|#
directive|define
name|TIOCSBRK
value|(('t'<<8)|123)
end_define

begin_comment
comment|/* set break bit */
end_comment

begin_define
define|#
directive|define
name|TIOCCBRK
value|(('t'<<8)|122)
end_define

begin_comment
comment|/* clear break bit */
end_comment

begin_define
define|#
directive|define
name|TIOCSDTR
value|(('t'<<8)|121)
end_define

begin_comment
comment|/* set data terminal ready */
end_comment

begin_define
define|#
directive|define
name|TIOCCDTR
value|(('t'<<8)|120)
end_define

begin_comment
comment|/* clear data terminal ready */
end_comment

begin_define
define|#
directive|define
name|TIOCGPGRP
value|(('t'<<8)|119)
end_define

begin_comment
comment|/* get pgrp of tty */
end_comment

begin_define
define|#
directive|define
name|TIOCSPGRP
value|(('t'<<8)|118)
end_define

begin_comment
comment|/* set pgrp of tty */
end_comment

begin_define
define|#
directive|define
name|TIOCSLTC
value|(('t'<<8)|117)
end_define

begin_comment
comment|/* set local special characters */
end_comment

begin_define
define|#
directive|define
name|TIOCGLTC
value|(('t'<<8)|116)
end_define

begin_comment
comment|/* get local special characters */
end_comment

begin_define
define|#
directive|define
name|TIOCOUTQ
value|(('t'<<8)|115)
end_define

begin_comment
comment|/* number of chars in output queue */
end_comment

begin_define
define|#
directive|define
name|TIOCSTI
value|(('t'<<8)|114)
end_define

begin_comment
comment|/* simulate a terminal in character */
end_comment

begin_define
define|#
directive|define
name|TIOCNOTTY
value|(('t'<<8)|113)
end_define

begin_comment
comment|/* get rid of tty association */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT
value|(('t'<<8)|112)
end_define

begin_comment
comment|/* on pty: set/clear packet mode */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_DATA
value|0
end_define

begin_comment
comment|/* data packet */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_FLUSHREAD
value|1
end_define

begin_comment
comment|/* flush packet */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_FLUSHWRITE
value|2
end_define

begin_comment
comment|/* flush packet */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_STOP
value|4
end_define

begin_comment
comment|/* stop output */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_START
value|8
end_define

begin_comment
comment|/* start output */
end_comment

begin_define
define|#
directive|define
name|TIOCSTOP
value|(('t'<<8)|111)
end_define

begin_comment
comment|/* stop output, like ^S */
end_comment

begin_define
define|#
directive|define
name|TIOCSTART
value|(('t'<<8)|110)
end_define

begin_comment
comment|/* start output, like ^Q */
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
name|FIOCLEX
value|(('f'<<8)|1)
end_define

begin_define
define|#
directive|define
name|FIONCLEX
value|(('f'<<8)|2)
end_define

begin_comment
comment|/* another local */
end_comment

begin_define
define|#
directive|define
name|FIONREAD
value|(('f'<<8)|127)
end_define

begin_comment
comment|/* get # bytes to read */
end_comment

begin_define
define|#
directive|define
name|FIONBIO
value|(('f'<<8)|126)
end_define

begin_define
define|#
directive|define
name|FIOASYNC
value|(('f'<<8)|125)
end_define

begin_define
define|#
directive|define
name|SIOCDONE
value|(('s'<<8)|0)
end_define

begin_comment
comment|/* shutdown read/write on socket */
end_comment

begin_define
define|#
directive|define
name|SIOCSKEEP
value|(('s'<<8)|1)
end_define

begin_comment
comment|/* set keep alive */
end_comment

begin_define
define|#
directive|define
name|SIOCGKEEP
value|(('s'<<8)|2)
end_define

begin_comment
comment|/* inspect keep alive */
end_comment

begin_define
define|#
directive|define
name|SIOCSLINGER
value|(('s'<<8)|3)
end_define

begin_comment
comment|/* set linger time */
end_comment

begin_define
define|#
directive|define
name|SIOCGLINGER
value|(('s'<<8)|4)
end_define

begin_comment
comment|/* get linger time */
end_comment

begin_define
define|#
directive|define
name|SIOCSENDOOB
value|(('s'<<8)|5)
end_define

begin_comment
comment|/* send out of band */
end_comment

begin_define
define|#
directive|define
name|SIOCRCVOOB
value|(('s'<<8)|6)
end_define

begin_comment
comment|/* get out of band */
end_comment

begin_define
define|#
directive|define
name|SIOCATMARK
value|(('s'<<8)|7)
end_define

begin_comment
comment|/* at out of band mark? */
end_comment

begin_define
define|#
directive|define
name|SIOCSPGRP
value|(('s'<<8)|8)
end_define

begin_comment
comment|/* set process group */
end_comment

begin_define
define|#
directive|define
name|SIOCGPGRP
value|(('s'<<8)|9)
end_define

begin_comment
comment|/* get process group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

