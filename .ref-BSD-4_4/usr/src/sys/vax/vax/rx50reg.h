begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)rx50reg.h	7.2 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * RX50 registers.  */
end_comment

begin_comment
comment|/*  * The names below do not quite match the DEC documentation simply because  * the names in the documentation are so bad.  */
end_comment

begin_struct
struct|struct
name|rx50device
block|{
name|u_short
name|rxid
decl_stmt|;
comment|/* identification */
name|u_short
name|reserved
decl_stmt|;
name|u_short
name|rxcmd
decl_stmt|;
comment|/* command function reg */
name|u_short
name|rxtrk
decl_stmt|;
comment|/* track */
name|u_short
name|rxsec
decl_stmt|;
comment|/* sector */
name|u_short
name|rxcsc
decl_stmt|;
comment|/* current sector */
name|u_short
name|rxict
decl_stmt|;
comment|/* incorrect track (???) */
name|u_short
name|rxext
decl_stmt|;
comment|/* extend command register */
name|u_short
name|rxedb
decl_stmt|;
comment|/* empty data buffer (read) */
name|u_short
name|rxrda
decl_stmt|;
comment|/* reset data address */
name|u_short
name|rxgo
decl_stmt|;
comment|/* read to start current cmd */
name|u_short
name|rxfdb
decl_stmt|;
comment|/* fill data buffer (write) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RX50SEC
value|10
end_define

begin_comment
comment|/* sectors per track */
end_comment

begin_define
define|#
directive|define
name|RX50MAXSEC
value|800
end_define

begin_comment
comment|/* 10 sectors times 80 tracks */
end_comment

begin_comment
comment|/*  * Do the sector skew given the sector and track  * number (it depends on both!).  */
end_comment

begin_comment
comment|/*			(((((s) / 5) + 2 * ((s) + (t))) % 10) + 1) */
end_comment

begin_define
define|#
directive|define
name|RX50SKEW
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|(((s) / 5) + "\1\3\5\7\11\1\3\5\7"[((s) + (t)) % 5])
end_define

begin_comment
comment|/*  * Values in the command function register.  */
end_comment

begin_define
define|#
directive|define
name|RXCMD_ERROR
value|0x80
end_define

begin_comment
comment|/* error bit (composite?) */
end_comment

begin_define
define|#
directive|define
name|RXCMD_READ
value|0x40
end_define

begin_comment
comment|/* read command */
end_comment

begin_define
define|#
directive|define
name|RXCMD_WRITE
value|0x70
end_define

begin_comment
comment|/* write command */
end_comment

begin_define
define|#
directive|define
name|RXCMD_RESET
value|0x20
end_define

begin_comment
comment|/* reset command */
end_comment

begin_define
define|#
directive|define
name|RXCMD_DONE
value|0x08
end_define

begin_comment
comment|/* operation done (status) */
end_comment

begin_define
define|#
directive|define
name|RXCMD_DRIVE0
value|0x00
end_define

begin_comment
comment|/* select drive 0 (csa1) */
end_comment

begin_define
define|#
directive|define
name|RXCMD_DRIVE1
value|0x02
end_define

begin_comment
comment|/* select drive 1 (csa2) */
end_comment

end_unit

