begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_TTOLD_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_TTOLD_H_
end_define

begin_struct
struct|struct
name|svr4_tchars
block|{
name|char
name|t_intrc
decl_stmt|;
name|char
name|t_quitc
decl_stmt|;
name|char
name|t_startc
decl_stmt|;
name|char
name|t_stopc
decl_stmt|;
name|char
name|t_eofc
decl_stmt|;
name|char
name|t_brkc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_sgttyb
block|{
name|u_char
name|sg_ispeed
decl_stmt|;
name|u_char
name|sg_ospeed
decl_stmt|;
name|u_char
name|sg_erase
decl_stmt|;
name|u_char
name|sg_kill
decl_stmt|;
name|int
name|sg_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_ltchars
block|{
name|char
name|t_suspc
decl_stmt|;
name|char
name|t_dsuspc
decl_stmt|;
name|char
name|t_rprntc
decl_stmt|;
name|char
name|t_flushc
decl_stmt|;
name|char
name|t_werasc
decl_stmt|;
name|char
name|t_lnextc
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|SVR4_tIOC
end_ifndef

begin_define
define|#
directive|define
name|SVR4_tIOC
value|('t'<< 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SVR4_TIOCGETD
value|(SVR4_tIOC |   0)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCSETD
value|(SVR4_tIOC |   1)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCHPCL
value|(SVR4_tIOC |   2)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCGETP
value|(SVR4_tIOC |   8)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCSETP
value|(SVR4_tIOC |   9)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCSETN
value|(SVR4_tIOC |  10)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCEXCL
value|(SVR4_tIOC |  13)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCNXCL
value|(SVR4_tIOC |  14)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCFLUSH
value|(SVR4_tIOC |  16)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCSETC
value|(SVR4_tIOC |  17)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCGETC
value|(SVR4_tIOC |  18)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCGPGRP
value|(SVR4_tIOC |  20)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCSPGRP
value|(SVR4_tIOC |  21)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCGSID
value|(SVR4_tIOC |  22)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCSTI
value|(SVR4_tIOC |  23)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCSSID
value|(SVR4_tIOC |  24)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCMSET
value|(SVR4_tIOC |  26)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCMBIS
value|(SVR4_tIOC |  27)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCMBIC
value|(SVR4_tIOC |  28)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCMGET
value|(SVR4_tIOC |  29)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCREMOTE
value|(SVR4_tIOC |  30)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCSIGNAL
value|(SVR4_tIOC |  31)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCSTART
value|(SVR4_tIOC | 110)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCSTOP
value|(SVR4_tIOC | 111)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCNOTTY
value|(SVR4_tIOC | 113)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCOUTQ
value|(SVR4_tIOC | 115)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCGLTC
value|(SVR4_tIOC | 116)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCSLTC
value|(SVR4_tIOC | 117)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCCDTR
value|(SVR4_tIOC | 120)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCSDTR
value|(SVR4_tIOC | 121)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCCBRK
value|(SVR4_tIOC | 122)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCSBRK
value|(SVR4_tIOC | 123)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCLGET
value|(SVR4_tIOC | 124)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCLSET
value|(SVR4_tIOC | 125)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCLBIC
value|(SVR4_tIOC | 126)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCLBIS
value|(SVR4_tIOC | 127)
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCM_LE
value|0001
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCM_DTR
value|0002
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCM_RTS
value|0004
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCM_ST
value|0010
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCM_SR
value|0020
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCM_CTS
value|0040
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCM_CAR
value|0100
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCM_CD
value|SVR4_TIOCM_CAR
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCM_RNG
value|0200
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCM_RI
value|SVR4_TIOCM_RNG
end_define

begin_define
define|#
directive|define
name|SVR4_TIOCM_DSR
value|0400
end_define

begin_define
define|#
directive|define
name|SVR4_OTTYDISC
value|0
end_define

begin_define
define|#
directive|define
name|SVR4_NETLDISC
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_NTTYDISC
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_TABLDISC
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_NTABLDISC
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_MOUSELDISC
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_KBDLDISC
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_TTOLD_H_ */
end_comment

end_unit

