begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)kdbparam.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * Machine dependent definitions for kdb.  */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|kdbshorten
parameter_list|(
name|w
parameter_list|)
value|((w)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|kdbbyte
parameter_list|(
name|w
parameter_list|)
value|((w)& 0xFF)
end_define

begin_define
define|#
directive|define
name|kdbitol
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((long)(((b)<< 16) | ((a)& 0xFFFF)))
end_define

begin_define
define|#
directive|define
name|kdbbtol
parameter_list|(
name|a
parameter_list|)
value|((long)(a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LPRMODE
value|"%R"
end_define

begin_define
define|#
directive|define
name|OFFMODE
value|"+%R"
end_define

begin_define
define|#
directive|define
name|SETBP
parameter_list|(
name|ins
parameter_list|)
value|MACH_BREAK_BRKPT
end_define

begin_comment
comment|/* return the program counter value modified if we are in a delay slot */
end_comment

begin_define
define|#
directive|define
name|kdbgetpc
parameter_list|(
name|pcb
parameter_list|)
value|(kdbvar[kdbvarchk('t')]< 0 ? \ 	(pcb).pcb_regs[34] + 4 : (pcb).pcb_regs[34])
end_define

begin_define
define|#
directive|define
name|kdbishiddenreg
parameter_list|(
name|p
parameter_list|)
value|((p)>=&kdbreglist[33])
end_define

begin_define
define|#
directive|define
name|kdbisbreak
parameter_list|(
name|type
parameter_list|)
value|(((type)& MACH_CR_EXC_CODE) == 0x24)
end_define

begin_comment
comment|/* check for address wrap around */
end_comment

begin_define
define|#
directive|define
name|kdbaddrwrap
parameter_list|(
name|addr
parameter_list|,
name|newaddr
parameter_list|)
value|(((addr)^(newaddr))>> 31)
end_define

begin_comment
comment|/* declare machine dependent routines defined in kadb.c */
end_comment

begin_decl_stmt
name|void
name|kdbprinttrap
name|__P
argument_list|(
operator|(
name|unsigned
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kdbsetsstep
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kdbclrsstep
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kdbreadc
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kdbwrite
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kdbprintins
name|__P
argument_list|(
operator|(
name|int
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kdbstacktrace
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|kdbmalloc
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

