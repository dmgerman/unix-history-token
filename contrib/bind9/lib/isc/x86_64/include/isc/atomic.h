begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2005  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: atomic.h,v 1.2.20.1 2005/09/02 13:27:12 marka Exp $ */
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
comment|/* We share the gcc-version with x86_32 */
end_comment

begin_error
error|#
directive|error
literal|"impossible case.  check build configuration"
end_error

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ISC_PLATFORM_USESTDASM
argument_list|)
end_elif

begin_comment
comment|/*  * The followings are "generic" assembly code which implements the same  * functionality in case the gcc extension cannot be used.  It should be  * better to avoid inlining below, since we directly refer to specific  * registers for arguments, which would not actually correspond to the  * intended address or value in the embedded mnemonic.  */
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
literal|"movq %rdi, %rdx\n"
literal|"movl %esi, %eax\n"
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USETHREADS
literal|"lock;"
endif|#
directive|endif
literal|"xadd %eax, (%rdx)\n"
comment|/* 		 * set the return value directly in the register so that we 		 * can avoid guessing the correct position in the stack for a 		 * local variable. 		 */
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
literal|"movq %rdi, %rax\n"
literal|"movl %esi, %edx\n"
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USETHREADS
literal|"lock;"
endif|#
directive|endif
literal|"xchgl (%rax), %edx\n"
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
literal|"movl %edx, %ecx\n"
literal|"movl %esi, %eax\n"
literal|"movq %rdi, %rdx\n"
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USETHREADS
literal|"lock;"
endif|#
directive|endif
comment|/* 		 * If (%rdi) == %eax then (%rdi) := %edx. 		 % %eax is set to old (%ecx), which will be the return value. 		 */
literal|"cmpxchgl %ecx, (%rdx)"
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

