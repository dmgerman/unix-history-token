begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)exec.h	7.4 (Berkeley) %G%  *  * from: $Header: exec.h,v 1.9 93/04/20 11:14:45 torek Exp $  */
end_comment

begin_comment
comment|/*  * __LDPGSZ is the page size used by the linker and by exec().  * It may be some multiple of the ``normal'' page size, so that, e.g.,  * the same binaries can be run on hardware with different page sizes  * that otherwise use the same instruction set.  It must be no larger  * than CLBYTES (in param.h).  */
end_comment

begin_define
define|#
directive|define
name|__LDPGSZ
value|8192
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
value|((ex).a_magic != ZMAGIC&& (ex).a_magic != NMAGIC&& \ 	    (ex).a_magic != OMAGIC)
end_define

begin_comment
comment|/*  * N_TXTADDR is the address of the first executable instruction: that is,  * the place the pc could begin after an a.out is loaded, in order to run  * the instructions in that a.out.  The pc will actually be set to ex.a_entry  * but this is the first place it could possibly reference.  *  * On the SPARC, binaries begin at __LDPGSZ, i.e., page 1.  */
end_comment

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|ex
parameter_list|)
value|8192
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
value|(N_TXTADDR(ex) + ((ex).a_magic == OMAGIC ? (ex).a_text : \ 	    (((ex).a_text + __LDPGSZ - 1)& ~(__LDPGSZ - 1))))
end_define

begin_comment
comment|/*  * N_TXTOFF is the offset within an a.out file of the first executable  * instruction: that is, the offset in the a.out of the byte that winds  * up at N_TXTADDR.  *  * On the SPARC, the a.out header is included in the executable when running  * a ZMAGIC file (but not for OMAGIC and NMAGIC).  */
end_comment

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|ex
parameter_list|)
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
value|(N_TXTOFF(ex) + ((ex).a_magic != ZMAGIC ? (ex).a_text : \ 	    (((ex).a_text + __LDPGSZ - 1)& ~(__LDPGSZ - 1))))
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
name|u_char
name|a_dynamic
range|:
literal|1
decl_stmt|;
comment|/* dynamically linked */
name|u_char
name|a_toolversion
range|:
literal|7
decl_stmt|;
comment|/* Sun toolset version	XXX */
define|#
directive|define
name|MID_ZERO
value|0
comment|/* unknown - implementation dependent */
define|#
directive|define
name|MID_SUN010
value|1
comment|/* sun 68010/68020 binary */
define|#
directive|define
name|MID_SUN020
value|2
comment|/* sun 68020-only binary */
define|#
directive|define
name|MID_SUN_SPARC
value|3
comment|/* sparc binary */
define|#
directive|define
name|MID_HP200
value|200
comment|/* hp200 (68010) BSD binary */
define|#
directive|define
name|MID_HP300
value|300
comment|/* hp300 (68020+68881) BSD binary */
define|#
directive|define
name|MID_HPUX
value|0x20C
comment|/* hp200/300 HP-UX binary */
define|#
directive|define
name|MID_HPUX800
value|0x20B
comment|/* hp800 HP-UX binary */
name|u_char
name|a_mid
decl_stmt|;
comment|/* machine ID */
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
name|u_short
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

begin_define
define|#
directive|define
name|a_machtype
value|a_mid
end_define

begin_comment
comment|/* SUN compatibility */
end_comment

end_unit

