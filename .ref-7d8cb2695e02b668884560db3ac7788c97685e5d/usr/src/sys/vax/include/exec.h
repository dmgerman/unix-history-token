begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)exec.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* Size of a page in an object file. */
end_comment

begin_define
define|#
directive|define
name|__LDPGSZ
value|1024
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
value|0
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
value|((ex).a_magic == ZMAGIC ? __LDPGSZ : sizeof(struct exec))
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
define|#
directive|define
name|OMAGIC
value|0407
comment|/* old impure format */
define|#
directive|define
name|NMAGIC
value|0410
comment|/* read-only text */
define|#
directive|define
name|ZMAGIC
value|0413
comment|/* demand load format */
name|long
name|a_magic
decl_stmt|;
comment|/* magic number */
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

end_unit

