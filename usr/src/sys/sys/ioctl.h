begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c)  *	1982, 1986, 1990, 1993  The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ioctl.h	8.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_IOCTL_H_
end_define

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

begin_comment
comment|/*  * Ioctl's have the command encoded in the lower word, and the size of  * any in or out parameters in the upper word.  The high 3 bits of the  * upper word are used to encode the in/out status of the parameter.  */
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
name|IOCBASECMD
parameter_list|(
name|x
parameter_list|)
value|((x)& ~IOCPARM_MASK)
end_define

begin_define
define|#
directive|define
name|IOCGROUP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xff)
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
value|(IOC_IN|IOC_OUT|IOC_VOID)
end_define

begin_define
define|#
directive|define
name|_IOC
parameter_list|(
name|inout
parameter_list|,
name|group
parameter_list|,
name|num
parameter_list|,
name|len
parameter_list|)
define|\
value|(inout | ((len& IOCPARM_MASK)<< 16) | ((group)<< 8) | (num))
end_define

begin_define
define|#
directive|define
name|_IO
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|)
value|_IOC(IOC_VOID,	(g), (n), 0)
end_define

begin_define
define|#
directive|define
name|_IOR
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|_IOC(IOC_OUT,	(g), (n), sizeof(t))
end_define

begin_define
define|#
directive|define
name|_IOW
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|_IOC(IOC_IN,	(g), (n), sizeof(t))
end_define

begin_comment
comment|/* this should be _IORW, but stdio got there first */
end_comment

begin_define
define|#
directive|define
name|_IOWR
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|_IOC(IOC_INOUT,	(g), (n), sizeof(t))
end_define

begin_define
define|#
directive|define
name|_IOWX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|s
parameter_list|)
value|(IOC_IN|(((s)&IOCPARM_MASK)<<16)|(x<<8)|(y))
end_define

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
name|TIOCPKT_TIOC
value|0x40
end_define

begin_comment
comment|/* transparent ioctl packet */
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
name|TIOCUCNTL
value|_IOW('t', 102, int)
end_define

begin_comment
comment|/* pty: set/clr usr cntl mode */
end_comment

begin_define
define|#
directive|define
name|TIOCTIOC
value|_IOW('t', 101, int)
end_define

begin_comment
comment|/* pty: set/clr transparent */
end_comment

begin_define
define|#
directive|define
name|TIOCBLK
value|_IOW('t', 100, int)
end_define

begin_comment
comment|/* pty: block slave writes */
end_comment

begin_define
define|#
directive|define
name|TIOCIOANS
parameter_list|(
name|s
parameter_list|)
value|_IOWX('t', 99, (s))
end_define

begin_comment
comment|/* pty: reply to user ioctl */
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
name|TTYDISC
value|0
end_define

begin_comment
comment|/* termios tty line discipline */
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
value|_IOW('r', 10, struct ortentry)
end_define

begin_comment
comment|/* add route */
end_comment

begin_define
define|#
directive|define
name|SIOCDELRT
value|_IOW('r', 11, struct ortentry)
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
name|OSIOCGIFADDR
value|_IOWR('i',13, struct ifreq)
end_define

begin_comment
comment|/* get ifnet address */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFADDR
value|_IOWR('i',33, struct ifreq)
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
name|OSIOCGIFDSTADDR
value|_IOWR('i',15, struct ifreq)
end_define

begin_comment
comment|/* get p-p address */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFDSTADDR
value|_IOWR('i',34, struct ifreq)
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
name|OSIOCGIFBRDADDR
value|_IOWR('i',18, struct ifreq)
end_define

begin_comment
comment|/* get broadcast addr */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFBRDADDR
value|_IOWR('i',35, struct ifreq)
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
name|OSIOCGIFCONF
value|_IOWR('i',20, struct ifconf)
end_define

begin_comment
comment|/* get ifnet list */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFCONF
value|_IOWR('i',36, struct ifconf)
end_define

begin_comment
comment|/* get ifnet list */
end_comment

begin_define
define|#
directive|define
name|OSIOCGIFNETMASK
value|_IOWR('i',21, struct ifreq)
end_define

begin_comment
comment|/* get net addr mask */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFNETMASK
value|_IOWR('i',37, struct ifreq)
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
name|SIOCDIFADDR
value|_IOW('i',25, struct ifreq)
end_define

begin_comment
comment|/* delete IF addr */
end_comment

begin_define
define|#
directive|define
name|SIOCAIFADDR
value|_IOW('i',26, struct ifaliasreq)
end_define

begin_comment
comment|/* add/chg IF alias */
end_comment

begin_define
define|#
directive|define
name|SIOCADDMULTI
value|_IOW('i', 49, struct ifreq)
end_define

begin_comment
comment|/* add m'cast addr */
end_comment

begin_define
define|#
directive|define
name|SIOCDELMULTI
value|_IOW('i', 50, struct ifreq)
end_define

begin_comment
comment|/* del m'cast addr */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|ioctl
name|__P
argument_list|(
operator|(
name|int
operator|,
name|unsigned
name|long
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_IOCTL_H_ */
end_comment

begin_comment
comment|/* Keep outside _SYS_IOCTL_H_  * Compatability with old terminal driver  *  * Source level -> #define USE_OLD_TTY  * Kernel level -> options COMPAT_43 or COMPAT_SUNOS  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_OLD_TTY
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_43
argument_list|)
operator|||
name|defined
argument_list|(
name|COMPAT_SUNOS
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"ioctl_compat.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/ioctl_compat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

