begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)exec.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Header prepended to each a.out file.  */
end_comment

begin_struct
struct|struct
name|exec
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|vax
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|tahoe
argument_list|)
name|unsigned
name|short
name|a_mid
decl_stmt|;
comment|/* machine ID */
name|unsigned
name|short
name|a_magic
decl_stmt|;
comment|/* magic number */
else|#
directive|else
name|long
name|a_magic
decl_stmt|;
comment|/* magic number */
endif|#
directive|endif
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
name|a_machtype
value|a_mid
end_define

begin_comment
comment|/* SUN compatibility */
end_comment

begin_comment
comment|/* a_magic */
end_comment

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

begin_comment
comment|/* a_mid */
end_comment

begin_define
define|#
directive|define
name|MID_ZERO
value|0
end_define

begin_comment
comment|/* unknown - implementation dependent */
end_comment

begin_define
define|#
directive|define
name|MID_SUN010
value|1
end_define

begin_comment
comment|/* sun 68010/68020 binary */
end_comment

begin_define
define|#
directive|define
name|MID_SUN020
value|2
end_define

begin_comment
comment|/* sun 68020-only binary */
end_comment

begin_define
define|#
directive|define
name|MID_HP200
value|200
end_define

begin_comment
comment|/* hp200 (68010) BSD binary */
end_comment

begin_define
define|#
directive|define
name|MID_HP300
value|300
end_define

begin_comment
comment|/* hp300 (68020+68881) BSD binary */
end_comment

begin_define
define|#
directive|define
name|MID_HPUX
value|0x20C
end_define

begin_comment
comment|/* hp200/300 HP-UX binary */
end_comment

begin_define
define|#
directive|define
name|MID_HPUX800
value|0x20B
end_define

begin_comment
comment|/* hp800 HP-UX binary */
end_comment

end_unit

