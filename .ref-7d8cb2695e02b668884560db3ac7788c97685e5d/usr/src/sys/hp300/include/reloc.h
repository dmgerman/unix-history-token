begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)reloc.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* Relocation format. */
end_comment

begin_struct
struct|struct
name|relocation_info
block|{
name|int
name|r_address
decl_stmt|;
comment|/* offset in text or data segment */
name|unsigned
name|int
name|r_symbolnum
range|:
literal|24
decl_stmt|,
comment|/* ordinal number of add symbol */
name|r_pcrel
range|:
literal|1
decl_stmt|,
comment|/* 1 if value should be pc-relative */
name|r_length
range|:
literal|2
decl_stmt|,
comment|/* log base 2 of value's width */
name|r_extern
range|:
literal|1
decl_stmt|,
comment|/* 1 if need to add symbol to value */
range|:
literal|4
decl_stmt|;
comment|/* reserved */
block|}
struct|;
end_struct

end_unit

