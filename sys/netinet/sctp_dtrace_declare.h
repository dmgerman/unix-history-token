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
name|_NETINET_SCTP_DTRACE_DECLARE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_SCTP_DTRACE_DECLARE_H_
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

begin_comment
comment|/* Declare the SCTP provider */
end_comment

begin_expr_stmt
name|SDT_PROVIDER_DECLARE
argument_list|(
name|sctp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The probes we have so far: */
end_comment

begin_comment
comment|/* One to track a net's cwnd */
end_comment

begin_comment
comment|/* initial */
end_comment

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|init
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* update at a ack -- increase */
end_comment

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|ack
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* update at a fast retransmit -- decrease */
end_comment

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|fr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* update at a time-out -- decrease */
end_comment

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|to
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* update at a burst-limit -- decrease */
end_comment

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|bl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* update at a ECN -- decrease */
end_comment

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|ecn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* update at a Packet-Drop -- decrease */
end_comment

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|pd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Rttvar probe declaration */
end_comment

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|rttvar
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sctp
argument_list|,
name|cwnd
argument_list|,
name|net
argument_list|,
name|rttstep
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* One to track an associations rwnd */
end_comment

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sctp
argument_list|,
name|rwnd
argument_list|,
name|assoc
argument_list|,
name|val
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* One to track a net's flight size */
end_comment

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sctp
argument_list|,
name|flightsize
argument_list|,
name|net
argument_list|,
name|val
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* One to track an associations flight size */
end_comment

begin_expr_stmt
name|SDT_PROBE_DECLARE
argument_list|(
name|sctp
argument_list|,
name|flightsize
argument_list|,
name|assoc
argument_list|,
name|val
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

