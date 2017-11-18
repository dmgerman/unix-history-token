begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-4-Clause  *  * Copyright (c) 2003 Peter Wemm.  * Copyright (c) 1990 Andrew Moore, Talke Studio  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * 	from: @(#) ieeefp.h 	1.0 (Berkeley) 9/23/93  * $FreeBSD$  */
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
comment|/*  * Deprecated historical FPU control interface  *  * IEEE floating point type, constant and function definitions.  * XXX: FP*FLD and FP*OFF are undocumented pollution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CDEFS_H_
end_ifndef

begin_error
error|#
directive|error
error|this file needs sys/cdefs.h as a prerequisite
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Rounding modes.  */
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
comment|/* round down towards minus infinity */
name|FP_RP
block|,
comment|/* round up towards plus infinity */
name|FP_RZ
comment|/* truncate */
block|}
name|fp_rnd_t
typedef|;
end_typedef

begin_comment
comment|/*  * Precision (i.e., rounding precision) modes.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FP_PS
init|=
literal|0
block|,
comment|/* 24 bit (single-precision) */
name|FP_PRS
block|,
comment|/* reserved */
name|FP_PD
block|,
comment|/* 53 bit (double-precision) */
name|FP_PE
comment|/* 64 bit (extended-precision) */
block|}
name|fp_prec_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fp_except_t
value|int
end_define

begin_comment
comment|/*  * Exception bit masks.  */
end_comment

begin_define
define|#
directive|define
name|FP_X_INV
value|0x01
end_define

begin_comment
comment|/* invalid operation */
end_comment

begin_define
define|#
directive|define
name|FP_X_DNML
value|0x02
end_define

begin_comment
comment|/* denormal */
end_comment

begin_define
define|#
directive|define
name|FP_X_DZ
value|0x04
end_define

begin_comment
comment|/* zero divide */
end_comment

begin_define
define|#
directive|define
name|FP_X_OFL
value|0x08
end_define

begin_comment
comment|/* overflow */
end_comment

begin_define
define|#
directive|define
name|FP_X_UFL
value|0x10
end_define

begin_comment
comment|/* underflow */
end_comment

begin_define
define|#
directive|define
name|FP_X_IMP
value|0x20
end_define

begin_comment
comment|/* (im)precision */
end_comment

begin_define
define|#
directive|define
name|FP_X_STK
value|0x40
end_define

begin_comment
comment|/* stack fault */
end_comment

begin_comment
comment|/*  * FPU control word bit-field masks.  */
end_comment

begin_define
define|#
directive|define
name|FP_MSKS_FLD
value|0x3f
end_define

begin_comment
comment|/* exception masks field */
end_comment

begin_define
define|#
directive|define
name|FP_PRC_FLD
value|0x300
end_define

begin_comment
comment|/* precision control field */
end_comment

begin_define
define|#
directive|define
name|FP_RND_FLD
value|0xc00
end_define

begin_comment
comment|/* rounding control field */
end_comment

begin_comment
comment|/*  * FPU status word bit-field masks.  */
end_comment

begin_define
define|#
directive|define
name|FP_STKY_FLD
value|0x3f
end_define

begin_comment
comment|/* sticky flags field */
end_comment

begin_comment
comment|/*  * FPU control word bit-field offsets (shift counts).  */
end_comment

begin_define
define|#
directive|define
name|FP_MSKS_OFF
value|0
end_define

begin_comment
comment|/* exception masks offset */
end_comment

begin_define
define|#
directive|define
name|FP_PRC_OFF
value|8
end_define

begin_comment
comment|/* precision control offset */
end_comment

begin_define
define|#
directive|define
name|FP_RND_OFF
value|10
end_define

begin_comment
comment|/* rounding control offset */
end_comment

begin_comment
comment|/*  * FPU status word bit-field offsets (shift counts).  */
end_comment

begin_define
define|#
directive|define
name|FP_STKY_OFF
value|0
end_define

begin_comment
comment|/* sticky flags offset */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUCLIKE_ASM
end_ifdef

begin_define
define|#
directive|define
name|__fldcw
parameter_list|(
name|addr
parameter_list|)
value|__asm __volatile("fldcw %0" : : "m" (*(addr)))
end_define

begin_define
define|#
directive|define
name|__fldenv
parameter_list|(
name|addr
parameter_list|)
value|__asm __volatile("fldenv %0" : : "m" (*(addr)))
end_define

begin_define
define|#
directive|define
name|__fnclex
parameter_list|()
value|__asm __volatile("fnclex")
end_define

begin_define
define|#
directive|define
name|__fnstcw
parameter_list|(
name|addr
parameter_list|)
value|__asm __volatile("fnstcw %0" : "=m" (*(addr)))
end_define

begin_define
define|#
directive|define
name|__fnstenv
parameter_list|(
name|addr
parameter_list|)
value|__asm __volatile("fnstenv %0" : "=m" (*(addr)))
end_define

begin_define
define|#
directive|define
name|__fnstsw
parameter_list|(
name|addr
parameter_list|)
value|__asm __volatile("fnstsw %0" : "=m" (*(addr)))
end_define

begin_comment
comment|/*  * Load the control word.  Be careful not to trap if there is a currently  * unmasked exception (ones that will become freshly unmasked are not a  * problem).  This case must be handled by a save/restore of the  * environment or even of the full x87 state.  Accessing the environment  * is very inefficient, so only do it when necessary.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|__fnldcw
parameter_list|(
name|unsigned
name|short
name|_cw
parameter_list|,
name|unsigned
name|short
name|_newcw
parameter_list|)
block|{
struct|struct
block|{
name|unsigned
name|_cw
decl_stmt|;
name|unsigned
name|_other
index|[
literal|6
index|]
decl_stmt|;
block|}
name|_env
struct|;
name|unsigned
name|short
name|_sw
decl_stmt|;
if|if
condition|(
operator|(
name|_cw
operator|&
name|FP_MSKS_FLD
operator|)
operator|!=
name|FP_MSKS_FLD
condition|)
block|{
name|__fnstsw
argument_list|(
operator|&
name|_sw
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|_sw
operator|&
operator|~
name|_cw
operator|)
operator|&
name|FP_STKY_FLD
operator|)
operator|!=
literal|0
condition|)
block|{
name|__fnstenv
argument_list|(
operator|&
name|_env
argument_list|)
expr_stmt|;
name|_env
operator|.
name|_cw
operator|=
name|_newcw
expr_stmt|;
name|__fldenv
argument_list|(
operator|&
name|_env
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
name|__fldcw
argument_list|(
operator|&
name|_newcw
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|fp_rnd_t
name|fpgetround
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|short
name|_cw
decl_stmt|;
name|__fnstcw
argument_list|(
operator|&
name|_cw
argument_list|)
expr_stmt|;
return|return
operator|(
call|(
name|fp_rnd_t
call|)
argument_list|(
operator|(
name|_cw
operator|&
name|FP_RND_FLD
operator|)
operator|>>
name|FP_RND_OFF
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|fp_rnd_t
name|fpsetround
parameter_list|(
name|fp_rnd_t
name|_m
parameter_list|)
block|{
name|fp_rnd_t
name|_p
decl_stmt|;
name|unsigned
name|short
name|_cw
decl_stmt|,
name|_newcw
decl_stmt|;
name|__fnstcw
argument_list|(
operator|&
name|_cw
argument_list|)
expr_stmt|;
name|_p
operator|=
call|(
name|fp_rnd_t
call|)
argument_list|(
operator|(
name|_cw
operator|&
name|FP_RND_FLD
operator|)
operator|>>
name|FP_RND_OFF
argument_list|)
expr_stmt|;
name|_newcw
operator|=
name|_cw
operator|&
operator|~
name|FP_RND_FLD
expr_stmt|;
name|_newcw
operator||=
operator|(
name|_m
operator|<<
name|FP_RND_OFF
operator|)
operator|&
name|FP_RND_FLD
expr_stmt|;
name|__fnldcw
argument_list|(
name|_cw
argument_list|,
name|_newcw
argument_list|)
expr_stmt|;
return|return
operator|(
name|_p
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|fp_prec_t
name|fpgetprec
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|short
name|_cw
decl_stmt|;
name|__fnstcw
argument_list|(
operator|&
name|_cw
argument_list|)
expr_stmt|;
return|return
operator|(
call|(
name|fp_prec_t
call|)
argument_list|(
operator|(
name|_cw
operator|&
name|FP_PRC_FLD
operator|)
operator|>>
name|FP_PRC_OFF
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|fp_prec_t
name|fpsetprec
parameter_list|(
name|fp_prec_t
name|_m
parameter_list|)
block|{
name|fp_prec_t
name|_p
decl_stmt|;
name|unsigned
name|short
name|_cw
decl_stmt|,
name|_newcw
decl_stmt|;
name|__fnstcw
argument_list|(
operator|&
name|_cw
argument_list|)
expr_stmt|;
name|_p
operator|=
call|(
name|fp_prec_t
call|)
argument_list|(
operator|(
name|_cw
operator|&
name|FP_PRC_FLD
operator|)
operator|>>
name|FP_PRC_OFF
argument_list|)
expr_stmt|;
name|_newcw
operator|=
name|_cw
operator|&
operator|~
name|FP_PRC_FLD
expr_stmt|;
name|_newcw
operator||=
operator|(
name|_m
operator|<<
name|FP_PRC_OFF
operator|)
operator|&
name|FP_PRC_FLD
expr_stmt|;
name|__fnldcw
argument_list|(
name|_cw
argument_list|,
name|_newcw
argument_list|)
expr_stmt|;
return|return
operator|(
name|_p
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Get or set the exception mask.  * Note that the x87 mask bits are inverted by the API -- a mask bit of 1  * means disable for x87 and SSE, but for fp*mask() it means enable.  */
end_comment

begin_function
specifier|static
name|__inline
name|fp_except_t
name|fpgetmask
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|short
name|_cw
decl_stmt|;
name|__fnstcw
argument_list|(
operator|&
name|_cw
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
operator|~
name|_cw
operator|&
name|FP_MSKS_FLD
operator|)
operator|>>
name|FP_MSKS_OFF
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|fp_except_t
name|fpsetmask
parameter_list|(
name|fp_except_t
name|_m
parameter_list|)
block|{
name|fp_except_t
name|_p
decl_stmt|;
name|unsigned
name|short
name|_cw
decl_stmt|,
name|_newcw
decl_stmt|;
name|__fnstcw
argument_list|(
operator|&
name|_cw
argument_list|)
expr_stmt|;
name|_p
operator|=
operator|(
operator|~
name|_cw
operator|&
name|FP_MSKS_FLD
operator|)
operator|>>
name|FP_MSKS_OFF
expr_stmt|;
name|_newcw
operator|=
name|_cw
operator|&
operator|~
name|FP_MSKS_FLD
expr_stmt|;
name|_newcw
operator||=
operator|(
operator|~
name|_m
operator|<<
name|FP_MSKS_OFF
operator|)
operator|&
name|FP_MSKS_FLD
expr_stmt|;
name|__fnldcw
argument_list|(
name|_cw
argument_list|,
name|_newcw
argument_list|)
expr_stmt|;
return|return
operator|(
name|_p
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|fp_except_t
name|fpgetsticky
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|_ex
decl_stmt|;
name|unsigned
name|short
name|_sw
decl_stmt|;
name|__fnstsw
argument_list|(
operator|&
name|_sw
argument_list|)
expr_stmt|;
name|_ex
operator|=
operator|(
name|_sw
operator|&
name|FP_STKY_FLD
operator|)
operator|>>
name|FP_STKY_OFF
expr_stmt|;
return|return
operator|(
operator|(
name|fp_except_t
operator|)
name|_ex
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|fp_except_t
name|fpresetsticky
parameter_list|(
name|fp_except_t
name|_m
parameter_list|)
block|{
struct|struct
block|{
name|unsigned
name|_cw
decl_stmt|;
name|unsigned
name|_sw
decl_stmt|;
name|unsigned
name|_other
index|[
literal|5
index|]
decl_stmt|;
block|}
name|_env
struct|;
name|fp_except_t
name|_p
decl_stmt|;
name|_m
operator|&=
name|FP_STKY_FLD
operator|>>
name|FP_STKY_OFF
expr_stmt|;
name|_p
operator|=
name|fpgetsticky
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|_p
operator|&
operator|~
name|_m
operator|)
operator|==
name|_p
condition|)
return|return
operator|(
name|_p
operator|)
return|;
if|if
condition|(
operator|(
name|_p
operator|&
operator|~
name|_m
operator|)
operator|==
literal|0
condition|)
block|{
name|__fnclex
argument_list|()
expr_stmt|;
return|return
operator|(
name|_p
operator|)
return|;
block|}
name|__fnstenv
argument_list|(
operator|&
name|_env
argument_list|)
expr_stmt|;
name|_env
operator|.
name|_sw
operator|&=
operator|~
name|_m
expr_stmt|;
name|__fldenv
argument_list|(
operator|&
name|_env
argument_list|)
expr_stmt|;
return|return
operator|(
name|_p
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUCLIKE_ASM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_IEEEFP_H_ */
end_comment

end_unit

