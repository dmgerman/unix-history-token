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
name|bootinfo_v1
block|{
name|u_long
name|ssym
decl_stmt|;
comment|/* 0: start of kernel sym table	*/
name|u_long
name|esym
decl_stmt|;
comment|/* 8: end of kernel sym table	*/
name|char
name|boot_flags
index|[
literal|64
index|]
decl_stmt|;
comment|/* 16: boot flags		*/
name|char
name|booted_kernel
index|[
literal|64
index|]
decl_stmt|;
comment|/* 80: name of booted kernel	*/
name|void
modifier|*
name|hwrpb
decl_stmt|;
comment|/* 144: hwrpb pointer (BEVA)	*/
name|u_long
name|hwrpbsize
decl_stmt|;
comment|/* 152: size of hwrpb data	*/
name|int
argument_list|(
argument|*cngetc
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* 160: console getc pointer	*/
name|void
argument_list|(
argument|*cnputc
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* 168: console putc pointer	*/
name|void
argument_list|(
argument|*cnpollc
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* 176: console pollc pointer	*/
name|u_long
name|pad
index|[
literal|6
index|]
decl_stmt|;
comment|/* 184: rsvd for future use	*/
name|char
modifier|*
name|envp
decl_stmt|;
comment|/* 232:	start of environment	*/
name|u_long
name|kernend
decl_stmt|;
comment|/* 240: end of kernel		*/
name|u_long
name|modptr
decl_stmt|;
comment|/* 248: FreeBSD module base	*/
comment|/* 256: total size		*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * Kernel-internal structure used to hold important bits of boot  * information.  NOT to be used by boot blocks.  *  * Note that not all of the fields from the bootinfo struct(s)  * passed by the boot blocks aren't here (because they're not currently  * used by the kernel!).  Fields here which aren't supplied by the  * bootinfo structure passed by the boot blocks are supposed to be  * filled in at startup with sane contents.  */
end_comment

begin_struct
struct|struct
name|bootinfo_kernel
block|{
name|u_long
name|ssym
decl_stmt|;
comment|/* start of syms */
name|u_long
name|esym
decl_stmt|;
comment|/* end of syms */
name|u_long
name|modptr
decl_stmt|;
comment|/* FreeBSD module pointer */
name|u_long
name|kernend
decl_stmt|;
comment|/* "end of kernel" from boot code */
name|char
modifier|*
name|envp
decl_stmt|;
comment|/* "end of kernel" from boot code */
name|u_long
name|hwrpb_phys
decl_stmt|;
comment|/* hwrpb physical address */
name|u_long
name|hwrpb_size
decl_stmt|;
comment|/* size of hwrpb data */
name|char
name|boot_flags
index|[
literal|64
index|]
decl_stmt|;
comment|/* boot flags */
name|char
name|booted_kernel
index|[
literal|64
index|]
decl_stmt|;
comment|/* name of booted kernel */
name|char
name|booted_dev
index|[
literal|64
index|]
decl_stmt|;
comment|/* name of booted device */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|bootinfo_kernel
name|bootinfo
decl_stmt|;
end_decl_stmt

end_unit

