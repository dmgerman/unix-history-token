begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FPU_H_
end_define

begin_comment
comment|/*  * Floating point control register bits.  *  * From Alpha AXP Architecture Reference Manual, Instruction  * Descriptions (I) PP 4-69.   */
end_comment

begin_define
define|#
directive|define
name|FPCR_INVD
value|(1LL<< 49)
end_define

begin_comment
comment|/* Invalid Operation DIsable */
end_comment

begin_define
define|#
directive|define
name|FPCR_DZED
value|(1LL<< 50)
end_define

begin_comment
comment|/* Division by Zero Disable */
end_comment

begin_define
define|#
directive|define
name|FPCR_OVFD
value|(1LL<< 51)
end_define

begin_comment
comment|/* Overflow Disable */
end_comment

begin_define
define|#
directive|define
name|FPCR_INV
value|(1LL<< 52)
end_define

begin_comment
comment|/* Invalid Operation */
end_comment

begin_define
define|#
directive|define
name|FPCR_DZE
value|(1LL<< 53)
end_define

begin_comment
comment|/* Division by Zero */
end_comment

begin_define
define|#
directive|define
name|FPCR_OVF
value|(1LL<< 54)
end_define

begin_comment
comment|/* Overflow */
end_comment

begin_define
define|#
directive|define
name|FPCR_UNF
value|(1LL<< 55)
end_define

begin_comment
comment|/* Underflow */
end_comment

begin_define
define|#
directive|define
name|FPCR_INE
value|(1LL<< 56)
end_define

begin_comment
comment|/* Inexact Result */
end_comment

begin_define
define|#
directive|define
name|FPCR_IOV
value|(1LL<< 57)
end_define

begin_comment
comment|/* Integer Overflow */
end_comment

begin_define
define|#
directive|define
name|FPCR_DYN_CHOPPED
value|(0LL<< 58)
end_define

begin_comment
comment|/* Chopped rounding mode */
end_comment

begin_define
define|#
directive|define
name|FPCR_DYN_MINUS
value|(1LL<< 58)
end_define

begin_comment
comment|/* Minus infinity */
end_comment

begin_define
define|#
directive|define
name|FPCR_DYN_NORMAL
value|(2LL<< 58)
end_define

begin_comment
comment|/* Normal rounding */
end_comment

begin_define
define|#
directive|define
name|FPCR_DYN_PLUS
value|(3LL<< 58)
end_define

begin_comment
comment|/* Plus infinity */
end_comment

begin_define
define|#
directive|define
name|FPCR_DYN_MASK
value|(3LL<< 58)
end_define

begin_comment
comment|/* Rounding mode mask */
end_comment

begin_define
define|#
directive|define
name|FPCR_DYN_SHIFT
value|58
end_define

begin_define
define|#
directive|define
name|FPCR_UNDZ
value|(1LL<< 60)
end_define

begin_comment
comment|/* Underflow to Zero */
end_comment

begin_define
define|#
directive|define
name|FPCR_UNFD
value|(1LL<< 61)
end_define

begin_comment
comment|/* Underflow Disable */
end_comment

begin_define
define|#
directive|define
name|FPCR_INED
value|(1LL<< 62)
end_define

begin_comment
comment|/* Inexact Disable */
end_comment

begin_define
define|#
directive|define
name|FPCR_SUM
value|(1LL<< 63)
end_define

begin_comment
comment|/* Summary Bit */
end_comment

begin_define
define|#
directive|define
name|FPCR_MASK
value|(~0LL<< 49)
end_define

begin_comment
comment|/*  * Exception summary bits.  *  * From Alpha AXP Architecture Reference Manual, DEC OSF/1 Exceptions  * and Interrupts (II-B) PP 5-5.  */
end_comment

begin_define
define|#
directive|define
name|EXCSUM_SWC
value|(1LL<< 0)
end_define

begin_comment
comment|/* Software completion */
end_comment

begin_define
define|#
directive|define
name|EXCSUM_INV
value|(1LL<< 1)
end_define

begin_comment
comment|/* Invalid operation */
end_comment

begin_define
define|#
directive|define
name|EXCSUM_DZE
value|(1LL<< 2)
end_define

begin_comment
comment|/* Division by zero */
end_comment

begin_define
define|#
directive|define
name|EXCSUM_OVF
value|(1LL<< 3)
end_define

begin_comment
comment|/* Overflow */
end_comment

begin_define
define|#
directive|define
name|EXCSUM_UNF
value|(1LL<< 4)
end_define

begin_comment
comment|/* Underflow */
end_comment

begin_define
define|#
directive|define
name|EXCSUM_INE
value|(1LL<< 5)
end_define

begin_comment
comment|/* Inexact result */
end_comment

begin_define
define|#
directive|define
name|EXCSUM_IOV
value|(1LL<< 6)
end_define

begin_comment
comment|/* Integer overflow */
end_comment

begin_comment
comment|/*  * Definitions for IEEE trap enables.  These are implemented in  * software and should be compatible with OSF/1 and Linux.  */
end_comment

begin_comment
comment|/* read/write flags */
end_comment

begin_define
define|#
directive|define
name|IEEE_TRAP_ENABLE_INV
value|(1LL<< 1)
end_define

begin_comment
comment|/* Invalid operation */
end_comment

begin_define
define|#
directive|define
name|IEEE_TRAP_ENABLE_DZE
value|(1LL<< 2)
end_define

begin_comment
comment|/* Division by zero */
end_comment

begin_define
define|#
directive|define
name|IEEE_TRAP_ENABLE_OVF
value|(1LL<< 3)
end_define

begin_comment
comment|/* Overflow */
end_comment

begin_define
define|#
directive|define
name|IEEE_TRAP_ENABLE_UNF
value|(1LL<< 4)
end_define

begin_comment
comment|/* Underflow */
end_comment

begin_define
define|#
directive|define
name|IEEE_TRAP_ENABLE_INE
value|(1LL<< 5)
end_define

begin_comment
comment|/* Inexact result */
end_comment

begin_define
define|#
directive|define
name|IEEE_TRAP_ENABLE_MASK
value|(IEEE_TRAP_ENABLE_INV		\ 				 | IEEE_TRAP_ENABLE_DZE		\ 				 | IEEE_TRAP_ENABLE_OVF		\ 				 | IEEE_TRAP_ENABLE_UNF		\ 				 | IEEE_TRAP_ENABLE_INE)
end_define

begin_comment
comment|/* read only flags */
end_comment

begin_define
define|#
directive|define
name|IEEE_STATUS_INV
value|(1LL<< 17)
end_define

begin_comment
comment|/* Invalid operation */
end_comment

begin_define
define|#
directive|define
name|IEEE_STATUS_DZE
value|(1LL<< 18)
end_define

begin_comment
comment|/* Division by zero */
end_comment

begin_define
define|#
directive|define
name|IEEE_STATUS_OVF
value|(1LL<< 19)
end_define

begin_comment
comment|/* Overflow */
end_comment

begin_define
define|#
directive|define
name|IEEE_STATUS_UNF
value|(1LL<< 20)
end_define

begin_comment
comment|/* Underflow */
end_comment

begin_define
define|#
directive|define
name|IEEE_STATUS_INE
value|(1LL<< 21)
end_define

begin_comment
comment|/* Inexact result */
end_comment

begin_define
define|#
directive|define
name|IEEE_STATUS_MASK
value|(IEEE_STATUS_INV		\ 				 | IEEE_STATUS_DZE		\ 				 | IEEE_STATUS_OVF		\ 				 | IEEE_STATUS_UNF		\ 				 | IEEE_STATUS_INE)
end_define

begin_define
define|#
directive|define
name|IEEE_STATUS_TO_EXCSUM_SHIFT
value|16
end_define

begin_comment
comment|/* convert to excsum */
end_comment

begin_define
define|#
directive|define
name|IEEE_STATUS_TO_FPCR_SHIFT
value|35
end_define

begin_comment
comment|/* convert to fpcr */
end_comment

begin_define
define|#
directive|define
name|IEEE_INHERIT
value|(1LL<< 63)
end_define

begin_comment
comment|/* inherit on fork */
end_comment

begin_comment
comment|/* read and write floating point control register */
end_comment

begin_define
define|#
directive|define
name|GET_FPCR
parameter_list|(
name|x
parameter_list|)
define|\
value|__asm__("trapb"); \ 	__asm__("mf_fpcr %0" : "=f" (x)); \ 	__asm__("trapb")
end_define

begin_define
define|#
directive|define
name|SET_FPCR
parameter_list|(
name|x
parameter_list|)
define|\
value|__asm__("trapb"); \ 	__asm__("mt_fpcr %0" : : "f" (x)); \ 	__asm__("trapb")
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|int
name|fp_software_completion
parameter_list|(
name|u_int64_t
name|regmask
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_FPU_H_ */
end_comment

end_unit

