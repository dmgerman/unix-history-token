begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.noredist.c%  *  *	@(#)tss.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Intel 386 Context Data Type  */
end_comment

begin_struct
struct|struct
name|i386tss
block|{
name|int
name|tss_link
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_esp0
decl_stmt|;
comment|/* kernel stack pointer priviledge level 0 */
define|#
directive|define
name|tss_ksp
value|tss_esp0
name|int
name|tss_ss0
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_esp1
decl_stmt|;
comment|/* kernel stack pointer priviledge level 1 */
name|int
name|tss_ss1
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_esp2
decl_stmt|;
comment|/* kernel stack pointer priviledge level 2 */
name|int
name|tss_ss2
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|struct
name|ptd
modifier|*
name|tss_cr3
decl_stmt|;
comment|/* page table directory */
define|#
directive|define
name|tss_ptd
value|tss_cr3
name|int
name|tss_eip
decl_stmt|;
comment|/* program counter */
define|#
directive|define
name|tss_pc
value|tss_eip
name|int
name|tss_eflags
decl_stmt|;
comment|/* program status longword */
define|#
directive|define
name|tss_psl
value|tss_eflags
name|int
name|tss_eax
decl_stmt|;
name|int
name|tss_ecx
decl_stmt|;
name|int
name|tss_edx
decl_stmt|;
name|int
name|tss_ebx
decl_stmt|;
name|int
name|tss_esp
decl_stmt|;
comment|/* user stack pointer */
define|#
directive|define
name|tss_usp
value|tss_esp
name|int
name|tss_ebp
decl_stmt|;
comment|/* user frame pointer */
define|#
directive|define
name|tss_fp
value|tss_ebp
name|int
name|tss_esi
decl_stmt|;
name|int
name|tss_edi
decl_stmt|;
name|int
name|tss_es
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_cs
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_ss
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_ds
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_fs
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_gs
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_ldt
decl_stmt|;
comment|/* actually 16 bits: top 16 bits must be zero */
name|int
name|tss_ioopt
decl_stmt|;
comment|/* options& io offset bitmap: currently zero */
comment|/* XXX unimplemented .. i/o permission bitmap */
block|}
struct|;
end_struct

end_unit

