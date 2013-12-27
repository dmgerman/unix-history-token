begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Brian Somers<brian@Awfulhak.org>  *   based on work by Slawa Olhovchenkov  *                    John Prince<johnp@knight-trosoft.com>  *                    Eric Hernes  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|global_data
block|{
specifier|volatile
name|u_short
name|cin
decl_stmt|;
specifier|volatile
name|u_short
name|cout
decl_stmt|;
specifier|volatile
name|u_short
name|cstart
decl_stmt|;
specifier|volatile
name|u_short
name|cmax
decl_stmt|;
specifier|volatile
name|u_short
name|ein
decl_stmt|;
specifier|volatile
name|u_short
name|eout
decl_stmt|;
specifier|volatile
name|u_short
name|istart
decl_stmt|;
specifier|volatile
name|u_short
name|imax
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|board_chan
block|{
specifier|volatile
name|u_short
name|tpjmp
decl_stmt|;
specifier|volatile
name|u_short
name|tcjmp
decl_stmt|;
specifier|volatile
name|u_short
name|fil1
decl_stmt|;
specifier|volatile
name|u_short
name|rpjmp
decl_stmt|;
specifier|volatile
name|u_short
name|tseg
decl_stmt|;
specifier|volatile
name|u_short
name|tin
decl_stmt|;
specifier|volatile
name|u_short
name|tout
decl_stmt|;
specifier|volatile
name|u_short
name|tmax
decl_stmt|;
specifier|volatile
name|u_short
name|rseg
decl_stmt|;
specifier|volatile
name|u_short
name|rin
decl_stmt|;
specifier|volatile
name|u_short
name|rout
decl_stmt|;
specifier|volatile
name|u_short
name|rmax
decl_stmt|;
specifier|volatile
name|u_short
name|tlow
decl_stmt|;
specifier|volatile
name|u_short
name|rlow
decl_stmt|;
specifier|volatile
name|u_short
name|rhigh
decl_stmt|;
specifier|volatile
name|u_short
name|incr
decl_stmt|;
specifier|volatile
name|u_short
name|dev
decl_stmt|;
specifier|volatile
name|u_short
name|edelay
decl_stmt|;
specifier|volatile
name|u_short
name|blen
decl_stmt|;
specifier|volatile
name|u_short
name|btime
decl_stmt|;
specifier|volatile
name|u_short
name|iflag
decl_stmt|;
specifier|volatile
name|u_short
name|oflag
decl_stmt|;
specifier|volatile
name|u_short
name|cflag
decl_stmt|;
specifier|volatile
name|u_short
name|gmask
decl_stmt|;
specifier|volatile
name|u_short
name|col
decl_stmt|;
specifier|volatile
name|u_short
name|delay
decl_stmt|;
specifier|volatile
name|u_short
name|imask
decl_stmt|;
specifier|volatile
name|u_short
name|tflush
decl_stmt|;
specifier|volatile
name|u_char
name|_1
index|[
literal|16
index|]
decl_stmt|;
specifier|volatile
name|u_char
name|num
decl_stmt|;
specifier|volatile
name|u_char
name|ract
decl_stmt|;
specifier|volatile
name|u_char
name|bstat
decl_stmt|;
specifier|volatile
name|u_char
name|tbusy
decl_stmt|;
specifier|volatile
name|u_char
name|iempty
decl_stmt|;
specifier|volatile
name|u_char
name|ilow
decl_stmt|;
specifier|volatile
name|u_char
name|idata
decl_stmt|;
specifier|volatile
name|u_char
name|eflag
decl_stmt|;
specifier|volatile
name|u_char
name|tflag
decl_stmt|;
specifier|volatile
name|u_char
name|rflag
decl_stmt|;
specifier|volatile
name|u_char
name|xmask
decl_stmt|;
specifier|volatile
name|u_char
name|xval
decl_stmt|;
specifier|volatile
name|u_char
name|mstat
decl_stmt|;
specifier|volatile
name|u_char
name|mchange
decl_stmt|;
specifier|volatile
name|u_char
name|mint
decl_stmt|;
specifier|volatile
name|u_char
name|lstat
decl_stmt|;
specifier|volatile
name|u_char
name|mtran
decl_stmt|;
specifier|volatile
name|u_char
name|orun
decl_stmt|;
specifier|volatile
name|u_char
name|startca
decl_stmt|;
specifier|volatile
name|u_char
name|stopca
decl_stmt|;
specifier|volatile
name|u_char
name|startc
decl_stmt|;
specifier|volatile
name|u_char
name|stopc
decl_stmt|;
specifier|volatile
name|u_char
name|vnext
decl_stmt|;
specifier|volatile
name|u_char
name|hflow
decl_stmt|;
specifier|volatile
name|u_char
name|fillc
decl_stmt|;
specifier|volatile
name|u_char
name|ochar
decl_stmt|;
specifier|volatile
name|u_char
name|omask
decl_stmt|;
specifier|volatile
name|u_char
name|_2
decl_stmt|;
specifier|volatile
name|u_char
name|_3
index|[
literal|28
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SRXLWATER
value|0xe0
end_define

begin_define
define|#
directive|define
name|SRXHWATER
value|0xe1
end_define

begin_define
define|#
directive|define
name|STPTR
value|0xe2
end_define

begin_define
define|#
directive|define
name|PAUSETX
value|0xe3
end_define

begin_define
define|#
directive|define
name|RESUMETX
value|0xe4
end_define

begin_define
define|#
directive|define
name|SAUXONOFFC
value|0xe6
end_define

begin_define
define|#
directive|define
name|SENDBREAK
value|0xe8
end_define

begin_define
define|#
directive|define
name|SETMODEM
value|0xe9
end_define

begin_define
define|#
directive|define
name|SETIFLAGS
value|0xeA
end_define

begin_define
define|#
directive|define
name|SONOFFC
value|0xeB
end_define

begin_define
define|#
directive|define
name|STXLWATER
value|0xeC
end_define

begin_define
define|#
directive|define
name|PAUSERX
value|0xeE
end_define

begin_define
define|#
directive|define
name|RESUMERX
value|0xeF
end_define

begin_define
define|#
directive|define
name|RESETCHAN
value|0xf0
end_define

begin_define
define|#
directive|define
name|SETBUFFER
value|0xf2
end_define

begin_define
define|#
directive|define
name|SETCOOKED
value|0xf3
end_define

begin_define
define|#
directive|define
name|SETHFLOW
value|0xf4
end_define

begin_define
define|#
directive|define
name|SETCFLAGS
value|0xf5
end_define

begin_define
define|#
directive|define
name|SETVNEXT
value|0xf6
end_define

begin_define
define|#
directive|define
name|SETBSLICE
value|0xf7
end_define

begin_define
define|#
directive|define
name|SETRSMODE
value|0xfd
end_define

begin_define
define|#
directive|define
name|SETCMDACK
value|0xfe
end_define

begin_define
define|#
directive|define
name|RESERV
value|0xff
end_define

begin_define
define|#
directive|define
name|BREAK_IND
value|0x01
end_define

begin_define
define|#
directive|define
name|LOWTX_IND
value|0x02
end_define

begin_define
define|#
directive|define
name|EMPTYTX_IND
value|0x04
end_define

begin_define
define|#
directive|define
name|DATA_IND
value|0x08
end_define

begin_define
define|#
directive|define
name|MODEMCHG_IND
value|0x20
end_define

begin_define
define|#
directive|define
name|RECV_OVR_IND
value|0x40
end_define

begin_define
define|#
directive|define
name|CMD_ACK_IND
value|0x40
end_define

begin_define
define|#
directive|define
name|UART_OVR_IND
value|0x80
end_define

begin_define
define|#
directive|define
name|ALL_IND
value|(BREAK_IND|LOWTX_IND|EMPTYTX_IND|DATA_IND|MODEMCHG_IND)
end_define

begin_define
define|#
directive|define
name|FEPTIMEOUT
value|2000
end_define

begin_define
define|#
directive|define
name|FEPCLR
value|0x0
end_define

begin_define
define|#
directive|define
name|FEPMEM
value|0x2
end_define

begin_define
define|#
directive|define
name|FEPRST
value|0x4
end_define

begin_define
define|#
directive|define
name|FEPREQ
value|0x8
end_define

begin_define
define|#
directive|define
name|FEPWIN
value|0x80
end_define

begin_define
define|#
directive|define
name|FEPMASK
value|0xe
end_define

begin_comment
comment|/* #define FEPMASK 0x4 */
end_comment

begin_define
define|#
directive|define
name|BOTWIN
value|0x100L
end_define

begin_define
define|#
directive|define
name|TOPWIN
value|0xFF00L
end_define

begin_define
define|#
directive|define
name|MISCGLOBAL
value|0x0C00L
end_define

begin_define
define|#
directive|define
name|FEPCODESEG
value|0x0200L
end_define

begin_comment
comment|/* #define BIOSCODE   0xff800 */
end_comment

begin_comment
comment|/* Window 15, offset 7800h */
end_comment

begin_define
define|#
directive|define
name|FEPCODE
value|0x0d000
end_define

begin_define
define|#
directive|define
name|FEP_CSTART
value|0x400L
end_define

begin_define
define|#
directive|define
name|FEP_CMAX
value|0x800L
end_define

begin_define
define|#
directive|define
name|FEP_ISTART
value|0x800L
end_define

begin_define
define|#
directive|define
name|FEP_IMAX
value|0xC00L
end_define

begin_define
define|#
directive|define
name|MBOX
value|0xC40L
end_define

begin_define
define|#
directive|define
name|FEP_CIN
value|0xD10L
end_define

begin_define
define|#
directive|define
name|FEP_GLOBAL
value|0xD10L
end_define

begin_define
define|#
directive|define
name|FEP_EIN
value|0xD18L
end_define

begin_define
define|#
directive|define
name|FEPSTAT
value|0xD20L
end_define

begin_define
define|#
directive|define
name|CHANSTRUCT
value|0x1000L
end_define

begin_define
define|#
directive|define
name|RXTXBUF
value|0x4000L
end_define

begin_define
define|#
directive|define
name|BIOSOFFSET
value|0x1000L
end_define

begin_define
define|#
directive|define
name|BIOSCODE
value|0xf800L
end_define

begin_define
define|#
directive|define
name|FEPOFFSET
value|0x2000L
end_define

begin_comment
comment|/* c_cflag bits */
end_comment

begin_define
define|#
directive|define
name|FEP_CSIZE
value|0x000030
end_define

begin_define
define|#
directive|define
name|FEP_CS5
value|0x000000
end_define

begin_define
define|#
directive|define
name|FEP_CS6
value|0x000010
end_define

begin_define
define|#
directive|define
name|FEP_CS7
value|0x000020
end_define

begin_define
define|#
directive|define
name|FEP_CS8
value|0x000030
end_define

begin_define
define|#
directive|define
name|FEP_CSTOPB
value|0x000040
end_define

begin_define
define|#
directive|define
name|FEP_CREAD
value|0x000080
end_define

begin_define
define|#
directive|define
name|FEP_PARENB
value|0x000100
end_define

begin_define
define|#
directive|define
name|FEP_PARODD
value|0x000200
end_define

begin_define
define|#
directive|define
name|FEP_CLOCAL
value|0x000800
end_define

begin_define
define|#
directive|define
name|FEP_FASTBAUD
value|0x000400
end_define

begin_comment
comment|/* c_iflag bits */
end_comment

begin_define
define|#
directive|define
name|FEP_IGNBRK
value|0000001
end_define

begin_define
define|#
directive|define
name|FEP_BRKINT
value|0000002
end_define

begin_define
define|#
directive|define
name|FEP_IGNPAR
value|0000004
end_define

begin_define
define|#
directive|define
name|FEP_PARMRK
value|0000010
end_define

begin_define
define|#
directive|define
name|FEP_INPCK
value|0000020
end_define

begin_define
define|#
directive|define
name|FEP_ISTRIP
value|0000040
end_define

begin_define
define|#
directive|define
name|FEP_IXON
value|0002000
end_define

begin_define
define|#
directive|define
name|FEP_IXANY
value|0004000
end_define

begin_define
define|#
directive|define
name|FEP_IXOFF
value|0010000
end_define

end_unit

