begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * The boot program passes a pointer (in the boot environment virtual  * address address space; "BEVA") to a bootinfo to the kernel using  * the following convention:  *  *	a0 contains first free page frame number  *	a1 contains page number of current level 1 page table  *	if a2 contains BOOTINFO_MAGIC and a4 is nonzero:  *		a3 contains pointer (BEVA) to bootinfo  *		a4 contains bootinfo version number  *	if a2 contains BOOTINFO_MAGIC and a4 contains 0 (backward compat):  *		a3 contains pointer (BEVA) to bootinfo version  *		    (u_long), then the bootinfo  */
end_comment

begin_define
define|#
directive|define
name|BOOTINFO_MAGIC
value|0xdeadbeeffeedface
end_define

begin_struct
struct|struct
name|bootinfo
block|{
name|u_int64_t
name|bi_magic
decl_stmt|;
comment|/* BOOTINFO_MAGIC */
name|u_int64_t
name|bi_version
decl_stmt|;
comment|/* version 1 */
name|u_int64_t
name|bi_spare
index|[
literal|8
index|]
decl_stmt|;
comment|/* was: name of booted kernel */
name|u_int64_t
name|bi_boothowto
decl_stmt|;
comment|/* value for boothowto */
name|u_int64_t
name|bi_systab
decl_stmt|;
comment|/* pa of EFI system table */
name|u_int64_t
name|bi_memmap
decl_stmt|;
comment|/* pa of EFI memory map */
name|u_int64_t
name|bi_memmap_size
decl_stmt|;
comment|/* size of EFI memory map */
name|u_int64_t
name|bi_memdesc_size
decl_stmt|;
comment|/* sizeof EFI memory desc */
name|u_int32_t
name|bi_memdesc_version
decl_stmt|;
comment|/* EFI memory desc version */
name|u_int64_t
name|bi_symtab
decl_stmt|;
comment|/* start of kernel sym table */
name|u_int64_t
name|bi_esymtab
decl_stmt|;
comment|/* end of kernel sym table */
name|u_int64_t
name|bi_kernend
decl_stmt|;
comment|/* end of kernel space */
name|u_int64_t
name|bi_envp
decl_stmt|;
comment|/* environment */
name|u_int64_t
name|bi_modulep
decl_stmt|;
comment|/* preloaded modules */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|bootinfo
name|bootinfo
decl_stmt|;
end_decl_stmt

end_unit

