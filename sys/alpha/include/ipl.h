begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IPL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IPL_H_
end_define

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_comment
comment|/* for pal inlines */
end_comment

begin_comment
comment|/*  * Software interrupt bit numbers  */
end_comment

begin_define
define|#
directive|define
name|SWI_TTY
value|0
end_define

begin_define
define|#
directive|define
name|SWI_NET
value|1
end_define

begin_define
define|#
directive|define
name|SWI_CAMNET
value|2
end_define

begin_define
define|#
directive|define
name|SWI_CAMBIO
value|3
end_define

begin_define
define|#
directive|define
name|SWI_VM
value|4
end_define

begin_define
define|#
directive|define
name|SWI_CLOCK
value|5
end_define

begin_define
define|#
directive|define
name|SWI_TQ
value|6
end_define

begin_define
define|#
directive|define
name|NSWI
value|32
end_define

begin_define
define|#
directive|define
name|NHWI
value|0
end_define

begin_decl_stmt
specifier|extern
name|u_int32_t
name|ipending
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|getcpl
parameter_list|()
value|(alpha_pal_rdps()& ALPHA_PSL_IPL_MASK)
end_define

begin_define
define|#
directive|define
name|SPLDOWN
parameter_list|(
name|name
parameter_list|,
name|pri
parameter_list|)
define|\ 						\
value|static __inline int name(void)			\ {						\     int s;					\     s = alpha_pal_swpipl(ALPHA_PSL_IPL_##pri);	\     return s;					\ }
end_define

begin_macro
name|SPLDOWN
argument_list|(
argument|splsoftclock
argument_list|,
argument|SOFT
argument_list|)
end_macro

begin_macro
name|SPLDOWN
argument_list|(
argument|splsoft
argument_list|,
argument|SOFT
argument_list|)
end_macro

begin_define
define|#
directive|define
name|SPLUP
parameter_list|(
name|name
parameter_list|,
name|pri
parameter_list|)
define|\ 							\
value|static __inline int name(void)				\ {							\     int cpl = getcpl();					\     if (ALPHA_PSL_IPL_##pri> cpl) {			\ 	int s = alpha_pal_swpipl(ALPHA_PSL_IPL_##pri);	\ 	return s;					\     } else						\ 	return cpl;					\ }
end_define

begin_macro
name|SPLUP
argument_list|(
argument|splsoftcam
argument_list|,
argument|SOFT
argument_list|)
end_macro

begin_macro
name|SPLUP
argument_list|(
argument|splsoftnet
argument_list|,
argument|SOFT
argument_list|)
end_macro

begin_macro
name|SPLUP
argument_list|(
argument|splsoftvm
argument_list|,
argument|SOFT
argument_list|)
end_macro

begin_macro
name|SPLUP
argument_list|(
argument|splsofttq
argument_list|,
argument|SOFT
argument_list|)
end_macro

begin_macro
name|SPLUP
argument_list|(
argument|splnet
argument_list|,
argument|IO
argument_list|)
end_macro

begin_macro
name|SPLUP
argument_list|(
argument|splbio
argument_list|,
argument|IO
argument_list|)
end_macro

begin_macro
name|SPLUP
argument_list|(
argument|splcam
argument_list|,
argument|IO
argument_list|)
end_macro

begin_macro
name|SPLUP
argument_list|(
argument|splimp
argument_list|,
argument|IO
argument_list|)
end_macro

begin_macro
name|SPLUP
argument_list|(
argument|spltty
argument_list|,
argument|IO
argument_list|)
end_macro

begin_macro
name|SPLUP
argument_list|(
argument|splvm
argument_list|,
argument|IO
argument_list|)
end_macro

begin_macro
name|SPLUP
argument_list|(
argument|splclock
argument_list|,
argument|CLOCK
argument_list|)
end_macro

begin_macro
name|SPLUP
argument_list|(
argument|splstatclock
argument_list|,
argument|CLOCK
argument_list|)
end_macro

begin_macro
name|SPLUP
argument_list|(
argument|splhigh
argument_list|,
argument|HIGH
argument_list|)
end_macro

begin_function
specifier|static
name|__inline
name|void
name|spl0
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|ipending
condition|)
name|do_sir
argument_list|()
expr_stmt|;
comment|/* lowers ipl to SOFT */
name|alpha_pal_swpipl
argument_list|(
name|ALPHA_PSL_IPL_0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|splx
parameter_list|(
name|int
name|s
parameter_list|)
block|{
if|if
condition|(
name|s
condition|)
name|alpha_pal_swpipl
argument_list|(
name|s
argument_list|)
expr_stmt|;
else|else
name|spl0
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|setdelayed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setsofttty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setsoftnet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setsoftcamnet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setsoftcambio
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setsoftvm
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setsofttq
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setsoftclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|schedsofttty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|schedsoftnet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|schedsoftcamnet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|schedsoftcambio
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|schedsoftvm
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|schedsofttq
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|schedsoftclock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX bogus */
end_comment

begin_comment
unit|extern		unsigned cpl;
comment|/* current priority level mask */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_MD_VAR_H_ */
end_comment

end_unit

