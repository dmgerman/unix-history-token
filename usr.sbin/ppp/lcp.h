begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 - 2001 Brian Somers<brian@Awfulhak.org>  *          based on work by Toshiharu OHNO<tony-o@iij.ad.jp>  *                           Internet Initiative Japan, Inc (IIJ)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* callback::opmask values */
end_comment

begin_define
define|#
directive|define
name|CALLBACK_AUTH
value|(0)
end_define

begin_define
define|#
directive|define
name|CALLBACK_DIALSTRING
value|(1)
end_define

begin_comment
comment|/* Don't do this */
end_comment

begin_define
define|#
directive|define
name|CALLBACK_LOCATION
value|(2)
end_define

begin_comment
comment|/* Don't do this */
end_comment

begin_define
define|#
directive|define
name|CALLBACK_E164
value|(3)
end_define

begin_define
define|#
directive|define
name|CALLBACK_NAME
value|(4)
end_define

begin_comment
comment|/* Don't do this */
end_comment

begin_define
define|#
directive|define
name|CALLBACK_CBCP
value|(6)
end_define

begin_define
define|#
directive|define
name|CALLBACK_NONE
value|(14)
end_define

begin_comment
comment|/* No callback is ok */
end_comment

begin_define
define|#
directive|define
name|CALLBACK_BIT
parameter_list|(
name|n
parameter_list|)
value|((n)< 0 ? 0 : 1<< (n))
end_define

begin_struct
struct|struct
name|callback
block|{
name|int
name|opmask
decl_stmt|;
comment|/* want these types of callback */
name|char
name|msg
index|[
name|SCRIPT_LEN
index|]
decl_stmt|;
comment|/* with this data (E.164) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|REJECTED
parameter_list|(
name|p
parameter_list|,
name|x
parameter_list|)
value|((p)->his_reject& (1<<(x)))
end_define

begin_struct
struct|struct
name|lcp
block|{
name|struct
name|fsm
name|fsm
decl_stmt|;
comment|/* The finite state machine */
name|u_int16_t
name|his_mru
decl_stmt|;
comment|/* Peers maximum packet size */
name|u_int16_t
name|his_mrru
decl_stmt|;
comment|/* Peers maximum reassembled packet size (MP) */
name|u_int32_t
name|his_accmap
decl_stmt|;
comment|/* Peeers async char control map */
name|u_int32_t
name|his_magic
decl_stmt|;
comment|/* Peers magic number */
name|u_int32_t
name|his_lqrperiod
decl_stmt|;
comment|/* Peers LQR frequency (100ths of seconds) */
name|u_short
name|his_auth
decl_stmt|;
comment|/* Peer wants this type of authentication */
name|u_char
name|his_authtype
decl_stmt|;
comment|/* Fifth octet of REQ/NAK/REJ */
name|struct
name|callback
name|his_callback
decl_stmt|;
comment|/* Peer wants callback ? */
name|unsigned
name|his_shortseq
range|:
literal|1
decl_stmt|;
comment|/* Peer would like only 12bit seqs (MP) */
name|unsigned
name|his_protocomp
range|:
literal|1
decl_stmt|;
comment|/* Does peer do Protocol field compression */
name|unsigned
name|his_acfcomp
range|:
literal|1
decl_stmt|;
comment|/* Does peer do addr& cntrl fld compression */
name|unsigned
name|mru_req
range|:
literal|1
decl_stmt|;
comment|/* Has the peer requested an MRU */
name|u_short
name|want_mru
decl_stmt|;
comment|/* Our maximum packet size */
name|u_short
name|want_mrru
decl_stmt|;
comment|/* Our maximum reassembled packet size (MP) */
name|u_int32_t
name|want_accmap
decl_stmt|;
comment|/* Our async char control map */
name|u_int32_t
name|want_magic
decl_stmt|;
comment|/* Our magic number */
name|u_int32_t
name|want_lqrperiod
decl_stmt|;
comment|/* Our LQR frequency (100ths of seconds) */
name|u_short
name|want_auth
decl_stmt|;
comment|/* We want this type of authentication */
name|u_char
name|want_authtype
decl_stmt|;
comment|/* Fifth octet of REQ/NAK/REJ */
name|struct
name|callback
name|want_callback
decl_stmt|;
comment|/* We want callback ? */
name|unsigned
name|want_shortseq
range|:
literal|1
decl_stmt|;
comment|/* I'd like only 12bit seqs (MP) */
name|unsigned
name|want_protocomp
range|:
literal|1
decl_stmt|;
comment|/* Do we do protocol field compression */
name|unsigned
name|want_acfcomp
range|:
literal|1
decl_stmt|;
comment|/* Do we do addr& cntrl fld compression */
name|u_int32_t
name|his_reject
decl_stmt|;
comment|/* Request codes rejected by peer */
name|u_int32_t
name|my_reject
decl_stmt|;
comment|/* Request codes I have rejected */
name|u_short
name|auth_iwait
decl_stmt|;
comment|/* I must authenticate to the peer */
name|u_short
name|auth_ineed
decl_stmt|;
comment|/* I require that the peer authenticates */
name|int
name|LcpFailedMagic
decl_stmt|;
comment|/* Number of `magic is same' errors */
struct|struct
block|{
name|u_short
name|mru
decl_stmt|;
comment|/* Preferred MRU value */
name|u_short
name|max_mru
decl_stmt|;
comment|/* Preferred MRU value */
name|u_short
name|mtu
decl_stmt|;
comment|/* Preferred MTU */
name|u_short
name|max_mtu
decl_stmt|;
comment|/* Preferred MTU */
name|u_int32_t
name|accmap
decl_stmt|;
comment|/* Initial ACCMAP value */
name|int
name|openmode
decl_stmt|;
comment|/* when to start CFG REQs */
name|u_int32_t
name|lqrperiod
decl_stmt|;
comment|/* LQR frequency (seconds) */
name|struct
name|fsm_retry
name|fsm
decl_stmt|;
comment|/* How often/frequently to resend requests */
name|unsigned
name|acfcomp
range|:
literal|2
decl_stmt|;
comment|/* Address& Control Field Compression neg */
name|unsigned
name|chap05
range|:
literal|2
decl_stmt|;
comment|/* Challenge Handshake Authentication proto */
ifndef|#
directive|ifndef
name|NODES
name|unsigned
name|chap80nt
range|:
literal|2
decl_stmt|;
comment|/* Microsoft (NT) CHAP */
name|unsigned
name|chap80lm
range|:
literal|2
decl_stmt|;
comment|/* Microsoft (LANMan) CHAP */
name|unsigned
name|chap81
range|:
literal|2
decl_stmt|;
comment|/* Microsoft CHAP v2 */
endif|#
directive|endif
name|unsigned
name|lqr
range|:
literal|2
decl_stmt|;
comment|/* Link Quality Report */
name|unsigned
name|pap
range|:
literal|2
decl_stmt|;
comment|/* Password Authentication protocol */
name|unsigned
name|protocomp
range|:
literal|2
decl_stmt|;
comment|/* Protocol field compression */
name|char
name|ident
index|[
name|DEF_MRU
operator|-
literal|7
index|]
decl_stmt|;
comment|/* SendIdentification() data */
block|}
name|cfg
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LCP_MAXCODE
value|CODE_IDENT
end_define

begin_define
define|#
directive|define
name|LCP_MINMPCODE
value|CODE_CODEREJ
end_define

begin_define
define|#
directive|define
name|TY_MRU
value|1
end_define

begin_comment
comment|/* Maximum-Receive-Unit */
end_comment

begin_define
define|#
directive|define
name|TY_ACCMAP
value|2
end_define

begin_comment
comment|/* Async-Control-Character-Map */
end_comment

begin_define
define|#
directive|define
name|TY_AUTHPROTO
value|3
end_define

begin_comment
comment|/* Authentication-Protocol */
end_comment

begin_define
define|#
directive|define
name|TY_QUALPROTO
value|4
end_define

begin_comment
comment|/* Quality-Protocol */
end_comment

begin_define
define|#
directive|define
name|TY_MAGICNUM
value|5
end_define

begin_comment
comment|/* Magic-Number */
end_comment

begin_define
define|#
directive|define
name|TY_RESERVED
value|6
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|TY_PROTOCOMP
value|7
end_define

begin_comment
comment|/* Protocol-Field-Compression */
end_comment

begin_define
define|#
directive|define
name|TY_ACFCOMP
value|8
end_define

begin_comment
comment|/* Address-and-Control-Field-Compression */
end_comment

begin_define
define|#
directive|define
name|TY_FCSALT
value|9
end_define

begin_comment
comment|/* FCS-Alternatives */
end_comment

begin_define
define|#
directive|define
name|TY_SDP
value|10
end_define

begin_comment
comment|/* Self-Describing-Padding */
end_comment

begin_define
define|#
directive|define
name|TY_CALLBACK
value|13
end_define

begin_comment
comment|/* Callback */
end_comment

begin_define
define|#
directive|define
name|TY_CFRAMES
value|15
end_define

begin_comment
comment|/* Compound-frames */
end_comment

begin_define
define|#
directive|define
name|TY_MRRU
value|17
end_define

begin_comment
comment|/* Max Reconstructed Receive Unit (MP) */
end_comment

begin_define
define|#
directive|define
name|TY_SHORTSEQ
value|18
end_define

begin_comment
comment|/* Want short seqs (12bit) please (see mp.h) */
end_comment

begin_define
define|#
directive|define
name|TY_ENDDISC
value|19
end_define

begin_comment
comment|/* Endpoint discriminator */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|link
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cmdargs
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|fsm2lcp
parameter_list|(
name|fp
parameter_list|)
value|(fp->proto == PROTO_LCP ? (struct lcp *)fp : NULL)
end_define

begin_function_decl
specifier|extern
name|void
name|lcp_Init
parameter_list|(
name|struct
name|lcp
modifier|*
parameter_list|,
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|,
specifier|const
name|struct
name|fsm_parent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lcp_Setup
parameter_list|(
name|struct
name|lcp
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lcp_SendProtoRej
parameter_list|(
name|struct
name|lcp
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lcp_SendIdentification
parameter_list|(
name|struct
name|lcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lcp_RecvIdentification
parameter_list|(
name|struct
name|lcp
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lcp_ReportStatus
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|lcp_Input
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lcp_SetupCallbacks
parameter_list|(
name|struct
name|lcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

