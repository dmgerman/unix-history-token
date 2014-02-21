begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IEEEFP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IEEEFP_H_
end_define

begin_comment
comment|/* Deprecated historical FPU control interface */
end_comment

begin_include
include|#
directive|include
file|<machine/fpu.h>
end_include

begin_typedef
typedef|typedef
name|int
name|fp_except_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FP_X_INV
value|IA64_FPSR_TRAP_VD
end_define

begin_comment
comment|/* invalid operation exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_DZ
value|IA64_FPSR_TRAP_ZD
end_define

begin_comment
comment|/* divide-by-zero exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_OFL
value|IA64_FPSR_TRAP_OD
end_define

begin_comment
comment|/* overflow exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_UFL
value|IA64_FPSR_TRAP_UD
end_define

begin_comment
comment|/* underflow exception */
end_comment

begin_define
define|#
directive|define
name|FP_X_IMP
value|IA64_FPSR_TRAP_ID
end_define

begin_comment
comment|/* imprecise(inexact) exception */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FP_RN
init|=
literal|0
block|,
comment|/* round to nearest */
name|FP_RM
block|,
comment|/* round toward minus infinity */
name|FP_RP
block|,
comment|/* round toward plus infinity */
name|FP_RZ
comment|/* round toward zero */
block|}
name|fp_rnd_t
typedef|;
end_typedef

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|fp_rnd_t
name|fpgetround
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fp_rnd_t
name|fpsetround
parameter_list|(
name|fp_rnd_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fp_except_t
name|fpgetmask
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fp_except_t
name|fpsetmask
parameter_list|(
name|fp_except_t
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_IEEEFP_H_ */
end_comment

end_unit

