begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)termios.h	8.3 (Berkeley) 3/28/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TERMIOS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TERMIOS_H_
end_define

begin_comment
comment|/*  * Special Control Characters  *  * Index into c_cc[] character array.  *  *	Name	     Subscript	Enabled by  */
end_comment

begin_define
define|#
directive|define
name|VEOF
value|0
end_define

begin_comment
comment|/* ICANON */
end_comment

begin_define
define|#
directive|define
name|VEOL
value|1
end_define

begin_comment
comment|/* ICANON */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|VEOL2
value|2
end_define

begin_comment
comment|/* ICANON together with IEXTEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VERASE
value|3
end_define

begin_comment
comment|/* ICANON */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|VWERASE
value|4
end_define

begin_comment
comment|/* ICANON together with IEXTEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VKILL
value|5
end_define

begin_comment
comment|/* ICANON */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|VREPRINT
value|6
end_define

begin_comment
comment|/* ICANON together with IEXTEN */
end_comment

begin_define
define|#
directive|define
name|VERASE2
value|7
end_define

begin_comment
comment|/* ICANON */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*			7	   ex-spare 1 */
end_comment

begin_define
define|#
directive|define
name|VINTR
value|8
end_define

begin_comment
comment|/* ISIG */
end_comment

begin_define
define|#
directive|define
name|VQUIT
value|9
end_define

begin_comment
comment|/* ISIG */
end_comment

begin_define
define|#
directive|define
name|VSUSP
value|10
end_define

begin_comment
comment|/* ISIG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|VDSUSP
value|11
end_define

begin_comment
comment|/* ISIG together with IEXTEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VSTART
value|12
end_define

begin_comment
comment|/* IXON, IXOFF */
end_comment

begin_define
define|#
directive|define
name|VSTOP
value|13
end_define

begin_comment
comment|/* IXON, IXOFF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|VLNEXT
value|14
end_define

begin_comment
comment|/* IEXTEN */
end_comment

begin_define
define|#
directive|define
name|VDISCARD
value|15
end_define

begin_comment
comment|/* IEXTEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VMIN
value|16
end_define

begin_comment
comment|/* !ICANON */
end_comment

begin_define
define|#
directive|define
name|VTIME
value|17
end_define

begin_comment
comment|/* !ICANON */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|VSTATUS
value|18
end_define

begin_comment
comment|/* ICANON together with IEXTEN */
end_comment

begin_comment
comment|/*			19	   spare 2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NCCS
value|20
end_define

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|0xff
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|CCEQ
parameter_list|(
name|val
parameter_list|,
name|c
parameter_list|)
value|((c) == (val) ? (val) != _POSIX_VDISABLE : 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Input flags - software input processing  */
end_comment

begin_define
define|#
directive|define
name|IGNBRK
value|0x00000001
end_define

begin_comment
comment|/* ignore BREAK condition */
end_comment

begin_define
define|#
directive|define
name|BRKINT
value|0x00000002
end_define

begin_comment
comment|/* map BREAK to SIGINTR */
end_comment

begin_define
define|#
directive|define
name|IGNPAR
value|0x00000004
end_define

begin_comment
comment|/* ignore (discard) parity errors */
end_comment

begin_define
define|#
directive|define
name|PARMRK
value|0x00000008
end_define

begin_comment
comment|/* mark parity and framing errors */
end_comment

begin_define
define|#
directive|define
name|INPCK
value|0x00000010
end_define

begin_comment
comment|/* enable checking of parity errors */
end_comment

begin_define
define|#
directive|define
name|ISTRIP
value|0x00000020
end_define

begin_comment
comment|/* strip 8th bit off chars */
end_comment

begin_define
define|#
directive|define
name|INLCR
value|0x00000040
end_define

begin_comment
comment|/* map NL into CR */
end_comment

begin_define
define|#
directive|define
name|IGNCR
value|0x00000080
end_define

begin_comment
comment|/* ignore CR */
end_comment

begin_define
define|#
directive|define
name|ICRNL
value|0x00000100
end_define

begin_comment
comment|/* map CR to NL (ala CRMOD) */
end_comment

begin_define
define|#
directive|define
name|IXON
value|0x00000200
end_define

begin_comment
comment|/* enable output flow control */
end_comment

begin_define
define|#
directive|define
name|IXOFF
value|0x00000400
end_define

begin_comment
comment|/* enable input flow control */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|IXANY
value|0x00000800
end_define

begin_comment
comment|/* any char will restart after stop */
end_comment

begin_define
define|#
directive|define
name|IMAXBEL
value|0x00002000
end_define

begin_comment
comment|/* ring bell on input queue full */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_POSIX_SOURCE */
end_comment

begin_comment
comment|/*  * Output flags - software output processing  */
end_comment

begin_define
define|#
directive|define
name|OPOST
value|0x00000001
end_define

begin_comment
comment|/* enable following output processing */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|ONLCR
value|0x00000002
end_define

begin_comment
comment|/* map NL to CR-NL (ala CRMOD) */
end_comment

begin_define
define|#
directive|define
name|OXTABS
value|0x00000004
end_define

begin_comment
comment|/* expand tabs to spaces */
end_comment

begin_define
define|#
directive|define
name|ONOEOT
value|0x00000008
end_define

begin_comment
comment|/* discard EOT's (^D) on output) */
end_comment

begin_define
define|#
directive|define
name|OCRNL
value|0x00000010
end_define

begin_comment
comment|/* map CR to NL on output */
end_comment

begin_define
define|#
directive|define
name|ONOCR
value|0x00000020
end_define

begin_comment
comment|/* no CR output at column 0 */
end_comment

begin_define
define|#
directive|define
name|ONLRET
value|0x00000040
end_define

begin_comment
comment|/* NL performs CR function */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_POSIX_SOURCE */
end_comment

begin_comment
comment|/*  * Control flags - hardware control of terminal  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|CIGNORE
value|0x00000001
end_define

begin_comment
comment|/* ignore control flags */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CSIZE
value|0x00000300
end_define

begin_comment
comment|/* character size mask */
end_comment

begin_define
define|#
directive|define
name|CS5
value|0x00000000
end_define

begin_comment
comment|/* 5 bits (pseudo) */
end_comment

begin_define
define|#
directive|define
name|CS6
value|0x00000100
end_define

begin_comment
comment|/* 6 bits */
end_comment

begin_define
define|#
directive|define
name|CS7
value|0x00000200
end_define

begin_comment
comment|/* 7 bits */
end_comment

begin_define
define|#
directive|define
name|CS8
value|0x00000300
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|CSTOPB
value|0x00000400
end_define

begin_comment
comment|/* send 2 stop bits */
end_comment

begin_define
define|#
directive|define
name|CREAD
value|0x00000800
end_define

begin_comment
comment|/* enable receiver */
end_comment

begin_define
define|#
directive|define
name|PARENB
value|0x00001000
end_define

begin_comment
comment|/* parity enable */
end_comment

begin_define
define|#
directive|define
name|PARODD
value|0x00002000
end_define

begin_comment
comment|/* odd parity, else even */
end_comment

begin_define
define|#
directive|define
name|HUPCL
value|0x00004000
end_define

begin_comment
comment|/* hang up on last close */
end_comment

begin_define
define|#
directive|define
name|CLOCAL
value|0x00008000
end_define

begin_comment
comment|/* ignore modem status lines */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|CCTS_OFLOW
value|0x00010000
end_define

begin_comment
comment|/* CTS flow control of output */
end_comment

begin_define
define|#
directive|define
name|CRTSCTS
value|(CCTS_OFLOW | CRTS_IFLOW)
end_define

begin_define
define|#
directive|define
name|CRTS_IFLOW
value|0x00020000
end_define

begin_comment
comment|/* RTS flow control of input */
end_comment

begin_define
define|#
directive|define
name|CDTR_IFLOW
value|0x00040000
end_define

begin_comment
comment|/* DTR flow control of input */
end_comment

begin_define
define|#
directive|define
name|CDSR_OFLOW
value|0x00080000
end_define

begin_comment
comment|/* DSR flow control of output */
end_comment

begin_define
define|#
directive|define
name|CCAR_OFLOW
value|0x00100000
end_define

begin_comment
comment|/* DCD flow control of output */
end_comment

begin_define
define|#
directive|define
name|MDMBUF
value|0x00100000
end_define

begin_comment
comment|/* old name for CCAR_OFLOW */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * "Local" flags - dumping ground for other state  *  * Warning: some flags in this structure begin with  * the letter "I" and look like they belong in the  * input flag.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|ECHOKE
value|0x00000001
end_define

begin_comment
comment|/* visual erase for line kill */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_POSIX_SOURCE */
end_comment

begin_define
define|#
directive|define
name|ECHOE
value|0x00000002
end_define

begin_comment
comment|/* visually erase chars */
end_comment

begin_define
define|#
directive|define
name|ECHOK
value|0x00000004
end_define

begin_comment
comment|/* echo NL after line kill */
end_comment

begin_define
define|#
directive|define
name|ECHO
value|0x00000008
end_define

begin_comment
comment|/* enable echoing */
end_comment

begin_define
define|#
directive|define
name|ECHONL
value|0x00000010
end_define

begin_comment
comment|/* echo NL even if ECHO is off */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|ECHOPRT
value|0x00000020
end_define

begin_comment
comment|/* visual erase mode for hardcopy */
end_comment

begin_define
define|#
directive|define
name|ECHOCTL
value|0x00000040
end_define

begin_comment
comment|/* echo control chars as ^(Char) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_POSIX_SOURCE */
end_comment

begin_define
define|#
directive|define
name|ISIG
value|0x00000080
end_define

begin_comment
comment|/* enable signals INTR, QUIT, [D]SUSP */
end_comment

begin_define
define|#
directive|define
name|ICANON
value|0x00000100
end_define

begin_comment
comment|/* canonicalize input lines */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|ALTWERASE
value|0x00000200
end_define

begin_comment
comment|/* use alternate WERASE algorithm */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_POSIX_SOURCE */
end_comment

begin_define
define|#
directive|define
name|IEXTEN
value|0x00000400
end_define

begin_comment
comment|/* enable DISCARD and LNEXT */
end_comment

begin_define
define|#
directive|define
name|EXTPROC
value|0x00000800
end_define

begin_comment
comment|/* external processing */
end_comment

begin_define
define|#
directive|define
name|TOSTOP
value|0x00400000
end_define

begin_comment
comment|/* stop background jobs from output */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|FLUSHO
value|0x00800000
end_define

begin_comment
comment|/* output being flushed (state) */
end_comment

begin_define
define|#
directive|define
name|NOKERNINFO
value|0x02000000
end_define

begin_comment
comment|/* no kernel output from VSTATUS */
end_comment

begin_define
define|#
directive|define
name|PENDIN
value|0x20000000
end_define

begin_comment
comment|/* XXX retype pending input (state) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_POSIX_SOURCE */
end_comment

begin_define
define|#
directive|define
name|NOFLSH
value|0x80000000
end_define

begin_comment
comment|/* don't flush after interrupt */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|tcflag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|cc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|speed_t
typedef|;
end_typedef

begin_struct
struct|struct
name|termios
block|{
name|tcflag_t
name|c_iflag
decl_stmt|;
comment|/* input flags */
name|tcflag_t
name|c_oflag
decl_stmt|;
comment|/* output flags */
name|tcflag_t
name|c_cflag
decl_stmt|;
comment|/* control flags */
name|tcflag_t
name|c_lflag
decl_stmt|;
comment|/* local flags */
name|cc_t
name|c_cc
index|[
name|NCCS
index|]
decl_stmt|;
comment|/* control chars */
name|speed_t
name|c_ispeed
decl_stmt|;
comment|/* input speed */
name|speed_t
name|c_ospeed
decl_stmt|;
comment|/* output speed */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Commands passed to tcsetattr() for setting the termios structure.  */
end_comment

begin_define
define|#
directive|define
name|TCSANOW
value|0
end_define

begin_comment
comment|/* make change immediate */
end_comment

begin_define
define|#
directive|define
name|TCSADRAIN
value|1
end_define

begin_comment
comment|/* drain output, then change */
end_comment

begin_define
define|#
directive|define
name|TCSAFLUSH
value|2
end_define

begin_comment
comment|/* drain output, flush input */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|TCSASOFT
value|0x10
end_define

begin_comment
comment|/* flag - don't alter h.w. state */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Standard speeds  */
end_comment

begin_define
define|#
directive|define
name|B0
value|0
end_define

begin_define
define|#
directive|define
name|B50
value|50
end_define

begin_define
define|#
directive|define
name|B75
value|75
end_define

begin_define
define|#
directive|define
name|B110
value|110
end_define

begin_define
define|#
directive|define
name|B134
value|134
end_define

begin_define
define|#
directive|define
name|B150
value|150
end_define

begin_define
define|#
directive|define
name|B200
value|200
end_define

begin_define
define|#
directive|define
name|B300
value|300
end_define

begin_define
define|#
directive|define
name|B600
value|600
end_define

begin_define
define|#
directive|define
name|B1200
value|1200
end_define

begin_define
define|#
directive|define
name|B1800
value|1800
end_define

begin_define
define|#
directive|define
name|B2400
value|2400
end_define

begin_define
define|#
directive|define
name|B4800
value|4800
end_define

begin_define
define|#
directive|define
name|B9600
value|9600
end_define

begin_define
define|#
directive|define
name|B19200
value|19200
end_define

begin_define
define|#
directive|define
name|B38400
value|38400
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|B7200
value|7200
end_define

begin_define
define|#
directive|define
name|B14400
value|14400
end_define

begin_define
define|#
directive|define
name|B28800
value|28800
end_define

begin_define
define|#
directive|define
name|B57600
value|57600
end_define

begin_define
define|#
directive|define
name|B76800
value|76800
end_define

begin_define
define|#
directive|define
name|B115200
value|115200
end_define

begin_define
define|#
directive|define
name|B230400
value|230400
end_define

begin_define
define|#
directive|define
name|B460800
value|460800
end_define

begin_define
define|#
directive|define
name|B921600
value|921600
end_define

begin_define
define|#
directive|define
name|EXTA
value|19200
end_define

begin_define
define|#
directive|define
name|EXTB
value|38400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_SOURCE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|TCIFLUSH
value|1
end_define

begin_define
define|#
directive|define
name|TCOFLUSH
value|2
end_define

begin_define
define|#
directive|define
name|TCIOFLUSH
value|3
end_define

begin_define
define|#
directive|define
name|TCOOFF
value|1
end_define

begin_define
define|#
directive|define
name|TCOON
value|2
end_define

begin_define
define|#
directive|define
name|TCIOFF
value|3
end_define

begin_define
define|#
directive|define
name|TCION
value|4
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|speed_t
name|cfgetispeed
parameter_list|(
specifier|const
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|speed_t
name|cfgetospeed
parameter_list|(
specifier|const
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfsetispeed
parameter_list|(
name|struct
name|termios
modifier|*
parameter_list|,
name|speed_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfsetospeed
parameter_list|(
name|struct
name|termios
modifier|*
parameter_list|,
name|speed_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcgetattr
parameter_list|(
name|int
parameter_list|,
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcsetattr
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcdrain
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcflow
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcflush
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcsendbreak
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_function_decl
name|void
name|cfmakeraw
parameter_list|(
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfsetspeed
parameter_list|(
name|struct
name|termios
modifier|*
parameter_list|,
name|speed_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_SOURCE */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_comment
comment|/*  * Include tty ioctl's that aren't just for backwards compatibility  * with the old tty driver.  These ioctl definitions were previously  * in<sys/ioctl.h>.  */
end_comment

begin_include
include|#
directive|include
file|<sys/ttycom.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * END OF PROTECTED INCLUDE.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TERMIOS_H_ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_include
include|#
directive|include
file|<sys/ttydefaults.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

