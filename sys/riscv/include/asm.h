begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_comment
comment|/* not lint and not STRIP_FBSDID */
end_comment

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
value|.text; .globl sym; .type sym,@function; .align 4; sym:
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
name|SET_FAULT_HANDLER
parameter_list|(
name|handler
parameter_list|,
name|tmp
parameter_list|)
define|\
value|ld	tmp, PC_CURTHREAD(gp);					\ 	ld	tmp, TD_PCB(tmp);
comment|/* Load the pcb */
value|\ 	sd	handler, PCB_ONFAULT(tmp)
end_define

begin_comment
comment|/* Set the handler */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_ASM_H_ */
end_comment

end_unit

