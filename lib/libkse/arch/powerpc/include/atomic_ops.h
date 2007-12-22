begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2004 by Peter Grehan. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATOMIC_OPS_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATOMIC_OPS_H_
end_define

begin_comment
comment|/*  * Atomic swap:  *   Atomic (tmp = *dst, *dst = val), then *res = tmp  *  * void atomic_swap32(intptr_t *dst, intptr_t val, intptr_t *res);  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|atomic_swap32
parameter_list|(
name|intptr_t
modifier|*
name|dst
parameter_list|,
name|intptr_t
name|val
parameter_list|,
name|intptr_t
modifier|*
name|res
parameter_list|)
block|{
name|int
name|tmp
decl_stmt|;
name|tmp
operator|=
literal|0
expr_stmt|;
comment|/* should be a better way to quieten cc1... */
ifdef|#
directive|ifdef
name|__GNUC__
asm|__asm __volatile(
literal|"1:	lwarx	%0, 0, %4\n"
comment|/* load with reservation */
literal|"	stwcx.	%3, 0, %4\n"
comment|/* attempt to store val */
literal|"	bne- 1b\n"
comment|/* interrupted? retry */
literal|"	stw	%0, %1\n"
comment|/* else, *dst -> *res */
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|res
operator|)
operator|,
literal|"+m"
operator|(
operator|*
name|dst
operator|)
operator|:
literal|"r"
operator|(
name|val
operator|)
operator|,
literal|"r"
operator|(
name|dst
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_define
unit|}
define|#
directive|define
name|atomic_swap_ptr
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|,
name|r
parameter_list|)
define|\
value|atomic_swap32((intptr_t *)d, (intptr_t)v, (intptr_t *)r)
end_define

begin_define
define|#
directive|define
name|atomic_swap_int
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|,
name|r
parameter_list|)
define|\
value|atomic_swap32((intptr_t *)d, (intptr_t)v, (intptr_t *)r)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

