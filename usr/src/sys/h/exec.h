begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)exec.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/*  * Header prepended to each a.out file.  */
end_comment

begin_struct
struct|struct
name|exec
block|{
name|long
name|a_magic
decl_stmt|;
comment|/* magic number */
name|unsigned
name|long
name|a_text
decl_stmt|;
comment|/* size of text segment */
name|unsigned
name|long
name|a_data
decl_stmt|;
comment|/* size of initialized data */
name|unsigned
name|long
name|a_bss
decl_stmt|;
comment|/* size of uninitialized data */
name|unsigned
name|long
name|a_syms
decl_stmt|;
comment|/* size of symbol table */
name|unsigned
name|long
name|a_entry
decl_stmt|;
comment|/* entry point */
name|unsigned
name|long
name|a_trsize
decl_stmt|;
comment|/* size of text relocation */
name|unsigned
name|long
name|a_drsize
decl_stmt|;
comment|/* size of data relocation */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OMAGIC
value|0407
end_define

begin_comment
comment|/* old impure format */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|0410
end_define

begin_comment
comment|/* read-only text */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC
value|0413
end_define

begin_comment
comment|/* demand load format */
end_comment

end_unit

