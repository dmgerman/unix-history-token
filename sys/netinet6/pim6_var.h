begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$KAME: pim6_var.h,v 1.8 2000/06/06 08:07:43 jinmei Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Protocol Independent Multicast (PIM),  * implementation-specific definitions.  *  * Written by George Edmond Eddy (Rusty), ISI, February 1998  * Modified by Pavlin Ivanov Radoslavov, USC/ISI, May 1998  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_PIM6_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_PIM6_VAR_H_
end_define

begin_struct
struct|struct
name|pim6stat
block|{
name|uint64_t
name|pim6s_rcv_total
decl_stmt|;
comment|/* total PIM messages received	*/
name|uint64_t
name|pim6s_rcv_tooshort
decl_stmt|;
comment|/* received with too few bytes	*/
name|uint64_t
name|pim6s_rcv_badsum
decl_stmt|;
comment|/* received with bad checksum	*/
name|uint64_t
name|pim6s_rcv_badversion
decl_stmt|;
comment|/* received bad PIM version	*/
name|uint64_t
name|pim6s_rcv_registers
decl_stmt|;
comment|/* received registers		*/
name|uint64_t
name|pim6s_rcv_badregisters
decl_stmt|;
comment|/* received invalid registers	*/
name|uint64_t
name|pim6s_snd_registers
decl_stmt|;
comment|/* sent registers		*/
block|}
struct|;
end_struct

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|)
end_if

begin_function_decl
name|int
name|pim6_input
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/*  * Identifiers for PIM sysctl nodes  */
end_comment

begin_define
define|#
directive|define
name|PIM6CTL_STATS
value|1
end_define

begin_comment
comment|/* statistics (read-only) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET6_PIM6_VAR_H_ */
end_comment

end_unit

