begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)reloc.h	7.2 (Berkeley) %G%  *  * from: $Header: reloc.h,v 1.6 92/06/20 09:59:37 torek Exp $  */
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

