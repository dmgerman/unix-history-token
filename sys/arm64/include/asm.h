begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Andrew Turner  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ASM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ASM_H_
end_define

begin_undef
undef|#
directive|undef
name|__FBSDID
end_undef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|STRIP_FBSDID
argument_list|)
end_if

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|s
parameter_list|)
value|.ident s
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|s
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_C_LABEL
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|sym
parameter_list|)
define|\
value|.text; .globl sym; .align 2; .type sym,#function; sym:
end_define

begin_define
define|#
directive|define
name|EENTRY
parameter_list|(
name|sym
parameter_list|)
define|\
value|.globl	sym; sym:
end_define

begin_define
define|#
directive|define
name|END
parameter_list|(
name|sym
parameter_list|)
value|.size sym, . - sym
end_define

begin_define
define|#
directive|define
name|EEND
parameter_list|(
name|sym
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WEAK_REFERENCE
parameter_list|(
name|sym
parameter_list|,
name|alias
parameter_list|)
define|\
value|.weak alias;						\ 	.set alias,sym
end_define

begin_define
define|#
directive|define
name|UINT64_C
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PIC
argument_list|)
end_if

begin_define
define|#
directive|define
name|PIC_SYM
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x ## @ ## y
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PIC_SYM
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Sets the trap fault handler. The exception handler will return to the  * address in the handler register on a data abort or the xzr register to  * clear the handler. The tmp parameter should be a register able to hold  * the temporary data.  */
end_comment

begin_define
define|#
directive|define
name|SET_FAULT_HANDLER
parameter_list|(
name|handler
parameter_list|,
name|tmp
parameter_list|)
define|\
value|ldr	tmp, [x18, #PC_CURTHREAD];
comment|/* Load curthread */
value|\ 	ldr	tmp, [tmp, #TD_PCB];
comment|/* Load the pcb */
value|\ 	str	handler, [tmp, #PCB_ONFAULT]
end_define

begin_comment
comment|/* Set the handler */
end_comment

begin_define
define|#
directive|define
name|ENTER_USER_ACCESS
parameter_list|(
name|reg
parameter_list|,
name|tmp
parameter_list|)
define|\
value|ldr	tmp, =has_pan;
comment|/* Get the addr of has_pan */
value|\ 	ldr	reg, [tmp];
comment|/* Read it */
value|\ 	cbz	reg, 997f;
comment|/* If no PAN skip */
value|\ 	.inst	0xd500409f | (0<< 8);
comment|/* Clear PAN */
value|\ 	997:
end_define

begin_define
define|#
directive|define
name|EXIT_USER_ACCESS
parameter_list|(
name|reg
parameter_list|)
define|\
value|cbz	reg, 998f;
comment|/* If no PAN skip */
value|\ 	.inst	0xd500409f | (1<< 8);
comment|/* Set PAN */
value|\ 	998:
end_define

begin_define
define|#
directive|define
name|EXIT_USER_ACCESS_CHECK
parameter_list|(
name|reg
parameter_list|,
name|tmp
parameter_list|)
define|\
value|ldr	tmp, =has_pan;
comment|/* Get the addr of has_pan */
value|\ 	ldr	reg, [tmp];
comment|/* Read it */
value|\ 	cbz	reg, 999f;
comment|/* If no PAN skip */
value|\ 	.inst	0xd500409f | (1<< 8);
comment|/* Set PAN */
value|\ 	999:
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_ASM_H_ */
end_comment

end_unit

