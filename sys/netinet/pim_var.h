begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998-2000  * University of Southern California/Information Sciences Institute.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_PIM_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_PIM_VAR_H_
end_define

begin_comment
comment|/*  * Protocol Independent Multicast (PIM),  * kernel variables and implementation-specific definitions.  *  * Written by George Edmond Eddy (Rusty), ISI, February 1998.  * Modified by Pavlin Radoslavov, USC/ISI, May 1998, Aug 1999, October 2000.  * Modified by Hitoshi Asaeda, WIDE, August 1998.  */
end_comment

begin_comment
comment|/*  * PIM statistics kept in the kernel  */
end_comment

begin_struct
struct|struct
name|pimstat
block|{
name|uint64_t
name|pims_rcv_total_msgs
decl_stmt|;
comment|/* total PIM messages received    */
name|uint64_t
name|pims_rcv_total_bytes
decl_stmt|;
comment|/* total PIM bytes received	     */
name|uint64_t
name|pims_rcv_tooshort
decl_stmt|;
comment|/* rcvd with too few bytes	     */
name|uint64_t
name|pims_rcv_badsum
decl_stmt|;
comment|/* rcvd with bad checksum	     */
name|uint64_t
name|pims_rcv_badversion
decl_stmt|;
comment|/* rcvd bad PIM version	     */
name|uint64_t
name|pims_rcv_registers_msgs
decl_stmt|;
comment|/* rcvd regs. msgs (data only)    */
name|uint64_t
name|pims_rcv_registers_bytes
decl_stmt|;
comment|/* rcvd regs. bytes (data only)   */
name|uint64_t
name|pims_rcv_registers_wrongiif
decl_stmt|;
comment|/* rcvd regs. on wrong iif     */
name|uint64_t
name|pims_rcv_badregisters
decl_stmt|;
comment|/* rcvd invalid registers	     */
name|uint64_t
name|pims_snd_registers_msgs
decl_stmt|;
comment|/* sent regs. msgs (data only)    */
name|uint64_t
name|pims_snd_registers_bytes
decl_stmt|;
comment|/* sent regs. bytes (data only)   */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|PIMSTAT_ADD
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
define|\
value|VNET_PCPUSTAT_ADD(struct pimstat, pimstat, name, (val))
end_define

begin_define
define|#
directive|define
name|PIMSTAT_INC
parameter_list|(
name|name
parameter_list|)
value|PIMSTAT_ADD(name, 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Identifiers for PIM sysctl nodes  */
end_comment

begin_define
define|#
directive|define
name|PIMCTL_STATS
value|1
end_define

begin_comment
comment|/* statistics (read-only) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|pim_input
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

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_pim
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_PIM_VAR_H_ */
end_comment

end_unit

