begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Multicast traceroute related definitions  *  * mtrace.h,v 5.1 1996/12/19 21:31:26 fenner Exp  */
end_comment

begin_comment
comment|/*  * The packet format for a traceroute request.  */
end_comment

begin_struct
struct|struct
name|tr_query
block|{
name|u_int32
name|tr_src
decl_stmt|;
comment|/* traceroute source */
name|u_int32
name|tr_dst
decl_stmt|;
comment|/* traceroute destination */
name|u_int32
name|tr_raddr
decl_stmt|;
comment|/* traceroute response address */
if|#
directive|if
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
operator|&&
operator|(
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|)
struct|struct
block|{
name|u_int
name|qid
range|:
literal|24
decl_stmt|;
comment|/* traceroute query id */
name|u_int
name|ttl
range|:
literal|8
decl_stmt|;
comment|/* traceroute response ttl */
block|}
name|q
struct|;
else|#
directive|else
struct|struct
block|{
name|u_int
name|ttl
range|:
literal|8
decl_stmt|;
comment|/* traceroute response ttl */
name|u_int
name|qid
range|:
literal|24
decl_stmt|;
comment|/* traceroute query id */
block|}
name|q
struct|;
endif|#
directive|endif
comment|/* BYTE_ORDER */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tr_rttl
value|q.ttl
end_define

begin_define
define|#
directive|define
name|tr_qid
value|q.qid
end_define

begin_comment
comment|/*  * Traceroute response format.  A traceroute response has a tr_query at the  * beginning, followed by one tr_resp for each hop taken.  */
end_comment

begin_struct
struct|struct
name|tr_resp
block|{
name|u_int32
name|tr_qarr
decl_stmt|;
comment|/* query arrival time */
name|u_int32
name|tr_inaddr
decl_stmt|;
comment|/* incoming interface address */
name|u_int32
name|tr_outaddr
decl_stmt|;
comment|/* outgoing interface address */
name|u_int32
name|tr_rmtaddr
decl_stmt|;
comment|/* parent address in source tree */
name|u_int32
name|tr_vifin
decl_stmt|;
comment|/* input packet count on interface */
name|u_int32
name|tr_vifout
decl_stmt|;
comment|/* output packet count on interface */
name|u_int32
name|tr_pktcnt
decl_stmt|;
comment|/* total incoming packets for src-grp */
name|u_char
name|tr_rproto
decl_stmt|;
comment|/* routing protocol deployed on router */
name|u_char
name|tr_fttl
decl_stmt|;
comment|/* ttl required to forward on outvif */
name|u_char
name|tr_smask
decl_stmt|;
comment|/* subnet mask for src addr */
name|u_char
name|tr_rflags
decl_stmt|;
comment|/* forwarding error codes */
block|}
struct|;
end_struct

begin_comment
comment|/* defs within mtrace */
end_comment

begin_define
define|#
directive|define
name|QUERY
value|1
end_define

begin_define
define|#
directive|define
name|RESP
value|2
end_define

begin_define
define|#
directive|define
name|QLEN
value|sizeof(struct tr_query)
end_define

begin_define
define|#
directive|define
name|RLEN
value|sizeof(struct tr_resp)
end_define

begin_comment
comment|/* fields for tr_rflags (forwarding error codes) */
end_comment

begin_define
define|#
directive|define
name|TR_NO_ERR
value|0
end_define

begin_define
define|#
directive|define
name|TR_WRONG_IF
value|1
end_define

begin_define
define|#
directive|define
name|TR_PRUNED
value|2
end_define

begin_define
define|#
directive|define
name|TR_OPRUNED
value|3
end_define

begin_define
define|#
directive|define
name|TR_SCOPED
value|4
end_define

begin_define
define|#
directive|define
name|TR_NO_RTE
value|5
end_define

begin_define
define|#
directive|define
name|TR_NO_FWD
value|7
end_define

begin_define
define|#
directive|define
name|TR_HIT_RP
value|8
end_define

begin_define
define|#
directive|define
name|TR_RPF_IF
value|9
end_define

begin_define
define|#
directive|define
name|TR_NO_MULTI
value|10
end_define

begin_define
define|#
directive|define
name|TR_NO_SPACE
value|0x81
end_define

begin_define
define|#
directive|define
name|TR_OLD_ROUTER
value|0x82
end_define

begin_define
define|#
directive|define
name|TR_ADMIN_PROHIB
value|0x83
end_define

begin_comment
comment|/* fields for tr_rproto (routing protocol) */
end_comment

begin_define
define|#
directive|define
name|PROTO_DVMRP
value|1
end_define

begin_define
define|#
directive|define
name|PROTO_MOSPF
value|2
end_define

begin_define
define|#
directive|define
name|PROTO_PIM
value|3
end_define

begin_define
define|#
directive|define
name|PROTO_CBT
value|4
end_define

begin_define
define|#
directive|define
name|PROTO_PIM_SPECIAL
value|5
end_define

begin_define
define|#
directive|define
name|PROTO_PIM_STATIC
value|6
end_define

begin_define
define|#
directive|define
name|PROTO_DVMRP_STATIC
value|7
end_define

begin_define
define|#
directive|define
name|VAL_TO_MASK
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
value|{ \ 			x = htonl(~((1<< (32 - (i))) - 1)); \ 			};
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|JAN_1970
value|2208988800UL
end_define

begin_comment
comment|/* 1970 - 1900 in seconds */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JAN_1970
value|2208988800L
end_define

begin_comment
comment|/* 1970 - 1900 in seconds */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

