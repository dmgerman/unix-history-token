begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_TERMIOS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_TERMIOS_H_
end_define

begin_define
define|#
directive|define
name|SVR4_POSIX_VDISABLE
value|0
end_define

begin_define
define|#
directive|define
name|SVR4_NCC
value|8
end_define

begin_define
define|#
directive|define
name|SVR4_NCCS
value|19
end_define

begin_typedef
typedef|typedef
name|u_long
name|svr4_tcflag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
name|svr4_cc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|svr4_speed_t
typedef|;
end_typedef

begin_struct
struct|struct
name|svr4_termios
block|{
name|svr4_tcflag_t
name|c_iflag
decl_stmt|;
name|svr4_tcflag_t
name|c_oflag
decl_stmt|;
name|svr4_tcflag_t
name|c_cflag
decl_stmt|;
name|svr4_tcflag_t
name|c_lflag
decl_stmt|;
name|svr4_cc_t
name|c_cc
index|[
name|SVR4_NCCS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_termio
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
name|SVR4_NCC
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* control characters */
end_comment

begin_define
define|#
directive|define
name|SVR4_VINTR
value|0
end_define

begin_define
define|#
directive|define
name|SVR4_VQUIT
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_VERASE
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_VKILL
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_VEOF
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_VEOL
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_VEOL2
value|6
end_define

begin_define
define|#
directive|define
name|SVR4_VMIN
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_VTIME
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_VSWTCH
value|7
end_define

begin_define
define|#
directive|define
name|SVR4_VSTART
value|8
end_define

begin_define
define|#
directive|define
name|SVR4_VSTOP
value|9
end_define

begin_define
define|#
directive|define
name|SVR4_VSUSP
value|10
end_define

begin_define
define|#
directive|define
name|SVR4_VDSUSP
value|11
end_define

begin_define
define|#
directive|define
name|SVR4_VREPRINT
value|12
end_define

begin_define
define|#
directive|define
name|SVR4_VDISCARD
value|13
end_define

begin_define
define|#
directive|define
name|SVR4_VWERASE
value|14
end_define

begin_define
define|#
directive|define
name|SVR4_VLNEXT
value|15
end_define

begin_comment
comment|/* Input modes */
end_comment

begin_define
define|#
directive|define
name|SVR4_IGNBRK
value|00000001
end_define

begin_define
define|#
directive|define
name|SVR4_BRKINT
value|00000002
end_define

begin_define
define|#
directive|define
name|SVR4_IGNPAR
value|00000004
end_define

begin_define
define|#
directive|define
name|SVR4_PARMRK
value|00000010
end_define

begin_define
define|#
directive|define
name|SVR4_INPCK
value|00000020
end_define

begin_define
define|#
directive|define
name|SVR4_ISTRIP
value|00000040
end_define

begin_define
define|#
directive|define
name|SVR4_INLCR
value|00000100
end_define

begin_define
define|#
directive|define
name|SVR4_IGNCR
value|00000200
end_define

begin_define
define|#
directive|define
name|SVR4_ICRNL
value|00000400
end_define

begin_define
define|#
directive|define
name|SVR4_IUCLC
value|00001000
end_define

begin_define
define|#
directive|define
name|SVR4_IXON
value|00002000
end_define

begin_define
define|#
directive|define
name|SVR4_IXANY
value|00004000
end_define

begin_define
define|#
directive|define
name|SVR4_IXOFF
value|00010000
end_define

begin_define
define|#
directive|define
name|SVR4_IMAXBEL
value|00020000
end_define

begin_define
define|#
directive|define
name|SVR4_DOSMODE
value|00100000
end_define

begin_comment
comment|/* Output modes */
end_comment

begin_define
define|#
directive|define
name|SVR4_OPOST
value|00000001
end_define

begin_define
define|#
directive|define
name|SVR4_OLCUC
value|00000002
end_define

begin_define
define|#
directive|define
name|SVR4_ONLCR
value|00000004
end_define

begin_define
define|#
directive|define
name|SVR4_OCRNL
value|00000010
end_define

begin_define
define|#
directive|define
name|SVR4_ONOCR
value|00000020
end_define

begin_define
define|#
directive|define
name|SVR4_ONLRET
value|00000040
end_define

begin_define
define|#
directive|define
name|SVR4_OFILL
value|00000100
end_define

begin_define
define|#
directive|define
name|SVR4_OFDEL
value|00000200
end_define

begin_define
define|#
directive|define
name|SVR4_NLDLY
value|00000400
end_define

begin_define
define|#
directive|define
name|SVR4_NL0
value|00000000
end_define

begin_define
define|#
directive|define
name|SVR4_NL1
value|00000400
end_define

begin_define
define|#
directive|define
name|SVR4_CRDLY
value|00003000
end_define

begin_define
define|#
directive|define
name|SVR4_CR0
value|00000000
end_define

begin_define
define|#
directive|define
name|SVR4_CR1
value|00001000
end_define

begin_define
define|#
directive|define
name|SVR4_CR2
value|00002000
end_define

begin_define
define|#
directive|define
name|SVR4_CR3
value|00003000
end_define

begin_define
define|#
directive|define
name|SVR4_TABDLY
value|00014000
end_define

begin_define
define|#
directive|define
name|SVR4_TAB0
value|00000000
end_define

begin_define
define|#
directive|define
name|SVR4_TAB1
value|00004000
end_define

begin_define
define|#
directive|define
name|SVR4_TAB2
value|00010000
end_define

begin_define
define|#
directive|define
name|SVR4_TAB3
value|00014000
end_define

begin_define
define|#
directive|define
name|SVR4_XTABS
value|00014000
end_define

begin_define
define|#
directive|define
name|SVR4_BSDLY
value|00020000
end_define

begin_define
define|#
directive|define
name|SVR4_BS0
value|00000000
end_define

begin_define
define|#
directive|define
name|SVR4_BS1
value|00020000
end_define

begin_define
define|#
directive|define
name|SVR4_VTDLY
value|00040000
end_define

begin_define
define|#
directive|define
name|SVR4_VT0
value|00000000
end_define

begin_define
define|#
directive|define
name|SVR4_VT1
value|00040000
end_define

begin_define
define|#
directive|define
name|SVR4_FFDLY
value|00100000
end_define

begin_define
define|#
directive|define
name|SVR4_FF0
value|00000000
end_define

begin_define
define|#
directive|define
name|SVR4_FF1
value|00100000
end_define

begin_define
define|#
directive|define
name|SVR4_PAGEOUT
value|00200000
end_define

begin_define
define|#
directive|define
name|SVR4_WRAP
value|00400000
end_define

begin_comment
comment|/* Control modes */
end_comment

begin_define
define|#
directive|define
name|SVR4_CBAUD
value|00000017
end_define

begin_define
define|#
directive|define
name|SVR4_CSIZE
value|00000060
end_define

begin_define
define|#
directive|define
name|SVR4_CS5
value|00000000
end_define

begin_define
define|#
directive|define
name|SVR4_CS6
value|00000200
end_define

begin_define
define|#
directive|define
name|SVR4_CS7
value|00000040
end_define

begin_define
define|#
directive|define
name|SVR4_CS8
value|00000006
end_define

begin_define
define|#
directive|define
name|SVR4_CSTOPB
value|00000100
end_define

begin_define
define|#
directive|define
name|SVR4_CREAD
value|00000200
end_define

begin_define
define|#
directive|define
name|SVR4_PARENB
value|00000400
end_define

begin_define
define|#
directive|define
name|SVR4_PARODD
value|00001000
end_define

begin_define
define|#
directive|define
name|SVR4_HUPCL
value|00002000
end_define

begin_define
define|#
directive|define
name|SVR4_CLOCAL
value|00004000
end_define

begin_define
define|#
directive|define
name|SVR4_RCV1EN
value|00010000
end_define

begin_define
define|#
directive|define
name|SVR4_XMT1EN
value|00020000
end_define

begin_define
define|#
directive|define
name|SVR4_LOBLK
value|00040000
end_define

begin_define
define|#
directive|define
name|SVR4_XCLUDE
value|00100000
end_define

begin_define
define|#
directive|define
name|SVR4_CIBAUD
value|03600000
end_define

begin_define
define|#
directive|define
name|SVR4_PAREXT
value|04000000
end_define

begin_comment
comment|/* line discipline modes */
end_comment

begin_define
define|#
directive|define
name|SVR4_ISIG
value|00000001
end_define

begin_define
define|#
directive|define
name|SVR4_ICANON
value|00000002
end_define

begin_define
define|#
directive|define
name|SVR4_XCASE
value|00000004
end_define

begin_define
define|#
directive|define
name|SVR4_ECHO
value|00000010
end_define

begin_define
define|#
directive|define
name|SVR4_ECHOE
value|00000020
end_define

begin_define
define|#
directive|define
name|SVR4_ECHOK
value|00000040
end_define

begin_define
define|#
directive|define
name|SVR4_ECHONL
value|00000100
end_define

begin_define
define|#
directive|define
name|SVR4_NOFLSH
value|00000200
end_define

begin_define
define|#
directive|define
name|SVR4_TOSTOP
value|00000400
end_define

begin_define
define|#
directive|define
name|SVR4_ECHOCTL
value|00001000
end_define

begin_define
define|#
directive|define
name|SVR4_ECHOPRT
value|00002000
end_define

begin_define
define|#
directive|define
name|SVR4_ECHOKE
value|00004000
end_define

begin_define
define|#
directive|define
name|SVR4_DEFECHO
value|00010000
end_define

begin_define
define|#
directive|define
name|SVR4_FLUSHO
value|00020000
end_define

begin_define
define|#
directive|define
name|SVR4_PENDIN
value|00040000
end_define

begin_define
define|#
directive|define
name|SVR4_IEXTEN
value|00100000
end_define

begin_define
define|#
directive|define
name|SVR4_TIOC
value|('T'<< 8)
end_define

begin_define
define|#
directive|define
name|SVR4_TCGETA
value|(SVR4_TIOC| 1)
end_define

begin_define
define|#
directive|define
name|SVR4_TCSETA
value|(SVR4_TIOC| 2)
end_define

begin_define
define|#
directive|define
name|SVR4_TCSETAW
value|(SVR4_TIOC| 3)
end_define

begin_define
define|#
directive|define
name|SVR4_TCSETAF
value|(SVR4_TIOC| 4)
end_define

begin_define
define|#
directive|define
name|SVR4_TCSBRK
value|(SVR4_TIOC| 5)
end_define

begin_define
define|#
directive|define
name|SVR4_TCXONC
value|(SVR4_TIOC| 6)
end_define

begin_define
define|#
directive|define
name|SVR4_TCFLSH
value|(SVR4_TIOC| 7)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCKBON
value|(SVR4_TIOC| 8)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCKBOF
value|(SVR4_TIOC| 9)
end_define

begin_define
define|#
directive|define
name|SVR4_KBENABLED
value|(SVR4_TIOC|10)
end_define

begin_define
define|#
directive|define
name|SVR4_TCGETS
value|(SVR4_TIOC|13)
end_define

begin_define
define|#
directive|define
name|SVR4_TCSETS
value|(SVR4_TIOC|14)
end_define

begin_define
define|#
directive|define
name|SVR4_TCSETSW
value|(SVR4_TIOC|15)
end_define

begin_define
define|#
directive|define
name|SVR4_TCSETSF
value|(SVR4_TIOC|16)
end_define

begin_define
define|#
directive|define
name|SVR4_TCDSET
value|(SVR4_TIOC|32)
end_define

begin_define
define|#
directive|define
name|SVR4_RTS_TOG
value|(SVR4_TIOC|33)
end_define

begin_define
define|#
directive|define
name|SVR4_TCGETSC
value|(SVR4_TIOC|34)
end_define

begin_define
define|#
directive|define
name|SVR4_TCSETSC
value|(SVR4_TIOC|35)
end_define

begin_define
define|#
directive|define
name|SVR4_TCMOUSE
value|(SVR4_TIOC|36)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCGWINSZ
value|(SVR4_TIOC|104)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCSWINSZ
value|(SVR4_TIOC|103)
end_define

begin_struct
struct|struct
name|svr4_winsize
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

begin_define
define|#
directive|define
name|SVR4_B0
value|0
end_define

begin_define
define|#
directive|define
name|SVR4_B50
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_B75
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_B110
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_B134
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_B150
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_B200
value|6
end_define

begin_define
define|#
directive|define
name|SVR4_B300
value|7
end_define

begin_define
define|#
directive|define
name|SVR4_B600
value|8
end_define

begin_define
define|#
directive|define
name|SVR4_B1200
value|9
end_define

begin_define
define|#
directive|define
name|SVR4_B1800
value|10
end_define

begin_define
define|#
directive|define
name|SVR4_B2400
value|11
end_define

begin_define
define|#
directive|define
name|SVR4_B4800
value|12
end_define

begin_define
define|#
directive|define
name|SVR4_B9600
value|13
end_define

begin_define
define|#
directive|define
name|SVR4_B19200
value|14
end_define

begin_define
define|#
directive|define
name|SVR4_B38400
value|15
end_define

begin_define
define|#
directive|define
name|SVR4_B57600
value|16
end_define

begin_define
define|#
directive|define
name|SVR4_B76800
value|17
end_define

begin_define
define|#
directive|define
name|SVR4_B115200
value|18
end_define

begin_define
define|#
directive|define
name|SVR4_B153600
value|19
end_define

begin_define
define|#
directive|define
name|SVR4_B230400
value|20
end_define

begin_define
define|#
directive|define
name|SVR4_B307200
value|21
end_define

begin_define
define|#
directive|define
name|SVR4_B460800
value|22
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_TERMIOS_H_ */
end_comment

end_unit

