begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)reg.h	7.4 (Berkeley) %G%  *  * from: $Header: reg.h,v 1.8 92/11/26 02:04:44 torek Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_REG_H_
end_define

begin_comment
comment|/*  * Registers passed to trap/syscall/etc.  * This structure is known to occupy exactly 80 bytes (see locore.s).  * Note, tf_global[0] is not actually written (since g0 is always 0).  * (The slot tf_global[0] is used to send a copy of %wim to kernel gdb.  * This is known as `cheating'.)  */
end_comment

begin_struct
struct|struct
name|trapframe
block|{
name|int
name|tf_psr
decl_stmt|;
comment|/* psr */
name|int
name|tf_pc
decl_stmt|;
comment|/* return pc */
name|int
name|tf_npc
decl_stmt|;
comment|/* return npc */
name|int
name|tf_y
decl_stmt|;
comment|/* %y register */
name|int
name|tf_global
index|[
literal|8
index|]
decl_stmt|;
comment|/* global registers in trap's caller */
name|int
name|tf_out
index|[
literal|8
index|]
decl_stmt|;
comment|/* output registers in trap's caller */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Register windows.  Each stack pointer (%o6 aka %sp) in each window  * must ALWAYS point to some place at which it is safe to scribble on  * 64 bytes.  (If not, your process gets mangled.)  Furthermore, each  * stack pointer should be aligned on an 8-byte boundary (the kernel  * as currently coded allows arbitrary alignment, but with a hefty  * performance penalty).  */
end_comment

begin_struct
struct|struct
name|rwindow
block|{
name|int
name|rw_local
index|[
literal|8
index|]
decl_stmt|;
comment|/* %l0..%l7 */
name|int
name|rw_in
index|[
literal|8
index|]
decl_stmt|;
comment|/* %i0..%i7 */
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<machine/fsr.h>
end_include

begin_comment
comment|/*  * FP coprocessor registers.  *  * FP_QSIZE is the maximum coprocessor instruction queue depth  * of any implementation on which the kernel will run.  David Hough:  * ``I'd suggest allowing 16 ... allowing an indeterminate variable  * size would be even better''.  Of course, we cannot do that; we  * need to malloc these.  */
end_comment

begin_define
define|#
directive|define
name|FP_QSIZE
value|16
end_define

begin_struct
struct|struct
name|fp_qentry
block|{
name|int
modifier|*
name|fq_addr
decl_stmt|;
comment|/* the instruction's address */
name|int
name|fq_instr
decl_stmt|;
comment|/* the instruction itself */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpstate
block|{
name|u_int
name|fs_regs
index|[
literal|32
index|]
decl_stmt|;
comment|/* our view is 32 32-bit registers */
name|int
name|fs_fsr
decl_stmt|;
comment|/* %fsr */
name|int
name|fs_qsize
decl_stmt|;
comment|/* actual queue depth */
name|struct
name|fp_qentry
name|fs_queue
index|[
name|FP_QSIZE
index|]
decl_stmt|;
comment|/* queue contents */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_REG_H_ */
end_comment

end_unit

