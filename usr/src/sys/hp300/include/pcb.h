begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1986, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: pcb.h 1.13 89/04/23$  *  *	@(#)pcb.h	7.1 (Berkeley) %G%  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"frame.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<hp300/frame.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * HP300 process control block  */
end_comment

begin_struct
struct|struct
name|pcb
block|{
name|short
name|pcb_flags
decl_stmt|;
comment|/* misc. process flags (+0) */
name|short
name|pcb_ps
decl_stmt|;
comment|/* processor status word (+2) */
name|int
name|pcb_ustp
decl_stmt|;
comment|/* user segment table pointer (+4) */
name|int
name|pcb_usp
decl_stmt|;
comment|/* user stack pointer (+8) */
name|int
name|pcb_regs
index|[
literal|12
index|]
decl_stmt|;
comment|/* D0-D7, A0-A7 (+C) */
name|struct
name|pte
modifier|*
name|pcb_p0br
decl_stmt|;
comment|/* P0 base register (+3C) */
name|int
name|pcb_p0lr
decl_stmt|;
comment|/* P0 length register (+40) */
name|struct
name|pte
modifier|*
name|pcb_p1br
decl_stmt|;
comment|/* P1 base register (+44) */
name|int
name|pcb_p1lr
decl_stmt|;
comment|/* P1 length register (+48) */
name|int
name|pcb_szpt
decl_stmt|;
comment|/* number of pages of user page table (+4C) */
name|int
name|pcb_cmap2
decl_stmt|;
comment|/* temporary copy PTE (+50) */
name|int
modifier|*
name|pcb_sswap
decl_stmt|;
comment|/* saved context for swap return (+54) */
name|short
name|pcb_sigc
index|[
literal|12
index|]
decl_stmt|;
comment|/* signal trampoline code (+58) */
name|caddr_t
name|pcb_onfault
decl_stmt|;
comment|/* for copyin/out faults (+70) */
name|struct
name|fpframe
name|pcb_fpregs
decl_stmt|;
comment|/* 68881/2 context save area (+74) */
name|int
name|pcb_exec
index|[
literal|16
index|]
decl_stmt|;
comment|/* exec structure for core dumps (+1B8) */
name|int
name|pcb_res
index|[
literal|2
index|]
decl_stmt|;
comment|/* reserved for future expansion (+1F8) */
block|}
struct|;
end_struct

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|PCB_AST
value|0x0001
end_define

begin_comment
comment|/* async trap pending */
end_comment

begin_define
define|#
directive|define
name|PCB_HPUXMMAP
value|0x0010
end_define

begin_comment
comment|/* VA space is multiple mapped */
end_comment

begin_define
define|#
directive|define
name|PCB_HPUXTRACE
value|0x0020
end_define

begin_comment
comment|/* being traced by an HPUX process */
end_comment

begin_define
define|#
directive|define
name|PCB_HPUXBIN
value|0x0040
end_define

begin_comment
comment|/* loaded from an HPUX format binary */
end_comment

begin_comment
comment|/* note: does NOT imply SHPUX */
end_comment

begin_define
define|#
directive|define
name|aston
parameter_list|()
define|\
value|{ \ 		u.u_pcb.pcb_flags |= PCB_AST; \ 	}
end_define

begin_define
define|#
directive|define
name|astoff
parameter_list|()
define|\
value|{ \ 		u.u_pcb.pcb_flags&= ~PCB_AST; \ 	}
end_define

begin_define
define|#
directive|define
name|astpend
parameter_list|()
define|\
value|(u.u_pcb.pcb_flags& PCB_AST)
end_define

end_unit

