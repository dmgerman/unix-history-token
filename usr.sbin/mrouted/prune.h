begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE".  Use of the mrouted program represents acceptance of  * the terms and conditions listed in that file.  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  *  * $Id: prune.h,v 1.3 1994/08/24 23:54:40 thyagara Exp $  */
end_comment

begin_comment
comment|/*   * Macro for copying the user-level cache table to the kernel  * level table variable passed on by the setsock option   */
end_comment

begin_define
define|#
directive|define
name|COPY_TABLES
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
value|{ \ 	register u_int _i; \ 	(to).mfcc_origin.s_addr     = (from)->kt_origin; \ 	(to).mfcc_mcastgrp.s_addr   = (from)->kt_mcastgrp; \ 	(to).mfcc_originmask.s_addr = (from)->kt_originmask; \ 	(to).mfcc_parent            = (from)->kt_parent; \ 	for (_i = 0; _i< numvifs; _i++) \ 	    (to).mfcc_ttls[_i]	  = (from)->kt_ttls[_i]; \ };
end_define

begin_comment
comment|/*  * User level Kernel Cache Table structure  *  * A copy of the kernel table is kept at the user level. Modifications are  * made to this table and then passed on to the kernel. A timeout value is  * an extra field in the user level table.  *  */
end_comment

begin_struct
struct|struct
name|ktable
block|{
name|struct
name|ktable
modifier|*
name|kt_next
decl_stmt|;
comment|/* pointer to the next entry        */
name|u_long
name|kt_origin
decl_stmt|;
comment|/* subnet origin of multicasts      */
name|u_long
name|kt_mcastgrp
decl_stmt|;
comment|/* multicast group associated       */
name|u_long
name|kt_originmask
decl_stmt|;
comment|/* subnet mask for origin           */
name|vifi_t
name|kt_parent
decl_stmt|;
comment|/* incoming vif                     */
name|u_long
name|kt_gateway
decl_stmt|;
comment|/* upstream router                  */
name|vifbitmap_t
name|kt_children
decl_stmt|;
comment|/* outgoing children vifs           */
name|vifbitmap_t
name|kt_leaves
decl_stmt|;
comment|/* subset of outgoing children vifs */
name|vifbitmap_t
name|kt_scope
decl_stmt|;
comment|/* scoped interfaces                */
name|u_char
name|kt_ttls
index|[
name|MAXVIFS
index|]
decl_stmt|;
comment|/* ttl vector for forwarding        */
name|vifbitmap_t
name|kt_grpmems
decl_stmt|;
comment|/* forw. vifs for src, grp          */
name|int
name|kt_timer
decl_stmt|;
comment|/* for timing out entry in cache    */
name|struct
name|prunlst
modifier|*
name|kt_rlist
decl_stmt|;
comment|/* router list nghboring this rter  */
name|u_short
name|kt_prun_count
decl_stmt|;
comment|/* count of total no. of prunes     */
name|int
name|kt_prsent_timer
decl_stmt|;
comment|/* prune lifetime timer             */
name|u_int
name|kt_grftsnt
decl_stmt|;
comment|/* graft sent upstream              */
block|}
struct|;
end_struct

begin_comment
comment|/*  * structure to store incoming prunes  */
end_comment

begin_struct
struct|struct
name|prunlst
block|{
name|struct
name|prunlst
modifier|*
name|rl_next
decl_stmt|;
name|u_long
name|rl_router
decl_stmt|;
name|u_long
name|rl_router_subnet
decl_stmt|;
name|vifi_t
name|rl_vifi
decl_stmt|;
name|int
name|rl_timer
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tr_query
block|{
name|u_long
name|tr_src
decl_stmt|;
comment|/* traceroute source */
name|u_long
name|tr_dst
decl_stmt|;
comment|/* traceroute destination */
name|u_long
name|tr_raddr
decl_stmt|;
comment|/* traceroute response address */
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
block|}
name|tr_query
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

begin_struct
struct|struct
name|tr_resp
block|{
name|u_long
name|tr_qarr
decl_stmt|;
comment|/* query arrival time */
name|u_long
name|tr_inaddr
decl_stmt|;
comment|/* incoming interface address */
name|u_long
name|tr_outaddr
decl_stmt|;
comment|/* outgoing interface address */
name|u_long
name|tr_rmtaddr
decl_stmt|;
comment|/* parent address in source tree */
name|u_long
name|tr_vifin
decl_stmt|;
comment|/* input packet count on interface */
name|u_long
name|tr_vifout
decl_stmt|;
comment|/* output packet count on interface */
name|u_long
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
name|tr_resp
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
value|0x0
end_define

begin_define
define|#
directive|define
name|TR_WRONG_IF
value|0x1
end_define

begin_define
define|#
directive|define
name|TR_PRUNED
value|0x2
end_define

begin_define
define|#
directive|define
name|TR_SCOPED
value|0x4
end_define

begin_define
define|#
directive|define
name|TR_NO_RTE
value|0x5
end_define

begin_comment
comment|/* fields for tr_rproto (routing protocol) */
end_comment

begin_define
define|#
directive|define
name|PROTO_DVMRP
value|0x1
end_define

begin_define
define|#
directive|define
name|PROTO_MOSPF
value|0x2
end_define

begin_define
define|#
directive|define
name|PROTO_PIM
value|0x3
end_define

begin_define
define|#
directive|define
name|PROTO_CBT
value|0x4
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
value|{ \ 			(i) = 0; \ 			while ((x)<< (i)) \ 				(i)++; \ 			}
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
value|{ \ 			x = ~((1<< (32 - (i))) - 1); \ 			}
end_define

end_unit

