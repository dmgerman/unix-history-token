begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fhpibreg.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_include
include|#
directive|include
file|<hp/dev/iotypes.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_struct
struct|struct
name|fhpibdevice
block|{
name|u_char
name|hpib_pad0
decl_stmt|;
name|vu_char
name|hpib_cid
decl_stmt|;
name|u_char
name|hpib_pad1
decl_stmt|;
define|#
directive|define
name|hpib_ie
value|hpib_ids
name|vu_char
name|hpib_ids
decl_stmt|;
name|u_char
name|hpib_pad2
decl_stmt|;
name|vu_char
name|hpib_ctrl2
decl_stmt|;
name|u_char
name|hpib_pad3
decl_stmt|;
name|vu_char
name|hpib_latch
decl_stmt|;
name|u_char
name|hpib_pad4
index|[
literal|9
index|]
decl_stmt|;
name|vu_char
name|hpib_intr
decl_stmt|;
name|u_char
name|hpib_pad5
decl_stmt|;
name|vu_char
name|hpib_imask
decl_stmt|;
name|u_char
name|hpib_pad6
decl_stmt|;
name|vu_char
name|hpib_data
decl_stmt|;
name|u_char
name|hpib_pad7
decl_stmt|;
name|vu_char
name|hpib_stat
decl_stmt|;
name|u_char
name|hpib_pad8
decl_stmt|;
name|vu_char
name|hpib_cmd
decl_stmt|;
name|u_char
name|hpib_pad9
decl_stmt|;
name|vu_char
name|hpib_ar
decl_stmt|;
name|u_char
name|hpib_pad10
decl_stmt|;
name|vu_char
name|hpib_pmask
decl_stmt|;
name|u_char
name|hpib_pad11
decl_stmt|;
name|vu_char
name|hpib_psense
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* status bits */
end_comment

begin_define
define|#
directive|define
name|ST_READ0
value|0xC0
end_define

begin_define
define|#
directive|define
name|ST_READ1
value|0x80
end_define

begin_define
define|#
directive|define
name|ST_IENAB
value|0x80
end_define

begin_define
define|#
directive|define
name|ST_EOI
value|0x80
end_define

begin_define
define|#
directive|define
name|ST_ATN
value|0x40
end_define

begin_define
define|#
directive|define
name|ST_WRITE
value|0x00
end_define

begin_comment
comment|/* control bits */
end_comment

begin_define
define|#
directive|define
name|CT_8BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|CT_REN
value|0x20
end_define

begin_define
define|#
directive|define
name|CT_IFC
value|0x10
end_define

begin_define
define|#
directive|define
name|CT_FIFOSEL
value|0x02
end_define

begin_define
define|#
directive|define
name|CT_INITFIFO
value|0x01
end_define

begin_define
define|#
directive|define
name|IM_PABORT
value|0x40
end_define

begin_define
define|#
directive|define
name|IM_PPRESP
value|0x20
end_define

begin_define
define|#
directive|define
name|IM_ROOM
value|0x08
end_define

begin_define
define|#
directive|define
name|IM_BYTE
value|0x04
end_define

begin_define
define|#
directive|define
name|IM_IDLE
value|0x02
end_define

begin_define
define|#
directive|define
name|AR_ARONC
value|0x80
end_define

end_unit

