begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2003 David Xu<davidxu@freebsd.org>  * Copyright (c) 2001 Daniel Eischen<deischen@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_KSD_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_struct_decl
struct_decl|struct
name|kse
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Evaluates to the byte offset of the per-kse variable name.  */
end_comment

begin_define
define|#
directive|define
name|__ksd_offset
parameter_list|(
name|name
parameter_list|)
value|__offsetof(struct kse, name)
end_define

begin_comment
comment|/*  * Evaluates to the type of the per-kse variable name.  */
end_comment

begin_define
define|#
directive|define
name|__ksd_type
parameter_list|(
name|name
parameter_list|)
value|__typeof(((struct kse *)0)->name)
end_define

begin_comment
comment|/*  * Evaluates to the value of the per-kse variable name.  */
end_comment

begin_define
define|#
directive|define
name|KSD_GET32
parameter_list|(
name|name
parameter_list|)
value|({					\ 	__ksd_type(name) __result;				\ 								\ 	u_int __i;						\ 	__asm __volatile("movl %%gs:%1, %0"			\ 	    : "=r" (__i)					\ 	    : "m" (*(u_int *)(__ksd_offset(name))));		\ 	__result = *(__ksd_type(name) *)&__i;			\ 								\ 	__result;						\ })
end_define

begin_comment
comment|/*  * Sets the value of the per-cpu variable name to value val.  */
end_comment

begin_define
define|#
directive|define
name|KSD_SET32
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
value|({					\ 	__ksd_type(name) __val = (val);				\ 								\ 	u_int __i;						\ 	__i = *(u_int *)&__val;					\ 	__asm __volatile("movl %1,%%gs:%0"			\ 	    : "=m" (*(u_int *)(__ksd_offset(name)))		\ 	    : "r" (__i));					\ })
end_define

begin_function
specifier|static
name|__inline
name|u_long
name|__ksd_readandclear32
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|addr
parameter_list|)
block|{
name|u_long
name|result
decl_stmt|;
asm|__asm __volatile (
literal|"	xorl	%0, %0;"
literal|"	xchgl	%%gs:%1, %0;"
literal|"# __ksd_readandclear32"
operator|:
literal|"=&r"
operator|(
name|result
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|addr
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|result
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|KSD_READANDCLEAR32
parameter_list|(
name|name
parameter_list|)
value|({				\ 	__ksd_type(name) __result;				\ 								\ 	__result = (__ksd_type(name))				\ 	    __ksd_readandclear32((u_long *)__ksd_offset(name)); \ 	__result;						\ })
end_define

begin_define
define|#
directive|define
name|_ksd_curkse
parameter_list|()
value|((struct kse *)KSD_GET32(k_mbx.km_udata))
end_define

begin_define
define|#
directive|define
name|_ksd_curthread
parameter_list|()
value|KSD_GET32(k_curthread)
end_define

begin_define
define|#
directive|define
name|_ksd_get_tmbx
parameter_list|()
value|KSD_GET32(k_mbx.km_curthread)
end_define

begin_define
define|#
directive|define
name|_ksd_set_tmbx
parameter_list|(
name|value
parameter_list|)
value|KSD_SET32(k_mbx.km_curthread, (void *)value);
end_define

begin_define
define|#
directive|define
name|_ksd_readandclear_tmbx
parameter_list|()
value|KSD_READANDCLEAR32(k_mbx.km_curthread)
end_define

begin_macro
unit|int
name|_ksd_create
argument_list|(
argument|struct ksd *ksd
argument_list|,
argument|void *base
argument_list|,
argument|int size
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|_ksd_destroy
parameter_list|(
name|struct
name|ksd
modifier|*
name|ksd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_ksd_getprivate
parameter_list|(
name|struct
name|ksd
modifier|*
name|ksd
parameter_list|,
name|void
modifier|*
modifier|*
name|base
parameter_list|,
name|int
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_ksd_setprivate
parameter_list|(
name|struct
name|ksd
modifier|*
name|ksd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

