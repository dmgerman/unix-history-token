begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2010  * 	Swinburne University of Technology, Melbourne, Australia  * Copyright (c) 2010 Lawrence Stewart<lstewart@freebsd.org>  * All rights reserved.  *  * This software was developed at the Centre for Advanced Internet  * Architectures, Swinburne University of Technology, by David Hayes, made  * possible in part by a grant from the Cisco University Research Program Fund  * at Community Foundation Silicon Valley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * The ERTT (Enhanced Round Trip Time) Khelp module calculates an estimate of  * the instantaneous TCP RTT which, for example, is used by delay-based  * congestion control schemes. When the module is loaded, ERTT data is  * calculated for each active TCP connection and encapsulated within a  * "struct ertt".  *  * This software was first released in 2010 by David Hayes and Lawrence Stewart  * whilst working on the NewTCP research project at Swinburne University of  * Technology's Centre for Advanced Internet Architectures, Melbourne,  * Australia, which was made possible in part by a grant from the Cisco  * University Research Program Fund at Community Foundation Silicon Valley.  * Testing and development was further assisted by a grant from the FreeBSD  * Foundation. More details are available at:  *   http://caia.swin.edu.au/urp/newtcp/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_KHELP_H_ERTT_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_KHELP_H_ERTT_
end_define

begin_struct_decl
struct_decl|struct
name|txseginfo
struct_decl|;
end_struct_decl

begin_comment
comment|/* Structure used as the ertt data block. */
end_comment

begin_struct
struct|struct
name|ertt
block|{
comment|/* Information about transmitted segments to aid in RTT calculation. */
name|TAILQ_HEAD
argument_list|(
argument|txseginfo_head
argument_list|,
argument|txseginfo
argument_list|)
name|txsegi_q
expr_stmt|;
comment|/* Bytes TX so far in marked RTT. */
name|long
name|bytes_tx_in_rtt
decl_stmt|;
comment|/* Final version of above. */
name|long
name|bytes_tx_in_marked_rtt
decl_stmt|;
comment|/* cwnd for marked RTT. */
name|unsigned
name|long
name|marked_snd_cwnd
decl_stmt|;
comment|/* Per-packet measured RTT. */
name|int
name|rtt
decl_stmt|;
comment|/* Maximum RTT measured. */
name|int
name|maxrtt
decl_stmt|;
comment|/* Minimum RTT measured. */
name|int
name|minrtt
decl_stmt|;
comment|/* Guess if the receiver is using delayed ack. */
name|int
name|dlyack_rx
decl_stmt|;
comment|/* Keep track of inconsistencies in packet timestamps. */
name|int
name|timestamp_errors
decl_stmt|;
comment|/* RTT for a marked packet. */
name|int
name|markedpkt_rtt
decl_stmt|;
comment|/* Flags to signal conditions between hook function calls. */
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flags for struct ertt. */
end_comment

begin_define
define|#
directive|define
name|ERTT_NEW_MEASUREMENT
value|0x01
end_define

begin_define
define|#
directive|define
name|ERTT_MEASUREMENT_IN_PROGRESS
value|0x02
end_define

begin_define
define|#
directive|define
name|ERTT_TSO_DISABLED
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_KHELP_H_ERTT_ */
end_comment

end_unit

