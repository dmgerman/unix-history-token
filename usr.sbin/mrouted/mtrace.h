begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Multicast traceroute related definitions  *  * mtrace.h,v 5.2 1998/12/04 04:48:21 fenner Exp  */
end_comment

begin_comment
comment|/*  * NetBSD renamed the mtrace packet types.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IGMP_MTRACE_RESP
argument_list|)
operator|&&
name|defined
argument_list|(
name|IGMP_MTRACE_REPLY
argument_list|)
end_if

begin_define
define|#
directive|define
name|IGMP_MTRACE_RESP
value|IGMP_MTRACE_REPLY
end_define

begin_define
define|#
directive|define
name|IGMP_MTRACE
value|IGMP_MTRACE_QUERY
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|u_int32
name|tr_rttlqid
decl_stmt|;
comment|/* response ttl and qid */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TR_SETTTL
parameter_list|(
name|x
parameter_list|,
name|ttl
parameter_list|)
value|(x = (x& 0x00ffffff) | ((ttl)<< 24))
end_define

begin_define
define|#
directive|define
name|TR_GETTTL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xff)
end_define

begin_define
define|#
directive|define
name|TR_SETQID
parameter_list|(
name|x
parameter_list|,
name|qid
parameter_list|)
value|(x = (x& 0xff000000) | ((qid)& 0x00ffffff))
end_define

begin_define
define|#
directive|define
name|TR_GETQID
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x00ffffff)
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
name|PROTO_PIM_BGP4PLUS
value|8
end_define

begin_define
define|#
directive|define
name|PROTO_CBT_SPECIAL
value|9
end_define

begin_define
define|#
directive|define
name|PROTO_CBT_STATIC
value|10
end_define

begin_define
define|#
directive|define
name|PROTO_PIM_ASSERT
value|11
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

