begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/fsr.h>
end_include

begin_include
include|#
directive|include
file|"fpu_emu.h"
end_include

begin_include
include|#
directive|include
file|"fpu_extern.h"
end_include

begin_define
define|#
directive|define
name|_QP_OP
parameter_list|(
name|op
parameter_list|)
define|\
value|void _Qp_ ## op(u_int *c, u_int *a, u_int *b); \ void \ _Qp_ ## op(u_int *c, u_int *a, u_int *b) \ { \ 	struct fpemu fe; \ 	struct fpn *r; \ 	__asm __volatile("stx %%fsr, %0" : "=m" (fe.fe_fsr) :); \ 	fe.fe_f1.fp_sign = a[0]>> 31; \ 	fe.fe_f1.fp_sticky = 0; \ 	fe.fe_f1.fp_class = __fpu_qtof(&fe.fe_f1, a[0], a[1], a[2], a[3]); \ 	fe.fe_f2.fp_sign = b[0]>> 31; \ 	fe.fe_f2.fp_sticky = 0; \ 	fe.fe_f2.fp_class = __fpu_qtof(&fe.fe_f2, b[0], b[1], b[2], b[3]); \ 	r = __fpu_ ## op(&fe); \ 	c[0] = __fpu_ftoq(&fe, r, c); \ }
end_define

begin_define
define|#
directive|define
name|_QP_TTOQ
parameter_list|(
name|qname
parameter_list|,
name|fname
parameter_list|,
name|ntype
parameter_list|,
name|atype
parameter_list|,
modifier|...
parameter_list|)
define|\
value|void _Qp_ ## qname ## toq(u_int *c, ntype n); \ void \ _Qp_ ## qname ## toq(u_int *c, ntype n) \ { \ 	struct fpemu fe; \ 	atype *a; \ 	__asm __volatile("stx %%fsr, %0" : "=m" (fe.fe_fsr) :); \ 	a = (atype *)&n; \ 	fe.fe_f1.fp_sign = a[0]>> 31; \ 	fe.fe_f1.fp_sticky = 0; \ 	fe.fe_f1.fp_class = __fpu_ ## fname ## tof(&fe.fe_f1, __VA_ARGS__); \ 	c[0] = __fpu_ftoq(&fe,&fe.fe_f1, c); \ }
end_define

begin_define
define|#
directive|define
name|_QP_QTOT
parameter_list|(
name|qname
parameter_list|,
name|fname
parameter_list|,
name|type
parameter_list|,
modifier|...
parameter_list|)
define|\
value|type _Qp_qto ## qname(u_int *c); \ type \ _Qp_qto ## qname(u_int *c) \ { \ 	struct fpemu fe; \ 	u_int *a; \ 	type n; \ 	__asm __volatile("stx %%fsr, %0" : "=m" (fe.fe_fsr) :); \ 	a = (u_int *)&n; \ 	fe.fe_f1.fp_sign = c[0]>> 31; \ 	fe.fe_f1.fp_sticky = 0; \ 	fe.fe_f1.fp_class = __fpu_qtof(&fe.fe_f1, c[0], c[1], c[2], c[3]); \ 	a[0] = __fpu_fto ## fname(&fe,&fe.fe_f1, ## __VA_ARGS__); \ 	return (n); \ }
end_define

begin_define
define|#
directive|define
name|FCC_EQ
parameter_list|(
name|fcc
parameter_list|)
value|((fcc) == FSR_CC_EQ)
end_define

begin_define
define|#
directive|define
name|FCC_GE
parameter_list|(
name|fcc
parameter_list|)
value|((fcc) == FSR_CC_EQ || (fcc) == FSR_CC_GT)
end_define

begin_define
define|#
directive|define
name|FCC_GT
parameter_list|(
name|fcc
parameter_list|)
value|((fcc) == FSR_CC_GT)
end_define

begin_define
define|#
directive|define
name|FCC_LE
parameter_list|(
name|fcc
parameter_list|)
value|((fcc) == FSR_CC_EQ || (fcc) == FSR_CC_LT)
end_define

begin_define
define|#
directive|define
name|FCC_LT
parameter_list|(
name|fcc
parameter_list|)
value|((fcc) == FSR_CC_LT)
end_define

begin_define
define|#
directive|define
name|FCC_NE
parameter_list|(
name|fcc
parameter_list|)
value|((fcc) != FSR_CC_EQ)
end_define

begin_define
define|#
directive|define
name|_QP_CMP
parameter_list|(
name|name
parameter_list|,
name|cmpe
parameter_list|,
name|test
parameter_list|)
define|\
value|int _Qp_f ## name(u_int *a, u_int *b) ; \ int \ _Qp_f ## name(u_int *a, u_int *b) \ { \ 	struct fpemu fe; \ 	struct fpn *r; \ 	__asm __volatile("stx %%fsr, %0" : "=m" (fe.fe_fsr) :); \ 	fe.fe_f1.fp_sign = a[0]>> 31; \ 	fe.fe_f1.fp_sticky = 0; \ 	fe.fe_f1.fp_class = __fpu_qtof(&fe.fe_f1, a[0], a[1], a[2], a[3]); \ 	fe.fe_f2.fp_sign = b[0]>> 31; \ 	fe.fe_f2.fp_sticky = 0; \ 	fe.fe_f2.fp_class = __fpu_qtof(&fe.fe_f2, b[0], b[1], b[2], b[3]); \ 	__fpu_compare(&fe, cmpe, 0); \ 	return (test(FSR_GET_FCC0(fe.fe_fsr))); \ }
end_define

begin_macro
name|_QP_OP
argument_list|(
argument|add
argument_list|)
end_macro

begin_macro
name|_QP_OP
argument_list|(
argument|div
argument_list|)
end_macro

begin_macro
name|_QP_OP
argument_list|(
argument|mul
argument_list|)
end_macro

begin_macro
name|_QP_OP
argument_list|(
argument|sub
argument_list|)
end_macro

begin_macro
name|_QP_TTOQ
argument_list|(
argument|d
argument_list|,
argument|d
argument_list|,
argument|double
argument_list|,
argument|u_int
argument_list|,
argument|a[
literal|0
argument|]
argument_list|,
argument|a[
literal|1
argument|]
argument_list|)
end_macro

begin_macro
name|_QP_TTOQ
argument_list|(
argument|i
argument_list|,
argument|i
argument_list|,
argument|int
argument_list|,
argument|u_int
argument_list|,
argument|a[
literal|0
argument|]
argument_list|)
end_macro

begin_macro
name|_QP_TTOQ
argument_list|(
argument|s
argument_list|,
argument|s
argument_list|,
argument|float
argument_list|,
argument|u_int
argument_list|,
argument|a[
literal|0
argument|]
argument_list|)
end_macro

begin_macro
name|_QP_TTOQ
argument_list|(
argument|x
argument_list|,
argument|x
argument_list|,
argument|long
argument_list|,
argument|u_long
argument_list|,
argument|a[
literal|0
argument|]
argument_list|)
end_macro

begin_macro
name|_QP_TTOQ
argument_list|(
argument|ui
argument_list|,
argument|i
argument_list|,
argument|u_int
argument_list|,
argument|u_int
argument_list|,
argument|a[
literal|0
argument|]
argument_list|)
end_macro

begin_macro
name|_QP_TTOQ
argument_list|(
argument|ux
argument_list|,
argument|x
argument_list|,
argument|u_long
argument_list|,
argument|u_long
argument_list|,
argument|a[
literal|0
argument|]
argument_list|)
end_macro

begin_macro
name|_QP_QTOT
argument_list|(
argument|d
argument_list|,
argument|d
argument_list|,
argument|double
argument_list|,
argument|a
argument_list|)
end_macro

begin_macro
name|_QP_QTOT
argument_list|(
argument|i
argument_list|,
argument|i
argument_list|,
argument|int
argument_list|,	)
end_macro

begin_macro
name|_QP_QTOT
argument_list|(
argument|s
argument_list|,
argument|s
argument_list|,
argument|float
argument_list|,	)
end_macro

begin_macro
name|_QP_QTOT
argument_list|(
argument|x
argument_list|,
argument|x
argument_list|,
argument|long
argument_list|,
argument|a
argument_list|)
end_macro

begin_macro
name|_QP_QTOT
argument_list|(
argument|ui
argument_list|,
argument|i
argument_list|,
argument|u_int
argument_list|,	)
end_macro

begin_macro
name|_QP_QTOT
argument_list|(
argument|ux
argument_list|,
argument|x
argument_list|,
argument|u_long
argument_list|,
argument|a
argument_list|)
end_macro

begin_macro
name|_QP_CMP
argument_list|(
argument|eq
argument_list|,
literal|0
argument_list|,
argument|FCC_EQ
argument_list|)
end_macro

begin_macro
name|_QP_CMP
argument_list|(
argument|ge
argument_list|,
literal|0
argument_list|,
argument|FCC_GE
argument_list|)
end_macro

begin_macro
name|_QP_CMP
argument_list|(
argument|gt
argument_list|,
literal|0
argument_list|,
argument|FCC_GT
argument_list|)
end_macro

begin_macro
name|_QP_CMP
argument_list|(
argument|le
argument_list|,
literal|0
argument_list|,
argument|FCC_LE
argument_list|)
end_macro

begin_macro
name|_QP_CMP
argument_list|(
argument|lt
argument_list|,
literal|0
argument_list|,
argument|FCC_LT
argument_list|)
end_macro

begin_macro
name|_QP_CMP
argument_list|(
argument|ne
argument_list|,
literal|0
argument_list|,
argument|FCC_NE
argument_list|)
end_macro

end_unit

