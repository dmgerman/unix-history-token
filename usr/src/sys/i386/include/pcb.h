begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.redist.c%  *  *	@(#)pcb.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Intel 386 process control block  */
end_comment

begin_include
include|#
directive|include
file|<machine/tss.h>
end_include

begin_include
include|#
directive|include
file|<machine/npx.h>
end_include

begin_struct
struct|struct
name|pcb
block|{
name|struct
name|i386tss
name|pcb_tss
decl_stmt|;
define|#
directive|define
name|pcb_ksp
value|pcb_tss.tss_esp0
define|#
directive|define
name|pcb_ptd
value|pcb_tss.tss_cr3
define|#
directive|define
name|pcb_cr3
value|pcb_ptd
define|#
directive|define
name|pcb_pc
value|pcb_tss.tss_eip
define|#
directive|define
name|pcb_psl
value|pcb_tss.tss_eflags
define|#
directive|define
name|pcb_usp
value|pcb_tss.tss_esp
define|#
directive|define
name|pcb_fp
value|pcb_tss.tss_ebp
ifdef|#
directive|ifdef
name|notyet
name|u_char
name|pcb_iomap
index|[
name|NPORT
operator|/
sizeof|sizeof
argument_list|(
name|u_char
argument_list|)
index|]
decl_stmt|;
comment|/* i/o port bitmap */
endif|#
directive|endif
name|struct
name|save87
name|pcb_savefpu
decl_stmt|;
comment|/* floating point state for 287/387 */
name|struct
name|emcsts
name|pcb_saveemc
decl_stmt|;
comment|/* Cyrix EMC state */
comment|/*  * Software pcb (extension)  */
name|int
name|pcb_flags
decl_stmt|;
define|#
directive|define
name|FP_WASUSED
value|0x01
comment|/* floating point has been used in this proc */
define|#
directive|define
name|FP_NEEDSSAVE
value|0x02
comment|/* needs save on next context switch */
define|#
directive|define
name|FP_NEEDSRESTORE
value|0x04
comment|/* need restore on next DNA fault */
define|#
directive|define
name|FP_USESEMC
value|0x08
comment|/* process uses EMC memory-mapped mode */
define|#
directive|define
name|FM_TRAP
value|0x10
comment|/* process entered kernel on a trap frame */
name|short
name|pcb_iml
decl_stmt|;
comment|/* interrupt mask level */
name|caddr_t
name|pcb_onfault
decl_stmt|;
comment|/* copyin/out fault recovery */
name|long
name|pcb_sigc
index|[
literal|8
index|]
decl_stmt|;
comment|/* XXX signal code trampoline */
name|int
name|pcb_cmap2
decl_stmt|;
comment|/* XXX temporary PTE - will prefault instead */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The pcb is augmented with machine-dependent additional data for  * core dumps. For the i386: ???  */
end_comment

begin_struct
struct|struct
name|md_coredump
block|{
name|int
name|pad
decl_stmt|;
comment|/* XXX? -- cgd */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|pcb
modifier|*
name|curpcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* our current running pcb */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

