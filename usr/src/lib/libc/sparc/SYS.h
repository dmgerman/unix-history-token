begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * %sccs.include.redist.c%  *  *	@(#)SYS.h	8.1 (Berkeley) %G%  *  * from: $Header: SYS.h,v 1.2 92/07/03 18:57:00 torek Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PROF
end_ifdef

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
define|\
value|.align 4; .globl _##x; .proc 1; _##x:; .data; .align 4; 1: .long 0; \ 	.text; save %sp,-96,%sp; sethi %hi(1b),%o0; call mcount; \ 	or %o0,%lo(1b),%o0; restore
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
define|\
value|.align 4; .globl _##x; .proc 1; _##x:
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ERROR branches to cerror.  This is done with a macro so that I can  * change it to be position independent later, if need be.  */
end_comment

begin_define
define|#
directive|define
name|ERROR
parameter_list|()
define|\
value|sethi %hi(cerror),%g1; or %lo(cerror),%g1,%g1; jmp %g1; nop
end_define

begin_comment
comment|/*  * SYSCALL is used when further action must be taken before returning.  * Note that it adds a `nop' over what we could do, if we only knew what  * came at label 1....  */
end_comment

begin_define
define|#
directive|define
name|SYSCALL
parameter_list|(
name|x
parameter_list|)
define|\
value|ENTRY(x); mov SYS_##x,%g1; t ST_SYSCALL; bcc 1f; nop; ERROR(); 1:
end_define

begin_comment
comment|/*  * RSYSCALL is used when the system call should just return.  Here  * we use the SYSCALL_G2RFLAG to put the `success' return address in %g2  * and avoid a branch.  */
end_comment

begin_define
define|#
directive|define
name|RSYSCALL
parameter_list|(
name|x
parameter_list|)
define|\
value|ENTRY(x); mov (SYS_##x)|SYSCALL_G2RFLAG,%g1; add %o7,8,%g2; \ 	t ST_SYSCALL; ERROR()
end_define

begin_comment
comment|/*  * PSEUDO(x,y) is like RSYSCALL(y) except that the name is x.  */
end_comment

begin_define
define|#
directive|define
name|PSEUDO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|ENTRY(x); mov (SYS_##y)|SYSCALL_G2RFLAG,%g1; add %o7,8,%g2; \ 	t ST_SYSCALL; ERROR()
end_define

begin_define
define|#
directive|define
name|ASMSTR
value|.asciz
end_define

begin_expr_stmt
operator|.
name|globl
name|cerror
end_expr_stmt

end_unit

