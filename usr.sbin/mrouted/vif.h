begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE".  Use of the mrouted program represents acceptance of  * the terms and conditions listed in that file.  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  *  * $Id: vif.h,v 1.6 1994/08/24 23:54:47 thyagara Exp $  */
end_comment

begin_comment
comment|/*  * User level Virtual Interface structure  *  * A "virtual interface" is either a physical, multicast-capable interface  * (called a "phyint") or a virtual point-to-point link (called a "tunnel").  * (Note: all addresses, subnet numbers and masks are kept in NETWORK order.)  */
end_comment

begin_struct
struct|struct
name|uvif
block|{
name|u_short
name|uv_flags
decl_stmt|;
comment|/* VIFF_ flags defined below            */
name|u_char
name|uv_metric
decl_stmt|;
comment|/* cost of this vif                     */
name|u_int
name|uv_rate_limit
decl_stmt|;
comment|/* rate limit on this vif               */
name|u_char
name|uv_threshold
decl_stmt|;
comment|/* min ttl required to forward on vif   */
name|u_long
name|uv_lcl_addr
decl_stmt|;
comment|/* local address of this vif            */
name|u_long
name|uv_rmt_addr
decl_stmt|;
comment|/* remote end-point addr (tunnels only) */
name|u_long
name|uv_subnet
decl_stmt|;
comment|/* subnet number         (phyints only) */
name|u_long
name|uv_subnetmask
decl_stmt|;
comment|/* subnet mask           (phyints only) */
name|u_long
name|uv_subnetbcast
decl_stmt|;
comment|/* subnet broadcast addr (phyints only) */
name|char
name|uv_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* interface name                   */
name|struct
name|listaddr
modifier|*
name|uv_groups
decl_stmt|;
comment|/* list of local groups  (phyints only) */
name|struct
name|listaddr
modifier|*
name|uv_neighbors
decl_stmt|;
comment|/* list of neighboring routers          */
name|struct
name|vif_acl
modifier|*
name|uv_acl
decl_stmt|;
comment|/* access control list of groups        */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VIFF_KERNEL_FLAGS
value|(VIFF_TUNNEL|VIFF_SRCRT)
end_define

begin_define
define|#
directive|define
name|VIFF_DOWN
value|0x0100
end_define

begin_comment
comment|/* kernel state of interface */
end_comment

begin_define
define|#
directive|define
name|VIFF_DISABLED
value|0x0200
end_define

begin_comment
comment|/* administratively disabled */
end_comment

begin_define
define|#
directive|define
name|VIFF_QUERIER
value|0x0400
end_define

begin_comment
comment|/* I am the subnet's querier */
end_comment

begin_define
define|#
directive|define
name|VIFF_ONEWAY
value|0x0800
end_define

begin_comment
comment|/* Maybe one way interface   */
end_comment

begin_struct
struct|struct
name|vif_acl
block|{
name|struct
name|vif_acl
modifier|*
name|acl_next
decl_stmt|;
comment|/* next acl member         */
name|u_long
name|acl_addr
decl_stmt|;
comment|/* Group address           */
name|u_long
name|acl_mask
decl_stmt|;
comment|/* Group addr. mask        */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|listaddr
block|{
name|struct
name|listaddr
modifier|*
name|al_next
decl_stmt|;
comment|/* link to next addr, MUST BE FIRST */
name|u_long
name|al_addr
decl_stmt|;
comment|/* local group or neighbor address  */
name|u_long
name|al_timer
decl_stmt|;
comment|/* for timing out group or neighbor */
name|u_long
name|al_genid
decl_stmt|;
comment|/* generation id for neighbor       */
name|u_char
name|al_pv
decl_stmt|;
comment|/* router protocol version	    */
name|u_char
name|al_mv
decl_stmt|;
comment|/* router mrouted version	    */
name|u_long
name|al_timerid
decl_stmt|;
comment|/* returned by set timer */
name|u_long
name|al_query
decl_stmt|;
comment|/* second query in case of leave*/
name|u_short
name|al_old
decl_stmt|;
comment|/* if old memberships are present */
name|u_short
name|al_last
decl_stmt|;
comment|/* # of query's since last old rep */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NO_VIF
value|((vifi_t)MAXVIFS)
end_define

begin_comment
comment|/* An invalid vif index */
end_comment

end_unit

