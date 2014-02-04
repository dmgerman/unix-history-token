begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2012, by Randall Stewart. All rights reserved.  * Copyright (c) 2008-2012, by Michael Tuexen. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_SCTP_DTRACE_DEFINE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_SCTP_DTRACE_DEFINE_H_
end_define

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/sdt.h>
end_include

begin_expr_stmt
name|SDT_PROVIDER_DEFINE
argument_list|(
name|sctp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/********************************************************/
end_comment

begin_comment
comment|/* Cwnd probe - tracks changes in the congestion window on a netp */
end_comment

begin_comment
comment|/********************************************************/
end_comment

begin_comment
comment|/* Initial */
end_comment

begin_expr_stmt
name|SDT_PROBE_DEFINE5
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|init
argument_list|,
literal|"uint32_t"
argument_list|,
comment|/* The Vtag for this end */
literal|"uint32_t"
argument_list|,
comment|/* 			 * The port number of the local side<< 16 | port number 			 * of remote in network byte order. 			 */
literal|"uintptr_t"
argument_list|,
comment|/* The pointer to the struct sctp_nets * changing */
literal|"int"
argument_list|,
comment|/* The old value of the cwnd */
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The new value of the cwnd */
end_comment

begin_comment
comment|/* ACK-INCREASE */
end_comment

begin_expr_stmt
name|SDT_PROBE_DEFINE5
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|ack
argument_list|,
literal|"uint32_t"
argument_list|,
comment|/* The Vtag for this end */
literal|"uint32_t"
argument_list|,
comment|/* 			 * The port number of the local side<< 16 | port number 			 * of remote in network byte order. 			 */
literal|"uintptr_t"
argument_list|,
comment|/* The pointer to the struct sctp_nets * changing */
literal|"int"
argument_list|,
comment|/* The old value of the cwnd */
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The new value of the cwnd */
end_comment

begin_comment
comment|/* ACK-INCREASE */
end_comment

begin_expr_stmt
name|SDT_PROBE_DEFINE5
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|rttvar
argument_list|,
literal|"uint64_t"
argument_list|,
comment|/* The Vtag<< 32 | localport<< 16 | remoteport */
literal|"uint64_t"
argument_list|,
comment|/* obw | nbw */
literal|"uint64_t"
argument_list|,
comment|/* bwrtt | newrtt */
literal|"uint64_t"
argument_list|,
comment|/* flight */
literal|"uint64_t"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* (cwnd<< 32) | point<< 16 | retval(0/1) */
end_comment

begin_expr_stmt
name|SDT_PROBE_DEFINE5
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|rttstep
argument_list|,
literal|"uint64_t"
argument_list|,
comment|/* The Vtag<< 32 | localport<< 16 | remoteport */
literal|"uint64_t"
argument_list|,
comment|/* obw | nbw */
literal|"uint64_t"
argument_list|,
comment|/* bwrtt | newrtt */
literal|"uint64_t"
argument_list|,
comment|/* flight */
literal|"uint64_t"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* (cwnd<< 32) | point<< 16 | retval(0/1) */
end_comment

begin_comment
comment|/* FastRetransmit-DECREASE */
end_comment

begin_expr_stmt
name|SDT_PROBE_DEFINE5
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|fr
argument_list|,
literal|"uint32_t"
argument_list|,
comment|/* The Vtag for this end */
literal|"uint32_t"
argument_list|,
comment|/* 			 * The port number of the local side<< 16 | port number 			 * of remote in network byte order. 			 */
literal|"uintptr_t"
argument_list|,
comment|/* The pointer to the struct sctp_nets * changing */
literal|"int"
argument_list|,
comment|/* The old value of the cwnd */
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The new value of the cwnd */
end_comment

begin_comment
comment|/* TimeOut-DECREASE */
end_comment

begin_expr_stmt
name|SDT_PROBE_DEFINE5
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|to
argument_list|,
literal|"uint32_t"
argument_list|,
comment|/* The Vtag for this end */
literal|"uint32_t"
argument_list|,
comment|/* 			 * The port number of the local side<< 16 | port number 			 * of remote in network byte order. 			 */
literal|"uintptr_t"
argument_list|,
comment|/* The pointer to the struct sctp_nets * changing */
literal|"int"
argument_list|,
comment|/* The old value of the cwnd */
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The new value of the cwnd */
end_comment

begin_comment
comment|/* BurstLimit-DECREASE */
end_comment

begin_expr_stmt
name|SDT_PROBE_DEFINE5
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|bl
argument_list|,
literal|"uint32_t"
argument_list|,
comment|/* The Vtag for this end */
literal|"uint32_t"
argument_list|,
comment|/* 			 * The port number of the local side<< 16 | port number 			 * of remote in network byte order. 			 */
literal|"uintptr_t"
argument_list|,
comment|/* The pointer to the struct sctp_nets * changing */
literal|"int"
argument_list|,
comment|/* The old value of the cwnd */
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The new value of the cwnd */
end_comment

begin_comment
comment|/* ECN-DECREASE */
end_comment

begin_expr_stmt
name|SDT_PROBE_DEFINE5
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|ecn
argument_list|,
literal|"uint32_t"
argument_list|,
comment|/* The Vtag for this end */
literal|"uint32_t"
argument_list|,
comment|/* 			 * The port number of the local side<< 16 | port number 			 * of remote in network byte order. 			 */
literal|"uintptr_t"
argument_list|,
comment|/* The pointer to the struct sctp_nets * changing */
literal|"int"
argument_list|,
comment|/* The old value of the cwnd */
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The new value of the cwnd */
end_comment

begin_comment
comment|/* PacketDrop-DECREASE */
end_comment

begin_expr_stmt
name|SDT_PROBE_DEFINE5
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|pd
argument_list|,
literal|"uint32_t"
argument_list|,
comment|/* The Vtag for this end */
literal|"uint32_t"
argument_list|,
comment|/* 			 * The port number of the local side<< 16 | port number 			 * of remote in network byte order. 			 */
literal|"uintptr_t"
argument_list|,
comment|/* The pointer to the struct sctp_nets * changing */
literal|"int"
argument_list|,
comment|/* The old value of the cwnd */
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The new value of the cwnd */
end_comment

begin_comment
comment|/********************************************************/
end_comment

begin_comment
comment|/* Rwnd probe - tracks changes in the receiver window for an assoc */
end_comment

begin_comment
comment|/********************************************************/
end_comment

begin_expr_stmt
name|SDT_PROBE_DEFINE4
argument_list|(
name|sctp
argument_list|,
name|rwnd
argument_list|,
name|assoc
argument_list|,
name|val
argument_list|,
literal|"uint32_t"
argument_list|,
comment|/* The Vtag for this end */
literal|"uint32_t"
argument_list|,
comment|/* 			 * The port number of the local side<< 16 | port number 			 * of remote in network byte order. 			 */
literal|"int"
argument_list|,
comment|/* The up/down amount */
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The new value of the cwnd */
end_comment

begin_comment
comment|/********************************************************/
end_comment

begin_comment
comment|/* flight probe - tracks changes in the flight size on a net or assoc */
end_comment

begin_comment
comment|/********************************************************/
end_comment

begin_expr_stmt
name|SDT_PROBE_DEFINE5
argument_list|(
name|sctp
argument_list|,
name|flightsize
argument_list|,
name|net
argument_list|,
name|val
argument_list|,
literal|"uint32_t"
argument_list|,
comment|/* The Vtag for this end */
literal|"uint32_t"
argument_list|,
comment|/* 			 * The port number of the local side<< 16 | port number 			 * of remote in network byte order. 			 */
literal|"uintptr_t"
argument_list|,
comment|/* The pointer to the struct sctp_nets * changing */
literal|"int"
argument_list|,
comment|/* The up/down amount */
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The new value of the cwnd */
end_comment

begin_comment
comment|/********************************************************/
end_comment

begin_comment
comment|/* The total flight version */
end_comment

begin_comment
comment|/********************************************************/
end_comment

begin_expr_stmt
name|SDT_PROBE_DEFINE4
argument_list|(
name|sctp
argument_list|,
name|flightsize
argument_list|,
name|assoc
argument_list|,
name|val
argument_list|,
literal|"uint32_t"
argument_list|,
comment|/* The Vtag for this end */
literal|"uint32_t"
argument_list|,
comment|/* 			 * The port number of the local side<< 16 | port number 			 * of remote in network byte order. 			 */
literal|"int"
argument_list|,
comment|/* The up/down amount */
literal|"int"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The new value of the cwnd */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

