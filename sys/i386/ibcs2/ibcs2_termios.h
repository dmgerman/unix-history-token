begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ibcs2_termios.h,v 1.3 1994/10/26 02:53:07 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994 Scott Bartram  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Scott Bartram.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBCS2_TERMIOS_H
end_ifndef

begin_define
define|#
directive|define
name|_IBCS2_TERMIOS_H
value|1
end_define

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_types.h>
end_include

begin_define
define|#
directive|define
name|IBCS2_NCC
value|8
end_define

begin_define
define|#
directive|define
name|IBCS2_NCCS
value|13
end_define

begin_typedef
typedef|typedef
name|u_short
name|ibcs2_tcflag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
name|ibcs2_cc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|ibcs2_speed_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ibcs2_termio
block|{
name|u_short
name|c_iflag
decl_stmt|;
name|u_short
name|c_oflag
decl_stmt|;
name|u_short
name|c_cflag
decl_stmt|;
name|u_short
name|c_lflag
decl_stmt|;
name|char
name|c_line
decl_stmt|;
name|u_char
name|c_cc
index|[
name|IBCS2_NCC
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ibcs2_termios
block|{
name|ibcs2_tcflag_t
name|c_iflag
decl_stmt|;
name|ibcs2_tcflag_t
name|c_oflag
decl_stmt|;
name|ibcs2_tcflag_t
name|c_cflag
decl_stmt|;
name|ibcs2_tcflag_t
name|c_lflag
decl_stmt|;
name|char
name|c_line
decl_stmt|;
name|ibcs2_cc_t
name|c_cc
index|[
name|IBCS2_NCCS
index|]
decl_stmt|;
name|char
name|c_ispeed
decl_stmt|;
name|char
name|c_ospeed
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IBCS2_VINTR
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_VQUIT
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_VERASE
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_VKILL
value|3
end_define

begin_define
define|#
directive|define
name|IBCS2_VEOF
value|4
end_define

begin_define
define|#
directive|define
name|IBCS2_VEOL
value|5
end_define

begin_define
define|#
directive|define
name|IBCS2_VEOL2
value|6
end_define

begin_define
define|#
directive|define
name|IBCS2_VMIN
value|4
end_define

begin_define
define|#
directive|define
name|IBCS2_VTIME
value|5
end_define

begin_define
define|#
directive|define
name|IBCS2_VSWTCH
value|7
end_define

begin_define
define|#
directive|define
name|IBCS2_VSUSP
value|10
end_define

begin_define
define|#
directive|define
name|IBCS2_VSTART
value|11
end_define

begin_define
define|#
directive|define
name|IBCS2_VSTOP
value|12
end_define

begin_define
define|#
directive|define
name|IBCS2_CNUL
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_CDEL
value|0377
end_define

begin_define
define|#
directive|define
name|IBCS2_CESC
value|'\\'
end_define

begin_define
define|#
directive|define
name|IBCS2_CINTR
value|0177
end_define

begin_define
define|#
directive|define
name|IBCS2_CQUIT
value|034
end_define

begin_define
define|#
directive|define
name|IBCS2_CERASE
value|'#'
end_define

begin_define
define|#
directive|define
name|IBCS2_CKILL
value|'@'
end_define

begin_define
define|#
directive|define
name|IBCS2_CSTART
value|021
end_define

begin_define
define|#
directive|define
name|IBCS2_CSTOP
value|023
end_define

begin_define
define|#
directive|define
name|IBCS2_CSWTCH
value|032
end_define

begin_define
define|#
directive|define
name|IBCS2_CNSWTCH
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_CSUSP
value|032
end_define

begin_define
define|#
directive|define
name|IBCS2_IGNBRK
value|0000001
end_define

begin_define
define|#
directive|define
name|IBCS2_BRKINT
value|0000002
end_define

begin_define
define|#
directive|define
name|IBCS2_IGNPAR
value|0000004
end_define

begin_define
define|#
directive|define
name|IBCS2_PARMRK
value|0000010
end_define

begin_define
define|#
directive|define
name|IBCS2_INPCK
value|0000020
end_define

begin_define
define|#
directive|define
name|IBCS2_ISTRIP
value|0000040
end_define

begin_define
define|#
directive|define
name|IBCS2_INLCR
value|0000100
end_define

begin_define
define|#
directive|define
name|IBCS2_IGNCR
value|0000200
end_define

begin_define
define|#
directive|define
name|IBCS2_ICRNL
value|0000400
end_define

begin_define
define|#
directive|define
name|IBCS2_IUCLC
value|0001000
end_define

begin_define
define|#
directive|define
name|IBCS2_IXON
value|0002000
end_define

begin_define
define|#
directive|define
name|IBCS2_IXANY
value|0004000
end_define

begin_define
define|#
directive|define
name|IBCS2_IXOFF
value|0010000
end_define

begin_define
define|#
directive|define
name|IBCS2_IMAXBEL
value|0020000
end_define

begin_define
define|#
directive|define
name|IBCS2_DOSMODE
value|0100000
end_define

begin_define
define|#
directive|define
name|IBCS2_OPOST
value|0000001
end_define

begin_define
define|#
directive|define
name|IBCS2_OLCUC
value|0000002
end_define

begin_define
define|#
directive|define
name|IBCS2_ONLCR
value|0000004
end_define

begin_define
define|#
directive|define
name|IBCS2_OCRNL
value|0000010
end_define

begin_define
define|#
directive|define
name|IBCS2_ONOCR
value|0000020
end_define

begin_define
define|#
directive|define
name|IBCS2_ONLRET
value|0000040
end_define

begin_define
define|#
directive|define
name|IBCS2_OFILL
value|0000100
end_define

begin_define
define|#
directive|define
name|IBCS2_OFDEL
value|0000200
end_define

begin_define
define|#
directive|define
name|IBCS2_NLDLY
value|0000400
end_define

begin_define
define|#
directive|define
name|IBCS2_NL0
value|0000000
end_define

begin_define
define|#
directive|define
name|IBCS2_NL1
value|0000400
end_define

begin_define
define|#
directive|define
name|IBCS2_CRDLY
value|0003000
end_define

begin_define
define|#
directive|define
name|IBCS2_CR0
value|0000000
end_define

begin_define
define|#
directive|define
name|IBCS2_CR1
value|0001000
end_define

begin_define
define|#
directive|define
name|IBCS2_CR2
value|0002000
end_define

begin_define
define|#
directive|define
name|IBCS2_CR3
value|0003000
end_define

begin_define
define|#
directive|define
name|IBCS2_TABDLY
value|0014000
end_define

begin_define
define|#
directive|define
name|IBCS2_TAB0
value|0000000
end_define

begin_define
define|#
directive|define
name|IBCS2_TAB1
value|0004000
end_define

begin_define
define|#
directive|define
name|IBCS2_TAB2
value|0010000
end_define

begin_define
define|#
directive|define
name|IBCS2_TAB3
value|0014000
end_define

begin_define
define|#
directive|define
name|IBCS2_BSDLY
value|0020000
end_define

begin_define
define|#
directive|define
name|IBCS2_BS0
value|0000000
end_define

begin_define
define|#
directive|define
name|IBCS2_BS1
value|0020000
end_define

begin_define
define|#
directive|define
name|IBCS2_VTDLY
value|0040000
end_define

begin_define
define|#
directive|define
name|IBCS2_VT0
value|0000000
end_define

begin_define
define|#
directive|define
name|IBCS2_VT1
value|0040000
end_define

begin_define
define|#
directive|define
name|IBCS2_FFDLY
value|0100000
end_define

begin_define
define|#
directive|define
name|IBCS2_FF0
value|0000000
end_define

begin_define
define|#
directive|define
name|IBCS2_FF1
value|0100000
end_define

begin_define
define|#
directive|define
name|IBCS2_CBAUD
value|0000017
end_define

begin_define
define|#
directive|define
name|IBCS2_CSIZE
value|0000060
end_define

begin_define
define|#
directive|define
name|IBCS2_CS5
value|0000000
end_define

begin_define
define|#
directive|define
name|IBCS2_CS6
value|0000020
end_define

begin_define
define|#
directive|define
name|IBCS2_CS7
value|0000040
end_define

begin_define
define|#
directive|define
name|IBCS2_CS8
value|0000060
end_define

begin_define
define|#
directive|define
name|IBCS2_CSTOPB
value|0000100
end_define

begin_define
define|#
directive|define
name|IBCS2_CREAD
value|0000200
end_define

begin_define
define|#
directive|define
name|IBCS2_PARENB
value|0000400
end_define

begin_define
define|#
directive|define
name|IBCS2_PARODD
value|0001000
end_define

begin_define
define|#
directive|define
name|IBCS2_HUPCL
value|0002000
end_define

begin_define
define|#
directive|define
name|IBCS2_CLOCAL
value|0004000
end_define

begin_define
define|#
directive|define
name|IBCS2_RCV1EN
value|0010000
end_define

begin_define
define|#
directive|define
name|IBCS2_XMT1EN
value|0020000
end_define

begin_define
define|#
directive|define
name|IBCS2_LOBLK
value|0040000
end_define

begin_define
define|#
directive|define
name|IBCS2_XCLUDE
value|0100000
end_define

begin_define
define|#
directive|define
name|IBCS2_ISIG
value|0000001
end_define

begin_define
define|#
directive|define
name|IBCS2_ICANON
value|0000002
end_define

begin_define
define|#
directive|define
name|IBCS2_XCASE
value|0000004
end_define

begin_define
define|#
directive|define
name|IBCS2_ECHO
value|0000010
end_define

begin_define
define|#
directive|define
name|IBCS2_ECHOE
value|0000020
end_define

begin_define
define|#
directive|define
name|IBCS2_ECHOK
value|0000040
end_define

begin_define
define|#
directive|define
name|IBCS2_ECHONL
value|0000100
end_define

begin_define
define|#
directive|define
name|IBCS2_NOFLSH
value|0000200
end_define

begin_define
define|#
directive|define
name|IBCS2_IEXTEN
value|0000400
end_define

begin_define
define|#
directive|define
name|IBCS2_TOSTOP
value|0001000
end_define

begin_define
define|#
directive|define
name|IBCS2_XIOC
value|(('i'<<24)|('X'<<16))
end_define

begin_define
define|#
directive|define
name|IBCS2_XCGETA
value|(IBCS2_XIOC|1)
end_define

begin_define
define|#
directive|define
name|IBCS2_XCSETA
value|(IBCS2_XIOC|2)
end_define

begin_define
define|#
directive|define
name|IBCS2_XCSETAW
value|(IBCS2_XIOC|3)
end_define

begin_define
define|#
directive|define
name|IBCS2_XCSETAF
value|(IBCS2_XIOC|4)
end_define

begin_define
define|#
directive|define
name|IBCS2_OXIOC
value|('x'<<8)
end_define

begin_define
define|#
directive|define
name|IBCS2_OXCGETA
value|(IBCS2_OXIOC|1)
end_define

begin_define
define|#
directive|define
name|IBCS2_OXCSETA
value|(IBCS2_OXIOC|2)
end_define

begin_define
define|#
directive|define
name|IBCS2_OXCSETAW
value|(IBCS2_OXIOC|3)
end_define

begin_define
define|#
directive|define
name|IBCS2_OXCSETAF
value|(IBCS2_OXIOC|4)
end_define

begin_define
define|#
directive|define
name|IBCS2_TIOC
value|('T'<<8)
end_define

begin_define
define|#
directive|define
name|IBCS2_TCGETA
value|(IBCS2_TIOC|1)
end_define

begin_define
define|#
directive|define
name|IBCS2_TCSETA
value|(IBCS2_TIOC|2)
end_define

begin_define
define|#
directive|define
name|IBCS2_TCSETAW
value|(IBCS2_TIOC|3)
end_define

begin_define
define|#
directive|define
name|IBCS2_TCSETAF
value|(IBCS2_TIOC|4)
end_define

begin_define
define|#
directive|define
name|IBCS2_TCSBRK
value|(IBCS2_TIOC|5)
end_define

begin_define
define|#
directive|define
name|IBCS2_TCXONC
value|(IBCS2_TIOC|6)
end_define

begin_define
define|#
directive|define
name|IBCS2_TCFLSH
value|(IBCS2_TIOC|7)
end_define

begin_define
define|#
directive|define
name|IBCS2_TCGETSC
value|(IBCS2_TIOC|34)
end_define

begin_define
define|#
directive|define
name|IBCS2_TCSETSC
value|(IBCS2_TIOC|35)
end_define

begin_define
define|#
directive|define
name|IBCS2_TIOCSWINSZ
value|(IBCS2_TIOC|103)
end_define

begin_define
define|#
directive|define
name|IBCS2_TIOCGWINSZ
value|(IBCS2_TIOC|104)
end_define

begin_define
define|#
directive|define
name|IBCS2_TIOCSPGRP
value|(IBCS2_TIOC|118)
end_define

begin_define
define|#
directive|define
name|IBCS2_TIOCGPGRP
value|(IBCS2_TIOC|119)
end_define

begin_define
define|#
directive|define
name|IBCS2_TCSANOW
value|IBCS2_XCSETA
end_define

begin_define
define|#
directive|define
name|IBCS2_TCSADRAIN
value|IBCS2_XCSETAW
end_define

begin_define
define|#
directive|define
name|IBCS2_TCSAFLUSH
value|IBCS2_XCSETAF
end_define

begin_define
define|#
directive|define
name|IBCS2_TCSADFLUSH
value|IBCS2_XCSETAF
end_define

begin_define
define|#
directive|define
name|IBCS2_TCIFLUSH
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_TCOFLUSH
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_TCIOFLUSH
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_TCOOFF
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_TCOON
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_TCIOFF
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_TCION
value|3
end_define

begin_define
define|#
directive|define
name|IBCS2_B0
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_B50
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_B75
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_B110
value|3
end_define

begin_define
define|#
directive|define
name|IBCS2_B134
value|4
end_define

begin_define
define|#
directive|define
name|IBCS2_B150
value|5
end_define

begin_define
define|#
directive|define
name|IBCS2_B200
value|6
end_define

begin_define
define|#
directive|define
name|IBCS2_B300
value|7
end_define

begin_define
define|#
directive|define
name|IBCS2_B600
value|8
end_define

begin_define
define|#
directive|define
name|IBCS2_B1200
value|9
end_define

begin_define
define|#
directive|define
name|IBCS2_B1800
value|10
end_define

begin_define
define|#
directive|define
name|IBCS2_B2400
value|11
end_define

begin_define
define|#
directive|define
name|IBCS2_B4800
value|12
end_define

begin_define
define|#
directive|define
name|IBCS2_B9600
value|13
end_define

begin_define
define|#
directive|define
name|IBCS2_B19200
value|14
end_define

begin_define
define|#
directive|define
name|IBCS2_B38400
value|15
end_define

begin_struct
struct|struct
name|ibcs2_winsize
block|{
name|u_short
name|ws_row
decl_stmt|;
name|u_short
name|ws_col
decl_stmt|;
name|u_short
name|ws_xpixel
decl_stmt|;
name|u_short
name|ws_ypixel
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IBCS2_H_ */
end_comment

end_unit

