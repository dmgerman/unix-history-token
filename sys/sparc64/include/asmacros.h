begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ASMACROS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ASMACROS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
operator|.
specifier|register
operator|%
name|g2
operator|,
operator|#
name|ignore
operator|.
expr|register
operator|%
name|g3
operator|,
operator|#
name|ignore
operator|.
expr|register
operator|%
name|g6
operator|,
operator|#
name|ignore
operator|.
expr|register
operator|%
name|g7
operator|,
operator|#
name|ignore
end_expr_stmt

begin_define
define|#
directive|define
name|PCPU
parameter_list|(
name|member
parameter_list|)
value|%g7 + GD_ ## member
end_define

begin_define
define|#
directive|define
name|PCPU_ADDR
parameter_list|(
name|member
parameter_list|,
name|reg
parameter_list|)
value|add %g7, GD_ ## member, reg
end_define

begin_define
define|#
directive|define
name|DEBUGGER
parameter_list|()
value|ta %xcc, 1
end_define

begin_define
define|#
directive|define
name|PANIC
parameter_list|(
name|msg
parameter_list|,
name|reg
parameter_list|)
define|\
value|.sect	.rodata ; \ 9:	.asciz	msg ; \ 	.previous ; \ 	setx	9b, reg, %o0 ; \ 	call	panic ; \ 	 nop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DATA
parameter_list|(
name|name
parameter_list|)
define|\
value|.data ; \ 	.globl	name ; \ 	.type	name, @object ; \ name ## :
end_define

begin_define
define|#
directive|define
name|EMPTY
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|name
parameter_list|)
define|\
value|.text ; \ 	.align	16 ; \ 	.globl	name ; \ 	.type	name, @function ; \ name ## :
end_define

begin_define
define|#
directive|define
name|END
parameter_list|(
name|name
parameter_list|)
define|\
value|.size	name, . - name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASMACROS_H_ */
end_comment

end_unit

