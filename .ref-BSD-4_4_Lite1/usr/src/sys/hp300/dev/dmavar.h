begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dmavar.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/* dmago flags */
end_comment

begin_define
define|#
directive|define
name|DMAGO_BYTE
value|0x00
end_define

begin_comment
comment|/* do byte (8 bit) transfers */
end_comment

begin_define
define|#
directive|define
name|DMAGO_WORD
value|0x01
end_define

begin_comment
comment|/* do word (16 bit) transfers */
end_comment

begin_define
define|#
directive|define
name|DMAGO_LWORD
value|0x02
end_define

begin_comment
comment|/* do longword (32 bit) transfers */
end_comment

begin_define
define|#
directive|define
name|DMAGO_PRI
value|0x04
end_define

begin_comment
comment|/* do "priority" DMA */
end_comment

begin_define
define|#
directive|define
name|DMAGO_READ
value|0x08
end_define

begin_comment
comment|/* transfer is a read */
end_comment

begin_define
define|#
directive|define
name|DMAGO_NOINT
value|0x80
end_define

begin_comment
comment|/* don't interrupt on completion */
end_comment

begin_comment
comment|/* dma "controllers" (channels) */
end_comment

begin_define
define|#
directive|define
name|DMA0
value|0x1
end_define

begin_define
define|#
directive|define
name|DMA1
value|0x2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|dmago
argument_list|()
decl_stmt|,
name|dmafree
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|dmareq
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

