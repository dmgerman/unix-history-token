begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)reloc.h	7.3 (Berkeley) %G%  *  * from: $Header: reloc.h,v 1.7 92/11/26 02:04:45 torek Exp $  */
end_comment

begin_comment
comment|/*  * SPARC relocations.  The linker has, unfortunately, a large number  * of link types.  We do not do dynamic linking (yet?) but we define  * the dynamic link types.  */
end_comment

begin_enum
enum|enum
name|reloc_type
block|{
comment|/* architecturally-required types */
name|RELOC_8
block|,
comment|/*  8-bit absolute */
name|RELOC_16
block|,
comment|/* 16-bit absolute */
name|RELOC_32
block|,
comment|/* 32-bit absolute */
name|RELOC_DISP8
block|,
comment|/*  8-bit pc-relative */
name|RELOC_DISP16
block|,
comment|/* 16-bit pc-relative */
name|RELOC_DISP32
block|,
comment|/* 32-bit pc-relative */
name|RELOC_WDISP30
block|,
comment|/* 30-bit pc-relative signed word */
name|RELOC_WDISP22
block|,
comment|/* 22-bit pc-relative signed word */
name|RELOC_HI22
block|,
comment|/* 22-bit `%hi' (ie, sethi %hi(X),%l0) */
name|RELOC_22
block|,
comment|/* 22-bit non-%hi (i.e., sethi X,%l0) */
name|RELOC_13
block|,
comment|/* 13-bit absolute */
name|RELOC_LO10
block|,
comment|/* 10-bit `%lo' */
comment|/* gnu ld understands some of these, but I do not */
name|RELOC_SFA_BASE
block|,
comment|/* ? */
name|RELOC_SFA_OFF13
block|,
comment|/* ? */
name|RELOC_BASE10
block|,
comment|/* ? */
name|RELOC_BASE13
block|,
comment|/* ? */
name|RELOC_BASE22
block|,
comment|/* ? */
comment|/* gnu ld does not use these but Sun linker does */
comment|/* we define them anyway (note that they are included 		   in the freely-available gas sources!) */
name|RELOC_PC10
block|,
comment|/* ? */
name|RELOC_PC22
block|,
comment|/* ? */
name|RELOC_JMP_TBL
block|,
comment|/* ? */
name|RELOC_SEGOFF16
block|,
comment|/* ? */
name|RELOC_GLOB_DAT
block|,
comment|/* ? */
name|RELOC_JMP_SLOT
block|,
comment|/* ? */
name|RELOC_RELATIVE
block|,
comment|/* ? */
block|}
enum|;
end_enum

begin_comment
comment|/*  * SPARC relocation info.  *  * Symbol-relative relocation is done by:  *	1. locating the appropriate symbol  *	2. if defined, adding (value + r_addend), subtracting pc if pc-rel,  *	   and then shifting down 2 or 10 or 13 if necessary.  * The resulting value is then to be stuffed into the appropriate bits  * in the object (the low 22, or the high 30, or ..., etc).  */
end_comment

begin_struct
struct|struct
name|reloc_info_sparc
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

