begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)reloc.h	8.1 (Berkeley) 6/10/93  *  * from: $Header: reloc.h,v 1.6 92/06/20 09:59:37 torek Exp $  */
end_comment

begin_comment
comment|/*  * MIPS relocation types.  */
end_comment

begin_enum
enum|enum
name|reloc_type
block|{
name|MIPS_RELOC_32
block|,
comment|/* 32-bit absolute */
name|MIPS_RELOC_JMP
block|,
comment|/* 26-bit absolute<< 2 | high 4 bits of pc */
name|MIPS_RELOC_WDISP16
block|,
comment|/* 16-bit signed pc-relative<< 2 */
name|MIPS_RELOC_HI16
block|,
comment|/* 16-bit absolute<< 16 */
name|MIPS_RELOC_HI16_S
block|,
comment|/* 16-bit absolute<< 16 (+1 if needed) */
name|MIPS_RELOC_LO16
block|,
comment|/* 16-bit absolute */
block|}
enum|;
end_enum

begin_comment
comment|/*  * MIPS relocation info.  *  * Symbol-relative relocation is done by:  *	1. start with the value r_addend,  *	2. locate the appropriate symbol and if defined, add symbol value,  *	3. if pc relative, subtract pc,  *	4. if the reloc_type is MIPS_RELOC_HI16_S and the result bit 15 is set,  *		add 0x00010000,  *	5. shift down 2 or 16 if necessary.  * The resulting value is then to be stuffed into the appropriate bits  * in the object (the low 16, or the low 26 bits).  */
end_comment

begin_struct
struct|struct
name|reloc_info_mips
block|{
name|u_long
name|r_address
decl_stmt|;
comment|/* relocation addr (offset in segment) */
name|u_int
name|r_index
range|:
literal|24
decl_stmt|,
comment|/* segment (r_extern==0) or symbol index */
name|r_extern
range|:
literal|1
decl_stmt|,
comment|/* if set, r_index is symbol index */
range|:
literal|2
decl_stmt|;
comment|/* unused */
name|enum
name|reloc_type
name|r_type
range|:
literal|5
decl_stmt|;
comment|/* relocation type, from above */
name|long
name|r_addend
decl_stmt|;
comment|/* value to add to symbol value */
block|}
struct|;
end_struct

end_unit

