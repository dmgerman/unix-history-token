begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000  * Intel Corporation.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *   *    This product includes software developed by Intel Corporation and  *    its contributors.  *   * 4. Neither the name of Intel Corporation or its contributors may be  *    used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY INTEL CORPORATION AND CONTRIBUTORS ``AS IS''  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL INTEL CORPORATION OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
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

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|JMPBUF_ADDR_OF
parameter_list|(
name|buf
parameter_list|,
name|item
parameter_list|)
value|((unsigned long)((char *)buf + item))
end_define

begin_define
define|#
directive|define
name|J_UNAT
value|0
end_define

begin_define
define|#
directive|define
name|J_NATS
value|0x8
end_define

begin_define
define|#
directive|define
name|J_PFS
value|0x10
end_define

begin_define
define|#
directive|define
name|J_BSP
value|0x18
end_define

begin_define
define|#
directive|define
name|J_RNAT
value|0x20
end_define

begin_define
define|#
directive|define
name|J_PREDS
value|0x28
end_define

begin_define
define|#
directive|define
name|J_LC
value|0x30
end_define

begin_define
define|#
directive|define
name|J_R4
value|0x38
end_define

begin_define
define|#
directive|define
name|J_R5
value|0x40
end_define

begin_define
define|#
directive|define
name|J_R6
value|0x48
end_define

begin_define
define|#
directive|define
name|J_R7
value|0x50
end_define

begin_define
define|#
directive|define
name|J_SP
value|0x58
end_define

begin_define
define|#
directive|define
name|J_F2
value|0x60
end_define

begin_define
define|#
directive|define
name|J_F3
value|0x70
end_define

begin_define
define|#
directive|define
name|J_F4
value|0x80
end_define

begin_define
define|#
directive|define
name|J_F5
value|0x90
end_define

begin_define
define|#
directive|define
name|J_F16
value|0xa0
end_define

begin_define
define|#
directive|define
name|J_F17
value|0xb0
end_define

begin_define
define|#
directive|define
name|J_F18
value|0xc0
end_define

begin_define
define|#
directive|define
name|J_F19
value|0xd0
end_define

begin_define
define|#
directive|define
name|J_F20
value|0xe0
end_define

begin_define
define|#
directive|define
name|J_F21
value|0xf0
end_define

begin_define
define|#
directive|define
name|J_F22
value|0x100
end_define

begin_define
define|#
directive|define
name|J_F23
value|0x110
end_define

begin_define
define|#
directive|define
name|J_F24
value|0x120
end_define

begin_define
define|#
directive|define
name|J_F25
value|0x130
end_define

begin_define
define|#
directive|define
name|J_F26
value|0x140
end_define

begin_define
define|#
directive|define
name|J_F27
value|0x150
end_define

begin_define
define|#
directive|define
name|J_F28
value|0x160
end_define

begin_define
define|#
directive|define
name|J_F29
value|0x170
end_define

begin_define
define|#
directive|define
name|J_F30
value|0x180
end_define

begin_define
define|#
directive|define
name|J_F31
value|0x190
end_define

begin_define
define|#
directive|define
name|J_FPSR
value|0x1a0
end_define

begin_define
define|#
directive|define
name|J_B0
value|0x1a8
end_define

begin_define
define|#
directive|define
name|J_B1
value|0x1b0
end_define

begin_define
define|#
directive|define
name|J_B2
value|0x1b8
end_define

begin_define
define|#
directive|define
name|J_B3
value|0x1c0
end_define

begin_define
define|#
directive|define
name|J_B4
value|0x1c8
end_define

begin_define
define|#
directive|define
name|J_B5
value|0x1d0
end_define

begin_define
define|#
directive|define
name|J_SIGMASK
value|0x1d8
end_define

begin_define
define|#
directive|define
name|J_SIGSET
value|0x1e0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_comment
comment|/*  * We only have 16 bytes left for future use, but it's a nice round,  * but above all large number. Size is in bytes.  */
end_comment

begin_define
define|#
directive|define
name|_JMPBUFSZ
value|0x200
end_define

begin_comment
comment|/*  * XXX this check is wrong, since LOCORE is in the application namespace and  * applications shouldn't be able to affect the implementation.  One workaround  * would be to only check LOCORE if _KERNEL is defined, but unfortunately  * LOCORE is used outside of the kernel.  The best solution would be to rename  * LOCORE to _LOCORE, so that it can be used in userland to safely affect the  * implementation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
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

begin_struct
struct|struct
name|_sigjmp_buf
block|{
name|char
name|_Buffer
index|[
name|_JMPBUFSZ
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|16
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_sigjmp_buf
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

begin_struct
struct|struct
name|_jmp_buf
block|{
name|char
name|_Buffer
index|[
name|_JMPBUFSZ
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|16
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_jmp_buf
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
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SETJMP_H_ */
end_comment

end_unit

