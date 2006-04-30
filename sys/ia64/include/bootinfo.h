begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1994, 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_struct
struct|struct
name|bootinfo
block|{
name|uint64_t
name|bi_magic
decl_stmt|;
comment|/* BOOTINFO_MAGIC */
define|#
directive|define
name|BOOTINFO_MAGIC
value|0xdeadbeeffeedface
name|uint64_t
name|bi_version
decl_stmt|;
comment|/* version 1 */
name|uint64_t
name|bi_spare
index|[
literal|6
index|]
decl_stmt|;
comment|/* was: name of booted kernel */
name|uint64_t
name|bi_hcdp
decl_stmt|;
comment|/* DIG64 HCDP table */
name|uint64_t
name|bi_fpswa
decl_stmt|;
comment|/* FPSWA interface */
name|uint64_t
name|bi_boothowto
decl_stmt|;
comment|/* value for boothowto */
name|uint64_t
name|bi_systab
decl_stmt|;
comment|/* pa of EFI system table */
name|uint64_t
name|bi_memmap
decl_stmt|;
comment|/* pa of EFI memory map */
name|uint64_t
name|bi_memmap_size
decl_stmt|;
comment|/* size of EFI memory map */
name|uint64_t
name|bi_memdesc_size
decl_stmt|;
comment|/* sizeof EFI memory desc */
name|uint32_t
name|bi_memdesc_version
decl_stmt|;
comment|/* EFI memory desc version */
name|uint32_t
name|bi_spare2
decl_stmt|;
name|uint64_t
name|bi_symtab
decl_stmt|;
comment|/* start of kernel sym table */
name|uint64_t
name|bi_esymtab
decl_stmt|;
comment|/* end of kernel sym table */
name|uint64_t
name|bi_kernend
decl_stmt|;
comment|/* end of kernel space */
name|uint64_t
name|bi_envp
decl_stmt|;
comment|/* environment */
name|uint64_t
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

