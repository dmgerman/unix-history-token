begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)exec.h	7.3 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_comment
comment|/* Size of a page in an object file. */
end_comment

begin_define
define|#
directive|define
name|__LDPGSZ
value|4096
end_define

begin_comment
comment|/* Valid magic number check. */
end_comment

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|ex
parameter_list|)
define|\
value|((ex).a_magic != NMAGIC&& (ex).a_magic != OMAGIC&& \ 	    (ex).a_magic != ZMAGIC)
end_define

begin_comment
comment|/* Address of the bottom of the text segment. */
end_comment

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|X
parameter_list|)
value|__LDPGSZ
end_define

begin_comment
comment|/* Address of the bottom of the data segment. */
end_comment

begin_define
define|#
directive|define
name|N_DATADDR
parameter_list|(
name|ex
parameter_list|)
define|\
value|(N_TXTADDR(ex) + ((ex).a_magic == OMAGIC ? (ex).a_text \ 	: __LDPGSZ + ((ex).a_text - 1& ~(__LDPGSZ - 1))))
end_define

begin_comment
comment|/* Text segment offset. */
end_comment

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|ex
parameter_list|)
define|\
value|((ex).a_magic == ZMAGIC ? 0 : sizeof(struct exec))
end_define

begin_comment
comment|/* Data segment offset. */
end_comment

begin_define
define|#
directive|define
name|N_DATOFF
parameter_list|(
name|ex
parameter_list|)
define|\
value|(N_TXTOFF(ex) + ((ex).a_magic != ZMAGIC ? (ex).a_text : \ 	__LDPGSZ + ((ex).a_text - 1& ~(__LDPGSZ - 1))))
end_define

begin_comment
comment|/* Symbol table offset. */
end_comment

begin_define
define|#
directive|define
name|N_SYMOFF
parameter_list|(
name|ex
parameter_list|)
define|\
value|(N_TXTOFF(ex) + (ex).a_text + (ex).a_data + (ex).a_trsize + \ 	    (ex).a_drsize)
end_define

begin_comment
comment|/* String table offset. */
end_comment

begin_define
define|#
directive|define
name|N_STROFF
parameter_list|(
name|ex
parameter_list|)
value|(N_SYMOFF(ex) + (ex).a_syms)
end_define

begin_comment
comment|/* Description of the object file header (a.out format). */
end_comment

begin_struct
struct|struct
name|exec
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_short
name|a_mid
decl_stmt|;
comment|/* machine ID */
name|u_short
name|a_magic
decl_stmt|;
comment|/* magic number */
else|#
directive|else
name|u_short
name|a_magic
decl_stmt|;
comment|/* magic number */
name|u_short
name|a_mid
decl_stmt|;
comment|/* machine ID */
endif|#
directive|endif
name|u_long
name|a_text
decl_stmt|;
comment|/* text segment size */
name|u_long
name|a_data
decl_stmt|;
comment|/* initialized data size */
name|u_long
name|a_bss
decl_stmt|;
comment|/* uninitialized data size */
name|u_long
name|a_syms
decl_stmt|;
comment|/* symbol table size */
name|u_long
name|a_entry
decl_stmt|;
comment|/* entry point */
name|u_long
name|a_trsize
decl_stmt|;
comment|/* text relocation size */
name|u_long
name|a_drsize
decl_stmt|;
comment|/* data relocation size */
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
name|MID_SUN_SPARC
value|3
end_define

begin_comment
comment|/* sparc binary */
end_comment

begin_define
define|#
directive|define
name|MID_386
value|100
end_define

begin_comment
comment|/* Intel 80386 binary */
end_comment

begin_define
define|#
directive|define
name|MID_29K
value|101
end_define

begin_comment
comment|/* AMD 29000 binary */
end_comment

begin_define
define|#
directive|define
name|MID_MIPSI
value|151
end_define

begin_comment
comment|/* MIPS R2000/R3000 binary */
end_comment

begin_define
define|#
directive|define
name|MID_MIPSII
value|152
end_define

begin_comment
comment|/* MIPS R4000 binary */
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

