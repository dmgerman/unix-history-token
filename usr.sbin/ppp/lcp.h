begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: lcp.h,v 1.16.2.23 1998/05/01 19:24:57 brian Exp $  *  *	TODO:  */
end_comment

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
comment|/* Peers LQR frequency */
name|u_short
name|his_auth
decl_stmt|;
comment|/* Peer wants this type of authentication */
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
comment|/* Our LQR frequency */
name|u_short
name|want_auth
decl_stmt|;
comment|/* We want this type of authentication */
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
name|u_int32_t
name|accmap
decl_stmt|;
comment|/* Initial ACCMAP value */
name|int
name|openmode
decl_stmt|;
comment|/* when to start CFG REQs */
name|u_int
name|lqrperiod
decl_stmt|;
comment|/* LQR frequency */
name|u_int
name|fsmretry
decl_stmt|;
comment|/* FSM retry frequency */
name|unsigned
name|acfcomp
range|:
literal|2
decl_stmt|;
comment|/* Address& Control Field Compression neg */
name|unsigned
name|chap
range|:
literal|2
decl_stmt|;
comment|/* Challenge Handshake Authentication proto */
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
value|CODE_DISCREQ
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

begin_define
define|#
directive|define
name|MAX_LCP_OPT_LEN
value|10
end_define

begin_struct
struct|struct
name|lcp_opt
block|{
name|u_char
name|id
decl_stmt|;
name|u_char
name|len
decl_stmt|;
name|u_char
name|data
index|[
name|MAX_LCP_OPT_LEN
operator|-
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INC_LCP_OPT
parameter_list|(
name|ty
parameter_list|,
name|length
parameter_list|,
name|o
parameter_list|)
define|\
value|do {                                                \     (o)->id = (ty);                                   \     (o)->len = (length);                              \     (o) = (struct lcp_opt *)((char *)(o) + (length)); \   } while (0)
end_define

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
name|physical
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
name|void
name|lcp_Input
parameter_list|(
name|struct
name|lcp
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

