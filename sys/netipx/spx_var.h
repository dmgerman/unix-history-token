begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Copyright (c) 1995, Mike Mitchell  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)spx_var.h  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPX_SPX_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPX_SPX_VAR_H_
end_define

begin_struct
struct|struct
name|spxstat
block|{
name|long
name|spxs_connattempt
decl_stmt|;
comment|/* connections initiated */
name|long
name|spxs_accepts
decl_stmt|;
comment|/* connections accepted */
name|long
name|spxs_connects
decl_stmt|;
comment|/* connections established */
name|long
name|spxs_drops
decl_stmt|;
comment|/* connections dropped */
name|long
name|spxs_conndrops
decl_stmt|;
comment|/* embryonic connections dropped */
name|long
name|spxs_closed
decl_stmt|;
comment|/* conn. closed (includes drops) */
name|long
name|spxs_segstimed
decl_stmt|;
comment|/* segs where we tried to get rtt */
name|long
name|spxs_rttupdated
decl_stmt|;
comment|/* times we succeeded */
name|long
name|spxs_delack
decl_stmt|;
comment|/* delayed acks sent */
name|long
name|spxs_timeoutdrop
decl_stmt|;
comment|/* conn. dropped in rxmt timeout */
name|long
name|spxs_rexmttimeo
decl_stmt|;
comment|/* retransmit timeouts */
name|long
name|spxs_persisttimeo
decl_stmt|;
comment|/* persist timeouts */
name|long
name|spxs_keeptimeo
decl_stmt|;
comment|/* keepalive timeouts */
name|long
name|spxs_keepprobe
decl_stmt|;
comment|/* keepalive probes sent */
name|long
name|spxs_keepdrops
decl_stmt|;
comment|/* connections dropped in keepalive */
name|long
name|spxs_sndtotal
decl_stmt|;
comment|/* total packets sent */
name|long
name|spxs_sndpack
decl_stmt|;
comment|/* data packets sent */
name|long
name|spxs_sndbyte
decl_stmt|;
comment|/* data bytes sent */
name|long
name|spxs_sndrexmitpack
decl_stmt|;
comment|/* data packets retransmitted */
name|long
name|spxs_sndrexmitbyte
decl_stmt|;
comment|/* data bytes retransmitted */
name|long
name|spxs_sndacks
decl_stmt|;
comment|/* ack-only packets sent */
name|long
name|spxs_sndprobe
decl_stmt|;
comment|/* window probes sent */
name|long
name|spxs_sndurg
decl_stmt|;
comment|/* packets sent with URG only */
name|long
name|spxs_sndwinup
decl_stmt|;
comment|/* window update-only packets sent */
name|long
name|spxs_sndctrl
decl_stmt|;
comment|/* control (SYN|FIN|RST) packets sent */
name|long
name|spxs_sndvoid
decl_stmt|;
comment|/* couldn't find requested packet*/
name|long
name|spxs_rcvtotal
decl_stmt|;
comment|/* total packets received */
name|long
name|spxs_rcvpack
decl_stmt|;
comment|/* packets received in sequence */
name|long
name|spxs_rcvbyte
decl_stmt|;
comment|/* bytes received in sequence */
name|long
name|spxs_rcvbadsum
decl_stmt|;
comment|/* packets received with ccksum errs */
name|long
name|spxs_rcvbadoff
decl_stmt|;
comment|/* packets received with bad offset */
name|long
name|spxs_rcvshort
decl_stmt|;
comment|/* packets received too short */
name|long
name|spxs_rcvduppack
decl_stmt|;
comment|/* duplicate-only packets received */
name|long
name|spxs_rcvdupbyte
decl_stmt|;
comment|/* duplicate-only bytes received */
name|long
name|spxs_rcvpartduppack
decl_stmt|;
comment|/* packets with some duplicate data */
name|long
name|spxs_rcvpartdupbyte
decl_stmt|;
comment|/* dup. bytes in part-dup. packets */
name|long
name|spxs_rcvoopack
decl_stmt|;
comment|/* out-of-order packets received */
name|long
name|spxs_rcvoobyte
decl_stmt|;
comment|/* out-of-order bytes received */
name|long
name|spxs_rcvpackafterwin
decl_stmt|;
comment|/* packets with data after window */
name|long
name|spxs_rcvbyteafterwin
decl_stmt|;
comment|/* bytes rcvd after window */
name|long
name|spxs_rcvafterclose
decl_stmt|;
comment|/* packets rcvd after "close" */
name|long
name|spxs_rcvwinprobe
decl_stmt|;
comment|/* rcvd window probe packets */
name|long
name|spxs_rcvdupack
decl_stmt|;
comment|/* rcvd duplicate acks */
name|long
name|spxs_rcvacktoomuch
decl_stmt|;
comment|/* rcvd acks for unsent data */
name|long
name|spxs_rcvackpack
decl_stmt|;
comment|/* rcvd ack packets */
name|long
name|spxs_rcvackbyte
decl_stmt|;
comment|/* bytes acked by rcvd acks */
name|long
name|spxs_rcvwinupd
decl_stmt|;
comment|/* rcvd window update packets */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|spx_istat
block|{
name|short
name|hdrops
decl_stmt|;
name|short
name|badsum
decl_stmt|;
name|short
name|badlen
decl_stmt|;
name|short
name|slotim
decl_stmt|;
name|short
name|fastim
decl_stmt|;
name|short
name|nonucn
decl_stmt|;
name|short
name|noconn
decl_stmt|;
name|short
name|notme
decl_stmt|;
name|short
name|wrncon
decl_stmt|;
name|short
name|bdreas
decl_stmt|;
name|short
name|gonawy
decl_stmt|;
name|short
name|notyet
decl_stmt|;
name|short
name|lstdup
decl_stmt|;
name|struct
name|spxstat
name|newstats
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SPX_ISSINCR
value|128
end_define

begin_comment
comment|/*  * spx sequence numbers are 16 bit integers operated  * on with modular arithmetic.  These macros can be  * used to compare such integers.  */
end_comment

begin_define
define|#
directive|define
name|SSEQ_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((short)((a)-(b)))< 0)
end_define

begin_define
define|#
directive|define
name|SSEQ_LEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((short)((a)-(b)))<= 0)
end_define

begin_define
define|#
directive|define
name|SSEQ_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((short)((a)-(b)))> 0)
end_define

begin_define
define|#
directive|define
name|SSEQ_GEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((short)((a)-(b)))>= 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETIPX_SPX_VAR_H_ */
end_comment

end_unit

