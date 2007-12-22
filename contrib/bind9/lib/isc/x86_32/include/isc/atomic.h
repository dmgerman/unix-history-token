begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2005  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: atomic.h,v 1.2.2.3 2005/07/27 04:23:33 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_ATOMIC_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_ATOMIC_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USEGCCASM
end_ifdef

begin_comment
comment|/*  * This routine atomically increments the value stored in 'p' by 'val', and  * returns the previous value.  */
end_comment

begin_function
specifier|static
specifier|inline
name|isc_int32_t
name|isc_atomic_xadd
parameter_list|(
name|isc_int32_t
modifier|*
name|p
parameter_list|,
name|isc_int32_t
name|val
parameter_list|)
block|{
name|isc_int32_t
name|prev
init|=
name|val
decl_stmt|;
asm|__asm__
specifier|volatile
asm|(
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USETHREADS
asm|"lock;"
endif|#
directive|endif
asm|"xadd %0, %1" 		:"=q"(prev) 		:"m"(*p), "0"(prev) 		:"memory", "cc");
return|return
operator|(
name|prev
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * This routine atomically stores the value 'val' in 'p'.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|isc_atomic_store
parameter_list|(
name|isc_int32_t
modifier|*
name|p
parameter_list|,
name|isc_int32_t
name|val
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|(
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USETHREADS
comment|/* 		 * xchg should automatically lock memory, but we add it 		 * explicitly just in case (it at least doesn't harm) 		 */
asm|"lock;"
endif|#
directive|endif
asm|"xchgl %1, %0" 		: 		: "r"(val), "m"(*p) 		: "memory");
block|}
end_function

begin_comment
comment|/*  * This routine atomically replaces the value in 'p' with 'val', if the  * original value is equal to 'cmpval'.  The original value is returned in any  * case.  */
end_comment

begin_function
specifier|static
specifier|inline
name|isc_int32_t
name|isc_atomic_cmpxchg
parameter_list|(
name|isc_int32_t
modifier|*
name|p
parameter_list|,
name|isc_int32_t
name|cmpval
parameter_list|,
name|isc_int32_t
name|val
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|(
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USETHREADS
asm|"lock;"
endif|#
directive|endif
asm|"cmpxchgl %1, %2" 		: "=a"(cmpval) 		: "r"(val), "m"(*p), "a"(cmpval) 		: "memory");
return|return
operator|(
name|cmpval
operator|)
return|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ISC_PLATFORM_USESTDASM
argument_list|)
end_elif

begin_comment
comment|/*  * The followings are "generic" assembly code which implements the same  * functionality in case the gcc extension cannot be used.  It should be  * better to avoid inlining below, since we directly refer to specific  * positions of the stack frame, which would not actually point to the  * intended address in the embedded mnemonic.  */
end_comment

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_comment
comment|/* for 'UNUSED' macro */
end_comment

begin_function
specifier|static
name|isc_int32_t
name|isc_atomic_xadd
parameter_list|(
name|isc_int32_t
modifier|*
name|p
parameter_list|,
name|isc_int32_t
name|val
parameter_list|)
block|{
name|UNUSED
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|UNUSED
argument_list|(
name|val
argument_list|)
expr_stmt|;
asm|__asm (
literal|"movl 8(%ebp), %ecx\n"
literal|"movl 12(%ebp), %edx\n"
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USETHREADS
literal|"lock;"
endif|#
directive|endif
literal|"xadd %edx, (%ecx)\n"
comment|/* 		 * set the return value directly in the register so that we 		 * can avoid guessing the correct position in the stack for a 		 * local variable. 		 */
literal|"movl %edx, %eax"
block|)
function|;
end_function

begin_function
unit|}  static
name|void
name|isc_atomic_store
parameter_list|(
name|isc_int32_t
modifier|*
name|p
parameter_list|,
name|isc_int32_t
name|val
parameter_list|)
block|{
name|UNUSED
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|UNUSED
argument_list|(
name|val
argument_list|)
expr_stmt|;
asm|__asm (
literal|"movl 8(%ebp), %ecx\n"
literal|"movl 12(%ebp), %edx\n"
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USETHREADS
literal|"lock;"
endif|#
directive|endif
literal|"xchgl (%ecx), %edx\n"
block|)
function|;
end_function

begin_function
unit|}  static
name|isc_int32_t
name|isc_atomic_cmpxchg
parameter_list|(
name|isc_int32_t
modifier|*
name|p
parameter_list|,
name|isc_int32_t
name|cmpval
parameter_list|,
name|isc_int32_t
name|val
parameter_list|)
block|{
name|UNUSED
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|UNUSED
argument_list|(
name|cmpval
argument_list|)
expr_stmt|;
name|UNUSED
argument_list|(
name|val
argument_list|)
expr_stmt|;
asm|__asm (
literal|"movl 8(%ebp), %ecx\n"
literal|"movl 12(%ebp), %eax\n"
comment|/* must be %eax for cmpxchgl */
literal|"movl 16(%ebp), %edx\n"
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USETHREADS
literal|"lock;"
endif|#
directive|endif
comment|/* 		 * If (%ecx) == %eax then (%ecx) := %edx. 		 % %eax is set to old (%ecx), which will be the return value. 		 */
literal|"cmpxchgl %edx, (%ecx)"
block|)
function|;
end_function

begin_else
unit|}
else|#
directive|else
end_else

begin_comment
comment|/* !ISC_PLATFORM_USEGCCASM&& !ISC_PLATFORM_USESTDASM */
end_comment

begin_error
error|#
directive|error
literal|"unsupported compiler.  disable atomic ops by --disable-atomic"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_ATOMIC_H */
end_comment

end_unit

