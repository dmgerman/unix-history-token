begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE".  Use of the mrouted program represents acceptance of  * the terms and conditions listed in that file.  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  *  * $FreeBSD$  * prune.h,v 3.8.4.5 1998/02/27 22:45:43 fenner Exp  */
end_comment

begin_comment
comment|/*  * Group table  *  * Each group entry is a member of two doubly-linked lists:  *  * a) A list hanging off of the routing table entry for this source (rt_groups)  *	sorted by group address under the routing entry (gt_next, gt_prev)  * b) An independent list pointed to by kernel_table, which is a list of  *	active source,group's (gt_gnext, gt_gprev).  *  */
end_comment

begin_struct
struct|struct
name|gtable
block|{
name|struct
name|gtable
modifier|*
name|gt_next
decl_stmt|;
comment|/* pointer to the next entry	    */
name|struct
name|gtable
modifier|*
name|gt_prev
decl_stmt|;
comment|/* back pointer for linked list	    */
name|struct
name|gtable
modifier|*
name|gt_gnext
decl_stmt|;
comment|/* fwd pointer for group list	    */
name|struct
name|gtable
modifier|*
name|gt_gprev
decl_stmt|;
comment|/* rev pointer for group list	    */
name|u_int32
name|gt_mcastgrp
decl_stmt|;
comment|/* multicast group associated       */
name|vifbitmap_t
name|gt_scope
decl_stmt|;
comment|/* scoped interfaces                */
name|u_char
name|gt_ttls
index|[
name|MAXVIFS
index|]
decl_stmt|;
comment|/* ttl vector for forwarding        */
name|vifbitmap_t
name|gt_grpmems
decl_stmt|;
comment|/* forw. vifs for src, grp          */
name|int
name|gt_prsent_timer
decl_stmt|;
comment|/* prune timer for this group	    */
name|int
name|gt_timer
decl_stmt|;
comment|/* timer for this group entry	    */
name|time_t
name|gt_ctime
decl_stmt|;
comment|/* time of entry creation	    */
name|u_char
name|gt_grftsnt
decl_stmt|;
comment|/* graft sent/retransmit timer	    */
name|nbrbitmap_t
name|gt_prunes
decl_stmt|;
comment|/* bitmap of neighbors who pruned   */
name|struct
name|stable
modifier|*
name|gt_srctbl
decl_stmt|;
comment|/* source table			    */
name|struct
name|ptable
modifier|*
name|gt_pruntbl
decl_stmt|;
comment|/* prune table			    */
name|struct
name|rtentry
modifier|*
name|gt_route
decl_stmt|;
comment|/* parent route			    */
name|int
name|gt_rexmit_timer
decl_stmt|;
comment|/* timer for prune retransmission   */
name|int
name|gt_prune_rexmit
decl_stmt|;
comment|/* time til prune retransmission    */
ifdef|#
directive|ifdef
name|RSRR
name|struct
name|rsrr_cache
modifier|*
name|gt_rsrr_cache
decl_stmt|;
comment|/* RSRR cache                       */
endif|#
directive|endif
comment|/* RSRR */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Source table  *  * When source-based prunes exist, there will be a struct ptable here as well.  */
end_comment

begin_struct
struct|struct
name|stable
block|{
name|struct
name|stable
modifier|*
name|st_next
decl_stmt|;
comment|/* pointer to the next entry        */
name|u_int32
name|st_origin
decl_stmt|;
comment|/* host origin of multicasts        */
name|u_long
name|st_pktcnt
decl_stmt|;
comment|/* packet count for src-grp entry   */
name|u_long
name|st_savpkt
decl_stmt|;
comment|/* saved pkt cnt when no krnl entry */
name|time_t
name|st_ctime
decl_stmt|;
comment|/* kernel entry creation time	    */
block|}
struct|;
end_struct

begin_comment
comment|/*  * structure to store incoming prunes.  Can hang off of either group or source.  */
end_comment

begin_struct
struct|struct
name|ptable
block|{
name|struct
name|ptable
modifier|*
name|pt_next
decl_stmt|;
comment|/* pointer to the next entry	    */
name|u_int32
name|pt_router
decl_stmt|;
comment|/* router that sent this prune	    */
name|vifi_t
name|pt_vifi
decl_stmt|;
comment|/* vif prune received on	    */
name|int
name|pt_index
decl_stmt|;
comment|/* neighbor index of router	    */
name|int
name|pt_timer
decl_stmt|;
comment|/* timer for prune		    */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MIN_PRUNE_LIFE
value|TIMER_INTERVAL
end_define

begin_comment
comment|/* min prune lifetime to bother with */
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
name|TR_NO_SPACE
value|0x81
end_define

begin_define
define|#
directive|define
name|TR_OLD_ROUTER
value|0x82
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
name|MASK_TO_VAL
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
value|{ \ 			u_int32 _x = ntohl(x); \ 			(i) = 1; \ 			while ((_x)<<= 1) \ 				(i)++; \ 			};
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
value|{ \ 			x = i ? htonl(~((1<< (32 - (i))) - 1)) : 0; \ 			};
end_define

begin_define
define|#
directive|define
name|NBR_VERS
parameter_list|(
name|n
parameter_list|)
value|(((n)->al_pv<< 8) + (n)->al_mv)
end_define

end_unit

