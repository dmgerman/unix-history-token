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

begin_comment
comment|/*  * Normal and alternate %g6 point to the pcb of the current process.  Normal,& alternate and interrupt %g7 point to per-cpu data.  */
end_comment

begin_define
define|#
directive|define
name|PCB_REG
value|%g6
end_define

begin_define
define|#
directive|define
name|PCPU_REG
value|%g7
end_define

begin_comment
comment|/*  * Alternate %g5 points to a per-cpu panic stack, which is used as a last  * resort, and for temporarily saving alternate globals.  */
end_comment

begin_define
define|#
directive|define
name|ASP_REG
value|%g5
end_define

begin_comment
comment|/*  * MMU %g7 points to the user tsb.  */
end_comment

begin_define
define|#
directive|define
name|TSB_REG
value|%g7
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_comment
comment|/*  * Atomically decrement an integer in memory.  */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_DEC_INT
parameter_list|(
name|r1
parameter_list|,
name|r2
parameter_list|,
name|r3
parameter_list|)
define|\
value|lduw	[r1], r2 ; \ 9:	sub	r2, 1, r3 ; \ 	casa	[r1] ASI_N, r2, r3 ; \ 	cmp	r2, r3 ; \ 	bne,pn	%icc, 9b ; \ 	 mov	r3, r2
end_define

begin_comment
comment|/*  * Atomically increment an integer in memory.  */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_INC_INT
parameter_list|(
name|r1
parameter_list|,
name|r2
parameter_list|,
name|r3
parameter_list|)
define|\
value|lduw	[r1], r2 ; \ 9:	add	r2, 1, r3 ; \ 	casa	[r1] ASI_N, r2, r3 ; \ 	cmp	r2, r3 ; \ 	bne,pn	%icc, 9b ; \ 	 mov	r3, r2
end_define

begin_comment
comment|/*  * Atomically clear a number of bits of an integer in memory.  */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_CLEAR_INT
parameter_list|(
name|r1
parameter_list|,
name|r2
parameter_list|,
name|r3
parameter_list|,
name|bits
parameter_list|)
define|\
value|lduw	[r1], r2 ; \ 9:	andn	r2, bits, r3 ; \ 	casa	[r1] ASI_N, r2, r3 ; \ 	cmp	r2, r3 ; \ 	bne,pn	%icc, 9b ; \ 	 mov	r3, r2
end_define

begin_define
define|#
directive|define
name|PCPU
parameter_list|(
name|member
parameter_list|)
value|%g7 + PC_ ## member
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
value|add %g7, PC_ ## member, reg
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
name|r1
parameter_list|)
define|\
value|.sect	.rodata ; \ 9:	.asciz	msg ; \ 	.previous ; \ 	SET(9b, r1, %o0) ; \ 	call	panic ; \ 	 nop
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|KASSERT
parameter_list|(
name|r1
parameter_list|,
name|msg
parameter_list|)
define|\
value|brnz	r1, 8f ; \ 	 nop ; \ 	PANIC(msg, r1) ; \ 8:
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KASSERT
parameter_list|(
name|r1
parameter_list|,
name|msg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PUTS
parameter_list|(
name|msg
parameter_list|,
name|r1
parameter_list|)
define|\
value|.sect	.rodata ; \ 9:	.asciz	msg ; \ 	.previous ; \ 	SET(9b, r1, %o0) ; \ 	call	printf ; \ 	 nop
end_define

begin_comment
comment|/*  * If the kernel can be located above 4G, setx needs to be used to load  * symbol values, otherwise set is sufficient.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HIGH_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|SET
parameter_list|(
name|sym
parameter_list|,
name|tmp
parameter_list|,
name|dst
parameter_list|)
define|\
value|setx	sym, tmp, dst
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SET
parameter_list|(
name|sym
parameter_list|,
name|tmp
parameter_list|,
name|dst
parameter_list|)
define|\
value|set	sym, dst
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
comment|/* LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASMACROS_H_ */
end_comment

end_unit

