begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)rsp.h	7.2 (Berkeley) 5/9/91  */
end_comment

begin_comment
comment|/*  * TU58 transfer protocol constants and data structures  */
end_comment

begin_comment
comment|/*  * Structure of a command packet  */
end_comment

begin_struct
struct|struct
name|packet
block|{
name|u_char
name|pk_flag
decl_stmt|;
comment|/* indicates packet type (cmd, data, etc.) */
name|u_char
name|pk_mcount
decl_stmt|;
comment|/* length of packet (bytes) */
name|u_char
name|pk_op
decl_stmt|;
comment|/* operation to perform (read, write, etc.) */
name|u_char
name|pk_mod
decl_stmt|;
comment|/* modifier for op or returned status */
name|u_char
name|pk_unit
decl_stmt|;
comment|/* unit number */
name|u_char
name|pk_sw
decl_stmt|;
comment|/* switches */
name|u_short
name|pk_seq
decl_stmt|;
comment|/* sequence number, always zero */
name|u_short
name|pk_count
decl_stmt|;
comment|/* requested byte count for read or write */
name|u_short
name|pk_block
decl_stmt|;
comment|/* block number for read, write, or seek */
name|u_short
name|pk_chksum
decl_stmt|;
comment|/* checksum, by words with end around carry */
block|}
struct|;
end_struct

begin_comment
comment|/*  * States  */
end_comment

begin_define
define|#
directive|define
name|TUS_INIT1
value|0
end_define

begin_comment
comment|/* sending nulls */
end_comment

begin_define
define|#
directive|define
name|TUS_INIT2
value|1
end_define

begin_comment
comment|/* sending inits */
end_comment

begin_define
define|#
directive|define
name|TUS_IDLE
value|2
end_define

begin_comment
comment|/* initialized, no transfer in progress */
end_comment

begin_define
define|#
directive|define
name|TUS_SENDH
value|3
end_define

begin_comment
comment|/* sending header */
end_comment

begin_define
define|#
directive|define
name|TUS_SENDD
value|4
end_define

begin_comment
comment|/* sending data */
end_comment

begin_define
define|#
directive|define
name|TUS_SENDC
value|5
end_define

begin_comment
comment|/* sending checksum */
end_comment

begin_define
define|#
directive|define
name|TUS_SENDR
value|6
end_define

begin_comment
comment|/* sending read command packet */
end_comment

begin_define
define|#
directive|define
name|TUS_SENDW
value|7
end_define

begin_comment
comment|/* sending write command packet */
end_comment

begin_define
define|#
directive|define
name|TUS_GETH
value|8
end_define

begin_comment
comment|/* reading header */
end_comment

begin_define
define|#
directive|define
name|TUS_GETD
value|9
end_define

begin_comment
comment|/* reading data */
end_comment

begin_define
define|#
directive|define
name|TUS_GETC
value|10
end_define

begin_comment
comment|/* reading checksum */
end_comment

begin_define
define|#
directive|define
name|TUS_GET
value|11
end_define

begin_comment
comment|/* reading an entire packet */
end_comment

begin_define
define|#
directive|define
name|TUS_WAIT
value|12
end_define

begin_comment
comment|/* waiting for continue */
end_comment

begin_define
define|#
directive|define
name|TUS_RCVERR
value|13
end_define

begin_comment
comment|/* receiver error in pseudo DMA routine */
end_comment

begin_define
define|#
directive|define
name|TUS_CHKERR
value|14
end_define

begin_comment
comment|/* checksum error in pseudo DMA routine */
end_comment

begin_define
define|#
directive|define
name|TUS_NSTATES
value|15
end_define

begin_define
define|#
directive|define
name|printstate
parameter_list|(
name|state
parameter_list|)
define|\
value|if ((state)< TUS_NSTATES) \ 		printf("%s", tustates[(state)]); \ 	else \ 		printf("%d", (state));
end_define

begin_comment
comment|/*  * Packet Flags  */
end_comment

begin_define
define|#
directive|define
name|TUF_DATA
value|1
end_define

begin_comment
comment|/* data packet */
end_comment

begin_define
define|#
directive|define
name|TUF_CMD
value|2
end_define

begin_comment
comment|/* command packet */
end_comment

begin_define
define|#
directive|define
name|TUF_INITF
value|4
end_define

begin_comment
comment|/* initialize */
end_comment

begin_define
define|#
directive|define
name|TUF_CONT
value|020
end_define

begin_comment
comment|/* continue */
end_comment

begin_define
define|#
directive|define
name|TUF_XOFF
value|023
end_define

begin_comment
comment|/* flow control */
end_comment

begin_comment
comment|/*  * Op Codes  */
end_comment

begin_define
define|#
directive|define
name|TUOP_NOOP
value|0
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|TUOP_INIT
value|1
end_define

begin_comment
comment|/* initialize */
end_comment

begin_define
define|#
directive|define
name|TUOP_READ
value|2
end_define

begin_comment
comment|/* read block */
end_comment

begin_define
define|#
directive|define
name|TUOP_WRITE
value|3
end_define

begin_comment
comment|/* write block */
end_comment

begin_define
define|#
directive|define
name|TUOP_SEEK
value|5
end_define

begin_comment
comment|/* seek to block */
end_comment

begin_define
define|#
directive|define
name|TUOP_DIAGNOSE
value|7
end_define

begin_comment
comment|/* run micro-diagnostics */
end_comment

begin_define
define|#
directive|define
name|TUOP_END
value|0100
end_define

begin_comment
comment|/* end packet */
end_comment

begin_comment
comment|/*  * Mod Flags  */
end_comment

begin_define
define|#
directive|define
name|TUMD_WRV
value|1
end_define

begin_comment
comment|/* write with read verify */
end_comment

begin_comment
comment|/*  * Switches  */
end_comment

begin_define
define|#
directive|define
name|TUSW_MRSP
value|010
end_define

begin_comment
comment|/* use Modified RSP */
end_comment

end_unit

