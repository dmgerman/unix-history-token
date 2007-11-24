begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)tss.h	5.4 (Berkeley) 1/18/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TSS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TSS_H_
value|1
end_define

begin_comment
comment|/*  * amd64 Context Data Type  *  * The alignment is pretty messed up here due to reuse of the original 32 bit  * fields.  It might be worth trying to set the tss on a +4 byte offset to  * make the 64 bit fields aligned in practice.  */
end_comment

begin_struct
struct|struct
name|amd64tss
block|{
name|u_int32_t
name|tss_rsvd0
decl_stmt|;
name|u_int64_t
name|tss_rsp0
name|__packed
decl_stmt|;
comment|/* kernel stack pointer ring 0 */
name|u_int64_t
name|tss_rsp1
name|__packed
decl_stmt|;
comment|/* kernel stack pointer ring 1 */
name|u_int64_t
name|tss_rsp2
name|__packed
decl_stmt|;
comment|/* kernel stack pointer ring 2 */
name|u_int32_t
name|tss_rsvd1
decl_stmt|;
name|u_int32_t
name|tss_rsvd2
decl_stmt|;
name|u_int64_t
name|tss_ist1
name|__packed
decl_stmt|;
comment|/* Interrupt stack table 1 */
name|u_int64_t
name|tss_ist2
name|__packed
decl_stmt|;
comment|/* Interrupt stack table 2 */
name|u_int64_t
name|tss_ist3
name|__packed
decl_stmt|;
comment|/* Interrupt stack table 3 */
name|u_int64_t
name|tss_ist4
name|__packed
decl_stmt|;
comment|/* Interrupt stack table 4 */
name|u_int64_t
name|tss_ist5
name|__packed
decl_stmt|;
comment|/* Interrupt stack table 5 */
name|u_int64_t
name|tss_ist6
name|__packed
decl_stmt|;
comment|/* Interrupt stack table 6 */
name|u_int64_t
name|tss_ist7
name|__packed
decl_stmt|;
comment|/* Interrupt stack table 7 */
name|u_int32_t
name|tss_rsvd3
decl_stmt|;
name|u_int32_t
name|tss_rsvd4
decl_stmt|;
name|u_int16_t
name|tss_rsvd5
decl_stmt|;
name|u_int16_t
name|tss_iobase
decl_stmt|;
comment|/* io bitmap offset */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|amd64tss
name|common_tss
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_TSS_H_ */
end_comment

end_unit

