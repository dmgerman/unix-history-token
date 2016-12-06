begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Andrew Turner  * Copyright (c) 2014-2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Andrew Turner under  * sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SETJMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SETJMP_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * We need to store:  *  - A magic value to differentiate the buffers  *  - The stack pointer  *  - The link register  *  - 11 general purpose registers  *  - 8 floating point registers  *  - The signal mask (128 bits)  * i.e. 24 64-bit words, round this up to 31(+1) 128-bit words to allow for  * CPU extensions with larger registers and stronger alignment requirements.  *  * The registers to save are: r19 to r29, and d8 to d15.  */
end_comment

begin_define
define|#
directive|define
name|_JBLEN
value|31
end_define

begin_define
define|#
directive|define
name|_JB_SIGMASK
value|22
end_define

begin_comment
comment|/* This should only be needed in libc and may change */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ASSEMBLER__
end_ifdef

begin_define
define|#
directive|define
name|_JB_MAGIC__SETJMP
value|0xfb5d25837d7ff700
end_define

begin_define
define|#
directive|define
name|_JB_MAGIC_SETJMP
value|0xfb5d25837d7ff701
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLER__
end_ifndef

begin_comment
comment|/*  * jmp_buf and sigjmp_buf are encapsulated in different structs to force  * compile-time diagnostics for mismatches.  The structs are the same  * internally to avoid some run-time errors for mismatches.  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
operator|||
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

begin_typedef
typedef|typedef
struct|struct
name|_sigjmp_buf
block|{
name|__int128_t
name|_sjb
index|[
name|_JBLEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|sigjmp_buf
index|[
literal|1
index|]
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_jmp_buf
block|{
name|__int128_t
name|_jb
index|[
name|_JBLEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|jmp_buf
index|[
literal|1
index|]
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASSEMBLER__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SETJMP_H_ */
end_comment

end_unit

