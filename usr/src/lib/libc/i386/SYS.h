begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.redist.c%  *  *	@(#)SYS.h	5.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<syscall.h>
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
value|.globl _
comment|/**/
value|x; \ 			.data; 1:; .long 0; .text; _
comment|/**/
value|x:	.align 4; \ 			movl $1b,%eax; call mcount
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
value|.globl _
comment|/**/
value|x; .text; .align 4; _
comment|/**/
value|x:
end_define

begin_endif
endif|#
directive|endif
endif|PROF
end_endif

begin_define
define|#
directive|define
name|SYSCALL
parameter_list|(
name|x
parameter_list|)
value|2: jmp cerror; ENTRY(x); lea SYS_
comment|/**/
value|x,%eax; LCALL(7,0); jb 2b
end_define

begin_define
define|#
directive|define
name|PSEUDO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|ENTRY(x); lea SYS_
comment|/**/
value|y, %eax; ; LCALL(7,0)
end_define

begin_define
define|#
directive|define
name|CALL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|call _
comment|/**/
value|y; addl $4*x,%esp
end_define

begin_comment
comment|/* gas fucks up offset -- although we don't currently need it, do for BCS */
end_comment

begin_define
define|#
directive|define
name|LCALL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|.byte 0x9a ; .long y; .word x
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

