begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_enreg.h	7.3 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * Xerox experimental ethernet registers.  *  * N.B.: status register and device address are read/write,  * device address is read-only, rest are WRITE ONLY!  */
end_comment

begin_struct
struct|struct
name|endevice
block|{
name|short
name|en_owc
decl_stmt|;
comment|/* output word count (10 bits) */
name|short
name|en_oba
decl_stmt|;
comment|/* output buffer address */
name|short
name|en_ostat
decl_stmt|;
comment|/* output control and status */
name|short
name|en_odelay
decl_stmt|;
comment|/* output start delay, 25usec units  */
name|short
name|en_iwc
decl_stmt|;
comment|/* input word count */
name|short
name|en_iba
decl_stmt|;
comment|/* input buffer address */
name|short
name|en_istat
decl_stmt|;
comment|/* input csr */
name|short
name|en_addr
decl_stmt|;
comment|/* ~device address (low 8 bits) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Control and status bits.  */
end_comment

begin_define
define|#
directive|define
name|EN_IERROR
value|0x8000
end_define

begin_comment
comment|/* CRC error, buf ovflo or overrun */
end_comment

begin_define
define|#
directive|define
name|EN_OERROR
value|0x8000
end_define

begin_comment
comment|/* collision or output underrun */
end_comment

begin_define
define|#
directive|define
name|EN_OPDONE
value|0x0080
end_define

begin_comment
comment|/* previous operation completed */
end_comment

begin_define
define|#
directive|define
name|EN_IEN
value|0x0040
end_define

begin_comment
comment|/* enable interrupt when DONE */
end_comment

begin_define
define|#
directive|define
name|EN_PROMISCUOUS
value|0x0002
end_define

begin_comment
comment|/* promiscuous, input any packet */
end_comment

begin_define
define|#
directive|define
name|EN_GO
value|0x0001
end_define

begin_comment
comment|/* start op bit */
end_comment

begin_define
define|#
directive|define
name|EN_BITS
value|"\10\20ERR\10OPDONE\7IEN\2PROM\1GO"
end_define

begin_define
define|#
directive|define
name|spl_enet
parameter_list|()
value|spl5()
end_define

end_unit

