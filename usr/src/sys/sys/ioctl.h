begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	ioctl.h	4.21	82/08/01	*/
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
comment|/* modem control */
end_comment

begin_define
define|#
directive|define
name|MLE
value|0001
end_define

begin_comment
comment|/* line enable */
end_comment

begin_define
define|#
directive|define
name|MDTR
value|0002
end_define

begin_comment
comment|/* data terminal ready */
end_comment

begin_define
define|#
directive|define
name|MRTS
value|0004
end_define

begin_comment
comment|/* request to send */
end_comment

begin_define
define|#
directive|define
name|MST
value|0010
end_define

begin_comment
comment|/* secondary transmit */
end_comment

begin_define
define|#
directive|define
name|MSR
value|0020
end_define

begin_comment
comment|/* secondary receive */
end_comment

begin_define
define|#
directive|define
name|MCTS
value|0040
end_define

begin_comment
comment|/* clear to send */
end_comment

begin_define
define|#
directive|define
name|MCAR
value|0100
end_define

begin_comment
comment|/* carrier detect */
end_comment

begin_define
define|#
directive|define
name|MCD
value|MCAR
end_define

begin_define
define|#
directive|define
name|MRNG
value|0200
end_define

begin_comment
comment|/* ring */
end_comment

begin_define
define|#
directive|define
name|MRI
value|MRNG
end_define

begin_define
define|#
directive|define
name|MDSR
value|0400
end_define

begin_comment
comment|/* data set ready */
end_comment

begin_comment
comment|/*  * Ioctl's have the command encoded in the lower word,  * and the size of any in or out parameters in the upper  * word.  The high 2 bits of the upper word are used  * to encode the in/out status of the parameter; for now  * we restrict parameters to at most 128 bytes.  */
end_comment

begin_define
define|#
directive|define
name|IOCPARM_MASK
value|0x7f
end_define

begin_comment
comment|/* parameters must be< 128 bytes */
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
value|(IOC_VOID|('x'<<8)|y)
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
value|(IOC_OUT|((sizeof(t)&IOCPARM_MASK)<<16)|('x'<<8)|y)
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
value|(IOC_IN|((sizeof(t)&IOCPARM_MASK)<<16)|('x'<<8)|y)
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
value|(IOC_INOUT|((sizeof(t)&IOCPARM_MASK)<<16)|('x'<<8)|y)
end_define

begin_comment
comment|/*  * tty ioctl commands  */
end_comment

begin_define
define|#
directive|define
name|TIOCGETD
value|_IOR(t, 0, int)
end_define

begin_comment
comment|/* get line discipline */
end_comment

begin_define
define|#
directive|define
name|TIOCSETD
value|_IOW(t, 1, int)
end_define

begin_comment
comment|/* set line discipline */
end_comment

begin_define
define|#
directive|define
name|TIOCHPCL
value|_IO(t, 2)
end_define

begin_comment
comment|/* hang up on last close */
end_comment

begin_define
define|#
directive|define
name|TIOCMODG
value|_IOR(t, 3, int)
end_define

begin_comment
comment|/* get modem control state */
end_comment

begin_define
define|#
directive|define
name|TIOCMODS
value|_IOW(t, 4, int)
end_define

begin_comment
comment|/* set modem control state */
end_comment

begin_define
define|#
directive|define
name|TIOCGETP
value|_IOR(t, 8,struct sgttyb)
end_define

begin_comment
comment|/* get parameters -- gtty */
end_comment

begin_define
define|#
directive|define
name|TIOCSETP
value|_IOW(t, 9,struct sgttyb)
end_define

begin_comment
comment|/* set parameters -- stty */
end_comment

begin_define
define|#
directive|define
name|TIOCSETN
value|_IOW(t,10,struct sgttyb)
end_define

begin_comment
comment|/* as above, but no flushtty */
end_comment

begin_define
define|#
directive|define
name|TIOCEXCL
value|_IO(t, 13)
end_define

begin_comment
comment|/* set exclusive use of tty */
end_comment

begin_define
define|#
directive|define
name|TIOCNXCL
value|_IO(t, 14)
end_define

begin_comment
comment|/* reset exclusive use of tty */
end_comment

begin_define
define|#
directive|define
name|TIOCFLUSH
value|_IOW(t, 16, int)
end_define

begin_comment
comment|/* flush buffers */
end_comment

begin_define
define|#
directive|define
name|TIOCSETC
value|_IOW(t,17,struct tchars)
end_define

begin_comment
comment|/* set special characters */
end_comment

begin_define
define|#
directive|define
name|TIOCGETC
value|_IOR(t,18,struct tchars)
end_define

begin_comment
comment|/* get special characters */
end_comment

begin_comment
comment|/* locals, from 127 down */
end_comment

begin_define
define|#
directive|define
name|TIOCLBIS
value|_IOW(t, 127, int)
end_define

begin_comment
comment|/* bis local mode bits */
end_comment

begin_define
define|#
directive|define
name|TIOCLBIC
value|_IOW(t, 126, int)
end_define

begin_comment
comment|/* bic local mode bits */
end_comment

begin_define
define|#
directive|define
name|TIOCLSET
value|_IOW(t, 125, int)
end_define

begin_comment
comment|/* set entire local mode word */
end_comment

begin_define
define|#
directive|define
name|TIOCLGET
value|_IOR(t, 124, int)
end_define

begin_comment
comment|/* get local modes */
end_comment

begin_define
define|#
directive|define
name|TIOCSBRK
value|_IO(t, 123)
end_define

begin_comment
comment|/* set break bit */
end_comment

begin_define
define|#
directive|define
name|TIOCCBRK
value|_IO(t, 122)
end_define

begin_comment
comment|/* clear break bit */
end_comment

begin_define
define|#
directive|define
name|TIOCSDTR
value|_IO(t, 121)
end_define

begin_comment
comment|/* set data terminal ready */
end_comment

begin_define
define|#
directive|define
name|TIOCCDTR
value|_IO(t, 120)
end_define

begin_comment
comment|/* clear data terminal ready */
end_comment

begin_define
define|#
directive|define
name|TIOCGPGRP
value|_IOR(t, 119, int)
end_define

begin_comment
comment|/* get pgrp of tty */
end_comment

begin_define
define|#
directive|define
name|TIOCSPGRP
value|_IOW(t, 118, int)
end_define

begin_comment
comment|/* set pgrp of tty */
end_comment

begin_define
define|#
directive|define
name|TIOCSLTC
value|_IOW(t,117,struct ltchars)
end_define

begin_comment
comment|/* set local special chars */
end_comment

begin_define
define|#
directive|define
name|TIOCGLTC
value|_IOR(t,116,struct ltchars)
end_define

begin_comment
comment|/* get local special chars */
end_comment

begin_define
define|#
directive|define
name|TIOCNOTTY
value|_IO(t, 113)
end_define

begin_comment
comment|/* void tty association */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT
value|_IOW(t, 112, int)
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
value|_IO(t, 111)
end_define

begin_comment
comment|/* stop output, like ^S */
end_comment

begin_define
define|#
directive|define
name|TIOCSTART
value|_IO(t, 110)
end_define

begin_comment
comment|/* start output, like ^Q */
end_comment

begin_define
define|#
directive|define
name|TIOCMSET
value|_IOW(t, 109, int)
end_define

begin_comment
comment|/* set all modem bits */
end_comment

begin_define
define|#
directive|define
name|TIOCMBIS
value|_IOW(t, 108, int)
end_define

begin_comment
comment|/* bis modem bits */
end_comment

begin_define
define|#
directive|define
name|TIOCMBIC
value|_IOW(t, 107, int)
end_define

begin_comment
comment|/* bic modem bits */
end_comment

begin_define
define|#
directive|define
name|TIOCMGET
value|_IOR(t, 106, int)
end_define

begin_comment
comment|/* get all modem bits */
end_comment

begin_define
define|#
directive|define
name|TIOCREMOTE
value|_IO(t, 105)
end_define

begin_comment
comment|/* remote input editing */
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
comment|/* hitachi tablet discipline */
end_comment

begin_define
define|#
directive|define
name|NTABLDISC
value|4
end_define

begin_comment
comment|/* gtco tablet discipline */
end_comment

begin_define
define|#
directive|define
name|FIOCLEX
value|_IO(f, 1)
end_define

begin_comment
comment|/* set exclusive use on fd */
end_comment

begin_define
define|#
directive|define
name|FIONCLEX
value|_IO(f, 2)
end_define

begin_comment
comment|/* remove exclusive use */
end_comment

begin_comment
comment|/* another local */
end_comment

begin_define
define|#
directive|define
name|FIONREAD
value|_IOR(f, 127, int)
end_define

begin_comment
comment|/* get # bytes to read */
end_comment

begin_define
define|#
directive|define
name|FIONBIO
value|_IOW(f, 126, int)
end_define

begin_comment
comment|/* set/clear non-blocking i/o */
end_comment

begin_define
define|#
directive|define
name|FIOASYNC
value|_IOW(f, 125, int)
end_define

begin_comment
comment|/* set/clear async i/o */
end_comment

begin_comment
comment|/* socket i/o controls */
end_comment

begin_define
define|#
directive|define
name|SIOCDONE
value|_IOW(s, 0, int)
end_define

begin_comment
comment|/* shutdown read/write */
end_comment

begin_define
define|#
directive|define
name|SIOCSKEEP
value|_IOW(s, 1, int)
end_define

begin_comment
comment|/* set keep alive */
end_comment

begin_define
define|#
directive|define
name|SIOCGKEEP
value|_IOR(s, 2, int)
end_define

begin_comment
comment|/* inspect keep alive */
end_comment

begin_define
define|#
directive|define
name|SIOCSLINGER
value|_IOW(s, 3, int)
end_define

begin_comment
comment|/* set linger time */
end_comment

begin_define
define|#
directive|define
name|SIOCGLINGER
value|_IOR(s, 4, int)
end_define

begin_comment
comment|/* get linger time */
end_comment

begin_comment
comment|/* these are really variable length */
end_comment

begin_define
define|#
directive|define
name|SIOCSENDOOB
value|_IOW(s, 5, char)
end_define

begin_comment
comment|/* send out of band */
end_comment

begin_define
define|#
directive|define
name|SIOCRCVOOB
value|_IOR(s, 6, char)
end_define

begin_comment
comment|/* get out of band */
end_comment

begin_define
define|#
directive|define
name|SIOCATMARK
value|_IOR(s, 7, int)
end_define

begin_comment
comment|/* at out of band mark? */
end_comment

begin_define
define|#
directive|define
name|SIOCSPGRP
value|_IOW(s, 8, int)
end_define

begin_comment
comment|/* set process group */
end_comment

begin_define
define|#
directive|define
name|SIOCGPGRP
value|_IOR(s, 9, int)
end_define

begin_comment
comment|/* get process group */
end_comment

begin_define
define|#
directive|define
name|SIOCADDRT
value|_IOW(s,10, struct rtentry)
end_define

begin_comment
comment|/* add route */
end_comment

begin_define
define|#
directive|define
name|SIOCDELRT
value|_IOW(s,11, struct rtentry)
end_define

begin_comment
comment|/* delete route */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

