begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: sysarch.h,v 1.5 2003/09/11 09:40:12 kleink Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996-1997 Mark Brinicombe.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Mark Brinicombe.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_SYSARCH_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM_SYSARCH_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * Pickup definition of uintptr_t  */
end_comment

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_comment
comment|/*  * Architecture specific syscalls (arm)  */
end_comment

begin_define
define|#
directive|define
name|ARM_SYNC_ICACHE
value|0
end_define

begin_define
define|#
directive|define
name|ARM_DRAIN_WRITEBUF
value|1
end_define

begin_define
define|#
directive|define
name|ARM_SET_TP
value|2
end_define

begin_define
define|#
directive|define
name|ARM_GET_TP
value|3
end_define

begin_define
define|#
directive|define
name|ARM_TP_ADDRESS
value|0xe0000000
end_define

begin_comment
comment|/* Magic */
end_comment

begin_struct
struct|struct
name|arm_sync_icache_args
block|{
name|uintptr_t
name|addr
decl_stmt|;
comment|/* Virtual start address */
name|size_t
name|len
decl_stmt|;
comment|/* Region size */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|__BEGIN_DECLS
name|int
name|arm_sync_icache
parameter_list|(
name|u_int
name|addr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|arm_drain_writebuf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sysarch
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ARM_SYSARCH_H_ */
end_comment

end_unit

