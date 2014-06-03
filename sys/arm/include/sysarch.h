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
file|<machine/armreg.h>
end_include

begin_comment
comment|/*  * The ARM_TP_ADDRESS points to a special purpose page, which is used as local  * store for the ARM per-thread data and Restartable Atomic Sequences support.  * Put it just above the "high" vectors' page.  * The cpu_switch() code assumes ARM_RAS_START is ARM_TP_ADDRESS + 4, and  * ARM_RAS_END is ARM_TP_ADDRESS + 8, so if that ever changes, be sure to  * update the cpu_switch() (and cpu_throw()) code as well.  * In addition, code in arm/include/atomic.h and arm/arm/exception.S  * assumes that ARM_RAS_END is at ARM_RAS_START+4, so be sure to update those  * if ARM_RAS_END moves in relation to ARM_RAS_START (look for occurrences  * of ldr/str rm,[rn, #4]).  */
end_comment

begin_comment
comment|/* ARM_TP_ADDRESS is needed for processors that don't support  * the exclusive-access opcodes introduced with ARMv6K. */
end_comment

begin_comment
comment|/* TODO: #if !defined(_HAVE_ARMv6K_INSTRUCTIONS) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__ARM_ARCH_7__
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__ARM_ARCH_6K__
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__ARM_ARCH_6ZK__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARM_TP_ADDRESS
value|(ARM_VECTORS_HIGH + 0x1000)
end_define

begin_define
define|#
directive|define
name|ARM_RAS_START
value|(ARM_TP_ADDRESS + 4)
end_define

begin_define
define|#
directive|define
name|ARM_RAS_END
value|(ARM_TP_ADDRESS + 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLER__
end_ifndef

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
comment|/* __ASSEMBLER__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ARM_SYSARCH_H_ */
end_comment

end_unit

