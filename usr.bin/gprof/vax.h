begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vax.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*      *	opcode of the `calls' instruction      */
end_comment

begin_define
define|#
directive|define
name|CALLS
value|0xfb
end_define

begin_comment
comment|/*      *	offset (in bytes) of the code from the entry address of a routine.      *	(see asgnsamples for use and explanation.)      */
end_comment

begin_define
define|#
directive|define
name|OFFSET_OF_CODE
value|2
end_define

begin_comment
comment|/*      *	register for pc relative addressing      */
end_comment

begin_define
define|#
directive|define
name|PC
value|0xf
end_define

begin_enum
enum|enum
name|opermodes
block|{
name|literal
block|,
name|indexed
block|,
name|reg
block|,
name|regdef
block|,
name|autodec
block|,
name|autoinc
block|,
name|autoincdef
block|,
name|bytedisp
block|,
name|bytedispdef
block|,
name|worddisp
block|,
name|worddispdef
block|,
name|longdisp
block|,
name|longdispdef
block|,
name|immediate
block|,
name|absolute
block|,
name|byterel
block|,
name|bytereldef
block|,
name|wordrel
block|,
name|wordreldef
block|,
name|longrel
block|,
name|longreldef
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|opermodes
name|operandenum
typedef|;
end_typedef

begin_struct
struct|struct
name|modebyte
block|{
name|unsigned
name|int
name|regfield
range|:
literal|4
decl_stmt|;
name|unsigned
name|int
name|modefield
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

end_unit

